#ifndef CATAdpEditability_H
#define CATAdpEditability_H
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
*//**
 * @level Private
 * @usage U1
 */



/**
 * Definition on editibility Status (Draft originated to reviewed). Authoring edition enabler :
 *
 *    1) Short introduction, as an academic attempt for newcomers
 *        This tactical mecanism is an alternative to manage a subset of changes 
 *            by means of an elementary physical level of detail (and not through a logical structuring level)
 *        All this stuff turns around remote persistency locking strategy and atomic status on Entity
 *            this explains why this topic is classify here in this Software's Category 
 *        Requirement is about status Holded/associated to any modeler entity (basic purpose)
 *        Remarks : As it does not impact entity definition, Concurrent Engineering Stamp 
 *                  it remains stable through this particular change of value.
 *
 *    2) Value is by default managed accorded to following behavior
 *           a) "undefined" value is provided to support waiting/pointed references.
 *           b) when usable working form is associated to  
 *                   "ReadOnly"  when under an OpenEngine transaction context
 *                      (so add-on services should engaged at this end of Open tu fullfill assocatied authorisation
 *                         see CATIPLMClientCoreMastering offer)
 *                   "ReadWrite" otherwise 
 *           c) Enhanced specification about local cache short term persistency (when engaged)
 *                   current value is saved and restored as it was before 
 (                   (see CATProxySpace IntoRawBox/FromRawBox/RestoreRebind)     
 *
 *    3) May be Granted/Revoked ponctually and manually accorded by People & Organisation control.
 *         to be documented about appropriate API and interactive GUI commands.
 *
 *    4) Given as edition helper to differentiate between
 *           a) What is enable    : high probalility of no dead-lock locking problems
 *           b) What is forbidden : to avoid/anticipate a deny of persistency save
 *
 *    5) Enhanced specification : Local Session cache value may be incoherent with the referential shared repository
 *       so refresh may occasionnaly needed 
 *           a) if user access/change this value by concurrent means by 
 *                  - distinct tools (webtop and wintop)
 *                  - distinct mutiple view managed as independantly 
 *                      (it has to precise according to original command offered to change status)
 *                (Think according to expand/opened classification windows 
 *                  or mutiple windows generated according along times with )
 *           b) if another user with administrative rights access/change this value
 *
 *
 * <tt> Possible values:</tt>
 * <dl>
 * @param <tt>CatAdpEditability_Undefined</tt>   <dd>if not meaningfull (waiting CID).   
 * @param <tt>CatAdpEditability_ReadOnly</tt>    <dd>Default behavior for opened entity.   
 * @param <tt>CatAdpEditability_ReadWrite</tt>   <dd>Default behavior for created entity.      
 * </dl>
 */
enum  CATAdpEditability 
{
    CatAdpEditability_Undefined,
    CatAdpEditability_ReadOnly,
    CatAdpEditability_ReadWrite
};

 

#endif
