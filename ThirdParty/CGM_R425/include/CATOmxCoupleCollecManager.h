#ifndef CATOmxCoupleCollecManager_H
#define CATOmxCoupleCollecManager_H

#include "CATOmxCollecManager.h"
class CATOmxBaseOrderedOSet;

/**
* Reserved for internal use
* a manager of CATOmxPair
*/
class ExportedByCATOmxKernel CATOmxCoupleCollecManager : public CATOmxCollecManager
{
public:
  const CATOmxCollecManager& m_keyManager;
  const CATOmxCollecManager& m_valueManager;
  const size_t m_valueOffset;
  const size_t m_sizeOf;

  CATOmxCoupleCollecManager(CATOmxCollecManagerLocator iKeyLocator, CATOmxCollecManagerLocator iValueLocator, size_t iValueOffset, size_t iSizeOf);
  virtual void InitVect(void *iVect, unsigned iLen) const;
  virtual void InitVect(void *iDest, const void *iSrc, unsigned iLen) const;
  virtual void SetVect(void *iDest, const void *iSrc, unsigned iLen) const;
  virtual void UnsetVect(void *iSrc, unsigned iLen) const;
  virtual CATHashKey Hash(const void* St) const;
  virtual int Compare(const void* St1, const void* St2) const;
  void* HMapRequire(const void* iKey, CATOmxBaseOrderedOSet& iSet);
  static int CompareValues(const CATOmxCollecManager& mgr, const void* p1, const void* p2);
};

#endif
