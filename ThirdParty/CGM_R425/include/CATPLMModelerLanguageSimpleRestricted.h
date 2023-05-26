#ifndef        CATPLMModelerLanguageSimpleRestricted_H  
#define        CATPLMModelerLanguageSimpleRestricted_H  

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

#define  TSTCATPLMMLInfra                                           AuthorizedModule
#define  TSTCATPLMMLMultiCustoEnrichAllCusto                        AuthorizedModule
#define  TSTCATPLMMLError                                           AuthorizedModule
#define  TSTCATPLMMLSession                                         AuthorizedModule
#define  TSTCATPLMMLSyntaxConnectionToRef                           AuthorizedModule
#define  TSTCATPLMMLSyntaxRefToConnection                           AuthorizedModule
#define  TSTCATPLMMLSyntaxInstToRef                                 AuthorizedModule
#define  TSTCATPLMMLSyntaxRefToInst                                 AuthorizedModule
#define  TSTCATPLMMLUIDebug                                         AuthorizedModule

#define  CATPLMTagModeler                                           AuthorizedModule
#define  CATPLMCompletionAccess                                     AuthorizedModule
#define  CATPLMIntegrationAccess                                    AuthorizedModule
#define  CATPLMModelBuilder                                         AuthorizedModule
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

#undef  TSTCATPLMMLInfra
#undef  TSTCATPLMMLMultiCustoEnrichAllCusto
#undef  TSTCATPLMMLError
#undef  TSTCATPLMMLSession
#undef  TSTCATPLMMLSyntaxConnectionToRef
#undef  TSTCATPLMMLSyntaxRefToConnection
#undef  TSTCATPLMMLSyntaxInstToRef
#undef  TSTCATPLMMLSyntaxRefToInst
#undef  TSTCATPLMMLUIDebug

#undef  CATPLMTagModeler
#undef  CATPLMCompletionAccess
#undef  CATPLMIntegrationAccess
#undef  CATPLMModelBuilder
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
