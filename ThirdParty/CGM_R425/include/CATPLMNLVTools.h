//===================================================================
// COPYRIGHT Dassault Systemes 2018/06/01
//===================================================================
// Header definition of class CATPLMNLVTools
//===================================================================
//
// Usage notes: Activation/Deactivation of NLV project
//
//===================================================================
//  2018/06/01 Creation: CME4/LCS2/JSL7/EPB
//===================================================================

#ifndef CATPLMNLVTools_H
#define CATPLMNLVTools_H

#include "CATPLMServicesItf.h"

#include "CATUnicodeString.h"
#include "CATUuid.h"

class ExportedByCATPLMServicesItf CATPLMNLVTools
{
  friend class CATPLMCompVersioningService;
public:

  enum eNLVProject
  {
    NLV_ENABLED_WRITE = 1,
    NLV_DISABLED = 2,
    NLV_ERROR = 3,
    NLV_UNSET = 4,
    NLV_ENABLED_READ_AND_WRITE = 5
  };

  // Activation of NLV project (Write mode)
  // If you are using "Internal DS" licence, then you can activate "set ENABLE_NLVLegacyAPIMigration=1" (Useful to perform Tests and Odts)
  // If you are a real customer and so if you don't have "Internal DS" licence, then you have to customize server:
  // modify expression NativeClientRevisionAuthoringOnServer  value AUTHORING_ENOVersioning ;
  // or
  // add expression NativeClientRevisionAuthoringOnServer  value AUTHORING_ENOVersioning;
  static eNLVProject IsNLVEnabled();

private:
  // Activation of NLV project (Read mode)
  static bool IsNLVEnableInReadMode();
};

#endif
