/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMContentRefreshToolbox_H
#define CATPLMContentRefreshToolbox_H

#include "CATPLMContentRefreshUsers.h"
#include "CATErrorDef.h"
class CATIPLMContentRefresher;
class CATIAdpErrorMonitorAbstract;

/**
 * Class to access to the integration workspace/reference engines.
 *<br><b>Role</b>: Thanks to its static method, you can access to the deliver and synchronize engines.
 */
class ExportedByCATPLMIntegrationInterfaces CATPLMContentRefreshToolbox
{
public:

/**
 * Get a content refresher.
 *
 * <br><b>Role</b>: Creation of a content refresher.
 *
 * @param oRefresher [out, CATBaseUnknown#Release]
 *   The created refresher.
 * @param ioErrorMonitor [in]
 *   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this transaction.
 *
 * @return
 * <dl>
 * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the engine to retrieve a pointer on the @href CATIPLMContentRefresher interface.</tt>
 * </dl>
 *
 */
  static HRESULT GetContentRefresher( CATIPLMContentRefresher *& oRefresher, CATIAdpErrorMonitorAbstract * iErrorMonitor );
};
#endif
