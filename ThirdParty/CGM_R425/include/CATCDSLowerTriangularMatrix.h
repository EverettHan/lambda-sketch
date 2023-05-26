// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
//
// CATCDSLowerTriangularMatrix:
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

#ifndef CATCDSLowerTriangularMatrix_H
#define CATCDSLowerTriangularMatrix_H

#include "CATCDSBoolean.h"
#include "CATCDSMatrix.h"

class ExportedByCDSMathematics CATCDSLowerTriangularMatrix
{
public:
  /**
   *  Default constructor of empty matrix.
   */
  CATCDSLowerTriangularMatrix();

  /**
  *  construction with the values
  */
  CATCDSLowerTriangularMatrix(int n, const double *aValue);

  /**
   *  Copy constructor.
   *  @param iMatrix
   *    matrix to be copied
   */
  CATCDSLowerTriangularMatrix(const CATCDSLowerTriangularMatrix &iMatrix);

  /**
   *  Copy operator.
   *  @param iMatrix
   *    matrix to be copied.
   *  @return
   *    <b>*this</b> object
   */
  CATCDSLowerTriangularMatrix& operator =(const CATCDSLowerTriangularMatrix &iMatrix);

  /**
   *  Destructor.
   */
  virtual ~CATCDSLowerTriangularMatrix();

  /**
   *  Get order of the matrix (square).
   *  @return
   *    number order of the matrix.
   */
  CATCDSInline int GetOrder() const;

  /**
   *  Solve linear system.
   *  Parameter sizes assumed to be equal to current matrix order.
   *  Input and output vectors can be the same
   *  @param iaB
   *    array, containing right-hand part
   *  @param oaX
   *    obtained solution
   *  @result
   *    FALSE if failed, TRUE otherwise
   */
  CATCDSBoolean Solve(double const * iaB, double * oaX) const;

  /**
   *  Solve linear system of transposed matrix.
   *  Parameter sizes assumed to be equal to current matrix order.
   *  Input and output vectors can be the same
   *  @param iaB
   *    array, containing right-hand part
   *  @param oaX
   *    obtained solution
   *  @result
   *    FALSE if failed, TRUE otherwise
   */
  CATCDSBoolean SolveTranspose(double const * iaB, double * oaX) const;

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

  CATCDSInline double * GetBuffer() const {return _aValues;};

  /**
   *  Write matrix in MAPLE format.
   */
  virtual void  Write(const char *iName) const;

protected:
  /**
   *  Number of columns and rows.
   */
  int _n;
  /**
   *  Buffer for matrix values.
   */
  double * _aValues;
};

CATCDSInline int CATCDSLowerTriangularMatrix::GetOrder() const
{
  return _n;
}

CATCDSInline double * CATCDSLowerTriangularMatrix::GetRow(int iRow)
{
  return _aValues + (iRow * (iRow + 1)) / 2;
}

CATCDSInline double const * CATCDSLowerTriangularMatrix::GetRow(int iRow) const
{
  return _aValues + (iRow * (iRow + 1)) / 2;
}

#endif /* CATCDSLowerTriangularMatrix_H */
