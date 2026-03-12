#include "XSecAnalyzer/Selections/NC1p.hh"
#include <iostream>
#include <cmath>
#include <unistd.h>
#include "TColor.h"

NC1p::NC1p() : SelectionBase( "NC1p" ){

    // 1. Initialize TMVA Reader
    bdt_reader_ = new TMVA::Reader( "!Color:!Silent" );

    // 2. Add Variables (Names match XML)
    bdt_reader_->AddVariable( "reco_length",  &tmva_reco_length_ );
    bdt_reader_->AddVariable( "reco_theta",   &tmva_reco_theta_ );
    bdt_reader_->AddVariable( "reco_phi",     &tmva_reco_phi_ );
    bdt_reader_->AddVariable( "end_dedx_2",   &tmva_end_dedx_2_ );
    bdt_reader_->AddVariable( "total_dedx_2", &tmva_total_dedx_2_ );
    bdt_reader_->AddVariable( "reco_start_y", &tmva_reco_start_y_ );
    bdt_reader_->AddVariable( "reco_start_z", &tmva_reco_start_z_ );
    bdt_reader_->AddVariable( "reco_end_y",   &tmva_reco_end_y_ );
    bdt_reader_->AddVariable( "reco_end_z",   &tmva_reco_end_z_ );
    bdt_reader_->AddVariable( "chi2_p_0",     &tmva_chi2_p_0_ );
    bdt_reader_->AddVariable( "chi2_p_1",     &tmva_chi2_p_1_ );
    bdt_reader_->AddVariable( "chi2_p_2",     &tmva_chi2_p_2_ );
    bdt_reader_->AddVariable( "trk_dis",      &tmva_trk_dis_ );

    current_run_ = -1;
    // Default fallback
    sample_type_ = "overlay_genie320_precompound_hadronhp";

    out_file.open(filename, std::ios::out | std::ios::trunc);
    if (!out_file.is_open()) {
        std::cerr << " > Error: Could not open file " << filename << std::endl;
    }
}

NC1p::~NC1p() {
    if (bdt_reader_) delete bdt_reader_;
    if(out_file.is_open()) out_file.close();
}

void NC1p::reset(AnalysisEvent* Event) {
    Event->is_mc_ = false;
    Event->sig_is_nc_ = false;
    Event->sig_one_proton_ = false;
    Event->sig_no_muon_ = false;
    Event->sig_no_pions_ = false;
    Event->sig_is_nu_pdg_ = false;
    Event->sig_in_fv_ = false;

    Event->sel_reco_1p_ = false;
    Event->sel_in_fv_ = false;
    Event->sel_containment_ = false;
    Event->sel_track_quality_ = false;
    Event->sel_pid_cut_ = false;
    Event->sel_bdt_cut_ = false;
    Event->sel_blip_cut_ = false;

    Event->proton_candidate_idx_ = BOGUS_INDEX;
    Event->reco_trk_dis_ = 999.0;
    Event->reco_nblip_upstream_ = 0;

    Event->reco_proton_ke_ = BOGUS;
    Event->reco_q2_ = BOGUS;
    Event->reco_proton_mom_ = BOGUS;
    Event->reco_costheta_ = BOGUS;
    Event->reco_length_ = BOGUS;
    Event->reco_bdt_score_ = BOGUS;
    Event->computed_weight_->clear();
    Event->computed_weight_->push_back( 1.0 );

    Event->true_proton_ke_ = BOGUS;
    Event->true_q2_ = BOGUS;
    Event->true_proton_mom_ = BOGUS;
    Event->true_costheta_ = BOGUS;
}

void NC1p::define_constants() {}

void NC1p::define_category_map() {
    categ_map_[10] = { "NC1p Signal", kRed };
    categ_map_[8]  = { "NC1p NCE Signal", kRed + 2 };
    categ_map_[9]  = { "NC1p Non-NCE Signal", kMagenta };
    categ_map_[7]  = { "NC Other", kOrange };
    categ_map_[4]  = { "CC Background", kBlue };
    categ_map_[3]  = { "NC Background", kCyan };
    categ_map_[5]  = { "Non-Proton Primary", kGreen };
    categ_map_[6]  = { "Non-Nu Origin", kGray };
    categ_map_[2]  = { "NC Out of FV", kYellow };
}

double NC1p::POTwgt(int ri, std::string type) {
    double wgt = 1.0;
    const double pot_overlay_s2[5] = {1, 6.538, 6.523, 7.349, 1};
    const double pot_overlay_s2_wgt[5] = {1, 6.5379, 6.523879, 7.14304, 1};
    const double pot_overlay_def[5] = {1, 5.5525, 1, 1, 1};
    const double pot_overlay_pre[5] = {1, 5.5448, 1, 1, 1};
    const double pot_overlay_pre_hhp_wgt[5] = {1, 5.307, 5.867, 5.325, 1};
    const double pot_overlay_pre_hhp[5] = {1, 5.52642, 5.8665, 5.4889, 1};
    const double pot_dirt_pre_hhp[5] = {1, 1.40837, 1.67329, 1.61019, 1};
    const double pot_overlay_outtpc_pre_hhp[5] = {1, 2.009894, 1.290968, 2.094839, 1};
    const double pot_overlay_def_hhp[5] = {1, 5.591, 5.915, 5.476, 1};
    const double pot_dirt[5] = {1, 3.256179, 9.531478, 3.355448, 1};
    const double pot_bnb[5] = {1, 1.686, 3.043, 2.218, 1};
    const double trig_bnb[5]={1,34766141.0,62279349.0,61510773.0,1};
    const double trig_extbnb[5]={1,34151572.0,151507351.0,166840107.0 ,1};

    if (ri < 0 || ri > 4) return 1.0;

    if (type.find("overlay_s2") != std::string::npos) wgt = pot_bnb[ri] / pot_overlay_s2[ri];
    else if (type.find("overlay_genie320_default") != std::string::npos && type.find("hadronhp") == std::string::npos) wgt = pot_bnb[ri] / pot_overlay_def[ri];
    else if (type.find("overlay_genie320_precompound") != std::string::npos && type.find("hadronhp") == std::string::npos) wgt = pot_bnb[ri] / pot_overlay_pre[ri];
    else if (type.find("overlay_genie320_default_hadronhp") != std::string::npos) wgt = pot_bnb[ri] / pot_overlay_def_hhp[ri];
    else if (type == "overlay_genie320_precompound_hadronhp") wgt = pot_bnb[ri] / pot_overlay_pre_hhp[ri];
    else if (type.find("outtpc_overlay") != std::string::npos) wgt = pot_bnb[ri] / pot_overlay_outtpc_pre_hhp[ri];
    else if (type.find("dirt_genie320_precompound_hadronhp") != std::string::npos) wgt = pot_bnb[ri] / pot_dirt_pre_hhp[ri];
    else if (type.find("overlay_genie_fsi") != std::string::npos) wgt = pot_bnb[ri] / pot_overlay_s2_wgt[ri];
    else if (type == "dirt") wgt = pot_bnb[ri] / pot_dirt[ri];
    else if(type=="extbnb")     wgt = trig_bnb[ri]/trig_extbnb[ri];
    else if (type == "bnb") wgt = 1.0;

    return wgt;
}

double NC1p::CalWeight(AnalysisEvent* Event, int run_id) {
    double pot_scale = POTwgt(run_id, sample_type_);
    double cv_weight = 1.0;
    if (Event->mc_wgt_tunedcv != BOGUS && Event->mc_wgt_tunedcv > -100) {
        // cv_weight = Event->mc_wgt_tunedcv;
    }
    return 1.0; //pot_scale * cv_weight;
}

void NC1p::LoadBDTWeights(int run) {
    TString weight_path = Form("/exp/uboone/app/users/renlu23/v61_2022/analysis/BDT/dataset/weights_%d/TMVAClassification_BDTG.weights.xml", run);
    if ( access( weight_path.Data(), F_OK ) != -1 ) {
        std::cout << "[NC1p] Loading BDT weights for Run " << run << " from: " << weight_path << std::endl;
        bdt_reader_->BookMVA( "BDTG", weight_path.Data() );
    } else {
        std::cerr << "[NC1p] WARNING: BDT Weight file not found: " << weight_path << std::endl;
    }
}

float NC1p::ClusterTrackDistance(float vx, float vy, float vz, float cx, float cy, float cz) {
    return std::sqrt(std::pow(vx - cx, 2) + std::pow(vy - cy, 2) + std::pow(vz - cz, 2));
}

/*
int NC1p::VertexIsInFV(float st_x, float st_y, float st_z) {
    const float xmin = 0, xmax = 256.35;
    const float ymin = -116.35, ymax = 116.35;
    const float zmin = 0, zmax = 1036.8;
    const float b_xz = 10, b_y = 20;

    // 1. Standard Rectangular Box Cut
    if (st_x < xmin + b_xz || st_x > xmax - b_xz) return -1;
    if (st_y < ymin + b_y  || st_y > ymax - b_y ) return -1;
    if (st_z < zmin + b_xz || st_z > zmax - b_xz) return -1;

    // 2. Specific Geometric "Dead Region" Checks (from make_tree.C)
    // These exclude regions with dead wires or TPC edge effects
    if (st_y - 0.6 * st_z > -186 && st_y - 0.6 * st_z < -120) return 1;
    if (st_y - 0.6 * st_z < -207 && st_y + 0.6 * st_z < 434 && st_z < 700) return 2;
    if (st_z > 740 && st_y + 0.6 * st_z > 454) return 3;
    if (st_y + 0.6 * st_z > 454 && st_z < 700) return 4;
    if (st_y + 0.6 * st_z < 434 && st_z > 740) return 5;

    return 0; // 0 = Purely inside the Fiducial Volume
}
*/

int NC1p::VertexIsInFV(float st_x, float st_y, float st_z) {
    int passFV = 0;
    const float border_xorz = 10;
    const float border_y = 20;

    if (st_x < 0 + border_xorz) passFV = -1;
    if (st_y < -116.35 + border_y) passFV = -1;
    if (st_z < 0 + border_xorz) passFV = -1;
    if (st_x > 256.35 - border_xorz) passFV = -1;
    if (st_y > 116.35 - border_y) passFV = -1;
    if (st_z > 1036.8 - border_xorz) passFV = -1;

    if (st_y - 0.6*st_z > -186 && st_y - 0.6*st_z < -120) passFV = 1;
    if (st_y - 0.6*st_z < -207 && st_y + 0.6*st_z < 434 && st_z < 700) passFV = 2;
    if (st_z > 740 && st_y + 0.6*st_z > 454) passFV = 3;
    if (st_y + 0.6*st_z > 454 && st_z < 700) passFV = 4;
    if (st_y + 0.6*st_z < 434 && st_z > 740) passFV = 5;

    return passFV;
}

bool NC1p::define_signal( AnalysisEvent* Event ) {
    Event->sig_is_nc_ = (Event->mc_ccnc == 1);
    Event->sig_no_muon_ = (Event->mc_n_threshold_muon == 0);
    Event->sig_no_pions_ = ((Event->mc_n_threshold_pionpm + Event->mc_n_threshold_pion0) == 0);
    Event->sig_one_proton_ = (Event->mc_n_threshold_proton == 1);
    Event->sig_is_nu_pdg_ = (Event->mc_nupdg == 14 || Event->mc_nupdg == -14);

    bool in_x = (Event->mc_nu_vtxx > 10 && Event->mc_nu_vtxx < 246.35);
    bool in_y = (Event->mc_nu_vtxy > -96.5 && Event->mc_nu_vtxy < 96.5);
    bool in_z = (Event->mc_nu_vtxz > 10 && Event->mc_nu_vtxz < 1026.8);
    Event->sig_in_fv_ = (in_x && in_y && in_z);

    bool is_nc1p = Event->sig_is_nc_ && Event->sig_no_muon_ && Event->sig_no_pions_ && Event->sig_one_proton_;
    return is_nc1p && Event->sig_in_fv_ && Event->sig_is_nu_pdg_;
}

bool NC1p::selection( AnalysisEvent* Event, int rid) {
    if ( rid != current_run_ ) {
        LoadBDTWeights(rid);
        current_run_ = rid;
    }

    if ( Event->evt_reco_1p != 1 ) return false;
    Event->sel_reco_1p_ = true;

    float startx, starty, startz, endx, endy, endz, len, costheta;
    int best_idx = -1;
    float best_trk_dis = 999.0;

    if ( !Event->reco_length || Event->reco_length->empty() ) return false;

    for ( size_t i = 0; i < Event->reco_length->size(); ++i ) {
        if ( !Event->is_reco_nc1p->at(i) ) continue;
        if ( Event->isinFV->at(i) <= 0 ) continue;

        startx = Event->reco_start_x_f2->at(i);
        starty = Event->reco_start_y_f2->at(i);
        startz = Event->reco_start_z_f2->at(i);
        endx   = Event->reco_end_x_f2->at(i);
        endy   = Event->reco_end_y_f2->at(i);
        endz   = Event->reco_end_z_f2->at(i);
        len    = Event->reco_length->at(i);
        costheta = cos(Event->reco_theta_f2->at(i));

        float temp_trk_dis = 999.0;
        if ( Event->reco_length->size() > 1 ) {
            for ( size_t j = 0; j < Event->reco_length->size(); ++j ) {
                if ( i == j ) continue;
                float d1 = std::sqrt(std::pow(startx - Event->reco_start_x->at(j), 2) +
                std::pow(starty - Event->reco_start_y->at(j), 2) +
                std::pow(startz - Event->reco_start_z->at(j), 2));
                float d2 = std::sqrt(std::pow(startx - Event->reco_end_x->at(j), 2) +
                std::pow(starty - Event->reco_end_y->at(j), 2) +
                std::pow(startz - Event->reco_end_z->at(j), 2));
                if (d1 < temp_trk_dis) {temp_trk_dis = d1;}
                if (d2 < temp_trk_dis) {temp_trk_dis = d2;}
            }
        }

        if (startx < 10 || startx > 246.35) continue;
        if (endx < 10 || endx > 246.35) continue;
        if (starty < -96.35 || starty > 96.35) continue;
        if (endy < -96.35 || endy > 96.35) continue;
        if (startz < 10 || startz > 1026.8) continue;
        if (endz < 10 || endz > 1026.8) continue;

        if (len < 1.2 || len > 200) continue;
        if (costheta < 0) continue;
        if (Event->chi2_p_2->at(i) > 60 || Event->chi2_p_2->at(i) < 0) continue;

        best_idx = i;
        best_trk_dis = temp_trk_dis;

        // break here to mimic make_tree.C "greedy" selection
        break;
    }

    if ( best_idx == -1 ) return false;

    Event->proton_candidate_idx_ = best_idx;
    Event->reco_trk_dis_ = best_trk_dis;
    Event->sel_in_fv_ = true;
    Event->sel_containment_ = true;
    Event->sel_track_quality_ = true;
    Event->sel_pid_cut_ = true;

    int nblip_5 = 0;
    float p_x = Event->reco_start_x->at(best_idx);
    float p_y = Event->reco_start_y->at(best_idx);
    float p_z = Event->reco_start_z->at(best_idx);

    if ( Event->blip_x && !Event->blip_x->empty() ) {
        for ( size_t k = 0; k < Event->blip_x->size(); ++k ) {
            float bx = Event->blip_x->at(k);
            float by = Event->blip_y->at(k);
            float bz = Event->blip_z->at(k);
            if ( VertexIsInFV(bx, by, bz) > 0 ) {
                float disb = ClusterTrackDistance(p_x, p_y, p_z, bx, by, bz);
                if ( disb < 50.0 ) {
                    if ( bz < p_z ) nblip_5++;
                }
            }
        }
    }
    Event->reco_nblip_upstream_ = nblip_5;

    if ( Event->reco_nblip_upstream_ > 1 ) return false;
    Event->sel_blip_cut_ = true;

    tmva_reco_length_ = Event->reco_length->at(best_idx);
    tmva_reco_theta_  = Event->reco_theta_f2->at(best_idx);
    tmva_reco_phi_    = Event->reco_phi_f2->at(best_idx);
    tmva_end_dedx_2_  = Event->start_dedx_2->at(best_idx);
    tmva_total_dedx_2_= Event->total_dedx_2->at(best_idx);
    tmva_reco_start_y_= Event->reco_start_y->at(best_idx);
    tmva_reco_start_z_= Event->reco_start_z->at(best_idx);
    tmva_reco_end_y_  = Event->reco_end_y->at(best_idx);
    tmva_reco_end_z_  = Event->reco_end_z->at(best_idx);
    tmva_chi2_p_0_    = Event->chi2_p_0->at(best_idx);
    tmva_chi2_p_1_    = Event->chi2_p_1->at(best_idx);
    tmva_chi2_p_2_    = Event->chi2_p_2->at(best_idx);
    tmva_trk_dis_     = Event->reco_trk_dis_;

    Event->reco_bdt_score_ = bdt_reader_->EvaluateMVA("BDTG");

    if ( Event->reco_bdt_score_ < 0.2 ) return false;
    Event->sel_bdt_cut_ = true;

    LogEvent(Event);
    Flush();

    return true;
}

int NC1p::categorize_event( AnalysisEvent* Event ) {

    // This allows SelectionBase to invoke compute_true_observables
    if (Event->mc_ccnc != BOGUS_INT) {
        Event->is_mc_ = true;
    } else {
        Event->is_mc_ = false;
    }

    // Logic from FillSubCat in make_tree.C
    if ( Event->mc_origin->size() > 0 && Event->mc_origin->at(0) == 1 ) {
        if ( Event->mc_pdg->size() > 0 && Event->mc_pdg->at(0) == 2212 ) {
            if ( Event->sig_is_nu_pdg_ && Event->sig_in_fv_ && Event->sig_is_nc_ && Event->sig_no_muon_ && Event->sig_no_pions_ && Event->sig_one_proton_ ) {
                if ( Event->mc_mode == 0 && (Event->mc_hitnuc == 2212 || Event->mc_hitnuc11_nuwro == 2212) ) return 8;
                return 9;
            }
            if ( Event->sig_is_nc_ ) return 7;
            if ( Event->mc_ccnc == 0 ) return 4;
        } else {
            return 5;
        }
    }
    return 6;
}

void NC1p::compute_reco_observables( AnalysisEvent* Event, int run_id) {
    Event->computed_weight_->clear();
    Event->computed_weight_->push_back( CalWeight(Event, run_id) );

    if ( Event->proton_candidate_idx_ == BOGUS_INDEX ) return;

    int i = Event->proton_candidate_idx_;
    Event->reco_length_ = Event->reco_length->at(i);
    Event->reco_proton_ke_ = 31.3 * std::pow(Event->reco_length_, 0.578) / 1000.0;
    Event->reco_q2_ = Event->reco_proton_ke_ * 2.0 * 0.938272;
    Event->reco_proton_mom_ = Event->reco_mom_proton->at(i);
    Event->reco_costheta_ = cos(Event->reco_theta_f2->at(i));
}

void NC1p::compute_true_observables( AnalysisEvent* Event ) {
    int i = (Event->proton_candidate_idx_ != BOGUS_INDEX) ? Event->proton_candidate_idx_ : 0;
    if ( Event->mc_ke && i < Event->mc_ke->size() ) {
        Event->true_proton_ke_ = Event->mc_ke->at(i);
        Event->true_proton_mom_ = Event->mc_mom->at(i);
        Event->true_costheta_ = cos(Event->mc_theta->at(i));
    }
    Event->true_q2_ = Event->mc_q2;
}


void NC1p::define_output_branches() {
    /*
    out_tree_->Branch( "reco_proton_ke", &reco_proton_ke_, "reco_proton_ke/D" );
    out_tree_->Branch( "reco_q2", &reco_q2_, "reco_q2/D" );
    out_tree_->Branch( "reco_proton_mom", &reco_proton_mom_, "reco_proton_mom/D" );
    out_tree_->Branch( "reco_costheta", &reco_costheta_, "reco_costheta/D" );
    out_tree_->Branch( "reco_bdt_score", &reco_bdt_score_, "reco_bdt_score/D" );
    out_tree_->Branch( "computed_weight", &computed_weight_, "computed_weight/D" );

    out_tree_->Branch( "true_proton_ke", &true_proton_ke_, "true_proton_ke/D" );
    out_tree_->Branch( "true_q2", &true_q2_, "true_q2/D" );

    out_tree_->Branch( "sig_is_nc", &sig_is_nc_, "sig_is_nc/O" );
    out_tree_->Branch( "sel_reco_1p", &sel_reco_1p_, "sel_reco_1p/O" );
    out_tree_->Branch( "sel_bdt_cut", &sel_bdt_cut_, "sel_bdt_cut/O" );
    out_tree_->Branch( "sel_blip_cut", &sel_blip_cut_, "sel_blip_cut/O" );
    */
}

void NC1p::LogEvent(AnalysisEvent* Event) {
    if(out_file.is_open()) {
        out_file << Event->event << "\t" << Event->proton_candidate_idx_ << "\t" << Event->sel_reco_1p_ << "\t" << Event->sel_in_fv_ << "\t" << Event->sel_containment_ << "\t" << Event->sel_track_quality_ << "\t" << Event->sel_pid_cut_ << "\t" << Event->sel_blip_cut_ << "\t" << Event->sel_bdt_cut_ << "\n";
    }
}

void NC1p::Flush() {
    out_file.flush();
}
