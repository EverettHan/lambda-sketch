#ifndef CATEditor_h
#define CATEditor_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATAfrProperties.h"
#include "CATEventSubscriber.h"
#include <CATUnicodeString.h>
#include "PropertyMode.h"
#include "CATListOfCATString.h"
#include "CATLISTP_CATEditorPage.h"
#include "CATString.h"
#include "CATBoolean.h"

class CATEditorPage;
class CATCommandGlobalUndo;
class CATDocument;
class CATSettingRepository;
class CATISysSettingController;

/**
 * Class to define an editor called by the PropertyEditor.
 */
class ExportedByCATAfrProperties CATEditor : public CATEventSubscriber 
{

  CATDeclareKindOf;

 public:

  /**
  * Constructs the editor.
  */
  CATEditor();
  virtual ~CATEditor();

/**
 * Constructs the dialog objects of the editor.
 */
  virtual void BuildEditor(CATEditorPage * iPage) = 0 ;

  /**
  * @nodoc	
  */
   virtual void BuildMultiEditors(CATLISTP(CATEditorPage) * iListOfPages);

/**
 * Method to close dialog object open by the editor.
 */
  virtual void CloseWindowFromEditor();
  /**
    ** Peut-être à mettre en R10 - voir avec JBT. Le besoin est la prise dynamique de 
    * licences.
    * @nodoc
    * Closes secondary dialog objects.
    * <br><b>Role</b>: In the case that the dialog object associated with
    * the property sheets creates a secondary window,
    * this method must provide a way to close it.
    * In addition to that, the editor can dispatch a notification: this method 
    * has to be used only for dynamic licencing purposes.
    *
    virtual HRESULT CloseWindowFromEditorAtExit(CATBoolean iValue) = 0;
    ***/

/**
 * Method to give a name to the editor.
 */
  virtual CATUnicodeString  GetEditorTitle();


  /**
  * @nodoc	
  */
  virtual CATListOfCATUnicodeString GetSubEditors(CATLISTV(CATBaseUnknown_var)& iExtract);

  /**
  * Valuates the dialog objects of the editor.
  */
  virtual void SetPropertyValue ( CATLISTV(CATBaseUnknown_var)& iExtract,
				   ModeReadWrite iMode );

  /**
  * Valuates the dialog objects of the Tools Option editor.
  * @param iRep 
  *      not used.
  */
  virtual void SetUserSettingsValue (CATSettingRepository * iRep);

  /**
  * Resets all values of repositories.
  */
  virtual void ResetUserSettingsValue ();
  
  /**
  * Saves properties modifications for all the selection.
  * @param iExtract
  *       list of concerned objects with the modification.
  */
  virtual void CommitModification( CATLISTV(CATBaseUnknown_var)& iExtract );

  /**
  * Saves settings modifications.
  * @param iRep 
  *      not used.
  * <br><b> careful: </b> you need to get the repository by yourself
  *  by GetRepository method, don't try to use iRep directly
  * @see CATSettingRepository
  */
  virtual void CommitModification(CATSettingRepository *iRep);

  /**
  * Cancels a modification when closing the panel.
  * @param iExtract
  *      list of concerned objects with the modification.
  */
  virtual void CancelModification( CATLISTV(CATBaseUnknown_var)& iExtract );
	
  /**
  * Cancels settings modification.
  * @param iRep 
  *      not used. 
  * <br><b> careful: </b> you need to get the repository by yourself
  *  by GetRepository method, don't try to use iRep directly
  * @see CATSettingRepository
  */
  virtual void CancelModification(CATSettingRepository *iRep);

	/**
	* Sets the behaviour of the dialog objects during the update of tabpages when applying modifications.
    * Useful for tab pages depending on each other
	* @param oStatus
	* <br><b> Legal Values : </b>
	*     <tt> 0 if no repaint is required : for each tabpage, methods CommitModification and SetPropertyValue are called one after the other 
	*     <tt> 1 otherwise : default behaviour - for each tabpage method CommitModification is applied. Then, for each tabpage method SetPropertyValue is called. 
	*/
  virtual HRESULT OKToRepaintOnCommit(int& oStatus);

	/**
	* Sets the behaviour of the dialog objects when applying modifications by OK.
	* @param oStatus
	* <br><b> Legal Values : </b>
	*     <tt> FALSE : SetPropertyValue method is not called after OK is pressed. 
	*     <tt> TRUE otherwise : default behaviour - SetPropertyValue method is called when APPLY or/and OK are pressed. 
	*/
  virtual HRESULT ValuePropertyOnOK(CATBoolean& oStatus);

  /**
  * Method to make a query on the selection for acceptance.
  */
  virtual void ExtractFromSelection ( CATLISTV(CATBaseUnknown_var)& iExtract,
				       const CATLISTV(CATBaseUnknown_var) * iSelection =NULL );
  
  /**
  * @nodoc	
  */
  virtual int QueryAcceptDocument (const CATDocument * doc);

/**
 * Allows to choose the size you need to accommodate the page. 
 * @param iSize
 	* <br><b> Legal Values : </b>
	*     <tt> 1 for small size: 250x460 using Windows or 294x533 using Unix. 
	*     <tt> 2 for large size: 415x425 using Windows or 500x496 using Unix.
 */
  virtual void SetEditorSize(int & iSize );


 /**
  * Returns the list of unexpected tab pages.
  */
 CATListOfCATString GetListOfUnexpectedTabpages();
  
 /**
 * Method to record an undo action from the editor.
 */
  virtual CATCommandGlobalUndo * GetUndoFromEditor();

 /**
 * Method to Check if all the property values are OK. 
  * @param oStatus
 	* <br><b> Legal Values : </b>
	*     <tt> FALSE : if any value is incorrect
	*     <tt> TRUE : If the values are proper
 */ 
  virtual HRESULT CheckPropertyValues(CATBoolean& oStatus);
};


#endif


