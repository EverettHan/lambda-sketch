/* -*-c++-*- */
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
* @usage U3
*/
#ifndef CATPLMIsUnderODT_H
#define CATPLMIsUnderODT_H

#include "CATPLMIdentificationAccess.h"
#include "CATPLMRepositoryName.h"
#include "CATBooleanDef.h"
#include "CATLISTV_CATPLMIdentifier.h"
#include "CATPLMIdentificationAccessMacros.h"
#include "CATTosDumpOptions.h"

/**  @nodoc   */ 
class CATOxTransaction;
class CATOmxUTF8String;


class ExportedByCATPLMIdentificationAccess CATPLMIsUnderODT 
{
public :

  /** 
  *   TOOLS  : dedicated for ODT
  *   Dump PLM Session in html format
  *
  * @param pContext
  *        Describe calling context
  * @param iDumpOptions
  *        Drive dump content
  * @return
  *        S_OK   : if succeeded
  *        E_FAIL : if failure
  */
  static HRESULT DumpRegisters(const char pContext[], CATTosDumpOptions iDumpOptions = CATTosDumpOptions_SPACES);

  /**
  * For detection of ODT context
  * Permets de pallier les problemes de contexte de sortie d'ODT
  */
  static CATBoolean IsUnderODT(size_t       iMaxNameLength      = 0,
    char        *iopName             = NULL,
    size_t      *iopFilledNameLength = NULL); 

  /**
  * Detect perfo odts
  */
  static CATBoolean IsPerfOnly(); 
private:
     /** 
     *   TOOLS  : dedicated for ODT
     *   Dump PLM Session in html format
     *
     * @param pContext
     *        Describe calling context
     * @param iDumpOptions
     *        Drive dump content
     * @return
     *        S_OK   : if succeeded
     *        E_FAIL : if failure
     */
  static HRESULT DumpRegisters(const char pContext[], CATTosDumpOptions iDumpOptions, const CATUnicodeString iDumpPath );


  /**  @nodoc 
  * In ODT mode, returns a file beginning  "ADL_ODT_OUT/ODT_LOG_NAME."
  *   that can have a suffix to generate special outputs
  *  const char *MyPrefix = CATPLMIsUnderODT::GetOutput();
  */
  static CATOmxUTF8String GetOutputDir(); 
  static CATOmxUTF8String GetOdtName(); 

  static void InitIfNecessary();
  static void _LocalInitIfNecessary();

  friend class CATOxTransaction;
  friend class CATOxSingleton;
  friend class CATTosRestrictedUsed;
  friend class CATPLMTosPendingProviderImpl;
 friend class CATPLMQEServices;
};
#endif

