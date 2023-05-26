#ifndef CATCDSCPlusPlusVersions_h
#define CATCDSCPlusPlusVersions_h

#include "CATIAV5Level.h"

// N.B MSVC++ 14.0  _MSC_VER == 1900 (Visual Studio 2015 version 14.0)
#if    ( defined(_WINDOWS_SOURCE) && _MSC_VER >= 1900   ) \
    || ( defined(_LINUX_SOURCE)   && defined(CATIAR419) ) \
    || ( defined(_IOS_SOURCE)     && defined(CATIAR420) ) \
    || ( defined(_ANDROID_SOURCE) && defined(CATIAR420) ) \
    || ( defined(_DARWIN_SOURCE)  && defined(CATIAR420) ) \
	|| ( defined(_AIX_SOURCE)  	  && __ibmxl__ ) \
    ||   defined(_EMSCRIPTEN_SOURCE)
  //#ifdef CATIAV5R30
 #define CPP11_AVALAIBLE // avec la faute d'anglais historique
 #define CPP11_AVAILABLE // migrer les sources vers cette macro

 #if    ( defined(_WINDOWS_SOURCE) && _MSC_VER <= 1900   )
 #else
 #define CPP11_AVAILABLE_V2 // NLD021219 pour nouveautés TE9 Nov2019; KO avec (Visual Studio 2015 version 14.0)
 #endif

  //#endif
#endif

#if    ( defined(_WINDOWS_SOURCE) && ( _MSC_VER >= 1900 ) && defined(CATIAR422) && ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || (defined(__cplusplus) && __cplusplus >= 201703L)) ) \
    || (defined(_LINUX_SOURCE) && defined(CATIAR422)) \
    || (defined(_IOS_SOURCE) && defined(CATIAR422)) \
    || (defined(_ANDROID_SOURCE) && defined(CATIAR422)) \
    || (defined(_DARWIN_SOURCE) && defined(CATIAR422)) \
    || defined(_EMSCRIPTEN_SOURCE)
#define CPP17_AVAILABLE
#endif

#ifdef CPP11_AVAILABLE
#include <utility>
#define CDS_MOVE(ref) std::move(ref)
#else
#define CDS_MOVE(ref) ref

#if !defined(_MSC_VER)||_MSC_VER<1700
namespace std
{
  template<class Integer, Integer n>
  struct integral_constant { static Integer const value = n; };
}
#endif
#endif

#ifdef CPP17_AVAILABLE
#include <utility>
#define CDS_CONSTEXPR constexpr
#else
#define CDS_CONSTEXPR 
#endif

#endif
