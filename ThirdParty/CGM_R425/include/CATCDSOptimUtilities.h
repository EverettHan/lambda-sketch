#ifndef CATCDSOptimUtilities_H
#define CATCDSOptimUtilities_H

#include "CDSMathematics.h"

#include "CATCDSBoolean.h"
#include "CATCDSVector.h"

class CATCDSSymmetricMatrix;
class CATCDSMatrix;

class CATCDSOptimUtilities
{

public:
  /**
  * solve min_x 0.5 * x^t iG x + x^t iD subject to  (iA x_ )i = iB_i for 0 <=i <iNbEquations,  (iA x_ )i <= iB_i for i>= iNbEquations
  * @param CATCDSSymmetricMatrix iG, matrix of size n*n
  * @param CATCDSMatrix iA, matrix of size m*n
  * @param CATCDSVector iD, vector of size n
  * @param CATCDSVector iB, vector of size m
  * @param int iNbEquations
  * @param CATCDSBoolean* aLowerBoundActive. if aLowerBoundActive[i] = TRUE, the variable ioX_i has a lower bound, size == n
  * @param double* aLowerBound. aLowerBound[i] <= ioX_i if aLowerBoundActive[i] == TRUE
  * @param CATCDSBoolean* aUpperBoundActive. if aUpperBoundActive[i] = TRUE, the variable ioX_i has a upper bound, size == n
  * @param double* aUpperBound. aUpperBound[i] >= ioX_i if aUpperBoundActive[i] == TRUE
  * @param CATCDSVector ioX solution of the system and init of the methode. ioX must lie in the feasible space !!!!
  * @param CATCDSVector oLambda, lagrange multiplier, size nb constraint + nb active bounds
  */
  ExportedByCDSMathematics static CATCDSBoolean ActiveSetMethod(int iCDSLevel, const CATCDSSymmetricMatrix& iG, const CATCDSVector& iD, const CATCDSMatrix& iA, const CATCDSVector& iB, int iNbEquations, 
    const CATCDSBoolArray& aLowerBoundActive, const CATCDSVector& aLowerBound, const CATCDSBoolArray& aUpperBoundActive, const CATCDSVector& aUpperBound,
    CATCDSVector& ioX, double iZeroPivot = 1e-10);//@NumValidated

  /**
  * solve min_x 0.5 * x^t iG x + x^t iD + iC subject to  (iA x)_i = iB_i for 0 <= i <iNbEqualities,  (iA x)_i <= iB_i for iNbEqualities <= i < iNbEqualities + iNbInequalities
  * @param iCDSLevel
  * @param iG matrix of size n*n
  * @param iA matrix of size m*n
  * @param iD vector of size n
  * @param iC constant
  * @param iB vector of size m
  * @param iNbEqualities
  * @param iNbInequalities
  * @param ioX solution of the system and init of the method. ioX must lie in the feasible space !!!!
  */
  ExportedByCDSMathematics static CATCDSBoolean ActiveSetMethod(int iCDSLevel, const CATCDSSymmetricMatrix& iG, const CATCDSVector& iD, const CATCDSMatrix& iA, const CATCDSVector& iB, int iNbEqualities, int iNbInequalities, 
    CATCDSVector& ioX, double iZeroPivot = 1e-10);//@NumValidated

  /**
  * solve min_{x} ic^t x st (Ax)_i = iB_i for i<iNbEquation, (Ax)_i <= iB_i for i>=iNbEquation
  * @param CATCDSMatrix iA, matrix of size m*n
  * @param CATCDSVector iD, vector of size n
  * @param CATCDSVector iB, vector of size m
  * @param int iNbEquations
  */

  ExportedByCDSMathematics static CATCDSBoolean SolveLinearProgramming(int iCDSLevel, const CATCDSVector& ic, const CATCDSMatrix& iA, const CATCDSVector& iB, int iNbEquations, 
     const CATCDSBoolArray& aLowerBoundActive, const CATCDSVector& aLowerBound, const CATCDSBoolArray& aUpperBoundActive, const CATCDSVector& aUpperBound,
    CATCDSVector& x, double iZeroPivot = 1e-10, double iTolerance = 1e-12);//@NumValidated


   /**
  * solve min_{x} ic^t x st (Ax)_i = iB_i for i<iNbEquation, (Ax)_i <= iB_i for i>=iNbEquation, and x >=0
  * @param CATCDSMatrix iA, matrix of size m*n
  * @param CATCDSVector iD, vector of size n
  * @param CATCDSVector iB, vector of size m
  * @param int iNbEquations
  */
  ExportedByCDSMathematics static CATCDSBoolean InteriorPoint_Mehrotra(int iCDSLevel, const CATCDSVector& ic, const CATCDSMatrix& iA, const CATCDSVector& iB, int iNbEquation, CATCDSVector& x, CATCDSVector& lambda, double iZeroPivot = 1e-10, double iTolerance = 1e-12);//@NumValidated

private:
  CATCDSOptimUtilities();
  CATCDSOptimUtilities(const CATCDSOptimUtilities&);
  void operator = (const CATCDSOptimUtilities&);

};

#endif
