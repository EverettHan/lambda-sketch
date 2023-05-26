#ifndef CATIVBAProgram_h
#define CATIVBAProgram_h

#include "CATVBACodeMacro.h"
#if defined(_WINDOWS_SOURCE) && (!defined(_DS_VBAIntegrationIsOutProcess)) // -JBX 3.2012 VBA7 Migration 

// COPYRIGHT DASSAULT SYSTEMES 2005

#include "VBAAfx.h"
#include "IUnknown.h"
#include "CATBoolean.h"

/**
 * Interface used to manage VBA program.
 */
class CATIVBAProgram : public IUnknown {

	public:

		/**
		 * Returns the name of the script program.
		 */
		virtual HRESULT GetName(
			CString& oName) = 0;

		/**
		 * Returns <tt>TRUE</tt> if the program cannot be modified.
		 */
		virtual HRESULT IsReadOnly(
			CATBoolean& oReadOnly) = 0;

		/**
		 * Get the script text.
		 */
		virtual HRESULT GetScriptText(
			CString& oScriptText) = 0;

    /**
		 * Sets the script text for the program.
		 */
		virtual HRESULT SetScriptText(
			const CString& iScriptText) = 0;

		/**
		 * Returns true when the program has been deleted or
		 * when the container which contains the program 
		 * has been closed and the program cannot be used any more.
		 */
		virtual HRESULT IsZombied(
			CATBoolean& oZombied) = 0;

		/**
		 * Retrieve the IDispatch pointer representing the VBA program.
		 */
		virtual HRESULT GetIDispatch(IDispatch *& oDispatch) = 0;
		
		/**
		 * Runs the specified function or subroutine, passing the specified parameters.
		 * In case of failure, the error source and error description are set.
		 */
		virtual HRESULT Run(
			BSTR iName, 
			SAFEARRAY ** iArguments, 
			VARIANT * oReturnValue, 
			BSTR * oErrorSource, 
			BSTR* oErrorDescription) = 0;

		/**
		 * Shows the VBA program code by displaying the VBA IDE.
		 */
		virtual HRESULT ShowCode() = 0;

};

extern "C" const IID IID_CATIVBAProgram;

#endif // #if defined(_WINDOWS_SOURCE) && (!defined(_DS_VBAIntegrationIsOutProcess)) // -JBX 3.2012 VBA7 Migration 

#endif // CATIVBAProgram_h
