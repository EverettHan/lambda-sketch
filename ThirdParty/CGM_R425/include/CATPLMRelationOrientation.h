// COPYRIGHT DASSAULT SYSTEMES 2010


#ifndef CATPLMRelationOrientation_H
#define CATPLMRelationOrientation_H

#include "CATPLMRelationInformation.h"

/**
* @level Protected
* @usage U1
*/

/**
* Orientation of a relation.
*
* @param CATPLMRelationOrientation_NEUTRAL
*   Neutral relation.
* @param CATPLMRelationOrientation_IN
*   In relation.
* @param CATPLMRelationOrientation_OUT
*   Out relation.
* @param CATPLMRelationOrientation_OUT
*   In-Out relation.
*/
enum CATPLMRelationOrientation 
{
    CATPLMRelationOrientation_NEUTRAL = 0,
    CATPLMRelationOrientation_IN = 1,
    CATPLMRelationOrientation_OUT = 2,
    CATPLMRelationOrientation_INOUT = 3
} ;

#endif
