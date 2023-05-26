#ifndef _CATPLMLifeGuard_H
#define _CATPLMLifeGuard_H
/**
* @level Private
* @usage U1
*/

#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATPLMBag.h"

class CATComponentId;
class CATOxBag;

/**
 * PLM Components inserted into a Locker are protected against remove operations.
 * Components will be still alived after Locker deletion.
 * Usage is restricted to infrastructure
 */
class CATPLMLifeGuard final : public CATPLMBag
{
public:
  ExportedByCATPLMTos CATPLMLifeGuard();
};

#endif
