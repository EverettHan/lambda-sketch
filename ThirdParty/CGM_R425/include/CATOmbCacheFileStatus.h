#ifndef CATOMBCACHEFILESTATUS_H
#define CATOMBCACHEFILESTATUS_H

#include "CATOmxSR.h"
#include "CATDataType.h"

class CATError;
class CATOmbCacheFileStatus
{
public:
  CATOmbCacheFileStatus() = default;
  ~CATOmbCacheFileStatus() = default;

  bool _presentInCache = false;
  CATOmxSR<CATError> _error;
  CATLONG64 _size = -1; // in bytes
  unsigned int _estimatedDownloadTime = 0; // milliseconds
  unsigned int _estimatedUploadTime = 0; // milliseconds. For now same as DownloadTime, no upload speed computation
};

#endif
