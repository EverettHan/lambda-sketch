/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2013

/**
 * @level Protected
 * @usage U1
 */

#ifndef CATAdpProtectedSidewayOpener_H
#define CATAdpProtectedSidewayOpener_H

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"
#include "CATIAdpProtectedCompletionParameters.h"
#include "CATAdpProtectedOpener.h"
class CATAdpProtectedOpenerImpl;
class CATIAdpPLMIdentificator;
class CATPLMID;
class CATPLMIDSet;
class CATIAdpErrorMonitor;
class CATOmbLoadingModeRuleSet;
class CATPLMComponentData;
class CATLISTP(CATIAdpPLMIdentificator);
class CATLISTV(CATPLMID);
class CATOmbLifeCycleRootsBag;

#define AuthorizedModule                  999
#define CATPLMIntegrationAccess           AuthorizedModule
#define CATPLMItgTestIntegrationAccess    AuthorizedModule
#define CATPLMItgTests                    AuthorizedModule
#define CATPLMIdentification_PLM          AuthorizedModule
#define CATPLMOpenUI                      AuthorizedModule
#define PLMDesignWorkspaceCompareImages   AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATAdpProtectedSidewayOpener from not authorized module
@error
#endif
#undef CATPLMIntegrationAccess
#undef CATPLMItgTestIntegrationAccess
#undef CATPLMItgTests
#undef CATPLMIdentification_PLM
#undef CATPLMOpenUI
#undef PLMDesignWorkspaceCompareImages

/**
 * Class to manage open of Components in a sideway Session.
 * <br><b>Role</b>: <p>Provides all basic functions to open Components in Session.</p>
 *
 * <p>Use is pretty the same as of @href CATAdpProtectedOpener. Only differences are linked to lifecycle management of the Components.</p>
 *
 * <p>Data completion algorithms can be set by @href CATAdpProtectedCompletionParametersFactory. For fine tuning, you can also get the parameters to modify.</p>
 * <pre>
 * CATIAdpProtectedCompletionParameters_var spParams = CATAdpProtectedCompletionParametersFactory::<wanted mode>;
 * CATAdpProtectedOpener opener(spParams,pErrorMonitor);
 * </pre>
 *
 * Example of usage :
 * <pre>
 * CATUuid errorMonitorId;
 * CATIAdpErrorMonitor* pErrorMonitor = 0;
 * CATAdpErrorMonitorFactory::CreateErrorMonitor(errorMonitorId, pErrorMonitor);
 *
 * CATIAdpProtectedCompletionParameters_var spParams=CATAdpProtectedCompletionParametersFactory::<wanted mode>();
 * spParams->AddMinorOverload(<my_set_of_overloads>); // If you need to overload some minor Components.
 *
 * CATAdpProtectedSidewayOpener opener(spParams, pErrorMonitor);
 * opener.AddElements(iListOfPLMID);
 * CATOmbLoadingModeRuleSet ruleset; // optional
 * ruleset.ApplyPredefinedRules(<my_predefined_mode>);
 * CATOmbLifeCycleRootsBag LocalBag;
 * CATPLMComponentData Components;
 * opener.CompleteAndOpen(Components, LocalBag, &ruleset);
 * [...]
 * LocalBag.RemoveAll();
 * CATSysReleasePtr(pErrorMonitor);
 * </pre>
 *
 * You can also get an error monitor after opening :
 *
 * <pre>
 * CATIAdpProtectedCompletionParameters_var spParams=CATAdpProtectedCompletionParametersFactory::<wanted mode>;
 * CATAdpProtectedSidewayOpener opener(spParams);
 * opener.AddElements(iListOfPLMID);
 * CATPLMComponentData Components;
 * CATOmbLifeCycleRootsBag LocalBag;
 * opener.CompleteAndOpen(Components, LocalBag);
 * [...]
 * CATIAdpErrorMonitor * pErrorMonitor = 0;
 * opener.GetErrorMonitor(pErrorMonitor);
 * [...]
 * LocalBag.RemoveAll();
 * CATSysReleasePtr(pErrorMonitor);
 * </pre>
 */
  class CATAdpProtectedSidewayOpener : public CATAdpProtectedOpener
{
public:
  /**
   * Class constructor
   * <b>Role</b>: Create a new sideway opener.
   *
   * @param iCompletionParameters [in]
   * Completion parameters. @see CATAdpProtectedCompletionParametersFactory or @see CATIAdpProtectedCompletionParameters for fine tuning.
   *
   * @param iErrorMonitor [in]
   * Error monitor to populate with errors, can be created using @href CATAdpErrorMonitorFactory. You can also use @see CATAdpProtectedOpener#GetErrorMonitor to get it afterwards.
   */
  ExportedByCATPLMIntegrationAccess CATAdpProtectedSidewayOpener(CATIAdpProtectedCompletionParameters_var   iCompletionParameters, CATIAdpErrorMonitor* iErrorMonitor = NULL);
};

//-----------------------------------------------------------------------

#endif
