// COPYRIGHT Dassault Systemes 2010
//===================================================================
// CATPLMImportOption.h
//===================================================================
//
// Usage notes:
// class implemented as part of Project:
// Ability to import a 3DXML for review in V6 session using a specific provider called Psp.
// (Psp like Provider Session)
//
//===================================================================
// June 2010  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U3
*/

#ifndef CATPLMImportOption_H
#define CATPLMImportOption_H

#include "CATBaseUnknown.h"

#include "CATPLMIntegrationInterfaces.h"

class ExportedByCATPLMIntegrationInterfaces CATPLMImportOption{
public:
  enum ImportOption {ImportInSession, ImportInDatabase, ImportInSessionAndSave};
};

#endif
