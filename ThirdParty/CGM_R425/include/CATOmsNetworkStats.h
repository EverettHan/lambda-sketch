#ifndef CATOMSNETWORKSTATS_H
#define CATOMSNETWORKSTATS_H

#include <list>
#include "CATDataType.h"
#include "CATUuid.h"
#include "CATOmxList.h"
#include "CATOMYBackground.h"
#include "CATOmsNetworkTransactionStats.h"

class CATOmyCioUrlUsageCtx;
class ExportedByCATOMYBackground CATOmsNetworkStats
{
public:
  ~CATOmsNetworkStats() = default;
  static CATOmsNetworkStats& Get();

  // record the beginning and end of download requests. This allows to get download network speed. If request leads to a fail, it is not integrated in calculations.
  void OnDownloadRequestStart(CATUuid iRequestId, const CATOmxList<CATOmyCioUrlUsageCtx> &iUrls);
  void OnDownloadRequestEnd(CATUuid iRequestId, bool iFail=false);

  // record the beginning and end of upload requests. This allows to get upload network speed. If request leads to a fail, it is not integrated in calculations.
  void OnUploadRequestStart(CATUuid iRequestId, CATOmxList<CATOmyCioUrlUsageCtx> &iUrls);
  void OnUploadRequestEnd(CATUuid iRequestId, bool iFail=false);

  //speed in bytes/second. negative value means no valid speed has been computed.
  CATLONG64 GetDownloadAverageSpeed();
  CATLONG64 GetUploadAverageSpeed();

  void Clear();
private:
  CATOmsNetworkStats();
  //<older first in array>
  CATLONG64 _averageDownloadSpeed = -1;
  CATLONG64 _averageUploadSpeed = -1;
  std::list<CATOmsNetworkTransactionStats> _downloadspeeds;
  std::list<CATOmsNetworkTransactionStats> _uploadspeeds;
};


#endif

