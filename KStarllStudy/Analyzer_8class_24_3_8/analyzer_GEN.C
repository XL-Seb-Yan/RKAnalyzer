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

void FillHistogram(TH1F* hist1_1, TH1F* hist1_2, TH1F* hist1_3, TH1F* hist1_4, TChain* chain) {
	
    TTreeReader reader(chain);

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

    // Loop through the entries
    Long64_t numEntries = chain->GetEntries();
    for (Long64_t ievt = 0; ievt < numEntries; ++ievt) {
				reader.SetLocalEntry(ievt);
        if(ievt % 1000 == 0) {
            std::cout << "Processing " << static_cast<double>(ievt) / numEntries << std::endl;
        }

        chain->GetEntry(ievt);
				
				int mode = 0;
				
				// Locate desired electron and Kaon
				std::vector<TLorentzVector> genEle_p4s;
				std::vector<TLorentzVector> genHad_p4s;
				for(int igen = 0; igen < *nGenPart; igen++){
						// cout<<GenPart_pdgId[igen]<<" "<<GenPart_status[igen]<<" "<<GenPart_genPartIdxMother[igen]<<" "<<GenPart_pdgId[GenPart_genPartIdxMother[igen]]<<endl;
						if(GenPart_status[igen] != 1) continue;
						if(abs(GenPart_pdgId[igen]) != 11 && abs(GenPart_pdgId[igen]) != 321 && abs(GenPart_pdgId[igen]) != 211) continue;
						TLorentzVector genp4;
						if(abs(GenPart_pdgId[igen]) == 11 && (abs(GenPart_pdgId[GenPart_genPartIdxMother[igen]]) == 443 || abs(GenPart_pdgId[GenPart_genPartIdxMother[igen]]) == 521 - mode)){
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
						
						// GEN matching
						TLorentzVector l1p4, l2p4, Kp4;
						l1p4.SetPtEtaPhiM(Electron_pt[l1_index],Electron_eta[l1_index],Electron_phi[l1_index],0.000511);
						l2p4.SetPtEtaPhiM(Electron_pt[l2_index],Electron_eta[l2_index],Electron_phi[l2_index],0.000511);
						Kp4.SetPtEtaPhiM(ProbeTracks_pt[k_index],ProbeTracks_eta[k_index],ProbeTracks_phi[k_index],0.493677);
						bool isMatched_ele = false;
						bool isMatched_K = false;
						std::vector<bool> matchingbit; 
						for(int i=0; i<genEle_p4s.size();i++){
							if(l1p4.DeltaR(genEle_p4s[i]) < 0.005) {
								matchingbit.push_back(1);
							}
							else{
								matchingbit.push_back(0);
							}
						}
						for(int i=0; i<genEle_p4s.size();i++){
							if(l2p4.DeltaR(genEle_p4s[i]) < 0.005) {
								matchingbit.push_back(1);
							}
							else{
								matchingbit.push_back(0);
							}
						}
						if((matchingbit[0] && matchingbit[3]) || (matchingbit[1] && matchingbit[2])) isMatched_ele = true;
						for(int i=0; i<genHad_p4s.size();i++){
							if(Kp4.DeltaR(genHad_p4s[0]) < 0.005) isMatched_K = true;
						}
						if(!isMatched_ele || !isMatched_K) continue;
						 
						int isize = -99;
						isize = unique_BToKEE_m.size();
						unique_BToKEE_m.insert(BToKEE_fit_mass[iBKee]);
						if(unique_BToKEE_m.size() > isize){
							if(BToKEE_fit_mass[iBKee] < 5.2 && (genEle_p4s[0] + genEle_p4s[1] + genHad_p4s[0]).M() > 5.2){
								hist1_1->Fill((genEle_p4s[0] + genEle_p4s[1] + genHad_p4s[0]).M());
								cout<<genEle_p4s[0].Pt()<<" "<<genEle_p4s[0].Phi()<<" "<<genEle_p4s[0].Eta()<<" "<<genEle_p4s[0].M()<<endl;
								cout<<genEle_p4s[1].Pt()<<" "<<genEle_p4s[1].Phi()<<" "<<genEle_p4s[1].Eta()<<" "<<genEle_p4s[1].M()<<endl;
								cout<<genHad_p4s[0].Pt()<<" "<<genHad_p4s[0].Phi()<<" "<<genHad_p4s[0].Eta()<<" "<<genHad_p4s[0].M()<<endl;
								cout<<endl;
								cout<<l1p4.Pt()<<" "<<l1p4.Phi()<<" "<<l1p4.Eta()<<" "<<l1p4.M()<<endl;
								cout<<l2p4.Pt()<<" "<<l2p4.Phi()<<" "<<l2p4.Eta()<<" "<<l2p4.M()<<endl;
								cout<<Kp4.Pt()<<" "<<Kp4.Phi()<<" "<<Kp4.Eta()<<" "<<Kp4.M()<<endl;
								cout<<BToKEE_fit_mass[iBKee]<<" "<<BToKEE_mass[iBKee]<<" "<<(genEle_p4s[0] + genEle_p4s[1] + genHad_p4s[0]).M()<<endl;
							}
							else
								hist1_2->Fill((genEle_p4s[0] + genEle_p4s[1] + genHad_p4s[0]).M()); 
							cout<<"--------------------------------------"<<endl;
						}
				}

		}
		
}

void analyzer_GEN() {
    // Create histograms to store muon pt values
    TH1F* hist1_1 = new TH1F("hist1_1", "B mass (GEN)", 1000, 4.2, 6.2);
		TH1F* hist1_2 = new TH1F("hist1_2", "B mass (GEN)", 1000, 4.2, 6.2);
		TH1F* hist1_3 = new TH1F("hist1_3", "l1 p_{T} (all triplet)", 1000, 0,100);
		TH1F* hist1_4 = new TH1F("hist1_4", "l2 p_{T} (all triplet)", 1000, 0,100);
		TChain* chain = new TChain("Events"); // Replace "tree" with the name of your TTree

		for (int i = 0; i < 1; i++) {
				// TString fileName = Form("/eos/cms/store/group/phys_bphys/DiElectronX/production/samples/BParkingNANO_2023Mar10/ParkingDoubleElectronLowMass0/crab_Run2022F_part0/230310_211514/0000/BParkingNANO_Run3_data_2023Mar10_%d.root", i);
				TString fileName = Form("/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/KEE/myNano_%d.root", i);
				chain->Add(fileName);
		}


		FillHistogram(hist1_1, hist1_2, hist1_3, hist1_4, chain);
		
    TCanvas* canvas = new TCanvas("canvas", "Title", 2400, 1800);
		
		TLegend* leg = new TLegend(0.1,0.7,0.3,0.9);
		// leg->AddEntry(hist1, "PF-PF (PF ID, OS)","l");
		// leg->AddEntry(hist2, "PF-PF (PF ID, SS)","l");
		// leg->AddEntry(hist3, "LP-LP (LP ID, OS)","l");
		// leg->AddEntry(hist4, "LP-LP (LP ID, SS)","l");

    hist1_1->Draw();
    hist1_2->SetLineColor(2);
    hist1_2->Draw("SAME");
		// hist1->SetLineColor(6);
    // hist1->Draw("SAME");
		// hist2->SetLineColor(8);
    // hist2->Draw("SAME");
		leg->Draw();

    canvas->Print("test.png");
}