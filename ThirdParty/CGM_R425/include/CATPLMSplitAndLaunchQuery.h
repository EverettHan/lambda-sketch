// ==================================================================================
// SPLIT IS ONLY MADE IF YOU ARE ON M1, we don't do anything on other providers
// ==================================================================================
// On CATIPLMCompStatement given, we do:
// CHK_SUCCESS_AND_RET(ipStatement->GetQueryFilter(&_spFilter));
// _repoName=ipStatement->GetRepositoryName();
// If repoName is empty, we detected provider connected and if we are on PLM1, we split
// ==================================================================================
// SPLIT IS ONLY MADE ON BASIC QUERY
// ==================================================================================
// with only one type in SELECT condition
// ==================================================================================
// 1-
// CRITERIA
//   |_ ONE FILTER ON ATTRIBUTE type1 attr1 EQ [value1,...,valueN]
// ==================================================================================
// 2-
// CRITERIA
//   |_ CONDITION AND
//          |_ ONE FILTER ON ATTRIBUTE type1 attr1 EQ [value1,...,valueN]
// ==================================================================================
// 3-
// recognized pattern:
// COND OR
//    |_SUBCOND
//    |  |_ Filter On AttributeA EQ Value1
//    |_SUBCOND
//    |  |_ ...
//    |_SUBCOND
//    |  |_ ...
//    |_SUBCOND
//       |_ Filter On AttributeA EQ ValueN
// We split it if we have too many conditions
// ==================================================================================
// -4
// recognized pattern:
// COND OR
//    |_ Filter On AttributeA EQ Value1
//    |_ ...
//    |_ ...
//    |_ Filter On AttributeA EQ ValueN
// We split it if we have too many conditions
// ==================================================================================
// Following pattern:
// Filter On AttributeA EQ Value1
// ...
// ...
// Filter On AttributeA EQ ValueN
// becomes:
// AttributeA IN [Value1,...,ValueN] Job made in CATPLMSplitQueryFilter::_Optimize
// ==================================================================================
// if it is necessary to split two different conditions, we raise an error
// ==================================================================================

#ifndef CATPLMSplitAndLaunchQuery_H
#define CATPLMSplitAndLaunchQuery_H

#if defined (private) || defined(friend) || defined (protected)

  #error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 
#endif


#define AuthorizedModule     999

// List of authorized infrastructure modules 
#define CATPLMServicesItf                     AuthorizedModule
#define TSTCATPLMxSplitBasic                  AuthorizedModule
#define CATPLMTEEmbeddedServices              AuthorizedModule
#define CATPLMTEMappingServices               AuthorizedModule
#define CATPLMTERecordServices                AuthorizedModule
#define TransferData                          AuthorizedModule
#define TransferDataServices                  AuthorizedModule
#define TransitionEngine                      AuthorizedModule
#define CATPLMReplicationEngineCommon         AuthorizedModule
#define CATPLMImplAdapterBase                 AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

      #error Forbidden Access To CATPLMSplitAndLaunchQuery Services from a non-authorized module
        // Fatal error on solaris
        @error 
#endif

#undef AuthorizedModule

// List of authorized infrastructure modules 
#undef CATPLMServicesItf
#undef TSTCATPLMxSplitBasic
#undef CATPLMTEEmbeddedServices
#undef CATPLMTEMappingServices
#undef CATPLMTERecordServices
#undef TransferData
#undef TransferDataServices
#undef TransitionEngine
#undef CATPLMReplicationEngineCommon
#undef CATPLMImplAdapterBase

#ifdef  __CATPLMServicesItf
#define ExportedByCATPLMServices  DSYExport
#else
#define ExportedByCATPLMServices  DSYImport
#endif

#include "DSYExport.h"


#include "CATBoolean.h"
#include "CATSysErrorDef.h"

#include "CATOmxSR.h"
#include "CATOmxList.h"

#include "CATIPLMQueryFilter.h"

#include "CATPLMRepositoryName.h"

class CATIPLMCompRecordReadSet;
class CATIPLMCompStatementService;
class CATIPLMCompStatement;

class ExportedByCATPLMServices CATPLMSplitAndLaunchQuery
{
public:
  CATPLMSplitAndLaunchQuery(CATIPLMCompStatement* ipStatement);

  /*
  * @param opRecordSet [out, CATBaseUnknown#Release]
  */
  HRESULT Query(CATIPLMCompRecordReadSet*& opRecordSet);

private:
  /*
  * ipFilter [in]
  * opRecordSet [out, CATBaseUnknown#Release]
  */
  HRESULT _LaunchQuery(CATIPLMQueryFilter* ipFilter,CATIPLMCompRecordReadSet*& opRecordSet);

  // The copy constructor and the equal operator must not be implemented
  // -------------------------------------------------------------------
  CATPLMSplitAndLaunchQuery (CATPLMSplitAndLaunchQuery &);
  CATPLMSplitAndLaunchQuery& operator=(CATPLMSplitAndLaunchQuery&);

  CATOmxSR<CATIPLMQueryFilter> _spFilter;
  CATOmxSR<CATIPLMCompStatementService> _spStatementService;
  CATPLMRepositoryName _repoName;
};

#endif
