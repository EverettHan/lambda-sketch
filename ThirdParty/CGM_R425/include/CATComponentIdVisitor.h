#ifndef CATComponentIdVisitor_H
#define CATComponentIdVisitor_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
/**
* Interface to browse the result of ::CATComponentIdSearch  query.
* <br>It is a kind of generic iterator hidding implementation.
*/
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
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"

class CATComponentId;

/**
 * This makes possible to give a light access to a list of components
 */
class ExportedByCATPLMTos CATComponentIdVisitor
{
public:

  /**
  * CATBehaviour_continue : visit next component 
  * CATBehaviour_break    : stop iteration
  */
  enum CATBehaviour {CATBehaviour_break, CATBehaviour_continue};

  CATComponentIdVisitor();
  virtual ~CATComponentIdVisitor();
  virtual CATBehaviour Visit(CATComponentId & iCID) = 0;
};
 
#endif
