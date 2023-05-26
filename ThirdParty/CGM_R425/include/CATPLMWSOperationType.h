 /* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U3
 */

#ifndef CATPLMWSOperationType_h
#define CATPLMWSOperationType_h

#include "CATPLMWorkspaceReferenceUsers.h"

namespace CATPLMWSOperationType
{
  enum OperationType { UNDEFINED=0, ATTACHED=1, UPDATED=2, DETACHED=3, IMPACTED=4, CREATED=5, DELETED=6 };
}
#endif
