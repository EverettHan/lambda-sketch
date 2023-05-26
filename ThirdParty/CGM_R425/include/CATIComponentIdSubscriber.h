#ifndef CATIComponentIdSubscriber_H
#define CATIComponentIdSubscriber_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
/* 
* @COPYRIGHT DASSAULT SYSTEMES 2004
* ----------------------------------------------------------------------------------------------------------------------
*   Origin              : Local running (inside wintop) of remote persistency entity 
*                            associative kernel change/data set of ... actors ...
*                            made as simple as possible to be affordable for enhanced infrastructure integration
*   Software's Category : Physical Layer (Middleware services) dedicated to client side
*                            (in a kind of software classification similar to the layered OSI Network 
*                             upper (logical) Layer is mainly about two main axis  (
*                                  Modeler (domain) specialisation (for Data and Attributes ...)
*                                  Upper Levering Operand Integration exchange (QEOPS, 
*   Premilinary         : Do not forget to contact your Database Administrators or any other representative
*                            (Authoring definition) for more convenient support 
*                          (Just to be sure that appropriate schema (Table for Data , or Services) are supported 
*                              when reference persistency occured when dealing with local work realized  )
*   Specification       : Simple genuine (re-usable) services about 
*                            - associativity between local insulated implementation and shared remote repository
*                            - synthetic change set (persistency intents)
*   Limitations         : No attributes vocabulary provided to let this current functional component software 
*                              be as comprehensible in specifications
*                         Status is slaved to Modelers deployement and Behaviors
*                             for more detailled specification (UML sequence diagram, statechart, ..)  
*                             consult specialized specifications database relative to upper Logical Software layer 
*                             it means Product Structure Legacy, PLM Client Core, Representation Model
*   Favorites entry-point for developpers :
*                         CATPLMRepositoryName : Repository classification 
*                         CATProxySpace   : Instance of a domain resolution                    
*                         CATComponentId  : Handle on primary associativity between local and remote entity           
* ------------------ ----------------------------------------------------------------------------------------------------
*/

/**
 * @level Private
 * @usage U5       
 */
/**
*  Management of subscription on PLM component  
*        
*  Using subscription is made in two steps :
*   *) Build-Time : adhesion somewhere to Interface CATIComponentIdSubscriber
*   *) Run-Time   : dynamic subsription
*                   CATComponentIdSubscriber::AddGlobalSubscription
*                   CATComponentIdSubscriber::RemoveSubscription
*
*  Global subscription :
*   *) Global mode allows to register a space content after applying filters. 
*      One by one registration is no more supported.
*
*      code samples :
*
*      // Global subscription
*      CATComponentIdSubscriber::AddGlobalSubscription(Subscriber3,                      [Subscriber]
*                                                        SPACE,                            [Space]
*                                                        CATComponentIdFilter_Null,      [No Filters]
*                                                        CATComponentIdEvent_Waiting |     [2 Events]
*                                                        CATComponentIdEvent_Editability);  
*
*      // Global subscription with filters
*      CATComponentIdEventsFilter Filter;
*      Filter.SetCoreTypeFilter(CATPLMTypeId_CoreRepReference);
*      CATComponentIdSubscriber::AddGlobalSubscription(Subscriber2,                      [Subscriber]
*                                                        SPACE,                            [Space]
*                                                        Filter,                           [Filters]
*                                                        0xFFFFFFFF);                      [All Events]
*
*  Asynchronous vs Synchronous :
*   *) If an asynchronous transaction is opened all the events are systematically 
*      bufferised and sent when transaction is flushed. If new events are sent
*      during asynchronous dispathing, events can be intercepted by an other
*      asynchronous transaction or sent in synchronous mode.
* 
*      code samples : 
* 
*    	 CATProxySpace TransactionContext (...);
*
*      // Activate asynchronous mode
*      CATBoolean iOkayEndingStatus = TRUE;
*      CATProxyTransactionBegin(TransactionContext, AsynchronousArea, CatPLMUnknownTransaction); 
*      
*      ---- NO EVENTS DISPATCHING ----      
*
*      // Desactivate asynchronous mode
*      CATProxyTransactionEnd(TransactionContext, AsynchronousArea, iOkayEndingStatus);
*/
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATComponentIdEvents.h"

class CATComponentId;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMTos IID IID_CATIComponentIdSubscriber;
#else
extern "C" const IID IID_CATIComponentIdSubscriber ;
#endif

/** 
* Management of TOS holding object
* */
class ExportedByCATPLMTos CATIComponentIdSubscriber : public CATBaseUnknown
{
  CATDeclareInterface;
  
public:

  /**
  * Starting dispatch phase
  */
  virtual void OnDispatchStarting() = 0;

  /** 
  * Notification 
  *
  * @param iHandle
  *   Handle on proxy component
  *
  * @param iEvents_MaskAnd
  *    Associated Events (several events simultaneously notified in asynchronous mode)
  *    
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  * */
  virtual HRESULT Notification(const CATComponentId      & iHandle,
                               const CATComponentIdEvents  iEvents_MaskAnd) = 0;

  /**
  * Ending dispatch phase
  */
  virtual void OnDispatchEnding() = 0;
};

CATDeclareHandler( CATIComponentIdSubscriber, CATBaseUnknown );


#endif
