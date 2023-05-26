#ifndef CATAfrProtectedUIUndoRedoServices_H
#define CATAfrProtectedUIUndoRedoServices_H
#include "UndoRedoUI.h"

// COPYRIGHT DASSAULT SYSTEMES 2006-2018

#include "CATAfrUndoRedoServices.h" // Allows to move to a function to CATAfrUndoRedoServices.h without impact
#include "CATBoolean.h"
#include "IUnknown.h"

// SHOULD NOT EXPOSE ObjectModelerBase headers!!!!
//#ifndef  REMOVE_USELESS_INCLUDE
#include "CATOmbUndoRedoDefs.h"
//#else
//#pragma  message ( "  BADREM  :  ABI  071205  "  __FILE__  " Include CATOmbUndoRedoDefs.h header in your cpp"  )
//#endif

class CATUndoRequest;
class CATBaseUnknown;
class CATUnicodeString;
class CATCallbackManager;
class OmbUndoRedoContext;
class CATIModelUndoRedoManager;

//---------------------------------------------------------------------------
/**
 * Indicates whether Session Undo is active.
 * @return
 * Returns TRUE if Session Undo is active.
 */
ExportedByUndoRedoUI
CATBoolean CATAfrIsSessionUndoActive (int iCore = 0);

//---------------------------------------------------------------------------
/**
 * Subscribes to the Session Undo/Redo transactional model.
 * <br><b>Role</b>: This method adds the client to the list of those
 * to be called on CATIModelUndoRedoManager methods along the session.
 * @param iClient
 *  The Client.
 * @param iClientID
 *  Client ID, used to differenciate clients.
 * @param iModelManagement
 *  If TRUE the client is to be integrated in the Model Undo/Redo management
 * @param iBeforeModel
 *  If TRUE (and if iModelManagement is FALSE) the client will be called before
 *  the model for Undo and after the model for Redo
 *  If FALSE (and if iModelManagement is FALSE) the client will be called after
 *  the model for Undo and before the model for Redo
 * @return
 * <dl>
 * <dt> <tt>S_OK</tt>    <dd> The client has been added.
 * <dt> <tt>S_FALSE</tt> <dd> The client had already been added.
 * <dt> <tt>E_FAIL</tt>  <dd> Error.
 * </dl>
 */
ExportedByUndoRedoUI
HRESULT CATAfrAddToUndoRedoManagement (CATBaseUnknown * iClient, const CATUnicodeString & iClientID, CATBoolean iModelManagement=TRUE, CATBoolean iBeforeModelManagement=TRUE);

//---------------------------------------------------------------------------
/**
 * Unsubscribes from the Session Undo/Redo transactional model.
 * <br><b>Role</b>: This method removes the client from the list of those
 * to be called on CATIModelUndoRedoManager methods along the session.
 * @param iClient
 *  The Client.
 * @return
 * <dl>
 * <dt> <tt>S_OK</tt>    <dd> The client has been removed.
 * <dt> <tt>S_FALSE</tt> <dd> The client had not been found.
 * <dt> <tt>E_FAIL</tt>  <dd> Error.
 * </dl>
 */
ExportedByUndoRedoUI
HRESULT CATAfrRemoveFromUndoRedoManagement (CATBaseUnknown * iClient);

//---------------------------------------------------------------------------
/**
 * Gets the last item in the Undo stack.
 * <br><b>Role</b>: This method returns the newest item in the Undo stack.
 * @param oUndo
 *  The last item in the Undo stack
 * @return
 * Returns always S_OK.
 */
ExportedByUndoRedoUI
HRESULT CATAfrGetUIUndoRedoCallbackManager (CATCallbackManager *& oCBManager);

//---------------------------------------------------------------------------
/**
 * Creates a new undo step in the the Session Undo/Redo mechanism to a specific transition.
 * <br><b>Role</b>: This method creates a new undo step in the the Session Undo/Redo mechanism.
 * @param iUndoTitle
 *  The Id of the newly created undo step. Can be any string, used for debugging purpose.
 * @param iFirstTransactionIndex
 *  The index of the first transaction (from 1 to ...) of the newly created undo step
 * @return
 * Returns S_OK if the undo was successfully created and E_FAIL otherwise.
 
 */
ExportedByUndoRedoUI
HRESULT CATAfrCreateUndoStepToTransaction(const CATUnicodeString& iUndoTitle, int iFirstTransactionIndex, CATBoolean iExclusive = false);

//---------------------------------------------------------------------------
/**
 * Returns whether an Undo has been requested.
 * <br><b>Role</b>: This method returns the transactional state of the session.
 * @param oUndoRequested
 *  The current transactional state of the session.
 * @return
 * Returns always S_OK.
 */
ExportedByUndoRedoUI
HRESULT CATAfrIsUndoRequested (CATBoolean & oUndoRequested);

//---------------------------------------------------------------------------
/**
 * Returns whether a Redo has been requested.
 * <br><b>Role</b>: This method returns the transactional state of the session.
 * @param oRedoRequested
 *  The current transactional state of the session.
 * @return
 * Returns always S_OK.
 */
ExportedByUndoRedoUI
HRESULT CATAfrIsRedoRequested (CATBoolean & oRedoRequested);

//---------------------------------------------------------------------------
/**
 * Gets the transactional state of the session.
 * <br><b>Role</b>: This method returns the transactional state of the session.
 * @param oMode
 *  The current transactional state of the session
 * @return
 * Returns always S_OK.
 */
enum CATAfrUndoRedoMode {DO, UNDO, REDO};
ExportedByUndoRedoUI
HRESULT CATAfrGetUndoRedoMode (CATAfrUndoRedoMode & oMode);

//---------------------------------------------------------------------------
/**
 * Gets the Undo/Redo commands availability.
 * <br><b>Role</b>: This method returns the availability of the Undo/Redo commands.
 * @param oAvailability
 *  The availability of the Undo/Redo commands.
 * @return
 * Returns always S_OK.
 */
ExportedByUndoRedoUI
HRESULT CATAfrGetUndoAvailability (CATBoolean & oAvailability);

//---------------------------------------------------------------------------
/**
 * Sets the Undo/Redo commands availability.
 * <br><b>Role</b>: This method sets the availability of the Undo/Redo commands.
 * @param iAvailability
 *  The availability of the Undo/Redo commands.
 * @return
 * Returns always S_OK.
 */
ExportedByUndoRedoUI
HRESULT CATAfrSetUndoAvailability (CATBoolean iAvailability);

//---------------------------------------------------------------------------
/**
 * Gets the current UI transaction set number.
 * <br><b>Role</b>: This method returns the number of the current UI transaction set.
 * The UI transaction set number is increased every time the UI Undo/Redo stack is emptied.
 * @param oTransactionSet
 *  The current UI transaction set number (from 1 (the oldest) to ...)
 * @return
 * Returns always S_OK.
 */
ExportedByUndoRedoUI
HRESULT CATAfrGetCurrentTransactionSet (int & oTransactionSet);

//---------------------------------------------------------------------------
/**
 * Creates a new UI transaction in the Session Undo/Redo mechanism.
 * <br><b>Role</b>: This method creates a new transaction.
 * @param iId
 *  Any string, used for debugging purpose.
 * @param iContext
 *  Command context for Model Undo/Redo checks.
 * @param iForce
 *  If FALSE no transaction will be created if the current one is empty.
 * @param iCheck
 *  If FALSE no check about Model Undo/Redo state is performed
 * @param oTransactionIndex
 *  The index of the new transaction (from 1 to ...)
 * @return
 * Returns always S_OK.
 */
ExportedByUndoRedoUI
HRESULT CATAfrNewTransaction (const CATUnicodeString & iId, OmbUndoRedoContext & iContext, CATBoolean iForce, CATBoolean iCheck, int & oTransactionIndex);

//---------------------------------------------------------------------------
/**
 * Gets the current UI transaction index.
 * <br><b>Role</b>: This method returns the index of the current UI transaction.
 * @param oTransactionIndex
 *  The current UI transaction index (from 1 (the oldest) to ...)
 * @return
 * Returns always S_OK.
 */
ExportedByUndoRedoUI
HRESULT CATAfrGetCurrentTransaction (int & oTransactionIndex);

//---------------------------------------------------------------------------
/**
 * Gets the current Model transaction index.
 * <br><b>Role</b>: This method returns the index of the current model transaction.
 * @param iModelUndoRedoManager
 *  The model Undo/Redo manager
 * @param oTransactionIndex
 *  The current model transaction index for this manager (from 1 (the oldest) to ...)
 * @return
 * <dl>
 * <dt> <tt>S_OK</tt>    <dd> The index has been returned.
 * <dt> <tt>E_FAIL</tt>  <dd> Invalid model Undo/Redo manager.
 * </dl>
 */
ExportedByUndoRedoUI
HRESULT CATAfrGetCurrentTransaction (CATIModelUndoRedoManager * iModelUndoRedoManager, int & oTransactionIndex);

//---------------------------------------------------------------------------
/**
 * Checks whether a UI transaction is empty or not.
 * <br><b>Role</b>: This method checks whether modifications have been registered in a UI transaction.
 * @param iIndex
 *  The UI transaction index (from 1 (the oldest) to ...) to check
 * @return
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> The UI transaction is empty.
 * <dt> <tt>S_FALSE</tt>  <dd> Modifications have been registered in the UI transaction.
 * </dl>
 */
ExportedByUndoRedoUI
HRESULT CATAfrIsEmptyTransaction (int iIndex);

//---------------------------------------------------------------------------
/**
 * Checks whether several UI transactions are empty or not.
 * <br><b>Role</b>: This method checks whether modifications have been registered in several UI transactions.
 * @param startingIndex
 *  The first UI transaction index (from 1 (the oldest) to ...) to check
 * @param endingIndex
 *  The last UI transaction index (from 1 (the oldest) to ...) to check
 *  have to be higher than startingIndex
 * @return
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> The UI transactions are empty.
 * <dt> <tt>S_FALSE</tt>  <dd> Modifications have been registered in one of the UI transactions.
 * </dl>
 */
ExportedByUndoRedoUI
HRESULT CATAfrAreEmptyTransactions (int startingIndex, int endingIndex);

//---------------------------------------------------------------------------
/**
 * Commits a transaction.
 * <br><b>Role</b>: This method commits a UI transaction.
 * <br>Either the transaction to commit is merged into the previous one,
 * or it is deleted.
 * @param iIndex
 *  The UI transaction index (from 1 (the oldest) to ...) to commit
 * @return
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> The UI transaction has been committed.
 * <dt> <tt>E_FAIL</tt>   <dd> Invalid index.
 * </dl>
 */
ExportedByUndoRedoUI
HRESULT CATAfrCommitTransaction (int iIndex);

//---------------------------------------------------------------------------
/**
 * Merges transactions.
 * <br><b>Role</b>: This method merges UI transactions.
 * <br>Merging transactions involves merging intermediate transactions too.
 * @param iTargetIndex
 *  The UI transaction index (from 1 (the oldest) to ...) into the other transaction(s) will be merged
 * @param iCommittedIndex
 *  The UI transaction index (from 1 (the oldest) to ...) which must be merged into the target one
 * @return
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> The UI transactions have been merged.
 * <dt> <tt>E_FAIL</tt>   <dd> Invalid indexes.
 * </dl>
 */
ExportedByUndoRedoUI
HRESULT CATAfrMergeTransactions (int iTargetIndex, int iCommittedIndex);

//---------------------------------------------------------------------------
/**
 * Gets the Undo stack count.
 * <br><b>Role</b>: This method returns the count of items in the Undo stack.
 * @param oCount
 *  The Undo stack count
 * @return
 * Returns always S_OK.
 */
ExportedByUndoRedoUI
HRESULT CATAfrGetUndoRequestCount (int & oCount);

//---------------------------------------------------------------------------
/**
 * Gets the last item in the Undo stack.
 * <br><b>Role</b>: This method returns the next undoable item in the Undo stack.
 * @param oUndo
 *  The last item in the Undo stack
 * @return
 * Returns always S_OK.
 */
ExportedByUndoRedoUI
HRESULT CATAfrGetLastUndoRequest (CATUndoRequest *& oUndo);

//---------------------------------------------------------------------------
/**
 * Gets the penultimate item in the Undo stack.
 * <br><b>Role</b>: This method returns the penultimate undoable item in the Undo stack.
 * @param oUndo
 *  The penultimate item in the Undo stack
 * @return
 * Returns always S_OK.
 */
ExportedByUndoRedoUI
HRESULT CATAfrGetPenultimateUndoRequest (CATUndoRequest *& oUndo);


//---------------------------------------------------------------------------
/**
 * Gets the last item in the Redo stack.
 * <br><b>Role</b>: This method returns the next redoable item in the Redo stack.
 * @param oRedo
 *  The last item in the Redo stack
 * @return
 * Returns always S_OK.
 */
ExportedByUndoRedoUI
HRESULT CATAfrGetLastRedoRequest (CATUndoRequest *& oRedo);

//---------------------------------------------------------------------------
/**
 * Gets an item in the Undo stack by its index.
 * <br><b>Role</b>: This method returns the last item in the Undo stack.
 * @param iIndex
 *  The index in the Undo stack (from 0 (the oldest) to ...)
 * @param oUndo
 *  The item at the requested position
 * @return
 * <dl>
 * <dt> <tt>S_OK</tt>    <dd> The item has been returned.
 * <dt> <tt>E_FAIL</tt>  <dd> Invalid index.
 * </dl>
 */
ExportedByUndoRedoUI
HRESULT CATAfrGetUndoRequest (int iIndex, CATUndoRequest *& oUndo);

//---------------------------------------------------------------------------
/**
 * Gets an item in the Undo stack by its index.
 * <br><b>Role</b>: This method returns the last item in the Undo stack.
 * @param iUndo
 *  The item
 * @param oIndex
 *  The item index in the Undo stack (from 0 (the oldest) to ...)
 * @return
 * <dl>
 * <dt> <tt>S_OK</tt>    <dd> The index has been returned.
 * <dt> <tt>E_FAIL</tt>  <dd> Invalid item.
 * </dl>
 */
ExportedByUndoRedoUI
HRESULT CATAfrGetUndoRequestIndex (CATUndoRequest * iUndo, int & oIndex);

//---------------------------------------------------------------------------
/**
 * Undoes the last action stacked.
 * <br><b>Role</b>: This method starts the Undo command once.
 * @param iStopCurrentCommand
 *  If TRUE the current command will be interrupted before Undo is performed.
 * @param iEnableRedo
 *  If TRUE the undone action will be redoable (if possible).
 * @return
 * Returns always S_OK.
 */
ExportedByUndoRedoUI
HRESULT CATAfrExecuteUndo (CATBoolean iStopCurrentCommand=TRUE, CATBoolean iEnableRedo=TRUE, int* oNumInRedoStack = NULL);

//---------------------------------------------------------------------------
/**
 * Redoes the last action stacked.
 * <br><b>Role</b>: This method starts the Redo command once.
 * @return
 * Returns always S_OK.
 */
ExportedByUndoRedoUI
HRESULT CATAfrExecuteRedo (int* oNumInUndoStack = NULL);

//---------------------------------------------------------------------------
/**
 * Pulls and manages last Model Undo/Redo error.
 * <br><b>Role</b>: This method pulls the last Model Undo/Redo error and performs actions
 * @param oErrorId
 * <dl>
 * <dt> <tt>OMBUNDO_NOERROR</tt>                        <dd> No error.
 * <dt> <tt>OMBUNDO_IRREVERSIBLE_OPERATION</tt>         <dd> Empty stack + new transaction.
 * <dt> <tt>OMBUNDO_IRREVERSIBLE_EDITABILITY_ERROR</tt> <dd> Empty stack + Message.
 * <dt> <tt>OMBUNDO_EDITABILITY_ERROR</tt>              <dd> Message + Undo.
 * <dt> <tt>OMBUNDO_REVERSIBLE_ERROR</tt>               <dd> Message + Undo.
 * </dl>
 * @return
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> No error.
 * <dt> <tt>S_FALSE</tt>  <dd> Error managed.
 * </dl>
 */
ExportedByUndoRedoUI
HRESULT CATAfrManageUndoRedoError (OmbUndoRedoErrorId & oErrorId);
#endif
 
