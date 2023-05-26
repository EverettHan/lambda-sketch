
#if !defined(vkKernelTypes_hpp)
#define vkKernelTypes_hpp

namespace VKernel
{

VK_INLINE Integer64::Integer64()
{
}

VK_INLINE Integer64::Integer64(int32 iH,uint32 iL)
{
	hi=iH;
	lo=iL;
}

VK_INLINE UInteger64::UInteger64()
{
}

VK_INLINE UInteger64::UInteger64(uint32 iH,uint32 iL)
{
	hi=iH;
	lo=iL;
}

#if defined(VK_64BIT_NOTSUPPORTED)
	VK_INLINE UInteger64::operator uint64(){
		return *this;
	}

	VK_INLINE Integer64::operator int64(){
		return *this;
	}
#else
	 VK_INLINE UInteger64::operator uint64(){
		return (((uint64)hi)<<32) | lo;
	}

	VK_INLINE Integer64::operator int64(){
		return (((int64)hi)<<32) | lo;
	}
#endif


VK_INLINE UInteger24::UInteger24()
#if defined(VK_LITTLE_ENDIAN)
:       lo(0),mid(0),hi(0)
#else
:	hi(0),mid(0),lo(0)
#endif
{
}

VK_INLINE UInteger24::UInteger24(const uint32 iValue)
#if defined(VK_LITTLE_ENDIAN)
:       lo((uint8)(iValue & 0x000000FF)),
        mid((uint8)((iValue & 0x0000FF00) >> 8)),
        hi((uint8)((iValue & 0x00FF0000) >> 16))
#else
:       hi((uint8)((iValue & 0x00FF0000) >> 16)),
        mid((uint8)((iValue & 0x0000FF00) >> 8)),
        lo((uint8)(iValue & 0x000000FF))
#endif
{
}

VK_INLINE UInteger24::operator uint32()
{
	return (uint32(hi) << 16) | (uint32(mid) << 8) | uint32(lo);
}

} // namespace VKernel

#endif // vkKernelTypes_hpp



