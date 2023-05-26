#ifndef        CATPLMModelerLanguageRestricted_H  
#define        CATPLMModelerLanguageRestricted_H  

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

#define  TSTCATPLMMLExtMultiCustoEnrichAllCustoSimple               AuthorizedModule
#define  TSTCATPLMMLSimple                                          AuthorizedModule
#define  TSTCATPLMDbgML1                                            AuthorizedModule
#define  TSTCATPLMDbgML2                                            AuthorizedModule
#define  TSTCATPLMDbgML                                             AuthorizedModule
#define  TSTCATPLMDbgML4                                            AuthorizedModule
#define  TSTCATPLMDbgML5                                            AuthorizedModule
#define  TSTCATPLMDbgML6                                            AuthorizedModule
#define  TSTCATPLMDbgML7                                            AuthorizedModule
#define  TSTCATPLMDbgML8                                            AuthorizedModule
#define  TSTCATPLMDbgML9                                            AuthorizedModule
#define  TSTCATPLMML                                                AuthorizedModule
#define  TSTCATPLMMLActivity4_1                                     AuthorizedModule
#define  TSTCATPLMMLActivity4_2                                     AuthorizedModule
#define  TSTCATPLMMLActivity2                                       AuthorizedModule
#define  TSTCATPLMMLCusto                                           AuthorizedModule
#define  TSTCATPLMMLError                                           AuthorizedModule
#define  TSTCATPLMMLCustoAndFilter                                  AuthorizedModule
#define  TSTCATPLMMLExt                                             AuthorizedModule
#define  TSTCATPLMMLExtMultiCustoEnrichAllCusto                     AuthorizedModule
#define  TSTCATPLMMLGetRelationValue1                               AuthorizedModule
#define  TSTCATPLMMLGetPath                                         AuthorizedModule
#define  TSTCATPLMMLGetNbOfRel                                      AuthorizedModule
#define  TSTCATPLMMLGetRelationValue2_1                             AuthorizedModule
#define  TSTCATPLMMLGetRelationValue2_2                             AuthorizedModule
#define  TSTCATPLMMLIRPCER                                          AuthorizedModule
#define  TSTCATPLMMLInfra                                           AuthorizedModule
#define  TSTCATPLMMLMultiCustoEnrichAllCusto                        AuthorizedModule
#define  TSTCATPLMMLMcx                                             AuthorizedModule
#define  TSTCATPLMMLMultiCustoFilterAllCusto                        AuthorizedModule
#define  TSTCATPLMMLMultiCustoFilterOneCusto                        AuthorizedModule
#define  TSTCATPLMMLOptions2                                        AuthorizedModule
#define  TSTCATPLMMLOptions1                                        AuthorizedModule
#define  TSTCATPLMMLPlmidOnly1                                      AuthorizedModule
#define  TSTCATPLMMLTransientTOS                                    AuthorizedModule
#define  TSTCATPLMMLPlmidOnly2                                      AuthorizedModule
#define  TSTCATPLMMLPostFiltering                                   AuthorizedModule
#define  TSTCATPLMMLSession                                         AuthorizedModule
#define  TSTCATPLMMLUIDebug                                         AuthorizedModule
#define  TSTCATPLMMLSyntaxConnectionToRef                           AuthorizedModule
#define  TSTCATPLMMLSyntaxInstToRef                                 AuthorizedModule
#define  TSTCATPLMMLSyntaxRefToConnection                           AuthorizedModule
#define  TSTCATPLMMLSyntaxRefToInst                                 AuthorizedModule
#define  TSTCATPLMDbgTag                                            AuthorizedModule
#define  TSTCATPLMDbgClauseSubClauseForRel                          AuthorizedModule
#define  TSTCATPLMMLBugCuzin                                        AuthorizedModule
#define  TSTCATPLMMLWithRealConnection                              AuthorizedModule
#define  TSTCATPLMMLNewTyping1                                      AuthorizedModule
#define  TSTCATPLMMLNewTyping2                                      AuthorizedModule
#define  TSTCATPLMMLNewTyping3                                      AuthorizedModule
#define  TSTCATPLMMLNewTyping4                                      AuthorizedModule
#define  TSTCATPLMMLNewTyping5                                      AuthorizedModule
#define  TSTCATPLMMLInstRelEnt1                                     AuthorizedModule
#define  TSTCATPLMMLInstRelEnt1Ext                                  AuthorizedModule
#define  TSTCATPLMMLInstRelEnt1ExtNoAttr                            AuthorizedModule
#define  TSTCATPLMMLInstRelEnt1ExtInheritance                       AuthorizedModule
#define  TSTCATPLMMLInstRelEnt2                                     AuthorizedModule
#define  TSTCATPLMMLInstRelEnt3                                     AuthorizedModule
#define  TSTCATPLMMLInstRelEnt4                                     AuthorizedModule
#define  TSTCATPLMDbgNavCatISOWNEDBY                                AuthorizedModule
#define  TSTCATPLMDbgInstRelEnt1                                    AuthorizedModule
#define  TSTCATPLMDbgInstRelEnt2                                    AuthorizedModule
#define  TSTCATPLMDbgInstRelEnt3                                    AuthorizedModule
#define  TSTCATPLMDbgInstRelEnt4                                    AuthorizedModule
#define  TSTCATPLMMLAddAttribute                                    AuthorizedModule
#define  TSTCATPLMMLInstRelEnt5                                     AuthorizedModule
#define  TSTCATPLMMLInstRelEnt6                                     AuthorizedModule
#define  TSTCATPLMMLInstRelEnt7                                     AuthorizedModule
#define  TSTCATPLMDbgNavComplex3                                    AuthorizedModule
#define  TSTCATPLMMLNavComplex3                                     AuthorizedModule
#define  TSTCATPLMMLMultiPrimaryKey                                 AuthorizedModule

#define  CATPLMTagModeler                                           AuthorizedModule
#define  CATPLMCompletionAccess                                     AuthorizedModule//  yt5
#define  CATPLMIntegrationAccess                                    AuthorizedModule//  yt5
#define  CATPLMModelBuilder                                         AuthorizedModule//  CATRevealIPModel                              (VPMNAV)
#define  CATImmRFLPLinksDecoder                                     AuthorizedModule
#define  CATPLMEditorServices                                       AuthorizedModule// modif NR8 - HO2 request
#define  PLMPIMOpenCommonServices                                   AuthorizedModule
#define  CATPLMEditorModelServices                                  AuthorizedModule

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
#undef  TSTCATPLMDbgML
#undef  TSTCATPLMDbgML4
#undef  TSTCATPLMDbgML5
#undef  TSTCATPLMDbgML6
#undef  TSTCATPLMDbgML7
#undef  TSTCATPLMDbgML8
#undef  TSTCATPLMDbgML9
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
#undef  TSTCATPLMMLSession
#undef  TSTCATPLMMLUIDebug
#undef  TSTCATPLMMLSyntaxConnectionToRef
#undef  TSTCATPLMMLSyntaxInstToRef
#undef  TSTCATPLMMLSyntaxRefToConnection
#undef  TSTCATPLMMLSyntaxRefToInst
#undef  TSTCATPLMDbgTag
#undef  TSTCATPLMDbgClauseSubClauseForRel
#undef  TSTCATPLMMLBugCuzin
#undef  TSTCATPLMMLWithRealConnection
#undef  TSTCATPLMMLNewTyping1
#undef  TSTCATPLMMLNewTyping2
#undef  TSTCATPLMMLNewTyping3
#undef  TSTCATPLMMLNewTyping4
#undef  TSTCATPLMMLNewTyping5
#undef  TSTCATPLMMLInstRelEnt1
#undef  TSTCATPLMMLInstRelEnt1Ext
#undef  TSTCATPLMMLInstRelEnt1ExtNoAttr
#undef  TSTCATPLMMLInstRelEnt1ExtInheritance
#undef  TSTCATPLMMLInstRelEnt2
#undef  TSTCATPLMMLInstRelEnt3
#undef  TSTCATPLMMLInstRelEnt4
#undef  TSTCATPLMDbgNavCatISOWNEDBY
#undef  TSTCATPLMDbgInstRelEnt1
#undef  TSTCATPLMDbgInstRelEnt2
#undef  TSTCATPLMDbgInstRelEnt3
#undef  TSTCATPLMDbgInstRelEnt4
#undef  TSTCATPLMMLAddAttribute
#undef  TSTCATPLMMLInstRelEnt5
#undef  TSTCATPLMMLInstRelEnt6
#undef  TSTCATPLMMLInstRelEnt7
#undef  TSTCATPLMDbgNavComplex3
#undef  TSTCATPLMMLNavComplex3
#undef  TSTCATPLMMLMultiPrimaryKey

#undef  CATPLMTagModeler
#undef  CATPLMCompletionAccess
#undef  CATPLMIntegrationAccess
#undef  CATPLMModelBuilder
#undef  CATImmRFLPLinksDecoder
#undef  CATPLMEditorServices
#undef  PLMPIMOpenCommonServices
#undef  CATPLMEditorModelServices

#if defined(__CATPLMModelerLanguage)
#define ExportedByCATPLMModelerLanguage DSYExport
#else
#define ExportedByCATPLMModelerLanguage DSYImport
#endif
#include "DSYExport.h"

#endif
