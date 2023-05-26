
#if !defined(vkHeapObject_hpp)
#define vkHeapObject_hpp

namespace VKernel
{

VK_INLINE
void*
vkHeapObject::operator new(size_t iSize)
{
	return vkAllocate((uint32)iSize);
}

VK_INLINE
void
vkHeapObject::operator delete(void* iP, size_t)
{
	if (iP)
		vkDeallocate(iP);
}

// For placement new

VK_INLINE
void*
vkHeapObject::operator new(size_t, void* p)
{
	return p;
}

VK_INLINE
void
vkHeapObject::operator delete(void*, void*)
{
}

} // VKernel

#endif // vkHeapObject_hpp



