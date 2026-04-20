#include "XSecAnalyzer/Selections/NC1p.hh"
#include "XSecAnalyzer/Functions.hh"
#include "TMath.h"
#include <unistd.h>

NC1p::NC1p() : SelectionBase( "NC1p" ) {
  bdt_reader_ = new TMVA::Reader( "!Color:!Silent" );
  bdt_reader_->AddVariable( "reco_length", &len_ );
  bdt_reader_->AddVariable( "reco_theta", &theta_ );
  bdt_reader_->AddVariable( "reco_phi", &phi_ );
  bdt_reader_->AddVariable( "end_dedx_2", &dedx_end2_ );
  bdt_reader_->AddVariable( "total_dedx_2", &dedx_total2_ );
  bdt_reader_->AddVariable( "reco_start_y", &starty_ );
  bdt_reader_->AddVariable( "reco_start_z", &startz_ );
  bdt_reader_->AddVariable( "reco_end_y", &endy_ );
  bdt_reader_->AddVariable( "reco_end_z", &endz_ );
  bdt_reader_->AddVariable( "chi2_p_0", &pid_p0_ );
  bdt_reader_->AddVariable( "chi2_p_1", &pid_p1_ );
  bdt_reader_->AddVariable( "chi2_p_2", &pid_p2_ );
  bdt_reader_->AddVariable( "trk_dis", &trk_dis_ );

  current_run_ = -1;
}

void NC1p::LoadBDTWeights( int run ) {
  bdt_weights_loaded_ = false;
  TString weight_path = Form("/exp/uboone/app/users/renlu23/v61_2022/analysis/BDT/dataset/weights_%d/TMVAClassification_BDTG.weights.xml", run);
  if ( access( weight_path.Data(), F_OK ) != -1 ) {
      std::cout << "[NC1p] Loading BDT weights for Run " << run << " from: " << weight_path << std::endl;
      // Re-initialize the reader to avoid multiple booking of the same method
      delete bdt_reader_;
      bdt_reader_ = new TMVA::Reader( "!Color:!Silent" );
      bdt_reader_->AddVariable( "reco_length", &len_ );
      bdt_reader_->AddVariable( "reco_theta", &theta_ );
      bdt_reader_->AddVariable( "reco_phi", &phi_ );
      bdt_reader_->AddVariable( "end_dedx_2", &dedx_end2_ );
      bdt_reader_->AddVariable( "total_dedx_2", &dedx_total2_ );
      bdt_reader_->AddVariable( "reco_start_y", &starty_ );
      bdt_reader_->AddVariable( "reco_start_z", &startz_ );
      bdt_reader_->AddVariable( "reco_end_y", &endy_ );
      bdt_reader_->AddVariable( "reco_end_z", &endz_ );
      bdt_reader_->AddVariable( "chi2_p_0", &pid_p0_ );
      bdt_reader_->AddVariable( "chi2_p_1", &pid_p1_ );
      bdt_reader_->AddVariable( "chi2_p_2", &pid_p2_ );
      bdt_reader_->AddVariable( "trk_dis", &trk_dis_ );
      bdt_reader_->BookMVA( "BDTG", weight_path.Data() );
      bdt_weights_loaded_ = true;
  } else {
      std::cerr << "[NC1p] WARNING: BDT Weight file not found: " << weight_path << std::endl;
  }
}

void NC1p::define_constants() {
  // Truth FV from make_tree.C FillSubCat
  this->define_true_FV( 10., 246.35, -96.5, 96.5, 10., 1026.8 );
  // Reco FV from make_tree.h IsInFV (border_xorz=10, border_y=20)
  this->define_reco_FV( 10., 246.35, -96.35, 96.35, 10., 1026.8 );
}

void NC1p::compute_reco_observables( AnalysisEvent* event ) {
  // Find the NC1p candidate track index
  int cand_idx = -1;
  for ( size_t i = 0; i < event->track_length_->size(); ++i ) {
    if ( event->is_reco_nc1p_->at(i) ) {
      cand_idx = i;
      break;
    }
  }

  if ( cand_idx != -1 ) {
    reco_ke_ = 31.3 * std::pow( event->track_length_->at(cand_idx), 0.578 ) / 1000.0;
    reco_q2_ = reco_ke_ * 2.0 * PROTON_MASS;
    // Use f2 for reco costheta to match selection
    reco_costheta_ = std::cos( event->track_theta_f2_->at(cand_idx) );
  }
}

void NC1p::compute_true_observables( AnalysisEvent* event ) {
  // Looking for the leading true proton in the daughters as in make_tree.C L410
  int true_p_idx = -1;
  float max_e = 0;
  for ( size_t i = 0; i < event->mc_nu_daughter_pdg_->size(); ++i ) {
    if ( event->mc_nu_daughter_pdg_->at(i) == 2212 && event->mc_nu_daughter_energy_->at(i) > max_e ) {
      max_e = event->mc_nu_daughter_energy_->at(i);
      true_p_idx = i;
    }
  }

  if ( true_p_idx != -1 ) {
    true_ke_ = event->mc_nu_daughter_energy_->at(true_p_idx) - PROTON_MASS;
    true_q2_ = true_ke_ * 2.0 * PROTON_MASS;
    // Use mc_theta branch directly if available
    if ( event->mc_nu_daughter_theta_->size() > (size_t)true_p_idx ) {
      true_costheta_ = std::cos( event->mc_nu_daughter_theta_->at(true_p_idx) );
    } else {
      true_costheta_ = event->mc_nu_daughter_pz_->at(true_p_idx) / 
                       std::sqrt(std::pow(event->mc_nu_daughter_px_->at(true_p_idx), 2) + 
                                 std::pow(event->mc_nu_daughter_py_->at(true_p_idx), 2) + 
                                 std::pow(event->mc_nu_daughter_pz_->at(true_p_idx), 2));
    }
  }
}

int NC1p::categorize_event( AnalysisEvent* event ) {
  // Refined categorization based on make_tree.C FillSubCat
  if ( !event->is_mc_ ) return 0; // Data

  bool in_fv = point_inside_FV( this->true_FV(), event->mc_nu_vx_, event->mc_nu_vy_, event->mc_nu_vz_ );
  bool is_nc1p = (event->mc_nu_pdg_ == 14) && (event->mc_n_threshold_muon_ == 0) && 
                 (event->mc_n_threshold_pionpm_ + event->mc_n_threshold_pion0_ == 0) && 
                 (event->mc_n_threshold_proton_ == 1);

  if ( in_fv ) {
    if ( is_nc1p ) {
      if ( event->mc_nu_ccnc_ == 1 && event->mc_nu_interaction_type_ == 0 && 
           (event->mc_hitnuc_ == 2212 || event->mc_hitnuc11_nuwro_ == 2212) ) return 8; // NC1p and NCE
      return 9; // NC1p and non-NCE
    }
    if ( event->mc_nu_pdg_ != 14 && is_nc1p ) return 7; // NC not numu
  } else {
    if ( is_nc1p ) return 2; // OOFV NC
  }

  if ( !is_nc1p ) {
    if ( event->mc_nu_ccnc_ == 0 ) return 4; // CC
    if ( event->mc_nu_ccnc_ == 1 ) return 3; // NC other
  }

  return 5; // Default other
}

bool NC1p::define_signal( AnalysisEvent* event ) {
  // Signal definition from make_tree.C
  bool in_fv = point_inside_FV( this->true_FV(), event->mc_nu_vx_, event->mc_nu_vy_, event->mc_nu_vz_ );
  bool is_nc1p = (event->mc_nu_pdg_ == 14) && (event->mc_n_threshold_muon_ == 0) && 
                 (event->mc_n_threshold_pionpm_ + event->mc_n_threshold_pion0_ == 0) && 
                 (event->mc_n_threshold_proton_ == 1);
  return in_fv && is_nc1p;
}

bool NC1p::selection( AnalysisEvent* event ) {
  reset();

  // Primary selection from make_tree.C L435
  if ( event->evt_reco_1p_ != 1 ) return false;

  int index_p = -1;
  float trkdis = 999;
  for ( size_t i = 0; i < event->track_length_->size(); ++i ) {
    if ( event->is_reco_nc1p_->at(i) && event->isinFV_->at(i) > 0 ) {
      // Use _f2 branches for primary track as in make_tree.C L445-450
      float startx = event->track_startx_f2_->at(i);
      float starty = event->track_starty_f2_->at(i);
      float startz = event->track_startz_f2_->at(i);
      float endx = event->track_endx_f2_->at(i);
      float endy = event->track_endy_f2_->at(i);
      float endz = event->track_endz_f2_->at(i);
      float len = event->track_length_->at(i);
      float theta = event->track_theta_f2_->at(i);
      float phi = event->track_phi_f2_->at(i);
      float costheta = std::cos( theta );
      float chi2p2 = event->track_chi2_proton_2_->at(i);

      if ( startx < 10 || startx > 246.35 ) continue;
      if ( endx < 10 || endx > 246.35 ) continue;
      if ( starty < -96.35 || starty > 96.35 ) continue;
      if ( endy < -96.35 || endy > 96.35 ) continue;
      if ( startz < 10 || startz > 1026.8 ) continue;
      if ( endz < 10 || endz > 1026.8 ) continue;
      if ( len < 1.2 || len > 200 ) continue;
      if ( costheta < 0 ) continue;
      if ( chi2p2 > 60 || chi2p2 < 0 ) continue;

      // Track distance calculation as in make_tree.C L460-467
      if ( event->track_length_->size() > 1 ) {
        for ( size_t j = 0; j < event->track_length_->size(); ++j ) {
          // Note: make_tree.C uses reco_start_x (non-f2) for comparison
          float temp1 = std::sqrt( std::pow(startx - event->track_startx_->at(j), 2) + 
                                   std::pow(starty - event->track_starty_->at(j), 2) + 
                                   std::pow(startz - event->track_startz_->at(j), 2) );
          float temp2 = std::sqrt( std::pow(startx - event->track_endx_->at(j), 2) + 
                                   std::pow(starty - event->track_endy_->at(j), 2) + 
                                   std::pow(startz - event->track_endz_->at(j), 2) );
          if ( temp1 > 0 && temp2 > 0 && temp1 < temp2 && temp1 < trkdis ) { trkdis = temp1; }
          if ( temp1 > 0 && temp2 > 0 && temp1 >= temp2 && temp2 < trkdis ) { trkdis = temp2; }
        }
      }

      index_p = i;
      trk_dis_ = trkdis;
      len_ = len;
      theta_ = theta;
      phi_ = phi;
      break;
    }
  }

  if ( index_p == -1 ) return false;

  // BDT evaluation
  dedx_end2_ = event->track_end_dedx_2_->at(index_p); 
  dedx_total2_ = event->track_total_dedx_2_->at(index_p);
  starty_ = event->track_starty_f2_->at(index_p);
  startz_ = event->track_startz_f2_->at(index_p);
  endy_ = event->track_endy_f2_->at(index_p);
  endz_ = event->track_endz_f2_->at(index_p);
  pid_p0_ = event->track_chi2_proton_0_->at(index_p);
  pid_p1_ = event->track_chi2_proton_1_->at(index_p);
  pid_p2_ = event->track_chi2_proton_2_->at(index_p);

  // Check if BDT weights need to be loaded for the current run
  if ( event->run_number_ != current_run_ ) {
    this->LoadBDTWeights( event->run_number_ );
    current_run_ = event->run_number_;
  }

  // Evaluate BDT score if weights are loaded
  if ( bdt_weights_loaded_ ) {
    try {
      bdt_score_ = bdt_reader_->EvaluateMVA( "BDTG" );
    } catch (...) {
      bdt_score_ = -1.0;
    }
  } else {
    bdt_score_ = -1.0;
  }

  if ( bdt_score_ < 0.2 ) return false;

  return true;
}

void NC1p::define_output_branches() {
  set_branch( &bdt_score_, "bdt_score" );
  set_branch( &reco_ke_, "reco_ke" );
  set_branch( &reco_q2_, "reco_q2" );
  set_branch( &reco_costheta_, "reco_costheta" );
  set_branch( &true_ke_, "true_ke" );
  set_branch( &true_q2_, "true_q2" );
  set_branch( &true_costheta_, "true_costheta" );
  set_branch( &trk_dis_, "trk_dis" );
  set_branch( &len_, "len" );
  set_branch( &theta_, "theta" );
  set_branch( &phi_, "phi" );
}

void NC1p::reset() {
  bdt_score_ = BOGUS;
  reco_ke_ = BOGUS;
  reco_q2_ = BOGUS;
  reco_costheta_ = BOGUS;
  true_ke_ = BOGUS;
  true_q2_ = BOGUS;
  true_costheta_ = BOGUS;
  trk_dis_ = BOGUS;
  len_ = BOGUS;
  theta_ = BOGUS;
  phi_ = BOGUS;
}

void NC1p::define_category_map() {
  categ_map_ = {
    { 0, { "Data", 0 } },
    { 8, { "NC1p NCE", 1 } },
    { 9, { "NC1p non-NCE", 2 } },
    { 7, { "NC not numu", 3 } },
    { 2, { "OOFV NC", 4 } },
    { 4, { "CC", 5 } },
    { 3, { "NC other", 6 } },
    { 5, { "Other", 7 } }
  };
}
