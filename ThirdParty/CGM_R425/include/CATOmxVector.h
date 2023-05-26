/**
 * @level Private
 * @usage U1
 * COPYRIGHT DASSAULT SYSTEMES 2003
 */
#ifndef __CATOmxVector_h__
#define __CATOmxVector_h__

#include "CATOmxBaseVector.h"
#include "CATOmxDeprecated.h"

template<class Type> class CATOmxList;

/**
 * This class implements an array of IUnknown derived pointers.
 * Pointers are AddRef'ed when they enter the collection and Release'd as soon as they leave it.
 *
 * It implements an optimization on collections of 1 object (no allocation)
 *
 * It implements Copy-On-Write feature.
 *
 * Notice you will find half of the available methods here, half on base class: CATOmxBaseVector
 *
 * @href http://osmwebdsy/wiki/index.php/CATOmxVector_Usage
 */
template<class Type>
class CATOmxVector : public CATOmxBaseVector
{
  OMX_STATIC_ASSERT_CLASS_SCOPE(std::is_class<Type>::value, "CATOmxVector must be used only on IUnknown descendants")
    //FIXME: should assert Type inherits from IUnknown but could not find any place where Type is known and not only forwarded.
public:
  typedef Type* ValueType;
  typedef int KeyType;

  typedef CATOmxIter<Type> IteratorType;
  typedef CATOmxIter<const Type> ConstIteratorType;

  /**
   * Default constructor.
   */
  inline CATOmxVector() {}

  /**
   * Copy constructor.
   */
  inline CATOmxVector(const CATOmxVector<Type>&iList) { SetVector(iList); }

  /**
   * Copy operator.
   */
  inline CATOmxVector<Type>& operator=(const CATOmxVector<Type>&iList) { SetVector(iList); return *this; }

  /**
   * Build the Vector using an iterator.
   * @see CATOmxIter.
   * @param iter the iterator (warning, despite const type specifier, iter is emptied)
   */
  inline CATOmxVector<Type>(const IteratorType& iter) { SetByIterator(const_cast<IteratorType&>(iter).PrivateStrip()); }

  /**
   * Build the collection using an iterator.
   * @see CATOmxIter.
   * @param iter the iterator (warning, despite const type specifier, iter is emptied)
   */
  inline CATOmxVector<Type>& operator=(const IteratorType& iter) { SetByIterator(const_cast<IteratorType&>(iter).PrivateStrip()); return *this; }

  /**
   * Returns an iterator on the vector.
   * @see CATOmxIter.
   */
  inline IteratorType Iterator() const { return IteratorType(CATOmxBaseVector::Iterator(manager())); }
  /** Collection of pointer (iterator are not distinguishable). */
  inline ConstIteratorType ConstIterator() const { return IteratorType(CATOmxBaseVector::Iterator(manager())); }

  /**
   * Returns i-th element of the vector.
   * @param i must be in [0;Size()[.
   */
  inline ValueType operator[](KeyType i) const { return reinterpret_cast<ValueType> (_GetItem(i)); }
  inline ValueType GetItem(KeyType i) const { return this->operator[](i); }

  /**
   * Returns i-th element of the vector or NULL if outside range.
   * @param i must be in [0;Size()[.
   */
  inline ValueType TryGetItem(KeyType i) const { return reinterpret_cast<ValueType>(_TryGetItem(i)); }
  /*
   * Set i-th element of the vector .
   * @param i must be in [0;Size()[.
   */
  inline void Set(KeyType i, ValueType iObj) { _SetItem(i, iObj); }
  inline void SetItem(KeyType i, ValueType iObj) { Set(i, iObj); }

  /**
   * Append an item to the vector.
   */
  inline void Append(ValueType iObj) { _Append(iObj); }

  /**
   * Append an item to the vector and opportunistically reserve max size
   * of the vector in order to reduce reallocations.
   */
  inline void QuickAppend(ValueType iObj, int iReserve) { _QuickAppend(iObj, iReserve); }

  /**
   * Append a vector.
   */
  inline void Append(const CATOmxVector& iVect) { _Append(iVect); }

  /**
   * Append an item to the vector without AddRef'ing it.
   * for example you can replace:
   *   T* item = new T;
   *   vect.Append(item);
   *   item->Release();
   * with
   *   vect.Steal(new T);
   *
   */
  inline void Steal(ValueType iObj, int iReserve = 0) { _Steal(iObj, iReserve); }

  /**
   * Insert an item in the vector.
   * @param i must be in [0;Size()].
   */
  inline void InsertAt(KeyType i, ValueType iObj) { _InsertAt(i, iObj); }

  /**
   * Locate an item in the vector.
   * @param iObj the item to find.
   * @return the found position, -1 if not found
   */
  inline KeyType Locate(const Type*iObj) const { return _Locate(iObj); }


  /**
   * Removes the first occurrence of iObj in the vector.
   * returns the position where iObj was, -1 if not found.
   */
  inline KeyType RemoveValue(const Type* iObj) { return _RemoveValue(iObj); }

  /**
   * Sort vector (in ascending order).
   * @param iCompF
   *   A strcmp like comparison function.
   *   if NULL, items are sorted by address.
   */
  inline void Sort(int(*iCompF)(const Type*, const Type*) = NULL) { _Sort((int(*)(const IUnknown*, const IUnknown*))iCompF); }

  /**
   * @deprecated
   * Prefer previous version.
   */
  inline OMX_DEPRECATED("Use other Sort method") void Sort(int(*iCompF)(const Type**, const Type**)) { _Sort((int(*)(const IUnknown**, const IUnknown**))iCompF); }

  /**
   * Build a vector from an array of iSize items.
   */
  inline void BuildFromCArray(Type const*const* iArray, int iSize) { _BuildFromCArray((void**)iArray, iSize); }

  /**Cast to CATOmxList*/
  inline operator CATOmxList<Type>&() { return *(CATOmxList<Type>*)this; }
  inline operator const CATOmxList<Type>& () const { return *(const CATOmxList<Type>*)this; }

  /** Comparison (strcmp style). */
  inline int Compare(const CATOmxVector<Type>& vect2) const { return CATOmxBaseVector::_Compare(vect2); }

  /** Comparison operators. */
  inline CATBoolean operator==(const CATOmxVector<Type>& vect2) const { return 0 == Compare(vect2); }
  inline CATBoolean operator!=(const CATOmxVector<Type>& vect2) const { return !this->operator==(vect2); }

  /** range for support */
  inline CATOmxSTLIter<Type> begin() const { return CATOmxSTLIter<Type>(Iterator()); }
  inline CATOmxSTLIter<Type> end()   const { return CATOmxSTLIter<Type>(); }

#if OMX_CXX11 == 1
  /** move semantics */
  inline CATOmxVector(CATOmxVector<Type>&& other) :CATOmxBaseVector(std::move(other)) {}
  inline CATOmxVector<Type>& operator=(CATOmxVector<Type>&& other) { return static_cast<CATOmxVector<Type>&>(this->CATOmxBaseVector::operator=(std::move(other))); }

  /** initializer list */
  inline CATOmxVector(std::initializer_list<Type*> list)
  {
    int size = (int)list.size();
    for (Type* item : list)
      QuickAppend(item, size);
  }
  inline CATOmxVector<Type>& operator=(std::initializer_list<Type*> list) { return this->operator=(CATOmxVector<Type>(list)); }
#endif

  /** std::back_inserter support */
  typedef Type value_type; //the actual type is Type& but that causes overloading issue in back_inserter between & and &&
  inline void push_back(const Type& item) { Append(const_cast<Type*>(&item)); } //const required because of previous hack
};

/**
 * CATOmxVector<*> manager.
 */
ExportedByCATOmxKernel CATOmxCollecManager& vector_manager();

#endif
