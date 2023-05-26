// COPYRIGHT Dassault Systemes 2015
#ifndef CATPLMPathType_H
#define CATPLMPathType_H

#include "CATPLMIdentificationAccess.h"

#include "CATBoolean.h"
#include "CATErrorDef.h"

#include "AttrTypes.h"
#include "CATPLMPathDataEnum.h"
#include "CATPLMElementH.h"

#include "CATOmxAny.h"
#include "CATOmxSR.h"
#include "CATOmxArray.h"

class CATPLMTypeH;
class CATUnicodeString;
class CATOmxKeyString;
class CATOmxKeyValueBlock;
class CATPLMPathDataInt;
class CATPLMPathTypeH;
#include "CATCollec.h"
class CATLISTV(CATPLMID);
class CATPLMID;

class ExportedByCATPLMIdentificationAccess CATPLMPathDataH
{
  friend class CATPLMDataStreamRecord;
public:
  CATPLMPathDataH();

  /*
   * Global/Local path type 
   * When we RETRIEVE/READ existing data from server, iIdentifier.GetLengthInChar() != 0.
   *
   * Current constructors with parameter iIdentifier: Usage restricted to PLMAdapter, Providers, TransitionEngine, ReplicationEngine
   *
   * iType [IN]
   *   aggregating type
   * iPathTypeName [IN]
   *   if path type name is not a kind of semantic relation, use pathTypeName_declared_in_metadata (role + category are useless)
   *   if path type name is kind of semantic relation, if CATUnicornLevel::PathTypeMappingSuppressed()==FALSE, use SemanticRelation + role + category
   *   if path type name is kind of semantic relation, if CATUnicornLevel::PathTypeMappingSuppressed()==TRUE, use pathTypeName_declared_in_metadata or aggregating_type_declared_in_metadata.pathTypeName_declared_in_metadata
   *
   * When you READ data:
   * If in CATIPLMQueryFilter you set PLMQY_PATHTYPES to PLMQY_PUREPATHTYPE or to PLMQY_ALL then iState == CATPLMPathDataEnum::eall.
   * If in CATIPLMQueryFilter you set PLMQY_PATHTYPES to PLMQY_PUREPATHTYPE or to PLMQY_ALL_ID_ONLY then iState == CATPLMPathDataEnum::eall_except_id.
  */
  // SemanticRelation that have not been migrated: Need to specify role and category
  CATPLMPathDataH(const CATPLMTypeH& iType,const CATOmxKeyString& iPathTypeName,const CATOmxKeyString& iRole,const CATOmxKeyString& iCategory, const CATUnicodeString& iIdentifier, CATPLMPathDataEnum::ePathStateOfLoading iState = CATPLMPathDataEnum::eall);

  // Pure PathType (role + category are useless)
  CATPLMPathDataH(const CATPLMTypeH& iType, const CATOmxKeyString& iPathTypeName, const CATUnicodeString& iIdentifier, CATPLMPathDataEnum::ePathStateOfLoading iState = CATPLMPathDataEnum::eall);

  // Pure PathType and SemanticRelation (CATPLMPathTypeH uses iPathTypeName for pure path type and iPathTypeName, iRole, iCategory for SemanticRelation)
  CATPLMPathDataH(const CATPLMTypeH& iType, const CATPLMPathTypeH& iPathType, const CATUnicodeString& iIdentifier, CATPLMPathDataEnum::ePathStateOfLoading iState = CATPLMPathDataEnum::eall);

  /*
  * Global/Local path type 
  * When we CREATE/WRITE a path data on Rich client, iIdentifier is not necessary and state of loading is CATPLMPathDataEnum::eall_except_id. Indeed, identifier is filled by server.
  *
  * iType [IN]
  *   aggregating type
  * iPathTypeName [IN]
  *   if path type name is not a kind of semantic relation, use pathTypeName_declared_in_metadata (role + category are useless)
  *   if path type name is kind of semantic relation, if CATUnicornLevel::PathTypeMappingSuppressed()==FALSE, use SemanticRelation + role + category
  *   if path type name is kind of semantic relation, if CATUnicornLevel::PathTypeMappingSuppressed()==TRUE, use pathTypeName_declared_in_metadata or aggregating_type_declared_in_metadata.pathTypeName_declared_in_metadata
  *
  * When you WRITE data:
  * then iState == CATPLMPathDataEnum::eall_except_id (it is automatically set).
  */
  // SemanticRelation that have not been migrated: Need to specify role and category
  CATPLMPathDataH(const CATPLMTypeH& iType, const CATOmxKeyString& iPathTypeName, const CATOmxKeyString& iRole, const CATOmxKeyString& iCategory);

  // Pure PathType (role + category are useless)
  CATPLMPathDataH(const CATPLMTypeH& iType, const CATOmxKeyString& iPathTypeName);

  // Pure PathType and SemanticRelation (CATPLMPathTypeH uses iPathTypeName for pure path type and iPathTypeName, iRole, iCategory for SemanticRelation)
  CATPLMPathDataH(const CATPLMTypeH& iType, const CATPLMPathTypeH& iPathType);

  ~CATPLMPathDataH();

  CATBoolean IsValid() const;

  int operator ==( const CATPLMPathDataH & iOther ) const;

  int operator !=( const CATPLMPathDataH & iOther ) const;

  HRESULT ComputeHashKey( unsigned int & oKey ) const;

  int Compare( const CATPLMPathDataH & iOther ) const;

  const CATPLMPathTypeH& GetPathTypeH() const;

  // @Deprecated
  HRESULT GetPathTypeH( CATPLMPathTypeH& oPathType ) const;

  const CATPLMTypeH& GetTypeH() const;

  HRESULT GetIdentifier(CATUnicodeString& oId) const;

  CATPLMPathDataEnum::ePathStateOfLoading GetStateOfLoading() const;

  const CATPLMElementHArray& GetElementsR() const;
  CATPLMElementHArray& GetElementsW();

  // @Deprecated
  HRESULT GetElements(CATPLMElementHArray& oListElement) const;

  // copy on write is implemented
  // Suppose you have:
  // CATPLMPathDataH A;
  // CATPLMPathDataH B = A;
  // A and B share same data
  // Suppose you do A.SetElements(...)
  // A and B don't share same data anymore
  HRESULT SetElements(const CATPLMElementHArray& iListElem);

  const CATOmxKeyValueBlock& GetAttrBlock() const;

  // copy on write is implemented
  // Suppose you have:
  // CATPLMPathDataH A;
  // CATPLMPathDataH B = A;
  // A and B share same data
  // Suppose you do A.SetAttrBlock(...)
  // A and B don't share same data anymore
  HRESULT SetAttrBlock(const CATOmxKeyValueBlock& iAttrBlock);

  // copy on write is implemented
  // Suppose you have:
  // CATPLMPathDataH A;
  // CATPLMPathDataH B = A;
  // A and B share same data
  // Suppose you do A.MergeAttrBlock(...)
  // A and B don't share same data anymore
  HRESULT MergeAttrBlock(const CATOmxKeyValueBlock& iAttrBlock);

  // copy on write is implemented
  // Suppose you have:
  // CATPLMPathDataH A;
  // CATPLMPathDataH B = A;
  // A and B share same data
  // Suppose you do A.SetAttrValue(...)
  // A and B don't share same data anymore
  HRESULT SetAttrValue(const CATOmxKeyString& iAttrName,const CATOmxAny& iValue);

  HRESULT GetAttrValue(const CATOmxKeyString& iAttrName,CATOmxAny& oValue,AttrTypes& oType,CATBoolean& oIsMultivaluated) const;

  // lazy copy
  // eg:
  // CATPLMPathDataH A(...)
  // CATPLMPathDataH B(A);
  // B and A share the same data
  CATPLMPathDataH(const CATPLMPathDataH& iSource);

  // lazy copy
  // eg:
  // CATPLMPathDataH A(...)
  // CATPLMPathDataH B = A;
  // B and A share the same data
  CATPLMPathDataH& operator = (const CATPLMPathDataH& iSource);

  // Copy
  // CATPLMPathDataH A(...)
  // CATPLMPathDataH B;
  // B.Clone(A);
  // B and A have their own content
  HRESULT Clone(const CATPLMPathDataH& iSource);

  HRESULT Merge(const CATPLMPathDataH& iSource);
private:
  HRESULT _GetAttrType(const CATOmxKeyString& iAttrName,AttrTypes& oAttrType,CATBoolean& oIsMultivaluated) const;

  HRESULT _SetAttrValue(const CATOmxKeyString& iAttrName,const CATOmxAny& iValue,unsigned int iMask);

  HRESULT _CloneIfNecessary();

  CATPLMPathDataInt* _Clone(CATPLMPathDataInt* ipPathDataInt);

  CATOmxSR<CATPLMPathDataInt> _spPathDataInt;
};

extern const ExportedByCATPLMIdentificationAccess CATPLMPathDataH CATPLMPathDataH_Null;

template <> ExportedByCATPLMIdentificationAccess CATOmxCollecManager & CATOmxDefaultCollecManager <CATPLMPathDataH>::manager();

typedef CATOmxArray<CATPLMPathDataH,CATOmxDefaultCollecManager<CATPLMPathDataH>::manager> CATPLMPathDataHArray;

#endif
