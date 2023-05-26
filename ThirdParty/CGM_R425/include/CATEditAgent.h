#ifndef __CATEditAgent_h
#define __CATEditAgent_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 2000-2011
// public CATDegEditAgent.m

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATStateCommand.h"

#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATString.h"
#include "CATUnicodeString.h"

class CATPathElement;
class CATFrmEditor;
class CATCommand;
class CATNotification;
class CATActiveObject;
class CATDialog;
class CATStackableCommandSet;
class CATDialogAgent;
class CATDE2Manager; 

#define SETELEMENTPROVIDER(iobj, iMethod) _SetElementProvider(iobj, iMethod, #iMethod)

/**
 * Class representing an agent to edit an object in a workbench different from the
 * current one.
 * <b>Role</b>: An edition agent is a specific agent which enables the user to
 * edit an object inside a state command. This agent is itself a state command which,
 * when it is activated, launchs the workbench specified by the @href #SetWorkbench method. Once the end user has
 * clicked on the workbench's exit button, the edition agent is completed, the edited object is put 
 * into the CSO, and the state chart of the original command resumes. 
 * <br>The object to edit is provided by a method given as argument of the
 * @href #SetElementProvider method.
 * <br><br><b>Note</b>: As every state command used as an agent,
 * an edition agent must be the only agent added to a given state.
 */
class ExportedByCATDialogEngine CATEditAgent: public CATStateCommand
{

  /** @nodoc */
  CATDeclareClass;
  /** @nodoc */
  CmdDeclareResourceFile(CATDialogEngine, CATEditAgent, CATStateCommand);
  
public:
  
  /**
  * Constructs an edition agent.
  * @param iId
  *   The agent identifier. It is used to retrieve the undo/redo titles in 
  *   the command resource file.
  * @param iType
  *   The type corresponds to an interface. 
  *   <br>It is given to be an argument of the <tt>ElementProvider</tt> method given 
  *   as argument of the @href #SetElementProvider method. This <tt>ElementProvider</tt> 
  *   method can use or not this input parameter to check the object to edit.
  */
  CATEditAgent (const CATString & iId,
                CATClassId iType=NULL);
  /**
  * @nodoc
  * OBSOLETE : Do not use
  */
  CATEditAgent (CATStateCommand * iFather,
                const CATString & iId,
                CATFrmEditor * iEditor,
                CATClassId iType=NULL);

  virtual ~CATEditAgent ();

 /**
  * Prototype of the element provider methods.
  * <br><b>Role</b>: These methods are passed as parameters of the @href 
  * #SetElementProvider method and are automatically called each time the 
  * edition agent is activated. 
  * <br>They are expected to return a full model path element to be edited.
  * @param iType
  *   The type corresponds to an interface. 
  *   <br><tt>iType</tt> is an input parameter coming from the constructor 
  *   ( @href #CATEditAgent ). 
  * @return 
  *   The path to the object to edit. The object to activate is the first one
  *   implementing @href CATIUIActivate (beginning from the leaf).
  *   <br><b>Cyclic reference</b>: the path is kept and AddRef'ed.
  *   It is Released at the end of the agent before the agent
  */
  typedef CATPathElement * (CATBaseUnknown::*ElementProvider) (CATClassId iType);

  /**
  * Sets the method to provide the object to edit.
  * <br><b>Role</b>: This method enables you to specify the name of a 
  * <tt>ElementProvider</tt> method, and an instance of the class defining this method. 
  * This <tt>ElementProvider</tt> method will be called just before
  * the edition to provide to the agent the object to edit .
  * <pre>
  * _myAgent = new CATEditAgent("EditAgentId");
  * _myAgent->SetElementProvider(this, 
  *              (CATEditAgent::ElementProvider) &MyStateCommand::<tt>ObjectProviderMethod</tt>);
  * </pre>
  * @param iObject
  *   The pointer to the class instance defining <tt>iMethod</tt>
  * @param iMethod
  *   The method to execute before edition.
  */
  void SetElementProvider (CATBaseUnknown * iObject, ElementProvider iMethod);
  
  /**
  * Sets the workbench used during the edition.
  * <br><b>Role</b>: This method sets the name of the workbench that must be activated
  * to edit the object.
  * For workshops with only one workbench or without workbench (like Sketcher), this method 
  * is useless.
  * @param iWorkbench
  *   The workbench name
  */
  void SetWorkbench (const CATString & iWorkbench);
  
  /**
  * Sets the commands available during the edition.
  * <br><b>Role</b>: This method enables you to specify the available
  * commands for the activated workbench. 
  * <br>If this method is never called, or if <tt>NULL</tt> is given as argument,
  * an empty instance of the @href CATStackableCommandSet class will be used by
  * the agent. A minimum set of commands will then be available, including the one
  * to leave the workbench.
  * @param iCommandSet
  *   The command set.
  *   <br><b>Cyclic reference</b>: <tt>iCommandSet</tt> is kept and AddRef'ed.
  *   It is Released at the end of the agent before the agent destructor call.
  */
  void SetCommandSet (CATStackableCommandSet * iCommandSet);
  
  /**
  * Sets the dialog object, if any, representing the command.
  * <br><b>Role</b>: This dialog object will be desactivated during the edition
  * (but it won't be hidden by the edition agent) and reactivated after the edition.
  * @param iDialog
  *   The dialog object.
  */
  void SetPanel (CATDialog * iDialog);
    
  /**
  * Returns the path of the edited object.
  * <br><b>Role:</b>This method returns the value returned by the 
  * <tt>ElementProvider</tt> method. Since this <tt>ElementProvider</tt> method is
  * called just before the edition, the value is valid only after the edition. 
  * @return 
  *   The path of the edited object. 
  * <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
  * returned value.
  */
  CATPathElement * GetValue ();
  
  /**
  * @nodoc
  * Specifies a user interaction expected by the agent before triggering the edition.
  * <br><b>Role</b>: Sets the edition agent in a waiting state until an expected
  * event occurs.
  * <br>The notifier must send the notification to the command selector of the editor
  * where the command has been started.
  * @param iNotifier
  *   The notifier.
  *   <br><b>Legal values</b>: The notifier may be NULL: the reception of the
  *   notification is sufficient to trigger the edition whatever the notifier. 
  * @param iNotif
  *   The notification address.
  *   The agent checks whether the received notifications belong to the
  *   same class as the <tt>iNotif</tt> notification. So, only the 
  *   notification class matters. 
  *   <br><b>Legal values</b>: It can be NULL: any notification sent by the
  *   <tt>iNotifier</tt> notifier values the agent. 
  * @return 
  *   <dl>
  *   <dt> <tt>S_OK</tt>    <dd> The triggering condition is set
  *   <dt> <tt>E_FAIL</tt>  <dd> <tt>iNotifier</tt> and <tt>iNotif</tt> are both NULL
  *   </dl>   
  * @see SetFirstStateMessage
  */
  HRESULT SetEditTrigger (CATCommand * iNotifier, CATNotification * iNotif);
  
  /**
  * @nodoc
  * Specifies a user interaction expected by the agent before triggering the edition.
  * <br><b>Role</b>: Sets the edition agent in a waiting state until an expected
  * event occurs.
  * <br>The notifier must send the notification to the command selector of the editor
  * where the command has been started.
  * @param iNotifier
  *   The notifier.
  *   <br><b>Legal values</b>: The notifier may be NULL: the reception of the
  *   notification is sufficient to trigger the edition whatever the notifier. 
  * @param iNotifClass
  *   The notification class.
  *   <br><b>Legal values</b>: It can be NULL: any notification sent by the
  *   <tt>iNotifier</tt> notifier values the agent. 
  * @return 
  *   <dl>
  *   <dt> <tt>S_OK</tt>    <dd> The triggering condition is set
  *   <dt> <tt>E_FAIL</tt>  <dd> <tt>iNotifier</tt> and <tt>iNotifClass</tt> are both NULL
  *   </dl>   
  * @see SetFirstStateMessage
  */
  HRESULT SetEditTrigger (CATCommand * iNotifier, const char * iNotifClass);
  
  /**
  * @nodoc
  * Sets the message associated with the waiting state.
  * <br><b>Role</b>: This method must be used in conjunction with the
  * @href #SetEditTrigger to define the message associated with the waiting state.
  * @param iMessage
  *   The message to prompt
  * @return 
  *   S_OK 
  */
  HRESULT SetFirstStateMessage (const CATUnicodeString & iMessage);
  
private:
  
  // Initialize (called by C'tors)
  void Init ();
  
  // Build state command graph (called during activation)
  virtual void BuildGraph ();
  
  // (called by SetEditTrigger)
  HRESULT DoSetEditTrigger (CATCommand *, CATNotification *, const char *);

  // Gets or creates command set
  CATStackableCommandSet * GetCommandSet ();
  
  // Gets active object
  CATActiveObject * GetActiveObject ();
  
  // Calls the ElementProvider method to get the element to edit.
  CATPathElement * GetWorkingElement ();

  // Condition Methods
  CATBoolean TrueCondition (void *);
  CATBoolean ValueCondition (void *);
  // Action Methods
  CATBoolean EnterEditStateAction (void *);
  CATBoolean LeaveEditStateAction (void *);
  
  // Type of the element edited by the agent
  CATClassId        _type;
  
  // Path of the edited element
  CATPathElement  * _value;
  
  // Notifier and Notification triggering the edition
  CATCommand      * _editOnNotifier;
  CATNotification * _editOnNotification;
  CATString         _editOnNotifClassName;
  // Agent triggering the edition
  CATDialogAgent  * _editTriggerAgent;
  // Message associated with the waiting first state
  CATUnicodeString  _firstStateMessage;
  
  // Agent triggering the end of the edition
  CATDialogAgent  * _editExitAgent;
  
  // The top level command's ui to desactivate during the edition
  CATDialog       * _panel;
  
  // The client method used to get the element to edit
  ElementProvider   _elementProviderMethod;
  CATBaseUnknown  * _elementProvider;
  
  // The favorite workbench when ui-activating the provided path element
  CATString         _workbench;
  
  // The allowed stacked commands during edition
  CATStackableCommandSet * _commandSet;
  
  // The current transaction index when the agent is activated
  int _firstTransactionIndex;
  
  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATEditAgent ();
  CATEditAgent (const CATEditAgent &);
  CATEditAgent & operator= (const CATEditAgent &);
  
protected:
  
  /*----------------------------------------------------------*/
  /* Set/Retrieve the agent properties	-DE² use-			*/
  /*----------------------------------------------------------*/
  /** @nodoc */
  virtual HRESULT _GetProperty(CATUnicodeString iPropertyId, CATBaseUnknown_var& iospPropValue);
  virtual HRESULT _SetProperty(CATUnicodeString iPropertyId, const CATListValCATBaseUnknown_var& ispPropValue);

private:
  /**
  * @nodoc
  * Gets or creates command set 
  * Internal use only
  * return const CATStackableCommandSet* to limit as much as possible deviant use.
  */
  CATStackableCommandSet& GetCommandSetInternalForDE2();
  const CATUnicodeString  GetSelectionType() const {return _type;}
  const CATUnicodeString  GetElementProviderMethod(){return _DE2ElementProviderMethodName;}
  const CATUnicodeString  GetWorkbench() const {return CATUnicodeString(_workbench);}
  const CATUnicodeString  GetFirstStateMessage()const {return _firstStateMessage;}

  //Set Element provider for DE²
  void SetDE2ElementProvider (CATDE2Manager* Object, CATUnicodeString iMethName);
  
  CATUnicodeString   _DE2ElementProviderMethodName;

protected:    

  /** @nodoc*/
  /*DO NOT CALL THIS FUNCTIONS DIRECTLY!!!!*/
  /*Internal use for DE² DUMP*/
  void _SetElementProvider(CATBaseUnknown* iObj, ElementProvider iMethod, CATUnicodeString iMethodName);

  friend class CATDE2DumpCppStateCommand;
};
#endif//__CATEditAgent_h

