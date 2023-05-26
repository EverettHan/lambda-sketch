// COPYRIGHT Dassault Systemes 2008
#ifndef CATIPLMModelerEventFriendServices_H
#define CATIPLMModelerEventFriendServices_H

/**
* @level Private
* @usage U3
*/

#include "CATBaseUnknown.h"
#include "CATPLMModelerBaseInterfaces.h"
#include "CATPLMModelerEventDef.h"

class CATIAdpType;
class CATIAdpExtType;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerBaseInterfaces IID IID_CATIPLMModelerEventFriendServices;
#else
extern "C" const IID IID_CATIPLMModelerEventFriendServices ;
#endif
 
/**
* @nodoc
*/

class ExportedByCATPLMModelerBaseInterfaces CATIPLMModelerEventFriendServices : public CATBaseUnknown
{
  CATDeclareInterface;

public : 

   /** 
  * <br><b>Role</b>: Log a friend event to be sent at end of transaction.
  * @param iExtensionType [in]
  *   the friend extension type
  * @param iContext [in]
  *   the context of modification.
  * @param iModifiedObject [in]
  *   the modified entity
  * @return
  *   <code>S_OK</code> if everything ran OK.
  */
  virtual HRESULT LogPLMEventForExtension(CATIAdpExtType* iExtensionType, CATBaseUnknown* iContext, CATBaseUnknown* iModifiedObject) = 0;

	/** 
  * <br><b>Role</b>: Log a friend event to be sent at end of transaction.
  * @param iConnectionType [in]
  *   the friend connection type
  * @param iContext [in]
  *   the context of modification.
  * @param iModifiedObject [in]
  *   the modified entity
  * @return
  *   <code>S_OK</code> if everything ran OK.
  */
  virtual HRESULT LogPLMEventForConnection(CATIAdpType* iConnectionType, CATBaseUnknown* iContext, CATBaseUnknown* iModifiedObject) = 0;

};

CATDeclareHandler(CATIPLMModelerEventFriendServices, CATBaseUnknown);

#endif
