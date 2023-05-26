#ifndef CATTosLogError_H
#define CATTosLogError_H

#include "CATPLMIDTextStreamExtensions.h"
#include "CATOmxLogError.h"
#include "ExportedByCATPLMIdentification.h"

class CATProxySpace;

/**
* outputs a CATProxySpace for debugging purpose
*/
ExportedByCATPLMIdentification CATOmxTextStream& operator<<(CATOmxTextStream& out, const CATProxySpace& space);

#endif
