/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMComponentCollabBuilder_H
#define CATPLMComponentCollabBuilder_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATPLMGenericEngineBuilder.h"
#include "CATErrorDef.h"
class CATIPLMCollabImporter;
class CATIPLMCollabExporter;
class CATIPLMSpace;
class CATIAdpErrorMonitorAbstract;
class CATIPLMEngineListener;

// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMIntegrationInterfaces       AuthorizedModule
#define CATPLMIntegrationAccess           AuthorizedModule
#define CATPLMItgTests                    AuthorizedModule
#define CATPLMIntegration                 AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
	    #error Forbidden access to CATPLMComponentCollabBuilder from non-infrastructure module
        @error 
#endif
#undef CATPLMIntegrationInterfaces
#undef CATPLMIntegrationAccess
#undef CATPLMItgTests
#undef CATPLMIntegration
// ----------------------------------------------------------------------------------------------------------------------

class ExportedByCATPLMIntegrationInterfaces CATPLMComponentCollabBuilder : public CATPLMGenericEngineBuilder
{
public:
  CATPLMComponentCollabBuilder();
  virtual ~CATPLMComponentCollabBuilder();

/**
 * Get a collaboration exporter.
 *
 * <br><b>Role</b>: Creation of a collaboration exporter.
 *
 * @param oCollabExporter [out, CATBaseUnknown#Release]
 *   The created exporter.
 * @param iSourceResolutionSpace [in]
 *   The memory dataspace the components are represented in. The data defining the content of the components will therefore be introspected from this dataspace.
 * The dataspace can be obtained through the @href CATPLMSpaceServices#GetResolutionSpace entry point. A NULL pointer will result in a E_INVALIDARG result.
 * @param ioErrorMonitor [inout]
 *   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this service.
 * @param iListener [in]
 *   The process listener provided for the versioning process. If NULL, a default listener will be used.
 *
 * @return
 * <dl>
 * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the collaboration exporter to retrieve a pointer on the @href CATIPLMCollabExporter interface.</tt>
 * </dl>
 *
 */
  HRESULT GetCollabExporter( CATIPLMCollabExporter *& oCollabExporter );

/**
 * Get a collaboration importer.
 *
 * <br><b>Role</b>: Creation of a collaboration importer.
 *
 * @param oCollabImporter [out, CATBaseUnknown#Release]
 *   The created importer.
 * @param iTargetResolutionSpace [in]
 *   The memory dataspace the components will unmarshalled into.
 * The dataspace can be obtained through the @href CATPLMSpaceServices#GetResolutionSpace entry point. A NULL pointer will result in a E_INVALIDARG result.
 * @param iErrorMonitor [inout]
 *   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this service.
 * @param iListener [in]
 *   The process listener provided for the versioning process. If NULL, a default listener will be used.
 *
 * @return
 * <dl>
 * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the collaboration marshaller to retrieve a pointer on the @href CATIPLMCollabImporter interface.</tt>
 * </dl>
 *
 */
  HRESULT GetCollabImporter( CATIPLMCollabImporter *& oCollabImporter );
};
#endif
