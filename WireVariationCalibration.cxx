
#define WireVariationCalibration_cxx
#include "WireVariationCalibration.h"



WireVariationCalibration::WireVariationCalibration(TString WireVariationCalibrationTreeFile) {

   TFile *f = new TFile(WireVariationCalibrationTreeFile);
   fTree = (TTree*)f->Get("WireVariationCalibTree");
   
   fTree->SetBranchAddress("Plane",&fTTreePlane);
   fTree->SetBranchAddress("Channel",&fTTreeChannel);
   fTree->SetBranchAddress("Wire",&fTTreeWire);
   fTree->SetBranchAddress("dQdxMPV",&fTTreedQdxMPV);

   // Get average values of dQ/dx MPV to determine the correction
   this->CalculateAveragedQdxMPV();

}

WireVariationCalibration::WireVariationCalibration(TTree *WireVariationCalibTree) {
  
   fTree = WireVariationCalibTree;
   fTree->SetBranchAddress("Plane",&fTTreePlane);
   fTree->SetBranchAddress("Channel",&fTTreeChannel);
   fTree->SetBranchAddress("Wire",&fTTreeWire);
   fTree->SetBranchAddress("dQdxMPV",&fTTreedQdxMPV);

   // Get average values of dQ/dx MPV to determine the correction
   this->CalculateAveragedQdxMPV();

}

void WireVariationCalibration::CalculateAveragedQdxMPV(){
   Long64_t nentries = fTree->GetEntries();
   Long64_t nbytes = 0, nb = 0;
   Double_t dQdxMPVSum[3] = {0};
   Double_t ndQdxMPV[3] = {0};
   // Loop over entries
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      nb = fTree->GetEntry(jentry);   nbytes += nb;
      dQdxMPVSum[fTTreePlane]+=fTTreedQdxMPV;
      ndQdxMPV[fTTreePlane]++;
   }
   fAveragedQdxMPV[0] = dQdxMPVSum[0]/ndQdxMPV[0];
   fAveragedQdxMPV[1] = dQdxMPVSum[1]/ndQdxMPV[1];
   fAveragedQdxMPV[2] = dQdxMPVSum[2]/ndQdxMPV[2];
}





// Get the wire-variaion correction from channel
Double_t WireVariationCalibration::CorrectionFromChannel(Short_t i_c) {
   Long64_t nentries = fTree->GetEntries();
   Long64_t nbytes = 0, nb = 0;
   // Loop over entries
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      nb = fTree->GetEntry(jentry);   nbytes += nb;
      if(fTTreedQdxMPV == 0)
         continue;
      if(i_c == fTTreeChannel && fTTreeChannel >= 0 && fTTreeChannel < 2400)
         return fAveragedQdxMPV[0]/fTTreedQdxMPV;
      if(i_c == fTTreeChannel && fTTreeChannel >= 2400 && fTTreeChannel < 3456)
         return fAveragedQdxMPV[1]/fTTreedQdxMPV;
      if(i_c == fTTreeChannel && fTTreeChannel >= 3456)
         return fAveragedQdxMPV[2]/fTTreedQdxMPV;
   }
   return -999999;
}


// Get the wire-variaion correction from wire
Double_t WireVariationCalibration::CorrectionFromWire(Short_t i_p, Short_t i_w) {
   Long64_t nentries = fTree->GetEntries();
   Long64_t nbytes = 0, nb = 0;
   // Loop over entries
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      nb = fTree->GetEntry(jentry);   nbytes += nb;
      if(fTTreedQdxMPV == 0)
         continue;
      if(i_w == fTTreeWire && i_p == fTTreePlane)
         return fAveragedQdxMPV[fTTreePlane]/fTTreedQdxMPV;
   }
   return -999999;
}




// Get dQdx MPV from channel
Double_t WireVariationCalibration::dQdxMPVFromChannel(Short_t i_c) {
   Long64_t nentries = fTree->GetEntries();
   Long64_t nbytes = 0, nb = 0;
   // Loop over entries
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      nb = fTree->GetEntry(jentry);   nbytes += nb;
      if(i_c == fTTreeChannel)
         return fTTreedQdxMPV;
   }
   return -999999;
}

// Get dQdx MPV from wire
Double_t WireVariationCalibration::dQdxMPVFromWire(Short_t i_p, Short_t i_w) {
   Long64_t nentries = fTree->GetEntries();
   Long64_t nbytes = 0, nb = 0;
   // Loop over entries
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      nb = fTree->GetEntry(jentry);   nbytes += nb;
      if(i_w == fTTreeWire && i_p == fTTreePlane)
         return fTTreedQdxMPV;
   }
   return -999999;
}





