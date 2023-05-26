#ifndef CATMMCDEBUGSERVICES_H
#define CATMMCDEBUGSERVICES_H

#include "CATMMediaCore.h"
#include "CATUnicodeString.h"
#include "CATMMCProperties.h"

class ExportedByCATMMediaCore CATMMCDebugServices
{
public:
  static CATUnicodeString  GetTracesFromProperties(const CATMMCProperties& iProperties);
};
#endif
