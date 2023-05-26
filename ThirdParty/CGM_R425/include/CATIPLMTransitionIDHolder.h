#ifndef CATIPLMTransitionIDHolder_H
#define CATIPLMTransitionIDHolder_H

// COPYRIGHT Dassault Systemes 2006
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
* @level Protected
* @usage U3
*/

//===================================================================
//
// Usage notes :
//
//===================================================================
//
//  November 2006 - Creation - pir
//===================================================================

#include "CATBaseUnknown.h"

#include "ExportedByCATPLMIdentification.h"
#include "CATIPLMTransitionIdentification.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIdentification IID IID_CATIPLMTransitionIDHolder;
#else
extern "C" const IID IID_CATIPLMTransitionIDHolder ;
#endif

//------------------------------------------------------------------
#define AuthorizedModule 999
// List of authorized modules
#define CATPLMIdentification	                   AuthorizedModule
#define TransitionEngine                           AuthorizedModule
#define CATPLMXmlSpecsConverter                    AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden Access To CATIPLMTransitionIDHolder from a non-authorized module
// Fatal error on solaris
@error 
#endif

#undef CATPLMIdentification
#undef TransitionEngine
#undef CATPLMXmlSpecsConverter

/**
 * 
 * <br><b>Role</b>: This interface allows to initialize a component with Transition Identification.
 * 
 */

class ExportedByCATPLMIdentification CATIPLMTransitionIDHolder : public CATBaseUnknown
{
 CATDeclareInterface;

 public:

  /**
   * Sets the CATIPLMTransitionIdentification interface pointer.
   *
   * <br><b>Role</b>: This method is used to initialize with Transition Identification access
   *
   * @param iTransitionIdentification
   * the CATIPLMTransitionIdentification interface pointer.
   *
   */
   virtual HRESULT SetTransitionIdentification(CATIPLMTransitionIdentification*& iTransitionIdentification) = 0;
    
};

#endif
