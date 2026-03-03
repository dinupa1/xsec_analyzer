#pragma once

// XSecAnalyzer includes
#include "XSecAnalyzer/Selections/SelectionBase.hh"

// ROOT & TMVA includes
#include "TMVA/Reader.h"
#include "TString.h"
#include <fstream>
#include <iostream>
#include <string>

class NC1p : public SelectionBase {

public:
    NC1p();
    virtual ~NC1p();

    // Setter for sample type (needed for POT scaling)
    void set_sample_type( std::string type ) { sample_type_ = type; }
    void set_run_id(int rid) {}

    // Standard SelectionBase methods
    virtual int categorize_event( AnalysisEvent* Event ) override final;
    virtual bool selection( AnalysisEvent* Event, int rid) override final;
    virtual bool define_signal( AnalysisEvent* Event ) override final;
    virtual void compute_reco_observables( AnalysisEvent* Event, int rid) override final;
    virtual void compute_true_observables( AnalysisEvent* Event) override final;
    virtual void define_output_branches() override final;
    virtual void define_constants() override final;
    virtual void define_category_map() override final;
    virtual void reset(AnalysisEvent* Event) override final;

private:

    // --- Helpers ---
    void LoadBDTWeights(int run);
    double POTwgt(int run, std::string type);
    double CalWeight(AnalysisEvent* Event, int rid);
    float ClusterTrackDistance(float vx, float vy, float vz, float cx, float cy, float cz);
    int VertexIsInFV(float st_x, float st_y, float st_z);
    void LogEvent(AnalysisEvent* Event);
    void Flush();

    // --- Debug event selection ---
    std::ofstream out_file;
    std::string filename = "r1_bnb.debug";

    // --- Configuration ---
    int current_run_;
    std::string sample_type_;

    // --- TMVA Reader ---
    TMVA::Reader* bdt_reader_;

    // TMVA Float Variables
    float tmva_reco_length_;
    float tmva_reco_theta_;
    float tmva_reco_phi_;
    float tmva_end_dedx_2_;
    float tmva_total_dedx_2_;
    float tmva_reco_start_y_;
    float tmva_reco_start_z_;
    float tmva_reco_end_y_;
    float tmva_reco_end_z_;
    float tmva_chi2_p_0_;
    float tmva_chi2_p_1_;
    float tmva_chi2_p_2_;
    float tmva_trk_dis_;

    /*
    // --- Signal Flags ---
    bool sig_is_nc_;
    bool sig_one_proton_;
    bool sig_no_muon_;
    bool sig_no_pions_;
    bool sig_is_nu_pdg_;
    bool sig_in_fv_;

    // --- Selection Flags ---
    bool sel_reco_1p_;
    bool sel_in_fv_;
    bool sel_containment_;
    bool sel_track_quality_;
    bool sel_pid_cut_;
    bool sel_bdt_cut_;
    bool sel_blip_cut_;

    // --- Internal State ---
    int proton_candidate_idx_;
    float reco_trk_dis_;
    int reco_nblip_upstream_;

    // --- Observables ---
    double reco_proton_ke_;
    double reco_q2_;
    double reco_proton_mom_;
    double reco_costheta_;
    double reco_length_;
    double reco_bdt_score_;
    double computed_weight_;

    double true_proton_ke_;
    double true_q2_;
    double true_proton_mom_;
    double true_costheta_;
    */
};
