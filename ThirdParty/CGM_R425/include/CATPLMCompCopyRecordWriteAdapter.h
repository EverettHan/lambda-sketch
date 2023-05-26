// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATPLMCompCopyRecordWriteAdapter.h
// Define the CATPLMCompCopyRecordWriteAdapter adapter
//
//===================================================================
//
// Usage notes:
//   adapter
//
//===================================================================
//
// April 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U3
*/

#ifndef CATPLMCompCopyRecordWriteAdapter_H
#define CATPLMCompCopyRecordWriteAdapter_H

#include "CATPLMImplAdapterClass.h"

#include "CATIPLMCompCopyRecordWrite.h"
#include "CATIPLMAttrWrite.h"
#include "CATOmxOrderedOSet.h"
#include "CATPLMTypeH.h"
#include "CATPLMStrongRelationshipId.h"
#include "CATPLMCEStamp.h"

class CATPLMID;
class CATPLMTypeId;
class CATIPLMAttrWrite;

class ExportedByCATPLMImplAdapterClass CATPLMCompCopyRecordWriteAdapter : public CATIPLMCompCopyRecordWrite
{
public:
  CATPLMCompCopyRecordWriteAdapter();

  ~CATPLMCompCopyRecordWriteAdapter();

  virtual HRESULT SetProperties(const CATPLMNLVPropertiesWrite & iProperties);

  virtual HRESULT GetProperties(CATPLMNLVPropertiesWrite & oProperties);

  virtual HRESULT GetPLMId(CATPLMID & oId);

  virtual HRESULT CopyObject();

  virtual HRESULT GetAttributeAccess(CATIPLMAttrWrite ** oAttrAccess, const CATPLMTypeId *iExtensionType);

  virtual HRESULT GetAttributeAccess(CATPLMType* ipExtensionType, CATIPLMAttrWrite *& oAttrAccess);

  virtual HRESULT KeepFamily();

  virtual CATPLMOrderedOSetOfTypeH GetListExtension() const;

  virtual HRESULT SetAssociatedObj(CATPLMStrongRelationshipId::eStrongRelId iStrongRelId, const CATPLMID & iTargetId);

  virtual HRESULT GetAssociatedObj(CATPLMStrongRelationshipId::eStrongRelId iStrongRelId, CATPLMID &  oTargetId);

  virtual HRESULT GetCEStamp(CATPLMCEStamp& oCEStamp) const;

  virtual CATPLMCEStamp GetCEStamp() const;

private:
  CATPLMCompCopyRecordWriteAdapter(CATPLMCompCopyRecordWriteAdapter &);
  CATPLMCompCopyRecordWriteAdapter& operator=(CATPLMCompCopyRecordWriteAdapter&);
};

#endif
