// COPYRIGHT DASSAULT SYSTEMES 2007
//=============================================================================
//
// CATCDSAssert:
//   Functions and macros for safe and powerful checks.
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Nov 2007  Creation                         Vladislav Kornienko
//=============================================================================

#ifndef CATCDSAssert_h
#define CATCDSAssert_h

#include "CATCDSCPlusPlusVersions.h"

#ifdef CPP11_AVAILABLE
#define CATCDSStaticAssert(exp, message) static_assert(exp, message);
#else
#define CATCDSStaticAssert(exp, message) 
#endif

#include "CATCDSUtilities.h"

ExportedByCATCDSUtilities void CATCDSAssertError(
  char const* iExp,
  char const* iFile,
  unsigned int iLine);

#if defined(CDS_ASSERT)

#define CATCDSAssert(exp) \
  if (!(exp)) { \
    CATCDSAssertError(#exp, __FILE__, __LINE__); \
  }

#define CATCDSAssertR(exp) \
  if (!(exp)) { \
    CATCDSAssertError(#exp, __FILE__, __LINE__); \
    return; \
  }

#define CATCDSAssertV(exp, ret) \
  if (!(exp)) { \
    CATCDSAssertError(#exp, __FILE__, __LINE__); \
    return ret; \
  }

#define CATCDSAssertB(exp) \
  if (!(exp)) { \
    CATCDSAssertError(#exp, __FILE__, __LINE__); \
    break; \
  }

#define CATCDSAssertC(exp) \
  if (!(exp)) { \
    CATCDSAssertError(#exp, __FILE__, __LINE__); \
    continue; \
  }

#define CATCDSAssertRL(exp, level) \
  if (!(exp)) { \
    if(level) \
      CATCDSAssertError(#exp, __FILE__, __LINE__); \
    return; \
  }

#define CATCDSAssertVL(exp, ret, level) \
  if (!(exp)) { \
    if(level) \
      CATCDSAssertError(#exp, __FILE__, __LINE__); \
    return ret; \
  }


#define CATCDSAssertBL(exp, level) \
  if (!(exp)) { \
    if(level) \
      CATCDSAssertError(#exp, __FILE__, __LINE__); \
    break; \
  }

#define CATCDSAssertCL(exp, level) \
  if (!(exp)) { \
    if(level) \
      CATCDSAssertError(#exp, __FILE__, __LINE__); \
    continue; \
  }

#else

#if !defined(NOT_CDS_ASSERT) && defined(_WINDOWS_SOURCE)
#define CATCDSAssertWarning __pragma(message("You must define NOT_CDS_ASSERT in your Imakefile (see CATCDSUtilities for example)"))
#else
#define CATCDSAssertWarning
#endif

#define CATCDSAssert(exp) \
  do {} while(0); \
  CATCDSAssertWarning

#define CATCDSAssertR(exp) \
  if (!(exp)) \
    return; \
  CATCDSAssertWarning

#define CATCDSAssertV(exp, ret) \
  if (!(exp)) \
    return ret; \
  CATCDSAssertWarning

#define CATCDSAssertB(exp) \
  if (!(exp)) \
    break; \
  CATCDSAssertWarning

#define CATCDSAssertC(exp) \
  if (!(exp)) \
    continue; \
  CATCDSAssertWarning

#define CATCDSAssertRL(exp, level) CATCDSAssertR(exp)

#define CATCDSAssertVL(exp, ret, level) CATCDSAssertV(exp, ret)

#define CATCDSAssertBL(exp, level) CATCDSAssertB(exp)

#define CATCDSAssertCL(exp, level) CATCDSAssertC(exp)

#endif

#endif
