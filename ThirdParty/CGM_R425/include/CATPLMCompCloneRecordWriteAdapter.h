// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATPLMCompCloneRecordWriteAdapter.h
// Define the CATPLMCompCloneRecordWriteAdapter adapter
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

#ifndef CATPLMCompCloneRecordWriteAdapter_H
#define CATPLMCompCloneRecordWriteAdapter_H

#include "CATPLMImplAdapterClass.h"

#include "CATIPLMCompCloneRecordWrite.h"

class CATPLMID;
class CATPLMTypeId;
class CATIPLMAttrWrite;
class CATPLMNLVPropertiesWrite;
class CATPLMType;

class ExportedByCATPLMImplAdapterClass CATPLMCompCloneRecordWriteAdapter : public CATIPLMCompCloneRecordWrite
{
public:
  CATPLMCompCloneRecordWriteAdapter();

  ~CATPLMCompCloneRecordWriteAdapter();

  virtual HRESULT SetProperties(const CATPLMNLVPropertiesWrite & iProperties);

  virtual HRESULT GetPLMId(CATPLMID & oId);

  virtual HRESULT CloneObject();

  virtual HRESULT GetAttributeAccess(CATIPLMAttrWrite ** oAttrAccess, const CATPLMTypeId *iExtensionType);

  virtual HRESULT GetAttributeAccess(const CATString * iExtensionType, CATIPLMAttrWrite ** oAttrAccess);

  virtual HRESULT GetAttributeAccess(CATPLMType* ipExtensionType, CATIPLMAttrWrite*& opAttrAccess);

  virtual HRESULT KeepFamily();

  virtual HRESULT GetCEStamp(CATPLMCEStamp& oCEStamp) const;

  virtual CATPLMCEStamp GetCEStamp() const;

  virtual HRESULT GetProperties(CATPLMNLVPropertiesWrite & oProperties);

  virtual CATPLMOrderedOSetOfTypeH GetListExtension() const;

private:
  CATPLMCompCloneRecordWriteAdapter(CATPLMCompCloneRecordWriteAdapter &);
  CATPLMCompCloneRecordWriteAdapter& operator=(CATPLMCompCloneRecordWriteAdapter&);
};

#endif
