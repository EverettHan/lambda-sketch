#ifndef CATIComponentIdEvents_H
#define CATIComponentIdEvents_H
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
#if ! defined ( CATComponentIdEvents_definition )
#define CATComponentIdEvents_definition
typedef unsigned int CATComponentIdEvents;
#endif

/** --------------------------------------------------------------------------------
*        Official management of Waiting List
* You must check that the component is not already here
* -------------------------------------------------------------------------------- */

/** @nodoc */
#define CATComponentIdEvent_None              0x00000000

/** @nodoc Number of bits needed inside Bit Fields */
#define CATComponentIdEvent_Cardinality               16

/** @nodoc */
#define CATComponentIdEvent_Waiting           0x00000001
/** @nodoc */
#define CATComponentIdEvent_Versioned         0x00000002
/** @nodoc */
#define CATComponentIdEvent_Activated         0x00000004
/** @nodoc */
#define CATComponentIdEvent_Garbaged          0x00000008
/** @nodoc */
#define CATComponentIdEvent_Destroyed         0x00000010
/** @nodoc */
#define CATComponentIdEvent_Clearing          0x00000020
/** @nodoc */
#define CATComponentIdEvent_Editability       0x00000040
/** @nodoc */
#define CATComponentIdEvent_Relational        0x00000080
/** @nodoc */
#define CATComponentIdEvent_Cloned            0x00000100

/**
* Is sent when component is synchronized
* A more generic event can be used : @see CATComponentIdEvent_Imported
*/
#define CATComponentIdEvent_Synchronized     0x00000200

/**
* Is sent when component is opened
* A more generic event can be used : @see CATComponentIdEvent_Imported
*/

#define CATComponentIdEvent_Collaborated      0x00000800

/**
* Is sent when component is imported as new
* A more generic event can be used : @see CATComponentIdEvent_Imported
*/
#define CATComponentIdEvent_ImportedAsNew     0x00001000

/**
* Is sent when component is imported as new
* A more generic event can be used : @see CATComponentIdEvent_Imported
*/
#define CATComponentIdEvent_Overloaded        0x00002000

/**
* Is sent when component is imported as new
* A more generic event can be used : @see CATComponentIdEvent_Imported
*/
#define CATComponentIdEvent_Restored          0x00004000

/**
* Is sent when component arrived in memory.
* If the working context is necessary, it possible to use specialized events :
* @see CATComponentIdEvent_Refreshed
* @see CATComponentIdEvent_Restored
* @see CATComponentIdEvent_Overloaded
* @see CATComponentIdEvent_Colaborated
* @see CATComponentIdEvent_ImportedAsNew
*/
#define CATComponentIdEvent_Imported          0x00008000

#endif
