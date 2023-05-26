#ifndef CATRootOccurrenceMgr_H
#define CATRootOccurrenceMgr_H

#include "CATPLMModelerOccInterfaces.h"
#include "CATOmxSR.h"
#include "CATOmxList.h"

class CATBaseUnknown;

#define	CATRootOccModeUndefined  0 
#define	CATRootOccModeAuthoring  1 
#define	CATRootOccModeNavigation 2 
#define	CATRootOccModeSystem     4 
#define	CATRootOccModeAll (CATRootOccModeAuthoring | CATRootOccModeNavigation | CATRootOccModeSystem) 
typedef unsigned int CATRootOccModeMask;


class ExportedByCATPLMModelerOccInterfaces CATRootOccurrenceMgr
{
public:
  /**
   * retrieve unique root occurrence associated to given reference/filter
   *
   * @param iReference:
   *   a root reference (PLMCoreReference object implementing CATIPLMNavReference interface)
   * @param iFilter:
   *   an occurrence tree filter (object implementing CATIGenericSessionFilterFederator)
   *   passing nullptr means "default filter" (CATIGenericSessionFilter::IsDefault) which here means "no filter"
   * @param iMask:
   *   @see GetRootOccurrenceMode
   * @return:
   *   unique root occurrence (object implementing CATIPLMNavOccurrence) matching input arguments
   */
  static CATOmxSR<CATBaseUnknown> RetrieveRootOccurrence(const CATBaseUnknown* iReference, const CATBaseUnknown* iFilter, CATRootOccModeMask iMask = CATRootOccModeAuthoring);

  /*
   * Notice that you should very rarely use this service (prefer RetrieveRootOccurrence)
   * Unless in very specific situations (somes batches), you should not assume that
   * only one root occurrence is returned or that the "first" returned is the "good" one
   *
   * Lists the root occurrences existing for given root reference, according to the given mode, authoring or navigation.
   */
  HRESULT GetRootOccList(const CATBaseUnknown* iReference, CATRootOccModeMask iMask, CATOmxList<CATBaseUnknown> & oRootOccList);

  /*
  * Creates, in authoring mode, a new Root Occurrence for the given root reference and the given filter,
  * and unfolds the underlying reuse model.
  * Fails if a root occurrence already exist for the given root reference and the given filter
  *
  * Dedicated to migrate calls to CATIOccurrenceServices::GetOrCreateRootOccurrence()
  *
  * @param iReference:
  *   a root reference (PLMCoreReference object implementing CATIPLMNavReference interface)
  * @param iFilter:
  *   an occurrence tree filter (object implementing CATIGenericSessionFilterFederator)
  *   passing nullptr means "default filter" (CATIGenericSessionFilter::IsDefault) which here means "no filter"
  */
  HRESULT CreateAndUnfold(const CATBaseUnknown* iReference, CATOmxSR<CATBaseUnknown> & oRootOcc, const CATBaseUnknown * iFilter = nullptr);

  /**
   * not recommended
   * if usage of LockOccurrenceTree is not systematically paired with this method, the outcome is "destroy immediately even if someone else uses this occurrence tree"
   */
  void ReleaseOccurrenceTree(CATBaseUnknown * iRootOcc);
  void LockOccurrenceTree(CATBaseUnknown * iRootOcc);

  /*
  * Gets the mode of the given root occurrence.
  * @param iRootOcc
  *   a root occurrence
  * @param oMode
  *   CATRootOccModeAuthoring:  "default", what is returned by CreateAndUnfold
  *   CATRootOccModeNavigation: UWP (new navigation experience) light/nav occurrences
  *   CATRootOccModeSystem:     occurrences created by some CATPLMOccurrenceWrapper methods where the CATPLMOccurrenceWrapper is built from something else that an occurrence
  */
  HRESULT GetRootOccurrenceMode(CATBaseUnknown * iRootOcc, CATRootOccModeMask& oMode);

  /**
   * shortcut for CATIOccurrenceServices::Synchronize
   * synchronizes (create/delete occurrences corresponding to created/deleted instances) occurrence trees
   * corresponding to the modeler of the occurrence passed in input
   */
  static void SynchronizeOccurrenceTree(CATBaseUnknown* iRootOcc);

  CATRootOccurrenceMgr() {}
  ~CATRootOccurrenceMgr() {}
  CATRootOccurrenceMgr& operator=(const CATRootOccurrenceMgr&) = delete;
  CATRootOccurrenceMgr(const CATRootOccurrenceMgr&) = delete;
};

#endif
