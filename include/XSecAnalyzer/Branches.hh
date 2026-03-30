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

  if(etree.GetBranch("run") != nullptr) {SetBranchAddress(etree, "run", &ev.run);}
  if(etree.GetBranch("subrun") != nullptr) {SetBranchAddress(etree, "subrun", &ev.subrun);}
  if(etree.GetBranch("event") != nullptr) {SetBranchAddress(etree, "event", &ev.event);}
  if(etree.GetBranch("evt_gen_nc1p") != nullptr) {SetBranchAddress(etree, "evt_gen_nc1p", &ev.evt_gen_nc1p);}
  if(etree.GetBranch("evt_gen_nce") != nullptr) {SetBranchAddress(etree, "evt_gen_nce", &ev.evt_gen_nce);}
  if(etree.GetBranch("evt_gen_nc1p_q2_gen") != nullptr) {SetBranchAddress(etree, "evt_gen_nc1p_q2_gen", &ev.evt_gen_nc1p_q2_gen);}
  if(etree.GetBranch("evt_gen_nc1p_q2_ke") != nullptr) {SetBranchAddress(etree, "evt_gen_nc1p_q2_ke", &ev.evt_gen_nc1p_q2_ke);}
  if(etree.GetBranch("evt_gen_nc1p_stx") != nullptr) {SetBranchAddress(etree, "evt_gen_nc1p_stx", &ev.evt_gen_nc1p_stx);}
  if(etree.GetBranch("evt_gen_nc1p_sty") != nullptr) {SetBranchAddress(etree, "evt_gen_nc1p_sty", &ev.evt_gen_nc1p_sty);}
  if(etree.GetBranch("evt_gen_nc1p_stz") != nullptr) {SetBranchAddress(etree, "evt_gen_nc1p_stz", &ev.evt_gen_nc1p_stz);}
  if(etree.GetBranch("evt_gen_nc1p_endx") != nullptr) {SetBranchAddress(etree, "evt_gen_nc1p_endx", &ev.evt_gen_nc1p_endx);}
  if(etree.GetBranch("evt_gen_nc1p_endy") != nullptr) {SetBranchAddress(etree, "evt_gen_nc1p_endy", &ev.evt_gen_nc1p_endy);}
  if(etree.GetBranch("evt_gen_nc1p_endz") != nullptr) {SetBranchAddress(etree, "evt_gen_nc1p_endz", &ev.evt_gen_nc1p_endz);}
  if(etree.GetBranch("evt_gen_nc1p_costheta") != nullptr) {SetBranchAddress(etree, "evt_gen_nc1p_costheta", &ev.evt_gen_nc1p_costheta);}
  if(etree.GetBranch("evt_gen_nc1p_phi") != nullptr) {SetBranchAddress(etree, "evt_gen_nc1p_phi", &ev.evt_gen_nc1p_phi);}
  if(etree.GetBranch("evt_gen_nc1p_mom") != nullptr) {SetBranchAddress(etree, "evt_gen_nc1p_mom", &ev.evt_gen_nc1p_mom);}
  if(etree.GetBranch("evt_gen_nc1p_ke") != nullptr) {SetBranchAddress(etree, "evt_gen_nc1p_ke", &ev.evt_gen_nc1p_ke);}
  if(etree.GetBranch("evt_gen_nc1p_contained") != nullptr) {SetBranchAddress(etree, "evt_gen_nc1p_contained", &ev.evt_gen_nc1p_contained);}
  if(etree.GetBranch("evt_gen_nc1p_inFV") != nullptr) {SetBranchAddress(etree, "evt_gen_nc1p_inFV", &ev.evt_gen_nc1p_inFV);}
  if(etree.GetBranch("evt_reco_1p_nu") != nullptr) {SetBranchAddress(etree, "evt_reco_1p_nu", &ev.evt_reco_1p_nu);}
  if(etree.GetBranch("evt_reco_1p_non_nu") != nullptr) {SetBranchAddress(etree, "evt_reco_1p_non_nu", &ev.evt_reco_1p_non_nu);}
  if(etree.GetBranch("evt_reco_1p") != nullptr) {SetBranchAddress(etree, "evt_reco_1p", &ev.evt_reco_1p);}
  if(etree.GetBranch("evt_reco_1mu1p") != nullptr) {SetBranchAddress(etree, "evt_reco_1mu1p", &ev.evt_reco_1mu1p);}
  if(etree.GetBranch("nflashes") != nullptr) {SetBranchAddress(etree, "nflashes", &ev.nflashes);}
  if(etree.GetBranch("evt_n_pfp") != nullptr) {SetBranchAddress(etree, "evt_n_pfp", &ev.evt_n_pfp);}
  if(etree.GetBranch("evt_n_trk") != nullptr) {SetBranchAddress(etree, "evt_n_trk", &ev.evt_n_trk);}
  if(etree.GetBranch("evt_n_shower") != nullptr) {SetBranchAddress(etree, "evt_n_shower", &ev.evt_n_shower);}
  if(etree.GetBranch("evt_n_nu") != nullptr) {SetBranchAddress(etree, "evt_n_nu", &ev.evt_n_nu);}
  if(etree.GetBranch("evt_n_nu_pfp") != nullptr) {SetBranchAddress(etree, "evt_n_nu_pfp", &ev.evt_n_nu_pfp);}
  if(etree.GetBranch("evt_nu_PDG") != nullptr) {SetBranchAddress(etree, "evt_nu_PDG", &ev.evt_nu_PDG);}

  if(etree.GetBranch("flash_Ywidth") != nullptr) set_object_input_branch_address(etree, "flash_Ywidth", ev.flash_Ywidth);
  if(etree.GetBranch("flash_Zwidth") != nullptr) set_object_input_branch_address(etree, "flash_Zwidth", ev.flash_Zwidth);
  if(etree.GetBranch("flash_Twidth") != nullptr) set_object_input_branch_address(etree, "flash_Twidth", ev.flash_Twidth);
  if(etree.GetBranch("flash_Ycenter") != nullptr) set_object_input_branch_address(etree, "flash_Ycenter", ev.flash_Ycenter);
  if(etree.GetBranch("flash_Zcenter") != nullptr) set_object_input_branch_address(etree, "flash_Zcenter", ev.flash_Zcenter);
  if(etree.GetBranch("flash_Time") != nullptr) set_object_input_branch_address(etree, "flash_Time", ev.flash_Time);
  if(etree.GetBranch("flash_CRThit") != nullptr) set_object_input_branch_address(etree, "flash_CRThit", ev.flash_CRThit);
  if(etree.GetBranch("flash_CRTveto") != nullptr) set_object_input_branch_address(etree, "flash_CRTveto", ev.flash_CRTveto);
  if(etree.GetBranch("flash_TotalPE") != nullptr) set_object_input_branch_address(etree, "flash_TotalPE", ev.flash_TotalPE);

  if(etree.GetBranch("flash_brightest_Ywidth") != nullptr) SetBranchAddress(etree, "flash_brightest_Ywidth", &ev.flash_brightest_Ywidth);
  if(etree.GetBranch("flash_brightest_Zwidth") != nullptr) SetBranchAddress(etree, "flash_brightest_Zwidth", &ev.flash_brightest_Zwidth);
  if(etree.GetBranch("flash_brightest_Twidth") != nullptr) SetBranchAddress(etree, "flash_brightest_Twidth", &ev.flash_brightest_Twidth);
  if(etree.GetBranch("flash_brightest_Ycenter") != nullptr) SetBranchAddress(etree, "flash_brightest_Ycenter", &ev.flash_brightest_Ycenter);
  if(etree.GetBranch("flash_brightest_Zcenter") != nullptr) SetBranchAddress(etree, "flash_brightest_Zcenter", &ev.flash_brightest_Zcenter);
  if(etree.GetBranch("flash_brightest_Time") != nullptr) SetBranchAddress(etree, "flash_brightest_Time", &ev.flash_brightest_Time);
  if(etree.GetBranch("flash_brightest_CRThit") != nullptr) SetBranchAddress(etree, "flash_brightest_CRThit", &ev.flash_brightest_CRThit);
  if(etree.GetBranch("flash_brightest_CRTveto") != nullptr) SetBranchAddress(etree, "flash_brightest_CRTveto", &ev.flash_brightest_CRTveto);
  if(etree.GetBranch("flash_brightest_TotalPE") != nullptr) SetBranchAddress(etree, "flash_brightest_TotalPE", &ev.flash_brightest_TotalPE);

  if(etree.GetBranch("flash_PE_Per_PMT") != nullptr) set_object_input_branch_address(etree, "flash_PE_Per_PMT", ev.flash_PE_Per_PMT);

  if(etree.GetBranch("mc_ccnc") != nullptr) SetBranchAddress(etree, "mc_ccnc", &ev.mc_ccnc);
  if(etree.GetBranch("mc_mode") != nullptr) SetBranchAddress(etree, "mc_mode", &ev.mc_mode);
  if(etree.GetBranch("mc_interactiontype") != nullptr) SetBranchAddress(etree, "mc_interactiontype", &ev.mc_interactiontype);
  if(etree.GetBranch("mc_hitnuc") != nullptr) SetBranchAddress(etree, "mc_hitnuc", &ev.mc_hitnuc);
  if(etree.GetBranch("mc_hitnuc11") != nullptr) SetBranchAddress(etree, "mc_hitnuc11", &ev.mc_hitnuc11);
  if(etree.GetBranch("mc_hitnuc11_p") != nullptr) SetBranchAddress(etree, "mc_hitnuc11_p", &ev.mc_hitnuc11_p);
  if(etree.GetBranch("mc_hitnuc11_px") != nullptr) SetBranchAddress(etree, "mc_hitnuc11_px", &ev.mc_hitnuc11_px);
  if(etree.GetBranch("mc_hitnuc11_py") != nullptr) SetBranchAddress(etree, "mc_hitnuc11_py", &ev.mc_hitnuc11_py);
  if(etree.GetBranch("mc_hitnuc11_pz") != nullptr) SetBranchAddress(etree, "mc_hitnuc11_pz", &ev.mc_hitnuc11_pz);
  if(etree.GetBranch("mc_hitnuc11_nuwro") != nullptr) SetBranchAddress(etree, "mc_hitnuc11_nuwro", &ev.mc_hitnuc11_nuwro);
  if(etree.GetBranch("mc_hitnuc11_nuwro_p") != nullptr) SetBranchAddress(etree, "mc_hitnuc11_nuwro_p", &ev.mc_hitnuc11_nuwro_p);
  if(etree.GetBranch("mc_hitnuc11_nuwro_px") != nullptr) SetBranchAddress(etree, "mc_hitnuc11_nuwro_px", &ev.mc_hitnuc11_nuwro_px);
  if(etree.GetBranch("mc_hitnuc11_nuwro_py") != nullptr) SetBranchAddress(etree, "mc_hitnuc11_nuwro_py", &ev.mc_hitnuc11_nuwro_py);
  if(etree.GetBranch("mc_hitnuc11_nuwro_pz") != nullptr) SetBranchAddress(etree, "mc_hitnuc11_nuwro_pz", &ev.mc_hitnuc11_nuwro_pz);
  if(etree.GetBranch("mc_q2") != nullptr) SetBranchAddress(etree, "mc_q2", &ev.mc_q2);
  if(etree.GetBranch("mc_nu_vtxx") != nullptr) SetBranchAddress(etree, "mc_nu_vtxx", &ev.mc_nu_vtxx);
  if(etree.GetBranch("mc_nu_vtxy") != nullptr) SetBranchAddress(etree, "mc_nu_vtxy", &ev.mc_nu_vtxy);
  if(etree.GetBranch("mc_nu_vtxz") != nullptr) SetBranchAddress(etree, "mc_nu_vtxz", &ev.mc_nu_vtxz);
  if(etree.GetBranch("mc_nu_vtxx_sce") != nullptr) SetBranchAddress(etree, "mc_nu_vtxx_sce", &ev.mc_nu_vtxx_sce);
  if(etree.GetBranch("mc_nu_vtxy_sce") != nullptr) SetBranchAddress(etree, "mc_nu_vtxy_sce", &ev.mc_nu_vtxy_sce);
  if(etree.GetBranch("mc_nu_vtxz_sce") != nullptr) SetBranchAddress(etree, "mc_nu_vtxz_sce", &ev.mc_nu_vtxz_sce);
  if(etree.GetBranch("mc_enu") != nullptr) SetBranchAddress(etree, "mc_enu", &ev.mc_enu);
  if(etree.GetBranch("mc_wgt_v4a") != nullptr) SetBranchAddress(etree, "mc_wgt_v4a", &ev.mc_wgt_v4a);
  if(etree.GetBranch("mc_wgt_tunedcv") != nullptr) SetBranchAddress(etree, "mc_wgt_tunedcv", &ev.mc_wgt_tunedcv);

  if(etree.GetBranch("evtwgt_genie_ncel_nfunc") != nullptr) SetBranchAddress(etree, "evtwgt_genie_ncel_nfunc", &ev.evtwgt_genie_ncel_nfunc);

  if(etree.GetBranch("evtwgt_genie_ncel_funcname") != nullptr) set_object_input_branch_address(etree, "evtwgt_genie_ncel_funcname", ev.evtwgt_genie_ncel_funcname);
  if(etree.GetBranch("evtwgt_genie_ncel_nweight") != nullptr) set_object_input_branch_address(etree, "evtwgt_genie_ncel_nweight", ev.evtwgt_genie_ncel_nweight);
  if(etree.GetBranch("evtwgt_genie_ncel_weight") != nullptr) set_object_input_branch_address(etree, "evtwgt_genie_ncel_weight", ev.evtwgt_genie_ncel_weight);

  if(etree.GetBranch("evtwgt_genie_pm1_nfunc") != nullptr) SetBranchAddress(etree, "evtwgt_genie_pm1_nfunc", &ev.evtwgt_genie_pm1_nfunc);

  if(etree.GetBranch("evtwgt_genie_pm1_funcname") != nullptr) set_object_input_branch_address(etree, "evtwgt_genie_pm1_funcname", ev.evtwgt_genie_pm1_funcname);
  if(etree.GetBranch("evtwgt_genie_pm1_nweight") != nullptr) set_object_input_branch_address(etree, "evtwgt_genie_pm1_nweight", ev.evtwgt_genie_pm1_nweight);
  if(etree.GetBranch("evtwgt_genie_pm1_weight") != nullptr) set_object_input_branch_address(etree, "evtwgt_genie_pm1_weight", ev.evtwgt_genie_pm1_weight);

  if(etree.GetBranch("evtwgt_genie_multisim_nfunc") != nullptr) SetBranchAddress(etree, "evtwgt_genie_multisim_nfunc", &ev.evtwgt_genie_multisim_nfunc);

  if(etree.GetBranch("evtwgt_genie_multisim_funcname") != nullptr) set_object_input_branch_address(etree, "evtwgt_genie_multisim_funcname", ev.evtwgt_genie_multisim_funcname);
  if(etree.GetBranch("evtwgt_genie_multisim_nweight") != nullptr) set_object_input_branch_address(etree, "evtwgt_genie_multisim_nweight", ev.evtwgt_genie_multisim_nweight);
  if(etree.GetBranch("evtwgt_genie_multisim_weight") != nullptr) set_object_input_branch_address(etree, "evtwgt_genie_multisim_weight", ev.evtwgt_genie_multisim_weight);

  if(etree.GetBranch("evtwgt_g4_multisim_nfunc") != nullptr) SetBranchAddress(etree, "evtwgt_g4_multisim_nfunc", &ev.evtwgt_g4_multisim_nfunc);

  if(etree.GetBranch("evtwgt_g4_multisim_funcname") != nullptr) set_object_input_branch_address(etree, "evtwgt_g4_multisim_funcname", ev.evtwgt_g4_multisim_funcname);
  if(etree.GetBranch("evtwgt_g4_multisim_nweight") != nullptr) set_object_input_branch_address(etree, "evtwgt_g4_multisim_nweight", ev.evtwgt_g4_multisim_nweight);
  if(etree.GetBranch("evtwgt_g4_multisim_weight") != nullptr) set_object_input_branch_address(etree, "evtwgt_g4_multisim_weight", ev.evtwgt_g4_multisim_weight);

  if(etree.GetBranch("evtwgt_flux_multisim_nfunc") != nullptr) SetBranchAddress(etree, "evtwgt_flux_multisim_nfunc", &ev.evtwgt_flux_multisim_nfunc);

  if(etree.GetBranch("evtwgt_flux_multisim_funcname") != nullptr) set_object_input_branch_address(etree, "evtwgt_flux_multisim_funcname", ev.evtwgt_flux_multisim_funcname);
  if(etree.GetBranch("evtwgt_flux_multisim_nweight") != nullptr) set_object_input_branch_address(etree, "evtwgt_flux_multisim_nweight", ev.evtwgt_flux_multisim_nweight);
  if(etree.GetBranch("evtwgt_flux_multisim_weight") != nullptr) set_object_input_branch_address(etree, "evtwgt_flux_multisim_weight", ev.evtwgt_flux_multisim_weight);

  if(etree.GetBranch("mc_nupdg") != nullptr) SetBranchAddress(etree, "mc_nupdg", &ev.mc_nupdg);
  if(etree.GetBranch("mc_n_muon") != nullptr) SetBranchAddress(etree, "mc_n_muon", &ev.mc_n_muon);
  if(etree.GetBranch("mc_n_proton") != nullptr) SetBranchAddress(etree, "mc_n_proton", &ev.mc_n_proton);
  if(etree.GetBranch("mc_n_photon") != nullptr) SetBranchAddress(etree, "mc_n_photon", &ev.mc_n_photon);
  if(etree.GetBranch("mc_n_pionpm") != nullptr) SetBranchAddress(etree, "mc_n_pionpm", &ev.mc_n_pionpm);
  if(etree.GetBranch("mc_n_pion0") != nullptr) SetBranchAddress(etree, "mc_n_pion0", &ev.mc_n_pion0);
  if(etree.GetBranch("mc_n_electron") != nullptr) SetBranchAddress(etree, "mc_n_electron", &ev.mc_n_electron);
  if(etree.GetBranch("mc_n_neutron") != nullptr) SetBranchAddress(etree, "mc_n_neutron", &ev.mc_n_neutron);
  if(etree.GetBranch("mc_nI_n_photon") != nullptr) SetBranchAddress(etree, "mc_nI_n_photon", &ev.mc_nI_n_photon);
  if(etree.GetBranch("mc_nI_n_proton") != nullptr) SetBranchAddress(etree, "mc_nI_n_proton", &ev.mc_nI_n_proton);
  if(etree.GetBranch("mc_nI_n_neutron") != nullptr) SetBranchAddress(etree, "mc_nI_n_neutron", &ev.mc_nI_n_neutron);
  if(etree.GetBranch("mc_n_threshold_muon") != nullptr) SetBranchAddress(etree, "mc_n_threshold_muon", &ev.mc_n_threshold_muon);
  if(etree.GetBranch("mc_n_threshold_proton") != nullptr) SetBranchAddress(etree, "mc_n_threshold_proton", &ev.mc_n_threshold_proton);
  if(etree.GetBranch("mc_n_threshold_pionpm") != nullptr) SetBranchAddress(etree, "mc_n_threshold_pionpm", &ev.mc_n_threshold_pionpm);
  if(etree.GetBranch("mc_n_threshold_pion0") != nullptr) SetBranchAddress(etree, "mc_n_threshold_pion0", &ev.mc_n_threshold_pion0);
  if(etree.GetBranch("mc_n_threshold_electron") != nullptr) SetBranchAddress(etree, "mc_n_threshold_electron", &ev.mc_n_threshold_electron);
  if(etree.GetBranch("mc_n_threshold_neutron") != nullptr) SetBranchAddress(etree, "mc_n_threshold_neutron", &ev.mc_n_threshold_neutron);

  if(etree.GetBranch("mc_g4_mom") != nullptr) set_object_input_branch_address(etree, "mc_g4_mom", ev.mc_g4_mom);
  if(etree.GetBranch("mc_g4_E") != nullptr) set_object_input_branch_address(etree, "mc_g4_E", ev.mc_g4_E);
  if(etree.GetBranch("mc_g4_p") != nullptr) set_object_input_branch_address(etree, "mc_g4_p", ev.mc_g4_p);
  if(etree.GetBranch("mc_g4_mass") != nullptr) set_object_input_branch_address(etree, "mc_g4_mass", ev.mc_g4_mass);
  if(etree.GetBranch("mc_g4_phi") != nullptr) set_object_input_branch_address(etree, "mc_g4_phi", ev.mc_g4_phi);
  if(etree.GetBranch("mc_g4_theta") != nullptr) set_object_input_branch_address(etree, "mc_g4_theta", ev.mc_g4_theta);
  if(etree.GetBranch("mc_g4_pdg") != nullptr) set_object_input_branch_address(etree, "mc_g4_pdg", ev.mc_g4_pdg);
  if(etree.GetBranch("mc_g4_start_x") != nullptr) set_object_input_branch_address(etree, "mc_g4_start_x", ev.mc_g4_start_x);
  if(etree.GetBranch("mc_g4_start_y") != nullptr) set_object_input_branch_address(etree, "mc_g4_start_y", ev.mc_g4_start_y);
  if(etree.GetBranch("mc_g4_start_z") != nullptr) set_object_input_branch_address(etree, "mc_g4_start_z", ev.mc_g4_start_z);
  if(etree.GetBranch("mc_g4_end_x") != nullptr) set_object_input_branch_address(etree, "mc_g4_end_x", ev.mc_g4_end_x);
  if(etree.GetBranch("mc_g4_end_y") != nullptr) set_object_input_branch_address(etree, "mc_g4_end_y", ev.mc_g4_end_y);
  if(etree.GetBranch("mc_g4_end_z") != nullptr) set_object_input_branch_address(etree, "mc_g4_end_z", ev.mc_g4_end_z);
  if(etree.GetBranch("mc_g4_photon_E") != nullptr) set_object_input_branch_address(etree, "mc_g4_photon_E", ev.mc_g4_photon_E);
  if(etree.GetBranch("mc_g4_photon_start_x") != nullptr) set_object_input_branch_address(etree, "mc_g4_photon_start_x", ev.mc_g4_photon_start_x);
  if(etree.GetBranch("mc_g4_photon_start_y") != nullptr) set_object_input_branch_address(etree, "mc_g4_photon_start_y", ev.mc_g4_photon_start_y);
  if(etree.GetBranch("mc_g4_photon_start_z") != nullptr) set_object_input_branch_address(etree, "mc_g4_photon_start_z", ev.mc_g4_photon_start_z);
  if(etree.GetBranch("mc_g4_photon_end_x") != nullptr) set_object_input_branch_address(etree, "mc_g4_photon_end_x", ev.mc_g4_photon_end_x);
  if(etree.GetBranch("mc_g4_photon_end_y") != nullptr) set_object_input_branch_address(etree, "mc_g4_photon_end_y", ev.mc_g4_photon_end_y);
  if(etree.GetBranch("mc_g4_photon_end_z") != nullptr) set_object_input_branch_address(etree, "mc_g4_photon_end_z", ev.mc_g4_photon_end_z);
  if(etree.GetBranch("mc_g4_proton_E") != nullptr) set_object_input_branch_address(etree, "mc_g4_proton_E", ev.mc_g4_proton_E);
  if(etree.GetBranch("mc_g4_proton_start_x") != nullptr) set_object_input_branch_address(etree, "mc_g4_proton_start_x", ev.mc_g4_proton_start_x);
  if(etree.GetBranch("mc_g4_proton_start_y") != nullptr) set_object_input_branch_address(etree, "mc_g4_proton_start_y", ev.mc_g4_proton_start_y);
  if(etree.GetBranch("mc_g4_proton_start_z") != nullptr) set_object_input_branch_address(etree, "mc_g4_proton_start_z", ev.mc_g4_proton_start_z);
  if(etree.GetBranch("mc_g4_proton_end_x") != nullptr) set_object_input_branch_address(etree, "mc_g4_proton_end_x", ev.mc_g4_proton_end_x);
  if(etree.GetBranch("mc_g4_proton_end_y") != nullptr) set_object_input_branch_address(etree, "mc_g4_proton_end_y", ev.mc_g4_proton_end_y);
  if(etree.GetBranch("mc_g4_proton_end_z") != nullptr) set_object_input_branch_address(etree, "mc_g4_proton_end_z", ev.mc_g4_proton_end_z);
  if(etree.GetBranch("mc_g4_neutron_E") != nullptr) set_object_input_branch_address(etree, "mc_g4_neutron_E", ev.mc_g4_neutron_E);
  if(etree.GetBranch("mc_g4_neutron_start_x") != nullptr) set_object_input_branch_address(etree, "mc_g4_neutron_start_x", ev.mc_g4_neutron_start_x);
  if(etree.GetBranch("mc_g4_neutron_start_y") != nullptr) set_object_input_branch_address(etree, "mc_g4_neutron_start_y", ev.mc_g4_neutron_start_y);
  if(etree.GetBranch("mc_g4_neutron_start_z") != nullptr) set_object_input_branch_address(etree, "mc_g4_neutron_start_z", ev.mc_g4_neutron_start_z);
  if(etree.GetBranch("mc_g4_neutron_end_x") != nullptr) set_object_input_branch_address(etree, "mc_g4_neutron_end_x", ev.mc_g4_neutron_end_x);
  if(etree.GetBranch("mc_g4_neutron_end_y") != nullptr) set_object_input_branch_address(etree, "mc_g4_neutron_end_y", ev.mc_g4_neutron_end_y);
  if(etree.GetBranch("mc_g4_neutron_end_z") != nullptr) set_object_input_branch_address(etree, "mc_g4_neutron_end_z", ev.mc_g4_neutron_end_z);

  if(etree.GetBranch("mc_g4_nI_photon_E") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_photon_E", ev.mc_g4_nI_photon_E);
  if(etree.GetBranch("mc_g4_nI_photon_start_x") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_photon_start_x", ev.mc_g4_nI_photon_start_x);
  if(etree.GetBranch("mc_g4_nI_photon_start_y") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_photon_start_y", ev.mc_g4_nI_photon_start_y);
  if(etree.GetBranch("mc_g4_nI_photon_start_z") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_photon_start_z", ev.mc_g4_nI_photon_start_z);
  if(etree.GetBranch("mc_g4_nI_photon_end_x") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_photon_end_x", ev.mc_g4_nI_photon_end_x);
  if(etree.GetBranch("mc_g4_nI_photon_end_y") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_photon_end_y", ev.mc_g4_nI_photon_end_y);
  if(etree.GetBranch("mc_g4_nI_photon_end_z") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_photon_end_z", ev.mc_g4_nI_photon_end_z);
  if(etree.GetBranch("mc_g4_nI_proton_E") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_proton_E", ev.mc_g4_nI_proton_E);
  if(etree.GetBranch("mc_g4_nI_proton_start_x") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_proton_start_x", ev.mc_g4_nI_proton_start_x);
  if(etree.GetBranch("mc_g4_nI_proton_start_y") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_proton_start_y", ev.mc_g4_nI_proton_start_y);
  if(etree.GetBranch("mc_g4_nI_proton_start_z") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_proton_start_z", ev.mc_g4_nI_proton_start_z);

  if(etree.GetBranch("mc_g4_nI_proton_end_x") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_proton_end_x", ev.mc_g4_nI_proton_end_x);
  if(etree.GetBranch("mc_g4_nI_proton_end_y") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_proton_end_y", ev.mc_g4_nI_proton_end_y);
  if(etree.GetBranch("mc_g4_nI_proton_end_z") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_proton_end_z", ev.mc_g4_nI_proton_end_z);
  if(etree.GetBranch("mc_g4_nI_neutron_E") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_neutron_E", ev.mc_g4_nI_neutron_E);
  if(etree.GetBranch("mc_g4_nI_neutron_start_x") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_neutron_start_x", ev.mc_g4_nI_neutron_start_x);
  if(etree.GetBranch("mc_g4_nI_neutron_start_y") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_neutron_start_y", ev.mc_g4_nI_neutron_start_y);
  if(etree.GetBranch("mc_g4_nI_neutron_start_z") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_neutron_start_z", ev.mc_g4_nI_neutron_start_z);
  if(etree.GetBranch("mc_g4_nI_neutron_end_x") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_neutron_end_x", ev.mc_g4_nI_neutron_end_x);
  if(etree.GetBranch("mc_g4_nI_neutron_end_y") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_neutron_end_y", ev.mc_g4_nI_neutron_end_y);
  if(etree.GetBranch("mc_g4_nI_neutron_end_z") != nullptr) set_object_input_branch_address(etree, "mc_g4_nI_neutron_end_z", ev.mc_g4_nI_neutron_end_z);

  if(etree.GetBranch("mc_g4_start_x_sce") != nullptr) set_object_input_branch_address(etree, "mc_g4_start_x_sce", ev.mc_g4_start_x_sce);
  if(etree.GetBranch("mc_g4_start_y_sce") != nullptr) set_object_input_branch_address(etree, "mc_g4_start_y_sce", ev.mc_g4_start_y_sce);
  if(etree.GetBranch("mc_g4_start_z_sce") != nullptr) set_object_input_branch_address(etree, "mc_g4_start_z_sce", ev.mc_g4_start_z_sce);
  if(etree.GetBranch("mc_g4_end_x_sce") != nullptr) set_object_input_branch_address(etree, "mc_g4_end_x_sce", ev.mc_g4_end_x_sce);
  if(etree.GetBranch("mc_g4_end_y_sce") != nullptr) set_object_input_branch_address(etree, "mc_g4_end_y_sce", ev.mc_g4_end_y_sce);
  if(etree.GetBranch("mc_g4_end_z_sce") != nullptr) set_object_input_branch_address(etree, "mc_g4_end_z_sce", ev.mc_g4_end_z_sce);
  if(etree.GetBranch("is_from_nu_slice") != nullptr) set_object_input_branch_address(etree, "is_from_nu_slice", ev.is_from_nu_slice);
  if(etree.GetBranch("is_primary") != nullptr) set_object_input_branch_address(etree, "is_primary", ev.is_primary);
  if(etree.GetBranch("is_contained") != nullptr) set_object_input_branch_address(etree, "is_contained", ev.is_contained);
  if(etree.GetBranch("is_st") != nullptr) set_object_input_branch_address(etree, "is_st", ev.is_st);
  if(etree.GetBranch("is_nc1p") != nullptr) set_object_input_branch_address(etree, "is_nc1p", ev.is_nc1p);
  if(etree.GetBranch("is_reco_nc1p") != nullptr) set_object_input_branch_address(etree, "is_reco_nc1p", ev.is_reco_nc1p);
  if(etree.GetBranch("mc_pdg") != nullptr) set_object_input_branch_address(etree, "mc_pdg", ev.mc_pdg);
  if(etree.GetBranch("mc_primary") != nullptr) set_object_input_branch_address(etree, "mc_primary", ev.mc_primary);
  if(etree.GetBranch("mc_origin") != nullptr) set_object_input_branch_address(etree, "mc_origin", ev.mc_origin);
  if(etree.GetBranch("mc_length") != nullptr) set_object_input_branch_address(etree, "mc_length", ev.mc_length);
  if(etree.GetBranch("mc_start_x") != nullptr) set_object_input_branch_address(etree, "mc_start_x", ev.mc_start_x);
  if(etree.GetBranch("mc_start_y") != nullptr) set_object_input_branch_address(etree, "mc_start_y", ev.mc_start_y);
  if(etree.GetBranch("mc_start_z") != nullptr) set_object_input_branch_address(etree, "mc_start_z", ev.mc_start_z);
  if(etree.GetBranch("mc_end_x") != nullptr) set_object_input_branch_address(etree, "mc_end_x", ev.mc_end_x);
  if(etree.GetBranch("mc_end_y") != nullptr) set_object_input_branch_address(etree, "mc_end_y", ev.mc_end_y);
  if(etree.GetBranch("mc_end_z") != nullptr)set_object_input_branch_address(etree, "mc_end_z", ev.mc_end_z);
  if(etree.GetBranch("mc_start_x_sce") != nullptr) set_object_input_branch_address(etree, "mc_start_x_sce", ev.mc_start_x_sce);
  if(etree.GetBranch("mc_start_y_sce") != nullptr) set_object_input_branch_address(etree, "mc_start_y_sce", ev.mc_start_y_sce);
  if(etree.GetBranch("mc_start_z_sce") != nullptr) set_object_input_branch_address(etree, "mc_start_z_sce", ev.mc_start_z_sce);
  if(etree.GetBranch("mc_end_x_sce") != nullptr) set_object_input_branch_address(etree, "mc_end_x_sce", ev.mc_end_x_sce);
  if(etree.GetBranch("mc_end_y_sce") != nullptr) set_object_input_branch_address(etree, "mc_end_y_sce", ev.mc_end_y_sce);
  if(etree.GetBranch("mc_end_z_sce") != nullptr) set_object_input_branch_address(etree, "mc_end_z_sce", ev.mc_end_z_sce);
  if(etree.GetBranch("mc_theta") != nullptr) set_object_input_branch_address(etree, "mc_theta", ev.mc_theta);
  if(etree.GetBranch("mc_phi") != nullptr) set_object_input_branch_address(etree, "mc_phi", ev.mc_phi);
  if(etree.GetBranch("mc_ke") != nullptr) set_object_input_branch_address(etree, "mc_ke", ev.mc_ke);
  if(etree.GetBranch("mc_mom") != nullptr) set_object_input_branch_address(etree, "mc_mom", ev.mc_mom);
  if(etree.GetBranch("n_pfp") != nullptr) set_object_input_branch_address(etree, "n_pfp", ev.n_pfp);
  if(etree.GetBranch("n_trk") != nullptr) set_object_input_branch_address(etree, "n_trk", ev.n_trk);
  if(etree.GetBranch("id_pfp") != nullptr) set_object_input_branch_address(etree, "id_pfp", ev.id_pfp);
  if(etree.GetBranch("isinFV") != nullptr) set_object_input_branch_address(etree, "isinFV", ev.isinFV);
  if(etree.GetBranch("n_shower") != nullptr) set_object_input_branch_address(etree, "n_shower", ev.n_shower);
  if(etree.GetBranch("parentPDG") != nullptr) set_object_input_branch_address(etree, "parentPDG", ev.parentPDG);
  if(etree.GetBranch("trk_score") != nullptr) set_object_input_branch_address(etree, "trk_score", ev.trk_score);
  if(etree.GetBranch("KE_len") != nullptr) set_object_input_branch_address(etree, "KE_len", ev.KE_len);
  if(etree.GetBranch("dislen_ratio") != nullptr) set_object_input_branch_address(etree, "dislen_ratio", ev.dislen_ratio);
  if(etree.GetBranch("reco_q2") != nullptr) set_object_input_branch_address(etree, "reco_q2", ev.reco_q2);
  if(etree.GetBranch("top_score") != nullptr) set_object_input_branch_address(etree, "top_score", ev.top_score);
  if(etree.GetBranch("flash_score") != nullptr) set_object_input_branch_address(etree, "flash_score", ev.flash_score);
  if(etree.GetBranch("n_daughters") != nullptr) set_object_input_branch_address(etree, "n_daughters", ev.n_daughters);
  if(etree.GetBranch("has_shower") != nullptr) set_object_input_branch_address(etree, "has_shower", ev.has_shower);
  if(etree.GetBranch("reco_nu_vtxx") != nullptr) SetBranchAddress(etree, "reco_nu_vtxx", &ev.reco_nu_vtxx);
  if(etree.GetBranch("reco_nu_vtxy") != nullptr) SetBranchAddress(etree, "reco_nu_vtxy", &ev.reco_nu_vtxy);
  if(etree.GetBranch("reco_nu_vtxz") != nullptr) SetBranchAddress(etree, "reco_nu_vtxz", &ev.reco_nu_vtxz);
  if(etree.GetBranch("deltaY") != nullptr) set_object_input_branch_address(etree, "deltaY", ev.deltaY);
  if(etree.GetBranch("deltaZ") != nullptr) set_object_input_branch_address(etree, "deltaZ", ev.deltaZ);
  if(etree.GetBranch("deltaYSigma") != nullptr) set_object_input_branch_address(etree, "deltaYSigma", ev.deltaYSigma);
  if(etree.GetBranch("deltaZSigma") != nullptr) set_object_input_branch_address(etree, "deltaZSigma", ev.deltaZSigma);
  if(etree.GetBranch("chargeToLightRatio") != nullptr) set_object_input_branch_address(etree, "chargeToLightRatio", ev.chargeToLightRatio);
  if(etree.GetBranch("xclVariable") != nullptr) set_object_input_branch_address(etree, "xclVariable", ev.xclVariable);
  if(etree.GetBranch("flip_0") != nullptr) set_object_input_branch_address(etree, "flip_0", ev.flip_0);
  if(etree.GetBranch("flip_1") != nullptr) set_object_input_branch_address(etree, "flip_1", ev.flip_1);
  if(etree.GetBranch("flip_2") != nullptr) set_object_input_branch_address(etree, "flip_2", ev.flip_2);
  if(etree.GetBranch("reco_length") != nullptr) set_object_input_branch_address(etree, "reco_length", ev.reco_length);
  if(etree.GetBranch("reco_start_x") != nullptr) set_object_input_branch_address(etree, "reco_start_x", ev.reco_start_x);
  if(etree.GetBranch("reco_start_y") != nullptr) set_object_input_branch_address(etree, "reco_start_y", ev.reco_start_y);
  if(etree.GetBranch("reco_start_z") != nullptr) set_object_input_branch_address(etree, "reco_start_z", ev.reco_start_z);
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
void set_event_output_branch_addresses(TTree& out_tree, AnalysisEvent& ev, bool create = false) {

  set_output_branch_address(out_tree, "reco_proton_ke", &ev.reco_proton_ke_, create, "reco_proton_ke/D");
  set_output_branch_address(out_tree, "reco_q2", &ev.reco_q2_, create, "reco_q2/D");
  set_output_branch_address(out_tree, "reco_proton_mom", &ev.reco_proton_mom_, create, "reco_proton_mom/D");
  set_output_branch_address(out_tree, "reco_costheta", &ev.reco_costheta_, create, "reco_costheta/D");
  set_output_branch_address(out_tree, "reco_bdt_score", &ev.reco_bdt_score_, create, "reco_bdt_score/D");
  //set_object_output_branch_address< std::vector<double> >(out_tree, "computed_weight", ev.computed_weight_, create);
  set_output_branch_address(out_tree, "is_mc", &ev.is_mc_, create, "is_mc/O");
  set_output_branch_address(out_tree, "PoT_scale", &ev.PoT_scale_, create, "PoT_scale/D");
  set_output_branch_address(out_tree, "true_proton_ke", &ev.true_proton_ke_, create, "true_proton_ke/D");
  set_output_branch_address(out_tree, "true_costheta", &ev.true_costheta_, create, "true_costheta/D");
  set_output_branch_address(out_tree, "true_q2", &ev.true_q2_, create, "true_q2/D");
  set_output_branch_address(out_tree, "sig_is_nc", &ev.sig_is_nc_, create, "sig_is_nc/O");
  set_output_branch_address(out_tree, "sel_reco_1p", &ev.sel_reco_1p_, create, "sel_reco_1p/O");
  set_output_branch_address(out_tree, "sel_bdt_cut", &ev.sel_bdt_cut_, create, "sel_bdt_cut/O");
  set_output_branch_address(out_tree, "sel_blip_cut", &ev.sel_blip_cut_, create, "sel_blip_cut/O");
  // set_output_branch_address(out_tree, "reco_nblip_upstream", &ev.reco_nblip_upstream_, create, "reco_nblip_upstream/I");
  // set_output_branch_address(out_tree, "reco_trk_dis", &ev.reco_trk_dis_, create, "reco_trk_dis/F"); //is_mc_
}

/*
void set_event_output_branch_addresses(TTree& out_tree, AnalysisEvent& ev, bool create = false)
{
  set_output_branch_address(out_tree, "run", &ev.run, create, "run/I");
  set_output_branch_address(out_tree, "subrun", &ev.subrun, create, "subrun/I");
  set_output_branch_address(out_tree, "event", &ev.event, create, "event/I");
  set_output_branch_address(out_tree, "evt_gen_nc1p", &ev.evt_gen_nc1p, create, "evt_gen_nc1p/I");
  set_output_branch_address(out_tree, "evt_gen_nce", &ev.evt_gen_nce, create, "evt_gen_nce/I");
  set_output_branch_address(out_tree, "evt_gen_nc1p_q2_gen", &ev.evt_gen_nc1p_q2_gen, create, "evt_gen_nc1p_q2_gen/F");
  set_output_branch_address(out_tree, "evt_gen_nc1p_q2_ke", &ev.evt_gen_nc1p_q2_ke, create, "evt_gen_nc1p_q2_ke/F");
  set_output_branch_address(out_tree, "evt_gen_nc1p_stx", &ev.evt_gen_nc1p_stx, create, "evt_gen_nc1p_stx/F");
  set_output_branch_address(out_tree, "evt_gen_nc1p_sty", &ev.evt_gen_nc1p_sty, create, "evt_gen_nc1p_sty/F");
  set_output_branch_address(out_tree, "evt_gen_nc1p_stz", &ev.evt_gen_nc1p_stz, create, "evt_gen_nc1p_stz/F");
  set_output_branch_address(out_tree, "evt_gen_nc1p_endx", &ev.evt_gen_nc1p_endx, create, "evt_gen_nc1p_endx/F");
  set_output_branch_address(out_tree, "evt_gen_nc1p_endy", &ev.evt_gen_nc1p_endy, create, "evt_gen_nc1p_endy/F");
  set_output_branch_address(out_tree, "evt_gen_nc1p_endz", &ev.evt_gen_nc1p_endz, create, "evt_gen_nc1p_endz/F");
  set_output_branch_address(out_tree, "evt_gen_nc1p_costheta", &ev.evt_gen_nc1p_costheta, create, "evt_gen_nc1p_costheta/F");
  set_output_branch_address(out_tree, "evt_gen_nc1p_phi", &ev.evt_gen_nc1p_phi, create, "evt_gen_nc1p_phi/F");
  set_output_branch_address(out_tree, "evt_gen_nc1p_mom", &ev.evt_gen_nc1p_mom, create, "evt_gen_nc1p_mom/F");
  set_output_branch_address(out_tree, "evt_gen_nc1p_ke", &ev.evt_gen_nc1p_ke, create, "evt_gen_nc1p_ke/F");
  set_output_branch_address(out_tree, "evt_gen_nc1p_contained", &ev.evt_gen_nc1p_contained, create, "evt_gen_nc1p_contained/I");
  set_output_branch_address(out_tree, "evt_gen_nc1p_inFV", &ev.evt_gen_nc1p_inFV, create, "evt_gen_nc1p_inFV/I");
  set_output_branch_address(out_tree, "evt_reco_1p_nu", &ev.evt_reco_1p_nu, create, "evt_reco_1p_nu/I");
  set_output_branch_address(out_tree, "evt_reco_1p_non_nu", &ev.evt_reco_1p_non_nu, create, "evt_reco_1p_non_nu/I");
  set_output_branch_address(out_tree, "evt_reco_1p", &ev.evt_reco_1p, create, "evt_reco_1p/I");
  set_output_branch_address(out_tree, "evt_reco_1mu1p", &ev.evt_reco_1mu1p, create, "evt_reco_1mu1p/I");
  set_output_branch_address(out_tree, "nflashes", &ev.nflashes, create, "nflashes/I");
  set_output_branch_address(out_tree, "evt_n_pfp", &ev.evt_n_pfp, create, "evt_n_pfp/I");
  set_output_branch_address(out_tree, "evt_n_trk", &ev.evt_n_trk, create, "evt_n_trk/I");
  set_output_branch_address(out_tree, "evt_n_shower", &ev.evt_n_shower, create, "evt_n_shower/I");
  set_output_branch_address(out_tree, "evt_n_nu", &ev.evt_n_nu, create, "evt_n_nu/I");
  set_output_branch_address(out_tree, "evt_n_nu_pfp", &ev.evt_n_nu_pfp, create, "evt_n_nu_pfp/I");
  set_output_branch_address(out_tree, "evt_nu_PDG", &ev.evt_nu_PDG, create, "evt_nu_PDG/I");

  set_object_output_branch_address< std::vector<float> >(out_tree, "flash_Ywidth", ev.flash_Ywidth, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "flash_Zwidth", ev.flash_Zwidth, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "flash_Twidth", ev.flash_Twidth, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "flash_Ycenter", ev.flash_Ycenter, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "flash_Zcenter", ev.flash_Zcenter, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "flash_Time", ev.flash_Time, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "flash_CRThit", ev.flash_CRThit, create);
  set_object_output_branch_address< std::vector<bool> >(out_tree, "flash_CRTveto", ev.flash_CRTveto, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "flash_TotalPE", ev.flash_TotalPE, create);

  set_output_branch_address(out_tree, "flash_brightest_Ywidth", &ev.flash_brightest_Ywidth, create, "flash_brightest_Ywidth/F");
  set_output_branch_address(out_tree, "flash_brightest_Zwidth", &ev.flash_brightest_Zwidth, create, "flash_brightest_Zwidth/F");
  set_output_branch_address(out_tree, "flash_brightest_Twidth", &ev.flash_brightest_Twidth, create, "flash_brightest_Twidth/F");
  set_output_branch_address(out_tree, "flash_brightest_Ycenter", &ev.flash_brightest_Ycenter, create, "flash_brightest_Ycenter/F");
  set_output_branch_address(out_tree, "flash_brightest_Zcenter", &ev.flash_brightest_Zcenter, create, "flash_brightest_Zcenter/F");
  set_output_branch_address(out_tree, "flash_brightest_Time", &ev.flash_brightest_Time, create, "flash_brightest_Time/F");
  set_output_branch_address(out_tree, "flash_brightest_CRThit", &ev.flash_brightest_CRThit, create, "flash_brightest_CRThit/F");
  set_output_branch_address(out_tree, "flash_brightest_CRTveto", &ev.flash_brightest_CRTveto, create, "flash_brightest_CRTveto/O");
  set_output_branch_address(out_tree, "flash_brightest_TotalPE", &ev.flash_brightest_TotalPE, create, "flash_brightest_TotalPE/F");

  set_object_output_branch_address< std::vector<std::vector<float>> >(out_tree, "flash_PE_Per_PMT", ev.flash_PE_Per_PMT, create);

  set_output_branch_address(out_tree, "mc_ccnc", &ev.mc_ccnc, create, "mc_ccnc/I");
  set_output_branch_address(out_tree, "mc_mode", &ev.mc_mode, create, "mc_mode/I");
  set_output_branch_address(out_tree, "mc_interactiontype", &ev.mc_interactiontype, create, "mc_interactiontype/I");
  set_output_branch_address(out_tree, "mc_hitnuc", &ev.mc_hitnuc, create, "mc_hitnuc/I");
  set_output_branch_address(out_tree, "mc_hitnuc11", &ev.mc_hitnuc11, create, "mc_hitnuc11/I");
  set_output_branch_address(out_tree, "mc_hitnuc11_p", &ev.mc_hitnuc11_p, create, "mc_hitnuc11_p/F");
  set_output_branch_address(out_tree, "mc_hitnuc11_px", &ev.mc_hitnuc11_px, create, "mc_hitnuc11_px/F");
  set_output_branch_address(out_tree, "mc_hitnuc11_py", &ev.mc_hitnuc11_py, create, "mc_hitnuc11_py/F");
  set_output_branch_address(out_tree, "mc_hitnuc11_pz", &ev.mc_hitnuc11_pz, create, "mc_hitnuc11_pz/F");
  set_output_branch_address(out_tree, "mc_hitnuc11_nuwro", &ev.mc_hitnuc11_nuwro, create, "mc_hitnuc11_nuwro/I");
  set_output_branch_address(out_tree, "mc_hitnuc11_nuwro_p", &ev.mc_hitnuc11_nuwro_p, create, "mc_hitnuc11_nuwro_p/F");
  set_output_branch_address(out_tree, "mc_hitnuc11_nuwro_px", &ev.mc_hitnuc11_nuwro_px, create, "mc_hitnuc11_nuwro_px/F");
  set_output_branch_address(out_tree, "mc_hitnuc11_nuwro_py", &ev.mc_hitnuc11_nuwro_py, create, "mc_hitnuc11_nuwro_py/F");
  set_output_branch_address(out_tree, "mc_hitnuc11_nuwro_pz", &ev.mc_hitnuc11_nuwro_pz, create, "mc_hitnuc11_nuwro_pz/F");
  set_output_branch_address(out_tree, "mc_q2", &ev.mc_q2, create, "mc_q2/F");
  set_output_branch_address(out_tree, "mc_nu_vtxx", &ev.mc_nu_vtxx, create, "mc_nu_vtxx/F");
  set_output_branch_address(out_tree, "mc_nu_vtxy", &ev.mc_nu_vtxy, create, "mc_nu_vtxy/F");
  set_output_branch_address(out_tree, "mc_nu_vtxz", &ev.mc_nu_vtxz, create, "mc_nu_vtxz/F");
  set_output_branch_address(out_tree, "mc_nu_vtxx_sce", &ev.mc_nu_vtxx_sce, create, "mc_nu_vtxx_sce/F");
  set_output_branch_address(out_tree, "mc_nu_vtxy_sce", &ev.mc_nu_vtxy_sce, create, "mc_nu_vtxy_sce/F");
  set_output_branch_address(out_tree, "mc_nu_vtxz_sce", &ev.mc_nu_vtxz_sce, create, "mc_nu_vtxz_sce/F");
  set_output_branch_address(out_tree, "mc_enu", &ev.mc_enu, create, "mc_enu/F");
  set_output_branch_address(out_tree, "mc_wgt_v4a", &ev.mc_wgt_v4a, create, "mc_wgt_v4a/F");
  set_output_branch_address(out_tree, "mc_wgt_tunedcv", &ev.mc_wgt_tunedcv, create, "mc_wgt_tunedcv/F");

  set_output_branch_address(out_tree, "evtwgt_genie_ncel_nfunc", &ev.evtwgt_genie_ncel_nfunc, create, "evtwgt_genie_ncel_nfunc/I");

  set_object_output_branch_address< std::vector<std::string> >(out_tree, "evtwgt_genie_ncel_funcname", ev.evtwgt_genie_ncel_funcname, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "evtwgt_genie_ncel_nweight", ev.evtwgt_genie_ncel_nweight, create);
  set_object_output_branch_address< std::vector<std::vector<double>> >(out_tree, "evtwgt_genie_ncel_weight", ev.evtwgt_genie_ncel_weight, create);

  set_output_branch_address(out_tree, "evtwgt_genie_pm1_nfunc", &ev.evtwgt_genie_pm1_nfunc, create, "evtwgt_genie_pm1_nfunc/I");

  set_object_output_branch_address< std::vector<std::string> >(out_tree, "evtwgt_genie_pm1_funcname", ev.evtwgt_genie_pm1_funcname, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "evtwgt_genie_pm1_nweight", ev.evtwgt_genie_pm1_nweight, create);
  set_object_output_branch_address< std::vector<std::vector<double>> >(out_tree, "evtwgt_genie_pm1_weight", ev.evtwgt_genie_pm1_weight, create);

  set_output_branch_address(out_tree, "evtwgt_genie_multisim_nfunc", &ev.evtwgt_genie_multisim_nfunc, create, "evtwgt_genie_multisim_nfunc/I");

  set_object_output_branch_address< std::vector<std::string> >(out_tree, "evtwgt_genie_multisim_funcname", ev.evtwgt_genie_multisim_funcname, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "evtwgt_genie_multisim_nweight", ev.evtwgt_genie_multisim_nweight, create);
  set_object_output_branch_address< std::vector<std::vector<double>> >(out_tree, "evtwgt_genie_multisim_weight", ev.evtwgt_genie_multisim_weight, create);

  set_output_branch_address(out_tree, "evtwgt_g4_multisim_nfunc", &ev.evtwgt_g4_multisim_nfunc, create, "evtwgt_g4_multisim_nfunc/I");

  set_object_output_branch_address< std::vector<std::string> >(out_tree, "evtwgt_g4_multisim_funcname", ev.evtwgt_g4_multisim_funcname, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "evtwgt_g4_multisim_nweight", ev.evtwgt_g4_multisim_nweight, create);
  set_object_output_branch_address< std::vector<std::vector<double>> >(out_tree, "evtwgt_g4_multisim_weight", ev.evtwgt_g4_multisim_weight, create);

  set_output_branch_address(out_tree, "evtwgt_flux_multisim_nfunc", &ev.evtwgt_flux_multisim_nfunc, create, "evtwgt_flux_multisim_nfunc/I");

  set_object_output_branch_address< std::vector<std::string> >(out_tree, "evtwgt_flux_multisim_funcname", ev.evtwgt_flux_multisim_funcname, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "evtwgt_flux_multisim_nweight", ev.evtwgt_flux_multisim_nweight, create);
  set_object_output_branch_address< std::vector<std::vector<double>> >(out_tree, "evtwgt_flux_multisim_weight", ev.evtwgt_flux_multisim_weight, create);

  set_output_branch_address(out_tree, "mc_nupdg", &ev.mc_nupdg, create, "mc_nupdg/I");
  set_output_branch_address(out_tree, "mc_n_muon", &ev.mc_n_muon, create, "mc_n_muon/I");
  set_output_branch_address(out_tree, "mc_n_proton", &ev.mc_n_proton, create, "mc_n_proton/I");
  set_output_branch_address(out_tree, "mc_n_photon", &ev.mc_n_photon, create, "mc_n_photon/I");
  set_output_branch_address(out_tree, "mc_n_pionpm", &ev.mc_n_pionpm, create, "mc_n_pionpm/I");
  set_output_branch_address(out_tree, "mc_n_pion0", &ev.mc_n_pion0, create, "mc_n_pion0/I");
  set_output_branch_address(out_tree, "mc_n_electron", &ev.mc_n_electron, create, "mc_n_electron/I");
  set_output_branch_address(out_tree, "mc_n_neutron", &ev.mc_n_neutron, create, "mc_n_neutron/I");
  set_output_branch_address(out_tree, "mc_nI_n_photon", &ev.mc_nI_n_photon, create, "mc_nI_n_photon/I");
  set_output_branch_address(out_tree, "mc_nI_n_proton", &ev.mc_nI_n_proton, create, "mc_nI_n_proton/I");
  set_output_branch_address(out_tree, "mc_nI_n_neutron", &ev.mc_nI_n_neutron, create, "mc_nI_n_neutron/I");
  set_output_branch_address(out_tree, "mc_n_threshold_muon", &ev.mc_n_threshold_muon, create, "mc_n_threshold_muon/I");
  set_output_branch_address(out_tree, "mc_n_threshold_proton", &ev.mc_n_threshold_proton, create, "mc_n_threshold_proton/I");
  set_output_branch_address(out_tree, "mc_n_threshold_pionpm", &ev.mc_n_threshold_pionpm, create, "mc_n_threshold_pionpm/I");
  set_output_branch_address(out_tree, "mc_n_threshold_pion0", &ev.mc_n_threshold_pion0, create, "mc_n_threshold_pion0/I");
  set_output_branch_address(out_tree, "mc_n_threshold_electron", &ev.mc_n_threshold_electron, create, "mc_n_threshold_electron/I");
  set_output_branch_address(out_tree, "mc_n_threshold_neutron", &ev.mc_n_threshold_neutron, create, "mc_n_threshold_neutron/I");

  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_mom", ev.mc_g4_mom, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_E", ev.mc_g4_E, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_p", ev.mc_g4_p, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_mass", ev.mc_g4_mass, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_phi", ev.mc_g4_phi, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_theta", ev.mc_g4_theta, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "mc_g4_pdg", ev.mc_g4_pdg, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_start_x", ev.mc_g4_start_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_start_y", ev.mc_g4_start_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_start_z", ev.mc_g4_start_z, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_end_x", ev.mc_g4_end_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_end_y", ev.mc_g4_end_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_end_z", ev.mc_g4_end_z, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_photon_E", ev.mc_g4_photon_E, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_photon_start_x", ev.mc_g4_photon_start_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_photon_start_y", ev.mc_g4_photon_start_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_photon_start_z", ev.mc_g4_photon_start_z, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_photon_end_x", ev.mc_g4_photon_end_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_photon_end_y", ev.mc_g4_photon_end_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_photon_end_z", ev.mc_g4_photon_end_z, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_proton_E", ev.mc_g4_proton_E, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_proton_start_x", ev.mc_g4_proton_start_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_proton_start_y", ev.mc_g4_proton_start_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_proton_start_z", ev.mc_g4_proton_start_z, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_proton_end_x", ev.mc_g4_proton_end_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_proton_end_y", ev.mc_g4_proton_end_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_proton_end_z", ev.mc_g4_proton_end_z, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_neutron_E", ev.mc_g4_neutron_E, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_neutron_start_x", ev.mc_g4_neutron_start_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_neutron_start_y", ev.mc_g4_neutron_start_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_neutron_start_z", ev.mc_g4_neutron_start_z, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_neutron_end_x", ev.mc_g4_neutron_end_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_neutron_end_y", ev.mc_g4_neutron_end_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_neutron_end_z", ev.mc_g4_neutron_end_z, create);

  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_photon_E", ev.mc_g4_nI_photon_E, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_photon_start_x", ev.mc_g4_nI_photon_start_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_photon_start_y", ev.mc_g4_nI_photon_start_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_photon_start_z", ev.mc_g4_nI_photon_start_z, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_photon_end_x", ev.mc_g4_nI_photon_end_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_photon_end_y", ev.mc_g4_nI_photon_end_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_photon_end_z", ev.mc_g4_nI_photon_end_z, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_proton_E", ev.mc_g4_nI_proton_E, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_proton_start_x", ev.mc_g4_nI_proton_start_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_proton_start_y", ev.mc_g4_nI_proton_start_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_proton_start_z", ev.mc_g4_nI_proton_start_z, create);

  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_proton_end_x", ev.mc_g4_nI_proton_end_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_proton_end_y", ev.mc_g4_nI_proton_end_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_proton_end_z", ev.mc_g4_nI_proton_end_z, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_neutron_E", ev.mc_g4_nI_neutron_E, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_neutron_start_x", ev.mc_g4_nI_neutron_start_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_neutron_start_y", ev.mc_g4_nI_neutron_start_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_neutron_start_z", ev.mc_g4_nI_neutron_start_z, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_neutron_end_x", ev.mc_g4_nI_neutron_end_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_neutron_end_y", ev.mc_g4_nI_neutron_end_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_nI_neutron_end_z", ev.mc_g4_nI_neutron_end_z, create);

  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_start_x_sce", ev.mc_g4_start_x_sce, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_start_y_sce", ev.mc_g4_start_y_sce, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_start_z_sce", ev.mc_g4_start_z_sce, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_end_x_sce", ev.mc_g4_end_x_sce, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_end_y_sce", ev.mc_g4_end_y_sce, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_g4_end_z_sce", ev.mc_g4_end_z_sce, create);
  set_object_output_branch_address< std::vector<bool> >(out_tree, "is_from_nu_slice", ev.is_from_nu_slice, create);
  set_object_output_branch_address< std::vector<bool> >(out_tree, "is_primary", ev.is_primary, create);
  set_object_output_branch_address< std::vector<bool> >(out_tree, "is_contained", ev.is_contained, create);
  set_object_output_branch_address< std::vector<bool> >(out_tree, "is_st", ev.is_st, create);
  set_object_output_branch_address< std::vector<bool> >(out_tree, "is_nc1p", ev.is_nc1p, create);
  set_object_output_branch_address< std::vector<bool> >(out_tree, "is_reco_nc1p", ev.is_reco_nc1p, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "mc_pdg", ev.mc_pdg, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "mc_primary", ev.mc_primary, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "mc_origin", ev.mc_origin, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_length", ev.mc_length, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_start_x", ev.mc_start_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_start_y", ev.mc_start_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_start_z", ev.mc_start_z, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_end_x", ev.mc_end_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_end_y", ev.mc_end_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_end_z", ev.mc_end_z, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_start_x_sce", ev.mc_start_x_sce, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_start_y_sce", ev.mc_start_y_sce, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_start_z_sce", ev.mc_start_z_sce, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_end_x_sce", ev.mc_end_x_sce, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_end_y_sce", ev.mc_end_y_sce, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_end_z_sce", ev.mc_end_z_sce, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_theta", ev.mc_theta, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_phi", ev.mc_phi, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_ke", ev.mc_ke, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "mc_mom", ev.mc_mom, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "n_pfp", ev.n_pfp, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "n_trk", ev.n_trk, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "id_pfp", ev.id_pfp, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "isinFV", ev.isinFV, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "n_shower", ev.n_shower, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "parentPDG", ev.parentPDG, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "trk_score", ev.trk_score, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "KE_len", ev.KE_len, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "dislen_ratio", ev.dislen_ratio, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_q2", ev.reco_q2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "top_score", ev.top_score, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "flash_score", ev.flash_score, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "n_daughters", ev.n_daughters, create);
  set_object_output_branch_address< std::vector<bool> >(out_tree, "has_shower", ev.has_shower, create);
  set_output_branch_address(out_tree, "reco_nu_vtxx", &ev.reco_nu_vtxx, create, "reco_nu_vtxx/F");
  set_output_branch_address(out_tree, "reco_nu_vtxy", &ev.reco_nu_vtxy, create, "reco_nu_vtxy/F");
  set_output_branch_address(out_tree, "reco_nu_vtxz", &ev.reco_nu_vtxz, create, "reco_nu_vtxz/F");
  set_object_output_branch_address< std::vector<float> >(out_tree, "deltaY", ev.deltaY, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "deltaZ", ev.deltaZ, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "deltaYSigma", ev.deltaYSigma, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "deltaZSigma", ev.deltaZSigma, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "chargeToLightRatio", ev.chargeToLightRatio, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "xclVariable", ev.xclVariable, create);
  set_object_output_branch_address< std::vector<bool> >(out_tree, "flip_0", ev.flip_0, create);
  set_object_output_branch_address< std::vector<bool> >(out_tree, "flip_1", ev.flip_1, create);
  set_object_output_branch_address< std::vector<bool> >(out_tree, "flip_2", ev.flip_2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_length", ev.reco_length, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_start_x", ev.reco_start_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_start_y", ev.reco_start_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_start_z", ev.reco_start_z, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_end_x", ev.reco_end_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_end_y", ev.reco_end_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_end_z", ev.reco_end_z, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_theta", ev.reco_theta, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_phi", ev.reco_phi, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_start_x_f2", ev.reco_start_x_f2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_start_y_f2", ev.reco_start_y_f2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_start_z_f2", ev.reco_start_z_f2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_end_x_f2", ev.reco_end_x_f2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_end_y_f2", ev.reco_end_y_f2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_end_z_f2", ev.reco_end_z_f2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_theta_f2", ev.reco_theta_f2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_phi_f2", ev.reco_phi_f2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_ke", ev.reco_ke, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_mom", ev.reco_mom, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_mom_muon", ev.reco_mom_muon, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_mom_proton", ev.reco_mom_proton, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "reco_mom_pion", ev.reco_mom_pion, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "nhits_0", ev.nhits_0, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "nhits_1", ev.nhits_1, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "nhits_2", ev.nhits_2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "chi2_p_0", ev.chi2_p_0, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "chi2_p_1", ev.chi2_p_1, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "chi2_p_2", ev.chi2_p_2, create);

  set_object_output_branch_address< std::vector<float> >(out_tree, "start_dedx_0", ev.start_dedx_0, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "start_dedx_1", ev.start_dedx_1, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "start_dedx_2", ev.start_dedx_2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "end_dedx_0", ev.end_dedx_0, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "end_dedx_1", ev.end_dedx_1, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "end_dedx_2", ev.end_dedx_2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "start_dedx_0_f2", ev.start_dedx_0_f2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "start_dedx_1_f2", ev.start_dedx_1_f2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "start_dedx_2_f2", ev.start_dedx_2_f2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "end_dedx_0_f2", ev.end_dedx_0_f2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "end_dedx_1_f2", ev.end_dedx_1_f2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "end_dedx_2_f2", ev.end_dedx_2_f2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "ratio_dedx_0", ev.ratio_dedx_0, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "ratio_dedx_1", ev.ratio_dedx_1, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "ratio_dedx_2", ev.ratio_dedx_2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "avg_dedx_0", ev.avg_dedx_0, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "avg_dedx_1", ev.avg_dedx_1, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "avg_dedx_2", ev.avg_dedx_2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "total_dedx_0", ev.total_dedx_0, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "total_dedx_1", ev.total_dedx_1, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "total_dedx_2", ev.total_dedx_2, create);
  set_output_branch_address(out_tree, "nclusters", &ev.nclusters, create, "nclusters/I");
  set_output_branch_address(out_tree, "nclustersps", &ev.nclustersps, create, "nclustersps/I");
  set_object_output_branch_address< std::vector<int> >(out_tree, "cluster_ID", ev.cluster_ID, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "cluster_plane", ev.cluster_plane, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "cluster_start_charge", ev.cluster_start_charge, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "cluster_start_angle", ev.cluster_start_angle, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "cluster_end_charge", ev.cluster_end_charge, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "cluster_end_angle", ev.cluster_end_angle, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "cluster_integral", ev.cluster_integral, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "cluster_integral_average", ev.cluster_integral_average, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "cluster_summedADC", ev.cluster_summedADC, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "cluster_summedADC_average", ev.cluster_summedADC_average, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "cluster_width", ev.cluster_width, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "cluster_nhits", ev.cluster_nhits, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "cluster_start_wire", ev.cluster_start_wire, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "cluster_start_tick", ev.cluster_start_tick, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "cluster_end_wire", ev.cluster_end_wire, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "cluster_end_tick", ev.cluster_end_tick, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "cluster_sps_x", ev.cluster_sps_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "cluster_sps_y", ev.cluster_sps_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "cluster_sps_z", ev.cluster_sps_z, create);
  set_output_branch_address(out_tree, "nblips", &ev.nblips, create, "nblips/I");
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_x", ev.blip_x, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_y", ev.blip_y, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_z", ev.blip_z, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "blip_plane_0", ev.blip_plane_0, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "blip_plane_1", ev.blip_plane_1, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "blip_plane_2", ev.blip_plane_2, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_charge_0", ev.blip_charge_0, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_charge_1", ev.blip_charge_1, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_charge_2", ev.blip_charge_2, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "blip_ID", ev.blip_ID, create);
  set_object_output_branch_address< std::vector<bool> >(out_tree, "blip_isValid", ev.blip_isValid, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "blip_nplanes", ev.blip_nplanes, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_maxdiff", ev.blip_maxdiff, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "blip_tpc", ev.blip_tpc, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_energy", ev.blip_energy, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_energy_estar", ev.blip_energy_estar, create);
  set_object_output_branch_address< std::vector<bool> >(out_tree, "blip_incylinder", ev.blip_incylinder, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "blip_trkid", ev.blip_trkid, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_trkdist", ev.blip_trkdist, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "blip_pdg", ev.blip_pdg, create);
  set_object_output_branch_address< std::vector<std::string> >(out_tree, "blip_process", ev.blip_process, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_vx", ev.blip_vx, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_vy", ev.blip_vy, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_vz", ev.blip_vz, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_E", ev.blip_E, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_mass", ev.blip_mass, create);
  set_object_output_branch_address< std::vector<std::string> >(out_tree, "blip_mom_process", ev.blip_mom_process, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "blip_mom_pdg", ev.blip_mom_pdg, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_mom_vx", ev.blip_mom_vx, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_mom_vy", ev.blip_mom_vy, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_mom_vz", ev.blip_mom_vz, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_mom_E", ev.blip_mom_E, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_mom_mass", ev.blip_mom_mass, create);
  set_object_output_branch_address< std::vector<std::string> >(out_tree, "blip_grandmom_process", ev.blip_grandmom_process, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "blip_grandmom_pdg", ev.blip_grandmom_pdg, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_grandmom_vx", ev.blip_grandmom_vx, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_grandmom_vy", ev.blip_grandmom_vy, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_grandmom_vz", ev.blip_grandmom_vz, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_grandmom_E", ev.blip_grandmom_E, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_grandmom_mass", ev.blip_grandmom_mass, create);
  set_object_output_branch_address< std::vector<std::string> >(out_tree, "blip_greatgrandmom_process", ev.blip_greatgrandmom_process, create);
  set_object_output_branch_address< std::vector<int> >(out_tree, "blip_greatgrandmom_pdg", ev.blip_greatgrandmom_pdg, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_greatgrandmom_vx", ev.blip_greatgrandmom_vx, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_greatgrandmom_vy", ev.blip_greatgrandmom_vy, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_greatgrandmom_vz", ev.blip_greatgrandmom_vz, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_greatgrandmom_E", ev.blip_greatgrandmom_E, create);
  set_object_output_branch_address< std::vector<float> >(out_tree, "blip_greatgrandmom_mass", ev.blip_greatgrandmom_mass, create);
}
*/
