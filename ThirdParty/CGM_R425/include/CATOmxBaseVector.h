/**
 * @level Private
 * @usage U1
 * COPYRIGHT DASSAULT SYSTEMES 2003
 */
#ifndef __CATOmxBaseVector_h__
#define __CATOmxBaseVector_h__

#include "CATOmxKernel.h"
#include "CATOmxPortability.h"
#include "CATOmxIter.h"

class CATOmxCollecManager;
template<typename T, CATOmxCollecManagerLocator M>
class CATOmxTuple;

/**
 * see CATOmxVector
 */
class ExportedByCATOmxKernel CATOmxBaseVector
{
public:
  typedef CATOmxTuple<IUnknown*, com_manager> Tuple;
private:
  union Value {
    Tuple* u_tuple;
    char *u_single;
    inline Value() : u_tuple(NULL) {}
  } val;
protected:
  void SetVector(const CATOmxBaseVector &iVect);
  Tuple &_Mutate(int idSize);
  IUnknown* _GetItem(int idx) const;
  IUnknown* _TryGetItem(int idx) const;
  void _SetItem(int idx, void *iObj);
  void _Append(void* iObj);
  void _Steal(void* iObj, int iReserve);
  void _QuickAppend(void* iObj, int iReserve);
  void _Append(const CATOmxBaseVector &iVect);
  void _InsertAt(int idx, void *iObj);
  CATOmxBaseIter* Iterator(CATOmxCollecManager&) const;
  void SetByIterator(CATOmxBaseIter* iter);
  void _Sort(int(*Cmp)(const IUnknown**, const IUnknown**));
  void _Sort(int(*Cmp)(const IUnknown*, const IUnknown*));
  static CATOmxCollecManager &manager();
  int _Locate(const void* iObj) const;
  int _RemoveValue(const void* iObj);
  void _BuildFromCArray(void** iArray, int iSize);
  int _Compare(const CATOmxBaseVector& vect2) const;
#ifdef DS_CXX11_SUPPORT_MOVE_SEMANTIC
  /** move semantics */
  inline CATOmxBaseVector(CATOmxBaseVector&& other) { val.u_tuple = other.val.u_tuple; other.val.u_tuple = NULL; }
  inline CATOmxBaseVector& operator=(CATOmxBaseVector&& other)
  {
    Tuple* t = val.u_tuple;
    val.u_tuple = other.val.u_tuple;
    other.val.u_tuple = t;
    return *this;
  }
#endif
public:
  /**
   * Default constructor.
   */
  inline CATOmxBaseVector() {}

  /**
  * Remove an element of the array.
  * @param index
  *   the index to remove
  * @param count
  *   the number of elements to remove (optional, default is one)
  * @param keepAllocation
  *   if true, do not reallocate internal data (optional, default is false)
  */
  void RemoveAt(int index, int count = 1, CATBoolean keepAllocation = FALSE);
  void RemovePosition(int index);

  /**
   * RemoveAll item in collection.
   * You can specify iKeepAlloc=TRUE to avoid free of used memory.
   */
  void RemoveAll();
  void RemoveAll(CATBoolean iKeepAlloc);

  /**
   * Collection size.
   * @return the collection size.
   */
  int Size() const;

  /**
   * Returns TRUE if the collection is empty.
   */
  inline int IsEmpty() const { return !Size(); }

  /**
   * Remove all NULL pointer in the collection.
   */
  void PackNull();

  /**
   * Gives access to underlying array.
   * DO NOT USE.
   */
  void GetRawInfos(void*& iBuffer, int& oSize, void**& oArray) const;

  /**
   * pre-allocate iReserve items.
   */
  void Reserve(int iReserve);

  /**
   * Reverse the vector
   */
  void Reverse();

  /**
  * Resize vector to given size.
  * @param iNewSize the new size.
  */
  void FixSize(int iSize);
  inline void Resize(int iSize) { FixSize(iSize); }

  /** internal usage */
  void SetTuple(Tuple *newT);

  /** Ensure a private version of the collection. */
  int Isolate();

  /** Destructor.*/
  ~CATOmxBaseVector();
};

#endif

