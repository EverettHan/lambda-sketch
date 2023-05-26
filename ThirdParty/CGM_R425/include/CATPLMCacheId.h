// COPYRIGHT Dassault Systemes 2014
#ifndef CATPLMCACHEID_H_
#define CATPLMCACHEID_H_

/**
* @level Private
* @usage U1
*/

#include "CATIPLMCompStatementService.h"
#include "CATPLMServicesItf.h"
#include "CATPLMCEStamp.h"
#include "CATPLMID.h"
#include "CATOmxList.h"
#include "CATOmxCollecManager.h"
#include "CATOmxOHMap.h"
#include "CATPLMID.h"
#include "CATLISTV_CATPLMID.h"
#include "CATOmxKeyValueBlock.h"
#include "CATOmxSR.h"
#include "CATIPLMRecordRead.h"
#include "CATIAV5Level.h"

#ifdef CATIAR417
#include "CATPLMTypeHSet.h"
#include "CATPLMRepositoryName.h"
#endif

class CATIPLMError;
class CATIPLMRecordRead;
class CATIPLMQueryFilter;
class CATPLMTypeH;
class CATPLMCacheId;
class CATPLMIDSet;
class CATComponentId;

/**
 * Manager for CATOmxCollection usage as a value. Note suitable for usage as a key or in a basic CATOmxOMap.
 */
template<> ExportedByCATPLMIdentificationAccess CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMCacheId>::manager();

/**
 * Map from CATPLMID to CATPLMCacheId.
 * See @href CATOmxOHMap for detail and sample usage 2. in the next comment.
 */
typedef CATOmxOHMap<CATPLMID, CATPLMCacheId> CATPLMCacheIdMap;

/**
 * Class to represent unique identifier for a data in an applicative cache.
 * It must be used as input to CATIPLMCompApplicationLoader.
 *
 * There are two main use case (Warning : these sample don't handle errors or release data) :
 *
 * 1. You are already making a query (Expand, Navigate, Basic...) and you want to retrieve
 *    related applicative state through the associated CATIPLMCompApplicationLoader. Each
 *    time you add a type to the query filter of your query, you shoud call the method
 *    CATPLMCacheId::CompleteQueryFilterForCacheId to ensure the necessary data for cacheid
 *    are retrieved.
 *
 * <code>
 *   CATIPLMCompStatementService::ApplicationIdentifier myAppId;
 *   CATIPLMCompStatement * myStatement;
 *   CATIPLMQueryFilter * myQueryFilter;
 *
 *   // Create and fill your query filter.
 *   //...
 *   // For each type in the select condition:
 *   CATPLMTypeH theSelectedType(...);
 *   CATPLMCacheId::CompleteQueryFilterForCacheId(myAppId, myQueryFilter, theSelectedType);
 *
 *   // Run your query and treat the results. In addition to your existing treatment, you
 *   // can fill a list of CATPLMCacheIds (or CATPLMCacheIdMap...) you'll use later to
 *   // retrieve the full state through CATIPLMCompApplicationLoader api.
 *   CATIPLMCompRecordReadSet * records;
 *   myStatement -> Query(&records);
 *
 *   CATOmxArray<CATPLMCacheId> cacheIds;
 *   CATIPLMRecordRead * record = NULL;
 *   while(S_OK == records.Next(&record) && record)
 *   {
 *     // Your existing treatment
 *     //...
 *     CATPLMCacheId cacheId;
 *     cacheId.InitFromRecord(myAppId, record);
 *     cacheIds.Append(cacheId);
 *   }
 *
 *   // Later in your code (see @href CATIPLMCompApplicationLoader and @href CATIPLMCompStatementService):
 *   CATIPLMCompApplicationLoader * myAppLoader;
 *   // ...
 *   for(int i=1, size= cacheIds.Size(); i <= size; ++i)
 *     myAppLoader -> AddInput(cacheIds[i]);
 *   CATIPLMCompRecordReadSet * appLoaderRecords;
 *   myAppLoader -> Query(&records);
 *   // ...
 * </code>
 *
 * 2. You have a bunch of CATPLMIDs and you want their latest state for your application,
 *    with the benefit of the CATIPLMCompApplicationLoader. Them, you should call
 *    CATPLMCacheId::QueryCacheIds
 *
 * <code>
 *   CATIPLMCompStatementService::ApplicationIdentifier myAppId;
 *   CATPLMIDSet plmids;
 *   // Fill the set with your plmids
 *   //...
 *   CATPLMCacheIdMap cacheIds;
 *   CATOmxList<CATIPLMError> errors;
 *   CATPLMCacheId::QueryCacheIds(myAppId, plmids, cacheIds, errors);
 *
 *   // Later in your code (see @href CATIPLMCompApplicationLoader and @href CATIPLMCompStatementService):
 *   CATIPLMCompApplicationLoader * myAppLoader;
 *   // ...
 *   CATPLMCacheIdMap::MapIteratorType iter = cacheIds.MapIterator();
 *   while(iter.Next())
 *     myAppLoader -> AddInput(iter.Value());
 *   CATIPLMCompRecordReadSet * appLoaderRecords;
 *   myAppLoader -> Query(&records);
 *   // ...
 * </code>
 */
class ExportedByCATPLMServicesItf CATPLMCacheId
{
  CATIPLMCompStatementService::ApplicationIdentifier  _appid;
  CATOmxSR<CATIPLMRecordRead>                         _CacheRR;
  CATBoolean                                          _ErrMode;
  
public :

  /**
   * Initialized a empty CATPLMCacheId.
   * The CATPLMCacheId will only completed and useable once
   * InitFromRecord is called.
   */
  CATPLMCacheId();

  CATBoolean IsValid() const { return (_CacheRR)?TRUE:FALSE; }

  /**
   * Initialize the internal values for the CATPLMCacheId from a
   * given CATIPLMRecordRead. To be sure you have asked for the good
   * information in your query, use CompleteQueryFilterForCacheId
   * static mehtod in this class.
   *
   * @param iAppId [in]:
   *    the application id for which the cacheid will be used.
   * @param iRecord [in]:
   *    the record from where to extract the CacheId data
   * @returns
   *    S_OK if all the necessary data has been found in the record
   *    E_FAIL if the record is missing some necessary data
   *    E_* in case of error (invalid input...)
   */
  HRESULT InitFromRecord(
      const CATIPLMCompStatementService::ApplicationIdentifier & iAppId,
      CATIPLMRecordRead * iRecord,
      CATBoolean b=FALSE);

#ifdef CATIAR215      
  /**
   * Initialize the internal values for the CATPLMCacheId from a
   * given CATIPLMSessionDataSource. 
   *
   * @param iAppId [in]:
   *    the application id for which the cacheid will be used.
   * @param iSessionDataSource [in]:
   *    the source from where to extract the CacheId data
   * @returns
   *    S_OK if all the necessary data has been found in the source
   *    E_FAIL if the source is missing some necessary data
   *    E_* in case of error (invalid input...)
   */
  HRESULT InitFromComponentId(
      const CATIPLMCompStatementService::ApplicationIdentifier & iAppId,
      const CATComponentId &iCmpId);
#endif      

  /**
   * Adds the necessary attributes to query for CATPLMCacheId creation
   * for the components of the given type. Note that the added attributes
   * will be accessible in the record reads for your components.
   *
   * @param iAppId [in]:
   *   the AppId the CacheIds
   * @param iQueryFilter [in]:
   *   the query filter to complete
   * @param iType [in]:
   *   the type on which to query the CacheId.
   * @return
   *   S_OK if the extraction of the necessary data succeeds
   *   E_INVALIDARG if iAppId is AppId_Unknown or iQueryFilter null
   *   E_FAIL if the necessary data as not been found in the record.
   *     The cacheid as not beed initialized.
   */
  static HRESULT CompleteQueryFilterForCacheId(
      const CATIPLMCompStatementService::ApplicationIdentifier & iAppId,
      CATIPLMQueryFilter * iQueryFilter,
      const CATPLMTypeH & iType);

#ifdef CATIAR417
  /**
   * Same as previous, iterating over the given types.
   * Stops at first error.
   */
  static HRESULT CompleteQueryFilterForCacheId(
      const CATIPLMCompStatementService::ApplicationIdentifier & iAppId,
      CATIPLMQueryFilter * iFilter,
      const CATPLMTypeHSet & iTypes);

  /**
   * Adds the necessary attributes to query for CATPLMCacheId creation
   * for the components of the types already added to the query filter.
   * Note that the added attributes will be accessible in the record reads
   * for your components.
   *
   * @param iAppId [in]:
   *   the AppId the CacheIds
   * @param iQueryFilter [in]:
   *   the query filter to complete
   * @return
   *   S_OK if the extraction of the necessary data succeeds
   *   E_INVALIDARG if iAppId is AppId_Unknown or iQueryFilter null
   *   E_FAIL if the necessary data as not been found in the record.
   *     The cacheid as not beed initialized.
   */
  static HRESULT CompleteQueryFilterForCacheId(
      const CATIPLMCompStatementService::ApplicationIdentifier & iAppId,
      CATIPLMQueryFilter * iQueryFilter);

  /**
   * Clones the given query, removes the selection conditions and
   * replace them with the query for CacheId attributes.
   *
   * @param iAppId [in]:
   *   the AppId the CacheIds
   * @param iQueryFilter [in]:
   *   the query filter to be cleaned
   * @return CATBaseUnknown::Release
   *   a new query filter with only the cacheid attributes
   */
  static CATIPLMQueryFilter * DuplicateQueryForCacheIds(
      const CATIPLMCompStatementService::ApplicationIdentifier & iAppId,
      CATIPLMQueryFilter * iQueryFilter);
#endif

  /**
   * Queries the current cacheids for the given plmids from the database.
   *
   * @param iAppId (in]:
   *   the AppId for the cacheids.
   * @param iPlmids [in]:
   *   a collection of plmids for which to retrieve the current cacheids.
   * @param oCacheIds [out]:
   *   the cacheids for the given iPlmids. Note that its order is NOT granted.
   * @param oErrors [out]:
   *   the various PLMError encountered during the query, mainly not found componente
   *   (deleted or unaccessible due to pno restrictions)
   * @return
   *   S_FALSE if the given collection is empty
   *   S_OK if the query succeeded and no severe error as been encountered. Note that
   *     unaccessible components are not considered as a severe error.
   *   E_* if the query failed or a severe error was encountered.
   */
  static HRESULT QueryCacheIds(
      const CATIPLMCompStatementService::ApplicationIdentifier & iAppId,
      const CATPLMIDs & iPlmids,
      CATPLMCacheIdMap & oCacheIds,
      CATOmxList<CATIPLMError> & oErrors);
  static HRESULT QueryCacheIds(
      const CATIPLMCompStatementService::ApplicationIdentifier & iAppId,
      const CATPLMIDSet & iPlmids,
      CATPLMCacheIdMap & oCacheIds,
      CATOmxList<CATIPLMError> & oErrors);
      
  /**
   * Queries the current cacheids for the given plmids from the database without return of the CATIPLMErrors.
   * Errors encountered during the query are stored directly in the CATPLMCacheId
   *
   * @param iAppId (in]:
   *   the AppId for the cacheids.
   * @param iPlmids [in]:
   *   a collection of plmids for which to retrieve the current cacheids.
   * @param oCacheIds [out]:
   *   the cacheids for the given iPlmids. Note that its order is NOT granted.
   * @return
   *   S_FALSE if the given collection is empty
   *   S_OK if the query succeeded and no severe error as been encountered. Note that
   *     unaccessible components are not considered as a severe error.
   *   E_* if the query failed or a severe error was encountered.
   */
  static HRESULT QueryCacheIds(const CATIPLMCompStatementService::ApplicationIdentifier & iAppId,const CATPLMIDs & iPlmids,CATPLMCacheIdMap & oCacheIds,const CATPLMRepositoryName *iRepoName = 0);
  static HRESULT QueryCacheIds(const CATIPLMCompStatementService::ApplicationIdentifier & iAppId,const CATPLMIDSet & iPlmids,CATPLMCacheIdMap & oCacheIds,const CATPLMRepositoryName *iRepoName = 0);
  static HRESULT QueryCacheIds(CATIPLMCompStatementService::ApplicationIdentifier iAppId,CATOmxIter<const CATPLMID>& iIds,const CATPLMRepositoryName* iRepoName,CATPLMCacheIdMap & oCacheIds,CATOmxIter<CATIPLMError>& oErrors);

  /**
   * Accessor to the associcated AppId
   */
  const CATIPLMCompStatementService::ApplicationIdentifier & GetAppId() const
  {
    return _appid;
  }
 
  /**
   * Accessor to the plmid
   */
  HRESULT GetPLMID(CATPLMID & oPLMID)
  {
    return (!!_CacheRR) ? (_CacheRR->GetPLMID(oPLMID)) : (E_FAIL);
  }
  
  /**
   * Accessor to the plmid
   */
  HRESULT GetErrorMode(CATBoolean & oErrMode)
  {
    oErrMode = _ErrMode;
    return (!!_CacheRR) ? (S_OK) : (E_FAIL);
  }
  
  /**
   * Accessor to the CEStamp
   */
  HRESULT GetCEStamp(CATPLMCEStamp & oCEStamp);
  
  /**
   * Accessor to the record read
   */
  CATIPLMRecordRead * GetRecordRead() const
  {
#ifdef CATIAR216
    return _CacheRR.Ref();
#else
    return const_cast<CATIPLMRecordRead *>(_CacheRR.Ref());
#endif
  }
 
private:
  CATPLMCacheId(
      const CATIPLMCompStatementService::ApplicationIdentifier & iAppId,
      const CATPLMID & iPLMID,
      const CATPLMCEStamp & iCEStamp);
      
  HRESULT _CheckValidity();
  
  friend class CATPLMCompApplicationLoaderImpl;

#ifdef CATIAR417
  static HRESULT ExtractTypesFromFilter(CATIPLMQueryFilter * iFilter, CATPLMTypeHSet & oTypes);
#endif

};

#endif /* CATPLMCACHEID_H_ */
