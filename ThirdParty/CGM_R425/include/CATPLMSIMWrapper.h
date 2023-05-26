/**
 * @level Private
 * @usage U1
 */

#ifndef CATPLMSIMWrapper_H
#define CATPLMSIMWrapper_H

#include "CATPLMIntegrationInfra.h"
#include "CATIOmySIMWrapper.h"
#include "CATBaseUnknown.h"
#include "CATPLMBag.h"
//-----------------------------------------------------------------------

class ExportedByCATPLMIntegrationInfra CATPLMSIMWrapper: public CATIOmySIMWrapper
{
public:
  CATDeclareClass;

  CATPLMSIMWrapper (CATPLMBag & iBag);
  virtual ~CATPLMSIMWrapper ();

  HRESULT Open();

  HRESULT DisableUIManagers();

private:
  CATPLMBag _Bag;

  CATPLMSIMWrapper (CATPLMSIMWrapper &);
  CATPLMSIMWrapper& operator=(CATPLMSIMWrapper&);

};

//-----------------------------------------------------------------------

#endif
