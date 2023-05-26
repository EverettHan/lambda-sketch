#ifndef _CATPLMComponentEvent_H
#define _CATPLMComponentEvent_H
/**
 * @level Protected
 * @usage U1
 */
#include "CATPLMIdentificationAccess.h"

enum CATPLMComponentEventType
{
  CATPLMComponentEventType_Editability,
  CATPLMComponentEventType_Relational,
  CATPLMComponentEventType_Versioned,
  CATPLMComponentEventType_Synchronized
};

class CATPLMComponentEvent
{
  CATPLMComponentEventType m_type;
public:
  CATPLMComponentEvent(CATPLMComponentEventType type) :m_type(type) {}
  CATPLMComponentEventType GetType() const { return m_type; }
};

#endif
