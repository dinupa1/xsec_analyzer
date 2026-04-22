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
  if ( event->is_reco_nc1p_ ) {
    for ( size_t i = 0; i < event->is_reco_nc1p_->size(); ++i ) {
      if ( event->is_reco_nc1p_->at(i) ) {
        cand_idx = i;
        break;
      }
    }
  }

  if ( cand_idx != -1 ) {
    if ( event->track_length_ && event->track_length_->size() > (size_t)cand_idx ) {
      reco_ke_ = 31.3 * std::pow( event->track_length_->at(cand_idx), 0.578 ) / 1000.0;
      reco_q2_ = reco_ke_ * 2.0 * PROTON_MASS;
    } else {
      reco_ke_ = BOGUS;
      reco_q2_ = BOGUS;
    }

    // Use f2 for reco costheta to match selection
    if ( event->track_theta_f2_ && event->track_theta_f2_->size() > (size_t)cand_idx ) {
      reco_costheta_ = std::cos( event->track_theta_f2_->at(cand_idx) );
    } else {
      reco_costheta_ = BOGUS;
    }
  }
}

void NC1p::compute_true_observables( AnalysisEvent* event ) {
  // Looking for the leading true proton in the daughters as in make_tree.C L410
  int true_p_idx = -1;
  float max_e = 0;
  
  if ( event->mc_nu_daughter_pdg_ && event->mc_nu_daughter_energy_ ) {
    size_t n_pdg = event->mc_nu_daughter_pdg_->size();
    size_t n_e = event->mc_nu_daughter_energy_->size();
    size_t n = std::min( n_pdg, n_e );

    for ( size_t i = 0; i < n; ++i ) {
      if ( event->mc_nu_daughter_pdg_->at(i) == 2212 && event->mc_nu_daughter_energy_->at(i) > max_e ) {
        max_e = event->mc_nu_daughter_energy_->at(i);
        true_p_idx = i;
      }
    }
  }

  if ( true_p_idx != -1 ) {
    true_ke_ = event->mc_nu_daughter_energy_->at(true_p_idx) - PROTON_MASS;
    true_q2_ = true_ke_ * 2.0 * PROTON_MASS;

    size_t n_px = event->mc_nu_daughter_px_ ? event->mc_nu_daughter_px_->size() : 0;
    size_t n_py = event->mc_nu_daughter_py_ ? event->mc_nu_daughter_py_->size() : 0;
    size_t n_pz = event->mc_nu_daughter_pz_ ? event->mc_nu_daughter_pz_->size() : 0;
    size_t n_theta = event->mc_nu_daughter_theta_ ? event->mc_nu_daughter_theta_->size() : 0;

    // Use mc_theta branch directly if available and size is consistent
    if ( n_theta > (size_t)true_p_idx ) {
      true_costheta_ = std::cos( event->mc_nu_daughter_theta_->at(true_p_idx) );
    } 
    else if ( n_px > (size_t)true_p_idx && n_py > (size_t)true_p_idx && n_pz > (size_t)true_p_idx ) {
      float px = event->mc_nu_daughter_px_->at(true_p_idx);
      float py = event->mc_nu_daughter_py_->at(true_p_idx);
      float pz = event->mc_nu_daughter_pz_->at(true_p_idx);
      true_costheta_ = pz / std::sqrt( px*px + py*py + pz*pz );
    }
    else {
      true_costheta_ = BOGUS;
    }
  }
}

int NC1p::categorize_event( AnalysisEvent* event ) {
  // Refined categorization based on make_tree.C FillSubCat
  int abs_mc_nu_pdg = std::abs( event->mc_nu_pdg_ );
  event->is_mc_ = ( abs_mc_nu_pdg == ELECTRON_NEUTRINO
    || abs_mc_nu_pdg == MUON_NEUTRINO || abs_mc_nu_pdg == TAU_NEUTRINO );

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

  // Safe vector access lambda
  auto get_val = [&](const auto& vec_ptr, size_t idx, auto default_val) -> decltype(default_val) {
    if ( vec_ptr && vec_ptr->size() > idx ) return vec_ptr->at(idx);
    return default_val;
  };

  int index_p = -1;
  float trkdis = 999;
  size_t n_tracks = event->track_length_ ? event->track_length_->size() : 0;

  for ( size_t i = 0; i < n_tracks; ++i ) {
    bool is_reco = get_val( event->is_reco_nc1p_, i, false );
    int in_fv = get_val( event->isinFV_, i, 0 );

    if ( is_reco && in_fv > 0 ) {
      // Use _f2 branches for primary track as in make_tree.C L445-450
      float startx = get_val( event->track_startx_f2_, i, BOGUS );
      float starty = get_val( event->track_starty_f2_, i, BOGUS );
      float startz = get_val( event->track_startz_f2_, i, BOGUS );
      float endx = get_val( event->track_endx_f2_, i, BOGUS );
      float endy = get_val( event->track_endy_f2_, i, BOGUS );
      float endz = get_val( event->track_endz_f2_, i, BOGUS );
      float len = get_val( event->track_length_, i, BOGUS );
      float theta = get_val( event->track_theta_f2_, i, BOGUS );
      float phi = get_val( event->track_phi_f2_, i, BOGUS );
      float costheta = std::cos( theta );
      float chi2p2 = get_val( event->track_chi2_proton_2_, i, BOGUS );

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
      if ( n_tracks > 1 ) {
        for ( size_t j = 0; j < n_tracks; ++j ) {
          float tj_startx = get_val( event->track_startx_, j, BOGUS );
          float tj_starty = get_val( event->track_starty_, j, BOGUS );
          float tj_startz = get_val( event->track_startz_, j, BOGUS );
          float tj_endx = get_val( event->track_endx_, j, BOGUS );
          float tj_endy = get_val( event->track_endy_, j, BOGUS );
          float tj_endz = get_val( event->track_endz_, j, BOGUS );

          if (tj_startx == BOGUS) continue;

          float temp1 = std::sqrt( std::pow(startx - tj_startx, 2) + 
                                   std::pow(starty - tj_starty, 2) + 
                                   std::pow(startz - tj_startz, 2) );
          float temp2 = std::sqrt( std::pow(startx - tj_endx, 2) + 
                                   std::pow(starty - tj_endy, 2) + 
                                   std::pow(startz - tj_endz, 2) );
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

  // nblip check from make_tree.C L566
  int nblip5 = 0;
  size_t n_blips = event->blip_x_ ? event->blip_x_->size() : 0;
  float startx_f2 = get_val( event->track_startx_f2_, index_p, BOGUS );
  float starty_f2 = get_val( event->track_starty_f2_, index_p, BOGUS );
  float startz_f2 = get_val( event->track_startz_f2_, index_p, BOGUS );

  if ( n_blips > 0 ) {
    for ( size_t i = 0; i < n_blips; ++i ) {
      float blipx = get_val( event->blip_x_, i, BOGUS );
      float blipy = get_val( event->blip_y_, i, BOGUS );
      float blipz = get_val( event->blip_z_, i, BOGUS );
      
      float disb = std::sqrt( std::pow(startx_f2 - blipx, 2) + 
                              std::pow(starty_f2 - blipy, 2) + 
                              std::pow(startz_f2 - blipz, 2) );
      
      // VertexIsInFV check based on make_tree.h
      auto is_in_fv = [](float x, float y, float z) -> int {
        if (x < 10 || x > 246.35) return -1;
        if (y < -96.35 || y > 96.35) return -1;
        if (z < 10 || z > 1026.8) return -1;

        if (y - 0.6 * z > -186 && y - 0.6 * z < -120) return 1;
        if (y - 0.6 * z < -207 && y + 0.6 * z < 434 && z < 700) return 2;
        if (z > 740 && y + 0.6 * z > 454) return 3;
        if (y + 0.6 * z > 454 && z < 700) return 4;
        if (y + 0.6 * z < 434 && z > 740) return 5;
        return 0;
      };

      if ( disb < 50 && is_in_fv(blipx, blipy, blipz) > 0 ) {
        if ( blipz < startz_f2 ) nblip5++;
      }
    }
  }

  // Assuming do_blip1 is true as per Task 2/3 requirements for NC1p
  if ( nblip5 > 1 ) return false;

  // Safe BDT variable assignment with range checks
  auto assign_if_safe = [&](const auto& vec_ptr, float& target, size_t idx) {
    if ( vec_ptr && vec_ptr->size() > idx ) target = vec_ptr->at(idx);
    else target = BOGUS;
  };

  assign_if_safe( event->track_end_dedx_2_, dedx_end2_, index_p );
  assign_if_safe( event->track_total_dedx_2_, dedx_total2_, index_p );
  assign_if_safe( event->track_starty_f2_, starty_, index_p );
  assign_if_safe( event->track_startz_f2_, startz_, index_p );
  assign_if_safe( event->track_endy_f2_, endy_, index_p );
  assign_if_safe( event->track_endz_f2_, endz_, index_p );
  assign_if_safe( event->track_chi2_proton_0_, pid_p0_, index_p );
  assign_if_safe( event->track_chi2_proton_1_, pid_p1_, index_p );
  assign_if_safe( event->track_chi2_proton_2_, pid_p2_, index_p );

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
  
  if ( is_mc_ ) {
    set_branch( &true_ke_, "true_ke" );
    set_branch( &true_q2_, "true_q2" );
    set_branch( &true_costheta_, "true_costheta" );
  }

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
