#ifndef CATAfrUndoRedoServices_H
#define CATAfrUndoRedoServices_H
#include "UndoRedoUI.h"

// COPYRIGHT DASSAULT SYSTEMES 2004-2008

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "IUnknown.h" // HRESULT definition under UNIX
#include "CATBoolean.h"

class CATUnicodeString;

//---------------------------------------------------------------------------
/**
 * Flushes the Undo and Redo stacks.
 * <br><b>Role</b>: This method flushes the Undo and Redo stacks.
 * <br>The Undo/Redo mechanism is freezed until a new UI transaction is created.
 * <br>Modifications done while the Undo/Redo mechanism is freezed will not be undoable.
 * @return
 * Returns always S_OK.
 */
ExportedByUndoRedoUI
HRESULT CATAfrEmptyUndoRedoStacks ();

//---------------------------------------------------------------------------
/**
 * Creates a new undo step in the the Session Undo/Redo mechanism.
 * <br><b>Role</b>: This method creates a new transaction and associated to a new undo step in the the Session Undo/Redo mechanism.
 * @param iUndoTitle
 *  The Undo Title of the undo step create
 * @param iFirstTransactionId
 *  The Id of the newly created first transaction for the new undo step. Can be any string, used for debugging purpose.
 * @param oFirstTransactionIndex
 *  The index of the created first transaction (from 1 to ...) of the newly created undo step
 * @return
 * Returns S_OK if the undo step was successfully created and E_FAIL Otherwise
 
 */
ExportedByUndoRedoUI
HRESULT CATAfrCreateNewUndoStep(const CATUnicodeString& iUndoTitle, const CATUnicodeString & iFirstTransactionId, int & oFirstTransactionIndex, int iIsExclusive = 0);

//---------------------------------------------------------------------------
/**
 * Creates a new UI transaction in the Session Undo/Redo mechanism.
 * <br><b>Role</b>: This method creates a new transaction. The common command context is used,
 * the transaction will be created even if the current one is empty
 * and a check about Model Undo/Redo state is performed.
 * @param iId
 *  Any string, used for debugging purpose.
 * @param oTransactionIndex
 *  The index of the new transaction (from 1 to ...)
 * @return
 * Returns always S_OK.
 */
ExportedByUndoRedoUI
HRESULT CATAfrCoreNewTransaction(const CATUnicodeString & iId, int & oTransactionIndex);

/**
 * Obsolete, DO NOT USE, use CATAfrCoreNewTransaction please.
 */
ExportedByUndoRedoUI
HRESULT CATAfrNewTransaction (const CATUnicodeString & iId, int & oTransactionIndex);

//---------------------------------------------------------------------------
/**
 * Freezes the Undo/Redo mechanism.
 * <br><b>Role</b>: This method flushes the Undo and Redo stacks and locks transactions.
 * <br>The Undo/Redo mechanism is freezed until @href CATAfrUnlockUndoRedoTransactions is called.
 * <br>Modifications done while the Undo/Redo mechanism is freezed will not be undoable.
 * @param iWarning
 *  If TRUE, displays a warning message to the user.
 * @return 
 *   <dl>
 *   <dt> <tt>S_OK</tt>    <dd> The Undo/Redo mechanism has been freezed
 *   <dt> <tt>S_FALSE</tt> <dd> The Undo/Redo mechanism cannot be freezed during Undo or Redo actions
 *   </dl>   
 */
ExportedByUndoRedoUI
HRESULT CATAfrLockUndoRedoTransactions (CATBoolean iWarning=FALSE);

//---------------------------------------------------------------------------
/**
 * Unfreezes the Undo/Redo mechanism.
 * <br><b>Role</b>: This method cancels the action of @href CATAfrLockUndoRedoTransactions.
 * New modifications done will be undoable as usual once a new UI transaction is created.
 * @return
 * Returns always S_OK.
 */
ExportedByUndoRedoUI
HRESULT CATAfrUnlockUndoRedoTransactions ();

//---------------------------------------------------------------------------
/**
 * Checks whether the Undo/Redo mechanism is freezed.
 * <br><b>Role</b>: This method checks whether the Undo/Redo mechanisl has been locked.
 * @param oLocked
 *  If TRUE, the Undo/Redo mechanism is freezed.
 * @return
 * Returns always S_OK.
 */
ExportedByUndoRedoUI
HRESULT CATAfrIsUndoRedoLocked (CATBoolean & oLocked);

#endif
 
