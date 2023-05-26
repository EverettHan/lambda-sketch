#ifndef CATPLMComponentEvent_Versioned_H
#define CATPLMComponentEvent_Versioned_H

#include "CATPLMComponentEvent.h"

/**
*  Object to represent a Versioned event
*  <b>Role</b> This event is sent when a component is versioned
*  Event has to be subscribed calling @see CATPLMComponentRedrawListener
*/
class CATPLMComponentEvent_Versioned : public CATPLMComponentEvent
{
public:
  CATPLMComponentEvent_Versioned() :CATPLMComponentEvent(CATPLMComponentEventType_Versioned) {}
};

#endif 





