// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMRecordReadAdapter.h
// Define the CATPLMRecordReadAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMRecordRead
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMRecordReadAdapter_H
#define CATPLMRecordReadAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedBy
#include "CATIPLMRecordRead.h" // CATPLMServices ProtectedInterfaces CATPLMServicesItf.m CATPLMServicesItf.dll
#include "CATPLMTypeId.h"// CATPLMServices ProtectedInterfaces CATPLMServicesItf.m CATPLMServicesItf.dll
#include "CATPLMStrongRelationshipId.h"
#include "CATIAV5Level.h"

// ObjectModelerSystem
#include "CATOmyAsserts.h"

#define final

class CATIPLMRecordReadExtraInfo;

/**
* Gives an adapter to the interface CATIPLMRecordRead
*/

class ExportedByCATPLMImplAdapterClass CATPLMRecordReadAdapter : public CATIPLMRecordRead
{
  friend class CATPLMCompStatement;
  friend class CATPLMQLAsyncResultMsg;
public:
  CATPLMRecordReadAdapter();
  virtual ~CATPLMRecordReadAdapter();

  /**
  * @nodoc
  * CATIPLMRecordRead functions.
  * Specialized classes should not overload these functions but instead the functions starting with '_'
  * These functions have all the following implementation pattern :
  *        HRESULT CATPLMRecordReadAdapter::GetSectionName(...) { return _GetSectionName(...) }
  */
  virtual HRESULT GetSectionName(CATUnicodeString ** oSectionName) final;
  virtual HRESULT GetPLMID(CATPLMID & oId) final;
  virtual HRESULT GetAttributeAccess(const CATString * iPLMExtension, CATIPLMAttrRead ** oAttrAccess) final;
  virtual HRESULT GetAttributeAccess(CATIPLMAttrRead ** oAttrAccess, const CATPLMTypeId * iPLMExtension = NULL) final;
  virtual HRESULT GetAttrAccess(CATIPLMAttrRead ** oAttrAccess, CATPLMType* ipPLMExtension = NULL) final;
  virtual HRESULT GetStreamAccess(CATPLMStreamDescriptor * iStreamDesc, CATVVSUrl **oVVSUrl) final;
  virtual HRESULT ListStreamDescriptors(CATListPtrCATPLMStreamDescriptor * oStreamDescList) final;
  virtual HRESULT ListStreamDescriptorsDeleted(CATListPtrCATPLMStreamDescriptor * oStreamDescListDeleted) final;
  virtual HRESULT GetAssociatedObject(const CATString * iRelType, CATPLMID & oAssObjId) final;
  virtual HRESULT SemanticRelationCount(int * oCount) final;
  virtual HRESULT PathDataHCount(int& oCount) final;
  virtual HRESULT GetSemanticRelation(int iIndex, CATPLMID & oTargetId, CATPLMSemanticRelationData ** oSemanticData) final;
  virtual HRESULT GetPathDataH(int iIndex, CATPLMPathDataH& oPathData) final;

  // Please, do CATLISTP_APPLY_DELETE(oSRList). Indeed, internal srList is copied and returned.
  virtual HRESULT GetSRList(CATLISTP(CATPLMSemanticRelation) & oSRList) final;
  virtual HRESULT ListExtensionTypes(CATListValCATString ** oExtensionList) final;
  virtual HRESULT GetReport(CATIPLMError ** oError) final;
  virtual HRESULT GetExtraInfo1(CATIPLMRecordReadExtraInfo ** opAttrAccess, const CATPLMTypeId& iPLMExtension = CATPLMTypeId_Null) final;
  virtual HRESULT GetAttrAccess1(CATIPLMAttrRead ** oAttrAccess, const CATPLMTypeId& iPLMExtension = CATPLMTypeId_Null) final;
  virtual HRESULT GetAttrAccess2(CATIPLMAttrRead ** oAttrAccess, CATPLMType* ipPLMExtension = NULL) final;
  virtual HRESULT ListStreamDescriptors(CATOmxList<CATPLMStreamDescriptor>& oStreamDescList) final;
  virtual HRESULT GetAssociatedObj(CATPLMStrongRelationshipId::eStrongRelId iStrongRelId, CATPLMID & oAssObjId) final;
  virtual HRESULT ListExtensionTypes(CATLISTV(CATPLMTypeId)& oExtensionList) final;
  virtual HRESULT ListExtensionTypes(CATPLMTypeList & oExtensionList) final;
  virtual HRESULT ListExtensionTypes(CATLISTP(CATPLMType)& oExtensionList) final;
  virtual HRESULT GetLockStatus(PLMLockStatus &oLockStatus) final;
  virtual HRESULT GetExtraInfo2(CATIPLMRecordReadExtraInfo ** opAttrAccess, CATPLMType* ipPLMExtension = NULL) final;
  virtual HRESULT GetCEStamp(CATPLMCEStamp & oStamp) const final;
  // Should not be final because same method name in CATIPLMAttributeBlockAccess
  virtual HRESULT GetAttributeBlock(CATOmxKeyValueBlock &oAttrBlock, const CATString * iPLMExtension = NULL);
  virtual HRESULT GetAttributeBlock(CATOmxKeyValueBlock &oAttrBlock, const CATPLMTypeId &iPLMExtension);
  virtual HRESULT GetAttrBlock(CATOmxKeyValueBlock &oAttrBlock, CATPLMType* ipPLMExtension = NULL);
  // Should not be final because same method name in CATIPLMSystemAttrAccess 
  virtual HRESULT GetRepoPrivilege(int & oRepoPrivilege) const;

  int SemanticRelationDataInfosCount() const;
  virtual HRESULT GetSemanticRelationDataInfos(int iIndex, CATOmxKeyValueBlock& oInfos) const;

  virtual CATIPLMRecordRead::eStatus GetStatus() const;
  virtual CATUnicodeString GetStatusAsStr() const;

  virtual CATIPLMError* GetReport() final;

  /**
  * @nodoc
  * Same functions as before but starting with '_'. There are three kinds of them.
  * METH1 : The ones that should be overloaded by specialized classes as their implementation in CATPLMRecordReadAdapter returns E_NOTIMPL.
  * METH2 : The ones that should not be overloaded by specialized classes as their implementation in CATPLMRecordReadAdapter is correct.
  *         This implementation is based on a METH1 method.
  * METH3 : The ones that should not be overloaded by specialized classes as their implementation in CATPLMRecordReadAdapter is correct.
  *         This implementation is based on a method of another interface that have to be implemented instead of the function returns E_NOTIMPL.
  * METH2 and METH3 functions can be overloaded even if it's not necessary and not recommended.
  */
  // METH1 functions  
  virtual HRESULT _GetSectionName(CATUnicodeString ** oSectionName) { LOG_ABEND("***ERROR*** CATPLMRecordReadAdapter::_GetSectionName E_NOTIMPL"); return E_NOTIMPL; }
  virtual HRESULT _GetPLMID(CATPLMID & oId) { LOG_ABEND("***ERROR*** CATPLMRecordReadAdapter::_GetPLMID E_NOTIMPL"); return E_NOTIMPL; }
  virtual HRESULT _GetAttributeAccess(const CATString * iPLMExtension, CATIPLMAttrRead ** oAttrAccess) { LOG_ABEND("***ERROR*** CATPLMRecordReadAdapter::_GetAttributeAccess E_NOTIMPL"); return E_NOTIMPL; }
  virtual HRESULT _GetAttributeAccess(CATIPLMAttrRead ** oAttrAccess, const CATPLMTypeId * iPLMExtension = NULL) { LOG_ABEND("***ERROR*** CATPLMRecordReadAdapter::_GetAttributeAccess E_NOTIMPL"); return E_NOTIMPL; }
  virtual HRESULT _GetAttrAccess(CATIPLMAttrRead ** oAttrAccess, CATPLMType* ipPLMExtension = NULL) { LOG_ABEND("***ERROR*** CATPLMRecordReadAdapter::_GetAttrAccess E_NOTIMPL"); return E_NOTIMPL; }
  virtual HRESULT _GetStreamAccess(CATPLMStreamDescriptor * iStreamDesc, CATVVSUrl **oVVSUrl) { LOG_ABEND("***ERROR*** CATPLMRecordReadAdapter::_GetStreamAccess E_NOTIMPL"); return E_NOTIMPL; }
  virtual HRESULT _ListStreamDescriptors(CATListPtrCATPLMStreamDescriptor * oStreamDescList) { LOG_ABEND("***ERROR*** CATPLMRecordReadAdapter::_ListStreamDescriptors E_NOTIMPL"); return E_NOTIMPL; }
  virtual HRESULT _ListStreamDescriptorsDeleted(CATListPtrCATPLMStreamDescriptor * oStreamDescListDeleted) { LOG_ABEND("***ERROR*** CATPLMRecordReadAdapter::_ListStreamDescriptorsDeleted E_NOTIMPL"); return E_NOTIMPL; }
  virtual HRESULT _GetAssociatedObject(const CATString * iRelType, CATPLMID & oAssObjId) { LOG_ABEND("***ERROR*** CATPLMRecordReadAdapter::_GetAssociatedObject E_NOTIMPL"); return E_NOTIMPL; }
  virtual HRESULT _SemanticRelationCount(int * oCount) { LOG_ABEND("***ERROR*** CATPLMRecordReadAdapter::_SemanticRelationCount E_NOTIMPL"); return E_NOTIMPL; }
  virtual HRESULT _PathDataHCount(int& oCount) {
    //log_abend breaks following odt: ENOUniversalEditor.tst UniversalEditor_ExploreInContext_ExpandSiblings_Filter_MultiInstances_CloudView
    //LOG_ABEND("***ERROR*** CATPLMRecordReadAdapter::_PathDataHCount E_NOTIMPL");
    return E_NOTIMPL;
  }
  virtual HRESULT _GetSemanticRelation(int iIndex, CATPLMID & oTargetId, CATPLMSemanticRelationData ** oSemanticData) { LOG_ABEND("***ERROR*** CATPLMRecordReadAdapter::_GetSemanticRelation E_NOTIMPL"); return E_NOTIMPL; }
  virtual HRESULT _GetPathDataH(int iIndex, CATPLMPathDataH& oSemanticData) { LOG_ABEND("***ERROR*** CATPLMRecordReadAdapter::_GetPathDataH E_NOTIMPL"); return E_NOTIMPL; }
  virtual HRESULT _GetSRList(CATLISTP(CATPLMSemanticRelation) & oSRList) { LOG_ABEND("***ERROR*** CATPLMRecordReadAdapter::_GetSRList E_NOTIMPL"); return E_NOTIMPL; }
  virtual HRESULT _GetReport(CATIPLMError ** oError)
  {
#ifdef CATIAR423
    LOG_ABEND("***ERROR*** CATPLMRecordReadAdapter::_GetReport E_NOTIMPL");
#endif
    return E_NOTIMPL;
  }

  virtual CATIPLMError* _GetReport();

  virtual HRESULT _GetExtraInfo1(CATIPLMRecordReadExtraInfo ** opAttrAccess, const CATPLMTypeId& iPLMExtension = CATPLMTypeId_Null) { 
    //log_abend breaks following odt: ENOUniversalEditor.tst UniversalEditor_ExploreInContext_ExpandSiblings_Filter_MultiInstances_CloudView
    //LOG_ABEND("***ERROR*** CATPLMRecordReadAdapter::_GetExtraInfo1 E_NOTIMPL");
    return E_NOTIMPL; 
  }
  // METH2 functions  
  virtual HRESULT _GetAttrAccess1(CATIPLMAttrRead ** oAttrAccess, const CATPLMTypeId& iPLMExtension = CATPLMTypeId_Null); // Based on CATIPLMRecordRead::GetAttributeAccess
  virtual HRESULT _GetAttrAccess2(CATIPLMAttrRead ** oAttrAccess, CATPLMType* ipPLMExtension = NULL);                      // Based on CATIPLMRecordRead::GetAttributeAccess  
  virtual HRESULT _ListStreamDescriptors(CATOmxList<CATPLMStreamDescriptor>& oStreamDescList);                               // Based on CATIPLMRecordRead::ListStreamDescriptors
  virtual HRESULT _GetAssociatedObj(CATPLMStrongRelationshipId::eStrongRelId iStrongRelId, CATPLMID & oAssObjId);             // Based on CATIPLMRecordRead::GetAssociatedObject
  virtual HRESULT _ListExtensionTypes(CATListValCATString ** oExtensionList);
  virtual HRESULT _ListExtensionTypes(CATLISTV(CATPLMTypeId)& oExtensionList);                                               // Based on CATIPLMRecordRead::ListExtensionTypes(CATPLMTypeList)
  virtual HRESULT _ListExtensionTypes(CATPLMTypeList & oExtensionList);                                                      // Based on CATIPLMRecordRead::ListExtensionTypes(CATListValCATString**)
  virtual HRESULT _ListExtensionTypes(CATLISTP(CATPLMType)& oExtensionList);                                                 // Based on CATIPLMRecordRead::ListExtensionTypes(CATListValCATString**)
  virtual HRESULT _GetLockStatus(PLMLockStatus &oLockStatus);                                                               // Based on CATIPLMRecordRead::GetAttributeAccess
  virtual HRESULT _GetExtraInfo2(CATIPLMRecordReadExtraInfo ** opAttrAccess, CATPLMType* ipPLMExtension = NULL);          // Based on CATIPLMRecordRead::GetExtraInfo1
  // METH3 functions
  virtual HRESULT _GetCEStamp(CATPLMCEStamp & oStamp) const;                                                      // Based on CATIPLMSystemAttrRead::GetCEStamp
  virtual HRESULT _GetAttributeBlock(CATOmxKeyValueBlock &oAttrBlock, const CATString * iPLMExtension = NULL); // Based on CATIPLMAttributeBlockAccess::GetAttributeBlock
  virtual HRESULT _GetAttributeBlock(CATOmxKeyValueBlock &oAttrBlock, const CATPLMTypeId &iPLMExtension);     // Based on CATIPLMAttributeBlockAccess::GetAttributeBlock
  virtual HRESULT _GetAttrBlock(CATOmxKeyValueBlock &oAttrBlock, CATPLMType* ipPLMExtension = NULL);          // Based on CATIPLMAttributeBlockAccess::GetAttrBlock
  virtual HRESULT _GetRepoPrivilege(int & oRepoPrivilege) const;                                                  // Based on CATIPLMSystemAttrAccess::GetRepoPrivilege
  virtual int _SemanticRelationDataInfosCount() const { return 0; }
  virtual HRESULT _GetSemanticRelationDataInfos(int iIndex, CATOmxKeyValueBlock& oInfos) const { LOG_ABEND("***ERROR*** CATPLMRecordReadAdapter::_GetSemanticRelationDataInfos E_NOTIMPL"); return E_NOTIMPL; }

  virtual CATIPLMRecordRead::eStatus _GetStatus() const { return eUndefined; }
  virtual CATUnicodeString _GetStatusAsStr() const { return "Undefined"; }

protected:
  /**
   * @nodoc
   * Internal
   */
#define SRsReq      0x01
#define SDsReq      0x02
#define ExtNamesReq      0x04
#define ExtAttrsReq      0x08
  unsigned int GetDefMode() { return _dm; }
  void ExtAttrs_AskedButNotRequired();

private:
  unsigned int _SetDefMode(unsigned int idm) { unsigned int od = _dm; _dm = idm; return od; }

  CATPLMRecordReadAdapter(CATPLMRecordReadAdapter &);
  CATPLMRecordReadAdapter& operator=(CATPLMRecordReadAdapter&);
  unsigned int _dm;
};

#endif
