/* -*-c++-*- */
#ifndef CATComponentIdSearch_H
#define CATComponentIdSearch_H
// COPYRIGHT DASSAULT SYSTEMES 2005
/**
* ToolBox for small services on CATComponentId handle
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

//           
//           
//                       
//            A Sample about Object in memory search
//           
//              /*
//                  Specifications of search criteria
//              */
//              CATComponentIdFilter Query;
//              {
//                /*
//                    Focused on  : still in session + deleted entity + entity To Create 
//                    To avoid avoid  garbaged entity
//                */
//                Query.SetPersistencyFilter(TRUE);
//           
//           
//                /*
//                   If Scope is specified , propagation in session is done
//                */
//                CATLISTV( CATComponentId ) Roots;
//                if ( Roots.Size() > 0 )
//                  Query.SetStartingWithRoot(TRUE,Roots);
//                /*
//                     Contexte Interactif
//                */
//                else  if ( TRUE == CATPLMIsUnderODT::IsInteractiveApplication() )
//                 Query.SetStartingWithEdited(TRUE);
//           
//                /*
//                    Extend analysis from startings points 
//                       ( Scope, Roots, Tos , ..
//                */
//                Query.SetWithExpandPointedScope(TRUE);
//           
//                /*
//                     Filtered with LOG pending to  avoid opened entities
//                */
//                Query.SetFilterByTodoStatus(TRUE);
//           
//                /*
//                    Filtered on Only Activated InSession 
//                */
//                Query.SetInMemory(CatTosQuery_OnlyActivatedInSession);
//           
//                /*
//                    Filtered on targetted Core Type
//                */
//                Query.SetCoreTypeFilter(CATPLMTypeId_PLMPort);
//              }
//           
//              /*
//                 Search running
//              */
//              CATComponentIdSet *Result = NULL;
//           
//              HRESULT rcSearch = ::CATComponentIdSearch(Query,Result);
//           
//              /*
//                  Analysis of result
//              */
//              if ( Result) 
//              {
//                CATLISTV( CATBaseUnknown_var ) PLMEntities;
//           
//                Result->GetList(PLMEntities);
//                CATSysReleasePtr(Result);
//           
//                int nbPLMEntities = PLMEntities.Size();
//                for ( int numPLMEntity=1; numPLMEntity<=nbPLMEntities ; numPLMEntity++ )
//                {
//                  CATBaseUnknown_var Entity = PLMEntities[numPLMEntity];
//                  ...
//                }
//              }
//           
//           
//           */
//           
//           

class CATComponentIdFilter;
class CATComponentIdSet;


/** 
* Search object/identifier used in Session, which are matching a specific criteria.
*
* This services could be expensive in Cpu/Times as it depends of current status of session
*   and behave like a kind of ListMembers on container like.
*
* @param iQueryFilter
*   The filter that allows you to narrow the list of target object/identifier.
*   <b>Warning:</b> If this filter is filtered by TOS with a space protected by UUID, 
*   the search will be limited to this space only. Otherwise spaces with UUID are hidden.
*    
* @param oResult
*   Interface on the list of target object/identifier. 
*   Release() after usage the returned value of oResult.
*
* @return
*    Error code of function :
*   <dl>
*     <dt>S_OK</dt>
*     <dd>the new current record is valid.</dd>
*     <dt>S_FALSE</dt>
*     <dd>there are no result.</dd>
*     <dt>E_FAIL </dt>
*     <dd>A problem occurs</dd>
*   </dl>
*/
ExportedByCATPLMTos HRESULT CATComponentIdSearch(CATComponentIdFilter   & iQueryFilter,
                                                 CATComponentIdSet   *  & oResult );

#endif
