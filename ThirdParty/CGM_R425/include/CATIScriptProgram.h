#ifndef CATIScriptProgram_h
#define CATIScriptProgram_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "IUnknown.h"
#include "CATScriptLanguage.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATListOfCATIScriptFunction.h"
#include "CATListOfCATBaseDispatch.h"
#include "CATListOfCATUnicodeString.h"

class CATIScriptFunctionCall;
class CATBaseDispatch;
class CATScriptRef;

/**
 * Interface to represent a macro. A macro can be written in
 * one of several scripting language. It can contain several
 * functions.
 * The script program can contain global variable which
 * refer to existing <tt>CATBaseDispatch</tt> objects.
 * Author: JDU
 */

class CATIScriptProgram : public IUnknown {
	public:

		/**
		 * Returns <tt>TRUE</tt> if the program cannot be modified.
		 */
		virtual HRESULT __stdcall IsReadOnly(
			CATBoolean& oReadOnly) = 0;

		/**
		 * Returns the scripting language used.
		 */
		virtual HRESULT __stdcall GetLanguage(
			CATScriptLanguage& oLanguage) = 0;

		/**
		 * Get the script text.
		 */
		virtual HRESULT __stdcall GetScriptText(
			CATUnicodeString& oScriptText) = 0;

		/**
		 * Get the script functions.
		 */
		virtual HRESULT __stdcall GetFunctions(
			CATListOfCATIScriptFunction& oFunctions) = 0;

		/**
		 * Returns a default function for the program
		 * (ex: CATMain for a BasicScript script).
		 */
		virtual HRESULT __stdcall GetDefaultFunction(
			CATIScriptFunction*& oFunction) = 0;

		/**
		 * Returns an object which can be used to invoke the
		 * scripted function with the supplied array of
		 * parameters. Passing a NULL function pointer
		 * causes the default function to be called.
		 * iAutomaticReplay specifies whether the replay is automatic or
		 * if it is explicitly done from a user interaction.
		 */
		virtual HRESULT __stdcall CreateCall(
			CATIScriptFunction* iFunction,
			VARIANT* iParameters,
			unsigned int iSize,
			CATIScriptFunctionCall*& oFunctionCall,
			CATBoolean iAutomaticReplay = TRUE) = 0;


		/**
		 * Registers an object with the scripting program. The object is registered
		 * under the specified name and is available from the script as a global
		 * variable. If another object is already registered with the same name
		 * that object is replaced by the new object in the registration table.
		 */
		virtual HRESULT __stdcall RegisterObject(
			CATBaseDispatch* iObject, 
			const CATUnicodeString& iObjectName) = 0;

		/**
		 * Removes a registered object from the scripting program.
		 */
		virtual HRESULT __stdcall UnregisterObject(
			CATBaseDispatch* iObject) = 0;

		/**
		 * Returns the objects registered as global variables with the scritping program.
		 */
		virtual HRESULT __stdcall GetRegisteredObjects(
			CATListOfCATUnicodeString& oObjectNames,
			CATListOfCATBaseDispatch& oObjects) = 0;

		/**
		 * Returns a reference object which identifies the program.
		 */
		virtual HRESULT __stdcall GetReference(
			CATScriptRef*& oReference) = 0;

		/**
		 * Returns true when the program has been deleted or
		 * when the container which contains the program 
		 * has been closed and the program cannot be used any more.
		 */
		virtual HRESULT __stdcall IsZombied(
			CATBoolean& oZombied) = 0;

};

extern "C" const IID IID_CATIScriptProgram;

#endif
