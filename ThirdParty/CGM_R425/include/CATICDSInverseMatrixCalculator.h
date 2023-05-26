// COPYRIGHT Dassault Systemes 2014
//===================================================================

// CATICDSInverseMatrixCalculator.h

//===================================================================

// Usage notes: Interface of operator dedicated to invert a matrix

//===================================================================

//  Apr 2014  Creation:             BF8 CHU
//===================================================================
#ifndef CATICDSInverseMatrixCalculator_H
#define CATICDSInverseMatrixCalculator_H

#include "CATCDS.h"
#include "CATCDSBoolean.h"

class CATCDSMatrix;

/**
 * @SKIP
 *
 */
class ExportedBySolverInterface CATICDSInverseMatrixCalculator
{

public:

  /**
   * Life Cycle (this class must be derived)
   */
  virtual ~CATICDSInverseMatrixCalculator();

  /**
   * Invert matrix. 
   * @param ioMatrix
   *   Initial matrix in input, inverse matrix in output
   * @return
   *   TRUE if calculation completed successfully, otherwise FALSE (if matrix cannot be inverted, having a non trivial kernel)
   */
  virtual CATCDSBoolean QuickInverse(CATCDSMatrix & ioMatrix) = 0;


protected :
  /**
  * Life Cycle (this class must be derived)
  */
  CATICDSInverseMatrixCalculator();
};

#endif
