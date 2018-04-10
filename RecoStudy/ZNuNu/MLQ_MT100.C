void MLQ_MT100()
{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Fri Feb  9 15:53:11 2018) by ROOT version6.04/14
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",630,94,590,679);
   Canvas_1->Range(-250,-2.624322,2250,23.61889);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1F *MuJet_LQMass_HighMT_HighDPhi_Iso__1 = new TH1F("MuJet_LQMass_HighMT_HighDPhi_Iso__1","",20,0,2000);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(1,1.328463);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(2,12.34473);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(3,18.61328);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(4,11.08848);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(5,6.298498);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(6,3.453003);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(7,2.025532);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(8,0.3830792);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(9,1.281);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(10,0.2143295);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(11,0.3445871);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(12,0.08563048);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(13,0.0977605);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(14,0.05987814);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(15,0.002611494);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(16,0.001335539);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(17,0.002708927);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(19,0.09064308);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(20,0.001357362);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinContent(21,0.00150413);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(1,0.3332916);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(2,1.251737);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(3,1.381553);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(4,0.8959098);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(5,0.6381375);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(6,0.3887015);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(7,0.3902483);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(8,0.100425);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(9,0.3341785);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(10,0.1078706);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(11,0.189022);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(12,0.06556684);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(13,0.06318963);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(14,0.05666026);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(15,0.001361836);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(16,0.0009717771);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(17,0.001394465);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(19,0.09064308);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(20,0.0009942159);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetBinError(21,0.001063728);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetEntries(1341);
   
   TPaveStats *ptstats = new TPaveStats(0.7011796,0.6169231,0.9003932,0.8969231,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *AText = ptstats->AddText("MuJet_LQMass_HighMT_HighDPhi_Iso");
   AText->SetTextSize(0.0368);
   AText = ptstats->AddText("Entries = 1341   ");
   AText = ptstats->AddText("Mean  =  327.9");
   AText = ptstats->AddText("Std Dev   =  194.9");
   AText = ptstats->AddText("Underflow =      0");
   AText = ptstats->AddText("Overflow  = 0.001504");
   AText = ptstats->AddText("Integral =  57.72");
   ptstats->SetOptStat(1111111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(MuJet_LQMass_HighMT_HighDPhi_Iso__1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->SetLineColor(ci);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->GetXaxis()->SetTitle("M_{LQ} (GeV)");
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->GetXaxis()->SetRange(1,20);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->GetXaxis()->SetLabelFont(42);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->GetXaxis()->SetLabelSize(0.035);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->GetXaxis()->SetTitleFont(42);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->GetYaxis()->SetTitle("Events");
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->GetYaxis()->SetLabelFont(42);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->GetYaxis()->SetLabelSize(0.035);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->GetYaxis()->SetTitleSize(0.035);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->GetYaxis()->SetTitleFont(42);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->GetZaxis()->SetLabelFont(42);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->GetZaxis()->SetLabelSize(0.035);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->GetZaxis()->SetTitleSize(0.035);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->GetZaxis()->SetTitleFont(42);
   MuJet_LQMass_HighMT_HighDPhi_Iso__1->Draw("");
      tex = new TLatex(759.1743,15.01919,"ZToNuNu");
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(746.0681,13.88872,"M_{LQ");
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(677.2608,11.74889,"M_{T} (#mu,MET) > 100 GeV");
   tex->SetLineWidth(2);
   tex->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
   Canvas_1->ToggleToolBar();
}
