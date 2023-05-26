#ifndef CATPLMDictionaryToolkit_H
#define CATPLMDictionaryToolkit_H

#include "CATPLMServicesItf.h" 

#include "CATOmxKeyString.h"

#include "CATString.h"

#include "CATPLMOmxCollections.h"

#include "CATOmxList.h"

#include "CATCollec.h"
class CATLISTP(IUnknown);
class VPMIDicClass;
class VPMIDicElement;
class VPMIDicRelationClass;
class VPMIDicMask;
class VPMIDicPackage;
class VPMIDicAttributeMask;

/*
  Managing a local struct to handle  entity and its list of attributes belongs to.
*/
class ExportedByCATPLMServicesItf CATPLMDictionaryToolkit
{
public:
  CATPLMDictionaryToolkit();

  ~CATPLMDictionaryToolkit();

  /**
  * <br><b>Role</b>:
  * @param *ipClass
  *
  * @param iAttributeName
  *
  * @param isInheritanceTreated
  *
  * @param opCurElement [out,  CATBaseUnknown#Release]
  *
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  HRESULT GetElement(VPMIDicClass *ipClass, const CATOmxKeyString& iAttributeName, CATBoolean isInheritanceTreated, VPMIDicElement*& opCurElement);

  /**
  *
  * <br><b>Role</b>:
  * @param *ipClass
  *
  * @param iAttributeName
  *
  * @param isInheritanceTreated
  *
  * @param opCurElement [out,  CATBaseUnknown#Release]
  *
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  HRESULT GetElement(VPMIDicRelationClass *ipRelationClass, const CATOmxKeyString& iAttributeName, CATBoolean iWithInherited, VPMIDicElement*& opCurElement);

  HRESULT ListAttributesInMetadata(VPMIDicClass* ipClass, CATBoolean isInheritance, CATPLMKSSet& oListOfAvailableAttributes);

  HRESULT ListAttributesInMetadata(VPMIDicRelationClass* ipClass, CATBoolean isInheritance, CATPLMKSSet& oListOfAvailableAttributes);

  HRESULT GetMaskList(VPMIDicClass* ipClass, CATOmxList<IUnknown>& oLMask);

  HRESULT GetMaskList(VPMIDicRelationClass* ipRelationClass, CATOmxList<IUnknown>& oLMask);

private:
  CATPLMMapKSToMapIntToKSSet _mapClassNameMapInheritanceAttrSet, _mapRelationClassNameMapInheritanceAttrSet;
};

#endif
