// COPYRIGHT Dassault Systemes 2006
#ifndef CATPLMBinaryCEStampPrivateFactory_H
#define CATPLMBinaryCEStampPrivateFactory_H

#include "CATPLMIdentificationAccess.h"
#include "IUnknown.h"

class CATPLMCEStamp;
class CATBinary;

/**
* @level Private
* @usage U1
*/

/**
 * Restricted availability (ask CATPLMIdentification framework owner)
 */
class ExportedByCATPLMIdentificationAccess CATPLMBinaryCEStampPrivateFactory 
{
public:

  /**
  * Gets the internal binary information. 
  */
  static HRESULT GetBinaryFromCEStamp(const CATPLMCEStamp & iCES, CATBinary & oBinary);

  /**
  * Creates a CE Stamp from a binary information. 
  */
  static CATPLMCEStamp CreateCEStampFromBinary(const CATBinary & iBinary);

};


#endif


