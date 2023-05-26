#ifndef CATIScriptForm_h
#define CATIScriptForm_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "IUnknown.h"
#include "CATScriptLanguage.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"

class CATScriptRef;

/**
 * Interface to represent a scripted form, such as
 * the a Microsoft VBA MS-Form.
 * Author: JDU
 */

class CATIScriptForm : public IUnknown {
	public:

		/**
		 * Returns the form name
		 */
		virtual HRESULT __stdcall GetName(
			CATUnicodeString& oFormName) = 0;

		/**
		 * Returns <tt>TRUE</tt> if the form cannot be modified.
		 */
		virtual HRESULT __stdcall IsReadOnly(
			CATBoolean& oReadOnly) = 0;

		/**
		 * Returns the scripting language used.
		 */
		virtual HRESULT __stdcall GetLanguage(
			CATScriptLanguage& oLanguage) = 0;

		/**
		 * Runs the form asynchronously.
		 * (the call immediately returns and the form is actually 
		 * displayed and run when the event loop returns to its idle state).
		 */
		virtual HRESULT __stdcall Display() = 0;

		/**
		 * Returns a reference object which identifies the form.
		 */
		virtual HRESULT __stdcall GetReference(
			CATScriptRef*& oReference) = 0;

		/**
		 * Returns true when the form has been deleted or
		 * when the container which contains the form 
		 * has been closed and the form cannot be used any more.
		 */
		virtual HRESULT __stdcall IsZombied(
			CATBoolean& oZombied) = 0;
};

extern "C" const IID IID_CATIScriptForm;

#endif
