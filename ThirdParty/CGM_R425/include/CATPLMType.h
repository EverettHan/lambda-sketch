// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATPLMType.h
// Header definition of CATPLMType
//
//===================================================================
//
// Usage notes:
// described an object type manages by the provider.
//
//===================================================================
//  May 2003  Creation: jvm
//===================================================================
/**
* @level Protected
* @usage U1
*/
#ifndef CATPLMType_H
#define CATPLMType_H

//System
#include "CATBooleanDef.h"
#include "CATListPV.h"

// CATPLMServices
#include "CATPLMAttribute.h"
#include "CATPLMTypeIdMode.h"
#include "CATPLMServicesItf.h"
#include "CATPLMBaseObject.h"
#include "CATPLMMask.h"
#include "CATPLMRelation.h"
#include "CATPLMPathTypeH.h"

// CATPLMIdentificationAccess
#include "CATPLMStrongRelationshipId.h"
#include "CATPLMTypeId.h"
#include "CATPLMCoreType.h"
#include "CATPLMTypeIdClassificationEnum.h"
#include "PLMDictionaryDefinitions.h"

// ObjectModelerCollection
#include "CATOmxKeyString.h"
#include "CATOmxArray.h"
#include "CATOmxSR.h"
#include "CATOmxOSet.h"
#include "CATPLMOmxCollections.h"
#include "CATOmxOMap.h"
#include "CATOmxKind.h"

// System
#include "CATLib.h"//System PublicInterfaces (CATGetEnv)

class CATLISTV(CATPLMTypeId);

class CATListPtrCATPLMAttribute;
class CATListPtrCATPLMAttributeInternal;
class CATListPtrCATPLMRelation;
class CATListPtrCATPLMCommand;
class CATListPtrCATPLMType;
class CATPLMAttributeInternal;
class CATPLMCommand;
class CATIPLMProviderDesc;
class VPMIDicClass;
class VPMIDicRelationClass;
class VPMIDicGenericClass;
class CATIAdpType;
class CATIAdpExtType;
class TSTCATPLMEV5Metadata;
class CATDbBinary;
class CATPCCDictionaryServices;
class VPMIDicElement;
class VPMIDicMgr;
class CATPLMAttribute;
class CATPLMTypeH;
struct CATPLMTypeInternal;
class VPMIDicUsingAttributeMask;
class VPMIDicPackage;
class CATIPLMProviderMgr;
class CATPLMTypeManagement2;
class CATIPLMBasicAttributes;

/**
* described an object type manages by the provider.<br>
* A type has attributes, associated commands and can be links to other objects type through relations.
*/
class ExportedByCATPLMServicesItf CATPLMType : public CATPLMBaseObject
{
  CATDeclareClass;

  friend class CATPLMxExpandAdapter;
  friend class CATPLMCompMetaDataService;
  friend class CATPLMODTToolbox;
  friend class TSTCATPLMEV5Metadata;
  friend class CATPLMPrivateTypeServices;
  friend class CATAdpProtectedDictionaryServices;
  friend class CATEKwePLMTypeAttrServices;
  friend class CATEKwePLMTypeAttrServices2;
  friend class CATPLMPrivateAttributeServices;
  friend class CATPLMxQueryFilterCompletion;
  friend class CATPLMDebugServices;
  friend class PLMBLKweFunctions;
  friend class CATAdpRestrictedUKServices;
  friend class CATPLMItgTestAdpRestrictedUKServices;
  friend class CATAdpPrivateQueryServices;
  friend class CATPCCDictionaryServices;
  friend class TSTCATPLMxMetadataHandling;
  friend class CATPLMDebugRWAdapter;
  friend class CATPLMDebugObjectWrite;
  friend class CATPLMDebugSaveTransaction;
  friend class CATPLMDebugOpenQuery;
  friend class CATPLMDebugQueryBase;
  friend class CATPLMDebugRecord;
  friend class CATPLMFilterCriteria;
  friend class CATPLMQLQueryFilter;
  friend class FilterClausesManager;
  friend class CATPLMQLFilterAttribute;
  friend class CATPLMCompApplicationLoaderManager;
  friend class CATPLMLanguageToolkit;
  friend class TSTCATPLMCATPLMTypeAndAttributeAPI_TestPLMSample2InstanceCusto1;
  friend class TSTCATPLMCATPLMTypeAndAttributeAPI_TestIPLMSampleRelation;
  friend class TSTCATPLMCATPLMTypeAndAttributeAPI_TestENOSAM_VPMPartInstance;
  friend class TSTCATPLMCATPLMTypeAndAttributeAPI_TestPLMSample2ReferenceCusto1;
  friend class TSTCATPLMCATPLMTypeAndAttributeAPI_TestPLMSample2Extension01;
  friend class TSTCATPLMCATPLMTypeAndAttributeAPI_TestIPLMDicoSampleExtension3;
  friend class TSTCATPLMCATPLMTypeAndAttributeAPI_TestIPLMDicoSampleClass2;
  friend class TSTCATPLMCATPLMTypeAndAttributeAPI_TestBusinessType;
  friend class CATPLMAttribute;
  friend class xMQLQueryFilter;
  friend class CATTCLRecordHelper;
  friend class CATPLMTypeManagementBase;
  friend class CATPLMTypeManagement;
  friend class CATPLMTypeManagement2;
  friend class CATPLMStrongRelationshipLoader;
  friend class CATPLMTypeTools;
  friend class CATPLMQLMarshallingFactory;
  friend class CATPLMFunctionFactory;
  friend class CATPLMRelation;
  friend class CATPLMxMetaData;
  friend class CATPLMxMetaDataTypesProcessor;
  friend class CATPLMPrivateAttributeServices;
  friend class TSTCATPLMUniqueKeyUsePrivateServices;
  friend class CATPLMCompConnectionInstance;
  friend class CATPLMTypeAttributesLoader;
  friend class CATPLMFilterAttribute;
  friend class CATPLMxTransactionManager;

public:

  // Standard constructors and destructors
  // -------------------------------------
  CATPLMType(CATString *iTypeId, CATUnicodeString *iAlias, CATString *iDomainId, CATIPLMProviderDesc * iProvider, short iIsVisible = 1);
  CATPLMType(VPMIDicClass * iClass, CATString *iDomainId, CATIPLMProviderDesc * iProvider);
  CATPLMType(VPMIDicRelationClass * iRelClass, CATString *iDomainId, CATIPLMProviderDesc * iProvider);
  virtual ~CATPLMType();
  virtual ULONG __stdcall AddRef();
  virtual ULONG __stdcall Release();

  // Be carefull, some objets neither are IRPC nor ER. eg: HistoryEntry, WspTableEntry...

  /*
    With no mapping and no instance mapping, almost all types are ER types even IRPC...
    Contract: Keep the same contract with or without no mapping and no instance mapping.
    so IsERType<=>IsHistoricalERType.
    eg:
    For Port, Connection, Ref, RepRef, Inst, Rep, Inst S_FALSE
    For Pure ER S_OK

    Real Inheritance is seen thanks to InheritsFrom, IsKindOf, GetMetaType
  */
  HRESULT IsERType() const;

  /*
    S_OK for PLMPort, PLMConnection, PLMCoreReference, PLMCoreRepReference, PLMCoreInstance, PLMCoreRepInstance and of course PLMInstance, PLMReference, PLMEntity...and sons....
    S_FALSE for other types
  */
  HRESULT IsIRPCType() const;

  /**
  * Returns the domain Id for this type
  * @param oDomainId  [out, delete]
  */
  virtual HRESULT GetDomainId(CATString **oDomainId);

  /**
  * Returns the domain Id for this type
  * @param oDomainId  [out]
  */
  HRESULT GetDomainId(CATOmxKeyString& oDomainId);

  /**
  * Returns the CATPLMTypeId of the Super CATPLMType.
  * CATPLMTypeId identify a Type of Object.
  */
  HRESULT GetSuperType(CATPLMTypeId * oSuperTypeId);

  /**
  * Returns the CATPLMType of the Super CATPLMType.
  *   @param oSuperType [out, CATBaseUnknown#Release]
  *        The CATPLMType of the Super CATPLMType.
  *   @return
  *        S_OK: the operation succeeded.<br>
  *        E_INVALIDARG: oSuperType is not null.<br>
  *        E_FAIL: the operation failed.

  */
  HRESULT GetSuperType(CATPLMType *& oSuperType);

  /**
  * Return the Lowest Common Ancestor with the input type.
  * Result may be NULL if no Common Ancestor found.
  * Examples:
  *                                                                           HRESULT    opLowestCommonAncestor
  *     "VPMReference".GetLowestCommonAncestor("PLMReference")            ->  S_OK       PLMReference
  *     "VPMRepInstance".GetLowestCommonAncestor("PLMCoreRepInstance")    ->  S_OK       PLMCoreRepInstance
  *     "PLMCoreRepInstance".GetLowestCommonAncestor(VPMRepInstance")     ->  S_OK       PLMCoreRepInstance
  *     "PLMConnection".GetLowestCommonAncestor("PLMPort")                ->  S_OK       PLMEntity
  *     "VPMReference".GetLowestCommonAncestor("VPMRepInstance")          ->  E_FAIL     NULL
  *
  * <br><b>Role</b>: Return the Lowest Common Ancestor with the input type.
  *
  * @param ipOtherType [in]
  *   the other type
  * @param opLowestCommonAncestor [out, CATBaseUnknown#Release]
  *   the lowest common ancestor pointer
  *
  * @return
  * <dt> <code>S_OK</code>          <dd> The lowest common ancestor has been found
  * <dt> <code>E_FAIL</code>        <dd> The lowest common ancestor cannot be found (BusinessType vs RelationType)
  */
  HRESULT GetLowestCommonAncestor(CATPLMType* ipOtherType, CATPLMType*& opLowestCommonAncestor);

  /**
  * Returns the CATPLMTypeId for this type.
  * CATPLMTypeId identify a Type of Object.
  *
  * Defaut mode: access forbidden to PLMTYPE that are on PLMABSTRACT and PLMCORE layer
  ** except if you use SetTypeIdMode
  */
  HRESULT GetTypeId(CATPLMTypeId * oTypeId);

  /**
  * Returns the Core Type for this type
  * @param oTypeCore
  *        The list of Attributes involving in the IdentifierSet.
  * @return
  *        S_OK: the operation succeeded.<br>
  *        E_FAIL: the operation failed. the PLMType is not defined from a known CORETYPE
  */
  HRESULT GetCoreType(CATPLMCoreType * oTypeCore);

  /**
  * Returns the list of attributes of the given mask
  * @param iMask
  *        The Mask defined for the new Attribute. If NULL Returns all the attribute of this Type.
  * @param oAttributes  [out]
  *        The list of Attributes of the given Mask.
  */
  HRESULT ListAttributes(CATPLMMask iMask, CATPLMAttributeList & oAttributes);

  /**
  * @nodoc
  * @deprecated use @href CATPLMType::ListAttributes with a CATOmxList
  */
  HRESULT ListAttributes(CATPLMMask iMask, CATListPtrCATPLMAttribute **oAttributes);

  /**
  * Returns the list of attributes involving in the IdentifierSet management
  * @param oAttributes  [out]
  *        The list of Attributes involving in the IdentifierSet.
  * @return
  *        S_OK: the operation succeeded.<br>
  *        S_FALSE: The Type has no IdentifierSet defined.<br>
  *        E_FAIL: the operation failed.
  * 
  * WARNING: 
  * E_FAIL if idset defined on base type contains attributes of extension and if CATBoolean isIDSetWithAttrOfExtSupported == FALSE
  */
  HRESULT ListIdentifierAttributes(CATPLMAttributeList & oAttributes, CATBoolean isIDSetWithAttrOfExtSupported = FALSE);

  /**
  * @nodoc
  * @deprecated use @href CATPLMType::ListIdentifierAttributes with a CATOmxList
  */
  HRESULT ListIdentifierAttributes(CATListPtrCATPLMAttribute **oAttributes, CATBoolean isIDSetWithAttrOfExtSupported = FALSE);

  /**
  *   Add an attribute to the given mask
  *   @param iAttribute [in, CATBaseUnknown#Release]
  *        The new Attribute to be added to the mask.
  *   @param iMask
  *        The Mask defined for the new Attribute.
  *   @return
  *        S_OK: the operation succeeded.<br>
  *        S_FALSE: the Attribute is already present in the mask.<br>
  *        E_FAIL: the operation failed.
  */
  HRESULT AddAttribute(CATPLMMask iMask, CATPLMAttribute *iAttribute);

  /**
  *   Add the list of attributes to the given mask.
  *   @param iAttributes
  *        The new Attribute to be added to the mask.
  *   @param iMask
  *        The Mask defined for the new Attribute.
  */
  HRESULT AddAttributes(CATPLMMask iMask, CATListPtrCATPLMAttribute *iAttributes);

  /**
  *   Returns the attribute with the specified Id in the given mask
  *   @param iAttributeId
  *        The Attribute Id.
  *   @param iMask
  *        The Mask.
  *   @param oppAttribute [out, CATBaseUnknown#Release]
  *        The CATPLMAttribute with the given iAttributeId in the given iMask.
  *   @return
  *        S_OK: the operation succeeded.<br>
  *        S_FALSE: the Attribute doesn't exist or isn't present in the mask.<br>
  *        E_FAIL: the operation failed.
  */
  HRESULT GetAttribute(CATPLMMask iMask, CATString* ipAttributeId, CATPLMAttribute** oppAttribute);
  HRESULT GetAttribute(const CATString& iAttributeId, CATPLMMask iMask, CATPLMAttribute*& opAttribute);
  HRESULT GetAttribute(CATPLMMask iMask, const CATOmxKeyString& iAttributeId, CATPLMAttribute*& opAttribute);

  /**
  *   Returns the attribute with the specified Index in the given mask
  *   @param iIndex
  *        The Attribute index.
  *   @param iMask
  *        The Mask.
  *   @param oAttribute [out, CATBaseUnknown#Release]
  *        The CATPLMAttribute with the given iAttributeId in the given iMask.
  *   @return
  *        S_OK: the operation succeeded.<br>
  *        E_FAIL: the operation failed.
  */
  HRESULT GetAttribute(CATPLMMask iMask, int iIndex, CATPLMAttribute **oAttribute);

  /**
  *   Returns attributes requested taking int account mask
  *   @param iMask
  *        The Attribute index.
  *   @param iAttrIdList
  *        list of attribute name searched.
  *   @param oAttrNameToPLMAttr [out, CATBaseUnknown#Release]
  *        Map attribute names with CATPLMAttribute.
  *   @return
  *        S_OK: the operation succeeded.<br>
  *        S_FALSE: some CATPLMAttribute have not been found, iAttrIdList.Size() != oAttrNameToPLMAttr.Size()
  *        E_FAIL: the operation failed.
  */
  HRESULT GetAttributes(CATPLMMask iMask, const CATListOfCATString& iAttrIdList, CATPLMCSToPLMAttr& oAttrNameToPLMAttr);
  HRESULT GetAttributes(CATPLMMask iMask, const CATOmxArray<CATOmxKeyString>& iAttrIdList, CATPLMKeyStringToPLMAttr& oAttrNameToPLMAttr);

  /**
  *   Returns the index for the specified attribute in the given mask
  *   @param iMask
  *        The Mask.
  *   @param iAttribute
  *        The CATPLMAttribute in the given iMask.
  *   @param oIndex
  *        The Attribute index.
  *   @return
  *        S_OK: the operation succeeded.<br>
  *        E_FAIL: the operation failed.
  */
  HRESULT GetIndexAttribute(CATPLMAttribute * iAttribute, CATPLMMask iMask, int * oIndex);

  /**
  * Returns the number of attributes of the given mask
  */
  HRESULT AttributeCount(CATPLMMask iMask, int *oAttrCount);

  /**
  * Returns the list of commands
  * @param oCommands  [out, delete]
  */
  HRESULT ListCommands(CATListPtrCATPLMCommand **oCommands);

  /**
  *   Add a command
  *   @param iCommand [in, CATBaseUnknown#Release]
  *        The CATPLMCommand.
  */
  HRESULT AddCommand(CATPLMCommand *iCommand);

  /**
  *	Add the list of commands
  */
  HRESULT AddCommands(CATListPtrCATPLMCommand *iCommands);

  /**
  * Returns the list of relations
  * In this case, we talk about "Aggregation Relation": V_Owner,V_InstanceOf.
  *
  *   @param oRelations  [out]
  *        The list of Relations of this Type.
  *   @param iOnlyVisible
  *        If not 0 returns only UI visible relations.
  *        If 0 returns all relations of PLMType
  */
  HRESULT ListRelations(CATPLMRelationList & oRelations, int iOnlyVisible = 1);

  /**
  * @nodoc
  * @deprecated use @href CATPLMType::ListRelations with a CATOmxList
  */
  HRESULT ListRelations(CATListPtrCATPLMRelation **oRelations, int iOnlyVisible = 1);

  /**
  * Returns the list of subrelations (SR only)
  * In this case, we talk about SR relation only and not "Aggregation relation" (from, to, V_Owner, fromrel, torel)
  * We don't talk about local/global path type (<=> sub relation that don't inherit from SemanticRelation)
  * For local/global path type, please use GetPathTypeH
  *
  *   @param oSubRelations  [out]
  *        The list of sub Relations of this Type.
  *   @param iOnlyVisible
  *        If not 0 returns only UI visible SubRelations.
  *        If 0 returns all SubRelations of PLMType
  */
  HRESULT ListSubRelations(CATPLMRelationList & oSubRelations, int iOnlyVisible = 1);

  /**
  * @nodoc
  * @deprecated use @href CATPLMType::ListSubRelations with a CATOmxList
  */
  HRESULT ListSubRelations(CATListPtrCATPLMRelation **oSubRelations, int iOnlyVisible = 1);

  /**
  * Returns the list of subrelations <=> Path type that inherits from SemanticRelation and others path type
  * In this case, we talk about SR relation only and not "Aggregation relation"
  *
  *   @param oListPathType  [out]
  *        The list of path type of this Type.
  */
  HRESULT ListPathTypeH(CATPLMPathTypeHArray& oListPathType);

  /*
   * Not implemented yet
  */
  HRESULT GetPathTypeH(const CATOmxKeyString& iPathTypeName, CATPLMPathTypeH& oPathType);

  /*
   * Global/Local path type
   *
   * iPathTypeName [IN]
   *   if path type name is not a kind of semantic relation, use pathTypeName_declared_in_metadata or aggregating_type_declared_in_metadata.pathTypeName_declared_in_metadata
   *   if path type name is kind of semantic relation, if CATUnicornLevel::PathTypeMappingSuppressed()==FALSE, use iPathTypeName==SemanticRelation
   *   if path type name is kind of semantic relation, if CATUnicornLevel::PathTypeMappingSuppressed()==TRUE , use pathTypeName_declared_in_metadata or aggregating_type_declared_in_metadata.pathTypeName_declared_in_metadata
   * oPathType [OUT]
   *   path type researched
  */
  HRESULT GetPathTypeH(const CATOmxKeyString& iPathTypeName, const CATOmxKeyString& iRole, const CATOmxKeyString& iCategory, CATPLMPathTypeH& oPathType);

  /**
  * Add a Sub relation
  * In this case, we talk about SR relation only and not "Aggregation relation"
  *
  *   @param iRelation [in, CATBaseUnknown#Release]
  *        The new SubRelation to be added to the type.
  *   @return
  *        S_OK: the operation succeeded.<br>
  *        S_FALSE: the SubRelation is already present in this Type.<br>
  *        E_FAIL: the operation failed.
  */
  HRESULT AddSubRelation(CATPLMRelation *iRelation);

  /**
  * Add a relation
  * In this case, we talk about "Aggregation Relation": V_Owner,V_InstanceOf.
  *
  *
  *   @param iRelation [in, CATBaseUnknown#Release]
  *        The new Relation to be added to the type.
  *   @return
  *        S_OK: the operation succeeded.<br>
  *        S_FALSE: the Relation is already present in this Type.<br>
  *        E_FAIL: the operation failed.
  */
  HRESULT AddRelation(CATPLMRelation *iRelation);

  /**
  * Adds the list of relations
  * In this case, we talk about "Aggregation Relation": V_Owner,V_InstanceOf.
  */
  HRESULT AddRelations(CATListPtrCATPLMRelation *iRelations);

  /**
  *	@deprecated
  * Please use HRESULT GetRelation (CATPLMStrongRelationshipId::eStrongRelId iStrongRelId,CATPLMRelation*& opRelation) ;
  * @param oRelation [out, CATBaseUnknown#Release]
  */
  HRESULT GetRelation(CATString * iRelationId, direction iDirection, CATPLMRelation **oRelation);

  /**
  * Return the Relation for the given Id
  * In this case, we talk about "Aggregation Relation": V_Owner,V_InstanceOf.
  *
  * @param iRelationId
  *    The relation Id.
  * @param opRelation [out, CATBaseUnknown#Release]
  *    The CATPLMRelation Object.
  */
  HRESULT GetRelation(CATPLMStrongRelationshipId::eStrongRelId iStrongRelId, CATPLMRelation*& opRelation);

  /**
  *   @return
  *    S_OK: the type is visible, it will be returned by CATPLMDomain#ListTypes.<br>
  *    S_FALSE: the type is not visible, it will not be returned by CATPLMDomain#ListTypes.<br>
  *    E_FAIL: the operation failed.
  */
  HRESULT IsVisible();

  /**
  * Return if this CATPLMType is an Extension.
  *
  * @param oBaseTypeId * DEPRECATED
  *   Since an extension can extend several base types, if you need to know the extended types, use the API CATPLMType::ListExtendedType
  *
  * @return
  * <dt> <code>S_OK</code>     <dd> The type is an extension.
  * <dt> <code>S_FALSE</code>  <dd> The type is not an extension.
  * <dt> <code>E_FAIL</code>   <dd> The operation failed.
  */
  virtual HRESULT IsExtension(CATPLMTypeId* opBaseTypeId = NULL);

  /**
  * Return list of base type that extension extends.
  *
  * <br><b>Role</b>: Return list of base type that extension extends.
  *
  * @param CATLISTV(CATPLMTypeId)& oListTypeId [out]
  *
  * @return
  * <dt> <code>S_OK</code>          <dd> The type is an extension and extended type(s) have been retrieved.
  * <dt> <code>S_FALSE</code>       <dd> The type is not an extension.
  * <dt> <code>E_INVALIDARG</code>  <dd> oListTypeId.Size() !=0 at the begin of the method.
  * <dt> <code>E_FAIL</code>   <dd> The operation failed.
  */
  HRESULT ListExtendedType(CATLISTV(CATPLMTypeId)& oListBaseTypeId);

  /**
  * Return list of base type that extension extends.
  *
  * <br><b>Role</b>: Return list of base type that extension extends.
  *
  * @param oListType [out]
  *  WARNING : ptrs to be released by caller
  *
  * @return
  * <dt> <code>S_OK</code>          <dd> The type is an extension and extended type(s) have been retrieved.
  * <dt> <code>S_FALSE</code>       <dd> The type is not an extension.
  * <dt> <code>E_INVALIDARG</code>  <dd> oListTypeId.Size() !=0 at the begin of the method.
  * <dt> <code>E_FAIL</code>   <dd> The operation failed.
  */
  virtual HRESULT ListExtendedType(CATPLMTypeList & olBaseType);

  /**
  * @nodoc
  * @deprecated use @href CATPLMType::ListExtendedType with a CATOmxList
  */
  virtual HRESULT ListExtendedType(CATLISTP(CATPLMType)& olBaseType);

  /**
  *   Returns the Alias of the object. the name seen by the user
  * @param oAlias  [out, delete]
  */
  virtual HRESULT GetAlias(CATUnicodeString **oAlias);

  ///////////////////////////////////////////////////////////////
  // Fonction to convertion CATPLMType to and from CATIAdpType, CATIAdpExtType
  ///////////////////////////////////////////////////////////////
  /**
  * Get the @href CATPLMType from a @href CATIAdpType.
  *
  * <br><b>Role</b>: From an exposed @href CATIAdpType, retrieve the related @href CATPLMType which is restricted accessed from the PLM adapter.
  *
  * @param iAdpType [in]
  *   The provided adp type.
  * @param oPLMType [out, CATBaseUnknown#Release]
  *   The retrieved plm type.
  *
  * @return
  *   <code>S_OK</code> if the related plm type could be retrieved.
  *   <code>E_FAIL</code> otherwise.
  *
  */
  static HRESULT GetPLMTypeFromAdpType(CATIAdpType* iAdpType, CATPLMType  *& oPLMType);

  /**
  * Get the CATIAdpType from a CATPLMType.
  *
  * <br><b>Role</b>: From a CATPLMType which is restricted accessed from the PLM adapter, retrieve the related exposed CATIAdpType .
  *
  * @param iPLMType [in]
  *   The provided plm type.
  * @param oAdpType  [out, CATBaseUnknown#Release]
  *   The retrieved adp type.
  *
  * @return
  *   <code>S_OK</code> if the related adp type could be retrieved.
  *   <code>E_FAIL</code> otherwise.
  *
  */
  static HRESULT GetAdpTypeFromPLMTypeId(const CATPLMTypeId& iPLMTypeId, CATIAdpType *& oAdpType);

  /**
  * Get the CATIAdpExtType from a CATPLMType.
  *
  * <br><b>Role</b>: From a CATPLMType which is restricted accessed from the PLM adapter, retrieve the related exposed CATIAdpType .
  *                  This type has to be an extension.
  *
  * @param iPLMType [in]
  *   The provided plm type.
  * @param oAdpType  [out, CATBaseUnknown#Release]
  *   The retrieved adp type.
  *
  * @return
  *   <code>S_OK</code> if the related adp type could be retrieved  and is an extension.
  *   <code>E_FAIL</code> otherwise.
  *
  */
  static HRESULT GetAdpExtTypeFromPLMTypeId(const CATPLMTypeId& iPLMTypeId, CATIAdpExtType *& oAdpType);

  /**
  * Get the CATIAdpType from a CATPLMType.
  *
  * <br><b>Role</b>: From a CATPLMType which is restricted accessed from the PLM adapter, retrieve the related exposed CATIAdpType .
  *
  * @param iPLMType [in]
  *   The provided plm type.
  * @param oAdpType  [out, CATBaseUnknown#Release]
  *   The retrieved adp type.
  *
  * @return
  *   <code>S_OK</code> if the related adp type could be retrieved.
  *   <code>E_FAIL</code> otherwise.
  *
  */
  static HRESULT GetAdpTypeFromPLMType(const CATPLMType * iPLMType, CATIAdpType *& oAdpType);

  /**
  * Get the CATIAdpType from a CATPLMType.
  *
  * <br><b>Role</b>: From a CATPLMType which is restricted accessed from the PLM adapter, retrieve the related exposed CATIAdpType .
  *                  It has to be a PLM Extension
  * @param iPLMType [in]
  *   The provided plm type.
  * @param oAdpType  [out, CATBaseUnknown#Release]
  *   The retrieved adp type.
  *
  * @return
  *   <code>S_OK</code> if the related adp type could be retrieved and is an extension.
  *   <code>E_FAIL</code> otherwise.
  *
  */
  static HRESULT GetAdpExtTypeFromPLMType(const CATPLMType * iPLMType, CATIAdpExtType *& oAdpType);

  /**
  * Get the @href CATPLMType from a @href CATIAdpExtType.
  * (a CATIAdpExtType is the type of an extension)
  *
  * <br><b>Role</b>: From an exposed @href CATIAdpType, retrieve the related @href CATPLMType which is restricted accessed from the PLM adapter.
  *
  * @param iAdpType [in]
  *   The provided adp type.
  * @param oPLMType [out, CATBaseUnknown#Release]
  *   The retrieved plm type.
  *
  * @return
  *   <code>S_OK</code> if the related plm type could be retrieved.
  *   <code>E_FAIL</code> otherwise.
  *
  */
  static HRESULT GetPLMTypeFromAdpExtType(CATIAdpExtType* iAdpType, CATPLMType  *& oPLMType);

  /**
  * Check if the PLMType is equal to another type (like a CoreType).
  *
  * @param iType [in]
  *   The provided type to check.
  *
  * @return
  *   <code>S_OK</code> The type is equal to the provided type.
  *   <code>E_FAIL</code> otherwise.
  *   <code>E_INVALIDARG</code> ipType == NULL or ipType->_pClass == NULL.
  */
  HRESULT CheckEquality(const CATPLMType * ipType) const;

  /**
  * Returns TRUE if both objects are equal. Return FALSE otherwise.
  * Based on CheckEquality method.
  *
  * @param ipOther [in]
  *   The other type.
  *
  * @return
  *   TRUE if this == ipOther
  *   FALSE otherwise
  */
  CATBoolean Equals(const CATPLMType* ipOther) const;

  /**
  * Compares the current type to the other input type.
  *   1- It checks the other type nullity. Return 1 if input is NULL.
  *   2- It uses Equals method. Return 0 if equal.
  *   3- It compares Ids.
  *
  * @param ipOther [in]
  *   The other type.
  *
  * @return
  *   -1    this < ipOther
  *    0    this == ipOther
  *    1    this > ipOther
  */
  int CompareTo(const CATPLMType* ipOther) const;

  /**
  * Returns the hash code of the current type.
  * The hash code is based on the type's id hash.
  *
  * @return
  *   unsigned int: the computed hash code.
  */
  CATHashKey Hash() const;

  /**
  * Return TRUE if left and right types are equal. Return FALSE otherwise.
  * Note that if both inputs are NULL, it returns TRUE.
  *
  * @param ipLeft [in]
  *   The first type.
  * @param ipRight [in]
  *   The second type.
  *
  * @return
  *   TRUE if ipLeft == ipRight
  *   FALSE otherwise
  */
  static CATBoolean Equals(const CATPLMType* ipLeft, const CATPLMType* ipRight);

  /**
  * Compare the two input types.
  *   1- It checks inputs nullity. NULL object is always smaller than a not NULL object.
  *   2- It uses the instance method CompareTo.
  *
  * @param ipLeft [in]
  *   The first type.
  * @param ipRight [in]
  *   The second type.
  *
  * @return
  *   -1    ipLeft < ipRight
  *    0    ipLeft == ipRight
  *    1    ipLeft > ipRight
  */
  static int Compare(const CATPLMType* ipLeft, const CATPLMType* ipRight);

  /**
  * Return the hash code of input type.
  *
  * @param ipType [in]
  *   The type you want to process.
  * @param oHash [out]
  *   The hash code computed.
  *
  * @return
  *   <code>S_OK</code> The hash code has been computed correctly.
  *   <code>E_INVALIDARG</code> ipType == NULL
  */
  static HRESULT Hash(const CATPLMType* ipType, CATHashKey& oHash);

  /**
  * Check if the PLMType inherits from another type (like a CoreType).
  *
  * @param iFatherType [in]
  *   The provided father type to check.
  *
  * @return
  *   <code>S_OK</code> The type inherits from the provided type.
  *   <code>E_FAIL</code> otherwise.
  *   <code>E_INVALIDARG</code> iFatherType == NULL or iFatherType->_pClass == NULL.
  */
  HRESULT InheritsFrom(const CATPLMType * iFatherType);

  HRESULT IsKindOf(const CATPLMTypeH &iSuper) const;

  /**
  * Check if a discipline can be used on a PLMType.
  *
  * @param iDisciplineName [in]
  *   The discipline to check on the type.
  *
  * @param iCreationMode [in]
  *   TRUE  : Check if the discipline is authorised on the type at Creation time.
  *   FALSE : Check if the discipline is authorised on the type at modification time.
  *
  * @param oAuthorized [out]
  *   The output flag.
  *
  * @return
  *   <code>S_OK</code> The discipline was found on the type.
  *   <code>E_FAIL</code> otherwise (oAuthorised is set to FALSE by default in this case).
  */
  HRESULT IsDisciplineAuthorized(const CATString& iDisciplineName, CATBoolean &oAuthorized);
  /**
  *@deprecated use @href CATPLMType::IsDisciplineAuhtorized with 2 arguments
  */
  HRESULT IsDisciplineAuhtorized(const CATString& iDisciplineName, const boolean iCreationMode, boolean& oAuthorized);

  /**
  * Return the list of Attribute to be returned by a given operation.
  *
  * @param iOperation [in]
  *   The operation to check.

  * @param oAttrNames [out]
  *   The list of attribute names.
  *
  * @return
  *   <code>S_OK</code> The attributes were found.
  *   <code>E_FAIL</code> An error occurs.
  *
  */
  HRESULT GetAttributeListForOperation(CATString &iOperation, CATLISTV(CATString) &oAttrNames);

  /**
  * If the Type is a Connection, returns if the Connection is Structured or not.
  * @return
  *    <ul>
  *    <li>S_OK     The Type is a Structured Connection.</li>
  *    <li>S_FALSE  The Type is a Connection not Structured.</li>
  *    <li>E_FAIL   The Type is not a Connection.</li>
  *    </ul>
  */
  HRESULT IsStructuredConnection();

  /**
  * Returns the CAA exposition of the type.
  * @param oCAAExposition [out]
  *   The level of exposition of the type
  * @return
  *    <ul>
  *    <li>S_OK     Everything is OK.</li>
  *    <li>E_FAIL   Otherwise.</li>
  *    </ul>
  */
  HRESULT GetCAAExposition(CATPLMAttrCAAExposition &oCAAExposition);

  /**
  * Checks that a displine is exposed or not on the type.
  * @param iDisciplineName [in]
  *   The discipline to check on the type.
  * @return
  *    <ul>
  *    <li>S_OK     The discipline is exposed.</li>
  *    <li>S_FALSE  The discipline is not exposed.</li>
  *    <li>E_FAIL   The discpline does not exist or something goes wrong.</li>
  *    </ul>
  */
  HRESULT IsDisciplineExposed(const CATString &iDisciplineName);

  /**
  * Checks that a displine is a custo discipline or not.
  * Note : This service does not test if the discipline is authorised on the type or not.
  * @param iDisciplineName [in]
  *   The discipline to check on the type.
  * @return
  *    <ul>
  *    <li>S_OK     The discipline is a custo discipline.</li>
  *    <li>S_FALSE  The discipline is not a custo discipline.</li>
  *    <li>E_FAIL   The discpline does not exist or something goes wrong.</li>
  *    </ul>
  */
  HRESULT IsCustoDiscipline(const CATString &iDisciplineName);

  /**
  * Returns the relation (SR relation)
  * In this case, we talk about SR relation only and not "Aggregation relation"
  *
  *   @param iCategory
  *   @param iRole
  *   @param oSubRelation[out,CATBaseUnknown#Release]
  *        The list of sub Relations of this Type.
  *   @param iOnlyVisible
  *        If not 0 returns only UI visible SubRelations.
  *        If 0 returns all SubRelations of PLMType
  *   @return
  *        S_OK:          operation succeeded and object was found.
  *        E_FAIL:        an unknown error has occured.
  *        E_INVALIDARG:  oSubRelation!=NULL before the call to GetSubRelation
  */
  HRESULT GetSubRelation(CATString & iCategory, CATString & iRole, CATPLMRelation **oSubRelation, int iOnlyVisible = 0);

  enum PLMMetaType { EntityType, RelationType, ExtensionType, ComplexType, FlatTable, Undefined };

  /**
  * Returns the meta type ER type (EntityType, RelationType, ExtensionType) + Complex type for Port and connection.
  *
  *   @param oMetaType
  *        The MetaType of the CATPLMType.
  *        On CBP type, returns EntityType, RelationType, ExtensionType
  *        On VPLM type:
  *           - returns EntityType    for PLMCoreReference and PLMCoreRepReference and PLMReference
  *           - returns RelationType  for PLMCoreInstance and PLMCoreRepInstance and PLMInstance
  *           - returns ExtensionType for extensions
  *           - returns ComplexType   for PLMConnection and PLMPort
  *
  * Exception:
  * CacheInstance => RelationType (<= it doesn't exist on M1)
  * WspTableEntry => EntityType   (<= for sure it is a mistake and need to manage impact or to live with that...)
  * HistoryEntry  => EntityType   (<= not used anymore, replaced by a pure flat table)
  *
  * For pure M1 view, please use CATPLMTypeId_Classification GetClassification()
  */
  HRESULT GetMetaType(CATPLMType::PLMMetaType& oMetaType);

  CATPLMType::PLMMetaType GetMetaType();

  /**
  * Service to retrieve the name of the owner attribute for a given type.
  * @param oAttrName [out]
  *   The attribute Name.
  * @return
  *   <code>S_OK</code> The Attribute exist on CATPLMType.
  *   <code>E_FAIL</code> An error occurs .
  */
  HRESULT GetOwnerAttributeName(CATString & oAttrName);

  /**
  * Service to retrieve the name of the organization attribute for a given type.
  * @param oAttrName [out]
  *   The attribute Name.
  * @return
  *   <code>S_OK</code> The Attribute exist on CATPLMType.
  *   <code>E_FAIL</code> An error occurs .
  */
  HRESULT GetOrganizationAttributeName(CATString & oAttrName);

  /**
  * Service to retrieve the name of the project attribute for a given type.
  * @param oAttrName [out]
  *   The attribute Name.
  * @return
  *   <code>S_OK</code> The Attribute exist on CATPLMType.
  *   <code>E_FAIL</code> An error occurs .
  */
  HRESULT GetProjectAttributeName(CATString & oAttrName);

  /**
  * Service to retrieve the name of the revision attribute for a given type.
  * @param oAttrName [out]
  *   The attribute Name.
  * @return
  *   <code>S_OK</code> The Attribute exist on CATPLMType.
  *   <code>E_FAIL</code> An error occurs .
  */
  HRESULT GetRevisionAttributeName(CATString & oAttrName);

  /**
  * Service to retrieve the name of the major revision attribute for a given type.
  * @param oAttrName [out]
  *   The attribute Name.
  * @return
  *   <code>S_OK</code> The Attribute exist on CATPLMType.
  *   <code>E_FAIL</code> An error occurs .
  */
  HRESULT GetMajorRevisionAttributeName(CATString & oAttrName);

  /**
  * Service to retrieve the name of the maturity attribute for a given type.
  * @param oAttrName [out]
  *   The attribute Name.
  * @return
  *   <code>S_OK</code> The Attribute exist on CATPLMType.
  *   <code>E_FAIL</code> An error occurs .
  */
  HRESULT GetMaturityAttributeName(CATString & oAttrName);

  /**
  * Service to retrieve the name of the CreationDate attribute for a given type.
  * @param oAttrName [out]
  *   The attribute Name.
  * @return
  *   <code>S_OK</code> The Attribute exist on CATPLMType.
  *   <code>E_FAIL</code> An error occurs .
  */
  HRESULT GetCreationDateAttributeName(CATString & oAttrName);

  /**
  * Service to retrieve the name of the Modification attribute for a given type.
  * @param oAttrName [out]
  *   The attribute Name.
  * @return
  *   <code>S_OK</code> The Attribute exist on CATPLMType.
  *   <code>E_FAIL</code> An error occurs .
  */
  HRESULT GetModificationAttributeName(CATString & oAttrName);

  /**
  * Service to retrieve the name of the Reserved attribute for a given type.
  * @param oAttrName [out]
  *   The attribute Name.
  * @return
  *   <code>S_OK</code> The Attribute exist on CATPLMType.
  *   <code>E_FAIL</code> An error occurs .
  */
  HRESULT GetReservedAttributeName(CATString & oAttrName);

  /**
  * Service to retrieve the name of the Reserved attribute for a given type.
  * @param oAttrName [out]
  *   The attribute Name.
  * @return
  *   <code>S_OK</code> The Attribute exist on CATPLMType.
  *   <code>E_FAIL</code> An error occurs .
  */
  HRESULT GetReservedAttributeType(AttrTypes & oAttrType);

  /**
  * Service to retrieve the name of the ReservedBy attribute for a given type.
  * @param oAttrName [out]
  *   The attribute Name.
  * @return
  *   <code>S_OK</code> The Attribute exist on CATPLMType.
  *   <code>E_FAIL</code> An error occurs .
  */
  HRESULT GetReservedByAttributeName(CATString & oAttrName);

  /*
  * Checks that type is abstract or not
  * @return
  *  <ul>
  *   <li>S_OK     The type is abstract.</li>
  *   <li>S_FALSE  The type is not abstract.</li>
  *   <li>E_FAIL   an error occurs.</li>
  *  </ul>
  */
  HRESULT IsAbstract();

  /*
  * Checks the property with a specified value
  * @return
  *  <ul>
  *   <li>S_OK     The property exists and has the right value.</li>
  *   <li>E_FAIL   The property doesn't have the right value.</li>
  *  </ul>
  */
  HRESULT CheckPropertyValue(const char *iPropertyName, const char *iPropertyValueToCheck);

  /**
  * For CATPLMType that are in fact relationships, it indicates the kind of relationship
  * @return
  *  <ul>
  *   <li>S_FALSE  The PLMType is not a relation (it is an extension or an RPC or an Entity.</li>
  *   <li>S_OK     The PLMType is a relation
  *  </ul>
  */
  HRESULT GetRelationNature(PLMDictionaryDefinitions::PLMRelationshipTypeNature &oNature);

  /**
  * For CATPLMType that are in fact objects, it indicates the kind of object
  * @return
  *  <ul>
  *   <li>S_FALSE  The PLMType is not an object (it is an extension or a RelationShip not seen as an object.</li>
  *   <li>S_OK     The PLMType is an object
  *  </ul>
  */
  HRESULT GetObjectNature(PLMDictionaryDefinitions::PLMObjectTypeNature &oNature);

  /**
  * For CATPLMType that are in fact objects, it indicates the level of the type
  * @return
  *  <ul>
  *   <li>S_FALSE  The PLMType is not an object (it is an extension).</li>
  *   <li>S_OK     The PLMType is a type
  *  </ul>
  */
  HRESULT GetTypeLevel(PLMDictionaryDefinitions::PLMTypeLevel &oLevel);

  /**
  * For CATPLMType that are in fact extensions
  * @return
  *  <ul>
  *   <li>S_FALSE  The PLMType is not an extension.</li>
  *   <li>S_OK     The PLMType is an extension type
  *  </ul>
  */
  HRESULT GetExtensionLevel(PLMDictionaryDefinitions::PLMExtensionLevel &oLevel);

  /**
  * Tests if a given operation is available on an object.<br>
  * @param iOperationToTest
  * Operation we want to test
  * @param oAvailable
  * Indicates if the operation is available (result valid even if HRESULT=S_FALSE;
  *  <ol>
  *    <li> TRUE if the operation is available
  *    <li> FALSE instead
  *  </ol>
  * @return
  *  <ol>
  *    <li> S_FALSE if this kind of object never supports the operation
  *    <li> S_OK if the service has answered the question.
  *  </ol>
  */
  HRESULT SupportsOperation(const PLMDictionaryDefinitions::PLMOperationSupport iOperationToTest,
    CATBoolean     &oAvailable);

  /**
  * Returns the modeler associated to the type.
  * @param oModelerName
  *   The name of the associated modeler in the metadata
  * @return
  *  <ol>
  *    <li> S_OK if the the modeler can be retrieved.
  *    <li> E_FAIL if the type does not have a modeler associated.
  *  </ol>
  */
  HRESULT GetModelerName(CATUnicodeString &oModelerName);

  /**
  * Asks what kind of data features are supported bu this type of objects
  * @param iDataFeature
  * DataFeature that we want to know if it is supported
  * @param oIsSupported
  * Indicates if it is supported or not
  * @return
  *  <ol>
  *    <li> S_OK
  *  </ol>
  */
  HRESULT IsDataFeatureSupported(const PLMDictionaryDefinitions::PLMDataFeaturesSupport iDataFeature, CATBoolean &oIsSupported);

  /**
  * Returns the instance type declared in the metadata.
  * @param oPreferedInstanceName
  *   The name of the associated instance type in the metadata
  * @return
  *  <ol>
  *    <li> S_OK	 if the instance type can be retrieved.
  *    <li> E_FAIL if nothing found.
  *  </ol>
  */
  HRESULT GetPreferedInstanceWithInheritance(CATUnicodeString &oPreferedInstanceName);

  HRESULT CanExtend(const CATPLMTypeH& iBaseType);

  /**
  * @return
  *  <ul>
  *   <li>S_OK     The type is CAADERIVABLE. Default for Relation. MULTIPLE is also considered as CAADerivable.</li>
  *   <li>S_FALSE  The type is not CAADERIVABLE.</li>
  *   <li>E_FAIL   an error occurs.</li>
  *  </ul>
  */
  HRESULT IsCAADerivable();

  CATBoolean HasRelation(const CATUnicodeString &iRelName);

  CATBoolean IsBasicAttribute(const CATOmxKeyString &iAttrName);

  //oAttrKind contains what is necessary for TCL parser and not what is necessary for CATOmxAny
  // Strange thing: For tcl parser I need to convert:
  // 1-PLMTYPE_DATE into (omx_time) instead of (omx_int64,omx_time) for CATOmxAny
  // 2-PLMTYPE_BINARY into omx_binary instead of (omx_any,omx_octet) for CATOmxAny
  // 3-PLMTYPE_ENUM into omx_enum instead of (omx_IUnknown,omx_enum) for CATOmxAny
  // Conversion result is different from what we find we we retrieve CATOmxKind associated to a CATOmxAny...
  // we have omx_uuid too for physicalid...
  HRESULT GetBasicAttributeProperties(const CATOmxKeyString &iAttrName, CATOmxKind& oAttrKind, CATBoolean& oIsMultivaluated, CATBoolean& oIsAcceptEmpty, CATBoolean& oIsFlattened);

  HRESULT GetPossibleExtensions(CATListOfCATUnicodeString &oUsableExtensionNameList);

  virtual HRESULT IsIRPCExtension();

  /**
  * Service to retrieve the name of the physicalid attribute for a given type.
  * @param oAttrName [out]
  *   The attribute Name.
  * @return
  *   <code>S_OK</code> The Attribute exist on CATPLMType.
  *   <code>E_FAIL</code> An error occurs .
  */
  HRESULT GetPhysicalIdAttributeName(CATString & oAttrName);

  /**
  * Service to retrieve the name of the logicalid attribute for a given type.
  * @param oAttrName [out]
  *   The attribute Name.
  * @return
  *   <code>S_OK</code> The Attribute exist on CATPLMType.
  *   <code>E_FAIL</code> An error occurs .
  */
  HRESULT GetLogicalIdAttributeName(CATString & oAttrName);

  /**
  * Service to retrieve the name of the logicalid attribute for a given type.
  * @param oAttrName [out]
  *   The attribute Name.
  * @return
  *   <code>S_OK</code> The Attribute exist on CATPLMType.
  *   <code>E_FAIL</code> An error occurs .
  */
  HRESULT GetMajorIdAttributeName(CATString & oAttrName);

  /**
  * Service to retrieve the name of the cestamp attribute for a given type.
  * @param oAttrName [out]
  *   The attribute Name.
  * @return
  *   <code>S_OK</code> The Attribute exist on CATPLMType.
  *   <code>E_FAIL</code> An error occurs .
  */
  HRESULT GetCEstampAttributeName(CATString & oAttrName);

  /**
   * Looks for the value of a given property, using type inheritance
   * to find the value if not available on the type.
   * @param iPropertyName [in] :
   *   The name of the property
   * @param oPropertyValue [out] :
   *   The value of the property, as found on the best matching type
   *   in the type inheritance tree.
   * @return
   *    S_OK : the property has been found
   *    S_FALSE : the property hasn't been found on type of the hierarchy
   *    E_* : error in the treatment
   */
  HRESULT GetPropertyValueWithInheritance(const CATUnicodeString& iPropertyName, CATUnicodeString & oPropertyValue);

  CATBoolean IsMinorVersionable();

  CATBoolean IsParentOfMinorVersionableType();

  /** Must be called to insure correct lifecycle. */
  void LogicalRemove();
  /** inherited from CATBaseUnknown. */
  int IsNull() const;

  HRESULT GetPackageName(CATString& oPackageName);

#if !defined(_WINDOWS_SOURCE) || \
  defined(__CATPLMServicesItf) || \
  defined(__CATPLMImplAdapterBase) || \
  defined (__TonModule)
  /**
  * Method implemented for Switch of Security Context Project
  * When switch of context occurs, need to invalid attributes.
  * Switch of Context can only be made if you are connected to one and only one provider: M1.
  */
  HRESULT InvalidAndResetAttrsOnSwitchOfCtx();

  /**
  * Method implemented for Switch Security Context Project
  * When switch context occurs, need to invalid attributes.
  */
  CATBoolean IsValidAttrsRegardingCtx() const;

  /**
  * Method implemented for Switch Security Context Project
  * With rebuild of attributes after switch of context, need to declare validity of attributes.
  */
  void ValidateAttrsRegardingCtx();
#endif

  /**
  * Suppose you have following data structure:
  * A (VPMRepReference)
  * (physicalid_A, logicalid_A, majorid_A)
  *  ^
  * |
  *from
  * |
  * | _ B (DerivedOutputRelationship)-------------------- - to-------------- > C (DerivedOutputEntity)
  *     (physicalid_B, logicalid_B, majorid_B)                                 (physicalid_C, logicalid_C, majorid_C)
  *
  * Suppose CATPLMType contains DerivedOutputEntity.
  * GetInstantiationOwnerTypes returns PLMCoreRepReference
  * Indeed, in metadata, we find:
  * <Class Name="DerivedOutputEntity"
  *  ...
  *  InstantiationOwnerTypes="PLMCoreRepReference"
  *  ...
  *  ObjectNature="Aggregated"
  * </Class>
  */
  HRESULT GetInstantiationOwnerTypes(CATPLMTypeList& oListOfTypes);

  HRESULT CanExtendSR();

  /**
  * Pure M1 view, complex types are seen like BO <=> TypeIdClassification_Entity:
  * PLMMetaType == EntityType    => TypeIdClassification_Entity
  * PLMMetaType == RelationType  => TypeIdClassification_Relation
  * PLMMetaType == ExtensionType => TypeIdClassification_Extension
  * PLMMetaType == ComplexType   => TypeIdClassification_Entity
  *
  * Exception:
  * CacheInstance => TypeIdClassification_Relation (<= it doesn't exist on M1)
  * WspTableEntry => TypeIdClassification_Entity   (<= for sure it is a mistake and need to manage impact or to live with that)
  * HistoryEntry  => TypeIdClassification_Entity   (<= not used anymore, replaced by a pure flat table)
  * Error         => TypeIdClassification_Unset
  *
  * For usage on Rich client, please use HRESULT GetMetaType(CATPLMType::PLMMetaType &oMetaType)
  */
  CATPLMTypeId_Classification GetClassification();

protected:
  /** @nodoc */
  VPMIDicClass * _pClass;   // To access through different PLMType
  VPMIDicRelationClass * _pRelClass;
  VPMIDicMgr * _pDicMgr;

private:
  enum CATPLMKindOfPath { eLocal = 1, eGlobal = 2, eAll = 3 };

  /*
  * Specify the mode that is used when we use GetTypeId (CATPLM_NORESTRICTION , CATPLM_BASICRESTRICTIONS)
  *
  * Default mode: CATPLM_BASICRESTRICTIONS
  * In default mode, it is forbidden to retrieve TypeId that are on layer PLMABSTRACT or on layer PLMCORE
  *
  *   @param iMode
  *
  *   @return
  */
  void SetTypeIdMode(CATPLMTypeIdMode iMode);

  /**
  * Checkl if extension are declared on the type in the PLMDictionary.
  * @return
  *    <ul>
  *    <li>S_OK     The Type has one or several extensions declared.</li>
  *    <li>S_FALSE  The Type does not have extension or is an extension itself.</li>
  *    <li>E_FAIL   A problem occurs.</li>
  *    </ul>
  */
  virtual HRESULT HasPossibleExtension();

  /**
  * Returns the element's NLSTag.
  * @param oNLSTag : NLSTag
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  HRESULT GetNLSTag(CATUnicodeString & oNLSTag);

  HRESULT GetNLSValue(CATUnicodeString & oNLSVal);

  HRESULT GetUuid(CATDbBinary &oUuid);

  CATPLMType(const CATPLMTypeId& iPLMTypeId, CATString *iId, CATIPLMProviderDesc * iProvider);

  HRESULT IsVPMIDicVisible();

  HRESULT GetTypeIdFromClass(VPMIDicClass* ipClass, CATPLMTypeId* opTypeId);

  HRESULT GetTypeIdFromRelationClass(VPMIDicRelationClass* ipClass, CATPLMTypeId* opTypeId);

  /**
  * Returns the lists of couple type / PLM attribute from a UKId. Restricted Use.
  * @param oListTypes
  *   The List of Types. A NULL value means that we are on the current PLMType. A not NULL type means that we are on a extension.
  *   Each value has to be released by the caller service after use.
  * @param oListAttributes
  *   The List of attribute. Its PLM type can be found in the first list. Each value has to be released by the caller service after use.
  * @return
  *  <ol>
  *    <li> S_OK          if at least one attribute is retrieved.
  *    <li> E_INVALIDARG  invalid UKId
  *    <li> E_FAIL        if something is wrong.
  *  </ol>
  */
  HRESULT GetTypesAndAttributesFromUKId(const CATUnicodeString & iUKId, CATPLMTypeList &oListTypes, CATPLMAttributeList &oListAttributes);

  /**
  * Returns the lists of UKId. Restricted Use.
  * @param oListUKId
  *   The List of UniqueKey Id.
  * @return
  *  <ol>
  *    <li> S_OK   if at least one UKId is retrieved.
  *    <li> E_FAIL if something is wrong or if there is no avalaible UKId.
  *  </ol>
  */
  HRESULT GetListOfUKId(CATListOfCATUnicodeString& oListUKId);

  HRESULT ComputeTable();

  void _Dump(CATPLMMask iMask);

  void _Dump(CATPLMMask iMask, const CATString& iAttrName);

  HRESULT _GetTypeIdFromGenericClass(VPMIDicGenericClass* ipGenericClass, CATPLMTypeId& oTypeId);

  HRESULT _ComputeSubRelation();

  HRESULT _ComputePathTypeH(CATPLMKindOfPath iKindOfPath);

  HRESULT _GetPathTypeH(const CATOmxKeyString& iPathTypeName, const CATOmxKeyString& iRole, const CATOmxKeyString& iCategory,
    CATPLMKindOfPath iKindOfPath, CATPLMUnicodeStringToPathTypeHMap& iMapLocalPTNWithPT,
    CATPLMPathTypeH& oPathType);

  // no AddRef!!!!
  CATPLMAttributeInternal* _QueryAttribute(const CATOmxKeyString &iAttributeId);

  void _DetectCollision(CATPLMMask iMask, CATPLMAttribute* ipOldAttribute, CATPLMAttributeInternal* ipNewAttribute);

  CATPLMMask _ReplaceNULLByDefaultMask(CATPLMMask iMask);

  /*
  *   @param opAttribute [out, CATBaseUnknown#Release]
  */
  HRESULT _GetMaskedAttr(const CATOmxKeyString& iAttributeId, CATPLMAttributeInternal*& opAttribute);

  /*
  *   @param opElem [out, CATBaseUnknown#Release]
  */
  HRESULT _GetMaskedAndUnmaskedAttr(const CATOmxKeyString& iAttributeId, VPMIDicElement*& opElem);

  HRESULT AddAttribute(CATPLMMask iMask, VPMIDicUsingAttributeMask* ipUAM, const CATOmxArray<CATUnicodeString>& iOperators);

  HRESULT _AddAttribute(CATPLMMask iMask, VPMIDicUsingAttributeMask *ipUAM, int iPosition, const CATOmxArray<CATUnicodeString>& iOperators);

  HRESULT _GetProvMgr(CATIPLMProviderMgr*& opProvMgr);//No AddRef

  CATString *_pDomainId;
  CATOmxKeyString _ModelerName;

  // This map only contains masked attributes. It is not enough for CATPLMPrivateAttributeServices::GetModelerAttributeType() that works on mask/unmasked attributes
  CATPLMTypeInternal &_internal;

  CATListPtrCATPLMCommand *_pCommands;
  CATListPtrCATPLMRelation *_pRelations;
  CATBoolean _isStrongRelationComputed;
  CATUnicodeString _ListConnectedRepoForStrongRel;

  CATListPtrCATPLMRelation *_pSubRelations;
  CATBoolean _isSubRelationComputed;
  CATUnicodeString _ListConnectedRepoForSubRel;

  short _isVisible;

  CATBoolean _isLocalPathTypeComputed;
  CATUnicodeString _ListConnectedRepoForLocalPathType;

  // PTNWithPT
  // PTN <=> Aggregating Type Name.Path Type Name or Path Type Name
  // PT <=> Path Type
  CATPLMUnicodeStringToPathTypeHMap _mapLocalPTNWithPTWithInherit;
  CATPLMUnicodeStringToPathTypeHMap _mapLocalPTNWithPTWithoutInherit;

  CATBoolean _isGlobalPathTypeComputed;
  CATUnicodeString _ListConnectedRepoForGlobalPathType;

  // PTNWithPT
  // PTN<=> Aggregating Type Name.Path Type Name or Path Type Name
  // PT <=> Path Type
  CATPLMUnicodeStringToPathTypeHMap _mapGlobalPTNWithPTWithInherit;
  CATPLMUnicodeStringToPathTypeHMap _mapGlobalPTNWithPTWithoutInherit;

  CATPLMTypeId _TypeId;
  CATPLMTypeId _SuperTypeId;
  CATPLMTypeId _SuperTypeIdNoRestriction;
  static const char  * _pDisableTiechain;
  IUnknown          **_TbInherits;
  int                 _TbInherits_Size;
  int                 _TbInherits_NbElem;

  CATPLMTypeIdMode _TypeIdMode;
  HRESULT _RCSuperType;
  HRESULT _RCSuperTypeNoRestriction;

  int _TypeOrExtensionLevel; // contient le niveau du type ou de l'extension (sa couleur ds le nouveau typage): -1 si pas encore calcule
  int _TypeNature;   // contient la nature "objet" du type: -1 si pas encore calcule. -2 si pas un type d'objet (une extension par exemple)
  int _RelationNature;   // contient la nature "relation" du type: -1 si pas encore calcule. -2 si pas une relation

  CATPLMCoreType      _CoreType;
  int _isExtension;

  // For each mask, we have a list of attributes
  // When we build attributes for a mask, we declare that job has been made using this data structure
  CATOmxOSet<int> _setOfAttributesMaskAlreadyBuilt;
  CATPLMIntToDicMaskMap _mapMaskWithDicMask;

  CATIPLMProviderMgr* _pProvMgr;

  static CATLONG32 _nb;

  // multi connection
  CATUnicodeString _ListConnectedRepoForAttr;//List connected providers when ipType->_internal.attribute is built

  // switch of security context (Ctx) only supported by PLM1
  CATBoolean _isValidWithCurrentCtx;//When switch of context is made, _isValid becomes FALSE. Need to rebuild ipType->_internal.attribute using CATPLMTypeAttributesLoader::BuildAttributes(...) to set _isValid to TRUE

  //AddRef made by current method, please release it!
  CATIPLMBasicAttributes* _GetToolsFactory();

  void _DeclareInvalidInstantiationOwnerTypes(CATPLMType* ipInvalidType);

  void _DeclareUseOfCacheInstance();

  CATPLMTypeList _listOwnerTypes;
  CATBoolean _isListOwnerTypesBuilt;

  CATOmxSR<CATIPLMBasicAttributes> _spBasicAttribute;

  CATBoolean _isMetaTypeAlreadyBuilt;
  PLMMetaType _metaType;
};

template<> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMType*>::manager();

#endif
