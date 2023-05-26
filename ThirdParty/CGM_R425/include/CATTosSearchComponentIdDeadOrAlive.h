#ifndef CATTosSearchComponentIdDeadOrAlive_H
#define CATTosSearchComponentIdDeadOrAlive_H

#include "ExportedByCATPLMTos.h"
#include "CATComponentId.h"
#include "CATBaseUnknown.h"

/**
 * compatibility with initial implementation of CATComponentId constructor
 * find TOS cell from a PLM component which is alive or garbaged (deleted but deletion is undoable)
 */
ExportedByCATPLMTos CATComponentId CATTosSearchComponentIdDeadOrAlive(CATBaseUnknown* iObject);

#endif
