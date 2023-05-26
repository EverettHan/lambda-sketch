/**
@file

Wrapping of standard stdio/stdlib tools.

@COPYRIGHT

@author Aymeric Bard
*/

#ifndef __vkStrTools_h
#define __vkStrTools_h


#include "vkKernelLib.h"
#include "vkAssert.h"
#include <stdarg.h>

namespace VKernel
{


	VKKERNEL_API int32                    vkSprintf(char8* oDst, uint32 iBufferSize, const char8* iFormat, ...);
	VKKERNEL_API int32                    vkNSprintf(char8* oDst, uint32 iBufferSize, const char8* iFormat, va_list& iArgs);

	VKKERNEL_API int32                    vkSScanf(const char8* iSrc, const char8* iFormat, void* iAddress);
	VKKERNEL_API error                    vkStrCat(char8* oDst, uint32 iBufferSize, const char8* iSrc);
	VKKERNEL_API error                    vkStrCpy(char8* oDst, uint32 iBufferSize, const char8* iSrc);
	VKKERNEL_API error                    vkStrNCpy(char8* oDst, uint32 iBufferSize, const char8* iSrc, uint32 iCharsToCopy);
	VKKERNEL_API int32                    vkStrCmp(const char8* iSrc1, const char8* iSrc2);
	VKKERNEL_API int32                    vkStrICmp(const char8* iSrc1, const char8* iSrc2);
	VKKERNEL_API int32                    vkStrICmp(const char8* iSrc1, const char8* iSrc2);

	VKKERNEL_API char*			          vkStrDup(const char* iSrc);	
	VKKERNEL_API wchar_t*                 vkStrDupW(const wchar_t* iSrc);

	// widechar version
	VKKERNEL_API error                    vkStrCatW(wchar_t* oDst, uint32 iBufferSize, const wchar_t* iSrc);
	VKKERNEL_API error                    vkStrCpyW(wchar_t* oDst, uint32 iBufferSize, const wchar_t* iSrc);

	char8                                 vkToLower(const char8 iCharacter);
	char8                                 vkToUpper(const char8 iCharacter);


#include "vkStrTools.hpp"

} // End of namespace VKernel

#endif // __vkStrTools_h


