#ifndef CATIModelEvents_h
#define CATIModelEvents_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U4 CATExtIModelEvents
 */

#include "CATVisItf.h"

#include "CATBaseUnknown.h"

class CATNotificationDispatcher;
class CATNotification;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIModelEvents;
#else
extern "C" const IID IID_CATIModelEvents;
#endif

/**
 * Interface that makes components communicate with their visualization, that is their graphical
 * representations. 
 *<br><b>Role</b>:
 * As the model world and the visualization world are independent, every action (ie that a geometry modification)
 * performed by one object or by any command should trigger
 * a visualization update (when necessary). The way to warn the visualization world is based onto
 * visualization events and a send/receive mechanism. And the management of the visualization events 
 * is done by this interface: how one object can be connected to (or disconnected from) 
 * another object, how sending 
 * a visualization event?
 *<p>
 * <p><b>BOA information</b>: this interface CANNOT be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the CAA Encyclopedia home page.
 * Click Middleware at the bottom left, then click the Object Modeler tab page.
 * Several articles deal with the BOA.</p>
 * @see CATModelNotification, CATVisManager
 */
class ExportedByCATVisItf CATIModelEvents : public CATBaseUnknown
{
  /** @nodoc */
  CATDeclareInterface;

  public :
  
  /**
   * Sends a visualization event.
   *@param iInfo
   * the notification.
   */
  virtual void Dispatch ( CATNotification & iInfo ) = 0;
  
  
  /**
   * Returns the component which allows the events' sending.
   */
  virtual CATNotificationDispatcher * GetDispatcher () = 0;

  //  allow to transmit notifications of son object to the object
  //  can be used to recursively transmit information from leaf to top
  //  in a tree
  //  ----------------------------------------------------------------
 
  /**
   * Connects itself with a given object.
   *
   * <br><b>Role</b>:
   * Connection with a given object means that when this object sends a visualization
   * event (a notification) thru the @href #Dispatch method the current object is "awakened" 
   * with the @href #Receive method. Finally the current object should send the received event 
   * thru the @href #Dispatch method. And all objects that are connected to the current object will be 
   * awakened also. This mechanism makes one event to go up to the last connected object. Usually 
   * the last connected object is the @href CATVisManager which has the ability to process the visualization
   * event . Notice that this kind of connection is a parent-like relation 
   * between the current object(<tt>parent</tt>) and 
   * the given object(<tt>child</tt> to which it is connected).
   *
   * @param iChild
   * the given object.
   *
   */
  virtual void ConnectTo ( CATBaseUnknown *iChild ) = 0;


  
  /**
   * Disconnects itself from a given object.
   *
   *<br><b>Role</b>: 
   *  Disconnection with a given object means that the connection is broken: not any events 
   * sent by the given object will awaken the current object.
   *
   *@param iChild
   * the given object.
   */
  virtual void DeconnectFrom ( CATBaseUnknown *iChild ) = 0;


  /**
   * Receive a visualization event.
   *
   *<br><b>Role</b>: 
   * this method should be called when the current object is awaken by one of its children.
   * It should then forward the event (thru the @href #Dispatch method) after any possible 
   * processing.
   */
  virtual void Receive ( CATNotification & info ) =0;

} ; 

/** @nodoc */
CATDeclareHandler(CATIModelEvents,CATBaseUnknown);

#endif
