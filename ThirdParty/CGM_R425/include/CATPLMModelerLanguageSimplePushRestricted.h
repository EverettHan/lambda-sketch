#ifndef        CATPLMModelerLanguageSimplePushRestricted_H  
#define        CATPLMModelerLanguageSimplePushRestricted_H  

/**
 *    @required
*/

//-----------------------------------------------------
//    Check  that  only  authorized  modules  can  link  on  the  exported  symbols
//----------------------------------------------------

//  List  of  forbidden  re-define
#if  defined  (private)  ||  defined(friend)  ||  defined  (protected)
    #error  Forbidden  re-define  of  'private',  'friend'  or  'protected'
        //  Fatal  error  on  solaris
        @error  
#endif

#define  AuthorizedModule          999

//  List  of  authorized  infrastructure  modules  
#define  CATPLMModelerLanguage                                      AuthorizedModule
#define  CATPLMMLEngine                                             AuthorizedModule
#define  CATPLMMLCreateTable                                        AuthorizedModule
#define  CATPLMMLParsingEngine                                      AuthorizedModule
#define  CATPLMMLDicoCheckEngine                                    AuthorizedModule
#define  CATPLMMLPostFiltering                                      AuthorizedModule
#define  CATPLMMLCSExchange                                         AuthorizedModule
#define  CATPLMModelBuilder                                         AuthorizedModule

#define  TSTCATPLMMLInfra                                           AuthorizedModule

#if  _MK_MODNAME_  ==  AuthorizedModule

#else

#error  Forbidden  Access  To  CATPLMModelerLanguage  Services  from  a  non-authorized  module
//  Fatal  error  on  solaris
@error  
#endif

#undef  AuthorizedModule

//  List  of  authorized  infrastructure  modules  
#undef  CATPLMModelerLanguage
#undef  CATPLMMLEngine
#undef  CATPLMMLCreateTable
#undef  CATPLMMLParsingEngine
#undef  CATPLMMLDicoCheckEngine
#undef  CATPLMMLPostFiltering
#undef  CATPLMMLCSExchange
#undef  CATPLMModelBuilder

#undef  TSTCATPLMMLExtMultiCustoEnrichAllCustoSimple
#undef  TSTCATPLMMLSimple
#undef  TSTCATPLMDbgML1
#undef  TSTCATPLMDbgML2
#undef  TSTCATPLMDbgML3
#undef  TSTCATPLMDbgML4
#undef  TSTCATPLMDbgML5
#undef  TSTCATPLMDbgML6
#undef  TSTCATPLMDbgML7
#undef  TSTCATPLMDbgML8
#undef  TSTCATPLMML
#undef  TSTCATPLMMLActivity4_1
#undef  TSTCATPLMMLActivity4_2
#undef  TSTCATPLMMLActivity2
#undef  TSTCATPLMMLCusto
#undef  TSTCATPLMMLError
#undef  TSTCATPLMMLCustoAndFilter
#undef  TSTCATPLMMLExt
#undef  TSTCATPLMMLExtMultiCustoEnrichAllCusto
#undef  TSTCATPLMMLGetRelationValue1
#undef  TSTCATPLMMLGetPath
#undef  TSTCATPLMMLGetNbOfRel
#undef  TSTCATPLMMLGetRelationValue2_1
#undef  TSTCATPLMMLGetRelationValue2_2
#undef  TSTCATPLMMLIRPCER
#undef  TSTCATPLMMLInfra
#undef  TSTCATPLMMLMultiCustoEnrichAllCusto
#undef  TSTCATPLMMLMcx
#undef  TSTCATPLMMLMultiCustoFilterAllCusto
#undef  TSTCATPLMMLMultiCustoFilterOneCusto
#undef  TSTCATPLMMLOptions2
#undef  TSTCATPLMMLOptions1
#undef  TSTCATPLMMLPlmidOnly1
#undef  TSTCATPLMMLTransientTOS
#undef  TSTCATPLMMLPlmidOnly2
#undef  TSTCATPLMMLPostFiltering
#undef  TstCATPLMMLSession
#undef  TSTCATPLMMLUIDebug
#undef  TSTCATPLMMLSyntaxConnectionToRef
#undef  TSTCATPLMMLSyntaxInstToRef
#undef  TSTCATPLMMLSyntaxRefToConnection
#undef  TSTCATPLMMLSyntaxRefToInst
#undef  TSTCATPLMDbgTag
#undef  TSTCATPLMDbgClauseSubClauseForRel
#undef  TSTCATPLMMLBugCuzin

#undef  CATPLMTagModeler
#undef  CATPLMCompletionAccess
#undef  CATPLMIntegrationAccess
#undef  CATPLMModelBuilder

#if defined(__CATPLMModelerLanguage)
#define ExportedByCATPLMModelerLanguage DSYExport
#else
#define ExportedByCATPLMModelerLanguage DSYImport
#endif
#include "DSYExport.h"

#endif
