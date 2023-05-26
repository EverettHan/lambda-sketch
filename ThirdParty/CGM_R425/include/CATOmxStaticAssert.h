/**
 * @level Private
 * @usage U1
 * COPYRIGHT DASSAULT SYSTEMES 2003
 */

#ifndef __CATOmxStaticAssert_H
#define __CATOmxStaticAssert_H

#include "CATOmxPortability.h"

 /**
  * DO NOT INCLUDE DIRECTLY/USE OUTSIDE ObjectModelerCollection framework
  */

  //Force activation by defining OMX_ENABLE_STATIC_ASSERT=0/1
#ifndef OMX_ENABLE_STATIC_ASSERT

//only tested on windows and only exist starting VS2010
#if defined(DS_CXX11_SUPPORT_STATIC_ASSERT) || (defined(_MSC_VER) && (_MSC_VER >= 1600))

#ifdef _STLP_MAKE_HEADER
//type_traits header has been delivered in VCOSTLport but is incompatible with compiler (including causes build errors)
//=> disable OMX_STATIC_ASSERT if _STLP_MAKE_HEADER is defined
#pragma message("[W] " __FILE__ ": STLport detected, disabling OMX_STATIC_ASSERT")
#else
#define OMX_ENABLE_STATIC_ASSERT 1
#endif
#endif

#ifndef OMX_ENABLE_STATIC_ASSERT
#define OMX_ENABLE_STATIC_ASSERT 0
#endif
#endif

/**
 * Usage (DO NOT USE OUTSIDE ObjectModelerCollection):
 *   - in functions:   OMX_STATIC_ASSERT(condition,"error message");
 *
 *   - at class scope: OMX_STATIC_ASSERT_CLASS_SCOPE(condition,"error message")
 *     nb: DO NOT ADD TRAILING ';' due to stupid solaris specific error "Empty declaration (probably an extra semicolon)."
 *
 * Will produce a compilation error containing "error message" if BUILDTIME condition is not fulfilled.
 * Enabled on windows only.
 */
#if OMX_ENABLE_STATIC_ASSERT == 1
#include <type_traits>
#define OMX_STATIC_ASSERT(...) static_assert(__VA_ARGS__)
#define OMX_STATIC_ASSERT_CLASS_SCOPE(...) static_assert(__VA_ARGS__);
#else
#define OMX_STATIC_ASSERT(...) 
#define OMX_STATIC_ASSERT_CLASS_SCOPE(...)
#endif

#endif
