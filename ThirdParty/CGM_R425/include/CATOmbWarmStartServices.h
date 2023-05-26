#ifndef CATOmbWarmStartServices_H
#define CATOmbWarmStartServices_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2003

/**
  * @level Protected
  * @usage U1
  */

#include "CATOmbWarmStart.h"
#include "IUnknown.h"
#include "CATBoolean.h"
class CATUnicodeString;

/**
* Services to control the warmstart incremental backup.
* <b>Role:</b> The following static methods are meant to be used by CAA applications which
* want to benefit from the warmstart system. They will provide basic services to test 
* the status of the warmstart and interact with it (activate, deactivate, commit 
* modifications...).  
*/

class ExportedByCATOmbWarmStart CATOmbWarmStartServices
{
 public:

  /**
  * Deactivates the warmstart incremental backup.
  * <br><b>Role:</b> This method should be called in the @href #CATCommand Activate method of 
  * a command when it is known that the command is incompatible with incremental backup.
  * <br>It will stop the warmstart logging and delete all previous logged data.
  * <br>If successful, the caller should display the returned message warning 
  * the user to save his data.
  * Use the following code to call this service and display the user message:
  * <pre>
  *   CATUnicodeString WarningMessage;
  *   HRESULT hr = CATOmbWarmStartServices::<b>Deactivate</b>(WarningMessage);
  *   if( SUCCEEDED(hr) && (0 !=warningMessage.GetLengthInChar()) )
  *   {	
  *      CATApplicationFrame * pFrame = <b>CATApplicationFrame::GetFrame</b>();
  *      if( (NULL!=pFrame) && (NULL!=pFrame->GetMainWindow()) )
  *      {
  *         CATDlgNotify *pNfy = new <b>CATDlgNotify</b>(pFrame->GetMainWindow(), 
  *                                  "AutoSave", 
  *                                  CATDlgNfyInformation|CATDlgNfyOK|CATDlgWndModal);
  *
  *          CATUnicodeString WindowTitle="..";
  *          pNfy-><b>DisplayBlocked</b>(WarningMessage ,WindowTitle);
  *          pNfy->RequestDelayedDestruction();
  *      }
  *   }
  * </pre>
  *
  * @param oWarningMessageToDisplay
  *     The warning message to be displayed to the user if successful (S_OK returned).
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The warmstart was successfully deactivated.</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The deactivation failed, either because warmstart is not available, or it was 
  *          already deactivated.</dd>
  *   </dl>
  */
  static HRESULT Deactivate(CATUnicodeString& oWarningMessageToDisplay);

  /**
  * Deactivates the warmstart incremental backup.
  * <br><b>Role:</b> This method should be called in the @href #CATCommand Activate method of 
  * a command when it is known that the command is incompatible with incremental backup.
  * <br>It will stop the warmstart logging and also, when requested, delete all previous logged data.
  * <br>If successful, the caller should display the returned message warning the user to save his data.
  * <br>Use the following code to call this service and display the user message:
  * <pre>
  *   CATUnicodeString WarningMessage;
  *   int iDeleteLog = 0; // depending user wants to delete or not previously logged data
  *   HRESULT hr = CATOmbWarmStartServices::<b>Deactivate</b>(iDeleteLog, WarningMessage);
  *   if( SUCCEEDED(hr) && (0 !=warningMessage.GetLengthInChar()) )
  *   {	
  *      CATApplicationFrame * pFrame = <b>CATApplicationFrame::GetFrame</b>();
  *      if( (NULL!=pFrame) && (NULL!=pFrame->GetMainWindow()) )
  *      {
  *         CATDlgNotify *pNfy = new <b>CATDlgNotify</b>(pFrame->GetMainWindow(), 
  *                                  "AutoSave", 
  *                                  CATDlgNfyInformation|CATDlgNfyOK|CATDlgWndModal);
  *
  *          CATUnicodeString WindowTitle="..";
  *          pNfy-><b>DisplayBlocked</b>(WarningMessage ,WindowTitle);
  *          pNfy->RequestDelayedDestruction();
  *      }
  *   }
  * </pre>
  *
  * @param iDeleteLog
  *     Delete when requested the previously logged data at deactivation time.
  * <ul>
  *     <li>FALSE: Logged data remain until next incremental backup activation.
  *     <br>If a crash occurs after deactivation, all commands preceeding deactivated one will be restored.</li>
  *     <li>TRUE: Logged data are deleted at deactivation time.
  *     <br>If a crash occurs after deactivation, none of the commands preceeding deactivated one will be restored.
  *     <br>User should save all data before processing deactivated command.</li>
  * </ul>
  *
  * @param oWarningMessageToDisplay
  *     The warning message to be displayed to the user if successful (S_OK returned).
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The warmstart was successfully deactivated.</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The deactivation failed, either because warmstart is not available, or it was 
  *          already deactivated.</dd>
  *   </dl>
  */
  static HRESULT Deactivate(CATBoolean iDeleteLog, CATUnicodeString& oWarningMessageToDisplay);

  /**
  * Activates or re-initialises the warmstart incremental backup.
  * <br><b>Role:</b> This method should be called in commands saving or closing documents.
  * It will succeed only if none of the open documents is dirty (aka modified and not saved).
  * If the warmstart was previously:
  * <ul>
  *  <li>deactivated, it will be reactivated: a copy of each loaded V5 documents 
  *    will be done, and log files will be created.</li>
  *  <li>Already activated, it will be re-initialized. A copy of each loaded V5 documents 
  *    is done, and the backup data files are emptied.</li>
  * </ul>
  * <br>If successful, the caller should display the returned warning message. Use the following 
  * code to call this service and display the user message:
  * <pre>
  *   CATUnicodeString WarningMessage;
  *   HRESULT hr = CATOmbWarmStartServices::Activate(WarningMessage);
  *   if( SUCCEEDED(hr) && (0!=WarningMessage.GetLengthInChar()) )
  *   {	
  *      CATApplicationFrame *pFrame = CATApplicationFrame::GetFrame();
  *      if( (NULL!=pFrame) && (NULL!=pFrame->GetMainWindow()) )
  *      {
  *         CATDlgNotify *pNfy = new CATDlgNotify(pFrame->GetMainWindow(), 
  *                                "AutoSave", 
  *                                CATDlgNfyInformation|CATDlgNfyOK|CATDlgWndModal);
  *
  *         CATUnicodeString WindowTitle = "..." ;
  *         pNfy->DisplayBlocked(WarningMessage , WindowTitle);
  *         pNfy->RequestDelayedDestruction();
  *      }
  *   }
  * </pre>
  *
  * @param oWarningMessageToDisplay
  *     The warning message to be displayed to the user if successful (S_OK returned).
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The warmstart was successfully activated or re-initialized.</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The activation failed, either because warmstart is not available, or 
  *         some documents were dirty.</dd>
  *   </dl>
  */
  static HRESULT Activate(CATUnicodeString& oWarningMessageToDisplay);

  /**
  * Commits the transaction into the warmstart backup data.
  * <br><b>Role:</b> Normally the operations inside a command are validated at the end of 
  * the command for a state command, or at the activation of the next for the others. 
  *  That wants to say that as long as the validation is not made, if the V5 session is broken, 
  *  the last operations will be not restored at the backup. However, you can force this 
  *  validation during a command if it is necessary. 
  *  <br>This method should be called to force the 
  *  latest modifications on the model to be commited into the backup data. This means that 
  * those modifications will be replayed if a warmstart is needed. 
  * The method should be called only when the 
  * modifications to commit make a coherent transaction up, so that if they are replayed, 
  * the model won't be left in a instable state.
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The transaction has been successfully committed.</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>An internal error prevented the transaction from being committed.</dd>
  *   </dl>
  */
  static HRESULT CommitTransaction();

  /**
  * Tests if the warmstart is active.
  * <br><b>Role:</b> This method should be called to test if the warmstart is 
  *  currently saving backup data.
  *
  * @param oActive
  *     When successful (S_OK returned) : TRUE if the warmstart is active, FALSE otherwise.
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The returned status is meaningful.</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The warmstart is not available, or an internal error prevents 
  *        the status from being retrieved.</dd>
  *   </dl>
  */
  static HRESULT IsActive(CATBoolean &oActive);

  /**
  * Tests if the warmstart is available.
  * <br><b>Role:</b> This method should be called to test if the warmstart can be activated,
  * depending on environment variables and user settings.
  *
  * @param oAvailable
  *     When successful (S_OK returned) : TRUE if the warmstart is available, FALSE otherwise.
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The returned status is meaningful.</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>An internal error prevents the status from being retrieved.</dd>
  *   </dl>
  */
  static HRESULT IsAvailable(CATBoolean &oAvailable);


};
#endif
