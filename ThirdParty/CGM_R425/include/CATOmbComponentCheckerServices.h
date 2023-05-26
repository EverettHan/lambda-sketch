#ifndef _CATOmbComponentCheckerServices_H
#define _CATOmbComponentCheckerServices_H

/**
 * @level Private
 * @usage U1       
 */

#include "CATOmbLinkTrader.h"
#include "CATBaseUnknown.h"
#include "CATDataType.h"

class CATStorage;
class CATComponentId;
class CATUnicodeString;

class ExportedByCATOmbLinkTrader CATOmbComponentCheckerServices
{
public:

  static void ReadStreamWatermarkStamp (CATStorage & iStorage, CATULONG32 & oWatermarkStamp);

  static CATUnicodeString ReadAuthoringStreamDescriptorInfos (const CATComponentId & iComId, CATULONG32 & oStreamDescriptorWatermarkStamp);

};
 
#endif
