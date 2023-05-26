#ifndef __CATOmyCioBoundingBoxCache_H
#define __CATOmyCioBoundingBoxCache_H

#include "CATOMYCuteIOAccess.h"
#include "CATOmyCioUrlUsageCtx.h"
#include "TagdbSpecializations.h"


//
// DO NOT USE
//
class ExportedByCATOMYCuteIOAccess CATOmyCioBoundingBoxCache
{

public:

  CATOmyCioBoundingBoxCache();
  ~CATOmyCioBoundingBoxCache();

  // S_OK    : Set in cache  
  // E_FAIL  : Internal error
  HRESULT SetInCache(const CATOmyCioUrlUsageCtx& iCtx, const double iCoordMin[], const double iCoordMax[]);
  
  // S_OK    : Found in cache
  // S_FALSE : Not Found in cache
  // E_FAIL  : Internal error
  HRESULT GetFromCache(const CATOmyCioUrlUsageCtx& iCtx, double oCoordMin[], double oCoordMax[]);    
  
private:
  
  HRESULT       _InitTagDb();
  TagdbBlbBlb * _tagdb;
  HRESULT       _tagdbhr;    
};

#endif // __CATOmyCioBoundingBoxCache_H
