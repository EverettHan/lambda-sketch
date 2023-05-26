/**
 * @level Private
 * @usage U1
 */
#ifndef CATOmxOHMap_H
#define CATOmxOHMap_H

#include "CATOmxBaseSet.h"
#include "CATOmxPair.h"
#include "CATOmxIter.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxPortability.h"

template<class KeyT, class ValueT> class CATOmxMapIter;

/**
 * This class allows to do a mapping between keys and values.
 * See CATOmxBaseSet for implementations details.
 * You should normally not use the 3rd and 4th template arguments
 * as the CATOmxDefaultCollecManager pattern does the work.
 * Override these only if you know what you are doing.
 * @href http://osmwebdsy/wiki/index.php/CATOmxOHMap_Usage
 */
template<typename KeyT, typename ValueT = KeyT, CATOmxCollecManagerLocator KeyMgr = CATOmxDefaultCollecManager<KeyT>::manager, CATOmxCollecManagerLocator ValueMgr = CATOmxDefaultCollecManager<ValueT>::manager >
class CATOmxOHMap : public CATOmxBaseSet
{
public:
  typedef CATOmxPair< KeyT, ValueT > PairType;
  typedef ValueT ValueType;
  typedef KeyT KeyType;
  typedef CATOmxIter< PairType > IteratorType;
  typedef CATOmxIter< const PairType > ConstIteratorType;
  typedef CATOmxMapIter< KeyT, ValueT >  MapIteratorType;
  typedef CATOmxIter<KeyT> KeyIteratorType;
  typedef CATOmxIter<ValueT> ValueIteratorType;

  /** deprecated. */
  typedef PairType Pair;

  /** default constructor.  */
  inline CATOmxOHMap<KeyT, ValueT, KeyMgr, ValueMgr>() {}
  /** presizing constructor.  */
  OMX_EXPLICIT inline CATOmxOHMap<KeyT, ValueT, KeyMgr, ValueMgr>(unsigned int iSize)
  {
    Reserve(iSize);
  }

  /** copy constructor */
  inline CATOmxOHMap<KeyT, ValueT, KeyMgr, ValueMgr>(const CATOmxOHMap<KeyT, ValueT, KeyMgr, ValueMgr>& iHMap)
  {
    operator=(iHMap);
  }

  /** copy operator */
  inline CATOmxOHMap<KeyT, ValueT, KeyMgr, ValueMgr>& operator=(const CATOmxOHMap<KeyT, ValueT, KeyMgr, ValueMgr>& iHMap)
  {
    CATOmxPairCollecManager mgr(KeyMgr, ValueMgr, PairType::ValueOffset(), sizeof(PairType));
    CATOmxBaseSet::CopySet(mgr, iHMap);
    return *this;
  }

  /**
   * constructors/assignment operators from iterators
   */
  OMX_EXPLICIT inline CATOmxOHMap<KeyT, ValueT, KeyMgr, ValueMgr>(const IteratorType& iIterator) { operator=(iIterator); }
  OMX_EXPLICIT inline CATOmxOHMap<KeyT, ValueT, KeyMgr, ValueMgr>(const ConstIteratorType& iIterator) { operator=(iIterator); }
  inline CATOmxOHMap<KeyT, ValueT, KeyMgr, ValueMgr>& operator=(const IteratorType& iIterator) { return this->operator=(iterator_add_const(iIterator)); }
  inline CATOmxOHMap<KeyT, ValueT, KeyMgr, ValueMgr>& operator=(const ConstIteratorType& iIterator)
  {
    CATOmxPairCollecManager mgr(KeyMgr, ValueMgr, PairType::ValueOffset(), sizeof(PairType));
    CopyIter(mgr, const_cast<ConstIteratorType&>(iIterator).PrivateStrip());
    return *this;
  }


  /**
   * destructor.
   */
  inline ~CATOmxOHMap() { RemoveAll(); }


  /**
   * Same as require.
   */
  inline ValueType& operator[](const KeyType &iKey) { return Require(iKey); }

  /**
   * if iKey is not present, corresponding node is created with default value specified by the CollecManager.
   * Returns writable reference on the value.
   * This method is forbidden if you use com_manager as ValueT manager.
   */
  inline ValueType& Require(const KeyType &iKey)
  {
    CATOmxPairCollecManager mgr(KeyMgr, ValueMgr, PairType::ValueOffset(), sizeof(PairType));
    return *reinterpret_cast<ValueT*>(mgr.HMapRequire(&iKey, *this));
  }

  /** Locate an item. */
  inline const ValueType* Locate(const KeyType& iKey) const
  {
    CATOmxPairCollecManager mgr(KeyMgr, ValueMgr, PairType::ValueOffset(), sizeof(PairType));
    PairType* pair = reinterpret_cast<PairType*>(LocateItem(mgr, &iKey));
    return pair ? &pair->value : NULL;
  }

  /**
   * if iKey is not present, returns NULL else returns a pointer on the corresponding value.
   */
  inline ValueType* LocateForWrite(const KeyType &iKey)
  {
    CATOmxPairCollecManager mgr(KeyMgr, ValueMgr, PairType::ValueOffset(), sizeof(PairType));
    PairType* pair = reinterpret_cast<PairType*>(LocateItemForWrite(mgr, &iKey));
    return pair ? &pair->value : NULL;
  }

  /** same as Locate */
  inline const ValueType* LocateForGet(const KeyType &iKey) const { return Locate(iKey); }

  /**
   * @return TRUE is iKey is present in the dictionary
   */
  inline CATBoolean Exists(const KeyType &iKey) const { return 0 != Locate(iKey); }

  /**
   * CATOmxOMap like legacy iterator
   */
  inline const MapIteratorType MapIterator() const
  {
    CATOmxPairCollecManager mgr(KeyMgr, ValueMgr, PairType::ValueOffset(), sizeof(PairType));
    return MapIteratorType(CATOmxBaseSet::MapIterator(mgr), TRUE);
  }

  /**
   * Inserts the couple (iKey,iValue) in the map.
   * @return
   *   TRUE: (iKey,iValue) has been inserted in the map
   *   FALSE:  iKey was already in the map, associated value is NOT replaced by iValue
   * see also: Replace
   */
  inline CATBoolean Insert(const KeyType& iKey, const ValueType& iValue)
  {
    const PairType pair = { iKey,iValue };
    return Insert(pair);
  }
  inline CATBoolean Insert(const PairType& pair)
  {
    CATOmxPairCollecManager mgr(KeyMgr, ValueMgr, PairType::ValueOffset(), sizeof(PairType));
    return NULL == InsertItem(mgr, &pair, 0, 0);
  }

  /**
   * Insert a collection of couples (key,value)
   * Already existing elements are not updated
   * @return: the number of elements inserted
   */
  inline int Insert(const IteratorType& iIterator) { return Insert(iterator_add_const(iIterator)); }
  inline int Insert(const ConstIteratorType& iIterator)
  {
    CATOmxPairCollecManager mgr(KeyMgr, ValueMgr, PairType::ValueOffset(), sizeof(PairType));
    return InsertItems(mgr, const_cast<ConstIteratorType&>(iIterator).PrivateStrip());
  }

  /**
   * Associates iValue to iKey in the map.
   * The difference with Insert is that in all cases iValue is associated to iKey
   */
  inline CATBoolean Replace(const KeyType& iKey, const ValueType& iValue)
  {
    const PairType pair = { iKey,iValue };
    CATOmxPairCollecManager mgr(KeyMgr, ValueMgr, PairType::ValueOffset(), sizeof(PairType));
    return NULL == InsertItem(mgr, &pair, 1, 0);
  }

  /**
   * Remove input key from the collection
   * @return
   *   TRUE:  iKey has been removed from the collection
   *   FALSE: iKey was not present in the collection
   */
  inline CATBoolean Remove(const KeyType& iKey)
  {
    CATOmxPairCollecManager mgr(KeyMgr, ValueMgr, PairType::ValueOffset(), sizeof(PairType));
    return 0 != RemoveItem(mgr, &iKey);
  }

  /**
   * Remove all items.
   */
  inline void RemoveAll()
  {
    CATOmxPairCollecManager mgr(KeyMgr, ValueMgr, PairType::ValueOffset(), sizeof(PairType));
    CATOmxBaseSet::RemoveAll(mgr);
  }

  /** @see CATOmxBaseSet::Reserve*/
  inline void Reserve(unsigned int iSize)
  {
    CATOmxPairCollecManager mgr(KeyMgr, ValueMgr, PairType::ValueOffset(), sizeof(PairType));
    CATOmxBaseSet::Reserve(mgr, iSize);
  }

  /**
   * Returns an iterator on collection.
   * Usage:
   * CATOmxOHMap<KeyType,ValueType> map;
   * CATOmxOHMap<KeyType,ValueType>::IteratorType iter(map.Iterator());
   * const CATOmxOHMap<KeyType,ValueType>::PairType* p;
   * while( p = iter.Next())
   * {
   *   //Do something with p->key and p->value
   * }
   */
  inline IteratorType Iterator() const
  {
    CATOmxPairCollecManager mgr(KeyMgr, ValueMgr, PairType::ValueOffset(), sizeof(PairType));
    return CATOmxBaseSet::MapBaseIterator(mgr, 0);
  }
  inline ConstIteratorType ConstIterator() const
  {
    CATOmxPairCollecManager mgr(KeyMgr, ValueMgr, PairType::ValueOffset(), sizeof(PairType));
    return CATOmxBaseSet::MapBaseIterator(mgr, 0);
  }

  /**
   * Returns an iterator on the keys of the collection.
   */
  inline KeyIteratorType Keys() const
  {
    CATOmxPairCollecManager mgr(KeyMgr, ValueMgr, PairType::ValueOffset(), sizeof(PairType));
    return CATOmxBaseSet::MapBaseIterator(mgr, 0);
  }

  /**
  * Returns an iterator on the values of the collection.
  */
  inline ValueIteratorType Values() const
  {
    CATOmxPairCollecManager mgr(KeyMgr, ValueMgr, PairType::ValueOffset(), sizeof(PairType));
    return CATOmxBaseSet::MapBaseIterator(mgr, int(PairType::ValueOffset()));
  }

  /**
   * Comparison operator
   * note that result depends on CATOmxCollecManager::Compare implementation
   */
  inline int operator==(const CATOmxOHMap<KeyT, ValueT, KeyMgr, ValueMgr>& iRight) const
  {
    CATOmxPairCollecManager mgr(KeyMgr, ValueMgr, PairType::ValueOffset(), sizeof(PairType));
    return CATOmxBaseSet::IsEqual(iRight, mgr, &CATOmxPairCollecManager::CompareValues);
  }
  inline int operator!=(const CATOmxOHMap<KeyT, ValueT, KeyMgr, ValueMgr>& iRight) const { return !this->operator==(iRight); }

  /** range for support */
  typedef CATOmxSTLIter<const PairType> const_iterator;
  inline CATOmxSTLIter<const PairType> begin() const { return CATOmxSTLIter<const PairType>(ConstIterator()); }
  inline CATOmxSTLIter<const PairType> end()   const { return CATOmxSTLIter<const PairType>(); }

#if OMX_CXX11 == 1
  /** move semantics */
  inline CATOmxOHMap(CATOmxOHMap&& other) :CATOmxBaseSet(std::move(other)) {}
  inline CATOmxOHMap& operator=(CATOmxOHMap&& other) { return static_cast<CATOmxOHMap&>(this->CATOmxBaseSet::operator=(std::move(other))); }

  /** initializer list */
  inline CATOmxOHMap(std::initializer_list<PairType> list)
  {
    Reserve((unsigned int)list.size());
    for (const PairType& item : list)
      Insert(item);
  }
  inline CATOmxOHMap& operator=(std::initializer_list<PairType> list) { return this->operator=(CATOmxOHMap(list)); }
#endif

  /** std::inserter support */
  typedef PairType value_type;
  typedef const_iterator iterator;
  inline const iterator& insert(const iterator& dummy, const value_type& item) { Insert(item); return dummy; }
};

#endif
