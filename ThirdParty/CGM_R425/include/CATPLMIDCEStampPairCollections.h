#ifndef CATPLMIDCEStampPairCollections_H
#define CATPLMIDCEStampPairCollections_H

#include "CATPLMIdentificationAccess.h"

#include "CATPLMIDCEStampPair.h"

#include "CATOmxDefaultCollecManager.h"

#include "CATOmxArray.h"

typedef CATOmxArray<CATPLMIDCEStampPair,CATOmxDefaultCollecManager<CATPLMIDCEStampPair>::manager> CATPLMIDCEStampPairArray;

#include "CATOmxCollecManager.h"
template<> ExportedByCATPLMIdentificationAccess CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMIDCEStampPairArray>::manager();

typedef CATOmxArray<CATPLMIDCEStampPairArray,CATOmxDefaultCollecManager<CATPLMIDCEStampPairArray>::manager> CATPLMIDCEStampPairArrayArray;

#endif
