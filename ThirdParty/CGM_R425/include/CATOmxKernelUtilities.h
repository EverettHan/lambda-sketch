
#ifndef __CATOmxKernelUtilities_h__
#define __CATOmxKernelUtilities_h__

/**
 * @level Protected
 * @usage U1
 * COPYRIGHT DASSAULT SYSTEMES 2007
 */
 // SpecialAPI
#include "CATDataType.h"
// System
#include "CATUnicodeString.h"
#include "IUnknown.h"
// ObjectModelerCollection
#include "CATOmxKernel.h"
#include "CATOmxPortability.h"

#include <time.h>
class CATUuid;
#ifdef _WINDOWS_SOURCE
#include <float.h>
#else
#include <math.h>
#endif
#include <limits.h>

#ifndef DBL_MAX
#define OMX_DBL_MAX     1.7976931348623157E+308
#else
#define OMX_DBL_MAX DBL_MAX
#endif
typedef unsigned int CATHashKey;

/**
 * Various string utilities are defined here.
 */

 /**
 * Converts a string representation of a double into a double value.
 *    Decimal separator, if any, must be a point.
 *    Input value representing non finite values (e.g. "inf", "-inf", "nan") will not be converted.
 *    Input value representing finite values which cannot be represented on a double value (e.g. values greater than DBL_MAX such as "1.0e+9000") will not be converted.
 *    Input value with precision which cannot be handled by double value will be rounded up and successfully converted.
 *
 * @param iString : Input string.
 * @param oValue  : Input string converted as a double value.
 * @return Conversion status : true for success, false for failure.
 */
ExportedByCATOmxKernel bool CATOmxAtoF(char const * iString, double & oValue);

/**
*   Computes a string representation of a double value respecting the following conditions:
*     - Decimal separator is a point and is always displayed.
*     - Output string always contains at least one digit after the decimal point.
*     - Output string may have an exponential representation.
*     - Precision is sufficient to stream/unstream normalized and denormalized double values as string using CATOmxFtoA and CATOmxAtoF (i.e. no round up errors).
*
*   Non finite values:
*     CATOmxFtoA will return string representations of non finite values such as infinity or nan. Contrary to finite values, return code of CATOmxFtoA for non finite values will be false.
*     Note that string representations of non finite values are not valid inputs for CATOmxAtoF.
*
* @param iValue  : Input double value.
* @param oString : String representation of the input double value.
* @return Status of the input value : true if input value is finite, false if not (e.g. infinity or nan).
*/
ExportedByCATOmxKernel bool CATOmxFtoA(double iValue, char oString[32]);


#if !defined(CATIAV5R32)
// @nodoc : Do not use, use CATOmxAToF instead.
ExportedByCATOmxKernel double omxatof(const char * doNotUse);

// @nodoc : Do not use, use CATOmxAToF instead.
ExportedByCATOmxKernel HRESULT omxatof(const char * iDoNotUse, double & oDoNotUse);

/**
 * Consider using CATOmxFToA instead.
 *
 * Convert a double in byte string.
 * Note that integers values are always dotted.
 * @param num the number to convert
 * @param oBuf the output buffer
 * @param dig the number of digit to keep before period
 * @param prec the precision (number of digits)
 * @param add_zero add a zero after the '.' if all zero are trimmed
 */
ExportedByCATOmxKernel void omxftoa(double num, char oBuf[32], int dig = 5, int prec = 7, int add_zero = 0);
#endif

/**
 * Glob the next double.
 * @return return the start of the number
 * @param iStr the string to glob
 * @param oStr the last scanned character
 */
ExportedByCATOmxKernel const char * omx_glob_double(const char * iStr, const char *& oEnd);

/**
 * Convert a byte sting in a int64.
 * @param iStr the string to scan
 * @param o64 the returned int
 * @return 8/16/32 or 64 if fit for 8,16,32 or 64 bits number return FAILED on failure
 */
ExportedByCATOmxKernel HRESULT omxatoint64(const char * iStr, CATLONG64 & o64);

/** do not use */
ExportedByCATOmxKernel time_t CATOmxTimeFromCATUuid(const CATUuid & iUUID);

/**
 * Extracts a numeric value from an environment variable.
 * Return iDefaultValue in environment variable is unset or invalid.
 */
ExportedByCATOmxKernel int CATOmxGetIntEnvValue(const char * iValueName, int iDefaultValue);
ExportedByCATOmxKernel CATBoolean CATOmxGetBoolEnvValue(const char * iValueName, CATBoolean iDefaultValue);

/** An efficient general purpose hash algorithm (sorry for the typo: hash-pjw). Also called ELF hash. */
ExportedByCATOmxKernel CATHashKey hashpjv(int len, const unsigned char binary[]);
inline CATHashKey CATOmxHashPJW(int len, const unsigned char binary[]) { return hashpjv(len, binary); }

/**
 * Computes a hashkey from two hash keys.
 * Not "good" but better than "h1 + h2"...
 * for a list of hash keys use it like that:
 * CATHashKey hashes[N] = ...;
 * CATHashKey h = hashes[0];
 * for(size_t i=1; i<N; i++)
 *   h = CATOmxHash2(h,hashes[i]);
 */
inline CATHashKey CATOmxHash2(CATHashKey h1, CATHashKey h2) { return h1 * 31 + h2; }


/** dumps uuid to a CATUnicodeString (@see CATUUid::UUID_to_chaine)*/
ExportedByCATOmxKernel CATUnicodeString CATOmxUuidToString(const CATUuid & iUuid);

/** returns TRUE if iUuid is null (0-0-0-0)*/
ExportedByCATOmxKernel int CATOmxUuidIsNull(const CATUuid & iUuid);

/** Hash a CATUuid*/
inline CATHashKey CATOmxHashUuid(const CATUuid & iUuid) { return hashpjv(16, reinterpret_cast<const unsigned char *>(&iUuid)); }


#endif
