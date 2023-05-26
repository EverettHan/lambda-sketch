#ifndef CATVidDialogAgent_H_
#define CATVidDialogAgent_H_
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 2012
// protected CATCmdDialogAgents.m

#include "CATDialogAgent.h"

#include "CATListPV.h"

class CATSYPEvent;
class CATSYPEventHandler;
class CATSYPEventArgs;

typedef struct controlEvent {
  CATCommand * cmd;
  CATSYPEvent * event;
  int handleConsumedEvents;
  CATSYPEventHandler * handler;
} WidgetEvent;

/**
 * Class representing an agent dedicated to VID Control events.
 * <b>Role</b>: A VID Agent is a specific dialog agent which
 * accepts VID events.
 * @see CATVidCtl
 */

class ExportedByCATDialogEngine CATVidDialogAgent : public CATDialogAgent
{
  
  /** @nodoc */
  CATDeclareClass;
  
public:
  
  /**
  * Constructs an agent to catch VID components events.
  * @param iId
  *   The agent identifier. It is used to retrieve the undo/redo titles in 
  *   the command resource file.
  */
  CATVidDialogAgent (const CATString & iId,
	                   CATDlgEngBehavior iBehavior=NULL);
  
  virtual ~CATVidDialogAgent ();
  
  /*---------------------------------------*/
  /*    VID Components and Events handling */
  /*---------------------------------------*/
  
  /**
  * Specifies the user interaction expected by the agent.
  * <br><b>Role</b>: The agent becomes valued when <tt>iCmd</tt> triggers 
  * <tt>iNotif</tt> event.
  * @param iCmd
  *   The VID control.
  * @param iEvent
  *   The event.
  * @param i_handleConsumedEvents @c !=0 if the handler should be
  *   called for consumed events.
  */
  HRESULT AcceptOnEvent (CATCommand * iCmd, CATSYPEvent * iEvent, int iHandleConsumedEvents = 0);
  
  /**
  * Cancels the effect of the AcceptOnEvent method.
  * <br><b>Role</b>: The agent won't be valued anymore when <tt>iCmd</tt> triggers 
  * <tt>iNotif</tt> event.
  * @param iCmd
  *   The VID control.
  * @param iEvent
  *   The event.
  */
  HRESULT IgnoreOnEvent (CATCommand * iCmd, CATSYPEvent * iEvent);

  /*---------------------------------*/
  /*    Life cycle                   */
  /*---------------------------------*/
  
  /** @nodoc */
  virtual CATStatusChangeRC Activate (CATCommand * fromClient, CATNotification * );
  /** @nodoc */
  virtual CATStatusChangeRC Desactivate (CATCommand * fromClient, CATNotification *);
  /** @nodoc */
  virtual CATStatusChangeRC Cancel (CATCommand * fromClient, CATNotification *);
  
  /*---------------------------------------------*/
  // Dump to DE² methods
  /*---------------------------------------------*/
  /**
  * @nodoc 
  *  Internal use only 
  */
  virtual CATBoolean IsListenningToEvent();
  virtual int        GetListennedEventNb();
  virtual void       GetListennedEvent(int iIdx, CATCommand** oSender, CATString& oEvent);

 
protected:
  
  /*---------------------------------*/
  /*    Callback                     */
  /*---------------------------------*/
  
  /** @nodoc */
  virtual void HandleEvent (CATBaseUnknown * iFrom, CATSYPEventArgs * iArgs); 
 

private:
    
  CATListPV _controlEventList;

  /**
  * Connects the agent to registered events.
  */
  void AddHandlers ();
  /**
  * Disconnects the agent to connected events.
  */
  void RemoveHandlers ();
  /**
  * Removes a handler.
  */
  void RemoveHandler (CATCommand * iCmd, CATSYPEvent * iEvent, CATSYPEventHandler * iHandler);

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATVidDialogAgent ();
  CATVidDialogAgent (const CATVidDialogAgent &);
  CATVidDialogAgent & operator= (const CATVidDialogAgent &);
  
};

#endif
