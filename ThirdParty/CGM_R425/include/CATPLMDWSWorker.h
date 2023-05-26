/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMDWSWorker_H
#define CATPLMDWSWorker_H

#include "CATPLMIntegrationAccessRestrictedDWSUse.h"
#include "CATPLMID.h"
#include "CATCollec.h"
class CATLISTP(CATBaseUnknown);
class CATLISTP(CATIPLMComponent);
class CATIAdpErrorMonitor;
class CATIAdpContentChecker;

class ExportedByCATPLMIntegrationAccessRestrictedDWSUse CATPLMDWSWorker
{
public:
  CATPLMDWSWorker( const CATPLMID & iWorkspaceID );
  virtual ~CATPLMDWSWorker();

/**
 * @deprecated V6R210
 * @use CATPLMDWSWorker#Save
 */
  HRESULT Save( const CATLISTP(CATBaseUnknown) & iRoots, CATIAdpErrorMonitor * iErrorMonitor );

/**
 * Performs a Propagation on components in the database.
 * <br><b>Role:</b>This method saves all AUTHORING session or all given roots and their prerequisites.
 * The targetted repository of each component has been defined when component has been created.
 * <ul>
 * <li>If the intent of the propagation concerns a Workspace, the Workspace Identifier must be provided to the Worker.</li>
 * <li>If the given @href CATIAdpContentChecker cancels the process because of an identified Component, <code>ERR_01</code> is raised on the Monitor.</li>
 * <li>If the given @href CATIAdpContentChecker cancels the process because of an unidentified Component, <code>ERR_02</code> is raised on the Monitor.</li>
 * </ul>
 *
 * @param iRoots [in]
 * <ul>
 *   <li>The roots which will be used to compute a Save scope for following propagation to the database.</li>
 *   <li>If no Root is given, the previously computed scope will be .</li>
 *   <li>No deleted component can be provided, else an <code>E_INVALIDARG</code> return should be expected.</li>
 * </ul>
 * @param iErrorMonitor [in]
 * <ul>
 *   <li>The Error Monitor dedicated to store and handle all PLM Errors raised during the execution of this operation.</li>
 *   <li>It can be created through the @href CATAdpErrorMonitorFactory#CreateErrorMonitor entry point.</li>
 *   <li>It is mandatory, else an <code>E_INVALIDARG</code> return should be expected.</li>
 * </ul>
 * @param iContentChecker [in]
 * <ul>
 *   <li>The callback provided by the user to be informed about the Components being propagated.</li>
 *   <li>If no callback is provided, the Save operation will be performed without any control.</li>
 * </ul>
 *
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt>: Save successful.</li> 
 *   <li><tt>E_INVALIDARG</tt>: Given iRoots did not contain any component or no Error Monitor is available. Nothing was done.</li> 
 *   <li><tt>E_FAIL</tt>: Save failed. Errors encountered can be read on the @href CATIAdpErrorMonitor.</li>
 *  </ul>
 */
  HRESULT Save( const CATLISTP(CATIPLMComponent) & iRoots, CATIAdpErrorMonitor * iErrorMonitor, CATIAdpContentChecker * iContentChecker=0 );


private:
  CATPLMDWSWorker( const CATPLMDWSWorker & );
  CATPLMDWSWorker & operator =( const CATPLMDWSWorker & );

private:
  CATPLMID _WorkspaceID;
};
#endif
