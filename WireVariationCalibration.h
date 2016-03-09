
#ifndef WireVariationCalibration_h
#define WireVariationCalibration_h

#include <TROOT.h>
#include <TTree.h>
#include <TFile.h>


class WireVariationCalibration {

   public:

      /// Constructors
      WireVariationCalibration(TTree *WireVariationCalibrationTree);
      WireVariationCalibration(TString WireVariationCalibrationTreeFile);


      // Variables
      Double_t dQdxMPVFromChannel(Short_t i_c);
      Double_t dQdxMPVFromWire(Short_t i_w);
      Double_t dQdxMPVGainCorrectedFromChannel(Short_t i_c);
      Double_t dQdxMPVGainCorrectedFromWire(Short_t i_w);


   private:

      Short_t fTTreeChannel;
      Short_t fTTreeWire;
      Double_t fTTreedQdxMPV;
      Double_t fTTreedQdxMPVGainCorrected;
      TTree *fTree;

};


#endif // #ifdef WireVariationCalibration_cxx




