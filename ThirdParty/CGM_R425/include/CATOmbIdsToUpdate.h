#ifndef CATOmbIdsToUpdate_H
#define CATOmbIdsToUpdate_H

#include "CATPLMID_Simple.h"
#include "CATPLMCEStamp.h"
#include "CATOmxArray.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATObjectModelerBase.h"
#include "CATPLMPathId.h"
#include "CATOmxOHMap.h"

struct CATOmbIdsToUpdate
{
  CATPLMID_Simple id;                              //new plmid of the object
  CATPLMCEStamp cestamp;                           //new cestamp of the object
  CATOmxOHMap<unsigned int, CATPLMPathId> pathids;  //mapping IDRel => new pathid of the SRs of the object
};

template<>
ExportedByCATObjectModelerBase CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmbIdsToUpdate>::manager();

#endif
