#ifndef CATPLMTypeHHelpers_H
#define CATPLMTypeHHelpers_H

#include "CATPLMServicesItf.h"

#include "CATSysErrorDef.h"
#include "CATCollec.h"

class CATPLMTypeHArray;
class CATLISTV(CATPLMID);

class ExportedByCATPLMServicesItf CATPLMTypeHHelpers
{
public:
  static CATPLMTypeHArray Convert(const CATLISTV(CATPLMID)& iPlmid);
};

#endif
