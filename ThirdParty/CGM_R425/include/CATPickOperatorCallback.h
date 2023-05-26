//==========================================================================================
// COPYRIGHT DASSAULT SYSTEMES 2009
//==========================================================================================
//
//==========================================================================================
// March 09 Creation                                    MPX
//==========================================================================================

#ifndef CATPickOperatorCallback_H
#define CATPickOperatorCallback_H

#include "CATBoolean.h"
#include "Pick.h"

// Client code can derive from this class and implement
// the Abort method
class ExportedByPick CATPickOperatorCallback
{
public:

  // CATPickOperator will call this function frequently
  // If and when this return TRUE, then CATPickOperator::Run will abort itself and return
  virtual CATBoolean Abort() = 0;

  virtual ~CATPickOperatorCallback();
};




#endif //CATPickOperatorCallback_H
