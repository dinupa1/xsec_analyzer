// Post-processing program for the MicroBooNE xsec_analyzer framework.
// Updated to include NC1p selection with manual setup.

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

#include "XSecAnalyzer/Selections/NC1p.hh"

void analyze( const std::string& input_filename,
              const std::string& file_type,
              const std::vector< std::string >& selection_names,
              const int run_id,
              const std::string& output_filename )
{
  std::cout << "\nRunning ProcessNTuples with options:\n";
  std::cout << "\tinput_filename: " << input_filename << '\n';
  std::cout << "\tinput_file_type: " << file_type << '\n';
  std::cout << "\toutput_filename: " << output_filename << '\n';
  std::cout << "\n\nselection names:\n";
  for ( const auto& sel_name : selection_names ) {
    std::cout << "\t\t- " << sel_name << '\n';
  }

  // Get the TTrees containing the event ntuples and subrun POT information
  TChain events_ch( "SingleProtonAna/tree" );
  events_ch.Add( input_filename.c_str() );

  // Get the POT from the input file
  float summed_pot = 0;
  TFile* in_file = TFile::Open( input_filename.c_str(), "read" );
  if ( in_file && !in_file->IsZombie() ) {
    TParameter<float>* in_pot_param = nullptr;
    in_file->GetObject( "summed_pot", in_pot_param );
    if ( in_pot_param ) {
      summed_pot = in_pot_param->GetVal();
    } else {
      TTree* pot_tree = nullptr;
      in_file->GetObject( "SingleProtonAna/subrun", pot_tree );
      if ( !pot_tree ) in_file->GetObject( "nuselection/SubRun", pot_tree );
      if ( pot_tree ) {
        float pot;
        if ( pot_tree->GetBranch( "pot" ) ) {
          pot_tree->SetBranchAddress( "pot", &pot );
          for ( long i = 0; i < pot_tree->GetEntries(); ++i ) {
            pot_tree->GetEntry( i );
            summed_pot += pot;
          }
        } else if ( pot_tree->GetBranch( "POT" ) ) {
          pot_tree->SetBranchAddress( "POT", &pot );
          for ( long i = 0; i < pot_tree->GetEntries(); ++i ) {
            pot_tree->GetEntry( i );
            summed_pot += pot;
          }
        }
      }
    }
    in_file->Close();
  }

  // OUTPUT TTREE
  TFile* out_file = new TFile( output_filename.c_str(), "recreate" );
  out_file->cd();
  TTree* out_tree = new TTree( "nc1p_tree", "NC1p analysis tree" );

  // Write the summed_pot to the output file
  TParameter<float>* out_pot_param = new TParameter<float>( "summed_pot", summed_pot );
  out_pot_param->Write();

  // Selection Setup
  std::vector< std::unique_ptr<SelectionBase> > selections;
  SelectionFactory sf;

  for ( const auto& sel_name : selection_names ) {
    // *** Manual Hook for NC1p ***
    // Allows us to set the sample_type before running setup()
    if ( sel_name == "NC1p" ) {
      std::unique_ptr<NC1p> nc1p_ptr( new NC1p() );
      // Pass the file_type so POTwgt() inside NC1p knows which array to use
      nc1p_ptr->set_sample_type(file_type);
      nc1p_ptr->set_run_id(run_id);
      selections.push_back( std::move(nc1p_ptr) );
    }
    else {
      // Use standard factory for other selections
      selections.emplace_back().reset( sf.CreateSelection(sel_name) );
    }
  }

  out_file->cd();
  for ( auto& sel : selections ) {
    sel->setup( out_tree );
  }

  // Active volume definition for signal enhanced samples
  FiducialVolume AV = { 0.0, 256.0, -120.0, 120.0, 0.0, 1076.0 };

  // EVENT LOOP
  bool created_output_branches = false;
  long events_entry = 0;

  while ( true ) {

    if ( events_entry % 1000 == 0 ) {
      std::cout << "Processing event #" << events_entry << '\n';
    }

    AnalysisEvent cur_event;
    set_event_branch_addresses( events_ch, cur_event );

    int local_entry = events_ch.LoadTree( events_entry );
    if ( local_entry < 0 ) break;

    events_ch.GetEntry( events_entry );

    // *** Signal Enhanced Sample Handling (Pelee logic) ***
    // Avoid double-counting for specific intrinsic samples
    /*
    if (file_type == "nueMC" || file_type == "nueDV") {
      if ( !(std::abs(cur_event.mc_nu_pdg_) == 12 && cur_event.mc_nu_ccnc_ == 0 && point_inside_FV(AV, cur_event.mc_nu_vx_, cur_event.mc_nu_vy_, cur_event.mc_nu_vz_)) ) {
        ++events_entry;
        continue;
      }
    }
    if (file_type == "numuMC") {
      if ( (std::abs(cur_event.mc_nu_pdg_) == 12 && cur_event.mc_nu_ccnc_ == 0 && point_inside_FV(AV, cur_event.mc_nu_vx_, cur_event.mc_nu_vy_, cur_event.mc_nu_vz_)) ) {
        ++events_entry;
        continue;
      }
    }

    // NuMI specific: configure normalisation weight
    if (useNuMI) {
      if (file_type == "dirtMC") cur_event.normalisation_weight_ = 0.65;
      else cur_event.normalisation_weight_ = 1.0;
    }
    */

    // Set the output TTree branch addresses
    bool create_them = false;
    if ( !created_output_branches ) {
      create_them = true;
      created_output_branches = true;
    }
    set_event_output_branch_addresses(*out_tree, cur_event, create_them );

    for ( auto& sel : selections ) {
      sel->apply_selection( &cur_event, run_id);
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

  // We expect 6 arguments now: program_name + 5 inputs
  if ( argc != 6 ) {
    std::cout << "Usage: " << argv[0]
    << " INPUT_FILE FILE_TYPE SELECTION_NAMES RUN_ID OUTPUT_FILE\n";
    return 1;
  }

  // argv[0] is the program name
  std::string input_file_name( argv[1] );
  std::string file_type( argv[2] );

  // Parse comma-separated selection names
  std::vector< std::string > selection_names;
  std::stringstream sel_ss( argv[3] );
  std::string sel_name;
  while ( std::getline(sel_ss, sel_name, ',') ) {
    selection_names.push_back( sel_name );
  }

  // Use std::stoi for better error handling than atoi
  int run_id = 0;
  try {
    run_id = std::stoi(argv[4]);
  } catch (const std::exception& e) {
    std::cerr << "Error: RUN_ID must be an integer. Received: " << argv[4] << "\n";
    return 1;
  }

  std::string output_file_name( argv[5] );

  // Execute the analysis
  analyze( input_file_name, file_type, selection_names, run_id, output_file_name );

  return 0;
}
