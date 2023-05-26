#ifndef CATPLMPrivateTypeServices_H
#define CATPLMPrivateTypeServices_H
// COPYRIGHT DASSAULT SYSTEMES 2007

/**
* @level Private
* @usage U1
*/

#undef ExportedByCATPLMPrivateAccess  
#if defined (private) || defined(friend) || defined (protected)

  #error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 
#endif

#define AuthorizedModule     999
// List of authorized infrastructure modules 
#define CATPLMServicesItf               AuthorizedModule
#define CATPLMServicesOmx               AuthorizedModule
#define VPLMIndexerToolbox              AuthorizedModule
#define TSTCATPLMxMetaData              AuthorizedModule
#define CATPLMQL_Visitor                AuthorizedModule
#define PLMQLEditorUI                   AuthorizedModule
#define CATPLMAdapterEKLBinding         AuthorizedModule
#define PLMQLInEKLDebug                 AuthorizedModule
#define CATPLMImplAdapterQLBase         AuthorizedModule
#define TSTCATPLMTypeServices           AuthorizedModule
#define CATPLMREDataAccessor            AuthorizedModule
#define CATPLMImplAdapterBase           AuthorizedModule
#define CATPLMMLDicoCheckEngine         AuthorizedModule
#define TSTCATPLMMLUIDebug              AuthorizedModule
#define TSTCATPLMMLCusto                AuthorizedModule
#define XPGXMLInOutputer                AuthorizedModule
#define CATPLMTaxon                     AuthorizedModule
#define CATPLMMLEngine                  AuthorizedModule
#define CATPLMMLDicoBaseType            AuthorizedModule
#define CATPLMIntegrationAccess         AuthorizedModule
#define TSTCATPLMxMetadataIRPCER2       AuthorizedModule
#define TSTCATPLMDbgNewTyping3          AuthorizedModule
#define CATPLMTagModeler                AuthorizedModule
#define TSTCATPLMDbgBasicQueryOnER1     AuthorizedModule
#define CATImmSearchRefine              AuthorizedModule
#define PLMSRMQueryServices             AuthorizedModule
#define CATPLMModelBuilder              AuthorizedModule
#define CATPLMiPMLDataStream            AuthorizedModule
#define TstTestEngineUtilities          AuthorizedModule
#define CATPLMxReadWriteXMQL            AuthorizedModule
#define CATTCLThreadSafe                AuthorizedModule
#define CATTCLRecordBuilderMainThread   AuthorizedModule
#define TSTCATPLMCATPLMTypeServices     AuthorizedModule
#define CATOmbStreamsImporter           AuthorizedModule
#define TSTCATPLMxSRWithExtCreateOnly   AuthorizedModule
#define CATPLMDebugProviderImpl         AuthorizedModule
#define TSTCATPLMxSaveER2               AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else
  #error Forbidden Access To CATPLMPrivateTypeServices from a non-authorized module
  // Fatal error on solaris
  @error 
#endif
#undef CATPLMServicesItf
#undef CATPLMServicesOmx
#undef VPLMIndexerToolbox
#undef TSTCATPLMxMetaData
#undef CATPLMQL_Visitor
#undef PLMQLEditorUI
#undef CATPLMAdapterEKLBinding
#undef PLMQLInEKLDebug
#undef CATPLMImplAdapterQLBase 
#undef TSTCATPLMTypeServices
#undef CATPLMREDataAccessor
#undef CATPLMImplAdapterBase
#undef CATPLMMLDicoCheckEngine
#undef TSTCATPLMMLUIDebug
#undef TSTCATPLMMLCusto
#undef XPGXMLInOutputer
#undef CATPLMTaxon
#undef CATPLMMLEngine
#undef CATPLMMLDicoBaseType
#undef CATPLMIntegrationAccess
#undef TSTCATPLMxMetadataIRPCER2
#undef TSTCATPLMDbgNewTyping3
#undef CATPLMTagModeler
#undef TSTCATPLMDbgBasicQueryOnER1
#undef CATImmSearchRefine
#undef PLMSRMQueryServices
#undef CATPLMModelBuilder
#undef CATPLMiPMLDataStream
#undef TstTestEngineUtilities
#undef CATPLMxReadWriteXMQL
#undef CATTCLThreadSafe
#undef CATTCLRecordBuilderMainThread
#undef TSTCATPLMCATPLMTypeServices
#undef CATOmbStreamsImporter
#undef TSTCATPLMxSRWithExtCreateOnly
#undef CATPLMDebugProviderImpl
#undef TSTCATPLMxSaveER2

#if defined(__CATPLMServicesItf)
#define ExportedByCATPLMPrivateAccess DSYExport
#else
#define ExportedByCATPLMPrivateAccess DSYImport
#endif
#include "DSYExport.h"


#include "CATListOfCATString.h"
#include "IUnknown.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATPLMOmxCollections.h"
#include "CATOmxSet.h"
#include "CATOmxOMap.h"
#include "AttrTypes.h"

#include "CATIAV5Level.h"

class CATPLMType;
class CATOmxKeyString;

#include "CATLISTP_Declare.h"
class CATLISTP(CATPLMType);
class CATListPtrCATPLMAttribute;
class CATPLMAttribute;

/**
 * RESTRICTED TOOLBOX for special Type API access
 * Must be called only by xMQL code
 * Part of this code may be called in different threads at the same time
 * It means it must be threadsafe
 * None ThreadSafe code must be done in the constructor
 * @nodoc
 */
class ExportedByCATPLMPrivateAccess CATPLMPrivateTypeServicesForSRBuilder
{
public:
  // Singleton
  static const CATPLMPrivateTypeServicesForSRBuilder& get();

  // Returns "" if not found
  // iCategoryIndex >=1
  CATUnicodeString GetSRCategoryNameFromIndex ( int iCategoryIndex ) const;

  // Returns "" if not found
  // iRoleIndex >=1
  CATUnicodeString GetSRRoleNameFromIndex ( int iRoleIndex ) const;

  // if KO, Returns -1 if not found
  // if OK, int returned >=1
  int GetIndexFromSRCategory(const CATUnicodeString& iCategory) const;

  // if KO, Returns -1 if not found
  // if OK, int returned >=1
  int GetIndexFromSRRole(const CATUnicodeString& iRole) const;

private:
  CATPLMPrivateTypeServicesForSRBuilder();
  ~CATPLMPrivateTypeServicesForSRBuilder();

  CATOmxOMap<int,CATUnicodeString> _IndexToCategory;
  CATOmxOMap<int,CATUnicodeString> _IndexToRole;

  CATOmxOMap<CATUnicodeString,int> _CategoryToIndex;
  CATOmxOMap<CATUnicodeString,int> _RoleToIndex;
};


/**
 * RESTRICTED TOOLBOX for special Type API access
 * @nodoc
 */
class ExportedByCATPLMPrivateAccess CATPLMPrivateTypeServices
{
public:

  /**
  * This method computes a CATPLMType from a doublette (CATUnicodestring)
  * The caller must give a valid reference to a CATPLMType pointer.
  * Returns S_OK if the returned CATPLMType is valid, E_FAIL otherwise.
  * Expected iDoublette format : DomainName/TypeName
  * @nodoc
  */
  static HRESULT GetPLMTypeFromDoublette (const CATUnicodeString& iDoublette, CATPLMType ** oType);
  static HRESULT GetPLMTypeFromDoublette (const CATOmxKeyString& iDoublette, CATPLMType ** oType);

  /**
  * This methods is computing a doublette CATUnicodestring from a triplette one.
  * Expected iTriplette format : Custo/Modeler/CoreType or Modeler/CoreType if no Custo available
  * Output  oDoublette  format : DomainName/TypeName
  * @nodoc
  */
  //static HRESULT GetDoubletteFromTriplette (const CATUnicodeString& iTriplette, CATUnicodeString& oDoublette);

  /**
  * This methods returns the semantic relation values found in the PLMDictionary.
  * Of course, MetaData should be initialized first.
  * @nodoc
  */
  static HRESULT GetListOfCategoryAndRole(CATOmxArray<CATString> &oCategoryArray, CATOmxArray<CATString> &oRoleArray);

  // CUSTO_CHILDREN is DEPRECATED because of new typing...
  enum ChildMode{ ALL_CHILDREN = 0, CUSTO_CHILDREN = 1, DIRECT_CHILD = 2 };

  /**
  * Return list of children that inherit from ipType.
  *
  * <br><b>Role</b>: Return list of children that inherit from ipType.
  *
  * @param ipType [in]
  *   all types are accepted today except extension.
  * @param iChildMode [in]
  *   mode used to filter children
  * @param oChildrenTypeSet [out]
  *   if iChildMode == ALL_CHILDREN, we retrieve all children under ipType.
  *   if iChildMode == DIRECT_CHILD, we retrieve direct child of ipType.
  *   if iChildMode == CUSTO_CHILDREN, we retrieve only custo type under ipType.
  *
  * @return
  * <dt> <code>S_OK</code>          <dd> The type has children.
  * <dt> <code>S_FALSE</code>       <dd> No type is child of the current type.
  * <dt> <code>E_INVALIDARG</code>  <dd> if oListTypeId.Size()!=0 or if this (type) is an extension.
  * <dt> <code>E_FAIL</code>        <dd> The operation failed.
  */
  static HRESULT GetChildren( CATPLMType* ipType,
                              ChildMode iChildMode,
                              CATPLMTypeSet& oChildrenTypeSet);

  // iMaxDepth==-1 all types below ipType are returned
  // or iMaxDepth>0
  // iMaxDepth==0 is forbidden!!!
  static HRESULT GetChildren( CATPLMType * ipType,
                              CATPLMTypeSet& oChildrenTypeSet,
                              int MaxDepth = -1);

  /** OLD TYPING
  * @deprecated V6R2014 use @href CATPLMPrivateTypeServices#GetNotInheritedAttributes
  *
  * Retrieve custo attributes of PLM type.
  * Attributes which are on father type are filtered.
  * <br><b>Role</b>:
  * Retrieve custo attributes of PLM type.
  * Attributes which are on father type are filtered.
  *
  * @param ipCustoType [in]
  *       only custo types are accepted.
  * @param opListAttr [out]
  *       list of custo attributes.
  *       don't forget to call CATLISTP_APPLY_RELEASE when you have finished to use the list
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd> custo attributes have been retrieved.
  * <dt> <code>E_INVALIDARG</code>  <dd> if oListAttr.Size()!=0
  *                                      or if ipCustoType == 0
  *                                      or if ipCustoType is not a custo type.
  * <dt><code>E_FAIL</code> <dd> The operation failed.
  * </dl>
  */
  //static HRESULT GetCustoAttributes( CATPLMType * ipCustoType,
  //                                   CATListPtrCATPLMAttribute & oListAttr);

  /** NEW TYPING
  * Retrieve not inherited attributes of PLM type.
  * Attributes which are on "parent" type are filtered (parent can be the father or grandfather or great grandfather).
  * <br><b>Role</b>:
  * Retrieve not inherited attributes of PLM type.
  * Attributes which are on parent type are filtered.
  *
  * @param ipChildType [in]
  *       only custo types are accepted.
  * @param ipParentType [in]
  *       father or grand father or great grandfather ... of ipCustoType.
  * @param opListAttr [out]
  *       list of custo attributes.
  *       don't forget to call CATLISTP_APPLY_RELEASE when you have finished to use the list
  * @return
  * <dl>
  * <dt><code>S_OK</code>           <dd> custo attributes have been retrieved.
  * <dt><code>E_INVALIDARG</code>   <dd> if oListAttr.Size()!=0
  *                                      or if ipCustoType == 0
  *                                      or if ipCustoType is not a custo type.
  * <dt><code>E_FAIL</code>         <dd> The operation failed.
  * </dl>
  */
  static HRESULT GetNotInheritedAttributes( CATPLMType * ipChildType,
    CATPLMType * ipParentType,
    CATPLMAttributeNotOrderedSet & oNotInheritedAttrSet);

  static HRESULT GetAttributeType(CATPLMType* ipType,const CATString& iAttrName,AttrTypes& oAttrType,CATBoolean& oIsMulti);

  /**
  * Find the lowest ancestor, in the given available ancestor set, for each input types.
  * The result is a map: input type -> lowest ancestor.
  * If no lowest ancestor found in the given set, the input type is used (input type -> input type).
  *
  * <br><b>Role</b>: Find the lowest ancestor, in the given available ancestor set, for each input types.
  *
  * @param iTypeSet [in]
  *   the types to process.
  * @param iAncestorSet [in]
  *   the lowest ancestors.
  * @param oAncestorByTypeMap [out]
  *   input type -> lowest ancestor.
  *
  * @return
  * <dt> <code>S_OK</code>              <dd> The lowest ancestors have been found
  * <dt> <code>E_INVALIDARG</code>      <dd> iTypeSet is empty
  * <dt> <code>E_INVALIDARG</code>      <dd> iLowestAncestorSet is empty
  * <dt> <code>E_INVALIDARG</code>      <dd> oAncestorByTypeMap is not empty
  */
  static HRESULT GetLowestAncestors(CATPLMTypeSet& iTypeSet, CATPLMTypeSet& iLowestAncestorSet, CATPLMTypeToCATPLMType& oAncestorByTypeMap);

  /**
  * @deprecated use GetNotInheritedAttributes with CATPLMAttributeNotOrderedSet output instead.
  */
  static HRESULT GetNotInheritedAttributes( CATPLMType * ipChildType, CATPLMType * ipParentType, CATListPtrCATPLMAttribute & oListAttr);
  
  /**
  * @deprecated use GetChildren with CATPLMTypeSet output instead.
  */
  static HRESULT GetChildren(CATPLMType* ipType, ChildMode iChildMode, CATLISTP(CATPLMType)& oListType);

  /**
  * @deprecated use GetChildren with CATPLMTypeSet output instead.
  */
  static HRESULT GetChildren( CATPLMType * ipType, CATLISTP(CATPLMType)& oListType, int MaxDepth = -1);

  /**
  * @deprecated use GetListOfCategoryAndRole with CATOmxArray<CATString> inputs instead.
  */
  static HRESULT GetListOfCategoryAndRole(CATLISTV(CATString)& oCategoryList, CATLISTV(CATString)& oRoleList);

  /**
  * @deprecated 
  * VPMIDicClass::GetListOfSecuredElement is deprecated and returns nothing.
  *
  * @return
  * S_FALSE
  */
  static HRESULT GetSecurityAttributesFromType (const CATPLMType *iType, CATLISTV(CATString) &oList);

  /**
   * @param opBestType [out,  CATBaseUnknown#Release]
  */
  static HRESULT GetBestTypeUnderBusinessType(CATPLMType* ipType,CATPLMType*& opBestType);

  static CATBoolean IsSRFound(CATPLMType* ipType);

#ifdef CATIAR424
  static bool IsCompositionalRel(CATPLMType* ipType);

  static bool IsCompositionalRel(const CATPLMTypeH& iType);
#endif

private:
  friend class CATPLMCompMetaDataService;
  /**
  * @nodoc
  */
  static void FlushHashTable();

  // S_OK found
  // E_FAIL not found
  // E_FAIL error
  static HRESULT _SearchInHTab( const CATOmxKeyString& iDoublette,
                                CATPLMType** oType);

  // E_FAIL if iDoublette=="" or iDoublette doesn't contain '/'
  static HRESULT _UnstreamDoublette(  const CATUnicodeString& iDoublette,
                                      CATString& opDomainId,
                                      CATString& opTypeName);

  // E_FAIL if ipType == NULL
  static HRESULT _CompleteHTab(CATOmxKeyString& iDoublette,
                               CATPLMType* iType);

  static HRESULT _RecognizeCacheInstance(CATString& ipDomainId,
                                         CATString& ipTypeName,
                                         CATPLMType** oType);

  /**
  * This method returns the input type's lowest ancestor which is in the given ancestor set.
  * The input type is included in the search, which mean if the input type is in ancestor set, then the input type is returned.
  * If no lowest ancestor found, then it returns the input type (himself).
  *
  * @param ipType [in]
  *   the type to process.
  * @param iLowestAncestorSet [in]
  *   the lowest ancestors.
  * @param opLowestAncestorType [out, CATBaseUnknown#Release]
  *   the lowest ancestor found.
  *
  * @return
  * <dt> <code>S_OK</code>              <dd> The lowest ancestor has been found.
  * <dt> <code>S_FALSE</code>           <dd> The lowest ancestor cannot be found. Return input type.
  * <dt> <code>E_INVALIDARG</code>      <dd> ipType is NULL
  * <dt> <code>E_INVALIDARG</code>      <dd> iLowestAncestorSet is empty
  * <dt> <code>E_INVALIDARG</code>      <dd> opLowestAncestorType is not NULL
  */
  static HRESULT _GetLowestAncestor(CATPLMType* ipType, CATPLMTypeSet& iLowestAncestorSet, CATPLMType*& opLowestAncestorType);
};

#endif
