#ifndef CATIParmEvents_H
#define CATIParmEvents_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */

/*  CAA2Reviewed by FRH */

// inherited class
#include "CATInterfaceEvents.h"

// module exports declaration
#include "CATLifSpecs.h"
#include "CATICkeForwards.h"

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIParmEvents;
#else
extern "C" const IID IID_CATIParmEvents;
#endif


/**   
 * Interface dedicated to parameters events management.
 * <b>Role</b>: This interface is used to add subscription to parameters events.<br>
 * It is implemented on parameters.
 * 4 events are available<br>
 *  <li> <b>ChangeValue</b> when content is actually changed </li>
 *  <li> <b>Rename</b> when parameter is actually renamed </li>
 *  <li> <b>ChangeVisu</b> when <br>
 *      <li> for internal reasons :
 *         <li>visibility change</li>    
 *         <li>user access change</li>
 *         <li>driving relation set or unset</li>
 *         <li>magnitude current unit change</li></li>
 *      <li> for external reason : (SendChangeVisu)
 *         <li>driving relation is activated or desactivated</li> </li>
 * </li>
 *  <li> <b>Delete</b> when literal is deleted (before deletion)</li>
 * This interface is multi implemented.
 * It is implemented on literal and volatile values
 * @see CATParmNotification, CATICkeParm
 */
class ExportedByCATLifSpecs CATIParmEvents: public CATInterfaceEvents
{
  CATDeclareInterface;

public:

/**
 * Returns rename notification.
 */
virtual CATCallbackEvent GetRenameNotification()  = 0;

/**
 * Returns change value notification.
 */
virtual CATCallbackEvent GetChangeValueNotification()  = 0;

/**
 * Returns change visu notification.
 */
virtual CATCallbackEvent GetChangeVisuNotification()  = 0;

/**
 * Returns delete notification.
 */
virtual CATCallbackEvent GetDeleteNotification()  = 0;

/**
 * Produces the change visu event dispatch on the parameter. 
 */
virtual void SendChangeVisuNotification () = 0;



/** 
 * Defines when Change value event is dispatched by parameter.<br>
 *               Never = change value event is never sent.<br>
 *               WhenChanged = when valuated and value is eventually changed.<br>
 *               WhenValuated = when valuated even if value isn't changed.<br>
 */
enum SendBehavior  {  Never, WhenChanged, WhenValuated  };

/**
 * Sets the way the Change value event is sent.
 * @param iSendBehavior :
 *   	change value event mode
 */
virtual void DefineSendBehavior (const SendBehavior iSendBehavior) = 0;


/**
 * Produces the change value event dispatch on the parameter. 
 * @param iChanged :
 *   	indicates if value has actually changed<br>.
 */
virtual void SendChangeValueNotification (const CATCke::Boolean &iChanged = 1) =0;


};

CATDeclareHandler(CATIParmEvents,CATInterfaceEvents);

#endif
