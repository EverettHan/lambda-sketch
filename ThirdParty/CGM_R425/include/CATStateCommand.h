#ifndef CATStateCommand_H
#define CATStateCommand_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0STATE.m

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATDialogAgent.h"

#include "CATDlgEngUtility.h"
#include "CATDiaAction.h"
#include "CATDialogState.h"
#include "CATStateCondition.h"
#include "CATAcquisitionFilter.h"
#include "CATDiaError.h"
// fw Dialog
#include "CATDialog.h"
// fw System
#include "CATCommand.h"
#include "CATUnicodeString.h"
#include "CATBooleanDef.h"

class CATDialogTransition;
class CATCommandGlobalUndo;
class CATString;
class CATFrmEditor;
class CATBaseUnknown;


/** @nodoc*/
#define DE2ACTION(...) _Action(0, #__VA_ARGS__, __VA_ARGS__)
#define DE2CONDITION(...) _Condition(0, #__VA_ARGS__, __VA_ARGS__)
#define DE2FILTER(...) _Filter(0, #__VA_ARGS__, __VA_ARGS__)


/**
 * Base class for a State Command.
 * <b>Role</b>: A State Command is a command modeled as a state machine.
 * It is a graph made of states linked between them using incoming and
 * outgoing transitions. 
 * The states are composed of dialog agents which let the end user input the
 * requested parameters. 
 * Conditions may be associated with states and transitions in order to 
 * guide the progression according to the user inputs. Actions are linked
 * to states and transition to execute the know-how of the command.
 * <br>
 * To create a State Command, derive the <tt>CATStateCommand</tt> class and 
 * override the methods:
 * <ul>
 * <li>@href CATCommand#Activate </li>
 * <li>@href CATCommand#Desactivate </li>
 * <li>@href CATCommand#Cancel </li>
 * </ul>
 * if needed to manage the activation cycle and above all
 * <ul>
 * <li>@href #BuildGraph </li> called once before the first @href 
 * CATCommand#Activate method
 * </ul>
 * in order to build the state chart.
 * <p>
 * <b>Life cycle</b>
 * <p>
 * In general, a main State Command is allocated by the command header
 * and is deallocated by the internal focus mechanism.
 * <br>A main State Command ends when:
 * <ul>
 * <li>another exclusive command is activated:
 * the State Command is cancelled by the focus manager.</li>
 * <li>the NULL state is reached:
 * the State Command cancels itself.</li>
 * <li>the Cancel state is reached:
 * same as the NULL state, but a global Undo is executed.</li>
 * <li>the @href CATCommand#RequestDelayedDestruction method is called:
 * a good State Command prefers to use transitions towards the NULL state.</li>
 * </ul>
 * <p>
 * <b>Error Management during execution</b>
 * <p>
 * Exceptions thrown during condition evaluation or action execution must be caught
 * by the condition methods or the action methods.
 * <br>Nevertheless, if DialogEngine catches one, the main State Command is desactivated
 * while a default error dialog box displays information about the error.
 * Then the main State Command resumes after the error dialog box is closed.
 * 
 * @see CATDialogState, CATDialogTransition, CATStateCondition, CATDiaAction, CATDialogAgent
 */

class ExportedByCATDialogEngine CATStateCommand : public CATDialogAgent
{
  
  /** @nodoc */
  CATDeclareClass;
  
public:
  
  /**
  * Constructs a State Command.
  * @param iId
  *   The command identifier. It must be unique and is used to retrieve the 
  *   undo/redo titles in the command message file.
  * @param iBehavior
  *   The behavior of the command.
  * @param iMode
  *   The focus mode.
  *   <br><b>Legal values</b>: With the default mode 
  *   <tt>CATCommandModeExclusive</tt>, the command takes the focus and 
  *   cancels the other commands. This mode is mandatory if the command 
  *   modifies the model.
  *   <br>The other possible mode is <tt>CATCommandModeShared</tt>: the command
  *   only deactivates the active command and takes the focus. The previous
  *   command will resume when the current command ends.
  *   <br>The <tt>CATCommandModeUndefined</tt> mode is forbidden with a main
  *   State Command since it needs to take the focus, but must be used for a
  *   State Command used as an agent of another State Command.
  */
  CATStateCommand (const CATString & iId, 
                   CATDlgEngBehavior iBehavior=NULL, 
                   CATCommandMode iMode=CATCommandModeExclusive);
  
  /** @nodoc
  * Constructor reserved for CATSelect (the SELECT command) and CATEditAgent only
  */
  CATStateCommand (const CATString & iId, 
                   CATFrmEditor * iEditor,
                   CATDlgEngBehavior iBehavior=NULL, 
                   CATCommandMode iMode=CATCommandModeExclusive,
                   CATBoolean iCreateImpl=TRUE);
  /** @nodoc
  * Constructor reserved for P3 commands only
  */
  CATStateCommand (const CATString & iId, 
                   CATCommand * iFather,
                   CATDlgEngBehavior iBehavior=NULL, 
                   CATCommandMode iMode=CATCommandModeExclusive);

  /**
  * @nodoc
  * OBSOLETE : Do not use
  */
  CATStateCommand (CATCommandMode iMode=CATCommandModeExclusive);
  /**
  * @nodoc
  * OBSOLETE : Do not use
  */
  CATStateCommand (const CATString & iId,
                   CATCommandMode iMode);
  
  virtual ~CATStateCommand ();
  
  /*---------------------------------*/
  //     GRAPH DEFINITION  
  /*---------------------------------*/
  
  /**
  * Builds the command statechart.
  * <br><b>Role</b>: Override this method to define the command graph.
  */
  virtual void BuildGraph (); 
  
  /** @nodoc
  * Manages the light edit manipulators.
  * <br><b>Role</b>: Override this method to manage the light edit manipulators
  * <br>This is to be called instead of BuildGraph for undefined commands with the
  * CATDlgEngParallel behavior.
  */
  virtual void BuildParallel (); 
  
  /** @nodoc
  * BuildGraph() internal header
  */
  virtual HRESULT CreateGraph (); 
  
  
  /*---------------------------------*/
  //           STATES  
  /*---------------------------------*/
  
  /**
  * Creates the initial state or retrieves it if it already exists.
  * <br><b>Role</b>: The initial state is the state with which the command 
  * starts. There is only one initial state.
  * @param iId
  *   The resource identifier used to retrieve the state prompt in the command
  *   message file.
  *   This identifier is useful only if the initial state doesn't already
  *   exist. 
  * @return 
  *   The initial state.
  *   <br><b>Cyclic reference</b>: A pointer to the state is kept and
  *   Released at the end of the command before the command destructor call.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATDialogState * GetInitialState (const CATString & iId);
  
  /** @nodoc
  * same as GetInitialState("InitialState")
  */
  virtual CATDialogState * GetInitialState ();
  
  /**
  * Creates the cancel state or retrieves it if it already exists.
  * <br><b>Role</b>: When the dialog reaches the cancel state, the command
  * ends as if it had reached the NULL state, and a global undo is executed.
  * @return 
  *   The cancel state.
  *   <br><b>Cyclic reference</b>: A pointer to the state is kept and
  *   Released at the end of the command before the command destructor call.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATDialogState * GetCancelState ();
  
  /**
  * Creates a state.
  * @param iId
  *   The resource identifier used to retrieve the state prompt in the command
  *   message file.
  * @return 
  *   The state.
  *   <br><b>Cyclic reference</b>: A pointer to the state is kept and
  *   Released at the end of the command before the command destructor call.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATDialogState * AddDialogState (const CATString &iId);
  
  /**
  * Adds an existing state to the command.
  * <br><b>Role</b>: Use this method only with @href CATPanelState states. 
  * Otherwise, use the @href #AddDialogState method which creates and adds the
  * state in the same time.
  * @param iState
  *   The state.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iState</tt> is kept, and
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor call.
  */
  virtual void AddDialogState (CATDialogState * iState);
  
  /**
  * Declares a state as the initial state.
  * <br><b>Role</b>: May be useful if you need to modify a graph inherited 
  * from the base class but don't use it dynamically during the dialog.
  * It replaces the previous initial state but this former state still
  * belongs to the graph. 
  * @param iState
  *   The new initial state.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iState</tt> is kept and
  *   AddRef'ed. It is Released at the end of the command before the command 
  *   destructor
  *   call.
  */
  virtual void SetInitialState (CATDialogState * iState);
  
  /**
  * Removes a state from a command.
  * <br><b>Role</b>: May be useful if you need to modify a graph inherited 
  * from the base class but don't use it dynamically during the dialog.
  * <br>This state must not be linked to a transition (the transition must be
  * removed first) and must not be the cancel state nor the initial state.
  * @param iState
  *   The state to remove.
  * @return 
  *   The error return code.
  *   <br><b>Legal values</b>:  
  *   <ul>
  *   <li>0: the state is removed successfully.</li>
  *   <li>1: the state is not found.</li>
  *   <li>2: the remove operation failed because the state is still useful.
  *          (it is the initial or the cancel state or it is linked to a 
  *          transition.</li>
  *   </ul>
  */
  virtual int RemoveState (CATDialogState * iState);
  
  /**
  * Points to the first command state.
  * @see #GetNextState 
  */
  virtual void InitStateList ();
  
  /**
  * Returns the pointed command state and points to the next one.
  * <br><b>Precondition</b>: Set the pointer to the first command state
  * using @href #InitStateList before traversing out the command state
  * list using calls to <tt>GetNextState</tt> enclosed in a loop.
  * @return 
  *   The pointed state.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATDialogState * GetNextState ();
  
  
  /*---------------------------------*/
  //      TRANSITIONS  
  /*---------------------------------*/
  
  /**
  * Creates a transition given its source and target states.
  * @param iSource
  *   The source state.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iSource</tt> is kept and 
  *   AddRef'ed. It is Released at the end of the command before the command 
  *   destructor call.
  * @param iTarget
  *   The target state.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iTarget</tt> is kept and
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor call.
  *   <br><b>Legal values</b>: The target state may be NULL to represent the
  *   end of the command.  
  * @return 
  *   The transition.
  *   <br><b>Cyclic reference</b>: A pointer to the transition is kept and
  *   Released at the end of the command before the command destructor call.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATDialogTransition * AddTransition (CATDialogState * iSource,
                                               CATDialogState * iTarget);
  
  /**
  * Creates a transition given its source and target states, its condition 
  * and its action.
  * @param iSource
  *   The source state.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iSource</tt> is kept and
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor call.
  * @param iTarget
  *   The target state.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iTarget</tt> is kept and
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor  call.
  *   <br><b>Legal values</b>: The target state may be NULL to represent the
  *   end of the command.  
  * @param iCondition
  *   The condition.
  *   <br><b>Legal values</b>: The condition may be NULL or specified later
  *   by the @href CATDialogTransition#SetCondition method. A NULL condition 
  *   evaluates TRUE, so the transition fires at the first agent valuation.
  * @param iAction
  *   The action.
  *   <br><b>Legal values</b>: The action may be NULL or specified later
  *   by the @href CATDialogTransition#SetAction method.
  * @return 
  *   The transition.
  *   <br><b>Cyclic reference</b>: A pointer to the transition is kept and
  *   Released at the end of the command before the command destructor call.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATDialogTransition * AddTransition (CATDialogState * iSource,
                                               CATDialogState * iTarget, 
                                               CATStateCondition * iCondition,
                                               CATDiaAction * iAction);
  
  /**
  * Creates a transition given its source and target states, and its condition.
  * @param iSource
  *   The source state.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iSource</tt> is kept and
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor call.
  * @param iTarget
  *   The target state.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iTarget</tt> is kept and
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor  call.
  *   <br><b>Legal values</b>: The target state may be NULL to represent the
  *   end of the command.  
  * @param iCondition
  *   The condition.
  *   <br><b>Legal values</b>: The condition may be NULL or specified later
  *   by the @href CATDialogTransition#SetCondition method. A NULL condition 
  *   evaluates TRUE, so the transition fires at the first agent valuation.
  * @return 
  *   The transition.
  *   <br><b>Cyclic reference</b>: A pointer to the transition is kept and
  *   Released at the end of the command before the command destructor call.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATDialogTransition * AddTransition (CATDialogState * iSource,
                                               CATDialogState * iTarget,
                                               CATStateCondition * iCondition);
  
  /**
  * Creates a transition given its source and target states, and its action.
  * @param iSource
  *   The source state.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iSource</tt> is kept and
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor call.
  * @param iTarget
  *   The target state.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iTarget</tt> is kept and
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor  call.
  *   <br><b>Legal values</b>: The target state may be NULL to represent the
  *   end of the command.  
  * @param iAction
  *   The action.
  *   <br><b>Legal values</b>: The action may be NULL or specified later
  *   by the @href CATDialogTransition#SetAction method.
  * @return 
  *   The transition.
  *   <br><b>Cyclic reference</b>: A pointer to the transition is kept and
  *   Released at the end of the command before the command destructor call.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATDialogTransition * AddTransition (CATDialogState * iSource,
                                               CATDialogState * iTarget,
                                               CATDiaAction * iAction);
  
  /** @nodoc */
  virtual void AddTransition (CATDialogTransition * trans);
  
  
  /**
  * Points to the first command transition.
  * @see #GetNextTransition 
  */
  virtual void InitTransitionList ();
  
  /**
  * Returns the pointed command transition and points to the next one.
  * <br><b>Precondition</b>: Set the pointer to the first command transition
  * using @href #InitTransitionList before traversing out the command 
  * transition list using calls to <tt>GetNextTransition</tt> enclosed in a
  * loop.
  * @return 
  *   The pointed transition.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATDialogTransition * GetNextTransition ();
  
  /**
  * Removes a transition from a command.
  * <br><b>Role</b>: May be useful if you need to modify a graph inherited 
  * from the base class but don't use it dynamically during the dialog.
  * @param iTrans
  *   The transition to remove.
  * @return 
  *   The error return code.
  *   <br><b>Legal values</b>:  
  *   <ul>
  *   <li>0: the transition is removed successfully.</li>
  *   <li>1: the transition is not found.</li>
  *   </ul>
  */
  virtual int RemoveTransition (CATDialogTransition * iTrans);
  
  
  /*---------------------------------*/
  //      ACTIONS  
  /*---------------------------------*/
  
  /**
  * Creates a composite action which combines actions using the AND operator.
  * <br><b>Role</b>: The <tt>iAct1</tt> action is executed first. Then the
  * <tt>iAct2</tt> action is executed whatever <tt>iAct1</tt> returned.
  * @param iAct1
  *   The first action to execute.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iAct1</tt> is kept and 
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor call.
  * @param iAct2
  *   The second action to execute.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iAct2</tt>is kept and
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor call.
  * @return 
  *   The composite action.
  *   <br><b>Cyclic reference</b>: A pointer to the action is kept and
  *   Released at the end of the command before the command destructor call.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  CATDiaAction * AndAction (CATDiaAction * iAct1, CATDiaAction * iAct2);
  
  /**
  * Creates a composite action which combines actions using the OR operator.
  * <br><b>Role</b>: The <tt>iAct1</tt> action is executed first. Then the 
  * <tt>iAct2</tt> action is executed only if <tt>iAct1</tt> returned TRUE.
  * @param iAct1
  *   The first action to execute.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iAct1</tt> is kept and 
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor call.
  * @param iAct2
  *   The second action to execute.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iAct2</tt> is kept and 
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor call.
  * @return 
  *   The composite action.
  *   <br><b>Cyclic reference</b>: A pointer to the action is kept and
  *   Released at the end of the command before the command destructor call.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  CATDiaAction * OrAction (CATDiaAction * iAct1 , CATDiaAction * iAct2);
  
  /**
  * Creates an action given the addresses of the methods to execute.
  * <br><b>Role</b>: These methods must be methods of the current state
  * command.
  * @param iDo
  *   The method to execute in the normal mode.
  * @param iBeforeUndo
  *   The method to undo what has been done in the <tt>iDo</tt> method.
  *   This method is executed before the transaction undo and must not 
  *   modify transactional objects.
  * @param iBeforeRedo
  *   The method to redo what has been done in the <tt>iDo</tt> method.
  *   This method is executed before the transaction redo and must not 
  *   modify transactional objects.
  * @param iData
  *   An object that can be useful for the action.
  *   This data will be given as the argument of the 
  *   <tt>ActionMethod</tt> methods.
  *   <br><b>Warning</b>: A copy of <tt>iData</tt> is kept. 
  *   Deallocate this object only in the command destructor.
  * @return 
  *   The action.
  *   <br><b>Cyclic reference</b>: A pointer to the action is kept and
  *   Released at the end of the command before the command destructor call.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  CATDiaAction * Action (ActionMethod iDo, 
                         ActionMethod iBeforeUndo=NULL,
                         ActionMethod iBeforeRedo=NULL, 
                         void * iData=NULL);

  /*---------------------------------*/
  //      CONDITIONS  
  /*---------------------------------*/
  
  /**
  * Creates a composite condition which combines conditions using the 
  * AND operator.
  * <br><b>Role</b>: The AND condition returns TRUE if its subconditions
  * return both TRUE.
  * The <tt>iCond1</tt> condition is evaluated first. Then the <tt>iCond2</tt>
  * condition is evaluated only if <tt>iCond1</tt> returned TRUE.
  * @param iCond1
  *   The first condition to evaluate.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iCond1</tt> is kept and 
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor call.
  * @param iCond2
  *   The second condition to evaluate.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iCond2</tt> is kept and 
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor call.
  * @return 
  *   The composite condition.
  *   <br><b>Cyclic reference</b>: A pointer to the condition is kept and
  *   Released at the end of the command before the command destructor call.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  CATStateCondition * AndCondition (CATStateCondition * iCond1, 
                                    CATStateCondition * iCond2);
  
  /**
  * Creates a composite condition which combines conditions using the 
  * OR operator.
  * <br><b>Role</b>: The OR condition returns TRUE if one of its subconditions
  * returns TRUE.
  * The <tt>iCond1</tt> condition is evaluated first. Then the <tt>iCond2</tt>
  * condition is evaluated only if <tt>iCond1</tt> returned FALSE.
  * @param iCond1
  *   The first condition to evaluate.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iCond1</tt> is kept and 
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor call.
  * @param iCond2
  *   The second condition to evaluate.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iCond2</tt> is kept and 
  *   AddRef'ed. It is Released at the end of the command before the command 
  *   destructor call.
  * @return 
  *   The composite condition.
  *   <br><b>Cyclic reference</b>: A pointer to the condition is kept and
  *   Released at the end of the command before the command destructor call.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  CATStateCondition * OrCondition (CATStateCondition * iCond1, 
                                   CATStateCondition * iCond2);
  
  /**
  * Creates a composite condition which uses the NOT operator on its 
  * subcondition.
  * <br><b>Role</b>: The NOT condition returns TRUE if its subcondition 
  * returns FALSE.
  * @param iCond
  *   The subcondition.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iCond</tt> is kept and
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor call.
  * @return 
  *   The composite condition.
  *   <br><b>Cyclic reference</b>: A pointer to the condition is kept and
  *   Released at the end of the command before the command destructor call.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  CATStateCondition * NotCondition (CATStateCondition * iCond);
  
  /**
  * Creates a condition given the address of a method to execute.
  * <br><b>Role</b>: This method must be a method of the current State Command.
  * @param iEvaluate
  *   The method to execute to evaluate the condition.
  * @param iData
  *   An object that can be useful for the condition.
  *   This data will be given as the argument of the 
  *   <tt>iEvaluate</tt> method.
  *   <br><b>Warning</b>: A copy of <tt>iData</tt> is kept. 
  *   Deallocate this object only in the command destructor.
  * @return 
  *   The condition.
  *   <br><b>Cyclic reference</b>: A pointer to the condition is kept and
  *   Released at the end of the command before the command destructor call.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  CATStateCondition * Condition (ConditionMethod iEvaluate, 
                                 void * iData=NULL);
 
  /**
  * Creates a NOT condition given the address of a method to execute.
  * <br><b>Role</b>: This method must be a method of the current State Command.
  * <br>The condition returns TRUE if the method returns FALSE.
  * @param iEvaluate
  *   The method to execute to evaluate the condition.
  *   This method gives a result opposite to the condition result.
  * @param iData
  *   An object that can be useful for the condition.
  *   This data will be given as the argument of the 
  *   <tt>iEvaluate</tt> method.
  *   <br><b>Warning</b>: A copy of <tt>iData</tt> is kept. 
  *   Deallocate this object only in the command destructor.
  * @return 
  *   The condition.
  *   <br><b>Cyclic reference</b>: A pointer to the condition is kept and
  *   Released at the end of the command before the command destructor call.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  CATStateCondition * NotCondition (ConditionMethod iEvaluate, 
                                    void * iData=NULL);
  
  /**
  * Creates a condition which checks whether an agent is valued.
  * <br><b>Role</b>: The condition evaluates TRUE if the <tt>iAgent</tt> agent
  * is valued.
  * @param iAgent
  *   The agent.
  * @return 
  *   The condition.
  *   <br><b>Cyclic reference</b>: A pointer to the condition is kept and
  *   Released at the end of the command before the command destructor call.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  CATStateCondition * IsOutputSetCondition (CATCommand * iAgent);
  
  /**
  * Creates a condition which checks whether an agent is the latest modified
  * agent.
  * <br><b>Role</b>: The condition evaluates TRUE if the <tt>iAgent</tt> agent
  * has just been modified and if it was due to a notification which belongs 
  * to the <tt>iNotifClass</tt> class.
  * @param iAgent
  *   The agent.
  * @param iNotifClass
  *   The notification class.
  *   <br><b>Legal values</b>: It can be NULL: the condition only checks if 
  *   the <tt>iAgent</tt> agent has just been modified.  
  * @return 
  *   The condition.
  *   <br><b>Cyclic reference</b>: A pointer to the condition is kept and
  *   Released at the end of the command before the command destructor call.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  CATStateCondition * IsLastModifiedAgentCondition (CATCommand * iAgent, 
                                                    const char * iNotifClass);
  
  /**
  * Creates a condition which checks whether an agent is the latest modified
  * agent.
  * <br><b>Role</b>: The condition evaluates TRUE if the <tt>iAgent</tt> agent
  * has just been modified and if it was due to the <tt>iNotif</tt> 
  * notification.
  * @param iAgent
  *   The agent.
  * @param iNotif
  *   The address of a notification.
  *   <br><b>Legal values</b>: It can be NULL: the condition only checks if 
  *   the <tt>iAgent</tt> agent has just been modified.  
  * @return 
  *   The condition.
  *   <br><b>Cyclic reference</b>: A pointer to the condition is kept and
  *   Released at the end of the command before the command destructor call.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  CATStateCondition * IsLastModifiedAgentCondition (CATCommand * iAgent, 
                                                    CATNotification * iNotif=NULL);
  
  
  /*---------------------------------*/
  //      FILTERS  
  /*---------------------------------*/
  
  /**
  * Creates an agent filter given the address of a method to execute.
  * <br><b>Role</b>: This method must be a method of the current State Command.
  * @param iMeth
  *   The method to filter the agent value.
  * @param iData
  *   An object that can be useful for the filter.
  *   This data will be given as the argument of the 
  *   <tt>iMeth</tt> method.
  *   <br><b>Warning</b>: A copy of <tt>iData</tt> is kept. 
  *   Deallocate this object only in the command destructor.
  * @return 
  *   The filter.
  *   <br><b>Cyclic reference</b>: A pointer to the filter is kept and
  *   Released at the end of the command before the command destructor call.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  * See also: @href CATDialogAgent#AndFilter, @href CATDialogAgent#OrFilter
  * and @href CATDialogAgent#NotFilter methods.
  */
  CATAcquisitionFilter * Filter (FilterMethod iMeth, void * iData);


  /*---------------------------------*/
  //      VALUATION FROM THE CSO  
  /*---------------------------------*/
  
  /**
  * Declares an agent as a CSO client.
  * <br><b>Role</b>: At the beginning of the command, @href 
  * CATPathElementAgent agents declared as CSO clients will try to get valued 
  * with the @href CATPathElement objects present in the CSO.
  * <br>If there is only one CSO client, with the CATDlgEngMultiAcquisition behavior,
  * it will decode a CATMultiSel notification gathering all the CSO content.
  * <br>Else all the objects in the CSO are taken into account separately, one after another.
  * For each object the CSO clients will decode a CATActivate notification.
  * All the objects in the CSO must be used. If at least one object in the CSO does not value any agent,
  * all the valuations from the CSO are then cancelled.
  * <br>This CSO client mecanism is useful to program object/action commands.
  * <br>As regards repeating commands, this mechanism only works at the first 
  * execution of the command.
  * @param iPathElementAgent
  *   The CATPathElementAgent agent to be valued from the CSO.
  */
  void AddCSOClient (CATCommand * iPathElementAgent);


  /*---------------------------------*/
  //      SDO MANAGEMENT
  /*---------------------------------*/
  
  /**
  * Sets the object in the CATSDO.
  * @param iObject
  *   This object is set in the SDO 
  * @see CATCommandHeaderWithSDOForAgent
  */
  void AddSDOElement (CATBaseUnknown * iObject);
  
  
  /*---------------------------------*/
  //     CURSOR
  /*---------------------------------*/
  
  /**
  * Sets a customized cursor.
  * <br><b>Role</b>: This method enables to display a cursor different
  * from the standard one.
  * @param iCursor
  *   The cursor.
  *   Use @href CATDialog#DefineCursor to define the new cursor.
  */
  void SetDefaultCursor (CATDialog::CATDlgHCursor iCursor);
  
  /**
  * Gets the customized cursor.
  * <br><b>Role</b>: This method retrieves the command customized cursor if any.
  * @return 
  *   The cursor.
  */
  CATDialog::CATDlgHCursor GetDefaultCursor ();

  /**
  * Resets the customized cursor.
  * <br><b>Role</b>: This method cancels previous uses of @href #SetDefaultCursor.
  */
  void ResetDefaultCursor ();


  /*---------------------------------*/
  //  INFORMATION ON THE PROCESS
  /*---------------------------------*/
  
  /**
  * Returns the current state.
  * <br><b>Role</b>: In a transition action, the current state is the source
  * state of the transition.
  * @return 
  *   The current state.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATDialogState * GetCurrentState () const;
  
  /**
  * Returns the agent which has just been modified.
  * @return 
  *   The agent.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATCommand * GetLastModifiedAgent () const;
  
  /**
  * Tests if an agent has just been modified.
  * @param iAgent
  *   The agent.
  * @return 
  *   The result of the test.
  */
  virtual CATBoolean IsLastModifiedAgent (CATCommand * iAgent) const;
  
  /**
  * Returns the latest notification.
  * <br><b>Role</b>: This method only works just after the notification 
  * reception. So it cannot be used in undo/redo methods.
  * @return
  *   The notification.
  */
  virtual CATNotification * GetLastNotification () const;
  
  /** @nodoc */
  virtual CATDialogAgent::ValuationMode GetLastModificationMode () const;
  
  
  /*---------------------------------*/
  //  UNDO/REDO MANAGEMENT
  /*---------------------------------*/
  
  /**
  * Tests if a redo is being processed.
  * <br><b>Role</b>: It may be useful if a method is used as a Do and a Redo
  * method, to avoid modifying transactional objects in Redo mode.
  * @return 
  *   The result of the test.
  *   <br><b>Legal values</b>:1 in redo mode, 0 in normal or undo mode.
  */
  virtual int IsRedoMode () const;
  
  /**
  * Returns the undo/redo object associated with the command.
  * <br><b>Role</b>: This method returns an object with methods to execute
  * when the command is undone or redone.
  * <br><b>Example of implementation</b>:
  * <p>in MyCommand.h:
  * <pre>
  *   protected:
  *     virtual CATCommandGlobalUndo * GetGlobalUndo ();
  *     static void UndoMethod (void * iData);
  *     static void RedoMethod (void * iData);
  *     static void DeallocateMethod (void * iData);
  * </pre>
  * in MyCommand.cpp:
  * <pre>
  *   //----------------------------------------------------------------------------
  *   CATCommandGlobalUndo * MyCommand::GetGlobalUndo ()
  *   {   
  *     // example of data used in Undo and/or Redo methods
  *     int * num = new int;
  *     *num = ...
  *     void * data = num;
  *     // define Undo object with Undo, Redoand Deallocate methods
  *     CATCommandGlobalUndo * Undo = new CATCommandGlobalUndo (
  *                                          (CATGlobalUndoMethod) &MyCommand::UndoMethod,
  *                                          (CATGlobalUndoMethod) &MyCommand::RedoMethod,
  *                                          data,
  *                                          (CATGlobalUndoMethod) &MyCommand::DeallocateMethod); 
  *     // return Undo object.
  *     return Undo;
  *   }
  *   //----------------------------------------------------------------------------
  *   void MyCommand::UndoMethod (void * Data)
  *   {
  *     int value = *((int*)Data);
  *     printf("UndoMethod : value = %d\n",value); fflush(stdout);
  *     ...
  *   }
  *   //----------------------------------------------------------------------------
  *   void MyCommand::RedoMethod (void * Data)
  *   {
  *     int value = *((int*)Data);
  *     printf("RedoMethod : value = %d\n",value); fflush(stdout);
  *     ...
  *   }
  *   //----------------------------------------------------------------------------
  *   void MyCommand::DeallocateMethod (void * Data)
  *   {
  *     int * pValue = (int*) Data;
  *     if (pValue) { delete pValue; pValue = NULL; }
  *   }
  * </pre>
  * @return
  *   The undo/redo object.
  */
  virtual CATCommandGlobalUndo * GetGlobalUndo ();
  
  /**
  * Adds a local Undo step.
  * <br><b>Role</b>: This method adds a local step in the Undo stack.
  * <br>When a transition is executed as a consequence of an explicit acquisition agent valuation
  *     (and not as a consequence of a user action) no Undo step is stacked (whatever the agent's behavior).
  *     This method enables you to explicitely add a local Undo step.
  * @param iUndoObject
  *   The Undo/Redo step manager for this step. No specific Undo/Redo step manager is requested
  *   if there is no specific need (Undo/Redo for features is already managed).
  * @param iUndoTitle
  *   The title displayed in the Undo history.
  * @param iUndoBehavior
  *   The behavior.
  *   <br><b>Legal values</b>:
  *   <br><tt>CATDlgEngWithUndoStep</tt>: The step is displayed in the Undo history (default).
  *   <br><tt>NULL</tt>: Reserved for internal usage.
  * @param iRedoAllowed
  *   Defines whether the Undo step will be redoable.
  * <br><b>Example of usage</b>: When a selection is expected, sometimes the user uses a contextual menu
  *    to create an element which will be explicitely got as an input for the selection as soon as
  *    it is created. This can be done by explicitely valuating an acquisition agent with the CSO content
  *    during resume of the main command.
  *    By default, the Undo command then undoes both selection and creation of the element.
  *    In order to enable the user to undo the selection without undoing the creation of the element,
  *    this method can be used to add a local Undo step.
  * <br><b>Example of implementation</b>:
  * <pre>
  *    CATPathElementAgent * curPathAgent = ...; 
  *    if (curPathAgent)
  *    {
  *      // create explicit local undo step
  *      CATCommandGlobalUndo * GlobalUndo = new CATCommandGlobalUndo;
  *      if (GlobalUndo)
  *      {
  *        AddLocalUndo(GlobalUndo,”MyStep”);
  *        GlobalUndo -> Release(); GlobalUndo = NULL;
  *      }
  *      // value curPathAgent
  *      curPathAgent -> SetValue(...);
  *      curPathAgent -> SetValuation();
  *    }
  * </pre>
  */
  void AddLocalUndo (CATCommandGlobalUndo * iUndoObject,
                     const CATUnicodeString & iUndoTitle,
                     CATDlgEngBehavior iUndoBehavior=CATDlgEngWithUndoStep,
                     CATBoolean iRedoAllowed=FALSE);
  /**
  * @nodoc
  * OBSOLETE
  */
  void AddLocalUndo (CATCommandGlobalUndo * UndoObject,
                     CATDlgEngBehavior UndoType=CATDlgEngWithUndoStep);
  
  /**
  * Requests to undo local steps in the State Command.
  * <br><b>Role</b>: This method can be used:
  * <ul>
  * <li>in the @href #Rescue method
  * or in the command which is in charge of the error management
  * (defined using the @href #SetErrorCommand method).</li>
  * <li>during an action execution.</li>
  * </ul>
  * It requests to undo local steps at the end of the transition.
  * @param iCount
  *   The number of local Undos to execute.
  *   <br><b>Legal values</b>: from one (default) to the number of local undos
  *   possible for the State Command.  
  * @param iRedoAllowed
  *   Defines whether the Undo steps will be redoable.
  */
  void RequestLocalUndo (int iCount=1, CATBoolean iRedoAllowed=FALSE);

  /**
  * @nodoc
  */
  void RequestLocalRedo (int iCount=1);
  
  /**
  * Requests to undo the State Command when it ends.
  * <br><b>Role</b>: This method can be used:
  * <ul>
  * <li>in the @href #Rescue method
  * or in the command which is in charge of the error management
  * (defined using the @href #SetErrorCommand method).</li>
  * <li>during an action execution.</li>
  * </ul>
  * It requests a global undo at the end of the State Command.
  * <br><b>Note</b>: It is recommended to use transitions towards the
  * Cancel state rather than using this method.
  */
  void ExecuteUndoAtEnd ();
  
  /**
  * Requests to forbid Undo before the next current state.
  * <br><b>Role</b>: This method can be used:
  * <ul>
  * <li>in the @href #Rescue method
  * or in the command which is in charge of the error management
  * (defined using the @href #SetErrorCommand method).</li>
  * <li>during an action execution.</li>
  * </ul>
  * It requests an emptying of the Undo stack. 
  */
  void ForbidUndo ();
  
  /**
  * Notifies that the Undo/Redo stack has been emptied as a consequence of an irreversible operation.
  * <br><b>Role</b>: This method can be overridden to perform any useful task after such an event occurred.
  */
  virtual void NotifyUndoRedoStackEmptied ();


  /*---------------------------------*/
  //  ERROR MANAGEMENT
  /*---------------------------------*/
  
  /**
  * Cleans data if an error occurs.
  * <br><b>Role</b>: Override this method to clean data after the
  * default error dialog box is closed.
  * <br><b>Warning</b>: If the @href #SetErrorCommand method is used, it is useless
  * to override this method.
  */
  virtual void Rescue ();
  
  /**
  * Sets a specific command to manage errors.
  * <br><b>Role</b>: This command replaces the default error dialog box displayed 
  * when an exception is caught during a condition evaluation or an action execution.
  * <br>It must be instantiated with the <tt>CATCommandModeUndefined</tt> mode
  * in the @href #BuildGraph method of the main State Command,
  * and the error treatment must be done in the overridden @href CATCommand#Activate method.
  * <br>When an exception occurs, DialogEngine requires a shared focus for this command
  * and after the error treatment the State Command resumes.
  * @see CATCommand 
  * @param iCmd
  *   The command.
  *   <br><b>Warning</b>: A pointer to the error command is kept 
  *   without being AddRef'ed. Deallocate this command only at the end of
  *   the main State Command.
  */
  void SetErrorCommand (CATCommand * iCmd);  
  
  /**
  * Returns the error caught by DialogEngine during a condition evaluation or
  * an action execution.
  * <br><b>Role</b>: This method can be used in the @href #Rescue method
  * or in the command which is in charge of the error management
  * to get information about the error.
  * @return 
  *   The error.
  */
  CATDiaError * GetError (); 


  /*--------------------*/
  //  CONTEXTUAL HELP
  /*--------------------*/
  
  /**
  * Gets LongHelpId information.
  * <br><b>Role</b>: Enables contextual help for commands not started through command headers.
  * @param oKey
  *   The key.
  *   <br>It must follow the standard LongHelpId syntax to be taken into account in the mapping file.
  * @param oCatalog
  *   Name of the resource catalog file, without the .CATRsc suffix.
  */
  virtual void GetLongHelpIdKey (CATString & oKey, CATString & oCatalog);
  
 
  /*--------------------*/
  //  DEBUG FACILITIES
  /*--------------------*/
  
  /**
  * Sets the debug mode.
  * <br><b>Role</b>: Activates or desactivates the State Command debug trace mode.
  * <br>When activated, information about the command and its components
  * is displayed in the standard output at different steps of its life cycle.
  * @param iMode
  *  <b>Legal values</b>:
  *  <br><tt>FALSE</tt> :The trace mode is not activated.
  *  <br><tt>TRUE</tt>  :The trace mode is activated.
  */
  void SetDebugMode (CATBoolean iMode);
  
  
  /*---------------------------------*/
  //  FOR INTERNAL USE
  /*---------------------------------*/
  
  
  /* notification reception */
  
  /** @nodoc */
  void ActivateCB (CATCommand * sendObject,
                   CATNotification * evt,
                   CATCommandClientData data);
  /** @nodoc */
  void DesactivateCB (CATCommand * sendObject,
                      CATNotification * evt,
                      CATCommandClientData data);
  /** @nodoc */
  void CancelCB (CATCommand * sendObject,
                 CATNotification * evt,
                 CATCommandClientData data);
  /** @nodoc */
  void AnalyseCB (CATCommand * Cmd,
                  CATNotification * Evt,
                  CATCommandClientData Data);
  
  /*---------------------------------*/
  //  FOR INTERNAL USE
  /*---------------------------------*/
  /** @nodoc */
  CATBoolean IsLaunchedInCurrentEditor();

  /**
  * Requests the state command delayed destruction.
  * <br><b>Role</b>: The state command will be destroyed as soon as this will be possible.
  * This must be used only when the state command is used as an agent of another state command,
  * in this state command's destructor.
  * This must not be used inside a state command to stop its execution.
  */
  virtual void RequestDelayedDestruction ();

protected:
  
  /*----------------------------------------------------------*/
  /* Set/Retrieve the agent properties	-DE² use-			*/
  /*----------------------------------------------------------*/
  /** @nodoc */
  virtual HRESULT _GetProperty(CATUnicodeString iPropertyId, CATBaseUnknown_var& iospPropValue);
  virtual HRESULT _SetProperty(CATUnicodeString iPropertyId, const CATListValCATBaseUnknown_var& ispPropValue);

  /** @nodoc*/
  /*DO NOT CALL THOSE FUNCTIONS DIRECTLY!!!!*/
  /*Internal use for DE² DUMP*/
  CATDiaAction *         _Action(int isDE2Command, ...);
  CATStateCondition *    _Condition(int isDE2Command, ...);
  CATAcquisitionFilter * _Filter(int isDE2Command, ...);
  /*Internal use for DE²*/
  CATDiaAction *         _DeclarativeAction(CATUnicodeString iDoMethodName, 
                                            ActionMethod     iDoMethod, 
                                            CATUnicodeString iBeforeUndoMethodName, 
                                            ActionMethod     iBeforeUndoMethod, 
                                            CATUnicodeString iBeforeRedoMethodName, 
                                            ActionMethod     iBeforeRedoMethod, 
                                            CATUnicodeString iAfterUndoMethodName, 
                                            ActionMethod     iAfterUndoMethod, 
                                            CATUnicodeString iAfterRedoMethodName, 
                                            ActionMethod     iAfterRedoMethod, 
                                            void* data);
  CATStateCondition *    _DeclarativeCondition(CATUnicodeString iConditionMethodName, ConditionMethod iConditionMethod, void* data);
  CATAcquisitionFilter * _DeclarativeFilter(CATUnicodeString iFilterMethodName, FilterMethod iFilterMethod, void* data);
  

private:

  /*Internal use for DE² DUMP*/
  CATListOfCATString  BuildArgNameArray(char*);  
  void                AddMethodToMethodHashMap( const CATULONGPTR *ippMethod, CATString iMethodName);
  void                AddMethodToMethodHashMap(ActionMethod iMethod, CATString iMethodName);
  void                AddMethodToMethodHashMap(FilterMethod iMethod, CATString iMethodName);

  friend class CATDE2DumpCppStateCommand;
};
#endif
