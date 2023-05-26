// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMCompRecordWriteAdapter.h
//
//===================================================================
//
// Usage notes:
// Provide implementation to interface CATIPLMCompRecordWrite
//
//===================================================================
// April 2009  Creation: EPB
//===================================================================

/**
* @level Private
* @usage U1
*/

#ifndef CATPLMCompRecordWriteAdapter_H
#define CATPLMCompRecordWriteAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMCompRecordWrite.h"
#include "CATPLMStrongRelationshipId.h"

class CATPLMID;
class CATPLMTypeId;
class CATIPLMAttrWrite;
class CATUnicodeString;
class CATVVSUrl;
class CATString;
class _SEQUENCE_octet;
class CATPLMSemanticRelationData;
class CATPLMStreamDescriptor;
class CATPLMPathDataH;

#include "CATCollec.h"
class CATPLMSemanticRelation;
class CATListPtrCATPLMSemanticRelation;
class CATPLMSemanticRelationId;

class ExportedByCATPLMImplAdapterClass CATPLMCompRecordWriteAdapter : public CATIPLMCompRecordWrite
{
public:
  CATPLMCompRecordWriteAdapter();

  ~CATPLMCompRecordWriteAdapter();

  virtual HRESULT GetPLMId(CATPLMID& oId);

  virtual HRESULT CreateObject();

  virtual HRESULT UpdateObject();

  virtual HRESULT DeleteObject();

  virtual HRESULT ReplaceObject(const CATPLMID& iId);

  virtual HRESULT GetAttributeAccess(const CATString* iExtensionType, CATIPLMAttrWrite** oAttrAccess);

  virtual HRESULT GetAttributeAccess(CATIPLMAttrWrite** oAttrAccess, const CATPLMTypeId* iExtensionType = NULL);

  virtual HRESULT GetAttributeAccess(CATPLMType* ipExtensionType, CATIPLMAttrWrite*& opAttrAccess);

  virtual HRESULT ReserveStream(const CATPLMStreamDescriptor* iStreamDesc);

  virtual HRESULT DeleteStream(CATPLMStreamDescriptor* iStreamDesc);

  virtual HRESULT ResetStream();

  virtual HRESULT SetAssociatedObject(const CATString* iRelType, const CATPLMID& iTargetId);

  virtual HRESULT SetAssociatedObj(CATPLMStrongRelationshipId::eStrongRelId iStrongRelId, const CATPLMID& iTargetId);

  virtual HRESULT GetAssociatedObj(CATPLMStrongRelationshipId::eStrongRelId iStrongRelId, CATPLMID& oTargetId);

  virtual HRESULT AddSemanticRelation(const CATPLMID& iTargetId, const CATPLMSemanticRelationData* iSemanticData);

  virtual HRESULT AddPathDataH(const CATPLMPathDataH& iPathData);

  virtual HRESULT ModPathDataH(const CATPLMPathDataH& iPathData);

  virtual HRESULT DelPathDataH(const CATPLMPathDataH& iPathData);

  virtual HRESULT DeletePathDataH(const CATPLMPathDataH& iPathData);

  virtual HRESULT DeleteSemanticRelations();

  virtual HRESULT SetSRList(const CATLISTP(CATPLMSemanticRelation)& iSRList);

  virtual HRESULT PushSRForAdd(const CATPLMSemanticRelation& iSR);

  virtual HRESULT PushSRForSync(const CATPLMSemanticRelation& iSR);

  virtual HRESULT PushSRIdForDel(const CATPLMSemanticRelationId& iSRId);

  virtual HRESULT RemoveExtension(const CATPLMTypeId& iExtensionType);

  virtual HRESULT RemoveExtension(CATPLMType* ipExtensionType);

  virtual HRESULT SetComposerId(const CATPLMID& iComposer);

  virtual HRESULT SetInitPOVFromSelf(CATBoolean iInitPOVFromSelf);

  virtual HRESULT SetComposition(const CATPLMTypeH& iComposition);

  virtual HRESULT SetComposition(const CATPLMID& iComposition);

  virtual HRESULT SetComposerAndComposition(const CATPLMID& iComposer, CATPLMType* ipCompositionalRelType);

  virtual HRESULT SetComposerAndComposition(const CATPLMID& iComposer, const CATPLMID& iCompositionalRelId);
};

#endif
