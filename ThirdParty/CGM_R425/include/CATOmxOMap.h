/**
 * @level Private
 * @usage U1
 */
#ifndef __CATOmxOMap_h__
#define __CATOmxOMap_h__

#include "CATOmxBaseMap.h"
#include "CATOmxPair.h"

/**
 * This class allows to do a mapping between keys and values.
 * See CATOmxBaseMap for implementations details.
 * You should normally not use the 3rd and 4th template arguments
 * as the CATOmxDefaultCollecManager pattern does the work.
 * Override these only if you know what you are doing.
 * @href http://osmwebdsy/wiki/index.php/CATOmxOMap_Usage
 */
template<typename Key, typename Value = Key, CATOmxCollecManagerLocator KeyMgr = CATOmxDefaultCollecManager<Key>::manager, CATOmxCollecManagerLocator ValueMgr = CATOmxDefaultCollecManager<Value>::manager >
class CATOmxOMap : public CATOmxBaseMap
{
public:
  typedef Value ValueType;
  typedef Key KeyType;
  typedef CATOmxPair< Key, Value > PairType;

  typedef CATOmxMapIter<Key, Value>  MapIteratorType;

  /**
   * default constructor.
   */
  inline CATOmxOMap<Key, Value, KeyMgr, ValueMgr>() : CATOmxBaseMap(KeyMgr, ValueMgr, sizeof(Key), sizeof(Value)) {}

  /**
   * destructor.
   */
  inline ~CATOmxOMap() { RemoveAll(); }

  /**
   * Inserts (iKey,iValue) in the map.
   * if iKey was yet inserted returns false and corresponding value is not overriden.
   */
  inline CATBoolean Insert(const KeyType &iKey, const ValueType &iValue)
  {
    CATOmxMapContext ctx(KeyMgr, ValueMgr, PairType::ValueOffset(), &iKey, &iValue);
    return CATOmxBaseMap::Insert(ctx);
  }

  /**
   * Same as Insert but value is overriden if iKey is yet inserted.
   */
  inline CATBoolean Replace(const KeyType &iKey, const ValueType &iValue)
  {
    CATOmxMapContext ctx(KeyMgr, ValueMgr, PairType::ValueOffset(), &iKey, &iValue);
    return CATOmxBaseMap::Replace(ctx);
  }

  /**
   * Same as require.
   */
  inline ValueType& operator[](const KeyType &iKey)
  {
    CATOmxMapContext ctx(KeyMgr, ValueMgr, PairType::ValueOffset(), &iKey);
    return *reinterpret_cast<ValueType*>(CATOmxBaseMap::Require(ctx));
  }

  /**
   * if iKey is not present, corresponding node is created with default value specified by the CollecManager.
   * Returns writable reference on the value.
   * This method is forbidden if you use com_manager as Value manager.
   */
  inline ValueType& Require(const KeyType &iKey)
  {
    CATOmxMapContext ctx(KeyMgr, ValueMgr, PairType::ValueOffset(), &iKey);
    return *reinterpret_cast<ValueType*>(CATOmxBaseMap::Require(ctx));
  }

  /**
   * if iKey is not present, returns NULL else returns a pointer on the corresponding value.
   * @deprecated VR5R21
   */
  inline ValueType* Locate(const KeyType &iKey) const
  {
    CATOmxMapContext ctx(KeyMgr, ValueMgr, PairType::ValueOffset(), &iKey);
    return reinterpret_cast<ValueType*>(CATOmxBaseMap::Locate(ctx, CATOmx::AllowSideEffect));
  }
  /**
   * if iKey is not present, returns NULL else returns a pointer on the corresponding value.
   */
  inline ValueType* LocateForWrite(const KeyType &iKey)
  {
    CATOmxMapContext ctx(KeyMgr, ValueMgr, PairType::ValueOffset(), &iKey);
    return reinterpret_cast<ValueType*>(CATOmxBaseMap::Locate(ctx, CATOmx::ForWrite));
  }
  /**
   * CAUTION this API is used for any code that want to violate the COW pattern when iterating on collection.
   * if iKey is not present, returns NULL else returns a pointer on the corresponding value.
   */
  inline ValueType* LocateForSideEffect(const KeyType &iKey) const
  {
    CATOmxMapContext ctx(KeyMgr, ValueMgr, PairType::ValueOffset(), &iKey);
    return reinterpret_cast<ValueType*>(CATOmxBaseMap::Locate(ctx, CATOmx::AllowSideEffect));
  }
  /**
   * if iKey is not present, returns NULL else returns a pointer on the corresponding value.
   */
  inline const ValueType* LocateForGet(const KeyType &iKey) const
  {
    CATOmxMapContext ctx(KeyMgr, ValueMgr, PairType::ValueOffset(), &iKey);
    return reinterpret_cast<ValueType*>(CATOmxBaseMap::Locate(ctx, CATOmx::ForGet));
  }

  /**
   * Returns nearest item of the map according to iRelation.
   * @param iKey
   *   key to search in the map
   * @param iRelation
   *    legal values: a combination of CATOmx::Lesser, CATOmx::Equal and CATOmx::Greater (see CATOmxOrderRelation.h)
   *                  notice that it is forbidden to combine CATOmx::Lesser and CATOmx::Greater
   * @returns
   *   the pair (key,value) which is nearest to iKey according to iRelation constraint or NULL if no item match
   *   Returned pointer must not be modified and is valid until next modification of the map.
   */
  inline const PairType* LocateNearest(const KeyType &iKey, unsigned int iRelation) const
  {
    CATOmxMapContext ctx(KeyMgr, ValueMgr, PairType::ValueOffset(), &iKey);
    return reinterpret_cast<const CATOmxPair<Key, Value>*>(CATOmxBaseMap::LocateNearest(ctx, iRelation));
  }

  inline CATBoolean Exists(const KeyType &iKey) const
  {
    CATOmxMapContext ctx(KeyMgr, ValueMgr, PairType::ValueOffset(), &iKey);
    return 0 != CATOmxBaseMap::Locate(ctx, CATOmx::ForGet);
  }

  /**
   * if iKey is not present, returns false.
   * else corresponding node is removed from the map.
   */
  inline CATBoolean Remove(const KeyType &iKey)
  {
    CATOmxMapContext ctx(KeyMgr, ValueMgr, PairType::ValueOffset(), &iKey);
    return CATOmxBaseMap::Remove(ctx);
  }

  /**
   * Remove all nodes from the map.
   */
  inline void RemoveAll()
  {
    CATOmxMapContext ctx(KeyMgr, ValueMgr, PairType::ValueOffset());
    CATOmxBaseMap::RemoveAll(ctx);
  }

  /**
   * Create an isolated copy of the map.
   */
  inline void Clone(const CATOmxOMap<Key, Value, KeyMgr, ValueMgr>& iMap)
  {
    CATOmxMapContext ctx(KeyMgr, ValueMgr, PairType::ValueOffset());
    CATOmxBaseMap::Clone(ctx, iMap);
  }
  /** @deprecated V5R21. use MapIterator instead*/
  inline operator MapIteratorType() const
  {
    CATOmxMapContext ctx(KeyMgr, ValueMgr, PairType::ValueOffset());
    return MapIteratorType(ctx.new_iterator(letter), TRUE);
  }
  inline MapIteratorType MapIterator() const
  {
    CATOmxMapContext ctx(KeyMgr, ValueMgr, PairType::ValueOffset());
    return MapIteratorType(ctx.new_iterator(letter), TRUE);
  }
  inline CATOmxOMap<Key, Value, KeyMgr, ValueMgr>(const CATOmxOMap<Key, Value, KeyMgr, ValueMgr>&iMap) : CATOmxBaseMap(KeyMgr, ValueMgr, PairType::ValueOffset(), iMap) {}
  inline CATOmxOMap<Key, Value, KeyMgr, ValueMgr>& operator=(const CATOmxOMap<Key, Value, KeyMgr, ValueMgr>&iMap)
  {
    CATOmxMapContext ctx(KeyMgr, ValueMgr, PairType::ValueOffset());
    CATOmxBaseMap::Share(ctx, iMap);
    return *this;
  }

  /**
   * Comparison operator
   * WARNING: result depends on CATOmxCollecManager::Compare implementation
   */
  inline int operator==(const CATOmxOMap<Key, Value, KeyMgr, ValueMgr>& iRight) const
  {
    CATOmxMapContext ctx(KeyMgr, ValueMgr, PairType::ValueOffset());
    return CATOmxBaseMap::IsEqual(ctx, iRight);
  }

  /** see operator == */
  inline int operator!=(const CATOmxOMap<Key, Value, KeyMgr, ValueMgr>& iRight) const { return !this->operator==(iRight); }
};

#endif
