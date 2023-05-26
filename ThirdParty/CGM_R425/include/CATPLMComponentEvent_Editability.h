#ifndef CATPLMComponentEvent_Editability_H
#define CATPLMComponentEvent_Editability_H

#include "CATPLMComponentEvent.h"
/**
*  Object to represent an Editability event
*  <b>Role</b> This event is sent when Editability is switched to RW or RO
*  Event has to be subscribed calling @see CATPLMComponentRedrawListener
*/
class CATPLMComponentEvent_Editability : public CATPLMComponentEvent
{
public:
  CATPLMComponentEvent_Editability() :CATPLMComponentEvent(CATPLMComponentEventType_Editability) {}
};

#endif 





