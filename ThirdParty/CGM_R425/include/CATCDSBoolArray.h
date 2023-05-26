// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATCDSBoolArray.h
// Header definition of CATCDSBoolArray
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2009  Creation:                Evgueni ROUKOLEEVint
//===================================================================
#ifndef CATCDSBoolArray_H
#define CATCDSBoolArray_H

#include "CATCDSArray.h"
#include "CATCDSBoolean.h"
#include "CATCDSInline.h"
#include "CATCDSUtilities.h"

//-----------------------------------------------------------------------

class ExportedByCATCDSUtilities CATCDSBoolArray : protected CATCDSArray<CATCDSBoolean>
{
public:
  CATCDSBoolArray();
  CATCDSBoolArray(int iSize, CATCDSBoolean iFillValue);
  CATCDSBoolArray(CATCDSBoolArray const& iArray);
  CATCDSBoolArray& operator=(CATCDSBoolArray const& iArray);
#ifdef CPP11_AVAILABLE
  CATCDSBoolArray(CATCDSBoolArray&& iArray);
  CATCDSBoolArray& operator=(CATCDSBoolArray&& iArray);
#endif

  /**
   * Resize to specified length and fill with given value.
   */
  void Fill(int iLength, CATCDSBoolean iFillValue);

  /**
   * Increase size of specified length and fill with given value.
   */
  void IncreaseSize(int iLength, CATCDSBoolean iFillValue)
  {
    CATCDSArray<CATCDSBoolean>::Resize(CATCDSArray<CATCDSBoolean>::Size() + iLength, iFillValue);
    _nbBits += iFillValue ? iLength : 0;
  }

  /**
   * Add the specified value of the end of the array
   */
  void Append(CATCDSBoolean iValue)
  {
    CATCDSArray<CATCDSBoolean>::Append(iValue);
    _nbBits += iValue;
  }

  /**
   * Set iIdx element.
   */
  void Set(int iIdx, CATCDSBoolean iValue = TRUE);

  /**
   * Set all values
   */
  void Set(CATCDSBoolean* iaValues);

  /**
   * Return iIdx element.
   */
  CATCDSBoolean operator[](int iIdx) const
  {
    return CATCDSArray<CATCDSBoolean>::operator[](iIdx);
  }

  /**
   * Return iIdx element, range check will be performed.
   */
  CATCDSBoolean IsSet(int iIdx) const
  {
    return CATCDSArray<CATCDSBoolean>::operator[](iIdx);
  }

  /**
   * Return TRUE if contains TRUE values.
   */
  CATCDSBoolean IsAny() const
  {
    return _nbBits != 0;
  }

  /**
   * Return number of TRUE values
   */
  int Count() const
  {
    return _nbBits;
  }

  /**
   * Return values buffer.
   */
  CATCDSBoolean const* GetBuffer() const
  {
    return CATCDSArray<CATCDSBoolean>::GetBuffer();
  }

  CATCDSBoolean* GetBuffer()
  {
    return CATCDSArray<CATCDSBoolean>::GetBuffer();
  }

  /**
   * Count for TRUE values; used after GetBuffer() call.
   */
  void Check();

  /**
   * Return current length.
   */
  int Size() const
  {
    return CATCDSArray<CATCDSBoolean>::Size();
  }

  /**
   * Inverse values.
   */
  void Inverse();

private:
  int _nbBits;
};

//-----------------------------------------------------------------------

inline CATCDSBoolArray::CATCDSBoolArray()
  : _nbBits(0)
{
}

inline CATCDSBoolArray::CATCDSBoolArray(int iSize, CATCDSBoolean iFillValue)
  : CATCDSArray<CATCDSBoolean>(iSize, iFillValue)
  , _nbBits(iFillValue ? iSize : 0)
{
}

inline CATCDSBoolArray::CATCDSBoolArray(CATCDSBoolArray const& iArray)
  : CATCDSArray<CATCDSBoolean>(iArray)
  , _nbBits(iArray._nbBits)
{
}

inline CATCDSBoolArray& CATCDSBoolArray::operator=(CATCDSBoolArray const& iArray)
{
  CATCDSArray<CATCDSBoolean>::operator=(iArray);
  _nbBits = iArray._nbBits;
  return *this;
}

#ifdef CPP11_AVAILABLE
inline CATCDSBoolArray::CATCDSBoolArray(CATCDSBoolArray&& iArray)
  : CATCDSArray<CATCDSBoolean>(std::move(iArray))
  , _nbBits(iArray._nbBits)
{
  iArray._nbBits = 0;
}

inline CATCDSBoolArray& CATCDSBoolArray::operator=(CATCDSBoolArray&& iArray)
{
  CATCDSArray<CATCDSBoolean>::operator=(std::move(iArray));
  std::swap(_nbBits, iArray._nbBits);
  return *this;
}
#endif

#endif
