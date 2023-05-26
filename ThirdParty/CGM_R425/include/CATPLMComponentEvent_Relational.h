#ifndef CATPLMComponentEvent_Relational_H
#define CATPLMComponentEvent_Relational_H

#include "CATPLMComponentEvent.h"

/**
 * "relational" event.
 * relational means here SemanticRelation (SR), not RelationType (rel).
 *
 * You can listen this event by using CATPLMComponentRedrawListener.
 *
 *  This event is sent on an object when:
 *    - an SR is created/modified/deleted on this object
 *    - this object is loaded and holds at least one relation. (hint: this is useless)
 *    - the target of a relation held by this object is "modified".
 *      Warning "modified" means here any kind of modification of the target object (any attribute, any stream, any relation, really anything...)
 *      This means that you will get called in situations where absolutely nothing meaningful for you occured.
 *      Notice that as stated former documentation of this class, you will get called when an SR is synchronized/unsynchronized. Actually you will also get called in case of "false impact".
 *  It is not possible to differentiate those cases.
 *
 *  This event is not sent during undo-redo.
 */
class CATPLMComponentEvent_Relational : public CATPLMComponentEvent
{
public:
  CATPLMComponentEvent_Relational() :CATPLMComponentEvent(CATPLMComponentEventType_Relational) {}
};

#endif 





