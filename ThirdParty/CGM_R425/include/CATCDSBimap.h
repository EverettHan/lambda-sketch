// COPYRIGHT DASSAULT SYSTEMES 2021
//=============================================================================
//
// CATCDSBimap:
//
// A template map class.
//
// Implementation of a bidirecional map
//
//=============================================================================
//  Dec 2021  Creation                         KUB
//=============================================================================

#ifndef CATCDSBimap_H
#define CATCDSBimap_H


#include "CATCDSMap.h"

template<class Left , class Right> 
class CATCDSBimap
{

public:


  class Iterator {
  public:
    Iterator();

    Iterator(typename CATCDSMap<Left, Right>::Iterator iIterator);

    typename CATCDSBimap<Left,Right>::Iterator operator++();
    typename CATCDSBimap<Left, Right>::Iterator operator++(int);

    bool operator==(Iterator const& iIterator) const;
    bool operator!=(Iterator const& iIterator) const;

    typename CATCDSMap<Left, Right>::Iterator _iterator;
  };

  class ConstIterator {
  public:
    ConstIterator();

    ConstIterator(typename CATCDSMap<Left, Right>::ConstIterator  iIterator);

    ConstIterator operator++();
    ConstIterator operator++(int);

    bool operator==(ConstIterator const& iIterator) const;
    bool operator!=(ConstIterator const& iIterator) const;

    typename CATCDSMap<Left, Right>::ConstIterator _iterator;
  };


  /**
  * Constructs a new map
  * @param iSize Approximate size of the map after filling
  */
  CATCDSBimap();
  CATCDSBimap(int iSize);
  CATCDSBimap(CATCDSBimap const& iMap);
  CATCDSBimap& operator=(CATCDSBimap const& iMap);

  /**
  * Inserts an element in the bimap
  * @param ileft   left element
  * @param iright  right elemnt
  * @return       TRUE if insertion succeeded
  */
  bool Insert(const Left& ileft, const Right& iright);

  /**
    * Erase a pair<left, Right> in bimap
    * @param ileft the left element of the pair to erase
    */
  void EraseLeft(Left const& iLeft);

  /**
   * Erase a pair<left, Right> in bimap
   * @param iRight the right element of the pair to erase
   */
  void EraseRight(Right const& iRight);
  

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
   * Reserve size to contain at least the given number of elements
   * @param iSize Size to reserve
   */
  void Reserve(int iSize);

 
  /**
   * Returns an iterator pointing on the first pair of elements of the bimap
   */  
  Iterator begin();

  /**
   * Returns an iterator pointing on the last left element of the map
   */
  Iterator end();

  ConstIterator cbegin() const;

  /**
   * Returns a const iterator pointing on the first right element of the map
   */
  ConstIterator cend() const;


  /**Get the right Value pointed by the iterator
  * @param it The iterator
  * @param oVal The right value associated to it
  * @return TRUE if the iterator is valid, FALSE elsewhere
  */
  bool GetRightValue(Iterator & it, Right& oVal);
  bool GetRightValue(ConstIterator& it, Right& oVal) const;

  /**Get the Left Value pointed by the iterator
  * @param it The iterator
  * @param oVal The Left value associated to it
  * @return TRUE if the iterator is valid, FALSE elsewhere
  */
  bool GetLeftValue(Iterator& it, Left& oVal);
  bool GetLeftValue(ConstIterator& it, Left& oVal) const;



  /**Search the left iterator associated to a Left element
   * @param iLeft The Left object
   * @return an Iterator pointing on iLeft if it was found, an Iterator equal to end otherwise
   */
  Iterator LeftFind(Left const& iLeft);
  
  /**Search the const iterator associated to a left element
   * @param iLeft The Left object
   * @return a ConstIterator pointing on iLeft if it was found, a ConstIterator equal to cend otherwise
   */
  ConstIterator LeftFind(Left const& iLeft) const;

  /**
  * Search the right iterator associated to a Right element
  * @param iRight The Right object
  * @return an right_iterator pointing on iRight if it was found, an right_iterator equal to right_end otherwise
  */
  Iterator RightFind(Right const& iRight);

  /**
   * Search the const right iterator associated to a Right element
   * @param iRight The Right object
   * @return an const_right_iterator pointing on iRight if it was found, an const_right_iterator equal to right_cend otherwise
   */
  ConstIterator RightFind(Right const& iRight) const;

  /**
   * Search the right element associated to the a left object
   * @param iLeft The left object
   * @param oRight The right object to find
   * @return TRUE if we find the right object, FALSE elsewhere
   */
  bool GetRightAssoc(Left const& iLeft, Right& oRight) const;


  /**
   * Search the left element associated to the a right object
   * @param iRight The right object
   * @param oLeft The left object to find
   * @return TRUE if we find the left object, FALSE elsewhere
   */
  bool GetLeftAssoc(Right const& iRight, Left& oLeft) const;

private:
  CATCDSMap<Left, Right> _l2r;
  CATCDSMap<Right, Left> _r2l;

};

// iterator implementation

template<class Left, class Right>
CATCDSInline CATCDSBimap<Left, Right>::Iterator::Iterator() {}

template<class Left, class Right>
CATCDSInline CATCDSBimap<Left, Right>::Iterator::Iterator(typename CATCDSMap<Left, Right>::Iterator iIterator) : _iterator(iIterator) {}

template<class Left, class Right>
CATCDSInline typename CATCDSBimap<Left, Right>::Iterator CATCDSBimap<Left, Right>::Iterator::operator++()
{
  ++_iterator;
  return *this;
}

template<class Left, class Right>
CATCDSInline typename CATCDSBimap<Left, Right>::Iterator CATCDSBimap<Left, Right>::Iterator::operator++(int)
{
  _iterator++;
  return *this;
}

template<class Left, class Right>
CATCDSInline bool CATCDSBimap<Left, Right>::Iterator::operator==(Iterator const& iIterator) const
{
  return iIterator._iterator == _iterator;
}

template<class Left, class Right>
CATCDSInline bool CATCDSBimap<Left, Right>::Iterator::operator!=(Iterator const& iIterator) const
{
  return iIterator._iterator != _iterator;
}

template<class Left, class Right>
CATCDSInline CATCDSBimap<Left, Right>::ConstIterator::ConstIterator() {}

template<class Left, class Right>
CATCDSInline CATCDSBimap<Left, Right>::ConstIterator::ConstIterator(typename CATCDSMap<Left, Right>::ConstIterator iIterator) : _iterator(iIterator) {}

template<class Left, class Right>
CATCDSInline typename CATCDSBimap<Left, Right>::ConstIterator CATCDSBimap<Left, Right>::ConstIterator::operator++()
{
  ++_iterator;
  return *this;
}

template<class Left, class Right>
CATCDSInline typename CATCDSBimap<Left, Right>::ConstIterator CATCDSBimap<Left, Right>::ConstIterator::operator++(int)
{
  _iterator++;
  return *this;
}

template<class Left, class Right>
CATCDSInline bool CATCDSBimap<Left, Right>::ConstIterator::operator==(ConstIterator const& iIterator) const
{
  return iIterator._iterator == _iterator;
}

template<class Left, class Right>
CATCDSInline bool CATCDSBimap<Left, Right>::ConstIterator::operator!=(ConstIterator const& iIterator) const
{
  return iIterator._iterator != _iterator;
}

// CATCDSBimap implementation

template<class Left, class Right>
CATCDSInline CATCDSBimap<Left,Right>::CATCDSBimap() 
{
}

template<class Left, class Right>
CATCDSInline CATCDSBimap<Left, Right>::CATCDSBimap(int iSize) : _l2r(iSize), _r2l(iSize)
{

}

template<class Left, class Right>
CATCDSInline CATCDSBimap<Left, Right>::CATCDSBimap(CATCDSBimap<Left, Right> const& iMap) : _l2r(iMap._l2r), _r2l(iMap._r2l)
{

}
template<class Left, class Right>
CATCDSInline CATCDSBimap<Left, Right>& CATCDSBimap<Left, Right>::operator=(CATCDSBimap const& iMap)
{
  _l2r = iMap._l2r;
  _r2l = iMap._r2l;
  return *this;
}

template<class Left, class Right>
CATCDSInline bool CATCDSBimap<Left, Right>::Insert(const Left& ileft, const Right& iright)
{
  bool rc = _l2r.Insert(ileft, iright);
  rc &= _r2l.Insert(iright, ileft);
  return rc;
}

template<class Left, class Right>
CATCDSInline void CATCDSBimap<Left, Right>::EraseLeft(Left const& iLeft)
{
  typename CATCDSMap<Left, Right>::Iterator it = _l2r.Find(iLeft);
  Right rv = it->GetValue();
  _l2r.Erase(iLeft);
  _r2l.Erase(rv);
}

template<class Left, class Right>
CATCDSInline void CATCDSBimap<Left, Right>::EraseRight(Right const& iRight)
{
  typename CATCDSMap<Right, Left>::Iterator it = _r2l.Find(iRight);
  Left lv = it->GetValue();
  _l2r.Erase(lv);
  _r2l.Erase(iRight);
}

template<class Left, class Right>
CATCDSInline void CATCDSBimap<Left, Right>::Clear()
{
  _l2r.Clear();
  _r2l.Clear();
}

template<class Left, class Right>
CATCDSInline int CATCDSBimap<Left, Right>::Size() const
{
  CATCDSAssert(_l2r.Size() == _r2l.Size());
  return _l2r.Size();
}

template<class Left, class Right>
CATCDSInline void CATCDSBimap<Left, Right>::Reserve(int iSize)
{
  _l2r.Reserve(iSize);
  _r2l.Reserve(iSize);
}


template<class Left, class Right>
CATCDSInline typename CATCDSBimap<Left, Right>::Iterator CATCDSBimap<Left, Right>::LeftFind(Left const& iLeft)
{
  return _l2r.Find(iLeft);
}

template<class Left, class Right>
CATCDSInline typename CATCDSBimap<Left, Right>::ConstIterator CATCDSBimap<Left, Right>::LeftFind(Left const& iLeft) const
{
  return _l2r.Find(iLeft);
}

template<class Left, class Right>
CATCDSInline typename CATCDSBimap<Left, Right>::Iterator CATCDSBimap<Left, Right>::RightFind(Right const& iRight)
{
  typename CATCDSMap<Right, Left>::Iterator it = _r2l.Find(iRight);
  return it != _r2l.end() ? _l2r.Find(it->GetValue()) : _l2r.end();
}

template<class Left, class Right>
CATCDSInline typename CATCDSBimap<Left, Right>::ConstIterator CATCDSBimap<Left, Right>::RightFind(Right const& iRight) const
{
  typename CATCDSMap<Right, Left>::ConstIterator it = _r2l.Find(iRight);
  return it != _r2l.end() ? _l2r.Find(it->GetValue()) : _r2l.end();
}

template<class Left, class Right>
CATCDSInline typename CATCDSBimap<Left, Right>::Iterator CATCDSBimap<Left, Right>::begin()
{
  return _l2r.begin();
}

template<class Left, class Right>
CATCDSInline typename CATCDSBimap<Left, Right>::Iterator CATCDSBimap<Left, Right>::end()
{
  return _l2r.end();
}

template<class Left, class Right>
CATCDSInline typename CATCDSBimap<Left, Right>::ConstIterator CATCDSBimap<Left, Right>::cbegin() const
{
  return _l2r.begin();
}

template<class Left, class Right>
CATCDSInline typename CATCDSBimap<Left, Right>::ConstIterator CATCDSBimap<Left, Right>::cend() const
{
  return _l2r.cend();
}


template<class Left, class Right>
CATCDSInline bool CATCDSBimap<Left, Right>::GetRightValue(typename CATCDSBimap<Left, Right>::ConstIterator& it, Right& oVal) const
{
  if (it != cend())
  {
    oVal = it._iterator->GetValue();
    return TRUE;
  }
  return FALSE;
}

template<class Left, class Right>
CATCDSInline bool CATCDSBimap<Left, Right>::GetRightValue(typename CATCDSBimap<Left, Right>::Iterator& it, Right& oVal)
{
  if (it != end())
  {
    oVal = it._iterator->GetValue();
    return TRUE;
  }
  return FALSE;
}

template<class Left, class Right>
CATCDSInline bool CATCDSBimap<Left, Right>::GetLeftValue(typename CATCDSBimap<Left, Right>::Iterator& it, Left& oVal)
{
  if (it != end())
  {
    typename CATCDSMap<Left, Right>::Iterator it_map = static_cast<typename CATCDSMap<Left, Right>::Iterator>(it._iterator);
    oVal = it._iterator->GetKey();
    return TRUE;
  }
  return FALSE;
}

template<class Left, class Right>
CATCDSInline bool CATCDSBimap<Left, Right>::GetLeftValue(typename CATCDSBimap<Left, Right>::ConstIterator& it, Left& oVal) const
{
  if (it != cend())
  {
    oVal = it._iterator->GetKey();
    return TRUE;
  }
  return FALSE;
}


template<class Left, class Right>
CATCDSInline bool CATCDSBimap<Left, Right>::GetRightAssoc(Left const& iLeft, Right& oRight) const
{
  bool rc = FALSE;
  typename CATCDSMap<Left, Right>::ConstIterator it = _l2r.Find(iLeft);
  if (it != _l2r.cend())
  {
    rc = TRUE;
    oRight = it->GetValue();
  }
  return rc;
}


template<class Left, class Right>
bool CATCDSBimap<Left, Right>::GetLeftAssoc(Right const& iRight, Left& oLeft) const
{
  bool rc = FALSE;
  typename CATCDSMap<Right, Left>::ConstIterator it = _r2l.Find(iRight);
  if (it != _r2l.cend())
  {
    rc = TRUE;
    oLeft = it->GetValue();
  }
  return rc;

}



#endif
