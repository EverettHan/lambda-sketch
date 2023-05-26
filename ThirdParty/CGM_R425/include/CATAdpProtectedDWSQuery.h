/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATAdpProtectedDWSQuery_H
#define CATAdpProtectedDWSQuery_H

#include "CATAdpDWSQueryUsers.h"
#include "CATBaseUnknown.h"
#include "CATOmxOMap.h"
#include "CATCollec.h"
class CATAdpDWSQueryAttachmentResult;
class CATAdpDWSQueryWorkspaceIdResult;
class CATLISTP(CATIAdpPLMIdentificator);
class CATIAdpErrorMonitor;
class CATIAdpPLMIdentificator;

template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATIAdpPLMIdentificator *>::manager();

class ExportedByCATPLMIntegrationDWSQueryUse CATAdpProtectedDWSQuery
{
public:
  CATAdpProtectedDWSQuery();
  virtual ~CATAdpProtectedDWSQuery();

/**
 * Determines if Components are associated to a Workspace.
 * <br><b>Role:</b>This method performs a query in the database to determine if the given Components are associated
 * to the given Workspace.
 *
 * @param iWorkspaceId [in]
 * The identifier of the Workspace the given components must be searched in.
 * <ul>
 * <li>If a nul workspace identifier is given, the Components will be searched in the Enterprise Reference.</li>
 * <li>A complex identifier will result in a <code>E_INVALIDARG</code> return.</li>
 * </ul>
 * @param iComponents [in]
 * The components which will be searched in the given Workspace.
 * <ul>
 * <li>An empty set will result in an <code>E_INVALIDARG</code> return.</li>
 * <li>If components are duplicated in this input set, it won't anyway be duplicated in the output set.</li>
 * </ul>
 * @param iErrorMonitor [in]
 * The Error Monitor dedicated to store and handle all PLM Errors raised during the execution of this operation.
 * <ul>
 *   <li>It can be created through the @href CATAdpErrorMonitorFactory#CreateErrorMonitor entry point.</li>
 *   <li>It is mandatory, else an <code>E_INVALIDARG</code> return should be expected.</li>
 *   <li>If a given Component is not found in the database, an error will be posted on this Error Monitor.</li>
 * </ul>
 * @param oResults [in]
 * The results of the operation. Each found component is associated to a <code>TRUE</code>/<code>FALSE</code> status
 * representing its attachement to the given Workspace. A not-empty set will result in an <code>E_INVALIDARG</code> return.
 *
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> if the operation could be performed in the database. Results are then available.</li> 
 *   <li><tt>E_INVALIDARG</tt> if at least one entry was invalid.</li> 
 *   <li><tt>E_FAIL</tt> if the operation failed. Errors encountered can be read on the @href CATIAdpErrorMonitor.</li>
 *  </ul>
 */
  HRESULT IsAttachedToWorkspace( CATIAdpPLMIdentificator * iWorkspaceId,
                                 const CATLISTP(CATIAdpPLMIdentificator) & iComponents,
                                 CATIAdpErrorMonitor * iErrorMonitor, 
                                 CATAdpDWSQueryAttachmentResult & oResults );

/**
 * Retrieves the identifier of the Workspace each given Component is attached to.
 * <br><b>Role:</b>This method performs a query in the database to determine for each given Component the Workspace it is 
 * attached to.
 *
 * @param iComponents [in]
 * The components which will be searched in the given Workspace.
 * <ul>
 * <li>An empty set will result in an <code>E_INVALIDARG</code> return.</li>
 * <li>If components are duplicated in this input set, it won't anyway be duplicated in the output set.</li>
 * </ul>
 * @param iErrorMonitor [in]
 * The Error Monitor dedicated to store and handle all PLM Errors raised during the execution of this operation.
 * <ul>
 *   <li>It can be created through the @href CATAdpErrorMonitorFactory#CreateErrorMonitor entry point.</li>
 *   <li>It is mandatory, else an <code>E_INVALIDARG</code> return should be expected.</li>
 *   <li>If a given Component is not found in the database, an error will be posted on this Error Monitor.</li>
 * </ul>
 * @param oResults [in]
 * The results of the operation. Each found component is associated to a @href CATIAdpPLMIdentificator representing the
 * identifier of the Workspace it is attached to. A not-empty set will result in an <code>E_INVALIDARG</code> return.
 *
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> if the operation could be performed in the database. Results are then available.</li> 
 *   <li><tt>E_INVALIDARG</tt> if at least one entry was invalid.</li> 
 *   <li><tt>E_FAIL</tt> if the operation failed. Errors encountered can be read on the @href CATIAdpErrorMonitor.</li>
 *  </ul>
 */
  HRESULT GetWorkspaceIdValue( const CATLISTP(CATIAdpPLMIdentificator) & iComponents,
                               CATIAdpErrorMonitor * iErrorMonitor, 
                               CATAdpDWSQueryWorkspaceIdResult & oResults );

private:
  CATAdpProtectedDWSQuery( const CATAdpProtectedDWSQuery & );
  CATAdpProtectedDWSQuery & operator =( const CATAdpProtectedDWSQuery & );
};
#endif
