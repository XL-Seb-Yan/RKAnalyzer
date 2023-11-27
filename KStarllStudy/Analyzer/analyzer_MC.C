#if!defined(__CINT__) || defined(__MAKECINT__)
#include <TROOT.h>                  // access to gROOT, entry point to ROOT system
#include <TSystem.h>                // interface to OS
#include <TFile.h>                  // file handle class
#include <TTree.h>                  // class to access ntuples
#include <TClonesArray.h>           // ROOT array class
#include <TBenchmark.h>             // class to track macro running statistics
#include <TVector2.h>               // 2D vector class
#include <TVector3.h>               // 2D vector class
#include <Math/Vector3D.h>
#include <TMath.h>                  // ROOT math library
#include <vector>                   // STL vector class
#include <utility>
#include <iostream>                 // standard I/O
#include <iomanip>                  // functions to format standard I/O
#include <fstream>                  // functions forfile I/O
#include <bitset>
#include "TLorentzVector.h"         // 4-vector class
#include <THStack.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TLegend.h>
#include <TF1.h>
#include <TStopwatch.h>
#include <TMatrixD.h>
#include <TArrayD.h>
#include <TMatrixDEigen.h>
#include <TVectorD.h>
#include "TH1D.h"
#include "TRandom3.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "TTreeReaderArray.h"
#include "TMath.h"
// C++ tool
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#endif

void FillHistogram(TH1F* hist1_1, TH1F* hist1_2, TH1F* hist1_3, TH1F* hist1_4, TH1F* hist1_5, TH1F* hist1_6, TH1F* hist1_7, TH1F* hist1_8, TH1F* hist1_9, TH1F* hist1_10,
										TH1F* hist1_11, TH1F* hist1_12, TH1F* hist1_13, TH1F* hist1_14, TH1F* hist1_15, TH1F* hist1_16, TH1F* hist1_17, TH1F* hist1_18, TH1F* hist1_19, TH1F* hist1_20,
										TH1F* hist1_21, TH1F* hist1_22, TH1F* hist1_23, TH1F* hist1_24, TH1F* hist1_25,
										TH1F* hist2_1, TH1F* hist2_2, TH1F* hist2_3, TH1F* hist2_4, 
										TH2F* hist2d_1_1, TH2F* hist2d_1_2,
										TString filename,
										int mode) {
    // Open the ROOT file
    TFile* file = TFile::Open(filename);
    if(!file || file->IsZombie()) {
        // Handle file open error
        return;
    }

    // Get the TTree containing the data (replace "Events" with your tree name)
    TTree* tree = dynamic_cast<TTree*>(file->Get("Events"));
    if(!tree) {
        // Handle tree retrieval error
        file->Close();
        return;
    }

		TTreeReader reader(tree);

		TTreeReaderArray<Float_t> BToKEE_mass(reader, "BToKEE_mass");
		TTreeReaderArray<Float_t> BToKEE_fit_mass(reader, "BToKEE_fit_mass");
		TTreeReaderArray<Float_t> BToKEE_fit_pt(reader, "BToKEE_fit_pt");
		TTreeReaderArray<Float_t> BToKEE_fit_eta(reader, "BToKEE_fit_eta");
		TTreeReaderArray<Float_t> BToKEE_fit_phi(reader, "BToKEE_fit_phi");
		TTreeReaderArray<Float_t> BToKEE_fit_k_pt(reader, "BToKEE_fit_k_pt");
		TTreeReaderArray<Float_t> BToKEE_fit_k_eta(reader, "BToKEE_fit_k_eta");
		TTreeReaderArray<Float_t> BToKEE_fit_k_phi(reader, "BToKEE_fit_k_phi");
		TTreeReaderArray<Float_t> BToKEE_svprob(reader, "BToKEE_svprob");
		TTreeReaderArray<Float_t> BToKEE_vtx_x(reader, "BToKEE_vtx_x");
		TTreeReaderArray<Float_t> BToKEE_vtx_y(reader, "BToKEE_vtx_y");
		TTreeReaderArray<Float_t> BToKEE_vtx_z(reader, "BToKEE_vtx_z");
		TTreeReaderArray<Float_t> BToKEE_l_xy(reader, "BToKEE_l_xy");
		TTreeReaderArray<Float_t> BToKEE_l_xy_unc(reader, "BToKEE_l_xy_unc");
    TTreeReaderArray<Float_t> BToKEE_mll_raw(reader, "BToKEE_mll_raw");
		TTreeReaderArray<Float_t> BToKEE_mll_charge(reader, "BToKEE_mll_charge");
		TTreeReaderArray<Float_t> BToKEE_mll_fullfit(reader, "BToKEE_mll_fullfit");
		TTreeReaderArray<Float_t> BToKEE_fit_l1_pt(reader, "BToKEE_fit_l1_pt");
		TTreeReaderArray<Float_t> BToKEE_fit_l1_eta(reader, "BToKEE_fit_l1_eta");
		TTreeReaderArray<Float_t> BToKEE_fit_l1_phi(reader, "BToKEE_fit_l1_phi");
		TTreeReaderArray<Float_t> BToKEE_fit_l2_pt(reader, "BToKEE_fit_l2_pt");
		TTreeReaderArray<Float_t> BToKEE_fit_l2_eta(reader, "BToKEE_fit_l2_eta");
		TTreeReaderArray<Float_t> BToKEE_fit_l2_phi(reader, "BToKEE_fit_l2_phi");
    TTreeReaderArray<Int_t>   BToKEE_l1Idx(reader, "BToKEE_l1Idx");
    TTreeReaderArray<Int_t>   BToKEE_l2Idx(reader, "BToKEE_l2Idx");
		TTreeReaderArray<Int_t>   BToKEE_kIdx(reader, "BToKEE_kIdx");
		TTreeReaderArray<Float_t> BToKEE_k_svip3d(reader, "BToKEE_k_svip3d");
		TTreeReaderArray<Float_t> BToKEE_k_svip3d_err(reader, "BToKEE_k_svip3d_err");
		TTreeReaderArray<Float_t> BToKEE_k_iso04_dca(reader, "BToKEE_k_iso04_dca");
		TTreeReaderArray<Float_t> BToKEE_l1_iso04_dca(reader, "BToKEE_l1_iso04_dca");
		TTreeReaderArray<Float_t> BToKEE_l2_iso04_dca(reader, "BToKEE_l2_iso04_dca");
		
		TTreeReaderArray<Float_t> BToKsEE_mass(reader, "BToKsEE_mass");
		TTreeReaderArray<Float_t> BToKsEE_fit_mass(reader, "BToKsEE_fit_mass");
    TTreeReaderArray<Float_t> BToKsEE_mll_raw(reader, "BToKsEE_mll_raw");
		TTreeReaderArray<Float_t> BToKsEE_mll_fullfit(reader, "BToKsEE_mll_fullfit");
		TTreeReaderArray<Float_t> BToKsEE_mll_charge(reader, "BToKsEE_mll_charge");
    TTreeReaderArray<Int_t>   BToKsEE_l1_idx(reader, "BToKsEE_l1_idx");
    TTreeReaderArray<Int_t>   BToKsEE_l2_idx(reader, "BToKsEE_l2_idx");
		TTreeReaderArray<Int_t>   BToKsEE_trk1_idx(reader, "BToKsEE_trk1_idx");
    TTreeReaderArray<Int_t>   BToKsEE_trk2_idx(reader, "BToKsEE_trk2_idx");
		TTreeReaderArray<Float_t> BToKsEE_fit_kstar_mass(reader, "BToKsEE_fit_kstar_mass");
		TTreeReaderArray<Float_t> Kstar_mass(reader, "Kstar_mass");
		
		TTreeReaderArray<Float_t> Electron_pt(reader, "Electron_pt");
		TTreeReaderArray<Float_t> Electron_eta(reader, "Electron_eta");
		TTreeReaderArray<Float_t> Electron_phi(reader, "Electron_phi");
    TTreeReaderArray<Bool_t>  Electron_isPF(reader, "Electron_isPF");
    TTreeReaderArray<Bool_t>  Electron_PFEleMvaID_Fall17NoIsoV2wp90(reader, "Electron_PFEleMvaID_Fall17NoIsoV2wp90");
		TTreeReaderArray<Float_t> Electron_PFEleMvaID_RetrainedRawValue(reader, "Electron_PFEleMvaID_RetrainedRawValue");
		TTreeReaderArray<Float_t> Electron_vz(reader, "Electron_vz");
		
		TTreeReaderArray<Float_t> ProbeTracks_pt(reader, "ProbeTracks_pt");
		TTreeReaderArray<Float_t> ProbeTracks_eta(reader, "ProbeTracks_eta");
		TTreeReaderArray<Float_t> ProbeTracks_phi(reader, "ProbeTracks_phi");
		TTreeReaderArray<Float_t> ProbeTracks_vz(reader, "ProbeTracks_vz");
		
		TTreeReaderArray<Float_t> PV_x(reader, "PV_x");
		TTreeReaderArray<Float_t> PV_y(reader, "PV_y");
		TTreeReaderArray<Float_t> PV_z(reader, "PV_z");
		
		TTreeReaderValue<UInt_t> nGenPart(reader, "nGenPart");
		TTreeReaderArray<Float_t> GenPart_pt(reader, "GenPart_pt");
		TTreeReaderArray<Float_t> GenPart_eta(reader, "GenPart_eta");
		TTreeReaderArray<Float_t> GenPart_phi(reader, "GenPart_phi");
		TTreeReaderArray<Float_t> GenPart_mass(reader, "GenPart_mass");
		TTreeReaderArray<Int_t> GenPart_genPartIdxMother(reader, "GenPart_genPartIdxMother");
		TTreeReaderArray<Int_t> GenPart_pdgId(reader, "GenPart_pdgId");
		TTreeReaderArray<Int_t> GenPart_status(reader, "GenPart_status");
		
		
		TTreeReaderValue<UChar_t> L1_DoubleEG11_er1p2_dR_Max0p6(reader, "L1_DoubleEG11_er1p2_dR_Max0p6");
		TTreeReaderValue<UChar_t> L1_DoubleEG10p5_er1p2_dR_Max0p6(reader, "L1_DoubleEG10p5_er1p2_dR_Max0p6");
		TTreeReaderValue<UChar_t> L1_DoubleEG10_er1p2_dR_Max0p6(reader, "L1_DoubleEG10_er1p2_dR_Max0p6");
		TTreeReaderValue<UChar_t> L1_DoubleEG9p5_er1p2_dR_Max0p6(reader, "L1_DoubleEG9p5_er1p2_dR_Max0p6");
		TTreeReaderValue<UChar_t> L1_DoubleEG9_er1p2_dR_Max0p7(reader, "L1_DoubleEG9_er1p2_dR_Max0p7");
		TTreeReaderValue<UChar_t> L1_DoubleEG8p5_er1p2_dR_Max0p7(reader, "L1_DoubleEG8p5_er1p2_dR_Max0p7");
		TTreeReaderValue<UChar_t> L1_DoubleEG8_er1p2_dR_Max0p7(reader, "L1_DoubleEG8_er1p2_dR_Max0p7");
		TTreeReaderValue<UChar_t> L1_DoubleEG7p5_er1p2_dR_Max0p7(reader, "L1_DoubleEG7p5_er1p2_dR_Max0p7");
		TTreeReaderValue<UChar_t> L1_DoubleEG7_er1p2_dR_Max0p8(reader, "L1_DoubleEG7_er1p2_dR_Max0p8");
		TTreeReaderValue<UChar_t> L1_DoubleEG6p5_er1p2_dR_Max0p8(reader, "L1_DoubleEG6p5_er1p2_dR_Max0p8");
		TTreeReaderValue<UChar_t> L1_DoubleEG6_er1p2_dR_Max0p8(reader, "L1_DoubleEG6_er1p2_dR_Max0p8");
		TTreeReaderValue<UChar_t> L1_DoubleEG5p5_er1p2_dR_Max0p8(reader, "L1_DoubleEG5p5_er1p2_dR_Max0p8");
		TTreeReaderValue<UChar_t> L1_DoubleEG5_er1p2_dR_Max0p9(reader, "L1_DoubleEG5_er1p2_dR_Max0p9");
		TTreeReaderValue<UChar_t> L1_DoubleEG4p5_er1p2_dR_Max0p9(reader, "L1_DoubleEG4p5_er1p2_dR_Max0p9");
		TTreeReaderValue<UChar_t> L1_DoubleEG4_er1p2_dR_Max0p9(reader, "L1_DoubleEG4_er1p2_dR_Max0p9");
		
		TTreeReaderValue<UChar_t> HLT_DoubleEle10_eta1p22_mMax6(reader, "HLT_DoubleEle10_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle9p5_eta1p22_mMax6(reader, "HLT_DoubleEle9p5_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle9_eta1p22_mMax6(reader, "HLT_DoubleEle9_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle8p5_eta1p22_mMax6(reader, "HLT_DoubleEle8p5_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle8_eta1p22_mMax6(reader, "HLT_DoubleEle8_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle7p5_eta1p22_mMax6(reader, "HLT_DoubleEle7p5_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle7_eta1p22_mMax6(reader, "HLT_DoubleEle7_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle6p5_eta1p22_mMax6(reader, "HLT_DoubleEle6p5_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle6_eta1p22_mMax6(reader, "HLT_DoubleEle6_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle5p5_eta1p22_mMax6(reader, "HLT_DoubleEle5p5_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle5_eta1p22_mMax6(reader, "HLT_DoubleEle5_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle4p5_eta1p22_mMax6(reader, "HLT_DoubleEle4p5_eta1p22_mMax6");
		TTreeReaderValue<UChar_t> HLT_DoubleEle4_eta1p22_mMax6(reader, "HLT_DoubleEle4_eta1p22_mMax6");

		TH1F* dR_l = new TH1F("dR_l", "dR_l", 500, 0, 0.5);
		TH1F* dR_K = new TH1F("dR_K", "dR_K", 500, 0, 0.5);
    // Loop through the entries
    Long64_t numEntries = tree->GetEntries();
    for(Long64_t ievt = 0; ievt < numEntries; ++ievt) {
		// for(Long64_t ievt = 0; ievt < 100; ++ievt) {
				reader.SetLocalEntry(ievt);
        if(ievt % 1000 == 0) {
            std::cout << "Processing " << static_cast<double>(ievt) / numEntries << std::endl;
        }

        tree->GetEntry(ievt);
				
				int nTriplets = 0, nQuadruplets = 0;
				
				std::vector<int> HLT_values;
				std::vector<int> L1_values;
				
				HLT_values.push_back(int(*HLT_DoubleEle4_eta1p22_mMax6));
				HLT_values.push_back(int(*HLT_DoubleEle4p5_eta1p22_mMax6));
				HLT_values.push_back(int(*HLT_DoubleEle5_eta1p22_mMax6));
				HLT_values.push_back(int(*HLT_DoubleEle5p5_eta1p22_mMax6));
				HLT_values.push_back(int(*HLT_DoubleEle6_eta1p22_mMax6));
				HLT_values.push_back(int(*HLT_DoubleEle6p5_eta1p22_mMax6));
				HLT_values.push_back(int(*HLT_DoubleEle7_eta1p22_mMax6));
				HLT_values.push_back(int(*HLT_DoubleEle7p5_eta1p22_mMax6));
				HLT_values.push_back(int(*HLT_DoubleEle8_eta1p22_mMax6));
				HLT_values.push_back(int(*HLT_DoubleEle8p5_eta1p22_mMax6));
				HLT_values.push_back(int(*HLT_DoubleEle9_eta1p22_mMax6));
				HLT_values.push_back(int(*HLT_DoubleEle9p5_eta1p22_mMax6));
				HLT_values.push_back(int(*HLT_DoubleEle10_eta1p22_mMax6));
						
				
				L1_values.push_back(int(*L1_DoubleEG4_er1p2_dR_Max0p9));
				L1_values.push_back(int(*L1_DoubleEG4p5_er1p2_dR_Max0p9));
				L1_values.push_back(int(*L1_DoubleEG5_er1p2_dR_Max0p9));
				L1_values.push_back(int(*L1_DoubleEG5p5_er1p2_dR_Max0p8));
				L1_values.push_back(int(*L1_DoubleEG6_er1p2_dR_Max0p8));
				L1_values.push_back(int(*L1_DoubleEG6p5_er1p2_dR_Max0p8));
				L1_values.push_back(int(*L1_DoubleEG7_er1p2_dR_Max0p8));
				L1_values.push_back(int(*L1_DoubleEG7p5_er1p2_dR_Max0p7));
				L1_values.push_back(int(*L1_DoubleEG8_er1p2_dR_Max0p7));
				L1_values.push_back(int(*L1_DoubleEG8p5_er1p2_dR_Max0p7));
				L1_values.push_back(int(*L1_DoubleEG9_er1p2_dR_Max0p7));
				L1_values.push_back(int(*L1_DoubleEG9p5_er1p2_dR_Max0p6));
				L1_values.push_back(int(*L1_DoubleEG10_er1p2_dR_Max0p6));
				L1_values.push_back(int(*L1_DoubleEG10p5_er1p2_dR_Max0p6));
				L1_values.push_back(int(*L1_DoubleEG11_er1p2_dR_Max0p6));
				
				int index_HLT_highest = -99;
				for(size_t i = 0; i < HLT_values.size(); ++i) {
					if(HLT_values[HLT_values.size()-1-i] == 1){
						index_HLT_highest = HLT_values.size()-1-i;
						break;
					}
				}
				
				int index_L1_highest = -99;
				for(size_t i = 0; i < L1_values.size(); ++i) {
					if(L1_values[L1_values.size()-1-i] == 1){
						index_L1_highest = L1_values.size()-1-i;
						break;
					}
				}
				
				
				hist2d_1_1->Fill((index_L1_highest+8)*0.5,(index_HLT_highest+8)*0.5,1);
				
				// for(size_t i = 0; i < L1_values.size(); ++i) {
						// for(size_t j = 0; j < HLT_values.size(); ++j) {
								// if(L1_values[i] && HLT_values[j]) {
										// hist2d_1_1->Fill((i+8)*0.5,(j+8)*0.5,1);
								// }
						// }
				// }
				
				// Locate desired electron and Kaon
				std::vector<TLorentzVector> genEle_p4s;
				std::vector<TLorentzVector> genHad_p4s;
				for(int igen = 0; igen < *nGenPart; igen++){
						// cout<<GenPart_pdgId[igen]<<" "<<GenPart_status[igen]<<" "<<GenPart_genPartIdxMother[igen]<<" "<<GenPart_pdgId[GenPart_genPartIdxMother[igen]]<<endl;
						if(GenPart_status[igen] != 1) continue;
						if(abs(GenPart_pdgId[igen]) != 11 && abs(GenPart_pdgId[igen]) != 321 && abs(GenPart_pdgId[igen]) != 211) continue;
						if(abs(GenPart_pdgId[GenPart_genPartIdxMother[igen]]) != 521 - mode && abs(GenPart_pdgId[GenPart_genPartIdxMother[igen]]) != 313) continue;
						TLorentzVector genp4;
						if(abs(GenPart_pdgId[igen]) == 11){
								genp4.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.000511);
								genEle_p4s.push_back(genp4);
						}
						if(abs(GenPart_pdgId[igen]) == 321 && mode == 0 && abs(GenPart_pdgId[GenPart_genPartIdxMother[igen]]) == 521){
								genp4.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.493677);
								genHad_p4s.push_back(genp4);
						}
						if(abs(GenPart_pdgId[igen]) == 321 && mode == 10 && abs(GenPart_pdgId[GenPart_genPartIdxMother[igen]]) == 313 && abs(GenPart_pdgId[GenPart_genPartIdxMother[GenPart_genPartIdxMother[igen]]]) == 511){
								genp4.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.493677);
								genHad_p4s.push_back(genp4);
						}
						if(abs(GenPart_pdgId[igen]) == 211 && mode == 10 && abs(GenPart_pdgId[GenPart_genPartIdxMother[igen]]) == 313 && abs(GenPart_pdgId[GenPart_genPartIdxMother[GenPart_genPartIdxMother[igen]]]) == 511){
								genp4.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.13957);
								genHad_p4s.push_back(genp4);
						}
				}
				if(mode == 10 && (genEle_p4s.size() < 2 || genHad_p4s.size() < 2)) {
					cout<<genEle_p4s.size()<<" "<<genHad_p4s.size()<<endl; 
					// for(int igen = 0; igen < *nGenPart; igen++){
						// cout<<GenPart_pdgId[igen]<<" "<<GenPart_status[igen]<<" "<<GenPart_pt[igen]<<" "<<GenPart_eta[igen]<<" "<<GenPart_phi[igen]<<" "<<GenPart_genPartIdxMother[igen]<<" "<<GenPart_pdgId[GenPart_genPartIdxMother[igen]]<<endl;
					// }
					continue;
				}
				if(mode == 0 && (genEle_p4s.size() < 2 || genHad_p4s.size() < 1)) {
					cout<<genEle_p4s.size()<<" "<<genHad_p4s.size()<<endl; 
					// for(int igen = 0; igen < *nGenPart; igen++){
						// cout<<GenPart_pdgId[igen]<<" "<<GenPart_status[igen]<<" "<<GenPart_pt[igen]<<" "<<GenPart_eta[igen]<<" "<<GenPart_phi[igen]<<" "<<GenPart_genPartIdxMother[igen]<<" "<<GenPart_pdgId[GenPart_genPartIdxMother[igen]]<<endl;
					// }
					continue;
				}
				
				std::set<float> unique_BToKEE_m;
				std::set<float> unique_BToKEE_mll;
				std::set<float> unique_BToKEE_noKstar_m;
				std::set<float> unique_BToKEE_noKstar_mll;
				
				for(size_t iBKee = 0; iBKee < BToKEE_mass.GetSize(); ++iBKee) {
						int l1_index = BToKEE_l1Idx[iBKee];
						int l2_index = BToKEE_l2Idx[iBKee];
						int k_index = BToKEE_kIdx[iBKee];
						
						if(BToKEE_fit_mass[iBKee] < 4.7 || BToKEE_fit_mass[iBKee] > 5.7) continue;
						if(BToKEE_mll_fullfit[iBKee]*BToKEE_mll_fullfit[iBKee] < 1.1 || BToKEE_mll_fullfit[iBKee]*BToKEE_mll_fullfit[iBKee] > 6.0) continue;
						
						if(Electron_pt[l1_index] < 5 || Electron_pt[l2_index] < 5) {continue;}
						if(abs(Electron_eta[l1_index]) > 1.22 || abs(Electron_eta[l2_index]) > 1.22) {continue;}
						if(ProbeTracks_pt[k_index] < 0.5) {continue;}
						if(abs(ProbeTracks_eta[k_index]) > 1.22) {continue;}
						if(!Electron_isPF[l1_index] || !Electron_isPF[l2_index] || Electron_PFEleMvaID_RetrainedRawValue[l1_index] < 0 || Electron_PFEleMvaID_RetrainedRawValue[l2_index] < 0 || BToKEE_mll_charge[iBKee] != 0) {continue;}
						
						nTriplets++;
						
						// GEN matching
						TLorentzVector l1p4, l2p4, Kp4;
						l1p4.SetPtEtaPhiM(Electron_pt[l1_index],Electron_eta[l1_index],Electron_phi[l1_index],0.000511);
						l2p4.SetPtEtaPhiM(Electron_pt[l2_index],Electron_eta[l2_index],Electron_phi[l2_index],0.000511);
						Kp4.SetPtEtaPhiM(ProbeTracks_pt[k_index],ProbeTracks_eta[k_index],ProbeTracks_phi[k_index],0.493677);
						bool isMatched_ele = false;
						bool isMatched_K = false;
						std::vector<bool> matchingbit; 
						dR_l->Fill(l1p4.DeltaR(genEle_p4s[0]));
						dR_l->Fill(l1p4.DeltaR(genEle_p4s[1]));
						dR_l->Fill(l2p4.DeltaR(genEle_p4s[0]));
						dR_l->Fill(l2p4.DeltaR(genEle_p4s[1]));
						dR_K->Fill(Kp4.DeltaR(genHad_p4s[0]));
						for(int i=0; i<genEle_p4s.size();i++){
							if(l1p4.DeltaR(genEle_p4s[i]) < 0.03) {
								matchingbit.push_back(1);
							}
							else{
								matchingbit.push_back(0);
							}
						}
						for(int i=0; i<genEle_p4s.size();i++){
							if(l2p4.DeltaR(genEle_p4s[i]) < 0.03) {
								matchingbit.push_back(1);
							}
							else{
								matchingbit.push_back(0);
							}
						}
						if((matchingbit[0] && matchingbit[3]) || (matchingbit[1] && matchingbit[2])) isMatched_ele = true;
						// if((matchingbit[0] + matchingbit[3]) + (matchingbit[1] + matchingbit[2]) > 1) isMatched_ele = true;
						for(int i=0; i<genHad_p4s.size();i++){
							if(Kp4.DeltaR(genHad_p4s[0]) < 0.03) isMatched_K = true;
						}
						if(!isMatched_ele || !isMatched_K) continue;
						
						bool isPartOfBKStar = false;
						for(size_t iBKStaree = 0; iBKStaree < BToKsEE_mass.GetSize(); ++iBKStaree) {
								if((BToKsEE_l1_idx[iBKStaree] == l1_index && 
									 BToKsEE_l2_idx[iBKStaree] == l2_index &&
									 BToKsEE_trk1_idx[iBKStaree] == k_index) ||
									(BToKsEE_l1_idx[iBKStaree] == l1_index && 
									 BToKsEE_l2_idx[iBKStaree] == l2_index &&
									 BToKsEE_trk2_idx[iBKStaree] == k_index) ||
									(BToKsEE_l1_idx[iBKStaree] == l2_index && 
									 BToKsEE_l2_idx[iBKStaree] == l1_index &&
									 BToKsEE_trk1_idx[iBKStaree] == k_index) ||
									(BToKsEE_l1_idx[iBKStaree] == l2_index && 
									 BToKsEE_l2_idx[iBKStaree] == l1_index &&
									 BToKsEE_trk2_idx[iBKStaree] == k_index)) {
										 isPartOfBKStar = true;
										 break;
									 }
						}
						 
						int isize = -99;
						
						isize = unique_BToKEE_m.size();
						unique_BToKEE_m.insert(BToKEE_fit_mass[iBKee]);
						if(unique_BToKEE_m.size() > isize){
							hist1_1->Fill(BToKEE_fit_mass[iBKee]);
							hist1_3->Fill(Electron_pt[l1_index]);
							hist1_4->Fill(Electron_pt[l2_index]);
							hist1_5->Fill(Electron_pt[l1_index] / BToKEE_fit_mass[iBKee]);
							hist1_6->Fill(Electron_pt[l2_index] / BToKEE_fit_mass[iBKee]);
							hist1_7->Fill(ProbeTracks_pt[k_index]);
							hist1_8->Fill(ProbeTracks_pt[k_index] / BToKEE_fit_mass[iBKee]);
							hist1_9->Fill(BToKEE_fit_pt[iBKee]);
							hist1_10->Fill(BToKEE_fit_pt[iBKee] / BToKEE_fit_mass[iBKee]);
							ROOT::Math::XYZVector BVtxVector(BToKEE_vtx_x[iBKee] - PV_x[0], BToKEE_vtx_y[iBKee] - PV_y[0], BToKEE_vtx_z[iBKee] - PV_z[0]);
							TLorentzVector Bp4;
							Bp4.SetPtEtaPhiM(BToKEE_fit_pt[iBKee],BToKEE_fit_eta[iBKee],BToKEE_fit_phi[iBKee],BToKEE_fit_mass[iBKee]);
							ROOT::Math::XYZVector Bp3Vector(Bp4.Px(), Bp4.Py(), Bp4.Pz());
							hist1_11->Fill(BVtxVector.Dot(Bp3Vector) / (BVtxVector.R() * Bp3Vector.R()));
							int overflow = hist1_12->GetBinContent(1001);
							hist1_12->Fill(BToKEE_svprob[iBKee]);
							if(hist1_12->GetBinContent(1001) > overflow)
								cout<<BToKEE_svprob[iBKee]<<endl;
							hist1_13->Fill(BToKEE_l_xy[iBKee] / BToKEE_l_xy_unc[iBKee]);
							hist1_14->Fill(Electron_vz[l1_index] - ProbeTracks_vz[k_index]);
							hist1_15->Fill(Electron_vz[l2_index] - ProbeTracks_vz[k_index]);
							hist1_16->Fill(BToKEE_k_svip3d[iBKee] / BToKEE_k_svip3d_err[iBKee]);
							TLorentzVector l1p4, l2p4, Kp4;
							l1p4.SetPtEtaPhiM(BToKEE_fit_l1_pt[iBKee], BToKEE_fit_l1_eta[iBKee], BToKEE_fit_l1_phi[iBKee], 0.000511);
							l2p4.SetPtEtaPhiM(BToKEE_fit_l2_pt[iBKee], BToKEE_fit_l2_eta[iBKee], BToKEE_fit_l2_phi[iBKee], 0.000511);
							Kp4.SetPtEtaPhiM(BToKEE_fit_k_pt[iBKee], BToKEE_fit_k_eta[iBKee], BToKEE_fit_k_phi[iBKee], 0.493677);
							hist1_17->Fill(l1p4.DeltaR(l2p4));
							hist1_18->Fill(l1p4.DeltaR(Kp4));
							hist1_19->Fill(l2p4.DeltaR(Kp4));
							TLorentzVector llp4;
							llp4 = l1p4 + l2p4;
							ROOT::Math::XYZVector llp3Vector(llp4.Px(),llp4.Py(),llp4.Pz());
							ROOT::Math::XYZVector Kp3Vector(Kp4.Px(),Kp4.Py(),Kp4.Pz());
							ROOT::Math::XYZVector unitBVtxVector = BVtxVector / BVtxVector.R();
							hist1_20->Fill(((llp3Vector.Cross(unitBVtxVector)).R() - (Kp3Vector.Cross(unitBVtxVector)).R()) / ((llp3Vector.Cross(unitBVtxVector)).R() + (Kp3Vector.Cross(unitBVtxVector)).R()));
							hist1_21->Fill(Electron_PFEleMvaID_RetrainedRawValue[l1_index]);
							hist1_22->Fill(Electron_PFEleMvaID_RetrainedRawValue[l2_index]);
							hist1_23->Fill(BToKEE_l1_iso04_dca[iBKee]);
							hist1_24->Fill(BToKEE_l2_iso04_dca[iBKee]);
							hist1_25->Fill(BToKEE_k_iso04_dca[iBKee]);
							
							if(BToKEE_svprob[iBKee] > 1) cout<<ievt<<" "<<iBKee<<" SVProb: "<<BToKEE_svprob[iBKee]<<endl;
							if(BToKEE_l1_iso04_dca[iBKee] > 50) cout<<ievt<<" "<<iBKee<<" Iso: "<<BToKEE_l1_iso04_dca[iBKee]<<endl;
						}
						
						isize = unique_BToKEE_mll.size();
						unique_BToKEE_mll.insert(BToKEE_mll_fullfit[iBKee]);
						if(unique_BToKEE_mll.size() > isize){
							hist1_2->Fill(BToKEE_mll_fullfit[iBKee]);
						}
						
						// if(!isPartOfBKStar){
			
							// int isize = unique_BToKEE_noKstar_m.size();
							// unique_BToKEE_noKstar_m.insert(BToKEE_fit_mass[iBKee]);
							// if(unique_BToKEE_noKstar_m.size() > isize){
								// hist1_3->Fill(BToKEE_fit_mass[iBKee]);
							// }
							
							// isize = unique_BToKEE_noKstar_mll.size();
							// unique_BToKEE_noKstar_mll.insert(BToKEE_mll_fullfit[iBKee]);
							// if(unique_BToKEE_noKstar_mll.size() > isize){
								// hist1_4->Fill(BToKEE_mll_fullfit[iBKee]);
							// }
						// }
				}
				
				
				std::set<float> unique_BToKsEE_m;
				std::set<float> unique_Ks_m;
				
				for(size_t iBKStaree = 0; iBKStaree < BToKsEE_mass.GetSize(); ++iBKStaree) {
					
					int l1_index = BToKsEE_l1_idx[iBKStaree];
					int l2_index = BToKsEE_l2_idx[iBKStaree];
					int trk1_index = BToKsEE_trk1_idx[iBKStaree];
					int trk2_index = BToKsEE_trk2_idx[iBKStaree];
					
					if(BToKsEE_fit_mass[iBKStaree] < 4.7 || BToKsEE_fit_mass[iBKStaree] > 5.7) continue;
					if(BToKsEE_mll_fullfit[iBKStaree]*BToKsEE_mll_fullfit[iBKStaree] < 1.1 || BToKsEE_mll_fullfit[iBKStaree]*BToKsEE_mll_fullfit[iBKStaree] > 6.0) continue;
					if(BToKsEE_fit_kstar_mass[iBKStaree] < 0.792 || BToKsEE_fit_kstar_mass[iBKStaree] > 0.992) continue;
					
					if(Electron_pt[l1_index] < 5 || Electron_pt[l2_index] < 5) {continue;}
					if(abs(Electron_eta[l1_index]) > 1.22 || abs(Electron_eta[l2_index]) > 1.22) {continue;}
					if(ProbeTracks_pt[trk1_index] < 0.5 || ProbeTracks_pt[trk2_index] < 0.5 ) {continue;}
					if(abs(ProbeTracks_eta[trk1_index]) > 1.22 || abs(ProbeTracks_eta[trk2_index]) > 1.22) {continue;}
					if(!Electron_isPF[l1_index] || !Electron_isPF[l2_index] || Electron_PFEleMvaID_RetrainedRawValue[l1_index] < 0 || Electron_PFEleMvaID_RetrainedRawValue[l2_index] < 0) {continue;}
					
					// GEN matching
					TLorentzVector l1p4, l2p4, trk1p4, trk2p4;
					l1p4.SetPtEtaPhiM(Electron_pt[l1_index],Electron_eta[l1_index],Electron_phi[l1_index],0.000511);
					l2p4.SetPtEtaPhiM(Electron_pt[l2_index],Electron_eta[l2_index],Electron_phi[l2_index],0.000511);
					trk1p4.SetPtEtaPhiM(ProbeTracks_pt[trk1_index],ProbeTracks_eta[trk1_index],ProbeTracks_phi[trk1_index],0.493677);
					trk2p4.SetPtEtaPhiM(ProbeTracks_pt[trk2_index],ProbeTracks_eta[trk2_index],ProbeTracks_phi[trk2_index],0.493677);
					bool isMatched_ele = false;
					bool isMatched_trk = false;
					std::vector<int> matchingbit_ele; 
					std::vector<int> matchingbit_trk1; 
					std::vector<int> matchingbit_trk2; 
					for(int i=0; i<genEle_p4s.size();i++){
						if(l1p4.DeltaR(genEle_p4s[i]) < 0.03) {
							matchingbit_ele.push_back(1);
						}
						else{
							matchingbit_ele.push_back(0);
						}
					}
					for(int i=0; i<genEle_p4s.size();i++){
						if(l2p4.DeltaR(genEle_p4s[i]) < 0.03) {
							matchingbit_ele.push_back(1);
						}
						else{
							matchingbit_ele.push_back(0);
						}
					}
					if((matchingbit_ele[0] && matchingbit_ele[3]) || (matchingbit_ele[1] && matchingbit_ele[2])) isMatched_ele = true;
					
					for(int i=0; i<genHad_p4s.size();i++){
						if(trk1p4.DeltaR(genHad_p4s[i]) < 0.03) {
							matchingbit_trk1.push_back(1);
						}
						else{
							matchingbit_trk1.push_back(0);
						}
					}
					for(int i=0; i<genHad_p4s.size();i++){
						if(trk2p4.DeltaR(genHad_p4s[i]) < 0.03) {
							matchingbit_trk2.push_back(1);
						}
						else{
							matchingbit_trk2.push_back(0);
						}
					}
					int sumtrk1 = 0;
					int sumtrk2 = 0;
					for(int i=0; i<matchingbit_trk1.size();i++){
						sumtrk1+=matchingbit_trk1[i];
					}
					for(int i=0; i<matchingbit_trk2.size();i++){
						sumtrk2+=matchingbit_trk2[i];
					}
					if(sumtrk1 > 0 && sumtrk2 > 0) isMatched_trk = true;
					
					if(!isMatched_ele || !isMatched_trk) continue;
					
					nQuadruplets++;
					
					int isize_BToKsEE = unique_BToKsEE_m.size();
					unique_BToKsEE_m.insert(BToKsEE_mass[iBKStaree]);
					if(unique_BToKsEE_m.size() > isize_BToKsEE){
						hist2_1->Fill(BToKsEE_fit_mass[iBKStaree]);
					}
					int isize_Kstar = unique_Ks_m.size();
					unique_Ks_m.insert(BToKsEE_fit_kstar_mass[iBKStaree]);
					if(unique_Ks_m.size() > isize_Kstar){
						hist2_2->Fill(BToKsEE_fit_kstar_mass[iBKStaree]);
						hist2_3->Fill(ProbeTracks_pt[trk1_index]);
						hist2_4->Fill(ProbeTracks_pt[trk2_index]);
					}
				}
				hist2d_1_2->Fill(nTriplets, nQuadruplets, 1);
		}
    // Close the file
		// Create a canvas
		TCanvas* canvas = new TCanvas("canvas", "Title", 2400, 1800);

		dR_l->Draw();
		dR_K->SetLineColor(2);
		dR_K->Draw("SAME");
	
		canvas->SetLogy();
		canvas->Print("test.png");
    file->Close();
		
}

void analyzer_MC(TString filename, int ifile, int mode) {
    // Create histograms to store muon pt values
    TH1F* hist1_1 = new TH1F("hist1_1", "B mass (all triplet)", 1000, 4.2, 6.2);
		TH1F* hist1_2 = new TH1F("hist1_2", "ll mass (all triplet)", 1200, 0, 6);
		TH1F* hist1_3 = new TH1F("hist1_3", "l1 p_{T} (all triplet)", 1000, 0,100);
		TH1F* hist1_4 = new TH1F("hist1_4", "l2 p_{T} (all triplet)", 1000, 0,100);
		TH1F* hist1_5 = new TH1F("hist1_5", "l1 p_{T} normalized (all triplet)", 1500, 0,15);
		TH1F* hist1_6 = new TH1F("hist1_6", "l2 p_{T} normalized (all triplet)", 1500, 0,15);
		TH1F* hist1_7 = new TH1F("hist1_7", "K p_{T} (all triplet)", 1500, 0,30);
		TH1F* hist1_8 = new TH1F("hist1_8", "K p_{T} normalized (all triplet)", 1000, 0,10);
		TH1F* hist1_9 = new TH1F("hist1_9", "B p_{T} (all triplet)", 1000, 0,100);
		TH1F* hist1_10 = new TH1F("hist1_10", "B p_{T} normalized (all triplet)", 1000, 0,20);
		TH1F* hist1_11 = new TH1F("hist1_11", "cos #alpha_{3D} (all triplet)", 1000, -1,1);
		TH1F* hist1_12 = new TH1F("hist1_12", "Prob(SV fit) (all triplet)", 1000, 0,1);
		TH1F* hist1_13 = new TH1F("hist1_13", "sig(Lxy) (all triplet)", 1000, 0,500);
		TH1F* hist1_14 = new TH1F("hist1_14", "#Delta z (l1, K) (all triplet)", 5000,-20,20);
		TH1F* hist1_15 = new TH1F("hist1_15", "#Delta z (l2, K) (all triplet)", 5000,-20,20);
		TH1F* hist1_16 = new TH1F("hist1_16", "SigImpactParam(K, ll) (all triplet)", 5000,-1000,1000);
		TH1F* hist1_17 = new TH1F("hist1_17", "#Delta R (ll) (all triplet)", 1000, 0,5);
		TH1F* hist1_18 = new TH1F("hist1_18", "#Delta R (K,l1) (all triplet)", 1000, 0,5);
		TH1F* hist1_19 = new TH1F("hist1_19", "#Delta R (K,l2) (all triplet)", 1000, 0,5);
		TH1F* hist1_20 = new TH1F("hist1_20", "Momentum asymmetry (all triplet)", 1000, -1,1);
		TH1F* hist1_21 = new TH1F("hist1_21", "ID (l1) (all triplet)", 1000, 0,10);
		TH1F* hist1_22 = new TH1F("hist1_22", "ID (l2) (all triplet)", 1000, 0,10);
		TH1F* hist1_23 = new TH1F("hist1_23", "Isolation l1_iso04_dca", 1000, 0,100);
		TH1F* hist1_24 = new TH1F("hist1_24", "Isolation l2_iso04_dca", 1000, 0,100);
		TH1F* hist1_25 = new TH1F("hist1_25", "Isolation K_iso04_dca", 1000, 0,100);
		
		// TH1F* hist1_3 = new TH1F("hist1_3", "B mass (Kstar veto)", 1000, 3, 8);
		// TH1F* hist1_4 = new TH1F("hist1_4", "ll mass (Kstar veto)", 1000, 0, 5);
		TH1F* hist2_1 = new TH1F("hist2_1", "B mass (quadruplet)", 1000, 4.2, 6.2);
		TH1F* hist2_2 = new TH1F("hist2_2", "K^{*} mass (quadruplet)", 1000, 0, 2);
		TH1F* hist2_3 = new TH1F("hist2_3", "K^{*} trk1 pt", 1000, 0, 20);
		TH1F* hist2_4 = new TH1F("hist2_4", "K^{*} trk2 pt", 1000, 0, 20);
		TH2F* hist2d_1_1  = new TH2F("hist2d_1_1","Trigger map",15,3.75,11.25,13,3.75,10.25);
		TH2F* hist2d_1_2  = new TH2F("hist2d_1_2","nQuadruplets vs nTriplet",50,0,50,20,0,20);

		FillHistogram(hist1_1, hist1_2, hist1_3, hist1_4, hist1_5, hist1_6, hist1_7, hist1_8, hist1_9, hist1_10,
									hist1_11, hist1_12, hist1_13, hist1_14, hist1_15, hist1_16, hist1_17, hist1_18, hist1_19, hist1_20,
									hist1_21, hist1_22, hist1_23, hist1_24, hist1_25,
									hist2_1, hist2_2, hist2_3, hist2_4, 
									hist2d_1_1, hist2d_1_2, 
									filename,
									mode);
		
		TString outname = "outputHits_" + std::to_string(ifile) + ".root";
		TFile* output = new TFile(outname,"RECREATE");
		output->cd();
		hist1_1->Write();
		hist1_2->Write();
		hist1_3->Write();
		hist1_4->Write();
		hist1_5->Write();
		hist1_6->Write();
		hist1_7->Write();
		hist1_8->Write();
		hist1_9->Write();
		hist1_10->Write();
		hist1_11->Write();
		hist1_12->Write();
		hist1_13->Write();
		hist1_14->Write();
		hist1_15->Write();
		hist1_16->Write();
		hist1_17->Write();
		hist1_18->Write();
		hist1_19->Write();
		hist1_20->Write();
		hist1_21->Write();
		hist1_22->Write();
		hist1_23->Write();
		hist1_24->Write();
		hist1_25->Write();
		hist2_1->Write();
		hist2_2->Write();
		hist2_3->Write();
		hist2_4->Write();
		hist2d_1_1->Write();
		hist2d_1_2->Write();
		output->Write();
		output->Close();
}