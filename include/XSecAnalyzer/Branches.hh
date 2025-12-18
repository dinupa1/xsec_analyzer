#pragma once

// ROOT includes
#include "TTree.h"
#include "AnalysisEvent.hh"

void SetBranchAddress(TTree& etree, std::string BranchName, void* Variable) {
  etree.SetBranchAddress(BranchName.c_str(),Variable);
}

// Helper function to set branch addresses for reading information
// from the Event TTree
void set_event_branch_addresses(TTree& etree, AnalysisEvent& ev)
{

  SetBranchAddress(etree, "run", &ev.run);
  SetBranchAddress(etree, "subrun", &ev.subrun);
  SetBranchAddress(etree, "event", &ev.event);
  SetBranchAddress(etree, "evt_gen_nc1p", &ev.evt_gen_nc1p);
  SetBranchAddress(etree, "evt_gen_nce", &ev.evt_gen_nce);
  SetBranchAddress(etree, "evt_gen_nc1p_q2_gen", &ev.evt_gen_nc1p_q2_gen);
  SetBranchAddress(etree, "evt_gen_nc1p_q2_ke", &ev.evt_gen_nc1p_q2_ke);
  SetBranchAddress(etree, "evt_gen_nc1p_stx", &ev.evt_gen_nc1p_stx);
  SetBranchAddress(etree, "evt_gen_nc1p_sty", &ev.evt_gen_nc1p_sty);
  SetBranchAddress(etree, "evt_gen_nc1p_stz", &ev.evt_gen_nc1p_stz);
  SetBranchAddress(etree, "evt_gen_nc1p_endx", &ev.evt_gen_nc1p_endx);
  SetBranchAddress(etree, "evt_gen_nc1p_endy", &ev.evt_gen_nc1p_endy);
  SetBranchAddress(etree, "evt_gen_nc1p_endz", &ev.evt_gen_nc1p_endz);
  SetBranchAddress(etree, "evt_gen_nc1p_costheta", &ev.evt_gen_nc1p_costheta);
  SetBranchAddress(etree, "evt_gen_nc1p_phi", &ev.evt_gen_nc1p_phi);
  SetBranchAddress(etree, "evt_gen_nc1p_mom", &ev.evt_gen_nc1p_mom);
  SetBranchAddress(etree, "evt_gen_nc1p_ke", &ev.evt_gen_nc1p_ke);
  SetBranchAddress(etree, "evt_gen_nc1p_contained", &ev.evt_gen_nc1p_contained);
  SetBranchAddress(etree, "evt_gen_nc1p_inFV", &ev.evt_gen_nc1p_inFV);
  SetBranchAddress(etree, "evt_reco_1p_nu", &ev.evt_reco_1p_nu);
  SetBranchAddress(etree, "evt_reco_1p_non_nu", &ev.evt_reco_1p_non_nu);
  SetBranchAddress(etree, "evt_reco_1p", &ev.evt_reco_1p);
  SetBranchAddress(etree, "evt_reco_1mu1p", &ev.evt_reco_1mu1p);
  SetBranchAddress(etree, "nflashes", &ev.nflashes);
  SetBranchAddress(etree, "evt_n_pfp", &ev.evt_n_pfp);
  SetBranchAddress(etree, "evt_n_trk", &ev.evt_n_trk);
  SetBranchAddress(etree, "evt_n_shower", &ev.evt_n_shower);
  SetBranchAddress(etree, "evt_n_nu", &ev.evt_n_nu);
  SetBranchAddress(etree, "evt_n_nu_pfp", &ev.evt_n_nu_pfp);
  SetBranchAddress(etree, "evt_nu_PDG", &ev.evt_nu_PDG);

  set_object_input_branch_address(etree, "flash_Ywidth", ev.flash_Ywidth);
  set_object_input_branch_address(etree, "flash_Zwidth", ev.flash_Zwidth);
  set_object_input_branch_address(etree, "flash_Twidth", ev.flash_Twidth);
  set_object_input_branch_address(etree, "flash_Ycenter", ev.flash_Ycenter);
  set_object_input_branch_address(etree, "flash_Zcenter", ev.flash_Zcenter);
  set_object_input_branch_address(etree, "flash_Time", ev.flash_Time);
  set_object_input_branch_address(etree, "flash_CRThit", ev.flash_CRThit);
  set_object_input_branch_address(etree, "flash_CRTveto", ev.flash_CRTveto);
  set_object_input_branch_address(etree, "flash_TotalPE", ev.flash_TotalPE);

  SetBranchAddress(etree, "flash_brightest_Ywidth", &ev.flash_brightest_Ywidth);
  SetBranchAddress(etree, "flash_brightest_Zwidth", &ev.flash_brightest_Zwidth);
  SetBranchAddress(etree, "flash_brightest_Twidth", &ev.flash_brightest_Twidth);
  SetBranchAddress(etree, "flash_brightest_Ycenter", &ev.flash_brightest_Ycenter);
  SetBranchAddress(etree, "flash_brightest_Zcenter", &ev.flash_brightest_Zcenter);
  SetBranchAddress(etree, "flash_brightest_Time", &ev.flash_brightest_Time);
  SetBranchAddress(etree, "flash_brightest_CRThit", &ev.flash_brightest_CRThit);
  SetBranchAddress(etree, "flash_brightest_CRTveto", &ev.flash_brightest_CRTveto);
  SetBranchAddress(etree, "flash_brightest_TotalPE", &ev.flash_brightest_TotalPE);

  set_object_input_branch_address(etree, "flash_PE_Per_PMT", ev.flash_PE_Per_PMT);

  SetBranchAddress(etree, "mc_ccnc", &ev.mc_ccnc);
  SetBranchAddress(etree, "mc_mode", &ev.mc_mode);
  SetBranchAddress(etree, "mc_interactiontype", &ev.mc_interactiontype);
  SetBranchAddress(etree, "mc_hitnuc", &ev.mc_hitnuc);
  SetBranchAddress(etree, "mc_hitnuc11", &ev.mc_hitnuc11);
  SetBranchAddress(etree, "mc_hitnuc11_p", &ev.mc_hitnuc11_p);
  SetBranchAddress(etree, "mc_hitnuc11_px", &ev.mc_hitnuc11_px);
  SetBranchAddress(etree, "mc_hitnuc11_py", &ev.mc_hitnuc11_py);
  SetBranchAddress(etree, "mc_hitnuc11_pz", &ev.mc_hitnuc11_pz);
  SetBranchAddress(etree, "mc_hitnuc11_nuwro", &ev.mc_hitnuc11_nuwro);
  SetBranchAddress(etree, "mc_hitnuc11_nuwro_p", &ev.mc_hitnuc11_nuwro_p);
  SetBranchAddress(etree, "mc_hitnuc11_nuwro_px", &ev.mc_hitnuc11_nuwro_px);
  SetBranchAddress(etree, "mc_hitnuc11_nuwro_py", &ev.mc_hitnuc11_nuwro_py);
  SetBranchAddress(etree, "mc_hitnuc11_nuwro_pz", &ev.mc_hitnuc11_nuwro_pz);
  SetBranchAddress(etree, "mc_q2", &ev.mc_q2);
  SetBranchAddress(etree, "mc_nu_vtxx", &ev.mc_nu_vtxx);
  SetBranchAddress(etree, "mc_nu_vtxy", &ev.mc_nu_vtxy);
  SetBranchAddress(etree, "mc_nu_vtxz", &ev.mc_nu_vtxz);
  SetBranchAddress(etree, "mc_nu_vtxx_sce", &ev.mc_nu_vtxx_sce);
  SetBranchAddress(etree, "mc_nu_vtxy_sce", &ev.mc_nu_vtxy_sce);
  SetBranchAddress(etree, "mc_nu_vtxz_sce", &ev.mc_nu_vtxz_sce);
  SetBranchAddress(etree, "mc_enu", &ev.mc_enu);
  SetBranchAddress(etree, "mc_wgt_v4a", &ev.mc_wgt_v4a);
  SetBranchAddress(etree, "mc_wgt_tunedcv", &ev.mc_wgt_tunedcv);

  SetBranchAddress(etree, "evtwgt_genie_ncel_nfunc", &ev.evtwgt_genie_ncel_nfunc);

  set_object_input_branch_address(etree, "evtwgt_genie_ncel_funcname", ev.evtwgt_genie_ncel_funcname);
  set_object_input_branch_address(etree, "evtwgt_genie_ncel_nweight", ev.evtwgt_genie_ncel_nweight);
  set_object_input_branch_address(etree, "evtwgt_genie_ncel_weight", ev.evtwgt_genie_ncel_weight);

  SetBranchAddress(etree, "evtwgt_genie_pm1_nfunc", &ev.evtwgt_genie_pm1_nfunc);

  set_object_input_branch_address(etree, "evtwgt_genie_pm1_funcname", ev.evtwgt_genie_pm1_funcname);
  set_object_input_branch_address(etree, "evtwgt_genie_pm1_nweight", ev.evtwgt_genie_pm1_nweight);
  set_object_input_branch_address(etree, "evtwgt_genie_pm1_weight", ev.evtwgt_genie_pm1_weight);

  SetBranchAddress(etree, "evtwgt_genie_multisim_nfunc", &ev.evtwgt_genie_multisim_nfunc);

  set_object_input_branch_address(etree, "evtwgt_genie_multisim_funcname", ev.evtwgt_genie_multisim_funcname);
  set_object_input_branch_address(etree, "evtwgt_genie_multisim_nweight", ev.evtwgt_genie_multisim_nweight);
  set_object_input_branch_address(etree, "evtwgt_genie_multisim_weight", ev.evtwgt_genie_multisim_weight);

  SetBranchAddress(etree, "evtwgt_g4_multisim_nfunc", &ev.evtwgt_g4_multisim_nfunc);

  set_object_input_branch_address(etree, "evtwgt_g4_multisim_funcname", ev.evtwgt_g4_multisim_funcname);
  set_object_input_branch_address(etree, "evtwgt_g4_multisim_nweight", ev.evtwgt_g4_multisim_nweight);
  set_object_input_branch_address(etree, "evtwgt_g4_multisim_weight", ev.evtwgt_g4_multisim_weight);

  SetBranchAddress(etree, "evtwgt_flux_multisim_nfunc", &ev.evtwgt_flux_multisim_nfunc);

  set_object_input_branch_address(etree, "evtwgt_flux_multisim_funcname", ev.evtwgt_flux_multisim_funcname);
  set_object_input_branch_address(etree, "evtwgt_flux_multisim_nweight", ev.evtwgt_flux_multisim_nweight);
  set_object_input_branch_address(etree, "evtwgt_flux_multisim_weight", ev.evtwgt_flux_multisim_weight);

  SetBranchAddress(etree, "mc_nupdg", &ev.mc_nupdg);
  SetBranchAddress(etree, "mc_n_muon", &ev.mc_n_muon);
  SetBranchAddress(etree, "mc_n_proton", &ev.mc_n_proton);
  SetBranchAddress(etree, "mc_n_photon", &ev.mc_n_photon);
  SetBranchAddress(etree, "mc_n_pionpm", &ev.mc_n_pionpm);
  SetBranchAddress(etree, "mc_n_pion0", &ev.mc_n_pion0);
  SetBranchAddress(etree, "mc_n_electron", &ev.mc_n_electron);
  SetBranchAddress(etree, "mc_n_neutron", &ev.mc_n_neutron);
  SetBranchAddress(etree, "mc_nI_n_photon", &ev.mc_nI_n_photon);
  SetBranchAddress(etree, "mc_nI_n_proton", &ev.mc_nI_n_proton);
  SetBranchAddress(etree, "mc_nI_n_neutron", &ev.mc_nI_n_neutron);
  SetBranchAddress(etree, "mc_n_threshold_muon", &ev.mc_n_threshold_muon);
  SetBranchAddress(etree, "mc_n_threshold_proton", &ev.mc_n_threshold_proton);
  SetBranchAddress(etree, "mc_n_threshold_pionpm", &ev.mc_n_threshold_pionpm);
  SetBranchAddress(etree, "mc_n_threshold_pion0", &ev.mc_n_threshold_pion0);
  SetBranchAddress(etree, "mc_n_threshold_electron", &ev.mc_n_threshold_electron);
  SetBranchAddress(etree, "mc_n_threshold_neutron", &ev.mc_n_threshold_neutron);

  set_object_input_branch_address(etree, "mc_g4_mom", ev.mc_g4_mom);
  set_object_input_branch_address(etree, "mc_g4_E", ev.mc_g4_E);
  set_object_input_branch_address(etree, "mc_g4_p", ev.mc_g4_p);
  set_object_input_branch_address(etree, "mc_g4_mass", ev.mc_g4_mass);
  set_object_input_branch_address(etree, "mc_g4_phi", ev.mc_g4_phi);
  set_object_input_branch_address(etree, "mc_g4_theta", ev.mc_g4_theta);
  set_object_input_branch_address(etree, "mc_g4_pdg", ev.mc_g4_pdg);
  set_object_input_branch_address(etree, "mc_g4_start_x", ev.mc_g4_start_x);
  set_object_input_branch_address(etree, "mc_g4_start_y", ev.mc_g4_start_y);
  set_object_input_branch_address(etree, "mc_g4_start_z", ev.mc_g4_start_z);
  set_object_input_branch_address(etree, "mc_g4_end_x", ev.mc_g4_end_x);
  set_object_input_branch_address(etree, "mc_g4_end_y", ev.mc_g4_end_y);
  set_object_input_branch_address(etree, "mc_g4_end_z", ev.mc_g4_end_z);
  set_object_input_branch_address(etree, "mc_g4_photon_E", ev.mc_g4_photon_E);
  set_object_input_branch_address(etree, "mc_g4_photon_start_x", ev.mc_g4_photon_start_x);
  set_object_input_branch_address(etree, "mc_g4_photon_start_y", ev.mc_g4_photon_start_y);
  set_object_input_branch_address(etree, "mc_g4_photon_start_z", ev.mc_g4_photon_start_z);
  set_object_input_branch_address(etree, "mc_g4_photon_end_x", ev.mc_g4_photon_end_x);
  set_object_input_branch_address(etree, "mc_g4_photon_end_y", ev.mc_g4_photon_end_y);
  set_object_input_branch_address(etree, "mc_g4_photon_end_z", ev.mc_g4_photon_end_z);
  set_object_input_branch_address(etree, "mc_g4_proton_E", ev.mc_g4_proton_E);
  set_object_input_branch_address(etree, "mc_g4_proton_start_x", ev.mc_g4_proton_start_x);
  set_object_input_branch_address(etree, "mc_g4_proton_start_y", ev.mc_g4_proton_start_y);
  set_object_input_branch_address(etree, "mc_g4_proton_start_z", ev.mc_g4_proton_start_z);
  set_object_input_branch_address(etree, "mc_g4_proton_end_x", ev.mc_g4_proton_end_x);
  set_object_input_branch_address(etree, "mc_g4_proton_end_y", ev.mc_g4_proton_end_y);
  set_object_input_branch_address(etree, "mc_g4_proton_end_z", ev.mc_g4_proton_end_z);
  set_object_input_branch_address(etree, "mc_g4_neutron_E", ev.mc_g4_neutron_E);
  set_object_input_branch_address(etree, "mc_g4_neutron_start_x", ev.mc_g4_neutron_start_x);
  set_object_input_branch_address(etree, "mc_g4_neutron_start_y", ev.mc_g4_neutron_start_y);
  set_object_input_branch_address(etree, "mc_g4_neutron_start_z", ev.mc_g4_neutron_start_z);
  set_object_input_branch_address(etree, "mc_g4_neutron_end_x", ev.mc_g4_neutron_end_x);
  set_object_input_branch_address(etree, "mc_g4_neutron_end_y", ev.mc_g4_neutron_end_y);
  set_object_input_branch_address(etree, "mc_g4_neutron_end_z", ev.mc_g4_neutron_end_z);

  set_object_input_branch_address(etree, "mc_g4_nI_photon_E", ev.mc_g4_nI_photon_E);
  set_object_input_branch_address(etree, "mc_g4_nI_photon_start_x", ev.mc_g4_nI_photon_start_x);
  set_object_input_branch_address(etree, "mc_g4_nI_photon_start_y", ev.mc_g4_nI_photon_start_y);
  set_object_input_branch_address(etree, "mc_g4_nI_photon_start_z", ev.mc_g4_nI_photon_start_z);
  set_object_input_branch_address(etree, "mc_g4_nI_photon_end_x", ev.mc_g4_nI_photon_end_x);
  set_object_input_branch_address(etree, "mc_g4_nI_photon_end_y", ev.mc_g4_nI_photon_end_y);
  set_object_input_branch_address(etree, "mc_g4_nI_photon_end_z", ev.mc_g4_nI_photon_end_z);
  set_object_input_branch_address(etree, "mc_g4_nI_proton_E", ev.mc_g4_nI_proton_E);
  set_object_input_branch_address(etree, "mc_g4_nI_proton_start_x", ev.mc_g4_nI_proton_start_x);
  set_object_input_branch_address(etree, "mc_g4_nI_proton_start_y", ev.mc_g4_nI_proton_start_y);
  set_object_input_branch_address(etree, "mc_g4_nI_proton_start_z", ev.mc_g4_nI_proton_start_z);

  set_object_input_branch_address(etree, "mc_g4_nI_proton_end_x", ev.mc_g4_nI_proton_end_x);
  set_object_input_branch_address(etree, "mc_g4_nI_proton_end_y", ev.mc_g4_nI_proton_end_y);
  set_object_input_branch_address(etree, "mc_g4_nI_proton_end_z", ev.mc_g4_nI_proton_end_z);
  set_object_input_branch_address(etree, "mc_g4_nI_neutron_E", ev.mc_g4_nI_neutron_E);
  set_object_input_branch_address(etree, "mc_g4_nI_neutron_start_x", ev.mc_g4_nI_neutron_start_x);
  set_object_input_branch_address(etree, "mc_g4_nI_neutron_start_y", ev.mc_g4_nI_neutron_start_y);
  set_object_input_branch_address(etree, "mc_g4_nI_neutron_start_z", ev.mc_g4_nI_neutron_start_z);
  set_object_input_branch_address(etree, "mc_g4_nI_neutron_end_x", ev.mc_g4_nI_neutron_end_x);
  set_object_input_branch_address(etree, "mc_g4_nI_neutron_end_y", ev.mc_g4_nI_neutron_end_y);
  set_object_input_branch_address(etree, "mc_g4_nI_neutron_end_z", ev.mc_g4_nI_neutron_end_z);

  set_object_input_branch_address(etree, "mc_g4_start_x_sce", ev.mc_g4_start_x_sce);
  set_object_input_branch_address(etree, "mc_g4_start_y_sce", ev.mc_g4_start_y_sce);
  set_object_input_branch_address(etree, "mc_g4_start_z_sce", ev.mc_g4_start_z_sce);
  set_object_input_branch_address(etree, "mc_g4_end_x_sce", ev.mc_g4_end_x_sce);
  set_object_input_branch_address(etree, "mc_g4_end_y_sce", ev.mc_g4_end_y_sce);
  set_object_input_branch_address(etree, "mc_g4_end_z_sce", ev.mc_g4_end_z_sce);
  set_object_input_branch_address(etree, "is_from_nu_slice", ev.is_from_nu_slice);
  set_object_input_branch_address(etree, "is_primary", ev.is_primary);
  set_object_input_branch_address(etree, "is_contained", ev.is_contained);
  set_object_input_branch_address(etree, "is_st", ev.is_st);
  set_object_input_branch_address(etree, "is_nc1p", ev.is_nc1p);
  set_object_input_branch_address(etree, "is_reco_nc1p", ev.is_reco_nc1p);
  set_object_input_branch_address(etree, "mc_pdg", ev.mc_pdg);
  set_object_input_branch_address(etree, "mc_primary", ev.mc_primary);
  set_object_input_branch_address(etree, "mc_origin", ev.mc_origin);
  set_object_input_branch_address(etree, "mc_length", ev.mc_length);
  set_object_input_branch_address(etree, "mc_start_x", ev.mc_start_x);
  set_object_input_branch_address(etree, "mc_start_y", ev.mc_start_y);
  set_object_input_branch_address(etree, "mc_start_z", ev.mc_start_z);
  set_object_input_branch_address(etree, "mc_end_x", ev.mc_end_x);
  set_object_input_branch_address(etree, "mc_end_y", ev.mc_end_y);
  set_object_input_branch_address(etree, "mc_end_z", ev.mc_end_z);
  set_object_input_branch_address(etree, "mc_start_x_sce", ev.mc_start_x_sce);
  set_object_input_branch_address(etree, "mc_start_y_sce", ev.mc_start_y_sce);
  set_object_input_branch_address(etree, "mc_start_z_sce", ev.mc_start_z_sce);
  set_object_input_branch_address(etree, "mc_end_x_sce", ev.mc_end_x_sce);
  set_object_input_branch_address(etree, "mc_end_y_sce", ev.mc_end_y_sce);
  set_object_input_branch_address(etree, "mc_end_z_sce", ev.mc_end_z_sce);
  set_object_input_branch_address(etree, "mc_theta", ev.mc_theta);
  set_object_input_branch_address(etree, "mc_phi", ev.mc_phi);
  set_object_input_branch_address(etree, "mc_ke", ev.mc_ke);
  set_object_input_branch_address(etree, "mc_mom", ev.mc_mom);
  set_object_input_branch_address(etree, "n_pfp", ev.n_pfp);
  set_object_input_branch_address(etree, "n_trk", ev.n_trk);
  set_object_input_branch_address(etree, "id_pfp", ev.id_pfp);
  set_object_input_branch_address(etree, "isinFV", ev.isinFV);
  set_object_input_branch_address(etree, "n_shower", ev.n_shower);
  set_object_input_branch_address(etree, "parentPDG", ev.parentPDG);
  set_object_input_branch_address(etree, "trk_score", ev.trk_score);
  set_object_input_branch_address(etree, "KE_len", ev.KE_len);
  set_object_input_branch_address(etree, "dislen_ratio", ev.dislen_ratio);
  set_object_input_branch_address(etree, "reco_q2", ev.reco_q2);
  set_object_input_branch_address(etree, "top_score", ev.top_score);
  set_object_input_branch_address(etree, "flash_score", ev.flash_score);
  set_object_input_branch_address(etree, "n_daughters", ev.n_daughters);
  set_object_input_branch_address(etree, "has_shower", ev.has_shower);
  SetBranchAddress(etree, "reco_nu_vtxx", &ev.reco_nu_vtxx);
  SetBranchAddress(etree, "reco_nu_vtxy", &ev.reco_nu_vtxy);
  SetBranchAddress(etree, "reco_nu_vtxz", &ev.reco_nu_vtxz);
  set_object_input_branch_address(etree, "deltaY", ev.deltaY);
  set_object_input_branch_address(etree, "deltaZ", ev.deltaZ);
  set_object_input_branch_address(etree, "deltaYSigma", ev.deltaYSigma);
  set_object_input_branch_address(etree, "deltaZSigma", ev.deltaZSigma);
  set_object_input_branch_address(etree, "chargeToLightRatio", ev.chargeToLightRatio);
  set_object_input_branch_address(etree, "xclVariable", ev.xclVariable);
  set_object_input_branch_address(etree, "flip_0", ev.flip_0);
  set_object_input_branch_address(etree, "flip_1", ev.flip_1);
  set_object_input_branch_address(etree, "flip_2", ev.flip_2);
  set_object_input_branch_address(etree, "reco_length", ev.reco_length);
  set_object_input_branch_address(etree, "reco_start_x", ev.reco_start_x);
  set_object_input_branch_address(etree, "reco_start_y", ev.reco_start_y);
  set_object_input_branch_address(etree, "reco_start_z", ev.reco_start_z);
  set_object_input_branch_address(etree, "reco_end_x", ev.reco_end_x);
  set_object_input_branch_address(etree, "reco_end_y", ev.reco_end_y);
  set_object_input_branch_address(etree, "reco_end_z", ev.reco_end_z);
  set_object_input_branch_address(etree, "reco_theta", ev.reco_theta);
  set_object_input_branch_address(etree, "reco_phi", ev.reco_phi);
  set_object_input_branch_address(etree, "reco_start_x_f2", ev.reco_start_x_f2);
  set_object_input_branch_address(etree, "reco_start_y_f2", ev.reco_start_y_f2);
  set_object_input_branch_address(etree, "reco_start_z_f2", ev.reco_start_z_f2);
  set_object_input_branch_address(etree, "reco_end_x_f2", ev.reco_end_x_f2);
  set_object_input_branch_address(etree, "reco_end_y_f2", ev.reco_end_y_f2);
  set_object_input_branch_address(etree, "reco_end_z_f2", ev.reco_end_z_f2);
  set_object_input_branch_address(etree, "reco_theta_f2", ev.reco_theta_f2);
  set_object_input_branch_address(etree, "reco_phi_f2", ev.reco_phi_f2);
  set_object_input_branch_address(etree, "reco_ke", ev.reco_ke);
  set_object_input_branch_address(etree, "reco_mom", ev.reco_mom);
  set_object_input_branch_address(etree, "reco_mom_muon", ev.reco_mom_muon);
  set_object_input_branch_address(etree, "reco_mom_proton", ev.reco_mom_proton);
  set_object_input_branch_address(etree, "reco_mom_pion", ev.reco_mom_pion);
  set_object_input_branch_address(etree, "nhits_0", ev.nhits_0);
  set_object_input_branch_address(etree, "nhits_1", ev.nhits_1);
  set_object_input_branch_address(etree, "nhits_2", ev.nhits_2);
  set_object_input_branch_address(etree, "chi2_p_0", ev.chi2_p_0);
  set_object_input_branch_address(etree, "chi2_p_1", ev.chi2_p_1);
  set_object_input_branch_address(etree, "chi2_p_2", ev.chi2_p_2);

  set_object_input_branch_address(etree, "start_dedx_0", ev.start_dedx_0);
  set_object_input_branch_address(etree, "start_dedx_1", ev.start_dedx_1);
  set_object_input_branch_address(etree, "start_dedx_2", ev.start_dedx_2);
  set_object_input_branch_address(etree, "end_dedx_0", ev.end_dedx_0);
  set_object_input_branch_address(etree, "end_dedx_1", ev.end_dedx_1);
  set_object_input_branch_address(etree, "end_dedx_2", ev.end_dedx_2);
  set_object_input_branch_address(etree, "start_dedx_0_f2", ev.start_dedx_0_f2);
  set_object_input_branch_address(etree, "start_dedx_1_f2", ev.start_dedx_1_f2);
  set_object_input_branch_address(etree, "start_dedx_2_f2", ev.start_dedx_2_f2);
  set_object_input_branch_address(etree, "end_dedx_0_f2", ev.end_dedx_0_f2);
  set_object_input_branch_address(etree, "end_dedx_1_f2", ev.end_dedx_1_f2);
  set_object_input_branch_address(etree, "end_dedx_2_f2", ev.end_dedx_2_f2);
  set_object_input_branch_address(etree, "ratio_dedx_0", ev.ratio_dedx_0);
  set_object_input_branch_address(etree, "ratio_dedx_1", ev.ratio_dedx_1);
  set_object_input_branch_address(etree, "ratio_dedx_2", ev.ratio_dedx_2);
  set_object_input_branch_address(etree, "avg_dedx_0", ev.avg_dedx_0);
  set_object_input_branch_address(etree, "avg_dedx_1", ev.avg_dedx_1);
  set_object_input_branch_address(etree, "avg_dedx_2", ev.avg_dedx_2);
  set_object_input_branch_address(etree, "total_dedx_0", ev.total_dedx_0);
  set_object_input_branch_address(etree, "total_dedx_1", ev.total_dedx_1);
  set_object_input_branch_address(etree, "total_dedx_2", ev.total_dedx_2);
  SetBranchAddress(etree, "nclusters", &ev.nclusters);
  SetBranchAddress(etree, "nclustersps", &ev.nclustersps);
  set_object_input_branch_address(etree, "cluster_ID", ev.cluster_ID);
  set_object_input_branch_address(etree, "cluster_start_charge", ev.cluster_start_charge);
  set_object_input_branch_address(etree, "cluster_start_angle", ev.cluster_start_angle);
  set_object_input_branch_address(etree, "cluster_end_charge", ev.cluster_end_charge);
  set_object_input_branch_address(etree, "cluster_end_angle", ev.cluster_end_angle);
  set_object_input_branch_address(etree, "cluster_integral", ev.cluster_integral);
  set_object_input_branch_address(etree, "cluster_integral_average", ev.cluster_integral_average);
  set_object_input_branch_address(etree, "cluster_summedADC", ev.cluster_summedADC);
  set_object_input_branch_address(etree, "cluster_summedADC_average", ev.cluster_summedADC_average);
  set_object_input_branch_address(etree, "cluster_width", ev.cluster_width);
  set_object_input_branch_address(etree, "cluster_nhits", ev.cluster_nhits);
  set_object_input_branch_address(etree, "cluster_start_wire", ev.cluster_start_wire);
  set_object_input_branch_address(etree, "cluster_start_tick", ev.cluster_start_tick);
  set_object_input_branch_address(etree, "cluster_end_wire", ev.cluster_end_wire);
  set_object_input_branch_address(etree, "cluster_end_tick", ev.cluster_end_tick);
  set_object_input_branch_address(etree, "cluster_sps_x", ev.cluster_sps_x);
  set_object_input_branch_address(etree, "cluster_sps_y", ev.cluster_sps_y);
  set_object_input_branch_address(etree, "cluster_sps_z", ev.cluster_sps_z);
  SetBranchAddress(etree, "nblips", &ev.nblips);
  set_object_input_branch_address(etree, "blip_x", ev.blip_x);
  set_object_input_branch_address(etree, "blip_y", ev.blip_y);
  set_object_input_branch_address(etree, "blip_z", ev.blip_z);
  set_object_input_branch_address(etree, "blip_plane_0", ev.blip_plane_0);
  set_object_input_branch_address(etree, "blip_plane_1", ev.blip_plane_1);
  set_object_input_branch_address(etree, "blip_plane_2", ev.blip_plane_2);
  set_object_input_branch_address(etree, "blip_charge_0", ev.blip_charge_0);
  set_object_input_branch_address(etree, "blip_charge_1", ev.blip_charge_1);
  set_object_input_branch_address(etree, "blip_charge_2", ev.blip_charge_2);
  set_object_input_branch_address(etree, "blip_ID", ev.blip_ID);
  set_object_input_branch_address(etree, "blip_isValid", ev.blip_isValid);
  set_object_input_branch_address(etree, "blip_nplanes", ev.blip_nplanes);
  set_object_input_branch_address(etree, "blip_maxdiff", ev.blip_maxdiff);
  set_object_input_branch_address(etree, "blip_tpc", ev.blip_tpc);
  set_object_input_branch_address(etree, "blip_energy", ev.blip_energy);
  set_object_input_branch_address(etree, "blip_energy_estar", ev.blip_energy_estar);
  set_object_input_branch_address(etree, "blip_incylinder", ev.blip_incylinder);
  set_object_input_branch_address(etree, "blip_trkid", ev.blip_trkid);
  set_object_input_branch_address(etree, "blip_trkdist", ev.blip_trkdist);
  set_object_input_branch_address(etree, "blip_pdg", ev.blip_pdg);
  set_object_input_branch_address(etree, "blip_process", ev.blip_process);
  set_object_input_branch_address(etree, "blip_vx", ev.blip_vx);
  set_object_input_branch_address(etree, "blip_vy", ev.blip_vy);
  set_object_input_branch_address(etree, "blip_vz", ev.blip_vz);
  set_object_input_branch_address(etree, "blip_E", ev.blip_E);
  set_object_input_branch_address(etree, "blip_mass", ev.blip_mass);
  set_object_input_branch_address(etree, "blip_mom_process", ev.blip_mom_process);
  set_object_input_branch_address(etree, "blip_mom_pdg", ev.blip_mom_pdg);
  set_object_input_branch_address(etree, "blip_mom_vx", ev.blip_mom_vx);
  set_object_input_branch_address(etree, "blip_mom_vy", ev.blip_mom_vy);
  set_object_input_branch_address(etree, "blip_mom_vz", ev.blip_mom_vz);
  set_object_input_branch_address(etree, "blip_mom_E", ev.blip_mom_E);
  set_object_input_branch_address(etree, "blip_mom_mass", ev.blip_mom_mass);
  set_object_input_branch_address(etree, "blip_grandmom_process", ev.blip_grandmom_process);
  set_object_input_branch_address(etree, "blip_grandmom_pdg", ev.blip_grandmom_pdg);
  set_object_input_branch_address(etree, "blip_grandmom_vx", ev.blip_grandmom_vx);
  set_object_input_branch_address(etree, "blip_grandmom_vy", ev.blip_grandmom_vy);
  set_object_input_branch_address(etree, "blip_grandmom_vz", ev.blip_grandmom_vz);
  set_object_input_branch_address(etree, "blip_grandmom_E", ev.blip_grandmom_E);
  set_object_input_branch_address(etree, "blip_grandmom_mass", ev.blip_grandmom_mass);
  set_object_input_branch_address(etree, "blip_greatgrandmom_process", ev.blip_greatgrandmom_process);
  set_object_input_branch_address(etree, "blip_greatgrandmom_pdg", ev.blip_greatgrandmom_pdg);
  set_object_input_branch_address(etree, "blip_greatgrandmom_vx", ev.blip_greatgrandmom_vx);
  set_object_input_branch_address(etree, "blip_greatgrandmom_vy", ev.blip_greatgrandmom_vy);
  set_object_input_branch_address(etree, "blip_greatgrandmom_vz", ev.blip_greatgrandmom_vz);
  set_object_input_branch_address(etree, "blip_greatgrandmom_E", ev.blip_greatgrandmom_E);
  set_object_input_branch_address(etree, "blip_greatgrandmom_mass", ev.blip_greatgrandmom_mass);
}

// Helper function to set branch addresses for the output TTree
void set_event_output_branch_addresses(TTree& out_tree, AnalysisEvent& ev,
  bool create = false)
{
  // Signal definition flags
  set_output_branch_address( out_tree, "is_mc", &ev.is_mc_, create, "is_mc/O" );

  // Event weights
  set_output_branch_address( out_tree, "spline_weight",
    &ev.spline_weight_, create, "spline_weight/F" );

  set_output_branch_address( out_tree, "tuned_cv_weight",
    &ev.tuned_cv_weight_, create, "tuned_cv_weight/F" );
  
  set_output_branch_address( out_tree, "ppfx_cv_weight",
    &ev.ppfx_cv_weight_, create, "ppfx_cv_weight/F" );

  if (useNuMI) {
    set_output_branch_address( out_tree, "normalisation_weight",
      &ev.normalisation_weight_, create, "normalisation_weight/F" );
  }

  // If MC weights are available, prepare to store them in the output TTree
  if ( ev.mc_weights_map_ ) {

    // Make separate branches for the various sets of systematic variation
    // weights in the map
    for ( auto& pair : *ev.mc_weights_map_ ) {

      // skip duplicate unecessary weights in NuMI files
      if (useNuMI) {
        // BNB flux weights
        if (pair.first == "flux_all") continue;

        // extra PPFX weights, use multi-sim instead
        if (pair.first == "ppfx_mippk_PPFXMIPPKaon" ||
    		  pair.first == "ppfx_mipppi_PPFXMIPPPion" ||
    		  pair.first == "ppfx_other_PPFXOther" ||
    		  pair.first == "ppfx_targatt_PPFXTargAtten" ||
    		  pair.first == "ppfx_think_PPFXThinKaon" ||
    		  pair.first == "ppfx_thinmes_PPFXThinMeson" ||
    		  pair.first == "ppfx_thinn_PPFXThinNuc" ||
    		  pair.first == "ppfx_thinna_PPFXThinNucA" ||
    		  pair.first == "ppfx_thinnpi_PPFXThinNeutronPion" ||
    		  pair.first == "ppfx_thinpi_PPFXThinPion" ||
    		  pair.first == "ppfx_totabs_PPFXTotAbsorp"
    		) continue;
      }

      // Prepend "weight_" to the name of the vector of weights in the map
      std::string weight_branch_name = "weight_" + pair.first;

      // Store a pointer to the vector of weights (needed to set the branch
      // address properly) in the temporary map of pointers
      ev.mc_weights_ptr_map_[ weight_branch_name ] = &pair.second;

      // Set the branch address for this vector of weights
      set_object_output_branch_address< std::vector<double> >( out_tree,
        weight_branch_name, ev.mc_weights_ptr_map_.at(weight_branch_name),
        create );
    }
  }

  // Backtracked neutrino purity and completeness
  set_output_branch_address( out_tree, "nu_completeness_from_pfp",
    &ev.nu_completeness_from_pfp_, create, "nu_completeness_from_pfp/F" );

  set_output_branch_address( out_tree, "nu_purity_from_pfp",
    &ev.nu_purity_from_pfp_, create, "nu_purity_from_pfp/F" );

  // Number of neutrino slices identified by the SliceID
  set_output_branch_address( out_tree, "nslice", &ev.nslice_, create,
    "nslice/I" );

  // *** Branches copied directly from the input ***

  // Cosmic rejection parameters for numu CC inclusive selection
  set_output_branch_address( out_tree, "topological_score",
    &ev.topological_score_, create, "topological_score/F" );

  set_output_branch_address( out_tree, "CosmicIP",
    &ev.cosmic_impact_parameter_, create, "CosmicIP/F" );

  // contained fraction
  set_output_branch_address( out_tree, "contained_fraction",
    &ev.contained_fraction_, create, "contained_fraction/F" );

  // Reconstructed neutrino vertex position
  set_output_branch_address( out_tree, "reco_nu_vtx_sce_x",
    &ev.nu_vx_, create, "reco_nu_vtx_sce_x/F" );

  set_output_branch_address( out_tree, "reco_nu_vtx_sce_y",
    &ev.nu_vy_, create, "reco_nu_vtx_sce_y/F" );

  set_output_branch_address( out_tree, "reco_nu_vtx_sce_z",
    &ev.nu_vz_, create, "reco_nu_vtx_sce_z/F" );

  // MC truth information for the neutrino
  set_output_branch_address( out_tree, "mc_nu_pdg", &ev.mc_nu_pdg_,
    create, "mc_nu_pdg/I" );

  set_output_branch_address( out_tree, "mc_nu_vtx_x", &ev.mc_nu_vx_,
    create, "mc_nu_vtx_x/F" );

  set_output_branch_address( out_tree, "mc_nu_vtx_y", &ev.mc_nu_vy_,
    create, "mc_nu_vtx_y/F" );

  set_output_branch_address( out_tree, "mc_nu_vtx_z", &ev.mc_nu_vz_,
    create, "mc_nu_vtx_z/F" );

  set_output_branch_address( out_tree, "mc_nu_energy", &ev.mc_nu_energy_,
    create, "mc_nu_energy/F" );

  set_output_branch_address( out_tree, "mc_ccnc", &ev.mc_nu_ccnc_,
    create, "mc_ccnc/I" );

  set_output_branch_address( out_tree, "mc_interaction",
    &ev.mc_nu_interaction_type_, create, "mc_interaction/I" );

  // PFParticle properties
  set_object_output_branch_address< std::vector<unsigned int> >( out_tree,
    "pfp_generation_v", ev.pfp_generation_, create );

  set_object_output_branch_address< std::vector<unsigned int> >( out_tree,
    "pfp_trk_daughters_v", ev.pfp_trk_daughters_count_, create );

  set_object_output_branch_address< std::vector<unsigned int> >( out_tree,
    "pfp_shr_daughters_v", ev.pfp_shr_daughters_count_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_score_v", ev.pfp_track_score_, create );

  set_object_output_branch_address< std::vector<int> >( out_tree,
    "pfpdg", ev.pfp_reco_pdg_, create );

  set_object_output_branch_address< std::vector<int> >( out_tree,
    "pfnhits", ev.pfp_hits_, create );

  set_object_output_branch_address< std::vector<int> >( out_tree,
    "pfnplanehits_U", ev.pfp_hitsU_, create );

  set_object_output_branch_address< std::vector<int> >( out_tree,
    "pfnplanehits_V", ev.pfp_hitsV_, create );

  set_object_output_branch_address< std::vector<int> >( out_tree,
    "pfnplanehits_Y", ev.pfp_hitsY_, create );

  // Backtracked PFParticle properties
  set_object_output_branch_address< std::vector<int> >( out_tree,
    "backtracked_pdg", ev.pfp_true_pdg_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "backtracked_e", ev.pfp_true_E_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "backtracked_px", ev.pfp_true_px_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "backtracked_py", ev.pfp_true_py_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "backtracked_pz", ev.pfp_true_pz_, create );

  // Shower properties
  // For some ntuples, reconstructed shower information is excluded.
  // In such cases, skip writing these branches to the output TTree.
  if ( ev.shower_startx_ ) {
    set_object_output_branch_address< std::vector<float> >( out_tree,
      "shr_start_x_v", ev.shower_startx_, create );

    set_object_output_branch_address< std::vector<float> >( out_tree,
      "shr_start_y_v", ev.shower_starty_, create );

    set_object_output_branch_address< std::vector<float> >( out_tree,
      "shr_start_z_v", ev.shower_startz_, create );

    // Shower start distance from reco neutrino vertex (pre-calculated for
    // convenience)
    set_object_output_branch_address< std::vector<float> >( out_tree,
      "shr_dist_v", ev.shower_start_distance_, create );
  }
  // primary shower
  set_output_branch_address( out_tree, "shr_id", &ev.shr_id_, create, "shr_id/I" );
  set_output_branch_address( out_tree, "shr_score", &ev.shr_score_, create, "shr_score/F" );
  set_output_branch_address( out_tree, "shr_energy_cali", &ev.shr_energy_cali_, create, "shr_energy_cali/F" );
  set_output_branch_address( out_tree, "hits_ratio", &ev.hits_ratio_, create, "hits_ratio/F" );
  set_output_branch_address( out_tree, "shrmoliereavg", &ev.shrmoliereavg_, create, "shrmoliereavg/F" );
  set_output_branch_address( out_tree, "shr_distance", &ev.shr_distance_, create, "shr_distance/F" );
  set_output_branch_address( out_tree, "shr_tkfit_gap10_dedx_Y", &ev.shr_tkfit_gap10_dedx_Y_, create, "shr_tkfit_gap10_dedx_Y/F" );
  set_output_branch_address( out_tree, "shr_tkfit_2cm_dedx_Y", &ev.shr_tkfit_2cm_dedx_Y_, create, "shr_tkfit_2cm_dedx_Y/F" );

  // Track properties
  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_len_v", ev.track_length_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_sce_start_x_v", ev.track_startx_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_sce_start_y_v", ev.track_starty_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_sce_start_z_v", ev.track_startz_, create );

  // Track start distance from reco neutrino vertex (pre-calculated for
  // convenience)
  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_distance_v", ev.track_start_distance_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_sce_end_x_v", ev.track_endx_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_sce_end_y_v", ev.track_endy_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_sce_end_z_v", ev.track_endz_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_dir_x_v", ev.track_dirx_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_dir_y_v", ev.track_diry_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_dir_z_v", ev.track_dirz_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_energy_proton_v", ev.track_kinetic_energy_p_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_range_muon_mom_v", ev.track_range_mom_mu_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_mcs_muon_mom_v", ev.track_mcs_mom_mu_, create );

  // Some ntuples exclude the old chi^2 proton PID score. Only include it in
  // the output if it is available.
  if ( ev.track_chi2_proton_ ) {
    set_object_output_branch_address< std::vector<float> >( out_tree,
      "trk_pid_chipr_v", ev.track_chi2_proton_, create );
  }

  // Log-likelihood-based particle ID information
  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_llr_pid_v", ev.track_llr_pid_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_llr_pid_u_v", ev.track_llr_pid_U_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_llr_pid_v_v", ev.track_llr_pid_V_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_llr_pid_y_v", ev.track_llr_pid_Y_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree,
    "trk_llr_pid_score_v", ev.track_llr_pid_score_, create );

  // MC truth information for the final-state primary particles
  set_object_output_branch_address< std::vector<int> >( out_tree, "mc_pdg",
    ev.mc_nu_daughter_pdg_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree, "mc_E",
    ev.mc_nu_daughter_energy_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree, "mc_px",
    ev.mc_nu_daughter_px_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree, "mc_py",
    ev.mc_nu_daughter_py_, create );

  set_object_output_branch_address< std::vector<float> >( out_tree, "mc_pz",
    ev.mc_nu_daughter_pz_, create );
}
