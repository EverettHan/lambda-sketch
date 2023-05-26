#ifndef CATComponentIdPublisherFilter_H
#define CATComponentIdPublisherFilter_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
/**
* Interface to specify a filter on the contents of space.
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
#include "CATPLMTypeId.h"
#include "CATBoolean.h"
#include "CATPLMTypeH.h"
#include "CATOmxSR.h"

class CATPLMComponentSpaceFilter;
class CATOxEventsFilter;
class CATComponentIdEventsFilter;

extern const ExportedByCATPLMTos CATComponentIdEventsFilter CATComponentIdEventsFilter_Null;

/**
* This filtering mechanism is used to specify a global subscription at space level
*/
class ExportedByCATPLMTos CATComponentIdEventsFilter
{
public:
  inline CATComponentIdEventsFilter() {} //required on iOS:  error: default initialization of an object of const type 'const CATComponentIdEventsFilter' requires a user-provided default constructor const CATComponentIdEventsFilter CATComponentIdEventsFilter_Null;

  /**
  * Returns FALSE if valuated 
  */
  CATBoolean operator!() const {return !_ImplUsage;}

  /**
  * Define filter based on core type
  *
  * @param iType
  *    Specified Core Type filter
  */
  CATComponentIdEventsFilter & SetCoreTypeFilter( const CATPLMTypeH & iType );  

  /**
  * SetCoreTypeFilter 
  *
  * @param iType
  *    Specified Core Type filter
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT Init (const CATPLMComponentSpaceFilter & iAppFilter);

  //Default ctors are OK

  //Yep, this data member is public which is absolutely not an issue as the type is "opaque"
  CATOmxSR<CATOxEventsFilter> _ImplUsage;
};



#endif
