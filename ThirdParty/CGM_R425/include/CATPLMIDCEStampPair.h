#ifndef CATPLMIDCEStampPair_H
#define CATPLMIDCEStampPair_H

#include "CATPLMIdentificationAccess.h"
#include "CATOmxPair.h"
#include "CATPLMID.h"
#include "CATPLMCEStamp.h"
#include "CATOmxDefaultCollecManager.h"

typedef CATOmxPair<CATPLMID,CATPLMCEStamp> CATPLMIDCEStampPair;

#include "CATOmxCollecManager.h"
template<> ExportedByCATPLMIdentificationAccess CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMIDCEStampPair>::manager();

#endif
