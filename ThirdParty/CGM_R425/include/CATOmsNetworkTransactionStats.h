#ifndef CATOMSNETWORKTRANSACTIONSTATS_H
#define CATOMSNETWORKTRANSACTIONSTATS_H

#include "CATAsyncRequest.h"
#include "CATDataType.h"
#include "CATOmxArray.h"

class CATOmyResourceReference;

class CATOmsNetworkTransactionStats
{
public:
  CATOmsNetworkTransactionStats() = delete;
  CATOmsNetworkTransactionStats(CATUuid iId, const CATOmxArray<CATOmyResourceReference> &iUrls);
  ~CATOmsNetworkTransactionStats();

  //in ms
  void SetOperationEnd();
  unsigned int GetDuration() const;

  //in bytes
  void SetSize(CATULONG64 iSize);
  CATLONG64 GetSize() const;

  //in seconds
  int HowOldAmI() const;

  bool HasThisId(CATUuid iId) const;
private:
  CATUuid _id;
  //CATOmxArray<CATVVSUrl> _urls;
  CATOmxArray<CATOmyResourceReference> _urls;
  unsigned int _operationDuration = 0;// in ms
  CATLONG64 _operationSize = 0; // in bytes
  CATTimeValue _creationTimestamp;
};


#endif

