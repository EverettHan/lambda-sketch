/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
* @level Protected
* @usage U1
*/
#ifndef CATPLMSynchronizationEngineToolbox_H
#define CATPLMSynchronizationEngineToolbox_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATErrorDef.h"

// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMIntegrationInterfaces       AuthorizedModule
#define CATOmbTransientServices           AuthorizedModule
#define CATPLMSynchronizationEngine       AuthorizedModule
#define CATOxiSynchronizationEngine       AuthorizedModule
#define CATOmbDebugLink                   AuthorizedModule
#define CATPLMIdentification_PLM          AuthorizedModule
#define CATOmbSelectiveLoading            AuthorizedModule
#define CATAuthoringRefresh               AuthorizedModule // Replaced by CATAuthoringServices, V6R2021xFD02
#define CATAuthoringServices              AuthorizedModule
#define CATImmVPMNavPCC                   AuthorizedModule
#define PrdOccModelRefresh                AuthorizedModule
#define CATPLMIntegrationAccess           AuthorizedModule
#define PLMRefreshCmd                     AuthorizedModule
#define DELPPRAuthAssignmentPanelImplementLinks AuthorizedModule
#define CATPLMUpdateServices              AuthorizedModule
#define CATExternalIntegration            AuthorizedModule // Refresh capabilities in EKL
#define CATPCCTestLib                     AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATPLMSynchronizationEngineToolbox from non-infrastructure module
@error
#endif
#undef CATPLMIntegrationInterfaces
#undef CATOmbTransientServices
#undef CATPLMSynchronizationEngine
#undef CATOxiSynchronizationEngine
#undef CATOmbDebugLink
#undef CATPLMIdentification_PLM
#undef CATOmbSelectiveLoading
#undef CATAuthoringRefresh
#undef CATAuthoringServices
#undef CATImmVPMNavPCC
#undef PrdOccModelRefresh
#undef CATPLMIntegrationAccess
#undef PLMRefreshCmd
#undef DELPPRAuthAssignmentPanelImplementLinks
#undef CATPLMUpdateServices
#undef CATExternalIntegration
#undef CATPCCTestLib

class CATIPLMFillRequest;
class CATIPLMSynchronizationEngine;
class CATIPLMEngineListener;
class CATIAdpErrorMonitorAbstract;
class CATIPLMSynchronizationRequest;

class ExportedByCATPLMIntegrationInterfaces CATPLMSynchronizationEngineToolbox
{
public:

  /**
  * Gets a synchronization request.
  * @param CATIPLMSynchronizationRequest *& oSynchronizationRequest [out, CATBaseUnknown#Release]
  *   The new Synchronization engine request. Release is to be called on the provided pointer when useless.
  * @param ioErrorMonitor [inout]
  *   The ErrorMonitor that collects all eventual errors happening during synchronization process
  * @return
  *   S_OK if request succeeded.
  *   E_FAIL if request failed.
  */
  static HRESULT GetSynchronizationRequest(CATIPLMSynchronizationRequest *& oSynchronizationRequest, CATIAdpErrorMonitorAbstract * ioErrorMonitor = 0);
};

#endif
