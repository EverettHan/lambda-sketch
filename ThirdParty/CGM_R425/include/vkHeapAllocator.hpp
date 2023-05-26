#if !defined(vkHeapAllocator_hpp)
#define vkHeapAllocator_hpp

namespace VKernel {

VK_INLINE uint8* 
vkHeapAllocator::Allocate(uint32 iSize) 
{
	return (uint8*)vkHeapManager::Instance().Allocate(iSize);
}

VK_INLINE uint8* 
vkHeapAllocator::AllocateAligned (uint32 iSize, uint32 iAlign) 
{
	return (uint8*)vkHeapManager::Instance().AllocateAligned(iSize, iAlign);
}

VK_INLINE uint8* 
vkHeapAllocator::AllocateDebug(uint32 iSize, const char* iFunc, uint32 iLine) 
{
	return (uint8*)vkHeapManager::Instance().AllocateDebug(iSize, iFunc, iLine);
}

VK_INLINE uint8* 
vkHeapAllocator::AllocateAlignedDebug(uint32 iSize, uint32 iAlign, const char* iFunc, uint32 iLine) 
{
	return (uint8*)vkHeapManager::Instance().AllocateAlignedDebug(iSize, iAlign, iFunc, iLine);
}

VK_INLINE void 
vkHeapAllocator::Deallocate(void* iPointer) 
{
	vkHeapManager::Instance().Deallocate(iPointer);
}

VK_INLINE void 
vkHeapAllocator::DeallocateAligned(void* iPointer) 
{
	vkHeapManager::Instance().DeallocateAligned(iPointer);
}

VK_INLINE void 
vkHeapAllocator::DeallocateDebug(void* iPointer, const char* iFile, uint32 iLine) 
{
	vkHeapManager::Instance().DeallocateDebug(iPointer, iFile, iLine);
}

VK_INLINE void 
vkHeapAllocator::DeallocateAlignedDebug(void* iPointer, const char* iFile, uint32 iLine) 
{
	vkHeapManager::Instance().DeallocateAlignedDebug(iPointer, iFile, iLine);
}

} // end namespace VKernel

#endif // vkHeapAllocator_hpp

