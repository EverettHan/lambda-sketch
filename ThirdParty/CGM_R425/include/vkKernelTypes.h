/**
@file

This file defines base type (integer, real, ....).

@COPYRIGHT

@author Nicolas Hognon
*/

#if !defined(__vkKernelTypes_h)
#define __vkKernelTypes_h

#if !defined(__vkKernelDefines_h)
	#include "vkKernelDefines.h"
#endif

#if defined(VK_COMPILER_GCC)
	#include <limits>
	#include <float.h>
	#include <sys/types.h>
#endif

// for ptrdiff_t
#include "stddef.h"

namespace VKernel
{

////////////////////////////////////////
// Definitions of basic types

#if defined(VK_COMPILER_MSVC)
	/**
	8-bit signed integer.

	Using this type you are sure of having a 8-bit signed integer. 
	The implementation depends on the compiler.target. The one seen in the documentation
	is for Microsoft Visual Studio (VK_COMPILER_MSVC).

	@see int16, int32, int64, uint8, uint16, uint32, uint64, bool32, char8, char16, char32

	
	*/
	typedef	signed __int8		int8;

	/**
	16-bit signed integer.

	Using this type you are sure of having a 16-bit signed integer. 
	The implementation depends on the compiler.target. The one seen in the documentation
	is for Microsoft Visual Studio (VK_COMPILER_MSVC).

	@see int8, int32, int64, uint8, uint16, uint32, uint64, bool32, char8, char16, char32

	
	*/
	typedef	signed __int16		int16;	// 16-bit signed integer.
	
	/**
	32-bit signed integer.

	Using this type you are sure of having a 32-bit signed integer. 
	The implementation depends on the compiler.target. The one seen in the documentation
	is for Microsoft Visual Studio (VK_COMPILER_MSVC).

	@see int8, int16, int64, uint8, uint16, uint32, uint64, bool32, char8, char16, char32

	
	*/
	typedef	signed __int32		int32;	// 32-bit signed integer.

	/**
	64-bit signed integer.

	Using this type you are sure of having a 64-bit signed integer. 
	The implementation depends on the compiler.target. The one seen in the documentation
	is for Microsoft Visual Studio (VK_COMPILER_MSVC). This type is
	defined as a structure on some target, see Integer64.

	@see int8, int16, int32, uint8, uint16, uint32, uint64, bool32, char8, char16, char32, Integer64

	
	*/
	typedef	signed __int64		int64;	// 64-bit signed integer (defined as a struct on some platform, see Integer64).

	/**
	8-bit unsigned integer.

	Using this type you are sure of having a 8-bit unsigned integer. 
	The implementation depends on the compiler.target. The one seen in the documentation
	is for Microsoft Visual Studio (VK_COMPILER_MSVC).

	@see int8, int16, int32, int64, uint16, uint32, uint64, bool32, char8, char16, char32

	
	*/
	typedef	unsigned __int8		uint8;	// 8-bit unsigned integer.

	/**
	16-bit unsigned integer.

	Using this type you are sure of having a 16-bit unsigned integer. 
	The implementation depends on the compiler.target. The one seen in the documentation
	is for Microsoft Visual Studio (VK_COMPILER_MSVC).

	@see int8, int16, int32, int64, uint8, uint32, uint64, bool32, char8, char16, char32

	
	*/
	typedef	unsigned __int16	uint16;	// 16-bit unsigned integer.

	/**
	32-bit unsigned integer.

	Using this type you are sure of having a 32-bit unsigned integer. 
	The implementation depends on the compiler.target. The one seen in the documentation
	is for Microsoft Visual Studio (VK_COMPILER_MSVC).

	@see int8, int16, int32, int64, uint8, uint16, uint64, bool32, char8, char16, char32

	
	*/
	typedef	unsigned __int32	uint32;	// 32-bit unsigned integer.

	/**
	64-bit unsigned integer.

	Using this type you are sure of having a 64-bit unsigned integer. 
	The implementation depends on the compiler.target. The one seen in the documentation
	is for Microsoft Visual Studio (VK_COMPILER_MSVC). This type is
	defined as a structure on some target, see UInteger64.

	@see int8, int16, int32, int64, uint8, uint16, uint32, bool32, char8, char16, char32, UInteger64

	
	*/
	typedef	unsigned __int64	uint64;	// 64-bit unsigned integer (defined as a struct on some platform, see UInteger64).

	/**
	Boolean as a 32-bit unsigned integer (same as uint32)

	@see int8, int16, int32, int64, uint8, uint16, uint64, char8, char16, char32

	
	*/
	typedef	unsigned __int32	bool32;	// boolean as a 32-bit unsigned integer (same as uint32).

	/**
	8-bit character used for ASCII or UTF8.

	@see int8, int16, int32, int64, uint8, uint16, uint64, bool32, char16, char32

	
	*/
	typedef char				char8;	// 8-bit character used for ASCII or UTF8.

	/**
	16-bit character used for UTF16.

	@see int8, int16, int32, int64, uint8, uint16, uint64, bool32, char8, char32

	
	*/
	typedef unsigned __int16	char16; // 16-bit character used for UTF16.

	/**
	32-bit character used for UTF32.

	@see int8, int16, int32, int64, uint8, uint16, uint64, bool32, char8, char16

	
	*/
	typedef unsigned __int32	char32; // 32-bit character used for UTF32.

#elif defined(VK_COMPILER_GCC)
	typedef	int8_t				int8;	// 8-bit signed integer.
	typedef	int16_t				int16;	// 16-bit signed integer.
	typedef	int32_t				int32;	// 32-bit signed integer.
	typedef	int64_t				int64;	// 64-bit signed integer (defined as a struct on some platform, see Integer64).
	typedef	u_int8_t			uint8;	// 8-bit unsigned integer.
	typedef	u_int16_t			uint16;	// 16-bit unsigned integer.
	typedef	u_int32_t			uint32;	// 32-bit unsigned integer.
	typedef	u_int64_t			uint64;	// 64-bit unsigned integer (defined as a struct on some platform, see UInteger64).
	typedef	u_int32_t			bool32;	// boolean as a 32-bit unsigned integer (same as uint32).
	typedef char				char8;	// 8-bit character used for ASCII or UTF8.
	typedef u_int16_t			char16;	// 16-bit character used for UTF16.
	typedef u_int32_t			char32;	// 32-bit character used for UTF32.
#else
	#error "Unrecognized compiler."
#endif

#if defined(VK_GCC_XML) || defined(VK_COMPILER_GCC) || defined(VK_COMPILER_CODEWARRIOR)
	#define VK_CONST_INT32(x) x##L
	#define VK_CONST_UINT32(x) x##UL
	#define VK_CONST_INT64(x) x##LL
	#define VK_CONST_UINT64(x) x##ULL
#elif defined(VK_COMPILER_MSVC)
	#define VK_CONST_INT32(x) x##i32
	#define VK_CONST_UINT32(x) x##ui32
	#define VK_CONST_INT64(x) x##i64
	#define VK_CONST_UINT64(x) x##ui64
#else
	#error unknown compiler
#endif

/**
Abstract handle to a window.
*/
typedef void* vkWindowHandle;

/**
Result of subtraction of two pointers.

It is a signed integer which size depends on the platform.
It is an alias for ptrdiff_t (which is a C++ standard type).


*/
typedef ptrdiff_t ptrdiff;

#if defined(VK_TARGET_WINDOWS) || defined(VK_TARGET_WINCE)
	typedef uint32 errorsys;
#elif defined(VK_TARGET_LINUX) || defined(VK_TARGET_MACOSX) || defined(VK_TARGET_IPHONE) || defined(VK_TARGET_ANDROID)
	typedef int errorsys;
#else
	#error not yet implemented!
#endif

#if !defined(VK_CONST_INT64)
	#error VK_CONST_INT64 not defined.
#endif

#if !defined(VK_CONST_UINT64)
	#error VK_CONST_UINT64 not defined.
#endif

/**
64-bit signed integer defined as a structure.

64-bit signed integer defined as a structure on platform which does support
64-bit natively.

The implementation depends on the byte ordering of the target (VK_LITTLE_ENDIAN or
VK_BIG_ENDIAN).

@see UInteger64, VK_64BIT_NOTSUPPORTED


*/
struct Integer64
{
#if defined(VK_LITTLE_ENDIAN)
	/** Low-order 32-bits (unsigned). */
	uint32	lo;
	/** High-order 32-bits (signed). */
	int32	hi;
#else
	/** High-order 32-bits (signed). */
	int32	hi;
	/** Low-order 32-bits (unsigned). */
	uint32	lo;
#endif

	/**
	Create uninitialize 64-bit integer.
	*/
	Integer64();
	
	/**
	Initialize the 64-bit integer using two 32-bit value.
	*/
	Integer64(int32 iH, uint32 iL);

	/**
	Convert the structure to the int64 type.
	*/
	operator int64();
};

/**
64-bit unsigned integer defined as a structure.

64-bit unsigned integer defined as a structure on platform which does support
64-bit natively.

@see Integer64, VK_64BIT_NOTSUPPORTED


*/
struct UInteger64
{
#if defined(VK_BIG_ENDIAN)
	/** High-order 32-bits (unsigned). */
	uint32	hi;
	/** Low-order 32-bits (unsigned). */
	uint32	lo;
#else
	/** Low-order 32-bits (unsigned). */
	uint32	lo;
	/** High-order 32-bits (unsigned). */
	uint32	hi;
#endif

	/**
	Create uninitialize 64-bit unsigned integer.
	*/
	UInteger64();

	/**
	Initialize the 64-bit usigned integer using two 32-bit usigned value.
	*/
	UInteger64(uint32 iH, uint32 iL);
	
	/**
	Convert the structure to the uint64 type.
	*/
	operator uint64();
};

#if defined(VK_64BIT_NOTSUPPORTED) && !defined(VK_DOXYGEN)
	#pragma NOTE("int64/uint64 are defined as struct!")
	typedef	Integer64	int64;	// 64-bit signed integer (defined as a struct on some platform, see Integer64).
	typedef	UInteger64	uint64;	// 64-bit unsigned integer (defined as a struct on some platform, see UInteger64).
#endif

/**
24-bit unsigned integer defined as a structure.

The implementation depends on the byte ordering of the target (VK_LITTLE_ENDIAN or
VK_BIG_ENDIAN).

@see Integer24


*/
struct UInteger24
{
#if defined(VK_LITTLE_ENDIAN)
	/** Low-order 8-bits (unsigned). */
	uint8 lo;
	/** Mid-order 8-bits (unsigned). */
	uint8 mid;
	/** High-order 8-bits (unsigned). */
	uint8 hi;
#else
	/** High-order 8-bits (unsigned). */
	uint8 hi;
	/** Mid-order 8-bits (unsigned). */
	uint8 mid;
	/** Low-order 8-bits (unsigned). */
	uint8 lo;
#endif

	/** Initialize the integer to 0. */
	UInteger24();

	/** Initialize the integer using a 32-bit unsigned value. */
	UInteger24(const uint32 iValue);

	/** Convert a 24-bit unsigned integer to a 32-bit unsigned integer. */
	operator uint32();

};

/**
24-bit unsigned integer (defined as a struct, see UInteger24).


*/
typedef	UInteger24	uint24;

// Now defines macros to perform clean (warning free)
// conversion between types
#if !defined(VK_DOXYGEN)
	/*
	Convert a pointer to a unsigned integer.
	*/
	#ifdef VK_32BIT
	#define VK_POINTER_TO_PTRDIFF(p) ((uint32)((ptrdiff) (void*)(p)))
		#define VK_HASH_32(a) (a)
	#else
		#define VK_POINTER_TO_PTRDIFF(p) ((ptrdiff) (void*)(p))
		#define VK_HASH_32(a) ((uint32)(((a)>>32)^(a)))
	#endif

#else	
	#define VK_POINTER_TO_PTRDIFF(p)
	#define VK_HASH_32(a) 
#endif



#if defined(VK_REAL_DOUBLE_PRECISION)

	/**
	Defines in the current precision.
	default is float but it can be fixed to double
	if VK_REAL_DOUBLE_PRECISION is defined.

	
	*/
	typedef double real;
#else
	typedef float real;
#endif


#if defined(VK_USE_ERROR_CLASS) && !defined(VK_DOXYGEN)

/**
Simple wrapper around error code.
Used to track wrong implicit cast from bool to error and first of all,
to make vkErrorInfo system work.
*/
class error
{
public:
#if !defined(VK_DOXYGEN)

	VK_INLINE error() {}
	VK_INLINE error(int32 iCode) : code(iCode) {}
	VK_INLINE error& operator=(int32 iCode)
	{
		code = iCode;
		return *this;
	}

	VK_INLINE error& operator=(error iError)
	{
		code = iError.code;
		return *this;
	}

	VK_INLINE bool IsError() const
	{
		return code != 0;
	}

	VK_INLINE int32 GetCode() const
	{
		return (code > 0) ? (code | kNakedErrorFlag) : code;
	}

	VK_INLINE bool operator==(error iCode) const
	{
		return ((code ^ iCode.code) & ~kNakedErrorFlag) == 0;
	}

	VK_INLINE bool operator!=(error iCode) const
	{
		return ((code ^ iCode.code) & ~kNakedErrorFlag) != 0;
	}

	VK_INLINE bool operator==(int32 iCode) const
	{
		// Conditional should be removed in release
		// when passing a compile time error code here.
		if (iCode == 0)
		{
			return code == 0;
		}
		else
		{
			return ((code ^ iCode) & ~kNakedErrorFlag) == 0;
		}
	}

	VK_INLINE bool operator!=(int32 iCode) const
	{
		// Conditional should be removed in release
		// when passing a compile time error code here.
		if (iCode == 0)
		{
			return code != 0;
		}
		else
		{
			return ((code ^ iCode) & ~kNakedErrorFlag) != 0;
		}
	}

	VK_INLINE void LinkToLastErrorInfo()
	{
		code &= ~kNakedErrorFlag;
	}

	VK_INLINE bool IsLinkedToLastErrorInfo() const
	{
		return code > 0;
	}

private:
	// Not allowed
	VK_INLINE error(bool /*iCondition*/) {}
	VK_INLINE error& operator=(bool /*iCondition*/) {return *this;}
	friend bool operator==(int32 iCode, error iError);
	friend bool operator!=(int32 iCode, error iError);

	/**
	This bit is reserved for indicating that last error info corresponds to
	this error. If set, then the error is "naked", ie there's no corresponding error info.
	Otherwise, (bit reset), the error has an error info that can be retrieved by
	vkErrorManager::GetLastErrorInfo()
	The consequence is : an error associated to an error info is positive.
	*/
	enum { kNakedErrorFlag = 1 << 31 };

	int32	code;
#endif // VK_DOXYGEN
};

VK_INLINE bool operator==(int32 iCode, error iError)
{
	// Conditional should be removed in release
	// when passing a compile time error code here.
	if (iCode == 0)
	{
		return iError.code == 0;
	}
	else
	{
		return ((iError.code ^ iCode) & ~error::kNakedErrorFlag) == 0;
	}
}

VK_INLINE bool operator!=(int32 iCode, error iError)
{
	// Conditional should be removed in release
	// when passing a compile time error code here.
	if (iCode == 0)
	{
		return iError.code != 0;
	}
	else
	{
		return ((iError.code ^ iCode) & ~error::kNakedErrorFlag) != 0;
	}
}

VK_INLINE int32 vkGetErrorCode(error iError)
{
	return iError.GetCode();
}

#else

/**
Type which defines an error value.

The error type is a signed integer value (32-bit). Values defined
by the @SDK_NAME are < 0, values defined by users must be > 0.

At this time, in debug mode (VK_DEBUG), the error type is in fact wrapped by a class,
so its impossible to convert a boolean value to an error. In this case error
automatically convert to int32.

@see EBaseError, vkErrorManager

@ingroup grp_error
*/
typedef int32 error;

/**
Convert an error into a 32-bit signed integer (int32).

This function exist because of the debug implementation of the error type.
Even if errors can be automatically converted to int32, sometimes it is no
enough. This function is here to resolve this problem.

@param iError the error

@return The error as a int32.

@code
	error err = Function();

	switch (vkGetErrorCode(err))
	{
		case errOk:	
			break;

		case errFailed:
		case errCancelled:
		case errTimeout:
			break;

		default:
			VKUNSUPPORTED();
			break;
	}
@endcode


*/
VK_INLINE int32 vkGetErrorCode(error iError)
{
	return (int32) iError;
}

#endif

/**
Defines a generic handle to a context.
-1 means invalid.
@see vkContext
*/
typedef const uint32 vkCtx;

/**
Defines a generic handle to a context
when stored in an volatile variable.
@see vkContext
*/
typedef uint32 vkCtxVariable;

enum
{
	kInvalidCtx	= -1,
	kMainCtx	= 0
};

////////////////////////////////////////
// Allocator functions pointers

/**
Allocation Function pointer.

@see vkKernelModule::SetAllocatorFunctions


*/
typedef void*	(*vkAllocateFct)(size_t iByteSize);

/**
Deallocation Function pointer.

@see vkKernelModule::SetAllocatorFunctions


*/
typedef void	(*vkDeallocateFct)(void* iPointer);

/**
TellSize Function pointer.

@see vkKernelModule::SetAllocatorFunctions


*/
typedef uint32	(*vkTellSizeFct)(void* iPointer);

void StoreDwordToUnalignedMemory(int32 iSrc, void* oDst);
int32 LoadDwordFromUnalignedMemory(void* iSrc);
void StoreQwordToUnalignedMemory(int64 iSrc, void* oDst);
int64 LoadQwordFromUnalignedMemory(void* iSrc);
void StoreFloatToUnalignedMemory(float iSrc, void* oDst);
float LoadFloatFromUnalignedMemory(void* iSrc);

} // VKernel

#include "vkKernelTypes.hpp"

#endif // __vkKernelTypes_h


