#ifndef CATPLMIGDevActivation_H
#define CATPLMIGDevActivation_H

/**
 * @level Protected
 * @usage U1
 */
#include "CATPLMImpactGraph.h"
#include "CATBoolean.h"

class ExportedByCATPLMImpactGraph CATPLMIGDevActivation
{
public:

  static CATBoolean IsRequirementIntegration();

  static CATBoolean IsRequirementIntegrationDebug();

private:

  static CATBoolean _bRequirementIntegration;
  static CATBoolean _bRequirementIntegrationDebug;
};

#endif
