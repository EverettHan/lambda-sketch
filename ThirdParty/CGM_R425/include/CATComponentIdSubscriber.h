/* -*-c++-*- */
#ifndef CATComponentIdSubscriber_H
#define CATComponentIdSubscriber_H
// COPYRIGHT DASSAULT SYSTEMES 2005

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
 * @usage U1       
 */
#define AuthorizedModule                  999
#define CATPLMTos													AuthorizedModule
#define CATPLMIdentificationEvent					AuthorizedModule
#define CATPLMId_ABCoverage               AuthorizedModule
#define CATPLMEditabilityImpl             AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATComponentIdSubscriber
  @error 
#endif
#undef CATPLMTos 
#undef CATPLMIdentificationEvent
#undef CATPLMId_ABCoverage
#undef CATPLMEditabilityImpl
/**
*  Subscription on event about
*  By Interface CATIComponentIdSubscriber and subscription made explicitely by functions call 
*  AddSubscription/RemoveSubscription
*/
#include "ExportedByCATPLMTos.h"
#include "CATIComponentIdSubscriber.h"

class CATComponentIdEventsFilter;
class CATProxySpace;

class ExportedByCATPLMTos CATComponentIdSubscriber : public CATIComponentIdSubscriber
{
public:
  
	/** wewe
  * Add global subscription on space content by filter
  *
  * @param iSubscriber
  *   Interface on notification feedback
  *
  * @param iGlobalHandle
  *   Handle on Space
  *
  * @param iFilter
  *   Handle on Filter to by applied on Space content
  *   If no filter, use CATComponentIdEventsFilter_Null
  *
  * @param iEvents_MaskAnd
  *   Events on which subscription is done
  *    
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT AddGlobalSubscription(CATIComponentIdSubscriber        * iSubscriber,
                                       const CATProxySpace              & iGlobalHandle, 
										                   const CATComponentIdEventsFilter & iFilter,
                                       const CATComponentIdEvents         iEvents_MaskAnd);
  
  /**
  * Remove Subscription
  *
  * @param iSubscriber
  *   Interface on notification feedback
  *
  * @param iHandle
  *   Handle on Component that may be present or not 
  *
  * @return
  *      S_OK   if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT RemoveSubscription(CATIComponentIdSubscriber  * iSubscriber,
                                    const CATProxySpace          & iHandle);

private:

  CATComponentIdSubscriber(){}
  ~CATComponentIdSubscriber(){}
};


#endif
