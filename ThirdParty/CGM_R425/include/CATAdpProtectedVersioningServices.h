/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2005
/**
* @level Protected
* @usage U1  
*/
#ifndef CATAdpProtectedVersioningServices_H
#define CATAdpProtectedVersioningServices_H

#include "CATPLMIntegrationAccess.h"

#include "IUnknown.h"
#include "CATBooleanDef.h"
#include "CATCollec.h"
#include "CATOmxOHMap.h"
#include "CATPLMIDCollections.h"
#include "CATPLMOmxCollections.h"

class CATLISTV(CATBaseUnknown_var);
class CATIAdpPLMIdentificator;
class CATListPtrCATBaseUnknown;
class CATTime;
class CATLISTP(CATAdpBasicQueryResult);
class CATAdpVersioningDatum;
class CATPLMID;
class CATLISTV(CATPLMID);
class CATListPtrCATIPLMComponent;
class CATIAdpErrorMonitor;
class CATAdpResultVersion;
class CATLISTP(CATAdpResultVersion);
class CATAdpResultMinorVersion;
class CATLISTP(CATAdpResultMinorVersion);
class CATLISTP(CATIAdpPLMIdentificator);
class CATAdpVersioningInfo;
class CATLISTV(CATAdpVersioningInfo);
class CATIPLMRecordRead;
class CATIPLMAttrRead;
class CATPLMRepositoryName;
class CATPLMType;
class CATPLMTypeH;
class CATIPLMCompRecordReadSet;
class CATIPLMQueryFilter;

/**
* Class to manage version operations in CATIA session.
*
* <br><b>Role</b>: Provides basic functions to manage the versions of a component.
*/
class ExportedByCATPLMIntegrationAccess CATAdpProtectedVersioningServices
{
public:

  /** 
  * Creation of a new version.
  *
  * <br><b>Role</b>: Creates in the database a new version of the provided components. 
  * The database informations are imbedded in the identifier of the object itself.
  *
  * @param iObjectToTreat [in]
  *   The identifier of the component to version.
  * @param iApplicabilityDate [in]
  *   The applicability date of the new version of the component.
  * @param oVersioned [out]
  *   The identifier of the new version of the component.
  * @param iopErrorMonitor [inout]
  *   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this service.
  * @return
  *   <ul>
  *   <li><tt>S_OK</tt>: The new version of the component was created in the database.</li> 
  *   <li><tt>E_FAIL</tt>: The new version could not be created in the database. Nothing was done during the operation. The blocking error can be accessed by using the static CATError CATGetLastError method.</li>
  *  </ul>
  */
  static HRESULT NewVersion( CATIAdpPLMIdentificator * iObjectToTreat, const CATTime & iApplicabilityDate,
    CATIAdpPLMIdentificator *& oVersioned, CATIAdpErrorMonitor* ipErrorMonitor=NULL );

  /** 
  * Creation of new versions of components available in the session.
  *
  * <br><b>Role</b>: Creates in the database a new version of every provided components. 
  * The database informations are imbedded in the identifiers of the objects itselves.
  * The provided components must be already opened in a session.
  * The new versions can be substituted to the components in the session if required.
  *
  * @param iComponents [in]
  *   The list of identifiers of components to version.
  * @param iApplicabilityDate [in]
  *   The applicability date of the new versions of the components.
  * @param iAction [in]
  *   Parameter of the VPDM versionning.
  * @param iUseNewVersionInSession [in]
  *   If required, the new versions created can then substitute the initial components in the session.
  *   <ul>
  *   <li>The use of this option will result in the deletion in the session of instances of the versioned component and the creation of instances of the new version.<li>
  *   <li>The use of this option will lead to a failure if configuration is applied on instances of the versioned component or if the user has no rights to modify the instances of the versioned component</li>
  *   </ul>
  * @param iopErrorMonitor [inout]
  *   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this service.
  * @return
  *   <ul>
  *   <li><tt>S_OK</tt>: All the new version are created in the database.</li> 
  *   <li><tt>E_FAIL</tt>: At least one new version could not be created in the database. Nothing was done during this method, the database is as before the call. The blocking error can be accessed by using the static CATError CATGetLastError method.</li>
  *  </ul>
  */
  static HRESULT NewVersion( const CATLISTV(CATBaseUnknown_var) & iComponents, const CATTime & iApplicabilityDate, 
    CATIAdpPLMIdentificator * iAction=0, CATBoolean iUseNewVersionInSession=TRUE, CATIAdpErrorMonitor* ipErrorMonitor=NULL );

  /** 
  * Creation of a new version.
  *
  * <br><b>Role</b>: Creates in the database a new version of the provided component. 
  * The database informations are imbedded in the identifier of the object itself.
  *
  * @param iVersioningDatum [in]
  *   The data enabling to perform the versioning of the component.
  * @param oNewComponent [out, CATBaseUnknown#Release]
  *   The identifier of the new version of the component.
  * @param iopErrorMonitor [inout]
  *   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this service.
  * @return
  *   <ul>
  *   <li><tt>S_OK</tt>: The new version of the component was created in the database.</li> 
  *   <li><tt>E_FAIL</tt>: The new version could not be created in the database. Nothing was done during the operation. The blocking error can be accessed by using the static @href CATError#CATGetLastError method.</li>
  *  </ul>
  */
  static HRESULT NewVersion( const CATAdpVersioningDatum & iVersioningDatum, CATIAdpPLMIdentificator *& oNewComponent, CATIAdpErrorMonitor* ipErrorMonitor=NULL );

  /** 
  * Get the available versions of a component.
  *
  * <br><b>Role</b>: Retrieves in the database all the available versions of a component.
  * The database informations are imbedded in the identifier of the object itself.
  * No order is guaranteed in return.
  *
  * @param iComponent [in]
  *   The component which versions are required.
  * @param oQueryResults [out]
  *   The result of the query in the database. Can be introspected through @href CATAdpBasicQueryResult protocol.
  * @param iopErrorMonitor [inout]
  *   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this service.
  *
  * @return
  *   <code>S_OK</code> if the versions of the component could be retrieved in the database.
  *   <code>E_FAIL</code> if the operation failed.
  *
  */
  static HRESULT GetAllVersions( CATIAdpPLMIdentificator * iComponent, CATLISTP(CATAdpBasicQueryResult) & oQueryResults, CATIAdpErrorMonitor* ipErrorMonitor=NULL );

  /** 
  * Get the available versions of a component.
  *
  * <br><b>Role</b>: Retrieves in the database all the available versions of a component.
  * The database informations are imbedded in the identifier of the object itself.
  * No order is guaranteed in return.
  *
  * @param iComponent [in]
  *   The component which versions are required.
  * @param opListPLMComp [out]
  *   The result of the query in the database.
  * @param iopErrorMonitor [inout]
  *   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this service.
  *
  * @return
  *   <code>S_OK</code> if the versions of the component could be retrieved in the database.
  *   <code>E_FAIL</code> if the operation failed.
  *
  */
  // static HRESULT GetAllVersions( const char *iRepository, CATIAdpPLMIdentificator * iComponent, CATListPtrCATIPLMComponent** opListPLMComp);

  enum VersionState {IsLastVersion, IsFirst};
  /** 
  * Check for versions of components.
  *
  * <br><b>Role</b>: Retrieves in the database all versions of components et check for state.
  * The database informations are imbedded in the identifier of the object itself.
  * No order is guaranteed in return.
  *
  * @param iPLMIDList [in]
  *   The components list whose versions must be checked.
  *   IMPORTANT : THE LIST SHOULD NOT CONTAIN DOUBLE ENTRIES. Use iPLMIDList.RemoveDuplicates before the call.
  * @param iState [in]
  *   versions state to check.
  * @param oResultList [out]
  *   The result list of checked version.
  *   -1 no version found
  *    0 version is not in good state
  *    1 version is in good state
  *
  * @return
  *   <code>S_OK</code> if the versions of the component could be retrieved in the database.
  *   <code>E_FAIL</code> if the operation failed.
  *
  */
  static HRESULT CheckVersion (CATLISTV(CATPLMID) &iPLMIDList, VersionState iState, CATListOfInt* oResultList);

  /**
  * Defines a seek mode for versions retrieval.
  * <dt> <code><b>Last</b></code>     <dd> Only the last version is required.
  * <dt> <code><b>All</b></code>      <dd> All the versions of the component are required.
  */
  enum SeekMode { Last=0, All=1 };

  /**
  * Defines an order mode for versions retrieval return.
  * <dt> <code><b>OlderFirst</b></code>     <dd> The older version is first in the returned set.
  * <dt> <code><b>NewerFirst</b></code>      <dd> The last version is first in the returned set.
  */
  enum OrderMode { None, OlderFirst, NewerFirst };

  /** 
  * Get the available versions of a component.
  *
  * <br><b>Role</b>: Retrieves in the database available versions of a component.
  *
  * @param iInputList [in]
  *   The component which versions are required.
  * @param iSeekMode [in]
  *   The seek mode.
  * @param iOrderMode [in]
  *   The order mode in return.
  * @param oResultsVersion [out]
  *   The result of the query in the database. Can be introspected through @href CATAdpBasicQueryResult protocol.
  *
  * @return
  *   <code>S_OK</code> if the versions of the component could be retrieved in the database.
  *   <code>E_FAIL</code> if the operation failed.
  *
  */
  static HRESULT RetrieveVersions (const CATLISTP(CATIAdpPLMIdentificator) &iInputList, CATAdpProtectedVersioningServices::SeekMode iSeekMode, CATAdpProtectedVersioningServices::OrderMode iOrderMode, CATLISTP(CATAdpResultVersion)& oResultsVersion);



  /**
  * Defines a seek mode for major versions retrieval.
  * <dt> <code><b>NoMajor</b></code>   <dd> No major elements are required in CATAdpVersioningInfo::GetAssociatedMajor.
  * <dt> <code><b>AllMajor</b></code>  <dd> All major elements should be returned in CATAdpVersioningInfo::GetAssociatedMajor.
  */
  enum MajorSeekMode { NoMajor = 0
    ,AllMajor
  };

  /**
  * Defines a seek mode for minor versions retrieval.
  * <dt> <code><b>NoMinor</b></code>   <dd> No minor elements are required in CATAdpVersioningInfo::GetAssociatedMinor.
  * <dt> <code><b>AllMinor</b></code>  <dd> All minor elements are required in CATAdpVersioningInfo::GetAssociatedMinor.
  */
  enum MinorSeekMode { NoMinor = 0
    ,AllMinor
  };

  /**
  * Service to retrieve informations and siblings based on version family.
  * @param iInputList [in]
  *   The components which versioning informations are required.
  * @param iMajorRetrieve [in]
  *   Tell the service to retrieve major family elements or not.
  * @param iMinorRetrieve [in]
  *   Tell the service to retrieve minor family elements or not.
  * @param oVersioningInfoResults [out]
  *   The result of the request from the database. This list is build with all iInputList elements even if there are doublons.
  *   The order of the output may not follow the order of the input list. Use CATAdpVersioningInfo::GetElement to retrieve the input if needed.
  *   The CATAdpVersioningInfo class links inputs with versioning info and minor / major elements from this particular input.
  *   If an input element launch an error (not found for example), it will not be put inside the ouput list and an error will be send to the ErrorMonitor.
  * @param iopErrorMonitor [inout]
  *   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this service.
  */
  static HRESULT GetVersioningInfo (const CATLISTP(CATIAdpPLMIdentificator) &iInputList, 
    CATAdpProtectedVersioningServices::MajorSeekMode iMajorRetrieve,
    CATAdpProtectedVersioningServices::MinorSeekMode iMinorRetrieve,
    CATLISTV (CATAdpVersioningInfo)& oVersioningInfoResults,
    CATIAdpErrorMonitor *ipErrorMonitor);

  /**
  * Service to retrieve modifications of BSF elements from a particular date.
  * @param iDate [in]
  *   The date from where to find BSF modifications.
  * @param oResultsVersion [out]
  *   The result of the request from the database. 
  *   This list is build with all minor elements which are the new BSF of their family after iDate.
  *   There is only minor information inside the result (no major information nor associated major / minor).
  */
  static HRESULT GetSpecialMinorModifiedAfter (const CATTime &iDate, CATLISTV (CATAdpVersioningInfo)& oResultsVersion);

  /**
  * Service to retrieve the main element from which a new major version will be created.
  * @param iInputList [in]
  *   The list of element to check.
  * @param oResultsVersion [out]
  *   The result of the request from the database.
  */
  //  static HRESULT GetBaseNewMajorVersionElements (const CATLISTP(CATIAdpPLMIdentificator) &iInputList, 
  //                                                 CATLISTP (CATAdpResultVersion)& oResultsVersion,
  //                                                 CATIAdpErrorMonitor *ipErrorMonitor);

  /**
  * Service to retrieve the BSF element of a list of object.
  * @param iInputList [in]
  *   The list of element to check.
  *   The request automaticaly filtered unwanted elements (Not Simple / Not saved / Instances / etc…).
  * @param oResultsVersion [out]
  *   The result of the request from the database.
  *   One output is generated for each input. 
  *   Filtered elements have an Error 'No BSF associated' generated inside the CATAdpResultVersionObject.
  *   Check the error before asking the GetIdentifiers method.
  */
  static HRESULT GetBSFOfMinorFamily (const CATLISTP (CATIAdpPLMIdentificator) &iInputList, 
    CATLISTP (CATAdpResultVersion)& oResultsVersion,
    CATIAdpErrorMonitor *ipErrorMonitor);

  /**
  * Defines VersionGraphMode.
  */
  enum VersionGraphMode {
    LinearMode = 0
    , GraphMode = 1
  };

  /**
  * Service to retrieve the Family of major version of all components in input. The family also contains minor versions if any minor versioning was perfomed : the query is based on versionid
  * @param iInputList [in]
  *   The list of components which versions are required.
  * @param iProviderName [in]
  *   The Provider Name
  * @param iVersionGraphMode [in]
  *   [NLV project] Defines LinearMode or Graphmode
  * @param iBSFOnly [in]
  *   BSFOnly parameter for query : only the BSF elements are retrieved from the query
  * @param oResultsVersion [out]
  *   The result of the query. Map containing the input element and the list of its associated major version family
  * @return
  *   <code>S_OK</code> if the versions of the components could be retrieved in the database.
  *   <code>E_FAIL</code> if the operation failed.
  */
  static HRESULT GetMajorVersionFamily(const CATOmxList<CATIAdpPLMIdentificator>& iInputList, const CATPLMRepositoryName& iProviderName, CATAdpProtectedVersioningServices::VersionGraphMode iVersionGraphMode, CATBoolean iBSFOnly, CATLISTP(CATAdpResultVersion)& oResultsVersion);

  /**
  * Service to retrieve the Family of minor version of all components in input
  * @param iInputList [in]
  *   The list of components which versions are required.
  * @param iProviderName [in]
  *   The Provider Name
  * @param iVersionGraphMode [in]
  *   [NLV project] Defines LinearMode or Graphmode
  * @param iBSFOnly [in]
  *   BSFOnly parameter for query : only the BSF elements are retrieved from the query
  * @param oResultsVersion [out]
  *   The result of the query. Map containing the input element and the list of its associated minor version family
  * @return
  *   <code>S_OK</code> if the versions of the components could be retrieved in the database.
  *   <code>E_FAIL</code> if the operation failed.
  */
  static HRESULT GetMinorVersionFamily(const CATOmxList<CATIAdpPLMIdentificator>& iInputList, const CATPLMRepositoryName& iProviderName, CATAdpProtectedVersioningServices::VersionGraphMode iVersionGraphMode, CATBoolean iBSFOnly, CATLISTP(CATAdpResultVersion)& oResultsVersion);

  /**
  * Service to retrieve the last version of all components in input
  * @param iInputList [in]
  *   The list of components which versions are required.
  * @param iProviderName [in]
  *   The Provider Name
  * @param iVersionGraphMode [in]
  *   [NLV project] Defines LinearMode or Graphmode
  * @param oResultsLastVersion [out]
  *   The result of the query. Map containing the input element and its last version
  * @return
  *   <code>S_OK</code> if the versions of the components could be retrieved in the database.
  *   <code>E_FAIL</code> if the operation failed.
  */
  static HRESULT GetLastVersion(const CATOmxList<CATIAdpPLMIdentificator>& iInputList, const CATPLMRepositoryName& iProviderName, CATAdpProtectedVersioningServices::VersionGraphMode iVersionGraphMode, CATLISTP(CATAdpResultVersion)& oResultsLastVersion);

};
#endif
