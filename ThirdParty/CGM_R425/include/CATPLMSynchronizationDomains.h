/* -*-c++-*- */

#ifndef CATPLMSynchronizationDomains_H
#define CATPLMSynchronizationDomains_H

#include "CATLISTV_CATPLMSynchronizationDomains.h"
#include "CATPLMSemanticRelationData.h"
#include "CATOmxAny.h"
#include "CATOmxKeyValueBlock.h"
#include "CATPLMTypeId.h"
#include "CATOmxKeyString.h"
#include "CATOmxKeyValueFlags.h"
#include "CATPLMIdentificationAccess.h"

/**
 * This class holds synchronization data for an SR which synchronization is based on specific attributes (ie not "updatestamp")
 * It contains
 *   - an extension type.
 *     It is a CATPLMTypeId (and not a CATPLMTypeH) in order to be able to support types unknown in current session
 *     It is NULL if the target attributes are held directly by the target object (and not by an extension),
 *     this is not a design error, the opposite choice would have leaded to duplicating target type with the possibility of incoherency
 *  - a set of (attribute name,attribute value) which contains a copy of the target attributes
 *
 * Design errors:
 *   - this class should have been an immutable struct with no behavior, instead we have the awkward API hereunder
 *   - It occurs that held data are unusable
 *        created broken
 *        broken through database migration
 *        missing metadata in client (either type is unknown or attribute is unknown)
 *     In order to manage that:
 *        . an unresolved state has been introduced:
 *          this is bad design, all callers creating this object must manage this state (and obvously some don't)
 *          A dynamic check would have been much better (available now through CheckMetadata)
 *        . an extension type name member has been added
 *          this is useless, already present CATPLMTypeId member can do the work
 */
class CATPLMSynchronizationDomainDatas
{
public:
  // WARNING:
  // iDomainDatas contains (attribute name 1, value of attribute 1),...,(attribute name N, value of attribute N)
  // Suppose that type of attribute P (P>=1 && P<=N) is a date. Unset date are supported on PLM model.
  // Two cases are managed using mask found on CATOmxKeyValueBlock:
  // 1- If date is set, iDomainDatas must be filled using following value of mask: OMX_KEYVALUE_ISVALUATED
  // example given: iDomainDatas.SetValue(<attribue name>,<value of attribute stored in CATOmxAny>, OMX_KEYVALUE_ISVALUATED)
  // 2- If date is unset, iDomainDatas must be filled using following value of mask OMX_KEYVALUE_NONE
  // example given: iDomainDatas.SetValue(<attribue name P>, <empty CATOmxAny which kind is omx_void>, OMX_KEYVALUE_NONE)
  inline CATPLMSynchronizationDomainDatas(const CATPLMTypeId& iExtensionType, const CATOmxKeyValueBlock & iDomainDatas) :
    _ExtensionType(iExtensionType),
    _Datas(iDomainDatas),
    _UnresolvedStatus(FALSE)
  {}

  inline const CATPLMTypeId& GetExtensionTypeId() const { return _ExtensionType; }
  inline const CATOmxKeyValueBlock & GetAttributes() const { return _Datas; }

  /**
   * checks if stored data can be used in client:
   *   if the attribute is defined on an extension, this extension must be known in current metadata
   *   the attribute must exist
   * @param iTargetBaseType
   *   the type of the object pointed by the semantic relation holding this 'CATPLMSynchronizationDomainDatas' instance.
   *   must be non null
   *   must not be an extension
   */
  ExportedByCATPLMIdentificationAccess CATBoolean CheckMetaData(const CATPLMTypeH& iTargetBaseType) const;

  inline int operator == (const CATPLMSynchronizationDomainDatas & other) const { return GetExtensionTypeId() == other.GetExtensionTypeId() && GetAttributes() == other.GetAttributes(); }
  inline int operator != (const CATPLMSynchronizationDomainDatas & other) const { return !operator==(other); }

  //legacy API, deprecated
  inline HRESULT GetExtTypeId(CATPLMTypeId & oExtensionType)  const { oExtensionType = GetExtensionTypeId(); return S_OK; }
  inline HRESULT GetTypeId(CATPLMTypeId & oExtensionType) const { return GetExtTypeId(oExtensionType); }
  ExportedByCATPLMIdentificationAccess HRESULT GetExtTypeName(CATOmxKeyString & oExtTypeName) const;
  ExportedByCATPLMIdentificationAccess HRESULT SetExtTypeName(const CATOmxKeyString & iExtTypeName);

  inline HRESULT GetDatas(CATOmxKeyValueBlock & oDatas) const { oDatas = GetAttributes(); return S_OK; };
  inline HRESULT AddData(const CATOmxKeyString &iKey, const CATOmxAny &iValue, unsigned int iUnused) { return _Datas.SetValue(iKey, iValue, OMX_KEYVALUE_NONE); }

  inline HRESULT IsUnresolved(CATBoolean & oIsUnresolved)     const { oIsUnresolved = _UnresolvedStatus; return S_OK; }
  inline HRESULT SetUnresolvedMode(CATBoolean   iIsUnresolved) { _UnresolvedStatus = iIsUnresolved; return S_OK; }

private:
  CATPLMTypeId        _ExtensionType;
  CATOmxKeyValueBlock _Datas;
  CATBoolean          _UnresolvedStatus;
};

/**
 * this class holds
 *   a domain name:
 *     It is "Attributes_of_last", anything else is unspecified, unsupported or treated like "Attributes_of_last"...
 *   a list of CATPLMSynchronizationDomainDatas:
 *     notice that thanks to the shitiness of this design, it is possible to model the exact same thing in different ways
 *     for example if you have an SR which synchronization is sensitive to V_description and V_Name attribute, you can either have:
 *        a list of one  CATPLMSynchronizationDomainDatas holding both attributes
 *        a list of two CATPLMSynchronizationDomainDatas, one for V_description, one for V_Name
 *        there is zero check on unicity, an SR can synchronize itself towards xxx times the same attribute
 *   a synchronization status:
 *     this status is meaningless everywhere except after a fetch query (computed client-side by the 'remote engine')
 */
class CATPLMSynchronizationDomains
{
public:
  inline CATPLMSynchronizationDomains(const CATUnicodeString& iDomain, const CATListCATPLMSynchronizationDomainDatas & iListDomainDatas, CATPLMSemanticRelationData::DomainSynchroStatus iSyncStatus) :
    _Domain(iDomain),
    _DomainDatas(iListDomainDatas),
    _SyncStatus(iSyncStatus)
  {}

  inline HRESULT GetSynchronizationDomainsDatas(CATListCATPLMSynchronizationDomainDatas& oListDomainDatas) const { oListDomainDatas = _DomainDatas; return S_OK; }
  inline CATOmxKeyString GetName() const { return _Domain; }
  inline HRESULT GetDomain(CATUnicodeString & oDomain) { oDomain = _Domain.AsCUS();  return S_OK; }
  inline HRESULT GetDomainKS(CATOmxKeyString & oDomain) { oDomain = GetName(); return S_OK; }
  inline CATPLMSemanticRelationData::DomainSynchroStatus GetStatus() const { return _SyncStatus; }
  inline HRESULT GetStatus(CATPLMSemanticRelationData::DomainSynchroStatus& oStatus) { oStatus = GetStatus(); return S_OK; }
  inline HRESULT SetStatus(CATPLMSemanticRelationData::DomainSynchroStatus iStatus) { _SyncStatus = iStatus; return S_OK; }

  inline int operator == (const CATPLMSynchronizationDomains& other) const { return _Domain == other._Domain && _DomainDatas == other._DomainDatas && _SyncStatus == other._SyncStatus; }
  inline int operator != (const CATPLMSynchronizationDomains& other) const { return !operator==(other); }
private:
  CATOmxKeyString _Domain;
  CATListCATPLMSynchronizationDomainDatas _DomainDatas;
  CATPLMSemanticRelationData::DomainSynchroStatus _SyncStatus;
};

#endif
