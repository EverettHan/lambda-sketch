/*
 * CATPLMCompletionDataOnTos.h
 *
 *  Created on: Dec 7, 2012
 *      Author: PJQ
 */

#ifndef CATPLMCOMPLETIONDATAONTOS_H_
#define CATPLMCOMPLETIONDATAONTOS_H_

#include "CATIAV5Level.h"
#include "CATPLMIntegrationAccess.h"
#include "CATPLMCompletionParameters.h"
#include "CATIPLMIDAssociationSet.h"
#include "CATPLMCompletionDataCplxMode.h"
#include "CATPLMCompletionDataVisitor.h"
#include "CATOmxOHMap.h"
#include "CATOmxMapIter.h"
#include "CATPLMID.h"
#include "CATPLMIDCollections.h"
#include "CATPLMIDSet.h"
#include "CATPLMCompletionDatum.h" //Legacy
#include "CATIPLMQueryFilter.h"
#include "CATOmxSR.h"
#include "CATOmxCollecManagers.h"
#include "CATOmxDefaultCollecManager.h"

class CATIPLMRecordRead;
class CATOmxKeyValueBlock;
class CATPLMCompletionRecordParserForFetch;
class CATPLMCompletionDataVisitor;
class CATPLMCompletionDataIter;
class CATPLMCompletionDataRawIter;
class CATPLMCompletionData;

class CATPLMCompletionDataOnTos;
template <>
ExportedByCATPLMIntegrationAccess CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMCompletionDataOnTos>::manager();

class ExportedByCATPLMIntegrationAccess CATPLMCompletionDataOnTos
{

  friend class CATPLMCompletionDataRawIter;
  friend class CATPLMCompletionRecordParserForFetch;

public:
  CATPLMCompletionDataOnTos();
  CATPLMCompletionDataOnTos(const CATPLMCompletionDataOnTos & iData);
  CATPLMCompletionDataOnTos(const CATPLMID  & iPid, CATPLMCompletionDataCplxMode::Mode iCplxMode = CATPLMCompletionDataCplxMode::NoModif, CATIPLMQueryFilter *iAssociatedFilter = NULL);
  virtual ~CATPLMCompletionDataOnTos();
  CATPLMCompletionDataOnTos(const CATPLMCompletionData & iData);

  /*
  * Updates the current datums with the given one(s). The comparaison is done on the plmid.
  * If no curresponding plmid is found for a given datum, this datum is them inserted.
  */
  void UpdateOrInsert(const CATPLMID                &iPLMID, CATPLMCompletionDataCplxMode::Mode iCplxMode = CATPLMCompletionDataCplxMode::NoModif, CATIPLMQueryFilter *iAssociatedFilter = NULL);
  void UpdateOrInsert(const CATPLMIDs               &iPLMIDs, CATPLMCompletionDataCplxMode::Mode iCplxMode = CATPLMCompletionDataCplxMode::NoModif, CATIPLMQueryFilter *iAssociatedFilter = NULL);
  void UpdateOrInsert(const CATPLMID                &iPLMID, const CATOmxKeyValueBlock &iBlock, CATIPLMQueryFilter *iAssociatedFilter = NULL);
  void UpdateOrInsert(const CATPLMCompletionData    &iData);
  void UpdateOrInsert(const CATPLMCompletionDataOnTos &iData, CATPLMCompletionDataCplxMode::Mode iCplxMode = CATPLMCompletionDataCplxMode::NoModif);
  void UpdateOrInsert(CATIPLMRecordRead       *iRecord,
    const CATBoolean &iSynchronizeRelations = TRUE,
    const CATBoolean &iSynchronizeAttributes = TRUE,
    CATIPLMQueryFilter *iAssociatedFilter = NULL);
  void UpdateOrInsert2(CATIPLMRecordRead       *iRecord,
    const CATBoolean &iSynchronizeRelations = TRUE,
    const CATBoolean &iSynchronizeAttributes = TRUE,
    const CATOmxList<CATIPLMQueryFilter> * iAssociatedQueryFilters = NULL);
  void UpdateOrInsert2(const CATPLMID                &iPLMID, const CATOmxList<CATIPLMQueryFilter> * iAssociatedQueryFilters, CATPLMCompletionDataCplxMode::Mode iCplxMode = CATPLMCompletionDataCplxMode::NoModif);
  void UpdateOrInsert2(const CATPLMIDs               &iPLMIDs, const CATOmxList<CATIPLMQueryFilter> * iAssociatedQueryFilters, CATPLMCompletionDataCplxMode::Mode iCplxMode = CATPLMCompletionDataCplxMode::NoModif);
  /*@ deprecated, use UpdateOrInsert with AttributeBlock */
  void Append(const CATPLMCompletionDatum  & iDatum);

  unsigned int Size() const;

  /*
  * Return S_OK if a datum corresponding to the given PLMID is found and removed,
  * S_FALSE if the datum/plmid hasn't been found. Note that if iCplxMode is not default, this status will the one of the last element of the path
  * else, returns E_FAIL.
  */
  HRESULT Remove(const CATPLMID & iPLMID, CATPLMCompletionDataCplxMode::Mode iCplxMode = CATPLMCompletionDataCplxMode::NoModif);
  HRESULT Remove(const CATPLMCompletionData   & iData, CATPLMCompletionDataCplxMode::Mode iCplxMode = CATPLMCompletionDataCplxMode::NoModif);
  HRESULT Remove(const CATPLMCompletionDataOnTos   & iData, CATPLMCompletionDataCplxMode::Mode iCplxMode = CATPLMCompletionDataCplxMode::NoModif);
  HRESULT RemoveAll();
  /**
   * Removes every paths that fully contains the target path.
   * For example, if you want to remove every paths that contains B->C->D the
   * result is:
   * - B->C->D => Removed
   * - A->B->C->D => Removed
   * - A->B->C->D->E => Removed
   * - A->B->C => Kept
   * @param iTargetPath [in]
   *  The path to contain for removal (may be a simple PLMID).
   * @return
   *  S_OK if some paths were removed, S_FALSE if no path containing the target
   *  were found, or E_* if the method failed.
   */
  HRESULT RemovePaths(const CATPLMCompletionData & iData);
  HRESULT RemovePaths(const CATPLMCompletionDataOnTos & iData);
  HRESULT RemovePaths(const CATPLMID & iTargetPath);

  /*
  * Return S_OK if a PLMID is found in the data,
  * else, returns E_FAIL.
  */
  HRESULT Locate(const CATPLMID  & iPid) const;
  const CATOmxList<CATIPLMQueryFilter> *GetAssociatedQueryFilters(const CATPLMID &iPid) const;

  /*
  * Parse the content of the data.
  */
  HRESULT Visit(CATPLMCompletionDataVisitor & iVisitor, CATPLMCompletionDataCplxMode::Mode iCplxMode = CATPLMCompletionDataCplxMode::NoModif) const;

  /**
  * Get a basic iterator on the content of the collection
  */
  CATPLMCompletionDataRawIter GetRawIterator() const;

  /**
   * Get an iterator on the content of the collection with refined complex plmid management.
   */
  CATPLMCompletionDataIter GetIterator(CATPLMCompletionDataCplxMode::Mode iCplxMode) const;

  /*
  * Add a complex plmid as simple elements. Or a simple element as itself.
  */
  HRESULT AddAsSimples(const CATPLMID &iId, CATIPLMQueryFilter *iAssociatedFilter = NULL);

  /*
  * Get simple plmids from every added plmids. Gets a "flatten" view of the data.
  */
  HRESULT ToSimplePLMIDs(CATPLMIDs &oIds);

  /**
   * Adds the contained PLMIDs to the PLMIDList/PLMIDSet
   */
  HRESULT AddToPLMIDs(CATPLMIDs & oPLMIDs, CATPLMCompletionDataCplxMode::Mode iCplxMode = CATPLMCompletionDataCplxMode::NoModif) const;
  HRESULT AddToPLMIDSet(CATPLMIDSet & oPLMIDs, CATPLMCompletionDataCplxMode::Mode iCplxMode = CATPLMCompletionDataCplxMode::NoModif) const;

protected:

  /**
  * Basically handle the datum inside the collection, without managing the cplxmode.
  * Can be speciallized to add some specific behaviour.
  */
  virtual void RawUpdateOrInsert(const CATPLMID            &iPid, CATIPLMQueryFilter *iAssociatedFilter = NULL);
  virtual void RawUpdateOrInsert(CATIPLMRecordRead   *iRecordRead,
    const CATBoolean &iSynchronizeRelations = TRUE,
    const CATBoolean &iSynchronizeAttributes = TRUE,
    CATIPLMQueryFilter *iAssociatedFilter = NULL);
  virtual HRESULT RawRemove(const CATPLMID   &iPLMID, CATPLMCompletionDataCplxMode::Mode iCplxMode);
  virtual HRESULT RawRemove(const CATPLMID   &iPLMID);
  virtual HRESULT RawRemoveAll();
  //must add simple ids to completion space
  HRESULT InsertInCompletionSpace(const CATPLMID &iPlmid);

  friend class CATPLMCompletionDataRawIter;
  friend class CATPLMCompletionDataManager;

private:
  void Reserve(int size);

  CATOmxOHMap<CATPLMID, CATOmxList<CATIPLMQueryFilter> > _data;
};

/**
 * Basic iterator on the content of a CATPLMCompletionData.
 *
 * Basic usage :
 * <code>
 * CATPLMCompletionDataRawIter iter = myCompletionData.GetRawIterator();
 * while(iter.Next())
 * {
 *   CATPLMID current = iter.Current();
 *   // ...
 * }
 * </code>
 */
class CATPLMCompletionDataRawIter
{
  CATOmxOHMap<CATPLMID, CATOmxList<CATIPLMQueryFilter> >::MapIteratorType _iter;
  CATPLMID _current;
public:
  CATPLMCompletionDataRawIter() = default;
  CATPLMCompletionDataRawIter(const CATPLMCompletionDataOnTos & iData) :_iter(iData._data.MapIterator()) {}

  CATBoolean Next() { return _iter.Next(); }
  const CATPLMID & Current() { return _iter.Key(); }
};

#include "CATPLMCompletionDataIter.h"

#endif /* CATPLMCOMPLETIONDATAONTOS_H_ */


