#pragma once

// STV analysis includes
#include "XSecAnalyzer/TreeUtils.hh"
#include "Constants.hh"

#include <vector>
#include <map>
#include <string>

// ROOT includes
#include "TVector3.h"

class AnalysisEvent{
public:
  AnalysisEvent() {}
  ~AnalysisEvent() {}

  bool is_mc_ = false;

  // --- Simple Branch Types ---
  Int_t           run = BOGUS_INT;
  Int_t           subrun = BOGUS_INT;
  Int_t           event = BOGUS_INT;
  Int_t           evt_gen_nc1p = BOGUS_INT;
  Int_t           evt_gen_nce = BOGUS_INT;

  Float_t         evt_gen_nc1p_q2_gen = BOGUS;
  Float_t         evt_gen_nc1p_q2_ke = BOGUS;
  Float_t         evt_gen_nc1p_stx = BOGUS;
  Float_t         evt_gen_nc1p_sty = BOGUS;
  Float_t         evt_gen_nc1p_stz = BOGUS;
  Float_t         evt_gen_nc1p_endx = BOGUS;
  Float_t         evt_gen_nc1p_endy = BOGUS;
  Float_t         evt_gen_nc1p_endz = BOGUS;
  Float_t         evt_gen_nc1p_costheta = BOGUS;
  Float_t         evt_gen_nc1p_phi = BOGUS;
  Float_t         evt_gen_nc1p_mom = BOGUS;
  Float_t         evt_gen_nc1p_ke = BOGUS;

  Int_t           evt_gen_nc1p_contained = BOGUS_INT;
  Int_t           evt_gen_nc1p_inFV = BOGUS_INT;
  Int_t           evt_reco_1p_nu = BOGUS_INT;
  Int_t           evt_reco_1p_non_nu = BOGUS_INT;
  Int_t           evt_reco_1p = BOGUS_INT;
  Int_t           evt_reco_1mu1p = BOGUS_INT;
  Int_t           nflashes = BOGUS_INT;
  Int_t           evt_n_pfp = BOGUS_INT;
  Int_t           evt_n_trk = BOGUS_INT;
  Int_t           evt_n_shower = BOGUS_INT;
  Int_t           evt_n_nu = BOGUS_INT;
  Int_t           evt_n_nu_pfp = BOGUS_INT;
  Int_t           evt_nu_PDG = BOGUS_INT;

  // --- Vectors (Wrapped in MyPointer) ---
  MyPointer <std::vector<float>>   flash_Ywidth;
  MyPointer <std::vector<float>>   flash_Zwidth;
  MyPointer <std::vector<float>>   flash_Twidth;
  MyPointer <std::vector<float>>   flash_Ycenter;
  MyPointer <std::vector<float>>   flash_Zcenter;
  MyPointer <std::vector<float>>   flash_Time;
  MyPointer <std::vector<float>>   flash_CRThit;
  MyPointer <std::vector<bool>>    flash_CRTveto;
  MyPointer <std::vector<float>>   flash_TotalPE;

  Float_t         flash_brightest_Ywidth = BOGUS;
  Float_t         flash_brightest_Zwidth = BOGUS;
  Float_t         flash_brightest_Twidth = BOGUS;
  Float_t         flash_brightest_Ycenter = BOGUS;
  Float_t         flash_brightest_Zcenter = BOGUS;
  Float_t         flash_brightest_Time = BOGUS;
  Float_t         flash_brightest_CRThit = BOGUS;
  Bool_t          flash_brightest_CRTveto = false;
  Float_t         flash_brightest_TotalPE = BOGUS;

  MyPointer <std::vector<std::vector<float>>> flash_PE_Per_PMT;

  Int_t           mc_ccnc = BOGUS_INT;
  Int_t           mc_mode = BOGUS_INT;
  Int_t           mc_interactiontype = BOGUS_INT;
  Int_t           mc_hitnuc = BOGUS_INT;
  Int_t           mc_hitnuc11 = BOGUS_INT;

  Float_t         mc_hitnuc11_p = BOGUS;
  Float_t         mc_hitnuc11_px = BOGUS;
  Float_t         mc_hitnuc11_py = BOGUS;
  Float_t         mc_hitnuc11_pz = BOGUS;

  Int_t           mc_hitnuc11_nuwro = BOGUS_INT;

  Float_t         mc_hitnuc11_nuwro_p = BOGUS;
  Float_t         mc_hitnuc11_nuwro_px = BOGUS;
  Float_t         mc_hitnuc11_nuwro_py = BOGUS;
  Float_t         mc_hitnuc11_nuwro_pz = BOGUS;
  Float_t         mc_q2 = BOGUS;
  Float_t         mc_nu_vtxx = BOGUS;
  Float_t         mc_nu_vtxy = BOGUS;
  Float_t         mc_nu_vtxz = BOGUS;
  Float_t         mc_nu_vtxx_sce = BOGUS;
  Float_t         mc_nu_vtxy_sce = BOGUS;
  Float_t         mc_nu_vtxz_sce = BOGUS;
  Float_t         mc_enu = BOGUS;
  Float_t         mc_wgt_v4a = BOGUS;
  Float_t         mc_wgt_tunedcv = BOGUS;

  Int_t           evtwgt_genie_ncel_nfunc = BOGUS_INT;

  MyPointer <std::vector<std::string>>            evtwgt_genie_ncel_funcname;
  MyPointer <std::vector<int>>                    evtwgt_genie_ncel_nweight;
  MyPointer <std::vector<std::vector<double>>>    evtwgt_genie_ncel_weight;

  Int_t           evtwgt_genie_pm1_nfunc = BOGUS_INT;

  MyPointer <std::vector<std::string>>                evtwgt_genie_pm1_funcname;
  MyPointer <std::vector<int>>                        evtwgt_genie_pm1_nweight;
  MyPointer <std::vector<std::vector<double>>>        evtwgt_genie_pm1_weight;

  Int_t           evtwgt_genie_multisim_nfunc = BOGUS_INT;

  MyPointer <std::vector<std::string>>                evtwgt_genie_multisim_funcname;
  MyPointer <std::vector<int>>                        evtwgt_genie_multisim_nweight;
  MyPointer <std::vector<std::vector<double>>>        evtwgt_genie_multisim_weight;

  Int_t           evtwgt_g4_multisim_nfunc = BOGUS_INT;

  MyPointer <std::vector<std::string>>                evtwgt_g4_multisim_funcname;
  MyPointer <std::vector<int>>                        evtwgt_g4_multisim_nweight;
  MyPointer <std::vector<std::vector<double>>>        evtwgt_g4_multisim_weight;

  Int_t           evtwgt_flux_multisim_nfunc = BOGUS_INT;

  MyPointer <std::vector<std::string>>                evtwgt_flux_multisim_funcname;
  MyPointer <std::vector<int>>                        evtwgt_flux_multisim_nweight;
  MyPointer <std::vector<std::vector<double>>>        evtwgt_flux_multisim_weight;

  Int_t           mc_nupdg = BOGUS_INT;
  Int_t           mc_n_muon = BOGUS_INT;
  Int_t           mc_n_proton = BOGUS_INT;
  Int_t           mc_n_photon = BOGUS_INT;
  Int_t           mc_n_pionpm = BOGUS_INT;
  Int_t           mc_n_pion0 = BOGUS_INT;
  Int_t           mc_n_electron = BOGUS_INT;
  Int_t           mc_n_neutron = BOGUS_INT;
  Int_t           mc_nI_n_photon = BOGUS_INT;
  Int_t           mc_nI_n_proton = BOGUS_INT;
  Int_t           mc_nI_n_neutron = BOGUS_INT;
  Int_t           mc_n_threshold_muon = BOGUS_INT;
  Int_t           mc_n_threshold_proton = BOGUS_INT;
  Int_t           mc_n_threshold_pionpm = BOGUS_INT;
  Int_t           mc_n_threshold_pion0 = BOGUS_INT;
  Int_t           mc_n_threshold_electron = BOGUS_INT;
  Int_t           mc_n_threshold_neutron = BOGUS_INT;

  MyPointer <std::vector<float>>          mc_g4_mom;
  MyPointer <std::vector<float>>          mc_g4_E;
  MyPointer <std::vector<float>>          mc_g4_p;
  MyPointer <std::vector<float>>          mc_g4_mass;
  MyPointer <std::vector<float>>          mc_g4_phi;
  MyPointer <std::vector<float>>          mc_g4_theta;
  MyPointer <std::vector<int>>            mc_g4_pdg;
  MyPointer <std::vector<float>>          mc_g4_start_x;
  MyPointer <std::vector<float>>          mc_g4_start_y;
  MyPointer <std::vector<float>>          mc_g4_start_z;
  MyPointer <std::vector<float>>          mc_g4_end_x;
  MyPointer <std::vector<float>>          mc_g4_end_y;
  MyPointer <std::vector<float>>          mc_g4_end_z;
  MyPointer <std::vector<float>>          mc_g4_photon_E;
  MyPointer <std::vector<float>>          mc_g4_photon_start_x;
  MyPointer <std::vector<float>>          mc_g4_photon_start_y;
  MyPointer <std::vector<float>>          mc_g4_photon_start_z;
  MyPointer <std::vector<float>>          mc_g4_photon_end_x;
  MyPointer <std::vector<float>>          mc_g4_photon_end_y;
  MyPointer <std::vector<float>>          mc_g4_photon_end_z;
  MyPointer <std::vector<float>>          mc_g4_proton_E;
  MyPointer <std::vector<float>>          mc_g4_proton_start_x;
  MyPointer <std::vector<float>>          mc_g4_proton_start_y;
  MyPointer <std::vector<float>>          mc_g4_proton_start_z;
  MyPointer <std::vector<float>>          mc_g4_proton_end_x;
  MyPointer <std::vector<float>>          mc_g4_proton_end_y;
  MyPointer <std::vector<float>>          mc_g4_proton_end_z;
  MyPointer <std::vector<float>>          mc_g4_neutron_E;
  MyPointer <std::vector<float>>          mc_g4_neutron_start_x;
  MyPointer <std::vector<float>>          mc_g4_neutron_start_y;
  MyPointer <std::vector<float>>          mc_g4_neutron_start_z;
  MyPointer <std::vector<float>>          mc_g4_neutron_end_x;
  MyPointer <std::vector<float>>          mc_g4_neutron_end_y;
  MyPointer <std::vector<float>>          mc_g4_neutron_end_z;

  MyPointer <std::vector<float>>          mc_g4_nI_photon_E;
  MyPointer <std::vector<float>>          mc_g4_nI_photon_start_x;
  MyPointer <std::vector<float>>          mc_g4_nI_photon_start_y;
  MyPointer <std::vector<float>>          mc_g4_nI_photon_start_z;
  MyPointer <std::vector<float>>          mc_g4_nI_photon_end_x;
  MyPointer <std::vector<float>>          mc_g4_nI_photon_end_y;
  MyPointer <std::vector<float>>          mc_g4_nI_photon_end_z;
  MyPointer <std::vector<float>>          mc_g4_nI_proton_E;
  MyPointer <std::vector<float>>          mc_g4_nI_proton_start_x;
  MyPointer <std::vector<float>>          mc_g4_nI_proton_start_y;
  MyPointer <std::vector<float>>          mc_g4_nI_proton_start_z;
  MyPointer <std::vector<float>>          mc_g4_nI_proton_end_x;
  MyPointer <std::vector<float>>          mc_g4_nI_proton_end_y;
  MyPointer <std::vector<float>>          mc_g4_nI_proton_end_z;
  MyPointer <std::vector<float>>          mc_g4_nI_neutron_E;
  MyPointer <std::vector<float>>          mc_g4_nI_neutron_start_x;
  MyPointer <std::vector<float>>          mc_g4_nI_neutron_start_y;
  MyPointer <std::vector<float>>          mc_g4_nI_neutron_start_z;
  MyPointer <std::vector<float>>          mc_g4_nI_neutron_end_x;
  MyPointer <std::vector<float>>          mc_g4_nI_neutron_end_y;
  MyPointer <std::vector<float>>          mc_g4_nI_neutron_end_z;

  MyPointer <std::vector<float>>          mc_g4_start_x_sce;
  MyPointer <std::vector<float>>          mc_g4_start_y_sce;
  MyPointer <std::vector<float>>          mc_g4_start_z_sce;
  MyPointer <std::vector<float>>          mc_g4_end_x_sce;
  MyPointer <std::vector<float>>          mc_g4_end_y_sce;
  MyPointer <std::vector<float>>          mc_g4_end_z_sce;
  MyPointer <std::vector<bool>>           is_from_nu_slice;
  MyPointer <std::vector<bool>>           is_primary;
  MyPointer <std::vector<bool>>           is_contained;
  MyPointer <std::vector<bool>>           is_st;
  MyPointer <std::vector<bool>>           is_nc1p;
  MyPointer <std::vector<bool>>           is_reco_nc1p;
  MyPointer <std::vector<int>>            mc_pdg;
  MyPointer <std::vector<int>>            mc_primary;
  MyPointer <std::vector<int>>            mc_origin;
  MyPointer <std::vector<float>>          mc_length;
  MyPointer <std::vector<float>>          mc_start_x;
  MyPointer <std::vector<float>>          mc_start_y;
  MyPointer <std::vector<float>>          mc_start_z;
  MyPointer <std::vector<float>>          mc_end_x;
  MyPointer <std::vector<float>>          mc_end_y;
  MyPointer <std::vector<float>>          mc_end_z;
  MyPointer <std::vector<float>>          mc_start_x_sce;
  MyPointer <std::vector<float>>          mc_start_y_sce;
  MyPointer <std::vector<float>>          mc_start_z_sce;
  MyPointer <std::vector<float>>          mc_end_x_sce;
  MyPointer <std::vector<float>>          mc_end_y_sce;
  MyPointer <std::vector<float>>          mc_end_z_sce;
  MyPointer <std::vector<float>>          mc_theta;
  MyPointer <std::vector<float>>          mc_phi;
  MyPointer <std::vector<float>>          mc_ke;
  MyPointer <std::vector<float>>          mc_mom;
  MyPointer <std::vector<int>>            n_pfp;
  MyPointer <std::vector<int>>            n_trk;
  MyPointer <std::vector<int>>            id_pfp;
  MyPointer <std::vector<int>>            isinFV;
  MyPointer <std::vector<int>>            n_shower;
  MyPointer <std::vector<int>>            parentPDG;
  MyPointer <std::vector<float>>          trk_score;
  MyPointer <std::vector<float>>          KE_len;
  MyPointer <std::vector<float>>          dislen_ratio;
  MyPointer <std::vector<float>>          reco_q2;
  MyPointer <std::vector<float>>          top_score;
  MyPointer <std::vector<float>>          flash_score;
  MyPointer <std::vector<int>>            n_daughters;
  MyPointer <std::vector<bool>>           has_shower;

  Float_t         reco_nu_vtxx = BOGUS;
  Float_t         reco_nu_vtxy = BOGUS;
  Float_t         reco_nu_vtxz = BOGUS;

  MyPointer <std::vector<float>>          deltaY;
  MyPointer <std::vector<float>>          deltaZ;
  MyPointer <std::vector<float>>          deltaYSigma;
  MyPointer <std::vector<float>>          deltaZSigma;
  MyPointer <std::vector<float>>          chargeToLightRatio;
  MyPointer <std::vector<float>>          xclVariable;
  MyPointer <std::vector<bool>>           flip_0;
  MyPointer <std::vector<bool>>           flip_1;
  MyPointer <std::vector<bool>>           flip_2;
  MyPointer <std::vector<float>>          reco_length;
  MyPointer <std::vector<float>>          reco_start_x;
  MyPointer <std::vector<float>>          reco_start_y;
  MyPointer <std::vector<float>>          reco_start_z;
  MyPointer <std::vector<float>>          reco_end_x;
  MyPointer <std::vector<float>>          reco_end_y;
  MyPointer <std::vector<float>>          reco_end_z;
  MyPointer <std::vector<float>>          reco_theta;
  MyPointer <std::vector<float>>          reco_phi;
  MyPointer <std::vector<float>>          reco_start_x_f2;
  MyPointer <std::vector<float>>          reco_start_y_f2;
  MyPointer <std::vector<float>>          reco_start_z_f2;
  MyPointer <std::vector<float>>          reco_end_x_f2;
  MyPointer <std::vector<float>>          reco_end_y_f2;
  MyPointer <std::vector<float>>          reco_end_z_f2;
  MyPointer <std::vector<float>>          reco_theta_f2;
  MyPointer <std::vector<float>>          reco_phi_f2;
  MyPointer <std::vector<float>>          reco_ke;
  MyPointer <std::vector<float>>          reco_mom;
  MyPointer <std::vector<float>>          reco_mom_muon;
  MyPointer <std::vector<float>>          reco_mom_proton;
  MyPointer <std::vector<float>>          reco_mom_pion;
  MyPointer <std::vector<int>>            nhits_0;
  MyPointer <std::vector<int>>            nhits_1;
  MyPointer <std::vector<int>>            nhits_2;
  MyPointer <std::vector<float>>          chi2_p_0;
  MyPointer <std::vector<float>>          chi2_p_1;
  MyPointer <std::vector<float>>          chi2_p_2;

  MyPointer <std::vector<float>>          start_dedx_0;
  MyPointer <std::vector<float>>          start_dedx_1;
  MyPointer <std::vector<float>>          start_dedx_2;
  MyPointer <std::vector<float>>          end_dedx_0;
  MyPointer <std::vector<float>>          end_dedx_1;
  MyPointer <std::vector<float>>          end_dedx_2;
  MyPointer <std::vector<float>>          start_dedx_0_f2;
  MyPointer <std::vector<float>>          start_dedx_1_f2;
  MyPointer <std::vector<float>>          start_dedx_2_f2;
  MyPointer <std::vector<float>>          end_dedx_0_f2;
  MyPointer <std::vector<float>>          end_dedx_1_f2;
  MyPointer <std::vector<float>>          end_dedx_2_f2;
  MyPointer <std::vector<float>>          ratio_dedx_0;
  MyPointer <std::vector<float>>          ratio_dedx_1;
  MyPointer <std::vector<float>>          ratio_dedx_2;
  MyPointer <std::vector<float>>          avg_dedx_0;
  MyPointer <std::vector<float>>          avg_dedx_1;
  MyPointer <std::vector<float>>          avg_dedx_2;
  MyPointer <std::vector<float>>          total_dedx_0;
  MyPointer <std::vector<float>>          total_dedx_1;
  MyPointer <std::vector<float>>          total_dedx_2;

  Int_t           nclusters = BOGUS_INT;
  Int_t           nclustersps = BOGUS_INT;
  MyPointer <std::vector<int>>            cluster_ID;
  MyPointer <std::vector<int>>            cluster_plane;
  MyPointer <std::vector<float>>          cluster_start_charge;
  MyPointer <std::vector<float>>          cluster_start_angle;
  MyPointer <std::vector<float>>          cluster_end_charge;
  MyPointer <std::vector<float>>          cluster_end_angle;
  MyPointer <std::vector<float>>          cluster_integral;
  MyPointer <std::vector<float>>          cluster_integral_average;
  MyPointer <std::vector<float>>          cluster_summedADC;
  MyPointer <std::vector<float>>          cluster_summedADC_average;
  MyPointer <std::vector<float>>          cluster_width;
  MyPointer <std::vector<int>>            cluster_nhits;
  MyPointer <std::vector<int>>            cluster_start_wire;
  MyPointer <std::vector<int>>            cluster_start_tick;
  MyPointer <std::vector<int>>            cluster_end_wire;
  MyPointer <std::vector<int>>            cluster_end_tick;
  MyPointer <std::vector<float>>          cluster_sps_x;
  MyPointer <std::vector<float>>          cluster_sps_y;
  MyPointer <std::vector<float>>          cluster_sps_z;

  Int_t           nblips = BOGUS_INT;
  MyPointer <std::vector<float>>          blip_x;
  MyPointer <std::vector<float>>          blip_y;
  MyPointer <std::vector<float>>          blip_z;
  MyPointer <std::vector<int>>            blip_plane_0;
  MyPointer <std::vector<int>>            blip_plane_1;
  MyPointer <std::vector<int>>            blip_plane_2;
  MyPointer <std::vector<float>>          blip_charge_0;
  MyPointer <std::vector<float>>          blip_charge_1;
  MyPointer <std::vector<float>>          blip_charge_2;
  MyPointer <std::vector<int>>            blip_ID;
  MyPointer <std::vector<bool>>           blip_isValid;
  MyPointer <std::vector<int>>            blip_nplanes;
  MyPointer <std::vector<float>>          blip_maxdiff;
  MyPointer <std::vector<int>>            blip_tpc;
  MyPointer <std::vector<float>>          blip_energy;
  MyPointer <std::vector<float>>          blip_energy_estar;
  MyPointer <std::vector<bool>>           blip_incylinder;
  MyPointer <std::vector<int>>            blip_trkid;
  MyPointer <std::vector<float>>          blip_trkdist;
  MyPointer <std::vector<int>>            blip_pdg;
  MyPointer <std::vector<std::string>>    blip_process;

  MyPointer <std::vector<float>>          blip_vx;
  MyPointer <std::vector<float>>          blip_vy;
  MyPointer <std::vector<float>>          blip_vz;
  MyPointer <std::vector<float>>          blip_E;
  MyPointer <std::vector<float>>          blip_mass;
  MyPointer <std::vector<std::string>>    blip_mom_process;
  MyPointer <std::vector<int>>            blip_mom_pdg;
  MyPointer <std::vector<float>>          blip_mom_vx;
  MyPointer <std::vector<float>>          blip_mom_vy;
  MyPointer <std::vector<float>>          blip_mom_vz;
  MyPointer <std::vector<float>>          blip_mom_E;
  MyPointer <std::vector<float>>          blip_mom_mass;
  MyPointer <std::vector<std::string>>    blip_grandmom_process;
  MyPointer <std::vector<int>>            blip_grandmom_pdg;
  MyPointer <std::vector<float>>          blip_grandmom_vx;
  MyPointer <std::vector<float>>          blip_grandmom_vy;
  MyPointer <std::vector<float>>          blip_grandmom_vz;
  MyPointer <std::vector<float>>          blip_grandmom_E;
  MyPointer <std::vector<float>>          blip_grandmom_mass;
  MyPointer <std::vector<std::string>>    blip_greatgrandmom_process;
  MyPointer <std::vector<int>>            blip_greatgrandmom_pdg;
  MyPointer <std::vector<float>>          blip_greatgrandmom_vx;
  MyPointer <std::vector<float>>          blip_greatgrandmom_vy;
  MyPointer <std::vector<float>>          blip_greatgrandmom_vz;
  MyPointer <std::vector<float>>          blip_greatgrandmom_E;
  MyPointer <std::vector<float>>          blip_greatgrandmom_mass;

  // NC1p variables

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
};
