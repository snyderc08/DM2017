void DMLimit_1D()
{
    //=========Macro generated from canvas: lim_expected_cmb/lim_expected_cmb
    //=========  (Tue Apr 11 07:13:16 2017) by ROOT version6.02/05
    TCanvas *lim_expected_cmb = new TCanvas("lim_expected_cmb", "lim_expected_cmb",0,0,600,600);
    gStyle->SetOptFit(1);
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    lim_expected_cmb->SetHighLightColor(2);
    lim_expected_cmb->Range(0,0,1,1);
    lim_expected_cmb->SetFillColor(0);
    lim_expected_cmb->SetBorderMode(0);
    lim_expected_cmb->SetBorderSize(2);
    lim_expected_cmb->SetLeftMargin(0.16);
    lim_expected_cmb->SetRightMargin(0.04);
    lim_expected_cmb->SetTopMargin(0.06);
    lim_expected_cmb->SetBottomMargin(0.12);
    lim_expected_cmb->SetFrameFillStyle(0);
    lim_expected_cmb->SetFrameBorderMode(0);
    
    // ------------>Primitives in pad: pad
    TPad *pad = new TPad("pad", "pad",0,0,1,1);
    pad->Draw();
    pad->cd();
    pad->Range(1080,-0.4214361,1830,3.090531);
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
    
    TH1F *tmp01 = new TH1F("tmp01","Graph",100,1200,1800);
    tmp01->SetMinimum(0);
    tmp01->SetMaximum(2.879813);
    tmp01->SetStats(0);
    tmp01->SetLineStyle(0);
    tmp01->SetMarkerStyle(20);
    tmp01->GetXaxis()->SetTitle("M_{LQ} (GeV)");
    tmp01->GetXaxis()->SetLabelFont(42);
    tmp01->GetXaxis()->SetLabelOffset(0.01);
    tmp01->GetXaxis()->SetTitleSize(0.05);
    tmp01->GetXaxis()->SetTickLength(0.02);
    tmp01->GetXaxis()->SetTitleOffset(1.08);
    tmp01->GetXaxis()->SetTitleFont(42);
    tmp01->GetYaxis()->SetTitle("#sigma (fb)");
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
    
//    TH1F *tmp02 = new TH1F("tmp02","Graph",100,1200,1800);
//    tmp02->SetMinimum(0);
//    tmp02->SetMaximum(2.879813);
//    tmp02->SetStats(0);
//    tmp02->SetLineStyle(0);
//    tmp02->SetMarkerStyle(20);
//    tmp02->GetXaxis()->SetTitle("m_{H} (GeV)");
//    tmp02->GetXaxis()->SetLabelFont(42);
//    tmp02->GetXaxis()->SetLabelOffset(0.01);
//    tmp02->GetXaxis()->SetTitleSize(0.05);
//    tmp02->GetXaxis()->SetTickLength(0.02);
//    tmp02->GetXaxis()->SetTitleOffset(1.08);
//    tmp02->GetXaxis()->SetTitleFont(42);
//    tmp02->GetYaxis()->SetTitle("95% CL limit on #sigma/#sigma_{SM}");
//    tmp02->GetYaxis()->SetLabelFont(42);
//    tmp02->GetYaxis()->SetLabelOffset(0.007);
//    tmp02->GetYaxis()->SetTitleSize(0.05);
//    tmp02->GetYaxis()->SetTickLength(0.02);
//    tmp02->GetYaxis()->SetTitleOffset(1.56);
//    tmp02->GetYaxis()->SetTitleFont(42);
//    tmp02->GetZaxis()->SetLabelFont(42);
//    tmp02->GetZaxis()->SetLabelOffset(0.007);
//    tmp02->GetZaxis()->SetTitleSize(0.05);
//    tmp02->GetZaxis()->SetTickLength(0.02);
//    tmp02->GetZaxis()->SetTitleFont(42);
//    tmp02->Draw("AXIGSAME");
    
    Double_t Graph0_fx3001[7] = {
        1200,
        1300,
        1400,
        1500,
        1600,
        1700,
        1800};
    Double_t Graph0_fy3001[7] = {
        1.074219,
        1.019531,
        0.8320312,
        0.7011719,
        0.6308594,
        0.4941406,
        0.4550781};
    Double_t Graph0_felx3001[7] = {
        4.567709e-316,
        4.567503e-316,
        4.792437e-322,
        4.386397e-316,
        1.58101e-322,
        6.95022e-310,
        0};
    Double_t Graph0_fely3001[7] = {
        0.5140305,
        0.4838791,
        0.4013901,
        0.3437386,
        0.3105011,
        0.2480354,
        0.2284279};
    Double_t Graph0_fehx3001[7] = {
        4.509909e-316,
        4.567636e-316,
        1.823102e-321,
        0,
        1.58101e-322,
        4.567635e-316,
        0};
    Double_t Graph0_fehy3001[7] = {
        1.085641,
        1.017641,
        0.8700014,
        0.7659448,
        0.6860919,
        0.5826749,
        0.5366136};
    TGraphAsymmErrors *grae = new TGraphAsymmErrors(7,Graph0_fx3001,Graph0_fy3001,Graph0_felx3001,Graph0_fehx3001,Graph0_fely3001,Graph0_fehy3001);
    grae->SetName("Graph0");
    grae->SetTitle("Graph");
    
    Int_t ci;      // for color index setting
    TColor *color; // for color definition with alpha
    ci = TColor::GetColor("#ffff00");
    grae->SetFillColor(ci);
    grae->SetMarkerStyle(20);
    
    TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,1140,1860);
    Graph_Graph3001->SetMinimum(0.03332927);
    Graph_Graph3001->SetMaximum(2.353181);
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
    
    Double_t Graph1_fx3002[7] = {
        1200,
        1300,
        1400,
        1500,
        1600,
        1700,
        1800};
    Double_t Graph1_fy3002[7] = {
        1.074219,
        1.019531,
        0.8320312,
        0.7011719,
        0.6308594,
        0.4941406,
        0.4550781};
    Double_t Graph1_felx3002[7] = {
        1.233625e-312,
        0,
        1.630417e-322,
        2.121996e-314,
        1.58101e-322,
        4.564172e-316,
        0};
    Double_t Graph1_fely3002[7] = {
        0.3192611,
        0.296754,
        0.2493008,
        0.2134939,
        0.1940632,
        0.155991,
        0.1436597};
    Double_t Graph1_fehx3002[7] = {
        1.233625e-312,
        0,
        1.630417e-322,
        2.121996e-314,
        1.58101e-322,
        4.564205e-316,
        0};
    Double_t Graph1_fehy3002[7] = {
        0.4752889,
        0.4510924,
        0.3813989,
        0.3325932,
        0.294212,
        0.2462082,
        0.2267451};
    grae = new TGraphAsymmErrors(7,Graph1_fx3002,Graph1_fy3002,Graph1_felx3002,Graph1_fehx3002,Graph1_fely3002,Graph1_fehy3002);
    grae->SetName("Graph1");
    grae->SetTitle("Graph");
    
    ci = TColor::GetColor("#00ff00");
    grae->SetFillColor(ci);
    grae->SetMarkerStyle(20);
    
    TH1F *Graph_Graph3002 = new TH1F("Graph_Graph3002","Graph",100,1140,1860);
    Graph_Graph3002->SetMinimum(0.1876095);
    Graph_Graph3002->SetMaximum(1.673317);
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
    
    Double_t Graph2_fx1[7] = {
        1200,
        1300,
        1400,
        1500,
        1600,
        1700,
        1800};
    Double_t Graph2_fy1[7] = {
        1.074219,
        1.019531,
        0.8320312,
        0.7011719,
        0.6308594,
        0.4941406,
        0.4550781};
    TGraph *graph = new TGraph(7,Graph2_fx1,Graph2_fy1);
    graph->SetName("Graph2");
    graph->SetTitle("Graph");
    graph->SetFillColor(1);
    
    ci = TColor::GetColor("#ff0000");
    graph->SetLineColor(ci);
    graph->SetLineWidth(2);
    graph->SetMarkerStyle(20);
    
    TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,1140,1860);
    Graph_Graph1->SetMinimum(0.3931641);
    Graph_Graph1->SetMaximum(1.136133);
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
    
    Double_t Graph3_fx2[7] = {
        1200,
        1300,
        1400,
        1500,
        1600,
        1700,
        1800};
    Double_t Graph3_fy2[7] = {
        1.072953,
        1.021046,
        0.8335641,
        0.7016249,
        0.6285988,
        0.4940294,
        0.4557142};
    graph = new TGraph(7,Graph3_fx2,Graph3_fy2);
    graph->SetName("Graph3");
    graph->SetTitle("Graph");
    graph->SetFillColor(1);
    graph->SetLineWidth(2);
    graph->SetMarkerStyle(20);
    
    TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Graph",100,1140,1860);
    Graph_Graph2->SetMinimum(0.3939903);
    Graph_Graph2->SetMaximum(1.134677);
    Graph_Graph2->SetDirectory(0);
    Graph_Graph2->SetStats(0);
    Graph_Graph2->SetLineStyle(0);
    Graph_Graph2->SetMarkerStyle(20);
    Graph_Graph2->GetXaxis()->SetLabelFont(42);
    Graph_Graph2->GetXaxis()->SetTitleSize(0.05);
    Graph_Graph2->GetXaxis()->SetTickLength(0.02);
    Graph_Graph2->GetXaxis()->SetTitleOffset(1.08);
    Graph_Graph2->GetXaxis()->SetTitleFont(42);
    Graph_Graph2->GetYaxis()->SetLabelFont(42);
    Graph_Graph2->GetYaxis()->SetLabelOffset(0.007);
    Graph_Graph2->GetYaxis()->SetTitleSize(0.05);
    Graph_Graph2->GetYaxis()->SetTickLength(0.02);
    Graph_Graph2->GetYaxis()->SetTitleOffset(1.56);
    Graph_Graph2->GetYaxis()->SetTitleFont(42);
    Graph_Graph2->GetZaxis()->SetLabelFont(42);
    Graph_Graph2->GetZaxis()->SetLabelOffset(0.007);
    Graph_Graph2->GetZaxis()->SetTitleSize(0.05);
    Graph_Graph2->GetZaxis()->SetTickLength(0.02);
    Graph_Graph2->GetZaxis()->SetTitleFont(42);
    graph->SetHistogram(Graph_Graph2);
    
    graph->Draw("pl");
    
    
    
    
    
    
    
    
    
    const int nTH=122;
    
    Double_t mTh[nTH] = {200.0,210.0,220.0,230.0,240.0,250.0,260.0,270.0,280.0,290.0,300.0,310.0,320.0,330.0,340.0,350.0,360.0,370.0,380.0,390.0,400.0,410.0,420.0,430.0,440.0,450.0,460.0,470.0,480.0,490.0,500.0,510.0,520.0,530.0,540.0,550.0,560.0,570.0,580.0,590.0,600.0,610.0,620.0,630.0,640.0,650.0,660.0,670.0,680.0,690.0,700.0,710.0,720.0,730.0,740.0,750.0,760.0,770.0,780.0,790.0,800.0,810.0,820.0,830.0,840.0,850.0,860.0,870.0,880.0,890.0,900.0,910.0,920.0,930.0,940.0,950.0,960.0,970.0,980.0,990.0,1000.0,1010.0,1020.0,1030.0,1040.0,1050.0,1060.0,1070.0,1080.0,1090.0,1100.0,1110.0,1120.0,1130.0,1140.0,1150.0,1160.0,1170.0,1180.0,1190.0,1200.0,1210.0,1220.0,1230.0,1240.0,1250.0,1260.0,1270.0,1280.0,1290.0,1300.0,1310.0,1320.0,1330.0,1340.0,1350.0,1360.0,1370.0,1380.0,1390.0,1400.0,1500};
    
    
    Double_t xsTh[nTH] = {6.06E+01,4.79E+01,3.82E+01,3.07E+01,2.49E+01,2.03E+01,1.67E+01,1.38E+01,1.15E+01,9.60E+00,8.04E+00,6.80E+00,5.75E+00,4.90E+00,4.18E+00,3.59E+00,3.09E+00,2.66E+00,2.31E+00,2.00E+00,1.74E+00,1.52E+00,1.33E+00,1.17E+00,1.03E+00,9.06E-01,8.00E-01,7.07E-01,6.27E-01,5.58E-01,4.96E-01,4.43E-01,3.95E-01,3.54E-01,3.16E-01,2.84E-01,2.55E-01,2.29E-01,2.07E-01,1.87E-01,1.69E-01,1.53E-01,1.38E-01,1.25E-01,1.14E-01,1.03E-01,9.39E-02,8.54E-02,7.78E-02,7.10E-02,6.48E-02,5.92E-02,5.42E-02,4.97E-02,4.55E-02,4.16E-02,3.82E-02,3.51E-02,3.22E-02,2.97E-02,2.73E-02,2.51E-02,2.31E-02,2.13E-02,1.97E-02,1.82E-02,1.68E-02,1.55E-02,1.44E-02,1.33E-02,1.23E-02,1.14E-02,1.06E-02,9.79E-03,9.09E-03,8.45E-03,7.84E-03,7.28E-03,6.77E-03,6.30E-03,5.86E-03,5.45E-03,5.08E-03,4.73E-03,4.41E-03,4.11E-03,3.83E-03,3.58E-03,3.34E-03,3.12E-03,2.91E-03,2.72E-03,2.54E-03,2.38E-03,2.22E-03,2.08E-03,1.95E-03,1.82E-03,1.71E-03,1.60E-03,1.50E-03,1.41E-03,1.32E-03,1.24E-03,1.16E-03,1.09E-03,1.02E-03,9.59E-04,9.01E-04,8.46E-04,7.95E-04,7.48E-04,7.03E-04,6.61E-04,6.22E-04,5.85E-04,5.50E-04,5.18E-04,4.87E-04,4.59E-04,4.33E-04,2.40E-04};
    
    Double_t xsTh_New[nTH]={0};
    
    for (int i=0; i < nTH; i++)
        xsTh_New[i]=xsTh[i]*1000*0.5;
    
    
    TGraph *xsTh_vs_m = new TGraph(nTH, mTh, xsTh_New);
    
    xsTh_vs_m->SetLineWidth(3);
    //    xsTh_vs_m->multi(1000);
    
    xsTh_vs_m->SetLineStyle(2);
    
    xsTh_vs_m->SetLineColor(kBlue);
    
    xsTh_vs_m->SetFillColor(kCyan-6);
    
    xsTh_vs_m->SetMarkerSize(0.00001);
    
    xsTh_vs_m->SetMarkerStyle(22);
    
    xsTh_vs_m->SetMarkerColor(kBlue);
    
    
    xsTh_vs_m->Draw("L");
    
    
    
    
    
    
    
    
    
    TH1F *tmp0_copy3 = new TH1F("tmp0_copy3","Graph",100,1200,1800);
    tmp0_copy3->SetMinimum(0.03332927);
    tmp0_copy3->SetMaximum(2.353181);
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
    
    TH1F *tmp0_copy4 = new TH1F("tmp0_copy4","Graph",100,1200,1800);
    tmp0_copy4->SetMinimum(0.03332927);
    tmp0_copy4->SetMaximum(2.353181);
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
    TLegendEntry *entry=leg->AddEntry("Graph3","Observed","LP");
    entry->SetLineColor(1);
    entry->SetLineStyle(1);
    entry->SetLineWidth(2);
    entry->SetMarkerColor(1);
    entry->SetMarkerStyle(20);
    entry->SetMarkerSize(1);
    entry->SetTextFont(42);
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
    entry=leg->AddEntry("Graph3","Observed","LP");
    entry->SetLineColor(1);
    entry->SetLineStyle(1);
    entry->SetLineWidth(2);
    entry->SetMarkerColor(1);
    entry->SetMarkerStyle(20);
    entry->SetMarkerSize(1);
    entry->SetTextFont(42);
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
    
    tex = new TLatex(0.196,0.8537,"Preliminary(35.9 fb^{-1})");
    tex->SetNDC();
    tex->SetTextAlign(13);
    tex->SetTextFont(52);
    tex->SetTextSize(0.03648);
    tex->SetLineWidth(2);
    tex->Draw();
    
    tex = new TLatex(0.596,0.7537,"M_{DM} = M_{X} = 600 GeV");
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
    lim_expected_cmb->cd();
    lim_expected_cmb->Modified();
    lim_expected_cmb->cd();
    lim_expected_cmb->SetSelected(lim_expected_cmb);
//    lim_expected_cmb->SaveAs("Limit1D_600.pdf");
}
