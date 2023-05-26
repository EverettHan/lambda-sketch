/**
@file

This file contains the implementation of multi purpose 
tools functions and functors.

@COPYRIGHT

@author Aymeric Bard
*/

#ifndef VKUTIL_HPP
#define VKUTIL_HPP

namespace VKernel {

//////////////////////////////////////////////////////////////////////////
// StringI functors


VK_INLINE bool 
vkLessStringI::operator()(const char8* iS1,const char8* iS2) const 
{ 
	return vkStrICmp(iS1,iS2) < 0; 
}


//////////////////////////////////////////////////////////////////////////

VK_INLINE bool
vkGreaterStringI::operator()(const char8* iS1,const char8* iS2) const 
{ 
	return vkStrICmp(iS1,iS2) > 0; 
}

//////////////////////////////////////////////////////////////////////////

VK_INLINE bool 
vkEqualStringI::operator()(const char8* iS1,const char8* iS2) const 
{ 
	return vkStrICmp(iS1,iS2) != 0; 
}

//////////////////////////////////////////////////////////////////////////

VK_INLINE uint32 
vkHashFunctionStringI::operator()(const char8* iS) const
{
	uint32 h = 0; 

	for ( ; *iS; ++iS)
		h = 5*h + vkToLower(*iS);

	return h;
}

//////////////////////////////////////////////////////////////////////////

VK_INLINE bool	
vkIsPowerOf2(uint32 iX)
{
	return (iX != 0) && !(iX & (iX-1));
}

VK_INLINE bool	
vkIsAligned(void* iX,uint32 iAlignInByte)
{
	return VK_POINTER_TO_PTRDIFF(iX) &((iAlignInByte)-1)?0:1;
}

VK_INLINE uint32	
vkAlign(uint32 iSize,uint32 iAlignInByte)
{
	VKASSERT(vkIsPowerOf2(iAlignInByte));
	return (iSize + (iAlignInByte)-1) & ~((iAlignInByte)-1);
}


VK_INLINE uint32 
vkNearestPowerOf2(uint32 iV)
{
	iV += (iV >> 1);
	iV |= (iV >> 1);
	iV |= (iV >> 2);
	iV |= (iV >> 4);
	iV |= (iV >> 8);
	iV |= (iV >> 16);
	return (iV & ~(iV >> 1));
}

VK_INLINE uint32 
vkNextPowerOf2(uint32 iV)
{
	iV |= (iV >> 1);
	iV |= (iV >> 2);
	iV |= (iV >> 4);
	iV |= (iV >> 8);
	iV |= (iV >> 16);
	return (iV+1);
}

VK_INLINE uint32 
vkBitCount(uint32 iV)
{
	iV -= ((iV >> 1) & 0x55555555);
	iV = (((iV >> 2) & 0x33333333) + (iV & 0x33333333));
	iV = (((iV >> 4) + iV) & 0x0f0f0f0f);
	iV += (iV >> 8);
	iV += (iV >> 16);
	return(iV & 0x0000003f);
}

VK_INLINE int32 
vkLog2(uint32 iV)
{
	iV |= (iV >> 1);
	iV |= (iV >> 2);
	iV |= (iV >> 4);
	iV |= (iV >> 8);
	iV |= (iV >> 16);
	return vkBitCount(iV) - 1;
}

VK_INLINE int32 
vkLog2(int32 iV)
{
	iV |= (iV >> 1);
	iV |= (iV >> 2);
	iV |= (iV >> 4);
	iV |= (iV >> 8);
	iV |= (iV >> 16);
	return vkBitCount(iV) - 1;
}

VK_INLINE int32 
vkLeastSignificantBit(uint32 iV)
{
#if defined(VK_COMPILER_MSVC) && defined(VK_PROC_X86) && !defined(VK_GCC_XML)
	__asm {
        bsf eax, iV
		jnz lsb_end
		mov eax, -1
	lsb_end:
	}
#else
	// compute the LSB
	iV &= (~iV + 1); 
	// return the index
	return vkLog2(iV);
#endif
}

VK_INLINE int32 
vkMostSignificantBit(uint32 iV)
{
#if defined(VK_COMPILER_MSVC) && defined(VK_PROC_X86) && !defined(VK_GCC_XML)
	__asm {
		bsr eax, iV
		jnz lsb_end
		mov eax, -1
	lsb_end:
	}
#else
	// return the index of the msb
	return vkLog2(iV);
#endif
}

VK_INLINE int32 vkFloori(real iF)
{
#if defined(VK_REAL_DOUBLE_PRECISION)
	return (int32)floor(iF);
#else
	return (int32)floorf(iF);
#endif
}

VK_INLINE real vkFloor(real iF)
{
#if defined(VK_REAL_DOUBLE_PRECISION)
	return floor(iF);
#else
	return floorf(iF);
#endif
}

VK_INLINE real vkFrac(real iF)
{
	real ip;
#if defined(VK_REAL_DOUBLE_PRECISION)
	return modf(iF, &ip);
#else
	return modff(iF, &ip);
#endif
}

VK_INLINE real vkFrac(real iF, real& oIntPart)
{
#if defined(VK_REAL_DOUBLE_PRECISION)
	return modf(iF, &oIntPart);
#else
	return modff(iF, &oIntPart);
#endif
}


VK_INLINE int32 vkRoundi(real iF)
{
	return vkFloori(iF + (real)0.5);
}

VK_INLINE real vkRound(real iF)
{
	return vkFloor(iF + (real)0.5);

}

VK_INLINE int32 vkCeili(real iF)
{
#if defined(VK_REAL_DOUBLE_PRECISION)
	return (int32)ceil(iF);
#else
	return (int32)ceilf(iF);
#endif
}

VK_INLINE real vkCeil(real iF)
{
#if defined(VK_REAL_DOUBLE_PRECISION)
	return ceil(iF);
#else
	return ceilf(iF);
#endif
}

//////////////////////////////////////////////////////////////////////////

VK_INLINE bool vkIsNull(const real iVal1, const real iEpsilon)
{
	return (vkAbs(iVal1) < iEpsilon);
}

////////////////////////////////////////////////////////////////////////////////

} // end namespace VKernel

#endif // VKUTIL_HPP


