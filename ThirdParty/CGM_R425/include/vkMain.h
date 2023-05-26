/**
@file

This file defines the static function that any application
should implement as a startup routine.

@COPYRIGHT

@author Gerald Guyomard
@author Nicolas Hognon.
*/

#if !defined(__vkMain_h)
#define __vkMain_h


#include "vkKernelLib.h"
#include "vkString.h"
#include "vkArray.h"
#include "vkError.h"
#include "vkRefPtr.h"
#include "vkContext.h"

namespace VKernel
{
	class vkType;
	class vkTypeManager;

	class vkAsset;
	typedef vkRefPtr<vkAsset> vkAssetPtr;

	/**
	Parameters used to configure an application.
	
	Main parameters are used mainly with the vkMain() function which is the entry
	point of a application (a program).

	@see vkMain

	
	*/
	class VKKERNEL_API vkMainParameters : /*public vkHeapObject, */public vkContextedObject
	{
	public:

		/**
		Represents a parameter.

		A parameter has the following syntax:
			- "-parameterName=parameterValue"
			- "-parameterName"
			- or simply "parameterName".

		Where '-' is the parameter prefix defined by kParameterPrefix and '=' is the 
		separator between a parameter name and a parameter value defined by
		kParameterValueSeparator. Note that there is no spaces between kParameterPrefix,
		the parameter name, kParameterValueSeparator and the parameter value.

		@see vkMainParameters::AddParameter
		*/
		class Parameter
		{
		public:

			/**
			The parameter name.

			The parameter name does not contains the kParameterPrefix.
			*/
			vkString								name;

			/**
			The parameter value(s).

			Values can be an empty array and can contains empty strings.
			*/
			vkArray<vkString, vkStandardAllocator>	values;

			/**
			Type Declaration.
			*/
			static vkType* RegisterType(vkTypeManager& iTm);

		private:
			typedef Parameter ThisClass;
		};

		/**
		Constant iterator used to inspect the parameters (read-only).

		@see Begin, End
		*/
		typedef vkArray<Parameter, vkStandardAllocator>::ConstIterator	ParamConstIterator;

		/**
		Prefix character of a parameter.

		@see AddParameter
		*/
		static const vkCharacter kParameterPrefix;

		/**
		Separator character between a parameter name and a parameter value.

		@see AddParameter
		*/
		static const vkCharacter kParameterValueSeparator;

		/**
		Constructor.
		*/
		vkMainParameters(vkCtx iCtx);

		/**
		Retrieves the application name.

		@see SetApplicationName
		*/
		const vkString& GetApplicationName() const;
	
		/**
		Retrieves the internal product name.
		*/
		const vkString GetInternalProductName() const;

		/**
		Set the internal product name
		*/
		void SetInternalProductName(const vkString& iInternalName);

		/**
		Set the application name.

		This function is automatically called by the main function defined
		in vkStandAlone library.

		@param iName the name of the application executable file.

		@see GetApplicationName
		*/
		void SetApplicationName(const vkString& iName);

		/**
		Add a parameter

		A parameter can has the following syntax:
			- "-parameterName=parameterValue"
			- "-parameterName"
			- or simply "parameterName".

		Where '-' is the parameter prefix defined by kParameterPrefix and '=' is the 
		separator between a parameter name and a parameter value defined by
		kParameterValueSeparator. Note that there is no spaces between kParameterPrefix,
		the parameter name, kParameterValueSeparator and the parameter value.

		This function is automatically called by the main function defined
		in vkStandAlone library.

		@param iParameter the name of the parameter.

		@see IsParameter, GetValue, GetValues
		*/
		void AddParameter(const vkString& iParameter);

		/**
		Returns true if iParameter is one of the parameter of the current object.

		@param iParameter the name of the parameter.

		@see AddParameter, GetValue, GetValues
		*/
		bool IsParameter(const vkString& iParameter) const;

		/**
		Gets the value of a parameter in the list.

		oValue can be an empty string even if true is returned. If there is
		more than one parameter which name is iParameterName, oValue will be
		the value of the first parameter which name is iParameterName.

		@param iParameterName the name of the parameter.
		@param oValue the value of the parameter.

		@return error code

		@see GetValues, IsParameter, AddParameter
		*/
		error GetValue(const vkString& iParameterName, vkString& oValue) const;

		/**
		Gets the value in the desired type.
		@param iParameterName the name of the parameter.
		@param oValue the value of the parameter.
		@return error code
		*/
		template <class TValue> error GetValue(const vkString& iParameterName, TValue& oValue) const;

		/**
		Gets the values of a parameter in the list.

		oValues can contains empty strings, even if true is returned.

		@param iParameterName the name of the parameter.
		@param oValues the values of the parameter (to support more than one parameter with the same name).

		@return true if the parameter was found.

		@see GetValue, IsParameter, AddParameter
		*/
		error GetValues(const vkString& iParameterName, vkArray<vkString>& oValues) const;

		/**
		Gets a const iterator pointing to the first parameter.

		@return a const iterator on the first parameter.

		
		@code
			vkString nameToCheck;
			vkString valueToCheck;

			const vkMainParameters* params = vkMainParameters::GetMainParameters();
			for (vkMainParameters::ParamConstIterator it=params->Begin();it!=params->End();++it) {
				if ((*it).name==nameToCheck && (!(*it).values.IsEmpty() && (*it).values[0]==valueToCheck)) {
					return true;
				}
			}
		@endcode

		@see End
		*/
		ParamConstIterator Begin() const;

		/**
		Gets a const iterator after the last parameter.

		@return a const iterator after the last parameter.

		
		@code
			vkString nameToCheck;
			vkString valueToCheck;

			const vkMainParameters* params = vkMainParameters::GetMainParameters();
			for (vkMainParameters::ParamConstIterator it=params->Begin();it!=params->End();++it) {
				if ((*it).name==nameToCheck && (!(*it).values.IsEmpty() && (*it).values[0]==valueToCheck)) {
					return true;
				}
			}
		@endcode

		@see Begin
		*/
		ParamConstIterator End() const;
		
		/**
		Builds the command line.
		@param oCommandLine in output, the list of uris
		@return true if the returned array is not empty
		*/
		error BuildCommandLine(vkString& oCommandLine) const;

		/**
		Builds a parameter list, ready to be passed to a shell
		@param oParams in output, the list of parameters
		@return errOk is no error occurred
		*/
		error BuildParameterList(vkArray<vkString>& oParams) const;

		/**
		Builds a parameter string, ready to be passed to a shell
		@param oParams in output, the string for the list of parameters
		@return errOk is no error occurred
		*/
		error BuildParameterString(vkString& oParams) const;

		/**
		Retrieve the main parameters of the application.

		This static function is used to retrieve the main parameters
		of the application, the same main parameters passed to the vkMain function.
		@param iCtx the context where the parameters live
		@see vkMain
		*/
		static const vkMainParameters* GetMainParameters(vkCtx iCtx);

		/**
		Copies all the main parameters from one context to another one.
		It's not possible to override parameters of context kMainCtx
		@param iDstCtx the destination context
		@param iSrcCtx the source context
		*/
		static error CopyMainParameters(vkCtx iDstCtx, vkCtx iSrcCtx);

		#if !defined(VK_DOXYGEN)
			// log information about main parameters, used by the real main funtion (from vkStandAlone)
			void Log() const;
			// initialize main parameters static data
			static void Initialize();
			// used by the real main function (from vkStandAlone) to set the main parameters
			static void SetMainParameters(vkCtx iCtx, const vkMainParameters& iParameters);
		#endif // VK_DOXYGEN

		void Clear();

		/**
		Type Declaration.
		*/
		static vkCtxTypePtr	s_Type;
		static void		RegisterType(vkTypeManager& iTm);

	private:
		typedef vkMainParameters ThisClass;
		typedef vkArray<Parameter, vkStandardAllocator>				Parameters;
		typedef vkArray<Parameter, vkStandardAllocator>::Iterator	ParamIterator;
		Parameters	m_Parameters;		// Parameters of the application. The first element is the name of the application

		static vkCtxObject<const vkMainParameters*>	s_MainParameters;

		vkString	m_AppName;
		vkString	m_InternalAppName;

		vkMainParameters(vkCtx iCtx, const vkMainParameters& iOther);
		void _AddParameter(const vkString& iParameterName, const vkString& iParameterValue);

		friend class vkKernelModule;
		static void _Terminate(vkCtx iCtx);
	};

	VK_INLINE const vkString&
	vkMainParameters::GetApplicationName() const
	{
		return m_AppName;
	}
	
	template <class TValue>
		error
		vkMainParameters::GetValue(const vkString& iParameterName, TValue& oValue) const
	{
		vkString value;
		VK_RETURN_IF_FAILED(GetValue(iParameterName, value));
		return value.To(oValue);
	}
	
} // End of namespace VKernel

/**
Startup Routine.

This is called <b>prior</b> vkKernelModule::Init() and vkMain. It is the good
place to initialize anything that should be initialize before the vkKernel module is
initialized (see vkLog::SetInitFlags, vkKernelModule::SetAllocatorFunctions).

@return Error code.

@see error, vkMain
*/
extern VKernel::error vkStartup();

/**
Shutdown Routine

This is called <b>after</b> vkMain and vkKernelModule::Uninit()

@return Error code.

@see error, vkMain
*/
extern VKernel::error vkShutdown();

/**
Tells whether the application must warn the user when exiting with 
an error code different from errOk.

@return true if the application must warn the user.
*/
extern bool vkIsErrorHandlerEnabled();

/**
Startup and shutdown Routine default implementation.

Use this macro to implement the default implementation
of the startup and shutdown routine. The default implementation does
nothing (simply returns VKernel::errOk).

@see vkMain, vkStartup, vkShutdown
*/
#if defined(VK_DOXYGEN)
	#define VK_IMPLEMENT_DEFAULT_STARTUP_SHUTDOWN()
	#define VK_IMPLEMENT_LICENSED_STARTUP_SHUTDOWN(classname)
#else
	#define VK_IMPLEMENT_DEFAULT_STARTUP_SHUTDOWN() \
		VKernel::error vkStartup() { return VKernel::errOk; } \
		VKernel::error vkShutdown() { return VKernel::errOk; } \
		bool vkIsErrorHandlerEnabled() { return true; } 
	#define VK_IMPLEMENT_LICENSED_STARTUP_SHUTDOWN() \
		VKernel::error vkStartup() { return VKernel::errOk; } \
		VKernel::error vkShutdown() { return VKernel::errOk; } \
		static bool s_IsErrorHandlerEnabled = true; \
		bool vkIsErrorHandlerEnabled() { return s_IsErrorHandlerEnabled; } 
#endif

/**
Entry point of any application.

Unique main routine that must be implemented in application.

This function must be defined outside of any namespace for dll-linking.
You also need to <b>link your program with the vkStandAlone static library</b> which goals
is to implement the entry point depending on your platform (WinMain, main, ...)
and to call the vkMain function which is platform independent.

Basically a main function looks like:

@code
int main(int argc, char* argv[])
{
	error ret = errOk;
	{
		vkMainParameters params;
		// here we compute the main parameters using argc/argv
		// then we set the main parameters so you can retrieve it with 
		// vkMainParameters::GetMainParameters

		// we call vkStartup to perform initialization before vkKernelModule::Initialize
		VK_RETURN_IF_FAILED(vkStartup())

		// call vkKernelModule::Initialize
		// but you do not forget to call other module initialization (in vkMain and/or
		// other module initialization methods).
		VK_RETURN_IF_FAILED(vkKernelModule::Init());

		// now we call the vkMain functions.
		ret = ::vkMain(params);
	}

	// call vkKernelModule::Uninitialize
	// but you do not forget to call other module uninitialization (in vkMain and/or
	// other module initialization methods).
	VK_RETURN_IF_FAILED(vkKernelModule::Uninit());

	// we call vkShutdown to perform uninitialization after vkKernelModule::Uninitialize
	VK_RETURN_IF_FAILED(vkShutdown());

	return ret;
}
@endcode

@param iParameters the main parameters.

@return VKernel::errOk if OK.

@see vkMainParameters
*/
extern VKernel::error vkMain(VKernel::vkCtx iCtx/*const VKernel::vkMainParameters& iParameters*/);
extern bool vkMainStep(VKernel::vkCtx iCtx, VKernel::error& oReturnValue);

#endif // __vkMain_h


