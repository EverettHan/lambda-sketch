//===================================================================
// COPYRIGHT Dassault Systemes 2019/03/22
//===================================================================
// Header definition of class CATPLMOmxCollections
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2019/03/22 Creation: EPB
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATPLMOMXCOLLECTIONS_H_
#define CATPLMOMXCOLLECTIONS_H_

#include "CATPLMServicesItf.h"

#include "CATOmxList.h"
#include "CATOmxArray.h"
#include "CATOmxOMap.h"
#include "CATOmxOSet.h"
#include "CATOmxSet.h"
#include "CATOmxAny.h"
#include "CATOmxPair.h"
#include "CATOmxKeyString.h"
#include "CATOmxKeyValueBlock.h"
#include "CATOmxOrderedSet.h"
#include "CATOmxOrderedOSet.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxOHMap.h"
#include "sequence_octet.h"
#include "CATOmxJsonObject.h"

#include "CATPLMID.h"
#include "CATPLMTypeH.h"
#include "CATPLMTypeHMap.h"

#include "CATUuid.h"//useless #include "CATUuid.h" that should be replaced by class CATUuid (I break build of file DELMfgContextBuilderCmds\DELPPRWipmidCmd.m\src\DNBPPRNavWipMidPanel.cpp)

#include "CATIAV5Level.h"
#include "CATOmxCollecManagers.h"

class CATOmxCollecManager;
class CATIPLMFilterSelectCondition;
class VPMIDicUsingAttributeMask;
class VPMIDicSimple;
class CATPLMCEStamp;
class CATIPLMFilterRelationQuality;
class CATIPLMRecordRead;
class CATPLMFTFilterOnAttrDesc;
class CATPLMFTFilterOnAttrNodeDesc;
class CATUnicodeString;
class CATPLMStreamDescriptor;
class CATPLMQueryFilterType;
class CATPLMPairUuidCes;
class CATPLMSemanticRelationData;
class CATIPLMCompCopyRecordWrite;
class CATPLMClientTaskMessage;
class CATPLMClientTaskObject;
class CATPLMClientTaskGroupOfObjects;

typedef CATOmxList<CATIPLMFilterSelectCondition> CATIPLMFilterSelectConditionList;

class CATIPLMFilterSelectCriteria;
typedef CATOmxList<CATIPLMFilterSelectCriteria> CATIPLMFilterSelectCriteriaList;

class CATIPLMFilterCriteria;
typedef CATOmxList<CATIPLMFilterCriteria> CATIPLMFilterCriteriaList;

class CATIPLMFilterOrderBy;
typedef CATOmxList<CATIPLMFilterOrderBy> CATIPLMFilterOrderByList;

class CATIPLMFilterObjectToTreat;
typedef CATOmxList<CATIPLMFilterObjectToTreat> CATIPLMFilterObjectToTreatList;

class CATIPLMFilterExplicit;
typedef CATOmxList<CATIPLMFilterExplicit> CATIPLMFilterExplicitList;

class CATIPLMProviderDesc;
typedef CATOmxList<CATIPLMProviderDesc> CATIPLMProviderDescList;

template<> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMQueryFilterType>::manager();

class CATPLMAttribute;
typedef CATOmxList<CATPLMAttribute> CATPLMAttributeList;
typedef CATOmxVector<CATPLMAttribute> CATPLMAttributeVector;
template<> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMAttribute*>::manager();
// Be careful, I have found CATPLMAttributeSet defined in CATPLMIntegrationBase (CATPLMIntegrationBase/ProtectedInterfaces/CATPLMAttributeSet.h)...
typedef CATOmxSet<CATPLMAttribute, CATOmxDefaultCollecManager<CATPLMAttribute*>::manager> CATPLMAttributeNotOrderedSet;
typedef CATOmxOrderedSet<CATPLMAttribute, CATOmxDefaultCollecManager<CATPLMAttribute*>::manager> CATPLMAttributeOrderedSet;
typedef CATOmxOMap<CATOmxKeyString, CATPLMAttribute*, CATOmxDefaultCollecManager<CATOmxKeyString>::manager, com_manager> CATPLMKeyStringToPLMAttr;
typedef CATOmxOMap<CATString, CATPLMAttribute*, CATOmxDefaultCollecManager<CATString>::manager, com_manager> CATPLMCSToPLMAttr;

class CATPLMRelation;
typedef CATOmxList<CATPLMRelation> CATPLMRelationList;

class CATPLMType;
typedef CATOmxList<CATPLMType> CATPLMTypeList;
template<> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMType*>::manager();
typedef CATOmxSet<CATPLMType, CATOmxDefaultCollecManager<CATPLMType*>::manager> CATPLMTypeSet;
typedef CATOmxOMap<CATPLMType*, CATPLMType*> CATPLMTypeToCATPLMType;
typedef CATOmxOrderedSet<CATPLMType, CATOmxDefaultCollecManager<CATPLMType*>::manager> CATPLMTypeOrderedSet;

class CATIPLMFilterFunction;
typedef CATOmxList<CATIPLMFilterFunction> CATIPLMFilterFunctionList;

class CATIPLMFilterAttribute;
typedef CATOmxList<CATIPLMFilterAttribute> CATIPLMFilterAttributeList;

class CATIPLMFilterRelation;
typedef CATOmxList<CATIPLMFilterRelation> CATIPLMFilterRelationList;

class CATIPLMFilterConfig;
typedef CATOmxList<CATIPLMFilterConfig> CATIPLMFilterConfigList;

class CATIPLMFilterVolume;
typedef CATOmxList<CATIPLMFilterVolume> CATIPLMFilterVolumeList;

class CATIPLMFilterCondition;
typedef CATOmxList<CATIPLMFilterCondition> CATIPLMFilterConditionList;

class VPMIDicMask;
typedef CATOmxOMap<int, VPMIDicMask*, CATOmxDefaultCollecManager<int>::manager, com_manager> CATPLMIntToDicMaskMap;

typedef CATOmxOMap<CATUnicodeString, VPMIDicMask*, CATOmxDefaultCollecManager<CATUnicodeString>::manager, com_manager> CATPLMStringToDicMaskMap;

template<> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager< CATUuid >::manager();// Already created in Omx - just for link

typedef CATOmxPair<CATUnicodeString, CATUnicodeString> CATPLMPairCUSCUS;

template<> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager< CATPLMPairCUSCUS >::manager();

typedef CATOmxPair<CATOmxKeyString, CATOmxKeyString> CATPLMPairKSKS;

template<> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager< CATPLMPairKSKS >::manager();

typedef CATOmxPair<CATOmxKeyString, CATUnicodeString> CATPLMPairKSCUS;

template<> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager< CATPLMPairKSCUS >::manager();

typedef CATOmxPair<CATOmxKeyString, CATOmxAny> CATPLMPairKSAny;

template<> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager< CATPLMPairKSAny >::manager();

typedef CATOmxPair<CATPLMID, CATUnicodeString> CATPLMPairCATPLMIDCUS;

template<> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager< CATPLMPairCATPLMIDCUS >::manager();

typedef CATOmxArray<CATPLMPairCATPLMIDCUS> ArrayOfCATPLMPairCATPLMIDCUS;

template<> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager< ArrayOfCATPLMPairCATPLMIDCUS >::manager();

typedef CATOmxOMap<CATPLMTypeH, ArrayOfCATPLMPairCATPLMIDCUS> CATPLMTypeHToArrayOfCATPLMPairCATPLMIDCUS;

template<> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager< CATPLMTypeHToArrayOfCATPLMPairCATPLMIDCUS >::manager();

class CATPLMEnvironment;
typedef CATOmxOMap<CATOmxKeyString, CATPLMEnvironment*, CATOmxDefaultCollecManager<CATOmxKeyString>::manager, com_manager> CATPLMKeyStringToPLMEnv;

typedef CATOmxPair<int, CATPLMTypeList> CATPLMPairIntListOfType;

template<> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager< CATPLMPairIntListOfType >::manager();

typedef CATOmxOMap<CATOmxKeyString, CATPLMPairIntListOfType, CATOmxDefaultCollecManager<CATOmxKeyString>::manager, CATOmxDefaultCollecManager<CATPLMPairIntListOfType>::manager> CATPLMKeyStringToPairIntListOfType;

typedef CATOmxOMap< CATPLMTypeH, CATOmxKeyValueBlock > CATPLMTypeToKVB;

class CATPLMDomain;
typedef CATOmxList<CATPLMDomain> CATPLMDomainList;
typedef CATOmxOMap<CATOmxKeyString, CATPLMDomain*, CATOmxDefaultCollecManager<CATOmxKeyString>::manager, com_manager> CATPLMKeyStringToPLMDomain;

typedef  CATOmxPair<CATString, CATString> CATPLMPairCSCS;

template<> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager< CATPLMPairCSCS >::manager();

typedef CATOmxOMap<CATString, CATPLMPairCSCS, CATOmxDefaultCollecManager<CATString>::manager, CATOmxDefaultCollecManager< CATPLMPairCSCS >::manager> CATPLMStringToPairStringString;

typedef CATOmxOMap<CATOmxKeyString, VPMIDicUsingAttributeMask*, CATOmxDefaultCollecManager<CATOmxKeyString>::manager, com_manager> CATPLMMapAttrNameWithUsingAttrMask;

typedef CATOmxOMap<CATOmxKeyString, VPMIDicSimple*, CATOmxDefaultCollecManager<CATOmxKeyString>::manager, com_manager> CATPLMMapAttrNameWithDicAttr;

typedef CATOmxPair<CATPLMID, CATPLMID> CATPLMPairPlmidPlmid;

// deprecated, please use CATPLMCUSToKvb, we try to standardize naming of those collections
typedef CATOmxOMap<CATUnicodeString, CATOmxKeyValueBlock, CATOmxDefaultCollecManager<CATUnicodeString>::manager, CATOmxDefaultCollecManager<CATOmxKeyValueBlock>::manager> CATPLMStrToKvb;

typedef CATOmxOMap<CATUnicodeString, CATOmxKeyValueBlock, CATOmxDefaultCollecManager<CATUnicodeString>::manager, CATOmxDefaultCollecManager<CATOmxKeyValueBlock>::manager> CATPLMCUSToKvb;

typedef CATOmxOMap<CATOmxKeyString, CATOmxKeyValueBlock, CATOmxDefaultCollecManager<CATUnicodeString>::manager, CATOmxDefaultCollecManager<CATOmxKeyValueBlock>::manager> CATPLMKSToKvb;

typedef CATOmxArray<CATBinary, CATOmxDefaultCollecManager<CATBinary>::manager> CATPLMArrayOfBin;

typedef CATOmxOrderedOSet<CATString, CATOmxDefaultCollecManager<CATString>::manager> CATPLMOrderedSetOfCS;

typedef CATOmxPair<CATPLMID, int> CATPLMPairPLMIDInt;

typedef CATOmxOMap<int, CATPLMID, CATOmxDefaultCollecManager<int>::manager, CATOmxDefaultCollecManager<CATPLMID>::manager> CATPLMIntToPLMID;

namespace CATPLMOmxCollections
{
  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrCATPLMPairUuidCes();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrCATPLMPairUuidCesArray();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrCATPLMPairPlmidPlmid();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrCATPLMFTFilterOnAttrNodeDesc();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrCATPLMFTFilterOnAttrDesc();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrCATPLMArrayOfBin();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrCATPLMID();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrArrayOfCATPLMID();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrOrderedSetOfCS();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrCATPLMSemanticRelationData();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrCATPLMTypeOrderedSet();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrKSSet();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrMapIntToKSSet();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrOrderedOSetOfPLMID();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrOSetOfPLMID();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrCATPLMOrderedOSetOfKS();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrCATPLMTypeHToOrderedOSetOfKS();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrCATPLMTypeHMapToOrderedOSetOfKS();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrCATPLMIntToCUS();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrBool();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrPairPLMIDInt();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrIntToPLMID();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrArrayPairPLMIDInt();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrArrayOfUuid();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrArrayOfInt();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrPairOfIntInt();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrArrayOfPairOfIntInt();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrClientTaskMessage();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrClientTaskObject();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrClientTaskGroupOfObjects();

  ExportedByCATPLMServicesItf CATOmxCollecManager& mngrOrderedOSetOfCUS();

  // ExportedByCATPLMServicesItf static const CATPLMTypeToKVB CATPLMTypeToKVB_Empty;
};

typedef CATOmxArray<CATPLMPairUuidCes, CATPLMOmxCollections::mngrCATPLMPairUuidCes> CATPLMPairUuidCesArray;

typedef CATOmxArray<CATPLMPairUuidCesArray, CATPLMOmxCollections::mngrCATPLMPairUuidCesArray> CATPLMPairUuidCesArrayArray;

typedef CATOmxOSet<CATUuid, CATOmxDefaultCollecManager<CATUuid>::manager> CATPLMUuidSet;

typedef CATOmxOMap<CATUuid, CATPLMID, CATOmxDefaultCollecManager<CATUuid>::manager, CATPLMOmxCollections::mngrCATPLMID> CATPLMUuidPlmidMap;

//@deprecated replaced by CATPLMIDToPairPLMIDPLMID
typedef CATOmxOMap<CATPLMID, CATPLMPairPlmidPlmid, CATPLMOmxCollections::mngrCATPLMID, CATPLMOmxCollections::mngrCATPLMPairPlmidPlmid> CATPLMPlmidToPairPlmidPlmid;
typedef CATOmxOMap<CATPLMID, CATPLMPairPlmidPlmid, CATPLMOmxCollections::mngrCATPLMID, CATPLMOmxCollections::mngrCATPLMPairPlmidPlmid> CATPLMIDToPairPLMIDPLMID;

typedef CATOmxList<CATIPLMFilterRelationQuality> CATIPLMFilterRelationQualityList;

#if defined(CATIAR419)
typedef CATOmxArray<CATPLMFTFilterOnAttrDesc, CATPLMOmxCollections::mngrCATPLMFTFilterOnAttrDesc> CATPLMArrayOfFilterOnAttrDesc;

typedef CATOmxArray<CATPLMFTFilterOnAttrNodeDesc, CATPLMOmxCollections::mngrCATPLMFTFilterOnAttrNodeDesc> CATPLMArrayOfFilterOnAttrNodeDesc;
#endif

typedef CATOmxOMap<int, CATUnicodeString> CATPLMIntToCUS;

template<> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager<CATIPLMRecordRead*>::manager();

typedef CATOmxList<CATPLMStreamDescriptor> CATPLMStreamDescriptorList;

typedef CATOmxOMap<CATPLMID, CATPLMStreamDescriptorList, CATPLMOmxCollections::mngrCATPLMID, CATOmxDefaultCollecManager<CATPLMStreamDescriptorList>::manager> CATPLMIDToSDList;

typedef CATOmxOMap<CATPLMType*, CATPLMAttributeList, com_manager, CATOmxDefaultCollecManager<CATPLMAttributeList>::manager> CATPLMTypeToAttrList;

typedef CATOmxOrderedOSet<CATPLMQueryFilterType, CATOmxDefaultCollecManager<CATPLMQueryFilterType>::manager> CATPLMQueryFilterTypeOrderedSet;

typedef CATOmxArray<CATPLMQueryFilterType, CATOmxDefaultCollecManager<CATPLMQueryFilterType>::manager> CATPLMQueryFilterTypeList;

typedef CATOmxArray<CATPLMID, CATOmxDefaultCollecManager <CATPLMID>::manager> CATPLMArrayOfPLMID;

typedef CATOmxArray<CATUuid, CATOmxDefaultCollecManager <CATUuid>::manager> CATPLMArrayOfUuid;

typedef CATOmxOMap<CATUnicodeString, CATPLMArrayOfPLMID, CATOmxDefaultCollecManager <CATUnicodeString>::manager, CATPLMOmxCollections::mngrArrayOfCATPLMID> CATPLMStringToArrayOfPLMID;

typedef CATOmxOHMap<CATPLMID, CATIPLMRecordRead*, CATPLMOmxCollections::mngrCATPLMID, com_manager> CATPLMIDToRecordReadHMap;

typedef CATOmxOHMap<CATPLMID, CATOmxList<CATIPLMRecordRead>, CATPLMOmxCollections::mngrCATPLMID, CATOmxDefaultCollecManager <CATOmxList<CATIPLMRecordRead> >::manager> CATPLMIDToRecordReadListHMap;

typedef CATOmxOMap<CATOmxKeyString, CATPLMTypeList, CATOmxDefaultCollecManager<CATOmxKeyString>::manager, CATOmxDefaultCollecManager<CATPLMTypeList>::manager> CATPLMTypeNameToTypeList;

typedef CATOmxOMap < CATPLMID, CATIPLMRecordRead*, CATPLMOmxCollections::mngrCATPLMID, com_manager> CATPLMIDToRecordRead;

typedef CATOmxArray<CATPLMSemanticRelationData, CATPLMOmxCollections::mngrCATPLMSemanticRelationData> CATPLMSemanticRelationDataArray;

typedef CATOmxOMap<CATPLMTypeH, CATOmxList<CATIPLMRecordRead>, CATOmxDefaultCollecManager <CATPLMTypeH >::manager, CATOmxDefaultCollecManager <CATOmxList<CATIPLMRecordRead> >::manager> CATPLMTypeHToRecordReadList;

typedef CATOmxOMap < CATPLMTypeH, CATPLMOrderedSetOfCS, CATOmxDefaultCollecManager <CATPLMTypeH>::manager, CATPLMOmxCollections::mngrOrderedSetOfCS > CATPLMTypeHToOrderedSetOfCS;

// Deprecated: Please migrate on CATPLMKSSet
//typedef CATOmxOSet<CATOmxKeyString, CATOmxDefaultCollecManager<CATOmxKeyString>::manager> CATPLMKeyStringSet;
typedef CATOmxOSet<CATOmxKeyString, CATOmxDefaultCollecManager<CATOmxKeyString>::manager> CATPLMKSSet;

extern const ExportedByCATPLMServicesItf CATPLMKSSet CATPLMKSSet_Empty;

typedef CATOmxOMap<CATOmxKeyString, CATUnicodeString, CATOmxDefaultCollecManager<CATOmxKeyString>::manager, CATOmxDefaultCollecManager<CATUnicodeString>::manager> CATPLMKSToCUS;

typedef CATOmxOMap<int, CATPLMKSSet, CATOmxDefaultCollecManager<int>::manager, CATPLMOmxCollections::mngrKSSet> CATPLMMapIntToKSSet;

typedef CATOmxOMap<CATOmxKeyString, CATPLMMapIntToKSSet, CATOmxDefaultCollecManager<CATOmxKeyString>::manager, CATPLMOmxCollections::mngrMapIntToKSSet> CATPLMMapKSToMapIntToKSSet;

typedef CATOmxOMap<CATPLMID, CATIPLMCompCopyRecordWrite*, CATOmxDefaultCollecManager<CATPLMID>::manager, com_manager> CATPLMIDToCopyRecordWrite;

typedef CATOmxOrderedOSet<CATPLMID, CATPLMOmxCollections::mngrCATPLMID > CATPLMOrderedOSetOfPLMID;

typedef CATOmxOSet<CATPLMID, CATPLMOmxCollections::mngrCATPLMID > CATPLMOSetOfPLMID;

typedef CATOmxOMap < CATPLMID, CATPLMOrderedOSetOfPLMID, CATOmxDefaultCollecManager<CATPLMID>::manager, CATPLMOmxCollections::mngrOrderedOSetOfPLMID> CATPLMIDToOrderedOSetOfPLMID;

typedef CATOmxOMap < CATUuid, CATOmxJsonObject, CATOmxDefaultCollecManager<CATUuid>::manager, CATOmxDefaultCollecManager<CATOmxJsonObject>::manager > CATPLMUuidToJsonObject;

typedef CATOmxOrderedOSet< CATOmxKeyString, CATOmxDefaultCollecManager<CATOmxKeyString>::manager> CATPLMOrderedOSetOfKS;

typedef CATOmxOMap< CATPLMTypeH, CATPLMOrderedOSetOfKS, CATOmxDefaultCollecManager<CATPLMTypeH>::manager, CATPLMOmxCollections::mngrCATPLMOrderedOSetOfKS > CATPLMTypeHToOrderedOSetOfKS;

typedef CATOmxOMap< CATPLMTypeH, CATPLMTypeHToOrderedOSetOfKS, CATOmxDefaultCollecManager<CATPLMTypeH>::manager, CATPLMOmxCollections::mngrCATPLMTypeHToOrderedOSetOfKS > CATPLMTypeHToTypeHToOrderedOSetOfKS;

typedef CATOmxOMap<SEQUENCE(octet), CATPLMArrayOfBin, CATOmxDefaultCollecManager<SEQUENCE(octet)>::manager, CATPLMOmxCollections::mngrCATPLMArrayOfBin > CATPLMSequenceOfOctetToArrayOfBin;

typedef CATOmxOrderedOSet<CATPLMTypeH, CATOmxDefaultCollecManager<CATPLMTypeH>::manager> CATPLMOrderedOSetOfTypeH;

typedef CATPLMTypeHMap< CATPLMTypeHMap<CATPLMOrderedOSetOfKS>, CATPLMOmxCollections::mngrCATPLMTypeHMapToOrderedOSetOfKS > CATPLMTypeHMapToTypeHMapToOrderedOSetOfKS;

typedef CATOmxOMap<CATPLMID, CATPLMIntToCUS, CATPLMOmxCollections::mngrCATPLMID, CATPLMOmxCollections::mngrCATPLMIntToCUS> CATPLMIDToIntToCUS;

typedef CATOmxArray<CATOmxList<CATIPLMRecordRead>, CATOmxDefaultCollecManager <CATOmxList<CATIPLMRecordRead> >::manager> CATPLMArrayOfRecordReadList;

typedef CATOmxOMap<CATUnicodeString, CATOmxList<CATIPLMRecordRead>, CATOmxDefaultCollecManager < CATUnicodeString >::manager, CATOmxDefaultCollecManager < CATOmxList<CATIPLMRecordRead> >::manager> CATPLMCUSToRecordReadList;

typedef CATOmxOrderedOSet< CATPLMTypeH > CATPLMTypeHOrderedOSet;

typedef CATOmxOMap<CATPLMID, bool, CATPLMOmxCollections::mngrCATPLMID, CATPLMOmxCollections::mngrBool> CATPLMIDToBool;

typedef CATOmxArray<CATPLMPairPLMIDInt, CATPLMOmxCollections::mngrPairPLMIDInt> CATPLMArrayPairPLMIDInt;

typedef CATOmxOMap<CATPLMTypeH, CATPLMArrayPairPLMIDInt, CATOmxDefaultCollecManager<CATPLMTypeH>::manager, CATPLMOmxCollections::mngrArrayPairPLMIDInt> CATPLMTypeHToArrayPairPLMIDInt;

typedef CATOmxOMap<CATPLMID, CATPLMIntToPLMID, CATOmxDefaultCollecManager<CATPLMID>::manager, CATPLMOmxCollections::mngrIntToPLMID> CATPLMIDToIntToPLMID;

typedef CATOmxOMap<CATUuid, CATPLMIntToPLMID, CATOmxDefaultCollecManager<CATUuid>::manager, CATPLMOmxCollections::mngrIntToPLMID> CATPLMUuidToIntToPLMID;

typedef CATOmxOMap<CATPLMTypeH, CATPLMArrayOfPLMID, CATOmxDefaultCollecManager <CATPLMTypeH>::manager, CATPLMOmxCollections::mngrArrayOfCATPLMID> CATPLMTypeHToArrayOfPLMID;

typedef CATOmxOMap<CATUuid, CATPLMArrayOfPLMID, CATOmxDefaultCollecManager <CATUuid>::manager, CATPLMOmxCollections::mngrArrayOfCATPLMID> CATPLMUuidToArrayOfPLMID;

typedef CATOmxOMap<CATUuid, CATPLMArrayOfUuid, CATOmxDefaultCollecManager <CATUuid>::manager, CATPLMOmxCollections::mngrArrayOfUuid> CATPLMUuidToArrayOfUuid;

typedef CATOmxArray<CATPLMClientTaskMessage, CATPLMOmxCollections::mngrClientTaskMessage> CATPLMArrayClientTaskMessage;

typedef CATOmxArray<CATPLMClientTaskObject, CATPLMOmxCollections::mngrClientTaskObject> CATPLMArrayClientTaskObject;

typedef CATOmxArray<CATPLMClientTaskGroupOfObjects, CATPLMOmxCollections::mngrClientTaskGroupOfObjects> CATPLMArrayClientTaskGroupOfObjects;

typedef CATOmxArray<CATOmxPair<int, int>, CATPLMOmxCollections::mngrPairOfIntInt > CATPLMArrayOfPairOfIntInt;

typedef CATOmxOMap<CATUnicodeString, CATPLMOSetOfPLMID, CATOmxDefaultCollecManager<CATUnicodeString>::manager, CATPLMOmxCollections::mngrOSetOfPLMID> CATPLMStringToSetOfPLMID;

typedef CATOmxOrderedOSet<CATUnicodeString, CATOmxDefaultCollecManager<CATUnicodeString>::manager> CATPLMOrderedOSetOfCUS;

#endif /* CATPLMOMXCOLLECTIONS_H_ */
