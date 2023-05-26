#if !defined(__vKernelDefines_h)
#define __vKernelDefines_h

#include "vTeamDefines.h"
#include "vSysDefines.h"

/** 
@file	    vKernelDefines.h
@author		j6h
@brief	  Basic definitions use by the Rendering Engine
*/


/** 
@todo juju -> alignment macros pour toutes les platformes (manquent OSX et iOS)
@todo juju -> size de V_SIMD_ALIGN_SIZE et V_CACH_LINE_SIZE � d�terminer selon hardware (proc)
@todo juju -> macro V_PROC_INTRINSICS_SSE � changer le nom
*/

#if defined(_WINDOWS_SOURCE)
//------------------------------------------------------------------------------
//WINDOWS

/*
===================
Inline
===================
*/
#define V_INLINE inline
#if (_MSC_VER >= 1200)
#define V_FORCEINLINE __forceinline
#else 
#define V_FORCEINLINE V_INLINE 
#endif

#define V_NOINLINE __declspec(noinline)


#ifdef CNEXT_CLIENT

#define V_ASSUME(iExpression) __assume(iExpression)

#define V_ASSUME_ALIGNED(iPointer, iAlignement) __assume((reinterpret_cast<size_t>(iPointer)  % (iAlignement)) == 0)

#else //In debug, we assert if the condition is wrong.

#define V_ASSUME(iExpression) V_ASSERT(iExpression); __assume(iExpression)

#define V_ASSUME_ALIGNED(iPointer, iAlignement) V_ASSERT((reinterpret_cast<size_t>(iPointer)  % (iAlignement)) == 0); __assume((reinterpret_cast<size_t>(iPointer)  % (iAlignement)) == 0)


#endif

#define V_UNUSED(x) x

/*
===================
SIMD
===================
*/
#define _V_PROC_INTRINSICS_SSE
#define _V_PROC_INTRINSICS_AVX
#define _V_PROC_INTRINSICS_AVX2

#if defined(PLATEFORME_DS64)
#define V_ALIGNED_DATA(iDataToBeAligned, iAlignSize) __declspec(align(iAlignSize)) iDataToBeAligned
#define V_ALIGNED_BEGIN(iAlignSize) __declspec(align(iAlignSize))
#define V_ALIGNED_END(iAlignSize)
#else
#define V_ALIGNED_DATA(iDataToBeAligned, iAlignSize)
#define V_ALIGNED_BEGIN(iAlignSize)
#define V_ALIGNED_END(iAlignSize)
#endif

/*
===================
Preprocessor
===================
*/
#define __V_FUNCTION__ __FUNCTION__

#elif (defined _LINUX_SOURCE)

// GCC specific
/*
===================
Inline
===================
*/
#define V_INLINE inline
#define V_FORCEINLINE V_INLINE
#define V_NOINLINE 

#define V_ASSUME(iExpression) 
#define V_ASSUME_ALIGNED(iPointer, iAlignement) 

#define V_UNUSED(x) UNUSED_ ## x __attribute__((__unused__))

/*
===================
SIMD
===================
*/
//#define _V_PROC_INTRINSICS_SSE
//#define _V_PROC_INTRINSICS_AVX
//#define _V_PROC_INTRINSICS_AVX2

#define V_ALIGNED_DATA(iDataToBeAligned, iAlignSize) iDataToBeAligned __attribute__((aligned(iAlignSize)))
#define V_ALIGNED_BEGIN(iAlignSize) 
#define V_ALIGNED_END(iAlignSize) __attribute__((aligned(iAlignSize)))

#define __V_FUNCTION__ __FUNCTION__


#elif (defined _COCOA_SOURCE || defined _DARWIN_SOURCE)
//------------------------------------------------------------------------------
//APPLE

/*
===================
Inline
===================
*/
#define V_INLINE inline
#define V_FORCEINLINE V_INLINE
#define V_NOINLINE 


#define V_ASSUME(iExpression)
#define V_ASSUME_ALIGNED(iPointer, iAlignement)

#define V_UNUSED(x) x
/*
===================
SIMD
===================
*/
#define V_ALIGNED_DATA(iDataToBeAligned, iAlignSize) iDataToBeAligned __attribute__((aligned(iAlignSize)))
#define V_ALIGNED_BEGIN(iAlignSize) 
#define V_ALIGNED_END(iAlignSize) __attribute__((aligned(iAlignSize)))


#else 
//------------------------------------------------------------------------------
//Specific fot Others OS

/*
===================
Inline
===================
*/
#define V_INLINE inline
#define V_FORCEINLINE V_INLINE
#define V_NOINLINE 

#define V_ASSUME(iExpression)
#define V_ASSUME_ALIGNED(iPointer, iAlignement)

#define V_UNUSED(x) x
/*
===================
SIMD
===================
*/
#define V_ALIGNED_DATA(iDataToBeAligned, iAlignSize) iDataToBeAligned
#define V_ALIGNED_BEGIN(iAlignSize) 
#define V_ALIGNED_END(iAlignSize)

#endif

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//For ALL OS

/*
===================
SIMD
===================
*/
#if defined(_V_PROC_INTRINSICS_SSE) && !defined(V_NO_SSE)
#define V_SSE_ENABLED
#endif

#if defined(_V_PROC_INTRINSICS_AVX) && !defined(V_NO_AVX)
#define V_AVX_ENABLED
#endif

#if defined(_V_PROC_INTRINSICS_AVX2) && !defined(V_NO_AVX)
#define V_AVX2_ENABLED
#endif

#define V_SIMD_ALIGN_SIZE 16
#define V_ALIGNED_SIMD_BEGIN	V_ALIGNED_BEGIN(V_SIMD_ALIGN_SIZE)
#define V_ALIGNED_SIMD_END		V_ALIGNED_END(V_SIMD_ALIGN_SIZE)
#define V_ALIGNED_SIMD_DATA(iDataToBeAligned) V_ALIGNED_DATA(iDataToBeAligned, V_SIMD_ALIGN_SIZE)

/*
===================
Concatenations
===================
*/

#define _V_CONCAT_PREP(x1,x2) x1 ## x2

/** 
Concatenation
@def V_CONCAT_PREP(x1,x2)
@code
V_CONCAT_PREP("the", " water")
@endcode
*/
#define V_CONCAT_PREP(x1,x2) _V_CONCAT_PREP(x1,x2)

/*
===================
Quotes
===================
*/
#define _V_QUOTE(x) # x

/**
@def V_QUOTE(x)
@brief Display the value of a define.
@code
  printf("The definition is : V_QUOTE(V_DEFINITION) "\n");
@endcode
*/
#define V_QUOTE(x) _V_QUOTE(x)

#define __V_FILE__LINE__ __FILE__ "(" V_QUOTE(__LINE__) ")"

/*
===================
Pragma messages
===================
*/

/**
Display a todo in the output of your compiler.
@def V_Todo(x)
@code
#pragma V_Todo("Message")
@endcode
*/
#define V_Todo(x)  message( __V_FILE__LINE__  ": TODO " #x "\n")

/** 
Display a todo in the output of your compiler.
@def V_TODO(x)
@code
  #pragma V_TODO("Message")
@endcode
*/
#define V_TODO(x)  message( __V_FILE__LINE__ "\n" \
  " ------------------------------------------------\n" \
  "|  TODO :  " #x "\n" \
  " -------------------------------------------------\n" )

/**
Display a tofix in the output of your compiler.
@def V_Tofix(x)
@code
#pragma V_Tofix("Message")
@endcode
*/
#define V_Tofix(x) message( __V_FILE__LINE__  ": TOFIX " #x "\n")

/**
Display a tofix in the output of your compiler.
@def V_TOFIX(x)
@code
#pragma V_TOFIX("Message")
@endcode
*/
#define V_TOFIX(x) message( __V_FILE__LINE__ "\n" \
  " ------------------------------------------------\n" \
  "|  TOFIX :  " #x "\n" \
  " -------------------------------------------------\n" )


#define V_Note(x) message( __V_FILE__LINE__  ": NOTE : " #x "\n")


#define V_NOTE(x) message( __V_FILE__LINE__ "\n" \
  " ------------------------------------------------\n" \
  "|  NOTE :  " #x "\n" \
  " -------------------------------------------------\n" )

/*
===================
Others
===================
*/
#if  !defined(NULL)
#define NULL 0
#endif

/*
===================
Asserts
===================
*/

//No asserts are used.
#if (defined(CNEXT_CLIENT) && !defined(V_FORCE_ASSERT)) || defined(V_DOXYGEN)
#define V_ASSERT_DISABLED

//Asserts from UIVCoreTools are used.
#elif !defined(CNEXT_CLIENT) && !defined(V_TEST_KERNEL)
#define V_ASSERT_ENABLED
#define _V_USE_ASSERT_UIVCORETOOLS

//We absolutely want to use assertions. But when CNEXT_CLIENT is defined,
//the asserts from CNEXT_CLIENT are not available.
//Only available for windows
#elif defined(CNEXT_CLIENT) && defined(V_FORCE_ASSERT) && defined(_WINDOWS_SOURCE)
#define V_ASSERT_ENABLED
#define _V_USE_ASSERT_OS

//Useful for several tests.
//temp
#elif defined(V_TEST_KERNEL) && defined(V_FORCE_ASSERT) && defined(_WINDOWS_SOURCE)
#define V_ASSERT_ENABLED
#define _V_USE_ASSERT_OS

#else
#define V_ASSERT_DISABLED
#endif

/*
===================
Non supported definitions
===================
*/
#if !defined(__V_FUNCTION__)
#define __V_FUNCTION__ ""
#endif

//mandatory with clang (it does not allowed the extra "template<>" token). To be verified on iOS and Windows if "template<>" token is necessary



#if defined _DARWIN_SOURCE && !defined _COCOA_SOURCE
#define V_MACOS_A_SOURCE
#endif

#if defined _COCOA_SOURCE && !defined _IOS_SOURCE
#define V_MACOS_B_SOURCE
#endif

#if defined _WINDOWS_SOURCE  || defined V_MACOS_A_SOURCE || defined _MOBILE_SOURCE || defined V_MACOS_B_SOURCE || defined _LINUX_SOURCE
#define V_TEMPLATE template<>
#else 
#define V_TEMPLATE
#endif

#define V_CAST_PTR_TO_UINT32(x) (*((uint32*)(&(x))))


//------------------------------------------------------------------------------
//Reminder

#if !defined(V_DOXYGEN)

/*
===================
defines OS
===================
*/

/** Already exist.
 * Windows						: _WINDOWS_SOURCE
 * Apple (MacOSX or/and IOS)	: _COCOA_SOURCE 
 * Apple_macos X11				: _DARWIN_SOURCE
 * Apple iOS					: _IOS_SOURCE
*/

/*
===================
Compiler
===================
*/

/** Already exist. 
 *	Defines by mkmk depending on OS	
 */

/*
===================
Endian
===================
*/
/** Already exist.
 *	_ENDIAN_LITTLE or _ENDIAN_BIG 	
 */

#endif //!V_DOXYGEN

#define V_FIX_VARRAY 0

constexpr unsigned int k_FixedTaskPoolSz = 1;
#define V_FIXED_TASK_POOL_SZ_DEFINED


#if !defined V_ADVANCED_DEBUG && !defined CNEXT_CLIENT
#define V_ADVANCED_DEBUG
#endif

#endif // end : __vKernelDefines_h
