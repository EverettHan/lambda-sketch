#ifndef CATOmbUnsetBySystemServices_H
#define CATOmbUnsetBySystemServices_H

/**
 * @level Protected
 * @usage U1
 */

 // SystemTS
#include "IUnknown.h"
// ObjectModelerCollection
#include "sequence_octet.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"

class CATIDocId;

class CATOmbUnsetBySystemServices
{
public:
  // Link resolution will fail with HR_LINKSOLVE_LinkUnsetBySystem return (@see CATOmbLink::Bind, CATIDocLinkManager::Bind).
  ExportedByCATObjectModelerBase static void GetCompleteLinkName(CATIDocId & iPointingDocId, _SEQUENCE_octet & oCompleteName);
  ExportedByCATObjectModelerBase static _SEQUENCE_octet const & GetLightLinkName();
  ExportedByCATObjectModelerBase static bool IsUnsetBySystemUuid(_SEQUENCE_octet const & iSequence);
};

#endif

