/**
 * @level Private
 * @usage U1
 * COPYRIGHT DASSAULT SYSTEMES 2003
 */
#ifndef CATOmxArray_H
#define CATOmxArray_H

#include "CATOmxBaseArray.h"
#include "CATOmxIter.h"
#include "CATOmxPortability.h"
#include "CATOmxCompareFunctor.h"
#include "CATOmxDeprecated.h"
#include "CATOmxDefaultCollecManager.h"

template<typename T, CATOmxCollecManagerLocator M> class CATOmxTuple;

template<typename T, CATOmxCollecManagerLocator M> class CATOmxArraySTLIterator;

/**
 * This class implements an array of objects.
 * Indexes start at 1.
 *
 * It implements Copy-On-Write feature.
 *
 * @href http://osmwebdsy/wiki/index.php/CATOmxArray_Usage
 */
template<typename T, CATOmxCollecManagerLocator M = CATOmxDefaultCollecManager<T>::manager  >
class CATOmxArray : public CATOmxBaseArray
{
public:
  typedef T ValueType;
  typedef int KeyType;
  typedef CATOmxIter<const T> IteratorType;

  /**
   * Default constructor, builds an empty array.
   */
  inline CATOmxArray() {}

  /**
   * Constructor, builds an array containing iSize default-initialized items
   */
  OMX_EXPLICIT inline CATOmxArray(int iSize) : CATOmxBaseArray(iSize, M) {}

  /**
   * copy constructor (does a shallow copy)
   */
  inline CATOmxArray(const CATOmxArray<T, M>& array) : CATOmxBaseArray(array) {}

  /**
   * Build the collection using an iterator.
   * @see CATOmxIter.
   * @param iter the iterator (warning, despite const type specifier, iter is emptied)
   */
  inline CATOmxArray(const CATOmxIter<const T>& iIter) :CATOmxBaseArray(0, M) { CATOmxBaseArray::Copy(const_cast<CATOmxIter<const T>&>(iIter).PrivateStrip(), M); }
  inline CATOmxArray(const CATOmxIter<T>& iIter) : CATOmxBaseArray(0, M) { CATOmxBaseArray::Copy(const_cast<CATOmxIter<T>&>(iIter).PrivateStrip(), M); }
  inline CATOmxArray<T, M>& operator=(const CATOmxIter<const T>& iIter) { CATOmxBaseArray::Copy(const_cast<CATOmxIter<const T>&>(iIter).PrivateStrip(), M); return *this; }
  inline CATOmxArray<T, M>& operator=(const CATOmxIter<T>& iIter) { CATOmxBaseArray::Copy(const_cast<CATOmxIter<T>&>(iIter).PrivateStrip(), M); return *this; }

  /**
   * copy operator (does a shallow copy)
   */
  inline CATOmxArray<T, M>& operator=(const CATOmxArray<T, M>& t) { CATOmxBaseArray::Copy(t, M); return *this; }


  /**
   * returns a read-only reference on the i-th element of the array.
   */
  inline const T& operator[](int idx) const { return *(const T*)CATOmxBaseArray::GetR(idx); }
  /** deprecated (implicit const_cast)*/
  inline OMX_DEPRECATED("Use operator[]") T& GetR(int idx) const { return const_cast<T&>(this->operator[](idx)); }

  /**
   * returns a read-write reference on the i-th element of the array.
   */
  inline T& GetW(int idx) { return *(T*)CATOmxBaseArray::GetW(idx, M); }

  /**
   * Resize array to iSize.
   */
  inline void Resize(int iSize) { CATOmxBaseArray::Resize(iSize, M); }

  /**
   * Pre-allocate iCapacity items.
   */
  inline void Reserve(int iCapacity) { CATOmxBaseArray::Reserve(iCapacity, M); }

  /**
   * Remove an element of the array.
   * @param index
   *   the index to remove
   * @param count
   *   the number of elements to remove (optional, default is one)
   * @param keepAllocation
   *   if true, do not reallocate internal data (optional, default is false)
   */
  inline void RemoveAt(int index, CATBoolean keepAllocation = FALSE) { RemoveAt(index, 1, keepAllocation); }
  inline void RemoveAt(int index, int count, CATBoolean keepAllocation = FALSE) { CATOmxBaseArray::RemoveAt(index, count, keepAllocation, M); }
  inline void Remove(int index, CATBoolean keepAllocation = FALSE) { RemoveAt(index, keepAllocation); }
  inline void RemovePosition(int index, CATBoolean keepAllocation = FALSE) { RemoveAt(index, keepAllocation); }

  /**
   * Remove all elements of the array.
   * You can specify iKeepAlloc=TRUE to avoid free of used memory.
   */
  inline void RemoveAll(CATBoolean iKeepAlloc = FALSE) { CATOmxBaseArray::RemoveAll(iKeepAlloc, M); }

  /**
   * Get a slice of this array
   * @param startIndex
   *   the first index of the slice
   * @param sliceLength
   *   the length of the slice
   *   this parameter is optional, default value means 'longest possible'
   * @return
   *   the slice
   *
   * example:
   *  [ 1, 2, 3].GetSlice(1, 2) => [1, 2]
   *  [ 1, 2, 3].GetSlice(2, 2) => [2, 3]
   *  [ 1, 2, 3].GetSlice(2, 1) => [2]
   *  [ 1, 2, 3].GetSlice(2)    => [2, 3]
   */
  inline CATOmxArray<T, M> GetSlice(int startIndex, int sliceLength = -1) const
  {
    CATOmxArray<T, M> slice;
    _GetSlice(startIndex, sliceLength, slice, M);
    return slice;
  }

  /**
   * Set i-th element of the array with value x.
   */
  inline void Set(int idx, const T& x) { CATOmxBaseArray::Set(idx, (void*)&x, M); }

  /**
   * Append an element at the end of the array.
   */
  inline void Append(const T& x) { CATOmxBaseArray::Append((void*)&x, M); }

  /**
   * Append an array at the end of the array.
   */
  inline void Append(const CATOmxArray<T, M>& array) { CATOmxBaseArray::Append(array, M); }

  /**
   * Append all objects from an iterator at the end of the array.
   */
  inline void Append(const CATOmxIter<const T>& iIter) { CATOmxBaseArray::Append(const_cast<CATOmxIter<const T>&>(iIter).PrivateStrip(), M); }
  inline void Append(const CATOmxIter<T>& iIter) { CATOmxBaseArray::Append(const_cast<CATOmxIter<T>&>(iIter).PrivateStrip(), M); }

  /**
   * Append an item to the array and opportunistically reserve storage for max size items.
   */
  inline void QuickAppend(const T& x, int iReserve) { CATOmxBaseArray::QuickAppend((void*)&x, iReserve, M); }

  /**
   * Insert element x at i-th position of the array.
   */
  inline void Insert(int idx, const T& x) { CATOmxBaseArray::Insert(idx, (void*)&x, M); }
  inline void InsertAt(int idx, const T& x) { CATOmxBaseArray::Insert(idx, (void*)&x, M); }

  /**
   * Remove first occurrence of x from the array.
   */
  inline void RemoveValue(const T& x) { CATOmxBaseArray::RemoveValue(&x, M); }

  /**
   * Returns index of the first occurrence of x in the array.
   */
  inline int Locate(const T& x) const { return CATOmxBaseArray::Locate(&x, M); }

  /**
   * Returns underlying "C" array.
   */
  inline const T* GetArray() const { return (T*)CATOmxBaseArray::GetArray(); }

  /**
   * Returns underlying "C" array (writable mode).
   */
  inline T* GetArrayW() { return (T*)CATOmxBaseArray::GetArrayW(M); }

  /**
   * Swap i-th and j-th elements of the array.
   */
  inline void Swap(int i, int j) { CATOmxBaseArray::Swap(i, j, M); }

  /**
   * Reverse the array.
   */
  inline void Reverse() { CATOmxBaseArray::Reverse(M); }


  /**
   * Sort the array (in ascending order).
   * @param iCmp
   *   A strcmp like comparison function
   *   If NULL, CollecManager comparison function is used.
   */
  inline void Sort(int(*iCmp)(const T&, const T&) = 0) { CATOmxBaseArray::Sort((int(*)(const void*, const void*))iCmp, M); }

  /**
   * Sort the array (in ascending order).
   * @param iCompare
   *   Comparison functor
   */
  inline void Sort(CATOmxCompareFunctor<T>& iCompare) { CATOmxBaseArray::Sort(&iCompare, (int(*)(void*, const void*, const void*))&CATOmxCompareFunctor<T>::Compare, M); }

  /**
   * Comparison (strcmp style).
   */
  inline int Compare(const CATOmxArray<T, M>& array) const { return CATOmxBaseArray::Compare(array, M); }

  /**
   * Comparison operators.
   */
  inline CATBoolean operator==(const CATOmxArray<T, M>& array) const { return 0 == CATOmxBaseArray::Compare(array, M); }
  inline CATBoolean operator!=(const CATOmxArray<T, M>& array) const { return !this->operator==(array); }

  /**
   * Build from a CATOmxTuple object.
   */
  inline void BuildFromTuple(CATOmxTuple<T, M>& iTuple) { CATOmxBaseArray::BuildFromTuple((CATOmxBaseTuple*)&iTuple, M); }

  /**
   * Build from a "C" array
   */
  inline void BuildFromCArray(const T* iArray, int iSize) { CATOmxBaseArray::BuildFromCArray(iArray, iSize, M); }

  /**
   * Returns an iterator on the array.
   * @see CATOmxIter.
   */
  inline IteratorType Iterator() const { return IteratorType(CATOmxBaseArray::Iterator(M)); }
  inline IteratorType ConstIterator() const { return IteratorType(CATOmxBaseArray::Iterator(M)); }

  /** Ensure the collection is not shared */
  inline int Isolate() { return CATOmxBaseArray::Isolate(M); }

  /**returns CollecManager locator...DO NOT USE*/
  static inline CATOmxCollecManagerLocator ManagerLocator() { return M; }

  /** range for support */
  typedef CATOmxArraySTLIterator<T, M> const_iterator;
  inline const_iterator begin() const { return const_iterator(*this, GetArray()); }
  inline const_iterator end() const { return const_iterator(*this, reinterpret_cast<const T*>(GetArrayEnd())); }
  inline const_iterator rbegin() const { return --end(); }
  inline const_iterator rend() const { return --begin(); }

  /** std::back_inserter support */
  typedef T value_type;
  inline void push_back(const T& item) { Append(item); }
  /**
   * Destructor.
   */
  inline ~CATOmxArray() { Die(M); }

#if OMX_CXX11 == 1
  /** move semantics */
  inline CATOmxArray(CATOmxArray<T, M>&& array) :CATOmxBaseArray(std::move(array)) {}
  inline CATOmxArray<T, M>& operator=(CATOmxArray<T, M>&& array) { return static_cast<CATOmxArray<T, M>&>(this->CATOmxBaseArray::operator=(std::move(array))); }

  /** initializer list */
  inline CATOmxArray(std::initializer_list<T> list)
  {
    int size = (int)list.size();
    for (const T& item : list)
      QuickAppend(item, size);
  }
  inline CATOmxArray<T, M>& operator=(std::initializer_list<T> list) { return this->operator=(CATOmxArray<T, M>(list)); }
#endif
};

/**
 * Build an iterator from an array of pointer (allows to avoid the ** from CATOmxArray native iterator)
 */
template<class ArrayType, class Type>
inline void CATOmxArrayOfPointerToIterator(const ArrayType& iArray, CATOmxIter<Type>& oIter)
{
  if (false) { Type* const& ref = iArray[0]; (void)ref; } //buildtime check
  oIter = iArray.ToPointerIterator(ArrayType::ManagerLocator());
}

/**
 * Build an array of pointer from an iterator (allows to avoid the ** from CATOmxArray native iterator)
 */
template<class ArrayType, class Type>
inline void CATOmxArrayOfPointerFromIterator(ArrayType& iArray, const CATOmxIter<Type>& iIter)
{
  if (false) { Type* const& ref = iArray[0]; (void)ref; } //buildtime check
  iArray.FromPointerIterator(const_cast<CATOmxIter<Type>&>(iIter).PrivateStrip(), ArrayType::ManagerLocator());
}

template<typename T, CATOmxCollecManagerLocator M>
class CATOmxArraySTLIterator
{
  CATOmxArray<T, M> m_array;
  const T* m_cursor;
public:
  CATOmxArraySTLIterator(const CATOmxArray<T, M>& array, const T* cursor) :m_array(array), m_cursor(cursor) {}

  inline CATOmxArraySTLIterator& operator++() { ++m_cursor; return *this; }
  inline CATOmxArraySTLIterator& operator--() { --m_cursor; return *this; }

  inline const T& operator*() const { return *m_cursor; }
  inline const T* operator->() const { return &this->operator*(); }

  inline bool operator==(const CATOmxArraySTLIterator& other) const { return m_cursor == other.m_cursor; }
  inline bool operator!=(const CATOmxArraySTLIterator& other) const { return !this->operator==(other); }

#if OMX_CXX11 == 1
  /** integration with <algorithm> (could not make it compile on AIX, but as there are no lambdas anyway...)*/
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = T;
  using difference_type = std::ptrdiff_t;
  using pointer = const T*;
  using reference = const T&;
#endif
};


#endif
