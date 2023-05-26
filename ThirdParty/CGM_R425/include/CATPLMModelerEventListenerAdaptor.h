// COPYRIGHT Dassault Systemes 2007
//===================================================================
#ifndef CATPLMModelerEventListenerAdaptor_H
#define CATPLMModelerEventListenerAdaptor_H

/**
* @level Protected
* @usage U1
*/

#include "CATPLMModelerBaseInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATPLMModelerEventDef.h"
#include "CATPLMModelerEventFilter.h"
#include "CATIPLMModelerEventListener.h"

class CATIAdpType;
class CATIAdpExtType;

/**
*/
class ExportedByCATPLMModelerBaseInterfaces CATPLMModelerEventListenerAdaptor: public CATIPLMModelerEventListener
{
public:

  /**
  *  Contructor
  */
  CATPLMModelerEventListenerAdaptor();

  /**
  *  Set a filter to the listener
  *  @param iFilter
  *     Filter to be associated the listener
  *  @return HRESULT 
  *	   <ul>
  *     <li><tt>S_OK</tt>: everything is OK.
  *     </ul>
  */
  HRESULT SetEventFilter(CATPLMModelerEventFilter& iFilter);

  /**
  * @deprecated 
  */
  HRESULT SetModelerType(CATPLMModelerType iModelerType);

  /**
  * @deprecated 
  */
  HRESULT GetModelerType(CATPLMModelerType& oModelerType);

  /**
  *  Get the commit mode of the listener.
  *  <p>
  *  <b>Role:</b> Commit mode can Synchronous or Asynchronous.
  *  </p>
  *  @param iCommitMode
  *     The commit mode to set to the listener.
  *  @return HRESULT 
  *	   <ul>
  *     <li><tt>S_OK</tt>: everything is OK.
  *     </ul>
  */
  HRESULT SetCommitMode(CATPLMModelerCommitMode iCommitMode);

  /**
  *  Get the commit mode of the listener.
  *  <p>
  *  <b>Role:</b> Commit mode can Synchronous or Asynchronous.
  *  </p>
  *  @param oCommitMode
  *     The commit mode  of the listener.
  *  @return HRESULT 
  *	   <ul>
  *     <li><tt>S_OK</tt>: everything is OK.
  *     </ul>
  */
  HRESULT GetCommitMode(CATPLMModelerCommitMode& oCommitMode);

  /**
  *  Get the context of the listener.
  *  <p>
  *  <b>Role:</b> The context may be NULL in case one listens to an event 
  *               without context.
  *  </p>
  *  @param oConext
  *     The context of the listener.
  *  @return HRESULT 
  *	   <ul>
  *     <li><tt>S_OK</tt>: everything is OK.
  *     </ul>
  */
  HRESULT GetContext(CATBaseUnknown_var& ospContext);

  /**
  *  Get Entity Types of the listener
  *  <p>
  *  <b>Role:</b> The Entity Types of listener may be sub set of Reference, Representation, 
  *               Instance, RepInstance, Port and Connections, or AnyEntity
  *  </p>
  *  @param oEntityTypes
  *     A list of Entity Types of the listener
  *  @return HRESULT 
  *	   <ul>
  *     <li><tt>S_OK</tt>: everything is OK.
  *     <li><tt>E_FAIL</tt>: No Entity Type is specified for the listener.
  *     </ul>
  */
  HRESULT GetEntityTypes(CATListOfCATPLMModelerEventEntityType& oEntityTypes);

  /**
  *  Get Action Types of the listener
  *  <p>
  *  <b>Role:</b> The Action Types of listener may be sub set of Create, Remove, Replace, 
  *               Load, Matrix, RelationView and AttributeModify or AnyAction.
  *  </p>
  *  @param oActionTypes
  *     A list of Action Types of the listener
  *  @return HRESULT 
  *	   <ul>
  *     <li><tt>S_OK</tt>: everything is OK.
  *     <li><tt>E_FAIL</tt>: No Action Type is specified for the listener.
  *     </ul>
  */
  HRESULT GetActionTypes(CATListOfCATPLMModelerEventActionType& oActionTypes);

	/**
	*/
	HRESULT GetFriendTypes(CATListOfCATPLMModelerEventFriendType& oFriendTypes);

  /**
  *  Process a set of expected modeler events.
  *  <p>
  *  <b>Role:</b> This method is called back the modeler event controller
  *               in case of events specified by the listner.
  *  </p>
  *  @param ipEventList
  *     A list of expected events.
  *  @return none.
  */
  virtual void ProcessEvent(CATLISTP(CATIPLMModelerEventAccess)* ipEventList);

	/**
	* Same as above, for events related to a given extension type
	*/
  virtual void ProcessEvent(const CATIAdpExtType* iExtensionType, CATLISTP(CATIPLMModelerEventAccess)* ipEventList);

	/**
	* For events related to a given connection type
	*/
	virtual void ProcessEvent(const CATIAdpType* iConnectionType, CATLISTP(CATIPLMModelerEventAccess)* ipEventList) ;

private : 

  CATPLMModelerEventFilter _Filter;
  CATPLMModelerCommitMode  _CommitMode;
  CATPLMModelerType _ModelerType;

};

#endif
