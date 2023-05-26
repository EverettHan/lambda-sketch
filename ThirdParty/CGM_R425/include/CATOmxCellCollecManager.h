#ifndef __CATOmxCellCollecManager_h__
#define __CATOmxCellCollecManager_h__
#include "CATOmxKernel.h"
#include "CATOmxCollecManager.h"
class CATOmxBaseSet;


class ExportedByCATOmxKernel CATOmxCellCollecManager: public CATOmxPtrManager
{
public:
  CATOmxCollecManager &keyMgr;
public:
  CATOmxCellCollecManager(CATOmxCollecManagerLocator iKeyLocator);
  virtual void InitVect(void *iDest,const void *iSrc,unsigned iLen) const ;
  virtual void SetVect(void *iDest,const void *iSrc, unsigned iLen) const;
  virtual void UnsetVect(void *iSrc,unsigned iLen) const;
  virtual CATHashKey Hash(const void* St) const;
  virtual int Compare(const void* St1, const void* St2) const;
  void* HSetRequire(const void* iKey,CATBoolean a, CATBoolean b, CATOmxBaseSet& iSet);
};
#endif

