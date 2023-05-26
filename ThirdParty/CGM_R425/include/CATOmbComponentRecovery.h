#ifndef _CATOmbComponentRecovery_H
#define _CATOmbComponentRecovery_H
/**
 * @level Private
 * @usage U1
 */
#include "CATOmbLinkTrader.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"

class CATComponentId;
class CATStorage;
class CATOmbRelationalImportFormat;
class CATOmbComponentLinkTable;
class CATOmbVirtualStorage;

class CATOmbComponentRecovery
{

public:

  static CATBoolean Activated() { return _Activated; }

  /**
  * Usage interne pour le cleaner de relations
  */
  static void Activate(CATBoolean iBool) { _Activated = iBool; }

  /**
  * On va s'assurer que la vue relationnelle est bien rechargeable sns provoquer d'assertion � cause de doublons ou probl�mes d'int�grit�
  */
  static CATBoolean CheckIfRelationalViewIsLoadable(const CATComponentId & iComId, CATOmbRelationalImportFormat &  iRelationalFormat);

  /**
  * En cas d'invalidit� de la vue relationnelle, on va switcher sur la copie de s�curit�
  */
  static void ReplaceRelationalViewWithSafeCopy(const CATComponentId & iComId, CATOmbVirtualStorage & iStorage);

  /**
  * Clean sommaire du sommaire apres unmarshalling
  */
  static void UpgradeRelationalViewAfterLinkUnmarshalling(CATOmbComponentLinkTable * iCLT);
private:

  ExportedByCATOmbLinkTrader static CATBoolean _Activated;
};

#endif
