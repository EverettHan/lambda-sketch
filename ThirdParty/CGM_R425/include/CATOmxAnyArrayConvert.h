#ifndef __CATOmxAnyArrayConvert_H
#define __CATOmxAnyArrayConvert_H

#include "CATOmxAny.h" 
#include "CATOmxArray.h"

/*
  various services for conversion between CATOmxArray or C raw arrays and CATOmxAny
  the services concerning CATOmxArray should be template but HP compiler
  crashes when mangling the methode names (perhaps too long identifier)
*/

inline CATOmxKind CppTypeToOmxKind(octet*) { return omx_octet; }
inline CATOmxKind CppTypeToOmxKind(int*) { return omx_int; }
inline CATOmxKind CppTypeToOmxKind(CATLONG64*) { return omx_int64; }
inline CATOmxKind CppTypeToOmxKind(double*) { return omx_double; }
inline CATOmxKind CppTypeToOmxKind(CATUnicodeString*) { return omx_string; }
inline CATOmxKind CppTypeToOmxKind(void**) { return omx_pointer; }
inline CATOmxKind CppTypeToOmxKind(IUnknown**) { return omx_IUnknown; }
inline CATOmxKind CppTypeToOmxKind(CATUuid*) { return omx_uuid; }

/**
 * build a CATOmxAny from a CATOmxArray
 * return code is useless (S_OK)
 */
inline HRESULT operator<<(CATOmxAny& iAny, const CATOmxArray<octet>& iArray) { return iAny.BuildFromArray(omx_octet, iArray); }
inline HRESULT operator<<(CATOmxAny& iAny, const CATOmxArray<int>& iArray) { return iAny.BuildFromArray(omx_int, iArray); }
inline HRESULT operator<<(CATOmxAny& iAny, const CATOmxArray<CATLONG64>& iArray) { return iAny.BuildFromArray(omx_int64, iArray); }
inline HRESULT operator<<(CATOmxAny& iAny, const CATOmxArray<double>& iArray) { return iAny.BuildFromArray(omx_double, iArray); }
inline HRESULT operator<<(CATOmxAny& iAny, const CATOmxArray<CATUnicodeString>& iArray) { return iAny.BuildFromArray(omx_string, iArray); }
inline HRESULT operator<<(CATOmxAny& iAny, const CATOmxArray<CATOmxKeyString>& iArray) { return iAny.BuildFromArray(omx_identifier, iArray); }
inline HRESULT operator<<(CATOmxAny& iAny, const CATOmxArray<void*>& iArray) { return iAny.BuildFromArray(omx_pointer, iArray); }
inline HRESULT operator<<(CATOmxAny& iAny, const CATOmxArray<IUnknown*>& iArray) { return iAny.BuildFromArray(omx_IUnknown, iArray); }
inline HRESULT operator<<(CATOmxAny& iAny, const CATOmxArray<CATUuid>& iArray) { return iAny.BuildFromArray(omx_uuid, iArray); }

/**
 * Converts a CATOmxAny to a CATOmxArray of a given type
 *
 * return code must be tested
 */
inline HRESULT operator>>(const CATOmxAny& iAny, CATOmxArray<octet>& oArray) { return iAny.CopyToArray(omx_octet, oArray); }
inline HRESULT operator>>(const CATOmxAny& iAny, CATOmxArray<int>& oArray) { return iAny.CopyToArray(omx_int, oArray); }
inline HRESULT operator>>(const CATOmxAny& iAny, CATOmxArray<CATLONG64>& oArray) { return iAny.CopyToArray(omx_int64, oArray); }
inline HRESULT operator>>(const CATOmxAny& iAny, CATOmxArray<double>& oArray) { return iAny.CopyToArray(omx_double, oArray); }
inline HRESULT operator>>(const CATOmxAny& iAny, CATOmxArray<CATUnicodeString>& oArray) { return iAny.CopyToArray(omx_string, oArray); }
inline HRESULT operator>>(const CATOmxAny& iAny, CATOmxArray<CATOmxKeyString>& oArray) { return iAny.CopyToArray(omx_identifier, oArray); }
inline HRESULT operator>>(const CATOmxAny& iAny, CATOmxArray<void*>& oArray) { return iAny.CopyToArray(omx_pointer, oArray); }
inline HRESULT operator>>(const CATOmxAny& iAny, CATOmxArray<IUnknown*>& oArray) { return iAny.CopyToArray(omx_IUnknown, oArray); }
inline HRESULT operator>>(const CATOmxAny& iAny, CATOmxArray<CATUuid>& oArray) { return iAny.CopyToArray(omx_uuid, oArray); }

ExportedByCATOmxKernel HRESULT operator<<(CATOmxAny& iAny, const CATOmxArray<bool>& iArray);
ExportedByCATOmxKernel HRESULT operator>>(const CATOmxAny& iAny, CATOmxArray<bool>& oArray);

/**
 * build a CATOmxAny from a C array
 */
template<typename T>
inline HRESULT CATOmxAnyBuildFromCArray(CATOmxAny& oAny, const T* iArray, int iSize)
{
  return oAny.BuildFromCArray(CppTypeToOmxKind((T*)0), iArray, iSize);
}

/**
 * copy content of a CATOmxAny to a C array
 */
template<typename T>
inline HRESULT CATOmxAnyCopyToCArray(const CATOmxAny& iAny, T* oArray)
{
  return iAny.CopyToCArray(CppTypeToOmxKind((T*)0), oArray);
}

#endif
