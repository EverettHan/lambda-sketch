#ifndef CATComponentId_H
#define CATComponentId_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004

/**
 * @level Protected
 * @usage U1
 */

 // System
#include "CATCollec.h"
#include "CATListPV.h"
#include "CATLISTV_CATBaseUnknown.h"
// ObjectModelerCollection
#include "CATOmxArray.h"
#include "CATOmxBaseArray.h"
#include "CATOmxCollecManager.h"
#include "CATOmxSupport.h" //DS_CXX11_SUPPORT_MOVE_SEMANTIC
// CATPLMIdentificationAccess
#include "CATAdpEditability.h"
#include "CATPLMCoreTypeFilter.h"
#include "CATPLMTypeH.h"
#include "CATPLMTypeHArray.h"
#include "CATPLMTypeId.h"
#include "CATPLMTypeToolsDefinitions.h"
// CATPLMIdentification
#include "CATAdpCodOp.h"
#include "CATAdpMetaData.h"
#include "CATComponentIdStatus.h"
#include "CATIPLMLogState.h"
#include "CATPLMComponentExtensionLogStatus.h"
#include "CATProxySpaceCategory.h"
#include "CATTosMacros.h"
#include "CATTosTodoLevel.h"
#include "CATxPDMTodoStatus.h"
#include "ExportedByCATPLMTos.h"
#include "ExportedByCATPLMIdentification.h"

class CATPLMRelationFilter;
class CATComponentIdVisitor;
class CATRelationIdVisitor;
class CATComponentIdFilter;
class CATComponentIdSet;
class CATPLMTypeId;
class CATPLMID;
class CATTrace;
class CATPLMID_Any;
class CATPLMCompletionLevel;
class CATComponentId;
class CATLISTV(CATComponentId);
class CATIComponent;
class CATIComponent_var;
class CATPLMIdentifier;
class CATPLMRepositoryName;
class CATPLMID_RepositoryLocation;
class CATIPLMLogState;
class CATIAdpPLMIdentificator;
class CATProxySpace;
class CATListValCATPLMTypeId;
class CATPLMAggregationFilter;
class CATImmChooserSessionFrame;
class CATLISTV(CATString);
class CATLISTV(CATUnicodeString);
class CATIOmbVOSnapshotAbstract;
class CATOmxKeyValueBlock;

template<> ExportedByCATPLMIdentification CATOmxCollecManager & CATOmxDefaultCollecManager <CATComponentId>::manager();
template<> ExportedByCATPLMIdentification CATOmxCollecManager & CATOmxDefaultCollecManager <CATListValCATComponentId>::manager();

class ExportedByCATPLMIdentification CATListValCATComponentId : public CATOmxArray <CATComponentId>
{
public:
  inline CATListValCATComponentId() {}
  inline CATListValCATComponentId(int iSize) {}
  inline CATComponentId& operator[](int idx) { return GetW(idx); }
  inline const CATComponentId& operator[](int idx)const { return CATOmxArray<CATComponentId>::operator[](idx); }
  inline void RemovePosition(int idx) { CATOmxArray<CATComponentId>::Remove(idx); };
  inline void InsertAt(int idx, const CATComponentId & iCID) { CATOmxArray<CATComponentId>::Insert(idx, iCID); }
  int Locate(const CATComponentId & iCID, int idx = 1) const;
  inline void Append(const CATComponentId & iCID) { CATOmxArray<CATComponentId>::Append(iCID); }
  inline void Append(const CATListValCATComponentId & iCIDs) { CATOmxArray<CATComponentId>::Append(iCIDs); }
  void RemoveAll(CATCollec::MemoryHandling iKeepAlloc = CATCollec::ReleaseAllocation);
  int RemoveValue(const CATComponentId & iRemove);
  inline int Size() const { return CATOmxArray<CATComponentId>::Size(); };
};
typedef CATListValCATComponentId CATComponentIds;

/** creepy */
class CATListValCATListValCATComponentId : public CATOmxArray<CATListValCATComponentId>
{
public:
  inline void RemovePosition(int idx) { CATOmxArray<CATListValCATComponentId>::Remove(idx); };
};
typedef CATListValCATListValCATComponentId VectorOfIDPathes;

class CATComponentId;
/** prefer CATComponentId() */
extern const ExportedByCATPLMTos CATComponentId CATComponentId_Null;

/** nodoc */
CATOmxCollecManager& ComponentIdManagerLocator();
void ExportedByCATPLMIdentification ToInternalWorld(const CATLISTV(CATComponentId) & iList, CATOmxArray<CATComponentId> & oArray);
CATOmxArray<CATComponentId> ExportedByCATPLMIdentification ToInternalWorld(const CATLISTV(CATComponentId) & iList);
void ExportedByCATPLMIdentification ToExternalWorld(const CATOmxArray<CATComponentId> &iIn, CATLISTV(CATComponentId) &iOut);

/**
 * Handle to a TOS component
 * A TOS component contains:
 *   an identifier (CATPLMID)
 *   a log status (none, modified, deleted...)
 *   strong relationships (V_Owner/from/V_IsInstanceOf/to) and also inverse strong relationsip (children/instances)
 *   SRs
 *   association to a "PLM component" (PC2 object) which holds attributes values
 *   ...
 *
 * Notice that a TOS cell may represent:
 *   the target of an SR: in such case only the PLMID is accessible and the object can represent an instance path (in such case most APIs are meaningless and will fail)
 *   a deleted object: the object is "deleted" in session but remains in order to register its deletion in database at next save
 *   an unloaded object
 *
 * Most of the time modeler or PC2 level APIs should be prefered to usage of this class
 */
class ExportedByCATPLMTos CATComponentId
{
public:
  /** default constructor*/
  inline CATComponentId() :_ImplUsage(NULL) {}
  /** destructor*/
  ~CATComponentId();
  /** copy constructor */
  CATComponentId(const CATComponentId &iCopy);
  /** copy operator */
  CATComponentId& operator=(const CATComponentId &iCopy);

  /** internal constructor*/
  explicit CATComponentId(CATOxJanus& iLetter);

  /** constructor from a PLM component*/
  CATComponentId(CATBaseUnknown* iComponentInSession);
  CATComponentId(const CATBaseUnknown* iComponentInSession);
  /**hack for CATComponentId(NULL)*/
  CATComponentId(int zero);
  CATComponentId(long zero);

#ifdef DS_CXX11_SUPPORT_MOVE_SEMANTIC 
  inline CATComponentId(CATComponentId && iCID)
  {
    _ImplUsage = iCID._ImplUsage;
    iCID._ImplUsage = NULL;
  }
  inline CATComponentId& operator=(CATComponentId&& iCID)
  {
    CATOxJanus* letter = _ImplUsage;
    _ImplUsage = iCID._ImplUsage;
    iCID._ImplUsage = letter;
    return *this;
  }
#endif

  /** return TRUE is this object is bound */
  inline explicit operator bool() const { return nullptr != _ImplUsage; }
  inline bool IsNull() const { return 0 == _ImplUsage; }

  /**
  * equality operators
  */
  inline bool operator==(const CATComponentId & iOtherComponent) const { return _ImplUsage == iOtherComponent._ImplUsage; }
  inline bool operator!=(const CATComponentId & iOtherComponent) const { return _ImplUsage != iOtherComponent._ImplUsage; }

  /**
  * Get associated space
  */
  HRESULT  GetProxySpace(CATProxySpace & oDataSpace) const;

  /**
  * Get Handle on TOS from Component In Session
  *
  * @param iComponentInSession
  *   associated value of Component available (activated) in memory
  *
  * @param oHandle
  *   Handle on Component that may be present or not
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT Get(IUnknown      * iComponentInSession, CATComponentId& oHandle);
  static HRESULT Get(CATBaseUnknown* iComponentInSession, CATComponentId& oHandle);
  static void  GetV2(CATBaseUnknown* ipComponentInSession, CATComponentId & oHandle);

  /**
  * Access to completion level on solved cells
  *
  * @param oCompletionLevel
  *        The level of completion of PLM Component
  * @return
  *    S_OK   : If available on simple cell
  *    S_FAIL : If not a simple cell
  */
  HRESULT GetCompletionLevel(CATPLMCompletionLevel & oCompletionLevel) const;

  /**
  * Check if component is matching PLM super type.
  *
  * @return
  *      Check result
  */
  CATBoolean IsMatchingSuperTypes(const CATPLMTypeHArray & iTypeFilter) const;

  /**
  * GetCIDStatus
  *    Give a computed status.
  *
  * @return
  * <tt> Possible values:</tt>
  * <dl>
  * @param <tt>ToCreate</tt>                   <dd>Entity definition is to be created in database.
  * @param <tt>ToModify</tt>                   <dd>Entity definition is to be modified in database.
  * @param <tt>ToDelete</tt>                   <dd>Entity definition is to be deleted in database.
  * @param <tt>Loaded</tt>                     <dd>Entity definition is available in session without known persistency intents
  * @param <tt>Waiting</tt>                    <dd>Entity definition is not available.
  * @param <tt>Lost</tt>                       <dd>Entity definition is considered as Lost from Persistency Point of View.
  * @param <tt>Invalid</tt>                    <dd>Entity definition is no more valid. (e.g. Object newly created & deleted)
  * </dl>
  */
  CATComponentIdStatus GetCIDStatus() const;

  /**
  * GetCIDPartialStatus
  *
  *    With this optimized computation, the ToModify status is not computed and component is seen as Loaded instead of ToModify.
  *    So you must use this method only if your are clear with this behaviour.
  *
  * @return
  * <tt> Possible values:</tt>
  * <dl>
  * @param <tt>ToCreate</tt>                   <dd>Entity definition is to be created in database.
  * @param <tt>ToDelete</tt>                   <dd>Entity definition is to be deleted in database.
  * @param <tt>Loaded</tt>                     <dd>Entity definition is available in session WITH or WITHOUT known persistency intents.
  * @param <tt>Waiting</tt>                    <dd>Entity definition is not available.
  * @param <tt>Lost</tt>                       <dd>Entity definition is considered as Lost from Persistency Point of View.
  * @param <tt>Invalid</tt>                    <dd>Entity definition is no more valid. (e.g. Object newly created & deleted)
  * </dl>
  */
  CATComponentIdStatus GetCIDPartialStatus() const;

  /**
  * GetxPDMTodoStatus
  *   Gives the Save Log status of the component. DO NOT USE THE RESULT IF THE RESULT IS NOT S_OK.
  *   Fails if the ComponentId if not one of a reference
  *
  * @param oxPDMTodoStatus
  *   The Save Log Status of the component. If the result is S_OK, the value of oxPDMStatus has the following meaning :
  *     - CATxPDMTodoStatusCreated  : The reference is new, it has not been propagated yet
  *     - CATxPDMTodoStatusModified : The reference is not new.
  *                                   The reference or one of the components it aggregates have been modified
  *     - CATxPDMTodoStatusDeleted  : The reference has been deleted (should not happen as of yet)
  *
  * @return
  *   S_OK : if the status was correctly computed / Use the output status in that case only.
  *   S_FALSE : The reference has not been created, modified or deleted. The output status is irrelevant in that case.
  *   E_INVALIDARG : This object is not a reference. The output status is irrelevant in that case.
  *   E_FAIL : The status could not be retrieved from the CATComponentId. The output status is irrelevant in that case.
  */
  HRESULT GetxPDMTodoStatus(CATxPDMTodoStatus & oxPDMTodoStatus) const;


  /**
  * retrieve log state
  */
  HRESULT GetTodoStatus(CATPLMLogStatus & oLogStatus, CATTosTodoLevel iTodoLevel = CatTosTodoLevel_Undefined) const;

  /**
  * retrieve log status
  *
  * @param oState [out, CATBaseUnknown#Release]
  *    Complete Log status
  *
  * @param oLogStatus
  *    Synthetic Log status
  *
  * @param iTodoLevel
  *        Select the TOS level
  *
  * @return
  *      S_OK    if request succeeded <br>
  *      S_FALSE if request succeeded but no available LogState status <br>
  *      E_FAIL  if request failed <br>
  */
  HRESULT GetTodoStatus(CATIPLMLogState ** oState, CATPLMLogStatus  * oLogStatus = NULL, CATTosTodoLevel    iTodoLevel = CatTosTodoLevel_Undefined) const;

  /**
   * declare creation
   */
  HRESULT ToCreate();

  /** meaningless, what is modified ? */
  HRESULT ToModify();
  /** modify something...*/
  HRESULT ToModify(CATPLMLogModified iModificationType);
  /**declare an attribute is modified, iModificationType must CATPLMLogModified_UserAttribute*/
  HRESULT ToModify(CATPLMLogModified iModificationType, const CATOmxKeyString& iModifiedAttribute);

  HRESULT ToDelete();
  HRESULT EmptyTodo();
  HRESULT ClearTodoStatus();

  /**
  * Declare the creation of an extension
  * @param iExtensionName : the name of the created extension
  * @return
  *    S_OK if extension was registered as created
  *    E_FAIL if extension could not be registered (e.g. already registered)
  */
  HRESULT ToCreateExtension(const CATPLMTypeId & iExtensionType);

  /**
  * Declare the deletion of an extension
  * @param iExtensionName : the name of the deleted extension
  * @return
  *    S_OK if extension was registered as deleted
  *    E_FAIL if extension could not be registered (e.g. already registered as deleted)
  */
  HRESULT ToDeleteExtension(const CATPLMTypeId & iExtensionType);

  /**
  * List all modified extensions of the component
  * @param iLevel : the level - global or differential - of the status
  * @param oModifiedExtensions : the list of name of modified extensions
  * @return
  *    S_OK if list of modified extensions was generated
  *    E_FAIL if something wrong happened
  */
  HRESULT ListModifiedExtensions(CATTosTodoLevel iLevel, unsigned int iModificationTypes, CATLISTV(CATPLMTypeId) &oModifiedExtensions);

  /**
  * Check if an extension is modified
  * @param iExtensionName : the name of the extension
  * @param iLevel : The level - global or differential - of the researched status
  * @param oStatus : the status of the extension (created or deleted, or null if no change occured)
  * @return
  *    S_OK if extension status was retrieved
  *    E_FAIL if extension status could not be retrieved
  */
  HRESULT IsExtensionModified(const CATPLMTypeId & iExtensionType, CATTosTodoLevel iLevel, CATPLMComponentExtensionLogStatus & oStatus);


  //Typing, obsolete, use directly CATPLMTypeH
  HRESULT IsAKindOf(const CATPLMTypeH& iReferenceType) const;
  HRESULT IsAKindOf(const CATPLMTypeH& iReferenceType, CATBoolean) const;
  HRESULT GetPLMType(CATPLMTypeId & oTypeReference) const;
  HRESULT GetTypeH(CATPLMTypeH & ioTypeH)const;

  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  //
  //   Editability
  //
  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


  /**
  * GetEditability
  *
  * @param oEditability
  *   The Editability
  *
  * @return
  *      S_OK    if request succeeded <br>
  *      S_FALSE if request succeeded but CatAdpEditability_Undefined  <br>
  *      E_FAIL  if request failed <br>
  */
  HRESULT  GetEditability(CATAdpEditability & oEditability) const;

  /**
  * FindAlreadyAssociatedComponentObject
  *
  * @param iCATIOmbComponentObject
  *    master/slave representant in client session of a database object.
  *    Object should adhere to CATIComponent or CATIOmbComponentObject
  *
  *  @param ioHandle
  *    Handle
  *
  *  @param iWithCATIOmbComponentObject
  *    With CATIOmbComponentObject helpers if needed
  *
  * @return
  *      S_OK if request succeeded and Object is identified as a Valid <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT  FindAlreadyAssociatedComponentObject(CATBaseUnknown* iCATIOmbComponentObject, CATComponentId& ioHandle, CATBoolean iWithCATIOmbComponentObject = TRUE);



  /**
* Query associated object in session for a given Interface
*  1) Dedicated to simple component associated to object with definition
*  2) Does not work for Complex Cell
*
* @param iIID
*   The IID associated to the request
*
* @param oPPV [out, CATBaseUnknown#Release]
*   associated value of representation.
*
* @param iFilter
*   Filtering on status of associated object in session.
*
* @return
*   S_OK if request succeeded <br>
*   E_PENDING if component is not in session <br>
*   E_ACCESSDENIED if component is not compatible with filter <br>
*   E_NOINTERFACE if component is in session but QueryInterface failed <br>
*   E_INVALIDARG if invalid parameters <br>
*/
  HRESULT QueryObjectInSession(const IID &iIID, void **oPPV, const CATTosQuery_Filter & iFilter = CatTosQuery_OnlyActivatedInSession) const;
  CATOmxSR<CATBaseUnknown> QueryObjectInSession(CATTosQuery_Filter iFilter = CatTosQuery_OnlyActivatedInSession) const;

  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  //
  //     Logical Family
  //
  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  /**
  * Checks if components belongs to the same logical family
  * (Is working only with simple handles)
  *
  * @param iCID
  *        handle to compare with
  *
  * @return
  *    S_OK    : if succeeded and logical family is the same
  *    S_FALSE : if succeeded and logical family is different
  *    E_FAIL  : if failure
  */
  HRESULT HasSameLogicalFamily(const CATComponentId & iToCompare) const;

  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
//     Minor Family
//
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

/**
* Checks if components belongs to the same minor family (components with same MajorId).
* Is working with simple and complex handles.
*
* @param iCID
*        handle to compare with
*
* @return
*    S_OK    : if succeeded and length and majorIds are the same
*    S_FALSE : if succeeded and length or majorIds are differents
*    E_FAIL  : if failure
*/
  HRESULT HasSameMinorFamily(const CATComponentId & iToCompare) const;

  /**
  * Visit a minor family from a single component according to filter
  *
  * @param iVisitor
  *        A visitor on the components that may be present or not
  * @param iFilter
  *        Criteria of search
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT VisitMinorFamily(CATComponentIdVisitor      & iVisitor,
    const CATTosQuery_Filter   & iFilter = CatTosQuery_OnlyActivatedInSession) const;

  /**
  * IsValidForUsage :
  *    it means CID is associated to an already persisted object in Repository/Database
  *    it is a kind of filter to exclude created object in memory cache not yet saved once
  *
  * @param oValidForUsage
  *
  *      TRUE  if Value of identification is valid in repository, meaning :
  *                1) it has been given from Query/Expand/Open
  *                2) it has been saved, comitted in repository and validated back in client side
  *
  *      FALSE if it correspond to a dummy identification
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT IsValidForUsage(CATBoolean & oValidForUsage) const;

  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  //
  //     Complex Cell Management
  //
  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  /**
  * detection of Complex Cell management
  *
  * @param oComplex
  *    Complexity Status
  *      TRUE  if Component is Complex identified<br>
  *      FALSE if Component is simple identified<br>
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT IsComplex(CATBoolean     & oComplex) const;

  /**
  * Get Elementary ID Path Depth
  *
  * @param oDepth
  *        Depth of the elementary path
  *
  * @return
  *      ==0 : if request failed <br>
  *      !=0 : if request succeeded <br>
  */
  unsigned int GetElementaryPathDepth() const;

  /**
  * Get Elementary ID Path
  *
  * @param oNodes
  *    List of simple Cell
  *
  * @return
  *      S_OK    if request succeeded <br>
  *      S_FALSE if request succeeded <br>
  *      E_FAIL  if request failed <br>
  */
  HRESULT GetElementaryPath(CATOmxArray<CATComponentId> & oNodes) const;
  CATOmxArray<CATComponentId> GetPath() const;

  /**
  * Get last path element
  *
  * @param oNodes
  *    List of simple Cell
  *
  * @return
  *      S_OK    if request succeeded <br>
  *      S_FALSE if request succeeded <br>
  *      E_FAIL  if request failed <br>
  */
  HRESULT GetLastPathElement(CATComponentId & oLastPathElement) const;

  /**
* Get last path element - this API takes into account the overload of the cell if it exists.
*
* @param oNodes
*    List of simple Cell
*
* @return
*      S_OK    if request succeeded <br>
*      S_FALSE if request succeeded <br>
*      E_FAIL  if request failed <br>
*/
  HRESULT GetLastPathElementOrOOD(CATComponentId & oLastPathElement) const;

  /**
  * Visit Elementary ID Path
  *
  * @param iVisitor
  *    The object visiting path content
  *
  * @return
  *      S_OK    if request succeeded <br>
  *      S_FALSE if request succeeded <br>
  *      E_FAIL  if request failed <br>
  */
  HRESULT VisitElementaryPath(CATComponentIdVisitor & iVisitor) const;

  /**
  * Visit Elementary ID Path - this API takes into account the overload of the cell if it exists.
  *
  * @param iVisitor
  *    The object visiting path content
  *
  * @return
  *      S_OK    if request succeeded <br>
  *      S_FALSE if request succeeded <br>
  *      E_FAIL  if request failed <br>
  */
  HRESULT VisitElementaryPathOrOOD(CATComponentIdVisitor & iVisitor) const;

  /**
   * IsLoaded :
   *
   * @param oLoaded
   *      TRUE  if associated (one or path) implementation(s) in session
   *      FALSE otherwise
   *
   * @return
   *      S_OK if request succeeded <br>
   *      E_FAIL if request failed <br>
   */
  HRESULT IsLoaded(CATBoolean & oLoaded) const;

  /** same as previous one, returns S_FALSE, S_OK or failure*/
  HRESULT IsLoaded() const;

  /**
  * Get Object Path
  */
  HRESULT GetObjects(CATListValCATBaseUnknown_var & oPath, CATBoolean iAllowPartialResult = FALSE) const;


  /**
  * Find Handle From Objects
  *  The service is very restrictive about input conditions :
  *    1/ you may check that correct manipulations are made on implementation enabled to be indexed
  *           with preventive CATIOmbComponentObject@GetComponent Interface
  *    2/ you may check that previous object is currently engaged with
  *           a session associative structure CATComponentId::Get(.., CID &)
  *  The service is rather lazzy about integrity check of outputs
  *    a/ Only redondant inputs are checked
  *    b/ with Reference-Owner of two successive Instances are Checked
  *
  * @param iPathObjects
  *    List of entities
  *
  * @param oCID
  *    Resulting handle
  *
  * @return
  *      S_OK    if request is a complete success<br>
  *      E_FAIL  if request failed <br>
  */
  static HRESULT FindFromObjects(const CATListValCATBaseUnknown_var & iPathObjects, CATComponentId& oCID);

  /**
  * GetComplexId
  *  The service is very restrictive about input conditions
  *
  * @param iSimples
  *    Input path of simple ID
  *
  * @param oComplex
  *   Output resulting equivalent Path
  *
  * @return
  *      S_OK if request succeeded (valuated, same depth of definition and same value) <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT GetComplexId(const CATOmxArray<CATComponentId> & iSimples, CATComponentId& oComplex);


  /**
  * Get the PLM Reference
  *  Instance-Reference Navigation
  *
  * @param oReference
  *        The PLM Reference
  *
  * @return
  *      S_OK      if request succeeded with reference<<br>
  *      S_FALSE   if request succeeded without reference<br>
  *      E_PENDING if the data necessary to complete this operation is not yet available<br>
  *      E_FAIL    if request failed <br>
  */
  HRESULT IsInstanceOf(CATComponentId &oReference) const;
  CATComponentId GetTo() const;

  /**
   * From a reference/rep reference/entity, retrieve instances/rep instances/relations which has their to/V_IsInstanceOf connected to this object
   * Be aware that although former wrong documentation stated the contrary it does return relations (even connected to a reference)
   * @param iCoreTypeMask:
   *   @see TYPTRP_* values in CATPLMTypeToolsDefinitions
   *   it is TYPTRP_Component by default (meaning anything)
   *   in order to filter relations, set iCoreTypeMask to TYPTRP_Instance|TYPTRP_RepInstance (for example)
   * @param iIncludeNotLoadedComponents:
   *   if FALSE (default) not loaded instances will not be returned
   *   Warning: Initial name was "iSearchDestroyedComponents"
   */
  HRESULT WhereInstanciated(CATListValCATComponentId& oListInstances, CATBoolean iIncludeNotLoadedComponents = FALSE) const;
  HRESULT VisitWhereInstanciated(CATComponentIdVisitor& iVisitor, CATBoolean iIncludeNotLoadedComponents = FALSE) const;
  HRESULT ListInstances(CATOmxArray<CATComponentId>& oListInstances, int iCoreTypeMask = TYPTRP_Component, CATBoolean iIncludeNotLoadedComponents = FALSE) const;
  HRESULT VisitInstances(CATComponentIdVisitor& iVisitor, int iCoreTypeMask = TYPTRP_Component, CATBoolean iIncludeNotLoadedComponents = FALSE) const;

  /**
  * Get the PLM Owner
  *  Ownership Navigation
  *
  * @param oPLMOwner
  *        The PLM Owner
  *
  * @return
  *      S_OK      if request succeeded with owner<<br>
  *      S_FALSE   if request succeeded without owner<br>
  *      E_PENDING if the data necessary to complete this operation is not yet available<br>
  *      E_FAIL    if request failed <br>
  */
  HRESULT HasPLMOwner(CATComponentId &oPLMOwner) const;
  CATComponentId GetFrom() const;

  enum AggregatedComponentType {
    Instances = 1,
    Ports = 2,
    Connections = 4,
    InstancesAndPorts = 3,
    InstancesAndConnections = 5,
    PortsAndConnections = 6,
    Everything = 7,
    Relations = 8
  };

  /**
  * Has Aggregated Components
  *  Ownership Navigation
  *
  *  Search direct PLM Components (Instances, Ports, Connections) aggregated under this object in session
  *  Should work for associated Reference.
  *
  * @param opListComponents
  *  list of "PLMComponents" found in session<br>
  *
  * @return
  *  S_OK  if request succeeded <br>
  *  E_FAIL if the object is not a reference <br>
  */
  HRESULT HasAggregatedComponents(CATLISTV(CATComponentId) &opListComponents, AggregatedComponentType iType = Everything, CATBoolean iSearchDestroyedComponents = FALSE) const;

  /**
  * Visit Aggregated components
  *  Ownership Navigation
  *
  *  Search direct PLM Components (Instances, Ports, Connections) aggregated under this object in session
  *  Should work for associated Reference.
  *
  * @param iVisitor
  *    The object visiting aggregated components according to filters
  *
  * @param iType
  *    Specified the PLM type filter
  *
  * @param iSearchDestroyedComponents
  *    Specified if deleted must be taken into account
  *
  * @return
  *    S_OK    if request succeeded <br>
  *    E_FAIL  if request failed <br>
  */
  HRESULT VisitAggregatedComponents(CATComponentIdVisitor & iVisitor,
    AggregatedComponentType iType = Everything,
    CATBoolean iSearchDestroyedComponents = FALSE) const;

  /**
  * Visit Aggregated components
  *  Ownership Navigation
  *
  *  Search direct PLM Components (Instances, Ports, Connections) aggregated under this object in session
  *  Should work for associated Reference.
  *
  * @param iVisitor
  *    The object visiting aggregated components according to filters
  *
  * @param iType
  *    Specified the PLM type filter
  *
  * @param iSearchDestroyedComponents
  *    Specified if deleted must be taken into account
  *
  * @return
  *    S_OK    if request succeeded <br>
  *    E_FAIL  if request failed <br>
  */
  HRESULT VisitAggregatedComponents(CATComponentIdVisitor & iVisitor, CATPLMAggregationFilter * iFilter) const;

  /**
  * Visit Pointing components
  *  Semantical Relations Navigation
  *
  * @param iVisitor
  *    The object visiting pointed components
  * @param iFilter
  *    The filter on pointing relations
  *
  * @return
  *    S_OK    if request succeeded <br>
  *    E_FAIL  if request failed <br>
  */
  HRESULT VisitPointingComponents(CATComponentIdVisitor & iVisitor, CATPLMRelationFilter * iFilter = 0) const;

  /**
  * Visit Pointing relations
  *  Semantical Relations Navigation
  *
  * @param iVisitor
  *    The object visiting pointing relations
  * @param iFilter
  *    The filter on pointing relations
  *
  * @return
  *    S_OK    if request succeeded <br>
  *    E_FAIL  if request failed <br>
  */
  HRESULT VisitInverseRelations(CATRelationIdVisitor & iVisitor, CATPLMRelationFilter * iFilter = 0) const;

  /**
  * Visit Pointed components
  *  Semantical Relations Navigation.
  *  WARNING, if relations are pointing in context, the visitor will be called on complex path.
  *  (TODO : add parameters for exploding complex path)
  *
  * @param iVisitor
  *    The object visiting pointed components
  * @param iFilter
  *    The filter on relations
  *
  * @return
  *    S_OK    if request succeeded <br>
  *    E_FAIL  if request failed <br>
  */
  HRESULT VisitPointedComponents(CATComponentIdVisitor & iVisitor, CATPLMRelationFilter * iFilter = 0) const;

  /**
  * Visit Pointed relations
  *  Semantical Relations Navigation
  *
  * @param iVisitor
  *    The object visiting pointed relations
  * @param iFilter
  *    The filter on relations
  *
  * @return
  *    S_OK    if request succeeded <br>
  *    E_FAIL  if request failed <br>
  */
  HRESULT VisitRelations(CATRelationIdVisitor & iVisitor, CATPLMRelationFilter * iFilter = 0) const;

  /** deprecated, unspecified/meaningless return code, unspecified/meaningless output, use GetAlias*/
  HRESULT HasAlias(CATUnicodeString &oAlias);

  /**
   * Retrieve the "alias" of a PLM component
   * this alias should look like the name displayed in GUI, however the result is modeler/application dependant (most of the time CATIAlias::GetAlias)
   * If the component is loaded
   *   the computation is delegated to the modeler
   * Else (for example destroyed object, unloaded object, target of an unresolved SR etc...)
   *   If a "cache" has been stored on this object (this cache existance depends on complex circumstances and it is likely that no cache is available)
   *     Then the alias if recomputed from this cache using GUI services (which behavior is undefined)
   *     Notice that this cache contains a probably OBSOLETE state of the object, therefore the result is theoretically wrong.
   *     However this result can be useful for end user to identify an object.
   *
   * for a "path" object, the result is the concatenation of the components aliases separated by "/"
   *
   * @return:
   *   S_OK: success and alias comes loaded components
   *   S_FALSE: success, but alias comes (entirely or partially) from cache
   *   E_XXX: failure, notice that for "path", if output is non empty, it contains at least on valid "alias" (the rest being filled with "???")
   */
  HRESULT GetAlias(CATUnicodeString& oAlias) const;

  HRESULT IsUIDisplayable(CATBoolean & oUIDisplayable) const;


  /**
   * @see CATPLMID::GetRepositoryName
   */
  HRESULT GetTypeOfRepository(CATPLMRepositoryName & oTargetRepository) const;


  /** @nodoc */
  unsigned int GetVolatileLabel() const;

  /**
  * GetPLMID
  *
  * @param oPLMID
  *    Output PLMID
  *
  * @param isValidForUsage
  *    @see: CATPLMID::IsValidForRemoteUsage
  *    WARNING: default value is TRUE, meaning that if this object does not come (or has not been saved into) provider, the return code will be E_FAIL
  */
  HRESULT GetPLMID(CATPLMID  & oIdentified, const CATBoolean isValidForUsage = TRUE) const;

  /** same as CATPLMID with isValidForUsage=FALSE, returns empty PLMID in case of error*/
  CATPLMID GetPLMID() const;

  /** @nodoc */
  HRESULT Dump(CATTrace &iTrace) const;

  /**
   * Returns the functional name attached to this component if it exists
   */
  HRESULT HasFunctionalName(CATUnicodeString &oName);

  /**
  * Create an association between this proxy and the object representing the component in session
  */
  HRESULT AssociateEntity(CATBaseUnknown * iCBU) const;

  /**
  * Remove the association between this proxy and the object representing the component in session
  */
  HRESULT FinalizeInSession()  const;

  /**
  * Check space category
  */
  CATBoolean IsSpaceCategoryMatching(CATProxySpaceCategory iCategoryMask) const;

  /** obsolete*/
  HRESULT SetEligibleForVDescriptionStreaming();
  CATBoolean IsEligibleForVDescriptionStreaming();


  /**
  * Get the associated ActionId
  * @return
  *   S_OK if valuated
  *   S_FALSE if not valuated
  *   E_FAIL otherwise
  */
  HRESULT GetActionId(CATPLMID  & oActionId);

  /**
  * Determine if the given PLM type matched a core behavior.
  * <br><b>Role:</b>This method enables to determine if the PLM type matched a core behavior.
  *
  * @param iCoreTypesDefinition [in]
  * A context for analysis: can be a combination of (TYPTRP_Reference, TYPTRP_RepReference, TYPTRP_Entity, TYPTRP_Relation, TYPTRP_Instance, TYPTRP_RepInstance, TYPTRP_Connection, TYPTRP_Port).
  * @see CATPLMTypeToolsDefinitions.h
  *
  * @return
  * <ul>
  * <li><tt>S_OK</tt> if the PLM type matches the given behavior.</li>
  * <li><tt>S_FALSE</tt> if the PLM type does not match the given behavior.</li>
  * <li><tt>E_XXX</tt> if an error occured during the treatment.</li>
  * </ul>
  */
  HRESULT IsMatchingCoreBehavior(int iCoreTypesDefinition) const;

  /** @nodoc */
  CATBoolean IsFrozen() const;
  CATBoolean IsMajorIdErasedForConfig() const;
  CATBoolean IsClipCell() const;
  void       SetOpenedFromOfflineRepository();
  CATBoolean IsOpenedFromOfflineRepository() const;


  /**
  * @deprecated V6R216
  * @use CATOmxArray signature instead
  */
  static HRESULT GetComplexId(const CATLISTV(CATComponentId)& iSimples, CATComponentId& oComplex) { return GetComplexId(ToInternalWorld(iSimples), oComplex); }

  HRESULT GetElementaryPath(CATLISTV(CATComponentId) & oNodes) const;

private:

  /*
  CATPLMLinksUI\CATPLMLinksImpacts.m\src\CATPLMLinksImpactsManager.cpp
  CATPLMLinksUI\CATPLMLinksInfra.m\src\CATPLMLinksInfraServices.cpp
  CATPLMLinksUI\CATPLMLinksInfra.m\src\CATPLMPrivateLinkImpl.cpp
  CATPLMLinksUI\CATPLMSRGraph.m\src\CATESRGraphDocument.cpp
  CATPLMLinksUI\CATPLMLinksUI.m\src\CATPLMELLinksLine.cpp
  CATPLMLinksUI\CATPLMLinksUI.m\src\CATPLMELPreferredActionDeleteComponent.cpp
  CATPLMLinksUI\CATPLMLinksUI.m\src\CATPLMELRelationTreeListViewer.cpp
  CATPLMLinksUI\CATPLMLinksImpacts.m\src\CATPLMLinksImpactsManager.cpp
  CATPLMLinksUI\CATPLMLinksInfra.m\src\CATPLMPrivateLinkImpl.cpp
  CATPLMLinksUI\CATPLMSRGraph.m\src\CATESRGraphDocument.cpp
  CATPLMLinksUI\CATPLMLinksUI.m\src\CATPLMELLinksLine.cpp
  CATPLMLinksUI\CATPLMLinksUI.m\src\CATPLMELPreferredActionDeleteComponent.cpp
  CATPLMLinksUI\CATPLMLinksUI.m\src\CATPLMELRelationTreeListViewer.cpp
  CATPLMLinksUI\CATPLMLinksUI.m\src\CATPLMEditLinksWnd.cpp
  CATPLMLinksUI\CATPLMLinksUI.m\src\CATPLMELRerouteManager.cpp
  CATPLMLinksUI\CATPLMLinksUI.m\src\CATPLMLinksCommand.cpp
  */

  friend class CATPLMLinksImpactsManager;
  friend class CATPLMLinksInfraServices;
  friend class CATPLMPrivateLinkImpl;
  friend class CATESRGraphDocument;
  friend class CATPLMELLinksLine;
  friend class CATPLMELPreferredActionDeleteComponent;
  friend class CATPLMELRelationTreeListViewer;
  friend class CATPLMLinksImpactsManager;
  friend class CATPLMPrivateLinkImpl;
  friend class CATESRGraphDocument;
  friend class CATPLMELLinksLine;
  friend class CATPLMELPreferredActionDeleteComponent;
  friend class CATPLMELRelationTreeListViewer;
  friend class CATPLMEditLinksWnd;
  friend class CATPLMELRerouteManager;
  friend class CATPLMLinksCommand;
  friend class CATOxiOOD;

  /**
  * @deprecated V6R214
  * @use CATPLMIdentificationAccess.CATPLMTypeDescriptor#IsKindOf
  */
  HRESULT HasSameCoreType(const CATPLMTypeId & iReferenceType) const;

  /**
  * @deprecated V6R214
  * @use CATPLMIdentificationAccess.CATPLMTypeDescriptor#IsKindOf
  */
  HRESULT HasSameCoreType(const CATComponentId & iReferenceCID) const;

  /**
  * @deprecated V6R214
  * @use CATPLMIdentificationAccess.CATPLMTypeDescriptor#IsKindOf
  */
  HRESULT HasSameModeler(const CATPLMTypeId & iReferenceType) const;

  /**
  * @deprecated V6R214
  * @use CATPLMIdentificationAccess.CATPLMTypeDescriptor#IsKindOf
  */
  HRESULT HasSameModeler(const CATComponentId & iReferenceCID) const;

  /**
  * @deprecated V6R214
  * @use IsMatchingSuperTypes(const CATPLMTypeHArray & iTypeFilter)
  */
  CATBoolean IsMatchingSuperTypes(const CATLISTV(CATPLMTypeId) & iTypeFilter) const;

  /**
  * @deprecated V6R214
  * @use CATPLMIdentificationAccess.CATPLMTypeDescriptor#IsKindOf
  */
  HRESULT GetPLMCoreType(CATPLMCoreType & oCoreType) const;

  /**
  * @deprecated V6R214
  * @use CATPLMIdentificationAccess.CATPLMTypeDescriptor#IsKindOf
  */
  CATBoolean IsMatchingCoreTypes(CATPLMCoreTypeFilter iTypeFilter) const;

private:

  friend class CATOmbRestrictedServicesForPLMCore2;
  friend class CATosUINeededCriteria;
  friend class CATOxSearchResult;
  friend class CATOmbVOSnapshotFactoryAdapter;
  HRESULT  QueryPersistentUnit(const IID &iIID, void **oPPV) const;
  void *InsertVOSnapshot(CATIOmbVOSnapshotAbstract *ipVOSnapshotAbstract);
  void *LocateVOSnapshot(CATIOmbVOSnapshotAbstract *ipVOSnapshotAbstract);
  friend class CATAdpRestrictedELRAccessImpl_PortsOwnersAliasesManager; // to be removed
  friend class CATAdpRestrictedELRAccessImpl_ComponentsAliasesManager;
  friend class CATOxiAliasServices;
  HRESULT CaptureAlias(CATLISTV(CATString) & iAttributeIds, CATLISTV(CATUnicodeString) & iAttributeValues); // delete before end O7/2015, replaced by KeyValueBlock.
  HRESULT CaptureAlias(const CATOmxKeyValueBlock & iAttributes);
public:
  inline CATOxJanus * GetUsage() const { return _ImplUsage; }
  CATOxEntity* GetSimple() const;

  void SetUsage(CATOxJanus * iJanus);

private:
  CATOxJanus* _ImplUsage;
};





#endif
