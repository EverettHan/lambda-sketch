// COPYRIGHT Dassault Systemes 2007
#ifndef CATPLMModelerEventFilter_H
#define CATPLMModelerEventFilter_H

/**
* @level Protected
* @usage U1
*/

#include "CATPLMModelerBaseInterfaces.h"
#include "CATPLMModelerEventDef.h"
#include "CATBaseUnknown.h"

/**
*/
class ExportedByCATPLMModelerBaseInterfaces CATPLMModelerEventFilter
{
public:

	/**
	*  Contructor
	*  @param iContext
	*     Context of the filter
	*  @param iEntityType
	*     Entity type of the filter.
	*  @param iActionType
	*     Action Type of the filter
	*/
	CATPLMModelerEventFilter(CATBaseUnknown_var ispContext, 
													 CATPLMModelerEventEntityType iEntityType, 
													 CATPLMModelerEventActionType iActionType);

	/**
	*/
	~CATPLMModelerEventFilter();

	/**
	*  Set an Entity Type to the filter
	*  <p>
	*  <b>Role:</b> The Entity Type to filter may be sub set of Reference, Representation, 
	*               Instance, RepInstance, Port and Connections, or AnyEntity
	*  </p>
	*  @param iEntityType
	*     Entity type to set.
	*  @return HRESULT 
	*	   <ul>
	*     <li><tt>S_OK</tt>: everything is OK.
	*     <li><tt>E_INVALIDARG</tt>: The input Entity Type is not allowed.
	*     </ul>
	*/
	HRESULT AddEntityType(CATPLMModelerEventEntityType iEntityType);

	/**
	*  Set Action Types to the filter
	*  <p>
	*  <b>Role:</b> The Action Type to filter may be sub set of Create, Remove, Replace, 
	*               Load, Matrix, RelationView and AttributeModify or AnyAction.
	*  </p>
	*  @param iActionTypes
	*     Action Type to set.
	*  @return HRESULT 
	*	   <ul>
	*     <li><tt>S_OK</tt>: everything is OK.
	*     <li><tt>E_INVALIDARG</tt>: The input Action Type is not allowed.
	*     </ul>
	*/
	HRESULT AddActionType(CATPLMModelerEventActionType iActionType);

	/*
	*/
	HRESULT AddFriendType(CATPLMModelerEventFriendType iFriendType);

	/**
	*  Get the context of the filter.
	*  <p>
	*  <b>Role:</b> The context may be NULL in case one listens to events without context.
	*  </p>
	*  @param oContext
	*     The context of the filter.
	*  @return HRESULT 
	*	   <ul>
	*     <li><tt>S_OK</tt>: everything is OK.
	*     </ul>
	*/
	HRESULT GetContext(CATBaseUnknown_var& ospContext);

	/**
	*  Get Entity Types of the filter
	*  <p>
	*  <b>Role:</b> The Entity Types may be sub set of Reference, Representation, 
	*               Instance, RepInstance, Port and Connections, or AnyEntity
	*  </p>
	*  @param oEntityTypes
	*     the list of Entity Types to filter.
	*  @return HRESULT 
	*	   <ul>
	*     <li><tt>S_OK</tt>: everything is OK.
	*     <li><tt>E_FAIL</tt>: No Entity Type is specified in the filter.
	*     </ul>
	*/
	HRESULT GetEntityTypes(CATListOfCATPLMModelerEventEntityType& oEntityTypes);

	/**
	*  Get Action Types of the filter
	*  <p>
	*  <b>Role:</b> The Action Types may be sub set of Create, Remove, Replace, 
	*               Load, Matrix, RelationView and AttributeModify or AnyAction.
	*  </p>
	*  @param oActionTypes
	*     the list of Action Types of the filter.
	*  @return HRESULT 
	*	   <ul>
	*     <li><tt>S_OK</tt>: everything is OK.
	*     <li><tt>E_FAIL</tt>: No Action Type is specified in the filter.
	*     </ul>
	*/
	HRESULT GetActionTypes(CATListOfCATPLMModelerEventEntityType& oActionTypes);

	/**
	*/
	HRESULT GetFriendTypes(CATListOfCATPLMModelerEventFriendType& oFriendTypes);

	/**
	*  Operator = 
	*/
	CATPLMModelerEventFilter& operator =(CATPLMModelerEventFilter& iFilter);

private:

	CATListOfCATPLMModelerEventEntityType _EntityTypes;
	CATListOfCATPLMModelerEventActionType _ActionTypes;
	CATListOfCATPLMModelerEventFriendType _FriendTypes;
	CATBaseUnknown_var _Context;
};

#endif
