
#ifndef CATPLMIDVisitor_H
#define CATPLMIDVisitor_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
 * @level Private
 * @usage U1       
 */
#include "CATPLMIdentificationAccess.h"
#include "CATBaseUnknown.h"

class CATPLMID;

/**
 * This makes possible to give a light access to a set
 */
class ExportedByCATPLMIdentificationAccess CATPLMIDVisitor
{
public:

  /**
  * CATBehaviour_continue : visit next component 
  * CATBehaviour_break    : stop iteration
  */
  enum CATBehaviour {CATBehaviour_break, CATBehaviour_continue};

  CATPLMIDVisitor();
  virtual ~CATPLMIDVisitor();
  virtual CATBehaviour Visit(CATPLMID & iPLMID) = 0;
};
 
#endif


