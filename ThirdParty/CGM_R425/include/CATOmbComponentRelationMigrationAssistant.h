#ifndef __CATOmbComponentRelationMigrationAssistant_H
#define __CATOmbComponentRelationMigrationAssistant_H

// COPYRIGHT DASSAULT SYSTEMES 2007

/**
 * @level Private
 * @usage U1
 */

#include "CATBoolean.h"
#include "IUnknown.h"
#include "CATObjectModelerBase.h"

class CATComponentId;
class CATOmbRelationInterface;

/***
 * This thingy is called by PC2 on connections/ports which are being restored from a stream (CATLnk, PLMCoreStreamStorage.Stream)
 *
 * if the connection/port is declared as
 *   FALSE == CATOmbRelationRuleManagerPrivateInterface::AreRelationsShareable()
 * (which means 1 link == 1 relation and is equivalent to "connection without stream", so we have a "connection without stream" that actually HAS a stream)
 *
 * then a migration is performed (maybe) in order to remove the "shared" flag on the relation (code is quite unclear and comes with zero comments)
 */
class CATOmbComponentRelationMigrationAssistant
{
public:
  inline CATOmbComponentRelationMigrationAssistant(CATComponentId & iCID) :_CID(iCID) {}

  ExportedByCATObjectModelerBase HRESULT MigrateRelations();

private:
  const CATComponentId& _CID;
};

#endif
