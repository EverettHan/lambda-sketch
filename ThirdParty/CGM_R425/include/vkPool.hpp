/**
@file

This file contains the implementation of a pool.

@COPYRIGHT

@author Aymeric Bard
*/


template <typename T, bool TFastStack>
vkPool<T, TFastStack>::vkPool(const uint32 iChunkSize, const uint16 iAlignment):m_Allocator(sizeof(T), iChunkSize, iAlignment)
{
	m_Mutex = new vkMutex("POOL");
}

template <typename T, bool TFastStack>
vkPool<T, TFastStack>::~vkPool()
{
	Empty();
	delete (m_Mutex);
}

//////////////////////////////////////////////////////////////////////////

template <typename T, bool TFastStack>
T*		
vkPool<T, TFastStack>::New()
{
	vkMutex::Lock lock(*m_Mutex);
	return new (m_Allocator.Allocate()) T;
}

//////////////////////////////////////////////////////////////////////////

template <typename T, bool TFastStack>
T*		
vkPool<T, TFastStack>::New(const T& iValue)
{
	vkMutex::Lock lock(*m_Mutex);
	return new (m_Allocator.Allocate()) T(iValue);
}

//////////////////////////////////////////////////////////////////////////

#if defined(VK_COMPILER_MSVC)
	#pragma warning (push)
	#pragma warning (disable:4127)
#endif

template <typename T, bool TFastStack>
void	
vkPool<T, TFastStack>::Delete(T* iP)
{
	if (!TFastStack) {
		vkMutex::Lock lock(*m_Mutex);
		vkMemoryTool<T>::Destroy(iP);
		m_Allocator.Deallocate(iP);
	}
}

#if defined(VK_COMPILER_MSVC)	
	#pragma warning (pop)
#endif

//////////////////////////////////////////////////////////////////////////

template <typename T, bool TFastStack>
void	
vkPool<T, TFastStack>::Clear()
{
	vkMutex::Lock lock(*m_Mutex);
	if (!vkIsPod<T>::result) {
		vkFixedSizeAllocator::Chunks& chunks = m_Allocator.m_Chunks;
		// we clear all the chunks
		for (vkFixedSizeAllocator::Chunks::Iterator it = chunks.Begin(); it != chunks.End(); ++it) {
			//it->CallDtor<T>((uint32) m_Allocator.m_BlockSize, (uint32) m_Allocator.m_BlockCount);
		}
	}

	m_Allocator.Clear();
}

template <typename T, bool TFastStack>
void	
vkPool<T, TFastStack>::Empty()
{
	vkMutex::Lock lock(*m_Mutex);
	if (!vkIsPod<T>::result) {
		vkFixedSizeAllocator::Chunks& chunks = m_Allocator.m_Chunks;
		// we clear all the chunks
		for (vkFixedSizeAllocator::Chunks::Iterator it = chunks.Begin(); it != chunks.End(); ++it) {
			//it->CallDtor<T>((uint32) m_Allocator.m_BlockSize, (uint32) m_Allocator.m_BlockCount);
		}
	}

	m_Allocator.Empty();
}

//////////////////////////////////////////////////////////////////////////

template <typename T, bool TFastStack>
const vkFixedSizeAllocator&	
vkPool<T, TFastStack>::GetAllocator() const
{
	return m_Allocator;
}

//////////////////////////////////////////////////////////////////////////
