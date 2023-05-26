#ifndef CATPLMTYPEHVISITOR_H_
#define CATPLMTYPEHVISITOR_H_

#include "CATPLMIdentificationAccess.h"
class CATPLMTypeH;
class ExportedByCATPLMIdentificationAccess CATPLMTypeHVisitor
{
public:
  /**
  * CATBehaviour_continue : visit next component
  * CATBehaviour_break    : stop iteration
  */
  enum CATBehaviour {CATBehaviour_break, CATBehaviour_continue};
  CATPLMTypeHVisitor(){};
  virtual ~CATPLMTypeHVisitor(){};
  virtual CATBehaviour Visit(const CATPLMTypeH & iType) = 0;
};
#endif /* CATPLMTYPEHVISITOR_H_ */
