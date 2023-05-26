#ifndef CATOxClipServices_H
#define CATOxClipServices_H

/**
* @level Private
* @usage U1
*/

#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"

class CATComponentId;
class CATProxySpace;
class CATPLMTypeH;

/**
* Usage is restricted to ObjectModelerBase Framework.
* Clip document life cycle management.
*/
namespace CATOxClipServices
{
  ExportedByCATPLMTos CATComponentId CreateTOSClipCell(CATProxySpace & iSpace, const CATPLMTypeH& iTypeH);
  ExportedByCATPLMTos CATComponentId AttachToNewClipCell(CATProxySpace& iSpace, const CATPLMTypeH& iTypeH, CATBaseUnknown& iCCPAtom);
  ExportedByCATPLMTos void SetClipboardCell(const CATComponentId & iCID);
  ExportedByCATPLMTos void RemoveClipboardCell(const CATComponentId & iCID);
  ExportedByCATPLMTos void FlushClipboard();
  ExportedByCATPLMTos CATComponentId GetClipCell(const CATBaseUnknown& iCCPAtom);
};

#endif
