#ifndef CATPLMAttrMasksAssociation_H
#define CATPLMAttrMasksAssociation_H

#include "CATPLMImplAdapterBase.h"

#include "CATPLMOmxCollections.h"

class ExportedByCATPLMImplAdapterBase CATPLMAttrMasksAssociation
{
public:
  CATPLMAttrMasksAssociation();

  CATPLMAttrMasksAssociation(const CATOmxKeyString& iAttrName);

  ~CATPLMAttrMasksAssociation();

  CATPLMAttrMasksAssociation(const CATPLMAttrMasksAssociation&);

  CATPLMAttrMasksAssociation& operator = (const CATPLMAttrMasksAssociation&);

  void AddMask(const CATOmxKeyString& iMaskName);

  CATBoolean IsMaskFound(const CATOmxKeyString& iMaskName);

  void SetOrder(const CATOmxKeyString& iMaskName, int iOrder);

  HRESULT GetOrder(const CATOmxKeyString& iMaskName, int& oOrder) const;

  void SetDefaultValue(const CATUnicodeString& iValue);

  CATUnicodeString GetDefaultValue() const;

private:
  CATPLMKSToKvb _MaskToKvb;
  CATOmxKeyString _AttrName;
  CATUnicodeString _DefaultValue;
};

#endif
