#ifndef CATExtIModelEvents_h
#define CATExtIModelEvents_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */


#include "SceneGraphManager.h"
#include "CATEventSubscriber.h"
//#include "list.h"

class CATNotification;
class CATNotificationDispatcher;
class CATBaseUnknown;

/**
 * Class which is an Adapter to the CATIModelEvents interface.
 *
 * <b>Role</b>: This class provides a default implementation for any extension of the CATIModelEvents interface.
 * That means you should derive from this class to implement your extension of the CATIModelEvents interface.
 *
 * @see CATIModelEvents, CATNotificationDispatcher
 */

class ExportedBySceneGraphManager CATExtIModelEvents : public CATBaseUnknown
{
  CATDeclareClass;
  
  public:

  /**
   * Constructs the class.
   */
  CATExtIModelEvents (void) ;
  
  virtual ~CATExtIModelEvents (void) ;
   
  /**
   * Sends a notification.
   * @param iNotif
   * the event to send.
   */
  virtual void Dispatch ( CATNotification & iNotif );

  /**
   * Returns the dispatcher of notification.
   */
  virtual CATNotificationDispatcher * GetDispatcher ();
  
  /**
   * Connects current object to a given one.
   * @param iChild
   *   object from which current object wants to receive notifications.
   */
  virtual void ConnectTo ( CATBaseUnknown *iChild );

  /**
   * Disconnects current object from a given one.
   * @param iChild
   *   object from which current object wants not to receive notifications.
   */
  virtual void DeconnectFrom ( CATBaseUnknown *iChild );

  /**
   * Receives a notification thru the CATIModelEvents mechanism.
   * @param iNotif
   *   event current object receives.
   */
  virtual void Receive ( CATNotification & iNotif);
  
  /**
  * @nodoc 
  * This method is called when an object is logically dead.
  */
  virtual HRESULT ChangeComponentState( ComponentState iFromState, 
	  ComponentState iToState, 
	  const CATSysChangeComponentStateContext * iContext);
  
  protected:

  /**
   * @nodoc
   */
  void ReceiveNotification ( CATCallbackEvent, void *,
                             CATNotification *, CATSubscriberData,
                             CATCallback );

  /**
   * @nodoc 
   * the dispatcher of notifications 
   */ 
  CATNotificationDispatcher *_dispatcher;
  

};


#endif
