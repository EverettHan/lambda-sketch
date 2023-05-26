#ifndef _CATPLMComponentEvent_Synchronized_H
#define _CATPLMComponentEvent_Synchronized_H

#include "CATPLMComponentEvent.h"

/**
*  Object to represent an event
*  <b>Role</b> This event is sent when a component is synchronized in memory after refresh operation.
*  This event is sent at the end of CATCommand or when the transaction is finalysed.
*  Event has to be subscribed calling @see CATPLMComponentRedrawListener
*  An other generic event can be sent @see CATPLMComponentEvent_Imported
*/
class CATPLMComponentEvent_Synchronized : public CATPLMComponentEvent
{
public:
  CATPLMComponentEvent_Synchronized() :CATPLMComponentEvent(CATPLMComponentEventType_Synchronized) {}
};

#endif 





