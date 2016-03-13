
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
      Double_t dQdxMPVFromWire(Short_t i_p, Short_t i_w);
      Double_t AveragedQdxMPV(Short_t i_p){return fAveragedQdxMPV[i_p];}

      // Get correction
      Double_t CorrectionFromChannel(Short_t i_c);
      Double_t CorrectionFromWire(Short_t i_p, Short_t i_w);

      void CalculateAveragedQdxMPV();

   private:

      Short_t fTTreePlane;
      Short_t fTTreeChannel;
      Short_t fTTreeWire;
      Double_t fTTreedQdxMPV;
      Double_t fAveragedQdxMPV[3];
      TTree *fTree;

};


#endif // #ifdef WireVariationCalibration_cxx




