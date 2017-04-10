void limit()
{
//=========Macro generated from canvas: limit/limit
//=========  (Fri Dec  2 00:26:29 2016) by ROOT version6.02/05
   TCanvas *limit = new TCanvas("limit", "limit",0,0,600,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   limit->SetHighLightColor(2);
   limit->Range(0,0,1,1);
   limit->SetFillColor(0);
   limit->SetBorderMode(0);
   limit->SetBorderSize(2);
   limit->SetLeftMargin(0.16);
   limit->SetRightMargin(0.04);
   limit->SetTopMargin(0.06);
   limit->SetBottomMargin(0.12);
   limit->SetFrameFillStyle(0);
   limit->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad
   TPad *pad = new TPad("pad", "pad",0,0,1,1);
   pad->Draw();
   pad->cd();
   pad->Range(800,-0.001267091,2050,0.009292004);
   pad->SetFillColor(0);
   pad->SetBorderMode(0);
   pad->SetBorderSize(2);
   pad->SetTickx(1);
   pad->SetTicky(1);
   pad->SetLeftMargin(0.16);
   pad->SetRightMargin(0.04);
   pad->SetTopMargin(0.06);
   pad->SetBottomMargin(0.12);
   pad->SetFrameFillStyle(0);
   pad->SetFrameBorderMode(0);
   pad->SetFrameFillStyle(0);
   pad->SetFrameBorderMode(0);
   
   TH1F *tmp01 = new TH1F("tmp01","Graph",100,1000,2000);
   tmp01->SetMinimum(0);
   tmp01->SetMaximum(0.008658458);
   tmp01->SetStats(0);
   tmp01->SetLineStyle(0);
   tmp01->SetMarkerStyle(20);
   tmp01->GetXaxis()->SetTitle("m_{LQ} (GeV)");
   tmp01->GetXaxis()->SetLabelFont(42);
   tmp01->GetXaxis()->SetLabelOffset(0.01);
   tmp01->GetXaxis()->SetTitleSize(0.05);
   tmp01->GetXaxis()->SetTickLength(0.02);
   tmp01->GetXaxis()->SetTitleOffset(1.08);
   tmp01->GetXaxis()->SetTitleFont(42);
   tmp01->GetYaxis()->SetTitle("95% CL limit on #sigma(LQLQ#rightarrowMuJ DMX) [pb]");
   tmp01->GetYaxis()->SetLabelFont(42);
   tmp01->GetYaxis()->SetLabelOffset(0.007);
   tmp01->GetYaxis()->SetTitleSize(0.05);
   tmp01->GetYaxis()->SetTickLength(0.02);
   tmp01->GetYaxis()->SetTitleOffset(1.56);
   tmp01->GetYaxis()->SetTitleFont(42);
   tmp01->GetZaxis()->SetLabelFont(42);
   tmp01->GetZaxis()->SetLabelOffset(0.007);
   tmp01->GetZaxis()->SetTitleSize(0.05);
   tmp01->GetZaxis()->SetTickLength(0.02);
   tmp01->GetZaxis()->SetTitleFont(42);
   tmp01->Draw("AXIS");
   
   TH1F *tmp02 = new TH1F("tmp02","Graph",100,1000,2000);
   tmp02->SetMinimum(0);
   tmp02->SetMaximum(0.008658458);
   tmp02->SetStats(0);
   tmp02->SetLineStyle(0);
   tmp02->SetMarkerStyle(20);
   tmp02->GetXaxis()->SetTitle("m_{LQ} (GeV)");
   tmp02->GetXaxis()->SetLabelFont(42);
   tmp02->GetXaxis()->SetLabelOffset(0.01);
   tmp02->GetXaxis()->SetTitleSize(0.05);
   tmp02->GetXaxis()->SetTickLength(0.02);
   tmp02->GetXaxis()->SetTitleOffset(1.08);
   tmp02->GetXaxis()->SetTitleFont(42);
   tmp02->GetYaxis()->SetTitle("95% CL limit on #sigma/#sigma_{SM}");
   tmp02->GetYaxis()->SetLabelFont(42);
   tmp02->GetYaxis()->SetLabelOffset(0.007);
   tmp02->GetYaxis()->SetTitleSize(0.05);
   tmp02->GetYaxis()->SetTickLength(0.02);
   tmp02->GetYaxis()->SetTitleOffset(1.56);
   tmp02->GetYaxis()->SetTitleFont(42);
   tmp02->GetZaxis()->SetLabelFont(42);
   tmp02->GetZaxis()->SetLabelOffset(0.007);
   tmp02->GetZaxis()->SetTitleSize(0.05);
   tmp02->GetZaxis()->SetTickLength(0.02);
   tmp02->GetZaxis()->SetTitleFont(42);
   tmp02->Draw("AXIGSAME");
   
   Double_t Graph0_fx3001[6] = {
   1000,
   1200,
   1400,
   1600,
   1800,
   2000};
   Double_t Graph0_fy3001[6] = {
   0.003290176,
   0.002439499,
   0.001517296,
   0.001261711,
   0.001091957,
   0.001227379};
   Double_t Graph0_felx3001[6] = {
   1.58101e-322,
   4.242499e-316,
   0,
   1.630417e-322,
   0,
   4.05959e-316};
   Double_t Graph0_fely3001[6] = {
   0.001561549,
   0.001160191,
   0.0007512392,
   0.0006246949,
   0.0005449122,
   0.00063047};
   Double_t Graph0_fehx3001[6] = {
   1.58101e-322,
   4.243029e-316,
   4.242321e-316,
   5.582942e-322,
   0,
   0};
   Double_t Graph0_fehy3001[6] = {
   0.003203667,
   0.002404752,
   0.001685691,
   0.001402488,
   0.001241547,
   0.001507231};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(6,Graph0_fx3001,Graph0_fy3001,Graph0_felx3001,Graph0_fehx3001,Graph0_fely3001,Graph0_fehy3001);
   grae->SetName("Graph0");
   grae->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,900,2100);
   Graph_Graph3001->SetMinimum(0);
   Graph_Graph3001->SetMaximum(0.007088523);
   Graph_Graph3001->SetDirectory(0);
   Graph_Graph3001->SetStats(0);
   Graph_Graph3001->SetLineStyle(0);
   Graph_Graph3001->SetMarkerStyle(20);
   Graph_Graph3001->GetXaxis()->SetLabelFont(42);
   Graph_Graph3001->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph3001->GetXaxis()->SetTickLength(0.02);
   Graph_Graph3001->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph3001->GetXaxis()->SetTitleFont(42);
   Graph_Graph3001->GetYaxis()->SetLabelFont(42);
   Graph_Graph3001->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph3001->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph3001->GetYaxis()->SetTickLength(0.02);
   Graph_Graph3001->GetYaxis()->SetTitleOffset(1.56);
   Graph_Graph3001->GetYaxis()->SetTitleFont(42);
   Graph_Graph3001->GetZaxis()->SetLabelFont(42);
   Graph_Graph3001->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph3001->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph3001->GetZaxis()->SetTickLength(0.02);
   Graph_Graph3001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3001);
   
   grae->Draw("3");
   
   Double_t Graph1_fx3002[6] = {
   1000,
   1200,
   1400,
   1600,
   1800,
   2000};
   Double_t Graph1_fy3002[6] = {
   0.003290176,
   0.002439499,
   0.001517296,
   0.001261711,
   0.001091957,
   0.001227379};
   Double_t Graph1_felx3002[6] = {
   1.58101e-322,
   1.064145e-312,
   4.238648e-316,
   1.630417e-322,
   0,
   1.064145e-312};
   Double_t Graph1_fely3002[6] = {
   0.0009622434,
   0.0007160556,
   0.0004695245,
   0.0003898242,
   0.0003416344,
   0.0003983536};
   Double_t Graph1_fehx3002[6] = {
   1.58101e-322,
   1.064145e-312,
   4.446591e-323,
   2.420922e-322,
   0,
   4.446591e-323};
   Double_t Graph1_fehy3002[6] = {
   0.001419676,
   0.001062341,
   0.0007242488,
   0.0006035082,
   0.0005299276,
   0.0006372331};
   grae = new TGraphAsymmErrors(6,Graph1_fx3002,Graph1_fy3002,Graph1_felx3002,Graph1_fehx3002,Graph1_fely3002,Graph1_fehy3002);
   grae->SetName("Graph1");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3002 = new TH1F("Graph_Graph3002","Graph",100,900,2100);
   Graph_Graph3002->SetMinimum(0.0003543698);
   Graph_Graph3002->SetMaximum(0.005105805);
   Graph_Graph3002->SetDirectory(0);
   Graph_Graph3002->SetStats(0);
   Graph_Graph3002->SetLineStyle(0);
   Graph_Graph3002->SetMarkerStyle(20);
   Graph_Graph3002->GetXaxis()->SetLabelFont(42);
   Graph_Graph3002->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph3002->GetXaxis()->SetTickLength(0.02);
   Graph_Graph3002->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph3002->GetXaxis()->SetTitleFont(42);
   Graph_Graph3002->GetYaxis()->SetLabelFont(42);
   Graph_Graph3002->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph3002->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph3002->GetYaxis()->SetTickLength(0.02);
   Graph_Graph3002->GetYaxis()->SetTitleOffset(1.56);
   Graph_Graph3002->GetYaxis()->SetTitleFont(42);
   Graph_Graph3002->GetZaxis()->SetLabelFont(42);
   Graph_Graph3002->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph3002->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph3002->GetZaxis()->SetTickLength(0.02);
   Graph_Graph3002->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3002);
   
   grae->Draw("3");
   
   Double_t Graph2_fx1[6] = {
   1000,
   1200,
   1400,
   1600,
   1800,
   2000};
   Double_t Graph2_fy1[6] = {
   0.003290176,
   0.002439499,
   0.001517296,
   0.001261711,
   0.001091957,
   0.001227379};
   TGraph *graph = new TGraph(6,Graph2_fx1,Graph2_fy1);
   graph->SetName("Graph2");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,900,2100);
   Graph_Graph1->SetMinimum(0.0008721352);
   Graph_Graph1->SetMaximum(0.003509998);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);
   Graph_Graph1->SetLineStyle(0);
   Graph_Graph1->SetMarkerStyle(20);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetXaxis()->SetTickLength(0.02);
   Graph_Graph1->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetYaxis()->SetTickLength(0.02);
   Graph_Graph1->GetYaxis()->SetTitleOffset(1.56);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetZaxis()->SetTickLength(0.02);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   graph->Draw("l");
   
   TH1F *tmp0_copy3 = new TH1F("tmp0_copy3","Graph",100,1000,2000);
   tmp0_copy3->SetMinimum(0);
   tmp0_copy3->SetMaximum(0.007088523);
   tmp0_copy3->SetDirectory(0);
   tmp0_copy3->SetStats(0);
   tmp0_copy3->SetLineStyle(0);
   tmp0_copy3->SetMarkerStyle(20);
   tmp0_copy3->GetXaxis()->SetLabelFont(42);
   tmp0_copy3->GetXaxis()->SetTitleSize(0.05);
   tmp0_copy3->GetXaxis()->SetTickLength(0.02);
   tmp0_copy3->GetXaxis()->SetTitleOffset(1.08);
   tmp0_copy3->GetXaxis()->SetTitleFont(42);
   tmp0_copy3->GetYaxis()->SetLabelFont(42);
   tmp0_copy3->GetYaxis()->SetLabelOffset(0.007);
   tmp0_copy3->GetYaxis()->SetTitleSize(0.05);
   tmp0_copy3->GetYaxis()->SetTickLength(0.02);
   tmp0_copy3->GetYaxis()->SetTitleOffset(1.56);
   tmp0_copy3->GetYaxis()->SetTitleFont(42);
   tmp0_copy3->GetZaxis()->SetLabelFont(42);
   tmp0_copy3->GetZaxis()->SetLabelOffset(0.007);
   tmp0_copy3->GetZaxis()->SetTitleSize(0.05);
   tmp0_copy3->GetZaxis()->SetTickLength(0.02);
   tmp0_copy3->GetZaxis()->SetTitleFont(42);
   tmp0_copy3->Draw("sameaxis");
   
   TH1F *tmp0_copy4 = new TH1F("tmp0_copy4","Graph",100,1000,2000);
   tmp0_copy4->SetMinimum(0);
   tmp0_copy4->SetMaximum(0.007088523);
   tmp0_copy4->SetDirectory(0);
   tmp0_copy4->SetStats(0);
   tmp0_copy4->SetLineStyle(0);
   tmp0_copy4->SetMarkerStyle(20);
   tmp0_copy4->GetXaxis()->SetLabelFont(42);
   tmp0_copy4->GetXaxis()->SetTitleSize(0.05);
   tmp0_copy4->GetXaxis()->SetTickLength(0.02);
   tmp0_copy4->GetXaxis()->SetTitleOffset(1.08);
   tmp0_copy4->GetXaxis()->SetTitleFont(42);
   tmp0_copy4->GetYaxis()->SetLabelFont(42);
   tmp0_copy4->GetYaxis()->SetLabelOffset(0.007);
   tmp0_copy4->GetYaxis()->SetTitleSize(0.05);
   tmp0_copy4->GetYaxis()->SetTickLength(0.02);
   tmp0_copy4->GetYaxis()->SetTitleOffset(1.56);
   tmp0_copy4->GetYaxis()->SetTitleFont(42);
   tmp0_copy4->GetZaxis()->SetLabelFont(42);
   tmp0_copy4->GetZaxis()->SetLabelOffset(0.007);
   tmp0_copy4->GetZaxis()->SetTitleSize(0.05);
   tmp0_copy4->GetZaxis()->SetTickLength(0.02);
   tmp0_copy4->GetZaxis()->SetTitleFont(42);
   tmp0_copy4->Draw("sameaxig");
   
   TLegend *leg = new TLegend(0.495,0.825,0.945,0.925,NULL,"NBNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph2","Expected","L");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1","#pm1#sigma Expected","F");

   ci = TColor::GetColor("#00ff00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph0","#pm2#sigma Expected","F");

   ci = TColor::GetColor("#ffff00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   TPave *pave = new TPave(0.16,0.81,0.96,0.94,1,"brNDC");
   pave->SetFillColor(0);
   pave->Draw();
   
   leg = new TLegend(0.495,0.825,0.945,0.925,NULL,"NBNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("Graph2","Expected","L");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1","#pm1#sigma Expected","F");

   ci = TColor::GetColor("#00ff00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph0","#pm2#sigma Expected","F");

   ci = TColor::GetColor("#ffff00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   TLatex *   tex = new TLatex(0.196,0.9113,"CMS");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.048);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.196,0.8537,"Preliminary(12.9 fb^{-1})");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetTextSize(0.03648);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.96,0.952,"");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.16,0.952,"");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   pad->Modified();
   limit->cd();
   limit->Modified();
   limit->cd();
   limit->SetSelected(limit);
}
