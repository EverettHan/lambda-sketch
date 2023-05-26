// COPYRIGHT DASSAULT SYSTEMES 2016
//=============================================================================
//
// CATCDSMultimap:
//
// A template multimap map class which wraps STL.
//
//=============================================================================
//  May 2016  Creation                         TE9
//=============================================================================

#ifndef CATCDSMultimap_h
#define CATCDSMultimap_h

#include "CATCDSBoolean.h"
#include "CATCDSInline.h"
#include "CATCDSAssert.h"
#include "CATCDSCPlusPlusVersions.h"

#include <map>

template<class Key, class Value>
class CATCDSMultimap
{
public:
  class Element : public std::pair<const Key, Value>
  {
  public:
    using std::pair<const Key, Value>::first;
    using std::pair<const Key, Value>::second;

    Key const & GetKey() const;

    Value & GetValue();
    Value const & GetValue() const;    
    
    void SetValue(Value const & iValue);
  };


  class Iterator {
  public:
    Iterator();

    Iterator(typename std::multimap<Key, Value>::iterator iIterator);

    Element & operator*(); 
    Element * operator->();

    Iterator operator++();
    Iterator operator++(int);

    bool operator==(Iterator const & iIterator) const;
    bool operator!=(Iterator const & iIterator) const;

    typename std::multimap<Key, Value>::iterator _iterator;
  };

  class ConstIterator {
  public:
    CATCDSInline ConstIterator();

    CATCDSInline ConstIterator(typename std::multimap<Key, Value>::const_iterator iIterator);

    Element const & operator*();
    Element const * operator->();

    CATCDSInline ConstIterator operator++();
    CATCDSInline ConstIterator operator++(int);

    CATCDSInline bool operator==(ConstIterator const & iIterator) const;
    CATCDSInline bool operator!=(ConstIterator const & iIterator) const;

    typename std::multimap<Key, Value>::const_iterator _iterator;
  };

  /**
   * Constructs a new map
   * @param iSize Approximate size of the map after filling
   */
  CATCDSInline CATCDSMultimap();
  CATCDSInline CATCDSMultimap(CATCDSMultimap const &iMap);
  CATCDSInline CATCDSMultimap & operator=(CATCDSMultimap const &iMap);
#ifdef CPP11_AVAILABLE
  CATCDSInline CATCDSMultimap(CATCDSMultimap &&iMap);
  CATCDSInline CATCDSMultimap & operator=(CATCDSMultimap &&iMap);
#endif

  /**
   * Inserts an element in the map
   * @param iKey   Element key
   * @param iValue Element value
   * @return       An iterator pointing on the inserted element
   */
  CATCDSInline Iterator Insert(Key const &iKey, Value const &iValue);

  /**
   * Removes an element by its key
   * @param iKey The key of the element
   */
  CATCDSInline void Erase(Key const &iKey);

  /**
   * Removes an element at a given position
   * @param iIterator An iterator pointing on the element to remove
   */
  CATCDSInline Iterator Erase(Iterator iIterator);

  /**
   * Clears map content
   */
  CATCDSInline void Clear();

  /**
   * Returns the number elements in the map
   * @return Map size
   */
  CATCDSInline int Size() const;

  /**
   * Search an element by its key in the map
   * @param iKey The element key
   * @return     An iterator pointing on the element if it was found, an iterator equal to End otherwise
   */
  CATCDSInline Iterator Find(Key const &iKey);

  CATCDSInline ConstIterator Find(Key const &iKey) const;

  /**
   * Search a key in the map
   * @param iKey The key
   * @return     TRUE if the key belongs to the map
   */
  CATCDSInline CATCDSBoolean Has(Key const &iKey) const;

  /**
   * Returns an iterator pointing on the first element of the map
   */
  CATCDSInline Iterator Begin();

  /**
   * Returns an iterator pointing just after the last element of the map
   */
  CATCDSInline Iterator End();

  /**
   * Returns a const iterator pointing on the first element of the map
   */
  CATCDSInline ConstIterator CBegin() const;

  CATCDSInline ConstIterator cbegin() const;

  CATCDSInline ConstIterator Begin() const;

  CATCDSInline ConstIterator begin() const;

  /**
   * Returns a const iterator pointing just after the last element of the map
   */
  CATCDSInline ConstIterator CEnd() const;

  CATCDSInline ConstIterator cend() const;

  CATCDSInline ConstIterator End() const;

  CATCDSInline ConstIterator end() const;

  /*
   * Count the number of elements associated to a given key
   * @param iKey          The key
   * @return              Number of elements associated to key
   */
  CATCDSInline int Count(Key const &iKey);

  /**
   * Return an iterator to the first element referenced by given key
   * @param iKey          The key
   * @return              An iterator
   */
  CATCDSInline Iterator LowerBound(Key const &iKey);

  CATCDSInline ConstIterator LowerBound(Key const &iKey) const;

  /**
   * Return an iterator just after the last element referenced by given key
   * @param iKey          The key
   * @return              An iterator
   */
  CATCDSInline Iterator UpperBound(Key const &iKey);

  CATCDSInline ConstIterator UpperBound(Key const &iKey) const;

  template<class IteratorType>
  class Range
  {
  public:
    CATCDSInline Range(IteratorType iBegin, IteratorType iEnd) :
      _begin(iBegin),
      _end(iEnd)
    {
    }

    CATCDSInline IteratorType begin()
    {
      return _begin;
    }

    CATCDSInline IteratorType end()
    {
      return _end;
    }

  private:
    IteratorType _begin;
    IteratorType _end;
  };

  CATCDSInline Range<Iterator> EqualRange(Key const &iKey);

  CATCDSInline Range<ConstIterator> EqualRange(Key const &iKey) const;

public:
  std::multimap<Key, Value> _map;
};

// Element

template<class Key, class Value>
CATCDSInline Value & CATCDSMultimap<Key, Value>::Element::GetValue()
{
  return second;
}

template<class Key, class Value>
CATCDSInline Key const & CATCDSMultimap<Key, Value>::Element::GetKey() const
{
  return first;
}

template<class Key, class Value>
CATCDSInline Value const & CATCDSMultimap<Key, Value>::Element::GetValue() const
{
  return second;
}

template<class Key, class Value>
CATCDSInline void CATCDSMultimap<Key, Value>::Element::SetValue(Value const & iValue)
{
  second = iValue;
}

// Iterator

template<class Key, class Value>
CATCDSInline CATCDSMultimap<Key, Value>::Iterator::Iterator()
{
}

template<class Key, class Value>
CATCDSInline CATCDSMultimap<Key, Value>::Iterator::Iterator(typename std::multimap<Key, Value>::iterator iIterator) : 
  _iterator(iIterator) 
{
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::Element & CATCDSMultimap<Key, Value>::Iterator::operator*()
{
  return static_cast<Element&>(*_iterator);
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::Element * CATCDSMultimap<Key, Value>::Iterator::operator->()
{
  return static_cast<Element*>(&*_iterator);
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::Iterator CATCDSMultimap<Key, Value>::Iterator::operator++()
{
  return ++_iterator;
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::Iterator CATCDSMultimap<Key, Value>::Iterator::operator++(int)
{
  return _iterator++;
}

template<class Key, class Value>
CATCDSInline bool CATCDSMultimap<Key, Value>::Iterator::operator==(Iterator const & iIterator) const
{
  return iIterator._iterator == _iterator;
}

template<class Key, class Value>
CATCDSInline bool CATCDSMultimap<Key, Value>::Iterator::operator!=(Iterator const & iIterator) const
{
  return iIterator._iterator != _iterator;
}

// ConstIterator

template<class Key, class Value>
CATCDSInline CATCDSMultimap<Key, Value>::ConstIterator::ConstIterator()
{
}

template<class Key, class Value>
CATCDSInline CATCDSMultimap<Key, Value>::ConstIterator::ConstIterator(typename std::multimap<Key, Value>::const_iterator iIterator) :
  _iterator(iIterator)
{
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::Element const & CATCDSMultimap<Key, Value>::ConstIterator::operator*()
{
  return static_cast<Element const&>(*_iterator);
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::Element const * CATCDSMultimap<Key, Value>::ConstIterator::operator->()
{
  return static_cast<Element const*>(&*_iterator);
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::ConstIterator CATCDSMultimap<Key, Value>::ConstIterator::operator++()
{
  return ++_iterator;
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::ConstIterator CATCDSMultimap<Key, Value>::ConstIterator::operator++(int)
{
  return _iterator++;
}

template<class Key, class Value>
CATCDSInline bool CATCDSMultimap<Key, Value>::ConstIterator::operator==(ConstIterator const & iIterator) const
{
  return iIterator._iterator == _iterator;
}

template<class Key, class Value>
CATCDSInline bool CATCDSMultimap<Key, Value>::ConstIterator::operator!=(ConstIterator const & iIterator) const
{
  return iIterator._iterator != _iterator;
}

// Multimap

template<class Key, class Value>
CATCDSInline CATCDSMultimap<Key, Value>::CATCDSMultimap()
{
}

template<class Key, class Value>
CATCDSInline CATCDSMultimap<Key, Value>::CATCDSMultimap(CATCDSMultimap const &iMap) : 
  _map(iMap._map)
{
}

template<class Key, class Value>
CATCDSInline CATCDSMultimap<Key, Value> & CATCDSMultimap<Key, Value>::operator=(CATCDSMultimap const &iMap) 
{ 
  _map = iMap._map;
  return *this;
}

#ifdef CPP11_AVAILABLE
template<class Key, class Value>
CATCDSInline CATCDSMultimap<Key, Value>::CATCDSMultimap(CATCDSMultimap &&iMap) : 
  _map(std::move(iMap._map))
{
}

template<class Key, class Value>
CATCDSInline CATCDSMultimap<Key, Value> & CATCDSMultimap<Key, Value>::operator=(CATCDSMultimap &&iMap)
{ 
  _map = std::move(iMap._map);
  return *this; 
}
#endif

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::Iterator CATCDSMultimap<Key, Value>::Insert(Key const &iKey, Value const &iValue)
{
  return _map.insert(std::pair<Key, Value>(iKey, iValue));
}

template<class Key, class Value>
CATCDSInline void CATCDSMultimap<Key, Value>::Erase(Key const &iKey)
{
  _map.erase(iKey);
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::Iterator CATCDSMultimap<Key, Value>::Erase(Iterator iIterator)
{
  Iterator itToErase = iIterator++;
  _map.erase(itToErase._iterator);
  return iIterator; //returns an iterator to the next element
}

template<class Key, class Value>
CATCDSInline void CATCDSMultimap<Key, Value>::Clear()
{
  _map.clear();
}

template<class Key, class Value>
CATCDSInline int CATCDSMultimap<Key, Value>::Size() const
{
  return static_cast<int>(_map.size());
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::Iterator CATCDSMultimap<Key, Value>::Find(Key const &iKey)
{
  return _map.find(iKey);
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::ConstIterator CATCDSMultimap<Key, Value>::Find(Key const &iKey) const
{
  return _map.find(iKey);
}

template<class Key, class Value>
CATCDSInline CATCDSBoolean CATCDSMultimap<Key, Value>::Has(Key const &iKey) const
{
  return Find(iKey) != End();
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::Iterator CATCDSMultimap<Key, Value>::Begin()
{
  return _map.begin();
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::Iterator CATCDSMultimap<Key, Value>::End()
{
  return _map.end();
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::ConstIterator CATCDSMultimap<Key, Value>::CBegin() const
{
  return _map.cbegin();
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::ConstIterator CATCDSMultimap<Key, Value>::cbegin() const
{
  return _map.cbegin();
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::ConstIterator CATCDSMultimap<Key, Value>::Begin() const
{
  return _map.begin();
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::ConstIterator CATCDSMultimap<Key, Value>::begin() const
{
  return _map.begin();
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::ConstIterator CATCDSMultimap<Key, Value>::CEnd() const
{
  return _map.cend();
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::ConstIterator CATCDSMultimap<Key, Value>::cend() const
{
  return _map.cend();
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::ConstIterator CATCDSMultimap<Key, Value>::End() const
{
  return _map.end();
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::ConstIterator CATCDSMultimap<Key, Value>::end() const
{
  return _map.end();
}

template<class Key, class Value>
CATCDSInline int CATCDSMultimap<Key, Value>::Count(Key const &iKey)
{
  return static_cast<int>(_map.count(iKey));
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::Iterator CATCDSMultimap<Key, Value>::LowerBound(Key const &iKey)
{
  return _map.lower_bound(iKey);
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::ConstIterator CATCDSMultimap<Key, Value>::LowerBound(Key const &iKey) const
{
  return _map.lower_bound(iKey);
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::Iterator CATCDSMultimap<Key, Value>::UpperBound(Key const &iKey)
{
  return _map.upper_bound(iKey);
}

template<class Key, class Value>
CATCDSInline typename CATCDSMultimap<Key, Value>::ConstIterator CATCDSMultimap<Key, Value>::UpperBound(Key const &iKey) const
{
  return _map.upper_bound(iKey);
}

template<class Key, class Value>
#ifdef _WINDOWS_SOURCE
CATCDSInline typename CATCDSMultimap<Key, Value>::Range<typename CATCDSMultimap<Key, Value>::Iterator> CATCDSMultimap<Key, Value>::EqualRange(Key const &iKey)
#else
CATCDSInline typename CATCDSMultimap<Key, Value>::template Range<typename CATCDSMultimap<Key, Value>::Iterator> CATCDSMultimap<Key, Value>::EqualRange(Key const &iKey)
#endif
{
  std::pair<typename std::multimap<Key, Value>::iterator, typename std::multimap<Key, Value>::iterator> range = _map.equal_range(iKey);
  return Range<Iterator>(range.first, range.second);
}

template<class Key, class Value>
#ifdef _WINDOWS_SOURCE
CATCDSInline typename CATCDSMultimap<Key, Value>::Range<typename CATCDSMultimap<Key, Value>::ConstIterator>  CATCDSMultimap<Key, Value>::EqualRange(Key const &iKey) const
#else
CATCDSInline typename CATCDSMultimap<Key, Value>::template Range<typename CATCDSMultimap<Key, Value>::ConstIterator>  CATCDSMultimap<Key, Value>::EqualRange(Key const &iKey) const
#endif
{
  std::pair<typename std::multimap<Key, Value>::const_iterator, typename std::multimap<Key, Value>::const_iterator> range = _map.equal_range(iKey);
  return Range<ConstIterator>(range.first, range.second);
}

#endif
