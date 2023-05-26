#ifndef CATStateCondition_h
#define CATStateCondition_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0STATE.m

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATString.h"
#include "CATStateCondition.h"

#include "CATDialogAgent.h"

class CATCommand;
class CATICmdCondition;
class CATNotification;

 /**
  * Prototype of the condition methods.
  * <b>Role</b>: These methods are passed as parameters of the @href 
  * CATStateCondition class methods.
  * @param iData
  *   The data specified by the @href CATStateCondition#SetData method.
  * @return 
  *   The result of the condition evaluation.
  */
typedef CATBoolean (CATCommand::*ConditionMethod)(void * iData);

/**
 * Base class to create a condition.
 * <b>Role</b>: Conditions are used to check whether the dialog can go on.
 * A condition may be
 * <ul>
 * <li>a guard condition linked to a transition. The condition is evaluated 
 * when the transition is triggered. 
 * If it evaluates TRUE, the transition fires. </li>
 * <li>a state exit condition. It is evaluated before the guard conditions: 
 * <ul>
 * <li>whenever a state dialog agent is valued
 * <li>when entering the state, if the state is empty or if the state 
 * contains a one-shot agent already valued.
 * </ul>
 * If it evaluates FALSE, the guard conditions are not evaluated and no 
 * transition fires.</li>
 * </ul>
 * <br>To create a condition, you can derive this class and override the @href
 * #GetStatus method or use the @href CATStateCommand#Condition method and
 * give as argument the address of a method to evaluate the condition.  
 * <br>Conditions must be created in the @href CATStateCommand#BuildGraph 
 * method.
 * @see CATDialogState, CATDialogTransition
 */

class ExportedByCATDialogEngine CATStateCondition : public CATBaseUnknown
{

  /** @nodoc  */
  CATDeclareClass;
  
public:
  
  /** @nodoc  */
  enum ConditionType { UNKNOWN, ALWAYS_TRUE, METHOD , IS_OUTPUT_SET, IS_LAST_MODIFIED_AGENT, AND, OR, NOT, DegMETH, INTERFACE};
  
  /**
  * Constructs an empty condition.
  * <br><b>Role</b>: Use it only when deriving the <tt>CATStateCondition</tt> 
  * class, otherwise use the @href CATStateCommand#Condition method to create
  * a condition.
  */
  CATStateCondition ();
  
  virtual ~CATStateCondition ();
  
  /**
  * Sets data which may be useful to evaluate the condition.
  * <br><b>Role</b>: This data will be given as the argument of the <tt>
  * ConditionMethod</tt> method.
  * <br>Do not use this method if you derive the <tt>CATStateCondition</tt> 
  * class.
  * @param iData
  *   An object that can be useful for the condition.
  *   <br><b>Warning</b>: A copy of <tt>iData</tt> is kept. 
  *   Deallocate this object only at end of the command.
  * @return
  *   An HRESULT. 
  *   S_OK is always returned.
  */
  HRESULT SetData (void * iData);
  
  /**
  * Sets the method to evaluate the condition.
  * <br><b>Role</b>: This method must be a method of the CATStateCommand 
  * object which defines the statechart.
  * <br>Do not use <tt>SetMethod</tt> if you derive the 
  * <tt>CATStateCondition</tt> class.
  * @param iMeth
  *   The method which evaluates the condition.
  * @return
  *   An HRESULT. 
  *   S_OK is always returned.
  */
  HRESULT SetMethod (ConditionMethod iMeth);
  
  /**
  * Evaluates the condition.
  * <br><b>Role</b>: Redefine this method when deriving <tt>
  * CATStateCondition</tt>.
  * @return 
  *   The result of the condition evaluation.
  */
  virtual CATBoolean GetStatus ();
  
  /*---------------------------------*/
  //  constructors FOR INTERNAL USE  
  /*---------------------------------*/
  
  /** @nodoc  */
  CATStateCondition (ConditionMethod);  
  /** @nodoc  */
  CATStateCondition (CATCommand *, ConditionMethod);
  /** @nodoc  */
  CATStateCondition (CATCommand *);
  /** @nodoc  */
  CATStateCondition (CATICmdCondition *interfac);
  /** @nodoc  */
  CATStateCondition (CATCommand * cmd,CATCommand * agt, CATNotification *);
  /** @nodoc  */
  CATStateCondition (CATCommand * cmd,CATCommand * agt, const char *);
  /** @nodoc  */
  CATStateCondition (ConditionType, CATStateCondition *, CATStateCondition *);
  /** @nodoc  */
  CATStateCondition (ConditionType, CATStateCondition *);
  
  /*---------------------------------*/
  //  methods FOR INTERNAL USE  
  /*---------------------------------*/
  
  /** @nodoc  */
  HRESULT Evaluate (CATBoolean * oBool);
  /** @nodoc  */
  void SetCommand (CATCommand *);
  /** @nodoc  
  * @param oCondition [out, IUnknown#Release] 
  */
  HRESULT QueryCATICmdCondition (CATICmdCondition ** oCondition);
  /** @nodoc  */
  void Dump (int decale=0, int offTraces=0); 
  /** @nodoc  */
  void ReleaseComponents (); 

  /** @nodoc */
  friend class CATEDegCmdDbgCondition;

protected:
  
  /*------------------*/
  // internal data 
  /*------------------*/
  
  /** @nodoc  */
  ConditionMethod _method;
  /** @nodoc  */
  /* command which can answer to GetLasModifiedAgent */
  CATCommand * _command;
  /** @nodoc  */
  /* command which contains the methods */
  CATCommand * _MethCommand; 
  /** @nodoc  */
  CATCommand * _agent;
  /** @nodoc  */
  CATNotification *  _notification;
  /** @nodoc  */
  CATString _notifChar;
  
  /** @nodoc  */
  ConditionType _type;
  /** @nodoc  */
  CATStateCondition * _firstCondition, *_secondCondition;
  /** @nodoc  */
  int _withData;
  /** @nodoc  */
  void * _data;
  /** @nodoc  */
  CATICmdCondition * _interface;
  /** @nodoc  */
  int _offTraces;
  
private:  
  /*---------------------------------*/
  //  DE² DUMP: methods FOR INTERNAL USE  
  /*---------------------------------*/
  /** @nodoc  */
  CATStateCondition::ConditionType GetType()const;
  /** @nodoc  */
  const CATStateCondition* const   GetCondition1()const;
  /** @nodoc  */
  const CATStateCondition* const   GetCondition2()const;
  /** @nodoc  */
  const CATCommand* const          GetAgent()const;
  /** @nodoc  */
  const ConditionMethod            GetConditionMethodAddr()const;
  
  CATStateCondition (CATStateCondition &);
  
  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATStateCondition & operator= (const CATStateCondition &);
  
  friend class CATDE2DumpCppStateCommand;
};

#endif
