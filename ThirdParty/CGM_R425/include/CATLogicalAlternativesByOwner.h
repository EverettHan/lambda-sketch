/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2006
#ifndef CATOwnerOrderedLogicalAlternatives_H
#define CATOwnerOrderedLogicalAlternatives_H
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
//=============================================================================
//
// Class CATOwnerOrderedLogicalAlternatives:
//
//=============================================================================
// Usage Notes: Storage class used to communicate new alternatives during
//				a bundle reroute.
//
//=============================================================================
// apr 06   Creation                                   LPQ
//=============================================================================

/**
 * @level Private
 * @usage U3
 */


#include "CATComponentId.h"
#include "ExportedByCATPLMTos.h"

/**
  * Storage class used during the reroute of a bundle to store a family of logically equivalent components.
  * <b>Role</b>: CATLogicalAlternativesByOwner provides access to a map {original -> new component list } for the
  * targets pointed by the bundle.
  */
class ExportedByCATPLMTos CATLogicalAlternativesByOwner
{
public:

	/**
	 * Returns the common owner of all the alternatives presented in the collection.
	 * @return
	 *		The owner.
	 */
	virtual const CATComponentId& GetOwner() const = 0;

	/**
	 * Returns the list of logical equivalences of a target aggregated under the owner.
	 *	@param iOriginalComponent
	 *		The target of the relation for which equivalents are required.
	 *	@param oAlternatives
	 *		The list of components logically equivalent to iOriginalComponent under the owner.
	 */
	virtual void GetAlternatives(
		CATComponentId& iOriginalComponent,
		CATLISTV( CATComponentId )& oAlternatives ) const = 0;
};

#endif
