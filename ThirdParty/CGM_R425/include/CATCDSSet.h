// COPYRIGHT DASSAULT SYSTEMES 2016
//=============================================================================
//
// CATCDSSet:
//
// A template set class.
// If your type is integers, floating points or pointers, 
// the implementation set is explicitely instantiated in CATCDSUtilities library.
//
//=============================================================================
//  April 2016  Creation                         TE9
//=============================================================================

#ifndef CATCDSSet_h
#define CATCDSSet_h

#include "CATCDSBoolean.h"
#include "CATCDSInline.h"
#include "CATCDSMap.h"

template<class T>
class CATCDSSet : protected CATCDSMap<T, CATCDSBoolean>
{
public:
  using typename CATCDSMap<T, CATCDSBoolean>::KeyType;
  using typename CATCDSMap<T, CATCDSBoolean>::ValueType;
  using typename CATCDSMap<T, CATCDSBoolean>::KeyRefType;
  using typename CATCDSMap<T, CATCDSBoolean>::ValueRefType;
  using typename CATCDSMap<T, CATCDSBoolean>::KeyConstRefType;
  using typename CATCDSMap<T, CATCDSBoolean>::ValueConstRefType;
  
  class Iterator {
  public:
    CATCDSInline Iterator() {}

    CATCDSInline Iterator(typename CATCDSMap<T, CATCDSBoolean>::Iterator iIterator) : _iterator(iIterator) {}

    CATCDSInline Iterator operator++()
    {
      return ++_iterator;
    }

    CATCDSInline Iterator operator++(int)
    {
      return _iterator++;
    }

    CATCDSInline typename CATCDSMap<T, CATCDSBoolean>::KeyConstRefType operator*()
    {
      return _iterator->GetKey();
    }

    CATCDSInline bool operator==(Iterator const & iIterator) const
    {
      return iIterator._iterator == _iterator;
    }

    CATCDSInline bool operator!=(Iterator const & iIterator) const
    {
      return iIterator._iterator != _iterator;
    }

    typename CATCDSMap<T, CATCDSBoolean>::Iterator _iterator;
  };

  class ConstIterator {
  public:
    CATCDSInline ConstIterator() {}

    CATCDSInline ConstIterator(typename CATCDSMap<T, CATCDSBoolean>::ConstIterator iIterator) : _iterator(iIterator) {}

    CATCDSInline ConstIterator operator++()
    {
      return ++_iterator;
    }

    CATCDSInline ConstIterator operator++(int)
    {
      return _iterator++;
    }

    CATCDSInline typename CATCDSMap<T, CATCDSBoolean>::KeyConstRefType operator*()
    {
      return _iterator->GetKey();
    }

    CATCDSInline bool operator==(ConstIterator const & iIterator) const
    {
      return iIterator._iterator == _iterator;
    }

    CATCDSInline bool operator!=(ConstIterator const & iIterator) const
    {
      return iIterator._iterator != _iterator;
    }

    typename CATCDSMap<T, CATCDSBoolean>::ConstIterator _iterator;
  };

  /**
   * Constructs a new set
   * @param iSize Approximate size of the set after filling
   */
  CATCDSInline CATCDSSet(int iSize = 0) : CATCDSMap<T, CATCDSBoolean>(iSize) {}

  /**
   * Inserts an element in the set
   * @param iKey   Element key
   * @param iValue Element value
   * @return       TRUE if insertion succeeded
   */
  CATCDSInline CATCDSBoolean Insert(T const &iE)
  {
    return CATCDSMap<T, CATCDSBoolean>::Insert(iE, TRUE);
  }

  /**
   * Removes an element by its key
   * @param iKey The key of the element
   */
  CATCDSInline void Erase(T const &iE)
  {
    CATCDSMap<T, CATCDSBoolean>::Erase(iE);
  }

  /**
   * Removes an element at a given position
   * @param iIterator An iterator pointing on the element to remove
   *
   * Note : Iterator return is available from C++ 11 to enable removing during an iteration over the set
   */
  CATCDSInline Iterator Erase(Iterator iIterator)
  {
    return CATCDSMap<T, CATCDSBoolean>::Erase(iIterator._iterator);
  }

  /**
   * Clears set content
   */
  CATCDSInline void Clear()
  {
    CATCDSMap<T, CATCDSBoolean>::Clear();
  }

  /**
   * Returns the number elements in the set
   * @return Map size
   */
  CATCDSInline int Size() const
  {
    return CATCDSMap<T, CATCDSBoolean>::Size();
  }

  /**
   * Search an element by its key in the set
   * @param iKey The element key
   * @return     An iterator pointing on the element if it was found, an iterator equal to End otherwise
   */
  CATCDSInline Iterator Find(T const &iE)
  {
    return CATCDSMap<T, CATCDSBoolean>::Find(iE);
  }

  CATCDSInline ConstIterator Find(T const &iE) const
  {
    return CATCDSMap<T, CATCDSBoolean>::Find(iE);
  }

  /**
   * Search an element in the set
   * @param iE   The element
   * @return     TRUE if the element belongs to the set
   */
  CATCDSInline CATCDSBoolean Has(T const &iE) const
  {
    return Find(iE) != End();
  }

  /*
   * Returns an iterator pointing on the first element of the set
   */
  CATCDSInline Iterator begin()
  {
    return CATCDSMap<T, CATCDSBoolean>::Begin();
  }

  CATCDSInline Iterator Begin()
  {
    return CATCDSMap<T, CATCDSBoolean>::Begin();
  }

  /*
   * Returns an iterator pointing just after the last element of the set
   */
  CATCDSInline Iterator end()
  {
    return CATCDSMap<T, CATCDSBoolean>::End();
  }

  CATCDSInline Iterator End()
  {
    return CATCDSMap<T, CATCDSBoolean>::End();
  }

  /*
   * Returns a const iterator pointing on the first element of the set
   */
  CATCDSInline ConstIterator CBegin() const
  {
    return CATCDSMap<T, CATCDSBoolean>::CBegin();
  }

  CATCDSInline ConstIterator begin() const
  {
    return CATCDSMap<T, CATCDSBoolean>::CBegin();
  }

  CATCDSInline ConstIterator Begin() const
  {
    return CATCDSMap<T, CATCDSBoolean>::CBegin();
  }

  /*
   * Returns a const iterator pointing just after the last element of the set
   */
  CATCDSInline ConstIterator CEnd() const
  {
    return CATCDSMap<T, CATCDSBoolean>::CEnd();
  }

  CATCDSInline ConstIterator end() const
  {
    return CATCDSMap<T, CATCDSBoolean>::CEnd();
  }

  CATCDSInline ConstIterator End() const
  {
    return CATCDSMap<T, CATCDSBoolean>::CEnd();
  }

  /**
   * Reserve size to contain at least the given number of elements
   * @param iSize Size to reserve
   */
  CATCDSInline void Reserve(int iSize)
  {
    CATCDSMap<T, CATCDSBoolean>::Reserve(iSize);
  }

  /**
   * Return a reference on a set element for a given key
   * If the key doesn't belong to the set. A default-initialized element is insert and a reference on it is returned.
   * @param iKey Element key
   * @return     A reference on set element at given key
   */
  CATCDSInline typename CATCDSMap<T, CATCDSBoolean>::ValueRefType operator[](T const & iE)
  {
    return CATCDSMap<T, CATCDSBoolean>::operator[](iE);
  }

  /*
   * Search an element by its key and return its associated value
   * We assume that the key belongs to the set
   * @param iKey          The key of the element to search
   * @param iDefaultValue The value to return if not found
   * @return              Associated value
   */
  CATCDSInline typename CATCDSMap<T, CATCDSBoolean>::ValueConstRefType At(T const &iE) const
  {
    return CATCDSMap<T, CATCDSBoolean>::At(iE);
  }

  /*
   * Search an element by its key and return its associated value
   * We assume that the key belongs to the set
   * @param iKey          The key of the element to search
   * @param iDefaultValue The value to return if not found
   * @return              Associated value
   */
  CATCDSInline typename CATCDSMap<T, CATCDSBoolean>::ValueRefType At(T const &iE)
  {
    return CATCDSMap<T, CATCDSBoolean>::At(iE);
  }
};

#endif
