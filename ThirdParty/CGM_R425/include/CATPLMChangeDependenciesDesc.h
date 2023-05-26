#ifndef CATPLMChangeDependenciesDesc_H
#define CATPLMChangeDependenciesDesc_H

#include "CATPLMServicesItf.h"
#include "CATPLMOmxCollections.h"

#include "CATSysErrorDef.h"

#include "CATOmxSR.h"
#include "CATOmxKeyString.h"
#include "CATOmxArray.h"

class ExportedByCATPLMServicesItf CATPLMChangeDependenciesDesc
{
public:
  static const CATPLMChangeDependenciesDesc &s();

  ~CATPLMChangeDependenciesDesc();

  const CATOmxKeyString& GetChangeDependenciesName() const;

  const CATOmxArray<CATOmxKeyString>& ListViewAttrName() const;

  const CATOmxKeyString ksrowuuid;
  const CATOmxKeyString ksfromPhysicalId;
  const CATOmxKeyString kstoPhysicalId;
  const CATOmxKeyString kstype;
  const CATOmxKeyString ksuserDefine;
  const CATOmxKeyString ksconsumed;
  const CATOmxKeyString kstwinRowId;

private:
  CATPLMChangeDependenciesDesc();

  CATPLMChangeDependenciesDesc (CATPLMChangeDependenciesDesc &);
  CATPLMChangeDependenciesDesc& operator=(CATPLMChangeDependenciesDesc&);

  const CATOmxKeyString ksChangeDependencies;
  CATOmxArray<CATOmxKeyString> _lViewAttrDesc;
};

#endif
