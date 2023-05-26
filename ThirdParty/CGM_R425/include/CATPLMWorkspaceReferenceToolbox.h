/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMWorkspaceReferenceToolbox_H
#define CATPLMWorkspaceReferenceToolbox_H

#include "CATPLMWorkspaceReferenceUsers.h"
#include "CATErrorDef.h"
class CATIPLMWSSynchronizeEngine;
class CATIPLMWSDeliverEngine;
class CATIAdpErrorMonitorAbstract;

/**
 * Class to access to the integration workspace/reference engines.
 *<br><b>Role</b>: Thanks to its static method, you can access to the deliver and synchronize engines.
 */
class ExportedByCATPLMIntegrationInterfaces CATPLMWorkspaceReferenceToolbox
{
public:

/**
 * Get a workspace/reference synchronize engine.
 *
 * <br><b>Role</b>: Creation of a synchronize engine.
 *
 * @param oEngine [out, CATBaseUnknown#Release]
 *   The created synchronize engine.
 * @param ioErrorMonitor [in]
 *   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this transaction.
 *
 * @return
 * <dl>
 * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the engine to retrieve a pointer on the @href CATIPLMWSSynchronizeEngine interface.</tt>
 * </dl>
 *
 */
  static HRESULT GetSynchronizeEngine( CATIPLMWSSynchronizeEngine *& oEngine, CATIAdpErrorMonitorAbstract * iErrorMonitor );

/**
 * Get a workspace/reference deliver engine.
 *
 * <br><b>Role</b>: Creation of a deliver engine.
 *
 * @param oEngine [out, CATBaseUnknown#Release]
 *   The created deliver engine.
 * @param ioErrorMonitor [in]
 *   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this transaction.
 *
 * @return
 * <dl>
 * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the engine to retrieve a pointer on the @href CATIPLMWSDeliverEngine interface.</tt>
 * </dl>
 *
 */
  static HRESULT GetDeliverEngine( CATIPLMWSDeliverEngine *& oEngine, CATIAdpErrorMonitorAbstract * iErrorMonitor );
};
#endif
