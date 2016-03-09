# wire-variation-calibration


This is a simple set of macros for accessing the wire-by-wire calibration from a ROOT file containing them. It is currently configured to use ROOT 6. 

## To setup to run on OSX 

The easy way to get going is to install ROOT6 via [Homebrew](http://brew.sh/)
and clone the repository using the following steps:

```bash
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
brew install homebrew/science/root6
git clone https://github.com/bcarls/wire-variation-calibration.git
cd wire-variation-calibration
source setup_homebrew.sh
```

## To setup to run on the gpvm nodes

```bash
git clone https://github.com/bcarls/anatreeloop.git
cd wire-variation-calibration
source setup_gpvm.sh
```

## The script and how to run it

The WireVariationCalibrationExample.C script shows how to access the calibrations. It uses the ROOT file WireVariationCalibTree.root. 

```bash
root -l WireVariationCalibrationExample.C
```

It ought to produce this output:

```bash
bcarls@mac-120200 ~/wire-variation-calibration $ root -l WireVariationCalibrationExample.C
root [0]
Processing WireVariationCalibrationExample.C...
dQ/dx MPV From channel: 325.72
dQ/dx MPV From wire: 325.72
Gain Corrected dQ/dx MPV From channel: 1793.91
Gain Corrected dQ/dx MPV From wire: 1793.91
root [1]
```






