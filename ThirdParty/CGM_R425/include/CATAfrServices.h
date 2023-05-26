#ifndef CATAfrServices_H
#define CATAfrServices_H
#include "CATAfrFoundation.h"

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATCommandHeader.h"
#include "CATListOfCATCommandHeader.h"
#include "CATAfrProtectedUIUndoRedoServices.h"

class CATDocument;
class CATFrmEditor;
class CATFrmWindow;
class CATIAfrCtxBarManager;

/**
* Gets the command name as an argument and search it in setting file
* if found delete it from commandlist and delete "framecommand" attribute from
* "frameconfig" setting file
* return False if command name not found
* return True if it found command and delete command successfuly
*/
ExportedByCATAfrFoundation
HRESULT CATAfrRemoveRunTimeHeaderFromSettings(CATUnicodeString  sNameDeleted);


//---------------------------------------------------------------------------
/**
 * Gets the editor associated with a document
 * <br><b>Role</b>: This method returns the @href CATFrmEditor associated
 * with a @href CATDocument, but does not create it if it does not exist yet.
 * @param iDocument
 *  The CATDocument.
 * @param oEditor
 *  The CATFrmEditor.
 * @return
 * Returns S_OK on success. On failure, it returns one of the following
 * error codes :
 * <ul>
 * <li>S_FALSE if no editor is found
 * <li>E_FAIL if iDocument is NULL.
 * </ul>
 * <br><b>Lifecycle rules deviation</b>: No AddRef is performed 
 * on the returned value. 
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetEditorFromDocument (CATDocument * iDocument,
                                     CATFrmEditor *& oEditor);

//---------------------------------------------------------------------------
/** 
* Gives the names of workshops/workbenches/addins currently available.
* <br><b>Role</b>: This function builds a list of unicode strings naming 
* the workshops/workbenches/addins currently available.
* <br>Each string is built following this syntax : <name>|<type>.
* <br><name> is "General" for the global workshop, 
* the unicode title for the current workshop or current workbench,
* or the internal name for an addin (addins do not have NLS titles).
* <br><type> is "Global Workshop", "Global Addin", "Current Workshop", "Workshop Addin",
* "Current Workbench" or "Workbench Addin".
* @return 
*  List of unicode strings built as described.
*/
ExportedByCATAfrFoundation
CATListValCATUnicodeString GetAvailableCommandSets();

/** 
* Gives the names of command headers belonging to a workshop/workbench/addin.
* <br><b>Role</b>: This function returns the list of command header names for a given workshop/workbench/addin.
* @param iAccessId
* <name>|<type> describing the workshop/workbench/addin.
* @return 
*  List of command header names.
*/
ExportedByCATAfrFoundation
CATLISTP(CATCommandHeader) GetAccessCommandHeaders(const CATUnicodeString& iAccessId);

/** 
* Gives the names of the addins of a workshop or a workbench.
* <br><b>Role</b>: This function returns the list of addin names for  a workshop or a workbench
* (implementing the given addin Interface)..
* @param iClassId
*  Class Id of the addin interface to look for.
* @return 
*  List of addin names.
*/
ExportedByCATAfrFoundation
CATListValCATUnicodeString GetAddinNames (CATClassId iClassId);

/** 
* Applies or ignores the availability status on all the command headers created in the current workshop.
*/
ExportedByCATAfrFoundation
  void CATAfrApplyHeaderAvailability (CATAfrAvailabilityType, CATBoolean, CATFrmEditor *pIEditor=NULL, const CATString& iWorkShopName = "" );

/** 
* Applies or ignores the editability availability status on all the command headers created in the current workshop.
*/
ExportedByCATAfrFoundation
void CATAfrApplyApplicativeHeaderAvailability (CATBoolean, CATFrmEditor *pIEditor=NULL);

/**
* Returns the name of the logon or restore panel upper image
*/
ExportedByCATAfrFoundation
CATString GetLogonIconName();

/** 
* Sets/Resets the last part of the application window title.
* @param iTitleEnd
*  String to add to the title.
* @param iAdd
*  True to add a string, False to remove the previously added string.
*/
ExportedByCATAfrFoundation
void CATAfrSetApplicationEndTitle (const CATUnicodeString & iTitleEnd, CATBoolean iAdd);

/** 
* Creates the Start window.
* @param iCoachMark
*  CoachMark display.
* @param iEventDeleted
*  Add event when the window was deleted.
* WARNING : this takes really much time...
* * WARNING : don't use only for Search context
*/
ExportedByCATAfrFoundation void CATAfrCreateorGetStartWindow( CATFrmWindow*& opCreatedWin, const CATBoolean& iCoachMark = TRUE, 
                                                              const CATBoolean& iEventDeleted = TRUE );

/** 
* Display the coachMark component with preference setting.
* @param iForceShow
*  iForceShow is TRUE display the coachMark without preference setting.
*/
ExportedByCATAfrFoundation HRESULT CATAfrDisplayCoachMark( const CATBoolean& iForceShow = FALSE );

/** 
* Send http request.
*/
HRESULT SendRequest( const char* const iServeurName, const char* const iUrl, 
                     const char * const iPostedBuffer, unsigned long iPostedBufferSize, 
                     char** oResultBuffer, size_t* oResultBufferSize );

/** 
* Get responsible trigram (exact output format is Resp:xxx) for a WWA.
* Only active on Windows OS AND if env variable CATAfrTrackWWAResp is set.
* WARNING : this takes really much time...
*/
ExportedByCATAfrFoundation CATString GetWWAResponsible (CATString & iWWAType, CATString & iWWAName);

/**
* Return a pointer on CATIAfrCtxBarManager.
*  @return CATIAfrCtxBarManager
*
* <br><b>Note :</b>
* It makes a QueryInterface(), so a release() is needed after using this method
*/
ExportedByCATAfrFoundation CATIAfrCtxBarManager* GetAfrCtxBarManager();

/** type of setting to retrieve or save*/
enum AfrTypeSetting 
{
  ShowLabel

};
/**
* Return a boxable value related to the settings 
*
*/
ExportedByCATAfrFoundation CATBaseUnknown_var RetrieveSetting(const AfrTypeSetting & setting);

/**
* Sets a boxable value related to the settings 
*
*/
ExportedByCATAfrFoundation void SaveSetting(const AfrTypeSetting & setting, CATBaseUnknown_var value);

/**
* Tells whether User asked the session to terminate (Exit command) 
*
*/
ExportedByCATAfrFoundation CATBoolean CATAfrIsExitInProgress();

/**
 * Show or hide the ActionBar.
 *
 * @param i_showOrHide true to display the ActionBar, false to hide it.
 *
 * @note For ActionBar V2, the ActionBar is collapsed when it is hidden.
 * For ActionBar V3, the ActionBar is set invisible when hidden.
 */
ExportedByCATAfrFoundation void CATAfrShowActionBar(bool i_showOrHide);

/**
 * Returns whether the ActionBar is expanded or collapsed.
 *
 * @return 1 when the ActionBar is expanded, 0 otherwise.
 *
 * @note Deprecated since R421. Use instead CATAfrIsActionBarDisplayed.
 */
ExportedByCATAfrFoundation int CATAfrIsActionBarExpanded();

/**
 * Returns whether the ActionBar is displayed or hidden.
 *
 * @return 1 when the ActionBar is visible, 0 otherwise.
 *
 * @note Since ActionBar V3 activation (R421), prefer using this function
 * instead of CATAfrIsActionBarExpanded.
 */
ExportedByCATAfrFoundation int CATAfrIsActionBarDisplayed();

/**
 * Register a callback to the event dispatched when the ActionBar is expanded
 * or collapsed.
 *
 * @note For ActionBar V2, the event is dispatched when the ActionBar state
 * changes from expanded to collapse (or vice versa).
 * For ActionBar V3, the event is dispatched when the ActionBar state changes
 * from visible to hidden (and vice versa).
 *
 * @param i_pEventSubscriber object that subscribes to the event
 * @param i_methodToCall member function to call when the event will be
 * dispatched
 * @param i_clientData data to associate
 */
ExportedByCATAfrFoundation CATCallback CATAfrRegisterToActionBarExpandStateChanged(CATBaseUnknown * i_pEventSubscriber, CATSubscriberMethod i_methodToCall, CATSubscriberData i_clientData = NULL);

/**
 * Unregister a previously registered callback to the event dispatched when
 * the ActionBar is expanded or collapsed.
 *
 * @see CATAfrRegisterToActionBarExpandStateChanged
 *
 * @param i_pEventSubscriber object that subscribed to the event
 * @param i_callback identifier of the callback to remove.
 */
ExportedByCATAfrFoundation void CATAfrUnregisterToActionBarExpandStateChanged(CATBaseUnknown * i_pEventSubscriber, CATCallback i_callback);

#endif
