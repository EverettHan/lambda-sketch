#ifndef __CATOmxAssertionFailed_h
#define __CATOmxAssertionFailed_h

#include "CATOmxKernel.h"
#include "CATOmxCxxPortability.h"

OMX_Cxx11_NORETURN ExportedByCATOmxKernel void _CATOmxAssertionFailed(const char* file, int line, const char* format, ...);

/**
 * Usage:
 * if(len > 7)
 *   CATOmxAssertionFailed("len is too long (%d)",len);
 */
#define CATOmxAssertionFailed(...) _CATOmxAssertionFailed(__FILE__,__LINE__,__VA_ARGS__)

#endif
