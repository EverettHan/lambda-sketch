
#ifndef __CATOmxPortability_h__
#define __CATOmxPortability_h__

/**
 * @level Protected
 * @usage U1
 * Code level helper.
 */


 // BSFBuildTimeData
#include "CATIAV5Level.h"
// ObjectModelerCollection
#include "CATOmxCxxPortability.h"
#include "CATOmxKernel.h"
#include "CATOmxStaticAssert.h"

// Avoid cross platform typical build errors.
#include "CATSysBoolean.h"
#include "CATDataType.h"
#include "CATErrorDef.h"
#include "IUnknown.h"

#if !defined(_SUNOS_SOURCE)
#include <new>
#else
#include <new.h>
#endif
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


#if OMX_CXX11 == 1
#include <utility> //std::move
#include <initializer_list>
#endif

typedef unsigned int CATHashKey;
typedef unsigned char octet;
typedef CATBoolean boolean;

/** Enable phase 1/2 split code.
 * #if OMX_CODE_PHASE == 2
 *   phase 2 specific code
 * #endif
 * WARNING : Mkmk-SourceRuler errors are not compatible with OMX_CODE_PHASE.
 * You are forced to use #if(n)def CATIAR201 in order to filter these errors.
 */
#ifdef CATIAR201
#define OMX_CODE_PHASE 2
#define OMX_V5V6_STRING "V6"
#else 
#define OMX_CODE_PHASE 1
#define OMX_V5V6_STRING "V5"
#endif

inline const int CATOmxIsPhase1() { return (1 == OMX_CODE_PHASE); }
inline const int CATOmxIsPhase2() { return (2 == OMX_CODE_PHASE); }


/**
 * Architecture helper: processor dependant macros
 */
#include "BigLittle.h"

 /** Enable endianess test
  * #if OMX_LITTLE_ENDIAN == 1
  *   little endian specific code
  * #endif
  * #if OMX_LITTLE_ENDIAN == 0
  *   big endian specific code
  * #endif
  */
#ifdef _ENDIAN_LITTLE
#define OMX_LITTLE_ENDIAN 1
#else
#define OMX_LITTLE_ENDIAN 0 
#endif

#define OMX_ENDIAN_LITTLE OMX_LITTLE_ENDIAN

inline const int CATOmxIsLittleEndian() { return (1 == OMX_LITTLE_ENDIAN); }


/**
 * Plateform dependant helper
 */

#ifdef _WINDOWS_SOURCE
 /** Directory separator char version. */
#define OMX_DIR_SEP_CHR '\\'
/** Directory separator str version. */
#define OMX_DIR_SEP_STR "\\"
/** Concatenation delimiter. */
#define OMX_PATHS_DELIMITER		';'
/** Concatenation delimiter. */
#define OMX_PATHS_DELIMITER_CHR		';'
/** Concatenation delimiter. */
#define OMX_PATHS_DELIMITER_STR		";"
#else
#define OMX_DIR_SEP_CHR '/'
#define OMX_DIR_SEP_STR "/"
#define OMX_PATHS_DELIMITER		':'
#define OMX_PATHS_DELIMITER_CHR		':'
#define OMX_PATHS_DELIMITER_STR		":"

#endif

 /** Export symbol. */
#define OMX_DLLEXPORT  DSYExport

#include "DSYExport.h"


/**
 * Switch endianness of iSize bytes of iData.
 */
void OMX_DLLEXPORT CATOmxSwitchEndianness(void* iData, int iSize);

/**
 * Switch endianness of a.
 */
template<typename T> inline void CATOmxSwitchEndianness(T& a) { CATOmxSwitchEndianness(&a, sizeof(a)); }

#ifndef _WINDOWS_SOURCE
inline int operator==(const IID & iIID1, const IID &iIID2)
{
  int *i1 = (int*)&iIID1;
  int *i2 = (int*)&iIID2;
  return (i1[0] == i2[0] && i1[1] == i2[1] && i1[2] == i2[2] && i1[3] == i2[3]);
}
inline int operator!=(const IID & iIID1, const IID &iIID2) { return !(iIID1 == iIID2); }
#endif

// Legacy macro OMX_EXPLICIT
#ifndef OMX_EXPLICIT
#define OMX_EXPLICIT OMX_Cxx_EXPLICIT
#endif

#endif // __CATOmxPortability_h__

