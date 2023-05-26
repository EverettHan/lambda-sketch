/**
 * @level Private
 * @usage U1
 */
#if !defined( __CATOmxOrderedOSet_h__ )
#define       __CATOmxOrderedOSet_h__

#include "CATOmxKernel.h"
#include "CATOmxIter.h"
#include "CATOmxBaseOrderedOSet.h"
#include "CATOmxPortability.h"
#include "CATOmxDefaultCollecManager.h"


 /*
  * Implement an ordered set of T.
  * @href http://osmwebdsy/wiki/index.php/CATOmxOrderedOSet_Usage
  * @see  CATOmxBaseOrderedOSet
  * @param T the collection Type
  * @param TMgr the collection manager
  */
template<class T, CATOmxCollecManagerLocator TMgr = CATOmxDefaultCollecManager<T>::manager>
class CATOmxOrderedOSet : public CATOmxBaseOrderedOSet
{
public:
  typedef T ValueType;
  typedef T const KeyType;
  typedef CATOmxIter<T> IteratorType;
  typedef CATOmxIter<const T> ConstIteratorType;

  /*
   * Build an empty set.
   * @param iSize the number of item to preallocate
   */
  inline CATOmxOrderedOSet<T, TMgr>(unsigned iSize) : CATOmxBaseOrderedOSet(TMgr(), iSize) {}

  inline CATOmxOrderedOSet<T, TMgr>() {}
  /*
   * Build the collection using an iterator.
   * @param iter the iterator (warning, despite const type specifier, iter is emptied)
   */
  inline CATOmxOrderedOSet<T, TMgr>(const IteratorType& iter) { CopyIter(TMgr(), const_cast<IteratorType&>(iter).PrivateStrip()); }
  inline CATOmxOrderedOSet<T, TMgr>(const ConstIteratorType& iter) { CopyIter(TMgr(), const_cast<ConstIteratorType&>(iter).PrivateStrip()); }

  /*
   * Build the collection using an iterator.
   * @param iter the iterator (warning, despite const type specifier, iter is emptied)
   */
  inline CATOmxOrderedOSet<T, TMgr>& operator=(const IteratorType &iter) { CopyIter(TMgr(), const_cast<IteratorType&>(iter).PrivateStrip()); return *this; }
  inline CATOmxOrderedOSet<T, TMgr>& operator=(const ConstIteratorType &iter) { CopyIter(TMgr(), const_cast<ConstIteratorType&>(iter).PrivateStrip()); return *this; }
  /*
   * Build the collection from another.
   * @param collec the collection
   */
  inline CATOmxOrderedOSet<T, TMgr>(const CATOmxOrderedOSet<T, TMgr> &collec)
  {
    CopySet(TMgr(), collec);
  }
  /*
   * Build the collection from another.
   * @param collec the collection
   */
  inline CATOmxOrderedOSet<T, TMgr>& operator=(const CATOmxOrderedOSet<T, TMgr> &collec)
  {
    CopySet(TMgr(), collec);
    return *this;
  }

  inline ~CATOmxOrderedOSet(void) { RemoveAll(); }

  /** return size.  */
  using CATOmxBaseOrderedOSet::Size;
  /** return true if empty. */
  using CATOmxBaseOrderedOSet::IsEmpty;
  using CATOmxBaseOrderedOSet::IsEqual;
  using CATOmxBaseOrderedOSet::CompareValues;

  /*
   * Insert  an item.
   * Warning: if item is yet present, it will not be replaced.
   * @param item to Insert
   * @param allowDuplicate: do not use
   * @return
   *   old item
   */
  inline const ValueType *Insert(const KeyType &item)
  {
    return reinterpret_cast<ValueType*>(CATOmxBaseOrderedOSet::InsertItem(TMgr(), &item));
  }

  /*
  * Insert a collection of items.
  * Warning: if some items are already present, they will not be replaced.
  * @param items
  *  items to insert to Insert
  * @return
  *   The number of inserted items
  */
  inline int Insert(const IteratorType& items) { return CATOmxBaseOrderedOSet::InsertItems(TMgr(), const_cast<IteratorType&>(items).PrivateStrip()); }
  inline int Insert(const ConstIteratorType& items) { return CATOmxBaseOrderedOSet::InsertItems(TMgr(), const_cast<ConstIteratorType&>(items).PrivateStrip()); }

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
  inline const ValueType *Replace(const KeyType& item)
  {
    return reinterpret_cast<ValueType*>(CATOmxBaseOrderedOSet::ReplaceItem(TMgr(), &item));
  }

  /*
   * @param item
   *  the item to find
   * @return
   *   found item.
   */
  inline const ValueType *Locate(const KeyType &item) const
  {
    return reinterpret_cast<ValueType*>(CATOmxBaseOrderedOSet::LocateItem(TMgr(), &item));
  }
  inline ValueType *LocateForWrite(const KeyType &item)
  {
    return reinterpret_cast<ValueType*>(CATOmxBaseOrderedOSet::LocateItemForWrite(TMgr(), &item));
  }

  /*
   * @param item to Remove
   * @return TRUE if removed
   */
  inline CATBoolean Remove(const KeyType& item, CATBoolean keepAllocation = FALSE) { return CATOmxBaseOrderedOSet::RemoveItem(TMgr(), &item, keepAllocation); }

  /**
   * Remove all items.
   */
  inline void RemoveAll(void)
  {
    CATOmxBaseOrderedOSet::RemoveAll(TMgr());
  }

  /**
   * Pack collection for minimal memory usage.
   */
  inline void Pack(void)
  {
    CATOmxBaseOrderedOSet::Pack(TMgr());
  }

  /** PreAllocate for future usage to minimize reallocate flow. */
  inline void Reserve(unsigned int iSize) { CATOmxBaseOrderedOSet::Reserve(TMgr(), iSize); }
  /** Insure a private version of the collection. */
  inline int Isolate() { return CATOmxBaseOrderedOSet::Isolate(TMgr()); }

  /**
   * Returns an iterator on all items of the collection.
   * Order is the insertion order.
   */
  inline IteratorType Iterator() const { return IteratorType(CATOmxBaseOrderedOSet::Iterator(TMgr())); }
  inline ConstIteratorType ConstIterator() const { return ConstIteratorType(CATOmxBaseOrderedOSet::ConstIterator(TMgr())); }

  /**
   * deprecated, use NextInBucket
   */
  inline IteratorType LocateByHashKey(CATHashKey iHashKey) const { return IteratorType(CATOmxBaseOrderedOSet::LocateByHashKey(TMgr(), iHashKey)); }

  /**
   * Comparison operators
   * note that result depends on CATOmxCollecManager::Compare implementation
   */
  inline int operator==(const CATOmxOrderedOSet<T, TMgr>& iRight) const { return CATOmxBaseOrderedOSet::IsEqual(iRight, TMgr(), NULL); }
  inline int operator!=(const CATOmxOrderedOSet<T, TMgr>& iRight) const { return !this->operator==(iRight); }

  /** range for support */
  typedef CATOmxSTLIter<const T> const_iterator;
  inline const_iterator begin() const { return const_iterator(ConstIterator()); }
  inline const_iterator end()   const { return const_iterator(); }


#if OMX_CXX11 == 1
  /** move semantics */
  inline CATOmxOrderedOSet(CATOmxOrderedOSet&& other) :CATOmxBaseOrderedOSet(std::move(other)) {}
  inline CATOmxOrderedOSet& operator=(CATOmxOrderedOSet&& other) { return static_cast<CATOmxOrderedOSet&>(this->CATOmxBaseOrderedOSet::operator=(std::move(other))); }

  /** initializer list */
  inline CATOmxOrderedOSet(std::initializer_list<T> list) : CATOmxBaseOrderedOSet(TMgr(), (unsigned int)list.size())
  {
    for (const T& item : list)
      Insert(item);
  }
  inline CATOmxOrderedOSet& operator=(std::initializer_list<T> list) { return this->operator=(CATOmxOrderedOSet(list)); }
#endif

  /** std::back_inserter/inserter support */
  typedef T value_type;
  typedef const_iterator iterator;
  inline void push_back(const T& item) { Insert(item); }
  inline const iterator& insert(const iterator& dummy, const T& item) { Insert(item); return dummy; }
};



#endif
