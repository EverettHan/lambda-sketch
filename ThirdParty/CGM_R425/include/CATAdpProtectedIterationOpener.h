/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2013

/**
 * @level Protected
 * @usage U1
 */

#ifndef CATAdpProtectedIterationOpener_H
#define CATAdpProtectedIterationOpener_H

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"
class CATAdpProtectedIterationOpenerImpl;
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
#define CATPLMItgTests                    AuthorizedModule
#define CATPLMIntegrationAccess           AuthorizedModule
#define CATImmRestoreIteration            AuthorizedModule
#define CATPLMGraphicServices             AuthorizedModule // SWKS
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATAdpProtectedIterationOpener from non-infrastructure module
@error
#endif
#undef CATPLMGraphicServices 
#undef CATImmRestoreIteration
#undef CATPLMIntegrationAccess
#undef CATPLMItgTests

/**
 * Class to manage open of Iterations of Representations.
 * <br><b>Role</b>: <p>Provides all basic functions to open Iterations of Representations in Session.</p>
 *
 * <p>Use is pretty the same as of @href CATAdpProtectedOpener. Only differences are Completion of data functions which are not available for Iterations.</p>
 *
 * Example of usage :
 * <pre>
 * CATUuid errorMonitorId;
 * CATIAdpErrorMonitor* pErrorMonitor=0;
 * CATAdpErrorMonitorFactory::CreateErrorMonitor(errorMonitorId, pErrorMonitor);
 *
 * CATAdpProtectedIterationOpener opener(pErrorMonitor);
 * opener.AddElements(iListOfPLMID);
 * CATOmbLoadingModeRuleSet ruleset; // optional
 * ruleset.ApplyPredefinedRules(<my_predefined_mode>);
 * CATOmbLifeCycleRootsBag LocalBag;
 * CATPLMComponentData Components;
 * opener.Open(Components, LocalBag, &ruleset);
 * [...]
 * LocalBag.RemoveAll();
 * CATSysReleasePtr(pErrorMonitor);
 * </pre>
 *
 * You can also get an error monitor after opening :
 *
 * <pre>
 * CATAdpProtectedIterationOpener opener;
 * opener.AddElements(iListOfPLMID);
 * CATPLMComponentData Components;
 * CATOmbLifeCycleRootsBag LocalBag;
 * opener.Open(Components, LocalBag);
 * [...]
 * CATIAdpErrorMonitor * pErrorMonitor = 0;
 * opener.GetErrorMonitor(pErrorMonitor);
 * [...]
 * LocalBag.RemoveAll();
 * CATSysReleasePtr(pErrorMonitor);
 * </pre>
 */
  class ExportedByCATPLMIntegrationAccess CATAdpProtectedIterationOpener
{

public:
  virtual ~CATAdpProtectedIterationOpener();

  /**
   * Class constructor
   * <b>Role</b>: Create a new Iterations opener.
   *
   * @param iErrorMonitor [in]
   * Error monitor to populate with errors, can be created using @href CATAdpErrorMonitorFactory. You can also use @see CATAdpProtectedOpener#GetErrorMonitor to get it afterwards.
   */
  CATAdpProtectedIterationOpener(CATIAdpErrorMonitor * iErrorMonitor = 0);

  /**
   * Add elements to be treated by the opener.
   * <b>Role</b>: enables the user to give elements for Open process.
   *
   * @param iRepIterations [in]
   * List of Components to process.
   *
   * @return
   * <dl>
   * <dt><code>S_OK</code> Operation succeeded<dd>
   * <dt><code>E_INVALIDARG</code> Bad argument, a element in the list is not of type Representation Reference <dd>
   * <dt><code>E_FAIL</code> Failure, no element added<dd>
   * <dt><code>E_UNEXPECTED</code> Bad argument, no element added<dd>
   * </dl>
   */
  HRESULT AddElements(const CATLISTP(CATIAdpPLMIdentificator) & iRepIterations);
  HRESULT AddElements(const CATLISTV(CATPLMID) & iRepIterations);
  HRESULT AddElements(const CATPLMIDSet & iRepIterations);

  /**
   * Add element to be treated by the opener.
   * <br><b>Role</b>: enables the user to give element for Open process.
   *
   * @param iRepIteration [in]
   * Component to process.
   *
   * @return
   * <dl>
   * <dt><code>S_OK</code> Operation succeeded<dd>
   * <dt><code>E_INVALIDARG</code> <dd> Bad argument, element is not of type Representation Reference<dd>
   * <dt><code>E_FAIL</code> Failure, no element added<dd>
   * <dt><code>E_UNEXPECTED</code> Bad argument, no element added<dd>
   * </dl>
   */
  HRESULT AddElement(CATIAdpPLMIdentificator * iRepIteration);
  HRESULT AddElement(const CATPLMID & iRepIteration);

  /**
   * Start the Open process.
   * <br><b>Role</b>: enables the user to trigger the open operation.
   * <ul>
   * <li>The Components will be opened.</li>
   * <li>If CATOmbLoadingModeRuleSet is null, Component fitting with Selective Loading behavior will be opened in predefined mode.</li>
   * </ul>
   *
   * @param oOpenedComponents [out]
   * Opened Components.
   * @param ioBag
   * Lifecyclebag. When the bag is released, components can be unloaded from session if not held by another bag.
   * You need to keep the bag until you won't need opened components anymore.
   * @param iLoadingRules [in]
   * The loading rules which will be applied to Components which fit with Selective Loading behavior.
   *
   * @return
   * <dl>
   * <dt><code>S_OK</code> No issue, operation succeeded</dd>
   * <dt><code>S_FALSE</code> The data were opened, but some warnings were detected.</dd>
   * <dt><code>E_FAIL</code> Failure. Errors can be read through given @CATIAdpErrorMonitor</dd>
   * </dl>
   */
  HRESULT Open(CATPLMComponentData  & oOpenedComponents,
    CATOmbLifeCycleRootsBag & ioBag,
    CATOmbLoadingModeRuleSet * iLoadingRules = 0);

  /**
   * Get the error monitor.
   * <br><b>Role</b>: enables the user to retrieve the Error Monitor associated to the Open transaction.
   *
   * @param oErrorMonitor [out, CATBaseUnknown#Release]
   * Error monitor giving access to errors.</li>
   *
   * @return
   * <dl>
   * <dt><code>S_OK</code> Operation succeeded </dd>
   * <dt><code>E_FAIL</code> Failure</dd>
   * </dl>
   */
  HRESULT GetErrorMonitor(CATIAdpErrorMonitor *& oErrorMonitor);

private:
  CATAdpProtectedIterationOpener(const CATAdpProtectedIterationOpener &);
  CATAdpProtectedIterationOpener & operator=(const CATAdpProtectedIterationOpener &);

private:
  CATAdpProtectedIterationOpenerImpl& _impl;
};
#endif
