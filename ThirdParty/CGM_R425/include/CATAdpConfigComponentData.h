/*
 * CATAdpConfigComponentData.h
 *
 *  Created on: Dec 16, 2013
 *      Author: pjq
 */

#ifndef CATADPCONFIGCOMPONENTDATA_H_
#define CATADPCONFIGCOMPONENTDATA_H_

/**
 * @level Protected
 * @usage U1
 */

#include "CATPLMIntegrationAccess.h"
#include "CATOmxOHMap.h"
#include "CATPLMID.h"
#include "CATPLMIDSet.h"
#include "CATAdpConfigInfo.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATProxySpace.h"
#include "CATString.h"
#include "CATIAdpErrorMonitor.h"
#include "CATOmxSharable.h"
#include "CATOmxArray.h"
#include "CATPLMCacheId.h"


class CATIPLMCompRecordReadSet;
class CATIPLMRecordRead;

/**
 * Retrieves and keep the configuration data related to instances.
 * Those data can also be filled directly into this map if they are already known.
 * This class is designed to be a shared ressource between various uses, mainly
 * for client side validation of paths with regards to a given configuration filter.
 * Be careful : the data may become obsolete if the components are modified in the
 * database. Don't keep it for to long.
 *
 * Sample usages :
 * <code>
 * // Creating the class : to enable shared owner ship of the data, this collection
 * // is a CATOmxSharable. It supports addref/release like a CATBaseUnknown, but
 * // not QueryInterface. Using a CATOmxSR is recommended to avoid memory leaks, else,
 * // don't forget to release your data !
 * CATOmxSR<CATAdpConfigComponentData> cfgData(new CATAdpConfigComponentData(), Steal);
 * //...
 *
 * // Use case 1 :
 * // You don't have any clue on the related component (or if you know it has an
 * // effectivity but don't know the related compiled form), just register it and
 * // ask for the data to be retrieved. Note that to limit the number of calls to
 * // the db, you should strive to call QueryMissingInfos only once, when you have
 * // regsitered all the wanted data to be retrieved. If used for client side
 * // validation, QueryMissingInfos will be called by the validation engine, so don't
 * // call it your self.
 * // See @CATAdpConfigComponentData::AddPLMID
 * // See @CATAdpConfigComponentData::QueryMissingInfos
 * // See @CATAdpConfigComponentData::GetConfigInfos
 * cfgData -> AddPLMID(MyInstancePlmId);
 * cfgData -> QueryMissingInfos();
 * CATAdpConfigInfo MyInstanceConfigInfo;
 * cfgData -> GetConfigInfos(MyInstancePlmId, MyInstanceConfigInfo);
 *
 * // Use case 2 :
 * // You already known the configuration info for your component (because you queried it
 * // yourself for example). You can set and retrieve it :). Calling QueryMissingInfos
 * // won't update those information, so you should be sure it is fresh. Therefore, this
 * // collection should not be kept for too long in session.
 * // See @CATAdpConfigComponentData::AddConfigInfos
 * // See @CATAdpConfigComponentData::GetConfigInfos
 * cfgData -> AddConfigInfos(MyInstancePlmId, MyInstanceConfigInfo);
 * CATAdpConfigInfo retrievedInstanceConfigInfo;
 * cfgData -> GetConfigInfos(MyInstancePlmId, retrievedInstanceConfigInfo);
 *
 * // Use case 3 :
 * // You made a query and asked for the configuration info. You can save lot of boiler
 * // plate code by simply giving us your records so we can extract the data.
 * // See @CATAdpConfigComponentData::AddConfigInfosFromRecordReads
 * // See @CATAdpConfigComponentData::AddConfigInfosFromRecordRead
 * // See @CATAdpConfigComponentData::GetConfigInfos
 * cfgData -> AddConfigInfosFromRecordRead(aQueryRecordWithConfigInfoForMyInstance);
 * CATAdpConfigInfo MyInstanceConfigInfo;
 * cfgData -> GetConfigInfos(MyInstancePlmId, MyInstanceConfigInfo);
 *
 */

typedef CATOmxOHMap<CATPLMID, CATAdpConfigInfo, CATOmxDefaultCollecManager<CATPLMID>::manager, CATAdpConfigInfo::OmxManager > CATAdpConfigInfoMap;
class ExportedByCATPLMIntegrationAccess CATAdpConfigComponentData : public CATOmxSharable
{
  CATPLMIDSet _insts, _staticMappingToQuery, _invalids; // Pas de CATOmxOSet en R212...
  CATAdpConfigInfoMap _infos;
  CATProxySpace _dataspace;

public:
  static const CATString HasEffectivityAttr;
  static const CATString EffectivityCompiledFormAttr;
  static const CATString HasStaticMappingAttr;
  static const CATString ConfigurationCompiledFormAttr;
  static const CATString ProdConfCompiledFormAttr;

  /**
   * Adds a component for config info retrieval based on its PLMID. If the data hasn't already
   * been fetched and the component is loaded in session, the related data can be extracted
   * from the loaded component.
   *
   * @param iPLMID [in]
   *  The component to add for config data retrieval. If the plmid is complex, its elements will
   *  be treated has independant plmids.
   * @param iUseSessionData [in]
   *  Force the usage of session information if the component is loaded. May be useful to
   *  ensure that the result matches the session even if the data has changed in database.
   * @returns
   *  E_INVALIDARG If the component is not an instance or relation or if the component isn't
   *               saved (based on IsValidForRemoteUsage).
   *  S_FALSE If the data is already retrieved.
   *  S_OK If the component has been added for fetch or the related data has been found in session.
   */
  HRESULT AddPLMID(const CATPLMID & iPLMID, CATBoolean iUseSessionData = FALSE);

  /**
   * Helper methods to add a whole bunch of plmids in one go. If non instance/relation plmids
   * are found in the collections, they won't be added, but the method won't fail.
   *
   * @param iPLMIDs [in]
   *  The components to add for config data retrieval.
   * @param iUseSessionData [in]
   *  Force the usage of session information if the component is loaded. May be useful to
   *  ensure that the result matches the session even if the data has changed in database.
   * @returns
   *  S_FALSE If the given collection is empty.
   *  S_OK If the components has been added for fetch.
   */
  HRESULT AddPLMIDs(const CATPLMIDSet & iPLMIDs, CATBoolean iUseSessionData = FALSE);
  HRESULT AddPLMIDs(const CATPLMIDs & iPLMIDs, CATBoolean iUseSessionData = FALSE);

  /**
   * Adds a component for config info retrieval, based on its PLMID and a known CEStamp. This
   * information enables various cache usage (mainly, the authoring session) in a clever way.
   *
   * @param iPLMID [in]
   *  The component to add for config data retrieval. Complex plmids are not allowed.
   * @param iCEStamp [in]
   *  The known current stamp of the component.
   * @returns
   *  E_INVALIDARG If the component is not an instance or relation or if the component isn't
   *               saved (based on IsValidForRemoteUsage) or the component is complex (path).
   *  S_FALSE If the data is already retrieved.
   *  S_OK If the component has been added for fetch or the related data has been found in session.
   */
  HRESULT AddPLMID(const CATPLMID & iPLMID, const CATPLMCEStamp & iCEStamp);

  /**
   * Associates the given configInfo to the component. It overrides existing values if existing.
   * If the component has been added before through AddPLMID, it will be removed from the data
   * to be fetched.
   *
   * @param iPLMID [in]
   *  The component on which to associated the given config info.
   * @param iConfigInfo [in]
   *  The config info to associate to the plmid.
   * @returns
   *  E_INVALIDARG If the component is not an instance.
   *  S_OK if the data has been associated.
   */
  HRESULT AddConfigInfos(const CATPLMID & iPLMID, const CATAdpConfigInfo & iConfigInfo );

  /**
   * Using the method, as well as the following AddConfigInfosFromRecordRead, you can
   * add config info from your own queries if you have asked for the right attributes
   * on instances and/or relations. It can save silly queries.
   *
   * Note that if you only asked for the 'HasEffectivity' attibute, it may be enough
   * to save important queries (if no configuration is applied to your isntances) while
   * not overweigth your own queries to much.
   *
   * @param records [in]
   *  Your record read set.
   * @returns
   *  S_OK if no impacting errors are detected. For example, if you give non instance records,
   *       the method won't fail. It will process only instances and relations. If the data is
   *       missing in those records, the method won't fail either.
   *  E_*  in case of impacting error. Most of the time, it will be an environment error.
   */
  HRESULT AddConfigInfosFromRecordReads(CATIPLMCompRecordReadSet * records, const CATIAdpErrorMonitor_var & iErrorMonitor = NULL_var);

  /**
   * Tries to extract as much configureation information as possible from the given recordread.
   *
   * Note that if you only asked for the 'HasEffectivity' attibute, it may be enough to save
   * important queries (if no configuration is applied to your isntances) while not overweigthing
   * your own queries to much.
   *
   * @param record [in]
   *  Your record read.
   * @returns
   *  E_INVALIDARG if the given record is not an instance.
   *  S_FALSE if the retrieved configuration info is not enough : there is no 'HasEffectivity'
   *          attribute or it is TRUE and the 'EffectivityCompiledForm' attribute is missing
   *  S_OK if the necessary data has been retrieved.
   */
  HRESULT AddConfigInfosFromRecordRead(CATIPLMRecordRead * record, const CATIAdpErrorMonitor_var & iErrorMonitor = NULL_var);

  /**
   * Launchs a query to retrieve the missing configuration info. The data will be fetched only
   * once. If components can't be found in the database (as if they have been deleted), the query
   * won't fail and they will be removed from the missing components.
   *
   * @param iErrorMonitor [in]
   *   An error monitor to report missing errors.
   * @returns
   *   S_FALSE if no data is missing (no query is done)
   *   S_OK if the query has been made and no dramatic error occured
   *   E_* in case of blocking error. The error monitor may give some extra information.
   */
  HRESULT QueryMissingInfos(const CATIAdpErrorMonitor_var & iErrorMonitor = NULL_var);

  /**
   * Retireves the data associated with the component has saved in this collection.
   *
   * @param iPLMID [in]
   *  The plmid to query
   * @param oConfigInfos [out]
   *  The related config info
   * @return
   *  unknown if the PLMID is not known by the collection
   *  invalid if the PLMID is known but can't be accessed by query to the DB (deleted or access restricted by PnO)
   *  toquery if the PLMID is known but the associated data has to be queried from the DB. Use QueryMissingInfos to get it
   *
   */
  enum ConfigInfoStatus{unknown, invalid, toquery, available};
  ConfigInfoStatus GetConfigInfos(const CATPLMID & iPLMID, CATAdpConfigInfo & oConfigInfos) const;

private:
  inline CATBoolean IsComplex(const CATPLMID & iPLMID);
  inline CATBoolean IsSaved(const CATPLMID & iPLMID);
  inline CATBoolean IsInstOrEquivalent(const CATPLMID & iPLMID);

  inline HRESULT AddComplexPLMID(const CATPLMID& iCplxPLMID, CATBoolean iUseSessionData);
  inline HRESULT AddSimplePLMID(const CATPLMID& iPLMID, CATBoolean iUseSessionData);
  inline void AddConfigInfosNoChecks(const CATPLMID & iPLMID, const CATAdpConfigInfo & iConfigInfo );

  inline HRESULT QueryInstancesConfigInfos(const CATIAdpErrorMonitor_var & iErrorMonitor);
  inline HRESULT QueryInstancesConfigRecords(CATIPLMCompRecordReadSet ** records);
  inline HRESULT GetConfigInfoFromRecord(CATIPLMRecordRead * record, CATAdpConfigInfo & oConfigInfo);

  inline HRESULT QueryStaticMappingCompiledForm(const CATIAdpErrorMonitor_var & iErrorMonitor);

  inline HRESULT AddSimplePLMIDWithSession(
      const CATPLMID & iPLMID, const CATPLMCEStamp * iRefCEStamp = NULL);
  inline HRESULT GetConfigInfoFromSession(
      const CATPLMID & iPLMID, CATAdpConfigInfo & oInfos, const CATPLMCEStamp * iRefCEStamp = NULL);
  inline CATBaseUnknown * GetComponentInSession(
      const CATPLMID & iPLMID, CATPLMCEStamp & oCEStamp);
  inline HRESULT FillConfigInfoFromComponent(
      CATAdpConfigInfo &oInfos, CATBaseUnknown * cbu, const CATPLMCEStamp & iCEStamp);
  inline const CATProxySpace & GetProxySpace(const CATPLMID & iPLMID);
  
  HRESULT CreateCacheIds(CATOmxArray<CATPLMCacheId> & oCacheIds);
};
#endif
