#ifndef CATDialogTransition_h
#define CATDialogTransition_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0STATE.m

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

class CATDiaAction;
class CATCommand;
class CATDialogState;
class CATCmdEvent;

#include "CATStateCondition.h"
#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATListOfCATDialogState.h"
//#include "CATListOfCATBaseUnknown.h"
#include "CATLISTP_CATBaseUnknown.h"
#include "CATListOfInt.h"

/**
 * Class to create a command transition.
 * <b>Role</b>: A transition is one of the main elements of a state dialog 
 * command which is a state machine that uses states to let the end user 
 * input the requested parameters, and transitions between states to process 
 * these input parameters and progress in the statechart.
 * <br>Do not use the <tt>CATDialogTransition</tt> constructor to create a 
 * transition but the @href CATStateCommand#Addtransition method.
 * <br>A transition must have at least one source state, a target state which
 * may be NULL, and may be associated with a condition and an action.
 * <br>
 * Transitions must be created in the @href CATStateCommand#BuildGraph method.
 * @see CATDialogState, CATStateCondition, CATDiaAction
 */

class ExportedByCATDialogEngine CATDialogTransition : public CATBaseUnknown
{

  /** @nodoc */
  CATDeclareClass;
  
public:
  
  virtual ~CATDialogTransition ();
 
  // complete the construction of a transition
  
  /*-------------------------*/
  //     ACTIONS
  /*-------------------------*/     
  
  /**
  * Sets the transition action.
  * <br><b>Role</b>: This action is executed when a transition fires.
  * <br>Since a transition has only one action, successive calls to 
  * <tt>SetAction</tt> for the same transition successively overwrite the 
  * action.
  * @param iAction
  *   The action.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iAction</tt> is kept and
  *   AddRef'ed. It is Released at the end of the command before the command 
  *   destructor call.
  *   <br><b>Legal values</b>: <tt>iAction</tt> may be set to NULL to cancel 
  *   an action inherited from the command base class. 
  */
  virtual void SetAction (CATDiaAction * iAction);
  
  /**
  * Returns the transition action.
  * <br><b>Role</b>: This action is executed when a transition fires.
  * @return
  *   The action.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATDiaAction * GetAction () const;
  
  
  /*-------------------------*/
  //     CONDITIONS
  /*-------------------------*/     
  
  /**
  * Sets the transition condition.
  * <br><b>Role</b>: This condition must evaluate TRUE to make the transition
  * fire. 
  * <br>Since a transition has only one condition, successive calls to 
  * <tt>SetCondition</tt> for the same transition successively overwrite the 
  * condition.
  * @param iCond
  *   The condition.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iCond</tt> is kept and 
  *   AddRef'ed. It is Released at the end of the command before the command 
  *   destructor call.
  *   <br><b>Legal values</b>: <tt>iCond</tt> may be set to NULL to cancel 
  *   a condition inherited from the command base class. 
  */
  virtual void SetCondition (CATStateCondition * iCond);
  
  /**
  * Returns the transition condition.
  * <br><b>Role</b>: This condition must evaluate TRUE to make the transition
  * fire. 
  * @return 
  *   The condition.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATStateCondition * GetCondition () const;
  
  
  /*-------------------------*/
  //     STATES
  /*-------------------------*/     
  
  /**
  * Adds a source state to the transition.
  * @param iState
  *   The state.
  *   <br><b>Cyclic reference</b>: A pointer to the state is kept, and 
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor call or when the state is removed.
  */
  void AddInitialState (CATDialogState * iState);
  
  /**
  * Removes a source state from the transition.
  * @param iState
  *   The state.
  */
  void RemoveInitialState (CATDialogState * iState);
  
  /**
  * Returns the count of source states.
  * <br><b>Role</b>: The count of source states ranges from 1 to n.
  * @return
  *   The source state count.
  */
  int GetInitialStateNumber ();
  
  /**
  * Returns a source state using the source state index.
  * <br><b>Role</b>: This method returns the <tt>iIndex</tt>th source state.
  * @param iIndex
  *   The index.
  *   <br><b>Legal values</b>: <tt>iIndex</tt> range starts with 1, which is 
  *   the default.
  *   Use @href #GetInitialStateNumber to get the source state count.
  * @return
  *   The state.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the
  *    returned value.
  */
  CATDialogState * GetInitialState (int iIndex=1);
  
  /**
  * Sets the target state.
  * <br><b>Role</b>: Since a transition has only one target state, successive
  * calls to <tt>SetFinalState</tt> for the same transition successively 
  * overwrite the target state.
  * @param iState
  *   the state.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iState</tt> is kept and
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor call or when the state is removed.
  *   <br><b>Legal values</b>: <tt>iState</tt> may be set to NULL to cancel 
  *   a state inherited from the command base class. 
  */
  void SetFinalState (CATDialogState * iState);
  
  /**
  * Returns the target state.
  * @return
  *   The state.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  CATDialogState * GetFinalState () const;
  
  
  /*-------------------------*/
  //     RESOURCE ID
  /*-------------------------*/     
  
  /**
  * Sets the resource identifier.
  * <br><b>Role</b>: This identifier is used to retrieve the Undo/Redo titles 
  * in the command message file.
  * @param iId
  *   The resource identifier.
  */
  void SetResourceID (const CATString & iId);
  
  /**
  * Retrieves the resource identifier.
  * <br><b>Role</b>: This identifier is used to retrieve the Undo/Redo titles
  * in the command message file.
  * @return
  *   The resource identifier.
  */
  CATString & GetResourceID ();


  /*-------------------------*/
  //     FOR INTERNAL USE 
  /*-------------------------*/     
  
  /* transition creation is hidden in the CATStateCommand::AddTransition method */ 
  /** @nodoc */
  CATDialogTransition (CATDialogState *, CATDialogState *);
  /** @nodoc */
  CATDialogTransition ();
  
  // get the elements which compose the transition
  
  /** @nodoc */
  void SetCommand (CATCommand *);
  /** @nodoc */
  CATCommand * GetCommand () const;
  
  /** @nodoc */
  void InitInitialStateList ();
  /** @nodoc */
  CATDialogState * GetNextInitialState ();
  
  /** @nodoc */
  void ReleaseComponents ();
  
  /* for CAA2 L2 */
  /** @nodoc */
  CATCmdEvent * GetEvent (int Num);
  /** @nodoc */
  int GetEventNumber ();
  /** @nodoc */
  void AddEvent (CATCmdEvent * Event);
  /** @nodoc */
  void RemoveEvent (CATCmdEvent * Event);
  /** @nodoc */
  CATBoolean IsTriggered (); 
  /** @nodoc */
  void  InitEventStatus ();
  
  /* execution of the condition and action associated with the transition */
  /** @nodoc */
  CATBoolean Precondition ();
  /** @nodoc */
  void ExecuteTransition (int InitialStateNumber=1);
  /** @nodoc */
  void BeforeUndo (int InitialStateNumber=1);
  /** @nodoc */
  void BeforeRedo (int InitialStateNumber=1);
  /** @nodoc */
  void AfterUndo (int InitialStateNumber=1);
  /** @nodoc */
  void AfterRedo (int InitialStateNumber=1);
  
  /** @nodoc */
  void Dump (int offTraces=0);  

  /* management of UndoTitle */
  /** @nodoc */
  CATUnicodeString & GetUndoTitle ();
  /** @nodoc */
  CATUnicodeString & GetRedoTitle ();
  /** @nodoc */
  void SetUndoTitle (const CATUnicodeString & Text);
  /** @nodoc */
  void SetRedoTitle (const CATUnicodeString & Text);
  
protected:
  
  /*------------------*/
  // internal data 
  /*------------------*/
  
  CATLISTP(CATDialogState) _initialStateList; 
  CATLISTP(CATBaseUnknown) _EventList; 
  CATListOfInt        _StatusList; 
  CATDialogState    * _finalState;
  CATCommand        * _command;  // state command which builds the graph
  CATStateCondition * _condition;   
  CATDiaAction      * _action;   
  
  CATUnicodeString   _UndoTitle;
  CATUnicodeString   _RedoTitle;
  CATString          _resourceID;
  int _InitialStateListIndice;
  int _offTraces;
  
private:
  
  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATDialogTransition (const CATDialogTransition &);
  CATDialogTransition & operator= (const CATDialogTransition &);
  
};

#endif
