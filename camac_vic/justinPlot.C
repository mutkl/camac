{

  Double_t measured[5] = {702.232, 752.369, 854.884, 1007.31, 1054.04};
  Double_t predicted[5] = {704.846, 753.6201, 854.884, 1005.96, 1053.25};
  Double_t ledVolts[5] = {450, 500, 600, 750, 800};

  Double_t wrongness[5];

  for (Int_t i=0; i<5; ++i){
    wrongness[i] = 100.*(predicted[i] - measured[i])/(measured[i]);
  }

  TGraph gMeasured(5, ledVolts, measured);
  TGraph gPred(5, ledVolts, predicted);
  TGraph gWrongness(5, ledVolts, wrongness);

  TCanvas cResults("cResults","",0,0,1000,700);
  cResults.Divide(2,1);
  cResults.cd(1);

  gMeasured.GetXaxis()->SetTitle("LED voltage (pulser box units)");
  gMeasured.GetYaxis()->SetTitle("LED peak posn. on 8-inch PMT (ADC)");

  gMeasured.Draw("a*L");
  gPred.SetLineColor(2);
  gPred.SetMarkerColor(2);
  gPred.SetTitle("");
  gPred.Draw("L*same");

  TLegend leg;
  leg.SetFillStyle(0);
  leg.SetBorderSize(0);
  leg.AddEntry(&gMeasured, "Measured LED peak", "l");
  leg.AddEntry(&gPred, "Predicted LED peak", "l");

  cResults.cd(2);
  gWrongness.GetXaxis()->SetTitle("LED voltage (pulser box units)");
  gWrongness.GetYaxis()->SetTitle("Accuracy of peak prediction (%)");
  gWrongness.GetYaxis()->SetRangeUser(-5,5);
  gWrongness.SetTitle("");
  gWrongness.Draw("a*L");

}
