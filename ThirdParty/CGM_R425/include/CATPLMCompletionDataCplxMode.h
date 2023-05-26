#ifndef CATPLMCompletionDataCplxMode_h
#define CATPLMCompletionDataCplxMode_h

/**
 * @level Protected
 * @usage U1
 */

namespace CATPLMCompletionDataCplxMode
{
  /**
  * Specifies how complex plmids should be treated when added to the set.
  *  # NoModif : the PLMID is kept has is
  *  # Explode : the PLMID's components are split and added as single entities to the set.
  *              Only the last element keep the discipline
  *  # Last    : Only the last element kept
  */
  enum Mode{NoModif, Explode, Last};
};
#endif
