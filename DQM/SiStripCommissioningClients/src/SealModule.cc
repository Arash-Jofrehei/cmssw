#include "FWCore/PluginManager/interface/ModuleDef.h"
#include "FWCore/Framework/interface/MakerMacros.h"

DEFINE_SEAL_MODULE();

#include "DQM/SiStripCommissioningClients/interface/SiStripCommissioningOfflineClient.h"
DEFINE_ANOTHER_FWK_MODULE(SiStripCommissioningOfflineClient);
  
