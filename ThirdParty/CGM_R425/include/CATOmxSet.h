/**
 * @level Private
 * @usage U1
 */
#ifndef CATOmxSet_H
#define CATOmxSet_H

#include "CATOmxKernel.h"
#include "CATOmxSharable.h"
#include "CATOmxIter.h"
#include "CATOmxBaseSet.h"
#include "CATOmxPortability.h"
#include "CATOmxDefaultCollecManager.h"


 /*
  * Implement a set of T*
  * @href http://osmwebdsy/wiki/index.php/CATOmxSet_Usage
  * @param T the collection Type
  * @param TMgr the collection manager
  */
template<class T, CATOmxCollecManagerLocator TMgr = CATOmxDefaultCollecManager<T*>::manager>
class CATOmxSet : private CATOmxBaseSet
{
public:
  typedef T * ValueType;
  typedef T const * KeyType;
  typedef CATOmxIter<T> IteratorType;
  typedef CATOmxIter<const T> ConstIteratorType;

  /*
   * Build an empty set.
   * @param iSize the number of item to preallocate
   */
  inline CATOmxSet<T, TMgr>() {}
  OMX_EXPLICIT inline CATOmxSet<T, TMgr>(unsigned iSize) : CATOmxBaseSet(iSize) {}

  /*
   * Build the collection using an iterator.
   * @param iter the iterator (warning, despite const type specifier, iter is emptied)
   */
  inline CATOmxSet<T, TMgr>(const IteratorType& iter) { CopyIter(TMgr(), const_cast<IteratorType&>(iter).PrivateStrip()); }
  inline CATOmxSet<T, TMgr>& operator=(const IteratorType &iter) { CopyIter(TMgr(), const_cast<IteratorType&>(iter).PrivateStrip()); return *this; }

  /*
   * Build the collection from another set.
   * @param other
   *   the set to copy
   */
  inline CATOmxSet<T, TMgr>(const CATOmxSet<T, TMgr>& other) { CopySet(TMgr(), other); }
  inline CATOmxSet<T, TMgr>& operator=(const CATOmxSet<T, TMgr>& other) { CopySet(TMgr(), other); return *this; }

  inline ~CATOmxSet() { RemoveAll(); }

  /*
  * @return
  *   The number of inserted items.
  */
  using CATOmxBaseSet::Size;

  /** @return TRUE if empty. */
  using CATOmxBaseSet::IsEmpty;

  /*
   * Insert an item.
   * Warning: if item is already present, it will not be replaced.
   * @param item
   *   the item to insert
   * @param allowDuplicate
   *   internal usage
   * @return
   *   NULL: item has been inserted
   *   not NULL: item has NOT been inserted, returned pointer is the address of an object matching item that is already present in the collection
   */
  inline ValueType Insert(KeyType item, int allowDuplicate = 0) { return reinterpret_cast<ValueType>(CATOmxBaseSet::InsertItem(TMgr(), item, FALSE, allowDuplicate)); }

  /*
  * Insert a collection of items.
  * Warning: if some items are already present, they will not be replaced.
  * @param items
  *  items to insert to Insert
  * @return
  *   The number of inserted items
  */
  inline int Insert(const IteratorType& items) { return CATOmxBaseSet::InsertItems(TMgr(), const_cast<IteratorType&>(items).PrivateStrip()); }

  /*
  * Replace an item.
  * If a matching item is already present, it is replaced by input item (contrarily to Insert)
  * Else input item is inserted
  * @param item
  *   the item to insert
  * @param allowDuplicate
  *   internal usage
  * @return
  *   the item that has been replaced (warning: may be deleted) or NULL
  */
  inline ValueType Replace(KeyType item) { return reinterpret_cast<ValueType>(CATOmxBaseSet::InsertItem(TMgr(), item, TRUE, 0)); }

  /*
   * Find an object in the set.
   * @param item
   *   the item to find
   * @return
   *   found item.
   */
  inline ValueType Locate(KeyType item) const { return reinterpret_cast<ValueType>(CATOmxBaseSet::LocateItem(TMgr(), item)); }

  /*
  * Remove an item from the set.
   * @param item
   *   the item to remove
   * @param keepAllocation
   *   if true, do not reallocate internal data (optional, default is false)
   * @return
   *   removed item if found (warning: may be deleted) or NULL
   */
  inline ValueType Remove(KeyType item, CATBoolean keepAllocation = FALSE) { return reinterpret_cast<ValueType>(CATOmxBaseSet::RemoveItem(TMgr(), item, keepAllocation)); }

  /**
   * Remove all items.
   */
  inline void RemoveAll() { CATOmxBaseSet::RemoveAll(TMgr()); }

  /* not implemented */
  inline void Pack() { CATOmxBaseSet::Pack(TMgr()); }

  /*
  * Prepare the collection to efficiently insert iSize items.
  */
  inline void Reserve(unsigned int iSize) { CATOmxBaseSet::Reserve(TMgr(), iSize); }

  /**
  * Ensure that the collection is not shared.
  */
  inline int Isolate() { return CATOmxBaseSet::Isolate(TMgr()); }

  /**
   * Returns an iterator on all items of the collection.
   * ORDER IS NOT GUARANTEED/STABLE.
   */
  inline IteratorType Iterator() const { return IteratorType(CATOmxBaseSet::Iterator(TMgr())); }
  inline ConstIteratorType ConstIterator() const { return ConstIteratorType(CATOmxBaseSet::Iterator(TMgr())); }

  /**
   * deprecated, use NextInBucket
   */
  inline IteratorType LocateByHashKey(CATHashKey iHashKey) const { return IteratorType(CATOmxBaseSet::LocateByHashKey(TMgr(), iHashKey)); }

  /**
   * Returns next element in bucket corresponding to iHashKey
   * There is no guarantee that returned element hash key is equal to iHashKey.
   * In all cases you must test full equality of returned object and of what you are looking for
   * Remember that the fact that two objects share same hash key does NOT involve they are the same.
   * Use case:
   *   class XXX {
   *     KeyType m_key;
   *   }
   *   CATOmxSet<XXX> set = ...;
   *   KeyType toSearch = ....:
   *   CATHashKey h = toSearch.Hash();
   *   int index = 0;
   *   while(const XXX* x = set.NextInBucket(h,index)) {
   *      if(x->m_key == toSearch) {
   *         //ok we found the item
   *         break;
   *      }
   *   }
   * The collection must not be modified during iteration.
   */
  inline ValueType NextInBucket(CATHashKey iHashKey, int& ioIndex) const { return (ValueType)CATOmxBaseSet::NextInBucket(iHashKey, ioIndex); }

  /** Comparison operators */
  inline int operator==(const CATOmxSet<T, TMgr>& iRight) const { return CATOmxBaseSet::IsEqual(iRight, TMgr(), NULL); }
  inline int operator!=(const CATOmxSet<T, TMgr>& iRight) const { return !this->operator==(iRight); }

  /** range for support */
  inline CATOmxSTLIter<T> begin() const { return CATOmxSTLIter<T>(Iterator()); }
  inline CATOmxSTLIter<T> end()   const { return CATOmxSTLIter<T>(); }

#if OMX_CXX11 == 1
  /** move semantics */
  inline CATOmxSet(CATOmxSet<T>&& other) :CATOmxBaseSet(std::move(other)) {}
  inline CATOmxSet& operator=(CATOmxSet&& other) { return static_cast<CATOmxSet&>(this->CATOmxBaseSet::operator=(std::move(other))); }

  /** initializer list */
  inline CATOmxSet(std::initializer_list<T*> list) : CATOmxBaseSet((unsigned int)list.size())
  {
    for (T* item : list)
      Insert(item);
  }
  inline CATOmxSet<T>& operator=(std::initializer_list<T*> list) { return this->operator=(CATOmxSet<T>(list)); }
#endif

  /** std::inserter support */
  typedef T value_type; //the actual type is Type& but that causes overloading issue in back_inserter between & and &&
  typedef CATOmxSTLIter<T> iterator;
  template<typename T2> //make it template in order to avoid an error with T=void (CATOmxSet<void>)
  inline const iterator& insert(const iterator& dummy, const T2& item) { Insert(&item); return dummy; } //const required because of previous hack
};

/**
 * CATOmxSet<*,com_manager> manager.
 */
ExportedByCATOmxKernel CATOmxCollecManager& com_set_manager();

/**
 * CATOmxSet<*,naive_manager> manager.
 */
ExportedByCATOmxKernel CATOmxCollecManager& naive_set_manager();

/**
 * CATOmxSet<*,sharable_manager> manager.
 */
ExportedByCATOmxKernel CATOmxCollecManager& sharable_set_manager();

#endif
