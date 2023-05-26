// COPYRIGHT DASSAULT SYSTEMES 2004
//=============================================================================
//
// CATCDSSparseMatrix:
//
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Mar 2004  Creation                               A. Leshchenko
//=============================================================================

#ifndef CATCDSSparseMatrix_H
#define CATCDSSparseMatrix_H

#include "CATCDSVirtual.h"
#include "CATCDSBoolean.h"
#include "CDSMathematics.h"
#include "CATCDSMatrix.h"
#include "CATCDSDebug.h"

class CATCDSThread;

class ExportedByCDSMathematics CATCDSSparseMatrix : public CATCDSMatrix
{
public:
  /**
   *  Default constructor of empty matrix.
   */
  CATCDSSparseMatrix();

  /**
   *  Copy constructor.
   *  @param iMatrix
   *    matrix to be copied
   */
  CATCDSSparseMatrix(const CATCDSSparseMatrix &iMatrix);

  /**
   *  Copy operator.
   *  @param iMatrix
   *    matrix to be copied.
   *  @return
   *    <b>*this</b> object
   */
  CATCDSSparseMatrix& operator =(const CATCDSSparseMatrix &iMatrix);

  /**
   *  Copy operator.
   *  @param iTable
   *    array of doubles to be copied
   *  @return
   *    <b>*this</b> object
   */
  CATCDSSparseMatrix& operator =(const double *iTable);

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
  CATCDSSparseMatrix(int iNbRow, int iNbCol, const double *iTable = 0);

  /**
   *  Destructor.
   */
  virtual ~CATCDSSparseMatrix();

  /**
   *  Get matrix element.
   *  @param iI
   *    row number of required element
   *  @param iJ
   *    column number of required element
   *  @return
   *    element of matrix as l-value
   */
  CATCDSInline double& Element(int iI, int iJ);

  /**
   *  Get matrix element.
   *  @param iI
   *    row number of required element
   *  @param iJ
   *    column number of required element
   *  @return
   *    value of matrix element
   */
  CATCDSInline double GetElement(int iI, int iJ) const;

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
   *  Solve linear system through Gauss-Jordan elimination method.
   *  Parameters size assumed is equal to current matrix columns number.
   *  @param iaB
   *    array, containing right-hand part
   *  @param oaX
   *    obtained solution
   *  @param opKernel
   *    if nonzero then kernel of matrix will be placed here
   *  @param iZeroPivot
   *    threshold value
   */
  void ParallelSolveGaussJordan(unsigned int iCDSLevel,
                                const double *iaB,
                                double *oaX,
                                CATCDSMatrix *opKernel = 0,
                                double iZeroPivot = 1e-10); //@NumValidated
  void SolveGaussJordan(unsigned int iCDSLevel,
                        const double *iaB,
                        double *oaX,
                        CATCDSMatrix *opKernel = 0,
                        double iZeroPivot = 1e-10); //@NumValidated

  /**
   *  Check matrix element
   *  @param iI
   *    row number of required element
   *  @param iJ
   *    column number of required element
   *  @return
   *    FALSE if element has non-zero value, TRUE if element is zero
   */
  CATCDSInline CATCDSBoolean IsNonZero(int iI, int iJ) const;

  /**
   *  Mark matrix element as zero
   *  @param iI
   *    row number of required element
   *  @param iJ
   *    column number of required element
   */
  CATCDSInline void SetToZero(int iI, int iJ);

  /**
   *  Mark matrix element as non-zero
   *  @param iI
   *    row number of required element
   *  @param iJ
   *    column number of required element
   */
  CATCDSInline void SetToNonZero(int iI, int iJ);

  /**
   *  Write matrix in MAPLE format.
   */
#ifdef CDS_DEBUG
  virtual void Write(const char *iName) const CATCDSOverride;
#endif

  struct REFThreadData {
    REFThreadData() : _pMatrix(0), _pThread(0), _returnStatus(-1),
      _row(0), _col(0), _maxRow(0), _maxCol(0), _aB(0), _pivot(0.0), _level(-1) {}

    unsigned int _level;
    CATCDSSparseMatrix* _pMatrix;
    CATCDSThread *_pThread;
    int _returnStatus;
    int *_row;
    int *_col;
    int _maxRow;
    int _maxCol;
    double * _aB;
    double _pivot;
  };

  /**
   * Solve Gauss-Jordan in parallel threads (threads are created only once)
   */
  int SolveGaussJordanThread(REFThreadData &ioREFData);

  /**
   * Fill _nzbuf
   */
  void Init();

private:
  int ParallelFindPivot(REFThreadData &ioREFData) const;
  int ParallelSubtractRows(REFThreadData &ioREFData);
#if 0
  void Check() const;
#endif

public:
  // needed for BlockTriangularMatrix
  double FindPivot(unsigned int iCDSLevel, int iI, int iJ, int &oI, int &oJ) const;
  void SwapRows(int iI1, int iI2, int iJStart = 0);
  void SwapCols(int iJ1, int iJ2);
  void ClearCol(int iCol, int iStart);
  void MultRow(int iI, double iVal, int iJStart = 0);
  // subtract row iRowTo from iRow. Subtraction begins from (iJStart+1) element
  void SubtractRowByFactor(int iRowTo, int iRow, int iJStart, double factor);

protected:
  /**
   *  Buffer for nonzero indicators values.
   */
  CATCDSBoolean *_nzbuf;
};

CATCDSInline int CATCDSSparseMatrix::GetNbOfCol() const
{
  return _n;
}

CATCDSInline int CATCDSSparseMatrix::GetNbOfRow() const
{
  return _m;
}

#define GTELC(i,j) (_vector[(i)*_n+(j)])

CATCDSInline double& CATCDSSparseMatrix::Element(int iI, int iJ)
{
  return GTELC(iI,iJ);
}

CATCDSInline double CATCDSSparseMatrix::GetElement(int iI, int iJ) const
{
  return GTELC(iI,iJ);
}

CATCDSInline CATCDSBoolean CATCDSSparseMatrix::IsNonZero(int iI, int iJ) const
{
  return _nzbuf[iI*_n+iJ];
}

CATCDSInline void CATCDSSparseMatrix::SetToZero(int iI, int iJ)
{
  _nzbuf[iI*_n+iJ] = FALSE;
}

CATCDSInline void CATCDSSparseMatrix::SetToNonZero(int iI, int iJ)
{
  _nzbuf[iI*_n+iJ] = TRUE;
}

#endif /* CATCDSSparseMatrix_H */
