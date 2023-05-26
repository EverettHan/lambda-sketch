#ifndef CATPLMHexaNormalView_H
#define CATPLMHexaNormalView_H

#include "CATPLMServicesItf.h"

class CATUnicodeString;

class ExportedByCATPLMServicesItf CATPLMHexaNormalView
{
  friend class CATPLMParameter;
  friend class CATPLMSessionInitializer;
private:
static void GetHexaView (const CATUnicodeString &iVal,CATUnicodeString& oVal);

/**
* @deprecated
*/
static CATUnicodeString GetHexaView (const CATUnicodeString &iVal);

static void GetNormalView (const CATUnicodeString& iVal, CATUnicodeString& oVal);

};

#endif
