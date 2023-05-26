#ifndef CATIScriptEditor_h
#define CATIScriptEditor_h

// COPYRIGHT DASSAULT SYSTEMES 2001

#include "IUnknown.h"
#include "CATBoolean.h"

class CATDialog;

/**
 * Interface to a script editor. The script
 * editor is bound to a script container and
 * a script program at creation time.
 * @author: Jean-Francois Doue (JDU)
 */
class CATIScriptEditor : public IUnknown {
	public:

		/**
		 * Runs the script editor.
		 * @param iParentWindow
		 * the parent Dialog.
		 * @param iLine
		 * the line number the script editor should select. If the
		 * supplied line number less than or equal to 0, nothing is selected.
		 */
		virtual HRESULT __stdcall RunEditor(
			CATDialog *iParentWindow,
			int iSelectedLine) = 0;

		/**
		 * Returns TRUE if the editor runs modally, FALSE if it
		 * runs in its own idenpendent window.
		 */
		virtual HRESULT __stdcall IsModal(CATBoolean& oIsModal) = 0;
};

extern "C" const IID IID_CATIScriptEditor;

#endif // CATIScriptEditor_h

