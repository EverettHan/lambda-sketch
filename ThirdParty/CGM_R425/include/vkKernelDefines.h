/**
* quickreview FDN 22:04:25 R424AssessedForLinux (ExportedBy managed by itself)
*/

/**
@file

This file introduce some DEFINE useful for all
other modules.

@COPYRIGHT

@author Nicolas Hognon
*/

#if !defined(__vkKernelDefines_h)
#define __vkKernelDefines_h

#if !defined(__cplusplus)
	#error "C++ compiler required."
#endif


#if !defined(VK_SDK_VERSION)
	#if !defined(VK_DOXYGEN)
		#define VK_SDK_VERSION	102
		#define VK_SDK_NAME		"Virtools MP SDK"
		#define VK_SDK_WNAME	L"Virtools MP SDK"
	#else
		/** Define representing the @SDK_NAME Version (something like a.b, where a and b are numbers). */
		#define VK_SDK_VERSION
		/** Define representing the @SDK_NAME name as a static constant character string. */
		//@{
		#define VK_SDK_NAME
		#define VK_SDK_WNAME
		//@}
	#endif
#endif


////////////////////////////////////////////////////////////////////////////////
// check supported  compilers and set the VK_COMPILER_XXX define
////////////////////////////////////////////////////////////////////////////////
#if (!(defined(VK_COMPILER_MSVC) || defined(VK_COMPILER_CODEWARRIOR) || defined(VK_COMPILER_GCC))) && !defined(VK_DOXYGEN)

	// Microsoft Visual C++
	#if defined(_MSC_VER)
		#define VK_COMPILER_MSVC _MSC_VER

		#if VK_COMPILER_MSVC < 1310
			#error "Invalid version of MSVC compiler (<1310)"
		#endif

		#if VK_COMPILER_MSVC >= 1400 // .Net 2005 and higher
			#define VK_RESTRICT __restrict
			#ifndef _CRT_SECURE_NO_WARNINGS
				#define _CRT_SECURE_NO_WARNINGS
			#endif
		#endif

	// MetroWerks CodeWarrior
	#elif defined(__MWERKS__)
		#define VK_COMPILER_CODEWARRIOR __MWERKS__

	// GNU GCC
	#elif defined(__GNUC__)
		#define VK_COMPILER_GCC __GNUC__
		#define VK_RESTRICT __restrict__

	// error
	#else
		#error "Unrecognized compiler."
	#endif
#endif

#ifndef VK_RESTRICT
	#define VK_RESTRICT
#endif

#if defined(VK_DOXYGEN)
	/**
	This define is on if the current compiler is Microsoft Visual C++ (MSVC).

	Its value is the version of the compiler. The minimal version supported
	is Microsoft Visual C++ .NET 2003 (a.k.a 7.1), which correspond the version 1310.
	*/
	#define VK_COMPILER_MSVC

	/**
	This define is on if the current compiler is Metrowrks Codewarrior (Codewarrior).

	Its value is the version of the compiler.
	*/
	#define VK_COMPILER_CODEWARRIOR

	/**
	This define is on if the current compiler is Gnu C compiler (GCC).

	Its value is the version of the compiler. GCC also defined (depending on
	its version) other value: __GNUC_MINOR__ and __GNUC_PATCHLEVEL__.
	*/
	#define VK_COMPILER_GCC
#endif


////////////////////////////////////////////////////////////////////////////////
// check for supported target and set the VK_TARGET_XXX define and the VK_TARGET define
////////////////////////////////////////////////////////////////////////////////

#if defined(VK_DOXYGEN)
	/**
	This define value if the current target as a string.

	This define is the value of the current target as a string. Values can be:
		- "VK_TARGET_LINUX"
		- "VK_TARGET_ANDROID"
		- "VK_TARGET_MACOSX"
		- "VK_TARGET_UNKNOWN"
		- "VK_TARGET_WINDOWS"
		- "VK_TARGET_WINCE"
	*/
	#define VK_TARGET
#endif

#if !(defined(VK_TARGET_WINDOWS) || defined(VK_TARGET_MACOSX) || defined(VK_TARGET_IPHONE)||defined(VK_TARGET_LINUX) || defined(VK_TARGET_ANDROID) || defined(VK_TARGET_WINCE))  \
   && !defined(VK_DOXYGEN)

	// Microsoft Visual C++
	#if defined(VK_COMPILER_MSVC)
		// with MSVC we only support WIN32 target (winpc)
		#if defined(_WIN32_WCE)
			#define VK_TARGET_WINCE
			#define VK_TARGET "VK_TARGET_WINCE"
		#elif defined(_WIN64)
			#define VK_TARGET_WINDOWS
			#define VK_TARGET_WINDOWS64
			#define VK_TARGET "VK_TARGET_WINDOWS64"
			#define VK_64BIT
			#if !defined(_DLL)
				#error "Multithreaded DLL is required."
			#endif
		#elif defined(_WIN32)
			#define VK_TARGET_WINDOWS
			#define VK_TARGET "VK_TARGET_WINDOWS"
			#if !defined(_DLL)
				#error "Multithreaded DLL is required."
			#endif

		#else
			#error "Unrecognized target for microsoft compiler."
		#endif

	// MetroWerks CodeWarrior
	#elif defined(VK_COMPILER_CODEWARRIOR)

		// PowerPC Macintosh
		#if defined(TARGET_API_MAC_OSX)
			#error "Metrowerks CodeWarrior not supported anymore on MP for MacOS X. Use Xcode instead."
		// error
		#else
			#error "Unrecognized target for metrowerks compiler."
		#endif

	// GNU GCC
	#elif defined(VK_COMPILER_GCC)
		//android with gcc
		#if defined(__ANDROID__) || defined(ANDROID) 
			#define VK_TARGET_ANDROID
			#define VK_TARGET "VK_TARGET_ANDROID"

		// Linux with gcc
		#elif defined(linux) || defined(__linux) || defined(__linux__) || defined(__gnu_linux__)
			#define VK_TARGET_LINUX
			#define VK_TARGET "VK_TARGET_LINUX"

		// mac os x on iphone with gcc (device only)
		#elif (defined(__APPLE__) && defined(__arm__)) || (defined(__APPLE__) && defined(VK_IPHONE_SIMULATOR))
			#define VK_TARGET_IPHONE
			#define VK_TARGET "VK_TARGET_IPHONE"
		// mac os x with gcc
		#elif defined(__APPLE__)
			#define VK_TARGET_MACOSX
			#define VK_TARGET "VK_TARGET_MACOSX"
/*
			#if defined(__x86_64__) || defined(__ppc64__)
				#define VK_64BIT
			#else
				#define VK_32BIT
			#endif
			#if !defined(__CARBON__)
			#include <Carbon/Carbon.h>
			#endif
			#if !defined(__AVAILABILITYMACROS__)
			#include "AvailabilityMacros.h"
			#endif
			// Availability.h for targeting iOS or Mac OS X 10.6 or later
			// if not, used the older AvailabilityMacros.h, but Carbon/Carbon.h must be included before. 
			#if defined(__MAC_OS_X_VERSION_MAX_ALLOWED)
				#if __MAC_OS_X_VERSION_MAX_ALLOWED >= 1060
					#define VK_TARGET_MACOSX_SDK_10_6
				#elif __MAC_OS_X_VERSION_MAX_ALLOWED >= 1050
					#define VK_TARGET_MACOSX_SDK_10_5
				#else
					// The SDK used is 10.6 with weak links for 10.5 deployment
					#error "Mac OS X 10.4 or older versions are not targeted"
				#endif
			#else
			// __MAC_OS_X_VERSION_MAX_ALLOWED is not defined on iOS:
			// iOS use SDKROOT and MACOSX_DEPLOYMENT_TARGET
				#error "__MAC_OS_X_VERSION_MAX_ALLOWED is not defined"
			#endif
*/
            #include <CoreServices/CoreServices.h>

		#else
			#error "Unrecognized target for gnu gcc compiler."
		#endif

	// error
	#else
		#error "Unrecognized target."
	#endif

#endif

#if defined(VK_DOXYGEN)

	/**
	This define is on if the current target is a Microsoft Windows (i.e.\ Win32).

	Windows is only available under MSVC on X86 processor.
	*/
	#define VK_TARGET_WINDOWS

	/**
	This define is on if the current target is Linux.

	Linux is only available under GCC on X86 processor.
	*/
	#define VK_TARGET_LINUX

	/**
	This define is on if the current target is Apple Mac OS X (MACOSX).

	Mac OS X is only available under GCC (Xcode) on G3/G4 Processor.
	*/
	#define VK_TARGET_MACOSX

	/**
	This define is on if the current target is Apple iOS (iPhone or iPad).

	iOS is only available under GCC (Xcode) on ARM Processor.
	*/
	#define VK_TARGET_IPHONE

	/**
	This define is on if the current target is Windows Mobile.

	Windows Mobile is only available under MSVC on ARMV4 / SH4 Processor.
	*/
	#define VK_TARGET_WINCE

#endif

#if !defined(VK_TARGET)
	#define VK_TARGET "VK_TARGET_UNKNOWN"
#endif

////////////////////////////////////////////////////////////////////////////////
// check for supported processor and set the VK_PROC_XXX define
////////////////////////////////////////////////////////////////////////////////
#if !(defined(VK_PROC_X86) || defined(VK_PROC_MIPS) || defined(VK_PROC_PPC) || defined(VK_PROC_XENON) || defined(VK_PROC_ARM) || defined(VK_PROC_SH)) && !defined(VK_DOXYGEN)

	// Microsoft Visual C++
	#if defined(VK_COMPILER_MSVC) 
		// with MSVC we only support x86
		#if defined(_M_IX86)
			#define VK_PROC_X86
			#define VK_PROC_X86_SSE
			#define VK_PROC_INTRINSICS_SSE // SSE via the use of intrinsics
			#define VK_PROC "VK_PROC_X86"
		#elif defined(_M_X64)
			#define VK_PROC_X64
			#define VK_PROC_INTRINSICS_SSE // SSE via the use of intrinsics
			#define VK_PROC "VK_PROC_X64"
		#elif (_XBOX_VER>=200)
			#define VK_PROC_XENON
			#define VK_PROC "VK_PROC_XENON"
		#elif defined(_ARM_) || defined(ARM)
			#define VK_PROC_ARM
			#define VK_PROC "VK_PROC_ARM"
		#elif defined(SH4) || defined(_SHX_)
			#define VK_PROC_SH
			#define VK_PROC "VK_PROC_SH"
		#else
			#error "Unrecognized processor for microsoft compiler."
		#endif

		#define VK_ALIGNED_DATA(DataToBeAligned, AlignSize) __declspec(align(AlignSize)) DataToBeAligned

		#define VK_ALIGNED_BEGIN(AlignSize) __declspec(align(AlignSize)) 
		#define VK_ALIGNED_END(AlignSize)  


	// MetroWerks CodeWarrior
	#elif defined(VK_COMPILER_CODEWARRIOR)
		// Play Station 2
		#if defined(__MIPS_PSX2__)
			#define VK_PROC_MIPS
			#define VK_PROC "VK_PROC_MIPS"
		// Wii
		#elif defined(__PPCGEKKO__)
			#define VK_PROC_WII
			#define VK_PROC "VK_PROC_WII"
		// PowerPC Macintosh
		#elif defined(__POWERPC__)
			#define VK_PROC_PPC
			#define VK_PROC "VK_PROC_PPC"
		// error
		#else
			#error "Unrecognized processor for metroWerks codewarrior."
		#endif

		#define VK_ALIGNED_DATA(DataToBeAligned, AlignSize) __declspec(align(AlignSize)) DataToBeAligned

		#define VK_ALIGNED_BEGIN(AlignSize) __declspec(align(AlignSize)) 
		#define VK_ALIGNED_END(AlignSize)  

	// GNU GCC
	#elif defined(VK_COMPILER_GCC) 

		// Playstation 3
		#if defined(__PPU__)
			#define VK_PROC_PPU
			#define VK_PROC "VK_PROC_PPU"
			#include <ppu_intrinsics.h>
		#elif defined(__SPU__)
			#define VK_PROC_SPU
			#define VK_PROC "VK_PROC_SPU"
			#include <spu_internals.h>

		// with GCC we only support Linux x86

		// i386
		#elif defined(i386) || defined(__i386) || defined(__i386__)
			#define VK_PROC_X86
			#if !defined(VK_TARGET_IPHONE)
				#define VK_PROC_X86_SSE
				#define VK_PROC_INTRINSICS_SSE // SSE via the use of intrinsics
			#endif
			#define VK_PROC "VK_PROC_X86"
        #elif defined(__amd64) || defined(__amd64__) || defined(__x86_64) || defined(__x86_64__) ||  defined(PLATEFORME_DS64)
			#define VK_PROC_AMD64
			#define VK_64BIT
            // #define VK_PROC_INTRINSICS_SSE // SSE via the use of intrinsics
            #define VK_PROC "VK_PROC_AMD64"
		#elif (defined(__POWERPC__) || defined(_ARCH_PPC) || defined(__ppc__))
			#define VK_PROC_PPC
			#define VK_PROC "VK_PROC_PPC"
		#elif defined(__arm__)
			#define VK_PROC_ARM
			#define VK_PROC "VK_PROC_ARM"
			#if defined(VK_TARGET_IPHONE)
				#define VK_PROC_SIMD_VFP
			#endif
		// error
		#else
			#error "Unrecognized processor for gnu gcc compiler."
		#endif

		#define VK_ALIGNED_DATA(DataToBeAligned, AlignSize) DataToBeAligned __attribute__((aligned(AlignSize)))

		#define VK_ALIGNED_BEGIN(AlignSize)  
		#define VK_ALIGNED_END(AlignSize)  __attribute__((aligned(AlignSize)))

	#else
		#error "Unrecognized processor."
	#endif

	#if defined(VK_PROC_XENON)
		#define VK_CACHE_LINE_SIZE	128
		#define VK_SIMD_ALIGN		16

		#define VK_PREFETCH(o,p)	__dcbt(o,p)

	#elif defined(VK_PROC_PPU)
		#define VK_CACHE_LINE_SIZE	128
		#define VK_SIMD_ALIGN		16

		#define VK_PREFETCH(o,p)	__dcbt(p+o)

	#elif defined(VK_PROC_SPU)
		#define VK_SIMD_ALIGN		16

	#elif defined(VK_PROC_X86) 
		#define VK_CACHE_LINE_SIZE	64
		#define VK_SIMD_ALIGN		16
	#elif defined(VK_PROC_X64) 
		#define VK_CACHE_LINE_SIZE	64
		#define VK_SIMD_ALIGN		16
	#elif defined(VK_PROC_AMD64) 
		#define VK_CACHE_LINE_SIZE	64
		#define VK_SIMD_ALIGN		16
	#elif defined(VK_PROC_PPC) 
		#define VK_CACHE_LINE_SIZE	64
		#define VK_SIMD_ALIGN		16
	#elif defined(VK_PROC_MIPS) 
		#define VK_CACHE_LINE_SIZE	64
		#define VK_SIMD_ALIGN		16
	#elif defined(VK_PROC_ARM)
		#define VK_CACHE_LINE_SIZE	32
		#define VK_SIMD_ALIGN		16
	#elif defined(VK_PROC_SH) 
		#define VK_CACHE_LINE_SIZE	32
		#define VK_SIMD_ALIGN		16
	#elif defined(VK_PROC_WII) 
		#define VK_CACHE_LINE_SIZE	32
		#define VK_SIMD_ALIGN		 4
	#endif

	#ifndef VK_PREFETCH
		#define VK_PREFETCH(p,o)
	#endif

	#define VK_SIMD_ALIGNED_DATA(DataToBeAligned) VK_ALIGNED_DATA(DataToBeAligned,VK_SIMD_ALIGN)
	#define VK_CACHE_ALIGNED_DATA(DataToBeAligned) VK_ALIGNED_DATA(DataToBeAligned,VK_CACHE_LINE_SIZE)

	#define VK_SIMD_ALIGNED_BEGIN  VK_ALIGNED_BEGIN(VK_SIMD_ALIGN)
	#define VK_CACHE_ALIGNED_BEGIN VK_ALIGNED_END(VK_CACHE_LINE_SIZE)

	#define VK_SIMD_ALIGNED_END VK_ALIGNED_END(VK_SIMD_ALIGN)
	#define VK_CACHE_ALIGNED_END VK_ALIGNED_END(VK_CACHE_LINE_SIZE)


	#if defined(VK_TARGET_WINDOWS64)
		extern "C" void _WriteBarrier(void);
		#pragma intrinsic(_WriteBarrier)

		extern "C" void _ReadBarrier(void);
		#pragma intrinsic(_ReadBarrier)

		extern "C" void _ReadWriteBarrier(void);
		#pragma intrinsic(_ReadWriteBarrier)

	#else
		#ifndef VK_TARGET_WINDOWS
			// This is not needed anymore on windows. Redefining them here was causing
			// build issues with non CU build.
			// These are compiler intrinsics which might change in their definition
			// from version to version. It is much safer to rely on VC includes for
			// their definition.
			#define _WriteBarrier() 
			#define _ReadBarrier() 
			#define _ReadWriteBarrier() 
		#endif
	#endif

#endif

// Cross platform alignof

template <class T> struct vkAlignof;

template <class T, int sizeof_quantum>
struct alignof_helper
{
	enum { RET = sizeof_quantum };
};

template <class T>
struct alignof_helper<T,0>
{
	enum { RET = vkAlignof<T>::RET };
};

template <class T>
struct vkAlignof
{
	struct bigger {
    T x;
    char c;
  private:
    bigger();
  };
	enum { RET = alignof_helper<bigger, (sizeof (bigger) - sizeof (T))>::RET };
};

#define VKALIGNOF(type) ((uint32)vkAlignof<type >::RET)

// Macros for accessing data to a particular structure's member ins assembler
#if defined(VK_PROC_X86)
	#if defined(VK_COMPILER_MSVC)
		#define VK_GET_STRUCT_MEMBER_IN_ASM(baseRegister, structName, memberName) [baseRegister]structName.memberName
	#elif defined(VK_COMPILER_GCC)
		#define VK_GET_STRUCT_MEMBER_IN_ASM(baseRegister, structName, memberName) [baseRegister + offsetof(structName, memberName)]
	#else
		#error "Unrecognized assembler for processor X86"
	#endif
#endif

#if defined(VK_DOXYGEN)
	/**
	This define is on if the current processor is Intel X86 compatible.

	X86 processors are available under
		- MSVC (for Windows and XBOX)
		- GCC (for Linux)
	*/
	#define VK_PROC_X86

	/**
	This define is on if the current processor is Intel X64 compatible.
	*/
	#define VK_PROC_X64

	/**
	This define is on if the current processor is Intel AMD64 compatible.
	X86 processors are available under
	- GCC (for Linux and MACOSX)
	*/
	#define VK_PROC_AMD64

	/** This define is on if the current processor is a Xenon.

	Xenon processors is available under MSVC.
	*/
	#define VK_PROC_XENON

	/** This define is on if the current processor is a MIPS. */
	#define VK_PROC_MIPS

	/** This define is on if the current processor is a Playstation 3 PPU. */
	#define VK_PROC_PPU

	/** This define is on if the current processor is a Playstation 3 SPU. */
	#define VK_PROC_SPU

	/** This define is on if the current processor is a Power PC. */
	#define VK_PROC_PPC

	/** This define is on if the current processor is a ARM. */
	#define VK_PROC_ARM

	/** This define is on if the current processor is a SH. */
	#define VK_PROC_SH

	/** This define is on if the current processor is WII PROC. */
	#define VK_PROC_WII


#endif


////////////////////////////////////////////////////////////////////////////////
// check use register for call
////////////////////////////////////////////////////////////////////////////////
#if !defined(VK_USE_REGISTER_FOR_CALL) && (defined(VK_PROC_XENON) || defined(VK_PROC_PPC) || defined(VK_PROC_MIPS) || defined(VK_PROC_WII) || defined(VK_PROC_PPU) || defined(VK_PROC_SPU))
	/**
	This define controls the way a c++ function is called (it used for example for calling c++ from VSL).
	*/
	#define VK_USE_REGISTER_FOR_CALL
#endif


////////////////////////////////////////////////////////////////////////////////
// check for posix support
////////////////////////////////////////////////////////////////////////////////
#if !defined(VK_API_POSIX) && (defined(VK_TARGET_LINUX) || defined(VK_TARGET_ANDROID) || defined(VK_TARGET_MACOSX) || defined(VK_TARGET_IPHONE))
	/**
	This define is on if the current target is POSIX compliant
	and will use Posix to implement system component in the @SDK_NAME.
	*/
	#define VK_API_POSIX
#endif

////////////////////////////////////////////////////////////////////////////////
// check for BSD support
////////////////////////////////////////////////////////////////////////////////
#if !defined(VK_API_BSD) && defined(VK_TARGET_MACOSX) && !defined(VK_PROC_AMD64)
/**
This define is on if the current target is BSD compliant
	and will use BSD to implement system component in the @SDK_NAME.
	*/
#define VK_API_BSD
#endif

#if !defined(VK_API_WIN32) && (defined(VK_TARGET_WINDOWS) || defined(VK_TARGET_WINCE))
	#define VK_API_WIN32
#endif
////////////////////////////////////////////////////////////////////////////////
// check wchar_t built in
////////////////////////////////////////////////////////////////////////////////
#if !defined(EXPERIENCEKERNEL) && !defined(VK_WCHAR_T_IS_BUILT_IN) && !defined(DS_MKMK) && (defined(VK_COMPILER_MSVC)  ||  defined(VK_API_POSIX) )
	#if !defined(VK_DOXYGEN)
		#define VK_WCHAR_T_IS_BUILT_IN 1
	#else
		/**
		This define is on if wchar_t is a built-in type on the current target,
		and then, it doesn't not conflict with char16 nor char32.
		*/
		#define VK_WCHAR_T_IS_BUILT_IN
	#endif
#endif


////////////////////////////////////////////////////////////////////////////////
// check the format of wchar_t
////////////////////////////////////////////////////////////////////////////////
#if !defined(VK_WCHAR_T_IS_UTF32) && (defined(VK_TARGET_LINUX) || defined(VK_TARGET_ANDROID) || defined(VK_TARGET_MACOSX) || defined(VK_TARGET_IPHONE))
	/** This define is on if the current target wchar_t size is 32 bits. */
	#define VK_WCHAR_T_IS_UTF32
#endif

////////////////////////////////////////////////////////////////////////////////
// check the format of wchar_t
////////////////////////////////////////////////////////////////////////////////
#if (!defined(VK_WCHAR_T_IS_UTF16) && !defined(VK_WCHAR_T_IS_UTF32)) || defined(VK_DOXYGEN)
	/** This define is on if the current target wchar_t size is 16 bits. */
	#define VK_WCHAR_T_IS_UTF16
#endif


////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
#if !defined(VK_SUPPORT_AUTOGENERATED_CODE) && (defined(VK_TARGET_LINUX) || defined(VK_TARGET_MACOSX))
	/**
	This define is on if binary executable code can be generated in runtime.

	@todo Check capability on Linux.
	*/
	#define VK_SUPPORT_AUTOGENERATED_CODE
#endif // Linux, MacOS X or Wii


////////////////////////////////////////////////////////////////////////////////
// set the byte order
////////////////////////////////////////////////////////////////////////////////
#if !defined(VK_BIG_ENDIAN)
	#if defined(VK_PROC_PPC) || defined(VK_PROC_XENON)|| defined(VK_PROC_PPU) || defined(VK_PROC_WII) || (defined(VK_COMPILER_GCC) && defined(__BIG_ENDIAN__)) || defined(VK_DOXYGEN)
		/** This define is on if the current target is Big Endian. */
		#define VK_BIG_ENDIAN
	#endif
#endif

#if !defined(VK_LITTLE_ENDIAN)
	#if defined(VK_PROC_X86) || defined(VK_PROC_AMD64) || defined(VK_PROC_X64) || defined(VK_PROC_MIPS) || defined(VK_PROC_ARM) || defined(VK_PROC_SH)  || (defined(VK_COMPILER_GCC) && defined(__LITTLE_ENDIAN__)) || defined(VK_DOXYGEN)
		/** This define is on if the current target is Little Endian. */
		#define VK_LITTLE_ENDIAN
	#endif
#endif

#if !defined(VK_BIG_ENDIAN) && !defined(VK_LITTLE_ENDIAN)
	#error "Unrecognized byte alignment."
#endif


////////////////////////////////////////////////////////////////////////////////
// check it the target is 32/64 bits
////////////////////////////////////////////////////////////////////////////////

#if defined(VK_DOXYGEN)
	/**
	This define is on if the current target is 32 bit.

	@todo check this value under other compiler than VK_COMPILER_MSVC
	*/
	#define VK_32BIT

	/**
	This define is on if the current target is 64 bit.

	@todo check this value under other compiler than VK_COMPILER_MSVC
	*/
	#define VK_64BIT
#endif

#if !defined(VK_64BIT) && !defined(VK_32BIT)
	#define VK_32BIT
#endif


////////////////////////////////////////////////////////////////////////////////
// check compilation configuration : VK_DEBUG, VK_CHECKED, VK_RELEASE
////////////////////////////////////////////////////////////////////////////////

//Force VIAMPFoundation debug mode, i.e. enable VKASSERT
//
#if defined(VK_PROC_AMD64)
//#define VK_DEBUG
#endif
//
////

#if defined(VK_DOXYGEN) || (!defined(VK_DEBUG) && (defined(_DEBUG) || defined(DEBUG)))
	/**
	This define is on if the current configuration is a Debug configuration.

	Debug configuration means:
		- _DEBUG or DEBUG are defined in the preprocessor.
		- no optimization of the compiler
		- assert on
		- full log
	*/
	#define VK_DEBUG
#endif

#if defined(VK_DOXYGEN) || (!defined(VK_CHECKED) && !defined(VK_DEBUG) && !defined(VK_RELEASE))
	/**
	This define is on if the current configuration is a Release configuration.

	Release configuration means:
		- _DEBUG and DEBUG are not defined in the preprocessor and VK_CHECKED is not defined
		in the preprocessor.
		- optimization of the compiler
		- no assert
		- only warning, error and info are logged (see #VKLOGW, #VKLOGE and #VKLOGI).
	*/
	#define VK_RELEASE
#endif

#if defined(VK_DOXYGEN)
	/**
	This define is on if the current configuration is a Release Checked configuration.

	Release checked configuration means:
		- VK_CHECKED has been explicitly defined in the preprocessor.
		- optimization of the compiler
		- assert on
		- full log
	*/
	#define VK_CHECKED
#endif


////////////////////////////////////////////////////////////////////////////////
// check assert mode
////////////////////////////////////////////////////////////////////////////////

#if (defined(VK_RELEASE) && !defined(VK_NO_ASSERT)) || defined(VK_DOXYGEN)
	/**
	This define is on if the current configuration does not generate any assertion.

	VK_NO_ASSERT is on if it is explictly defined by the preprocessor or
	if VK_RELEASE is on. It means VK_NO_ASSERT is off if VK_DEBUG or VK_CHECKED are on.
	*/
	#define VK_NO_ASSERT
#endif


////////////////////////////////////////////////////////////////////////////////
// check static mode
////////////////////////////////////////////////////////////////////////////////

// force static library for some target
#if !defined(VK_STATIC) && ( defined(VK_TARGET_IPHONE) || defined(VK_DOXYGEN) )
	/**
	This define is on if the current configuration is static (do not use any shared library).

	VK_STATIC is on if:
		- it is explictly defined by the preprocessor (VK_TARGET_WINDOWS, VK_TARGET_LINUX, VK_TARGET_MACOSX)
		- or the target only supports static library ( VK_TARGET_IPHONE)
	*/
	#define VK_STATIC
#endif


////////////////////////////////////////////////////////////////////////////////
// check taget supported features
////////////////////////////////////////////////////////////////////////////////

#if defined(VK_TARGET_WINDOWS) || defined(VK_TARGET_WINCE)
	/**
	This define is on if the current target support network file sharing protocol (SMB/CIFS) natively.

	Supported by:
		- Microsoft Windows system (VK_TARGET_WINDOWS, VK_TARGET_WINCE)
	*/
	#define VK_SUPPORT_SYSTEMSMB
#endif

/**
TODO : check in depth why VK_SUPPORT_DEBUGSYMBOL is incompatible with
Virtools Dev build
*/
#if (defined(VK_TARGET_WINDOWS) || defined(VK_TARGET_MACOSX)) && !defined(VK_SDK_FOR_DEV)
	#if defined(VK_DEBUG) || defined(VK_CHECKED)
		/**
		This define is on if the current target support
		interaction with the debug information generated by
		the debugger.

		Supporting interaction with the debug information means,
		at least, be able to generate/crawle the callstack.

		Supported by:
			- Microsoft Windows system (VK_TARGET_WINDOWS) (if VK_DEBUG or VK_CHECKED are on).
		*/
		#ifndef VK_TARGET_WINDOWS64 // no support for debuggin tools undeer win64 for now
			//#define VK_SUPPORT_DEBUGSYMBOL // Remove support on WinXP too
		#endif
	#endif
#endif

#if defined(VK_TARGET_WINDOWS) || defined(VK_TARGET_MACOSX) || defined(VK_TARGET_ANDROID) || defined(VK_TARGET_IPHONE) || defined(VK_TARGET_LINUX) || defined(VK_TARGET_WINCE)
	/**
	This define is on if the current target support memory mapped file natively.

	Supported by:
		- Microsoft Windows system (VK_TARGET_WINDOWS)
		- Mac OS X (VK_TARGET_MACOSX)
		- iOS (VK_TARGET_IPHONE)
		- Linux (VK_TARGET_LINUX)
	*/
	#define VK_SUPPORT_MEMORYMAPPEDFILE
#endif


#if defined(VK_TARGET_WINDOWS) || defined(VK_TARGET_MACOSX) || defined(VK_TARGET_ANDROID)|| defined(VK_TARGET_IPHONE) || defined(VK_TARGET_LINUX) || defined(VK_TARGET_XBOX) || defined(VK_TARGET_WINCE) 
	/**
	This define is on if the current target support parsing directories.

	Supported by:
		- Microsoft Windows system (VK_TARGET_WINDOWS, VK_TARGET_WINCE)
		- Mac OS X (VK_TARGET_MACOSX)
		- iOS (VK_TARGET_IPHONE)
		- Linux (VK_TARGET_LINUX)
	*/
	#define VK_SUPPORT_DIRECTORYPARSER
#endif

#if defined(VK_TARGET_WINDOWS) || defined(VK_TARGET_MACOSX)
/**
This define is on if the current target can move a file/folder to trash.

Supported by:
- Microsoft Windows system (VK_TARGET_WINDOWS)
- Mac OS X (VK_TARGET_MACOSX)
- Linux (VK_TARGET_LINUX)
*/
#define VK_SUPPORT_MOVETOTRASH
#endif

#if defined(VK_TARGET_WINDOWS) || defined(VK_TARGET_MACOSX) || defined(VK_TARGET_IPHONE) || defined(VK_TARGET_LINUX) || defined(VK_TARGET_ANDROID)
	/**
	This define is on if the current target support system environment variables.

	Supported by:
		- Microsoft Windows system (VK_TARGET_WINDOWS)
		- Mac OS X (VK_TARGET_MACOSX)
		- iOS (VK_TARGET_IPHONE)
		- Linux (VK_TARGET_LINUX)
	*/
	#define VK_SUPPORT_SYSTEMENVVAR
#endif

#if defined(VK_TARGET_WINDOWS) || defined(VK_TARGET_WINCE) || defined(VK_TARGET_MACOSX) || defined(VK_TARGET_IPHONE) || defined(VK_TARGET_LINUX) || defined(VK_TARGET_ANDROID)
	/**
	This define is on if the current target support exception handling.

	Supported by:
	- Microsoft Windows system (VK_TARGET_WINDOWS)
	- Mac OS X (VK_TARGET_MACOSX)
	- iOS (VK_TARGET_IPHONE)
	- Linux (VK_TARGET_LINUX)
	*/
	#define VK_SUPPORT_EXCEPTIONS		1
#endif

#if defined(VK_TARGET_WINDOWS) || defined(VK_TARGET_WINCE) || defined(VK_TARGET_MACOSX) || defined(VK_TARGET_LINUX) || defined(VK_TARGET_ANDROID)
	/**
	This define is on if the current target support process spawning.

	Supported by:
	- Microsoft Windows system (VK_TARGET_WINDOWS)
	- Mac OS X (VK_TARGET_MACOSX)
	- Linux (VK_TARGET_LINUX)
	*/
	#define VK_SUPPORT_PROCESS		1
#endif

#if defined(VK_TARGET_WINDOWS) || defined(VK_TARGET_XENON)
	/**
	This define is on if the system thread can choose their processor.

	Supported by:
		- Microsoft Windows system (VK_TARGET_WINDOWS)
	*/
	#define VK_SUPPORT_THREADIDEALPROCESSOR
#endif

#if defined(VK_TARGET_WINDOWS) || defined(VK_TARGET_WINCE) || defined(VK_TARGET_MACOSX)
	/**
	This define is on if the system thread can be suspend/resumed

	Supported by:
		- Microsoft Windows system (VK_TARGET_WINDOWS, VK_TARGET_WINCE)
		- Mac OS X (VK_TARGET_MACOSX)
	*/
	#define VK_SUPPORT_THREADSUSPEND
#endif

#ifndef  VK_SUPPORT_PROCESS
	#define VK_SUPPORT_PROCESS 0
#endif


////////////////////////////////////////////////////////////////////////////////
// calling convention and export
////////////////////////////////////////////////////////////////////////////////

#if defined(VK_COMPILER_MSVC) && !defined(VK_DOXYGEN)
	#define VK_CDECL __cdecl
	#define VK_STDCALL __stdcall
	#define VK_EXPORT  __declspec(dllexport)
	#define VK_PLUGIN_EXPORT extern "C" __declspec(dllexport)
#elif defined(VK_COMPILER_CODEWARRIOR) && !defined(VK_DOXYGEN)
	#define VK_CDECL
	#define VK_STDCALL
	#define VK_EXPORT __declspec(export)
	#define VK_PLUGIN_EXPORT extern "C" __declspec(export)

#elif defined(VK_COMPILER_GCC) && (VK_COMPILER_GCC >= 4) && !defined(VK_DOXYGEN)
	#define VK_CDECL
	#define VK_STDCALL
	#define VK_EXPORT __attribute__((visibility("default")))
	#define VK_PLUGIN_EXPORT extern "C" __attribute__((visibility("default")))

#elif !defined(VK_DOXYGEN)
	#define VK_CDECL
	#define VK_STDCALL
	#define VK_EXPORT
	#define VK_PLUGIN_EXPORT extern "C"
#else
	/**
	Force calling convention of a function to be _cdecl.

	This macro is specific to MSVC so it does nothing with other compiler.
	*/
	#define VK_CDECL

	/**
	Force calling convention of a function to be __stdcall.

	This macro is specific to MSVC so it does nothing with other compiler.
	*/
	#define VK_STDCALL

	/**
	Use this macro to explicitly export a symbol.
	*/
	#define VK_EXPORT

	/**
	Use this macro to explicitly export a symbol with the C naming convention for symbols.
	*/
	#define VK_PLUGIN_EXPORT
#endif

////////////////////////////////////////////////////////////////////////////////
// Try Catch
////////////////////////////////////////////////////////////////////////////////


#if defined(VK_SUPPORT_EXCEPTIONS)
	#define VK_TRY try
	#define VK_CATCH(a) catch(a)
#else
	#define VK_TRY 
	#define VK_CATCH(a) if(0)
#endif

////////////////////////////////////////////////////////////////////////////////
// inline
////////////////////////////////////////////////////////////////////////////////

#if defined(VK_COMPILER_MSVC) && !defined(VK_DOXYGEN)
	#define VK_INLINE inline
	#define VK_CPP_INLINE __forceinline
	#define VK_ALWAYS_INLINE __forceinline
	#define VK_NO_INLINE __declspec(noinline)

#elif defined(VK_COMPILER_GCC) && !defined(VK_DOXYGEN)
	// Do not force inline in debug because it messes out Gcc whatever the platform (ps3, mac)
	// Do not force inline. Recursive inlining generate build error
	// TODO ps3: Provide a solution for recursive inlining and force inline in Release
		#define VK_INLINE inline
		#define VK_CPP_INLINE inline
	#define VK_ALWAYS_INLINE inline __attribute__((always_inline))
	#define VK_NO_INLINE inline __attribute__((noinline))

#elif defined(VK_COMPILER_CODEWARRIOR) && !defined(VK_DOXYGEN)
	#define VK_INLINE inline
	#define VK_CPP_INLINE
	#define VK_NO_INLINE 

#elif !defined(VK_DOXYGEN)
	#define VK_INLINE inline
	#define VK_CPP_INLINE 
	#define VK_NO_INLINE
#else
	/**
	This define instruct the compiler to inline the function. 

	This define instruct the compiler to insert a copy of the function body into each place the function is called. 
	On all compiler excepted MSVC it is equivalent to <C>inline</C>, on MSVC it is equivalent to <C>__forceinline</C>.
	*/
	#define VK_INLINE

	/**
	This define instruct the compiler to inline the function only in the current cpp file.

	On target which support inline in cpp files, this macro is the same thing as VK_INLINE.
	But some target does not support inline in cpp files (like CodeWarrior for PS2), in this case this macro
	does nothing.
	*/
	#define VK_CPP_INLINE 
#endif


#if defined(VK_DEBUG) || defined(VK_CHECKED)
	/**
	This define is on if allocators are configured
	to keep information to help debugging memory allocation (tracking
	memory leaks for example).

	The default behavior is to set this define if VK_DEBUG or VK_CHECKED is on.
	*/
	//#define VK_MEMORYDEBUG
#endif

#if defined(VK_MEMORYDEBUG) && !defined(VK_STATIC) && defined(VK_TARGET_WINDOWS)
	/**
	This define is on if shared library are configured
	to keep information to help debugging memory allocation (tracking
	memory leaks for example).

	The default behavior is to set this define if VK_MEMORYDEBUG is on and VK_STATIC is not on.

	Supported by:
		- Microsoft Windows system (VK_TARGET_WINDOWS)
	*/
	#define VK_SHAREDLIBRARYDEBUG
#endif


#if defined(VK_COMPILER_MSVC) && (defined(VK_PROC_X86) || defined(VK_PROC_X64)) && !defined(VK_DOXYGEN)
#pragma warning(disable:4793)
#define VK_BREAKPOINT	{ __debugbreak();}

#elif defined(VK_TARGET_WINCE) && !defined(VK_DOXYGEN)
#define VK_BREAKPOINT __debugbreak();

#elif defined(VK_TARGET_MACOSX) && !defined(VK_DOXYGEN)
	#define VK_BREAKPOINT { SysBreak(); }

#elif defined(VK_TARGET_IPHONE) && !defined(VK_DOXYGEN)
	#define VK_BREAKPOINT { asm("bkpt 0"); }
	//#define VK_BREAKPOINT { asm("trap"); }
#elif defined(VK_TARGET_ANDROID) && !defined(VK_DOXYGEN)
	#define VK_BREAKPOINT { /*asm("bkpt 0");*/ }
#elif !defined(VK_DOXYGEN) &&  defined(VK_TARGET_ANDROID) 
	#define VK_BREAKPOINT {asm("bkpt 0");};

#elif defined(VK_COMPILER_CODEWARRIOR) && defined(VK_PROC_MIPS) && !defined(VK_DOXYGEN)
	#define VK_BREAKPOINT { asm(" breakc 0x0"); asm(" nop");}

#elif defined(VK_COMPILER_CODEWARRIOR) && defined(VK_PROC_WII) && !defined(VK_DOXYGEN)
	#define VK_BREAKPOINT { asm(" tw 31, r0, r0");}

#elif !defined(VK_DOXYGEN)
	// Force a crash 
	#define VK_BREAKPOINT {int *ptr=0; *ptr = 0;}

#else
	/**
	Macro definition to force the executable to stop on a breakpoint.

	At this time only available on:
		- Microsoft Windows System and XBOX (VK_COMPILER_MSVC && VK_PROC_X86)
		- PS2 (VK_COMPILER_CODEWARRIOR && VK_PROC_MIPS)

	On Mac OS X (VK_TARGET_MACOSX) it does nothing. On other targets try to generate a crash.

	@todo Find a solution for VK_TARGET_MACOSX and VK_TARGET_LINUX
	*/
	#define VK_BREAKPOINT
#endif

#if !defined(VK_DOXYGEN)
	#define VK_COPYRIGHT "(C) 2005 Virtools. All Rights Reserved."
#endif

////////////////////////////////////////////////////////////////////////////////
// some tools macros
////////////////////////////////////////////////////////////////////////////////

/**
Add to a class declaration to make the object uncopyable.

Note that this macro declare the copy constructor and
the affectation operator whitout definition as private method,
so you cannot copy an instance of this class or any derived classes.

@code

class MyClass
{
	VK_NO_COPYING(MyClass);
};

@endcode
*/
#define VK_NO_COPYING(classname)				\
	private:									\
	classname(const classname&); 				\
	classname& operator = (const classname&)

/**
Prepare a class to be have a private implementation.

This macro declares a _CreateImplementation protected static function
that you have define for creating the implementation.

Note that this macro also declare the class as uncopyable using
the VK_NO_COPYING macro.

@code

class MyClass
{
	VK_DECLARE_ABSTRACTPIMPL(MyClass);
};

@endcode

@see VK_NO_COPYING.

@todo Write a better sample.
*/
#define VK_DECLARE_ABSTRACTPIMPL(classname)							\
	VK_NO_COPYING(classname);public:										\
	classname##Impl* Impl() {return (classname##Impl*)m_Implementation;}	\
	const classname##Impl* Impl() const {return (const classname##Impl*)m_Implementation;}	\
	protected:static classname##Impl*	_CreateImplementation();

/**
@todo Write documentation.
*/
#define VK_DECLARE_PIMPL(classname)									\
	VK_DECLARE_ABSTRACTPIMPL(classname);							\
	public: static classname*		CreateInstance();

/**
@todo Write documentation.
*/
#define VK_DECLARE_EXPORTEDPIMPL(classname,exportMacro)				\
	VK_DECLARE_ABSTRACTPIMPL(classname);							\
	public: exportMacro static classname*	CreateInstance();

/**
@todo Write documentation.
*/
#define VK_IMPLEMENT_ABSTRACTPIMPL(classname)								\
	classname##Impl* classname::_CreateImplementation()						\
	{return new classname##Impl;}

/**
@todo Write documentation.
*/
#define VK_IMPLEMENT_PIMPL(classname)										\
	classname* classname::CreateInstance(){classname* c =  new classname;	\
	c->m_Implementation = c->_CreateImplementation(); return c;}			\
	VK_IMPLEMENT_ABSTRACTPIMPL(classname)

/**
Macro definition for cloning objects.

Put VK_DECLARE_STD_CLONE in the class declaration. 

@param className name of your class.
@param baseClassName name of the base class of the current class.

@code
class MyClassB : public MyClassA
{
	VK_DECLARE_STDCLONE(MyClassB,MyClassA);
};
@endcode

will produce the following code

@code
class MyClassB : public MyClassA
{
	virtual MyClassA* Clone() const
	{
		return new MyClassB(*this);
	}
};
@endcode
*/
#define VK_DECLARE_STDCLONE(className, baseClassName)	\
	virtual baseClassName* Clone() const	\
	{	\
		return new className(*this);	\
	} 

/**
Returns the number of element of a static array.

@code
	MyStruct buffer[12];
	// ...
	uint32 count = vkStaticArraySize(buffer);
	// count = 12
@endcode
*/
#define vkStaticArraySize(a) (sizeof(a)/sizeof(a[0]))

////////////////////////////////////////////////////////////////////////////////
// pragma commands to display messages in compilation log
////////////////////////////////////////////////////////////////////////////////

#if !defined(VK_DOXYGEN)

	#define __FILE__LINE__ __FILE__ "(" QUOTE(__LINE__) ") : "
	#define _QUOTE(x) # x

	/**
	Macro used to display the value of a define.

	@code
		printf("Microsoft Visual C version is: " QUOTE(VK_COMPILER_MSVC) "\n");
	@endcode
	*/
	#define QUOTE(x) _QUOTE(x)

	/**
	Display a note in the output of your compiler.

	@code
		#pragma NOTE("Microsoft Visual C is: " QUOTE(VK_COMPILER_MSVC) ")
	@endcode

	will display a line "Microsoft Visual C is: 1310" in the output of your compiler.
	*/
	#undef NOTE
	#define NOTE(x)  message(x)

	/**
	Display a todo in the output of your compiler.

	@code
		// TODO("check this line")
	@endcode

	will display

	<pre>
	.\source\file.cpp(14) : 
	------------------------------------------------
	|  TODO :   check this line
	-------------------------------------------------
	</pre>
	*/
	#define TODO( x )  message( __FILE__LINE__"\n"           \
        " ------------------------------------------------\n" \
        "|  TODO :   " #x "\n" \
        " -------------------------------------------------\n" )

	/**
	Display a tofix in the output of your compiler.

	@code
		#pragma TOFIX("the pointer can be null") 
	@endcode

	will display

	<pre>
	.\source\file.cpp(14) : 
	------------------------------------------------
	|  TOFIX :   the pointer can be null
	-------------------------------------------------
	</pre>
	*/
	#define TOFIX( x )  message(  __FILE__LINE__"\n"           \
        " ------------------------------------------------\n" \
        "|  TOFIX :  " #x "\n" \
        " -------------------------------------------------\n" )

	/**
	Display a todo in the output of your compiler.

	@code
		// TODO("check this line")
	@endcode

	will display

	<pre>
	.\source\VkAssert.cpp(16) :  TODO :  check this line
	</pre>
	*/
	#define todo( x )  message( __FILE__LINE__" TODO :   " #x "\n" ) 

	/**
	Display a todo in the output of your compiler.

	@code
		#pragma tofix("the pointer can be null")
	@endcode

	will display

	<pre>
	.\source\VkAssert.cpp(16) :  TOFIX : the pointer can be null
	</pre>
	*/
	#define tofix( x )  message( __FILE__LINE__" TOFIX:   " #x "\n" )

#endif // VK_DOXYGEN

#if defined(VK_COMPILER_MSVC) && !defined(VK_DOXYGEN)
	// // TODO("remettre ces warnings quand il n y en aura plus d autres (64bits issues)")
	#pragma warning (disable : 4311)
	#pragma warning (disable : 4312)
	// class 'type' needs to have dll-interface to be used by clients of class 'type2'
	#pragma warning( disable : 4251 )
#endif

#if defined(VK_STATIC_LINK) || defined(VK_STATIC)
	/**
	Macro used to import/export symbols.

	This macro does nothing in static mode (see VK_STATIC).
	On some compiler, exporting/importing symbols means nothing, in this
	case the macro does nothing.

	This macro is used to write your own module export/import macro:

	@code
		#if !defined(MYMODULE_API)
			#if defined(MYMODULE_EXPORTS)
				#define VKASSEMBLER_API VK_MODULE_EXPORT
			#else
				#define VKASSEMBLER_API VK_MODULE_IMPORT
			#endif
		#endif
	@endcode
	*/
	//@{
	#define VK_MODULE_EXPORT
	#define VK_MODULE_IMPORT
	//@}
#else
	#if defined(VK_GCC_XML)
		#define VK_MODULE_EXPORT __declspec(dllexport)
		#define VK_MODULE_IMPORT
	#elif defined(VK_COMPILER_MSVC)
		#define VK_MODULE_EXPORT __declspec(dllexport)
		#define VK_MODULE_IMPORT __declspec(dllimport)
	#elif defined(VK_COMPILER_CODEWARRIOR)
		#define VK_MODULE_EXPORT __declspec(export)
		#define VK_MODULE_IMPORT __declspec(import)
	#elif defined(VK_COMPILER_GCC)
		#define VK_MODULE_IMPORT

		#if VK_COMPILER_GCC >= 4
			#define VK_MODULE_EXPORT __attribute__((visibility("default")))
		#else 
			// no export with standard gcc
			#define VK_MODULE_EXPORT
		#endif
	#else
		#error "Unrecognized compiler."
	#endif
#endif

/**
Support for single / multiple context
*/
#if defined(VK_TARGET_WINCE) 
	#undef VK_MULTIPLE_CONTEXTS
#else
	#define VK_MULTIPLE_CONTEXTS 1
#endif

/**
Switch for enabling additional error info system (exception-like)
*/
#if defined(VK_TARGET_WINDOWS) || defined(VK_TARGET_MACOSX)
//#define VK_USE_ERROR_CLASS 1
#endif


////////////////////////////////////////////////////////////////////////////////
// Utility macro to get a string from a macro
////////////////////////////////////////////////////////////////////////////////
#define VKSTRINGIFY(x) #x
#define VKSTR(x) VKSTRINGIFY(x)

#define VKSTRINGIFYW(x) L#x
#define VKSTRW(x) VKSTRINGIFYW(x)

////////////////////////////////////////////////////////////////////////////////
// macros to get valid strings for product, vendor names
////////////////////////////////////////////////////////////////////////////////
#define VK_BRAND_NAME_STR VKSTR(VK_BRAND_NAME)
#define VK_VENDOR_NAME_STR VKSTR(VK_VENDOR_NAME)
#define VK_PRODUCT_NAME_STR VKSTR(VK_PRODUCT_NAME)
#define VK_PRODUCT_INTERNAL_NAME_STR VKSTR(VK_PRODUCT_INTERNAL_NAME)

#define VK_BRAND_NAME_STRW VKSTRW(VK_BRAND_NAME)
#define VK_VENDOR_NAME_STRW VKSTRW(VK_VENDOR_NAME)
#define VK_PRODUCT_NAME_STRW VKSTRW(VK_PRODUCT_NAME)
#define VK_PRODUCT_INTERNAL_NAME_STRW VKSTRW(VK_PRODUCT_INTERNAL_NAME)


#endif // __vkKernelDefines_h




