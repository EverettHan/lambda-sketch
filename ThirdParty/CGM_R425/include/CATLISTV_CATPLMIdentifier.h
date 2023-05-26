/* -*-c++-*- */
#ifndef CATLISTV_CATPLMIdentifier_H
#define CATLISTV_CATPLMIdentifier_H
/* -*-c++-*- */
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
 * @usage U3
 */
#include "CATPLMIdentificationAccess.h"

#include "CATPLMIdentifier.h"


// Clean previous functions requests
#include "CATLISTV_Clean.h"

// Require needed functions
#define CATLISTV_Append
#define CATLISTV_AppendList
#define CATLISTV_RemoveValue
#define CATLISTV_RemovePosition
#define CATLISTV_RemoveAll
#define CATLISTV_Locate

// Get macros
#include "CATLISTV_Declare.h"

// Generate interface of collection-class
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATPLMIdentificationAccess

CATLISTV_DECLARE( CATPLMIdentifier )

typedef CATLISTV( CATPLMIdentifier ) CATPLMIdentifiers;


#endif
