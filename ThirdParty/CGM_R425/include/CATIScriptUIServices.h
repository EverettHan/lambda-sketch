#ifndef CATIScriptUIServices_h
#define CATIScriptUIServices_h

// COPYRIGHT DASSAULT SYSTEMES 2001

#include "IUnknown.h"
#include "CATBoolean.h"

class CATIScriptEditor;
class CATIScriptContainer;
class CATIScriptProgram;
class CATDialog;
class CATIScriptContainers;
class CATScriptRef;

/**
 * Interface to provide access to the scripting UI.
 * @author: Jean-Francois Doue (JDU)
 */
class CATIScriptUIServices : public IUnknown {
	public:

		/**
		 * Returns an editor suitable for editing the supplied
		 * program reference.
		 */
		virtual HRESULT __stdcall GetScriptEditor(
			CATScriptRef* iProgramRef,
			CATIScriptEditor*& oEditor) = 0;

		/**
		 * Runs a modal error panel to display the current
		 * error to the user. This consumes the underlying
		 * CATError.
		 */
		virtual HRESULT __stdcall RunErrorPanel(
			HRESULT iErrorCode,
			CATDialog* iParentDialog) = 0;

		/**
		 * Returns the list of containers displayed in the UI.
		 */
		virtual HRESULT __stdcall GetCurrentContainers(
			CATIScriptContainers*& oContainers) = 0;

		/**
		 * Returns the container currently selected in the UI.
		 */
		virtual HRESULT __stdcall GetCurrentContainer(
			CATIScriptContainer*& oContainer) = 0;

		/**
		 * Returns the program currently selected in the UI.
		 */
		virtual HRESULT __stdcall GetCurrentProgram(
			CATIScriptProgram*& oProgram) = 0;

    /**
		 * Enables or disables the update of the display during the script replay.
		 */
		virtual HRESULT __stdcall EnableDisplayRefresh(CATBoolean iRefreshIsEnabled) = 0;

    /**
		 * Returns whether the display is updated during the script replay or not.
		 */
		virtual CATBoolean __stdcall IsDisplayRefreshEnabled() = 0;

};

extern "C" const IID IID_CATIScriptUIServices;

#endif // CATIScriptUIServices_h

