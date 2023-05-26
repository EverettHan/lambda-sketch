// COPYRIGHT DASSAULT SYSTEMES 2016
//=============================================================================
//
// CATCDSDataType
//
//=============================================================================
//  Jan 2016  Creation                         TE9
//=============================================================================


#ifndef CATCDSDataType_h
#define CATCDSDataType_h

// TODO TE9 : Supprimer Linux et MacOS de la liste lorsque le C++ 11 sera activé par défaut sur gcc et clang

#include "CATCDSCPlusPlusVersions.h"

#ifndef CPP11_AVAILABLE
#include <stdint.h>
#else
#include <cstdint>
#endif

#include "CATCDSAssert.h"

#ifndef CPP11_AVAILABLE
#if defined(PLATEFORME_DS64)
namespace std {
#if defined(_WINDOWS_SOURCE)
  typedef unsigned long long uint64_t; // long is 4 bytes on Win 64
  typedef long long int64_t;           // long is 4 bytes on Win 64
#else
  typedef unsigned long uint64_t;
  typedef long int64_t;
#endif
  typedef unsigned int uint32_t;
  typedef int int32_t;
  typedef int64_t intptr_t;
  typedef uint64_t uintptr_t;
}
#else
namespace std {
  typedef unsigned long long uint64_t;
  typedef long long int64_t;
  typedef unsigned int uint32_t;
  typedef int int32_t;
  typedef int32_t intptr_t;
  typedef uint32_t uintptr_t;  
}
#endif
CATCDSStaticAssert(sizeof(std::uint64_t) == 8, "uint64 is not 8 bytes");
CATCDSStaticAssert(sizeof(std::int64_t) == 8, "uint64 is not 8 bytes");
CATCDSStaticAssert(sizeof(std::uint32_t) == 4, "uint32_t is not 4 bytes");
CATCDSStaticAssert(sizeof(std::int32_t) == 4, "uint32_t is not 4 bytes");
CATCDSStaticAssert(sizeof(std::intptr_t) == sizeof(void*), "intptr_t has not void* size");
CATCDSStaticAssert(sizeof(std::uintptr_t) == sizeof(void*), "uintptr_t has not void* size");
#endif

#endif
