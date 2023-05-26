/* -*-c++-*- */
#ifndef _CATPLMIDElementaryInfos_H
#define _CATPLMIDElementaryInfos_H
/* -*-c++-*- */
/**
 * @level Private
 * @usage U1       
 */

#include "IUnknown.h"
#include "CATPLMIdentificationAccess.h"
#include "CATPLMRepositoryName.h"
#include "CATPLMID_Any.h"
#include "CATOmxKeyString.h"
#include "CATOmxDefaultCollecManager.h"

struct CATPLMIDElementaryInfos 
{ 
  CATPLMRepositoryName RepositoryName;
  CATPLMID_Any PhysicalId; 
  CATPLMID_Any LogicalId; 
  CATPLMID_Any MajorId; 
  CATOmxKeyString Custo;
  CATOmxKeyString Modeler;
  CATOmxKeyString TypeOrCoreType;

	ExportedByCATPLMIdentificationAccess CATPLMIDElementaryInfos();
};

template<> ExportedByCATPLMIdentificationAccess CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMIDElementaryInfos>::manager();

#endif
