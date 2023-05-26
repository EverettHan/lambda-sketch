#ifndef CATPLMDuplicationServices_H_
#define CATPLMDuplicationServices_H_


#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"

class CATComponentId;
class CATOmbLinkMap;

class CATPLMDuplicationServices
{
public:
  /**
   * reserved for CATPLMClientCore/CATPLMSpecsModeler
   */
  ExportedByCATObjectModelerBase static HRESULT DuplicateLinks(const CATComponentId & iSource, const CATComponentId & iTarget, CATOmbLinkMap& oLinkMap);
};

#endif




