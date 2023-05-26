// COPYRIGHT Dassault Systemes 2014
//===================================================================

// CATCDSInverseMatrixCalculator.h

//===================================================================

// Usage notes: Interface of operator dedicated to invert a matrix

//===================================================================

//  Apr 2014  Creation:             BF8 CHU
//===================================================================
#ifndef CATCDSInverseMatrixCalculator_H
#define CATCDSInverseMatrixCalculator_H
#if !defined(_EMSCRIPTEN_SOURCE)

#include "CDSProfile.h"
#include "CATICDSInverseMatrixCalculator.h"

class CATCDSMatrix;

//-----------------------------------------------------------------------

class ExportedByCDSProfile CATCDSInverseMatrixCalculator : public CATICDSInverseMatrixCalculator
{
public:

  // Life Cycle
  CATCDSInverseMatrixCalculator();
  virtual ~CATCDSInverseMatrixCalculator();

  // Invert a square matrix  
  CATCDSBoolean QuickInverse(CATCDSMatrix & ioMatrix);

};

//-----------------------------------------------------------------------
#endif
#endif
