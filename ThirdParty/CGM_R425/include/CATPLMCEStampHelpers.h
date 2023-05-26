#ifndef CATPLMCEStampHelpers_H
#define CATPLMCEStampHelpers_H

#include "CATPLMIdentificationAccess.h"
#include "CATPLMCEStamp.h"
#include "CATUnicodeString.h"

/**
 * CATPLMCEStamp <=> string converters
 * compatible with M1 format (uuid using an hexadecimal string)
 * not compatible with CATPLMCEStamp::Stream/CATPLMCEStamp::Unstream
 */
struct ExportedByCATPLMIdentificationAccess CATPLMCEStampHelpers
{
  /**
   * Converts cestamp to an hexadecimal string
   * behavior on legacy TSTPROVIDER cestamps is unspecified (but functional)
   */
  static CATUnicodeString ToString(const CATPLMCEStamp& iCEStamp);

  /**
   * Build a cestamp from an hexadecimal string
   * behavior on legacy TSTPROVIDER cestamps is compatible with ToString format
   */
  static CATPLMCEStamp FromString(const CATUnicodeString& iString);
};

#endif
