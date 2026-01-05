#pragma once

// XSecAnalyzer includes
#include "XSecAnalyzer/Selections/SelectionBase.hh"

class NC1p : public SelectionBase {

public:

    NC1p();

    virtual int categorize_event( AnalysisEvent* Event ) override final;
    virtual bool selection( AnalysisEvent* Event ) override final;
    virtual bool define_signal( AnalysisEvent* Event ) override final;
    virtual void compute_reco_observables( AnalysisEvent* Event ) override final;
    virtual void compute_true_observables( AnalysisEvent* Event ) override final;
    virtual void define_output_branches() override final;
    virtual void define_constants() override final;
    virtual void define_category_map() override final;
    virtual void reset() override final;

private:

    // --- Signal Definition Flags ---
    bool sig_is_nc_;
    bool sig_one_proton_;
    bool sig_no_muon_;
    bool sig_no_pions_;
    bool sig_is_nu_pdg_;
    bool sig_in_fv_;

    // --- Selection Flags ---
    bool sel_reco_1p_;           // Corresponds to evt_reco_1p == 1
    bool sel_in_fv_;             // Proton start/end inside FV
    bool sel_containment_;       // Proton contained
    bool sel_track_quality_;     // Length and angle cuts
    bool sel_pid_cut_;           // chi2_p_2 cut
    bool sel_bdt_cut_;           // Custom BDT score cut
    bool sel_blip_cut_;          // Upstream blip cut

    // --- Candidate Indices ---
    int proton_candidate_idx_;

    // --- Reconstructed Observables ---
    double reco_proton_ke_;      // Calculated: 31.3 * pow(len, 0.578) / 1000
    double reco_q2_;             // Calculated: 2 * Mn * KE
    double reco_proton_mom_;
    double reco_costheta_;
    double reco_length_;
    double reco_bdt_score_;      // Place holder for BDT calculation

    // --- True Observables ---
    double true_proton_ke_;
    double true_q2_;
    double true_proton_mom_;
    double true_costheta_;

};
