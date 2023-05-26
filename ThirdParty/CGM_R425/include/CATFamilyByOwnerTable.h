/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2006
#ifndef CATFamilyByOwnerTable_H
#define CATFamilyByOwnerTable_H
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
// Class CATFamilyByOwnerTable:
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
 * @usage U1
 */

class CATLogicalAlternativesByOwner;

/**
  * Class used to iterate through a list of families of components ordered by owners for the bundle reroute.
  * <b>Role</b>: CATFamilyByOwnerTable provides access to a set {owner, map {original -> new component }}. Each
  * family is used to build a possible solution during a reroute of a bundle of relations.
  */
class CATFamilyByOwnerTable
{
public:
	/** @nodoc */
	virtual ~CATFamilyByOwnerTable() {};
	
	/**
     * Select the next element
     */
   	virtual void operator++ () = 0;		// prefix incrementation
   
   	/**
     * Select the next element
     */
   	virtual void operator++ (int) = 0;	// postfix incrementation
   
   	/**
     * Returns the element currently pointed by the iterator
     * @return
     *   CATLogicalAlternativesByOwner*:	An object that is pointing the @href CATLogicalAlternativesByOwner.
     *   NULL:	The iteration is finished.
     */
   	virtual CATLogicalAlternativesByOwner* operator() () = 0;
};

#endif
