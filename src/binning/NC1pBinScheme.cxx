#include "XSecAnalyzer/Binning/NC1pBinScheme.hh"

NC1pBinScheme::NC1pBinScheme() : BinSchemeBase( "NC1pBinScheme" ) {}

void NC1pBinScheme::DefineBlocks() {
  ntuple_ttree_name_ = "stv_tree";
  runs_to_use_ = { 1, 2, 3 };
  out_config_prefix_ = "nc1p_";
  selection_name_ = "NC1p";
  out_tdir_name_ = "nc1p_analysis";

  // Block 1: Kinetic Energy
  std::vector< double > ke_edges = { 0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.4, 0.5, 0.6 };
  Block1D* b1t = new Block1D( "NC1p_true_ke", "Proton Kinetic Energy (GeV)", "T_{p} (GeV)", ke_edges, "NC1p_MC_Signal", kSignalTrueBin );
  Block1D* b1r = new Block1D( "NC1p_reco_ke", "Proton Kinetic Energy (GeV)", "T_{p} (GeV)", ke_edges, "NC1p_Selected", kOrdinaryRecoBin );
  vect_block.emplace_back( b1t, b1r );

  // Block 2: cos(theta)
  std::vector< double > costh_edges = { -1, 0, 0.3, 0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1 };
  Block1D* b2t = new Block1D( "NC1p_true_costheta", "Proton cos#theta", "\\cos\\theta_{p}", costh_edges, "NC1p_MC_Signal", kSignalTrueBin );
  Block1D* b2r = new Block1D( "NC1p_reco_costheta", "Proton cos#theta", "\\cos\\theta_{p}", costh_edges, "NC1p_Selected", kOrdinaryRecoBin );
  vect_block.emplace_back( b2t, b2r );
}
