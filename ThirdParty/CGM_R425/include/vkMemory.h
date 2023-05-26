/**
@file

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkMemory_h)
#define __vkMemory_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkMemoryUtils_h)
	#include "vkMemoryUtils.h"
#endif
#if !defined(__vkStandardAllocator_h)
	#include "vkStandardAllocator.h"
#endif
#if !defined(__vkHeapAllocator_h)
#include "vkHeapAllocator.h"
#endif

#if !defined(__vkAlignedAllocator_h)
	#include "vkAlignedAllocator.h"
#endif

//--- This is the place where DefaultAllocator should be defined 
#undef vkDefaultAllocator 
//#define vkDefaultAllocator vkStandardAllocator
#define vkDefaultAllocator VKernel::vkHeapAllocator


namespace VKernel
{

#if defined(VK_MEMORYDEBUG) && !defined(VK_DOXYGEN)
	#define vkAllocate(iSize) vkDefaultAllocator().AllocateDebug(iSize, __FILE__, __LINE__)
#elif !defined(VK_DOXYGEN)
	#define vkAllocate(iSize) vkDefaultAllocator().Allocate(iSize)
#else
	/**
	Function for allocating raw memory.

	@see vkDeallocate, vkTellSize
	*/
	#define vkAllocate(iSize)
#endif

#if defined(VK_MEMORYDEBUG) && !defined(VK_DOXYGEN)
	#define vkDeallocate(iPointer) vkDefaultAllocator().DeallocateDebug((VKernel::uint8*)iPointer, __FILE__, __LINE__)
#elif !defined(VK_DOXYGEN)
	#define vkDeallocate(iPointer) vkDefaultAllocator().Deallocate((VKernel::uint8*)iPointer)
#else
	/**
	Function for deallocating raw memory.

	@see vkAllocate, vkTellSize
	*/
	#define vkDeallocate(iPointer)
#endif

#if defined(VK_MEMORYDEBUG) && !defined(VK_DOXYGEN)
	#define vkAllocateAligned(iSize, iAlignment) vkDefaultAllocator().AllocateAlignedDebug(iSize, iAlignment, __FILE__, __LINE__)
#elif !defined(VK_DOXYGEN)
	#define vkAllocateAligned(iSize, iAlignment) vkDefaultAllocator().AllocateAligned(iSize, iAlignment)
#else
	/**
	Function for allocating raw memory.

	@see vkDeallocate, vkTellSize
	*/
	#define vkAllocateAligned(iSize, iAlignment)
#endif

#if defined(VK_MEMORYDEBUG) && !defined(VK_DOXYGEN)
	#define vkDeallocateAligned(iPointer) vkDefaultAllocator().DeallocateAlignedDebug((VKernel::uint8*)iPointer, __FILE__, __LINE__)
#elif !defined(VK_DOXYGEN)
	#define vkDeallocateAligned(iPointer) vkDefaultAllocator().DeallocateAligned((VKernel::uint8*)iPointer)
#else
	/**
	Function for deallocating raw memory.

	@see vkAllocate, vkTellSize
	*/
	#define vkDeallocateAligned(iPointer)
#endif

} // end namespace VKernel

#endif // __vkMemory_h

