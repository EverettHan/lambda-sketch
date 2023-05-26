/**
@file

This file defines the default heap allocator.

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkHeapAllocator_h)
#define __vkHeapAllocator_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif

namespace VKernel 
{

class VKKERNEL_API vkHeapAllocator 
{
public:
	uint8* Allocate(uint32 iSize);
	uint8* AllocateAligned (uint32 iSize, uint32 iAlign);
	uint8* AllocateDebug(uint32 iSize, const char* iFunc = nullptr, uint32 iLine = 0);
	uint8* AllocateAlignedDebug(uint32 iSize, uint32 iAlign, const char* iFunc = nullptr, uint32 iLine = 0);
	
	void Deallocate(void* iPointer);
	void DeallocateAligned(void* iPointer);
	void DeallocateDebug(void* iPointer, const char* iFile = nullptr, uint32 iLine = 0);
	void DeallocateAlignedDebug(void* iPointer, const char* iFile = nullptr, uint32 iLine = 0);

	VK_INLINE uint32 GetAlignment() const
	{
		return 0;
	}
	enum {
		GETALIGNMENT = 0
	};
};

}

#include "vkHeapManager.h"
#include "vkHeapAllocator.hpp"

#endif // __vkHeapAllocator_h



