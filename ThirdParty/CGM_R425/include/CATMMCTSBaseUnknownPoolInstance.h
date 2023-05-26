#ifndef CATMMCTSBASEUNKNOWNPOOLINSTANCE_H
#define CATMMCTSBASEUNKNOWNPOOLINSTANCE_H

#include "CATMMediaPixelImage.h"
#include "CATSysTSBaseUnknown.h"

class CATMMCTSBaseUnknownPool;

//Pooled objects have to dervie from CATSysTSBaseUnknown

/**
 * @ingroup groupMMCBaseUnknownPool
 * Instance of CATSystTSBaseUnknown which lifecycle will be managed by CATMMCTSBaseUnknownPool.
 */
class ExportedByCATMMediaPixelImage CATMMCTSBaseUnknownPoolInstance : public CATSysTSBaseUnknown
{
  friend class CATMMCTSBaseUnknownPool;
public:
  CATMMCTSBaseUnknownPoolInstance();
  virtual ~CATMMCTSBaseUnknownPoolInstance();
  virtual ULONG __stdcall Release();


protected:
  virtual bool BeforeReleasingInstanceToPool() { return 1; };


private:
  CATMMCTSBaseUnknownPool *_pPool;
  CATMutex                 _noneRecursiveMutex;

  bool DeclarePool(CATMMCTSBaseUnknownPool* ipPool);
  bool ReleaseDeletingPool();
};

#endif
