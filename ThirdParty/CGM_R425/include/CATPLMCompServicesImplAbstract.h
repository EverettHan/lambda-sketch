// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATPLMCompServicesImplAbstract.h
// Header definition of CATPLMCompServicesImplAbstract
//
//===================================================================
//
// Usage notes:
//
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATPLMCompServicesImplAbstract_H
#define CATPLMCompServicesImplAbstract_H

//-----------------------------------------------------------------------

/**
* Only PC² Private usage allowed
*/
#include "CATPLMComponentInterfaces.h"
#include "CATListOfCATUnicodeString.h"
#include "CATPLMComponentServicesProtected.h"

class CATIPLMComponent;
class CATOmxKeyValueBlock;

class CATPLMCompServicesImplAbstract
{
  friend class CATPLMComponentServicesProtected;
protected:
  virtual HRESULT GetCompletionLevel(CATIPLMComponent* iPLMComponent, CATPLMComponentCompletionLevel & oCompletionLevel) = 0;

  virtual HRESULT GetAttributesForDisplay(CATIPLMComponent* iPLMComponent, CATListOfCATUnicodeString & iAttributeNameList, CATListOfCATUnicodeString & oAttributeValueList) = 0;
};

//-----------------------------------------------------------------------

#endif
