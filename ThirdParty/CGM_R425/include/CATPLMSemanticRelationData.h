#ifndef CATPLMSemanticRelationData_H
#define CATPLMSemanticRelationData_H

/**
* @level Private
* @usage U3
*/

// BSFBuildtimeData
#include "CATIAV5Level.h"
// SpecialAPI
#include "CATDataType.h"
#include "CATSysErrorDef.h"
// System
#include "CATBinary.h"
#include "CATCollec.h"
#include "CATUnicodeString.h"
// SystemTS
#include "IUnknown.h"
// ObjectModelerCollection
#include "CATOmxArray.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxDeprecated.h"
#include "CATOmxOHMap.h"
#include "CATOmxSR.h"
// CATPLMIdentificationAccess
#include "CATLISTV_CATPLMSemanticRelationData.h"
#include "CATLISTV_CATPLMSynchronizationDomains.h"
#include "CATPLMIdentificationAccess.h"
#include "CATSemanticRelationMetaData.h"
#include "CATPLMIdentificationAccessHRESULT.h"

class CATString;
class CATBinary;
class CATTrace;
class CATComponentId;
class CATOmxAny;
class AllLevelsIdByAttr;
class CATPLMSynchronizationDomainDatas;
class SharedSRD;
class CATSemanticRelationMetaData;
class CATPLMSemanticRelationPrivateData;
class CATPLMTypeH;
template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMTypeH>::manager();
class CATOmxKeyValueBlock;
template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmxKeyValueBlock>::manager();

/**
 * This class holds
 * + all attributes held by "SemanticRelation":
 *   IDRel: unique identifier of the SR in the context of its
 *   pathid: M1 unique identifier for PathType's
 *   Role
 *   Semantics: aka "category"
 *   AppIndex: relative order of the SR (optional)
 *   PrivateData: a BLOB (check CATPLMSemanticRelationPrivateData)
 *
 * + synchronization stamps
 *     normally update stamps but it can be other attributes in which case the it uses the despicable CATListCATPLMSynchronizationDomains (see SRonAttribute extension of SemanticRelation)
 *
 * +  synchronization status
 *    computed client side (not genuine persistent data)
 *
 *  + SR extensions
 *
 * Be warned that this class uses enveloppe/letter but lacks a COW mechanism
 * The consequence is that when you update a CATPLMSemanticRelationData, unless building it from scratch, you are probably doing a side-effect on an other user of the same letter.
 * CATPLMSemanticRelationData source ...;
 * CATPLMSemanticRelationData copy{source};
 * copy.SetXXX(yyy);
 * => source is also modified !
 */
class ExportedByCATPLMIdentificationAccess CATPLMSemanticRelationData
{
public:
  /**
  * standard constructors & operators
  */
  CATPLMSemanticRelationData() = default;
  CATPLMSemanticRelationData(const CATPLMSemanticRelationData&) = default;
  CATPLMSemanticRelationData& operator=(const CATPLMSemanticRelationData&) = default;
  CATPLMSemanticRelationData(CATPLMSemanticRelationData&&) = default;
  CATPLMSemanticRelationData& operator=(CATPLMSemanticRelationData&&) = default;
  ~CATPLMSemanticRelationData() = default;

  /**
  * @param iIDrel
  *        Relation's identifier.
  * @param iCategory
  *        System attribut of the category. Declared in RELATION_ENUMS.metadata.
  * @param iRole
  *        System attribut of the role. Declared in RELATION_ENUMS.metadata.
  * @param iPathLength
  *        Path length is equal to the size of the associated ComponentId.
  * FOR GOD SAKE, PLEASE DO NOT ADD YET ANOTHER CONSTRUCTOR
  */
  CATPLMSemanticRelationData(unsigned int iIDrel, const CATSemanticRelationMetaData& iSRMD, unsigned int iPathLength, unsigned int iAppIndex = 0);
  CATPLMSemanticRelationData(unsigned int iIDrel, const CATUnicodeString& iType, const CATUnicodeString& iCategory, const CATUnicodeString& iRole, unsigned int iPathLength, unsigned int iAppIndex = 0);
  CATPLMSemanticRelationData(unsigned int iIDrel, const CATUnicodeString&  iCategory, const CATUnicodeString& iRole, unsigned int iPathLength, unsigned int iAppIndex = 0);
  CATPLMSemanticRelationData(unsigned int iIDrel, const CATSemanticRelationMetaData & iSRMD, unsigned int iPathLength, const CATBinary& iPrivateData, unsigned int iAppIndex = 0);
  CATPLMSemanticRelationData(unsigned int iIDrel, const CATUnicodeString& iCategory, const CATUnicodeString& iRole, unsigned int iPathLength, const CATBinary& iPrivateData, unsigned int iAppIndex = 0);

  /**
   * "SRV3"
   * this is not an enhanced version of "SRV2" (whatever that is) but a CATPLMSemanticRelationData with small subset of its attributes
   * using those constructors (which differ for the others constructors only by parameter orders...) you will obtain a CATPLMSemanticRelationData
   * for which a good share of the methods will fail...stay away !
   * FOR GOD SAKE, PLEASE DO NOT ADD YET ANOTHER CONSTRUCTOR
   */
  CATPLMSemanticRelationData(unsigned int iPathLength, unsigned int iIDrel, const CATSemanticRelationMetaData & iSRMD);
  CATPLMSemanticRelationData(unsigned int iPathLength, unsigned int iIDrel, const CATUnicodeString& iType, const CATUnicodeString& iCategory, const CATUnicodeString& iRole);
  CATPLMSemanticRelationData(unsigned int iPathLength, unsigned int iIDrel, const CATUnicodeString& iCategory, const CATUnicodeString& iRole);
  CATBoolean IsSlimSR() const;

  /**
  * valuated'ness
  */
  inline explicit operator bool() const { return _Shared != nullptr; }
  inline int operator!() const { return _Shared == nullptr; }


  /**
  * Compare content excluding pathid, zombie alias and SynchroStatus
  */
  HRESULT PartialCompare(const CATPLMSemanticRelationData & iToCompare) const;

  /** obsolete */
  inline HRESULT IsSafe() const { return _Shared ? S_OK : E_FAIL; }

  OMX_DEPRECATED("not implemented")  HRESULT Dump(CATTrace &iTrace) { return E_NOTIMPL; }

  /**
  * Dump content
  */
  HRESULT GetUnicodeDump(CATListOfCATUnicodeString& LUS) const;


  /** retrieve IDRel and {role, category} */
  HRESULT GetSemanticsN(unsigned int& oIDrel, CATSemanticRelationMetaData & oSRMD) const;
  HRESULT GetSemanticsN(unsigned int& oIDrel, CATUnicodeString& oTypeID, CATUnicodeString& oCategory, CATUnicodeString& oRole) const;
  HRESULT GetSemantics(unsigned int& oIDrel, CATUnicodeString& oCategory, CATUnicodeString& oRole) const
  {
    CATUnicodeString unused;
    return GetSemanticsN(oIDrel, unused, oCategory, oRole);
  }

  /** retrieve functional name (extracted from PrivateData) */
  HRESULT GetSemanticsN(unsigned int& oIDrel, CATSemanticRelationMetaData & oSRMD, CATUnicodeString& oFunctionalName) const;
  HRESULT GetSemanticsN(unsigned int& oIDrel, CATUnicodeString& oType, CATUnicodeString& oCategory, CATUnicodeString& oRole, CATUnicodeString& oFunctionalName) const;
  HRESULT GetSemantics(unsigned int& oIDrel, CATUnicodeString& oCategory, CATUnicodeString& oRole, CATUnicodeString& oFunctionalName) const;


  OMX_DEPRECATED("use GetZombieAlias") HRESULT GetSemantics(unsigned int& oIDrel, CATUnicodeString& oCategory, CATUnicodeString& oRole, CATUnicodeString& oFunctionalName, CATBinary&) const
  {
    return GetSemantics(oIDrel, oCategory, oRole, oFunctionalName);
  }
  OMX_DEPRECATED("use GetZombieAlias") HRESULT GetSemanticsN(unsigned int& oIDrel, CATUnicodeString& oType, CATUnicodeString& oCategory, CATUnicodeString& oRole, CATUnicodeString& oFunctionalName, CATBinary&) const
  {
    return GetSemanticsN(oIDrel, oCategory, oRole, oFunctionalName);
  }


  /** retrieve SemanticRelation.IDRel (or 0) */
  unsigned int GetIDRel() const;


  /** retrieve metadata (type which empty, role, category) */
  HRESULT GetTypeID(CATUnicodeString& oTypeID) const;
  HRESULT GetRoleID(CATUnicodeString& oRole) const;
  HRESULT GetCategoryID(CATUnicodeString& oCategory) const;
  HRESULT GetRoleAndCategory(CATUnicodeString& oRole, CATUnicodeString& oCategory) const;
  HRESULT GetSemanticRelationMetaData(CATSemanticRelationMetaData & oSRMD) const;


  /** return the length of the target path */
  HRESULT GetPathLength(unsigned int& oPathLength) const;

  /**
  * SynchroStamp property. Declared if SynchroStamp must be taken into account when synchroStatus is computed
  */
  enum TsProperty
  {
    relevant = 0,
    not_relevant = 1,
    not_computed = 2
  };

  /**
  * Valuates SynchroStamp value & Property for a given index
  *
  * @param iIndex
  *        index start at 0 and ends at GetPathLength -1.
  * @param iProp
  *        The SynchroStamp property.
  * @param iSynchroStamp
  *        The SynchroStamp value (UpdateStamp of the pointed object).
  *        (Supported kind : omx_void, omx_int, omx_uuid)
  * @return
  *        S_OK   : if succeeded
  *        E_FAIL : unsafe or index out of bounds
  */
  inline HRESULT SetIndexedSynchInfo(unsigned int iIndex, TsProperty iProp, const CATOmxAny & iSynchroStamp) { return SetIndexedSynchInfo(iIndex, iProp, const_cast<CATOmxAny&>(iSynchroStamp)); }
  HRESULT SetIndexedSynchInfo(unsigned int iIndex, TsProperty iProp, CATOmxAny& iSynchroStamp);

  /**
  * Returns Timestamp value and property for a given index
  *
  * @param iIndex
  *        index start at 0 and ends at GetPathLength -1.
  * @param oProp
  *        The Ts property.
  * @param oSynchroStamp
  *        The TS value.
  *        (Supported kind : omx_void, omx_int, omx_uuid)
  *
  * @return
  *        S_OK   : if succeeded
  *        E_PARTIAL_SR : specific to SRv3. No link on attribute on SRv3. Need to relaunch a query on server to retrieve a SRv1 or SRv2 and know if there is (or not) a link on attribut
  *        E_FAIL : unsafe or index out of bounds
  */
  HRESULT GetIndexedSynchInfo(unsigned int iIndex, TsProperty & oProp, CATOmxAny & oSynchroStamp) const;

  enum SynchroStatus
  {
    NotValuated = 0,              /* Status not available                                                                                                                 */
    Synch = 2,                    /* Build target is solved and Synchronized                                                                                              */
    Unsynch = 3,                  /* Build target is solved and Unsynchronized                                                                                            */
    Broken = 1,                   /* Sensitive relation has a broken build target : Binding is no more possible                                                           */
    Broken_UnAccessibleFamily = 6,/* Unsensitive relation has a broken build target, and family is unaccessible too. Binding is no more possible.                         */
    Broken_AccessibleFamily = 7,  /* Unsensitive relation has a broken build target, but family is still accessible. Binding is still possible with an equivalent target. */
    OutOfScope = 4,               /* Relation is inconsistent : Pointed object is out of scope due to duplicate operation                                                 */
    InconsistentOccurrence = 5    /* Relation is inconsistent : Pointed occurrence is Inconsistent due to a transfert in a workspace                                      */
  };


  /**
  * Valuates synchronization status for a given index
  *
  * @param iIndex
  *        index start at 0 and ends at GetPathLength -1.
  * @param iStatus
  *        The Synchro status.
  * @return
  *        S_OK   : if succeeded
  *        E_FAIL : unsafe or index out of bounds
  */
  HRESULT SetIndexedSynchroStatus(unsigned int iIndex, SynchroStatus iStatus);

  /**
  * Returns synchronization status for a given index
  *
  * @param iIndex
  *        index start at 0 and ends at GetPathLength -1.
  * @param oStatus
  *        The Synchro status.
  * @return
  *        S_OK   : if succeeded
  *        E_PARTIAL_SR : specific to SRv3. No link on attribute on SRv3. Need to relaunch a query on server to retrieve a SRv1 or SRv2 and know if there is (or not) a link on attribut
  *        E_FAIL : unsafe or index out of bounds
  */
  HRESULT GetIndexedSynchroStatus(unsigned int iIndex, SynchroStatus & oStatus) const;

  enum DomainSynchroStatus
  {
    DomainNotValuated = 0,   /* Status not available  */
    DomainNotComputed = 4,
    DomainSynch = 2,         /* Synchronized */
    DomainUnsynch = 3,       /* Unsynchronized */
    DomainBroken = 1
  };

  /**
  * Valuates synchronization status for a given index
  *
  * @param iIndex
  *        index start at 0 and ends at GetPathLength -1.
  * @param iStatus
  *        The Synchro status.
  * @return
  *        S_OK   : if succeeded
  *        E_FAIL : unsafe or index out of bounds
  */
  HRESULT SetIndexedSynchroStatusForSynchronizationDomain(unsigned int iDomainIndex, DomainSynchroStatus iStatus);

  /**
  * Returns synchronization status for a given index
  *
  * @param iIndex
  *        index start at 1 and ends at CountSynchronizationDomains.
  * @param oStatus
  *        The Synchro status.
  * @return
  *        S_OK   : if succeeded
  *        E_PARTIAL_SR : specific to SRv3. No link on attribute on SRv3. Need to relaunch a query on server to retrieve a SRv1 or SRv2 and know if there is (or not) a link on attribute
  *                  oStatus=DomainNotComputed
  *        E_FAIL : unsafe or index out of bounds (oStatus=DomainNotValuated)
  */
  HRESULT GetIndexedSynchroStatusForSynchronizationDomain(unsigned int iDomainIndex, DomainSynchroStatus & oStatus) const;

  /**
  * Streams object in a binary format
  * @param oBinary
  *        the output.
  * @return
  *    S_OK  : if succeeded
  *   E_PARTIAL_SR : specific to SRv3. No private data on SRv3. Need to relaunch a query on server to retrieve a SRv1 or SRv2 and know if there is (or not) a private data
  *   E_FAIL : if failed
  */
  HRESULT Marshalling(CATBinary & oBinary) const;

  /**
  * Streams object in a string
  * @param oBinary
  *        the output.
  * @return
  *    S_OK  : if succeeded
  *   E_PARTIAL_SR : specific to SRv3. No private data on SRv3. Need to relaunch a query on server to retrieve a SRv1 or SRv2 and know if there is (or not) a private data
  *   E_FAIL : if failed
  */
  HRESULT Marshalling(CATString & oString) const;

  /**
  * Creates object from binary stream
  * @param iBinary
  *        the input format.
  * @return
  *    S_OK  : if succeeded
  *   E_FAIL : if failed
  */
  HRESULT Unmarshalling(const CATBinary & iBinary);


  /**
  * Creates object from a string
  * @param iString
  *        the input format.
  * @param iTypeAggr
  *        correspond to the type of the aggregator of the path
  * @return
  *    S_OK  : if succeeded
  *   E_FAIL : if failed
  */
  HRESULT Unmarshalling(const CATString & iString);
  HRESULT Unmarshalling(const CATString & iString, const CATUnicodeString& iTypeAggr);



  /** Retrieve SemanticRelation.AppIndex */
  HRESULT GetPosition(unsigned int&) const;
  unsigned int GetPosition() const;

  /** LinkedIDRel (extracted from PrivateData) */
  HRESULT GetLinkedIDRel(unsigned int & oLinkedIDRel);

  /** ContextualRole (extracted from PrivateData) */
  HRESULT GetContextualRole(CATUnicodeString& oContextualRole);

  /**
   * retrieve zombie alias (extracted from PrivateData)
   */
  OMX_DEPRECATED("Use GetPrivateData") HRESULT GetAliasStream(const char ** iopAliasStream, size_t & oStreamSize);
  HRESULT GetZombieAlias(CATOmxArray<unsigned char>& oZombieAlias) const;

  /** obsolete, use SetPrivateData */
  void SetPrivateAttributes(unsigned int iLinkedIdRel, CATUnicodeString& iFunctionalName, char * ipAliasStream, size_t iAliasSize, CATUnicodeString * ipContextualRole = NULL, AllLevelsIdByAttr * ipIdByAttr = NULL, CATBoolean iSynchroEnabled = TRUE);
  HRESULT SetPrivateAttributes(unsigned int iLinkedIdRel, const CATUnicodeString& iFunctionalName, const CATOmxArray<unsigned char>& iZombieAlias, const CATUnicodeString& iContextualRole, const AllLevelsIdByAttr& IThingy, CATBoolean iSynchroEnabled);

  /** Retrieve SemanticRelation.PrivateData */
  HRESULT GetPrivateData(CATBinary & oBinary) const;
  CATBinary GetPrivateData() const
  {
    CATBinary PrivateData;
    GetPrivateData(PrivateData);
    return PrivateData;
  }

  /** Retrieve SemanticRelation.PrivateData */
  HRESULT GetPrivateData(CATPLMSemanticRelationPrivateData& oPrivateData) const;
  void SetPrivateData(const CATPLMSemanticRelationPrivateData& iPrivateData);

  /**
  * Returns identification by attributs of the component of the path (Extracted from PrivateData)
  *
  * @param AllLevelsIdByAttr oIdByAttr
  *
  * @return
  *      S_OK    : if succeeded, even if empty!
  *      E_PARTIAL_SR: specific to SRv3. No private data on SRv3. Need to relaunch a query on server to retrieve a SRv1 or SRv2 and know if there is (or not) a private data
  *      E_FAIL  : otherwise.
  */
  HRESULT GetIdByAttr(AllLevelsIdByAttr& oIdByAttr);


  /**
  * Return datas of an attribute link.
  *
  *  @param oLinks
  *       a list of links on attributes.
  *
  * @return
  *      S_OK    : if succeeded.
  *      E_PARTIAL_SR: specific to SRv3. No private data on SRv3. Need to relaunch a query on server to retrieve a SRv1 or SRv2 and know if there is (or not) a private data
  *      E_FAIL  : otherwise.
  */
  HRESULT GetSynchronizationDomains(CATListCATPLMSynchronizationDomains & oLinks) const;

  /**
  *   Create attributes links.
  *
  *  @param iLinks
  *       a list of links on attributes.
  *
  * @return
  *      S_OK    : if succeeded.
  *      E_FAIL  : otherwise.
  */
  HRESULT SetSynchronizationDomains(const CATListCATPLMSynchronizationDomains & iDomains);


  /** obsolete */
  HRESULT CountSynchronizationDomains(int & oSize);

  CATBoolean IsSynchroEnabled() const;

  enum PersistencyMode { Rewrite, Synchronize };

  void SetSRAttributes(const CATOmxOHMap<CATPLMTypeH, CATOmxKeyValueBlock>& iAttributes);
  CATOmxOHMap<CATPLMTypeH, CATOmxKeyValueBlock> GetSRAttributes() const;

  /** ensure isolation of the letter */
  void Isolate();

private:
  HRESULT CheckComplete() const;

  friend class CATOmbRelationalExportFormat_PLMRecord;
  friend class CATPLMQLUpdateStatementBuilder;

  PersistencyMode GetPersistencyMode() const;

public:
  HRESULT AssignPathId(const CATUnicodeString& iPathId);
  CATUnicodeString GetPathId() const;

private:
  CATOmxSR<SharedSRD>  _Shared;
  HRESULT Build(const CATBinary & iBinary, const CATUnicodeString& iTypeAggr);
};


#endif
