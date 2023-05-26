#ifndef __CATOmxList_H
#define __CATOmxList_H

#include "CATOmxVector.h"

/**
 * Exactly the same as CATOmxVector except that indices are in [1,Size()]
 */
template<class Type>
class CATOmxList : public CATOmxVector<Type>
{
public:
  typedef Type* ValueType;
  typedef int   KeyType;
  /**
   * Default constructor.
   */
  inline CATOmxList() {}

  /**
   * Copy constructor.
   */
  inline CATOmxList(const CATOmxVector<Type>& iList) :CATOmxVector<Type>(iList) {}


  /**
   * Build the Vector using an iterator.
   * @see CATOmxIter.
   */
  inline CATOmxList<Type>(const typename CATOmxVector<Type>::IteratorType& iter) : CATOmxVector<Type>(iter) {}

  /**
   * Copy operator. (overrided for some AIX issue)
   */
  inline CATOmxList<Type>& operator=(const CATOmxVector<Type>& iList) { return static_cast<CATOmxList<Type>&>(this->CATOmxVector<Type>::operator=(iList)); }

  /**
   * Build the collection using an iterator. (overrided for some AIX issue)
   * @see CATOmxIter.
   * @param iter the iterator (warning, despite const type specifier, iter is emptied)
   */
  inline CATOmxList<Type>& operator=(const typename CATOmxVector<Type>::IteratorType& iter) { return static_cast<CATOmxList<Type>&>(this->CATOmxVector<Type>::operator=(iter)); }

  /**
   * Returns i-th element of the vector.
   * @param i must be in [1,Size()].
   */
  inline Type* operator[](int i) const { return this->CATOmxVector<Type>::operator[](i - 1); }

  /*
   * Set i-th element of the vector .
   * @param i must be in [1,Size()].
   */
  inline void Set(int i, Type* iObj) { this->CATOmxVector<Type>::Set(i - 1, iObj); }

  /**
   * Insert an item in the vector.
   * @param i must be in [1,Size()].
   */
  inline void InsertAt(int i, Type* iObj) { this->CATOmxVector<Type>::InsertAt(i - 1, iObj); }

  /**
   * Locate an item in the vector.
   * @param iObj the item to find.
   * @return the found position, 0 if not found
   */
  inline int Locate(const Type* iObj) const { return this->CATOmxVector<Type>::Locate(iObj) + 1; }

  /**
  * Remove an element of the array.
  * @param index
  *   the index to remove
  * @param count
  *   the number of elements to remove (optional, default is one)
  * @param keepAllocation
  *   if true, do not reallocate internal data (optional, default is false)
  */
  inline void RemoveAt(int index, int count = 1, CATBoolean keepAllocation = FALSE) { this->CATOmxBaseVector::RemoveAt(index - 1, count, keepAllocation); }
  inline void RemovePosition(int index) { RemoveAt(index); }

  /**
   * Removes the first occurrence of iObj in the vector.
   * returns the position where iObj was, 0 if not found.
   */
  inline int RemoveValue(const Type* iObj) { return this->CATOmxVector<Type>::RemoveValue(iObj) + 1; }

  /**
   * Returns i-th element of the vector or NULL if outside range.
   * @param i must be in [1;Size()].
   */
  inline ValueType TryGetItem(int idx) const { return this->CATOmxVector<Type>::TryGetItem(idx - 1); }

#if OMX_CXX11 == 1
  /** move semantics */
  inline CATOmxList(CATOmxVector<Type>&& other) :CATOmxVector<Type>(std::move(other)) {}
  inline CATOmxList<Type>& operator=(CATOmxVector<Type>&& other) { return static_cast<CATOmxList<Type>&>(this->CATOmxVector<Type>::operator=(std::move(other))); }

  /** initializer list */
  inline CATOmxList(std::initializer_list<Type*> list) : CATOmxVector<Type>(list) {}
  inline CATOmxList<Type>& operator=(std::initializer_list<Type*> list) { return this->CATOmxVector<Type>::operator=(list); }
#endif

private:
  /**deprecated*/
  Type* GetItem(int i) const;
  /**deprecated*/
  void SetItem(int i, Type* iObj);
};

#endif
