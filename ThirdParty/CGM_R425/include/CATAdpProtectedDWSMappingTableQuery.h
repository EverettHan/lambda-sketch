/**
 * @level Protected
 * @usage U1
 */
#ifndef CATAdpProtectedDWSMappingTableQuery_H
#define CATAdpProtectedDWSMappingTableQuery_H

#undef ExportedByCATPLMIntegrationDWSMTAccessUse
#if defined (private) || defined(friend) || defined (protected)
#error Forbidden re-define of 'private', 'friend' or 'protected'
// Fatal error on solaris
@error 
#endif

#define AuthorizedModule     999
// List of authorized infrastructure modules
#define CATPLMDWSAccess AuthorizedModule
#define CATPLMItgTests AuthorizedModule
#define CATPLMWorkspaceImplCompEngine AuthorizedModule
#define CATPLMWorkspaceImpl AuthorizedModule
#define VPMEBOMAccessServices AuthorizedModule      //EBOM - IR-261251
#define CATPLMMatrixSyncRequestUI  AuthorizedModule //EBOM - IR-261251
#define CATPLMEditabilityImpl AuthorizedModule
#define CATPLMItgTestBase  AuthorizedModule
#define CATPLMModelBuilderTests  AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden Access to CATAdpProtectedDWSMappingTableQuery from a non-authorized module
// Fatal error on solaris
@error 
#endif

#undef CATPLMDWSAccess
#undef CATPLMItgTests
#undef CATPLMWorkspaceImplCompEngine
#undef CATPLMWorkspaceImpl
#undef VPMEBOMAccessServices
#undef CATPLMMatrixSyncRequestUI
#undef CATPLMEditabilityImpl
#undef CATPLMItgTestBase
#undef CATPLMModelBuilderTests

#if defined(__CATPLMIntegrationAccess)
#define ExportedByCATPLMIntegrationDWSMTAccessUse DSYExport
#else
#define ExportedByCATPLMIntegrationDWSMTAccessUse DSYImport
#endif
#include "DSYExport.h"

#include "IUnknown.h"
#include "CATIAdpErrorMonitor.h"

class CATAdpDWSMappingTableQueryDefinition;
class CATIAdpDWSMappingTableQueryCB;

/**
 * Class providing services to access DWS Mapping Table.
 */
class ExportedByCATPLMIntegrationDWSMTAccessUse CATAdpProtectedDWSMappingTableQuery
{
public:

  /**
   * Constructor.
   * @param iErrorMonitor [in]
   *   The Error Monitor dedicated to store and handle all PLM Errors raised during the execution of this operation.
   *   <ul>
   *   <li>It can be created through the @href CATAdpErrorMonitorFactory#CreateErrorMonitor entry point.</li>
   *   <li>It is mandatory, else an <code>E_INVALIDARG</code> return should be expected.</li>
   *   </ul>
   */
  CATAdpProtectedDWSMappingTableQuery(CATIAdpErrorMonitor * iErrorMonitor);
  virtual ~CATAdpProtectedDWSMappingTableQuery();

  /**
   * Process an asynchronous query on a DWS Mapping Table.
   * <br><b>Role</b>: This method queries a DWS Mapping Table.
   * The type of data requested is specified by the <code>iQueryDefinition</code> argument.
   * As soon as data is retrieved, or an error occurs, <code>ioCallback</code> is notified.
   * @param iQueryDefinition [in]
   *   Specified what data to request.
   * @param iCallback [in]
   *   This callback is notified as soon as data is retrieved.
   *   It is also notified if an error occurs.
   * @return
   *   <code>S_OK</code> if everything ran ok, otherwise <code>E_FAIL</code>.
   */
  HRESULT ProcessQuery(CATAdpDWSMappingTableQueryDefinition & iQueryDefinition, CATIAdpDWSMappingTableQueryCB * iCallback);

private:

  CATIAdpErrorMonitor_var _ErrorMonitor;

};

#endif
