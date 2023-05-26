#ifndef CATDialogState_H
#define CATDialogState_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0STATE.m

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATBaseUnknown.h"
#include "CATListOfCATCommand.h"
#include "CATUnicodeString.h"
#include "CATString.h"
#include "CATStateCondition.h"

class CATCommand;
class CATDiaAction;

/**
 * Class to create a command state.
 * <b>Role</b>: A state is one of the main elements of a state dialog command
 * which is a state machine that uses states to let the end user input the
 * requested parameters, and transitions between states to process these input
 * parameters and progress in the statechart.
 * <br>Do not use the <tt>CATDialogState</tt> constructor to create a state 
 * but the @href CATStateCommand#GetInitialState and @href 
 * CATStateCommand#AddDialogState methods.
 * <br>A state can contain several dialog agents and may be associated with an 
 * exit condition, an entry action and an exit action.
 * <br>States must be created in the @href CATStateCommand#BuildGraph method.
 * @see CATStateCondition, CATDiaAction, CATDialogAgent
 */

class ExportedByCATDialogEngine CATDialogState:public CATBaseUnknown
{
  
  /** @nodoc */
  CATDeclareClass;
  
public:
  
  /** @nodoc */
  CATDialogState ();
  
  virtual ~CATDialogState ();
  
  /*-------------------------*/
  //     AGENTS
  /*-------------------------*/     
  
  /**
  * Adds a dialog agent in the state.
  * @param iAgent
  *   The agent to add.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iAgent</tt> is kept and
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor call or when the agent is removed.
  */
  virtual void AddDialogAgent (CATCommand * iAgent);
  
  /**
  * Removes a dialog agent in the state.
  * @param iAgent
  *   The agent to remove.
  */
  void RemoveDialogAgent (CATCommand * iAgent);
  
  /**
  * Returns the count of agents in the state.
  * <br><b>Role</b>: The count of agents ranges from 1 to n.
  * @return
  *   The agent count.
  */
  int GetDialogAgentSize () const;
  
  /**
  * Returns an state agent using the agent index.
  * <br><b>Role</b>: This method returns the <tt>iIndex</tt>th agent.
  * @param iIndex
  *   The agent index.
  *   <br><b>Legal values</b>: <tt>iIndex</tt> range starts with 1, which is 
  *   the default.
  *   Use @href #GetDialogAgentSize to get the state agent count.
  * @return
  *   The agent.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  CATCommand * GetDialogAgent (int iIndex) const;
  
  
  /*-------------------------*/
  //     CONDITIONS
  /*-------------------------*/     
  
  /**
  * Sets the exit condition.
  * <br><b>Role</b>: This condition must evaluate TRUE to trigger a 
  * transition. 
  * <br>Since a state has only one exit condition, successive calls to 
  * <tt>SetLeaveCondition</tt> for the same state successively overwrite the 
  * condition.
  * @param iCond
  *   The exit condition.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iCond</tt> is kept and
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor call.
  *   <br><b>Legal values</b>: <tt>iCond</tt> may be set to NULL to cancel 
  *   a condition inherited from the command base class. 
  */
  virtual void SetLeaveCondition (CATStateCondition * iCond);
  
  /**
  * Returns the exit condition.
  * <br><b>Role</b>: This condition must evaluate TRUE to trigger a
  * transition. 
  * @return 
  *   The exit condition.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATStateCondition * GetLeaveCondition () const;
  
  
  /*-------------------------*/
  //     ACTIONS
  /*-------------------------*/     
  
  /**
  * Sets the exit action.
  * <br><b>Role</b>: This action is executed when a transition leaves the
  * state if it is not a self-transition.
  * <br>Since a state has only one exit action, successive calls to 
  * <tt>SetLeaveAction</tt> for the same state successively overwrite the 
  * action.
  * @param iAction
  *   The exit action.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iAction</tt> is kept and 
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor call.
  *   <br><b>Legal values</b>: <tt>iAction</tt> may be set to NULL to cancel 
  *   an action inherited from the command base class. 
  */
  virtual void SetLeaveAction (CATDiaAction * iAction);
  
  /**
  * Returns the exit action.
  * <br><b>Role</b>: This action is executed when a transition leaves the 
  * state if it is not a self-transition.
  * @return
  *   The exit action.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATDiaAction * GetLeaveAction () const; 
  
  /**
  * Sets the entry action.
  * <br><b>Role</b>: This action is executed when entering the state without 
  * using a self-transition.
  * <br>Since a state has only one entry action, successive calls to 
  * <tt>SetEnterAction</tt> for the same state successively overwrite the 
  * action.
  * @param iAction
  *   The entry action.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iAction</tt> is kept and 
  *   AddRef'ed. It is Released at the end of the command before the command
  *   destructor call.
  *   <br><b>Legal values</b>: <tt>iAction</tt> may be set to NULL to cancel 
  *   an action inherited from the command base class. 
  */
  virtual void SetEnterAction (CATDiaAction * iAction);
  
  /**
  * Returns the entry action.
  * <br><b>Role</b>: This action is executed when entering the state without 
  * using a self-transition.
  * @return
  *   The entry action.
  *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  *   returned value.
  */
  virtual CATDiaAction * GetEnterAction () const;
  
  
  /*-------------------------*/
  //     RESOURCE ID
  /*-------------------------*/     
  
  /**
  * Sets the resource identifier.
  * <br><b>Role</b>: This identifier is used to retrieve the state prompt in 
  * the command message file.
  * <br>Since a state has only one identifier, successive calls to 
  * <tt>SetResourceId</tt> for the same state successively overwrite the 
  * identifier. It may be useful to change the state prompt dynamically.
  * @param iId
  *   The resource identifier.
  */
  void SetResourceID (const CATString & iId);
  
  /**
  * Returns the resource identifier.
  * <br><b>Role</b>: This identifier is used to retrieve the state prompt in 
  * the command message file.
  * @return
  *   The resource identifier.
  */
  CATString & GetResourceID ();


  /*-------------------------*/
  //     FOR INTERNAL USE 
  /*-------------------------*/     
  
  /* useless methods. They do not work */
  /** @nodoc  */
  void SetHelp (const CATUnicodeString & Help);
  /** @nodoc  */
  CATUnicodeString & GetHelp ();
  
  /*  Manage the message associated with a state */
  /** @nodoc  */
  void SetMessage (const CATUnicodeString & Message);
  /** @nodoc  */
  CATUnicodeString & GetMsg ();
  
  /** @nodoc  */
  void ReleaseComponents ();
  
  /** @nodoc  */
  int IsActivated () const;
  /** @nodoc  */
  void SetActivated (int);
  
  /** @nodoc  */
  void SetCallingCommand (CATCommand *);
  /** @nodoc  */
  CATCommand * GetCallingCommand ();
  
  /** @nodoc  */
  void Dump (int offTraces=0);  
  
  /** @nodoc  */
  CATCommand * GetNextAgent ();
  /** @nodoc  */
  void InitAgentList ();
  
  /** @nodoc  */
  CATDialogState (CATDialogState &);
  
protected:
  
  /*------------------*/
  // internal data 
  /*------------------*/
  
  CATUnicodeString      _Message;
  CATUnicodeString      _Help;
  CATString             _ressourceID;
  CATLISTP (CATCommand) _DialogAgentTable;
  CATCommand *          _callingCommand;
  CATStateCondition *   _condition;
  CATDiaAction *        _leaveAction;
  CATDiaAction *        _enterAction;
  int                   _HasBeenInitialized;
  int                   _activated;
  int                   _AgentListIndice;
  int                   _offTraces;

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATDialogState & operator= (const CATDialogState &);
    
};

#endif 
