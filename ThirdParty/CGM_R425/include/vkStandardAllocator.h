/**
@file

This file defines a standard allocator, using the system
malloc/free functions to allocate/deallocate memory and objects.

This allocator is written following the STL coding style and is compatible
with STL containers.

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkStandardAllocator_h)
#define __vkStandardAllocator_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkAssert_h)
	#include "vkAssert.h"
#endif

#include <stdlib.h>


namespace VKernel
{

class vkStandardAllocator {
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

VK_INLINE uint8*
vkStandardAllocator::Allocate(uint32 iSize) 
{
	return (uint8*)malloc(iSize);
}

VK_INLINE uint8*
vkStandardAllocator::AllocateAligned (uint32 iSize, uint32 iAlign) 
{
	uint8* ptr = (uint8*)malloc(iSize + sizeof(ptrdiff) + iAlign);
	VKASSERT(ptr != nullptr); // "No more memory !!!"
	ptrdiff* alignedPtr = reinterpret_cast<ptrdiff*>(VK_POINTER_TO_PTRDIFF(ptr+sizeof(ptrdiff)+(iAlign-1)) & (~(ptrdiff)(iAlign-1)));
	*(alignedPtr-1) = VK_POINTER_TO_PTRDIFF(ptr);
	return (uint8*)alignedPtr;
}

VK_INLINE uint8*
vkStandardAllocator::AllocateDebug(uint32 iSize, const char* , uint32 ) 
{
	uint8* buffer = (uint8*)malloc(iSize);
	VKASSERT(buffer != nullptr);
	return buffer;
}

VK_INLINE uint8*
vkStandardAllocator::AllocateAlignedDebug(uint32 iSize, uint32 iAlign, const char* , uint32 ) 
{
	uint8* ptr = (uint8*)malloc(iSize + sizeof(ptrdiff) + iAlign);
	VKASSERT(ptr != nullptr); // "No more memory !!!"
	ptrdiff* alignedPtr = reinterpret_cast<ptrdiff*>(VK_POINTER_TO_PTRDIFF(ptr+sizeof(ptrdiff)+(iAlign-1)) & (~(ptrdiff)(iAlign-1)));
	*(alignedPtr-1) = VK_POINTER_TO_PTRDIFF(ptr);
	return (uint8*)alignedPtr;
}

VK_INLINE void 
vkStandardAllocator::Deallocate(void* iPointer) 
{
	free(iPointer);
}

VK_INLINE void 
vkStandardAllocator::DeallocateAligned(void* iPointer) 
{
	void* realPtr = (void*)(*((ptrdiff*)iPointer - 1));
	free(realPtr);
}

VK_INLINE void 
vkStandardAllocator::DeallocateDebug(void* iPointer, const char* , uint32 ) 
{
	free(iPointer);
}

VK_INLINE void 
vkStandardAllocator::DeallocateAlignedDebug(void* iPointer, const char* , uint32 ) 
{
	void* realPtr = (void*)(*((ptrdiff*)iPointer - 1));
	free(realPtr);
}

class vkStdHeapObject 
{
public:

	void*	operator new(size_t iSize)
	{
		void* buffer = malloc((uint32)iSize);
		VKASSERT(buffer != nullptr);
		return buffer;

	}

	void	operator delete(void* iP, size_t)
	{
		free(iP);
	}

	// For placement new
	void*	operator new(size_t , void* p)
	{
		return p;
	}

	void	operator delete(void*, void*)
	{
	}
};

#define VK_STD_ALLOCATION public:\
	void* operator new(size_t iSize) {\
		void* buffer = malloc((uint32)iSize);\
		VKASSERT(buffer != nullptr);\
		return buffer;\
	}\
	void	operator delete(void* iP, size_t){free(iP);}\
	void*	operator new(size_t , void* p) {return p;}\
	void	operator delete(void*, void*) {}

}

#endif // __vkStandardAllocator_h

