R__LOAD_LIBRARY(WireVariationCalibration.cxx)

#include "WireVariationCalibration.h"

void WireVariationCalibrationExample(){

   // Give the location of the calibration tree file
   WireVariationCalibration *wire_var_calib = new WireVariationCalibration("WireVariationCalibTree.root");

   // Give a TTree to the WireVariationCalibration constructor
   // TFile *f = new TFile("WireVariationCalibTree.root");
   // WireVariationCalibrationTree = (TTree*)f->Get("WireVariationCalibTree");
   // WireVariationCalibration *wire_var_calib = new WireVariationCalibration(WireVariationCalibrationTree);
   
   std::cout << "dQ/dx MPV From channel: " << wire_var_calib->dQdxMPVFromChannel(5875) << std::endl;
   std::cout << "dQ/dx MPV From wire: " << wire_var_calib->dQdxMPVFromWire(2,5875-2400-2400) << std::endl;
   std::cout << "Average dQ/dx MPV for Y Plane: " << wire_var_calib->AveragedQdxMPV(2) << std::endl;
   std::cout << "Correction Factor From channel: " << wire_var_calib->CorrectionFromChannel(5875) << std::endl;
   std::cout << "Correction Factor From wire: " << wire_var_calib->CorrectionFromWire(2,5875-2400-2400) << std::endl;

}




