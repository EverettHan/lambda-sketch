// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
//
// CATCDSInterruptDef:
//   Declaration of the interrupt class CATCDSInterruptInterface
//
//=============================================================================
//
// Usage notes:
//
//=============================================================================
//  Jul 2011  Creation                                                    FCX
//=============================================================================

#ifndef CATCDSInterruptDef_H
#define CATCDSInterruptDef_H

#include "CATCDSBoolean.h"

class CATCDSInterruptInterface
{
public :
  virtual CATCDSBoolean Interrupt() = 0;
  virtual CATCDSBoolean Interrupt(const char* iDbgString) { return Interrupt(); }
  virtual ~CATCDSInterruptInterface(){}
};

#endif
