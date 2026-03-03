// XSecAnalyzer includes
#include "XSecAnalyzer/Binning/NC1pBinScheme.hh"

NC1pBinScheme::NC1pBinScheme() : BinSchemeBase( "NC1pBinScheme" ) {}

void NC1pBinScheme::DefineBlocks() {

  /////// Set some standard variables before managing the blocks

  // TTree name for the post-processed ntuples
  ntuple_ttree_name_ = "nc1p_tree";

  // Run numbers to use when plotting migration matrices
  runs_to_use_ = { 1 };

  // Prefix for the output bin and slice configuration text files
  out_config_prefix_ = "nc1p_";

  // Selection to use with this binning scheme
  selection_name_ = "NC1p";

  // TDirectory file name to use when producing the univmake output histograms
  out_tdir_name_ = "nc1p_1D";

  /////// Define the blocks of bins in both true and reco space

  // First block: cos_theta in 1D
  std::vector< double > cos_theta_1D_edges = {-1.0, 0.0, 0.3, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1};

  Block1D* b1t = new Block1D( "true_costheta",
    "cos#theta", "\\cos\\theta_{\\mu}", cos_theta_1D_edges,
    "NC1p_MC_Signal", kSignalTrueBin );

  Block1D* b1r = new Block1D( "reco_costheta",
    "muon cos#theta", "\\cos\\theta", cos_theta_1D_edges,
    "NC1p_Selected", kOrdinaryRecoBin );

  vect_block.emplace_back( b1t, b1r );

  // Second block: KE in 1D
  std::vector< double > ke_1D_edges = {0.0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.4, 0.5, 0.6};

  Block1D* b2t = new Block1D( "true_proton_ke",
    "p_{#mu}; (GeV)", "K.E.; [GeV]", ke_1D_edges,
    "NC1p_MC_Signal", kSignalTrueBin );

  Block1D* b2r = new Block1D( "reco_proton_ke",
    "p_{#mu}; (GeV)", "K.E.; [GeV]", ke_1D_edges,
    "NC1p_Selected", kOrdinaryRecoBin );

  vect_block.emplace_back( b2t, b2r );
}
