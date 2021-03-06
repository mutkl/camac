{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Oct 18 17:17:26 2011) by ROOT version5.24/00
   TCanvas *c1 = new TCanvas("c1", "c1",15,49,946,719);
   c1->Range(188.0533,-16.95105,237.7387,178.4345);
   c1->SetBorderSize(2);
   c1->SetFrameFillColor(0);
   
   TH1 *Sr 90 Source with Scintillator = new TH1F("Sr 90 Source with Scintillator","Acquisition Results (Normalized by Area)",2048,0,2047);
   Sr 90 Source with Scintillator->SetBinContent(193,1);
   Sr 90 Source with Scintillator->SetBinContent(195,2);
   Sr 90 Source with Scintillator->SetBinContent(196,4);
   Sr 90 Source with Scintillator->SetBinContent(197,6);
   Sr 90 Source with Scintillator->SetBinContent(198,18);
   Sr 90 Source with Scintillator->SetBinContent(199,21);
   Sr 90 Source with Scintillator->SetBinContent(200,37);
   Sr 90 Source with Scintillator->SetBinContent(201,71);
   Sr 90 Source with Scintillator->SetBinContent(202,88);
   Sr 90 Source with Scintillator->SetBinContent(203,84);
   Sr 90 Source with Scintillator->SetBinContent(204,106);
   Sr 90 Source with Scintillator->SetBinContent(205,90);
   Sr 90 Source with Scintillator->SetBinContent(206,90);
   Sr 90 Source with Scintillator->SetBinContent(207,84);
   Sr 90 Source with Scintillator->SetBinContent(208,85);
   Sr 90 Source with Scintillator->SetBinContent(209,54);
   Sr 90 Source with Scintillator->SetBinContent(210,47);
   Sr 90 Source with Scintillator->SetBinContent(211,28);
   Sr 90 Source with Scintillator->SetBinContent(212,25);
   Sr 90 Source with Scintillator->SetBinContent(213,21);
   Sr 90 Source with Scintillator->SetBinContent(214,23);
   Sr 90 Source with Scintillator->SetBinContent(215,18);
   Sr 90 Source with Scintillator->SetBinContent(216,9);
   Sr 90 Source with Scintillator->SetBinContent(217,18);
   Sr 90 Source with Scintillator->SetBinContent(218,7);
   Sr 90 Source with Scintillator->SetBinContent(219,3);
   Sr 90 Source with Scintillator->SetBinContent(220,4);
   Sr 90 Source with Scintillator->SetBinContent(221,7);
   Sr 90 Source with Scintillator->SetBinContent(222,5);
   Sr 90 Source with Scintillator->SetBinContent(223,4);
   Sr 90 Source with Scintillator->SetBinContent(224,5);
   Sr 90 Source with Scintillator->SetBinContent(225,2);
   Sr 90 Source with Scintillator->SetBinContent(227,4);
   Sr 90 Source with Scintillator->SetBinContent(228,2);
   Sr 90 Source with Scintillator->SetBinContent(231,2);
   Sr 90 Source with Scintillator->SetBinContent(232,1);
   Sr 90 Source with Scintillator->SetBinContent(233,1);
   Sr 90 Source with Scintillator->SetBinContent(234,1);
   Sr 90 Source with Scintillator->SetBinContent(236,1);
   Sr 90 Source with Scintillator->SetBinContent(242,1);
   Sr 90 Source with Scintillator->SetBinContent(248,1);
   Sr 90 Source with Scintillator->SetBinContent(251,1);
   Sr 90 Source with Scintillator->SetBinContent(269,1);
   Sr 90 Source with Scintillator->SetBinContent(274,1);
   Sr 90 Source with Scintillator->SetBinContent(346,1);
   Sr 90 Source with Scintillator->SetMinimum(3.183025);
   Sr 90 Source with Scintillator->SetMaximum(159.1512);
   Sr 90 Source with Scintillator->SetEntries(1085);
   
   TPaveStats *ptstats = new TPaveStats(0.6963907,0.6763425,0.9012739,0.8998549,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(2);
   ptstats->SetFillColor(19);
   ptstats->SetLineColor(4);
   ptstats->SetLineWidth(3);
   ptstats->SetTextAlign(12);
   TText *text = ptstats->AddText("Sr 90 Source with Scintillator");
   text->SetTextSize(0.05140784);
   text = ptstats->AddText("Entries = 1085   ");
   text = ptstats->AddText("Mean  =  205.9");
   text = ptstats->AddText("RMS   =  5.546");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   Sr 90 Source with Scintillator->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(Sr 90 Source with Scintillator->GetListOfFunctions());
   Sr 90 Source with Scintillator->SetFillColor(4);
   Sr 90 Source with Scintillator->SetFillStyle(3002);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#0000ff");
   Sr 90 Source with Scintillator->SetLineColor(ci);
   Sr 90 Source with Scintillator->SetLineWidth(2);
   Sr 90 Source with Scintillator->GetXaxis()->SetTitle("ADC Values (1 count = ^{1}/_{4} pC)");
   Sr 90 Source with Scintillator->GetXaxis()->SetRange(194,233);
   Sr 90 Source with Scintillator->GetXaxis()->CenterTitle(true);
   Sr 90 Source with Scintillator->GetYaxis()->SetTitle("Counts ");
   Sr 90 Source with Scintillator->GetYaxis()->CenterTitle(true);
   Sr 90 Source with Scintillator->GetYaxis()->SetLabelSize(0.03);
   Sr 90 Source with Scintillator->Draw("");
   
   TPaveText *pt = new TPaveText(0.1518047,0.9172714,0.8343949,0.9724238,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(2);
   pt->SetFillColor(19);
   text = pt->AddText("Acquisition Results (Normalized by Area)");
   pt->Draw();
   
   TH1 *Sr 90 Source = new TH1F("Sr 90 Source","Acquisition Results",2048,0,2047);
   Sr 90 Source->SetBinContent(194,2.026144);
   Sr 90 Source->SetBinContent(195,5.06536);
   Sr 90 Source->SetBinContent(196,3.039216);
   Sr 90 Source->SetBinContent(197,9.117647);
   Sr 90 Source->SetBinContent(198,12.15686);
   Sr 90 Source->SetBinContent(199,29.37909);
   Sr 90 Source->SetBinContent(200,51.66667);
   Sr 90 Source->SetBinContent(201,70.91503);
   Sr 90 Source->SetBinContent(202,90.1634);
   Sr 90 Source->SetBinContent(203,109.4118);
   Sr 90 Source->SetBinContent(204,96.24183);
   Sr 90 Source->SetBinContent(205,118.5294);
   Sr 90 Source->SetBinContent(206,94.21568);
   Sr 90 Source->SetBinContent(207,81.04575);
   Sr 90 Source->SetBinContent(208,52.67974);
   Sr 90 Source->SetBinContent(209,34.44444);
   Sr 90 Source->SetBinContent(210,41.53595);
   Sr 90 Source->SetBinContent(211,24.31373);
   Sr 90 Source->SetBinContent(212,21.27451);
   Sr 90 Source->SetBinContent(213,13.16993);
   Sr 90 Source->SetBinContent(214,9.117647);
   Sr 90 Source->SetBinContent(215,11.14379);
   Sr 90 Source->SetBinContent(216,16.20915);
   Sr 90 Source->SetBinContent(217,10.13072);
   Sr 90 Source->SetBinContent(218,9.117647);
   Sr 90 Source->SetBinContent(219,6.078432);
   Sr 90 Source->SetBinContent(220,8.104575);
   Sr 90 Source->SetBinContent(221,7.091503);
   Sr 90 Source->SetBinContent(222,7.091503);
   Sr 90 Source->SetBinContent(223,4.052288);
   Sr 90 Source->SetBinContent(224,6.078432);
   Sr 90 Source->SetBinContent(225,4.052288);
   Sr 90 Source->SetBinContent(226,2.026144);
   Sr 90 Source->SetBinContent(227,3.039216);
   Sr 90 Source->SetBinContent(228,3.039216);
   Sr 90 Source->SetBinContent(229,4.052288);
   Sr 90 Source->SetBinContent(230,1.013072);
   Sr 90 Source->SetBinContent(231,2.026144);
   Sr 90 Source->SetBinContent(234,1.013072);
   Sr 90 Source->SetBinContent(235,2.026144);
   Sr 90 Source->SetBinContent(238,1.013072);
   Sr 90 Source->SetBinContent(240,1.013072);
   Sr 90 Source->SetBinContent(243,1.013072);
   Sr 90 Source->SetBinContent(251,1.013072);
   Sr 90 Source->SetBinContent(257,1.013072);
   Sr 90 Source->SetBinContent(263,1.013072);
   Sr 90 Source->SetBinContent(275,1.013072);
   Sr 90 Source->SetBinContent(285,1.013072);
   Sr 90 Source->SetEntries(1071);
   
   ptstats = new TPaveStats(0.6963907,0.4847605,0.9023355,0.6734398,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(2);
   ptstats->SetFillColor(19);
   ptstats->SetLineColor(2);
   ptstats->SetLineWidth(3);
   ptstats->SetTextAlign(12);
   text = ptstats->AddText("Sr 90 Source");
   text->SetTextSize(0.04339623);
   text = ptstats->AddText("Entries = 1071   ");
   text = ptstats->AddText("Mean  =  205.6");
   text = ptstats->AddText("RMS   =    7.6");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   Sr 90 Source->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(Sr 90 Source->GetListOfFunctions());
   Sr 90 Source->SetFillColor(2);
   Sr 90 Source->SetFillStyle(3003);

   ci = TColor::GetColor("#ff0000");
   Sr 90 Source->SetLineColor(ci);
   Sr 90 Source->SetLineWidth(2);
   Sr 90 Source->Draw("sames");
   
   TH1 *No source = new TH1F("No source","ADC_3",2048,0,2047);
   No source->SetBinContent(193,2.471526);
   No source->SetBinContent(194,2.471526);
   No source->SetBinContent(195,1.235763);
   No source->SetBinContent(196,4.943052);
   No source->SetBinContent(197,12.35763);
   No source->SetBinContent(198,21.00797);
   No source->SetBinContent(199,34.60137);
   No source->SetBinContent(200,56.8451);
   No source->SetBinContent(201,79.08884);
   No source->SetBinContent(202,100.0968);
   No source->SetBinContent(203,134.6982);
   No source->SetBinContent(204,122.3405);
   No source->SetBinContent(205,117.3975);
   No source->SetBinContent(206,121.1048);
   No source->SetBinContent(207,98.86105);
   No source->SetBinContent(208,53.13781);
   No source->SetBinContent(209,45.72324);
   No source->SetBinContent(210,28.42255);
   No source->SetBinContent(211,11.12187);
   No source->SetBinContent(212,7.414578);
   No source->SetBinContent(214,3.707289);
   No source->SetBinContent(215,1.235763);
   No source->SetBinContent(216,3.707289);
   No source->SetBinContent(218,1.235763);
   No source->SetBinContent(221,1.235763);
   No source->SetBinContent(222,2.471526);
   No source->SetBinContent(223,2.471526);
   No source->SetBinContent(225,1.235763);
   No source->SetBinContent(226,1.235763);
   No source->SetBinContent(227,1.235763);
   No source->SetBinContent(228,1.235763);
   No source->SetBinContent(231,1.235763);
   No source->SetBinContent(243,1.235763);
   No source->SetBinContent(244,2.471526);
   No source->SetBinContent(250,1.235763);
   No source->SetBinContent(261,1.235763);
   No source->SetBinContent(283,1.235763);
   No source->SetEntries(878);
   
   ptstats = new TPaveStats(0.6963907,0.2859216,0.9044586,0.478955,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(2);
   ptstats->SetFillColor(19);
   ptstats->SetLineWidth(3);
   ptstats->SetTextAlign(12);
   text = ptstats->AddText("No source");
   text->SetTextSize(0.04439768);
   text = ptstats->AddText("Entries = 878    ");
   text = ptstats->AddText("Mean  =  203.8");
   text = ptstats->AddText("RMS   =   5.85");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   No source->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(No source->GetListOfFunctions());
   No source->SetFillColor(1);
   No source->SetFillStyle(3005);
   No source->SetLineWidth(2);
   No source->Draw("sames");
   
   TLegend *leg = new TLegend(1.150122e-311,7.405765e-312,4.328871e-312,3.310313e-312,NULL,"brNDC");
   leg->SetTextAlign(11);
   leg->SetTextFont(62);
   leg->SetTextSize(0.05);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(19);
   leg->SetFillStyle(1001);
   leg->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
