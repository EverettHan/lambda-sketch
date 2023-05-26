#ifndef CATISetupDataChooserDlgFactory_h
#define CATISetupDataChooserDlgFactory_h

// COPYRIGHT Dassault Systemes 2007

// System framework
#include "CATBaseUnknown.h"

// KnowledgeInterfaces framework
#include "CATLifSpecs.h"
#include "CATISetupDataChooserDlg.h"
#include "CATListOfCATIKweAppResourceSubItem.h"
#include "CatKweAppRscItemType.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATISetupDataChooserDlgFactory;
#else
extern "C" const IID IID_CATISetupDataChooserDlgFactory;
#endif

class CATDialog;
class CATString;

// Different flags for the Setup Data Chooser dialog
#define CATSetupDataDlgWithPLMChooser       (1<<0)  // Shows the PLM Chooser button
#define CATSetupDataDlgMultipleSelection    (1<<1)  // Allows multiple selection
#define CATSetupDataDlgWithoutPreview	    (1<<2)  // Disables the selected resource preview

/**
 * Interface used to create the interactive dialog displayed to choose a Setup Data
 * item among a list of CATIKweAppResourceSubItem. Each CATISetupDataFinder instance implements
 * the interface CATISetupDataChooserDlgFactory.
 * @see CATISetupDataFinder
 * @see CATISetupDataChooserDlg
 */
class ExportedByCATLifSpecs CATISetupDataChooserDlgFactory : public CATBaseUnknown
{
	CATDeclareInterface;
	
  public:

	  /**
	   * Creates a new CATISetupDataChooserDlg instance with the given list of Resource sub items.
	   * @param iParent
	   *   The dialog parent
	   * @param iName
	   *   The dialog name
	   * @param iSubItems
	   *   The list of resource sub items among which the user have to choose.
	   * @param iDisplayMode
	   *   The display mode : this flag can be a combination of the possible display flags
	   *   Possible flags :
	   *     - CATSetupDataDlgWithPLMChooser
	   *     - CATSetupDataDlgMultipleSelection
	   *     - CATSetupDataDlgWithoutPreview
	   */
	  virtual CATISetupDataChooserDlg_var CreateChooserDlg(
				CATDialog * iParent,
				const CATString& iName,
				const CATListOfCATIKweAppResourceSubItem& iSubItems,
				CatKweAppRscItemType iResourceType = CatKweAppRscAnyType,
				int iDisplayMode = 0) = 0;
};

CATDeclareHandler(CATISetupDataChooserDlgFactory, CATBaseUnknown);

#endif // CATISetupDataChooserDlgFactory_h

