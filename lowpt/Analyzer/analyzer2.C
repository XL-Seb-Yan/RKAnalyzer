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

void FillHistogram(TH1F* hist1, TH1F* hist2, TH1F* hist3, TH1F* hist4, TH1F* hist5, TH1F* hist6, TString filename) {
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

    // Loop through the entries
    Long64_t numEntries = tree->GetEntries();
    for (Long64_t ievt = 0; ievt < numEntries; ++ievt) {
				reader.SetLocalEntry(ievt);
        if (ievt % 1000 == 0) {
            std::cout << "Processing " << static_cast<double>(ievt) / numEntries << std::endl;
        }

        tree->GetEntry(ievt);

        std::vector<float> mll_list;
				std::vector<int> charge_list;
        std::vector<bool> isBothPF_list;
				std::vector<bool> isBothLP_list;
        std::vector<bool> isBothPFID_list;
				std::vector<bool> isBothPFRetrainID_list;
				std::vector<bool> isBothLPID_list;

        for (size_t iBKee = 0; iBKee < BToKEE_mll_raw.GetSize(); ++iBKee) {
						if(BToKEE_mass[iBKee] < 4.7 || BToKEE_mass[iBKee] > 5.7) continue;
            int l1idx = BToKEE_l1Idx[iBKee];
            int l2idx = BToKEE_l2Idx[iBKee];
            bool isBothPF = false;
						bool isBothLP = false;
            bool isBothPFID = true;
						bool isBothPFRetrainID = false;
						bool isBothLPID = true;
						
						if (Electron_pt[l1idx] < 5 || Electron_pt[l2idx] < 5) {continue;}
						
						if (abs(Electron_eta[l1idx]) > 1.22 || abs(Electron_eta[l2idx]) > 1.22) {continue;}

            if (Electron_isPF[l1idx] && Electron_isPF[l2idx]) {
                isBothPF = true;
            }
						
						if (Electron_isLowPt[l1idx] && Electron_isLowPt[l2idx]) {
                isBothLP = true;
            }

            if (Electron_PFEleMvaID_Fall17NoIsoV2wp90[l1idx] && Electron_PFEleMvaID_Fall17NoIsoV2wp90[l2idx]) {
                isBothPFID = true;
            }
						
						// 1E-3
						// if (Electron_PFEleMvaID_RetrainedRawValue[l1idx] > -0.2 && Electron_PFEleMvaID_RetrainedRawValue[l2idx] > -0.2) {
                // isBothPFRetrainID = true;
            // }
						
						
						// if (Electron_LPEleMvaID_2020Sept15RawValue[l1idx] > 2.48 && Electron_LPEleMvaID_2020Sept15RawValue[l2idx] > 2.48) {
                // isBothLPID = true;
            // }
						
						// if (Electron_LPEleMvaID_2020Sept15RawValue[l1idx] > 1.95 && Electron_LPEleMvaID_2020Sept15RawValue[l2idx] > 1.95) {
                // isBothLPID = true;
            // }
						
						// 5E-3
						if (Electron_PFEleMvaID_RetrainedRawValue[l1idx] > -0.2 && Electron_PFEleMvaID_RetrainedRawValue[l2idx] > -0.2) {
                isBothPFRetrainID = true;
            }
						
						if (Electron_LPEleMvaID_2020Sept15RawValue[l1idx] > -9999 && Electron_LPEleMvaID_2020Sept15RawValue[l2idx] > -9999) {
                isBothLPID = true;
            }

            mll_list.push_back(BToKEE_mll_raw[iBKee]);
            isBothPF_list.push_back(isBothPF);
						isBothLP_list.push_back(isBothLP);
            isBothPFID_list.push_back(isBothPFID);
						isBothPFRetrainID_list.push_back(isBothPFRetrainID);
						isBothLPID_list.push_back(isBothLPID);
						charge_list.push_back(BToKEE_mll_charge[iBKee]);
        }

        // Select the desired di-ele
        std::set<Float_t> mllPFIDOS_list;
        std::set<Float_t> mllPFIDSS_list;
				std::set<Float_t> mllPFRetrainIDOS_list;
        std::set<Float_t> mllPFRetrainIDSS_list;
				std::set<Float_t> mllLPIDOS_list;
        std::set<Float_t> mllLPIDSS_list;

        for (size_t imll = 0; imll < mll_list.size(); ++imll) {
            if (isBothPF_list[imll] && isBothPFID_list[imll] && charge_list[imll] == 0) {
                mllPFIDOS_list.insert(mll_list[imll]);
            }

            if (isBothPF_list[imll] && isBothPFID_list[imll] && charge_list[imll] != 0) {
                mllPFIDSS_list.insert(mll_list[imll]);
            }
						
						if (isBothPF_list[imll] && isBothPFRetrainID_list[imll] && charge_list[imll] == 0) {
                mllPFRetrainIDOS_list.insert(mll_list[imll]);
            }

            if (isBothPF_list[imll] && isBothPFRetrainID_list[imll] && charge_list[imll] != 0) {
                mllPFRetrainIDSS_list.insert(mll_list[imll]);
            }
						
						if (isBothLP_list[imll] && isBothLPID_list[imll] && charge_list[imll] == 0) {
                mllLPIDOS_list.insert(mll_list[imll]);
            }

            if (isBothLP_list[imll] && isBothLPID_list[imll] && charge_list[imll] != 0) {
                mllLPIDSS_list.insert(mll_list[imll]);
            }
        }
		

				for (const float& mll_unique : mllPFIDOS_list) {
						hist1->Fill(mll_unique);
				}

        for (const float& mll_unique : mllPFIDSS_list) {
						hist2->Fill(mll_unique);
				}

        for (const float& mll_unique : mllPFRetrainIDOS_list) {
						hist3->Fill(mll_unique);
				}

        for (const float& mll_unique : mllPFRetrainIDSS_list) {
						hist4->Fill(mll_unique);
				}

        for (const float& mll_unique : mllLPIDOS_list) {
						hist5->Fill(mll_unique);
				}

        for (const float& mll_unique : mllLPIDSS_list) {
						hist6->Fill(mll_unique);
				}
    }
		
    // Close the file
    file->Close();
}

void analyzer2(TString filename, int ifile) {
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
		TH1F* hist2_2 = new TH1F("hist2_2", "PF2 pT (PF retrained ID, OS)", 300, 0, 30);
		TH1F* hist3_1 = new TH1F("hist3_1", "LP1 pT (LP ID, OS)", 300, 0, 30);
		TH1F* hist3_2 = new TH1F("hist3_2", "LP2 pT (LP ID, OS)", 300, 0, 30);
		

    // Loop through your ROOT files and fill the histograms
    // const char* fileNames[] = {"/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_0.root",
		// "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_1.root",
		// "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_2.root",
		// "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_3.root",
		// "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_4.root",
		// "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_5.root",
		// "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_6.root",
		// "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_7.root",
		// "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_8.root",
		// "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_9.root",
		// "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_10.root",
		// "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_11.root",
		// "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_12.root",
		// "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_13.root",
		// "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_14.root",
		// "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_15.root",
		// "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_16.root",
		// "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_17.root",
		// "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_18.root",
		// "/eos/home-x/xuyan/RKProj/lowpt/Data/Test1_1698084809/myNano_19.root"};

		FillHistogram(hist1, hist2, hist3, hist4, hist5, hist6, filename);
		
		TString outname = "outputHits_allID_" + std::to_string(ifile) + ".root";
		TFile* output = new TFile(outname,"RECREATE");
		output->cd();
		hist1->Write();
		hist2->Write();
		hist3->Write();
		hist4->Write();
		hist5->Write();
		hist6->Write();
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