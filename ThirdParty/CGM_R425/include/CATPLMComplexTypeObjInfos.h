/**
 * @level Private
 * @usage U1
 */

#ifndef CATPLMComplexTypeObjInfos_H
#define CATPLMComplexTypeObjInfos_H

#include "CATPLMIntegrationAccess.h"

#include "CATSysErrorDef.h"// for HRESULT

#include "CATOmxSR.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxArray.h"

class CATPLMComplexTypeObjInfosInternal;
class CATPLMCEStamp;
class CATPLMID;

class ExportedByCATPLMIntegrationAccess CATPLMComplexTypeObjInfos
{
public:
  CATPLMComplexTypeObjInfos();

  CATPLMComplexTypeObjInfos(const CATPLMID& iPlmid,const CATPLMCEStamp& iCestamp);

  virtual ~CATPLMComplexTypeObjInfos();

  CATPLMComplexTypeObjInfos(const CATPLMComplexTypeObjInfos & iObjInfos);

  CATPLMComplexTypeObjInfos& operator=(const CATPLMComplexTypeObjInfos& iObjInfos);

  const CATPLMID& GetPlmid() const;

  const CATPLMCEStamp& GetCestamp() const;

  HRESULT SetAssociatedObject(const CATPLMID& iParentPlmid);

  const CATPLMID& GetAssociatedObject() const;

private:
  CATOmxSR<CATPLMComplexTypeObjInfosInternal> _spInternal;
};

#include "CATOmxCollecManager.h"
template<> ExportedByCATPLMIntegrationAccess CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMComplexTypeObjInfos>::manager();

typedef CATOmxArray<CATPLMComplexTypeObjInfos,CATOmxDefaultCollecManager<CATPLMComplexTypeObjInfos>::manager> CATPLMComplexTypeObjInfosArray;

#endif
