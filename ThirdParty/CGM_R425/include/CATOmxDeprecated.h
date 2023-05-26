#ifndef __CATOmxDeprecated_h__
#define __CATOmxDeprecated_h__

#include "CATIAV5Level.h"

/**
 * OMX_DEPRECATED macro
 * usage
 * class MyClass
 * {
 *   void OMX_DEPRECATED("Use MyFunction") MyDeprecatedFunction(void**** oValue) {***oValue = new int(1);}
 *   int MyFunction() {return 1;}
 * }
 */
#if defined(_LINUX_SOURCE) || defined(_ANDROID_SOURCE) || defined(_IOS_SOURCE)
#define OMX_DEPRECATED(comment) __attribute__((deprecated))
#elif defined(_WINDOWS_SOURCE)
#define OMX_DEPRECATED(comment) __declspec(deprecated(comment))
#else
#define OMX_DEPRECATED(comment)
#endif

/*deprecated alias on OMX_DEPRECATED*/
#define OMX_DEPRECATED2(comment) OMX_DEPRECATED(comment)


#endif
