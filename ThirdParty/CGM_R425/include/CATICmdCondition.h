#ifndef CATICmdCondition_H
#define CATICmdCondition_H

/* COPYRIGHT DASSAULT SYSTEMES 1999 */

#include <IUnknown.h>

#include "CATBooleanDef.h"

/**
 * Condition behavior.
 * A condition must implement this interface and is associated with a
 * transition or a state.
 */
class CATICmdCondition : public IUnknown
{

public:
 
  /**
  * Evaluates the condition.
  * @param oResult
  *   The result of the evaluation
  */
  virtual HRESULT Evaluate (CATBoolean * oResult) = 0;
  
};

/* 87c73bc8-2244-0000-0280-030b27000000 */
extern "C" const IID IID_CATICmdCondition;

#endif
