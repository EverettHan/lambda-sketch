/**
@file

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkMemoryUtils_h)
#define __vkMemoryUtils_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkUtil_h)
	#include "vkUtil.h"
#endif

#include <new>

#if defined(VK_COMPILER_MSVC)
	#pragma warning(push)
	#pragma warning(disable : 4127)
	#pragma warning(disable : 4100)
#endif

namespace VKernel
{

	/**
	Tells if the pointer is valid.
	 
	A valid pointer is a pointer that liesin the address space of the current thread.

	@param iPointer the pointer to test

	@return True if the pointer is valid, else otherwise.
	*/
	extern VKKERNEL_API bool vkIsPointerValid(const void* iPointer);
	
	/**
	Functions to manipulate memory buffers
	*/
	
	/**
	Sets buffers to a specified uint32 value.

	This function is an optimized version of the vkMemSet dedicated to uint32 values.

	@param iDst the destination pointer.
	@param iValue the uint32 value to set.
	@param iSizeInBytes number of bytes that should be written (must be a multiple of 4).

	@see vkMemSet
	*/
	extern VKKERNEL_API void (*vkMemSet32)(void* iDst, uint32 iValue, uint32 iSizeInBytes);

	/**
	Sets buffers to a specified character.

	This function perform the exact same operation than the standard C run-time library memset function
	with some improvement on specific platforms.

	@param iDst the destination pointer.
	@param iValue the value to set (only the first byte is used).
	@param iDwordCount number of bytes that should be written .

	@see vkMemCopy,vkMemMove,vkStridedFill,vkStridedCopy
	*/
	extern VKKERNEL_API void (*vkMemSet)(void* iDst, uint32 iValue, uint32 iSizeInBytes);

	/**
	Copies characters between buffers.

	- Copies count bytes of iSrc to iDst.
	- If the source and destination overlap, the behavior of vkMemCopy is undefined (use vkMemMove)
	- These functions are optimized to handle alignment issues, if you mean to make a fixed sized copy of less
	than 32 bytes for example that you kwow to be issued on aligned pointers you should definitively use the standard memcpy function that will get inlined.

	Prefer memcpy(DstPtrAlignedOn16,SrcPtrAlignedOn16,32); to vkMemcopy but use
	uint32 size = nbVertex * sizeof(vkVec3);
	vkMemcopy(Dst,Src,size);

	@param iDst the destination pointer.
	@param iSrc the source pointer to copy from.
	@param iSizeInBytes Number of bytes to copy. 

	@see vkMemSet,vkMemSet32,vkMemMove,vkStridedFill,vkStridedCopy
	*/
	extern VKKERNEL_API void (*vkMemCopy)(void* iDst, const void* iSrc, uint32 iSizeInBytes);
	extern VKKERNEL_API void (*vkMemMove)(void* iDst, const void* iSrc, uint32 iSizeInBytes);


	extern VKKERNEL_API int32 (*vkMemCmp)(const void* iBuffer1, const void* iBuffer2, uint32 iSizeInBytes);

#if defined(VK_MEMORYDEBUG) && !defined(VK_DOXYGEN)
	#define vkAllocateEx(A, iSize) A().AllocateDebug(iSize, __FILE__, __LINE__)
#elif !defined(VK_DOXYGEN)
	#define vkAllocateEx(A, iSize) A().Allocate(iSize)
#else
	/**
	Function for allocating raw memory.

	@see vkDeallocate, vkTellSize
	*/
	#define vkAllocateEx(A, iSize)
#endif

#if defined(VK_MEMORYDEBUG) && !defined(VK_DOXYGEN)
	#define vkDeallocateEx(A, iPointer) A().DeallocateDebug(iPointer, __FILE__, __LINE__)
#elif !defined(VK_DOXYGEN)
	#define vkDeallocateEx(A, iPointer) A().Deallocate(iPointer)
#else
	/**
	Function for deallocating raw memory.

	@see vkAllocate, vkTellSize
	*/
	#define vkDeallocateEx(A, iPointer)
#endif

	template <class A>
	class vkGenHeapObject 
	{
	public:

		void*	operator new(size_t iSize)
		{
			return vkAllocateEx(A, (uint32)iSize);
		}

		void	operator delete(void* iP, size_t)
		{
			vkDeallocateEx(A, iP);
		}

		// For placement new
		void*	operator new(size_t iSize, void* p)
		{
			return p;
		}
		void	operator delete(void* p, void*)
		{}
	};

	//{secret}
	template <typename T, int POD = vkIsPod<T>::result>
	class vkMemoryTool
	{
	public:

		// Fill
		VK_INLINE static T* Fill(T* iStart, T* iEnd, const T& iValue)
		{
			while (iStart < iEnd) {
				*iStart = iValue;
				++iStart;
			}
			return iStart;
		}

		// Uninitialisated Fill
		VK_INLINE static T* UFill(T* iStart, T* iEnd, const T& iValue)
		{
			while (iStart < iEnd) {
				new (iStart) T(iValue);
				++iStart;
			}
			return iEnd;
		}

		// Uninitialisated Copy
		VK_INLINE static T* UCopy(T* iDest, const T* iStart, const T* iEnd)
		{
			while (iStart != iEnd) {
				new (iDest) T(*iStart);
				++iDest;
				++iStart;
			}
			return iDest;
		}

		// Copy
		VK_INLINE static T* Copy(T* iDest, const T* iStart, const T* iEnd)
		{
			while (iStart != iEnd) {
				*iDest = *iStart;
				++iDest;
				++iStart;
			}	
			return iDest;
		}

		// SwapCopy
		VK_INLINE static T* SwapCopy(T* iDest, T* iStart, T* iEnd)
		{
			while (iStart != iEnd) {
				vkSwap(*iDest, *iStart);
				++iDest;
				++iStart;
			}
			return iDest;
		}

		// SwapMove
		VK_INLINE static void SwapMove(T* iDest, T* iStart, T* iEnd)
		{
			if (iStart == iEnd) 
				return;

			iDest = iDest + (iEnd - iStart);
			while (iEnd != iStart) {
				--iDest;
				--iEnd;
				vkSwap(*iDest,*iEnd);
			}
		}

		// Move
		VK_INLINE static void Move(T* iDest, T* iStart, T* iEnd)
		{

			if(iDest<iStart){
				vkMemoryTool<T>::Copy(iDest,iStart,iEnd);
			}else{				
				iDest = iDest + (iEnd - iStart);
				while (iEnd != iStart) {
					--iDest;
					--iEnd;
					*iDest = *iEnd;
				}
			}
		}

		// Destroy
		VK_INLINE static void Destroy(T* iStart, T* iEnd)
		{
			// only have to call dtor if it is not a POD
			for (T* it = iStart; it != iEnd; ++it) {
				it->~T();
			}
		}

		// Destroy
		VK_INLINE static void Destroy(T* iPointer)
		{
			// only have to call dtor if it is not a POD
			iPointer->~T();
		}

		// Construct
		VK_INLINE static void Construct(T* iPointer, const T& iValue)
		{
			new (iPointer) T(iValue);
		}
	};

	template <typename T> 
	class vkMemoryTool<T, 1>
	{
	public:
		// Fill
		VK_INLINE static T* Fill(T* iStart, T* iEnd, const T& iValue)
		{
			while (iStart < iEnd) {
				*iStart = iValue;
				++iStart;
			}
			return iStart;
		}

		// Uninitialisated Fill
		VK_INLINE static T* UFill(T* iStart, T* iEnd, const T& iValue)
		{
			while (iStart < iEnd) {
				new (iStart) T(iValue);
				++iStart;
			}
			return iEnd;
		}

		// Uninitialisated Copy
		VK_INLINE static T* UCopy(T* iDest, const T* iStart, const T* iEnd)
		{
			uint32 count = uint32((uint8*)iEnd - (uint8*)iStart);
			if (count) {
				VKASSERT(iDest > iEnd || ((((uint8*)iDest)+(count)) <= (uint8*)iStart)); // No overlap allowed
				vkMemCopy(iDest, iStart, count);
				// memcpy(iDest, iStart, count);
			}
			return (T*)((uint8*)iDest + count);
		}

		// Copy
		VK_INLINE static T* Copy(T* iDest, const T* iStart, const T* iEnd)
		{
			uint32 count = uint32((uint8*)iEnd - (uint8*)iStart);
			if (count) {
				VKASSERT(iDest > iEnd || ((((uint8*)iDest)+(count)) <= (uint8*)iStart)); // No overlap allowed
				vkMemCopy(iDest, iStart, count);
				// memcpy(iDest, iStart, count);
			}
			return (T*)((uint8*)iDest + count);
		}

		// Move
		VK_INLINE static void Move(T* iDest, T* iStart, T* iEnd)
		{
			uint32 size = uint32((uint8*)iEnd - (uint8*)iStart);
			if (size) {
				vkMemMove(iDest, iStart, size);
				// memmove(iDest,iStart,size);
			}
		}
		
		// Destroy
		VK_INLINE static void Destroy(T* iStart, T* iEnd)
		{
		}

		// Destroy
		VK_INLINE static void Destroy(T* iPointer)
		{
		}

		// Destroy
		VK_INLINE static void Construct(T* iPointer, const T& iValue)
		{
			// only have to call dtor if it is not a POD
			*iPointer = iValue;
		}
	};

}

#if defined(VK_COMPILER_MSVC)
	#pragma warning(pop)
#endif

#endif // __vkMemoryUtils_h

#if !defined(vkMemoryUtils_hpp)
#include "vkMemoryUtils.hpp"
#endif

