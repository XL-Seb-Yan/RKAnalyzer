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
										TH1F* hist1_21, TH1F* hist1_22, TH1F* hist1_23, TH1F* hist1_24, TH1F* hist1_25, TH1F* hist1_26, TH1F* hist1_27, TH1F* hist1_28, TH1F* hist1_29, TH1F* hist1_30,
										TH1F* hist1_31, TH1F* hist1_32, TH1F* hist1_33, TH1F* hist1_34, TH1F* hist1_35, TH1F* hist1_36, TH1F* hist1_37, TH1F* hist1_38, TH1F* hist1_39, TH1F* hist1_40,
										TH1F* hist1_41,
										TH2F* hist2d_1_1,
										TString filename,
										int mode, int ifile) {
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
		
		TString outname = "outputTree_" + std::to_string(ifile) + ".root";
		TFile* outputFile = new TFile(outname,"RECREATE");
		
		TTree* outputTree = new TTree("Events","Events");
		
				Float_t output_BCand_mass_fullfit;
		Float_t output_BCand_mll_fullfit_norm;
		Float_t output_BCand_mll_fullfit;
		Float_t output_BCand_fit_l1_pt_norm;
		Float_t output_BCand_fit_l2_pt_norm;
		Float_t output_BCand_fit_trk1_pt_norm;
		Float_t output_BCand_fit_trk2_pt_norm;
		Float_t output_BCand_fit_l1_pt;
		Float_t output_BCand_fit_l2_pt;
		Float_t output_BCand_fit_trk1_pt;
		Float_t output_BCand_fit_trk2_pt;
		Float_t output_BCand_fit_pt_norm;
		Float_t output_BCand_fit_pt;
		Float_t output_BCand_fit_cos2D;
		Float_t output_BCand_cosAlpha3D;
		Float_t output_BCand_svprob;
		Float_t output_BCand_sigLxy;
		Float_t output_BCand_dR_ll;
		Float_t output_BCand_MomenAsym_lltrk1;
		Float_t output_BCand_MomenAsym_lltrk2;
		Float_t output_BCand_MomenAsym_llKs;
		Float_t output_BCand_iso04_l1_norm;
		Float_t output_BCand_iso04_l2_norm;
		Float_t output_BCand_iso04_trk1_norm;
		Float_t output_BCand_iso04_trk2_norm;
		Float_t output_BCand_sigImpact_lltrk1;
		Float_t output_BCand_sigImpact_lltrk2;
		Float_t output_BCand_dR_l1trk1;
		Float_t output_BCand_dR_l1trk2;
		Float_t output_BCand_dR_l2trk1;
		Float_t output_BCand_dR_l2trk2;
		Float_t output_BCand_dR_trk1trk2;		
		Float_t output_BCand_dz_l1trk1;
		Float_t output_BCand_dz_l1trk2;
		Float_t output_BCand_dz_l2trk1;
		Float_t output_BCand_dz_l2trk2;
		Float_t output_BCand_dz_trk1trk2;
		Float_t output_BCand_l1_ID;
		Float_t output_BCand_l2_ID;
		Int_t output_BCand_evt_nQuad;
		Int_t output_BCand_evt_nTri;
		
		outputTree->Branch("BCand_mass_fullfit", &output_BCand_mass_fullfit, "BCand_mass_fullfit/F");
		outputTree->Branch("BCand_mll_fullfit_norm", &output_BCand_mll_fullfit_norm, "BCand_mll_fullfit_norm/F");
		outputTree->Branch("BCand_mll_fullfit", &output_BCand_mll_fullfit, "BCand_mll_fullfit/F");
    outputTree->Branch("BCand_fit_l1_pt_norm", &output_BCand_fit_l1_pt_norm, "BCand_fit_l1_pt_norm/F");
    outputTree->Branch("BCand_fit_l2_pt_norm", &output_BCand_fit_l2_pt_norm, "BCand_fit_l2_pt_norm/F");
    outputTree->Branch("BCand_fit_trk1_pt_norm", &output_BCand_fit_trk1_pt_norm, "BCand_fit_trk1_pt_norm/F");
		outputTree->Branch("BCand_fit_trk2_pt_norm", &output_BCand_fit_trk1_pt_norm, "BCand_fit_trk2_pt_norm/F");
		outputTree->Branch("BCand_fit_l1_pt", &output_BCand_fit_l1_pt, "BCand_fit_l1_pt/F");
    outputTree->Branch("BCand_fit_l2_pt", &output_BCand_fit_l2_pt, "BCand_fit_l2_pt/F");
    outputTree->Branch("BCand_fit_trk1_pt", &output_BCand_fit_trk1_pt, "BCand_fit_trk1_pt/F");
		outputTree->Branch("BCand_fit_trk2_pt", &output_BCand_fit_trk1_pt, "BCand_fit_trk2_pt/F");
		outputTree->Branch("BCand_fit_pt", &output_BCand_fit_pt, "BCand_fit_pt/F");
    outputTree->Branch("BCand_fit_pt_norm", &output_BCand_fit_pt_norm, "BCand_fit_pt_norm/F");
		outputTree->Branch("BCand_fit_cos2D", &output_BCand_fit_cos2D, "BCand_fit_cos2D/F");
    outputTree->Branch("BCand_cosAlpha3D", &output_BCand_cosAlpha3D, "BCand_cosAlpha3D/F");
    outputTree->Branch("BCand_svprob", &output_BCand_svprob, "BCand_svprob/F");
    outputTree->Branch("BCand_sigLxy", &output_BCand_sigLxy, "BCand_sigLxy/F");
		outputTree->Branch("BCand_dR_ll", &output_BCand_dR_ll, "BCand_dR_ll/F");
		outputTree->Branch("BCand_MomenAsym_lltrk1", &output_BCand_MomenAsym_lltrk1, "BCand_MomenAsym_lltrk1/F");
		outputTree->Branch("BCand_MomenAsym_lltrk2", &output_BCand_MomenAsym_lltrk2, "BCand_MomenAsym_lltrk2/F");
		outputTree->Branch("BCand_MomenAsym_llKs", &output_BCand_MomenAsym_llKs, "BCand_MomenAsym_llKs/F");
		outputTree->Branch("BCand_iso04_l1_norm", &output_BCand_iso04_l1_norm, "BCand_iso04_l1_norm/F");
    outputTree->Branch("BCand_iso04_l2_norm", &output_BCand_iso04_l2_norm, "BCand_iso04_l2_norm/F");
    outputTree->Branch("BCand_iso04_trk1_norm", &output_BCand_iso04_trk1_norm, "BCand_iso04_trk1_norm/F");
		outputTree->Branch("BCand_iso04_trk2_norm", &output_BCand_iso04_trk2_norm, "BCand_iso04_trk2_norm/F");
		outputTree->Branch("BCand_sigImpact_lltrk1", &output_BCand_sigImpact_lltrk1, "BCand_sigImpact_lltrk1/F");
		outputTree->Branch("BCand_sigImpact_lltrk2", &output_BCand_sigImpact_lltrk2, "BCand_sigImpact_lltrk2/F");
		outputTree->Branch("BCand_dR_l1trk1", &output_BCand_dR_l1trk1, "BCand_dR_l1trk1/F");
    outputTree->Branch("BCand_dR_l1trk2", &output_BCand_dR_l1trk2, "BCand_dR_l1trk2/F");
		outputTree->Branch("BCand_dR_l2trk1", &output_BCand_dR_l2trk1, "BCand_dR_l2trk1/F");
    outputTree->Branch("BCand_dR_l2trk2", &output_BCand_dR_l2trk2, "BCand_dR_l2trk2/F");
		outputTree->Branch("BCand_dR_trk1trk2", &output_BCand_dR_trk1trk2, "BCand_dR_trk1trk2/F");
    outputTree->Branch("BCand_dz_l1trk1", &output_BCand_dz_l1trk1, "BCand_dz_l1trk1/F");
    outputTree->Branch("BCand_dz_l1trk2", &output_BCand_dz_l1trk2, "BCand_dz_l1trk2/F");
		outputTree->Branch("BCand_dz_l2trk1", &output_BCand_dz_l2trk1, "BCand_dz_l2trk1/F");
    outputTree->Branch("BCand_dz_l2trk2", &output_BCand_dz_l2trk2, "BCand_dz_l2trk2/F");
		outputTree->Branch("BCand_dz_trk1trk2", &output_BCand_dz_trk1trk2, "BCand_dz_trk1trk2/F");
		outputTree->Branch("BCand_l1_ID", &output_BCand_l1_ID, "BCand_l1_ID/F");
		outputTree->Branch("BCand_l2_ID", &output_BCand_l2_ID, "BCand_l2_ID/F");
		outputTree->Branch("BCand_evt_nTri", &output_BCand_evt_nTri, "BCand_evt_nTri/I");
		outputTree->Branch("BCand_evt_nQuad", &output_BCand_evt_nQuad, "BCand_evt_nQuad/I");
    
		
		TTreeReader reader(tree);
		
		TTreeReaderValue<Int_t> nBToKEE(reader, "nBToKEE");
		TTreeReaderValue<Int_t> nBToKsEE(reader, "nBToKsEE");
		TTreeReaderArray<Float_t> BToKsEE_mass(reader, "BToKsEE_mass");
		TTreeReaderArray<Float_t> BToKsEE_fit_mass(reader, "BToKsEE_fit_mass");
		TTreeReaderArray<Float_t> BToKsEE_fit_pt(reader, "BToKsEE_fit_pt");
		TTreeReaderArray<Float_t> BToKsEE_fit_eta(reader, "BToKsEE_fit_eta");
		TTreeReaderArray<Float_t> BToKsEE_fit_phi(reader, "BToKsEE_fit_phi");
		TTreeReaderArray<Float_t> BToKsEE_fit_l1_pt(reader, "BToKsEE_fit_l1_pt");
		TTreeReaderArray<Float_t> BToKsEE_fit_l1_eta(reader, "BToKsEE_fit_l1_eta");
		TTreeReaderArray<Float_t> BToKsEE_fit_l1_phi(reader, "BToKsEE_fit_l1_phi");
		TTreeReaderArray<Float_t> BToKsEE_fit_l2_pt(reader, "BToKsEE_fit_l2_pt");
		TTreeReaderArray<Float_t> BToKsEE_fit_l2_eta(reader, "BToKsEE_fit_l2_eta");
		TTreeReaderArray<Float_t> BToKsEE_fit_l2_phi(reader, "BToKsEE_fit_l2_phi");
		TTreeReaderArray<Float_t> BToKsEE_fit_trk1_pt(reader, "BToKsEE_fit_trk1_pt");
		TTreeReaderArray<Float_t> BToKsEE_fit_trk1_eta(reader, "BToKsEE_fit_trk1_eta");
		TTreeReaderArray<Float_t> BToKsEE_fit_trk1_phi(reader, "BToKsEE_fit_trk1_phi");
		TTreeReaderArray<Float_t> BToKsEE_fit_trk2_pt(reader, "BToKsEE_fit_trk2_pt");
		TTreeReaderArray<Float_t> BToKsEE_fit_trk2_eta(reader, "BToKsEE_fit_trk2_eta");
		TTreeReaderArray<Float_t> BToKsEE_fit_trk2_phi(reader, "BToKsEE_fit_trk2_phi");
		TTreeReaderArray<Float_t> BToKsEE_fit_kstar_eta(reader, "BToKsEE_fit_kstar_eta");
		TTreeReaderArray<Float_t> BToKsEE_fit_kstar_mass(reader, "BToKsEE_fit_kstar_mass");
		TTreeReaderArray<Float_t> BToKsEE_fit_kstar_phi(reader, "BToKsEE_fit_kstar_phi");
		TTreeReaderArray<Float_t> BToKsEE_fit_kstar_pt(reader, "BToKsEE_fit_kstar_pt");
		TTreeReaderArray<Float_t> BToKsEE_fit_cos2D(reader, "BToKsEE_fit_cos2D");
		TTreeReaderArray<Float_t> BToKsEE_svprob(reader, "BToKsEE_svprob");
		TTreeReaderArray<Float_t> BToKsEE_vtx_x(reader, "BToKsEE_vtx_x");
		TTreeReaderArray<Float_t> BToKsEE_vtx_y(reader, "BToKsEE_vtx_y");
		TTreeReaderArray<Float_t> BToKsEE_vtx_z(reader, "BToKsEE_vtx_z");
		TTreeReaderArray<Float_t> BToKsEE_l_xy(reader, "BToKsEE_l_xy");
		TTreeReaderArray<Float_t> BToKsEE_l_xy_unc(reader, "BToKsEE_l_xy_unc");
    TTreeReaderArray<Float_t> BToKsEE_mll_raw(reader, "BToKsEE_mll_raw");
		TTreeReaderArray<Float_t> BToKsEE_mll_charge(reader, "BToKsEE_mll_charge");
		TTreeReaderArray<Float_t> BToKsEE_mll_fullfit(reader, "BToKsEE_mll_fullfit");
    TTreeReaderArray<Int_t>   BToKsEE_l1_idx(reader, "BToKsEE_l1_idx");
    TTreeReaderArray<Int_t>   BToKsEE_l2_idx(reader, "BToKsEE_l2_idx");
		TTreeReaderArray<Int_t>   BToKsEE_trk1_idx(reader, "BToKsEE_trk1_idx");
		TTreeReaderArray<Int_t>   BToKsEE_trk2_idx(reader, "BToKsEE_trk2_idx");
		TTreeReaderArray<Float_t> BToKsEE_trk1_svip2d(reader, "BToKsEE_trk1_svip2d");
		TTreeReaderArray<Float_t> BToKsEE_trk1_svip2d_err(reader, "BToKsEE_trk1_svip2d_err");
		TTreeReaderArray<Float_t> BToKsEE_trk1_svip3d(reader, "BToKsEE_trk1_svip3d");
		TTreeReaderArray<Float_t> BToKsEE_trk1_svip3d_err(reader, "BToKsEE_trk1_svip3d_err");
		TTreeReaderArray<Float_t> BToKsEE_trk2_svip2d(reader, "BToKsEE_trk2_svip2d");
		TTreeReaderArray<Float_t> BToKsEE_trk2_svip2d_err(reader, "BToKsEE_trk2_svip2d_err");
		TTreeReaderArray<Float_t> BToKsEE_trk2_svip3d(reader, "BToKsEE_trk2_svip3d");
		TTreeReaderArray<Float_t> BToKsEE_trk2_svip3d_err(reader, "BToKsEE_trk2_svip3d_err");
		TTreeReaderArray<Float_t> BToKsEE_trk1_iso04(reader, "BToKsEE_trk1_iso04");
		TTreeReaderArray<Float_t> BToKsEE_trk2_iso04(reader, "BToKsEE_trk2_iso04");
		TTreeReaderArray<Float_t> BToKsEE_l1_iso04(reader, "BToKsEE_l1_iso04");
		TTreeReaderArray<Float_t> BToKsEE_l2_iso04(reader, "BToKsEE_l2_iso04");
		
		TTreeReaderArray<Int_t>   Electron_charge(reader, "Electron_charge");
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
		int counter1=0, counter2=0, counter3=0, counter4=0, counter5=0, counter6=0, counter7=0, counter8=0, counter9=0, counter10=0, counter11=0, counter12=0;
    // Loop through the entries
    Long64_t numEntries = tree->GetEntries();
		cout<<"Total: "<<numEntries<<endl;
    for(Long64_t ievt = 0; ievt < numEntries; ++ievt) {
		// for(Long64_t ievt = 0; ievt < 100; ++ievt) {
				counter1++;
				reader.SetLocalEntry(ievt);
        if(ievt % 1000 == 0) {
            std::cout << "Processing " << static_cast<double>(ievt) / numEntries << std::endl;
        }

        tree->GetEntry(ievt);
				
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
				
				for(size_t iB = 0; iB < BToKsEE_mass.GetSize(); ++iB) {
					counter3++;
					int l1_index = BToKsEE_l1_idx[iB];
					int l2_index = BToKsEE_l2_idx[iB];
					int trk1_index = BToKsEE_trk1_idx[iB];
					int trk2_index = BToKsEE_trk2_idx[iB];
					
					counter4++;
					l1_index = BToKsEE_l1_idx[iB];
					l2_index = BToKsEE_l2_idx[iB];
					trk1_index = BToKsEE_trk1_idx[iB];
					trk2_index = BToKsEE_trk2_idx[iB];
					if(BToKsEE_mll_charge[iB] != 0) continue;
					counter5++;
					if(!Electron_isPF[l1_index] || !Electron_isPF[l2_index]) continue;
					counter6++;
					if(BToKsEE_fit_mass[iB] < 4.7 || BToKsEE_fit_mass[iB] > 5.7) continue;
					if(BToKsEE_fit_mass[iB] < 5.5 && BToKsEE_fit_mass[iB] > 5.0) continue;
					counter7++;
					if(BToKsEE_mll_fullfit[iB]*BToKsEE_mll_fullfit[iB] < 1.1 || BToKsEE_mll_fullfit[iB]*BToKsEE_mll_fullfit[iB] > 6.0) continue;	
					counter8++;
					if(Electron_pt[l1_index] < 5 || Electron_pt[l2_index] < 5) {continue;}
					if(abs(Electron_eta[l1_index]) > 1.22 || abs(Electron_eta[l2_index]) > 1.22) {continue;}
					counter9++;
					if(ProbeTracks_pt[trk1_index] < 0.5 || ProbeTracks_pt[trk2_index] < 0.5) {continue;}
					if(abs(ProbeTracks_eta[trk1_index]) > 1.22 || abs(ProbeTracks_eta[trk2_index]) > 1.22) {continue;}
					counter10++;
					if(BToKsEE_fit_cos2D[iB] < 0.9) continue;
					counter11++;
					
					TLorentzVector l1p4, l2p4, trk1p4, trk2p4;
					TLorentzVector Ksp4, Bp4;
					l1p4.SetPtEtaPhiM(BToKsEE_fit_l1_pt[iB], BToKsEE_fit_l1_eta[iB], BToKsEE_fit_l1_phi[iB], 0.000511);
					l2p4.SetPtEtaPhiM(BToKsEE_fit_l2_pt[iB], BToKsEE_fit_l2_eta[iB], BToKsEE_fit_l2_phi[iB], 0.000511);
					trk1p4.SetPtEtaPhiM(BToKsEE_fit_trk1_pt[iB], BToKsEE_fit_trk1_eta[iB], BToKsEE_fit_trk1_phi[iB], 0.493677);
					trk2p4.SetPtEtaPhiM(BToKsEE_fit_trk2_pt[iB], BToKsEE_fit_trk2_eta[iB], BToKsEE_fit_trk2_phi[iB], 0.493677);
					Ksp4.SetPtEtaPhiM(BToKsEE_fit_kstar_pt[iB], BToKsEE_fit_kstar_eta[iB], BToKsEE_fit_kstar_phi[iB], BToKsEE_fit_kstar_mass[iB]);
					Bp4.SetPtEtaPhiM(BToKsEE_fit_pt[iB],BToKsEE_fit_eta[iB],BToKsEE_fit_phi[iB],BToKsEE_fit_mass[iB]);
					TLorentzVector llp4;
					llp4 = l1p4 + l2p4;
					ROOT::Math::XYZVector Bp3Vector(Bp4.Px(), Bp4.Py(), Bp4.Pz());
					ROOT::Math::XYZVector llp3Vector(llp4.Px(),llp4.Py(),llp4.Pz());
					ROOT::Math::XYZVector trk1p3Vector(trk1p4.Px(),trk1p4.Py(),trk1p4.Pz());
					ROOT::Math::XYZVector trk2p3Vector(trk2p4.Px(),trk2p4.Py(),trk2p4.Pz());
					ROOT::Math::XYZVector Ksp3Vector(Ksp4.Px(),Ksp4.Py(),Ksp4.Pz());
					ROOT::Math::XYZVector BVtxVector(BToKsEE_vtx_x[iB] - PV_x[0], BToKsEE_vtx_y[iB] - PV_y[0], BToKsEE_vtx_z[iB] - PV_z[0]);
					ROOT::Math::XYZVector unitBVtxVector = BVtxVector / BVtxVector.R();
					
					output_BCand_mass_fullfit = BToKsEE_fit_mass[iB];
					hist1_1->Fill(output_BCand_mass_fullfit); 
					
					output_BCand_mll_fullfit = BToKsEE_mll_fullfit[iB];
					hist1_2->Fill(output_BCand_mll_fullfit);
					
					output_BCand_mll_fullfit_norm = BToKsEE_mll_fullfit[iB] / BToKsEE_fit_mass[iB];
					hist1_3->Fill(output_BCand_mll_fullfit_norm);
					
					output_BCand_fit_l1_pt = BToKsEE_fit_l1_pt[iB];
					hist1_4->Fill(output_BCand_fit_l1_pt);
					
					output_BCand_fit_l2_pt = BToKsEE_fit_l2_pt[iB];
					hist1_5->Fill(output_BCand_fit_l2_pt);
					
					output_BCand_fit_l1_pt_norm = BToKsEE_fit_l1_pt[iB] / BToKsEE_fit_mass[iB];
					hist1_6->Fill(output_BCand_fit_l1_pt_norm);
					
					output_BCand_fit_l2_pt_norm = BToKsEE_fit_l2_pt[iB] / BToKsEE_fit_mass[iB];
					hist1_7->Fill(output_BCand_fit_l2_pt_norm); 
					
					output_BCand_fit_trk1_pt = BToKsEE_fit_trk1_pt[iB];
					hist1_8->Fill(output_BCand_fit_trk1_pt); 
					
					output_BCand_fit_trk2_pt = BToKsEE_fit_trk2_pt[iB];
					hist1_9->Fill(output_BCand_fit_trk2_pt); 
					
					output_BCand_fit_trk1_pt_norm = BToKsEE_fit_trk1_pt[iB] / BToKsEE_fit_mass[iB];
					hist1_10->Fill(output_BCand_fit_trk1_pt_norm); 
					
					output_BCand_fit_trk2_pt_norm = BToKsEE_fit_trk2_pt[iB] / BToKsEE_fit_mass[iB];
					hist1_11->Fill(output_BCand_fit_trk2_pt_norm); 
					
					output_BCand_fit_pt = BToKsEE_fit_pt[iB];
					hist1_12->Fill(output_BCand_fit_pt);
					
					output_BCand_fit_pt_norm = BToKsEE_fit_pt[iB] / BToKsEE_fit_mass[iB];
					hist1_13->Fill(output_BCand_fit_pt_norm); 
					
					output_BCand_cosAlpha3D = BVtxVector.Dot(Bp3Vector) / (BVtxVector.R() * Bp3Vector.R());
					hist1_14->Fill(output_BCand_cosAlpha3D); 
					
					output_BCand_svprob = BToKsEE_svprob[iB];
					hist1_15->Fill(output_BCand_svprob); 
					
					output_BCand_sigLxy = BToKsEE_l_xy[iB] / BToKsEE_l_xy_unc[iB];
					hist1_16->Fill(output_BCand_sigLxy);
					
					output_BCand_fit_cos2D = BToKsEE_fit_cos2D[iB];
					hist1_17->Fill(output_BCand_fit_cos2D); 
					
					output_BCand_MomenAsym_lltrk1 = ((llp3Vector.Cross(unitBVtxVector)).R() - (trk1p3Vector.Cross(unitBVtxVector)).R()) / ((llp3Vector.Cross(unitBVtxVector)).R() + (trk1p3Vector.Cross(unitBVtxVector)).R());
					hist1_18->Fill(output_BCand_MomenAsym_lltrk1);
					
					output_BCand_MomenAsym_lltrk2 = ((llp3Vector.Cross(unitBVtxVector)).R() - (trk2p3Vector.Cross(unitBVtxVector)).R()) / ((llp3Vector.Cross(unitBVtxVector)).R() + (trk2p3Vector.Cross(unitBVtxVector)).R());
					hist1_19->Fill(output_BCand_MomenAsym_lltrk2);
					
					output_BCand_MomenAsym_llKs = ((llp3Vector.Cross(unitBVtxVector)).R() - (Ksp3Vector.Cross(unitBVtxVector)).R()) / ((llp3Vector.Cross(unitBVtxVector)).R() + (Ksp3Vector.Cross(unitBVtxVector)).R());
					hist1_20->Fill(output_BCand_MomenAsym_llKs);
					
					output_BCand_sigImpact_lltrk1 = BToKsEE_trk1_svip3d[iB]/BToKsEE_trk1_svip3d_err[iB];
					hist1_21->Fill(output_BCand_sigImpact_lltrk1); 
					
					output_BCand_sigImpact_lltrk2 = BToKsEE_trk2_svip3d[iB]/BToKsEE_trk2_svip3d_err[iB];
					hist1_22->Fill(output_BCand_sigImpact_lltrk2);
					
					output_BCand_iso04_l1_norm = BToKsEE_l1_iso04[iB] / BToKsEE_fit_l1_pt[iB];
					hist1_23->Fill(output_BCand_iso04_l1_norm);
					
					output_BCand_iso04_l2_norm = BToKsEE_l2_iso04[iB] / BToKsEE_fit_l2_pt[iB];
					hist1_24->Fill(output_BCand_iso04_l2_norm); 
					
					output_BCand_iso04_trk1_norm = BToKsEE_trk1_iso04[iB] / BToKsEE_fit_trk1_pt[iB];
					hist1_25->Fill(output_BCand_iso04_trk1_norm); 
					
					output_BCand_iso04_trk2_norm = BToKsEE_trk2_iso04[iB] / BToKsEE_fit_trk2_pt[iB];
					hist1_26->Fill(output_BCand_iso04_trk2_norm); 
					
					output_BCand_dR_ll = l1p4.DeltaR(l2p4);
					hist1_27->Fill(output_BCand_dR_ll);
					
					output_BCand_dR_l1trk1 = l1p4.DeltaR(trk1p4);
					hist1_28->Fill(output_BCand_dR_l1trk1);
					
					output_BCand_dR_l1trk2 = l1p4.DeltaR(trk2p4);
					hist1_29->Fill(output_BCand_dR_l1trk2);
					
					output_BCand_dR_l2trk1 = l2p4.DeltaR(trk1p4);
					hist1_30->Fill(output_BCand_dR_l2trk1);
					
					output_BCand_dR_l2trk2 = l2p4.DeltaR(trk2p4);
					hist1_31->Fill(output_BCand_dR_l2trk2);
					
					output_BCand_dR_trk1trk2 = trk1p4.DeltaR(trk2p4);
					hist1_32->Fill(output_BCand_dR_trk1trk2);
					
					output_BCand_dz_l1trk1 = Electron_vz[l1_index] - ProbeTracks_vz[trk1_index];
					hist1_33->Fill(output_BCand_dz_l1trk1);
					
					output_BCand_dz_l1trk2 = Electron_vz[l1_index] - ProbeTracks_vz[trk2_index];
					hist1_34->Fill(output_BCand_dz_l1trk2);
					
					output_BCand_dz_l2trk1 = Electron_vz[l2_index] - ProbeTracks_vz[trk1_index];
					hist1_35->Fill(output_BCand_dz_l2trk1);
					
					output_BCand_dz_l2trk2 = Electron_vz[l2_index] - ProbeTracks_vz[trk2_index];
					hist1_36->Fill(output_BCand_dz_l2trk2);
					
					output_BCand_dz_trk1trk2 = ProbeTracks_vz[trk1_index] - ProbeTracks_vz[trk2_index];
					hist1_37->Fill(output_BCand_dz_trk1trk2);
					
					output_BCand_l1_ID = Electron_PFEleMvaID_RetrainedRawValue[l1_index];
					hist1_38->Fill(output_BCand_l1_ID);
					
					output_BCand_l2_ID = Electron_PFEleMvaID_RetrainedRawValue[l2_index];
					hist1_39->Fill(output_BCand_l2_ID);
					
					output_BCand_evt_nTri = *nBToKEE;
					hist1_40->Fill(output_BCand_evt_nTri);
					
					output_BCand_evt_nQuad = *nBToKsEE;
					hist1_41->Fill(output_BCand_evt_nQuad);
					
					outputTree->Fill();
				}
		}//end event loop
		
		cout<<"counters: "<<counter1<<" "<<counter2<<" "<<counter3<<" "<<counter4<<" "<<counter5<<" "<<counter6<<" "<<counter7<<" "<<counter8<<" "<<counter9<<" "<<counter10<<" "<<counter11<<" "<<counter12<<endl;
		cout<<"Tree check: "<<outputTree->GetEntries()<<endl;
		outputFile->Write();
		outputFile->Close();
		// Close the file
    file->Close();
}

void analyzer_Data_131_quadruplets(TString filename, int ifile, int mode) {
    // Create histograms to store muon pt values
    TH1F* hist1_1 = new TH1F("hist1_1", "B mass", 1000, 4.2, 6.2);
		TH1F* hist1_2 = new TH1F("hist1_2", "ll mass", 1200, 0, 6);
		TH1F* hist1_3 = new TH1F("hist1_3", "ll mass normalized", 1000, 0, 1);
		TH1F* hist1_4 = new TH1F("hist1_4", "l1 p_{T}", 1000, 0,100);
		TH1F* hist1_5 = new TH1F("hist1_5", "l2 p_{T}", 1000, 0,100);
		TH1F* hist1_6 = new TH1F("hist1_6", "l1 p_{T} normalized", 1500, 0,15);
		TH1F* hist1_7 = new TH1F("hist1_7", "l2 p_{T} normalized", 1500, 0,15);
		TH1F* hist1_8 = new TH1F("hist1_8", "trk1 p_{T}", 1500, 0,30);
		TH1F* hist1_9 = new TH1F("hist1_9", "trk2 p_{T}", 1500, 0,30);
		TH1F* hist1_10 = new TH1F("hist1_10", "trk1 p_{T} normalized", 1000, 0,10);
		TH1F* hist1_11 = new TH1F("hist1_11", "trk2 p_{T} normalized", 1000, 0,10);
		TH1F* hist1_12 = new TH1F("hist1_12", "B p_{T}", 1000, 0,100);
		TH1F* hist1_13 = new TH1F("hist1_13", "B p_{T} normalized", 1000, 0,20);
		TH1F* hist1_14 = new TH1F("hist1_14", "cos #alpha_{3D}", 1000, -1,1);
		TH1F* hist1_15 = new TH1F("hist1_15", "Prob(SV fit)", 1000, 0,1);
		TH1F* hist1_16 = new TH1F("hist1_16", "sig(Lxy)", 1000, 0,500);
		TH1F* hist1_17 = new TH1F("hist1_17", "cos 2D fit", 1000, 0.9,1);
		TH1F* hist1_18 = new TH1F("hist1_18", "Momentum asymmetry ll-trk1", 1000, -1,1);
		TH1F* hist1_19 = new TH1F("hist1_19", "Momentum asymmetry ll-trk2", 1000, -1,1);
		TH1F* hist1_20 = new TH1F("hist1_20", "Momentum asymmetry ll-Ks", 1000, -1,1);
		TH1F* hist1_21 = new TH1F("hist1_21", "Impact parameter trk1", 1000, 0,60);
		TH1F* hist1_22 = new TH1F("hist1_22", "Impact parameter trk2", 1000, 0,60);
		TH1F* hist1_23 = new TH1F("hist1_23", "Isolation l1_iso04 normalized", 1000, 0,1);
		TH1F* hist1_24 = new TH1F("hist1_24", "Isolation l2_iso04 normalized", 1000, 0,1);
		TH1F* hist1_25 = new TH1F("hist1_25", "Isolation trk1_iso04 normalized", 1000, 0,1);
		TH1F* hist1_26 = new TH1F("hist1_26", "Isolation trk2_iso04 normalized", 1000, 0,1);
		TH1F* hist1_27 = new TH1F("hist1_27", "#Delta R (ll)", 1000, 0,3);
		TH1F* hist1_28 = new TH1F("hist1_28", "#Delta R (l1-trk1)", 1000, 0,4);
		TH1F* hist1_29 = new TH1F("hist1_29", "#Delta R (l1-trk2)", 1000, 0,4);
		TH1F* hist1_30 = new TH1F("hist1_30", "#Delta R (l2-trk1)", 1000, 0,4);
		TH1F* hist1_31 = new TH1F("hist1_31", "#Delta R (l2-trk2)", 1000, 0,4);
		TH1F* hist1_32 = new TH1F("hist1_32", "#Delta R (trk-trk)", 1000, 0,4);
		TH1F* hist1_33 = new TH1F("hist1_33", "#Delta z (l1-trk1)", 1000, -3,3);
		TH1F* hist1_34 = new TH1F("hist1_34", "#Delta z (l1-trk2)", 1000, -3,3);
		TH1F* hist1_35 = new TH1F("hist1_35", "#Delta z (l2-trk1)", 1000, -3,3);
		TH1F* hist1_36 = new TH1F("hist1_36", "#Delta z (l2-trk2)", 1000, -3,3);
		TH1F* hist1_37 = new TH1F("hist1_37", "#Delta z (trk-trk)", 1000, -3,3);
		TH1F* hist1_38 = new TH1F("hist1_38", "l1 ID", 2000, -10,10);
		TH1F* hist1_39 = new TH1F("hist1_39", "l2 ID", 2000, -10,10);
		TH1F* hist1_40 = new TH1F("hist1_40", "nTriplets", 100, 0,100);
		TH1F* hist1_41 = new TH1F("hist1_41", "nQuadruplets", 30, 0,30);
		
		TH2F* hist2d_1_1  = new TH2F("hist2d_1_1","Trigger map",15,3.75,11.25,13,3.75,10.25);

		FillHistogram(hist1_1, hist1_2, hist1_3, hist1_4, hist1_5, hist1_6, hist1_7, hist1_8,hist1_9, hist1_10,
									hist1_11, hist1_12, hist1_13, hist1_14, hist1_15, hist1_16, hist1_17, hist1_18, hist1_19, hist1_20,
									hist1_21, hist1_22, hist1_23, hist1_24, hist1_25, hist1_26, hist1_27, hist1_28, hist1_29, hist1_30,
									hist1_31, hist1_32, hist1_33, hist1_34, hist1_35, hist1_36, hist1_37, hist1_38, hist1_39, hist1_40,
									hist1_41,
									hist2d_1_1, 
									filename,
									mode, ifile);
		
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
		hist1_26->Write();
		hist1_27->Write();
		hist1_28->Write();
		hist1_29->Write();
		hist1_30->Write();
		hist1_31->Write();
		hist1_32->Write();
		hist1_33->Write();
		hist1_34->Write();
		hist1_35->Write();
		hist1_36->Write();
		hist1_37->Write();
		hist1_38->Write();
		hist1_39->Write();
		hist1_40->Write();
		hist1_41->Write();
		hist2d_1_1->Write();
		output->Write();
		output->Close();
}