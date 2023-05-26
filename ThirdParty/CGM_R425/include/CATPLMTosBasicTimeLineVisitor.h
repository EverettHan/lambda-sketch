#ifndef CATPLMTosBasicTimeLineVisitor_H
#define CATPLMTosBasicTimeLineVisitor_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004

/**
 * @level Private
 * @usage U1
 */


#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATPLMTosBasicTimeLineEvents.h"

class CATComponentId;

/** obsolete, do not use */
class ExportedByCATPLMTos CATPLMTosBasicTimeLineVisitor
{
public:
  enum CATBehaviour { CATBehaviour_continue };

  virtual CATBehaviour Visit(const CATComponentId & iCID, CATPLMTosBasicTimeLineEvents iEventMask) = 0;
};

#endif
