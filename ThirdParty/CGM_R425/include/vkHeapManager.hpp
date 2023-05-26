
VK_INLINE vkHeapManager& 
vkHeapManager::Instance() 
{
	return *s_Instance;
}
	
VK_INLINE bool
vkHeapManager::IsInitialized()
{
	return s_Initialized;
}
//////////////////////////////////////////////////////////////////////////

VK_INLINE void* 
vkHeapManager::AllocateAligned(uint32 iSize, uint32 iAlignment)
{
	VKASSERT(vkIsPowerOf2(iAlignment)); // "Non power of 2 alignement not allowed"
	uint8* ptr = (uint8*)Allocate(iSize + sizeof(ptrdiff) + iAlignment);
	if (!ptr) return nullptr;
	ptrdiff* alignedPtr = (ptrdiff*)(VK_POINTER_TO_PTRDIFF(ptr+sizeof(ptrdiff)+(iAlignment-1)) & (~(ptrdiff)(iAlignment-1)));
	*(alignedPtr-1) = VK_POINTER_TO_PTRDIFF(ptr);
	return alignedPtr;
}

VK_INLINE void 
vkHeapManager::DeallocateAligned(void* iPointer)
{
	void* realPtr = (void*)(*((ptrdiff*)iPointer - 1));
	Deallocate(realPtr);
}

VK_INLINE const vkHMData&
vkHeapManager::GetData() const
{
	return *m_Data;
}

//////////////////////////////////////////////////////////////////////////
// Stats

VK_INLINE 
vkHeapManager::Stats::Stats():current(0),accum(0),peak(0),acount(0),dcount(0),pcount(0)
{}

VK_INLINE void 
vkHeapManager::Stats::Add(uint32 iSize) 
{
	++acount;
	current		+= iSize;
	accum		+= iSize;
	if (current > peak)
		peak	= current;
}

VK_INLINE void 
vkHeapManager::Stats::Remove(uint32 iSize) 
{
	++dcount;
	current		-= iSize;
}


