/**
@file

This file contains the definition of multi purpose 
tools functions and functors.

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkUtil_h)
#define __vkUtil_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif

#if !defined(__vkKernelTypes_h)
	#include "vkKernelTypes.h"
#endif

#if !defined(__vkStrTools_h)
	#include "vkStrTools.h"
#endif

#include <string.h>
#if defined (VK_TARGET_WINCE) 
#include <cmath>
#else
#include <math.h>
#endif


namespace VKernel
{

class vkString;

/**
"Less Than" comparison functor.

Use this functor in containers or functions with a 
comparison predicate in template arguments.

vkLessStringI is a version for performing a lowercase  comparison.

@see vkGreater
*/
template <typename T>
struct vkLess
{
	bool operator() (const T& iT1, const T& iT2) const;
};
template <typename T>
struct vkLessFirstOfPair
{
	bool operator() (const T& iT1, const T& iT2) const;
};


struct vkLessStringI
{
	bool operator() (const char8* iT1, const char8* iT2) const;
};

/**
"Greater Than" comparison functor

Use this functor in containers or functions with a 
comparison predicate in template arguments.

vkGreaterStringI is a version for performing a lowercase comparison.

@see vkEqual
*/
template <typename T>
struct vkGreater
{
	bool operator() (const T& iT1, const T& iT2) const;
};


struct vkGreaterStringI
{
	bool operator() (const char8* iT1, const char8* iT2) const;
};

/**
"Equal" comparison functor

Use this functor in containers or functions with a 
comparison predicate in template arguments.

vkEqualStringI is a version for perfoming a lowercase 
comparison.

@see vkLess
*/
template <typename T>
struct vkEqual
{
	bool operator() (const T& iT1,const T& iT2) const;
};

template <typename T>
struct vkEqualFirstOfPair
{
	bool operator() (const T& iT1, const T& iT2) const;
};


struct vkEqualStringI
{
	bool operator() (const char8* iT1, const char8* iT2) const;
};

/**
Containment functor.
this functor must return true if the
object iT1 "contains" objet iT2.

No Default behavior is implemented.
A specialization for char8* has been implemented.
*/
template <typename T>
struct vkContains
{
	bool operator()(const T& iT1,const T& iT2) const;
};

/**
Hashing function.

This functor returns an uint32 when given an object, allowing
storage in vkHash.

This function is specialized for:
	- const char8*
	- void*
	- T*
	- float
	- vkString

vkHashFunctionStringI is a version for performing a lowercase hashing.

@see vkHash
*/
template <typename T> 
struct vkHashFunction
{
	uint32 operator()(const T& iT) const;
};

/**
Hashing function for string ignoring the case.

@see vkHashFunction
*/
struct vkHashFunctionStringI
{
	uint32 operator()(const char8* iT) const;
};

/**
class pair definition.
@see vkHash, vkBinaryTree
*/
template <class T, class U>
struct vkPair 
{
	vkPair(const T& iT, const U& iU):first(iT),second(iU) {}
	vkPair() {}

	bool operator == (const vkPair& iOp) const
	{
		return (first == iOp.first) && (second == iOp.second);
	}

	bool operator != (const vkPair& iOp) const
	{
		return (first != iOp.first) || (second != iOp.second);
	}

	T first;
	U second;
};

template <class T, class U>
VK_INLINE vkPair<T,U> vkMakePair(const T& iT, const U& iU){return vkPair<T,U>(iT,iU);}


/**
Clamps a value to an interval.
@param iValue  value to clamp (unchanged by the function).
@param iMin minimum valid value
@param iMax maximum valid value (included)
@return 
	The clamped value.

@see vkMin, vkMax
*/
template <typename T>
T vkClamp(const T iValue, const T iMin, const T iMax);

/**
Returns the minimum of two (or three) values.

@param iA the first value
@param iB the second value
@param iC the third value

@return 
a const reference on the minimum value.

@see vkMax
*/
template <class T>
T vkMin(const T iA, const T iB);

template <class T>
T vkMin(const T iA, const T iB, const T iC);

/**
Returns the maximum of two values.

@param iA: the first value
@param iB the second value

@return 
	a const reference on the maximum value.

@see vkMin
*/
template <class T>
T vkMax(const T iA, const T iB);

/**
Returns the maximum of three values.

@param iA: the first value
@param iB the second value
@param iC the third value

@return 
a const reference on the maximum value.

@see vkMin
*/
template <class T>
T vkMax(const T iA, const T iB, const T iC);

/**
Tests if the given integer value is odd or even
*/
template <class TInteger>
bool vkIsOdd(TInteger iValue);

template <class TInteger>
bool vkIsEven(TInteger iValue);

/**
Swaps two elements.

Swaps oA and oB.	

This function must be specialized for complex types
to optimize containers behavior.
*/
template <class T>
void vkSwap(T& oA,T& oB);

/**
Swaps two buffer.

Swaps the data between oA and oB.	
*/
VKKERNEL_API void vkSwap(void* ioA, void* ioB, uint32 iByteCount);

////////////////////////////////////////////////////////////////////////////////

/**
A holder class for constant values.
*/
class vkConstants 
{
public:
	VKKERNEL_API static real kEpsilon;
	VKKERNEL_API static real kPi;
	VKKERNEL_API static real k2Pi;
	VKKERNEL_API static real k4PiOn3; // for sphere volume (4/3 * Pi * r^3)
	VKKERNEL_API static real kHalfPi;
	VKKERNEL_API static real kPiOn180;
	VKKERNEL_API static real k180OnPi;
	VKKERNEL_API static real kSqrt2;
	VKKERNEL_API static real kHalfSqrt2;
	VKKERNEL_API static real kMinValue;
	VKKERNEL_API static real kMaxValue;
	VKKERNEL_API static real kLog2;
	VKKERNEL_API static real kInvLog2;
	VKKERNEL_API static real kRandMax;
	VKKERNEL_API static real kInvRandMax;
};

/**
Returns the absolute value of a.
*/
template <class T>
T vkAbs(T iA);

/**
return true if the given value is a power of 2

@see  vkNearestPowerOf2, vkNextPowerOf2
*/
VKKERNEL_INL bool vkIsPowerOf2(uint32 iV);

/**
test the float nullity, using a integer comparison.
*/
#define vkIsFloatNull(a) (*(uint32*)&(a) == 0)

/**
test the float nullity, using a integer comparison.
*/
#define vkIsFloatNotNull(a) (*(uint32*)&(a) != 0)

/**
return true if the given pointer is aligned on align byte boundaries.
returns false otherwise.
*/
VKKERNEL_INL bool vkIsAligned(void* iX,uint32 iAlignInByte);

/**
returns the next mutiple iAlignByte after iSize.
**/
VKKERNEL_INL uint32 vkAlign( uint32 iSize,uint32 iAlignInByte);


/**
return the nearest power of 2 of a 32 bits dword.

@see  vkIsPowerOf2, vkNextPowerOf2
*/
VKKERNEL_INL uint32 vkNearestPowerOf2(uint32 iV);

/**
return the next power of 2 of a 32 bits dword. 

If the number is already a power of 2, the superior power of 2 will be returned.

@see  vkIsPowerOf2, vkNearestPowerOf2
*/
VKKERNEL_INL uint32 vkNextPowerOf2(uint32 iV);

/**
return the number of set bits in a 32 bits dword. 
Returns Value: number of bit set, 0 if none

@see  vkLeastSignificantBit, vkLog2
*/
VKKERNEL_INL uint32 vkBitCount(uint32 iV);

/**
Returns the floor of the base 2 log of a 32 bits dword. 

Log2(0) is undefined, so the function will return -1.

@see  vkLeastSignificantBit, vkBitCount
*/
VKKERNEL_INL int32 vkLog2(uint32 iV);
VKKERNEL_INL int32 vkLog2(int32 iV);

/**
return the least significant bit of a 32 bits dword. 
Returns Value: the index of the LSB, -1 if no bit is set.

@see  vkBitCount, vkLog2, vkMostSignificantBit
*/
VKKERNEL_INL int32 vkLeastSignificantBit(uint32 iV);

/**
return the most significant bit of a 32 bits dword. 
Returns Value: the index of the LSB, -1 if no bit is set.

@see  vkBitCount, vkLog2, vkLeastSignificantBit
*/
VKKERNEL_INL int32 vkMostSignificantBit(uint32 iV);

/**
returns an integer value representing 
the largest integer that is less than or equal to iF.
{group:Misc Utilities}
*/
VKKERNEL_INL int32 vkFloori(real iF);

/**
returns a realing-point value representing 
the largest integer that is less than or equal to iF.
{group:Misc Utilities}
*/
VKKERNEL_INL real vkFloor(real iF);

/**
returns an value representing 
the largest integer that is less than or equal to iF.
{group:Misc Utilities}
*/
template <typename TReturnType, typename T>
TReturnType vkGetFloor(T iF);

template <>
VK_INLINE int32 vkGetFloor<int32, int32>(int32 iF)
{
	return iF;
}

template <>
VK_INLINE int32 vkGetFloor<int32, real>(real iF)
{
	return vkFloori(iF);
}

template <>
VK_INLINE real vkGetFloor<real, real>(real iF)
{
	return vkFloor(iF);
}

template <>
VK_INLINE real vkGetFloor<real, int32>(int32 iF)
{
	return (real) iF;
}

/**
returns the fractional part of a float, and optionally the
integer part, as a real. 
{group:Misc Utilities}
*/
VK_INLINE real vkFrac(real iF);
VK_INLINE real vkFrac(real iF, real& oIntPart);

/**
returns the fractional part of the passed value 
{group:Misc Utilities}
*/
template <typename TReturnType, typename T>
TReturnType vkGetFrac(T iF);

template <>
VK_INLINE int32 vkGetFrac<int32, int32>(int32 /*iF*/)
{
	return 0;
}

template <>
VK_INLINE int32 vkGetFrac<int32, real>(real /*iF*/)
{
	return 0;
}

template <>
VK_INLINE real vkGetFrac<real, real>(real iF)
{
	return vkFrac(iF);
}

template <>
VK_INLINE real vkGetFrac<real, int32>(int32 /*iF*/)
{
	return (real) 0;
}

/**
return the integer nearest value of the given 
real.
{group:Misc Utilities}
*/
VKKERNEL_INL int32 vkRoundi(real iF);

/**
return the integer nearest value of the 
given real in realing point.
{group:Misc Utilities}
*/
VKKERNEL_INL real vkRound(real iF);

/**
return the integer nearest value of the 
given real.
{group:Misc Utilities}
*/
template <typename TReturnType, typename T>
TReturnType vkGetRound(T iF);

template <>
VK_INLINE int32 vkGetRound<int32, int32>(int32 iF)
{
	return iF;
}

template <>
VK_INLINE int32 vkGetRound<int32, real>(real iF)
{
	return vkRoundi(iF);
}

template <>
VK_INLINE real vkGetRound<real, int32>(int32 iF)
{
	return (real) iF;
}

template <>
VK_INLINE real vkGetRound<real, real>(real iF)
{
	return vkRound(iF);
}

/**
returns an integer value representing the 
smallest integer that is greater than or equal to iF.
{group:Misc Utilities}
*/
VKKERNEL_INL int32 vkCeili(real iF);

/**
returns a realing-point value representing the 
smallest integer that is greater than or equal to iF.
{group:Misc Utilities}
*/
VKKERNEL_INL real vkCeil(real iF);

/**
returns a value representing the 
smallest integer that is greater than or equal to iF.
{group:Misc Utilities}
*/
template <typename TReturnType, typename T>
TReturnType vkGetCeil(T iF);

template <>
VK_INLINE int32 vkGetCeil<int32, int32>(int32 iF)
{
	return iF;
}

template <>
VK_INLINE int32 vkGetCeil<int32, real>(real iF)
{
	return vkCeili(iF);
}

template <>
VK_INLINE real vkGetCeil<real, real>(real iF)
{
	return vkCeil(iF);
}

template <>
VK_INLINE real vkGetCeil<real, int32>(int32 iF)
{
	return (real) iF;
}


/**
Tests if a floats is equal to 0 with
an epsilon threshold.
@param 
iVal1: the float to test.
iEpsilon: the epsilon value.
*/
VKKERNEL_INL bool vkIsNull(const real iVal1, const real iEpsilon = vkConstants::kEpsilon);

/**
Tests if two floats are equal with
an epsilon threshold.
@param 
iVal1, iVal2: the two floats to test.
iEpsilon: the epsilon value.
*/
template <class T>
VK_INLINE bool vkApproxEqual(const T& iVal1, const T& iVal2, const real iEpsilon = vkConstants::kEpsilon)
{
	return (iVal1.Equal(iVal2, iEpsilon));
}

/**
Perform byte swapping on data

The values are modified in situ.

The data are transformed from BigEndian to 
LittleEndian or from LittleEndian to BigEndian.

The functions are specialized (i.e. implemented) 
for (u)int16, uint24, (u)int32, (u)int64, float, 
double.

@param ioValue reference on the value to byte swap
@param ioValues pointer on an array of value to byte swap.
@param iLength number of elements of the array provided.

*/
template <class T>
T vkByteSwap(T& ioValue);

template <class T>
void vkByteSwap(T* ioValues, uint32 iLength);

/**
Perform byte swapping on array of data for
which the word size is unknown at compile time.

The values are modified in situ.

@param ioArray pointer on an array of value to byte swap.
@param iArraySizeInBytes size of the array in bytes.
@param iWordSizeInBytes size of the word to byte swap (can be 2, 3, 4 or 8)

@see vkByteSwap
*/
VKKERNEL_API void  vkByteSwap(void* ioArray, const uint32 iArraySizeInBytes, const uint32 iWordSizeInBytes);

/**
Convert a value expressed in little endian to
the platform specific encoding.

Value directly modified
*/
#if defined(VK_BIG_ENDIAN)

	VK_INLINE bool vkIsPlatformLittleEndian() { return false; }
	VK_INLINE bool vkIsPlatformBigEndian() { return true; }

	template <class T>
	VK_INLINE void vkFromLittleEndian(T* ioValue) { vkByteSwap<T>(*ioValue); }

	template <class T>
	VK_INLINE T vkFromLittleEndian(T iValue)
	{ 
		vkByteSwap<T>(iValue);
		return iValue;
	}

	VK_INLINE void vkFromLittleEndian(void* ioValue, const uint32 iArraySizeInBytes, const uint32 iWordSizeInBytes) { vkByteSwap(ioValue, iArraySizeInBytes, iWordSizeInBytes); }

	template <class T>
	VK_INLINE void vkFromLittleEndian(T* ioValue, const uint32 iLength) { vkByteSwap<T>(ioValue, iLength); }

	//
	template <class T>
	VK_INLINE void vkToLittleEndian(T* ioValue) { vkByteSwap<T>(*ioValue); }

	template <class T>
	VK_INLINE T vkToLittleEndian(T iValue)
	{ 
		vkByteSwap<T>(iValue);
		return iValue;
	}

	VK_INLINE void vkToLittleEndian(void* ioValue, const uint32 iArraySizeInBytes, const uint32 iWordSizeInBytes) { vkByteSwap(ioValue, iArraySizeInBytes, iWordSizeInBytes); }

	template <class T>
	VK_INLINE void vkToLittleEndian(T* ioValue, const uint32 iLength) { vkByteSwap<T>(ioValue, iLength); }

#else

	VK_INLINE bool vkIsPlatformLittleEndian() { return true; }
	VK_INLINE bool vkIsPlatformBigEndian() { return false; }

	template <class T>
	VK_INLINE void vkFromLittleEndian(T* ioValue) {}

	template <class T>
	VK_INLINE T vkFromLittleEndian(T iValue) { return iValue; }

	template <class T>
	VK_INLINE void vkToLittleEndian(T* ioValue) {}

	template <class T>
	VK_INLINE T vkToLittleEndian(T iValue) { return iValue; }

	VK_INLINE void vkFromLittleEndian(void* /*ioValue*/, const uint32 /*iArraySizeInBytes*/, const uint32 /*iWordSizeInBytes*/) { }

	template <class T>
	VK_INLINE void vkFromLittleEndian(T* ioValue, const uint32 iLength) {}

	template <class T>
	VK_INLINE void vkToLittleEndian(T* ioValue, const uint32 iLength) {}

#endif

#if defined(VK_LITTLE_ENDIAN)

	template <class T>
	VK_INLINE void vkFromBigEndian(T* ioValue) { vkByteSwap<T>(*ioValue); }

	template <class T>
	VK_INLINE T vkFromBigEndian(T iValue)
	{ 
		vkByteSwap<T>(iValue);
		return iValue;
	}

	VK_INLINE void vkFromBigEndian(void* ioValue, const uint32 iArraySizeInBytes, const uint32 iWordSizeInBytes) { vkByteSwap(ioValue, iArraySizeInBytes, iWordSizeInBytes); }

	template <class T>
	VK_INLINE void vkFromBigEndian(T* ioValue, const uint32 iLength) { vkByteSwap<T>(ioValue, iLength); }

	//
	template <class T>
	VK_INLINE void vkToBigEndian(T* ioValue) { vkByteSwap<T>(*ioValue); }

	template <class T>
	VK_INLINE T vkToBigEndian(T iValue)
	{ 
		vkByteSwap<T>(iValue);
		return iValue;
	}

	VK_INLINE void vkToBigEndian(void* ioValue, const uint32 iArraySizeInBytes, const uint32 iWordSizeInBytes) { vkByteSwap(ioValue, iArraySizeInBytes, iWordSizeInBytes); }

	template <class T>
	VK_INLINE void vkToBigEndian(T* ioValue, const uint32 iLength) { vkByteSwap<T>(ioValue, iLength); }

#else

	template <class T>
	VK_INLINE void vkFromBigEndian(T* ioValue) {}

	template <class T>
	VK_INLINE T vkFromBigEndian(T iValue) { return iValue; }

	VK_INLINE void vkFromBigEndian(void* ioValue, const uint32 iArraySizeInBytes, const uint32 iWordSizeInBytes) {}

	template <class T>
	VK_INLINE void vkFromBigEndian(T* ioValue, const uint32 iLength) {}

	//
	template <class T>
	VK_INLINE void vkToBigEndian(T* ioValue) {}

	VK_INLINE void vkToBigEndian(void* ioValue, const uint32 iArraySizeInBytes, const uint32 iWordSizeInBytes) {}

	template <class T>
	VK_INLINE void vkToBigEndian(T* ioValue, const uint32 iLength) {}

	template <class T>
	VK_INLINE T vkToBigEndian(T iValue)
	{ 
		return iValue;
	}
#endif

/**
Sets or unsets some bits in a mask.

This method only works on bitfield whose size are <= 32 bits
For 64 bits bitfields, use ChangeMask64 instead

@param iSet set if true, unset otherwise.
@param iBitsField original bit field.
@param iMask bit mask to set or unset.

@return the modified value.
*/
template <typename T>
T vkChangeMask(const bool iSet, T iBitsField, const uint32 iMask);


template <typename T>
T vkChangeMask64(const bool iSet, T iBitsField, const uint64 iMask);

/**
Template structure describing a type, to know 
if it is a POD (plain old data). Useful for containers like vkArray
to perform faster copy and move.
*/
template <typename T> 
struct vkIsPod
{
	enum {result = 0};
};

/**
template structure describing if an integer type is signed.
*/
template <typename T> 
struct vkNumericLimits
{
	enum {
		IsSigned	= 0,
		IsInteger	= 0
	};

	static T Min() throw() {return 0;}
	static T Max() throw() {return 0;}
	static T Epsilon() throw() {return 0;}
};

/**
Gets the remainder of iX / iY.
*/
template <typename T>
T vkGetRemainder(T iX, T iY);

template <>
VK_INLINE int32 vkGetRemainder<int32>(int32 iX, int32 iY)
{
	return iX % iY; 
}

template <>
VK_INLINE float vkGetRemainder<float>(float iX, float iY)
{
	return fmodf(iX, iY); 
}

template <>
VK_INLINE double vkGetRemainder<double>(double iX, double iY)
{
	return fmod(iX, iY); 
}

/**
A simple template, initially described in Alexandrescu (2000).
Generates a distinct type for each distinct constant integral
value passed.
*/
template <uint32 v>
struct vkInt2Type
{
	enum {value = v};
};

VKKERNEL_API void	vkSizeToString(uint64 iSize, vkString& oStr);


enum FTimeStringFlags
{
	fDisplayHours			= 1 << 0,
	fDisplayMinutes			= 1 << 1,
	fDisplaySeconds			= 1 << 2,
	fDisplayMilliSeconds	= 1 << 3,
	f2DigitsMilliSeconds	= 1 << 4,
	f1DigitMilliSeconds		= 1 << 5
};


VKKERNEL_API void	vkTimeToString(float iTime, FTimeStringFlags iFlags, vkString& oStr);


} // end of namespace VKernel

#include "vkTemplatedUtil.hpp"
#include "vkUtil.hpp"


//-->Define Tools for easy flags management START<--
//(and not using several "bool"...) (TVS)
#ifndef VK_DECLARE_FLAGS
#define VK_DECLARE_FLAGS(m_Flags) \
	protected: \
	uint32 m_Flags; \
	public: \
	inline uint32 ModifyFlags(uint32 iAdded,uint32 iRemoved=0) \
	{ \
		m_Flags&=~iRemoved; \
		m_Flags|=iAdded; \
		return m_Flags; \
	} \
	inline uint32 HasFlags(uint32 iFlags) const\
	{ \
		return m_Flags & iFlags; \
	} \
	inline uint32 HasFullFlags(uint32 iFlags) const\
	{ \
		return (m_Flags & iFlags)==iFlags; \
	} \
	inline void SetFlags(uint32 iFlags) \
	{ \
		m_Flags = iFlags; \
	} \
	inline uint32 GetFlags() const\
	{ \
		return m_Flags; \
	} \
	inline void ChangeFlags(uint32 iFlags,bool iValue) \
	{ \
		if (iValue) \
			m_Flags|=iFlags; \
		else \
			m_Flags&=~iFlags; \
	}
#endif//-->Define Tools for easy flags management END<--


#endif // __vkUtil_h



