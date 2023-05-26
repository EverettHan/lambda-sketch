/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMComponentManagementBuilder_H
#define CATPLMComponentManagementBuilder_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATPLMGenericEngineBuilder.h"
#include "CATErrorDef.h"
#include "CATIPLMNewVersionEngine.h"
#include "CATIPLMCloningEngine.h"
#include "CATPLMMinorVersioningMode.h"
#include "CATUnicodeString.h"
class CATIPLMVersionGraph;
class CATIPLMMaturityEngine;
class CATIPLMLockEngine;
class CATIPLMCopyEngine;
class CATIPLMEvolutionEngine;
class CATIPLMNewMinorVersionEngine;
class CATIPLMTransferOwnershipEngine;
class CATIPLMOperationPrecheckAnalyzer;

/**
 * Builder enabling to retrieve Component Management engines.
 * <br><b>Role</b>: This builder aims to provide to the user manipulation engines for component management.
 * <ul>
 * <li>Error Monitor can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
 * <li>Engine Listener can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetListener.</li>
 * <li>Workspace Identifier can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetWorkspaceId.</li>
 * </ul>
 */
class ExportedByCATPLMIntegrationInterfaces CATPLMComponentManagementBuilder : public CATPLMGenericEngineBuilder
{
public:
  CATPLMComponentManagementBuilder();
  virtual ~CATPLMComponentManagementBuilder();

  /**
   * Specifies if the BL associated with the lifecycle operation should be applied by the engine.
   * @param iIdCloningString [in]
   *    The IdCloningString to be passed to the BL.
   */
  HRESULT ApplyBusinessLogic(CATBoolean iShouldBeApplied, const CATUnicodeString & iIdCloningString = "");

  /**
   * Valuates an operation precheck analyzer.
   * <br>
   * The operation precheck analyzer is used by the MinorVersioning engine in
   * <code>IntoFamily</code> mode to provide the engine user with the ability to
   * cancel the versioning operation depending on the result of the prechecks on
   * the components to process.
   * @param ipPrecheckAnalyzer [in] The precheck analyzer.
   * @return
   *  <dl>
   *  <dt><code>S_OK</code> if successful</dt>
   *  <dt><code>E_INVALIDARG</code> if a NULL pointer is passed</dt>
   *  <dt><code>E_UNEXPECTED</code> if an operation precheck analyzer was already set</dt>
   *  <dt><code>E_FAIL</code> if any other error occurred</dt>
   *  </dl>
   */
  HRESULT SetOperationPrecheckAnalyzer(CATIPLMOperationPrecheckAnalyzer * ipPrecheckAnalyzer);

  /**
  * Get an Engine for Non Linear Versionning (NLV) ie. Version Graph.
  * <br><b>Role</b>: Creation of a NLV Version Graph Engine.
  * <ul>
  * <li>Error Monitor must be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
  * <li>Engine Listener can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetListener.</li>
  * <li>Workspace Identifier can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetWorkspaceId.</li>
  * </ul>
  *
  * @param oEngine [out, CATBaseUnknown#Release]
  *   The created NLV Engine.
  *
  * @return
  * <dl>
  * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the engine to retrieve a pointer on the @href CATIPLMVersionGraph interface.</tt>
  * </dl>
  *
  */
  HRESULT GetVersionGraph(CATIPLMVersionGraph *& oEngine);

  /**
   * Get a Versioning Engine for majors.
   * <br><b>Role</b>: Creation of a Versioning Engine.
   * <ul>
   * <li>Error Monitor must be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
   * <li>Engine Listener can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetListener.</li>
   * <li>Workspace Identifier can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetWorkspaceId.</li>
   * </ul>
   *
   * @param iVersioningMode [in]
   *   The working mode of the engine.
   * @param oEngine [out, CATBaseUnknown#Release]
   *   The created Versioning Engine.
   *
   * @return
   * <dl>
   * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the engine to retrieve a pointer on the @href CATIPLMNewVersionEngine interface.</tt>
   * </dl>
   *
   */
  HRESULT GetVersioningEngine(CATIPLMNewVersionEngine::VersioningMode iVersioningMode, CATIPLMNewVersionEngine *& oEngine);


  /**
   * Get a Versioning Engine for minors.
   * <br><b>Role</b>: Creation of a Versioning Engine for minors.
   * <ul>
   * <li>Error Monitor must be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
   * <li>Engine Listener can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetListener.</li>
   * <li>Workspace Identifier can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetWorkspaceId.</li>
   * <li>Operation Precheck Analyzer (used for <code>IntoFamily</code> mode) can be provided to the builder thanks to @href #SetOperationPrecheckAnalyzer.</li>
   * </ul>
   *
   * @param iVersioningMode [in]
   *   The working mode of the engine.
   * @param oEngine [out, CATBaseUnknown#Release]
   *   The created Versioning Engine.
   *
   * @return
   * <dl>
   * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the engine to retrieve a pointer on the @href CATIPLMNewVersionEngine interface.</tt>
   * </dl>
   *
   */
  HRESULT GetMinorVersioningEngine(CATPLMMinorVersioningMode::MinorVersioningMode iVersioningMode, CATIPLMNewMinorVersionEngine *& oEngine);

  /**
   * Get a Cloning Engine.
   * <br><b>Role</b>: Creation of a Cloning Engine.
   * <ul>
   * <li>Error Monitor must be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
   * <li>Engine Listener can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetListener.</li>
   * </ul>
   *
   * @param iCloningMode [in]
   *   The working mode of the engine.
   * @param oEngine [out, CATBaseUnknown#Release]
   *   A pointer on the Cloning Engine.
   *
   * @return
   * <dl>
   * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the cloning engine to retrieve a pointer on the @href CATIPLMCloningEngine interface.</tt>
   * </dl>
   *
   */
  HRESULT GetCloningEngine(CATPLMCloningMode::CloningMode iCloningMode, CATIPLMCloningEngine *& oEngine);

  /**
   * Get a Copy Engine.
   * <br><b>Role</b>: Creation of a Copy Engine.
   * <ul>
   * <li>Error Monitor must be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
   * <li>Engine Listener can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetListener.</li>
   * </ul>
   *
   * @param iCloningMode [in]
   *   The working mode of the engine.
   * @param oEngine [out, CATBaseUnknown#Release]
   *   A pointer on the Copy Engine.
   *
   * @return
   * <dl>
   * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the copy engine to retrieve a pointer on the @href CATIPLMCopyEngine interface.</tt>
   * </dl>
   *
   */
  HRESULT GetCopyEngine(CATPLMCloningMode::CloningMode iCloningMode, CATIPLMCopyEngine *& oEngine);

  /**
   * Get an evolution engine.
   *
   * <br><b>Role</b>: Creation of an evolution engine.
   *
   * @param oEngine [out, CATBaseUnknown#Release]
   *   A pointer on the cloning engine. Release the pointer when useless.
   * @return
   * <dl>
   * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the evolution engine to retrieve a pointer on the @href CATIPLMEvolutionEngine interface.</tt>
   * </dl>
   *
   */
  HRESULT GetEvolutionEngine(CATIPLMEvolutionEngine *& oEngine);

  /**
   * Get a Maturity Engine.
   * <br><b>Role</b>: Creation of a Maturity Engine.
   * <ul>
   * <li>Error Monitor must be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
   * <li>Engine Listener can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetListener.</li>
   * </ul>
   *
   * @param oEngine [out, CATBaseUnknown#Release]
   *   A pointer on the maturity engine.
   *
   * @return
   * <dl>
   * <dt><tt> The result of @href CATBaseUnknown#QueryInterface on the maturity engine to retrieve a pointer on the @href CATIPLMMaturityEngine interface.</tt>
   * </dl>
   *
   */
  HRESULT GetMaturityEngine(CATIPLMMaturityEngine *& oEngine);

  /**
   * Get a Lock/Unlock Engine.
   * <br><b>Role</b>: Creation of a Lock Engine.
   * <ul>
   * <li>Error Monitor must be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
   * <li>Engine Listener can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetListener.</li>
   * </ul>
   *
   * @param oEngine [out, CATBaseUnknown#Release]
   *    A pointer on the Lock Engine.
   *
   * @return
   * <dl>
   * <dt><tt>The result of @href CATBaseUnknown#QueryInterface on the maturity engine to retrieve a pointer on the @href CATIPLMLockEngine interface.</tt>
   * </dl>
   */
  HRESULT GetLockEngine(CATIPLMLockEngine *& oEngine);

/**
 * Get a Transfer Ownership Engine.
 * <br><b>Role</b>: Creation of a Transfer Ownership Engine.
 * <ul>
 * <li>Error Monitor must be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
 * </ul>
 *
 * @param oEngine [out, CATBaseUnknown#Release]
 *   A pointer on the Transfer Ownership engine.
 *
 * @return
 * <dl>
 * <dt><tt> The result of @href CATBaseUnknown#QueryInterface on the Transfer Ownership engine to retrieve a pointer on the @href CATIPLMTransferOwnershipEngine interface.</tt>
 * </dl>
 *
 */
  HRESULT GetTransferOwnershipEngine(CATIPLMTransferOwnershipEngine *& oEngine);

};
#endif
