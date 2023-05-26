// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATPLMUuidConverter.h
// Header definition of CATPLMUuidConverter
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// Feb 2016  Creation: EPB
//===================================================================
#ifndef CATPLMUuidConverter_H
#define CATPLMUuidConverter_H

#include "CATPLMServicesItf.h"

#include "CATSysErrorDef.h"

#include "CATUuid.h"

/**
* @level Private
* @usage U1
*/


class CATUnicodeString;

//class CATBoolean;

#include "CATCollec.h"

/**
 * Private class.
 */
class ExportedByCATPLMServicesItf CATPLMUuidConverter
{
  public:
    static HRESULT GetUuidFromHex (const CATUnicodeString& iHexStr, CATUuid& oAny );

  private:
    static int BuildUnsignedHexaValueFromChar(const char * stringToConvert, int length, unsigned char * weight);

};

#endif
