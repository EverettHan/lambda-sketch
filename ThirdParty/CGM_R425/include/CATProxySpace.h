#ifndef CATProxySpace_H
#define CATProxySpace_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004

/**
 * @level Protected
 * @usage U1
 */

#include "ExportedByCATPLMTos.h"
#include "CATTosMacros.h"
#include "CATErrorMacros.h"
#include "CATString.h"
#include "CATPLMRepositoryName.h"
#include "CATLISTV_CATComponentId.h"
#include "CATComponentId.h"
#include "CATProxySpaceCategory.h"
#include "CATPLMIDVisitor.h"
#include "CATComponentIdVisitor.h"
#include "CATUuid.h"
#include "CATOmxArray.h"

class CATComponentId;
class CATComponentIdFilter;
class CATOmXStream;
class CATPLMRepositoryName;
class CATPLMID;
class CATProxySpace;
class CATPLMCEStamp;
class CATIPLMSpace;
class CATProxySpaceTransferManager;
class OmbTST_PLMSessionBuilder;

/**
 * This class is a handle to an object which is a container of TOS objects (see CATComponentId)
 * It is identified by its
 *   repository (PLM1, TST etc..)
 *   name
 *   category (@href CATProxySpaceCategory)
 *   uuid (mandatory for "incoming" spaces, zero for others)
 */
class ExportedByCATPLMTos CATProxySpace
{
public:

  /**
  *  BindToCreate
  *    Register an actor to be created inside Database persistency .
  *
  * @param iEntity
  *    Entity as unit of repository.
  *
  * @param iTargetShema
  *    See CATPLMTypeId.
  *
  * @param oHandle
  *    Handle on entity.
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  *   */
  HRESULT BindToCreate(CATBaseUnknown  * iEntity, const CATPLMTypeId & iTargetShema, CATComponentId & oHandle);

  HRESULT FindAlreadyBindedEntity(CATBaseUnknown* iObject, CATComponentId   & oHandle, CATTosQuery_Filter iFilter = CatTosQuery_ActivatedOrGarbagedInSession) const;



  /**
  * @return
  *      S_OK    if result is found<br>
  *      S_FALSE if result is not found<br>
  *      E_FAIL  if request failed <br>
  */
  HRESULT  Search_ByPhysicalIdentity(const CATPLMID           & iPLMID,
    CATComponentId           & oCID,
    const CATTosQuery_Filter & iFilter = CatTosQuery_OnlyActivatedInSession,
    const CATBoolean           iAllocateHandleIfNecessary = FALSE) const;

  /** obsolete, use SearchByPhysicalId */
  HRESULT Search_ByPhysicalIdentity(const char* iPhysicalId, CATComponentId& oCID, const CATTosQuery_Filter & iFilter = CatTosQuery_OnlyActivatedInSession) const;

  /**
   * Search a TOS cell using its physicalid
   */
  CATComponentId SearchByPhysicalId(const CATPLMID_Any& iPhysicalId, CATTosQuery_Filter iFilter = CatTosQuery_Nofilter) const;

  /**
  *  PrepareBindEntity
  *    Prepare Bind Entity.
  *
  * @param iIdentifier
  *
  * @param oHandle
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  *   */
  HRESULT  PrepareBindEntity(const CATPLMID & iIdentifier, CATComponentId & oHandle);

  /**
  * from a PLMID retrieve a "logical family"
  * the notion of "logical family" is here broken.
  * it is by default objects sharing the same logicalid,
  * but, depending on type, environment variable and session state it can be something else (objects that share(d) the same attribute value "at a given moment")
  *
  * notice that if used with paths, the returned paths might be invalid (broken path of instances)
  *
  * if you wish to browse the actual "logical family", use CATIPLMSpace::GetLogicalFamily
  */
  HRESULT Search_ByLogicalIdentity(const CATComponentId& iWithLogicalIdentifier, CATOmxArray<CATComponentId>& oHandles, const CATTosQuery_Filter& iFilter = CatTosQuery_OnlyActivatedInSession, const CATComponentId& iStartingOwnerShip = CATComponentId_Null) const;
  HRESULT Search_ByLogicalIdentity(const CATPLMID& iWithLogicalIdentifier, CATOmxArray<CATComponentId>& oHandles, const CATTosQuery_Filter& iFilter = CatTosQuery_OnlyActivatedInSession, const CATComponentId& iStartingOwnerShip = CATComponentId_Null) const;
  HRESULT Search_ByLogicalIdentity(const CATComponentId& iWithLogicalIdentifier, CATListValCATComponentId& oHandles, const CATTosQuery_Filter& iFilter = CatTosQuery_OnlyActivatedInSession, const CATComponentId& iStartingOwnerShip = CATComponentId_Null) const;
  HRESULT Search_ByLogicalIdentity(const CATPLMID& iWithLogicalIdentifier, CATListValCATComponentId& oHandles, const CATTosQuery_Filter& iFilter = CatTosQuery_OnlyActivatedInSession, const CATComponentId& iStartingOwnerShip = CATComponentId_Null) const;


  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  //   
  //  Major identification Search 
  //  
  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  /**
  * Visit a minor family from a single component according to filter
  *
  * @param iWithMajorIdentifier
  *        One element of the minor family (Complex are forbidden)
  * @param iVisitor
  *        A visitor on the components that may be present or not
  * @param iFilter
  *        Criteria of search
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT Search_ByMajorIdentity(const CATComponentId       & iWithMajorIdentifier,
    CATComponentIdVisitor      & iVisitor,
    const CATTosQuery_Filter   & iFilter = CatTosQuery_OnlyActivatedInSession) const;

  /**
  * Visit a minor family from a single ID according to filter
  *
  * @param iWithMajorIdentifier
  *   ID with Major Identifier of a minor family (Complex are forbidden)
  * @param iVisitor
  *   A visitor on the components that may be present or not
  * @param iFilter
  *   Criteria of search
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT Search_ByMajorIdentity(const CATPLMID              & iWithMajorIdentifier,
    CATComponentIdVisitor       & iVisitor,
    const CATTosQuery_Filter    & iFilter = CatTosQuery_OnlyActivatedInSession) const;

  //------------------------------------------------------------------------
  //  Short description   
  //------------------------------------------------------------------------

  /**
  * GetSpaceName
  *
  * @param oName
  *   Name
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  *   */
  HRESULT  GetSpaceName(CATUnicodeString   & oName) const;


  /**
  * GetSpaceCategory
  *
  * @param oCategory
  *        The category
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT GetSpaceCategory(CATProxySpaceCategory  & oCategory) const;

  /**
  * GetSpaceRepositoryName
  *
  * @param oRepositoryName
  *        The associated repository
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT GetSpaceRepositoryName(CATPLMRepositoryName & oRepositoryName) const;

  /**
  * GetSiteOfProvider
  *
  * @param oSiteOfRepository
  *    Site Of Repository
  *
  * @return
  *      S_OK    if request succeeded <br>
  *      S_FALSE if request succeeded but without result<br>
  *      E_FAIL  if request failed <br>
  */
  HRESULT GetSiteOfProvider(CATPLMID_RepositoryLocation & oSiteOfRepository) const;

  //------------------------------------------------------------------------
  //  Searrch    
  //------------------------------------------------------------------------

  /** obsolete, use CATProxySpaceFinder **/
  static CATProxySpace NextSpace(const CATProxySpace & iInfraSpace);

  /**
  * The default name of a proxy space
  */
  static const CATUnicodeString CATIA3D;

  /**
 * Get the uuid of the space
 *
 * @return
 *   The uuid
 */
  const CATUuid GetUuid() const;

  /**
  * Get the space identifier as string.
  * The identifier is built as such: "category" + "unique integer"
  * For example : "Associative1"
  * See @href CATProxySpaceCategory for details about categories.
  *
  * @param oIdentifier
  *   the identifier
  *
  * @return
  *   S_OK if success
  *   E_FAIL otherwise
  */
  HRESULT GetSpaceIdentifierAsString(CATString & oIdentifier) const;

  /**
  * GetProxySpaceFromIPLMSpace
  *   Retrieve a @href CATProxySpace from a @href CATIPLMSpace
  *
  * @param iDataSpace
  *   Initial dataspace
  *
  * @param oProxySpace
  *   the dataspace management
  *
  * @return
  *      S_OK    if result is found<br>
  *      E_FAIL  if request failed <br>
  *      E_INVALIDARG  if provided space is invalid <br>
  *   */
  static HRESULT  GetProxySpaceFromIPLMSpace(CATIPLMSpace* iDataSpace, CATProxySpace& oDataSpace);

  /**
  * GetIPLMSpaceFromProxySpace
  *   Retrieve a @href CATIPLMSpace from a @href CATProxySpace
  *
  * @param oDataSpace
  *   returned dataspace to be released
  *
  * @return
  *      S_OK    if result is found<br>
  *      E_FAIL  if request failed <br>
  *      E_INVALIDARG  if provided space is invalid <br>
  *   */
  static HRESULT GetIPLMSpaceFromProxySpace(CATProxySpace& iDataSpace, CATIPLMSpace *& oDataSpace);

  /** obsolete, use CATProxySpaceFinder **/
  static HRESULT FindOrAllocateProxySpaceFromPLMID(const CATPLMID& iPLMID, CATProxySpace& oSpace, CATProxySpaceCategory iSpaceCategory = CatProxySpaceCategory_Associative, const CATUnicodeString& iSpaceName = CATIA3D, CATBoolean              iAllocateIfNecessary = FALSE, CATUuid                 iUuid = CATUuid(nullptr));
  HRESULT FindOrAllocateProxySpaceFromSpace(CATProxySpace& oSpace, CATProxySpaceCategory iSpaceCategory = CatProxySpaceCategory_Associative, const CATUnicodeString& iSpaceName = CATIA3D, CATBoolean iAllocateIfNecessary = FALSE) const;
  HRESULT FindOrAllocateProxySpaceFromSpace(CATProxySpace& oSpace, CATUuid& iUuid, CATProxySpaceCategory iSpaceCategory = CatProxySpaceCategory_Associative, const CATUnicodeString& iSpaceName = CATIA3D, CATBoolean iAllocateIfNecessary = FALSE) const;
  static HRESULT FindAuthoringProxySpaceFromPLMID(const CATPLMID& iPLMID, CATProxySpace& oSpace);
  static HRESULT FindProxySpace(CATProxySpace & oSpace, CATProxySpaceCategory iSpaceCategory, const CATUnicodeString & iSpaceName = CATIA3D);
  static HRESULT FindOrAllocateProxySpace(CATProxySpace& oSpace, CATProxySpaceCategory iSpaceCategory, const CATPLMRepositoryName & iRepositoryName, const CATPLMID_RepositoryLocation & iRepositoryIdentifier, const CATUnicodeString & iSpaceName, CATBoolean iDoNotAllocateOnFly = FALSE);
  static HRESULT FindOrAllocateProxySpace(CATProxySpace& oSpace, CATProxySpaceCategory iSpaceCategory, const CATPLMRepositoryName & iRepositoryName, const CATPLMID_RepositoryLocation & iRepositoryIdentifier, const CATUnicodeString & iSpaceName, CATUuid & iUuid, CATBoolean iDoNotAllocateOnFly = FALSE);
  static HRESULT FindOrAllocateProxySpace(CATProxySpace& oSpace, CATProxySpaceCategory iSpaceCategory, const CATPLMRepositoryName & iRepositoryName, const CATPLMID_RepositoryLocation & iRepositoryIdentifier);
  static HRESULT FindOrAllocateProxySpace(CATProxySpace& oSpace, CATProxySpaceCategory iSpaceCategory, const CATPLMRepositoryName & iRepositoryName, const CATPLMID_RepositoryLocation & iRepositoryIdentifier, CATUuid & iUuid);
  static HRESULT FindProxySpaceByName(const CATPLMRepositoryName iTypeOfProvider, const CATPLMID_RepositoryLocation& iSiteOfRepository, const CATUnicodeString & iNameOfTos, CATProxySpace                      & ioDataSpace, CATBoolean                           iDoNotAllocate_OnFly);
  static HRESULT GetProxySpaceByPLMID(CATBaseUnknown *iPointingDataObject, const CATPLMID& iPLMID, CATProxySpace& oDataSpace, const CATProxySpaceCategory iIntentsCategory = CatProxySpaceCategory_Associative, CATBoolean iDoNotAllocateOnFly = FALSE);
  static HRESULT GetAuthoringProxySpace(CATProxySpace & oDataSpace);
  static HRESULT GetProxySpaceByAlreadyBindedHandle(CATBaseUnknown  * iDataObject, CATProxySpace   & oDataSpace);

  //------------------------------------------------------------------------
  //  ClearDataProxySpace
  //------------------------------------------------------------------------

  /**
  * ClearDataProxySpace
  *
  * @param iCheckBeforeClear
  *        Checks that space is empty before clearing
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  *   */
  HRESULT  ClearDataProxySpace(CATBoolean iCheckBeforeClear = TRUE);


  //------------------------------------------------------------------------
  //  IsProxySpaceCleared
  //------------------------------------------------------------------------
  /**
  * IsProxySpaceCleared
  *
  * @return
  *   S_OK if proxy space is cleared <br>
  *   E_FAIL if proxy space still holds components <br>
  *   E_INVALIDARG if proxy space is null <br>
  */
  HRESULT IsProxySpaceEmpty();



  //------------------------------------------------------------------------
  //  GetCurrentActiveSpace / SwitchActiveSpace
  //------------------------------------------------------------------------


  /**
  * GetCurrentActiveSpace
  *   Be carefull, not very usefull EXPLICIT Context is preferred methodology
  *   Access current infrastructure data management
  *
  * @param iRepositoryName
  *   Type of repository
  *
  * @param oDataSpace
  *   Get current active space
  *
  * @param iDoNotAllocate_OnFly
  *   Do Not Allocate OnFly
  *
  * @return
  *      S_OK    if request succeeded <br>
  *      S_FALSE if no result <br>
  *      E_FAIL  if request failed <br>
  **/
  static HRESULT  GetCurrentActiveSpace(const CATPLMRepositoryName iRepositoryName, CATProxySpace& oDataSpace, CATBoolean iDoNotAllocate_OnFly = TRUE);

  inline bool IsValid() const { return _ImplUsage != nullptr; }
  inline bool IsNull() const { return !IsValid(); }
  inline explicit operator bool() const { return IsValid(); }

  /** constructors */
  inline CATProxySpace() :_ImplUsage(nullptr) {}
  explicit CATProxySpace(CATOxSpace&);
  CATProxySpace(const CATProxySpace &iCopyIdSpace);
  CATProxySpace& operator=(const CATProxySpace &iCopyIdSpace);
  inline CATProxySpace(CATProxySpace&& iSpace) :_ImplUsage(iSpace._ImplUsage) { iSpace._ImplUsage = nullptr; }
  inline CATProxySpace& operator=(CATProxySpace&& iSpace)
  {
    auto* impl = _ImplUsage;
    _ImplUsage = iSpace._ImplUsage;
    iSpace._ImplUsage = impl;
    return *this;
  }
  ~CATProxySpace();

  /** internals */
  void SetUsage(CATOxSpace * Space);
  inline CATOxSpace * GetUsage() const { return _ImplUsage; };

  /**
  * Returns FALSE if this and other component share a common cell in TOS
  */
  inline int operator==(const CATProxySpace & iOtherSpace) const { return _ImplUsage == iOtherSpace._ImplUsage; }
  inline int operator!=(const CATProxySpace & iOtherSpace) const { return _ImplUsage != iOtherSpace._ImplUsage; }


  HRESULT  ResetActionIdAfterSave();
private:
  static HRESULT FindAuthoringProxySpace(const CATPLMRepositoryName & iRepositoryName, const CATPLMID_RepositoryLocation & iRepositoryIdentifier, CATProxySpace & oSpace);
  CATOxSpace* _ImplUsage;
};

template<>
ExportedByCATPLMTos CATOmxCollecManager& CATOmxDefaultCollecManager<CATProxySpace>::manager();

#endif
