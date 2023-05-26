#ifndef CATOmyPowerIOCanceledOperations_H
#define CATOmyPowerIOCanceledOperations_H

#include "CATOmxArray.h"
#include "IUnknown.h"
#include "CATOMY.h"
class CATUuid;
class CATVVSUrl;
template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATVVSUrl>::manager();

class ExportedByCATOMY CATOmyPowerIOCanceledOperations
{
public:
  static HRESULT RegisterCanceledCheckout(const CATUuid& iTransactionId, const CATOmxArray<CATVVSUrl>& iSourceUrlsFullyCanceled, const CATOmxArray<CATVVSUrl>& iSourceUrlsCanceledWithFallback);
  static HRESULT GetCanceledCheckout(const CATUuid& iTransactionId, CATOmxArray<CATVVSUrl>& oSourceUrlsFullyCanceled, CATOmxArray<CATVVSUrl>& oSourceUrlsCanceledWithFallback);
  static HRESULT RemoveTransactionData(const CATUuid& iTransactionId);
};

#endif // CATOmyPowerIOCanceledOperations
