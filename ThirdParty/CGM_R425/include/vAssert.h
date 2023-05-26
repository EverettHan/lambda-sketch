#if !defined(__vAssert_h)
#define __vAssert_h

/**
@file		  vAssert.h
@author		j6h
@brief		Assertions macros
@details	This file contains several custom definitions of assertion for Visualization Team only.
          It's just a wrapper of the asserts from UIVCoreTools
*/

/** 
@todo juju -> trouver un moyen de garder les aserts meme si pas de -dev en compil
*/

#include "VisREKernel.h"
#include "vKernelDefines.h"
#include "CATSGSYPCheck.h" //asserts of UIVCoreTools
#include "CATSYPCheck.h" //asserts of UIVCoreTools


#if defined(V_ASSERT_DISABLED)

/** 
@brief		Breakpoint.
@details	Macro definition to force the executable to stop on a breakpoint.
@remarks  This Macro totally disappears when V_ASSERT_DISABLED is defined
*/
#define V_BREAKPOINT() do { } while(0)

/** 
@brief		Breakpoint with a message
@details	Macro definition to force the executable to stop on a breakpoint.
          Display iMsg in your output
@remarks  This Macro totally disappears when V_ASSERT_DISABLED is defined
*/
#define V_BREAKPOINT_MSG(iMsg) do { } while(0)

/** 
@brief		Assert if(FAILED(iExpression)) 
@details	Evaluates an expression (iExpression) and, when the result is false, 
          prints a diagnostic msg with at least a message (here : the expression as a string), 
          the file, the function and the line where the assertion occurred.
@remarks  This Macro totally disappears when V_ASSERT_DISABLED is defined
*/
#define V_ASSERT(iExpression) do { } while(0)

/** 
@brief		Assert if(FAILED(iExpression)) and display iMsg
@details	Same as V_ASSERT but you can specify your own message
*/
#define V_ASSERT_MSG(iExpression, iMsg) do { } while(0)

/** 
@brief		Assert if (NULL == iPointer)
@details	Same as V_ASSERT but it evaluates if iPointer is NULL.
@remarks  This Macro totally disappears when V_ASSERT_DISABLED is defined
*/
#define V_ASSERT_CHECK_PTR(iPointer) do { } while(0)

/** 
@brief		Assert if (NULL == iPointer) and display iMsg.
@details	Same as V_ASSERT_CHECK_PTR but you can specify your own message
@remarks  This Macro totally disappears when V_ASSERT_DISABLED is defined
*/
#define V_ASSERT_CHECK_PTR_MSG(iPointer, iMsg) do { } while(0)

/** 
@brief		Assert to specify an operation that is not supported.
@details	This special assert does not evaluates an expression. 
          The assert is always displayed (with "Unsupported" message).
@remarks  This Macro totally disappears when V_ASSERT_DISABLED is defined
*/
#define V_ASSERT_UNSUPPORTED() do { } while(0)

/** 
@brief		Assert to specify an operation that is not supported, and display iMsg
@details	Same as V_ASSERT_UNSUPPORTED()() but you can specify your own message
@remarks  This Macro totally disappears when V_ASSERT_DISABLED is defined
*/
#define V_ASSERT_UNSUPPORTED_MSG(iMsg) do { } while(0)

/** 
@brief		Assert to specify an operation that is not implemented.
@details	This special assert does not evaluates an expression. 
          The assert is always displayed (with "Not Implemented" message).
@remarks  This Macro totally disappears when V_ASSERT_DISABLED is defined
*/
#define V_ASSERT_NOTIMPLEMENTED() do { } while(0)

/** 
@brief		Assert to specify an operation that is not implemented and display iMsg.
@details	Same as V_ASSERT_NOTIMPLEMENTED() but you can specify your own message
@remarks  This Macro totally disappears when V_ASSERT_DISABLED is defined
*/
#define V_ASSERT_NOTIMPLEMENTED_MSG(iMsg) do { } while(0)

/** 
@brief		Assert to specify an operation that is not implemented.
@details	Same as V_ASSERT_NOTIMPLEMENTED() but it also specify the name of the not implemented function.
@remarks  This Macro totally disappears when V_ASSERT_DISABLED is defined
*/
#define V_ASSERT_NOTIMPLEMENTED_FUNCTION() do { } while(0)

/** 
@brief		Assert to specify something still have to be done.
@details	This special assert does not evaluates an expression. 
          The assert is always displayed (with "TODO" message).
@remarks  This Macro totally disappears when V_ASSERT_DISABLED is defined
*/
#define V_ASSERT_TODO() do { } while(0)

/** 
@brief		Assert to specify something still have to be done and display iMsg.
@details	Same as V_ASSERT_TODO() but you can specify your own message
@remarks  This Macro totally disappears when V_ASSERT_DISABLED is defined
*/
#define V_ASSERT_TODO_MSG(iMsg) do { } while(0)

/** 
@brief		Assert to specify something still have to be done.
@details	Same as V_ASSERT_TODO() but it also specify the name of the not implemented function.
*/
#define V_ASSERT_TODO_FUNCTION() do { } while(0)

/*
@brief		Check if (NULL == iPointer)
@see      V_ASSERT_CHECK_PTR
@details	If iPointer is NULL : Assert + return oErrorCode
@remarks  This Macro totally disappears when V_ASSERT_DISABLED is defined
*/
//#define V_ASSERT_CHECK_PTR_RET(iPointer, oErrorCode)

/** 
@brief		Check if (NULL == iPointer)
@see      V_ASSERT_CHECK_PTR
@details	If iPointer is NULL : Assert + return;
@remarks  This Macro totally disappears when V_ASSERT_DISABLED is defined
*/
//#define V_ASSERT_CHECK_PTR_VOID(iPointer)

/** 
@brief		Check if (NULL == iPointer)
@see      V_ASSERT_CHECK_PTR
@details	If iPointer is NULL : Assert + return oErrorCode
@remarks  Only the assertion disappears when V_ASSERT_DISABLED is defined (it still does the return)
*/
//#define V_ASSERT_CHECK_PTR_ALWAYS_RET(iPointer, oErrorCode)

/** 
@brief		Check if (NULL == iPointer)
@see      V_ASSERT_CHECK_PTR
@details	If iPointer is NULL : Assert + return;
@remarks  Only the assertion disappears when V_ASSERT_DISABLED is defined (it still does the return)
*/
//#define V_ASSERT_CHECK_PTR_ALWAYS_VOID(iPointer)


#elif defined (_V_USE_ASSERT_UIVCORETOOLS)

#define V_BREAKPOINT()								          do { FAILURE("Generic Breakpoint"); }                     while(0)
#define V_BREAKPOINT_MSG(iMsg)						      do { FAILURE(iMsg);  }                                    while(0)

#ifdef _WINDOWS_SOURCE
// This function is used to prevent deadlock from main thread.
ExportedByVisREKernel void vAssertFailed(const char* exp, const char* file, int line);
#define V_ASSERT(iExpression)                                                                                                                                  \
  do                                                                                                                                                           \
  {                                                                                                                                                            \
    if (!(iExpression))                                                                                                                                        \
      vAssertFailed(#iExpression, __FILE__, __LINE__);                                                                                                         \
  } while (0)

#else

// On linux, some dependencies are failing to build correctly because many headers use V_ASSERT and not all link
// with VisREKernel.
#define V_ASSERT(iExpression)                   do { CHECK_TRUE(iExpression); }                           while (0)

#endif

#define V_ASSERT_MSG(iExpression, iMsg)				  do { CHECK_TRUE_MSG(iExpression, iMsg);  }                while(0)
#define V_ASSERT_CHECK_PTR(iPointer)				    do { CHECK_POINTER(iPointer);  }                          while(0)
#define V_ASSERT_CHECK_PTR_MSG(iPointer, iMsg)	do { CHECK_POINTER_MSG(iPointer, iMsg);  }                while(0)
#define V_ASSERT_UNSUPPORTED()						      do { FAILURE("Unsupported");  }                           while(0)
#define V_ASSERT_UNSUPPORTED_MSG(iMsg)				  do { FAILURE_MSG("Unsupported", iMsg);  }                 while(0)
#define V_ASSERT_NOTIMPLEMENTED()						    do { FAILURE("Not Implemented");  }                       while(0)
#define V_ASSERT_NOTIMPLEMENTED_MSG(iMsg)			  do { FAILURE_MSG("Not Implemented", iMsg);  }             while(0)
#define V_ASSERT_NOTIMPLEMENTED_FUNCTION()      do { FAILURE_MSG("Not Implemented", __V_FUNCTION__);  }   while(0)
#define V_ASSERT_TODO()								          do { FAILURE("TODO");  }                                  while(0)
#define V_ASSERT_TODO_MSG(iMsg)						      do { FAILURE_MSG("TODO", iMsg);  }                        while(0)
#define V_ASSERT_TODO_FUNCTION()      					do { FAILURE_MSG("TODO", __V_FUNCTION__);  }              while(0)


#elif defined(_V_USE_ASSERT_OS) && defined(_WINDOWS_SOURCE)                                            
#include <Windows.h>                                                                                   

#define V_BREAKPOINT()								           do  { DbgRaiseAssertionFailure(); }                      while(0)
#define V_BREAKPOINT_MSG(iMsg)						       do  {V_BREAKPOINT();}                                    while(0)
#define V_ASSERT(iExpression)                    do  { if(!(iExpression)) {V_BREAKPOINT();} }			        while(0)			           
#define V_ASSERT_MSG(iExpression, iMsg)				   do  { V_ASSERT(iExpression); }	                          while(0)
#define V_ASSERT_CHECK_PTR(iPointer)				     do  { if(NULL == (iPointer)) {V_BREAKPOINT();} }        	while(0)
#define V_ASSERT_CHECK_PTR_MSG(iPointer, iMsg)   do  { V_ASSERT_CHECK_PTR(iPointer, iMsg); }	            while(0)
#define V_ASSERT_UNSUPPORTED()						       do  {V_BREAKPOINT();}                                    while(0)
#define V_ASSERT_UNSUPPORTED_MSG(iMsg)				   do  {V_BREAKPOINT();}                                    while(0)
#define V_ASSERT_NOTIMPLEMENTED()						     do  {V_BREAKPOINT();}                                    while(0)
#define V_ASSERT_NOTIMPLEMENTED_MSG(iMsg)			   do  {V_BREAKPOINT();}                                    while(0)
#define V_ASSERT_NOTIMPLEMENTED_FUNCTION()       do  {V_ASSERT_UNSUPPORTED();}                            while(0)
#define V_ASSERT_TODO()								           do  {V_BREAKPOINT();}                                    while(0)
#define V_ASSERT_TODO_MSG(iMsg)				           do  {V_BREAKPOINT();}                                    while(0)
#define V_ASSERT_TODO_FUNCTION()      					 do  {V_BREAKPOINT();}                                    while(0) 
#else

#error "SGCoreUtils : a problem with the asserts definitions occured".

#endif

//#if !defined(V_ASSERT_DISABLED)

#define V_ASSERT_CHECK_PTR_RET(iPointer, oErrorCode)          do { if(NULL == (iPointer)) {V_BREAKPOINT(); return oErrorCode; } } while(0)
#define V_ASSERT_CHECK_PTR_VOID(iPointer)                     do { if(NULL == (iPointer)) {V_BREAKPOINT(); return;} } while(0)

#define V_ASSERT_CHECK_PTR_ALWAYS_RET(iPointer, oErrorCode)   do { if(NULL == (iPointer)) {V_BREAKPOINT(); return oErrorCode; }} while(0)
#define V_ASSERT_CHECK_PTR_ALWAYS_VOID(iPointer)              do { if(NULL == (iPointer)) {V_BREAKPOINT(); return;} } while(0)

#define V_ASSERT_IF_FAILED(iExpression) do{ if(FAILED((iExpression))) { V_BREAKPOINT(); } }while(0)
//#endif




#endif // end : __vAssert_h
