// COPYRIGHT DASSAULT SYSTEMES 2016
//=============================================================================
//
// CATCDSMap:
//
// A template map class.
//
// For building on Linux, you should add in your Imakefile
// #if os Linux
// LOCAL_CCFLAGS=-std=c++0x
// #endif
//
//=============================================================================
//  Jan 2016  Creation                         TE9
//=============================================================================

#ifndef CATCDSMap_h
#define CATCDSMap_h

#include "CATCDSUtilities.h"
#include "CATCDSDataType.h"
#include "CATCDSInline.h"
#include "CATCDSAssert.h"
#include "CATCDSMapForward.h"
#include "CATCDSMapSpecializations.h"
#include "CATCDSCPlusPlusVersions.h"

#if defined(_SUNOS_SOURCE)
#define _RWSTD_NO_MUTABLE 1
#endif

#ifdef CPP11_AVAILABLE
#include <unordered_map>
#endif

#include <map>

template<class Key, class Value, class Hash>
class CATCDSSTDMap
{
public:
#ifdef CPP11_AVAILABLE
  typedef std::unordered_map<Key, Value, Hash> type;
#else
  typedef std::map<Key, Value> type;
#endif   
};

template<class Key, class Value>
class CATCDSSTDMap<Key, Value, void>
{
public:
  typedef std::map<Key, Value> type;
};

template<class Key, class Value, class Hash>
class CATCDSMap
{
public:
  typedef typename CDSStorageType<Key>::type KeyType;
  typedef typename CDSStorageType<Value>::type ValueType;
  typedef typename CDSStorageType<Key>::ref KeyRefType;
  typedef typename CDSStorageType<Value>::ref ValueRefType;
  typedef typename CDSStorageType<Key>::const_ref KeyConstRefType;
  typedef typename CDSStorageType<Value>::const_ref ValueConstRefType;

  class Element : public std::pair<const KeyType, ValueType>
  {
  public:
    using std::pair<const KeyType, ValueType>::first;
    using std::pair<const KeyType, ValueType>::second;

    KeyConstRefType GetKey() const;

    ValueRefType GetValue();
    ValueConstRefType GetValue() const;    
    
    void SetValue(Value const & iValue);
  };

  class Iterator {
  public:
    Iterator();

    Iterator(typename CATCDSSTDMap<KeyType, ValueType, Hash>::type::iterator iIterator);

    Element & operator*(); 
    Element * operator->();

    Iterator operator++();
    Iterator operator++(int);

    bool operator==(Iterator const & iIterator) const;
    bool operator!=(Iterator const & iIterator) const;

    typename CATCDSSTDMap<KeyType, ValueType, Hash>::type::iterator _iterator;
  };

  class ConstIterator {
  public:
    ConstIterator();

    ConstIterator(typename CATCDSSTDMap<KeyType, ValueType, Hash>::type::const_iterator iIterator);

    Element const & operator*();
    Element const * operator->();

    ConstIterator operator++();
    ConstIterator operator++(int);

    bool operator==(ConstIterator const & iIterator) const;
    bool operator!=(ConstIterator const & iIterator) const;

    typename CATCDSSTDMap<KeyType, ValueType, Hash>::type::const_iterator _iterator;
  };

  /**
   * Constructs a new map
   * @param iSize Approximate size of the map after filling
   */
  CATCDSMap();
  CATCDSMap(int iSize);
  CATCDSMap(CATCDSMap const &iMap);
  CATCDSMap & operator=(CATCDSMap const &iMap);
#ifdef CPP11_AVAILABLE
  CATCDSMap(CATCDSMap &&iMap);
  CATCDSMap & operator=(CATCDSMap &&iMap);
#endif

  /**
   * Inserts an element in the map
   * @param iKey   Element key
   * @param iValue Element value
   * @return       TRUE if insertion succeeded
   */
  bool Insert(Key const &iKey, Value const &iValue);

  /**
   * Inserts an element in the map
   * @param iKey      Element key
   * @param iValue    Element value
   * @param oIterator An iterator pointing on inserted element (or existing element if already exists)
   * @return          TRUE if insertion succeeded
   */
  bool Insert(Key const &iKey, Value const &iValue, Iterator &oIterator);

  /**
   * Removes an element by its key
   * @param iKey The key of the element
   */
  void Erase(Key const &iKey);

  /**
   * Removes an element at a given position
   * @param iIterator An iterator pointing on the element to remove
   *
   * Note : Iterator return is available from C++ 11 to enable removing during an iteration over the map
   */
  Iterator Erase(Iterator iIterator);

  /**
   * Clears map content
   */
  void Clear();

  /**
   * Returns the number elements in the map
   * @return Map size
   */
  int Size() const;

  /**
   * Search an element by its key in the map
   * @param iKey The element key
   * @return     An iterator pointing on the element if it was found, an iterator equal to End otherwise
   */
  Iterator Find(Key const &iKey);

  ConstIterator Find(Key const &iKey) const;

  /**
   * Search a key in the map
   * @param iKey The key
   * @return     TRUE if the key belongs to the map
   */
  bool Has(Key const &iKey) const;

  /**
   * Returns an iterator pointing on the first element of the map
   */
  Iterator begin();
  Iterator Begin();

  /**
   * Returns an iterator pointing just after the last element of the map
   */
  Iterator end();
  Iterator End();

  /**
   * Returns a const iterator pointing on the first element of the map
   */
  ConstIterator cbegin() const;
  ConstIterator CBegin() const;

  ConstIterator begin() const;
  ConstIterator Begin() const;

  /**
   * Returns a const iterator pointing just after the last element of the map
   */
  ConstIterator cend() const;
  ConstIterator CEnd() const;

  ConstIterator end() const;
  ConstIterator End() const;

  /**
   * Reserve size to contain at least the given number of elements
   * @param iSize Size to reserve
   */
  void Reserve(int iSize);

  /**
   * Return a reference on a map element for a given key
   * If the key doesn't belong to the map. A default-initialized element is insert and a reference on it is returned.
   * @param iKey Element key
   * @return     A reference on map element at given key
   */
  ValueRefType operator[](Key const & iKey);

  /**
   * Search an element by its key and return its associated value
   * We assume that the key belongs to the map
   * @param iKey          The key of the element to search
   * @param iDefaultValue The value to return if not found
   * @return              Associated value
   */
  ValueConstRefType At(Key const &iKey) const;

  /**
   * Search an element by its key and return its associated value
   * We assume that the key belongs to the map
   * @param iKey          The key of the element to search
   * @param iDefaultValue The value to return if not found
   * @return              Associated value
   */
  ValueRefType At(Key const &iKey);

public:
  typename CATCDSSTDMap<KeyType, ValueType, Hash>::type _map;
};

template<class Key, class Value>
class CATCDSOrderedMap : public CATCDSMap<Key, Value, void>
{
public:
  using CATCDSMap<Key, Value, void>::_map;
	typedef typename CDSStorageType<Key>::type KeyType;
  typedef typename CDSStorageType<Value>::type ValueType;
  typedef typename CATCDSMap<Key, Value, void>::Element Element;
	
  class ReverseIterator {
  public:
    ReverseIterator();
    ReverseIterator(typename CATCDSSTDMap<KeyType, ValueType, void>::type::reverse_iterator iIterator);

    ReverseIterator operator++();
    ReverseIterator operator++(int);

    Element & operator*();
    Element * operator->();

    bool operator==(ReverseIterator const & iIterator) const;
    bool operator!=(ReverseIterator const & iIterator) const;

    typename CATCDSSTDMap<KeyType, ValueType, void>::type::reverse_iterator _iterator;
  };

  class ConstReverseIterator {
  public:
    ConstReverseIterator();
    ConstReverseIterator(typename CATCDSSTDMap<KeyType, ValueType, void>::type::const_reverse_iterator iIterator);

    ConstReverseIterator operator++();
    ConstReverseIterator operator++(int);

    Element const & operator*();
    Element const * operator->();

    bool operator==(ConstReverseIterator const & iIterator) const;
    bool operator!=(ConstReverseIterator const & iIterator) const;

    typename CATCDSSTDMap<KeyType, ValueType, void>::type::const_reverse_iterator _iterator;
  };

  /**
   * Returns an iterator pointing on the first element of the map
   */
  ReverseIterator RBegin();
  ConstReverseIterator RBegin() const;
  ConstReverseIterator CRBegin() const;

  ReverseIterator rbegin();
  ConstReverseIterator rbegin() const;
  ConstReverseIterator crbegin() const;

  /**
   * Returns an iterator pointing just after the last element of the map
   */
  ReverseIterator REnd();
  ConstReverseIterator REnd() const;
  ConstReverseIterator CREnd() const;

  ReverseIterator rend();
  ConstReverseIterator rend() const;
  ConstReverseIterator crend() const;
};

// CATCDSMap implementation

template<class Key, class Value, class Hash>
CATCDSInline CATCDSMap<Key, Value, Hash>::CATCDSMap()
{

}

template<class Key, class Value, class Hash>
CATCDSInline CATCDSMap<Key, Value, Hash>::CATCDSMap(int iSize)
#ifdef CPP11_AVAILABLE
  : _map(iSize)
#endif
{

}

template<class Key, class Value, class Hash>
CATCDSInline CATCDSMap<Key, Value, Hash>::CATCDSMap(CATCDSMap const &iMap) : _map(iMap._map)
{

}

template<class Key, class Value, class Hash>
CATCDSInline CATCDSMap<Key, Value, Hash> & CATCDSMap<Key, Value, Hash>::operator=(CATCDSMap const &iMap)
{
  _map = iMap._map;
  return *this;
}

#ifdef CPP11_AVAILABLE
template<class Key, class Value, class Hash>
CATCDSInline CATCDSMap<Key, Value, Hash>::CATCDSMap(CATCDSMap &&iMap) : _map(std::move(iMap._map))
{

}

template<class Key, class Value, class Hash>
CATCDSInline CATCDSMap<Key, Value, Hash> & CATCDSMap<Key, Value, Hash>::operator=(CATCDSMap &&iMap)
{
  _map = std::move(iMap._map);
  return *this;
}
#endif

template<class Key, class Value, class Hash>
CATCDSInline bool CATCDSMap<Key, Value, Hash>::Insert(Key const &iKey, Value const &iValue)
{
  return _map.insert(std::pair<KeyType, ValueType>(CDSStorageType<Key>::CastToStorage(iKey), CDSStorageType<Value>::CastToStorage(iValue))).second;
}

template<class Key, class Value, class Hash>
CATCDSInline bool CATCDSMap<Key, Value, Hash>::Insert(Key const &iKey, Value const &iValue, Iterator &oIterator)
{
  std::pair<typename CATCDSSTDMap<KeyType, ValueType, Hash>::type::iterator, bool> res = _map.insert(std::pair<KeyType, ValueType>(CDSStorageType<Key>::CastToStorage(iKey), CDSStorageType<Value>::CastToStorage(iValue)));
  oIterator = res.first;
  return res.second;
}

template<class Key, class Value, class Hash>
CATCDSInline void CATCDSMap<Key, Value, Hash>::Erase(Key const &iKey)
{
  _map.erase(CDSStorageType<Key>::CastToStorage(iKey));
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::Iterator CATCDSMap<Key, Value, Hash>::Erase(Iterator iIterator)
{
  Iterator itToErase=iIterator++;
  _map.erase(itToErase._iterator);
  return iIterator; //returns an iterator to the next element
}

template<class Key, class Value, class Hash>
CATCDSInline void CATCDSMap<Key, Value, Hash>::Clear()
{
  _map.clear();
}

template<class Key, class Value, class Hash>
CATCDSInline int CATCDSMap<Key, Value, Hash>::Size() const
{
  return static_cast<int>(_map.size());
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::Iterator CATCDSMap<Key, Value, Hash>::Find(Key const &iKey)
{
  return _map.find(CDSStorageType<Key>::CastToStorage(iKey));
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::ConstIterator CATCDSMap<Key, Value, Hash>::Find(Key const &iKey) const
{
  return _map.find(CDSStorageType<Key>::CastToStorage(iKey));
}

template<class Key, class Value, class Hash>
CATCDSInline bool CATCDSMap<Key, Value, Hash>::Has(Key const &iKey) const
{
  return Find(iKey) != End();
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::Iterator CATCDSMap<Key, Value, Hash>::Begin()
{
  return _map.begin();
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::Iterator CATCDSMap<Key, Value, Hash>::begin()
{
  return _map.begin();
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::Iterator CATCDSMap<Key, Value, Hash>::end()
{
  return _map.end();
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::Iterator CATCDSMap<Key, Value, Hash>::End()
{
  return _map.end();
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::ConstIterator CATCDSMap<Key, Value, Hash>::CBegin() const
{
  return _map.begin();
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::ConstIterator CATCDSMap<Key, Value, Hash>::cbegin() const
{
  return _map.begin();
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::ConstIterator CATCDSMap<Key, Value, Hash>::Begin() const
{
  return _map.begin();
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::ConstIterator CATCDSMap<Key, Value, Hash>::begin() const
{
  return _map.begin();
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::ConstIterator CATCDSMap<Key, Value, Hash>::CEnd() const
{
  return _map.end();
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::ConstIterator CATCDSMap<Key, Value, Hash>::cend() const
{
  return _map.end();
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::ConstIterator CATCDSMap<Key, Value, Hash>::End() const
{
  return _map.end();
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::ConstIterator CATCDSMap<Key, Value, Hash>::end() const
{
  return _map.end();
}

template<class Key, class Value, class Hash>
CATCDSInline void CATCDSMap<Key, Value, Hash>::Reserve(int iSize)
{
  #ifdef CPP11_AVAILABLE
  _map.reserve(iSize);
  #endif
}


template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::ValueRefType CATCDSMap<Key, Value, Hash>::operator[](Key const & iKey)
{
  return _map[CDSStorageType<Key>::CastToStorage(iKey)];
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::ValueConstRefType CATCDSMap<Key, Value, Hash>::At(Key const &iKey) const
{
  return _map.find(CDSStorageType<Key>::CastToStorage(iKey))->second;
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::ValueRefType CATCDSMap<Key, Value, Hash>::At(Key const &iKey)
{
  return _map.find(CDSStorageType<Key>::CastToStorage(iKey))->second;
}

// CATCDSOrderedMap implementation

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::ReverseIterator CATCDSOrderedMap<Key, Value>::RBegin()
{
  return _map.rbegin();
}

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::ConstReverseIterator CATCDSOrderedMap<Key, Value>::RBegin() const
{
  return _map.rbegin();
}

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::ConstReverseIterator CATCDSOrderedMap<Key, Value>::CRBegin() const
{
  return _map.crbegin();
}

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::ReverseIterator CATCDSOrderedMap<Key, Value>::rbegin()
{
  return _map.rbegin();
}

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::ConstReverseIterator CATCDSOrderedMap<Key, Value>::rbegin() const
{
  return _map.rbegin();
}

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::ConstReverseIterator CATCDSOrderedMap<Key, Value>::crbegin() const
{
  return _map.crbegin();
}

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::ReverseIterator CATCDSOrderedMap<Key, Value>::REnd()
{
  return _map.rend();
}

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::ConstReverseIterator CATCDSOrderedMap<Key, Value>::REnd() const
{
  return _map.rend();
}

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::ConstReverseIterator CATCDSOrderedMap<Key, Value>::CREnd() const
{
  return _map.crend();
}

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::ReverseIterator CATCDSOrderedMap<Key, Value>::rend()
{
  return _map.rend();
}

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::ConstReverseIterator CATCDSOrderedMap<Key, Value>::rend() const
{
  return _map.rend();
}

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::ConstReverseIterator CATCDSOrderedMap<Key, Value>::crend() const
{
  return _map.crend();
}

// Element

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::ValueRefType CATCDSMap<Key, Value, Hash>::Element::GetValue()
{
  return second;
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::KeyConstRefType CATCDSMap<Key, Value, Hash>::Element::GetKey() const
{
  return first;
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::ValueConstRefType CATCDSMap<Key, Value, Hash>::Element::GetValue() const
{
  return second;
}

template<class Key, class Value, class Hash>
CATCDSInline void CATCDSMap<Key, Value, Hash>::Element::SetValue(Value const & iValue)
{
  second = CDSStorageType<Value>::CastToStorage(iValue);
}

// Iterator

template<class Key, class Value, class Hash>
CATCDSInline CATCDSMap<Key, Value, Hash>::Iterator::Iterator() {}

template<class Key, class Value, class Hash>
CATCDSInline CATCDSMap<Key, Value, Hash>::Iterator::Iterator(typename CATCDSSTDMap<KeyType, ValueType, Hash>::type::iterator iIterator) : _iterator(iIterator) {}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::Element & CATCDSMap<Key, Value, Hash>::Iterator::operator*()
{
  return static_cast<Element&>(*_iterator);
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::Element * CATCDSMap<Key, Value, Hash>::Iterator::operator->()
{
  return static_cast<Element*>(&*_iterator);
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::Iterator CATCDSMap<Key, Value, Hash>::Iterator::operator++()
{
  return ++_iterator;
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::Iterator CATCDSMap<Key, Value, Hash>::Iterator::operator++(int)
{
  return _iterator++;
}

template<class Key, class Value, class Hash>
CATCDSInline bool CATCDSMap<Key, Value, Hash>::Iterator::operator==(Iterator const & iIterator) const
{
  return iIterator._iterator == _iterator;
}

template<class Key, class Value, class Hash>
CATCDSInline bool CATCDSMap<Key, Value, Hash>::Iterator::operator!=(Iterator const & iIterator) const
{
  return iIterator._iterator != _iterator;
}

// ConstIterator

template<class Key, class Value, class Hash>
CATCDSInline CATCDSMap<Key, Value, Hash>::ConstIterator::ConstIterator() {}

template<class Key, class Value, class Hash>
CATCDSInline CATCDSMap<Key, Value, Hash>::ConstIterator::ConstIterator(typename CATCDSSTDMap<KeyType, ValueType, Hash>::type::const_iterator iIterator) : _iterator(iIterator) {}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::Element const & CATCDSMap<Key, Value, Hash>::ConstIterator::operator*()
{
  return static_cast<Element const&>(*_iterator);
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::Element const * CATCDSMap<Key, Value, Hash>::ConstIterator::operator->()
{
  return static_cast<Element const*>(&*_iterator);
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::ConstIterator CATCDSMap<Key, Value, Hash>::ConstIterator::operator++()
{
  return ++_iterator;
}

template<class Key, class Value, class Hash>
CATCDSInline typename CATCDSMap<Key, Value, Hash>::ConstIterator CATCDSMap<Key, Value, Hash>::ConstIterator::operator++(int)
{
  return _iterator++;
}

template<class Key, class Value, class Hash>
CATCDSInline bool CATCDSMap<Key, Value, Hash>::ConstIterator::operator==(ConstIterator const & iIterator) const
{
  return iIterator._iterator == _iterator;
}

template<class Key, class Value, class Hash>
CATCDSInline bool CATCDSMap<Key, Value, Hash>::ConstIterator::operator!=(ConstIterator const & iIterator) const
{
  return iIterator._iterator != _iterator;
}

// ReverseIterator

template<class Key, class Value>
CATCDSInline CATCDSOrderedMap<Key, Value>::ReverseIterator::ReverseIterator()
{
}

template<class Key, class Value>
CATCDSInline CATCDSOrderedMap<Key, Value>::ReverseIterator::ReverseIterator(typename CATCDSSTDMap<KeyType, ValueType, void>::type::reverse_iterator iIterator) : 
  _iterator(iIterator)
{
}

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::ReverseIterator CATCDSOrderedMap<Key, Value>::ReverseIterator::operator++()
{
  return ++_iterator;
}

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::ReverseIterator CATCDSOrderedMap<Key, Value>::ReverseIterator::operator++(int)
{
  return _iterator++;
}

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::Element & CATCDSOrderedMap<Key, Value>::ReverseIterator::operator*()
{
  return static_cast<Element&>(*_iterator);
}

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::Element * CATCDSOrderedMap<Key, Value>::ReverseIterator::operator->()
{
  return static_cast<Element*>(&*_iterator);
}

template<class Key, class Value>
CATCDSInline bool CATCDSOrderedMap<Key, Value>::ReverseIterator::operator==(ReverseIterator const & iIterator) const
{
  return iIterator._iterator == _iterator;
}

template<class Key, class Value>
CATCDSInline bool CATCDSOrderedMap<Key, Value>::ReverseIterator::operator!=(ReverseIterator const & iIterator) const
{
  return iIterator._iterator != _iterator;
}

// ConstReverseIterator

template<class Key, class Value>
CATCDSInline CATCDSOrderedMap<Key, Value>::ConstReverseIterator::ConstReverseIterator() 
{
}

template<class Key, class Value>
CATCDSInline CATCDSOrderedMap<Key, Value>::ConstReverseIterator::ConstReverseIterator(typename CATCDSSTDMap<KeyType, ValueType, void>::type::const_reverse_iterator iIterator) :
  _iterator(iIterator)
{
}

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::ConstReverseIterator CATCDSOrderedMap<Key, Value>::ConstReverseIterator::operator++()
{
  return ++_iterator;
}

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::ConstReverseIterator CATCDSOrderedMap<Key, Value>::ConstReverseIterator::operator++(int)
{
  return _iterator++;
}

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::Element const & CATCDSOrderedMap<Key, Value>::ConstReverseIterator::operator*()
{
  return static_cast<Element const&>(*_iterator);
}

template<class Key, class Value>
CATCDSInline typename CATCDSOrderedMap<Key, Value>::Element const * CATCDSOrderedMap<Key, Value>::ConstReverseIterator::operator->()
{
  return static_cast<Element const*>(&*_iterator);
}

template<class Key, class Value>
CATCDSInline bool CATCDSOrderedMap<Key, Value>::ConstReverseIterator::operator==(ConstReverseIterator const & iIterator) const
{
  return iIterator._iterator == _iterator;
}

template<class Key, class Value>
CATCDSInline bool CATCDSOrderedMap<Key, Value>::ConstReverseIterator::operator!=(ConstReverseIterator const & iIterator) const
{
  return iIterator._iterator != _iterator;
}

// Extern map
#if !defined(_SUNOS_SOURCE) && !defined(_LINUX_SOURCE)
#ifdef CPP11_AVAILABLE
//impossible since VS2019
//Microsoft: exporting a class derived from an STL container creates a strong dependency for the DLL and the user of that DLL on a specific version of the STL. 
#if defined(_MSC_VER) && (_MSC_VER < 1924)
extern template class std::unordered_map<std::uint64_t, std::uint64_t>;
#endif
#else
extern template class std::map<std::uint64_t, std::uint64_t>;
#endif

#endif

#endif
