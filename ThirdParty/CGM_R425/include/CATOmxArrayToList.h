#ifndef __CATOmxArrayConvert_H
#define __CATOmxArrayConvert_H

#include "CATOmxArray.h"
#include "CATUnicodeString.h"
class CATListValCATUnicodeString;

/**
 * Convert a CATOmxArray<XXX> to a CATListOfXXX
 * example:
 *   const CATOmxArray<CATUnicodeString> arrayIn = ... ;
 *   CATListValCATUnicodeString listOut;
 *   CATOmxArrayToList(arrayIn,listOut);
 * => listOut contains now the same as arrayIn
 */
template<class CATOmxArrayOfXXX,class CATListOfXXX>
inline void CATOmxArrayToList(const CATOmxArrayOfXXX& src,CATListOfXXX& dst)
{
  const int size = src.Size();
  //nope, CATListOfXXX::Size(int ), which means Resize may not be available...and crashes in some cases !
  //dst.Size(size);
  //for(int i=1; i<=size; i++)
  //  dst[i] = src[i];
  dst.~CATListOfXXX();
  new(&dst) CATListOfXXX(size);
  for(int i=1; i<=size; i++)
    dst.Append(src[i]);
}

/**
 * Convert a CATListOfXXX to a CATOmxArray<XXX>
 * example:
 *   const CATListValCATUnicodeString listIn = ... ;
 *   CATOmxArray<CATUnicodeString> arrayOut = ... ;
 *   
 *   CATOmxListToArray(listIn,arrayOut);
 * => arrayOut contains now the same as listIn
 */
template<class CATListOfXXX,class CATOmxArrayOfXXX>
inline void CATOmxListToArray(const CATListOfXXX& src,CATOmxArrayOfXXX& dst)
{
  const int size = src.Size();
  dst.RemoveAll(TRUE);
  for(int i=1; i<=size; i++)
    dst.QuickAppend(src[i],size);
}

template<>
ExportedByCATOmxKernel void CATOmxArrayToList<CATOmxArray<CATUnicodeString>,CATListValCATUnicodeString>(const CATOmxArray<CATUnicodeString>& src,CATListValCATUnicodeString& dst);

template<>
ExportedByCATOmxKernel void CATOmxListToArray<CATListValCATUnicodeString,CATOmxArray<CATUnicodeString> >(const CATListValCATUnicodeString& src,CATOmxArray<CATUnicodeString>& dst);

#endif
