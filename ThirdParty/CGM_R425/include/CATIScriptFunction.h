#ifndef CATIScriptFunction_h
#define CATIScriptFunction_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "IUnknown.h"
#include "CATUnicodeString.h"
#include "CATListOfCATIScriptParameter.h"
#include "CATNTTypes.h"

class CATIScriptParameter;
class CATIFunctionCall;

/**
 * Interface to represent a scripted function.
 * Author: JDU
 */

class CATIScriptFunction : public IUnknown {
	public:

		/**
		 * Returns the name of the function.
		 */
		virtual HRESULT __stdcall GetName(
			CATUnicodeString& oFunctionName) = 0;

		/**
		 * Returns the array of parameters which will be passed to the script.
		 */
		virtual HRESULT __stdcall GetParameters(
			CATListOfCATIScriptParameter& oParameters) = 0;

		/**
		 * Returns the function's return parameter.
		 */
		virtual HRESULT __stdcall GetReturnParameter(
			CATIScriptParameter*& oParameter) = 0;

		/**
		 * Returns the invocation kind of the function.
		 */
		virtual HRESULT __stdcall GetInvKind(
			INVOKEKIND& oInvKind) = 0;

		/**
		 * Returns the flags of the function (hidden, restricted, ...).
		 */
		virtual HRESULT __stdcall GetFlags(
			WORD& oFlags) = 0;

};

extern "C" const IID IID_CATIScriptFunction;

#endif
