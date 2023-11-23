//make signal shapes
#if !defined(__CINT__) || defined(__MAKECINT__)
#include <TROOT.h>                  // access to gROOT, entry point to ROOT system
#include <TSystem.h>                // interface to OS
#include <TFile.h>                  // file handle class
#include <TTree.h>                  // class to access ntuples
#include <TClonesArray.h>           // ROOT array class
#include <TBenchmark.h>             // class to track macro running statistics
#include <TVector2.h>               // 2D vector class
#include <TMath.h>                  // ROOT math library
#include <vector>                   // STL vector class
#include <iostream>                 // standard I/O
#include <iomanip>                  // functions to format standard I/O
#include <fstream>                  // functions for file I/O
#include "TLorentzVector.h"         // 4-vector class
#include <THStack.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TLegend.h>
#include <TF1.h>
#include <TEfficiency.h>
#include "TGraphAsymmErrors.h"
#include "TH1D.h"
#include "TRandom.h"
#include <algorithm>
#include <map>
#include <RooMsgService.h>
#include <RooRandom.h>
#include <RooRealVar.h>
#include <RooArgSet.h>
#include <RooArgList.h>
#include <RooCBShape.h>
#include <RooDataSet.h>
#include <RooDataHist.h>
#include <RooChi2Var.h>
#include <TLatex.h>
#include <RooPlot.h>
#include <RooHist.h>
#include <RooPlotable.h>
#include <RooWorkspace.h>
#include <RooAddPdf.h>
#include <RooBukinPdf.h>
#include "/eos/home-x/xuyan/TrijetProj/TrijetAna/ZprimeAna/utiles/CMS_lumi.C"
#endif

std::string to_str_trim(const float a_value, const int n = 2)
{
    return std::to_string(a_value).substr(0,std::to_string(a_value).find(".") + n + 1);
}

void FittingSignal()
{
  gErrorIgnoreLevel = kInfo;
  gROOT->SetBatch(1);
  using namespace RooFit;
  RooMsgService::instance().setGlobalKillBelow(RooFit::ERROR);
  RooRandom::randomGenerator()->SetSeed(37); 

  gROOT->SetBatch(1);
  writeExtraText = 1;
  lumiTextOffset = 0.15;
  bool plot_CMS = true;
  extraText = "Preliminary";
  lumiTextSize = 0.4;
  cmsTextSize = 0.5;
  int iPeriod = 4;
  int iPos = 11;
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	gStyle->SetTitleSize(0.05,"XYZ");
	gStyle->SetLabelSize(0.05,"XYZ");
	//gStyle->SetFrameLineWidth(2);
	gStyle->SetLegendTextSize(0.03);
	gStyle->SetBarWidth(2);
	gStyle->SetHistLineWidth(2);
	gStyle->SetEndErrorSize(2);
	gStyle->SetPadTickX(1);
	gStyle->SetPadTickY(1);
  

  // --- Create obervable --- 
  RooRealVar *m = new RooRealVar("M_ee","M_ee",2.7,3.4,""); //the name "m" will be used by RooDataSet to import data

  // --- signal PDF ---
  TString fun_name = "CBGaus";
  RooRealVar* CB_mean = new RooRealVar("CB_mean","CB_mean",3.0,2.7,3.4,"");
  RooRealVar* CB_sigma = new RooRealVar("CB_sigma","CB_sigma",0.05,0,0.17,"");
  RooRealVar* CB_alpha = new RooRealVar("CB_alpha","CB_alpha",1,0,3,"");
  RooRealVar* CB_n = new RooRealVar("CB_n","CB_n",1,0,5,"");
  RooCBShape* CB_model = new RooCBShape("CBShape","Cystal Ball Function",*m,*CB_mean,*CB_sigma,*CB_alpha,*CB_n);
	
  
  RooRealVar* Gaus_mean = new RooRealVar("Gaus_mean","Gaus_mean",3.0,2.7,3.4,"");
  RooRealVar* Gaus_sigma = new RooRealVar("Gaus_sigma","Gaus_sigma",0.05,0,0.17,"");
  RooGaussian* Gaus_model = new RooGaussian("Gaussian","Gaussian Function",*m,*Gaus_mean,*Gaus_sigma);
	RooRealVar* frac_1 = new RooRealVar("frac1","frac1",0.5,0,1);
  RooAddPdf* CBGaus_model = new RooAddPdf("CBGaus","CBGaus",RooArgList(*CB_model,*Gaus_model),RooArgList(*frac_1));

  
  RooRealVar* lambda = new RooRealVar("lambda", "Exponential Decay Parameter", -0.1, -3.0, 0.0);
  RooExponential* exp_model = new RooExponential("ExpShape", "Exponential PDF", *m, *lambda);
	
	
	RooRealVar* frac_2 = new RooRealVar("frac2","frac2",0.5,0,1);
	RooAddPdf* total_model2 = new RooAddPdf("Total","Total",RooArgList(*CBGaus_model, *exp_model),RooArgList(*frac_2));
	RooRealVar* nor3 = new RooRealVar("nor3", "Normalization", 100000, 30000, 150000);
	RooExtendPdf* total_model2_ex = new RooExtendPdf("Ext", "Total", *total_model2, *nor3);
	

  // --- Import Binned dataset ---
  TFile* file = TFile::Open("2E-3_10GeV_-0p57_2p65.root");
	TH1F* hist = (TH1F*)file->Get("hist5");
	// hist->Rebin(5);
	
  RooDataHist datah("PFPFOS","PFPFOS",RooArgSet(*m),hist);
  
  RooFitResult *r = total_model2_ex->fitTo(datah,RooFit::Range(2.7,3.4),RooFit::Minimizer("Minuit2"),Save()); //SumW2Error(false) for weighted data, see how to choose this with same calling without SumW2Error(false)

  // --- Plot ---
  gStyle->SetOptStat(111111);
  RooPlot *frame = m->frame();
	datah.plotOn(frame,RooFit::Name("data"));
  frame->getAttMarker()->SetMarkerSize(2);
  total_model2_ex->plotOn(frame,LineColor(2),RooFit::Name("fit"));
  // total_model2_ex->plotOn(frame,VisualizeError(*r,2,kFALSE),FillColor(kYellow),LineColor(0),RooFit::Name("err2"));
  total_model2_ex->plotOn(frame,VisualizeError(*r,1,kFALSE),FillColor(kGreen),LineColor(0),RooFit::Name("err1"));
  total_model2_ex->plotOn(frame,Components("CBGaus"),LineStyle(kDashed),LineColor(1),RooFit::Name("CBGaus"));
  total_model2_ex->plotOn(frame,Components("ExpShape"),LineStyle(kDashed),RooFit::Name("Exp"));
  total_model2_ex->plotOn(frame,LineColor(2),RooFit::Name("fit"));
  datah.plotOn(frame);
  frame->getAttMarker()->SetMarkerSize(2);
	
	TString paramNames[] = {
  "#chi^{2}/ndf", "#mu_{CB}", "#sigma_{CB}", "#alpha_{CB}",
  "n_{CB}", "#lambda_{Exp}", "N (signal)", "N (background)"
};

double paramValues[] = {
  frame->chiSquare("fit", "data", 6),
  CB_mean->getVal(), CB_sigma->getVal(), CB_alpha->getVal(),
  CB_n->getVal(), lambda->getVal(), nor3->getVal() * frac_2->getVal(),
  nor3->getVal() * (1 - frac_2->getVal())
};

double paramErrors[] = {
  0, CB_mean->getError(), CB_sigma->getError(), CB_alpha->getError(),
  CB_n->getError(), lambda->getError(), nor3->getError() * frac_2->getVal(),
  nor3->getError() * (1 - frac_2->getVal())
};

// Create an array of TLatex objects
TLatex* latexArray[8];

for (int i = 0; i < 8; ++i) {
  TString paramText = Form("%s: %.2f #pm %.2f", paramNames[i].Data(), paramValues[i], paramErrors[i]);
  latexArray[i] = new TLatex(0.15, 0.7 - i * 0.04, paramText);
  latexArray[i]->SetNDC();
  latexArray[i]->SetTextSize(0.026);
  frame->addObject(latexArray[i]);
}
	
  
  TCanvas *c01 = new TCanvas("c01","c01",2100,2000);
  TPad *p01a = new TPad("p01a","p01a",0.0,0.27,1,1.0);
  TPad *p01b = new TPad("p01b","p01b",0.0,0.1,1,0.315);
  p01a->Draw();
  p01b->Draw();
  p01a->cd();
  p01a->SetLeftMargin(0.11);
  p01a->SetBottomMargin(0.11);
  //axis,log scale and range setting functions must be called after all plotOn functions being called
  TAxis* xaxis = frame->GetXaxis();
  TAxis* yaxis = frame->GetYaxis();
  xaxis->SetTitle("");
  xaxis->SetTitleOffset(1.2);
  yaxis->SetTitle("Events");
  yaxis->SetTitleOffset(1);
  yaxis->SetRangeUser(0,4000);
  xaxis->SetRangeUser(2.7,3.4);
  frame->Draw();
  // CMS_lumi(p01a,iPeriod,iPos, 0);
  TLegend *l =  new TLegend(0.7,0.7,0.85,0.85);
	l->SetBorderSize(0);
  l->AddEntry(frame->findObject("data"),"Data","lep");
  l->AddEntry(frame->findObject("fit"),"Total fit","l");
	l->AddEntry(frame->findObject("CB"),"J/#psi","l");
	l->AddEntry(frame->findObject("Exp"),"Background","l");
  l->AddEntry(frame->findObject("err1"),"Fit Error 1 #sigma","f");
  // l->AddEntry(frame->findObject("err2"),"Fit Error 2 #sigma","f");
  l->Draw("same");
  
  p01b->cd();
  p01b->SetLeftMargin(0.11);
  p01b->SetTopMargin(0.2);
  p01b->SetBottomMargin(0.25);
  RooHist* hpull = frame->pullHist();
  RooPlot* pull_frame = m->frame();
  pull_frame->addPlotable(hpull,"B") ;
  hpull->SetMarkerStyle(8);
  hpull->SetMarkerSize(0);
  hpull->SetLineWidth(0);
  hpull->SetFillColor(kAzure+1);
  hpull->SetFillColorAlpha(kAzure+1,0.7);
  xaxis = pull_frame->GetXaxis();
  yaxis = pull_frame->GetYaxis();
  xaxis->SetTitle("m_{ee} [GeV]");
  yaxis->SetTitle("#frac{Data-Fit}{#sigma_{stat}}");
  yaxis->SetTitleOffset(0.4);
  yaxis->SetRangeUser(-5,5);
  xaxis->SetLabelSize(0.12);
  xaxis->SetTitleSize(0.12);
  yaxis->SetLabelSize(0.12);
  yaxis->SetTitleSize(0.12);
  yaxis->SetNdivisions(5);
  xaxis->SetRangeUser(2.7,3.4);
  p01b->SetGrid();
  pull_frame->Draw();
  p01b->Update();
  c01->Print("fit.png");
  
  // --- Output root file ---
  // RooWorkspace *w = new RooWorkspace("w","w");
  // w->import(*m);
  // w->import(datah,Rename("signal_MC"));
  // w->import(*CBGaus_model);
  // w->writeToFile(signalmass_str+"-shapes-Unbinned-CBGaus"+".root");
}
