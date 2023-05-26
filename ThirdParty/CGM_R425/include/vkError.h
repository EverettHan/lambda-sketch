
/**
@file

This file defines main error values, macros and tools to manipulate errors.

@COPYRIGHT

@author Nicolas Hognon
*/

#if !defined(__vkError_h)
#define __vkError_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkKernelTypes_h)
	#include "vkKernelTypes.h"
#endif
#if !defined(__vkHeapManager_h)
	#include "vkHeapManager.h"
#endif
#if !defined(__vkHeapObject_h)
	#include "vkHeapObject.h"
#endif

namespace VKernel
{
	class vkErrorInfo;
	class vkErrorHandler;
	class vkErrorManager_Imp;

/**
Enumeration defining base error values for @SDK_NAME.

Other values can be defined by @SDK_NAME in other APIs.

@see vkErrorManager

@ingroup grp_error
*/
enum EBaseError
{
	////////////////////////////////////////
	// WARNING: think to update errLastBaseError when you add a value
	////////////////////////////////////////

	/** The operation completed successfully. */
	errOk				= 0,
	/** The operation failed (Generic failure). */
	errFailed			= -1,
	/**
	A system call failed (Generic system failure).
	
	You retrieve information about the system error using vkErrorManager::GetLastBackupedSystemError.
	You can also compute a readable error message using vkErrorManager::FormatSystemErrorMessage.
	*/
	errSysCallFailed	= -2,
	/** Returned by routines that are not implemented. */
	errNotImplemented	= -3,
	/** The object on which a method is called, is invalid. */
	errInvalidObject	= -4,
	/**
	The object on which a method is called, cannot execute the method
	because it's in a incorrect state.
	*/
	errInvalidState		= -5,
	/** The parameter is incorrect. */
	errInvalidParameter	= -6,
	/** The element already exists. */
	errAlreadyExists	= -7,
	/** Cannot find the element. */
	errNotFound			= -8,
	/** The values go out of range. */
	errOutOfRange		= -9,
	/** There is no more element in the iteration. */
	errEndOfIteration	= -10,
	/** Syntax error. */
	errSyntaxError		= -11,
	/** The conversion failed. */
	errConversionFailed	= -12,
	/** Invalid type. */
	errBadType			= -13,
	/** Unknown type. */
	errUnknownType		= -14,
	/** The initialization failed. */
	errInitFailed		= -15,
	/** Failed to destroy the object. */
	errDestroyFailed	= -16,
	/** The timeout interval elapsed. */
	errTimeout			= -17,
	/** The operation was canceled. */
	errCancelled		= -18,
	/** The operation is pending. */
	errPending			= -19,
	/** Failed to load the file. */
	errLoadFailed		= -20,
	/** Failed to save the file. */
	errSaveFailed		= -21,
	/** An allocation failed. */
	errAllocationFailed = -22,
	/** No data are available. */
	errNoDataAvailable	= -23,
	/** End of stream. */
	errEndOfStream			= -24,
	/** Failed to write in the stream. */
	errWriteInStreamFailed	= -25,
	/** Invalid BOM In Text Streams. */
	errInvalidBOM			= -26,
	/** Failed to read a XML stream. */
	errXMLReadFailed		= -27,
	/** Failed to write in a XML stream. */
	errXMLWriteFailed		= -28,
	/** System out of heap memory. */
	errOutOfMemory			= -29,
	/** No environment variable found in the string. */
	errNoEnvironmentVariable	= -30,
	/** Two objects from two different contexts try to "communicate".*/
	errContextConflict			= -31,
	/** Not a file. It means "something" exist but it is not a file. */
	errNotFile					= -32,
	/** Not a directory. It means "something" exist but it is not a directory. */
	errNotDirectory				= -33,
	/** Not ready. When an object is valid, but not ready (waiting for other data to work). */
	errNotReady					= -34,
	/** Not ready. When an object is valid, but not ready (waiting for other data to work). */
	errNotSupported				= -35,
	/** The operation is denied. */
	errDenied					= -36,
	/** The main (default) swap chain of a rasterizer is already owned by a another device, so going to fullscreen can't be done */
	errDefaultSwapChainAlreadyAcquiredByAnotherDevice = -37,

	////////////////////////////////////////
	// WARNING: think to update errLastBaseError when you add an error value
	////////////////////////////////////////
#if !defined(VK_DOXYGEN)
	errLastBaseError	= -38
#endif // VK_DOXYGEN
};


/**
Enumeration defining error scope for @SDK_NAME.
On some platform the network error and generic system error are stored separatly. 
To get the network error scope GetLastSystemError() should be called with errScopeNetwork value. 

@see vkErrorManager

@ingroup grp_error
*/
enum EErrorScope{
	errScopeSystem	= 0,
	errScopeNetwork = 1,
};

/**
This class is an utility class to manipulate error.

This class is used to manipulate errors. You can:
	- convert error to string (ErrorToString(), RegisterErrorString(), FormatSystemErrorMessage())
	- get information about system error (GetLastBackupedSystemError(), GetLastSystemError())
	- register information about error (TraceError(), BackupLastSystemError())

Many of this operations can be done using utility macros:
	- VK_THROW_ERROR, VK_THROW_ERROR_EX
	- VK_SUCCEEDED, VK_FAILED
	- VK_RETURN_IF_FAILED, VK_RETURN_IF_FAILED_EX, VK_RETURN_IF.
	- VK_THROW_SYSCALLFAILED, VK_THROW_SYSCALLFAILED_EX, VK_THROW_SYSCALLFAILED_EX2

If you want to create your own set of error value, you have to:

1. defines your enumeration (user value should be >0, values <=0 are reserved to
@SDK_NAME)

@code
	#define MY_BASE_VALUE	10000

	enum EMyErrorValue
	{
		errMyValue1 = MY_BASE_VALUE,
		errMyValue2,
		errMyValue3,
		...
		errMyValuex,

		errMyLastValue
	};
@endcode

2. write a function to register your range of errors and error values description.

@code
bool RegisterMyErrorValue()
{
	// errMyLastValue-1 because errMyLastValue is not really an error
	if (!RegisterRangeError(errMyValue1,errMyLastValue-1)) {
		return false;
	}

	bool res = RegisterErrorString(errMyValue1,VK_AS("errMyValue1 description"));
	res = res && RegisterErrorString(errMyValue2,VK_AS("errMyValue2 description"));
	res = res && RegisterErrorString(errMyValue3,VK_AS("errMyValue3 description"));
	...
	res = res && RegisterErrorString(errMyValuex,VK_AS("errMyValuex description"));

	if (!res) {
		return false;
	}

	// just to be sure we have really registered all error descriptions.
	res = CheckRangeError(errMyValue1,errMyLastValue-1);

	return res;
}
@endcode

@see error

@ingroup grp_error
*/
class VKKERNEL_API vkErrorManager : public vkHeapObject
{
public:

	/**
	Returns the unique instance of the Error Manager.
	@return the error manager
	*/
	static vkErrorManager& Instance();

	/**
	Returns the unique instance of the Error Manager or null if not initialized.
	@return the error manager
	*/
	static vkErrorManager* InstancePtr();

	/**
	Convert an error value to a string.

	Each error value should have its description.
	
	The error defined by the enumeration EBaseError are associated to a description when the vkKernel
	module is initialized (see vkKernelModule).

	@param iError the error value to convert to a string.

	@return A string describing the error value. This string can be empty
	if the error value description has not been found.

	@see RegisterErrorString
	*/	 
	const vkString&	ErrorToString(error iError) const;

	/**
	Register an error description.

	Register the description associated to an error value. Each error value
	should have its description. Before registering an error description we must register
	the range containing this error value.

	The error defined by the enumeration EBaseError are associated to a description when the vkKernel
	module is initialized (see vkKernelModule).

	@param iError the error value to describes.
	@param iString the error description.

	@return errOk if the description has been successfully registered (the error is not
	already registered and it is part of a registered range).

	@see ErrorToString
	@see RegisterRangeError
	*/
	error RegisterErrorString(error iError, const vkString& iString);

	/**
	Unregisters an error description.
	@param iError the error value to unregister.
	@return errOk if the description has been successfully unregistered or errNotFound
	if the error was not previously registered
	@see RegisterErrorString
	*/
	error UnregisterErrorString(error iError);

	/**
	Register a range error.

	Before registering any error description, you need to register the
	range which contains this error.

	The error defined by the enumeration EBaseError are associated to a description when the vkKernel
	module is initialized (see vkKernelModule).

	@param iMinValue minimal value of the range
	@param iMaxValue maximal value of the range.

	@return errOk if the range has been successfully registered (the range is
	not in conflict with other ranges).

	@see CheckRangeError, RegisterErrorString, ErrorToString
	*/
	error RegisterRangeError(error iMinValue, error iMaxValue);

	/**
	Unregisters a range error.
	You must pass the exact minimal and maximal that was passed in RegisterRangeError
	to remove the range.
	@param iMinValue minimal value of the range
	@param iMaxValue maximal value of the range.

	@return errOk if the range has been successfully registered or false if the range is unknown

	@see CheckRangeError, RegisterErrorString, ErrorToString
	*/
	error UnregisterRangeError(error iMinValue, error iMaxValue);

	/**
	Checks if all error value of a range have a description.

	@param iMinValue minimal value of the range
	@param iMaxValue maximal value of the range.

	@return errOk if all error value of a range have a description.

	@see RegisterRangeError, RegisterErrorString, ErrorToString
	*/
	error CheckRangeError(error iMinValue, error iMaxValue) const;

	/**
	Throws an error.

	This function is used to log information about an error and store information
	to be later retrieved by error handlers.

	The best way to throw an error is to use one of the VK_THROW_ERROR macros.
	The methods with suffix NoLog don't log any message. Only the vkErrorInfo is updated

	@param iError the error.
	@param iFile the file where the error has been raised.
	@param iLine the line in the file where the error has been raised.
	@param iFunction the function where the error has been raised.
	@param iMessage a message associated to the error. If empty (or not specified) the message will be
	@param iErrorInfo an object encapsulating all information about the error to be raised
	the result of ErrorToString.
		
	@see ErrorToString, VK_THROW_ERROR, VK_THROW_ERROR_EX
	*/
	//@{
	error ThrowError(error iError, const char8* iFile, uint32 iLine, const char8* iFunction);
	error ThrowError(error iError, const char8* iFile, uint32 iLine, const char8* iFunction, const vkString& iMessage);
	error ThrowError(vkErrorInfo* iErrorInfo, const char8* iFile, uint32 iLine, const char8* iFunction);

	error ThrowErrorNoLog(error iError, const char8* iFile, uint32 iLine, const char8* iFunction);
	error ThrowErrorNoLog(error iError, const char8* iFile, uint32 iLine, const char8* iFunction, const vkString& iMessage);
	error ThrowErrorNoLog(vkErrorInfo* iErrorInfo, const char8* iFile, uint32 iLine, const char8* iFunction);
	//@}

	error AddErrorHandler(vkErrorHandler* iHandler);
	error RemoveErrorHandler(vkErrorHandler* iHandler);

	vkErrorInfo*		GetLastErrorInfo(error iOriginalError) const;
	void				ResetLastErrorInfo();

	/**
	Computes the full error message from an error info and a user-oriented message
	@param iError the error to format
	@param iMessage the message explaining a little bit the error
	@param oFullErrorMessage in output the full message
	@return error code
	*/
	// @{
	error GetFullErrorMessage(error iError, const vkString& iMessage, vkString& oFullErrorMessage) const;
	// @}

	/**
	Backup a system error in the error manager.
	
	The last-error code is maintained on a per-thread basis.
	Multiple threads do not overwrite each other's last-error code.

	@code
		vkErrorManager& manager = vkErrorManager::Instance();
		int32 sysError = manager.GetLastSystemError();
		manager.BackupLastSystemError(sysError);

		vkString str;
		manager.FormatSystemErrorMessage(sysError,str);
		vkUTF8Lock lock(str);
		VKLOGE("SYSTEM ERROR (%s:%u)",lock.CStr(),sysError);
	@endcode

	@param iError A system error retrieved using GetLastSystemError().
	
	@see GetLastSystemError, GetLastBackupedSystemError.
	*/
	void BackupLastSystemError(errorsys iError);

	/**
	Backup the last system error in the error manager.

	Same as BackupLastSystemError(int32 iError) excepted GetLastSystemError()
	is called to automatically retrieve the last system error.

	The last-error code is maintained on a per-thread basis.
	Multiple threads do not overwrite each other's last-error code.

	@code
		vkErrorManager& manager = vkErrorManager::Instance();
		manager.BackupLastSystemError();
		int32 sysError = manager.GetLastBackupedSystemError();

		vkString str;
		manager.FormatSystemErrorMessage(sysError,str);
		vkUTF8Lock lock(str);
		VKLOGE("SYSTEM ERROR (%s:%u)",lock.CStr(),sysError);
	@endcode

	@see BackupLastSystemError(int32 iError), GetLastSystemError, GetLastBackupedSystemError.
	*/
	void BackupLastSystemError();

	/**
	Retrieve the last system error which was backuped in the error manager.
	
	The last-error code is maintained on a per-thread basis.
	Multiple threads do not overwrite each other's last-error code.

	@code
		vkErrorManager& manager = vkErrorManager::Instance();
		manager.BackupLastSystemError();
		int32 sysError = manager.GetLastBackupedSystemError();

		vkString str;
		manager.FormatSystemErrorMessage(sysError,str);
		vkUTF8Lock lock(str);
		VKLOGE("SYSTEM ERROR (%s:%u)",lock.CStr(),sysError);
	@endcode
	
	@return The last system error which was backuped in the error manager.
	
	@see BackupLastSystemError(int32 iError), BackupLastSystemError(), GetLastSystemError
	*/
	errorsys GetLastBackupedSystemError() const;

	/**
	Retrieve the last system error.
	
	Retrieve the last system error, not from vkErrorManager but really from the operating
	system (on Windows operating system call ::GetLastError).
	
	@code
		vkErrorManager& manager = vkErrorManager::Instance();
		int32 sysError = manager.GetLastSystemError();
		manager.BackupLastSystemError(sysError);

		vkString str;
		manager.FormatSystemErrorMessage(sysError,str);
		vkUTF8Lock lock(str);
		VKLOGE("SYSTEM ERROR (%s:%u)",lock.CStr(),sysError);
	@endcode

	@return The last system error.
	
	@see BackupLastSystemError, GetLastBackupedSystemError, FormatSystemErrorMessage, VK_THROW_SYSCALLFAILED
	*/
	static errorsys GetLastSystemError(EErrorScope iScope = errScopeSystem);

	/**
	Convert a system error to a string.
	
	This function is used to convert a system error to a string using target dependent
	functions.

	@code
		vkErrorManager& manager = vkErrorManager::Instance();
		int32 sysError = manager.GetLastSystemError();
		manager.BackupLastSystemError(sysError);

		vkString str;
		manager.FormatSystemErrorMessage(sysError,str);
		vkUTF8Lock lock(str);
		VKLOGE("SYSTEM ERROR (%s:%u)",lock.CStr(),sysError);
	@endcode
	
	@param iError A system error retrieved using GetLastSystemError() or GetLastBackupedSystemError.
	@param oString The string to store the result.
	
	@see GetLastSystemError, GetLastBackupedSystemError, VK_THROW_SYSCALLFAILED
	*/
	void FormatSystemErrorMessage(errorsys iError, vkString& oString) const;

public:

	// To be used only by macros VK_THROW_ERROR
	static error SThrowError(error iError, const char8* iFile, uint32 iLine, const char8* iFunction);
	static error SThrowError(error iError, const char8* iFile, uint32 iLine, const char8* iFunction, const vkString& iMessage);
	static error SThrowError(vkErrorInfo* iErrorInfo, const char8* iFile, uint32 iLine, const char8* iFunction);

	static error SThrowErrorNoLog(error iError, const char8* iFile, uint32 iLine, const char8* iFunction);
	static error SThrowErrorNoLog(error iError, const char8* iFile, uint32 iLine, const char8* iFunction, const vkString& iMessage);
	static error SThrowErrorNoLog(vkErrorInfo* iErrorInfo, const char8* iFile, uint32 iLine, const char8* iFunction);


private:

	friend class vkKernelModule;

	static error _Initialize();
	static error _Uninitialize();
	
	error _RegisterBaseError();
	bool _IsRange(error iError) const;

	vkErrorManager();
	~vkErrorManager();

	VK_NO_COPYING(vkErrorManager);

	vkErrorManager_Imp* m_Imp;
};

} // namespace VKernel

#if !defined(VK_DOXYGEN)

#define VK_THROW_ERROR(iError)	\
{	\
	return vkErrorManager::SThrowError(iError, __FILE__, __LINE__, __FUNCTION__); \
}

#define VK_THROW_ERROR_EX(iError, iMessage)	\
{	\
	return vkErrorManager::SThrowError(iError, __FILE__, __LINE__,__FUNCTION__, iMessage); \
}

#define VK_THROW_ERROR_INFO(iErrorInfo)	\
{	\
	return vkErrorManager::SThrowError(iErrorInfo, __FILE__, __LINE__,__FUNCTION__); \
}

#define VK_THROW_ERROR_NOLOG(iError)	\
{	\
	return vkErrorManager::SThrowErrorNoLog(iError, __FILE__, __LINE__, __FUNCTION__); \
}

#define VK_THROW_ERROR_EX_NOLOG(iError, iMessage)	\
{	\
	return vkErrorManager::SThrowErrorNoLog(iError, __FILE__, __LINE__,__FUNCTION__, iMessage); \
}

#define VK_THROW_ERROR_INFO_NOLOG(iErrorInfo)	\
{	\
	return vkErrorManager::SThrowErrorNoLog(iErrorInfo, __FILE__, __LINE__,__FUNCTION__); \
}


#define VK_SUCCEEDED(iError) ((iError) == VKernel::errOk)
#define VK_FAILED(iError) ((iError) != VKernel::errOk)


// Error version
#define VK_RETURN_IF_FAILED(expression)	\
{	\
	const error errorReturnedByExpression = expression; \
	if (VK_FAILED(errorReturnedByExpression)) \
		return errorReturnedByExpression; \
}

#define VK_RETURN_IF_FAILED_EX(expression, oError)	\
{	\
	const error errorReturnedByExpression = expression; \
	if (VK_FAILED(errorReturnedByExpression)) \
		return oError; \
}

#define VK_RETURN_IF(iErr, expression)	\
{	\
	const error errorReturnedByExpression = expression; \
	if (errorReturnedByExpression == iErr) \
		return iErr; \
}

#define VK_RETURN_IF_NULL(expression, ErrCode) \
	if(expression == NULL) return ErrCode;

#define VK_VOID_IF_NULL(expression) \
	if(expression == NULL) return;

#define VK_ASSERT_VOID_IF_NULL(expression) \
{ \
	if(expression == NULL) { \
		VKASSERT(expression != NULL); \
		return; \
	} \
} 

// Bool version
#define VK_RETURN_BOOL_IF_NULL(expression) \
	if (expression == NULL) return false;

#define VK_RETURN_BOOL_IF_FAILED(expression)			\
{														\
	const error valueReturnedByExpression = expression; \
	if (VK_FAILED(valueReturnedByExpression))			\
		return false;									\
}



#define VK_THROW_ERROR_IF(expression, iError)	\
{	\
	if( expression ){ \
		return vkErrorManager::SThrowError(iError, __FILE__, __LINE__, __FUNCTION__); \
	} \
}

#define VK_THROW_ERROR_IF_EX(expression, iError, message)	\
{	\
	if( expression ){ \
		return vkErrorManager::SThrowError(iError, __FILE__, __LINE__, __FUNCTION__, message); \
	} \
}

#define VK_THROW_SYSCALLFAILED()	\
{	\
	vkErrorManager* manager = vkErrorManager::InstancePtr(); \
	if (manager != 0) { \
		manager->BackupLastSystemError(); }\
	return errSysCallFailed; \
}


#define VK_THROW_SYSCALLFAILED_EX(iMessage)	\
{	\
	vkErrorManager* manager = vkErrorManager::InstancePtr(); \
	if (manager == 0) return errSysCallFailed; \
	int32 sysError = manager->GetLastSystemError();	\
	manager->BackupLastSystemError(sysError);	\
	vkString str(vkCharacter::eDefaultEncoding,100,true,vkHeapManager::IsInitialized()?vkString::eDefaultAllocator:vkString::eStdAllocator);	\
	manager->FormatSystemErrorMessage(sysError,str);	\
	vkUTF8Lock lock2(str);	\
	VKLOGE("SYSTEM ERROR (%s) (%s:%u)",iMessage,lock2.CStr(),sysError);	\
	return manager->ThrowError(errSysCallFailed, __FILE__, __LINE__,__FUNCTION__, iMessage); \
}

#define VK_THROW_SYSCALLFAILED_EX2(iSysError,iMessage)	\
{	\
	vkErrorManager* manager = vkErrorManager::InstancePtr(); \
	if (manager == 0) return errSysCallFailed; \
	int32 sysError = manager->GetLastSystemError();	\
	manager->BackupLastSystemError(iSysError);	\
	vkString str(vkCharacter::eDefaultEncoding,100,true,vkHeapManager::IsInitialized()?vkString::eDefaultAllocator:vkString::eStdAllocator);	\
	manager->FormatSystemErrorMessage(iSysError,str);	\
	vkUTF8Lock lock2(str);	\
	VKLOGE("SYSTEM ERROR (%s) (%s:%u)",iMessage,lock2.CStr(),iSysError);	\
	return manager->ThrowError(errSysCallFailed, __FILE__, __LINE__,__FUNCTION__, iMessage); \
}

#else
	/**
	Macro to returns the error value of a function if the function failed.

	Use this macro instead of using VKernel::vkErrorManager::ThrowError, so file, line and function
	are automatically set.

	The message will be the result of VKernel::vkErrorManager::ErrorToString.
	Macro with _NOLOG suffix does not log any message.

	@code
	error GetFileProperties(const vkURI& iURI, Properties& oProperties)
	{
		vkString str;
		if (!iURI.ComputeSystemPath(str)) {
			VK_THROW_ERROR(errInvalidParameter);
		}
			return GetFileProperties(str, oProperties);
		}
	@endcode

	@param iError the error to raise.

	@see VKernel::vkErrorManager::ThrowError

	@ingroup grp_error
	*/
	//@{
	#define VK_THROW_ERROR(iError)
	#define VK_THROW_ERROR_NOLOG(iError)
	//@}

	/**
	Macro to returns the error value of a function if the function failed.
	Same as VK_THROW_ERROR but you can specify your own message.
	Macro with _NOLOG suffix does not log any message.

	@param iError the error to raise.
	@param iMessage the message.
	
	@see VK_THROW_ERROR

	@ingroup grp_error
	*/
	//@{
	#define VK_THROW_ERROR_EX(iError, iMessage)
	#define VK_THROW_ERROR_EX_NOLOG(iError, iMessage)
	//@}

	/**
	Returns true if the error value is errOk.

	@code
		error err = Function();
		if (VK_SUCCEEDED(iError)) {
			return err; // same as returning errOk
		}

		// clean some data
		delete data;

		return err;
	@endcode

	@param iError the error to test.

	@see VK_FAILED, errOk

	@ingroup grp_error
	*/
	#define VK_SUCCEEDED(iError)

	/**
	Returns true if the error value is errOk.

	@code
		error err = Function();
		if (VK_SUCCEEDED(iError)) {
			// clean some data
			delete data;

			return err;
		}

		return err; // same as returning errOk
	@endcode

	@param iError the error to test.

	@see VK_SUCCEEDED, errOk

	@ingroup grp_error
	*/
	#define VK_FAILED(iError)

	/**
	Call the expression and return the error if the expression failed.

	@code
		error Function1()
		{
			...
		}

		error Function2()
		{
			// if Function1 returns something different from errOk
			// the error returned by Function1 is returned here
			VK_RETURN_IF_FAILED(Function1());

			// else Function1 returns errOk ... so nothing is returned.

			DoSomething();

			return errOk;
		}
	@endcode
	
	@param expression The expression to evaluate.

	@ingroup grp_error
	*/
	#define VK_RETURN_IF_FAILED(expression)

	/**
	Call the expression and return an error if the expression failed.

	Same as VK_RETURN_IF_FAILED excepted you can change the error value which is returned.

	@param expression The expression to evaluate.
	@param oError The error to returns if expression failed.

	@see VK_RETURN_IF_FAILED

	@ingroup grp_error
	*/
	#define VK_RETURN_IF_FAILED_EX(expression, oError)

	/**
	Returns an error value if the expression is equal to this error.

	@code
		error Function1(int iValue);

		error Function2(int iValue)
		{
			// if Function1 returns errInvalidState we stop here and returns errInvalidState
			VK_RETURN_IF(errInvalidState,Function1(iValue));

			// else we try something else, for example default value
			VK_RETURN_IF_FAILED(Function1(kDefaultValue));

			return errOk;
		}
	@endcode

	@param iErr The error value to compare the expression with.
	@param expression the expression to evaluate.

	@see VK_RETURN_IF_FAILED

	@ingroup grp_error
	*/
	#define VK_RETURN_IF(iErr, expression)

	/**
	Special macro used to raise VKernel::errSysCallFailed.

	This macro is a bit like VK_THROW_ERROR excepted
		- it backup the last system error (see VKernel::vkErrorManager::GetLastSystemError and VKernel::vkErrorManager::BackupLastSystemError(int32 iError))
		- it log a system error ("SYSTEM ERROR (System error message:value)" using VKernel::vkErrorManager::FormatSystemErrorMessage)
		- it always raise the same error (VKernel::errSysCallFailed)

	Here is sample which works under Microsoft Windows

	@code
		if (!::CreateDirectory(name.,0)) {
			VK_THROW_SYSCALLFAILED();
		}
	@endcode

	@ingroup grp_error
	*/
	#define VK_RETURN_IF_NULL(Expression, ErrCode)

	/**
	Call the expression and returns ErrCode if the expression is NULL.

	@param expression The expression to evaluate.
	@param ErrCode The error to return if expression failed.

	@see VK_RETURN_IF_FAILED

	@ingroup grp_error
	*/
	#define VK_THROW_SYSCALLFAILED()

	/**
	Special macro used to raise VKernel::errSysCallFailed.

	Same as VK_THROW_SYSCALLFAILED excepted the log which was generated looks like: "SYSTEM ERROR (Message) (System error message:value)"

	Here is sample which works under Microsoft Windows

	@code
		if (!::CreateDirectory(name.,0)) {
			VK_THROW_SYSCALLFAILED_EX("CREATEDIRECTORY");
		}
	@endcode

	@param iMessage The message to add to the log.

	@see VK_THROW_SYSCALLFAILED

	@ingroup grp_error
	*/
	#define VK_THROW_SYSCALLFAILED_EX(iMessage)

	/**
	Special macro used to raise VKernel::errSysCallFailed.

	Same as VK_THROW_SYSCALLFAILED excepted the log which was generated looks like: "SYSTEM ERROR (Message) (System error message:value)"

	Here is sample which works under Microsoft Windows

	@code
		if (!::MoveFile(iSrcFileName,iDestFileName)) {
			DWORD werr = vkErrorManager::GetLastSystemError();

			if (IgnoreSystemError(flags,werr)) {
				vkErrorManager::BackupLastSystemError(werr);
				return errSysCallFailed;
			}

			vkString s(vkCharacter::eDefaultEncoding,100,true,vkHeapManager::IsInitialized()?vkString::eDefaultAllocator:vkString::eStdAllocator);
			s << "MOVEFILE (";
			s << iSrcFileName;
			s << vkCharacter::kRParenthesis;
			vkUTF8Lock lock(s);
			VK_THROW_SYSCALLFAILED_EX2(werr,lock.CStr());
		}

		return errOk;
	@endcode

	@param iMessage The message to add to the log.

	@see VK_THROW_SYSCALLFAILED

	@ingroup grp_error
	*/
	#define VK_THROW_SYSCALLFAILED_EX2(iSysError,iMessage)

#endif

#endif // __vkError_h



