#ifndef CATPLMLogLinkage_H 
#define CATPLMLogLinkage_H
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
* @level Private
* @usage U1
*/

#include "ExportedByCATPLMTos.h"
#include "CATComponentId.h"
#include "CATBoolean.h"
#include "CATOmxKeyString.h"

class CATPLMLogLinkage
{
public:
  inline static HRESULT ActivateLogLinkageFromMetaDescription(const CATOmxKeyString& iDescriptionID,CATComponentId& iRootOfTheDescription) {return S_OK;}
  inline static HRESULT RevokeLogLinkageFromMetaDescription(const CATOmxKeyString& iDescriptionID,CATComponentId& iRootOfTheDescription)  {return S_OK;}
};

#endif
