/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMWorkspaceReferenceBuilder_H
#define CATPLMWorkspaceReferenceBuilder_H

#include "CATPLMWorkspaceReferenceUsers.h"
#include "CATPLMGenericEngineBuilder.h"
#include "CATErrorDef.h"
class CATIPLMWSSynchronizeEngine;
class CATIPLMWSDeliverEngine;
class CATIPLMWSReservationEngine;

/**
 * Builder enabling to retrieve Workspace/Reference engines.
 * <br><b>Role</b>: This builder aims to provide to the user manipulation engines for Workspace/Reference functionality.
 * <ul>
 * <li>Error Monitor can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
 * <li>Workspace Identifier can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetWorkspaceId.</li>
 * </ul>
 */
class ExportedByCATPLMIntegrationInterfaces CATPLMWorkspaceReferenceBuilder : public CATPLMGenericEngineBuilder
{
public:
  CATPLMWorkspaceReferenceBuilder();
  virtual ~CATPLMWorkspaceReferenceBuilder();

/**
 * Get a workspace/reference synchronize engine.
 * <br><b>Role</b>: Creation of a synchronize engine.
 * <ul>
 * <li>Error Monitor must be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
 * <li>Workspace Identifier can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetWorkspaceId.</li>
 * </ul>
 *
 * @param oEngine [out, CATBaseUnknown#Release]
 *   The created synchronize engine.
 *
 * @return
 * <dl>
 * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the engine to retrieve a pointer on the @href CATIPLMWSSynchronizeEngine interface.</tt>
 * </dl>
 *
 */
  HRESULT GetSynchronizeEngine( CATIPLMWSSynchronizeEngine *& oEngine );

/**
 * Get a workspace/reference deliver engine.
 * <br><b>Role</b>: Creation of a deliver engine.
 * <ul>
 * <li>Error Monitor must be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
 * <li>Workspace Identifier can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetWorkspaceId.</li>
 * </ul>
 *
 * @param oEngine [out, CATBaseUnknown#Release]
 *   The created deliver engine.
 *
 * @return
 * <dl>
 * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the engine to retrieve a pointer on the @href CATIPLMWSDeliverEngine interface.</tt>
 * </dl>
 *
 */
  HRESULT GetDeliverEngine( CATIPLMWSDeliverEngine *& oEngine );

/**
 * Get a workspace reservation engine.
 * <br><b>Role</b>: Creation of a reservation engine.
 * <ul>
 * <li>Error Monitor CAN be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
 * <li>Workspace Identifier MUST be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetWorkspaceId.</li>
 * </ul>
 *
 * @param opEngine [out, CATBaseUnknown#Release]
 *   The created deliver engine.
 *
 * @return
 * <dl>
 * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the engine to retrieve a pointer on the @href CATIPLMWSReservationEngine interface.</tt>
 * </dl>
 */
  HRESULT GetReservationEngine( CATIPLMWSReservationEngine *& opEngine );
};
#endif
