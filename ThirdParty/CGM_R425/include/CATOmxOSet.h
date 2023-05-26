/**
 * @level Private
 * @usage U1
 */
#if !defined( __CATOmxOSet_h__ )
#define       __CATOmxOSet_h__

#include "CATOmxKernel.h"
#include "CATOmxSharable.h"
#include "CATOmxIter.h"
#include "CATOmxCollecManager.h"
#include "CATOmxCellCollecManager.h"
#include "CATOmxBaseSet.h"
#include "CATOmxPortability.h"
#include "CATOmxDefaultCollecManager.h"


 /*
  * Implement a set of T
  * @href http://osmwebdsy/wiki/index.php/CATOmxOSet_Usage
  * @see  CATOmxBaseSet
  * @param T the collection Type
  * @param TMgr the collection manager
  */
template<class T, CATOmxCollecManagerLocator TMgr = CATOmxDefaultCollecManager<T>::manager>
class CATOmxOSet : public CATOmxBaseSet
{
public:
  typedef T ValueType;
  typedef T const KeyType;
  typedef CATOmxIter<T> IteratorType;
  typedef CATOmxIter<const T> ConstIteratorType;

  OMX_STATIC_ASSERT_CLASS_SCOPE(!std::is_pointer<T>::value, "CATOmxOSet must not be used on pointers, use CATOmxSet")

    /*
     * Build an empty set.
     * @param iSize the number of item to preallocate
     */
    OMX_EXPLICIT inline CATOmxOSet<T, TMgr>(unsigned iSize = 0) : CATOmxBaseSet(iSize) {}
  /*
   * Build the collection using an iterator.
   * @param iter the iterator (warning, despite const type specifier, iter is emptied)
   */
  inline CATOmxOSet<T, TMgr>(const IteratorType& iter)
  {
    CATOmxCellCollecManager mgr(TMgr);
    CopyIter(mgr, const_cast<IteratorType&>(iter).PrivateStrip());
  }
  /*
   * Build the collection using an iterator.
   * @param iter the iterator (warning, despite const type specifier, iter is emptied)
   */
  inline CATOmxOSet<T, TMgr>& operator=(IteratorType &iter)
  {
    CATOmxCellCollecManager mgr(TMgr);
    CopyIter(mgr, const_cast<IteratorType&>(iter).PrivateStrip());
    return *this;
  }
  /*
   * Build the collection from another.
   * @param collec the collection
   */
  inline CATOmxOSet<T, TMgr>(const CATOmxOSet<T, TMgr>& collec)
  {
    CATOmxCellCollecManager mgr(TMgr);
    CopySet(mgr, collec);
  }
  /*
   * Build the collection from another.
   * @param collec the collection
   */
  inline CATOmxOSet<T, TMgr>& operator=(const CATOmxOSet<T, TMgr> &collec)
  {
    CATOmxCellCollecManager mgr(TMgr);
    CopySet(mgr, collec);
    return *this;
  }

  inline ~CATOmxOSet() { RemoveAll(); }

  inline void Reserve(int iSize)
  {
    CATOmxCellCollecManager mgr(TMgr);
    return CATOmxBaseSet::Reserve(mgr, iSize);
  }

  /**
   * return size.
   */
  using CATOmxBaseSet::Size;
  /** return true if empty. */
  using CATOmxBaseSet::IsEmpty;
  using CATOmxBaseSet::CompareValues;
  using CATOmxBaseSet::IsEqual;

  /*
   * Insert  an item.
   * Warning: if item is yet present, it will not be replaced.
   * @param item to Insert
   * @param allowDuplicate: do not use
   * @return
   *   old item
   */
  inline const ValueType *Insert(const KeyType &item, int allowDuplicate = 0)
  {
    CATOmxCellCollecManager mgr(TMgr);
    return reinterpret_cast<ValueType*>(mgr.HSetRequire(&item, FALSE, allowDuplicate != 0, *this));
  }
  /*
   * Replace an item.
   * @param item to Replace
   * @return
   *   old item
   */
  inline const ValueType *Replace(const KeyType &item)
  {
    CATOmxCellCollecManager mgr(TMgr);
    return reinterpret_cast<ValueType*>(mgr.HSetRequire(&item, TRUE, 0, *this));
  }

  /*
   * @param item to find
   * @return
   *   found item.
   *   Warning, pointer is valid only until next alteration of the collection.
   */
  inline const ValueType *Locate(const KeyType &item) const
  {
    CATOmxCellCollecManager mgr(TMgr);
    return reinterpret_cast<ValueType*>(CATOmxBaseSet::LocateItem(mgr, &item));
  }
  /**
   * if iKey is not present, returns NULL else returns a pointer on the corresponding value.
   */
  inline ValueType* LocateForWrite(const KeyType &iKey)
  {
    CATOmxCellCollecManager mgr(TMgr);
    return reinterpret_cast<ValueType*>(LocateItemForWrite(mgr, &iKey));
  }

  /*
  * Remove an item from collection.
  * @param item: the item to remove
  * @return TRUE if removed
  */
  inline CATBoolean Remove(const KeyType& item)
  {
    CATOmxCellCollecManager mgr(TMgr);
    return reinterpret_cast<ValueType*>(CATOmxBaseSet::RemoveItem(mgr, &item)) != 0;
  }

  /**
   * Remove all items.
   */
  inline void RemoveAll()
  {
    CATOmxCellCollecManager mgr(TMgr);
    CATOmxBaseSet::RemoveAll(mgr);
  }

  /**
   * Pack collection for minimal memory usage.
   */
  inline void Pack()
  {
    CATOmxCellCollecManager mgr(TMgr);
    CATOmxBaseSet::Pack(mgr);
  }

  /**
   * Returns an iterator on all items of the collection.
   * ORDER IS NOT GUARANTEED/STABLE.
   */
  inline IteratorType Iterator() const
  {
    CATOmxCellCollecManager mgr(TMgr);
    CATOmxBaseIter* itr = CATOmxBaseSet::OSetBaseIterator(mgr);
    return IteratorType(itr);
  }

  inline ConstIteratorType ConstIterator() const
  {
    CATOmxCellCollecManager mgr(TMgr);
    CATOmxBaseIter* itr = CATOmxBaseSet::OSetBaseIterator(mgr);
    return ConstIteratorType(itr);
  }

  /**
   * Comparison operators
   * Note that result depends on CATOmxCollecManager::Compare implementation
   */
  inline int operator==(const CATOmxOSet<T, TMgr>& iRight) const
  {
    CATOmxCellCollecManager mgr(TMgr);
    return CATOmxBaseSet::IsEqual(iRight, mgr, NULL);
  }
  inline int operator!=(const CATOmxOSet<T, TMgr>& iRight) const { return !this->operator==(iRight); }

  /** range for support */
  inline CATOmxSTLIter<const T> begin() const { return CATOmxSTLIter<const T>(ConstIterator()); }
  inline CATOmxSTLIter<const T> end()   const { return CATOmxSTLIter<const T>(); }

#if OMX_CXX11 == 1
  /** move semantics */
  inline CATOmxOSet(CATOmxOSet&& other) :CATOmxBaseSet(std::move(other)) {}
  inline CATOmxOSet& operator=(CATOmxOSet&& other) { return static_cast<CATOmxOSet&>(this->CATOmxBaseSet::operator=(std::move(other))); }

  /** initializer list */
  inline CATOmxOSet(std::initializer_list<T> list) : CATOmxBaseSet((unsigned int)list.size())
  {
    for (const T& item : list)
      Insert(item);
  }
  inline CATOmxOSet& operator=(std::initializer_list<T> list) { return this->operator=(CATOmxOSet(list)); }
#endif
};

#endif
