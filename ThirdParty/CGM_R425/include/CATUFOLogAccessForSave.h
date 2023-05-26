#ifndef CATUFOLogAccessForSave_H
#define CATUFOLogAccessForSave_H
/**
 * @level Protected
 * @usage U1
 */

#include "ExportedByCATPLMIdentification.h"
#include "IUnknown.h"
#include "CATPLMID.h"
#include "CATComponentId.h"
#include "CATUFOUserActionAccessForSave.h"
#include "CATOmxVector.h"
#include "CATOmxIter.h"
#include "CATLISTV_CATComponentId.h"
#include "CATBoolean.h"
#include "CATOmxOSet.h"

class CATUFOOccurrenceEquivalenceGroup;

/**
* UFO log access for reroute.
*/
class ExportedByCATPLMIdentification CATUFOLogAccessForSave
{
protected:
  /*
  * Get UFO user actions from a CATComponentId if any
  *
  * @param iCID
  *   the given CID
  *
  * @param oAction
  *   the corresponding UFO user actions if any
  *
  * @return
  *   S_OK if everything is OK and at least one action was found
  *   S_FALSE if everything is OK and no action was found
  *   E_FAIL otherwise
  */
  static HRESULT GetUFOUserActions(CATComponentId& iCID, CATOmxSet<CATUFOUserActionAccessForSave, sharable_manager>& oUserActions);

  /*
  * Get UFO user actions from log
  *
  * @param oAction
  *   the corresponding UFO user actions if any
  *
  * @return
  *   S_OK if everything is OK and at least one action was found
  *   S_FALSE if everything is OK and no action was found
  *   E_FAIL otherwise
  */
  static HRESULT GetAllUFOUserActionsFromLog(const CATLISTV(CATComponentId)& iListOfObjectsToSave, const CATOmxOSet<CATPLMID>& iExcludedComponents, CATOmxVector<CATUFOUserActionAccessForSave>& oUserActions, CATBoolean& oActivateCCMServer, CATOmxOSet<CATPLMID>& oPLMIDsinLog);

  /*
  * Process the UFO log for save in change log.
  * ***WARNING*** : the order of the output vector is important.
  * Best is not to use CATOmxIter on it.
  *
  * @param iListOfObjectToSave
  *   the list of object to save computed by the save engine.
  *
  * @param oAction
  *   the UFO user actions
  *
  * @return
  *   S_OK if everything is OK and at least one action was found
  *   S_FALSE if everything is OK and no action was found
  *   E_FAIL otherwise
  */
  static HRESULT ProcessUFOLogForSave(const CATLISTV(CATComponentId)& iListOfObjectsToSave, const CATOmxOSet<CATPLMID>& iExcludedComponents, CATOmxVector<CATUFOUserActionAccessForSave>& oUserActions, CATBoolean& oActivateCCMServer);

  /*
  * Get action id if any
  *
  * @param iKey
  *     the plmid
  *
  * @param oActionId
  *     the corresponding action id
  *
  * @return
  *   S_OK if everything is OK and an action id was found
  *   S_FALSE if everything is OK and no action id was found
  *   E_FAIL otherwise
  */
  static HRESULT GetActionId(CATPLMID& iKey, CATPLMID& oActionId);

  /*
  * Warn UFO that the save transaction ended with success or not
  */
  static void EndOfSaveTransaction(const CATBoolean iWithSuccess, CATOmxOSet<CATComponentId>& iListOfObjectsToSave);

  /*
  * Retrieves in the UFO log the Components which are related to the given Component by User Facts.
  *
  * @param iComponent
  *     the plmid of the Component
  *
  * @param oImpactedComponents
  *     the components associated to the given component in the change log.
  *
  * @return
  *   S_OK if everything is OK
  *   E_FAIL otherwise
  */
  static HRESULT GetImpactedComponentForSaveScope(const CATComponentId& iComponent, CATOmxOSet<CATComponentId>& oImpactedComponents);

  friend class CATPLMGenericSaver; // To remove
  friend class CATPLMUFOLogSaver;
  friend class CATPLMSaveEngine;
  friend class CATPLMScopeServices;

  friend class CATUFOStateId;
  friend class CATUFOLogSimpleEntry;
  friend class CATOxiUFOSaveLog;

private:
  CATUFOLogAccessForSave();
  ~CATUFOLogAccessForSave();

  friend class CATUFOLogComplexEntry;
  /** @nodoc **/
  static HRESULT GetIteratorFromIndexes(CATComponentId& iCID, CATOmxIter<CATUFOOccurrenceEquivalenceGroup>& ioIterator);
  static CATBoolean IsPLMIDConsideredAsPersistant(CATPLMID& iPLMID);
  static void AddDeleteModifyAction(CATPLMID& iPLMID, CATOmxVector<CATUFOUserActionAccessForSave>& ioUserActionsVector, const CATPLMID& from = CATPLMID_Null, const CATPLMID& to = CATPLMID_Null, const CATBoolean iForceFromTo = FALSE);
  static void AddCreateModifyAction(CATPLMID& iPLMID, CATOmxVector<CATUFOUserActionAccessForSave>& ioUserActionsVector, const CATPLMID& from = CATPLMID_Null, const CATPLMID& to = CATPLMID_Null, const CATBoolean iForceFromTo = FALSE);
  static void AddUpdateModifyAction(CATPLMID& iPLMID, CATOmxVector<CATUFOUserActionAccessForSave>& ioUserActionsVector, const CATPLMID& from = CATPLMID_Null, const CATPLMID& to = CATPLMID_Null, const CATBoolean iForceFromTo = FALSE);
};

#endif


