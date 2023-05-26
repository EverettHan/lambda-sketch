/**
@file

This file contains the definition of an allocator
of blocks of fixed size, used mostly for small objects pool.

@COPYRIGHT

@author Aymeric Bard
*/

template <typename T>
VK_INLINE void		
vkFixedSizeAllocator::Chunk::CallDtor(uint32 iBlockSize, uint32 iBlockCount)
{
	// everything is clear -> nothing to do
	if (m_BlockAvailables == iBlockCount) 
		return;

	// else we have some cleaning todo

	if (!m_BlockAvailables) { // we need to clean everything

		{ // we call the dtor of the used blocks
			for (uint32 i=0; i<iBlockCount; ++i) {

				uint8* p = m_Data + i*iBlockSize;
				vkMemoryTool<T>::Destroy((T*)p);
			}

		}

	}/* else { // only some are used

		vkBitSet freeBlocks;

		{ // we mark the objects used
			uint32 freeb = m_FirstAvailableBlock;
			for (uint32 i=0; i<m_BlockAvailables-1; ++i) {

				freeBlocks.Set(freeb);

				uint8* p = m_Data + freeb*iBlockSize;
				freeb = *(uint32*)p;
			}
			freeBlocks.Set(freeb);
		}

		{ // we call the dtor of the used blocks
			for (uint32 i=0; i<iBlockCount; ++i) {

				if (freeBlocks.Test(i))
					continue;

				uint8* p = m_Data + i*iBlockSize;
				vkMemoryTool<T>::Destroy((T*)p);
			}

		}
	}*/
}

