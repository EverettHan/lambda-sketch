#ifndef CATPLMModelerEventTypeDef_H
#define CATPLMModelerEventTypeDef_H

/**
* @level Protected
* @usage U1
*/

#include "CATBaseUnknown.h"
#include "CATListOfInt.h"

/**
* Defines the authorized entity type of the event.
*/
enum CATPLMModelerEventEntityType
{
  PLM_UnknownEntity = 0,
  PLM_Reference,
  PLM_Representation,
  PLM_Instance,
  PLM_RepInstance,
  PLM_Port,
  PLM_Connection,
  PLM_AnyIRPC,
  PLM_BusinessObj,
  PLM_Relationship,
  PLM_AnyComponent,
  PLM_Occurrence,
  PLM_AnyEntity
};

/**
* Defines the authorized action type of the event.
*/
enum CATPLMModelerEventActionType
{
  PLM_UnknownAction = 0,
  PLM_Create,
  PLM_Delete,
  PLM_Replace,
  PLM_Load,
  PLM_UnLoad,
  PLM_ModifyMatrix,
  PLM_RelationView,
  PLM_ModifyAttribute,
  PLM_AnyAction,
  PLM_ModelerMessage
};

/**
* Defines the authorized commit mode of the controller.
*/
enum CATPLMModelerCommitMode
{
  Synchronous,
  Asynchronous
};

/**
*/
enum CATPLMModelerEventFriendType
{
  PLM_NoFriend = 0,
  PLM_Extension,
  PLM_Cnx,
  PLM_AnyFriend
};

typedef struct ModelerEventFriend
{
  CATPLMModelerEventFriendType _type;
  CATBaseUnknown* _data;
} ModelerEventFriend;

/**
* Defines list of event entity types
*/
typedef CATListOfInt CATListOfCATPLMModelerEventEntityType;

/**
* Defines list of event action types
*/
typedef CATListOfInt CATListOfCATPLMModelerEventActionType;

/**
* Defines list of event friend types
*/
typedef CATListOfInt CATListOfCATPLMModelerEventFriendType;

/**
* @deprecated
*/
enum CATPLMModelerType
{
  PLM_ProductModeler,
  PLM_ProcessModeler
};

#endif




