#if !defined(__CINT__) || defined(__MAKECINT__)
#include <TROOT.h>                  // access to gROOT, entry point to ROOT system
#include <TSystem.h>                // interface to OS
#include <TFile.h>                  // file handle class
#include <TTree.h>  
#include <TChain.h>                   // class to access ntuples
#include <TClonesArray.h>           // ROOT array class
#include <TBenchmark.h>             // class to track macro running statistics
#include <TVector2.h>               // 2D vector class
#include <TVector3.h>               // 2D vector class
#include <TMath.h>                  // ROOT math library
#include <vector>                   // STL vector class
#include <utility>
#include <iostream>                 // standard I/O
#include <iomanip>                  // functions to format standard I/O
#include <fstream>                  // functions for file I/O
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
    TTreeReaderArray<Float_t> BToKEE_mll_raw(reader, "BToKEE_mll_raw");
		// TTreeReaderArray<Float_t> BToKEE_mll_charge(reader, "BToKEE_mll_charge");
		TTreeReaderArray<Float_t> BToKEE_mll_fullfit(reader, "BToKEE_mll_fullfit");
    TTreeReaderArray<Int_t>   BToKEE_l1Idx(reader, "BToKEE_l1Idx");
    TTreeReaderArray<Int_t>   BToKEE_l2Idx(reader, "BToKEE_l2Idx");
		TTreeReaderArray<Int_t>   BToKEE_kIdx(reader, "BToKEE_kIdx");
		
		// TTreeReaderArray<Float_t> BToKsEE_mass(reader, "BToKsEE_mass");
    // TTreeReaderArray<Float_t> BToKsEE_mll_raw(reader, "BToKsEE_mll_raw");
		// TTreeReaderArray<Float_t> BToKsEE_mll_charge(reader, "BToKsEE_mll_charge");
    // TTreeReaderArray<Int_t>   BToKsEE_l1_idx(reader, "BToKsEE_l1_idx");
    // TTreeReaderArray<Int_t>   BToKsEE_l2_idx(reader, "BToKsEE_l2_idx");
		// TTreeReaderArray<Int_t>   BToKsEE_trk1_idx(reader, "BToKsEE_trk1_idx");
    // TTreeReaderArray<Int_t>   BToKsEE_trk2_idx(reader, "BToKsEE_trk2_idx");
		// TTreeReaderArray<Float_t> Kstar_mass(reader, "Kstar_mass");
		
		TTreeReaderArray<Float_t> Electron_pt(reader, "Electron_pt");
		TTreeReaderArray<Float_t> Electron_eta(reader, "Electron_eta");
    TTreeReaderArray<Bool_t>  Electron_isPF(reader, "Electron_isPF");
    TTreeReaderArray<Bool_t>  Electron_PFEleMvaID_Fall17NoIsoV2wp90(reader, "Electron_PFEleMvaID_Fall17NoIsoV2wp90");
		TTreeReaderArray<Float_t> Electron_PFEleMvaID_RetrainedRawValue(reader, "Electron_PFEleMvaID_RetrainedRawValue");
		
		TTreeReaderArray<Float_t> ProbeTracks_pt(reader, "ProbeTracks_pt");
		TTreeReaderArray<Float_t> ProbeTracks_eta(reader, "ProbeTracks_eta");

    // Loop through the entries
    Long64_t numEntries = chain->GetEntries();
    for (Long64_t ievt = 0; ievt < numEntries; ++ievt) {
				reader.SetLocalEntry(ievt);
        if (ievt % 1000 == 0) {
            std::cout << "Processing " << static_cast<double>(ievt) / numEntries << std::endl;
        }

        chain->GetEntry(ievt);
				
				std::set<float> unique_BToKEE_m;
				std::set<float> unique_BToKEE_mll;
				// std::set<float> unique_BToKEE_noKstar_m;
				// std::set<float> unique_BToKEE_noKstar_mll;
				
				for (size_t iBKee = 0; iBKee < BToKEE_mass.GetSize(); ++iBKee) {
						int l1_index = BToKEE_l1Idx[iBKee];
						int l2_index = BToKEE_l2Idx[iBKee];
						int k_index = BToKEE_kIdx[iBKee];
						
						if (Electron_pt[l1_index] < 5 || Electron_pt[l2_index] < 5) {continue;}
						if (abs(Electron_eta[l1_index]) > 1.22 || abs(Electron_eta[l2_index]) > 1.22) {continue;}
						if (ProbeTracks_pt[k_index] < 1.5) {continue;}
						if (abs(ProbeTracks_eta[k_index]) > 1.22) {continue;}
						if (!Electron_isPF[l1_index] || !Electron_isPF[l2_index] || Electron_PFEleMvaID_RetrainedRawValue[l1_index] < 0 || Electron_PFEleMvaID_RetrainedRawValue[l2_index] < 0) {continue;}
						
						// bool isPartOfBKStar = false;
						// for (size_t iBKStaree = 0; iBKStaree < BToKsEE_mass.GetSize(); ++iBKStaree) {
								// if((BToKsEE_l1_idx[iBKStaree] == l1_index && 
									 // BToKsEE_l2_idx[iBKStaree] == l2_index &&
									 // BToKsEE_trk1_idx[iBKStaree] == k_index) ||
									// (BToKsEE_l1_idx[iBKStaree] == l1_index && 
									 // BToKsEE_l2_idx[iBKStaree] == l2_index &&
									 // BToKsEE_trk2_idx[iBKStaree] == k_index) ||
									// (BToKsEE_l1_idx[iBKStaree] == l2_index && 
									 // BToKsEE_l2_idx[iBKStaree] == l1_index &&
									 // BToKsEE_trk1_idx[iBKStaree] == k_index) ||
									// (BToKsEE_l1_idx[iBKStaree] == l2_index && 
									 // BToKsEE_l2_idx[iBKStaree] == l1_index &&
									 // BToKsEE_trk2_idx[iBKStaree] == k_index)) {
										 // isPartOfBKStar = true;
										 // break;
									 // }
						// }
						 
						int isize = -99;
						
						isize = unique_BToKEE_m.size();
						unique_BToKEE_m.insert(BToKEE_fit_mass[iBKee]);
						if(unique_BToKEE_m.size() > isize){
							hist1_1->Fill(BToKEE_fit_mass[iBKee]);
						}
						
						isize = unique_BToKEE_mll.size();
						unique_BToKEE_mll.insert(BToKEE_mll_fullfit[iBKee]);
						if(unique_BToKEE_mll.size() > isize){
							hist1_2->Fill(BToKEE_mll_fullfit[iBKee]);
						}
						
						// if (!isPartOfBKStar){
			
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
		}
}

void analyzer_TChain() {
    // Create histograms to store muon pt values
    TH1F* hist1_1 = new TH1F("hist1_1", "B mass (Kll)", 1000, 3, 8);
		TH1F* hist1_2 = new TH1F("hist1_2", "ll mass", 1000, 0, 5);
		TH1F* hist1_3 = new TH1F("hist1_3", "B mass (Kstar veto)", 1000, 3, 8);
		TH1F* hist1_4 = new TH1F("hist1_4", "ll mass (Kstar veto)", 1000, 0, 5);
		TH1F* hist2_1 = new TH1F("hist2_1", "B mass (K^{*}ll)", 1000, 0, 5);
		TH1F* hist2_2 = new TH1F("hist2_2", "K^{*} mass (K^{*}ll)", 1000, 0, 5);
		
		TChain* chain = new TChain("Events"); // Replace "tree" with the name of your TTree

		for (int i = 0; i < 50; i++) {
				// TString fileName = Form("/eos/cms/store/group/phys_bphys/DiElectronX/production/samples/BParkingNANO_2023Mar10/ParkingDoubleElectronLowMass0/crab_Run2022F_part0/230310_211514/0000/BParkingNANO_Run3_data_2023Mar10_%d.root", i);
				TString fileName = Form("/eos/home-x/xuyan/RKProj/KStarllStudy/Data/Test1_1699908660/myNano_%d.root", i);
				chain->Add(fileName);
		}


		FillHistogram(hist1_1, hist1_2, hist1_3, hist1_4, chain);
		
		TString outname = "outputHits.root";
		TFile* output = new TFile(outname,"RECREATE");
		output->cd();
		hist1_1->Write();
		hist1_2->Write();
		hist1_3->Write();
		hist1_4->Write();
		output->Write();
		output->Close();
		

    // Create a canvas
    // TCanvas* canvas = new TCanvas("canvas", "Title", 2400, 1800);
		
		// TLegend* leg = new TLegend(0.1,0.7,0.3,0.9);
		// leg->AddEntry(hist1, "PF-PF (PF ID, OS)","l");
		// leg->AddEntry(hist2, "PF-PF (PF ID, SS)","l");
		// leg->AddEntry(hist3, "LP-LP (LP ID, OS)","l");
		// leg->AddEntry(hist4, "LP-LP (LP ID, SS)","l");

    // Draw histograms
    // hist3->Draw();
    // hist4->SetLineColor(2);
    // hist4->Draw("SAME");
		// hist1->SetLineColor(6);
    // hist1->Draw("SAME");
		// hist2->SetLineColor(8);
    // hist2->Draw("SAME");
		// leg->Draw();

    // Display the canvas
    // canvas->Print("test.png");
}