#if !defined(__CINT__) || defined(__MAKECINT__)
#include <TROOT.h>                  // access to gROOT, entry point to ROOT system
#include <TSystem.h>                // interface to OS
#include <TFile.h>                  // file handle class
#include <TTree.h>                  // class to access ntuples
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

void FillHistogram(TH1F* hist1, TH1F* hist2, TH1F* hist3, TH1F* hist4, TH1F* hist5, TH1F* hist6, TH1F* hist1_1, TH1F* hist1_2, TH1F* hist2_1, TH1F* hist2_2, TH1F* hist3_1, TH1F* hist3_2, TString filename) {
    // Open the ROOT file
    TFile* file = TFile::Open(filename);
    if (!file || file->IsZombie()) {
        // Handle file open error
        return;
    }

    // Get the TTree containing the data (replace "Events" with your tree name)
    TTree* tree = dynamic_cast<TTree*>(file->Get("Events"));
    if (!tree) {
        // Handle tree retrieval error
        file->Close();
        return;
    }

		TTreeReader reader(tree);

		TTreeReaderArray<Float_t> BToKEE_mass(reader, "BToKEE_mass");
    TTreeReaderArray<Float_t> BToKEE_mll_raw(reader, "BToKEE_mll_raw");
		TTreeReaderArray<Float_t> BToKEE_mll_charge(reader, "BToKEE_mll_charge");
		TTreeReaderArray<Float_t> Electron_pt(reader, "Electron_pt");
		TTreeReaderArray<Float_t> Electron_eta(reader, "Electron_eta");
    TTreeReaderArray<Int_t> BToKEE_l1Idx(reader, "BToKEE_l1Idx");
    TTreeReaderArray<Int_t> BToKEE_l2Idx(reader, "BToKEE_l2Idx");
    TTreeReaderArray<Bool_t> Electron_isPF(reader, "Electron_isPF");
		TTreeReaderArray<Bool_t> Electron_isLowPt(reader, "Electron_isLowPt");
    TTreeReaderArray<Bool_t> Electron_PFEleMvaID_Fall17NoIsoV2wp90(reader, "Electron_PFEleMvaID_Fall17NoIsoV2wp90");
		TTreeReaderArray<Float_t> Electron_PFEleMvaID_RetrainedRawValue(reader, "Electron_PFEleMvaID_RetrainedRawValue");
		TTreeReaderArray<Float_t> Electron_LPEleMvaID_2020Sept15RawValue(reader, "Electron_LPEleMvaID_2020Sept15RawValue");
		TTreeReaderArray<Float_t> Electron_LPEleSeed_Fall17PtBiasedV1RawValue(reader, "Electron_LPEleSeed_Fall17PtBiasedV1RawValue");
		TTreeReaderArray<Float_t> Electron_LPEleSeed_Fall17UnBiasedV1RawValue(reader, "Electron_LPEleSeed_Fall17UnBiasedV1RawValue");

		float minID_l1 = 999;
		float minID_l2 = 999;
    // Loop through the entries
    Long64_t numEntries = tree->GetEntries();
		// for (Long64_t ievt = 0; ievt < 100; ++ievt) {
    for (Long64_t ievt = 0; ievt < numEntries; ++ievt) {
				reader.SetLocalEntry(ievt);
        if (ievt % 1000 == 0) {
            std::cout << "Processing " << static_cast<double>(ievt) / numEntries << std::endl;
        }

        tree->GetEntry(ievt);

				std::vector<int> PFPFIDOS_list;
				std::vector<int> PFPFIDSS_list;
				std::vector<int> PFPFretrainedIDOS_list;
				std::vector<int> PFPFretrainedIDSS_list;
				std::vector<int> LPLPIDOS_list;
				std::vector<int> LPLPIDSS_list;
				
				std::vector<float> PFPFIDOSmll_list;
				std::vector<float> PFPFIDSSmll_list;
				std::vector<float> PFPFretrainedIDOSmll_list;
				std::vector<float> PFPFretrainedIDSSmll_list;
				std::vector<float> LPLPIDOSmll_list;
				std::vector<float> LPLPIDSSmll_list;

        for (size_t iBKee = 0; iBKee < BToKEE_mll_raw.GetSize(); ++iBKee) {
						if(BToKEE_mass[iBKee] < 4.7 || BToKEE_mass[iBKee] > 5.7) continue;
            int l1idx = BToKEE_l1Idx[iBKee];
            int l2idx = BToKEE_l2Idx[iBKee];
						
						if (Electron_pt[l1idx] < 2 || Electron_pt[l2idx] < 2) {continue;}
						
						if (abs(Electron_eta[l1idx]) > 1.22 || abs(Electron_eta[l2idx]) > 1.22) {continue;}

						// if (Electron_isPF[l1idx] && Electron_isPF[l2idx] && Electron_PFEleMvaID_Fall17NoIsoV2wp90[l1idx] && Electron_PFEleMvaID_Fall17NoIsoV2wp90[l2idx] && BToKEE_mll_charge[iBKee] == 0) {
            if (Electron_isPF[l1idx] && Electron_isPF[l2idx] && BToKEE_mll_charge[iBKee] == 0) {
                PFPFIDOS_list.push_back(iBKee);
								PFPFIDOSmll_list.push_back(BToKEE_mll_raw[iBKee]);
            }
						
						// if (Electron_isPF[l1idx] && Electron_isPF[l2idx] && Electron_PFEleMvaID_Fall17NoIsoV2wp90[l1idx] && Electron_PFEleMvaID_Fall17NoIsoV2wp90[l2idx] && BToKEE_mll_charge[iBKee] != 0) {
						if (Electron_isPF[l1idx] && Electron_isPF[l2idx] && BToKEE_mll_charge[iBKee] != 0) {
                PFPFIDSS_list.push_back(iBKee);
								PFPFIDSSmll_list.push_back(BToKEE_mll_raw[iBKee]);
            }
						
						if (Electron_isPF[l1idx] && Electron_isPF[l2idx] && Electron_PFEleMvaID_RetrainedRawValue[l1idx] > -9999 && Electron_PFEleMvaID_RetrainedRawValue[l2idx] > -9999 && BToKEE_mll_charge[iBKee] == 0) {
                PFPFretrainedIDOS_list.push_back(iBKee);
								PFPFretrainedIDOSmll_list.push_back(BToKEE_mll_raw[iBKee]);
            }
						
						if (Electron_isPF[l1idx] && Electron_isPF[l2idx] && Electron_PFEleMvaID_RetrainedRawValue[l1idx] > -9999 && Electron_PFEleMvaID_RetrainedRawValue[l2idx] > -9999 && BToKEE_mll_charge[iBKee] != 0) {
                PFPFretrainedIDSS_list.push_back(iBKee);
								PFPFretrainedIDSSmll_list.push_back(BToKEE_mll_raw[iBKee]);
            }
						
						if (Electron_isLowPt[l1idx] && Electron_isLowPt[l2idx] && Electron_LPEleMvaID_2020Sept15RawValue[l1idx] > -9999 && Electron_LPEleMvaID_2020Sept15RawValue[l2idx] > -9999 && BToKEE_mll_charge[iBKee] == 0) {
                LPLPIDOS_list.push_back(iBKee);
								LPLPIDOSmll_list.push_back(BToKEE_mll_raw[iBKee]);
            }
						
						if (Electron_isLowPt[l1idx] && Electron_isLowPt[l2idx] && Electron_LPEleMvaID_2020Sept15RawValue[l1idx] > -9999 && Electron_LPEleMvaID_2020Sept15RawValue[l2idx] > -9999 && BToKEE_mll_charge[iBKee] != 0) {
                LPLPIDSS_list.push_back(iBKee);
								LPLPIDSSmll_list.push_back(BToKEE_mll_raw[iBKee]);
            }
				}
				
				std::vector<int> PFPFIDOS_unique_list;
				std::vector<int> PFPFIDSS_unique_list;
				std::vector<int> PFPFretrainedIDOS_unique_list;
				std::vector<int> PFPFretrainedIDSS_unique_list;
				std::vector<int> LPLPIDOS_unique_list;
				std::vector<int> LPLPIDSS_unique_list;
				
				std:set<float> unique_mll;
				for(int i = 0; i < PFPFIDOSmll_list.size(); i++){
					int isize = unique_mll.size();
					unique_mll.insert(PFPFIDOSmll_list[i]);
					if(unique_mll.size() > isize){
						hist1->Fill(PFPFIDOSmll_list[i]);
						hist1_1->Fill(Electron_pt[BToKEE_l1Idx[PFPFIDOS_list[i]]]);
						hist1_2->Fill(Electron_pt[BToKEE_l2Idx[PFPFIDOS_list[i]]]);
					}
				}
				
				unique_mll.clear();
				for(int i = 0; i < PFPFIDSSmll_list.size(); i++){
					int isize = unique_mll.size();
					unique_mll.insert(PFPFIDSSmll_list[i]);
					if(unique_mll.size() > isize){
						hist2->Fill(PFPFIDSSmll_list[i]);
					}
				}
				
				unique_mll.clear();
				for(int i = 0; i < PFPFretrainedIDOSmll_list.size(); i++){
					int isize = unique_mll.size();
					unique_mll.insert(PFPFretrainedIDOSmll_list[i]);
					if(unique_mll.size() > isize){
						hist3->Fill(PFPFretrainedIDOSmll_list[i]);
						hist2_1->Fill(Electron_pt[BToKEE_l1Idx[PFPFretrainedIDOS_list[i]]]);
						hist2_2->Fill(Electron_PFEleMvaID_RetrainedRawValue[BToKEE_l2Idx[PFPFretrainedIDOS_list[i]]]);
					}
				}
				
				unique_mll.clear();
				for(int i = 0; i < PFPFretrainedIDSSmll_list.size(); i++){
					int isize = unique_mll.size();
					unique_mll.insert(PFPFretrainedIDSSmll_list[i]);
					if(unique_mll.size() > isize){
						hist4->Fill(PFPFretrainedIDSSmll_list[i]);
					}
				}
				
				unique_mll.clear();
				for(int i = 0; i < LPLPIDOSmll_list.size(); i++){
					int isize = unique_mll.size();
					unique_mll.insert(LPLPIDOSmll_list[i]);
					if(unique_mll.size() > isize){
						hist5->Fill(LPLPIDOSmll_list[i]);
						hist3_1->Fill(Electron_LPEleSeed_Fall17PtBiasedV1RawValue[BToKEE_l1Idx[LPLPIDOS_list[i]]]);
						hist3_2->Fill(Electron_LPEleSeed_Fall17UnBiasedV1RawValue[BToKEE_l1Idx[LPLPIDOS_list[i]]]);
						if(Electron_LPEleSeed_Fall17PtBiasedV1RawValue[BToKEE_l1Idx[LPLPIDOS_list[i]]] < minID_l1)
							minID_l1 = Electron_LPEleSeed_Fall17PtBiasedV1RawValue[BToKEE_l1Idx[LPLPIDOS_list[i]]];
						if(Electron_LPEleSeed_Fall17UnBiasedV1RawValue[BToKEE_l1Idx[LPLPIDOS_list[i]]] < minID_l2)
							minID_l2 = Electron_LPEleSeed_Fall17UnBiasedV1RawValue[BToKEE_l1Idx[LPLPIDOS_list[i]]];
					}
				}
				
				unique_mll.clear();
				for(int i = 0; i < LPLPIDSSmll_list.size(); i++){
					int isize = unique_mll.size();
					unique_mll.insert(LPLPIDSSmll_list[i]);
					if(unique_mll.size() > isize){
						hist6->Fill(LPLPIDSSmll_list[i]);
					}
				}
    }
		
    // Close the file
    file->Close();
		
		cout<<"minIDPtBiased_l1: "<<minID_l1<<endl;
		cout<<"minIDUnBiased_l1: "<<minID_l2<<endl;
}

void analyzer(TString filename, int ifile) {
    // Create histograms to store muon pt values
    TH1F* hist1 = new TH1F("hist1", "PF-PF (PF ID, OS)", 1000, 0, 5);
    TH1F* hist2 = new TH1F("hist2", "PF-PF (PF ID, SS)", 1000, 0, 5);
		TH1F* hist3 = new TH1F("hist3", "PF-PF (PF ID retrained, OS)", 1000, 0, 5);
		TH1F* hist4 = new TH1F("hist4", "PF-PF (PF ID retrained, SS)", 1000, 0, 5);
		TH1F* hist5 = new TH1F("hist5", "LP-LP (LP ID, OS)", 1000, 0, 5);
		TH1F* hist6 = new TH1F("hist6", "LP-LP (LP ID, SS)", 1000, 0, 5);
		
		TH1F* hist1_1 = new TH1F("hist1_1", "PF1 pT (PF ID, OS)", 300, 0, 30);
		TH1F* hist1_2 = new TH1F("hist1_2", "PF2 pT (PF ID, OS)", 300, 0, 30);
		TH1F* hist2_1 = new TH1F("hist2_1", "PF1 pT (PF retrained ID, OS)", 300, 0, 30);
		TH1F* hist2_2 = new TH1F("hist2_2", "PF1 ID value (PF retrained ID, OS)", 5000, -1, 1);
		TH1F* hist3_1 = new TH1F("hist3_1", "LP1 pT (LP ID, OS)", 5000, -5, 5);
		TH1F* hist3_2 = new TH1F("hist3_2", "LP1 ID value (LP ID, OS)", 5000, -5, 5);
		

    // Loop through your ROOT files and fill the histograms
    // const char* fileNames[] = {"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698767653/myNano_0.root"};

		FillHistogram(hist1, hist2, hist3, hist4, hist5, hist6, hist1_1, hist1_2, hist2_1, hist2_2, hist3_1, hist3_2, filename);
		
		TString outname = "outputHits_allID_" + std::to_string(ifile) + ".root";
		TFile* output = new TFile(outname,"RECREATE");
		output->cd();
		hist1->Write();
		hist2->Write();
		hist3->Write();
		hist4->Write();
		hist5->Write();
		hist6->Write();
		hist1_1->Write();
		hist1_2->Write();
		hist2_1->Write();
		hist2_2->Write();
		hist3_1->Write();
		hist3_2->Write();
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