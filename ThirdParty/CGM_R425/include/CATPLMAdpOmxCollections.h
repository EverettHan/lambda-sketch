#ifndef CATPLMAdpOmxCollections_H
#define CATPLMAdpOmxCollections_H

#include "CATPLMImplAdapterBase.h"

#include "CATOmxKeyString.h"

#include "CATOmxOMap.h"
#include "CATOmxCollecManager.h"

class CATPLMAttrMasksAssociation;

namespace CATPLMAdpOmxCollections
{
  ExportedByCATPLMImplAdapterBase CATOmxCollecManager& mngrCATPLMAttrMasksAssociation();
};

typedef CATOmxOMap<CATOmxKeyString, CATPLMAttrMasksAssociation, CATOmxDefaultCollecManager<CATOmxKeyString>::manager, CATPLMAdpOmxCollections::mngrCATPLMAttrMasksAssociation> CATPLMMapKSToAttrMasksAssociation;

#endif

