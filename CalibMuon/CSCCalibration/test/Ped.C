void Ped(){
  
  TFile *fDiffPeds = TFile::Open("Calibration_Feb_08_2024/diffPeds_Feb_08_2024.root");
  TTree* DiffPeds = (TTree*)fDiffPeds->Get("DiffPeds");
  TLegend* legend = new TLegend(0.7, 0.7, 0.9, 0.9);
  TH2F *h2 = new TH2F("h2","",500,-1,1,230000,0,230000);
  // index vs diff pedestals
  TCanvas *c1 = new TCanvas("c1","",800,600);
  //TH1F *hist = new TH1F("hist", "Histogram Title", 100, 0, 100);
  //c1->SetTitle("Index");
	h2->GetXaxis()->SetTitleSize(.05);
	h2->GetYaxis()->SetTitleSize(.05);
	//gStyle->SetStatOpt(0);
  gPad->SetBottomMargin(0.15); // Adjust margin to accommodate axis title
  gPad->SetLeftMargin(0.15); 
  
  
  //DiffPeds->Draw("index:diffPeds >> h2");
  DiffPeds->Draw("index:diffPeds>>h2","Ped");
  //h2->GetYaxis()->SetTitle("Strip Index");
	//h2->Draw();
	
  
  
  //  c1->SetLogy();
  c1->Update();

  // Draw lines separating each ring in index vs diff plots
  Double_t pME11b = 1.0;
  Double_t pME12 = 17281.0;
  Double_t pME13 = 34561.0;
  Double_t pME11a = 252289.0;
  Double_t pME21 = 48385.0;
  Double_t pME22 = 57025.0;
  Double_t pME31 = 74305.0;
  Double_t pME32 = 82945.0;
  Double_t pME41 = 100225.0;
  Double_t pME42 = 217729.0;
  Double_t mME11b = 108865.0;
  Double_t mME12 = 126145.0;
  Double_t mME13 = 143425.0;
  Double_t mME11a = 262657.0;
  Double_t mME21 = 157249.0;
  Double_t mME22 = 165889.0;
  Double_t mME31 = 183169.0;
  Double_t mME32 = 191809.0;
  Double_t mME41 = 209089.0;
  Double_t mME42 = 235009.0;
  Double_t end = 273024.0;

  TLine *pME11b_line = new TLine(c1->GetUxmin(), pME11b, c1->GetUxmax(), pME11b);
  TLine *pME12_line = new TLine(c1->GetUxmin(), pME12, c1->GetUxmax(), pME12);
  TLine *pME13_line = new TLine(c1->GetUxmin(), pME13, c1->GetUxmax(), pME13);
  TLine *pME11a_line = new TLine(c1->GetUxmin(), pME11a, c1->GetUxmax(), pME11a);
  TLine *pME21_line = new TLine(c1->GetUxmin(), pME21, c1->GetUxmax(), pME21);
  TLine *pME22_line = new TLine(c1->GetUxmin(), pME22, c1->GetUxmax(), pME22);
  TLine *pME31_line = new TLine(c1->GetUxmin(), pME31, c1->GetUxmax(), pME31);
  TLine *pME32_line = new TLine(c1->GetUxmin(), pME32, c1->GetUxmax(), pME32);
  TLine *pME41_line = new TLine(c1->GetUxmin(), pME41, c1->GetUxmax(), pME41);
  TLine *pME42_line = new TLine(c1->GetUxmin(), pME42, c1->GetUxmax(), pME42);
  TLine *mME11b_line = new TLine(c1->GetUxmin(), mME11b, c1->GetUxmax(), mME11b);
  TLine *mME12_line = new TLine(c1->GetUxmin(), mME12, c1->GetUxmax(), mME12);
  TLine *mME13_line = new TLine(c1->GetUxmin(), mME13, c1->GetUxmax(), mME13);
  TLine *mME11a_line = new TLine(c1->GetUxmin(), mME11a, c1->GetUxmax(), mME11a);
  TLine *mME21_line = new TLine(c1->GetUxmin(), mME21, c1->GetUxmax(), mME21);
  TLine *mME22_line = new TLine(c1->GetUxmin(), mME22, c1->GetUxmax(), mME22);
  TLine *mME31_line = new TLine(c1->GetUxmin(), mME31, c1->GetUxmax(), mME31);
  TLine *mME32_line = new TLine(c1->GetUxmin(), mME32, c1->GetUxmax(), mME32);
  TLine *mME41_line = new TLine(c1->GetUxmin(), mME41, c1->GetUxmax(), mME41);
  TLine *mME42_line = new TLine(c1->GetUxmin(), mME42, c1->GetUxmax(), mME42);
  TLine *end_line = new TLine(c1->GetUxmin(), end, c1->GetUxmax(), end);

  pME11b_line->SetLineColor(kRed);
  pME12_line->SetLineColor(kRed);
  pME13_line->SetLineColor(kRed);
  pME11a_line->SetLineColor(kRed);
  pME21_line->SetLineColor(kBlack);
  pME22_line->SetLineColor(kBlack);
  pME31_line->SetLineColor(kBlue);
  pME32_line->SetLineColor(kBlue);
  pME41_line->SetLineColor(kGreen);
  pME42_line->SetLineColor(kGreen);
  mME11b_line->SetLineColor(kRed);
  mME12_line->SetLineColor(kRed);
  mME13_line->SetLineColor(kRed);
  mME11a_line->SetLineColor(kRed);
  mME21_line->SetLineColor(kBlack);
  mME22_line->SetLineColor(kBlack);
  mME31_line->SetLineColor(kBlue);
  mME32_line->SetLineColor(kBlue);
  mME41_line->SetLineColor(kGreen);
  mME42_line->SetLineColor(kGreen);
  end_line->SetLineColor(kRed);

  pME11b_line->SetLineWidth(1);
  pME12_line->SetLineWidth(1);
  pME13_line->SetLineWidth(1);
  pME11a_line->SetLineWidth(1);
  pME21_line->SetLineWidth(1);
  pME22_line->SetLineWidth(1);
  pME31_line->SetLineWidth(1);
  pME32_line->SetLineWidth(1);
  pME41_line->SetLineWidth(1);
  pME42_line->SetLineWidth(1);
  mME11b_line->SetLineWidth(1);
  mME12_line->SetLineWidth(1);
  mME13_line->SetLineWidth(1);
  mME11a_line->SetLineWidth(1);
  mME21_line->SetLineWidth(1);
  mME22_line->SetLineWidth(1);
  mME31_line->SetLineWidth(1);
  mME32_line->SetLineWidth(1);
  mME41_line->SetLineWidth(1);
  mME42_line->SetLineWidth(1);
  end_line->SetLineWidth(1);

  pME11b_line->Draw("SAME");
  pME12_line->Draw("SAME");
  pME13_line->Draw("SAME");
  pME11a_line->Draw("SAME");
  pME21_line->Draw("SAME");
  pME22_line->Draw("SAME");
  pME31_line->Draw("SAME");
  pME32_line->Draw("SAME");
  pME41_line->Draw("SAME");
  pME42_line->Draw("SAME");
  mME11b_line->Draw("SAME");
  mME12_line->Draw("SAME");
  mME13_line->Draw("SAME");
  mME11a_line->Draw("SAME");
  mME21_line->Draw("SAME");
  mME22_line->Draw("SAME");
  mME31_line->Draw("SAME");
  mME32_line->Draw("SAME");
  mME41_line->Draw("SAME");
  mME42_line->Draw("SAME");
  end_line->Draw("SAME");
  legend->AddEntry(mME11a_line,"ME1"); 
  legend->AddEntry(mME21_line,"ME2");
  legend->AddEntry(mME31_line,"ME3");
  legend->AddEntry(mME41_line,"ME4");
  legend->Draw("SAME");
  //c1->Print("Figures/CSCCalib_run_10000014_Feb_08_2024/index_vs_diffPeds_rings.pdf");
  //c1->Print("Figures/CSCCalib_run_10000014_Feb_08_2024/index_vs_diffPeds_rings.png");
  //h2->Draw();
  // diff pedestals
  TCanvas *c2  = new TCanvas("c2","",800,600);
  c2->SetLogy();
  DiffPeds->Draw("diffPeds");
  h2->GetYaxis()->SetTitle("Strip Index");
  //c2->Print("Figures/CSCCalib_run_10000014_Feb_08_2024/diffPeds.pdf");
  //c2->Print("Figures/CSCCalib_run_10000014_Feb_08_2024/diffPeds.png");

}

