//-----------------------------------------------------
//  Check that only authorized modules can link on the exported symbols
//----------------------------------------------------

/**
 * @level Private
 * @usage U3
 */

#ifndef CATPLMServicesItfLimitedAccess_H
#define CATPLMServicesItfLimitedAccess_H

// ----------------------------------------------------------------------
// List  of  forbidden  re-define  
// ----------------------------------------------------------------------
#if  defined  (private)  ||  defined(friend)  ||  defined  (protected)  
        #error  Forbidden  re-define  of  'private',  'friend'  or  'protected'  
        //  Fatal  error  on  solaris  
        @error    
#endif  

#define  AuthorizedModule  999  

// ----------------------------------------------------------------------
// Define  List  of    authorized  modules  using  CATDexInterfaces  private  intefaces  
// ----------------------------------------------------------------------
#define  CATPLMImplAdapterQLBase                    AuthorizedModule// CATPLMImplAdapterQL
#define  CATPLMServicesLimitAccess                  AuthorizedModule// CATPLMServices
#define  CATPLMImplAdapterQLUUID                    AuthorizedModule// CATPLMImplAdapterQL
#define  CATPLMxQueryDataSet                        AuthorizedModule// CATPLMImplAdapterQL
#define  CATPLMxQueryPLMQL                          AuthorizedModule// CATPLMImplAdapterQL
#define  CATPLMServicesItf                          AuthorizedModule// CATPLMServices
#define  CATPLMServicesProc                         AuthorizedModule// CATPLMServices
#define  CATPLMxProviderImpl                        AuthorizedModule// CATPLMImplMx
#define  CATPLMxTSTProviderImpl                     AuthorizedModule// CATPLMProviderDebug
#define  CATPLMxProcCall                            AuthorizedModule// CATPLMImplAdapterQL
#define  TSTCATPLMxProcedureCallBase                AuthorizedModule// CATPLMImplAdapterQL.tst
#define  TSTCATPLMxProcedureCallInfra               AuthorizedModule// CATPLMImplAdapterQL.tst
#define  TstMxCommandFactory1                       AuthorizedModule// CATPLMImplMx.tst
#define  CATPLMIndexItfImpl                         AuthorizedModule// CATPLMIndexItfImpl
#define  CATAsyncProcess                            AuthorizedModule// CATPLMCommunication
#define  CATPLMiPMLDataStream                       AuthorizedModule// CATPLMImplAdapterQL
#define  CATPLMiPMLBase                             AuthorizedModule// CATPLMImplAdapterQL
#define CATPLMIndexCrawlerV6                        AuthorizedModule// BBDV6Crawler
#define  TSTCATPLMxTestFunctions                    AuthorizedModule// CATPLMImplAdapterQL.tst
#define  TSTCATPLMxBuzzTest                         AuthorizedModule// CATPLMImplAdapterQL.tst
#define  TSTCATPLMxAddFilterSelectCriteriaPerfoTest AuthorizedModule// CATPLMImplAdapterQL.tst
#define  CATPLMxReadWriteXMQL                       AuthorizedModule//CATPLMImplAdapterQL


//  Check  authorization  
#if  _MK_MODNAME_  ==  AuthorizedModule  
#else  
    #error  Forbidden  Access  To  CATPLMServicesItfLimitAccess  Services  from  a  non-authorized  module    
    //  Fatal  error  on  solaris  
    @error    
#endif  

// ----------------------------------------------------------------------
// Restore context (don t forget to do that!!!!!!):
// delete macros, de-associate module name  from int value above
// ----------------------------------------------------------------------
#undef CATPLMImplAdapterQLBase
#undef CATPLMServicesLimitAccess
#undef CATPLMImplAdapterQLUUID
#undef CATPLMxQueryDataSet
#undef CATPLMxQueryPLMQL
#undef CATPLMServicesItf
#undef CATPLMServicesProc
#undef CATPLMxProviderImpl
#undef CATPLMxTSTProviderImpl
#undef CATPLMxProcCall
#undef TSTCATPLMxProcedureCallBase
#undef TSTCATPLMxProcedureCallInfra
#undef TstMxCommandFactory1
#undef CATPLMIndexItfImpl
#undef CATAsyncProcess
#undef CATPLMiPMLDataStream
#undef CATPLMiPMLBase
#undef CATPLMIndexCrawlerV6
#undef TSTCATPLMxTestFunctions
#undef TSTCATPLMxBuzzTest
#undef TSTCATPLMxAddFilterSelectCriteriaPerfoTest
#undef CATPLMxReadWriteXMQL

// ----------------------------------------------------------------------
// ExportedBy
// ----------------------------------------------------------------------
#undef  ExportedByCATPLMServicesItf

#if defined __CATPLMServicesItf
#define ExportedByCATPLMServicesItf DSYExport
#else
#define ExportedByCATPLMServicesItf DSYImport
#endif
#include "DSYExport.h"

#endif  
