/**
@file

This file defines ASSERT macros.

@COPYRIGHT

@author Nicolas Hognon

@see VKASSERT
*/

#if !defined(__vkAssert_h)
#define __vkAssert_h
#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkKernelTypes_h)
	#include "vkKernelTypes.h"
#endif

namespace VKernel
{

// class forward so vkString.h is not included.
class vkString;



#if !defined(VK_NO_ASSERT) && !defined(VK_DOXYGEN)
	#define VKASSERT(expression)	\
	{	\
		if (!(expression)) {	\
			static bool ignoreAlways = false;	\
			if (VKernel::SystemAssert(#expression,__FILE__, __LINE__,__FUNCTION__,&ignoreAlways)) {	\
				VK_BREAKPOINT	\
			}	\
		}	\
	}

	#define VKASSERTEX(expression,statement)	\
	{	\
		if (!(expression)) {	\
			static bool ignoreAlways = false;	\
			if (VKernel::SystemAssert(statement,__FILE__, __LINE__,__FUNCTION__,&ignoreAlways)) {	\
				VK_BREAKPOINT	\
			}	\
		}	\
	}

	#define VKASSERTEX2(expression,statement,file,line,function)	\
	{	\
		if (!(expression)) {	\
			static bool ignoreAlways = false;	\
			if (VKernel::SystemAssert(statement,file, line,function,&ignoreAlways)) {	\
				VK_BREAKPOINT	\
			}	\
		}	\
	}

	#define VKUNSUPPORTED()	\
	{	\
		static bool ignoreAlways = false;	\
		if (VKernel::SystemAssert("(Unsupported)",__FILE__, __LINE__,__FUNCTION__,&ignoreAlways)) {	\
			VK_BREAKPOINT	\
		}	\
	}

	#define VKUNSUPPORTEDEX(statement)	\
	{	\
		static bool ignoreAlways = false;	\
		if (VKernel::SystemAssert(statement,__FILE__, __LINE__,__FUNCTION__,&ignoreAlways)) {	\
			VK_BREAKPOINT	\
		}	\
	}

	#define VKNOTYETIMPLEMENTED()	\
	{	\
		static bool ignoreAlways = false;	\
		if (VKernel::SystemAssert("(Not Yet Implemented)",__FILE__, __LINE__,__FUNCTION__,&ignoreAlways)) {	\
			VK_BREAKPOINT	\
		}	\
	}

	#define VKNOTYETIMPLEMENTEDEX(statement)	\
	{	\
		static bool ignoreAlways = false;	\
		if (VKernel::SystemAssert(statement,__FILE__, __LINE__,__FUNCTION__,&ignoreAlways)) {	\
			VK_BREAKPOINT	\
		}	\
	}

	#define VKTODO(statement)	\
	{	\
		static bool ignoreAlways = false;	\
		if (VKernel::SystemAssert(VK_AS("TODO: ") + statement,__FILE__, __LINE__,__FUNCTION__,&ignoreAlways)) {	\
		VK_BREAKPOINT	\
		}	\
	}

#else
	/**
	Runtime time assert. 

	This macro evaluates an expression and, when the result is false,
	prints a diagnostic message. The behavior of the assert depend
	on the vkSystem::s_AssertDisplayDialog static variable and the platform. For more
	information see vkKernelModule::FAssertBehavior.

	The message displayed contains at least: the statement (the expression as a string), the file, the function and the line
	where the assertion occurred.

	All assert can be removed using the VK_NO_ASSERT define. This define
	is on when VK_RELEASE is on.

	@param expression the expression to evaluates.

	@code
		void Function(void* iUserData)
		{
			VKASSERT(iUserData!=0); // "Invalid parameter (null pointer)"

			...
			DoSomething()
			...
		}
	@endcode

	@see VKASSERTEX, VKASSERTEX2, VKCALLASSERT, vkKernelModule::FAssertBehavior, vkSystem::s_AssertDisplayDialog, VK_NO_ASSERT, VK_RELEASE
	*/
	#define VKASSERT(expression)
	
	/**
	Runtime time assert. 

	Same as VKASSERT but you can specify your own statement.

	@param expression the expression to evaluates.
	@param statement used to create the message which will be displayed.

	@see VKASSERT
	*/
	#define VKASSERTEX(expression,statement)

	/**
	Runtime time assert. 

	Same as VKASSERT but you can specify your own statement, file, function and line.

	@param expression the expression to evaluates.
	@param statement used to create the message which will be displayed.
	@param file specify the file where the assertion occurred.
	@param line specify the line where the assertion occurred.
	@param function specify the function where the assertion occurred.

	@see VKASSERT
	*/
	#define VKASSERTEX2(expression,statement,file,line,function)

	/**
	Runtime time assert to specify an operation is not supported.

	This special assert does not evaluates an expression. The assert
	is always displayed.

	This example

	@code
		VKUNSUPPORTED();
	@endcode

	produce the same result as the following example

	@code
		VKASSERTEX(false,"(Unsupported)");
	@endcode

	@see VKASSERT
	*/
	#define VKUNSUPPORTED()
	
	/**
	Runtime time assert to specify an operation is not supported.

	Same as VKUNSUPPORTED but you can specify your own statement.

	@see VKUNSUPPORTED

	
	*/
	#define VKUNSUPPORTEDEX(statement)
	
	/**
	Runtime time assert to specify an operation is not yet implemented.

	This special assert does not evaluates an expression. The assert
	is always displayed.

	This example

	@code
		VKNOTYETIMPLEMENTED();
	@endcode

	produce the same result as the following example

	@code
		VKASSERTEX(false,"(Not Yet Implemented)");
	@endcode

	@see VKASSERT

	
	*/
	#define VKNOTYETIMPLEMENTED()
	
	/**
	Runtime time assert to specify an operation is not supported.

	Same as VKNOTYETIMPLEMENTED but you can specify your own statement.

	@see VKNOTYETIMPLEMENTED	
	*/
	#define VKNOTYETIMPLEMENTEDEX(statement)

	/**
	Runtime assert to specify something still have to be done.
	
	@see VKNOTYETIMPLEMENTED	
	*/
	#define VKTODO(statement)

#endif // !VK_NO_ASSERT


#if !defined(VK_NO_ASSERT) && !defined(VK_DOXYGEN)

	#define VKCALLASSERT(expression)	\
	{	\
		if (!(expression)) {	\
			static bool ignoreAlways = false;	\
			if (VKernel::SystemAssert(#expression,__FILE__, __LINE__,__FUNCTION__,&ignoreAlways)) {	\
				VK_BREAKPOINT	\
			}	\
		}	\
	}

	#define VKCALLASSERTEX(expression,statement)	\
	{	\
		if (!(expression)) {	\
			static bool ignoreAlways = false;	\
			if (VKernel::SystemAssert(statement,__FILE__, __LINE__,__FUNCTION__,&ignoreAlways)) {	\
					VK_BREAKPOINT	\
				}	\
			}	\
		}	\
	}
#elif !defined(VK_DOXYGEN)
	#define VKCALLASSERT(expression)				(expression)
	#define VKCALLASSERTEX(expression,statement)	(expression)
#else
	/**
	Runtime time assert with expression evaluation.

	@param expression the expression to evaluates.

	Same as VKASSERT excepted the expression is evaluated
	even if VK_NO_ASSERT is on.

	@see VKASSERT, VK_NO_ASSERT

	
	*/
	#define VKCALLASSERT(expression)

	/**
	Runtime time assert with expression evaluation.
	
	@param expression the expression to evaluates.
	@param statement used to create the message which will be displayed.

	Same as VKCALLASSERT but you can specify your own statement.

	@see VKCALLASSERT

	
	*/
	#define VKCALLASSERTEX(expression,statement)
#endif // !VK_NO_ASSERT

#if !defined(VK_DOXYGEN)

// Function used by the VKASSERT (and VKCALLASSERT) macros.
// Do not call this function, use VKASSERT (or VKCALLASSERT) macro.
// @see  VKASSERT, VKCALLASSERT
VKKERNEL_API bool SystemAssert(const char8* iASCIIStatement, const char* iFile, const int iLine, const char* iFunction, bool* oIgnore);
VKKERNEL_API bool SystemAssert(const wchar_t* iWideCharStatement, const char* iFile, const int iLine, const char* iFunction, bool* oIgnore);
VKKERNEL_API bool SystemAssert(const vkString& iStatement, const char* iFile, const int iLine, const char* iFunction, bool* oIgnore);

VKKERNEL_API bool IsInAssert();

extern volatile bool g_IsInAssert;


#endif // VK_DOXYGEN

} // namespace VKernel

#endif // __vkAssert_h

