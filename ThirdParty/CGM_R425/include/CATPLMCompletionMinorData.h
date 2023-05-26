#ifndef CATPLMCOMPLETIONMINORDATA_H_
#define CATPLMCOMPLETIONMINORDATA_H_

/**
 * @level Protected
 * @usage U1
 */

#include "CATPLMIntegrationAccess.h"
#include "CATPLMCompletionDataOnTos.h"
#include "CATPLMID.h"
#include "CATPLMIDMinorCollectManager.h"
#include "CATOmxOMap.h"
class CATIPLMRecordRead;

/**
 * Specific wrapper around CATPLMCompletionData internal data in order to add minor
 * sensitive information. Modifing the content of this collection will modify the
 * content of the original CATPLMCompletionDataOnTos.
 * In this structure each path is duplicated (only the internal pointer) for each of its nodes.
 */
class ExportedByCATPLMIntegrationAccess CATPLMCompletionMinorData : public CATPLMCompletionDataOnTos
{
  CATOmxOHMap<CATPLMID, CATPLMCompletionDataOnTos, CATPLMIDMinorCollectManager::manager> _minorFamilies;
  CATOmxOHMap<CATPLMID, CATOmxOSet<CATPLMID>, CATPLMIDMinorCollectManager::manager> _minorsInPaths;

public:
  CATPLMCompletionMinorData();
  CATPLMCompletionMinorData(const CATPLMCompletionDataOnTos & iData);
  CATPLMCompletionMinorData(const CATPLMCompletionMinorData & iData);
  ~CATPLMCompletionMinorData();

  /**
   * Replace the current datums with the given one(s). The comparaison is done on the plmid minor insensitively.
   * If no curresponding plmid is found for a given datum, this datum is them inserted.
   * This is useful for replacing minors by other minors
   */
  void ReplaceOrInsert(const CATPLMCompletionDataOnTos   & iData, CATPLMCompletionDataCplxMode::Mode iCplxMode = CATPLMCompletionDataCplxMode::NoModif);
  void ReplaceOrInsert(const CATPLMID               & iPid, CATPLMCompletionDataCplxMode::Mode iCplxMode = CATPLMCompletionDataCplxMode::NoModif);

  /**
   * Replaces the other minors from the same family by this one in every occurrences.
   * The replacement is performed for:
   * - Minors added as simple elements.
   * - Minors that are the last element of a path.
   * @param iPid [in] The replacement minor (simple element)
   * @return S_OK if success, E_INVALIDARG if the PLMID is complex or not valid,
   *  or E_UNEXPECTED for any other error.
   */
  HRESULT ReplaceMinors(const CATPLMID & iPid);

  /**
   * Retrieves the family of minor equilvalent components in the collection.
   * @returns
   *   * S_OK if some minor equivalent components are found,
   *   * E_FAIL in any other case
   */
  HRESULT LocateMinors(const CATPLMID  & iId, CATPLMCompletionDataOnTos  & oData) const;

  /**
   * Tells if there is at least one minor equilvalent component in the collection.
   * @returns
   *   * S_OK if some minor equivalent components are found,
   *   * E_FAIL in any other case
   */
  HRESULT LocateMinors(const CATPLMID  & iId) const;

  /**
   * Retrieves a unique equivalent minor to the input id.
   * @returns
   *  * S_OK if an unique minor of the family of input id is found,
   *  * S_FALSE if no element of the same minor family is found,
   *  * E_FAIL in other cases (like in case of multiple elements found, as it's not expected)
   */
  HRESULT LocateMinor(const CATPLMID  & iId, CATPLMID  & oEquivalentMinor) const;

  /**
  * Tells if there is a unique equivalent minor to the input id.
  * @returns
  *  * S_OK if an unique minor of the family of input id is there,
  *  * S_FALSE if no element of the same minor family is there,
  *  * E_FAIL in other cases (like in case of multiple equivalent elements in the collection, as it's not expected)
  */
  HRESULT LocateMinor(const CATPLMID  & iId) const;

private:
  virtual void RawUpdateOrInsert(const CATPLMID            &iPid, CATIPLMQueryFilter *iAssociatedFilter = NULL);
  virtual void RawUpdateOrInsert(CATIPLMRecordRead   *iRecordRead,
    const CATBoolean &iSynchronizeRelations = TRUE,
    const CATBoolean &iSynchronizeAttributes = TRUE,
    CATIPLMQueryFilter *iAssociatedFilter = NULL);
  virtual HRESULT RawRemove(const CATPLMID  & iPLMID);
  virtual HRESULT RawRemoveAll();

  void UpdateOrInsertInItsFamily(const CATPLMID  & iPid, CATIPLMQueryFilter *iAssociatedFilter = NULL);

  /**
   * Replaces all the minors by this one in all the paths.
   * This will remove, rebuild, and then readd all the paths.
   * The passed PLMID must be simple (no complexity check performed).
   * The replacement of minors in paths is supported only for the last element.
   * @param iMinorToUse [in] The new minor.
   */
  void ReplaceInPaths(const CATPLMID & iMinorToUse);
};
#endif /* CATPLMCOMPLETIONMINORDATA_H_ */
