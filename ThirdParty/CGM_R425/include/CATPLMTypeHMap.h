#ifndef CATPLMTYPEHMAP_H_
#define CATPLMTYPEHMAP_H_

#include "CATPLMTypeHCollectionBase.h"
#include "CATPLMTypeH.h"
#include "CATOmxOHMap.h"
#include "CATPLMTypeHVisitor.h"

/**
* This collection encapsulate a CATOmxOHMap with CATPLMTypeH has keys.
*
* Its main interests are the GetBestMatchingType, GetMatchingTypes and HasMatchingType that provide a
* centralized and cached access to types in the map from a derived type.
*
* Its main usage : you want to associate some data or behavior on a given type and you want to be sure
* all the derived types will benefit from it.
*/

template<typename Value, CATOmxCollecManagerLocator ValueMgr=CATOmxDefaultCollecManager<Value>::manager >
class CATPLMTypeHMap : public CATPLMTypeHCollectionBase
{
  CATOmxOHMap<CATPLMTypeH, Value, CATOmxDefaultCollecManager<CATPLMTypeH>::manager, ValueMgr> _BaseMap;
public:
  typedef Value ValueType;
  typedef CATOmxPair< CATPLMTypeH,ValueType > PairType;
  typedef CATOmxIter< PairType > IteratorType;
  typedef CATOmxMapIter< CATPLMTypeH, ValueType >  MapIteratorType;

  inline CATPLMTypeHMap<Value,ValueMgr>()
  {
  }



  /**
  * Those directives are not useful. They are just here to remember you of those key available methods.
  */
  using CATPLMTypeHCollectionBase::GetBestMatchingType;
  using CATPLMTypeHCollectionBase::GetMatchingTypes;
  using CATPLMTypeHCollectionBase::HasMatchingType;

  /**
   * if iKey is not present, corresponding node is created with default value specified by the CollecManager.
   * Returns writable reference on the value.
   * This method is forbidden if you use com_manager as ValueT manager.
   */
  inline ValueType& operator[](const CATPLMTypeH &iType)
  {
    return Require(iType);
  }
  inline ValueType& Require(const CATPLMTypeH &iType)
  {
    if(!Exists(iType)) UpdateTypeCacheAdd(iType);
    return _BaseMap.Require(iType);
  }

  /**
   * Locate an item.
   * If iKey is not present, returns NULL else returns a pointer on the corresponding value.
   */
  inline const ValueType* Locate(const CATPLMTypeH &iType) const
  {
    return _BaseMap.Locate(iType);
  }
  inline ValueType* LocateForWrite(const CATPLMTypeH &iType) 
  {
    return _BaseMap.LocateForWrite(iType);
  }
  inline const ValueType* LocateForGet(const CATPLMTypeH &iType) const
  {
    return Locate(iType);
  }
  inline CATBoolean Exists(const CATPLMTypeH &iType) const
  {
    return 0 != Locate(iType);
  }

  /**
   * Inserts (iKey,iValue) in the map.
   * if iKey was yet inserted returns false and corresponding value is not overriden.
   */
  inline CATBoolean Insert(const CATPLMTypeH &iType,const ValueType &iValue)
  {
    CATBoolean res = _BaseMap.Insert(iType, iValue);
    if(res) UpdateTypeCacheAdd(iType);
    return res;
  }

  /**
   * Same as Insert but value is overriden if iKey is yet inserted.
   */
  inline CATBoolean Replace(const CATPLMTypeH &iType,const ValueType &iValue)
  {
    CATBoolean res = _BaseMap.Replace(iType, iValue);
    if(res) UpdateTypeCacheAdd(iType);
    return res;
  }

  /**
   * if iKey is not present, returns false.
   * else corresponding node is removed from the map.
   */
  inline CATBoolean Remove(const CATPLMTypeH& iType)
  {
    CATBoolean res = _BaseMap.Remove(iType);
    if(res) UpdateTypeCacheRem(iType);
    return res;
  }

  inline void RemoveAll()
  {
    FlushTypeCache();
    return _BaseMap.RemoveAll();
  }

  inline const MapIteratorType MapIterator() const
  {
    return _BaseMap.MapIterator();
  }

  inline IteratorType Iterator()
  {
    return _BaseMap.Iterator();
  }

  inline unsigned Size(void) const
  {
    return _BaseMap.Size();
  }

private:
  inline void VisitAllTypes( CATPLMTypeHVisitor & iVisitor)
  {
    IteratorType iter = Iterator();
    PairType * pair = NULL;
    while(pair = iter.Next())
    {
      if(CATPLMTypeHVisitor::CATBehaviour_break == iVisitor.Visit( pair->key ))
        break;
    }
  }
};
#endif /* CATPLMTYPEHMAP_H_ */
