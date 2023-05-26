#ifndef CATDiaAction_h
#define CATDiaAction_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0STATE.m

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATBaseUnknown.h"
#include "CATString.h"
#include "CATDialogAgent.h"
#include "CATBooleanDef.h"

class CATDiaActionEngine;
class CATICmdAction;
class CATCommand;

 /**
  * Prototype of the action methods.
  * <b>Role</b>: These methods are passed as parameters of the @href 
  * CATDiaAction class methods.
  * @param iData
  *   The data specified by the @href CATDiaAction#SetData method.
  * @return 
  *   The CATBoolean value used to combine actions.
  *   In an OrAction, the second action is executed only if the first
  *   action returns TRUE.
  */
typedef CATBoolean (CATCommand::*ActionMethod)(void * iData);

/**
 * Base class to create a command action.
 * <b>Role</b>: An action is a task without interaction with the end user.
 * An action may be
 * <ul>
 * <li>linked to a transition. In this case, the action is executed when the
 *  transition fires. </li>
 * <li>a state entry action. In this case, the action is executed when 
 * entering the state. </li>
 * <li>a state exit action. In this case, the action is executed when 
 * leaving the state. </li>
 * </ul>
 * Moreover, a <tt>CATDiaAction</tt> object manages the action undo/redo. 
 * But, it must only undo/redo not transactional objects, that is to say 
 * the objects which don't belong to a model which implements the 
 * CATIUndoTransaction interface, because such a model undoes and redoes 
 * its objects itself.
 * <br>To create an action, you can derive this class and override the methods:
 * <ul>
 * <li>@href #Do </li>
 * <li>@href #BeforeUndo </li>
 * <li>@href #AfterUndo </li>
 * <li>@href #BeforeRedo </li>
 * <li>@href #AfterRedo </li>
 * </ul>
 * or use the @href CATStateCommand#Action method and give as arguments 
 * the addresses of methods to execute the action.  
 * <br>Actions must be created in the @href CATStateCommand#BuildGraph method.
 * @see CATDialogState, CATDialogTransition
 */

class ExportedByCATDialogEngine CATDiaAction : public CATBaseUnknown
{
  
  /** @nodoc  */
  CATDeclareClass;
  
public:
  
  /** @nodoc  */
  enum ActionType { ACTION, METHOD, AND, OR, DegMETH, INTERFACE, UNKNOWN};
  
  /**
  * Constructs an action.
  * <br><b>Role</b>: Use it only when deriving the <tt>CATDiaAction</tt> 
  * class, otherwise use the @href CATStateCommand#Action method to create an
  * action.
  * @param iName
  *   The name of the action. May be useful for debug.
  */
  CATDiaAction (const CATString &iName);
  
  virtual ~CATDiaAction ();
  
  /*--------------------------------------------*/
  //  methods to give data and method addresses
  /*--------------------------------------------*/
  
  /**
  * Sets the method to undo the action before the transactional undo.
  * <br><b>Role</b>: This method must be a method of the CATStateCommand 
  * object which defines the statechart.
  * <br>Do not use <tt>SetBeforeUndoMethod</tt> if you derive the 
  * <tt>CATDiaAction</tt> class.
  * @param iMeth
  *   The method which undoes the action.
  */
  virtual void SetBeforeUndoMethod (ActionMethod iMeth);
  
  /**
  * Sets the method to redo the action before the transactional redo.
  * <br><b>Role</b>: This method must be a method of the CATStateCommand 
  * object which defines the statechart.
  * <br>Do not use <tt>SetBeforeRedoMethod</tt> if you derive the 
  * <tt>CATDiaAction</tt> class.
  * @param iMeth
  *   The method which redoes the action.
  */
  virtual void SetBeforeRedoMethod (ActionMethod iMeth);
  
  /**
  * Sets the method to undo the action after the transactional undo.
  * <br><b>Role</b>: This method must be a method of the CATStateCommand 
  * object which defines the statechart.
  * <br>Do not use <tt>SetAfterUndoMethod</tt> if you derive the 
  * <tt>CATDiaAction</tt> class.
  * @param iMeth
  *   The method which undoes the action.
  */
  virtual void SetAfterUndoMethod (ActionMethod iMeth);
  
  /**
  * Sets the method to redo the action after the transactional redo.
  * <br><b>Role</b>: This method must be a method of the CATStateCommand 
  * object which defines the statechart.
  * <br>Do not use <tt>SetAfterRedoMethod</tt> if you derive the 
  * <tt>CATDiaAction</tt> class.
  * @param iMeth
  *   The method which redoes the action.
  */
  virtual void SetAfterRedoMethod (ActionMethod iMeth);
  
  /**
  * Sets the method to execute the action.
  * <br><b>Role</b>: This method must be a method of the CATStateCommand 
  * object which defines the statechart.
  * <br>Do not use <tt>SetExecuteMethod</tt> if you derive the 
  * <tt>CATDiaAction</tt> class.
  * @param iMeth
  *   The method which does the action.
  */
  virtual void SetExecuteMethod (ActionMethod iMeth);
  
  /**
  * Sets data which may be useful to execute or undo/redo the action.
  * <br><b>Role</b>: This data will be given as the argument of the 
  * <tt>ActionMethod</tt> methods.
  * @param iData
  *   An object that can be useful for the action.
  *   <br><b>Warning</b>: A copy of <tt>iData</tt> is kept. 
  *   Deallocate this object only at the end of the command.
  */
  virtual void SetData (void * iData);
  
  /*------------------------------------------------------*/
  // methods to be derived to program the action behavior 
  /*------------------------------------------------------*/
  
  /**
  * Executes the action.
  * <br><b>Role</b>: Redefine this method when deriving <tt>CATDiaAction</tt>.
  * @param iData
  *   The data specified by the @href #SetData method.
  * @return 
  *   The CATBoolean value used to combine actions.
  *   In an OrAction, the second action is executed only if the first
  *   action returns TRUE.
  */
  virtual CATBoolean Do (void * iData=NULL);
  
  /**
  * Undoes the action effects before the transactional undo.
  * <br><b>Role</b>: Redefine this method when deriving <tt>CATDiaAction</tt>.
  * @param iData
  *   The data specified by the @href #SetData method.
  * @return 
  *   The CATBoolean value used to combine actions.
  *   In an OrAction, if the second action is executed only if the first
  *   action returns TRUE.
  */
  virtual CATBoolean BeforeUndo (void * iData=NULL);
  
  /**
  * Redoes the action effects before the transactional redo.
  * <br><b>Role</b>: Redefine this method when deriving <tt>CATDiaAction</tt>.
  * @param iData
  *   The data specified by the @href #SetData method.
  * @return 
  *   The CATBoolean value used to combine actions.
  *   In an OrAction, the second action is executed only if the first
  *   action returns TRUE.
  */
  virtual CATBoolean BeforeRedo (void * iData=NULL);
  
  /**
  * Undoes the action effects after the transactional undo.
  * <br><b>Role</b>: Redefine this method when deriving <tt>CATDiaAction</tt>.
  * @param iData
  *   The data specified by the @href #SetData method.
  * @return 
  *   The CATBoolean value used to combine actions.
  *   In an OrAction, the second action is executed only if the first
  *   action returns TRUE.
  */
  virtual CATBoolean AfterUndo (void * iData=NULL);
  
  /**
  * Redoes the action effects after the transactional redo.
  * <br><b>Role</b>: Redefine this method when deriving <tt>CATDiaAction</tt>.
  * @param iData
  *   The data specified by the @href #SetData method.
  * @return 
  *   The CATBoolean value used to combine actions.
  *   In an OrAction, the second action is executed only if the first
  *   action returns TRUE.
  */
  virtual CATBoolean AfterRedo (void * iData=NULL);
  
  /*---------------------------------*/
  //  constructors FOR INTERNAL USE  
  /*---------------------------------*/
  
  /** @nodoc */
  CATDiaAction (int impl);
  /** @nodoc */
  CATDiaAction (CATDiaAction &);
  /** @nodoc */
  CATDiaAction (ActionType, CATDiaAction * act1, CATDiaAction * act2);
  /** @nodoc */
  CATDiaAction (CATICmdAction * interfac);
  /** @nodoc */
  CATDiaAction (CATCommand *, ActionMethod execute=NULL, ActionMethod undo=NULL,
                              ActionMethod reset=NULL, void * data=NULL);
  
  /*---------------------------------*/
  //  methods FOR INTERNAL USE  
  /*---------------------------------*/
  
  /** @nodoc */
  CATString & GetName ();
  /** @nodoc */
  void SetName (const CATString & name);
  
  /** @nodoc */
  CATDiaActionEngine * GetLetterObject ();
  /** @nodoc */
  HRESULT QueryCATICmdAction (CATICmdAction ** oAction);
  
  /** @nodoc */
  void ReleaseComponents (); 
  
  /*---------------------------------------------*/
  //  obsolete methods. Do not use it any more 
  /*---------------------------------------------*/
  
  /**
  * @nodoc 
  *  for perfos, declares when an action has no undo but it's obsolete.
  */
  void DeclareNoUndo ();
  
  /** @nodoc */
  virtual CATBoolean Execute ();
  /** @nodoc */
  virtual CATBoolean Undo ();
  /** @nodoc */
  virtual CATBoolean Redo ();
 
protected:
  
  /*------------------*/
  // internal data 
  /*------------------*/
  
  /** @nodoc */
  CATDiaActionEngine * _Implement;

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATDiaAction & operator= (const CATDiaAction &);
  
  /*---------------------------------------------*/
  // Dump to De² methods
  /*---------------------------------------------*/
  /**
  * @nodoc 
  *  Internal use only 
  */
  ActionType                GetActionType()const;
  const CATDiaAction* const GetAction1()const;
  const CATDiaAction* const GetAction2()const;
  const ActionMethod        GetExecuteMethodAddr()const;
  const ActionMethod        GetBeforeUndoMethodAddr()const;
  const ActionMethod        GetAfterUndoMethodAddr()const;
  const ActionMethod        GetBeforeRedoMethodAddr()const;
  const ActionMethod        GetAfterRedoMethodAddr()const;

  
  friend class CATDE2DumpCppStateCommand;
};

#endif
