#ifndef CATIVBAForm_h
#define CATIVBAForm_h

#include "CATVBACodeMacro.h"
#if defined(_WINDOWS_SOURCE) && (!defined(_DS_VBAIntegrationIsOutProcess)) // -JBX 3.2012 VBA7 Migration 

// COPYRIGHT DASSAULT SYSTEMES 2005

#include "VBAAfx.h"
#include "IUnknown.h"
#include "CATBoolean.h"

/**
 * Interface used to manage VBA form.
 */
class CATIVBAForm : public IUnknown {

	public:

		/**
		 * Returns the form name
		 */
		virtual HRESULT GetName(
			CString& oFormName) = 0;

		/**
		 * Runs the form asynchronously.
		 * (the call immediately returns and the form is actually 
		 * displayed and run when the event loop returns to its idle state).
		 */
		virtual HRESULT Display() = 0;

		/**
		 * Returns <tt>TRUE</tt> if the form cannot be modified.
		 */
		virtual HRESULT IsReadOnly(
			CATBoolean& oReadOnly) = 0;

		/**
		 * Returns true when the form has been deleted or
		 * when the container which contains the form 
		 * has been closed and the form cannot be used any more.
		 */
		virtual HRESULT IsZombied(
			CATBoolean& oZombied) = 0;


};

extern "C" const IID IID_CATIVBAForm;

#endif // #if defined(_WINDOWS_SOURCE) && (!defined(VBAIntegrationIsOtProcess)) // -JBX 3.2012 VBA7 Migration #endif // CATIVBAForm_h
#endif 
