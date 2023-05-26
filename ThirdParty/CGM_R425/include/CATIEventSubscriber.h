#ifndef CATIEventSubscriber_H
#define CATIEventSubscriber_H
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/


// COPYRIGHT DASSAULT SYSTEMES 2000

#include <stdlib.h>
#include "CATEventSubscriber.h"
#include "CATBaseUnknown.h"
#include "CATNotification.h"

#include "JS0SCBAK.h"

class CATBaseUnknown ;
class CATEventSubscriber;

class CATCallbackManager ;


extern IID IID_CATIEventSubscriber;

//----------------------------------------------------------------
// Class CATEventSubscriber             
//----------------------------------------------------------------
class ExportedByJS0SCBAK CATIEventSubscriber : public CATBaseUnknown
{
 
    CATDeclareInterface;

  public:

    
    // ----------------------------------------------------------
    // To handle interfaces -------------------------------------
    // ----------------------------------------------------------
    // Add a callback on an interface (specified by InterfaceName)
    virtual CATCallback AddSubscription(CATBaseUnknown     *iEventManager,
				   CATCallbackEvent      iEvent,
				   CATSubscriberMethod   iMethod, 
				   char                  *iInterfaceName,
				   CATSubscriberData     iData=NULL ) =0;

    // Add a callback on an interface (specified by  ClassId)
    virtual CATCallback AddSubscription(CATBaseUnknown     *iEventManager,
				   CATCallbackEvent      iEvent,
				   CATSubscriberMethod   iMethod, 
				   const IID &           iInterfaceId,
				   CATSubscriberData     iData=NULL )=0; 


    // Remove all callbacks which concern :
    //        the same CATCallbackManager
    //        the same CATCallbackEvent
    //        the same CATSubscriberData
    virtual void RemoveSubscriptionsOn( CATBaseUnknown    *iEventManager,
                            CATCallbackEvent              iEvent,
                            char                          *iInterfaceName,
                            CATSubscriberData             iData  ) = 0;


    virtual void RemoveSubscriptionsOn( CATBaseUnknown     *iEventManager,
                            CATCallbackEvent              iEvent,
			    const IID &                   iInterfaceId,
                            CATSubscriberData             iData  ) = 0;

    // Remove all callbacks of this Client on a CATCallbackManager --
    virtual 
      void RemoveInterfaceSubscriptions( CATBaseUnknown   *iEventManager , 
                                         char            *iInterfaceName) =0;
    virtual 
      void RemoveInterfaceSubscriptions( CATBaseUnknown   *iEventManager , 
                                         const IID &      iInterfaceId)=0;


    // Give the associated CATCallbackManager if it exists ----------
    virtual CATCallbackManager *GetCallbackManager() = 0 ;

};
#endif
