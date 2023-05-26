/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMSessionManagementBuilder_H
#define CATPLMSessionManagementBuilder_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATPLMGenericEngineBuilder.h"
#include "CATErrorDef.h"
class CATIPLMSaveEngine;
class CATIPLMSaveScope;
class CATIPLMOpenEngine;
class CATIPLMCompleteGraph;
class CATIPLMFillEngine;
class CATIPLMLocalSaveEngine;
class CATIPLMOfflineContentOpenEngine;

/**
 * Builder enabling to retrieve Session Management engines.
 * <br><b>Role</b>: This builder aims to provide to the user manipulation engines for session management.
 * <ul>
 * <li>Error Monitor can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
 * <li>Engine Listener can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetListener.</li>
 * <li>Workspace Identifier can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetWorkspaceId.</li>
 * </ul>
 */
class ExportedByCATPLMIntegrationInterfaces CATPLMSessionManagementBuilder : public CATPLMGenericEngineBuilder
{
public:
  CATPLMSessionManagementBuilder();
  virtual ~CATPLMSessionManagementBuilder();

/**
 * Get a Save Scope.
 * <br><b>Role</b>: Creation of a Save Scope.
 *
 * @param oSaveScope [out, CATBaseUnknown#Release]
 *   The created Save Scope.
 *
 * @return
 * <dl>
 * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the engine to retrieve a pointer on the @href CATIPLMSaveScope interface.</tt>
 * </dl>
 *
 */
  HRESULT GetSaveScope(CATIPLMSaveScope *& oSaveScope);

/**
 * Get a Save Engine.
 * <br><b>Role</b>: Creation of a Save Engine.
 * <ul>
 * <li>Error Monitor can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
 * <li>Engine Listener must be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetProcessListener.</li>
 * <li>Workspace Identifier can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetWorkspaceId.</li>
 * </ul>
 *
 * @param oSaveEngine [out, CATBaseUnknown#Release]
 *   The created Save Engine.
 *
 * @return
 * <dl>
 * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the engine to retrieve a pointer on the @href CATIPLMSaveEngine interface.</tt>
 * </dl>
 *
 */
  HRESULT GetSaveEngine(CATIPLMSaveEngine *& oSaveEngine);

/**
 * Gets an Open Engine.
 * <br><b>Role</b>: Creation of an Open Engine.
 * <ul>
 * <li>Error Monitor can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
 * <li>Engine Listener must be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetProcessListener.</li>
 * </ul>
 *
 * @param oOpenEngine [out, CATBaseUnknown#Release]
 *   The created Open Engine.
 *
 * @return
 * <dl>
 * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the engine to retrieve a pointer on the @href CATIPLMOpenEngine interface.</tt>
 * </dl>
 */
  HRESULT GetOpenEngine(CATIPLMOpenEngine *& oOpenEngine);

/**
 * Get a Complete Graph.
 * <br><b>Role</b>: Creation of a Completion Graph Manager.
 * <ul>
 * <li>Error Monitor can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
 * <li>Engine Listener must be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetProcessListener.</li>
 * </ul>
 *
 * @param oCompleteGraph [out, CATBaseUnknown#Release]
 *   The created Complete Graph.
 *
 * @return
 * <dl>
 * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the complete graph to retrieve a pointer on the @href CATIPLMCompleteGraph interface.</tt>
 * </dl>
 */
  HRESULT GetCompleteGraph(CATIPLMCompleteGraph *& oCompleteGraph);

/**
 * Get a Fill Engine.
 * <br><b>Role</b>: Creation of a Fill Engine.
 * <ul>
 * <li>Error Monitor can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
 * <li>Engine Listener must be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetProcessListener.</li>
 * </ul>
 *
 * @param oEngine [out, CATBaseUnknown#Release]
 *   A pointer on the Fill Engine.
 *
 * @return
 * <dl>
 * <dt><tt> The result of @href CATBaseUnknown#QueryInterface on the fill engine to retrieve a pointer on the @href CATIPLMFillEngine interface.</tt>
 * </dl>
 *
 */
  HRESULT GetFillEngine(CATIPLMFillEngine *& oEngine);

/**
 * Get a Local Save Engine.
 * <br><b>Role</b>: Creation of a Local Save Engine.
 * <ul>
 * <li>Error Monitor can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
 * <li>Engine Listener must be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetProcessListener.</li>
 * </ul>
 *
 * @param oEngine [out, CATBaseUnknown#Release]
 *   The created Local Save Engine.
 *
 * @return
 * <dl>
 * <dt><tt> The result of @href CATBaseUnknown#QueryInterface on the fill engine to retrieve a pointer on the @href CATIPLMLocalSaveEngine interface.</tt>
 * </dl>
 */
  HRESULT GetLocalSaveEngine(CATIPLMLocalSaveEngine *& oEngine);



 /**
 * Get an Offline Content open engine
 * <br><b>Role</b>: To open offline content
 * <ul>
 * <li>Error Monitor can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
 * <li>Engine Listener must be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetProcessListener.</li>
 * </ul>
 * @param oEngine [out, CATBaseUnknown#Release]
 *   The created Offline Content Engine.
 * @return
 * <dl>
 * <dt><tt> The result of @href CATBaseUnknown#QueryInterface on the fill engine to retrieve a pointer on the @href CATIPLMLocalSaveEngine interface.</tt>
 * </dl>
 */
  HRESULT GetOfflineContentOpenEngine(CATIPLMOfflineContentOpenEngine *& oEngine);

};
#endif
