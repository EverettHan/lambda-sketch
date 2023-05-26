#ifndef CATITosVDescriptionServices_H
#define CATITosVDescriptionServices_H

// COPYRIGHT DASSAULT SYSTEMES 2012

/**
 * @level Private
 * @usage U3
 */

#include "CATPLMIdentificationAccess.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"
#include "CATBoolean.h"

class CATComponentId;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIdentificationAccess IID IID_CATITosVDescriptionServices;
#else
extern "C" const IID IID_CATITosVDescriptionServices ;
#endif

class CATOmxAny;
class CATUnicodeString;

/**
* Bridge from CATPLMIdentifiation to CATPLMSpecsModeler
* <br><b>Role</b>Provides access to services implemented in CATPLMSpecsModeler framework
* This API must be used by CATPLMIdentification framework only.
*/
class ExportedByCATPLMIdentificationAccess CATITosVDescriptionServices : public CATBaseUnknown
{
	CATDeclareInterface;

public:

  /**
  * Check if the V_Description is usable for opening Fastener MCX
  */
  virtual CATBoolean IsVDescriptionCompatibleWithFastenerMCXOptimization(const CATOmxAny& iCmpUS, CATUnicodeString iVDescription) = 0;
};



#endif
