#ifndef CATComponentIdAssociationVisitor_H
#define CATComponentIdAssociationVisitor_H

/**
 * @level Private
 * @usage U1       
 */
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATDataType.h"

class CATComponentId;

/** obsolete */
class CATComponentIdAssociationVisitor
{
public:
  enum CATBehaviour {CATBehaviour_break, CATBehaviour_continue};

  virtual CATBehaviour Visit(const CATComponentId & iCID, const CATUINTPTR iValue) = 0;
};
 
#endif
