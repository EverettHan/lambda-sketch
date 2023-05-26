#ifndef CATPLMIDToCEStampMap_H
#define CATPLMIDToCEStampMap_H

#include "CATPLMIdentificationAccess.h"
#include "CATPLMID.h"
#include "CATPLMCEStamp.h"
#include "CATOmxOMap.h"

typedef CATOmxOMap<CATPLMID,CATPLMCEStamp> CATPLMIDToCEStampMap;
typedef CATPLMIDToCEStampMap::MapIteratorType CATPLMIDToCEStampMapIterator;

#endif
