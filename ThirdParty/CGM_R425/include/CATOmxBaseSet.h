/**
 * @level Private
 * @usage U1
 */
#ifndef CATOmxBaseSet_H
#define CATOmxBaseSet_H

#include "CATOmxKernel.h"
#include "CATOmxPortability.h"
class CATOmxCollecManager;

class CATOmxBaseHMap;
struct CATOmxMapIterContext;
class CATOmxPairCollecManager;
class CATOmxCellCollecManager;
class CATOmxBaseIter;

class CATOmxBaseSetInternal;

/**
 * Base implementation class for CATOmxSet.
 * Must not be used directly, use CATOmxSet.
 */
class ExportedByCATOmxKernel CATOmxBaseSet
{
public:
  inline CATOmxBaseSet() :m_datas(NULL) {}
  /*
   * Initialize the collection.
   * @param iSize: estimated collection size
   */
  OMX_EXPLICIT CATOmxBaseSet(unsigned iSize);

  ~CATOmxBaseSet();

  /*
   * @return
   *   The number of inserted items.
   */
  unsigned int Size() const;

  /*
   * Insert an item in the collection.
   * @param mgr
   *   the collection manager
   * @param item
   *   the item to insert
   * @param replace
   *   TRUE:  if a matching item was already present in the collection, it is replaced by input item.
   *   FALSE: if a matching item was already present in the collection, the collection is not modified
   * @return
   *   the old item (warning: it may be deleted)
   */
  void* InsertItem(CATOmxCollecManager& mgr, const void* item, int replace, int allowDuplicate = 0);

  /*
   * Insert a collection of items.
   * Warning: if some items are already present, they will not be replaced.
   * @param items
   *  items to insert to Insert
   * @return
   *   The number of inserted items
   */
  int InsertItems(CATOmxCollecManager& mgr, CATOmxBaseIter* items);

  /*
   * Locate an item in collection.
   * @param mgr
   *   the collection manager
   * @param item
   *   the item to locate
   * @return
   *   the item or NULL if not found
   */
  void* LocateItem(CATOmxCollecManager& mgr, const void* item) const;

  /*
  * Remove an item from the set.
  * @param item
  *   the item to remove
  * @param keepAllocation
  *   if true, do not reallocate internal data (optional, default is false)
  * @return
  *   removed item if found (warning: may be deleted) or NULL
  */
  void* RemoveItem(CATOmxCollecManager& mgr, const void* item);
  void* RemoveItem(CATOmxCollecManager& mgr, const void* item, CATBoolean keepAllocation);

  /*
   * RemoveAll item from collection.
   */
  void RemoveAll(CATOmxCollecManager& mgr);

  /* not implemented */
  void Pack(CATOmxCollecManager&);

  /**
   * Ensure that the collection is not shared.
   */
  int Isolate(CATOmxCollecManager&);

  /*
   * Prepare the collection to efficiently insert iSize items.
   */
  void Reserve(CATOmxCollecManager&, unsigned int iSize);

  /*
   * Return an iterator on the inserted items.
   * ORDER IS NOT GUARANTEED/STABLE.
   */
  CATOmxBaseIter* Iterator(CATOmxCollecManager&) const;

  /**
   * Returns an iterator on all items corresponding to input hash key.
   * ORDER IS NOT GUARANTEED/STABLE.
   * deprecated: use NextInBucket
   */
  CATOmxBaseIter* LocateByHashKey(CATOmxCollecManager& mgr, CATHashKey iHashKey) const;

  /** specific iterators for derived classes */
  CATOmxMapIterContext* MapIterator(CATOmxPairCollecManager& iContext) const;
  CATOmxBaseIter* MapBaseIterator(CATOmxPairCollecManager& iContext, int iOffset) const; //TODO: change signature to size_t
  CATOmxBaseIter* OSetBaseIterator(CATOmxCellCollecManager& iContext) const;

  /** return TRUE if empty.*/
  CATBoolean IsEmpty() const;

  /** LocateItem and prepare collection for write. */
  void* LocateItemForWrite(CATOmxCollecManager& mgr, const void* item);

  /** additional comparison function for IsEqual*/
  typedef int(*CompareValues)(const CATOmxCollecManager&, const void*, const void*);

  /**Return 1 if sets contains the same elements according to iManager & iCompareValues */
  int IsEqual(const CATOmxBaseSet& iRight, const CATOmxCollecManager& iManager, CompareValues iCompareValues) const;
protected:
  void CopySet(CATOmxCollecManager&, const CATOmxBaseSet&);
  void CopyIter(CATOmxCollecManager&, CATOmxBaseIter*);
  void* NextInBucket(CATHashKey iHashKey, int& ioIndex) const;

#ifdef DS_CXX11_SUPPORT_MOVE_SEMANTIC
  inline CATOmxBaseSet(CATOmxBaseSet&& other) :m_datas(other.m_datas) { other.m_datas = NULL; }
  inline CATOmxBaseSet& operator=(CATOmxBaseSet&& other)
  {
    CATOmxBaseSetInternal* data = m_datas;
    m_datas = other.m_datas;
    other.m_datas = data;
    return *this;
  }
#endif

private:
  CATOmxBaseSet(const CATOmxBaseSet&);
  CATOmxBaseSet& operator=(const CATOmxBaseSet&);
  union
  {
    CATOmxBaseSetInternal* m_datas;
    CATUINTPTR m_data;
  };
};

#endif
