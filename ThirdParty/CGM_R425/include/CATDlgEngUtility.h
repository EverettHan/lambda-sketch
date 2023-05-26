#ifndef CATDlgEngUtility_H
#define CATDlgEngUtility_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATString.h"
#include "CATUnicodeString.h"

/**
 * @nodoc
 * Dialog agent representation visibility.
 * @param CATDlgEngHide
 *   The dialog agent representation is hidden
 * @param CATDlgEngShow
 *   The dialog agent representation is shown
 */
enum CATDlgEngVisibility{CATDlgEngHide, CATDlgEngShow};

/**
 * Dialog agent behavior.
 * <b>Role</b>: Defines the dialog agent behavior as a field of bits.
 * The behavior is a concatenation of behavioral facets
 * set thanks to the @href CATDialogAgent#SetBehavior method.
 * <p>
 * @param CATDlgEngActive
 *   The dialog agent is notified by any user interaction.
 *   This is the default
 * @param CATDlgEngInactive
 *   The dialog agent is never notified by a user interaction
 * <p>
 * @param CATDlgEngOneShot
 *   The dialog agent doesn't remain active after it is valued.
 *   The state command stops when it reaches the NULL state.
 *   This is the default for both.
 * @param CATDlgEngRepeat
 *   The dialog agent remains active after it is valued and can be reused.
 *   The state command resumes when it reaches the NULL state
 * <p>
 * @param CATDlgEngReceiveAllNotifications
 *   The dialog agent receives all the notifications received by the CATStateCommand it belongs to.
 *   This is the default
 * @param CATDlgEngReceiveFromLinkedViews
 *   The dialog agent receives only notifications sent by objects of which
 *   it is the father (Send/Receive sense)
 * <p>
 * @param CATDlgEngIgnoreOnPrevaluate
 *   The dialog agent requests that the transition triggers when an object is selected only.
 *   This is the default
 * @param CATDlgEngAcceptOnPrevaluate
 *   The dialog agent requests that the transition triggers as soon as an object
 *   is located under the mouse without being selected.
 * <p>
 * @param CATDlgEngWithoutVisualization
 *   The dialog agent has no particular visualization attribute.
 *   This is the default
 * @param CATDlgEngWithVisualization
 *   The dialog agent is put into the ISO when it is activated
 * @param CATDlgEngWithXORVisualization
 *   The dialog agent is put into the furtive ISO when it is activated
 * <p>
 * @param CATDlgEngWithUndoStep
 *   The dialog agent's valuation can be undone, and the
 *   dialog agent registers an undo step.
 *   This is the default
 * @param CATDlgEngWithUndo
 *   The dialog agent's valuation can be undone, but the
 *   dialog agent doesn't register an undo step
 * @param CATDlgEngWithoutUndo
 *   The dialog agent's valuation can't be undone.
 * <p>
 * @param CATDlgEngTriggersLocalSave
 *   The agent triggers a local save when it is accepted.
 * <p>
 * Apply to @href CATStateCommand only :
 * @param CATDlgEngWithAutoUndo           
 *   The state command can have undo steps depending on agent's behavior.
 *   The agents of the command are undoable separately.
 *   This is the default
 * @param CATDlgEngWithoutAutoUndo  
 *   The state command has no undo step. 
 *   All agents of the command are undoable in one step.
 *   The command doesn't take account of agents undo behavior
 * <p>
 * Applies to @href CATStateCommand only :
 * @param CATDlgEngWithoutUndoStart
 *   No undo step is automatically added at the beginning of the command,
 *   so Undo command undoes the last undoable action before the command was started
 * <p>
 * Apply to @href CATStateCommand only :
 * @param CATDlgEngNoTransaction
 *   The Undo stack is emptied and remains empty as long as the state command is active
 *   (this can be used for performance reasons). A warning is displayed.
 * @param CATDlgEngNoTransactionNoWarning :
 *   The Undo stack is emptied and remains empty as long as the state command is active
 *   (this can be used for performance reasons). No warning is displayed.
 * @param CATDlgEngFlushTransactions
 *   The Undo stack is emptied after each transaction as long as the state command is active
 *   (this can be used for performance reasons). No warning is displayed.
 * <p>
 * Applies to @href CATStateCommand only :
 * @param CATDlgEngEmptyUndoAtEnd   
 *   The Undo stack is emptied when the command finishes
 *  (this can be used for performance reasons).
 * <p>
 * Apply to @href CATStateCommand only :
 * @param CATDlgEngWithAgentInitialization           
 *   The state command reinitializes its agents if it resumes after reaching
 *   the NULL state of after Undo or Redo.
 *   This is the default
 * @param CATDlgEngWithoutAgentInitialization  
 *   The state command does not reinitialize its agents.
 * <p>
 * Apply to @href CATStateCommand only :
 * @param CATDlgEngAgentActivationWhenEnteringState           
 *   The state command calls its agents on the Activate method
 *   each time the state they belong to is entered,
 *   even when a transition loops on the same state.
 *   This is the default
 * @param CATDlgEngAgentActivationWhenChangingState  
 *   The state command calls its agents on the Activate method
 *   when the state they belong to is entered,
 *   but only if the state has changed.
 * <p>
 * Apply to @href CATStateCommand only :
 * @param CATDlgEngOldTrigger           
 *   The conditions are tested when an agent is valued or when
 *   entering a state if this state contains no agent or if one of
 *   its agents is valued and is OneShot 
 *   This is the default
 * @param CATDlgEngNewTrigger  
 *   The conditions are tested when an agent is valued or when
 *   entering a new state whatever its agents or when entering
 *   the same state after a loop if an event has occurred during the loop.
 * <p>
 * Apply to @href CATStateCommand only :
 * @param CATDlgEngEmptyPSO           
 *   The CATAcquisitionAgent::ResetPrevaluation method empties the PSO.
 *   This is the default
 * @param CATDlgEngNoEmptyPSO  
 *   The CATAcquisitionAgent::ResetPrevaluation method removes from the PSO
 *   only the objects linked to the prevaluation.
 * <p>
 * Applies to @href CATStateCommand only :
 * @param CATDlgEngParallel   
 *   The state command is to be used in the special parallel mode
 * <p>
 * Applies to @href CATStateCommand only :
 * @param CATDlgEngDrillFilter
 *   If more than one element is acceptable by path element agents in the current state
 *   when the user clicks, the drill appears and the user must select through it.
 * <p>
 * Applies to @href CATStateCommand only :
 * @param CATDlgEngFlushCheck
 *   The command assumes it can make not undoable modifications.
 * <p>
 * Applies to @href CATStateCommand only :
 * @param CATDlgEngCancelCheck
 *   The command assumes it can make forbidden modifications.
 * <p>
 * Applies to @href CATStateCommand only :
 * @param CATDlgEngNoDirtyCheck
 *   The command assumes it does not dirty the session.
 * <p>
 * Applies to @href CATStateCommand only :
 * @param CATDlgEngOwnCSOHSOManagement
 *   The command modifies the CSO and deals with HSO update.
 * <p>
 * Apply to @href CATAcquisitionAgent only :
 * @param CATDlgEngWithoutSO
 *   The acquisition agent doesn't highlight either the object under the mouse
 *   nor the selected object.
 *   This is the default
 * @param CATDlgEngWithPSO
 *   The acquisition agent highlights the object under the mouse.
 *   Implies that <tt>CATDlgEngWithPrevaluation</tt> is also used.
 * @param  CATDlgEngWithHSO
 *   The acquisition agent highlights the selected object
 * @param CATDlgEngWithPSOHSO
 *   The acquisition agent highlights both the object under the mouse and the selected object.
 *   Implies that <tt>CATDlgEngWithPrevaluation</tt> is also used.
 * <p>
 * Apply to @href CATAcquisitionAgent only :
 * @param  CATDlgEngOldHSOManager   
 *   When the acquisition agent puts an element in the HSO,
 *   it remains in the HSO until the end of the command. 
 *   This is the default
 * @param  CATDlgEngNewHSOManager   
 *   The element is removed from the HSO when the
 *   acquisition agent is reinitialized.
 * <p>
 * Apply to @href CATAcquisitionAgent only :
 * @param CATDlgEngSimpleValuation
 *   The path element agent is valued with object selection, that is,
 *   with a mouse left button simple click on an object.
 *   This is the default
 * @param CATDlgEngWithPrevaluation
 *   The path element agent is valued with object preselection, that is, with an 
 *   object under the mouse without being selected, in addition to object 
 *   selection.
 * @param CATDlgEngWithManipulation
 *   The path element agent is valued with object manipulation, that is,
 *   with an object selected and dragged.
 * @param CATDlgEngWithEdit
 *   The path element agent is valued with object edition, that is,
 *   with a mouse left button double click on an object.
 * @param CATDlgEngWithContext
 *   The path element agent is valued with a mouse right click on an object.
 *   Applies to @href CATPathElementAgent only
 * @param CATDlgEngWithDrag
 *   The path element agent manages notifications during Drag and Drop.
 * <p>
 * Apply to @href CATPathElementAgent only :
 * @param  CATDlgEngNotValuedFromCSO   
 *   The path element agent is not valued from the CSO or the contextual selection at the beginning of the command.
 *   This is the default
 * @param  CATDlgEngValuedFromCSO   
 *   The path element agent is valued from the CSO or the contextual selection at the beginning of the command.
 *   This behavior is valid only for path element agents in the first state.
 *   This behavior is not compatible with CATDlgEngRepeat.
 * <p>
 * Apply to @href CATStateCommand only :
 * @param  CATDlgEngCSOAgentValuedFromFilteredPath   
 *   The path element agents are valued with the filtered paths, while by default they are valued with the genuine paths.
 *   Implies that <tt>CATDlgEngValuedFromCSO</tt> is also used on some agents in the first state.
 * <p>
 * Apply to @href CATPathElementAgent only :
 * @param CATDlgEngMonoAcquisition
 *   The path element agent accepts one object indication or selection only.
 *   This is the default
 * @param CATDlgEngMultiAcquisition
 *   The path element agent accepts multi-selection. 
 * @param CATDlgEngMultiAcquisitionSelModes
 *   The path element agent accepts multi-selection,
 *   with a user interface to manage the selection mode.
 *   The agent is valued as soon as the first acquisition is performed.
 * @param CATDlgEngMultiAcquisitionCtrl
 *   The path element agent accepts multi-indication or multi-selection,
 *   with a user interface to manage the acquisition mode.
 *   Several acquisitions can be appended using the Ctrl and Shift keys
 *   before the end user decides the agent must be valued.
 * @param CATDlgEngMultiAcquisitionUserCtrl
 *   The path element agent accepts multi-selection,
 *   with a user interface to manage the selection mode.
 *   The agent is valued as soon as the first acquisition is performed,
 *   unless the end user decides to toggle the multi-acquisition control mode.
 * <p>
 * Applies to @href CATPathElementAgent with CATDlgEngMultiAcquisitionCtrl or
 * CATDlgEngMultiAcquisitionUserCtrl behaviors only :
 * @param CATDlgEngMultiAcquisitionCtrlNoFeedback
 *   The user interface to manage the multi-acquisition mode includes
 *   neither the editor displaying the count of selected elements
 *   nor the bag icon to display the list of selected elements.
 * <p>
 * Apply to @href CATPathElementAgent only :
 * @param CATDlgEngWithoutDeepSel
 *   1 selection ONLY (use GetValue())
 *   NO "through" selection: you can only retrieve the element that is 
 *   "in front", and only if it has appropriate type. 
 *   This is the default.
 * @param CATDlgEngWithDeepSel
 *   Multi-selection (use GetListOfValues())
 *   "through" selection: you get all the elements that have the appropriate type
 * @param CATDlgEngWithDeepFirstSel
 *   1 selection ONLY (use GetValue())
 *   "through" selection: you get THE first element that has appropriate type.
 * <p>
 * Applies to @href CATPathElementAgent with element type(s) only :
 * @param CATDlgEngNoSubPath
 *   The path element agent does not accept a selection if the leaf is not a kind of the expected types.
 * <p>
 * Apply to @href CATPathElementAgent only :
 * @param CATDlgEngWithoutTooltip
 *   This is the default.
 * @param CATDlgEngWithTooltip
 *   The path element agent displays a tooltip over the preselected or selected element.
 *   This is the default for @href CATFeatureAgent.
 * <p>
 * Apply to @href CATPathElementAgent only :
 * @param CATDlgEngWithUserSelectionFilter
 *   This is the default.
 * @param CATDlgEngWithoutUserSelectionFilter
 *   The path element agent does not collaborate with the User Selection Filter toolbar.
 * <p>
 * Applies to @href CATPathElementAgent only :
 * @param CATDlgEngNoDrillFilter
 *   Even if the parent state command has the @href CATDlgEngDrillFilter behavior,
 *   the path element agent can accept direct selection without drill.
 * <p>
 * Applies to @href CATOtherDocumentAgent only :
 * @param CATDlgEngNotReactivated
 *   When the other document agent is desactivated,
 *   the document where it has been created from is not implicitely reactivated.
 */
typedef CATULONG64 CATDlgEngBehavior;

//           For values >= 31, use (1LL << xx)
// =======   31 value is already used for CATDlgEngNewHSOManager
// WARNING : 32 value is already used for CATDlgEngwithXORVisualization
// =======   33 value is already used for CATDlgEngWithDeepFirstSel
//           34 value is already used for CATDlgEngMultiAcquisitionUserCtrl
//           35 value is already used for CATDlgEngParallel
//           36 value is already used for CATDlgEngNoTransaction
//           37 value is already used for CATDlgEngNotReactivated
//           38 value is already used for CATDlgEngNoSubPath
//           39 value is already used for CATDlgEngWithoutUndoStart
//           40 value is already used for CATDlgEngMultiAcquisitionCtrlNoFeedback
//           41 value is already used for CATDlgEngWithoutTooltip
//           42 value is already used for CATDlgEngWithTooltip
//           43 value is already used for CATDlgEngMultiAcquisitionSelModes
//           44 value is already used for CATDlgEngWithoutUserSelectionFilter
//           45 value is already used for CATDlgEngWithUserSelectionFilter
//           46 value is already used for CATDlgEngNoTransactionNoWarning
//           47 value is already used for CATDlgEngEmptyUndoAtEnd
//           48 value is already used for CATDlgEngDrillFilter
//           49 value is already used for CATDlgEngNoDrillFilter
//           50 value is already used for CATDlgEngFlushCheck
//           51 value is already used for CATDlgEngCancelCheck
//           52 value is already used for CATDlgEngNoDirtyCheck
//           53 value is already used for CATDlgEngOwnCSOHSOManagement
//           54 value is already used for CATDlgEngTriggersLocalSave
//           55 value is already used for CATDlgEngFlushTransactions
//           56 value is already used for CATDlgEngCSOAgentValuedFromFilteredPath

/** @nodoc */
#define CATDlgEngWithCSO CATDlgEngWithPSOHSO 
/** @nodoc */
#define CATDlgEngWithoutCSO CATDlgEngWithoutSO

//------------------------------------------------------------------
//                       CATDialogAgent
//------------------------------------------------------------------

// default = CATDlgEngActive
// An agent is called on its Activate, Desactivate, Cancel, AnalyseNotification
// methods when the state its belongs to is the current state.
// If the agent becomes unnecessary, use CATDlgEngInactive to prevent it to 
// be called.
/** @nodoc */
#define CATDlgEngActive             (1 << 0)
/** @nodoc */
#define CATDlgEngInactive           (1 << 1)

// default = CATDlgEngWithUndoStep
// An agent registers an undo step at each valuation.
// With CATDlgEngWithUndo, the agent can be undone as well but it doe snot add
// an undo step. 
// if Undo is required, this agent and the previous one are undone together. 
// If the agent does not have to change value if undo is resquested, use 
// CATDlgEngWithoutUndo. 
/** @nodoc */
#define CATDlgEngWithUndo           (1 << 2)
/** @nodoc */
#define CATDlgEngWithUndoStep       (1 << 3)
/** @nodoc */
#define CATDlgEngWithoutUndo        (1 << 4)

// default = CATDlgEngOneShot
// An agent becomes inactive when it is valued.
// Use CATDlgEngRepeat if an agent can be valued several times.
// A CATStateCommand stoppes when it reaches the NULL state.
// Use CATDlgEngRepeat for the command to resume.
/** @nodoc */
#define CATDlgEngRepeat             (1 << 5)
/** @nodoc */
#define CATDlgEngOneShot            (1 << 6)

// default = CATDlgEngReceiveAllNotifications
// An agent receives all the notifications received by the CATStateCommand it belongs to.
// if an agent is only interested in notifications sending by objects of which
// it is the father (Send/Receive sense), use CATDlgEngReceiveFromLinkedViews.
/** @nodoc */
#define CATDlgEngReceiveAllNotifications     (1 << 7)
/** @nodoc */
#define CATDlgEngReceiveFromLinkedViews      (1 << 8)

// default = CATDlgEngWithoutVisualization
// With CATDlgEngWithVisualization, the agent is put into the ISO when it is activated.
// With CATDlgEngWithXORVisualization, the agent is put into the furtive ISO when it is activated.
/** @nodoc */
#define CATDlgEngWithVisualization           (1 << 9)
/** @nodoc */
#define CATDlgEngWithoutVisualization        (1 << 10)
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngWithXORVisualization        (((CATDlgEngBehavior)1) << 32)
#else
#define CATDlgEngWithXORVisualization        (1LL << 32)
#endif

// default = CATDlgEngIgnoreOnPrevaluate
// By default, the conditions are tested only when an agent is valued.
// With CATDlgEngAcceptOnPrevaluate, the conditions are also tested at each 
// agent prevaluation.
/** @nodoc */
#define CATDlgEngAcceptOnPrevaluate (1 << 15)
/** @nodoc */
#define CATDlgEngIgnoreOnPrevaluate (1 << 16)


//------------------------------------------------------------------
//            CATAcquisitionAgent
//------------------------------------------------------------------

// default = CATDlgEngWithoutSO
// By default, the selected object is not highlighted.
// With CATDlgEngWithHSO, the selected object is highlighted.
// With CATDlgEngWithPSO, the object under the mouse (with buttons up) is 
// highlighted in another way to show the preselection (must be used with 
// CATDlgEngWithPrevaluation)
// CATDlgEngWithPSOHSO is equivalent to CATDlgEngWithPSO&CATDlgEngWithHSO.
/** @nodoc */
#define CATDlgEngWithPSOHSO         (1 << 11)
/** @nodoc */
#define CATDlgEngWithPSO            (1 << 12)
/** @nodoc */
#define CATDlgEngWithHSO            (1 << 13)
/** @nodoc */
#define CATDlgEngWithoutSO          (1 << 14)

// default = CATDlgEngMonoAcquisition
// CATDlgEngMultiAcquisition enables the agent to store CATSO instead of 
// CATPathElement in order to manage multisel with traps.
// With CATDlgEngMultiAcquisitionCtrl, if the Ctrl Key is down, a 
// selected value is removed from the set of values if this value already
// belongs to the set. (only useful with CATSelectionAgent)
/** @nodoc */
#define CATDlgEngMonoAcquisition    (1 << 17)
/** @nodoc */
#define CATDlgEngMultiAcquisition   (1 << 18)
/** @nodoc */
#define CATDlgEngMultiAcquisitionCtrl   (1 << 19)
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngMultiAcquisitionUserCtrl  (((CATDlgEngBehavior)1) << 34)
#else
#define CATDlgEngMultiAcquisitionUserCtrl  (1LL << 34)
#endif
/** @nodoc */
#define CATDlgEngMultiAcquisitionOneAction  CATDlgEngMultiAcquisitionUserCtrl
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngMultiAcquisitionCtrlNoFeedback  (((CATDlgEngBehavior)1) << 40)
#else
#define CATDlgEngMultiAcquisitionCtrlNoFeedback  (1LL << 40)
#endif
#define CATDlgEngMultiAcquisitionBag
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngMultiAcquisitionSelModes  (((CATDlgEngBehavior)1) << 43)
#else
#define CATDlgEngMultiAcquisitionSelModes  (1LL << 43)
#endif

// default = CATDlgEngNotValuedFromCSO
// By default, a CATPathElementAgent is not valued from the CSO or the contextual selection. 
// With CATDlgEngValuedFromCSO, a CATPathElementAgent belonging to the first state of
// the current command is valued from the CSO or the contextual selection at the beginning of the command.
// By default, such a CATPathElementAgent is valued with the genuine paths.
// With CATDlgEngCSOAgentValuedFromFilteredPath, it is valued with the filtered paths.
/** @nodoc */
#define CATDlgEngNotValuedFromCSO     (1 << 20)
/** @nodoc */
#define CATDlgEngValuedFromCSO        (1 << 21)
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngCSOAgentValuedFromFilteredPath    (((CATDlgEngBehavior)1) << 56)
#else
#define CATDlgEngCSOAgentValuedFromFilteredPath    (1LL << 56)
#endif

// default = CATDlgEngSimpleValuation
// By default, an agent only reacts to the left mouse button click.
// With CATDlgEngWithPrevaluation, the agent also stores the prevalues (before selection).
// CATDlgEngWithManipulation enables an agent to manage notifications when the
// mouse moves with the left button down.
// With CATDlgEngWithEdit, an agent reacts to the double-click.
// With CATDlgEngWithContext, an agent reacts to right button in order to manage a contextual menu.
// With CATDlgEngWithDrag, an agent manages notifications during Drag and Drop.
/** @nodoc */
#define CATDlgEngSimpleValuation    (1 << 22)
/** @nodoc */
#define CATDlgEngWithPrevaluation   (1 << 23)
/** @nodoc */
#define CATDlgEngWithManipulation   (1 << 24)
/** @nodoc */
#define CATDlgEngWithEdit           (1 << 25)
/** @nodoc */
#define CATDlgEngWithContext        (1 << 26)
/** @nodoc */
#define CATDlgEngWithDrag           (1 << 27)

// default = CATDlgEngWithoutDeepSel
// By default, a mouse click selects the first object under the mouse (the 
// last created object) if its type is a good one for the acquisition agent.
// With CATDlgWithDeepSel, a mouse click can select under the mouse any object
// that has a good type for the acquisition agent.
// With CATDlgWithDeepFirstSel, a mouse click selects under the mouse
// the first object that has a good type for the acquisition agent.
/** @nodoc */
#define CATDlgEngWithoutDeepSel       (1 << 28)
/** @nodoc */
#define CATDlgEngWithDeepSel          (1 << 29)
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngWithDeepFirstSel     (((CATDlgEngBehavior)1) << 33)
#else
#define CATDlgEngWithDeepFirstSel     (1LL << 33)
#endif

// default = CATDlgEngOldHSOManager
// By default, when the CATPathElementAgent puts an element in the HSO, it 
// remains in the HSO until the end of the command. 
// With CATDlgEngOldHSOManager, the element is removed from the HSO when the
// agent is reinitialized.
/** @nodoc */
#define CATDlgEngOldHSOManager        (1 << 30)
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngNewHSOManager        (((CATDlgEngBehavior)1) << 31)
#else
#define CATDlgEngNewHSOManager        (1LL << 31)
#endif

// By default, when the CATPathElementAgent gets an element, it can be truncated
// so that the remaining leaf is a kind of the expected type(s).
// With CATDlgEngNoSubPath, no truncation is allowed. The former leaf must be
// a kind of the expected type(s).
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngNoSubPath            (((CATDlgEngBehavior)1) << 38)
#else
#define CATDlgEngNoSubPath            (1LL << 38)
#endif

// default = CATDlgEngWithoutTooltip for any agent but CATFeatureAgent
// By default, no specific information but highlight is displayed when
// an element is preselected or selected.
// With CATDlgEngWithTooltip, a tooltip is diplayed with the path of
// the element behind the cursor. The tooltip can also be enriched by
// the application.
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngWithoutTooltip       (((CATDlgEngBehavior)1) << 41)
#else
#define CATDlgEngWithoutTooltip       (1LL << 41)
#endif
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngWithTooltip          (((CATDlgEngBehavior)1) << 42)
#else
#define CATDlgEngWithTooltip          (1LL << 42)
#endif

// default = CATDlgEngWithoutUserSelectionFilter for any agent but CATFeatureAgent
// By default, the agent does not collaborate with the user selection filter toolbar.
// With CATDlgEngWithUserSelectionFilter,
// the agent does collaborate with the user selection filter toolbar.
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngWithoutUserSelectionFilter (((CATDlgEngBehavior)1) << 44)
#else
#define CATDlgEngWithoutUserSelectionFilter (1LL << 44)
#endif
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngWithUserSelectionFilter    (((CATDlgEngBehavior)1) << 45)
#else
#define CATDlgEngWithUserSelectionFilter    (1LL << 45)
#endif

// used for path element agents which can accept selection without waiting for drill
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngNoDrillFilter  (((CATDlgEngBehavior)1) << 49)
#else
#define CATDlgEngNoDrillFilter  (1LL << 49)
#endif


//------------------------------------------------------------------
//          CATStateCommand
//------------------------------------------------------------------

// default = CATDlgEngWithAgentInitialization
// By default, the agents of a CATStateCommand are reinitialized if the 
// CATStateCommand resumes after reaching the NULL state (if CATDlgEngRepeat)
// of after Undo or Redo.
// Use CATDlgEngWithoutAgentInitialization to prevent the reinitialization.
/** @nodoc */
#define CATDlgEngWithAgentInitialization     (1 << 11)
/** @nodoc */
#define CATDlgEngWithoutAgentInitialization  (1 << 12)


// default = CATDlgEngWithAutoUndo
// By default, a CATStateComand manages undo steps required by its agents 
// (with CATDlgEngWithUndoStep).
// Use CATDlgEngWithoutAutoUndo if the command must not record undo.
/** @nodoc */
#define CATDlgEngWithAutoUndo                (1 << 13)
/** @nodoc */
#define CATDlgEngWithoutAutoUndo             (1 << 14)


// default = CATDlgEngAgentActivationWhenEnteringState
// By default, the agents of a CATStateCommand are called on the Activate
// method each time the state they belong to is entered, even when a 
// transition loops on the same state.
// With CATDlgEngAgentActivationWhenChangingState, the Activate method is 
// called only when the state changes. (idem for Cancel)
/** @nodoc */
#define CATDlgEngAgentActivationWhenEnteringState (1 << 15)
/** @nodoc */
#define CATDlgEngAgentActivationWhenChangingState (1 << 16)


// default = CATDlgEngOldTrigger
// By default, the conditions are tested when an agent is valued or when
// entering a state if the state contains no agent or if one of its agents 
// is valued and is OneShot 
// With CATDlgEngNewTrigger, the conditions are tested when an agent is 
// valued or when entering a new state whatever ist agents or when entering
// the same state after a loop if an event has occured during the loop.
/** @nodoc */
#define CATDlgEngOldTrigger (1 << 17)
/** @nodoc */
#define CATDlgEngNewTrigger (1 << 18)

// default = CATDlgEngOldUndoManager
// By default, InitializeAcquisition is undone when the lattest acquisition is
// undone, which is not the right moment for all the scenari. Moreover, it is
// never redone (InitializeAcquisition must be programmed in Redo action too.
// In the same way, SetValuation or Accept is undone only when it is 
// programmed when receiving notifications, not during actions. 
// With CATDlgEngNewUndoManagger, InitializeAcquisition, Accept and 
// SetValuation always register an event which will be undone or redone in the
// right order. It is no use using InitialiseAcquisition in a Redo action.
/** @nodoc */
#define CATDlgEngOldUndoManager (1 << 19)
/** @nodoc */
#define CATDlgEngNewUndoManager (1 << 20)

// default = CATDlgEngEmptyPSO
// By default, a ResetPrevaluation empties the PSO.
// With CATDlgEngNoEmptyPSO, only the objects linked to the prevaluation are
// removed from the PSO.
// This a command behavior. And it is applied on all the CATPathElementAgent
// in the command.
/** @nodoc */
#define CATDlgEngEmptyPSO          (1 << 21)
/** @nodoc */
#define CATDlgEngNoEmptyPSO        (1 << 22)

// used for Light Edit commands
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngParallel             (((CATDlgEngBehavior)1) << 35)
#else
#define CATDlgEngParallel             (1LL << 35)
#endif

// used for commands that do not want to add an undo step when started
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngWithoutUndoStart     (((CATDlgEngBehavior)1) << 39)
#else
#define CATDlgEngWithoutUndoStart     (1LL << 39)
#endif

// used for consuming commands that do not want to save transactions
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngNoTransaction        (((CATDlgEngBehavior)1) << 36)
#else
#define CATDlgEngNoTransaction        (1LL << 36)
#endif
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngNoTransactionNoWarning (((CATDlgEngBehavior)1) << 46)
#else
#define CATDlgEngNoTransactionNoWarning (1LL << 46)
#endif
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngFlushTransactions (((CATDlgEngBehavior)1) << 55)
#else
#define CATDlgEngFlushTransactions (1LL << 55)
#endif

// used for consuming commands that want to empty Undo stacks when finished
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngEmptyUndoAtEnd  (((CATDlgEngBehavior)1) << 47)
#else
#define CATDlgEngEmptyUndoAtEnd  (1LL << 47)
#endif

// used for commands which request drill selection when possible
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngDrillFilter  (((CATDlgEngBehavior)1) << 48)
#else
#define CATDlgEngDrillFilter  (1LL << 48)
#endif

// used for commands allowed to make not undoable modifications
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngFlushCheck  (((CATDlgEngBehavior)1) << 50)
#else
#define CATDlgEngFlushCheck  (1LL << 50)
#endif

// used for commands allowed to make forbidden modifications
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngCancelCheck  (((CATDlgEngBehavior)1) << 51)
#else
#define CATDlgEngCancelCheck  (1LL << 51)
#endif

// used for commands not allowed to dirty the session
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngNoDirtyCheck  (((CATDlgEngBehavior)1) << 52)
#else
#define CATDlgEngNoDirtyCheck  (1LL << 52)
#endif

// used for commands modifying CSO and dealing with HSO update
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngOwnCSOHSOManagement  (((CATDlgEngBehavior)1) << 53)
#else
#define CATDlgEngOwnCSOHSOManagement  (1LL << 53)
#endif

// used for agents triggering a local save.
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngTriggersLocalSave  (((CATDlgEngBehavior)1) << 54)
#else
#define CATDlgEngTriggersLocalSave  (1LL << 54)
#endif


//------------------------------------------------------------------
//                      CATOtherDocumentAgent
//------------------------------------------------------------------

// By default, the document where the agent was activated is reactivated
// when the agent is desactivated.
// With CATDlgEngNotReactivated, the last active document remains active.
/** @nodoc */
#ifdef _WINDOWS_SOURCE
#define CATDlgEngNotReactivated       (((CATDlgEngBehavior)1) << 37)
#else
#define CATDlgEngNotReactivated       (1LL << 37)
#endif


//------------------------------------------------------------------
//                      CATAgentSet
//------------------------------------------------------------------

// default = CATDlgEngDispatchUntilAccept
// By default, a notification is dispatched to the agents of the current state
// until one agent accepts it.
// With CATDlgEngDispatchToAllAgents, the notification is dispatched to all 
// agents even if an agent accepts the notification.
/** @nodoc */
#define CATDlgEngDispatchUntilAccept         (1 << 11)
/** @nodoc */
#define CATDlgEngDispatchToAllAgents          (1 << 12)

#endif
