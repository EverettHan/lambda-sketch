#ifndef CATOmxBaseArray_H
#define CATOmxBaseArray_H

/**
* @level Private
* @usage U1
* COPYRIGHT DASSAULT SYSTEMES 2003
*/

#include "CATOmxKernel.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxPortability.h"

class CATOmxBaseTuple;
class CATOmxBaseIter;

/**
 * You should not use this class directly
 * You should use CATOmxArray instead
 */
class ExportedByCATOmxKernel CATOmxBaseArray
{
  CATOmxBaseTuple* m_tuple;
public:
  /**
   * constructor.
   */
  CATOmxBaseArray(int size, CATOmxCollecManagerLocator mgrLocator);

  /**
   * @return size of array.
   */
  int Size() const;

  /**
   * Returns TRUE if the collection is empty.
   */
  inline int IsEmpty() const { return !Size(); }

  /**
   * copy iSrc into this.
   */
  void Copy(const CATOmxBaseArray& iSrc, CATOmxCollecManagerLocator mgrLocator);

  /**
   * copy iIter into this.
   */
  void Copy(CATOmxBaseIter* iIter, CATOmxCollecManagerLocator mgrLocator);


  /**
   * Get a read-only pointer on i-th element of array.
   */
  void* GetR(int idx) const;

  /**
   * Get a read-write pointer on i-th element of array.
   */
  void* GetW(int idx, CATOmxCollecManagerLocator mgrLocator);

  /**
   * Set i-th element of the array.
   */
  void Set(int idx, const void* data, CATOmxCollecManagerLocator mgrLocator);

  /**
   * Append an element in the array.
   */
  void Append(const void* data, CATOmxCollecManagerLocator mgrLocator);

  /**
   * Append an array in the array.
   */
  void Append(const CATOmxBaseArray& array, CATOmxCollecManagerLocator mgrLocator);

  /**
   * Append an iterator in the array.
   */
  void Append(CATOmxBaseIter* iIter, CATOmxCollecManagerLocator mgrLocator);

  /**
   * Append an item to the array and opportunistically reserve max size
   * of the vector in order to reduce reallocations.
   */
  void QuickAppend(const void* data, int iReserve, CATOmxCollecManagerLocator mgrLocator);

  /**
   * pre-allocate iReserve items.
   */
  void Reserve(int iReserve, CATOmxCollecManagerLocator mgrLocator);

  /**
   * Append an element at i-th position of the array.
   */
  void Insert(int idx, const void* data, CATOmxCollecManagerLocator mgrLocator);

  /**
   * resize array.
   */
  void Resize(int size, CATOmxCollecManagerLocator mgrLocator);

  /**
  * Remove an element of the array.
  * @param index
  *   the index to remove
  * @param count
  *   the number of elements to remove (optional, default is one)
  * @param keepAllocation
  *   if true, do not reallocate internal data (optional, default is false)
  */
  void Remove(int index, CATBoolean keepAlloc, CATOmxCollecManagerLocator mgrLocator);
  void RemoveAt(int index, int count, CATBoolean keepAlloc, CATOmxCollecManagerLocator mgrLocator);

  /**
   * remove all elements of the array.
    * You can specify iKeepAlloc=TRUE to avoid free of used memory.
   */
  void RemoveAll(CATBoolean iKeepAlloc, CATOmxCollecManagerLocator mgrLocator);

protected:
  void _GetSlice(int startIndex, int sliceLength, CATOmxBaseArray& slice, CATOmxCollecManagerLocator mgrLocator) const;
public:
  /**
   * remove first occurrence of input value in the array.
   */
  void RemoveValue(const void* data, CATOmxCollecManagerLocator mgrLocator);

  /**
   * return index of the first occurrence of input value in the array.
   */
  int Locate(const void* data, CATOmxCollecManagerLocator mgrLocator) const;

  /**
   * Get CATOmxTuple internal structure.
   */
  CATOmxBaseTuple* GetTuple() const;

  /**
   * Build array from a CATOmxTuple.
   */
  void BuildFromTuple(CATOmxBaseTuple* t, CATOmxCollecManagerLocator mgrLocator);

  /**
   * Build array from a "C" array.
   */
  void BuildFromCArray(const void* iArray, int iSize, CATOmxCollecManagerLocator mgrLocator);

  /**
   * return underlying C array.
   */
  const void* GetArray() const;

  /**
   * return underlying C array (writable mode).
   */
  void* GetArrayW(CATOmxCollecManagerLocator mgrLocator);

  /**
   * swap i-th and j-th elements of the array.
   */
  void Swap(int i, int j, CATOmxCollecManagerLocator mgrLocator);

  /**
   * Reverse the array.
   */
  void Reverse(CATOmxCollecManagerLocator mgrLocator);

  /**
   * Compares two arrays.
   */
  int Compare(const CATOmxBaseArray& array, CATOmxCollecManagerLocator mgrLocator) const;


  /**
   * Sort the array.
   */
  void Sort(int(*Cmp)(const void*, const void*), CATOmxCollecManagerLocator mgrLocator);

  /**
   * Sort the array.
   */
  void Sort(void* iContext, int(*iCmp)(void*, const void*, const void*), CATOmxCollecManagerLocator mgrLocator);

  /**
   * Returns an iterator on the array.
   */
  CATOmxBaseIter* Iterator(CATOmxCollecManagerLocator mgrLocator) const;

  /**
   * @see CATOmxArrayOfPointerToIterator
   */
  CATOmxBaseIter* ToPointerIterator(CATOmxCollecManagerLocator mgrLocator) const;

  /**
   * @see CATOmxArrayOfPointerFromIterator
   */
  void FromPointerIterator(CATOmxBaseIter* iter, CATOmxCollecManagerLocator mgrLocator);

  /**
   * Destructor.
   */
  void Die(CATOmxCollecManagerLocator mgrLocator);

  /** Ensure a private version of the collection. */
  int Isolate(CATOmxCollecManagerLocator mgrLocator);

  /** Destructor. */
  inline ~CATOmxBaseArray() {}
protected:
  CATOmxBaseArray();
  CATOmxBaseArray(const CATOmxBaseArray& array);
#ifdef DS_CXX11_SUPPORT_MOVE_SEMANTIC 
  CATOmxBaseArray(CATOmxBaseArray&& array);
  inline CATOmxBaseArray& operator=(CATOmxBaseArray&& array)
  {
    CATOmxBaseTuple* tuple = m_tuple;
    m_tuple = array.m_tuple;
    array.m_tuple = tuple;
    return *this;
  }
#endif
  const void* GetArrayEnd() const;
};

#endif
