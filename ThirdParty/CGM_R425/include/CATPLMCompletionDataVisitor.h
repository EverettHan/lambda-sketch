#ifndef CATPLMCompletionDataVisitor_h
#define CATPLMCompletionDataVisitor_h

#include "CATPLMIntegrationAccess.h"
#include "CATAssert.h"

/**
* @level Protected
* @usage U2
**/


class CATPLMID;

/**
* Visitor for tne previous data.
*/
class ExportedByCATPLMIntegrationAccess CATPLMCompletionDataVisitor
{
public:  
  enum CATBehaviour {CATBehaviour_break, CATBehaviour_continue};

  CATPLMCompletionDataVisitor(){};
  virtual ~CATPLMCompletionDataVisitor(){};
  virtual CATBehaviour Visit(CATPLMID & /*iPid*/) { CATAssert(0); return CATBehaviour_break; /* le collec manager ne permet pas d'avoir du virtuel pur */}
};

#endif

