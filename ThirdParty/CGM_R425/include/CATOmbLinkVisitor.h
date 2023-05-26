#ifndef CATOmbLinkVisitor_H_
#define CATOmbLinkVisitor_H_

// COPYRIGHT DASSAULT SYSTEMES	2009

/**
 * @level Private
 * @usage U1
 */
#include "CATObjectModelerBase.h"
#include "CATBoolean.h"

class CATOmbLink;

class CATOmbLinkVisitor
{
public:
  enum CATBehaviour { CATBehaviour_break, CATBehaviour_continue };

  virtual CATBehaviour Visit(CATOmbLink & iLink) = 0;
};

#endif




