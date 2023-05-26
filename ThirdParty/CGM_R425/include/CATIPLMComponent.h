#ifndef CATIPLMComponent_H
#define CATIPLMComponent_H

// COPYRIGHT DASSAULT SYSTEMES 2006

/**
  * @CAA2Level L1
  * @CAA2Usage U3
*/

#include "CATPLMIdentificationAccess.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIdentificationAccess IID IID_CATIPLMComponent;
#else
extern "C" const IID IID_CATIPLMComponent;
#endif
/**
* Interface allowing to access to PLM component.
*
* <br><b>Role</b>: This class is used to access the base PLM entity in session.
*
*/
class CATIAdpPLMIdentificator;
class CATIAdpType;
class ExportedByCATPLMIdentificationAccess CATIPLMComponent  : public CATBaseUnknown
{
public:
  CATDeclareInterface;
 
  /**
  * Returns the identifier of the PLMComponent.
  * 
  * @param oAdpID [out, CATBaseUnknown#Release]
  *   The returned identifier (to be released)
  *   The validity can be checked using @href CATIAdpPLMIdentificator#IsValidForRemoteUsage
  * @return
  * <dt> <code>S_OK</code>     <dd> Success
  * <dt> <code>E_FAIL</code>   <dd> Failure
  *
  */
  virtual HRESULT GetAdpID(CATIAdpPLMIdentificator *& oAdpID) = 0;
 
  /**
  * Returns the PLM Class type of the PLMComponent.
  * 
  * @param oAdpType [out, CATBaseUnknown#Release]
  *   The returned type (to be released)
  * @return
  * <dt> <code>S_OK</code>     <dd> Success
  * <dt> <code>E_FAIL</code>   <dd> Failure
  *
  */
  virtual HRESULT GetAdpType(CATIAdpType *& oAdpType) = 0;
};


CATDeclareHandler( CATIPLMComponent, CATBaseUnknown );

#endif
