#ifndef __CATOmxCxxPortability_h__
#define __CATOmxCxxPortability_h__

/**
 * @level Protected
 * @usage U1
 * Code level helper.
 */

// BSFBuildtimeData
#include "CATIAV5Level.h"
#include "CATOmxSupport.h"

#define OMX_Cxx_EXPLICIT explicit

// CXR29 & R421 version: only the legacy AIX compiler is NOT C++11 compliant.
// C++11 features.
#if (!defined(_AIX_SOURCE) || defined(__ibmxl__))
#define OMX_CXX11 1
#else
#define OMX_CXX11 0
#endif

#if OMX_CXX11 == 1
#define OMX_Cxx11_DELETE = delete
#define OMX_Cxx11_FINAL final
#define OMX_Cxx11_NOEXCEPT(a) noexcept(a)
#define OMX_Cxx11_NULLPTR nullptr
#define OMX_Cxx11_OVERRIDE override
#define OMX_Cxx11_NORETURN [[noreturn]]
#else
#define OMX_Cxx11_DELETE
#define OMX_Cxx11_FINAL
#define OMX_Cxx11_NOEXCEPT(a)
#define OMX_Cxx11_NULLPTR 0
#define OMX_Cxx11_OVERRIDE
#define OMX_Cxx11_NORETURN
#endif

// C++ exceptions vs. D.S. not-real-exceptions.
#if defined(CATIAR424) || defined(CATIAV5R32) || (defined(_MSC_VER) && defined(_CPPUNWIND))
#define OMX_CxxDS_NOEXCEPT(a) OMX_Cxx11_NOEXCEPT(a)
#else
#define OMX_CxxDS_NOEXCEPT(a)
#endif

//compatibility, do not use
#define OMX_CXX11_SUPPORT_LAMBDA OMX_CXX11

#endif // __CATOmxCxxPortability_h__
