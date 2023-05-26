// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
//
// CATCDSVector:
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

#ifndef CATCDSVector_H
#define CATCDSVector_H

#include "CATCDSAssert.h"
#include "CATCDSMatrix.h"
#include "CDSMathematics.h"

class ExportedByCDSMathematics CATCDSVector : public CATCDSMatrix
{
public:
  CATCDSVector();
  CATCDSVector(CATCDSVector const& iVector);
  CATCDSVector& operator=(CATCDSVector const& iVector);
#ifdef CPP11_AVAILABLE
  CATCDSVector(CATCDSVector&& iVector);
  CATCDSVector& operator=(CATCDSVector&& iVector);
  explicit CATCDSVector(cds::span<double const> iSpan);
#endif

  /**
     *  Constructor of vector of given size and initial values.
     *  @param iNbElements
     *    vector size
     *  @param iTable
     *    pointer to array of initial values, NULL pointer is acceptable
     */
  CATCDSVector(int iNbElements, const double* iTable = 0);

  /**
   *  Constructor of vector of given size and initial values.
   *  @param iNbElements
   *    vector size
   *  @param val
   *    double value for all coefficients
   */
  CATCDSVector(int iNbElements, double iVal);
  /**
   *  Copy operator.
   *  @param iTable
   *    array of doubles to be copied
   *  @return
   *    <b>*this</b> object
   */
  CATCDSVector& operator=(const double* iTable);

  /**
   *  Adding operator.
   *  @param iTable
   *    vector to be added
   *  @return
   *    <b>*this</b> object
   */
  CATCDSVector& operator+=(const CATCDSVector& iVector);

  /**
   *  Adding operator.
   *  @param iTable
   *    array of double to be added
   *  @return
   *    <b>*this</b> object
   */
  CATCDSVector& operator+=(const double* iaTable);

  void Add(double iCoef, const double* iaTable);

  /**
   *  Subtraction operator.
   *  @param iTable
   *    vector to be subtracted
   *  @return
   *    <b>*this</b> object
   */
  CATCDSVector& operator-=(const CATCDSVector& iVector);

  /**
   *  Subtraction operator.
   *  @param iTable
   *    array of double to be subtracted
   *  @return
   *    <b>*this</b> object
   */
  CATCDSVector& operator-=(const double* iaTable);

  /**
   *  Scalar multiplication operator.
   *  @param iReal
   *    scalar multiplicand
   *  @return
   *    <b>*this</b> object
   */
  CATCDSVector& operator*=(double iReal);

  /**
   *  Scalar multiplication operator.
   *  @param iReal
   *    scalar multiplicand
   *  @return
   *    <b>*this</b> object
   */
  double operator*(const CATCDSVector& iVector) const;

  CATCDSVector operator+(const CATCDSVector& iA) const;

  CATCDSVector operator-(const CATCDSVector& iA) const;

  CATCDSVector operator*(double iVal) const;

  /**
  *  GramProduct.
  *  compute the product v*v^t
  *  @return
  *    <b>CATCDSMatrix</b> object
  */
  CATCDSMatrix GramProduct() const;

  /**
   *  Get vector element.
   *  @param iInd
   *    number of required element
   *  @return
   *    element of vector as l-value
   */
  double& Element(int iInd)
  {
    CATCDSAssert(iInd >= 0 && iInd < Size());
    return _vector[iInd];
  }

  /**
   *  "Array-access" operator.
   *  @param iInd
   *    number of required element
   *  @return
   *    element of vector as l-value
   */
  double& operator[](int iInd)
  {
    CATCDSAssert(iInd >= 0 && iInd < Size());
    return _vector[iInd];
  }

  /**
   *  Get vector element.
   *  @param iInd
   *    number of required element
   *  @return
   *    value of vector element
   */
  double GetElement(int iInd) const
  {
    CATCDSAssert(iInd >= 0 && iInd < Size());
    return _vector[iInd];
  }

  double operator[](int iInd) const
  {
    CATCDSAssert(iInd >= 0 && iInd < Size());
    return _vector[iInd];
  }

  CATCDSBoolean operator>(double iVal) const
  {
    CATCDSBoolean isBigger = TRUE;
    for (int i = 0; i < _n; i++)
    {
      if (_vector[i] < iVal)
      {
        isBigger = FALSE;
        break;
      }
    }
    return isBigger;
  }

  void Resize(int iNewSize)
  {
    _n = iNewSize;
    CATCDSArray<double>::Size(iNewSize);
  }

  void Append(double iValue)
  {
    _n++;
    CATCDSArray<double>::Append(iValue);
  }

  void Insert(int iIdx, double iValue)
  {
    _n++;
    CATCDSArray<double>::Insert(iIdx, iValue);
  }

  static double ScalarProduct(int iN, double const* iaVector1, double const* iaVector2);
};

inline CATCDSVector::CATCDSVector()
  : CATCDSMatrix(1, 0)
{
}

inline CATCDSVector::CATCDSVector(CATCDSVector const& iVector)
  : CATCDSMatrix(iVector)
{
}

inline CATCDSVector& CATCDSVector::operator=(CATCDSVector const& iVector)
{
  CATCDSMatrix::operator=(iVector);
  return *this;
}

#ifdef CPP11_AVAILABLE
inline CATCDSVector::CATCDSVector(CATCDSVector&& iVector)
  : CATCDSMatrix(std::move(iVector))
{
}

inline CATCDSVector& CATCDSVector::operator=(CATCDSVector&& iVector)
{
  CATCDSMatrix::operator=(std::move(iVector));
  return *this;
}

inline CATCDSVector::CATCDSVector(cds::span<double const> iSpan)
  : CATCDSVector(iSpan.size(), iSpan.data())
{
}
#endif

inline CATCDSVector::CATCDSVector(int iNbElements, const double* iTable)
  : CATCDSMatrix(iNbElements, iTable)
{
}

inline CATCDSVector::CATCDSVector(int iNbElements, double iVal)
  : CATCDSMatrix(1, iNbElements, iVal)
{
}

inline CATCDSVector& CATCDSVector::operator=(const double* iTable)
{
  CATCDSArray<double>::operator=(iTable);
  return *this;
}

#endif /* CATCDSVector_H */
