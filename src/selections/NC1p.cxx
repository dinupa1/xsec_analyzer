#include "XSecAnalyzer/Selections/NC1p.hh"
#include <iostream>

NC1p::NC1p() : SelectionBase( "NC1p" ) {
}

void NC1p::define_constants() {
    // Define specific constants if needed, or use those from Constants.hh
}

void NC1p::reset() {
    // Reset all flags and variables
    sig_is_nc_ = false;
    sig_one_proton_ = false;
    sig_no_muon_ = false;
    sig_no_pions_ = false;
    sig_is_nu_pdg_ = false;
    sig_in_fv_ = false;

    sel_reco_1p_ = false;
    sel_in_fv_ = false;
    sel_containment_ = false;
    sel_track_quality_ = false;
    sel_pid_cut_ = false;
    sel_bdt_cut_ = false;
    sel_blip_cut_ = false;

    proton_candidate_idx_ = BOGUS_INDEX;

    reco_proton_ke_ = BOGUS;
    reco_q2_ = BOGUS;
    reco_proton_mom_ = BOGUS;
    reco_costheta_ = BOGUS;
    reco_length_ = BOGUS;
    reco_bdt_score_ = BOGUS;

    true_proton_ke_ = BOGUS;
    true_q2_ = BOGUS;
    true_proton_mom_ = BOGUS;
    true_costheta_ = BOGUS;
}

void NC1p::define_category_map() {
    // Mapping based on make_tree.C FillSubCat logic
    category_map_[10] = "NC1p Signal";
    category_map_[8]  = "NC1p NCE Signal";
    category_map_[9]  = "NC1p Non-NCE Signal";
    category_map_[7]  = "NC Other";
    category_map_[4]  = "CC Background"; // mc_ccnc == 0
    category_map_[5]  = "Non-Proton";
    category_map_[6]  = "Non-Nu Origin";
    category_map_[2]  = "NC Out of FV";
}

bool NC1p::define_signal( AnalysisEvent* Event ) {

    // Logic from FillSubCat in make_tree.C

    // Must be neutrino origin
    // Note: make_tree loop checks index, here we generally check the event or specific MC particle.
    // Assuming signal definition is based on the interaction topology:

    sig_is_nc_ = (Event->mc_ccnc == 1);

    // Threshold counts
    sig_no_muon_ = (Event->mc_n_threshold_muon == 0);
    sig_no_pions_ = ((Event->mc_n_threshold_pionpm + Event->mc_n_threshold_pion0) == 0);
    sig_one_proton_ = (Event->mc_n_threshold_proton == 1);

    // 14 is Muon Neutrino
    sig_is_nu_pdg_ = (Event->mc_nupdg == 14 || Event->mc_nupdg == -14);

    // FV Truth Check (cm)
    bool in_x = (Event->mc_nu_vtxx > 10 && Event->mc_nu_vtxx < 246.35);
    bool in_y = (Event->mc_nu_vtxy > -96.5 && Event->mc_nu_vtxy < 96.5);
    bool in_z = (Event->mc_nu_vtxz > 10 && Event->mc_nu_vtxz < 1026.8);
    sig_in_fv_ = (in_x && in_y && in_z);

    // Standard NC1p definition
    bool is_nc1p = sig_is_nc_ && sig_no_muon_ && sig_no_pions_ && sig_one_proton_;

    // Return true if it meets the general signal definition (NC1p in FV)
    return is_nc1p && sig_in_fv_ && sig_is_nu_pdg_;
}

bool NC1p::selection( AnalysisEvent* Event ) {

    // 1. Pre-selection: Must be reconstructed as 1 proton event
    if ( Event->evt_reco_1p != 1 ) return false;
    sel_reco_1p_ = true;

    // 2. Loop over tracks to find the candidate proton
    // Logic from make_tree.C Loop

    // Variables for cuts
    float startx, starty, startz, endx, endy, endz, len, costheta, pid_p2;

    int best_idx = -1;

    // Check if vectors exist
    if ( !Event->reco_length || Event->reco_length->empty() ) return false;

    for ( size_t i = 0; i < Event->reco_length->size(); ++i ) {

        // Must be tagged as NC1p candidate by upstream reco
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
        pid_p2 = Event->chi2_p_2->at(i);

        // FV Cuts (make_tree.C)
        bool s_x = (startx > 10 && startx < 246.35);
        bool e_x = (endx > 10 && endx < 246.35);
        bool s_y = (starty > -96.35 && starty < 96.35);
        bool e_y = (endy > -96.35 && endy < 96.35);
        bool s_z = (startz > 10 && startz < 1026.8);
        bool e_z = (endz > 10 && endz < 1026.8);

        if ( !s_x || !e_x || !s_y || !e_y || !s_z || !e_z ) continue;
        sel_in_fv_ = true;
        sel_containment_ = true; // Implied by start/end checks

        // Track Quality Cuts
        if ( len < 1.2 || len > 200 ) continue;
        if ( costheta < 0 ) continue;
        sel_track_quality_ = true;

        // PID Cut
        if ( pid_p2 > 60 || pid_p2 < 0 ) continue;
        sel_pid_cut_ = true;

        // If passed all, this is our candidate
        best_idx = i;
        break; // Assuming we take the first valid one or there is only one due to evt_reco_1p
    }

    if ( best_idx == -1 ) return false;
    proton_candidate_idx_ = best_idx;

    // 3. BDT Cut (Placeholder logic)
    // make_tree.C calculates BDT on the fly.
    // Here we assume the score needs to be computed or checked.
    // For now, we pass this if we found a candidate, but in full implementation
    // the TMVA reader logic would go here or in compute_reco_observables.
    sel_bdt_cut_ = true; // Placeholder

    // 4. Blip Cut
    // Logic: if(nblip[5]>1 && do_blip1) continue;
    // nblip[5] corresponds to blips with R < 50cm and Z < startZ (upstream)
    // Implementation requires iterating blips.
    // Assuming passed for this skeleton.
    sel_blip_cut_ = true;

    return true;
}

int NC1p::categorize_event( AnalysisEvent* Event ) {
    // Logic from FillSubCat

    if ( Event->mc_origin->size() > 0 && Event->mc_origin->at(0) == 1 ) { // Neutrino origin
        if ( Event->mc_pdg->size() > 0 && Event->mc_pdg->at(0) == 2212 ) { // Proton? (Check index logic)
            // If signal definition passed
            if ( sig_is_nu_pdg_ && sig_in_fv_ && sig_is_nc_ && sig_no_muon_ && sig_no_pions_ && sig_one_proton_ ) {
                // Signal breakdown
                if ( Event->mc_mode == 0 && (Event->mc_hitnuc == 2212 || Event->mc_hitnuc11_nuwro == 2212) ) return 8; // NCE
                return 9; // Non-NCE
            }
            // NC Other
            if ( sig_is_nc_ ) return 7;
            // CC Background
            if ( Event->mc_ccnc == 0 ) return 4;
        }
        else {
            return 5; // Non-proton primary
        }
    }
    return 6; // Non-Nu origin
}

void NC1p::compute_reco_observables( AnalysisEvent* Event ) {
    if ( proton_candidate_idx_ == BOGUS_INDEX ) return;

    int i = proton_candidate_idx_;

    // Formula from make_tree.C
    reco_length_ = Event->reco_length->at(i);

    // KE = 31.3 * Length^0.578 (MeV -> GeV converison handled by /1000)
    reco_proton_ke_ = 31.3 * std::pow(reco_length_, 0.578) / 1000.0;

    // Q2 = 2 * Mn * KE (Mn = 0.938272 GeV)
    reco_q2_ = reco_proton_ke_ * 2.0 * 0.938272;

    reco_proton_mom_ = Event->reco_mom_proton->at(i);
    reco_costheta_ = cos(Event->reco_theta_f2->at(i));
}

void NC1p::compute_true_observables( AnalysisEvent* Event ) {
    // Need to find corresponding MC particle or use global MC vars
    // Assuming 1-to-1 mapping or using first primary for now
    if ( Event->mc_ke->size() > 0 ) {
        // In make_tree.C, true variables often pulled from vectors aligned with reco tracks
        // or specific MC branches.
        int i = (proton_candidate_idx_ != BOGUS_INDEX) ? proton_candidate_idx_ : 0;

        if(i < Event->mc_ke->size()){
            true_proton_ke_ = Event->mc_ke->at(i);
            true_proton_mom_ = Event->mc_mom->at(i);
            true_costheta_ = cos(Event->mc_theta->at(i));
        }
        true_q2_ = Event->mc_q2;
    }
}

void NC1p::define_output_branches() {
    set_branch( &reco_proton_ke_, "reco_proton_ke", "reco_proton_ke/D" );
    set_branch( &reco_q2_, "reco_q2", "reco_q2/D" );
    set_branch( &reco_proton_mom_, "reco_proton_mom", "reco_proton_mom/D" );
    set_branch( &reco_costheta_, "reco_costheta", "reco_costheta/D" );

    set_branch( &true_proton_ke_, "true_proton_ke", "true_proton_ke/D" );
    set_branch( &true_q2_, "true_q2", "true_q2/D" );

    set_branch( &sig_is_nc_, "sig_is_nc", "sig_is_nc/O" );
    set_branch( &sig_one_proton_, "sig_one_proton", "sig_one_proton/O" );
    set_branch( &sel_reco_1p_, "sel_reco_1p", "sel_reco_1p/O" );
}
