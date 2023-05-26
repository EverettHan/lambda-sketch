#ifndef CATPLMITGLOCALSAVECOMPONENTS_H_
#define CATPLMITGLOCALSAVECOMPONENTS_H_

#include "CATProxySpace.h"
#include "CATPLMIntegrationBase.h"
#include "CATPLMItgSessionComponentsQuery.h"
#include "CATComponentIdStatus.h"
#include "CATPLMBagType.h"
#include "CATOmxOrderedOSet.h"
#include "CATComponentId.h"
#include "CATComponentIdStatus.h"
#include "CATOmyAsserts.h"
#include "CATOmxList.h"
#include "CATLISTV_CATComponentId.h"
#include "CATLISTV_CATIPLMLogState.h"
class CATComponentIdSet;
class CATComponentIdFilter;

/**
 * This class mades a snapshot of the query to the given workspace with the 'local save' rules.
 *
 * The algorithm for selecting a component is pretty specific :
 *  * we do not want components that are held in session only though an undo-redo bag.
 *  * we want all components that are held in session though a non undo-redo bag.
 *  * we want components that are held by any bag (yes, that's strange).
 *
 * As a snapshot is made, it should not be kept for too long in session.
 * Typically, not longer than a local save transaction.
 */
class ExportedByCATPLMIntegrationBase CATPLMItgLocalSaveComponents : public CATPLMItgSessionComponentsQuery
{
  HRESULT _relevantComponentsAreRetrieved, _diffLogStatesAreRetrieved, _globalLogStatesAreRetrieved;
  CATOmxOrderedOSet<CATComponentId> _relevantComponents;
  CATOmxList<CATIPLMLogState> _diffLogStates, _globalLogStates;

public:
  CATPLMItgLocalSaveComponents(const CATProxySpace & iSpace = CATProxySpace_Null)
  :CATPLMItgSessionComponentsQuery(iSpace)
  {
    Reset();
  }

  void SetProxySpace(const CATProxySpace & iSpace)
  {
    _space = iSpace;
  }

  void Reset()
  {
    _relevantComponentsAreRetrieved = E_NOT_SET;
    _diffLogStatesAreRetrieved = E_NOT_SET;
    _globalLogStatesAreRetrieved = E_NOT_SET;
    _relevantComponents.RemoveAll();
    _diffLogStates.RemoveAll();
    _globalLogStates.RemoveAll();
  }

  int GetNbRelevantComponentsInSession();

  inline int GetNbRelevantComponentsDirty()
  {
    CATOmxList<CATIPLMLogState> globalLogState;
    CHK_SUCCESS_AND_RET_VAL(GetGlobalLogStates(globalLogState), 0);
    return globalLogState.Size();
  }

  /**
   * Retrieve the differential log states of the relevant components.
   * The components that are unchanged in the diff log are filtered out.
   */
  inline HRESULT GetDiffLogStates(CATOmxList<CATIPLMLogState> & oDiffLogStates)
  {
    if(E_NOT_SET == _diffLogStatesAreRetrieved)
    {
      CHK_SUCCESS_AND_RET_HR(_diffLogStatesAreRetrieved = GetLogStates(_diffLogStates, CatTosTodoLevel_Differential));
    }
    oDiffLogStates = _diffLogStates; // on joue sur le COW pour pas que ca coute.
    return _diffLogStatesAreRetrieved;
  }

  /**
   * Retrieve the global log states of the relevant components.
   * The components that are unchanged in the global log are filtered out.
   */
  inline HRESULT GetGlobalLogStates(CATOmxList<CATIPLMLogState> & oGlobalLogStates)
  {
    if(E_NOT_SET == _globalLogStatesAreRetrieved)
    {
      CHK_SUCCESS_AND_RET_HR(_globalLogStatesAreRetrieved = GetLogStates(_globalLogStates, CatTosTodoLevel_Global));
    }
    oGlobalLogStates = _globalLogStates; // on joue sur le COW pour pas que ca coute.
    return _globalLogStatesAreRetrieved;
  }

  /**
   * Utilities
   */
  static HRESULT ExtractComponentFromLogStates(const CATOmxList<CATIPLMLogState> & iStates, CATLISTV(CATComponentId)& oSet);

private :
  HRESULT ComputeRelevantComponents(CATOmxOrderedOSet<CATComponentId>& oSet);
  HRESULT GetComponentsInSpace(CATOmxOrderedOSet<CATComponentId>& oSet, CATBoolean iStartsWithBag, CATPLMBagType iBagType = CATPLMBagType_All);
  HRESULT SearchComponentsInSpace(CATComponentIdSet *& oSet, CATBoolean iStartsWithBag, CATPLMBagType iBagType = CATPLMBagType_All);

  /**
   * Retrieves the components to take into account for a local save transaction.
   */
  HRESULT GetRelevantComponents(CATOmxOrderedOSet<CATComponentId>& oSet)
  {
    if(E_NOT_SET == _relevantComponentsAreRetrieved)
    {
      CHK_SUCCESS_AND_RET_HR(_relevantComponentsAreRetrieved = ComputeRelevantComponents(_relevantComponents));
    }
    oSet = _relevantComponents;
    return _relevantComponentsAreRetrieved;
  }

  inline HRESULT GetLogStates(CATOmxList<CATIPLMLogState> &oLogStates, CATTosTodoLevel iTodoLevel)
  {
    CATOmxOrderedOSet<CATComponentId> set;
    CHK_SUCCESS_AND_RET_HR(GetRelevantComponents(set));
    CHK_SUCCESS_AND_RET_HR(ExtractLogStateFromComponentIds(set, oLogStates, iTodoLevel));
    return S_OK;
  }
  static HRESULT ExtractLogStateFromComponentIds(const CATOmxOrderedOSet<CATComponentId> & iSet, CATOmxList<CATIPLMLogState> &oLogStates, CATTosTodoLevel iTodoLevel);
};


#endif /* CATPLMITGLOCALSAVECOMPONENTS_H_ */
