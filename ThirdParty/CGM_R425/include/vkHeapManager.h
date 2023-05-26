/**
@file

This file defines the heap manager implementation.

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkHeapManager_h)
#define __vkHeapManager_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkStandardAllocator_h)
#include "vkStandardAllocator.h"
#endif
#if !defined(__vkUtil_h)
	#include "vkUtil.h"
#endif

// Macro to define if you want memory stats when leaving the application
#define VK_MEMORYPROFILE

namespace VKernel
{
	class vkHeapManagerTest;
	struct vkHMData;
	
/**
Heap allocator class.

vkHeapManager is the default allocator for @SDK_NAME. It is 
designed for low fragmentation and maximum efficiency.
To achieve this goal, allocations are divided in two groups : 
Large blocks and small blocks. 

The large blocks (default is greater than 64 bytes) are allocated 
in large pages (default is 1 MBytes per page) and they can be spreaded 
on multiple pages (up to 256 by default). The allocation
policy is to fill the most occupied page, using a best fit algorithm to use 
the free (possibly fragmented) space. The large blocks have an overhead of
8 bytes per allocation in release.

The small blocks are classified by size in pools (default size 1024 bytes).
The pools resides in Small Pages (default is 256 KBytes). Each pool only contains
one allocation size (only multiple of 4 bytes). There is no overhead per allocation
of a small size block (but there is one per small page).

In Debug mode, the allocation are 16 bytes larger because of start markers
kBlockBegin and end markers kBlockEnd that are written around the 
allocated block (to detect possible buffer overrun or underrun).
	In debug again, the uninitialized memory is wiped with the kBlockUninit 
pattern and the freed memory with the kBlockFreed pattern.

@ingroup grp_memory
*/
class vkHeapManager : public vkStdHeapObject
{
	friend class vkHeapManagerTest;
	friend class vkuiHeapManagerRenderer;
	friend class vkKernelModule;
	friend struct vkHMData;
public:

	//////////////////////////////////////////////////////////////////////////
	// Types

	/**
	Enum of constants used by the heap manager.
	*/
	enum {
		kBlockBegin				= 0xa0b0c0d0,	// Marker before the allocation block
		kBlockEnd				= 0xd9c9b9a9,	// Marker after the allocation block
		kBlockFreed				= 0xef,			// Marker recovering an allocation block after being freed
		kBlockUninit			= 0xab,			// Marker recovering the allocation block after allocation

		// Small Pages
		kSmallPagePoolSize		= 1024*8,		// size of the pools containining small blocks
		kSmallPageBlockLimit	= 64,			// limit of the small blocks (included)
		kSmallPageSize			= 256*1024,		// Size of the small blocks pages (pages containing the pools)

		// Large Pages
		kLargePageCountBits		= 8,			// number of bits representing the maximum number of large pages
#if defined(VK_TARGET_WINCE)
		kLargePageBits			= 21,
#else
		kLargePageBits			= 23,			// number of bits representing the size of a large page (>23 means the header size 3 dwords instead of 2)
#endif
		kLargePageCount			= 1 << kLargePageCountBits, // maximum number of large block pages
		kLargePageSize			= 1 << kLargePageBits		// size of the large blocks pages
	};

	//////////////////////////////////////////////////////////////////////////
	// Memory information structures

	/**
	Structure containing statistics about memory allocation.
	
	- current: is the current size allocated.
	- accum: is the accumulated size from the start.
	- peak: is the peak size allocated from the start.
	- acount: is the total number of allocation.
	- dcount: is the total number of deallocation.

	This structure are returned when asking for statistics about the
	allocation of large or small blocks, and derived version when asking for 
	stats on a specific allocation context.

	@see GetLargeBlocksStats, GetSmallBlocksStats, AllocContext
	*/
	struct VKKERNEL_API Stats
	{
		Stats();
		void		Add(uint32 iSize);
		void		Remove(uint32 iSize);
		uint32		current;
		uint32		accum;
		uint32		peak;
		uint32		acount;
		uint32		dcount;
		uint32		pcount;
	};

	// {secret} Default Ctor
	VKKERNEL_API vkHeapManager();
	// {secret} Dtor
	VKKERNEL_API ~vkHeapManager();

	/**
	Returns the global instance of the heap
	manager.
	*/
	VKKERNEL_API static vkHeapManager& Instance();

	VKKERNEL_API static bool IsInitialized();

	/**
	Allocate iSize bytes.
	
	The memory will be allocated differently whether you are allocating
	a small size block or a large size block (limit : SMALLLIMIT (def:64))
	The memory allocated with this function MUST be released with the
	Deallocate function.

	Prefer the vkAllocate, vkDeallocate and vkTellSize macros which will 
	use the debug versions of these functions whether you are in debug or
	release mode, providing more security and more debugging information.

	@see Deallocate, TellSize, vkKernelModule::SetAllocatorFunctions
	*/
	vkAllocateFct Allocate;

	/**
	deallocate a previously returned pointer.
	
	@param iPointer the pointer to deallocate.
	
	@see Allocate, TellSize, vkKernelModule::SetAllocatorFunctions
	*/
	vkDeallocateFct Deallocate;

	/**
	returns the size of a previously allocated pointer
	
	This function may not exist if you do not have provided a 
	vkDeallocateFct function pointer.
	
	@param iPointer pointer to query.
	
	@return 
		the size, in bytes, of the memory allocated.
	
	@see Allocate, Deallocate, vkKernelModule::SetAllocatorFunctions
	*/
	vkTellSizeFct TellSize;

	/**
	Allocates aligned memory, on a given boundary.
	
	@param iSize size, in bytes, to allocate.
	@param iAlignment size, in bytes of the pointer boundary.
	@param iPointer pointer to deallocate	
	*/
	void* AllocateAligned(uint32 iSize, uint32 iAlignment);
	void DeallocateAligned(void* iPointer);

	//////////////////////////////////////////////////////////////////////////
	// Debug functions

	#if !defined(VK_DOXYGEN)
	VKKERNEL_API void*	AllocateAlignedDebug(uint32 iSize, uint32 iAlignment, const char* iFile, uint32 iLine);
	VKKERNEL_API void	DeallocateAlignedDebug(void* iPointer, const char* iFile, uint32 iLine);
	VKKERNEL_API void*	AllocateDebug(uint32 iSize, const char* iFile, uint32 iLine);
	VKKERNEL_API void	DeallocateDebug(void* iPointer, const char* iFile, uint32 iLine);
	VKKERNEL_API uint32	TellSizeDebug(void* iPointer) const;
	VKKERNEL_API bool	CheckPointerDebugMarkers(const void* iPointer);
	#endif // VK_DOXYGEN

	//////////////////////////////////////////////////////////////////////////
	// Profiling/Reporting functions

	/**
	Returns the Large blocks statistics.
	
	This function is only relevant if the VK_MEMORYPROFILE macro is
	enabled.

	@see GetSmallBlocksStats
	*/
	VKKERNEL_API const Stats&		GetLargeBlocksStats() const;

	/**
	Returns the small blocks statistics.
	
	This function is only relevant if the VK_MEMORYPROFILE macro is enabled.

	@see GetLargeBlocksStats
	*/
	VKKERNEL_API const Stats&		GetSmallBlocksStats() const;

	VKKERNEL_API uint32	GetGlobalCapacity() const;
	VKKERNEL_API uint32	GetGlobalOccupation() const;

	VKKERNEL_API uint32	GetSmallBlockCapacity() const;
	VKKERNEL_API uint32	GetSmallBlockOccupation() const;

	VKKERNEL_API uint32	GetLargeBlockCapacity() const;
	VKKERNEL_API uint32	GetLargeBlockOccupation() const;
	VKKERNEL_API float	GetLargeBlockFragmentation() const;

	/**
	Dumps in the logging system (as an information) the memory
	leaks.
	
	This function is automatically called when the vkKernel DLL is unloaded.
	This function is only relevant in debug mode.

	@see DumpStatistics
	*/
#if defined(VK_MEMORYDEBUG)
	VKKERNEL_API void	DumpMemoryLeaks() const;
#endif

	/**
	Dumps in the logging system (as an information) the memory
	statistics (Large blocks, Small Blocks and all the allocation contextes
	registered). 
	
	This function is automatically called when the vkKernel DLL is unloaded.
	This function is only relevant in debug mode.

	@see DumpStatistics
	*/
	VKKERNEL_API void	DumpStatistics() const;
	VKKERNEL_API void	FrameProfile() const;

	#if !defined(VK_DOXYGEN)
#if defined(VK_SUPPORT_DEBUGSYMBOL)
	VKKERNEL_API static void SetStackInfo(bool iStackInfo);
#endif
	#endif // VK_DOXYGEN

	#if !defined(VK_DOXYGEN)
	const vkHMData& GetData() const;
	#endif // VK_DOXYGEN

private:

	VKKERNEL_API static void*	_Allocate(size_t iSize);
	VKKERNEL_API static void	_Deallocate(void* iPointer);
	VKKERNEL_API static uint32	_TellSize(void* iPointer);

	VKKERNEL_API uint32			_GetSmallPagesCount() const;

#if defined(VK_MEMORYDEBUG)
	VKKERNEL_API void			_DumpMemoryLeaksWithFile() const;
	#if defined(VK_SUPPORT_DEBUGSYMBOL)
		friend struct vkPoolAllocatorMethods;
		VKKERNEL_API void		_DumpMemoryLeaksWithStack() const;
		VKKERNEL_API void		_RecomputeStack(void* iPointer);
	#endif
#endif

	//////////////////////////////////////////////////////////////////////////
	// Members
	
	// Private implementation data (Pimpl pattern)
	vkHMData*				m_Data;
	// the unique instance
	VKKERNEL_API static vkHeapManager*    s_Instance;
	VKKERNEL_API static bool              s_Initialized;

	static error _Initialize();
	static error _Terminate();

};


#include "vkHeapManager.hpp"

} // end namespace VKernel

#endif // __vkHeapManager_h

