#ifndef CATPLMMaskToolkit_H
#define CATPLMMaskToolkit_H

#include "CATPLMImplAdapterBase.h"

#include "CATPLMDictionaryToolkit.h"

#include "CATPLMAdpOmxCollections.h"

class VPMIDicPackage;
class VPMIDicClass;
class VPMIDicRelationClass;

class ExportedByCATPLMImplAdapterBase CATPLMMaskToolkit
{
public:
  CATPLMMaskToolkit();

  ~CATPLMMaskToolkit();

  HRESULT CreateMasksInPackage(VPMIDicPackage * ipPackage, VPMIDicClass* ipDicClass, const CATPLMMapKSToAttrMasksAssociation& iAttrNameToMaskNameAndMaskProperties);
  HRESULT CreateMasksInPackage(VPMIDicPackage * ipPackage, VPMIDicRelationClass* ipDicClass, const CATPLMMapKSToAttrMasksAssociation& iAttrNameToMaskNameAndMaskProperties);
private:
  template <class T>
  HRESULT _CreateMasksInPackage(VPMIDicPackage * ipPackage, T * ipClassOrRelationClass, const CATPLMMapKSToAttrMasksAssociation& iAttrNameToMaskNameAndMaskProperties);

  CATPLMDictionaryToolkit _t;
};

#endif
