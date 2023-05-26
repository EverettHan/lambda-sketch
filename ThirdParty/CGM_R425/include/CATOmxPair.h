#ifndef __CATOmxPair_h__
#define __CATOmxPair_h__

#include "CATOmxKernel.h"
#include "CATOmxCollecManager.h"
struct CATOmxBasePair;
class CATOmxBaseSet;

template<typename KeyT, typename ValueT>
struct CATOmxPair
{
  KeyT key;
  ValueT value;

  /**DO NOT USE*/
  static inline size_t ValueOffset() { return offsetof(CATOmxPair, value); }

  /**comparison operators*/
  inline bool operator==(const CATOmxPair& other) const { return key == other.key && value == other.value; }
  inline bool operator!=(const CATOmxPair& other) const { return !this->operator==(other); }
};

/**
 * Reserved for internal use
 * a manager of pointers to CATOmxPair
 */
class ExportedByCATOmxKernel CATOmxPairCollecManager : public CATOmxPtrManager
{
public:
  const CATOmxCollecManager& m_keyManager;
  const CATOmxCollecManager& m_valueManager;
  const size_t m_valueOffset;
public:
  CATOmxPairCollecManager(CATOmxCollecManagerLocator iKeyLocator, CATOmxCollecManagerLocator iValueLocator, size_t iValueOffset); //stub to be remove
  CATOmxPairCollecManager(CATOmxCollecManagerLocator iKeyLocator, CATOmxCollecManagerLocator iValueLocator, size_t iValueOffset, size_t iSizeOf);
  virtual void InitVect(void *iDest, const void *iSrc, unsigned iLen) const;
  virtual void SetVect(void *iDest, const void *iSrc, unsigned iLen) const;
  virtual void UnsetVect(void *iSrc, unsigned iLen) const;
  virtual CATHashKey Hash(const void* St) const;
  virtual int Compare(const void* St1, const void* St2) const;
  void* HMapRequire(const void* iKey, CATOmxBaseSet& iSet);
  static int CompareValues(const CATOmxCollecManager& mgr, const void* p1, const void* p2);
};

#endif
