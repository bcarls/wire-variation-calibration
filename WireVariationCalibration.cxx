
#define WireVariationCalibration_cxx
#include "WireVariationCalibration.h"



WireVariationCalibration::WireVariationCalibration(TString WireVariationCalibrationTreeFile) {

   TFile *f = new TFile(WireVariationCalibrationTreeFile);
   fTree = (TTree*)f->Get("WireVariationCalibTree");
   
   fTree->SetBranchAddress("Channel",&fTTreeChannel);
   fTree->SetBranchAddress("Wire",&fTTreeWire);
   fTree->SetBranchAddress("dQdxMPV",&fTTreedQdxMPV);
   fTree->SetBranchAddress("dQdxMPVGainCorrected",&fTTreedQdxMPVGainCorrected);

}

WireVariationCalibration::WireVariationCalibration(TTree *WireVariationCalibTree) {
  
   fTree = WireVariationCalibTree;
   fTree->SetBranchAddress("Channel",&fTTreeChannel);
   fTree->SetBranchAddress("Wire",&fTTreeWire);
   fTree->SetBranchAddress("dQdxMPV",&fTTreedQdxMPV);
   fTree->SetBranchAddress("dQdxMPVGainCorrected",&fTTreedQdxMPVGainCorrected);

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
   return -1;
}

// Get dQdx MPV from wire
Double_t WireVariationCalibration::dQdxMPVFromWire(Short_t i_w) {
   Long64_t nentries = fTree->GetEntries();
   Long64_t nbytes = 0, nb = 0;
   // Loop over entries
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      nb = fTree->GetEntry(jentry);   nbytes += nb;
      if(i_w == fTTreeWire)
         return fTTreedQdxMPV;
   }
   return -1;
}

// Get gain corrected dQdx MPV from channel
Double_t WireVariationCalibration::dQdxMPVGainCorrectedFromChannel(Short_t i_c) {
   Long64_t nentries = fTree->GetEntries();
   Long64_t nbytes = 0, nb = 0;
   // Loop over entries
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      nb = fTree->GetEntry(jentry);   nbytes += nb;
      if(i_c == fTTreeChannel)
         return fTTreedQdxMPVGainCorrected;
   }
   return -1;
}

// Get gain corrected Qdx MPV from wire
Double_t WireVariationCalibration::dQdxMPVGainCorrectedFromWire(Short_t i_w) {
   Long64_t nentries = fTree->GetEntries();
   Long64_t nbytes = 0, nb = 0;
   // Loop over entries
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      nb = fTree->GetEntry(jentry);   nbytes += nb;
      if(i_w == fTTreeWire)
         return fTTreedQdxMPVGainCorrected;
   }
   return -1;
}






