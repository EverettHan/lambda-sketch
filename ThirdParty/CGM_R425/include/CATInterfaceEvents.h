/* -*-c++-*- */
#ifndef CAT_INTERFACE_EVENTS_H
#define CAT_INTERFACE_EVENTS_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @CAA2Level L1
* @CAA2Usage U5
*/

#include "CATOMY.h"

#include <stdlib.h>
#include "CATBaseUnknown.h"
#include "CATNotification.h"

class CATCallbackManager ;

#ifndef CATEventSubscriber_H

/**
* 
* To avoid type redeclarations.
*/
#define CATIEventSubscriber_H

/**
*
* Definition of CATCallbackEvent Type : identifier of Event.
*/
typedef CATLONG32   CATCallback ;

/**
* 
* Definition of CATCallback Type : identifier of Callback.
*/
typedef char*  CATCallbackEvent ;

/**
* 
* Definition of CATSubscriberData  :  client data. 
*/
typedef void*  CATSubscriberData ;

/**
* 
* Definition of CATSysMethod.   
*/
/**
 * @nodoc
 */
typedef void (CATExtendable::*CATSubscriberMethod)( CATCallbackEvent ,
						    void*,
						    CATNotification*,
						    CATSubscriberData,
                                                    CATCallback ) ;

#endif


#include "CATOMY.h"
extern ExportedByCATOMY IID IID_CATInterfaceEvents ;

/**
* Definition of the services for Event Interface classes.
*
* <b> role: </b> All user interfaces have to inherit from this class
*  if they need to use the event services
*/

class ExportedByCATOMY CATInterfaceEvents : public CATBaseUnknown
{
 
  CATDeclareInterface;

  public:
	/**
      * Handles interfaces.
	  * @param eventManager
	  *        pointer to eventManager
	  * @param event
	  *        kind of event
	  * @param method
	  *        method which will be called on event
	  * @param interfaceID
	  *        interface name
	  * @param data
	  *        data
	  * @return
      *   Callback
      */
    virtual CATCallback AddSubscription( CATInterfaceEvents  *eventManager,
				         CATCallbackEvent     event,
				         CATSubscriberMethod  method, 
				         char                *interfaceID,
				         CATSubscriberData    data = NULL  ) = 0 ;


    /**
      * Removes all callbacks.
	  * Removes all callbacks which concern the same CATCallbackManager, CATCallbackEvent, CATSubscriberData.
	  * @param eventManager
	  *        pointer to eventManager
	  * @param event
	  *        kind of event
	  * @param interfaceID
	  *        interface name
	  * @param data
	  *        data
      */
    virtual void RemoveSubscriptionsOn( CATInterfaceEvents *eventManager,
				        CATCallbackEvent    event,
				        char               *interfaceID,
				        CATSubscriberData   data  ) = 0 ; 

    /**
      * Removes all callbacks of this Client on a CATCallbackManager.
      * @param eventManager
	  *        pointer to eventManager
	  * @param interfaceID
	  *        interface name
      */
    virtual void RemoveInterfaceSubscriptions( CATInterfaceEvents *eventManager , 
                                               char               *interfaceID ) =0 ;


    /**
      * Gives the associated CATCallbackManager if it exists.
	  * @return
      *   pointer to eventManager
      */
    virtual CATCallbackManager *GetCallbackManager() = 0 ;
} ;

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATInterfaceEvents, CATBaseUnknown ) ;


#endif
