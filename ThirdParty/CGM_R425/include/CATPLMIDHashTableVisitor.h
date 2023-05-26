
#ifndef CATPLMIDHashTableVisitor_H
#define CATPLMIDHashTableVisitor_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
 * @level Private
 * @usage U1       
 */
#include "CATPLMIdentificationAccess.h"
#include "CATBaseUnknown.h"
#include "CATDataType.h"

class CATPLMID;

/**
 * This makes possible to give a light access to a set
 */
class ExportedByCATPLMIdentificationAccess CATPLMIDHashTableVisitor
{
public:

  /**
  * CATBehaviour_continue : visit next component 
  * CATBehaviour_break    : stop iteration
  */
  enum CATBehaviour {CATBehaviour_break, CATBehaviour_continue};

  CATPLMIDHashTableVisitor();
  virtual ~CATPLMIDHashTableVisitor();
  virtual CATBehaviour Visit(CATPLMID & iPLMID, CATUINTPTR & oValue) = 0;
};
 
#endif


