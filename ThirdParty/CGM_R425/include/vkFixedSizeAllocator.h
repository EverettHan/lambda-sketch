/**
@file

This file contains the definition of an allocator
of blocks of fixed size, used mostly for small objects pool.

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkFixedSizeAllocator_h)
#define __vkFixedSizeAllocator_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkArray_h)
	#include "vkArray.h"
#endif

namespace VKernel
{

template <typename T, bool TFastStack> class vkPool;

/**
Class representation of a fixed size allocator.

Allows the user to allocate small block of memory of fixed size.
This class will seldomly be used directly but in conjunction with vkPool 
instead.

@see vkPool

@ingroup grp_memory
*/
class vkFixedSizeAllocator
{
public:

	enum {
		/** Default chunk size. */
		kDefaultChunkSize = 4096
	};

	/**
	Constructor.

	@param iBlockSize size of the block this allocator will allocate.
	@param iChunkSize size of the chunk to will contains the blocks (the bigger, the less overhead, but also
	potentially the more fragmented).
	@param iAlignment value of the alignment in bytes this allocator must use to allocate memory.
	*/
	VKKERNEL_API vkFixedSizeAllocator(const uint32 iBlockSize, const uint32 iChunkSize = kDefaultChunkSize, const uint16 iAlignment = 0);
	
	/**
	Destructor.
	*/
	VKKERNEL_API ~vkFixedSizeAllocator();

	/**
	Return the number of allocated blocks.
	*/
	VKKERNEL_API uint32 GetBlocksCount() const;

	/**
	Return the number of allocated chunks.
	*/
	VKKERNEL_API uint32 GetChunksCount() const;

	/**
	Return the size allocated in chunks.
	
	Returned value is in bytes.
	*/
	VKKERNEL_API uint32	GetChunksTotalSize() const;

	/**
	Return the occupation percentage of the
	allocator : used space/reserved space ratio between 
	0 and 100.
	*/
	VKKERNEL_API uint32 GetOccupation() const;

	/**
	Clear all the blocks reserved and free  the memory used.
	*/
	VKKERNEL_API void Clear();

	/**
	Clear all the blocks reserved.
	*/
	VKKERNEL_API void Empty();

	/**
	Allocates one block of raw memory, with no initialization.
	*/
	VKKERNEL_API void* Allocate();

	/**
	Deallocates one block of raw memory.
	*/
	VKKERNEL_API void Deallocate(void* iP);

//private:
	
	// {secret}
	struct Chunk
	{
		bool		Init(uint32 iBlockSize, uint32 iBlockCount, bool bAllocate, uint16 iAlignment);
		void*		Allocate(uint32 iBlockSize);
		void		Deallocate(void* iP, uint32 iBlockSize);
		void		Destroy(uint32 iBlockSize, uint16 iAlignment);
		
		template <typename T>
		void		CallDtor(uint32 iBlockSize, uint32 iBlockCount);

		uint8*		m_Data;
		uint32		m_FirstAvailableBlock;
		uint32		m_BlockAvailables;
	};

	// types
	typedef vkArray<Chunk>	Chunks;

	// function to find the chunk containing the ptr
	Chunk*			_FindChunk(void* iP);

	// members
	uint32			m_BlockSize;	// Block size
	uint32			m_BlockCount;	// Blocks Count (per Chunk)
	uint32			m_ChunkSize;	// Chunk size
	Chunks			m_Chunks;		// the chunks

	// Allocating and deallocating chunks
	Chunk*			m_AChunk;
	Chunk*			m_DChunk;

	uint16			m_Alignment;
};

#include "vkFixedSizeAllocator.hpp"

} // end of namespace VKernel


#endif // __vkFixedSizeAllocator_h


