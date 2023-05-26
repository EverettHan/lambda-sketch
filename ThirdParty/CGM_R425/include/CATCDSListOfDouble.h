// COPYRIGHT DASSAULT SYSTEMES 2010
//=============================================================================
//
// CATCDSListOfDouble:
//   Dynamic array of double.
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Nov 2010  Creation                                   D. Jennequin
//=============================================================================

#ifndef CATCDSListOfDouble_h
#define CATCDSListOfDouble_h

#include "CATCDSUtilities.h"
#include "CATCDSInline.h"
#include "CATCDSArray.h"

class ExportedByCATCDSUtilities CATCDSListOfDouble : protected CATCDSArray<double>
{
public:
  CATCDSInline CATCDSListOfDouble(int iInitAlloc = 0) : CATCDSArray<double>(iInitAlloc) {}
  CATCDSInline CATCDSListOfDouble(double const *iaValues, int iSize) : CATCDSArray<double>(iSize, iaValues) {}

  CATCDSInline void Append(double iValue)
  {
    CATCDSArray<double>::Append(iValue);
  }

  CATCDSInline void Append(const CATCDSListOfDouble& iList)
  {
    CATCDSArray<double>::Append(iList.begin(), iList.end() + iList.size());
  }

  CATCDSInline void Insert(double iValue, int iIdx)
  {
    CATCDSArray<double>::Insert(iIdx, iValue);
  }

  CATCDSInline int Size() const
  { 
    return CATCDSArray<double>::Size();
  }

  CATCDSInline void Size(int iSize)
  {
    CATCDSArray<double>::Size(iSize);
  }

  CATCDSInline void Size(int iSize, double iValue)
  {
    CATCDSArray<double>::Size(iSize, iValue);
  }

  CATCDSInline double& operator[](int iIdx) 
  { 
    return CATCDSArray<double>:: operator[](iIdx);
  }

  CATCDSInline double const & operator[](int iIdx) const
  { 
    return CATCDSArray<double>:: operator[](iIdx);
  }

  CATCDSInline int Locate(double iValue, int iFrom = 0) const
  {
    return CATCDSArray<double>::Locate(iValue, iFrom);
  }

  int RemoveValue(double iValue)
  {
    return CATCDSArray<double>::RemoveValue(iValue);
  }

  int Remove(const CATCDSListOfDouble& iList);

  void RemovePosition(int iIdx)
  {
    CATCDSArray<double>::RemoveAt(iIdx);
  }

  void RemoveAll()
  {
    CATCDSArray<double>::RemoveAll();
  }

  int RemoveNulls()
  {
    return CATCDSArray<double>::RemoveNulls();
  }

  CATCDSInline CATCDSBoolean operator==(const CATCDSListOfDouble& iList) const
  {
    return CATCDSArray<double>::operator==(iList);
  }

  CATCDSInline CATCDSBoolean operator!=(const CATCDSListOfDouble& iList) const
  {
    return CATCDSArray<double>::operator!=(iList);
  }
};

#endif
