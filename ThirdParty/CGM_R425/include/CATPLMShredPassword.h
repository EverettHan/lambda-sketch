#ifndef CATPLMShredPassword_H
#define CATPLMShredPassword_H

#include "CATPLMIdentificationAccess.h"

class CATUnicodeString;

class ExportedByCATPLMIdentificationAccess CATPLMShredPassword
{
friend class CATPLMSessionInitializer;
friend class TSTCATPLMSessionInititalizer;
friend class CATPLMSessionServices;
friend class CATPLMHexaNormalView;
private:
static void ShredString(CATUnicodeString &ioCUS);
};

#endif
