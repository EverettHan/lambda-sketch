#ifdef CATDCMpgTestCommonServices_H

#ifndef CATPLMCEStampServices_H
#define CATPLMCEStampServices_H

#include "CATPLMCEStamp.h"
#include "CATBinary.h"

/**
 * Warning: insance hack here
 * in CATDCMpgTestCommonServices::CreateAndTestV6Component,
 * after an erroneous migration, CATPLMCEStampServices::CreateInvalidCEStamp (which is NULL) is used as a valid CEStamp but also as the default invalid one...
 * later the "invalid" CEStamp is marshalled, and due to a hack in CATPLMCEStamp::SaveAsBinary/CATPLMCEStamp::Stream instead of returning failure it is epoch time_t CEStamp that is streamed...
 * Later, invalid CEStamp (which should be a valid one) is compared to epoch time_t CEStamp and thanks to a hack (NULL CEStamp == epoch time_t CEStamp) in CATPLMCEStamp::operator== it returns "yes they are equal"
 * This second hack makes CATPLMCEStamp::operator==  wrong, non symetric and and non transitive which is insanely dangerous
 * In order to fix that without breaking hundreds of CATDCMpgTestCommonServices related odts, we detected here that we are in the context of this test code and force "invalid CEStamp" (NULL) to be epoch time_t CEStamp
 * TODO(02/29/2016): migrate CATDCMpgTestCommonServices
 */

#define CATPLMCEStampServices CATPLMCEStampServices_CATDCMpgTestCommonServices
#define CreateInvalidCEStamp CATDCMpgTestCommonServices_CreateEpochInvalidCEStamp

class CATPLMCEStampServices_CATDCMpgTestCommonServices 
{
public:
  static inline CATPLMCEStamp CATDCMpgTestCommonServices_CreateEpochInvalidCEStamp()
  {
    CATBinary binary(3,reinterpret_cast<const signed char*>("\x31\x80\x80"));
    CATPLMCEStamp dummy;
    CATPLMCEStamp::RestoreFromBinary(dummy,binary);
    return dummy;
  }
};

#endif

#endif
