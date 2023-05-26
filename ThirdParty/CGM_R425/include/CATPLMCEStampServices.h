#include "CATPLMCEStampServices_CATDCMpgTestCommonServices.h" //yep, big hack here

#ifndef CATPLMCEStampServices_H
#define CATPLMCEStampServices_H

#include "CATPLMIdentificationAccess.h"
#include "IUnknown.h"
class CATPLMCEStamp;
class CATTime;

/**
* @level Private
* @usage U1
*/

/** obsolete */
class ExportedByCATPLMIdentificationAccess CATPLMCEStampServices 
{
public:
  /** obsolete, use CATPLMCEStamp default constructor */
  static CATPLMCEStamp CreateInvalidCEStamp();
};


#endif
