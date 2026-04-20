#pragma once

#include "XSecAnalyzer/Selections/SelectionBase.hh"
#include "TMVA/Reader.h"

class NC1p : public SelectionBase {

public:

  NC1p();
  virtual ~NC1p() = default;

  virtual bool selection( AnalysisEvent* event ) override;
  virtual int categorize_event( AnalysisEvent* event ) override;
  virtual void compute_reco_observables( AnalysisEvent* event ) override;
  virtual void compute_true_observables( AnalysisEvent* event ) override;
  virtual void define_output_branches() override;
  virtual bool define_signal( AnalysisEvent* event ) override;
  virtual void define_constants() override;
  virtual void reset() override;
  virtual void define_category_map() override;

  void LoadBDTWeights( int run );

protected:

  TMVA::Reader* bdt_reader_;
  int current_run_;

  // BDT variables
  float len_, theta_, phi_, dedx_end2_, dedx_total2_, starty_, startz_, endy_, endz_, pid_p0_, pid_p1_, pid_p2_, trk_dis_;
  float bdt_score_;

  // Selection flags
  bool sel_ntrack_eq_1_;
  bool sel_in_fv_;
  bool sel_bdt_cut_;

  // Reco observables
  float reco_ke_;
  float reco_q2_;
  float reco_costheta_;

  // True observables
  float true_ke_;
  float true_q2_;
  float true_costheta_;

  // Signal definition flags
  bool sig_is_nc1p_;
};
