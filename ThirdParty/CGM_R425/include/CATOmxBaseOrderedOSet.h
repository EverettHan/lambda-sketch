/**
 * @level Private
 * @usage U1
 */
#ifndef __CATOmxBaseOrderedOSet_h__
#define __CATOmxBaseOrderedOSet_h__

#include "CATOmxKernel.h"
#include "CATOmxPortability.h"
class CATOmxCollecManager;

struct CATOmxMapIterContext;
class CATOmxPairCollecManager;
class CATOmxCellCollecManager;
class CATOmxCoupleCollecManager;
class CATOmxBaseIter;

class CATOmxBaseOrderedOSetInternal;

/**
 * Base implementation class for CATOmxSet.
 * Must not be used directly, use CATOmxSet.
 */
class ExportedByCATOmxKernel CATOmxBaseOrderedOSet
{
public:
  /*
   * Initialize the collection.
   * @param iSize: estimated collection size
   */
  CATOmxBaseOrderedOSet(CATOmxCollecManager &mgr, unsigned int iSize);

  inline CATOmxBaseOrderedOSet() { m_datas = 0; }
  ~CATOmxBaseOrderedOSet();

  /*
   * The number of inserted items.
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
  void* InsertItem(CATOmxCollecManager& mgr, const void* item);
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
   * same as InsertItem with replace=TRUE
   */
  void* ReplaceItem(CATOmxCollecManager& mgr, const void* item);

  /*
   * Locate an item in collection.
   * @param mgr
   *   the collection manager
   * @param item
   *   the item to locate
   * @return
   *   the item or NULL if not found
   */
  void* LocateItem(CATOmxCollecManager&mgr, const void*item) const;
  /*
   * Remove an item from collection.
   * @param
   *   mgr the collection manager
   * @param item
   *   the item to remove
   * @return
   *   TRUE if removed, FALSE if not found
   */
  CATBoolean RemoveItem(CATOmxCollecManager&mgr, const void* item);
  CATBoolean RemoveItem(CATOmxCollecManager&mgr, const void* item, CATBoolean keepAllocation);

  /*
   * RemoveAll item from collection.
   */
  void RemoveAll(CATOmxCollecManager&mgr);

  /*
   * Adjust the collection memory size to the best size.
   */
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
  CATOmxBaseIter* ConstIterator(CATOmxCollecManager&) const;

  /**
   * Returns an iterator on all items corresponding to input hash key.
   * ORDER IS NOT GUARANTEED/STABLE.
   * deprecated: use NextInBucket
   */
  CATOmxBaseIter* LocateByHashKey(CATOmxCollecManager& mgr, CATHashKey iHashKey) const;

  /** specific iterators for derived classes */
  CATOmxMapIterContext* MapIterator(CATOmxCoupleCollecManager &iContext) const;
  CATOmxBaseIter* MapBaseIterator(CATOmxCoupleCollecManager& iContext, int iOffset) const; //TODO: change signature to size_t
  CATOmxBaseIter* OSetBaseIterator(CATOmxCellCollecManager &iContext) const;

  /** return true if empty.*/
  CATBoolean IsEmpty() const;

  /** LocateItem and prepare collection for write. */
  void* LocateItemForWrite(CATOmxCollecManager& mgr, const void*item);

  /** additional comparison function for IsEqual*/
  typedef int(*CompareValues)(const CATOmxCollecManager&, const void*, const void*);

  /**Return 1 if sets contains the same elements according to iManager & iCompareValues */
  int IsEqual(const CATOmxBaseOrderedOSet& iRight, const CATOmxCollecManager& iManager, CompareValues iCompareValues) const;
protected:
  void CopySet(CATOmxCollecManager&, const CATOmxBaseOrderedOSet &);
  void CopyIter(CATOmxCollecManager&, CATOmxBaseIter *);
#ifdef DS_CXX11_SUPPORT_MOVE_SEMANTIC
  inline CATOmxBaseOrderedOSet(CATOmxBaseOrderedOSet&& other) :m_datas(other.m_datas) { other.m_datas = NULL; }
  inline CATOmxBaseOrderedOSet& operator=(CATOmxBaseOrderedOSet&& other)
  {
    CATOmxBaseOrderedOSetInternal* data = m_datas;
    m_datas = other.m_datas;
    other.m_datas = data;
    return *this;
  }
#endif
private:
  CATOmxBaseOrderedOSet(const CATOmxBaseOrderedOSet& not_ready_to_do);
  CATOmxBaseOrderedOSet& operator=(const CATOmxBaseOrderedOSet& not_ready_to_do);
  void MutateSet(CATOmxCollecManager&, unsigned int iSize);
  CATOmxBaseOrderedOSetInternal* m_datas;
};

#endif
