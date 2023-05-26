/**
 * @level Private
 * @usage U1
 */
#ifndef __CATOmxBaseBigSet_H
#define __CATOmxBaseBigSet_H

#include "CATOmxKernel.h"
#include "CATOmxPortability.h"
class CATOmxCollecManager;
class CATOmxBaseIter;
class CATOmxBaseSetInternal;

/**
 * Base implementation class for CATOmxBigSet.
 * Must not be used directly, use CATOmxBigSet.
 * @see CATOmxBaseSet CATOmxBigSet
 */
class ExportedByCATOmxKernel CATOmxBaseBigSet 
{
private:
  CATOmxBaseBigSet(const CATOmxBaseBigSet& );
  CATOmxBaseBigSet& operator=(const CATOmxBaseBigSet& );
protected:
  CATOmxBaseBigSet(unsigned int iSize=0);
  ~CATOmxBaseBigSet();
  unsigned int Size() const;
  void* InsertItem(CATOmxCollecManager& ,const void* ,int ,int);
  int InsertItems(CATOmxCollecManager& ,CATOmxBaseIter* );
  void* LocateItem(CATOmxCollecManager& ,const void* ) const;
  void* RemoveItem(CATOmxCollecManager& ,const void* );
  void RemoveAll(CATOmxCollecManager& );
  void Reserve(CATOmxCollecManager&,unsigned int );
  CATOmxBaseIter* Iterator(CATOmxCollecManager&) const;
  void* NextInBucket(CATHashKey ,int& ) const;
private:
  CATOmxBaseSetInternal* m_datas;
};

#endif
