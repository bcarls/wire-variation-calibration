R__LOAD_LIBRARY(WireVariationCalibration.cxx)

#include "WireVariationCalibration.h"

void WireVariationCalibrationExample(){

   // Give the location of the calibration tree file
   WireVariationCalibration *wire_var_calib = new WireVariationCalibration("WireVariationCalibTree.root");
   std::cout << "dQ/dx MPV From channel: " << wire_var_calib->dQdxMPVFromChannel(5875) << std::endl;
   std::cout << "dQ/dx MPV From wire: " << wire_var_calib->dQdxMPVFromWire(5875-2400-2400) << std::endl;
   std::cout << "Gain Corrected dQ/dx MPV From channel: " << wire_var_calib->dQdxMPVGainCorrectedFromChannel(5875) << std::endl;
   std::cout << "Gain Corrected dQ/dx MPV From wire: " << wire_var_calib->dQdxMPVGainCorrectedFromWire(5875-2400-2400) << std::endl;

   // Give a TTree to the WireVariationCalibration constructor
   // TFile *f = new TFile("WireVariationCalibTree.root");
   // WireVariationCalibrationTree = (TTree*)f->Get("WireVariationCalibTree");
   // WireVariationCalibration *wire_var_calib = new WireVariationCalibration(WireVariationCalibrationTree);
   // std::cout << "dQ/dx MPV From channel: " << wire_var_calib->dQdxMPVFromChannel(5875) << std::endl;
   // std::cout << "dQ/dx MPV From wire: " << wire_var_calib->dQdxMPVFromWire(5875-2400-2400) << std::endl;
   // std::cout << "Gain Corrected dQ/dx MPV From channel: " << wire_var_calib->dQdxMPVGainCorrectedFromChannel(5875) << std::endl;
   // std::cout << "Gain Corrected dQ/dx MPV From wire: " << wire_var_calib->dQdxMPVGainCorrectedFromWire(5875-2400-2400) << std::endl;

}




