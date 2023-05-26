#ifndef __CATOmxStringUtils_H
#define __CATOmxStringUtils_H

#include "CATOmxPortability.h"
#include "CATUnicodeString.h"
#include "CATOmxArray.h"

/** sprintf */
ExportedByCATOmxKernel CATUnicodeString CATOmxSPrintf(const char* format, ...);

/** vsprintf */
ExportedByCATOmxKernel CATUnicodeString CATOmxVSPrintf(const char* format, va_list args);


/** concatenate an array of string */
ExportedByCATOmxKernel CATUnicodeString CATOmxConcatenate(const CATUnicodeString* iArray, size_t iArraySize);
inline CATUnicodeString CATOmxConcatenate(const CATOmxArray<CATUnicodeString>& iArray) { return CATOmxConcatenate(iArray.GetArray(), iArray.Size()); }

/** concatenate strings */
inline CATUnicodeString CATOmxConcatenate(const CATUnicodeString& iString1, const CATUnicodeString& iString2)
{
  return iString1 + iString2;
}
inline CATUnicodeString CATOmxConcatenate(const CATUnicodeString& iString1, const CATUnicodeString& iString2, const CATUnicodeString& iString3)
{
  const CATUnicodeString array[] = { iString1,iString2,iString3 };
  return CATOmxConcatenate(array, sizeof(array) / sizeof(*array));
}
inline CATUnicodeString CATOmxConcatenate(const CATUnicodeString& iString1, const CATUnicodeString& iString2, const CATUnicodeString& iString3, const CATUnicodeString& iString4)
{
  const CATUnicodeString array[] = { iString1,iString2,iString3,iString4 };
  return CATOmxConcatenate(array, sizeof(array) / sizeof(*array));
}
inline CATUnicodeString CATOmxConcatenate(const CATUnicodeString& iString1, const CATUnicodeString& iString2, const CATUnicodeString& iString3, const CATUnicodeString& iString4, const CATUnicodeString& iString5)
{
  const CATUnicodeString array[] = { iString1,iString2,iString3,iString4,iString5 };
  return CATOmxConcatenate(array, sizeof(array) / sizeof(*array));
}

#define OMX_SU_DEFAULT        0x0
#define OMX_SU_EXCLUDE_EMPTY  0x1

/**
 * Join strings
 * CATOmxJoin("+",{"1","2","3"}) returns "1+2+3"
 * @param iFlags
 *   CATOmxJoin(".",{"a","","c"},OMX_SU_DEFAULT) return "a++c"
 *   CATOmxJoin(".",{"a","","c"},OMX_SU_EXCLUDE_EMPTY)  return "a+c"
 */
ExportedByCATOmxKernel CATUnicodeString CATOmxJoin(const CATUnicodeString& iSeparator, const CATUnicodeString* iArray, size_t iSize, unsigned int iFlags = OMX_SU_DEFAULT);
inline CATUnicodeString CATOmxJoin(const CATUnicodeString& iSeparator, const CATOmxArray<CATUnicodeString>& iArray, unsigned int iFlags = OMX_SU_DEFAULT) { return CATOmxJoin(iSeparator, iArray.GetArray(), iArray.Size(), iFlags); }

#define OMX_SU_INCLUDE_SEPARATORS          0x2
#define OMX_SU_TREAT_SEPARATOR_AS_A_STRING 0x4
#define OMX_SU_TRIM                        0x8
/**
 * Split string
 * CATOmxSplit("a+b+c","+-/*") returns {"a","b","c"}
 * @param iString
 *   the string to split
 *
 * @param iSeparators
 *  the characters over witch the string must be splitted (except if OMX_SU_TREAT_SEPARATOR_AS_A_STRING is used)
 *  Must contain ascii printable characters
 *
 * @param iFlags
 *   - OMX_SU_INCLUDE_SEPARATORS:
 *       CATOmxSplit("a+b-c","+-/*",OMX_SU_DEFAULT) returns {"a","b","c"}
 *     whereas
 *       CATOmxSplit("a+b-c","+-/*",OMX_SU_INCLUDE_SEPARATORS) returns {"a","+","b","-","c"}
 *
 *   - OMX_SU_TREAT_SEPARATOR_AS_A_STRING:
 *       CATOmxSplit("-a->b","->",OMX_SU_DEFAULT) returns {"a","","b"}
 *     whereas
 *       CATOmxSplit("-a->b","->",OMX_SU_TREAT_SEPARATOR_AS_A_STRING) returns {"-a","b"}
 *
 *   - OMX_SU_TRIM:
 *       CATOmxSplit(" a + b ","+",OMX_SU_DEFAULT) returns {" a "," b "}
 *     whereas
 *       CATOmxSplit("a+b","+",OMX_SU_TRIM)        returns {"a","b"}
 *
 *   - OMX_SU_EXCLUDE_EMPTY
 *       CATOmxSplit("a++b","+",OMX_SU_DEFAULT) returns {"a","","b"}
 *      whereas
 *       CATOmxSplit("a++b","+",OMX_SU_EXCLUDE_EMPTY) returns {"a","b"}
 */
ExportedByCATOmxKernel CATOmxArray<CATUnicodeString> CATOmxSplit(const CATUnicodeString& iString, const char* iSeparators, unsigned int iFlags = OMX_SU_DEFAULT);

/**
 * Same as strlen but allows null input and returns a signed 32 bits integer (assertion in case of string longer than 2Gb...)
 */
ExportedByCATOmxKernel int strlen_i32(const char* str);


#endif
