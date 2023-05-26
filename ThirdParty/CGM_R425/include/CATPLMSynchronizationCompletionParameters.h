// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @level Protected
 * @usage U1
 */

#ifndef CATPLMSynchronizationCompletionParameters_h
#define CATPLMSynchronizationCompletionParameters_h

#include "CATPLMIntegrationInterfaces.h"
#include "CATBoolean.h"
#include "CATPLMCompletionParameters.h"

 /** obsolete, use CATPLMCompletionParameters */
class CATPLMSynchronizationCompletionParameters : public CATPLMCompletionParameters
{
public:

  /** obsolete */
  enum CompleteWithRepsMode
  {
    MandatoryReps = CATPLMCompletionParameters::IntegrityReps,
    MandatoryAnd3DShapeReps = CATPLMCompletionParameters::Shape3DReps,
    AllReps = CATPLMCompletionParameters::AllReps
  };

  /**
  * Constuctor
  *   * iCompleteWithRepsMode      : see SetCompleteWithRepsMode
  *   * iCompleteWithMaterials     : see SetCompleteWithMaterials
  *   * iCompleteWithCnxAndPorts   : see SetCompleteWithCnxAndPorts
  */
  inline CATPLMSynchronizationCompletionParameters(CompleteWithRepsMode iCompleteWithRepsMode = AllReps, CATBoolean iCompleteWithMaterials = TRUE, CATBoolean iCompleteWithCnxAndPorts = TRUE) :CATPLMCompletionParameters((CATPLMCompletionParameters::RepMode)iCompleteWithRepsMode, iCompleteWithMaterials, iCompleteWithCnxAndPorts) {}
};
#endif
