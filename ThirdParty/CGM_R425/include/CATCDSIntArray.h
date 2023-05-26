// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATCDSIntArray.h
// Header definition of CATCDSIntArray
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2009  Creation:                Evgueni ROUKOLEEVint
//===================================================================
#ifndef CATCDSIntArray_H
#define CATCDSIntArray_H

#define USE_STL_ALGORITHM

#include "CATCDSArray.h"
#include "CATCDSAssert.h"
#include "CATCDSBoolean.h"
#include "CATCDSInline.h"
#include "CATCDSUtilities.h"

class CATCDSBoolArray;

//-----------------------------------------------------------------------

class ExportedByCATCDSUtilities CATCDSIntArray : protected CATCDSArray<int>
{
public:
  CATCDSIntArray();
  CATCDSIntArray(int iSize, int iFillValue);
  CATCDSIntArray(int iNbRows, int iNbColumns, int iFillValue);
  CATCDSIntArray(const CATCDSIntArray& iArray);
  CATCDSIntArray& operator=(const CATCDSIntArray& iArray);
#ifdef CPP11_AVAILABLE
  CATCDSIntArray(CATCDSIntArray&& iArray);
  CATCDSIntArray& operator=(CATCDSIntArray&& iArray);
#endif

  /**
   * Set second dimension.
   */
  void SetDimension(int iDimension)
  {
    if (iDimension > 0)
      _dimension = iDimension;
  }

  /**
   * Resize to specified length and fill with given value.
   */
  void Fill(int iLength, int iFillValue);

  /**
   * Fill array with indices of TRUE values.
   */
  int FillIdxFrom(const CATCDSBoolArray& iBits);

  /**
   * Fill array with indices of its positive values.
   */
  int MapIdxOfPositive();

  /**
   * Return array element.
   */
  int& operator[](int iIdx)
  {
    CATCDSAssert(iIdx >= 0 && iIdx < Size());
    return _vector[iIdx];
  }

  int operator[](int iIdx) const
  {
    CATCDSAssert(iIdx >= 0 && iIdx < Size());
    return _vector[iIdx];
  }

  /**
   * Resize array & set element
   */
  void Set(int iIdx, int iValue)
  {
    CATCDSArray<int>::Set(iIdx, iValue);
  }

  /**
   * Append value.
   */
  void Append(int iValue)
  {
    CATCDSArray<int>::Append(iValue);
  }

  /**
   * Access element of 2-dimensional array.
   */
  int& operator()(int iRow, int iCol)
  {
    CATCDSAssert(_dimension * iRow + iCol >= 0 && _dimension * iRow + iCol < Size());
    return _vector[_dimension * iRow + iCol];
  }

  int const& operator()(int iRow, int iCol) const
  {
    CATCDSAssert(_dimension * iRow + iCol >= 0 && _dimension * iRow + iCol < Size());
    return _vector[_dimension * iRow + iCol];
  }

  /**
   * Return second dimension of 2-dimensional array.
   */
  int GetNbOfColumns() const
  {
    return _dimension;
  }

  /**
   * Get row of 2-dimensional array, resize if necessary.
   */
  int* GetRow(int iRow);

  /**
   * Return values buffer.
   */
  int* GetBuffer()
  {
    return CATCDSArray<int>::GetBuffer();
  }

  /**
   * Return const values buffer.
   */
  const int* GetBuffer() const
  {
    return CATCDSArray<int>::GetBuffer();
  }

  /**
   * Return current length.
   */
  int Size() const
  {
    return CATCDSArray<int>::Size();
  }

  /**
   * Build inverse mapping.
   */
  void BuildInverseMap(int iInverseMapSize, CATCDSIntArray& oInverseMap) const;

  /**
   * Sort array in ascending order.
   */
  void QuickSort();

  /**
   * Remove duplicate values from sorted array.
   */
  void RemoveDuplicates()
  {
    CATCDSArray<int>::RemoveDuplicates(true);
  }

  /**
   * Remove an element at the position iIndex
   */
  void RemoveAt(int iIndex)
  {
    CATCDSArray<int>::RemoveAt(iIndex);
  }

  /**
   * Search value in sorted array.
   * Return index of found value, or -1 if there is no such value.
   */
  int BinarySearch(int iValue) const;

  /**
  * Compute the intersection of the array of dim 1
  */
  void Intersect(const CATCDSIntArray& iArray, CATCDSIntArray& ioResultArray);

  /**
   * Resize to specified length
   */
  void Resize(int iLength, CATCDSBoolean iKeepValues)
  {
    CATCDSArray<int>::Size(iLength);
  }

  /**
   * Search value.
   * Return index of found value, or -1 if there is no such value.
   */
  int Locate(int iValue, int iFrom = 0) const
  {
    return CATCDSArray<int>::Locate(iValue, iFrom);
  }

  /*
   * Pre-allocate at least given size
   * @param iSize Size to reserve
   */
  void Reserve(int iSize)
  {
    CATCDSArray<int>::Reserve(iSize);
  }

  /**
   * Reverse element order
   */
  void Reverse()
  {
    CATCDSArray<int>::Reverse();
  }

private:
  int _dimension;
};

//-----------------------------------------------------------------------

inline CATCDSIntArray::CATCDSIntArray()
  : CATCDSArray<int>()
  , _dimension(1)
{
}

inline CATCDSIntArray::CATCDSIntArray(int iSize, int iFillValue)
  : CATCDSArray<int>(iSize, iFillValue)
  , _dimension(1)
{
}

inline CATCDSIntArray::CATCDSIntArray(int iNbRows, int iNbColumns, int iFillValue)
  : CATCDSArray<int>(iNbRows * iNbColumns, iFillValue)
  , _dimension(iNbColumns)
{
} // 2-dimensional array

inline CATCDSIntArray::CATCDSIntArray(const CATCDSIntArray& iArray)
  : CATCDSArray<int>(iArray)
  , _dimension(iArray._dimension)
{
}

inline CATCDSIntArray& CATCDSIntArray::operator=(const CATCDSIntArray& iArray)
{
  CATCDSArray<int>::operator=(iArray);
  _dimension = iArray._dimension;
  return *this;
}

#ifdef CPP11_AVAILABLE
inline CATCDSIntArray::CATCDSIntArray(CATCDSIntArray&& iArray)
  : CATCDSArray<int>(std::move(iArray))
  , _dimension(iArray._dimension)
{
}

inline CATCDSIntArray& CATCDSIntArray::operator=(CATCDSIntArray&& iArray)
{
  CATCDSArray<int>::operator=(std::move(iArray));
  std::swap(_dimension, iArray._dimension);
  return *this;
}
#endif

#endif
