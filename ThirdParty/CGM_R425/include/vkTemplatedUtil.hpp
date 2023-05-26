/**
@file

This file contains the implementation of multi purpose 
tools functions and functors.

@COPYRIGHT

@author Aymeric Bard
*/

//////////////////////////////////////////////////////////////////////////
// Functors
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// vkLess

namespace VKernel{

template <typename T>
VK_INLINE bool vkLess<T>::operator()(const T& iT1, const T& iT2) const 
{
	return (iT1 < iT2);
}
template <typename T>
VK_INLINE bool vkLessFirstOfPair<T>::operator()(const T& iT1, const T& iT2) const 
{
	return (iT1.first < iT2.first);
}

//////////////////////////////////////////////////////////////////////////

template <>
struct vkLess<const char8*>
{
	VK_INLINE int operator()(const char8* iS1,const char8* iS2) const { return vkStrCmp(iS1,  iS2) < 0;}
};

//////////////////////////////////////////////////////////////////////////
// vkGreater

template <typename T>
VK_INLINE bool vkGreater<T>::operator()(const T& iT1, const T& iT2) const 
{
	return (iT1 > iT2);
}

//////////////////////////////////////////////////////////////////////////

template <>
struct vkGreater<const char8*>
{
	VK_INLINE bool operator()(const char8* iS1,const char8* iS2) const { return vkStrCmp(iS1,  iS2) > 0;}
};

//////////////////////////////////////////////////////////////////////////

template <>
struct vkGreater<char8*>
{
	VK_INLINE bool operator()(char8* iS1,char8* iS2) const { return vkStrCmp(iS1,  iS2) > 0;}
};

//////////////////////////////////////////////////////////////////////////
// vkEqual


template <typename T>
VK_INLINE bool vkEqual<T>::operator()(const T& iT1, const T& iT2) const 
{
	return (iT1 == iT2);
}
template <typename T>
VK_INLINE bool vkEqualFirstOfPair<T>::operator()(const T& iT1, const T& iT2) const 
{
	return (iT1.first == iT2.first);
}

//////////////////////////////////////////////////////////////////////////

template <>
struct vkEqual<const char8*>
{
	VK_INLINE bool operator()(const char8* iS1,const char8* iS2) const { return !vkStrCmp(iS1,  iS2); }
};

//////////////////////////////////////////////////////////////////////////

template <>
struct vkEqual<char8*>
{
	VK_INLINE bool operator()(char8* iS1,char8* iS2) const { return !vkStrCmp(iS1,  iS2); }
};

//////////////////////////////////////////////////////////////////////////
// vkContains

// No default implementation

template <>
struct vkContains<char8*>
{
	VK_INLINE bool operator()(const char8* iS1, const char8* iS2) const 
	{ 
		return strstr(iS1, iS2) != nullptr;
	}
};

//////////////////////////////////////////////////////////////////////////
// vkHashFunction

template <typename T> 
VK_INLINE uint32 
vkHashFunction<T>::operator()(const T& iT) const
{
	return iT;
}

//////////////////////////////////////////////////////////////////////////

template <>
struct vkHashFunction<const char8*>
{
	VK_INLINE uint32 operator()(const char8* iS) const 
	{ 
		uint32 h = 0; 
		for ( ; *iS; ++iS)
			h = h*33 + *iS;

		return h;
	}
};

template <>
struct vkHashFunction<char8*>
{
	VK_INLINE uint32 operator()(char8* iS) const 
	{ 
		uint32 h = 0; 
		for ( ; *iS; ++iS)
			h = h*33 + *iS;

		return h;
	}
};

//////////////////////////////////////////////////////////////////////////

template <>
struct vkHashFunction<float>
{
	VK_INLINE uint32 operator()(const float iF) const 
	{
		return *(uint32*)&iF; 
	}
};

//////////////////////////////////////////////////////////////////////////

template <>
struct vkHashFunction<uint64>
{
	VK_INLINE uint32 operator()(const uint64 iF) const 
	{
		uint32 h = (uint32)(iF>>32);
		uint32 l = (uint32)(iF & 0x00000000FFFFFFFF);
		return h^l; 
	}
};

//////////////////////////////////////////////////////////////////////////

template <>
struct vkHashFunction<void*>
{
	VK_INLINE uint32 operator()(const void* iP) const 
	{
		#ifdef VK_64BIT
			ptrdiff p = VK_POINTER_TO_PTRDIFF(iP);
			ptrdiff p2 = p >> 32;
			return (uint32)(p^p2)>>2; 
		#else
			return (VK_POINTER_TO_PTRDIFF(iP))>>2; 
		#endif

	}
};

template <>
struct vkHashFunction<const void*>
{
	VK_INLINE uint32 operator()(const void* const iP) const 
	{
		return (VK_HASH_32(VK_POINTER_TO_PTRDIFF(iP)))>>2; 		
	}
};

//////////////////////////////////////////////////////////////////////////

/* T. Wang
VK_INLINE unsigned int inthash(unsigned int key)
{
	key += ~(key << 15);
	key ^=  (key >> 10);
	key +=  (key << 3);
	key ^=  (key >> 6);
	key += ~(key << 11);
	key ^=  (key >> 16);
	return key;
}

// Golden Ratio : no change constated so unused
VK_INLINE unsigned int inthash(unsigned int key)
{
	return (key * 2654435761);
}
*/

template <typename T>
struct vkHashFunction<const T*>
{
	VK_INLINE uint32 operator()(const T* iP) const 
	{
		return VK_HASH_32(VK_POINTER_TO_PTRDIFF(iP)) / sizeof(T); 
	}
};


template <typename T>
struct vkHashFunction<T*>
{
	VK_INLINE uint32 operator()(const T* iP) const 
	{
		return VK_HASH_32(VK_POINTER_TO_PTRDIFF(iP)) / sizeof(T); 
	}
};

template <typename T, typename U>
struct vkHashFunction<vkPair<T, U> >
{
	uint32 operator()(const vkPair<T, U>& iP) const 
	{
		vkHashFunction<T> hashT; 
		vkHashFunction<U> hashU; 
		return hashT(iP.first) ^ hashU(iP.second);
	}
};

//////////////////////////////////////////////////////////////////////////
// Utilities

template <typename T>
VK_INLINE T 
vkClamp(const T iValue, const T iMin, const T iMax) 
{
	if (iValue < iMin) 
		return iMin;
	if (iValue > iMax) 
		return iMax;
	return iValue;
}

//////////////////////////////////////////////////////////////////////////

template <class T>
VK_INLINE T
vkMin(const T iA, const T iB) 
{
	return (iA < iB)?iA:iB;
}

template <class T>
VK_INLINE T 
vkMin(const T iA, const T iB, const T iC) 
{
	return (iA<iB)?((iC<iA)?iC:iA):((iC<iB)?iC:iB);
}

//////////////////////////////////////////////////////////////////////////

template <class T>
VK_INLINE T 
vkMax(const T iA, const T iB) 
{
	return (iA > iB)?iA:iB;
}

template <class T>
VK_INLINE T 
vkMax(const T iA, const T iB, const T iC) 
{
	return (iA>iB)?((iC>iA)?iC:iA):((iC>iB)?iC:iB);
}

//////////////////////////////////////////////////////////////////////////
template <class TInteger>
VK_INLINE bool
vkIsOdd(TInteger iValue)
{
	return (iValue & 1) != 0;
}

template <class TInteger>
VK_INLINE bool
vkIsEven(TInteger iValue)
{
	return (iValue & 1) == 0;
}

//////////////////////////////////////////////////////////////////////////

template <class T>
VK_INLINE void 
vkSwap(T& ioA, T& ioB) 
{
	T c = ioA;
	ioA = ioB;
	ioB = c;
}

//////////////////////////////////////////////////////////////////////////

template <class T>
VK_INLINE T vkAbs(T iA)
{
	return (iA>0) ? iA : -iA;
}

// float specialization

template <> 
VK_INLINE float vkAbs<float>(float iA) 
{
	return fabsf(iA);
}

template <> VK_INLINE uint8 vkAbs<uint8>(uint8 iA) {return iA;}
template <> VK_INLINE uint16 vkAbs<uint16>(uint16 iA) {return iA;}
template <> VK_INLINE uint32 vkAbs<uint32>(uint32 iA) {return iA;}
template <> VK_INLINE uint64 vkAbs<uint64>(uint64 iA) {return iA;}

//////////////////////////////////////////////////////////////////////////

template <typename T>
VK_INLINE T
vkChangeMask(const bool iSet, T iBitsField, const uint32 iMask)
{
	if (iSet)
		return iBitsField | T(iMask);
	else
		return iBitsField & ~T(iMask);
}

template <typename T>
VK_INLINE T
vkChangeMask64(const bool iSet, T iBitsField, const uint64 iMask)
{
	if (iSet)
		return iBitsField | T(iMask);
	else
		return iBitsField & ~T(iMask);
}

//////////////////////////////////////////////////////////////////////////
// vkByteSwap specializations

// tool function
template <class T>
VK_INLINE void
vkByteSwapArray(T* ioValue, const uint32 iLength)
{	
	T* p	 = ioValue - 1;
	T* pEnd  = ioValue + iLength;

	while (++p < pEnd)
	{
		vkByteSwap<T>(*p);
	}
}

// default implementation of the array function
template <class T>
VK_INLINE void
vkByteSwap(T* ioValue, const uint32 iLength)
{
	// TODO : Write the platform specific implementation for speed optimization (PC/Mac...)
	vkByteSwapArray<T>(ioValue, iLength);
}


// Perform the byte swapping on the 16 bit data



template <>
VK_INLINE uint16
vkByteSwap<uint16>(uint16& ioValue)
{
	// TODO : Write the platform specific implementation for speed optimization (PC/Mac...)
	const uint16 v = ioValue;
	return ioValue = (v << 8) | ((v >> 8) & 0x00FF);
}

template <>
VK_INLINE int16
vkByteSwap<int16>(int16& ioValue)
{
	return vkByteSwap<uint16>((uint16&)ioValue);
}

// Perform the byte swapping on the 24 bit data

template <>
VK_INLINE uint24
vkByteSwap<uint24>(uint24& ioValue)
{
	// TODO : Write the platform specific implementation for speed optimization (PC/Mac...)
	const uint8 lo = ioValue.lo;
	ioValue.lo = ioValue.hi;
	ioValue.hi = lo;
	return ioValue;

}

// Perform the byte swapping on the 32 bit data


template <>
VK_INLINE uint32
vkByteSwap<uint32>(uint32& ioValue)
{
	// TODO : Write the platform specific implementation for speed optimization (PC/Mac...)
	const uint32 v = ioValue;
	return  ioValue = (v << 24) | ((v << 8) & 0x00FF0000) | ((v >> 8) & 0x0000FF00) | ((v >> 24) & 0x000000FF);

}

template <>
VK_INLINE int32
vkByteSwap<int32>(int32& ioValue)
{
	return (int32) vkByteSwap<uint32>((uint32&)ioValue);
}

// Perform the byte swapping on the 64 bit data

template <>
VK_INLINE uint64
vkByteSwap<uint64>(uint64& ioValue)
{
	// Warning this code does not compile as it should on Xenon in Release mode with Optimize for speed
	// Something to watch for.
	uint32* pHiWord = (uint32*)&ioValue;
	uint32* pLoWord = ((uint32*)&ioValue) + 1;

	vkByteSwap<uint32>(*pHiWord);
	vkByteSwap<uint32>(*pLoWord);

	const uint32 tmp = *pHiWord;
	*pHiWord = *pLoWord;
	*pLoWord = tmp;
	return ioValue;
}

template <>
VK_INLINE int64
vkByteSwap<int64>(int64& ioValue)
{
	return (int64) vkByteSwap<uint64>((uint64&)ioValue);
}

// Perform the byte swapping on the float data

template <>
VK_INLINE float
vkByteSwap<float>(float& ioValue)
{
	vkByteSwap<uint32>((uint32&)ioValue);
	return ioValue;

}

// Perform the byte swapping on the double data

template <>
VK_INLINE double
vkByteSwap<double>(double& ioValue)
{
	vkByteSwap<uint64>((uint64&)ioValue);
	return ioValue;

}

//////////////////////////////////////////////////////////////////////////
// template specializations
//////////////////////////////////////////////////////////////////////////

template <> struct vkIsPod<char8> {enum {result = 1};};
template <> struct vkIsPod<int64> {enum {result = 1};};
template <> struct vkIsPod<uint64> {enum {result = 1};};
template <> struct vkIsPod<int32> {enum {result = 1};};
template <> struct vkIsPod<uint32> {enum {result = 1};};
template <> struct vkIsPod<int16> {enum {result = 1};};
template <> struct vkIsPod<uint16> {enum {result = 1};};
template <> struct vkIsPod<int8> {enum {result = 1};};
template <> struct vkIsPod<uint8> {enum {result = 1};};
template <> struct vkIsPod<float> {enum {result = 1};};
template <> struct vkIsPod<double> {enum {result = 1};};
template <> struct vkIsPod<bool> {enum {result = 1};};
template <typename T> struct vkIsPod<T*> {enum {result = 1};};

//////////////////////////////////////////////////////////////////////////

template <> 
struct vkNumericLimits<int8>
{
	enum {
		IsSigned	= 1,
		IsInteger	= 1
	};
	static int8 Min() throw() {return -128;}
	static int8 Max() throw() {return 127;}
	static int8 Epsilon() throw() {return 0;}
};

template <> 
struct vkNumericLimits<uint8>
{
	enum {
		IsSigned	= 0,
		IsInteger	= 1
	};
	static uint8 Min() throw() {return 0;}
	static uint8 Max() throw() {return 0xff;}
	static uint8 Epsilon() throw() {return 0;}
};

//////////////////////////////////////////////////////////////////////////

template <> 
struct vkNumericLimits<int16>
{
	enum {
		IsSigned	= 1,
		IsInteger	= 1
	};
	static int16 Min() throw() {return -32768;}
	static int16 Max() throw() {return 32767;}
	static int16 Epsilon() throw() {return 0;}
};

template <> 
struct vkNumericLimits<uint16>
{
	enum {
		IsSigned	= 0,
		IsInteger	= 1
	};
	static uint16 Min() throw() {return 0;}
	static uint16 Max() throw() {return 0xffff;}
	static uint16 Epsilon() throw() {return 0;}
};

//////////////////////////////////////////////////////////////////////////

template <> 
struct vkNumericLimits<int32>
{
	enum {
		IsSigned	= 1,
		IsInteger	= 1
	};
	static int32 Min() throw() {return (-2147483647-1);}
	static int32 Max() throw() {return 2147483647;}
	static int32 Epsilon() throw() {return 0;}
};

template <> 
struct vkNumericLimits<uint32>
{
	enum {
		IsSigned	= 0,
		IsInteger	= 1
	};
	static uint32 Min() throw() {return 0;}
	static uint32 Max() throw() {return 0xffffffff;}
	static uint32 Epsilon() throw() {return 0;}
};

//////////////////////////////////////////////////////////////////////////

template <> 
struct vkNumericLimits<int64>
{
	enum {
		IsSigned	= 1,
		IsInteger	= 1
	};

	static int64 Min() throw() {return VK_CONST_INT64(-9223372036854775807) - 1;}
	static int64 Max() throw() {return VK_CONST_INT64(9223372036854775807);}
	static int64 Epsilon() throw() {return 0;}
};

template <> 
struct vkNumericLimits<uint64>
{
	enum {
		IsSigned	= 0,
		IsInteger	= 1
	};
	static uint64 Min() throw() {return 0;}
	static uint64 Max() throw() {return VK_CONST_UINT64(0xffffffffffffffff);}
	static uint64 Epsilon() throw() {return 0;}
};

//////////////////////////////////////////////////////////////////////////

template <> 
struct vkNumericLimits<float>
{
	enum {
		IsSigned	= 1,
		IsInteger	= 0
	};
	static float Min() throw() {return -1e38f;}
	static float Max() throw() {return 1e38f;}
	static float Epsilon() throw() {return 1e-6f;}
};

//////////////////////////////////////////////////////////////////////////

template <> 
struct vkNumericLimits<double>
{
	enum {
		IsSigned	= 1,
		IsInteger	= 0
	};
//	static double Min() throw() {return 2.2250738585072014e-308;}
//	static double Max() throw() {return 1.7976931348623158e+308;}
	static double Min() throw() {return -1.e+308;}
	static double Max() throw() {return 1.e+308;}
	static double Epsilon() throw() {return 2.2204460492503131e-016;}
};

////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// specialization of vkApproxEqual

template<>
VK_INLINE bool vkApproxEqual(const double& iVal1, const double& iVal2, const real iEpsilon)
{
	return (vkAbs(iVal2 - iVal1) <= iEpsilon);
}

template<>
VK_INLINE bool vkApproxEqual(const float& iVal1, const float& iVal2, const real iEpsilon)
{
	return (vkAbs(iVal2 - iVal1) <= iEpsilon);
}

template<>
VK_INLINE bool vkApproxEqual(const int64& iVal1, const int64& iVal2, const real)
{
	return iVal2 == iVal1;
}

template<>
VK_INLINE bool vkApproxEqual(const int32& iVal1, const int32& iVal2, const real)
{
	return iVal2 == iVal1;
}

template<>
VK_INLINE bool vkApproxEqual(const int16& iVal1, const int16& iVal2, const real)
{
	return iVal2 == iVal1;
}

template<>
VK_INLINE bool vkApproxEqual(const int8& iVal1, const int8& iVal2, const real)
{
	return iVal2 == iVal1;
}

template<>
VK_INLINE bool vkApproxEqual(const uint64& iVal1, const uint64& iVal2, const real)
{
	return iVal2 == iVal1;
}

template<>
VK_INLINE bool vkApproxEqual(const uint32& iVal1, const uint32& iVal2, const real)
{
	return iVal2 == iVal1;
}

template<>
VK_INLINE bool vkApproxEqual(const uint16& iVal1, const uint16& iVal2, const real)
{
	return iVal2 == iVal1;
}

template<>
VK_INLINE bool vkApproxEqual(const uint8& iVal1, const uint8& iVal2, const real)
{
	return iVal2 == iVal1;
}

} // Namespace VKernel


