#ifndef CATIScriptFunctionCall_h
#define CATIScriptFunctionCall_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "IUnknown.h"
#include "CATScriptLanguage.h"
#include "CATVariant.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"

class CATBaseUnknown;

/**
 * Interface to represent a call to a scripted function.
 * Author: JDU
 */

class CATIScriptFunctionCall : public IUnknown {
	public:

		/**
		 * Executes the function call synchronously.
		 * (the call will block until the script terminates).
   * Caution: If the script uses one of the following methods:
		 * <ul>
		 * <li>Selection.SelectElement2</li>
		 * <li>Selection.SelectElement3</li>
		 * <li>Selection.SelectElement4</li>
		 * <li>Selection.IndicateOrSelectElement2D</li>
		 * <li>Selection.IndicateOrSelectElement3D</li>
		 * </ul>
		 * the current method should not be used otherwise that ran on time-out. See the sample described in the
   * @href CATScriptUtilities#ExecuteScript documentation.
		 */
		virtual HRESULT __stdcall Run() = 0;

		/**
		 * Executes the function call asynchronously 
		 * (the call immediately returns and the script is actually 
		 * invoked when the event loop returns to its idle state).
   * See the sample described in the @href CATScriptUtilities#ExecuteScript documentation.
		 */
		virtual HRESULT __stdcall RunAsynchronous() = 0;

		/**
		 * Returns TRUE if the call is currently running, FALSE otherwise.
		 */
		virtual HRESULT __stdcall IsScriptRunning(
			CATBoolean& oBoolean) = 0;

		/**
		 * Returns the array of parameters which will be passed to the function
		 * call.
		 */
		virtual HRESULT __stdcall GetParameters(
			VARIANT*& oParameters, 
			unsigned int& oSize) = 0;

		/**
		 * Returns the result of the script execution (if any). This method
		 * can only be called once the function call has run.
		 */
		virtual HRESULT __stdcall GetResult(
			VARIANT& oResult) = 0;

		/**
		 * Returns the object which publishes scripting events.
		 */
		virtual HRESULT __stdcall GetPublisher(
			CATBaseUnknown*& oPublisher) = 0;

		/**
		 * Returns true when the call cannot be made
		 * because the program being called is no
		 * longer valid.
		 */
		virtual HRESULT __stdcall IsZombied(
			CATBoolean& oZombied) = 0;
        
        /**
		 * Customize undoability behavior for the function call.
         * WARNING: overrides user setting (GeneralPCS -> UndoMacro).
		 */
		virtual HRESULT __stdcall SetUndoable(CATBoolean iUndoable) = 0;
        
        /**
         * Remove any customization of undoability behavior for the function call.
         * Undoability behavior is according to user setting (GeneralPCS -> UndoMacro).
         */
        virtual HRESULT __stdcall UnsetUndoable() = 0;
};

extern "C" const IID IID_CATIScriptFunctionCall;

#endif
