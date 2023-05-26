#ifndef CATUFOProtectedLogAccessForReroute_H
#define CATUFOProtectedLogAccessForReroute_H

// SpecialAPI
#include "CATSysBoolean.h"
// SystemTS
#include "IUnknown.h"
// ObjectModelerCollection
#include "CATOmxIter.h"
// CATPLMIdentification
#include "ExportedByCATPLMIdentification.h"

class CATProxySpace;
class CATUFOUserActionInformation;

/**
* Get impacted occurrences for current operation
*/
ExportedByCATPLMIdentification HRESULT GetImpactedComponentsForCurrentOperation(CATProxySpace & iSpace, CATOmxIter<CATUFOUserActionInformation> & oResult, CATBoolean iMinorSensitivity);


#endif
