// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
//
// CATCDSSymmetricMatrix:
//
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  November 2011  Creation                               TE9
//=============================================================================

#ifndef CATCDSSymmetricMatrix_H
#define CATCDSSymmetricMatrix_H

#include "CATCDSBoolean.h"
#include "CATCDSMatrix.h"
#include "CATCDSLowerTriangularMatrix.h"
#include "CATCDSIntArray.h"

class CATCDSLowerTriangularMatrix;
class CATCDSIntArray;

class ExportedByCDSMathematics CATCDSSymmetricMatrix
{
public:
  /**
   *  Default constructor of empty matrix.
   */
  CATCDSSymmetricMatrix();

  /**
   *  Constructor.
   *  @param iOrder
   *    Create a symmetric matrix initialized with iVal, zero if iVal = 0
   */
  CATCDSSymmetricMatrix(int iOrder, const double *iVal = 0);


   /**
   *  Conversion to Symmetric matrix, without check !
   *  the lower part is choosen
   */
  CATCDSSymmetricMatrix(int iOrder, const CATCDSMatrix& iMat);


  /**
   *  Copy constructor.
   *  @param iMatrix
   *    matrix to be copied
   */
  CATCDSSymmetricMatrix(const CATCDSSymmetricMatrix &iMatrix);

  /**
   *  Copy operator.
   *  @param iMatrix
   *    matrix to be copied.
   *  @return
   *    <b>*this</b> object
   */
  CATCDSSymmetricMatrix& operator =(const CATCDSSymmetricMatrix &iMatrix);

  /**
   *  Destructor.
   */
  virtual ~CATCDSSymmetricMatrix();

  /**
   *  Get order of the matrix (square).
   *  @return
   *    number order of the matrix.
   */
  CATCDSInline int GetOrder() const;


  /*
  * product operators
  */
  CATCDSMatrix operator *(CATCDSMatrix const &iA) const;
  CATCDSVector operator *(CATCDSVector const &iV) const;
   
  /**
   *  Scalar multiplication operator.
   *  @param iReal
   *    scalar multiplicand
   *  @return
   *    <b>*this</b> object
   */
  CATCDSSymmetricMatrix& operator *=(double iReal);

  /**
  / Convertions en 
  */
  CATCDSMatrix ConvertToFullMatrix() const;

  /**
  *  Get Infinite norm of matrix.
  */
  double GetNormInf() const;

  CATCDSInline double * GetBuffer() const {return _aValues;};



  /**
   *  Solve linear system through Cholesky factorisation method.
   *  Parameters size assumed is equal to current matrix columns number.
   *  Input and output vectors can be the same
   *  @param iaB
   *    array, containing right-hand part
   *  @param oaX
   *    obtained solution
   *  @param oCholeskyFactor
   *    cholesky factor
   */
  CATCDSBoolean SolveCholesky(const double * iaB, double * oaX, CATCDSLowerTriangularMatrix * opCholeskyFactor = 0, double iLambda = 0.) const;

  /**
   *  Computes cholesky factor
   *  @param oCholeskyFactor
   *    cholesky factor
   */
  CATCDSBoolean CholeskyFactorisation(CATCDSLowerTriangularMatrix & oCholeskyFactor, double iLambda = 0.) const;


  /**
  * LDL^t factorisation
  */

   CATCDSBoolean LDLt(CATCDSLowerTriangularMatrix & oLD, CATCDSIntArray & iPivot);


   CATCDSBoolean SolveLDLt(CATCDSBoolean useLastFactorisation, const CATCDSVector& rhs, CATCDSVector &oSolution);

  /**
   * Return non non zero elements of the row
   * @param iRow
   *  row index
   * @return
   *  an array with non zero elements
   */
  CATCDSInline double * GetRow(int iRow);
  CATCDSInline double const * GetRow(int iRow) const;

  /**
   * Resize matrix
   */
  void Resize(int iN);

  double& operator()(int iRow, int iCol)
  { 
    CATCDSAssert(iCol <= iRow);
    return _aValues[(iRow * (iRow + 1)) / 2 + iCol];
  }

  double operator()(int iRow, int iCol) const
  {
    CATCDSAssert(iCol <= iRow);
    return _aValues[(iRow * (iRow + 1)) / 2 + iCol];
  }

  /**
   *  Write matrix in MAPLE format.
   */
  virtual void  Write(const char *iName) const;


#ifdef CDS_DEBUG
  void ScilabDump(const char *iName, CATCDSStream* ipOutput) const;
#endif


protected:
  /**
   *  Number of columns and rows.
   */
  int _n;
  /**
   *  Number of non zero elements.
   */
  double * _aValues;


  // keep the values of the LDLt factorisation when run
  CATCDSLowerTriangularMatrix _LD; // le block triangulaire inférieur contient L et la diagonale contient l'inverse de D 
  CATCDSIntArray _pivot;
  CATCDSIntArray _block;


  void SymmetricPivot(const int size, double * ioLD, CATCDSIntArray& piv, int k, int p ) const;

  CATCDSBoolean RunFactorisation();
};

CATCDSInline int CATCDSSymmetricMatrix::GetOrder() const
{
  return _n;
}

CATCDSInline double * CATCDSSymmetricMatrix::GetRow(int iRow)
{
  return _aValues + (iRow * (iRow + 1)) / 2;
}

CATCDSInline double const * CATCDSSymmetricMatrix::GetRow(int iRow) const
{
  return _aValues + (iRow * (iRow + 1)) / 2;
}

#endif /* CATCDSSymmetricMatrix_H */
