#ifndef _CATPLMRelationDirection_H
#define _CATPLMRelationDirection_H

/**
 * @level Private
 * @usage U1
 *
 */
typedef unsigned int CATPLMRelationDirection;
constexpr CATPLMRelationDirection CATPLMRelationDirection_DIRECT = 1;
constexpr CATPLMRelationDirection CATPLMRelationDirection_INVERSE = 2;
constexpr CATPLMRelationDirection CATPLMRelationDirection_ALL = CATPLMRelationDirection_DIRECT | CATPLMRelationDirection_INVERSE;


#endif
