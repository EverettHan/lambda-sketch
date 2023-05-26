#ifndef CATOmbSDSyncStatus_H
#define CATOmbSDSyncStatus_H

#include "CATOmbLoadableDataUniqueKey.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxCollecManager.h"
#include "AD0XXBAS.h"


/**
* OMBSDS_Unknown: RepRef is not in valid state to provide status of a StreamDescriptor
* OMBSDS_Missing: RepRef is in a valid and required SD is missing
* OMBSDS_Unsynchronized: RepRef is in a valid and required SD is prevent and unavalaible to be loaded by SwitchEngine
* OMBSDS_Synchronized: RepRef is in a valid and required SD is present and avalaible to be loaded by SwitchEngine
*/
enum CATOmbSDState { OMBSDS_Unknown = 0, OMBSDS_Missing = 1, OMBSDS_Unsynchronized = 2, OMBSDS_Synchronized = 3 };

class ExportedByAD0XXBAS CATOmbSDSyncStatus
{
public:
  CATOmbSDSyncStatus(const CATOmbLoadableDataUniqueKey& iKey);
  ~CATOmbSDSyncStatus(){};
  CATOmbLoadableDataUniqueKey _sdKey;
  // if sdKey is the globalMasterSD key, masterkey = sdKey
  CATOmbLoadableDataUniqueKey _masterKey;
  CATOmbSDState _sdState;
  //should not be used
//private:
  CATOmbSDSyncStatus();//FIXME TO PUT AS PRIVATE
};

template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmbSDSyncStatus>::manager();

#endif // CATOmbSDSyncStatus_H
