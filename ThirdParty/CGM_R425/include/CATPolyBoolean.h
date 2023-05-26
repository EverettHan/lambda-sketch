// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBoolean.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// October 2004 Creation: NDO
//===================================================================
#ifndef CATPolyBoolean_H
#define CATPolyBoolean_H

#include "CATPolyBooleanOperators.h"


class ExportedByCATPolyBooleanOperators CATPolyBoolean 
{

public:
  
  enum BooleanOperation
  {
    eBooleanNone = 0,
    eBooleanUnion,
    eBooleanIntersection,
    eBooleanSubtraction
  };

  enum BooleanOperand
  {
    eBooleanVolume = 0,
    eBooleanSurface,
    eBooleanBadOperand
  };

  enum BooleanError
  {
    eNoError = 0,
    eMemoryError,
    ePartitionError,
    eOpenOperand,
    eFirstOperandOpen,
    eSecondOperandOpen,
    eBothOperandsOpen,
    eBadOperand,
    eFirstOperandBad,
    eSecondOperandBad,
    eBothOperandsBad,
    eInterrupted
  };
  
};

#endif

