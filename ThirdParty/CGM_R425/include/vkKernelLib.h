#if !defined(VK_DOXYGEN)
/**
@file

This file defines VKKERNEL_API to export/import symbols.
Other module which include this file will automticaly link
with vkKernel librarie (only available for shared library under MSVC).

@COPYRIGHT

@author Nicolas Hognon
*/

#if !defined(__vkKernelLib_h)
#define __vkKernelLib_h


#if !defined(__vkKernelDefines_h)
#include "vkKernelDefines.h"
#endif


#if defined(VK_TARGET_MACOSX) && !defined(VK_PROC_AMD64)
// To compile without any precompiled headers
#include <Carbon/Carbon.h>
#include <xlocale.h>
#endif

// define the way to export/import symbols in shared library
#if !defined(VKKERNEL_API)
	#if defined(VKKERNEL_EXPORTS)
		#define VKKERNEL_API VK_MODULE_EXPORT
	#else
		#define VKKERNEL_API VK_MODULE_IMPORT
	#endif
#endif

#if !defined(VKKERNEL_INL)
		#define VKKERNEL_INL
#endif

#endif // __vkKernelLib_h

#endif // VK_DOXYGEN


