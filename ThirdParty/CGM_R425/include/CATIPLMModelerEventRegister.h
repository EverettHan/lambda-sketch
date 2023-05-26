// COPYRIGHT Dassault Systemes 2007
//===================================================================
// CATIPLMModelerEventRegister.h
// Define the CATIPLMModelerEventRegister interface
//===================================================================
//  Mar 2007  Creation: Code generated by the CAA wizard  xlu
//===================================================================
#ifndef CATIPLMModelerEventRegister_H
#define CATIPLMModelerEventRegister_H

/**
* @level Protected
* @usage U1
*/

#include "CATPLMModelerBaseInterfaces.h"
#include "CATPLMModelerEventDef.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerBaseInterfaces IID IID_CATIPLMModelerEventRegister;
#else
extern "C" const IID IID_CATIPLMModelerEventRegister ;
#endif

class CATIPLMModelerEventListener;
class CATIAdpType;
class CATIAdpExtType;

/**
* nodoc
*/
class ExportedByCATPLMModelerBaseInterfaces CATIPLMModelerEventRegister: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  *  Subscribes a listener to modeler event controller.
  *  @param iMacroModelerName
  *      The macro modeler name, which is the result of the method PLMIMacroModelerAccess::GetMacroModelerName
  *      that has to be implented by the modeler on its references / instances / ...
  *      Input Parameter.
  *  @param iListener
  *     Listener to be subscribed to modeler event controller.
  *  @return HRESULT
  *     <ul>
  *     <li><tt>S_OK</tt>: everything is OK.
  *     <li><tt>E_INVALIDARG</tt>: The input listener is empty.
  *     <li><tt>E_FAIL</tt>: Subscription failed.
  *     </ul>
  */
  virtual HRESULT Subscribe(const CATString iMacroModelerName, const CATIPLMModelerEventListener* iListener) = 0;

  /**
  * Use upper method
  * @nodoc
  */
  virtual HRESULT Subscribe(const CATPLMModelerType iModelerKey, const CATIPLMModelerEventListener  *iListener) = 0;

  /**
  *  Subscribes a listener to modeler event controller, for events registered using CATIPLMModelerEventFriendServices::LogPLMEventForExtension.
  *  @param iMacroModelerName
  *      The macro modeler name, see above
  *      Input Parameter.
  *  @param iExtensionType
  *      The extension type.
  *      Input Parameter.
  *  @param iListener
  *     Listener to be subscribed to modeler event controller.
  *  @return HRESULT
  *     <ul>
  *     <li><tt>S_OK</tt>: everything is OK.
  *     <li><tt>E_INVALIDARG</tt>: The input listener is empty.
  *     <li><tt>E_FAIL</tt>: Subscription failed.
  *     </ul>
  */
  virtual HRESULT Subscribe(const CATString iMacroModelerName, const CATIAdpExtType* iExtensionType, const CATIPLMModelerEventListener* iListener) = 0;

	/**
	*  Subscribes a listener to modeler event controller, for events registered using CATIPLMModelerEventFriendServices::LogPLMEventForConnection.
	*  @param iMacroModelerName
	*      The macro modeler name, see above
	*      Input Parameter.
	*  @param iConnectionType
	*      The connection type.
	*      Input Parameter.
	*  @param iListener
	*     Listener to be subscribed to modeler event controller.
	*  @return HRESULT
	*     <ul>
	*     <li><tt>S_OK</tt>: everything is OK.
	*     <li><tt>E_INVALIDARG</tt>: The input listener is empty.
	*     <li><tt>E_FAIL</tt>: Subscription failed.
	*     </ul>
	*/
	virtual HRESULT Subscribe(const CATString iMacroModelerName, const CATIAdpType* iConnectionType, const CATIPLMModelerEventListener* iListener) = 0;

  /**
  *  Unsubscribes a listener from modeler event controller.
  *  @param iMacroModelerName
  *      The macro modeler name, which is the result of the method PLMIMacroModelerAccess::GetMacroModelerName
  *      that has to be implented by the modeler on its references / instances / ...
  *      Input Parameter.
  *  @param iListener
  *     Listener to be unsubscribed from modeler event controller.
  *  @return HRESULT
  *     <ul>
  *     <li><tt>S_OK</tt>: everything is OK.
  *     <li><tt>E_INVALIDARG</tt>: The input listener is empty or it has not been subscribed.
  *     <li><tt>E_FAIL</tt>: Unsubscription failed.
  *     </ul>
  */
  virtual HRESULT Unsubscribe(const CATString iMacroModelerName, const CATIPLMModelerEventListener* iListener) = 0;
  
  /**
  *  Use upper method
  * @nodoc
  */
  virtual HRESULT Unsubscribe(const CATPLMModelerType iModelerKey, const CATIPLMModelerEventListener* iListener) = 0;

  /**
  *  Unsubscribes a listener from modeler event controller.
  *  @param iMacroModelerName
  *      The macro modeler name, see above
  *      Input Parameter.
  *  @param iExtensionType
  *      The extension type.
  *      Input Parameter.
  *  @param iListener
  *     Listener to be unsubscribed from modeler event controller.
  *  @return HRESULT
  *     <ul>
  *     <li><tt>S_OK</tt>: everything is OK.
  *     <li><tt>E_INVALIDARG</tt>: The input listener is empty.
  *     <li><tt>E_FAIL</tt>: Subscription failed.
  *     </ul>
  */
  virtual HRESULT Unsubscribe(const CATString iMacroModelerName, const CATIAdpExtType* iExtensionType, const CATIPLMModelerEventListener* iListener) = 0;

	/**
	*  Unsubscribes a listener from modeler event controller.
	*  @param iMacroModelerName
	*      The macro modeler name, see above
	*      Input Parameter.
	*  @param iConnectionType
	*      The connection type.
	*      Input Parameter.
	*  @param iListener
	*     Listener to be unsubscribed from modeler event controller.
	*  @return HRESULT
	*     <ul>
	*     <li><tt>S_OK</tt>: everything is OK.
	*     <li><tt>E_INVALIDARG</tt>: The input listener is empty.
	*     <li><tt>E_FAIL</tt>: Subscription failed.
	*     </ul>
	*/
	virtual HRESULT Unsubscribe(const CATString iMacroModelerName, const CATIAdpType* iConnectionType, const CATIPLMModelerEventListener* iListener) = 0;

};

CATDeclareHandler(CATIPLMModelerEventRegister, CATBaseUnknown);

#endif
