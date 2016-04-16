#include "SimTracker/SiPhase2Digitizer/interface/Phase2TrackerDigiCommon.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

namespace phase2trackerdigi {
    int getOTLayerNumber(unsigned int& detid, const TrackerTopology* topo) {
    int layer = -1;
    const DetId theDetId(detid);
    
    if (theDetId.det() == DetId::Tracker) {
      if (theDetId.subdetId() == StripSubdetector::TOB) {
	layer = topo->tobLayer(detid);
      } else if (theDetId.subdetId() == StripSubdetector::TID) {
	layer = 100 * topo->tidSide(detid)  + topo->tidWheel(detid);
      } else {
	edm::LogInfo("Phase2TrackerDigiCommon") << ">>> Invalid subdetId()  " ;
      }
    }
    return layer;
  }
  int getPixelLayerNumber(unsigned int& detid, const TrackerTopology* topo) {
    int layer = -1;
    const DetId theDetId(detid);
    
    if (theDetId.det() == DetId::Tracker) {
      if (theDetId.subdetId() == PixelSubdetector::PixelBarrel) {
	layer = topo->pxbLayer(detid);
      } else if (theDetId.subdetId() == PixelSubdetector::PixelEndcap) {
	layer = 100 * topo->pxfSide(detid)  + topo->pxfDisk(detid);
      } else {
	edm::LogInfo("Phase2TrackerDigiCommon") << ">>> Invalid subdetId()  " ;
      }
    }
    return layer;
  }

}    
