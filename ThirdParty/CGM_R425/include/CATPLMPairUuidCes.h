#ifndef CATPLMPairUuidCes_H
#define CATPLMPairUuidCes_H

#include "CATPLMServicesItf.h"

#include "CATPLMCEStamp.h"

#include "CATUuid.h"

class ExportedByCATPLMServicesItf CATPLMPairUuidCes
{
public:
  CATPLMPairUuidCes();
  CATPLMPairUuidCes(const CATUuid& iUuid, const CATPLMCEStamp& iCes);
  ~CATPLMPairUuidCes();
  CATPLMPairUuidCes(CATPLMPairUuidCes & iPair);
  CATPLMPairUuidCes& operator=(CATPLMPairUuidCes& iPair);

  CATUuid key;
  CATPLMCEStamp value;
};

#endif
