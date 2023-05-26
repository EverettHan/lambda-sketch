// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMCompImportRecordWriteAdapter.h
//
//===================================================================
//
// Usage notes:
// Provide implementation to interface CATIPLMCompImportRecordWrite
//
//===================================================================
//
// April 2009  Creation: EPB
//===================================================================

/**
* @level Private
* @usage U1
*/

#ifndef CATPLMCompImportRecordWriteAdapter_H
#define CATPLMCompImportRecordWriteAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMCompImportRecordWrite.h"

class CATPLMID;
class CATVVSUrl;
class CATPLMStreamDescriptor;
class CATPLMRepoPrivilege;
class CATPLMCEStamp;
class CATPLMPathDataH;
class CATPLMType;

class ExportedByCATPLMImplAdapterClass CATPLMCompImportRecordWriteAdapter : public CATIPLMCompImportRecordWrite
{
public:

  CATPLMCompImportRecordWriteAdapter();

  ~CATPLMCompImportRecordWriteAdapter();

  virtual HRESULT SetRepoPrivilege(const CATPLMRepoPrivilege &iRepoPrivilege);

  virtual HRESULT RequestObject(int iUrls);

  virtual HRESULT DetachObject();

  virtual HRESULT ChgRepoObject(const CATPLMRepoPrivilege &iRepoPrivilege);

  virtual HRESULT ImportObject(TransactionType iHint);

  virtual HRESULT AddStream(const CATPLMStreamDescriptor& iStreamDesc, const CATVVSUrl &iVVSUrl);

  virtual HRESULT SetSDPreservationMode(const PLMStreamDescriptorPreservationMode iSDPreservationMode);

  virtual HRESULT GetPLMId(CATPLMID & oId);

  virtual HRESULT CreateObject();

  virtual HRESULT UpdateObject();

  virtual HRESULT DeleteObject();

  virtual HRESULT ReplaceObject(const CATPLMID & iId);

  virtual HRESULT GetAttributeAccess(const CATString * iExtensionType, CATIPLMAttrWrite ** oAttrAccess);

  virtual HRESULT GetAttributeAccess(CATIPLMAttrWrite ** oAttrAccess, const CATPLMTypeId *iExtensionType);

  virtual HRESULT GetAttributeAccess(CATPLMType* ipExtensionType, CATIPLMAttrWrite*& opAttrAccess);

  virtual HRESULT ReserveStream(const CATPLMStreamDescriptor * iStreamDesc);

  virtual HRESULT DeleteStream(CATPLMStreamDescriptor * iStreamDesc);

  virtual HRESULT ResetStream();

  virtual HRESULT SetAssociatedObject(const CATString * iRelType, const CATPLMID & iTargetId);

  virtual HRESULT SetAssociatedObj(CATPLMStrongRelationshipId::eStrongRelId iStrongRelId, const CATPLMID & iTargetId);

  virtual HRESULT AddSemanticRelation(const CATPLMID & iTargetId, const CATPLMSemanticRelationData * iSemanticData);

  virtual HRESULT AddPathDataH(const CATPLMPathDataH& iPathData);

  virtual HRESULT ModPathDataH(const CATPLMPathDataH& iPathData);

  virtual HRESULT DelPathDataH(const CATPLMPathDataH& iPathData);

  virtual HRESULT DeletePathDataH(const CATPLMPathDataH& iPathData);

  virtual HRESULT DeleteSemanticRelations();

  virtual HRESULT SetSRList(const CATLISTP(CATPLMSemanticRelation) & iSRList);

  virtual HRESULT PushSRForAdd(const CATPLMSemanticRelation & iSR);

  virtual HRESULT PushSRForSync(const CATPLMSemanticRelation & iSR);

  virtual HRESULT PushSRIdForDel(const CATPLMSemanticRelationId & iSRId);

  virtual HRESULT RemoveExtension(const CATPLMTypeId &iExt);

  virtual HRESULT RemoveExtension(CATPLMType* ipExtensionType);

  virtual HRESULT PreserveExtensionMode(PLMExtensionPreservationMode imode);

  virtual HRESULT SetComposerId(const CATPLMID& iComposer);

  virtual HRESULT SetInitPOVFromSelf(CATBoolean iInitPOVFromSelf);

  virtual HRESULT SetComposition(const CATPLMTypeH& iComposition);

  virtual HRESULT SetComposition(const CATPLMID& iRelation);

  virtual HRESULT SetComposerAndComposition(const CATPLMID& iComposer, CATPLMType* ipRelation);

  virtual HRESULT SetComposerAndComposition(const CATPLMID& iComposer, const CATPLMID& iRelation);

  virtual HRESULT GetAssociatedObj(CATPLMStrongRelationshipId::eStrongRelId iStrongRelId, CATPLMID& oTargetId);
};

#endif
