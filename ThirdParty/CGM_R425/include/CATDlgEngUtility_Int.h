#ifndef CATDlgEngUtility_Int_H
#define CATDlgEngUtility_Int_H

// COPYRIGHT DASSAULT SYSTEMES 2006-2009

#include "CATDlgEngUtility.h"

/**
 * Dialog agent behavior.
 * <b>Role</b>: Defines the dialog agent behavior as a field of bits.
 * The behavior is a concatenation of behavioral facets
 * set thanks to the @href CATDialogAgent#SetBehavior method.
 * <p>
 * Applies to @href CATStateCommand only:
 * @param CATDlgEngEdtChangeRequestOKCancel   
 *   The standard behavior when a command is stopped because the user activates another editor is that
 *   the modifications done during the command are cancelled.
 *   <br>Using this behavior will display a notify box to enable the user to commit its modifications.
 * <p>
 * Applies to @href CATStateCommand only:
 * @param CATDlgEngNoEmptyUndoAtEndAfterIrreversibleOperation   
 *   The standard behavior when an irreversible operation occurs is to empty the Undo/Redo stack
 *   immediately after and at the end of the command.
 *   <br>Using this behavior will prevent the Undo/Redo stack from being emptied at the end of the command. 
 * <p>
 * Applies to @href CATStateCommand only:
 * @param CATDlgEngNoGlobalUndoStep   
 *   The standard behavior when a command ends is to add a global step in the Undo stack.
 *   <br>Using this behavior will prevent the global step to be created at the end of the command. 
 * <p>
 * Applies to @href CATStateCommand with CATDlgEngWithAutoUndo behavior only:
 * @param CATDlgEngWithTransactions
 *   If a transition does not create an undo step, a transaction is created
 */

//           For values >= 31, use (1LL << xx)
// =======   63 value is already used for CATDlgEngEdtChangeRequestOKCancel
// WARNING : 62 value is already used for CATDlgEngNoEmptyUndoAtEndAfterIrreversibleOperation
// =======   61 value is already used for CATDlgEngNoGlobalUndoStep
//           60 value is already used for CATDlgEngWithTransactions
//           59 value is already used for ...

//------------------------------------------------------------------
//          CATStateCommand
//------------------------------------------------------------------

// used for commands which want to ask the user whether he/she wants to commit data
// before the command is cancelled when the user activates another editor
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngEdtChangeRequestOKCancel (((CATDlgEngBehavior)1) << 63)
#else
#define CATDlgEngEdtChangeRequestOKCancel (1LL << 63)
#endif

// used for commands which do not want to empty the Undo/Redo stack at the end when
// an irreversible operation occurred
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngNoEmptyUndoAtEndAfterIrreversibleOperation (((CATDlgEngBehavior)1) << 62)
#else
#define CATDlgEngNoEmptyUndoAtEndAfterIrreversibleOperation (1LL << 62)
#endif

// used for commands which do not want to create a global Undo step at the end
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngNoGlobalUndoStep (((CATDlgEngBehavior)1) << 61)
#else
#define CATDlgEngNoGlobalUndoStep (1LL << 61)
#endif

// used for commands which want to create a transaction if agents do not create an undo step
// when they trigger a transition
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngWithTransactions (((CATDlgEngBehavior)1) << 60)
#else
#define CATDlgEngWithTransactions (1LL << 60)
#endif

#endif
