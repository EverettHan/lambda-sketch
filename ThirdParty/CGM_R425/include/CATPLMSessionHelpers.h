/* -*-c++-*- */
#ifndef CATPLMSessionHelpers_H
#define CATPLMSessionHelpers_H
//
// CATIA Version 6 Release 208
// Copyright   : Dassault Systemes 2009
//-----------------------------------------------------------------------------
// Description :
// C++ class header file for the class named "CATPLMSessionHelpers"
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Inheritance : CATPLMSessionHelpers
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//

#include "CATIAV5Level.h"

/**
* @level Protected
* @usage U1
*/

#include "CATPLMModelBuilder.h"
#include "CATPLMID.h"
#include "CATLISTV_CATPLMID.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATPLMBag.h"
#include "CATPLMQEDef.h"
#include "CATPLMQueryEngineProgress.h"
#include "CATPLMOperationContext.h"
#include "CATPLMQEConstants.h"

class CATIPLMQueryFilter;

/**
*/
class ExportedByCATPLMModelBuilder CATPLMSessionHelpers : public CATBaseUnknown
{
public:

  CATPLMSessionHelpers() = default;
  ~CATPLMSessionHelpers() = default;
  CATPLMSessionHelpers(const CATPLMSessionHelpers&) = delete;
  CATPLMSessionHelpers& operator=(const CATPLMSessionHelpers&) = delete;


  /**
   * ONLY TO BE USED BY Filters AND PVS!!
   * Rebuild a session (PLM objects and occurrences) according to a Persistent Filter or a PVS.
   * PrepareLoad may be called more than one time before executing the entire process operation (by running the Commit method)
   * @param iBag
   *    Bag that will manage lifecycle of constructed PLM objects.
   * @param iFilter
   *    Filter that will be associated to the constructed root occurrence (using CATIPLMSessionFilter API).
   * @param iState
   *    Targeted State used to switch PLM Components in session.
   * @param iOccurrences
   *    Occurrences to rebuild in session (occurrences are identified by using a complex PLMID).
   *    R213 limitation: only root is supported. As a consequence, only simple (or complex PLMID with a size of 1) is supported.
   * @param iWrapDensity
   *    Session will be constructed with a wrap query (positive value, from 1 to 9) or not (nul value).
   * @param iModeExpandAll
   *    Overload the expand strategy by Expand-All.
   * @return
   *    S_OK  : Operation added correctly.
   *    E_FAIL: Otherwise.
   */
#ifdef CATIAR425
  OMX_DEPRECATED("This method is deprecated. Kindly use the equivalent PrepareLoad method.")
    HRESULT PrepareLoad(CATPLMBag& iBag,
      CATIPLMQueryFilter* iFilter,
      CATPLMQEState iState,
      CATLISTV(CATPLMID)& iOccurrences,
      int iWrapDensity = 3,
      int iModeExpandAll = 0);
#else
  HRESULT PrepareLoad(CATPLMBag& iBag,
    CATIPLMQueryFilter* iFilter,
    CATPLMQEState iState,
    CATLISTV(CATPLMID)& iOccurrences,
    int iWrapDensity = 3,
    int iModeExpandAll = 0);
#endif

  /**
   * ONLY TO BE USED BY Filters AND PVS!!
   * Rebuild a session (PLM objects and occurrences) according to a Persistent Filter or a PVS.
   * PrepareLoad may be called more than one time before executing the entire process operation (by running the Commit method)
   * @param iFilter
   *    Filter that will be associated to the constructed root occurrence (using CATIPLMSessionFilter API).
   * @param iState
   *    Targeted State used to switch PLM Components in session.
   * @param iOccurrence
   *    Occurrence to rebuild in session (occurrences are identified by using a complex PLMID).
   * @param iModeExpandAll
   *    Overload the expand strategy by Expand-All.
   * @param iWrapDensity
   *    Session will be constructed with a wrap query (positive value, from 1 to 9) or not (nul value).
   * @return
   *    S_OK  : Operation added correctly.
   *    E_FAIL: Otherwise.
   */
  HRESULT PrepareLoad(CATIPLMQueryFilter* iFilter,
    CATPLMQEConstants::CATPLMLoadingState iState,
    const CATPLMID& iOccurrence,
    CATBoolean iModeExpandAll = FALSE,
    unsigned char iWrapDensity = 3);

  /**
  * Run query operation(s) after multiple call to PrepareLoad/LoadPointed
  * @param iCallback
  *    Callback to be triggered at the end of the query process.
  * @param iError
  *    Error monitor used to register errors during query process.
  * @return
  *    PLMSE_S_SYNC_QUERY_STARTED: Query has been executed synchronously.
  *    S_OK                      : Query has been started asynchronously.
  *    E_FAIL                    : Otherwise.
  */
  HRESULT Commit(CATPLMQueryEngineCB* iCallback, CATIAdpErrorMonitor* iError);

  /**
  * Run query operation(s) after multiple call to PrepareLoad/LoadPointed
  * @param iCallback
  *    Callback to be triggered at the end of the query process.
  * @param iError
  *    Error monitor used to register errors during query process.
  * @param oProgress [out, CATBaseUnknown#Release]
  *    Give access to progression information of the entire process.
  *    @see CATPLMQueryEngineProgress
  * @return
  *    PLMSE_S_SYNC_QUERY_STARTED: Query has been executed synchronously.
  *    S_OK                      : Query has been started asynchronously.
  *    E_FAIL                    : Otherwise.
  */
  HRESULT Commit(CATPLMQueryEngineCB* iCallback, CATIAdpErrorMonitor* iError, CATPLMQueryEngineProgress*& oProgress);

  /**
  * Get the loaded root objects (occurrence or PLM object) if any.
  * Can be called once notified (CATPLMQueryEngineCB::Notify) that the Commit operation is over.
  * @param oRoots
  *    The loaded roots.
  * @return
  *    Return code.
  */
#ifdef CATIAR425
  OMX_DEPRECATED("This method is deprecated. Kindly use the equivalent GetRoots method.")
    HRESULT GetRoots(CATListValCATBaseUnknown_var& oRoots) const;
#else
  HRESULT GetRoots(CATListValCATBaseUnknown_var& oRoots) const;
#endif

  /**
* Get the loaded root objects (occurrence or PLM object) if any.
* Can be called once notified (CATPLMQueryEngineCB::Notify) that the Commit operation is over.
* @param oRoots
*    The loaded roots.
* @return
*    Return code.
*/
  HRESULT GetRoots(CATPLMCBUOrderedSet& oRoots) const;

  /**
  * Get the completion state of a component in session.
  * @param iComponent
  *    The component in session.
  * @param oState
  *    The state of the component.
  * @return
  *    Return code.
  */
#ifdef CATIAR425
  OMX_DEPRECATED("This method is deprecated. Kindly use the equivalent GetCompletionState method.")
    static HRESULT GetCompletionState(CATBaseUnknown* iComponent, CATPLMQEState& oState);
#else
  static HRESULT GetCompletionState(CATBaseUnknown* iComponent, CATPLMQEState& oState);
#endif

  /**
   * Get the completion state of a component in session.
   * @param iComponent
   *    The component in session.
   * @param oState
   *    The state of the component.
   * @return
   *    Return code.
   */
  static HRESULT GetCompletionState(CATBaseUnknown* iComponent, CATPLMQEConstants::CATPLMLoadingState& oState);

private:
  CATPLMOperationKey m_key;
};
#endif
