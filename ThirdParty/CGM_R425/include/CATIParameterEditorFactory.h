// COPYRIGHT Dassault Systemes 2001
#ifndef CATIParameterEditorFactory_H
#define CATIParameterEditorFactory_H

#include "KnowledgeItf.h"
#include "CATBaseUnknown.h"

#include "CATString.h"
#include "CATIParameterEditor.h"
#include "CATBoolean.h"

class CATDialog;

#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATIParameterEditorFactory ;
#else
extern "C" const IID IID_CATIParameterEditorFactory ;
#endif

//------------------------------------------------------------------

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */

/*  CAA2Reviewed by FRH */

/**
* Interface giving access to a factory for standard parameters editors.
* <b>Role</b>: It is implemented as an extension of CATApplicationFrame and CATInteractiveApplication object (you can use either one of them depending on the context)
* and is used to obtain a parameter editor.
* It concerns only the following parameters: literal and volatile value.
* @see CATIParameterEditor, CATICkeParm
*/
class ExportedByKnowledgeItf CATIParameterEditorFactory: public CATBaseUnknown
{
	CATDeclareInterface;
	
public:
	
/**
* Creates a standard parameter edition frame in a dialog.<br>
* The caller has to manage grids layouts in the dialog by retrieving the underlying frame
* on CATIParameterEditor interface and to call the SetEditedParameter method of CATIParameterEditor 
* to pass the edited parameter
* <dl>
* <dt><b>Example:</b>
* <pre>
* CATApplicationFrame *pApplicationFrame = CATApplicationFrame::GetFrame();
* CATIParameterEditorFactory *poEditorFactory = NULL;
* HRESULT hr = pApplicationFrame->QueryInterface(CATIParameterEditorFactory::ClassId(), (void**) &poEditorFactory);
* if (SUCCEEDED(hr))
* {
*  	 CATIParameterEditor *poParmEditor = NULL;
*  	 hr = poEditorFactory->CreateParameterEditor(iParent, iName, 1, poParmEditor);
*  	 if (SUCCEEDED(hr))
*  	 {
*  	 	 poParmEditor->SetParameter(iParameter);
*  	 	 CATDlgFrame *pFrame = poParmEditor->GetFrame();
*  	 	 pFrame->SetGridConstraints(...
*  	 	 ...
*  	 	 poParmEditor->Release();
* 	 }
*  	 poEditorFactory->Release();
* }
* </pre>
* </dl>
*       
* @param iParent
* The parent dialog. Must not be NULL
* @param iName
* The name of the frame built by this method
* @param iWithContextualMenu
* A flag to indicate wether a contextual menu is to be added
* @param oParameterEditor
* A pointer to the CATIParameterEditor interface on the created parameter editor
* @return
* E_FAIL if iParent is NULL or if iName is empty, and S_OK otherwise
*/
	virtual HRESULT CreateParameterEditor(const CATDialog *iParent, const CATString &iName, CATBoolean iWithContextualMenu, CATIParameterEditor *& oParameterEditor) = 0;
};

//------------------------------------------------------------------

#endif
