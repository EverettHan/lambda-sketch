#ifndef CATPLMLifeCycleRootsBag_H
#define CATPLMLifeCycleRootsBag_H

/**
  * @level Protected
  * @usage U1
  */
#include "CATOmbLifeCycle.h"
#include "CATBaseUnknown.h"
#include "CATOmbLifeCycleRootsBag.h"

class CATPLMBag;

/**
 * Yet another bag class.
 * you can use it to convert a CATPLMBag to CATOmbLifeCycleRootsBag
 */
class ExportedByCATOmbLifeCycle CATPLMLifeCycleRootsBag: public CATOmbLifeCycleRootsBag
{
public:
  CATPLMLifeCycleRootsBag(CATOmbLifeCycleRootsBag& iBag);
  CATPLMLifeCycleRootsBag(CATPLMBag& iBag);
  inline CATPLMLifeCycleRootsBag() {}
  inline ~CATPLMLifeCycleRootsBag() {}

  /**
  * Transfer to PLM bag or internal management
  */
  CATPLMBag Transfer();

  void Bind(CATOmbLifeCycleRootsBagImpl* iLetter);
};

//-----------------------------------------------------------------------

#endif
