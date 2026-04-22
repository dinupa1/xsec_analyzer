// Post-processing program for the MicroBooNE xsec_analyzer framework. This is
// currently designed for use with the PeLEE group's "searchingfornues" ntuples
//
// Updated 24 September 2024
// Steven Gardiner <gardiner@fnal.gov>
// Daniel Barrow <daniel.barrow@physics.ox.ac.uk>

// Standard library includes
#include <cmath>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

// ROOT includes
#include "TChain.h"
#include "TFile.h"
#include "TBranch.h"
#include "TParameter.h"
#include "TTree.h"
#include "TVector3.h"

// XSecAnalyzer includes
#include "XSecAnalyzer/AnalysisEvent.hh"
#include "XSecAnalyzer/Branches.hh"
#include "XSecAnalyzer/Constants.hh"
#include "XSecAnalyzer/Functions.hh"
#include "XSecAnalyzer/FiducialVolume.hh"

#include "XSecAnalyzer/Selections/SelectionBase.hh"
#include "XSecAnalyzer/Selections/SelectionFactory.hh"

void analyze( const std::string& input_filename,
  const std::vector< std::string >& selection_names,
  const int run_id,
  const std::string& output_filename )
{
  std::cout << "\nRunning ProcessNTuples with options:\n";
  std::cout << "\tinput_filename: " << input_filename << '\n';
  std::cout << "\trun_id: " << run_id << '\n';
  std::cout << "\toutput_filename: " << output_filename << '\n';
  std::cout << "\n\nselection names:\n";
  for ( const auto& sel_name : selection_names ) {
    std::cout << "\t\t- " << sel_name << '\n';
  }

  // Get the TTrees containing the event ntuples and subrun POT information
  // Use TChain objects for simplicity in manipulating multiple files
  bool is_nc1p_format = false;
  TFile* temp_file = TFile::Open( input_filename.c_str() );
  if ( temp_file && temp_file->Get("SingleProtonAna/tree") ) {
    is_nc1p_format = true;
  }
  if ( temp_file ) temp_file->Close();

  std::string event_tree_name = is_nc1p_format ? "SingleProtonAna/tree" : "nuselection/NeutrinoSelectionFilter";
  std::string subrun_tree_name = is_nc1p_format ? "SingleProtonAna/pottree" : "nuselection/SubRun";

  TChain events_ch( event_tree_name.c_str() );
  TChain subruns_ch( subrun_tree_name.c_str() );
  events_ch.Add( input_filename.c_str() );
  subruns_ch.Add( input_filename.c_str() );

  // OUTPUT TTREE
  // Make an output TTree for plotting (one entry per event)
  TFile* out_file = new TFile( output_filename.c_str(), "recreate" );
  out_file->cd();
  TTree* out_tree = new TTree( "stv_tree", "STV analysis tree" );
  out_tree->SetDirectory( out_file );

  // Get the total POT from the subruns TTree. Save it in the output
  // TFile as a TParameter<float>. Real data doesn't have this TTree,
  // so check that it exists first.
  float pot;
  float summed_pot = 0.;
  std::string pot_branch_name = is_nc1p_format ? "pot" : "pot"; // Both seem to use "pot"
  bool has_pot_branch = ( subruns_ch.GetBranch(pot_branch_name.c_str()) != nullptr );
  if ( has_pot_branch ) {
    subruns_ch.SetBranchAddress( pot_branch_name.c_str(), &pot );
    for ( int se = 0; se < subruns_ch.GetEntries(); ++se ) {
      subruns_ch.GetEntry( se );
      summed_pot += pot;
    }
  }

  // If summed_pot is 0 and it's NC1p format, maybe it's BNB data where POT is handled differently
  // but for now let's stick to the tree if it exists.

  TParameter<float>* summed_pot_param = new TParameter<float>( "summed_pot",
    summed_pot );

  summed_pot_param->Write();

  std::vector< std::unique_ptr<SelectionBase> > selections;

  SelectionFactory sf;
  for ( const auto& sel_name : selection_names ) {
    selections.emplace_back().reset( sf.CreateSelection(sel_name) );
  }

  out_file->cd();
  for ( auto& sel : selections ) {
    sel->setup( out_tree );
  }

  // Active volume definition
  // required for correctly incorporating signal enhanced samples 
  // generated only in active volume rather than full cryostat volume
  FiducialVolume AV = { 0.0, 256.0, -120.0, 120.0, 0.0, 1076.0 };

  // Detect if the input file is MC or Data
  bool input_is_mc = ( events_ch.GetBranch("mc_nupdg") != nullptr );

  // Create a single AnalysisEvent object outside the loop to ensure stable memory addresses
  AnalysisEvent cur_event;
  OldNC1pTruth old_truth;

  // Temporary pointers for old format weights (moved outside the loop)
  std::vector<std::string>* old_genie_names = nullptr;
  std::vector<std::vector<double>>* old_genie_weights = nullptr;
  std::vector<std::string>* old_g4_names = nullptr;
  std::vector<std::vector<double>>* old_g4_weights = nullptr;
  std::vector<std::string>* old_flux_names = nullptr;
  std::vector<std::vector<double>>* old_flux_weights = nullptr;

  if ( is_nc1p_format ) {
    if ( events_ch.GetBranch("evtwgt_genie_multisim_funcname") ) {
      events_ch.SetBranchAddress("evtwgt_genie_multisim_funcname", &old_genie_names);
      events_ch.SetBranchAddress("evtwgt_genie_multisim_weight", &old_genie_weights);
    }
    if ( events_ch.GetBranch("evtwgt_g4_multisim_funcname") ) {
      events_ch.SetBranchAddress("evtwgt_g4_multisim_funcname", &old_g4_names);
      events_ch.SetBranchAddress("evtwgt_g4_multisim_weight", &old_g4_weights);
    }
    if ( events_ch.GetBranch("evtwgt_flux_multisim_funcname") ) {
      events_ch.SetBranchAddress("evtwgt_flux_multisim_funcname", &old_flux_names);
      events_ch.SetBranchAddress("evtwgt_flux_multisim_weight", &old_flux_weights);
    }
  }

  // Initialize the weights map early if in NC1p format MC so that output branches can be created
  if ( is_nc1p_format && input_is_mc ) {
    cur_event.mc_weights_map_.reset( new std::map<std::string, std::vector<double>>() );
    
    // Discovery step: get first entry to see all weight names
    if ( events_ch.GetEntries() > 0 ) {
      events_ch.GetEntry(0);
      if ( old_genie_names ) {
        for ( const auto& name : *old_genie_names ) (*cur_event.mc_weights_map_)[ name ] = {};
      }
      if ( old_g4_names ) {
        for ( const auto& name : *old_g4_names ) (*cur_event.mc_weights_map_)[ name ] = {};
      }
      if ( old_flux_names ) {
        for ( const auto& name : *old_flux_names ) (*cur_event.mc_weights_map_)[ name ] = {};
      }
    }

    // Ensure CV weights are in the map
    (*cur_event.mc_weights_map_)[ "TunedCentralValue_UBGenie" ] = {};
    (*cur_event.mc_weights_map_)[ "splines_general_Spline" ] = {};
  }

  // Set up branch addresses once before the loop
  if ( is_nc1p_format ) {
    set_nc1p_event_branch_addresses( events_ch, cur_event, old_truth );
  }
  else {
    set_event_branch_addresses( events_ch, cur_event );
  }

  // Set the output TTree branch addresses once
  set_event_output_branch_addresses(*out_tree, cur_event, true );

  // EVENT LOOP
  long events_entry = 0;
  while ( true ) {

    if ( events_entry % 1000 == 0 ) {
      std::cout << "Processing event #" << events_entry << '\n';
    }

    // Reset analysis variables for the current event
    cur_event.is_mc_ = false;
    // Clear only the contents of the weight vectors, not the map itself,
    // to maintain stable memory addresses for the output branches
    if ( cur_event.mc_weights_map_ ) {
      for ( auto& pair : *cur_event.mc_weights_map_ ) {
        pair.second.clear();
      }
    }

    // Reset old truth pointers
    old_truth.mc_pdg_float = nullptr;
    old_truth.mc_pdg_int = nullptr;

    // TChain::LoadTree() returns the entry number that should be used with
    // the current TTree object
    int local_entry = events_ch.LoadTree( events_entry );

    if ( local_entry < 0 ) break;

    // Load all of the branches for which we've called SetBranchAddress()
    events_ch.GetEntry( events_entry );

    // Overwrite run_number_ with run_id provided externally
    cur_event.run_number_ = run_id;

    // If in old format, perform truth data conversion/casting
    if ( is_nc1p_format && input_is_mc ) {
      cur_event.mc_nu_pdg_ = old_truth.mc_nupdg;
      cur_event.mc_nu_vx_ = old_truth.mc_nu_vtxx;
      cur_event.mc_nu_vy_ = old_truth.mc_nu_vtxy;
      cur_event.mc_nu_vz_ = old_truth.mc_nu_vtxz;
      cur_event.mc_nu_energy_ = old_truth.mc_enu;
      cur_event.mc_nu_ccnc_ = old_truth.mc_ccnc;
      cur_event.mc_nu_interaction_type_ = old_truth.mc_mode;
      cur_event.mc_hitnuc_ = old_truth.mc_hitnuc;

      if ( !cur_event.mc_nu_daughter_pdg_ ) {
        cur_event.mc_nu_daughter_pdg_.reset( new std::vector<int>() );
      }
      cur_event.mc_nu_daughter_pdg_->clear();

      if ( old_truth.mc_pdg_float ) {
        for ( float pdg : *old_truth.mc_pdg_float ) {
          cur_event.mc_nu_daughter_pdg_->push_back( (int)pdg );
        }
      } else if ( old_truth.mc_pdg_int ) {
        for ( int pdg : *old_truth.mc_pdg_int ) {
          cur_event.mc_nu_daughter_pdg_->push_back( pdg );
        }
      }

      if ( !cur_event.mc_weights_map_ ) {
        cur_event.mc_weights_map_.reset( new std::map<std::string, std::vector<double>>() );
      }
      
      // Add a dummy TunedCentralValue weight with value 1.0
      (*cur_event.mc_weights_map_)[ "TunedCentralValue_UBGenie" ] = { 1.0 };
      (*cur_event.mc_weights_map_)[ "splines_general_Spline" ] = { 1.0 };

      // Also initialize individual weight branches to 1.0
      cur_event.spline_weight_ = 1.0;
      cur_event.tuned_cv_weight_ = 1.0;
      cur_event.ppfx_cv_weight_ = 1.0;

      if ( old_genie_names && old_genie_weights ) {
        size_t n = std::min( old_genie_names->size(), old_genie_weights->size() );
        for ( size_t i = 0; i < n; ++i ) {
          (*cur_event.mc_weights_map_)[ old_genie_names->at(i) ] = old_genie_weights->at(i);
        }
      }
      if ( old_g4_names && old_g4_weights ) {
        size_t n = std::min( old_g4_names->size(), old_g4_weights->size() );
        for ( size_t i = 0; i < n; ++i ) {
          (*cur_event.mc_weights_map_)[ old_g4_names->at(i) ] = old_g4_weights->at(i);
        }
      }
      if ( old_flux_names && old_flux_weights ) {
        size_t n = std::min( old_flux_names->size(), old_flux_weights->size() );
        for ( size_t i = 0; i < n; ++i ) {
          (*cur_event.mc_weights_map_)[ old_flux_names->at(i) ] = old_flux_weights->at(i);
        }
      }
    }

    for ( auto& sel : selections ) {
      sel->apply_selection( &cur_event );
    }

    out_tree->Fill();
    ++events_entry;
  }

  for ( auto& sel : selections ) {
    sel->summary();
  }
  std::cout << "Wrote output to:" << output_filename << std::endl;

  for ( auto& sel : selections ) {
    sel->final_tasks();
  }

  out_tree->Write();
  out_file->Close();
  delete out_file;
}

int main( int argc, char* argv[] ) {

  if ( argc != 5 ) {
    std::cout << "Usage: " << argv[0]
      << " INPUT_PELEE_NTUPLE_FILE SELECTION_NAMES RUN_ID OUTPUT_FILE\n";
    return 1;
  }

  std::string input_file_name( argv[1] );
  std::string output_file_name( argv[4] );

  std::vector< std::string > selection_names;

  std::stringstream sel_ss( argv[2] );
  std::string sel_name;
  while ( std::getline(sel_ss, sel_name, ',') ) {
    selection_names.push_back( sel_name );
  }

  int run_id = std::stoi( argv[3] );

  analyze( input_file_name, selection_names, run_id, output_file_name );

  return 0;
}
