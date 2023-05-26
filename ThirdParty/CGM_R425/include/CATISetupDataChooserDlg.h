#ifndef CATISetupDataChooserDlg_h
#define CATISetupDataChooserDlg_h

// COPYRIGHT Dassault Systemes 2007

// System framework
#include "CATBaseUnknown.h"

// KnowledgeInterfaces framework
#include "CATLifSpecs.h"
#include "CATIKweAppResourceSubItem.h"
#include "CATListOfCATIKweAppResourceSubItem.h"

class CATDlgDialog;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATISetupDataChooserDlg;
#else
extern "C" const IID IID_CATISetupDataChooserDlg;
#endif

/**
 * Interface used to manipulate the interactive dialog displayed to choose a Setup Data
 * item among a list of CATIKweAppResourceSubItem. 
 * Use the method CATISetupDataChooserDlgFactory::CreateChooserDlg to create a new 
 * instance of CATISetupDataChooserDlg.
 * @see CATISetupDataChooserDlgFactory
 */
class ExportedByCATLifSpecs CATISetupDataChooserDlg : public CATBaseUnknown
{
	CATDeclareInterface;
	
  public:

	  /**
	   * Returns the editor dialog.
	   * Use this method to show/hide the dialog and to subscribe callbacks to 
	   * the OK, Cancel and Close notifications.
	   */
	  virtual CATDlgDialog * GetEditorDialog() = 0;

	  /**
	   * Returns the selected resource sub item.
	   */
	  virtual CATIKweAppResourceSubItem_var GetSelectedItem() = 0;

	  /**
	   * Returns the list of selected resource sub items.
	   */
	  virtual HRESULT GetSelectedItems(CATListOfCATIKweAppResourceSubItem& oItems) = 0;
};

CATDeclareHandler(CATISetupDataChooserDlg, CATBaseUnknown);

#endif // CATISetupDataChooserDlg_h

