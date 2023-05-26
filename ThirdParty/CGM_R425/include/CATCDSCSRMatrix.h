// COPYRIGHT DASSAULT SYSTEMES 2019
//=============================================================================
//
// CATCDSCSRMatrix:
//
//
//=============================================================================
//
// Usage notes:
// Sparse matrix optimized for row dependent operation
//
//=============================================================================
//  Jul 2019  Creation                               T. Petiau
//=============================================================================

#ifndef CATCDSCSRMatrix_H
#define CATCDSCSRMatrix_H

#include "CDSMathematics.h"
#include "CATCDSVector.h"
#include "CATCDSMatrix.h"

class ExportedByCDSMathematics CATCDSCSRMatrix
{
public:

  CATCDSCSRMatrix(const CATCDSMatrix &iMatrix);

  /**
   *  Destructor.
   */
  virtual ~CATCDSCSRMatrix();

  /**
   *  Get number of columns.
   *  @return
   *    number of columns
   */
  CATCDSInline int GetNbOfCol() const;

  /**
   *  Get number of rows.
   *  @return
   *    number of rows
   */
  CATCDSInline int GetNbOfRow() const;

  /**
  *   Scalar product between a row of this matrix and any vector
  *   @return
  *      scalar product
  */
  double ScalarProduct(int iRow, double * iVector) const;

  /**
  *  Product between any matrix and a row of this matrix
  *  @return
  *     vector
  */
  CATCDSVector MatrixProductWithRow(const CATCDSMatrix iMatrix, int iRow) const;

  /**
  *  Swap rows using _rowMapping
  */
  void SwapRows(int iRow1, int iRow2);

protected:
  
  int _n; // Number of columns.
  int _m; // Number of rows.
  CATCDSArray<int> _indCol; // Array of column indices
  CATCDSArray<double> _data; // Array of corresponding nonzero values
  CATCDSArray<int> _indPtr; // Points to rows starts in _indCol and _data
  CATCDSArray<int> _rowMapping; // points to corresponding row, MANDATORY to use when accessing other data members
};

CATCDSInline int CATCDSCSRMatrix::GetNbOfCol() const
{
  return _n;
}

CATCDSInline int CATCDSCSRMatrix::GetNbOfRow() const
{
  return _m;
}

#endif /* CATCDSCSRMatrix_H */
