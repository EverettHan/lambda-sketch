
#if !defined(vkMemoryUtils_hpp)
#define vkMemoryUtils_hpp

namespace VKernel
{
VK_INLINE void StoreDwordToUnalignedMemory(int32 iSrc, void* oDst)
{
	#if defined(VK_DWORD_COPY_MUST_BE_ALIGNED)
		vkMemCopy(oDst,&iSrc,4);
	#else
		*(int32*)oDst = iSrc;
	#endif
}

VK_INLINE int32 LoadDwordFromUnalignedMemory(void* iSrc)
{
	#if defined(VK_DWORD_COPY_MUST_BE_ALIGNED)
		int32 temp;
		vkMemCopy(&temp,iSrc,4);
	return temp;
	#else
		return *(int32*)iSrc;
	#endif
}

VK_INLINE void StoreQwordToUnalignedMemory(int64 iSrc, void* oDst)
{
	#if defined(VK_DWORD_COPY_MUST_BE_ALIGNED)
		vkMemCopy(oDst,&iSrc,4);	
	#else
		*(int64*)oDst = iSrc;
	#endif
}

VK_INLINE int64 LoadQwordFromUnalignedMemory(void* iSrc)
{
	#if defined(VK_DWORD_COPY_MUST_BE_ALIGNED)
		int64 temp;
		vkMemCopy(&temp,iSrc,4);
		return temp;
	#else
		return *(int64*)iSrc;
	#endif
}

VK_INLINE void StoreFloatToUnalignedMemory(float iSrc, void* oDst)
{
	#if defined(VK_DWORD_COPY_MUST_BE_ALIGNED)
		vkMemCopy(oDst,&iSrc,4);	
	#else
		*(float*)oDst = iSrc;
	#endif
	}

VK_INLINE float LoadFloatFromUnalignedMemory(void* iSrc)
{
	#if defined(VK_FLOAT_COPY_MUST_BE_ALIGNED)
		uint32 temp;
		vkMemCopy(&temp,iSrc,4);
		return *(float*)&temp;
	#else
		return *(float*)iSrc;
	#endif
}

} //namespace VKernel

#endif // vkMemoryUtils_hpp



