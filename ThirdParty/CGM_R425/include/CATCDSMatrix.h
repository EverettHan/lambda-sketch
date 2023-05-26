// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
//
// CATCDSMatrix:
//
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Jun 2002  Creation                                 E. Rukoleev
//=============================================================================

#ifndef CATCDSMatrix_H
#define CATCDSMatrix_H

#include "CATCDSArray.h"
#include "CATCDSAssert.h"
#include "CATCDSBoolean.h"
#include "CATCDSDebug.h"
#include "CATCDSInline.h"
#include "CDSMathematics.h"

class CATCDSStream;
class CATCDSBoolArray;
class CATCDSVector;
class CATCDSString;
class CATCDS3x3Matrix;

extern const double CATCDSMatrixThresholdREF;

#if defined(CATIAR421)
#include <initializer_list>
#endif

class ExportedByCDSMathematics CATCDSMatrix : protected CATCDSArray<double>
{
public:
  /**
   *  Default constructor of empty matrix.
   */
  CATCDSMatrix();

  /**
   *  Copy constructor.
   *  @param iMatrix
   *    matrix to be copied
   */
  CATCDSMatrix(const CATCDSMatrix& iMatrix);

  /**
  *  Move constructor.
  *  @param iMatrix
  *    matrix to be moved
  */
#ifdef CPP11_AVAILABLE
  CATCDSMatrix(CATCDSMatrix&& iMatrix);
  CATCDSMatrix(int iNbRow, int iNbCol, cds::span<double const> iSpan);
#endif

  /**
   *  Copy operator.
   *  @param iMatrix
   *    matrix to be copied.
   *  @return
   *    <b>*this</b> object
   */
  CATCDSMatrix& operator=(const CATCDSMatrix& iMatrix);

  /**
  *  Move operator.
  *  @param iMatrix
  *    matrix to be moved.
  *  @return
  *    <b>*this</b> object
  */
#ifdef CPP11_AVAILABLE
  CATCDSMatrix& operator=(CATCDSMatrix&& iMatrix);
  CATCDSMatrix& operator=(cds::span<double const> iSpan);
#endif

  /**
   *  Copy operator.
   *  @param iTable
   *    array of doubles to be copied
   *  @return
   *    <b>*this</b> object
   */
  CATCDSMatrix& operator=(const double* iTable)
  {
    CATCDSArray<double>::operator=(iTable);
    return *this;
  }

  /**
   *  Constructor of matrix of given size and initial values.
   *  @param iNbRow
   *    number of rows
   *  @param iNbCol
   *    number of columns
   *  @param iTable
   *    pointer to array of initial values in rowwise order,
   *    NULL pointer is acceptable
   */
  CATCDSMatrix(int iNbRow, int iNbCol, const double* iTable = 0);

  /**
  *  Constructor of matrix of given size and initial values.
  *  @param iNbRow
  *    number of rows
  *  @param iNbCol
  *    number of columns
  *  @param iTable
  *    pointer to array of initial values in rowwise order,
  */
  CATCDSMatrix(int iNbRow, int iNbCol, CATCDSArray<double> const& iTable);

  /**
  *  Constructor of matrix of given size and initial values.
  *  @param iNbRow
  *    number of rows
  *  @param iNbCol
  *    number of columns
  *  @param iVal
  *    double coefficient value
  */
  CATCDSMatrix(int iNbRow, int iNbCol, double iVal);

  /**
   *  Constructor of identity matrix E(Dim).
   *  @param iDim
   *    matrix dimension
   */
  CATCDSMatrix(int iDim);

#if defined(CATIAR421)
  /**
  *  Constructor of matrix by concatening input matrices
  *  @param iMatrices Rows or columns
  *  @param iRows     If true input matrices are rows otherwise columns
  */
  CATCDSMatrix(std::initializer_list<CATCDSMatrix> const& iMatrices, CATCDSBoolean iRows);
#endif

  CATCDSMatrix(CATCDS3x3Matrix const& iMatrix);

  /**
   *  Destructor.
   */
  virtual ~CATCDSMatrix();

  /**
   *  Get matrix element.
   *  @param iI
   *    row number of required element
   *  @param iJ
   *    column number of required element
   *  @return
   *    element of matrix as l-value
   */
  double& Element(int iI, int iJ)
  {
    CATCDSAssert(_n * iI + iJ >= 0 && _n * iI + iJ < Size());
    return _vector[_n * iI + iJ];
  }

  /**
   *  Get matrix element.
   *  @param iI
   *    row number of required element
   *  @param iJ
   *    column number of required element
   *  @return
   *    value of matrix element
   */
  double GetElement(int iI, int iJ) const
  {
    CATCDSAssert(_n * iI + iJ >= 0 && _n * iI + iJ < Size());
    return _vector[_n * iI + iJ];
  }

  CATCDSInline double& operator()(int iRow, int iCol)
  {
    CATCDSAssert(_n * iRow + iCol >= 0 && _n * iRow + iCol < Size());
    return _vector[_n * iRow + iCol];
  }

  CATCDSInline double operator()(int iRow, int iCol) const
  {
    CATCDSAssert(_n * iRow + iCol >= 0 && _n * iRow + iCol < Size());
    return _vector[_n * iRow + iCol];
  }

  /**
   * Get matrix row.
   * The user should never delete it,
   * neither use it after the matrix will be destroyed.
   * @param iRow
   *   row index (rows are indexed from 0)
   * @return
   *   a pointer to the matrix row (an array of double)
   */
  double* GetRow(int iRow) const
  {
    // <= instead of < because GetRow is very often called to retrieve buffer
    CATCDSAssert(iRow >= 0 && iRow <= _m);
    return GetBuffer() + iRow * _n;
  }

  void SetRow(int iRow, const double* iaCoef);
  void SetRows(int iStartRow, int iNbRows, const double* iaCoef);

  void AppendRow(const double* iaCoef);
  void AppendRows(int iNbRows, const double* iaCoef);

  void AppendRows(const CATCDSMatrix& iMatrix);

  void ZeroRow(int iRow);
  void ZeroRows(int iStartRow, int iNbRows);

  /**
   *  Get number of columns.
   *  @return
   *    number of columns
   */
  int GetNbOfCol() const
  {
    return _n;
  }

  /**
   *  Get number of rows.
   *  @return
   *    number of rows
   */
  int GetNbOfRow() const
  {
    return _m;
  }

  /**
   *  Get values buffer.
   */
  double* GetBuffer() const { return const_cast<double*>(CATCDSArray<double>::GetBuffer()); }

#ifdef CPP11_AVAILABLE
  cds::span<double> GetSpan() { CATCDSArray<double> &base = *this; return base; }
  cds::span<double const> GetSpan() const { CATCDSArray<double> const &base = *this; return base; }
#endif

  /**
   *  Resize matrix to given dimensions.
   *  @param iNbRow
   *    new number of rows
   *  @param iNbCol
   *    new number of columns
   */
  void Resize(int iNbRow, int iNbCol)
  {
    _m = iNbRow;
    _n = iNbCol;
    CATCDSArray<double>::Size(iNbRow * iNbCol);
  }

  /*
   * Pre-allocate at least given size
   * @param iSize Size to reserve
   */
  void Reserve(int iSize)
  {
    CATCDSArray<double>::Reserve(iSize);
  }

  /**
   *  Transpose matrix.
   */
  void Transpose();

  /**
   *  Solve linear system through SVD decomposition.
   *  Parameters size assumed is equal to current matrix columns number.
   *  @param iB
   *    array, containing right-hand part
   *  @param oX
   *    obtained solution
   *  @param iScale
   *    cut-off scale factor
   *  @result
   *    FALSE if failed, TRUE otherwise
   */
  CATCDSBoolean SolveSVD(const double iB[], double oX[], double iScale = -1.0);

  /**
   *  Compute matrix kernel through SVD decomposition.
   *  Parameters size assumed is equal to current matrix columns number.
   *  @param oKernel
   *    kernel of matrix will be placed here
   *  @param iScale
   *    cut-off scale factor
   *  @result
   *    FALSE if failed, TRUE otherwise
   */
  CATCDSBoolean KernelSVD(CATCDSMatrix& oKernel, double iScale = -1.);

  /**
   *  Solve linear system through Gauss-Jordan elimination method.
   *  Parameters size assumed is equal to current matrix columns number.
   *  @param iaB
   *    array, containing right-hand part
   *  @param oaX
   *    obtained solution
   *  @param iMinimizeNorm
   *    if TRUE, try to find solution with minimal norm
   *  @param opKernel
   *    if nonzero then kernel of matrix will be placed here
   *  @param iaPriorities
   *    if nonzero, minimize solution norm with priorities
   *  @param iZeroPivot
   *    threshold value
   *  @param iUseBTM
   *    if TRUE, use block triangular matrix
   *    if FALSE, use sparse matrix
   */
  void SolveGaussJordan(unsigned int iCDSLevel,
    const double* iaB,
    double* oaX,
    CATCDSBoolean iMinimizeNorm = FALSE,
    CATCDSMatrix* opKernel = 0,
    const int* iaPriorities = 0,
    double iZeroPivot = 1e-10 /*, //@NumValidated
                        CATCDSBoolean iUseBTM = FALSE*/
  );

  //void BlockDecompose(unsigned int iCDSLevel, int *oaShif, double iZeroPivot = 1e-10);

  /**
   *  Performs Gramm-Schmidt orthogonalization on given matrix.
   *  @param iThreshold
   *    a threshold value used for rank determination
   *  @param oaSquare
   *    store square of euclidean norm for vectors
   *  @result
   *    rank of the matrix
   */
  int Orthogonalize(double iThreshold, double* oaSquare = 0);

  /**
   *  Performs normalization of rows of given matrix using Euclidean norm.
   *  @param iThreshold
   *    a threshold value used for rank determination
   */
  void Normalize(double iThreshold);

  /**
   *  Zeroing all matrix elements.
   */
  void SetZero();

  /**
   * Make Identity matrix
   */
  void SetIdentity(int iDimension = -1);

  /**
   *  Matrix multiplication.
   *  <b>*this</b> matrix is multiplied by operator argument.
   *  @param iA
   *    multiplier
   *  @result
   *    ((*this) * iA) product
   */
  CATCDSMatrix operator*(CATCDSMatrix const& iA) const;
  CATCDSVector operator*(CATCDSVector const& iV) const;
  CATCDSVector operator*(double const* iaVector) const;

  /**
   *  Scalar multiplication operator.
   *  @param iReal
   *    scalar multiplicand
   *  @return
   *    <b>*this</b> object
   */
  CATCDSMatrix& operator*=(double iReal);

  void MultiplyLeft(CATCDSMatrix const& iMatrix);
  CATCDSVector MultiplyVectorLeft(CATCDSVector const& iVector) const;

  CATCDSMatrix& operator+=(const CATCDSMatrix& iA);
  CATCDSMatrix operator+(const CATCDSMatrix& iA) const;
  CATCDSMatrix& operator-=(const CATCDSMatrix& iA);
  CATCDSMatrix operator-(const CATCDSMatrix& iA) const;

  CATCDSMatrix GetSubMatrix(int iStartColum, int iStartRow, int iWidth, int iHeight) const;
  /**
	@brief Put the matrix iToSet into the current matrix at the positon iStartColum,iStartRow
	if (iStartColum+iToSet.GetNbOfCol()> this.GetNbOfCol()) do nothing and return FALSE
	if (iStartRow+iToSet.GetNbOfRow()> this.GetNbOfRow()) do nothing and return FALSE
	otherwise return TRUE
  */
  //// ---------- WARNING ------------------
  // Fisrt index is a column index although we start with the row index in all other methods !!!!!!!!! (grrr)
  // ---------------------------------------
  CATCDSBoolean SetSubMatrix(int iStartColum, int iStartRow, const CATCDSMatrix& iToSet);

  /**
  @brief  Return a matrix containing all the rows in [iStartRow, iLastRow]
  */
  CATCDSMatrix GetRows(int iStartRow, int iLastRow) const;
  void GetRows(int iStartRow, int iLastRow, CATCDSMatrix& oMatrix) const;

  /**
  @brief  Return a matrix containing all the colmuns in [iStartCol, iLastCol]
  */
  CATCDSMatrix GetColumns(int iStartCol, int iLastCol) const;
  void GetColumns(int iStartCol, int iLastCol, CATCDSMatrix& oMatrix) const;

  /**
   *  Write matrix in MAPLE format, if iPrintValues == TRUE
   *  or write its structure (* for nonzero elements, 0 for zero elements)
   */
#ifdef CDS_DEBUG
  virtual void Write(const char* iName) const;
  virtual void Write(const char* iName, CATCDSStream* ipOutput) const;

  void SetNames(CATCDSString const* iaRowNames, CATCDSString const* iaColumnNames);

  CATCDSString const* GetRowNames() const { return _aRowNames; }
  CATCDSString const* GetColumnNames() const { return _aColumnNames; }
#endif

  /**
   *  Perform SVD factorization (<b>*this</b> == U*W*V`).
   *  @param oMatrixU
   *    rectangular matrix U (U`*U=I)
   *  @param oDiagW
   *    diagonal elements of matrix W
   *  @param
   *    orthogonal matrix V
   *  @result
   *    FALSE if failed, TRUE otherwise
   */
  CATCDSBoolean FactorisationSVD(CATCDSMatrix& oMatrixU, double oDiagW[], CATCDSMatrix& oMatrixV) const;

  /**
   *  Perform zeroing of singular values of matrix.
   *  @param ioDiagW
   *    array of singular values of matrix
   *  @param iScale
   *    zeroing coefficient
   */
  void ZeroingSVD(double ioDiagW[], double iScale = -1.0);

  /**
   *  Resolve linear system, using SVD decomposition.
   *  @param iMatrixU
   *    rectangular matrix U
   *  @param iDiagW
   *    diagonal elements of matrix W
   *  @param iMatrixV
   *    orthogonal matrix V
   *  @param iB
   *    right hand side vector
   *  @param oX
   *    obtained solution
   */
  void ResolveSVD(const CATCDSMatrix& iMatrixU,
    const double iDiagW[],
    const CATCDSMatrix& iMatrixV,
    const double iB[],
    double oX[]) const;

  /**
   *  Performs limited gauss elimination: pivots can be chosen only from submatrix limited by iStartRow,
   *  iStartColumn and iFinishColumn, eliminations are performed only in columns from iStartColumn to right.
   *
   *  @param iStartRow
   *    upper bound of elimination submatrix
   *  @param iStartColumn
   *    left bound of elimination submatrix
   *  @param iFinishColumn
   *    right bound of elimination submatrix
   *  @param iThreshold
   *    constant used as limit for ignore of tiny values in matrix
   *  @result
   *    number of independent rows in submatrix with columns from left to iFinishColumn
   */
  int ReduceSubmatrix(int iStartRow, int iStartColumn, int iFinishColumn, double iThreshold = 1e-10); //@NumValidated

  /**
   *  Performs standard gauss elimination and
   *  moves independent rows in upper part of matrix
   *  @result
   *    Number of independent rows in matrix
   */
  int PerformGaussElimination(double iThreshold, CATCDSBoolean iKeepThreshold = FALSE);

  void MinimizeNorm(double* ioaX, const int* iaPriorities, double iThreshold);

  /**
   *  Get Euclidean norm of matrix.
   */
  double GetNorm2(int iRow = -1) const;

  static double Norm2(int iN, double const* iaValues);

  /**
   *  Get Infinite norm of matrix.
   */
  double GetNormInf(int iRow = -1) const;

  static double NormInf(int iN, double const* iaValues);

  CATCDSInline int GetSize() const
  {
    return _n * _m;
  }

  /**
  * Maximise cT*x with respect to Ax = b and x >= 0 where c is the cost vector and A the current matrix
  * @param ioSolution      The solution of maximisation problem (user input have to be a valid start point for the simplex algorithm, ie x >= 0 and Ax = b)
  * @param iCostVector     The cost vector which defines the function cT*x to maximise
  * @param iB              The second member in equality contraint Ax = b
  * @param iBreakIfGreater Stops algorithm and return current solution when best solution is greater than this value
  * @param iZeroPivot      Constant used as limit for ignore of tiny values in matrix
  * @return                0 If the maximum was found
  *                        1 If no solution was found
  *                        2 If problem is unbound
  */
  int SimplexMaximisation(CATCDSVector& ioSolution, CATCDSVector const& iCostVector, CATCDSVector const& iB, double iBreakIfGreater, double iZeroPivot = 1e-10) const; //@NumValidated

  /**
   * Compute a valid start point for the simplex problem Ax = b where A is current matrix
   * @param oStartPoint  Start point result
   * @param iB           The second member in equality contraint Ax = b
   * @param iZeroPivot   Constant used as limit for ignore of tiny values in matrix
   * @return             TRUE if a valid start point was found, FALSE otherwise
   */
  CATCDSBoolean InitializeSimplexStartPoint(CATCDSVector& oStartPoint, CATCDSVector const& iB, double iZeroPivot = 1e-10) const; //@NumValidated

  /**
  * create the matrix Z (null space) 
  * @param int oRank rank of the matrix 
  * @param CATCDSMatrix oY size is MxoRank
  * @param CATCDSMatrix oZ matrix of size is Mx(N-oRank)
  * this null space is computed using QR decomposition
  */
  CATCDSBoolean FindNullSpace(int& oRank, CATCDSMatrix& oY, CATCDSMatrix& oZ) const;

  /**
  * Inverse a matrix with SVD factorisation, should be use with caution (may be time expensive)
  * @param oInverse     The result of matrix inversion
  */
  CATCDSBoolean InverseSVD(CATCDSMatrix& oInverse) const;

  /**
  * Inverse a matrix with QR decomposition (mandatory : number of rows >= number of columns)
  * @param oInverse     The result of matrix inversion
  */
  CATCDSBoolean InverseQR(CATCDSMatrix& oInverse) const;

  /**
  * @brief merge the 2 matrix A and B along line or column.
  *
  * To be merge in column A.GetNbOfCol must be equal to B.GetNbOfCol
  * the result of the merge will be the matrix M = [A]
  *                                                [B]
  *
  * To be merge in line A.GetNbOfRow must be equal to B.GetNbOfRow
  * the result of the merge will be the matrix M = [A][B]
  *                                                
  * if the condition on line or colum are not true, the function return a matrix of size 0x0
  *
  * @param iA First Matrix to be merged
  * @param iB Second Matrix to be merged
  * @param iInColumn select the direction of merge TRUE means in colum A will be in top of B, FALSE mean in line A will be on left of B.
  *
  */
  static CATCDSMatrix MergeMatrix(const CATCDSMatrix& iA, const CATCDSMatrix& iB, CATCDSBoolean iInColumn);

  /**
   * Add iC * iM to this matrix
   * this and iM are assumed to have same dimensions
   * @param iC Coefficient
   * @param iM added matrix
   */
  void Add(double iC, CATCDSMatrix const& iM);

  /**
   * Compute matrix trace
   * Matrix is assumed to be square
   * @return matrix trace
   */
  double Trace() const;

#ifdef CDS_DEBUG
  void ScilabDump(const char* iName, CATCDSStream* ipOutput) const;
#endif

protected:
  int _n; // Number of columns.
  int _m; // Number of rows.

#ifdef CDS_DEBUG
  CATCDSString* _aRowNames;
  CATCDSString* _aColumnNames;
#endif

  // Vector constructors
  CATCDSMatrix(int iNbElements, double const* iTable)
    : CATCDSArray<double>(iNbElements)
    , _m(1)
    , _n(iNbElements)
#ifdef CDS_DEBUG
    , _aRowNames(0)
    , _aColumnNames(0)
#endif
  {
    if (iTable)
      CATCDSArray<double>::operator=(iTable);
  }

private:
  CATCDSBoolean QRFactors(const int iM, const int iN, const double* ioR, double* ow) const;
};

ExportedByCDSMathematics CATCDSMatrix operator*(double scalar, const CATCDSMatrix& iA);
ExportedByCDSMathematics CATCDSMatrix operator*(const CATCDSMatrix& iA, double scalar);
ExportedByCDSMathematics CATCDSMatrix operator-(CATCDSMatrix const& iA);

#ifdef CPP11_AVAILABLE
inline CATCDSMatrix::CATCDSMatrix(int iNbRow, int iNbCol, cds::span<double const> iSpan)
  : CATCDSMatrix(iNbRow, iNbCol, iSpan.data())
{
  CATCDSAssert(iSpan.size() == iNbRow * iNbCol);
}

inline CATCDSMatrix& CATCDSMatrix::operator=(cds::span<double const> iSpan)
{
  CATCDSAssert(iSpan.size() == GetNbOfRow() * GetNbOfCol());
  return operator=(iSpan.data());
}
#endif

inline CATCDSMatrix CATCDSMatrix::GetRows(int iStartRow, int iLastRow) const
{
  return GetSubMatrix(0, iStartRow, GetNbOfCol(), iLastRow - iStartRow + 1);
}

inline void CATCDSMatrix::GetRows(int iStartRow, int iLastRow, CATCDSMatrix& oMatrix) const
{
  oMatrix = GetRows(iStartRow, iLastRow);
}

inline CATCDSMatrix CATCDSMatrix::GetColumns(int iStartCol, int iLastCol) const
{
  return GetSubMatrix(iStartCol, 0, iLastCol - iStartCol + 1, GetNbOfRow());
}

inline void CATCDSMatrix::GetColumns(int iStartCol, int iLastCol, CATCDSMatrix& oMatrix) const
{
  oMatrix = GetColumns(iStartCol, iLastCol);
}

inline CATCDSMatrix Transpose(CATCDSMatrix const& iMatrix)
{
  CATCDSMatrix res(iMatrix);
  res.Transpose();
  return res;
}

inline void CATCDSMatrix::Add(double iC, CATCDSMatrix const& iM)
{
  *this += iC * iM;
}

#endif /* CATCDSMatrix_H */
