/**
@file

This file defines an allocator that align allocation with
a template parameter alignement in bytes.

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkAlignedAllocator_h)
#define __vkAlignedAllocator_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkAssert_h)
	#include "vkAssert.h"
#endif

namespace VKernel
{
 
template <uint32 T>
class vkAlignedAllocator {
public:
	VK_INLINE uint8* Allocate(uint32 iSize)
	{
		return (uint8*)vkHeapManager::Instance().AllocateAligned(iSize, T);
	}
	VK_INLINE uint8* AllocateAligned (uint32 iSize, uint32 iAlign)
	{
		return (uint8*)vkHeapManager::Instance().AllocateAligned(iSize, iAlign);
	}
	VK_INLINE uint8* AllocateDebug(uint32 iSize, const char* iFunc = 0, uint32 iLine = 0)
	{
		return (uint8*)vkHeapManager::Instance().AllocateAlignedDebug(iSize, T, iFunc, iLine);
	}
	VK_INLINE uint8* AllocateAlignedDebug(uint32 iSize, uint32 iAlign, const char* iFunc = 0, uint32 iLine = 0)
	{
		return (uint8*)vkHeapManager::Instance().AllocateAlignedDebug(iSize, iAlign, iFunc, iLine);
	}
	
	VK_INLINE void Deallocate(void* iPointer) 
	{
		vkHeapManager::Instance().DeallocateAligned(iPointer);
	}

	VK_INLINE void DeallocateAligned(void* iPointer) 
	{
		vkHeapManager::Instance().DeallocateAligned(iPointer);
	}

	VK_INLINE void DeallocateDebug(void* iPointer, const char* iFile, uint32 iLine) 
	{
		vkHeapManager::Instance().DeallocateAlignedDebug(iPointer, iFile, iLine);
	}

	VK_INLINE void DeallocateAlignedDebug(void* iPointer, const char* iFile, uint32 iLine) 
	{
		vkHeapManager::Instance().DeallocateAlignedDebug(iPointer, iFile, iLine);
	}

	VK_INLINE uint32 GetAlignment() const
	{
		return T;
	}

	enum {
		GETALIGNMENT = T
	};

};

typedef vkAlignedAllocator<VK_SIMD_ALIGN>		vkSIMDAlignedAllocator;
typedef vkAlignedAllocator<VK_CACHE_LINE_SIZE>	vkCACHEAlignedAllocator;


} // Namespace VKernel


#endif // __vkAlignedAllocator_h

