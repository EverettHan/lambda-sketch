// COPYRIGHT DASSAULT SYSTEMES 2008
//=============================================================================
//
// CATCDSArray:
//   Macro for declaring dynamic array of elements class.
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Oct 2008  Creation                         Vladislav Kornienko
//=============================================================================

#ifndef CATCDSArray_h
#define CATCDSArray_h

#include "CATCDSCPlusPlusVersions.h"

#include <cstdlib>
#include <new>
#include <iostream.h>

#ifdef CPP11_AVAILABLE
#include "CATCDSSpan.h"
#include "CATCDSReallocableTrait.h"

#include <utility>
#include <algorithm>
#endif

#if defined(CATIAR421)
#include <initializer_list>
#endif

#include "CATCDSAssert.h"
#include "CATCDSBoolean.h"
#include "CATCDSInline.h"
#include "CATCDSMath.h"
#include "CATCDSUtilities.h"

class CATMemAllocator;

template<class T> class CATCDSArrayDefaultStaticSize : public std::integral_constant<int, 0> {};
template<> class CATCDSArrayDefaultStaticSize<void*> : public std::integral_constant<int, 16> {};
template<class T> class CATCDSArrayDefaultStaticSize<T*> : public std::integral_constant<int, 16> {};
template<> class CATCDSArrayDefaultStaticSize<int> : public std::integral_constant<int, 32> {};
template<> class CATCDSArrayDefaultStaticSize<CATCDSBoolean> : public std::integral_constant<int, 64> {};
template<> class CATCDSArrayDefaultStaticSize<double> : public std::integral_constant<int, 36> {};

template<class T> class CATCDSArray;

#ifdef CPP11_AVAILABLE
// reallocable specialization for CATCDSArray (non static)
namespace cds
{
  template<class T> class is_reallocable<CATCDSArray<T>> : public std::integral_constant<bool, (CATCDSArrayDefaultStaticSize<T>::value == 0)> {};
}
#endif

#ifdef CPP11_AVAILABLE
#include <type_traits>
#elif !defined(_MSC_VER)||_MSC_VER<1700
namespace std
{
  template<class T>
  struct remove_const
  {
    typedef T type;
  };

  template<class T>
  struct remove_const<T const>
  {
    typedef T type;
  };
}
#endif

template<class T, unsigned int StaticSize>
class CDSSTLVectorAllocator
{
protected:
  CDSSTLVectorAllocator();
  ~CDSSTLVectorAllocator();
  CDSSTLVectorAllocator(CDSSTLVectorAllocator const& iSTLVector);
  CDSSTLVectorAllocator& operator=(CDSSTLVectorAllocator const& iSTLVector);
#ifdef CPP11_AVAILABLE
  CDSSTLVectorAllocator(CDSSTLVectorAllocator&& iSTLVector);
  CDSSTLVectorAllocator& operator=(CDSSTLVectorAllocator&& iSTLVector);
#endif
#if defined(CATIAR421)
  CDSSTLVectorAllocator(std::initializer_list<T> iList);
#endif

  void reserve(int iSize);

  void swap(CDSSTLVectorAllocator& iSTLVector);

protected:
  T _aStaticVector[StaticSize]; // En 1er pour détecter les accès frauduleux à -1
  int _size, _capacity;
  T* _vector;

  template<class T2, unsigned int StaticSize2>
  friend class CDSSTLVectorAllocator;
};

template<class T, unsigned int StaticSize>
CDSSTLVectorAllocator<T, StaticSize>::CDSSTLVectorAllocator()
  : _size(0)
  , _capacity(StaticSize)
  , _vector(_aStaticVector)
{
}

template<class T, unsigned int StaticSize>
CDSSTLVectorAllocator<T, StaticSize>::~CDSSTLVectorAllocator()
{
#ifdef CPP11_AVAILABLE
  if CDS_CONSTEXPR (!std::is_trivially_destructible<T>::value)
#endif
  {
    for (int i = 0; i < _size; i++)
    {
      _vector[i].~T();
    }
  }

  if (_vector != _aStaticVector)
    ::operator delete(static_cast<void*>(_vector)); 
}

template<class T, unsigned int StaticSize>
CDSSTLVectorAllocator<T, StaticSize>::CDSSTLVectorAllocator(CDSSTLVectorAllocator const& iSTLVector)
  : _size(0)
  , _capacity(StaticSize)
  , _vector(_aStaticVector)
{
  *this = iSTLVector;
}

template<class T, unsigned int StaticSize>
CDSSTLVectorAllocator<T, StaticSize>& CDSSTLVectorAllocator<T, StaticSize>::operator=(CDSSTLVectorAllocator const& iSTLVector)
{
  if (this != &iSTLVector)
  {    
    if (iSTLVector._size < _size)
    {
      // Remove useless elements   
#ifdef CPP11_AVAILABLE
      if CDS_CONSTEXPR (!std::is_trivially_destructible<T>::value)
#endif
      {
        for (int i = iSTLVector._size; i < _size; i++)
          _vector[i].~T();
      }
      _size = iSTLVector._size;
      // Copy new elements
#ifdef CPP11_AVAILABLE
      std::copy_n(iSTLVector._vector, _size, _vector);
#else
      for (int i = 0; i < _size; i++)
        _vector[i] = iSTLVector._vector[i];
#endif
    }
#ifdef CPP11_AVAILABLE
    else if (std::is_move_assignable<T>::value && !std::is_trivially_move_assignable<T>::value && _capacity < iSTLVector._size)
    {
      // Reserve necessary size
      reserve(iSTLVector._size);
      // Create new elements
#ifdef CPP11_AVAILABLE
      if CDS_CONSTEXPR (std::is_trivially_copy_assignable<T>::value)
      {
        std::copy_n(iSTLVector._vector, iSTLVector._size, _vector);
      }
      else
#endif
      {
#ifdef CPP11_AVAILABLE
        std::copy_n(iSTLVector._vector, _size, _vector);
#else
        for (int i = 0; i < _size; i++)
          _vector[i] = iSTLVector._vector[i];
#endif
        for (int i = _size; i < iSTLVector._size; i++)
          new (_vector + i) T(iSTLVector._vector[i]);
      }
      _size = iSTLVector._size;
    }
#endif
    else
    {
      // Remove current elements
#ifdef CPP11_AVAILABLE
      if CDS_CONSTEXPR (!std::is_trivially_destructible<T>::value)
#endif
      {
        for (int i = 0; i < _size; i++)
          _vector[i].~T();
      }
      _size = 0;

      // Reserve necessary size
      reserve(iSTLVector._size);

      // Create new copied elements
#ifdef CPP11_AVAILABLE
      if CDS_CONSTEXPR (std::is_trivially_copy_assignable<T>::value)
      {
        std::copy_n(iSTLVector._vector, iSTLVector._size, _vector);
      }
      else
#endif
      {
        for (int i = 0; i < iSTLVector._size; i++)
          new (_vector + i) T(iSTLVector._vector[i]);
      }
      _size = iSTLVector._size;
    }
  }
  return *this;
}

#ifdef CPP11_AVAILABLE
template<class T, unsigned int StaticSize>
CDSSTLVectorAllocator<T, StaticSize>::CDSSTLVectorAllocator(CDSSTLVectorAllocator&& iSTLVector)
  : _size(0)
  , _capacity(StaticSize)
  , _vector(_aStaticVector)
{
  *this = std::move(iSTLVector);
}

template<class T, unsigned int StaticSize>
CDSSTLVectorAllocator<T, StaticSize>& CDSSTLVectorAllocator<T, StaticSize>::operator=(CDSSTLVectorAllocator&& iSTLVector)
{
  if (iSTLVector._vector == iSTLVector._aStaticVector)
  {
    // Apply standard copy allocation since move is not possible
    operator=(iSTLVector);
  }
  else if(_vector == _aStaticVector)
  {
    // Delete old
#ifdef CPP11_AVAILABLE
    if CDS_CONSTEXPR (!std::is_trivially_destructible<T>::value)
#endif
    {
      for (int i = 0; i < _size; i++)
        _vector[i].~T();
    }
    _size = 0;

    // Move the data
    _size = iSTLVector._size;
    _capacity = iSTLVector._capacity;
    _vector = iSTLVector._vector;

    // Reset moved vector
    iSTLVector._size = 0;
    iSTLVector._capacity = StaticSize;
    iSTLVector._vector = iSTLVector._aStaticVector;
  }
  else
  {
    std::swap(_vector, iSTLVector._vector);
    std::swap(_size, iSTLVector._size);
    std::swap(_capacity, iSTLVector._capacity);
  }
  return *this;
}
#endif

#if defined(CATIAR421)
template<class T, unsigned int StaticSize>
CDSSTLVectorAllocator<T, StaticSize>::CDSSTLVectorAllocator(std::initializer_list<T> iList)
  : _size(0)
  , _capacity(StaticSize)
  , _vector(_aStaticVector)
{
  reserve(static_cast<int>(iList.size()));
  for (auto iterator = iList.begin(), end = iList.end(); iterator != end; ++iterator, ++_size)
    new (_vector + _size) T(*iterator);
}
#endif

template<class T, unsigned int StaticSize>
void CDSSTLVectorAllocator<T, StaticSize>::reserve(int iSize)
{
  if (_capacity < iSize)
  {
    if (_capacity == StaticSize)
    {
      _capacity = iSize;
    }
    else
    {
      do
      {
        _capacity *= 2;
      } while (_capacity < iSize);
    }
    T* aVector = (T*)::operator new(_capacity * sizeof(T));
#ifdef CPP11_AVAILABLE
    if CDS_CONSTEXPR (std::is_trivially_copy_assignable<T>::value)
    {
      std::copy_n(_vector, _size, aVector);
      if CDS_CONSTEXPR (!std::is_trivially_destructible<T>::value)
      {
        for (int i = 0; i < _size; i++)
          _vector[i].~T();
      }
    }
    else if CDS_CONSTEXPR(cds::is_reallocable<T>::value)
    {
      memcpy(aVector, _vector, _size * sizeof(T));
    }
    else
#endif
    {
      for (int i = 0; i < _size; i++)
      {
        new (aVector + i) T(CDS_MOVE(_vector[i]));
#ifdef CPP11_AVAILABLE
        if CDS_CONSTEXPR (!std::is_trivially_destructible<T>::value)
#endif
          _vector[i].~T();
      }
    }
    if (_vector != _aStaticVector)
      ::operator delete(static_cast<void*>(_vector));
    _vector = aVector;
  }
}

template<class T, unsigned int StaticSize>
void CDSSTLVectorAllocator<T, StaticSize>::swap(CDSSTLVectorAllocator& iSTLVector)
{
  if (iSTLVector._vector == iSTLVector._aStaticVector && _vector == _aStaticVector)
  {
    int i;
    int minSize = CATCDSMin(_size, iSTLVector._size);
    for (i = 0; i < minSize; i++)
      CATCDSSwap(_aStaticVector[i], iSTLVector._aStaticVector[i]);
    for (; i < _size; i++)
    {
      new (iSTLVector._aStaticVector + i) T(CDS_MOVE(_aStaticVector[i]));
#ifdef CPP11_AVAILABLE
      if CDS_CONSTEXPR (!std::is_trivially_destructible<T>::value)
#endif
        _aStaticVector[i].~T();
    }
    for (; i < iSTLVector._size; i++)
    {
      new (_aStaticVector + i) T(CDS_MOVE(iSTLVector._aStaticVector[i]));
#ifdef CPP11_AVAILABLE
      if CDS_CONSTEXPR (!std::is_trivially_destructible<T>::value)
#endif
        iSTLVector._aStaticVector[i].~T();
    }
    CATCDSSwap(_size, iSTLVector._size);
    CATCDSSwap(_capacity, iSTLVector._capacity);
  }
  else
  {
    int size = _size, capacity = _capacity;
    T* vector = _vector;
    _size = iSTLVector._size;
    _capacity = iSTLVector._capacity;
    if (iSTLVector._vector == iSTLVector._aStaticVector)
    {
      for (int i = 0; i < iSTLVector._size; i++)
      {
        new (_aStaticVector + i) T(CDS_MOVE(iSTLVector._aStaticVector[i]));
#ifdef CPP11_AVAILABLE
        if CDS_CONSTEXPR (!std::is_trivially_destructible<T>::value)
#endif
          iSTLVector._aStaticVector[i].~T();
      }
      _vector = _aStaticVector;
    }
    else
      _vector = iSTLVector._vector;
    iSTLVector._size = size;
    iSTLVector._capacity = capacity;
    if (vector == _aStaticVector)
    {
      for (int i = 0; i < iSTLVector._size; i++)
      {
        new (iSTLVector._aStaticVector + i) T(CDS_MOVE(_aStaticVector[i]));
#ifdef CPP11_AVAILABLE
        if CDS_CONSTEXPR (!std::is_trivially_destructible<T>::value)
#endif
          _aStaticVector[i].~T();
      }
      iSTLVector._vector = iSTLVector._aStaticVector;
    }
    else
      iSTLVector._vector = vector;
  }
}

template<class T>
class CDSSTLVectorAllocator<T, 0>
{
protected:
  CDSSTLVectorAllocator();
  ~CDSSTLVectorAllocator();
  CDSSTLVectorAllocator(CDSSTLVectorAllocator const& iSTLVector);
  CDSSTLVectorAllocator& operator=(CDSSTLVectorAllocator const& iSTLVector);
#ifdef CPP11_AVAILABLE
  CDSSTLVectorAllocator(CDSSTLVectorAllocator&& iSTLVector);
  CDSSTLVectorAllocator& operator=(CDSSTLVectorAllocator&& iSTLVector);
#endif
#if defined(CATIAR421)
  CDSSTLVectorAllocator(std::initializer_list<T> iList);
#endif

  void reserve(int iSize);

  void swap(CDSSTLVectorAllocator& iSTLVector);

protected:
  int _size, _capacity;
  T* _vector;

  template<class T2, unsigned int StaticSize2>
  friend class CDSSTLVectorAllocator;
};

template<class T>
CDSSTLVectorAllocator<T, 0>::CDSSTLVectorAllocator()
  : _size(0)
  , _capacity(0)
  , _vector(0)
{
}

template<class T>
CDSSTLVectorAllocator<T, 0>::~CDSSTLVectorAllocator()
{
#ifdef CPP11_AVAILABLE
  if CDS_CONSTEXPR (!std::is_trivially_destructible<T>::value)
#endif
  {
    for (int i = 0; i < _size; i++)
    {
      _vector[i].~T();
    }
  }

  ::operator delete(static_cast<void*>(_vector));
}

template<class T>
CDSSTLVectorAllocator<T, 0>::CDSSTLVectorAllocator(CDSSTLVectorAllocator const& iSTLVector)
  : _size(0)
  , _capacity(0)
  , _vector(0)
{
  *this = iSTLVector;
}

template<class T>
CDSSTLVectorAllocator<T, 0>& CDSSTLVectorAllocator<T, 0>::operator=(CDSSTLVectorAllocator const& iSTLVector)
{
  if (this != &iSTLVector)
  {
    if (iSTLVector._size < _size)
    {
      // Remove useless elements   
#ifdef CPP11_AVAILABLE
      if CDS_CONSTEXPR (!std::is_trivially_destructible<T>::value)
#endif
      {
        for (int i = iSTLVector._size; i < _size; i++)
          _vector[i].~T();
      }
      _size = iSTLVector._size;
      // Copy new elements
#ifdef CPP11_AVAILABLE
      std::copy_n(iSTLVector._vector, _size, _vector);
#else
      for (int i = 0; i < _size; i++) {
        _vector[i] = iSTLVector._vector[i];
      }
#endif
    }
#ifdef CPP11_AVAILABLE
    else if(std::is_move_assignable<T>::value && !std::is_trivially_move_assignable<T>::value && _capacity < iSTLVector._size)
    {
      // Reserve necessary size
      reserve(iSTLVector._size);
      // Create new elements
#ifdef CPP11_AVAILABLE
      if CDS_CONSTEXPR (std::is_trivially_copy_assignable<T>::value)
      {
        std::copy_n(iSTLVector._vector, iSTLVector._size, _vector);
      }
      else
#endif
      {
#ifdef CPP11_AVAILABLE
         std::copy_n(iSTLVector._vector, _size, _vector);
#else
        for (int i = 0; i < _size; i++)
          _vector[i] = iSTLVector._vector[i];     
#endif
        for (int i = _size; i < iSTLVector._size; i++)
          new (_vector + i) T(iSTLVector._vector[i]);
      }
      _size = iSTLVector._size;
    }
#endif
    else
    {
      // Remove current elements
#ifdef CPP11_AVAILABLE
      if CDS_CONSTEXPR (!std::is_trivially_destructible<T>::value)
#endif
      {
        for (int i = 0; i < _size; i++)
          _vector[i].~T();
      }
      _size = 0;

      // Reserve necessary size
      reserve(iSTLVector._size);

      // Create new elements
#ifdef CPP11_AVAILABLE
      if CDS_CONSTEXPR (std::is_trivially_copy_assignable<T>::value)
      {
        std::copy_n(iSTLVector._vector, iSTLVector._size, _vector);
      }
      else
#endif
      {
        for (int i = 0; i < iSTLVector._size; i++)
          new (_vector + i) T(iSTLVector._vector[i]);
      }

      _size = iSTLVector._size;
    }
  }
  return *this;
}

#ifdef CPP11_AVAILABLE
template<class T>
CDSSTLVectorAllocator<T, 0>::CDSSTLVectorAllocator(CDSSTLVectorAllocator&& iSTLVector)
  : _size(0)
  , _capacity(0)
  , _vector(0)
{
  *this = std::move(iSTLVector);
}

template<class T>
CDSSTLVectorAllocator<T, 0>& CDSSTLVectorAllocator<T, 0>::operator=(CDSSTLVectorAllocator&& iSTLVector)
{
  if (this != &iSTLVector)
  {
    std::swap(_size, iSTLVector._size);
    std::swap(_capacity, iSTLVector._capacity);
    std::swap(_vector, iSTLVector._vector);
  }
  return *this;
}
#endif

#if defined(CATIAR421)
template<class T>
CDSSTLVectorAllocator<T, 0>::CDSSTLVectorAllocator(std::initializer_list<T> iList)
  : _size(0)
  , _capacity(0)
  , _vector(0)
{
  reserve(static_cast<int>(iList.size()));
  for (auto iterator = iList.begin(), end = iList.end(); iterator != end; ++iterator, ++_size)
    new (_vector + _size) T(*iterator);
}
#endif

template<class T>
void CDSSTLVectorAllocator<T, 0>::reserve(int iSize)
{
  if (_capacity < iSize)
  {
    if (_capacity == 0)
    {
      _capacity = iSize;
    }
    else
    {
      do
      {
        _capacity *= 2;
      } while (_capacity < iSize);
    }
    T* aVector = (T*)::operator new(_capacity * sizeof(T));
#ifdef CPP11_AVAILABLE
    if CDS_CONSTEXPR (std::is_trivially_copy_assignable<T>::value)
    {
      std::copy_n(_vector, _size, aVector);
      if CDS_CONSTEXPR(!std::is_trivially_destructible<T>::value)
      {
        for (int i = 0; i < _size; i++)
          _vector[i].~T();
      }
    }
    else if CDS_CONSTEXPR (cds::is_reallocable<T>::value)
    {
      memcpy(aVector, _vector, _size * sizeof(T));
    }
    else
#endif
    {
      for (int i = 0; i < _size; i++)
      {
        new (aVector + i) T(CDS_MOVE(_vector[i]));
#ifdef CPP11_AVAILABLE
        if CDS_CONSTEXPR (!std::is_trivially_destructible<T>::value)
#endif
          _vector[i].~T();
      }
    }
    ::operator delete(static_cast<void*>(_vector));
    _vector = aVector;
  }
}

template<class T>
void CDSSTLVectorAllocator<T, 0>::swap(CDSSTLVectorAllocator& iSTLVector)
{
#ifdef CPP11_AVAILABLE
  std::swap(_size, iSTLVector._size);
  std::swap(_capacity, iSTLVector._capacity);
  std::swap(_vector, iSTLVector._vector);
#else
  int tmp = _size;
  _size = iSTLVector._size;
  iSTLVector._size = tmp;
  tmp = _capacity;
  _capacity = iSTLVector._capacity;
  iSTLVector._capacity = tmp;
  T *tmpv = _vector;
  _vector = iSTLVector._vector;
  iSTLVector._vector = tmpv;
#endif
}

template<class T, unsigned int StaticSize = CATCDSArrayDefaultStaticSize<T>::value>
class CDSSTLVector : public CDSSTLVectorAllocator<T, StaticSize>
{
public:
  using CDSSTLVectorAllocator<T, StaticSize>::_size;
  using CDSSTLVectorAllocator<T, StaticSize>::_capacity;
  using CDSSTLVectorAllocator<T, StaticSize>::_vector;

  CDSSTLVector();

  CDSSTLVector(int iSize);
  CDSSTLVector(int iSize, T const& iT);

  CDSSTLVector(T const* iStart, T const* iEnd);

  CDSSTLVector(CDSSTLVector const& iSTLVector);

  CDSSTLVector& operator=(CDSSTLVector const& iSTLVector);

#ifdef CPP11_AVAILABLE
  CDSSTLVector(CDSSTLVector&& iSTLVector);

  CDSSTLVector& operator=(CDSSTLVector&& iSTLVector);
#endif

#if defined(CATIAR421)
  CDSSTLVector(std::initializer_list<T> iList);
#endif

  int size() const;

  int capacity() const;

  void reserve(int iSize);

  void resize(int iSize);
  void resize(int iSize, T const& iValue);

  T& operator[](int iIdx);
  const T& operator[](int iIdx) const;

  void push_back(const T& iElement);

#ifdef CPP11_AVAILABLE
  void push_back(T&& iElement);

  template<class... Args>
  void emplace_back(Args&&... iArgs);
#endif

  void insert(T* iIterator, T const& iElement);

  template<class Iterator>
  void insert(T* iIterator, Iterator iStart, Iterator iEnd)
  {
    int idx = static_cast<int>(iIterator - _vector);
    int nAdded = static_cast<int>(iEnd - iStart);
    reserve(_size + nAdded);
    int i, n = nAdded < _size - idx ? nAdded : _size - idx, m = nAdded - n;
    for (i = 1; i <= n; i++)
    {
      new (_vector + _size + nAdded - i) T(CDS_MOVE(_vector[_size - i]));
    }
    for (i = 1; i <= m; i++)
    {
      new (_vector + _size + m - i) T(iEnd[-i]);
    }
    if (m)
    {
      for (i = 0; i < n; i++)
      {
        _vector[_size - n + i] = iStart[i];
      }
    }
    else
    {
      for (i = _size - 1; i >= idx + nAdded; i--)
        _vector[i] = CDS_MOVE(_vector[i - nAdded]);
      for (i = 0; i < nAdded; i++)
        _vector[idx + i] = iStart[i];
    }
    _size += nAdded;
  }

  T* begin();

  T* end();

  T const* begin() const;

  T const* end() const;

  void erase(T* iIterator);
  void erase(T* iFirst, T* iLast);
  void erase_last();

  void clear();

  bool operator==(CDSSTLVector const& iSTLVector) const;
  bool operator!=(CDSSTLVector const& iSTLVector) const;
  bool operator<(CDSSTLVector const& iSTLVector) const;
  bool operator<=(CDSSTLVector const& iSTLVector) const;
  bool operator>(CDSSTLVector const& iSTLVector) const;
  bool operator>=(CDSSTLVector const& iSTLVector) const;

  void swap(CDSSTLVector& iSTLVector);

  void reverse();
};

template<class T, unsigned int StaticSize>
CDSSTLVector<T, StaticSize>::CDSSTLVector()
  : CDSSTLVectorAllocator<T, StaticSize>()
{
}

template<class T, unsigned int StaticSize>
CDSSTLVector<T, StaticSize>::CDSSTLVector(int iSize)
  : CDSSTLVectorAllocator<T, StaticSize>()
{
  resize(iSize);
}

template<class T, unsigned int StaticSize>
CDSSTLVector<T, StaticSize>::CDSSTLVector(int iSize, T const& iT)
  : CDSSTLVectorAllocator<T, StaticSize>()
{
  resize(iSize, iT);
}

template<class T, unsigned int StaticSize>
CDSSTLVector<T, StaticSize>::CDSSTLVector(T const* iStart, T const* iEnd)
  : CDSSTLVectorAllocator<T, StaticSize>()
{
  int size = static_cast<int>(iEnd - iStart);
  CATCDSAssert(size >= 0);
  reserve(size);
#ifdef CPP11_AVAILABLE
  if (std::is_trivially_copy_assignable<T>::value)
  {
    std::copy_n(iStart, size, _vector);
  }
  else
#endif
  {
    for (int i = 0; i < size; i++)
      new (_vector + i) T(iStart[i]);
  }
  _size = size;
}

template<class T, unsigned int StaticSize>
CDSSTLVector<T, StaticSize>::CDSSTLVector(CDSSTLVector const& iSTLVector)
  : CDSSTLVectorAllocator<T, StaticSize>(iSTLVector)
{
}

template<class T, unsigned int StaticSize>
CDSSTLVector<T, StaticSize>& CDSSTLVector<T, StaticSize>::operator=(CDSSTLVector const& iSTLVector)
{
  CDSSTLVectorAllocator<T, StaticSize>::operator=(iSTLVector);
  return *this;
}

#ifdef CPP11_AVAILABLE
template<class T, unsigned int StaticSize>
CDSSTLVector<T, StaticSize>::CDSSTLVector(CDSSTLVector&& iSTLVector)
  : CDSSTLVectorAllocator<T, StaticSize>(std::move(iSTLVector))
{
}

template<class T, unsigned int StaticSize>
CDSSTLVector<T, StaticSize>& CDSSTLVector<T, StaticSize>::operator=(CDSSTLVector&& iSTLVector)
{
  CDSSTLVectorAllocator<T, StaticSize>::operator=(std::move(iSTLVector));
  return *this;
}
#endif

#if defined(CATIAR421)
template<class T, unsigned int StaticSize>
CDSSTLVector<T, StaticSize>::CDSSTLVector(std::initializer_list<T> iList)
  : CDSSTLVectorAllocator<T, StaticSize>(iList)
{
}
#endif

template<class T, unsigned int StaticSize>
int CDSSTLVector<T, StaticSize>::size() const
{
  return _size;
}

template<class T, unsigned int StaticSize>
int CDSSTLVector<T, StaticSize>::capacity() const
{
  return _capacity;
}

template<class T, unsigned int StaticSize>
void CDSSTLVector<T, StaticSize>::reserve(int iSize)
{
  CDSSTLVectorAllocator<T, StaticSize>::reserve(iSize);
}

template<class T, unsigned int StaticSize>
void CDSSTLVector<T, StaticSize>::resize(int iSize)
{
  if (iSize > _size)
  {
    reserve(iSize);
#ifdef CPP11_AVAILABLE
    if CDS_CONSTEXPR (std::is_trivially_copy_assignable<T>::value)
    {
      std::fill(_vector + _size, _vector + iSize, T());
    }
    else
#endif
    {
      for (int i = _size; i < iSize; i++)
        new (_vector + i) T();
    }
  }
  else
  {
#ifdef CPP11_AVAILABLE
    if CDS_CONSTEXPR (!std::is_trivially_destructible<T>::value)
#endif
    {
      for (int i = iSize; i < _size; i++)
        _vector[i].~T();
    }
  }
  _size = iSize;
}

template<class T, unsigned int StaticSize>
void CDSSTLVector<T, StaticSize>::resize(int iSize, T const& iValue)
{
  if (iSize > _size)
  {
    reserve(iSize);
#ifdef CPP11_AVAILABLE
    if CDS_CONSTEXPR (std::is_trivially_copy_assignable<T>::value)
    {
      std::fill(_vector + _size, _vector + iSize, iValue);
    }
    else
#endif
    {
      for (int i = _size; i < iSize; i++)
        new (_vector + i) T(iValue);
    }
  }
  else
  {
#ifdef CPP11_AVAILABLE
    if CDS_CONSTEXPR (!std::is_trivially_destructible<T>::value)
#endif
    {
      for (int i = iSize; i < _size; i++)
        _vector[i].~T();
    }
  }
  _size = iSize;
}

template<class T, unsigned int StaticSize>
T& CDSSTLVector<T, StaticSize>::operator[](int iIdx)
{
  return _vector[iIdx];
}

template<class T, unsigned int StaticSize>
T const& CDSSTLVector<T, StaticSize>::operator[](int iIdx) const
{
  return _vector[iIdx];
}

template<class T, unsigned int StaticSize>
void CDSSTLVector<T, StaticSize>::push_back(const T& iElement)
{
  reserve(_size + 1);
  new (_vector + _size) T(iElement);
  ++_size;
}

#ifdef CPP11_AVAILABLE
template<class T, unsigned int StaticSize>
void CDSSTLVector<T, StaticSize>::push_back(T&& iElement)
{
  reserve(_size + 1);
  new (_vector + _size) T(std::move(iElement));
  ++_size;
}

template<class T, unsigned int StaticSize>
template<class... Args>
void CDSSTLVector<T, StaticSize>::emplace_back(Args&&... iArgs)
{
  reserve(_size + 1);
  new (_vector + _size) T(std::forward<Args>(iArgs)...);
  ++_size;
}
#endif

template<class T, unsigned int StaticSize>
void CDSSTLVector<T, StaticSize>::insert(T* iIterator, T const& iElement)
{
  int idx = static_cast<int>(iIterator - _vector);
  reserve(_size + 1);
  if (idx < _size)
  {
    new (_vector + _size) T(CDS_MOVE(_vector[_size - 1]));
    for (int i = _size - 1; i > idx; i--)
      _vector[i] = CDS_MOVE(_vector[i - 1]);
    _vector[idx] = iElement;
  }
  else
    new (_vector + _size) T(iElement);
  ++_size;
}

template<class T, unsigned int StaticSize>
T* CDSSTLVector<T, StaticSize>::begin()
{
  return _vector;
}

template<class T, unsigned int StaticSize>
T* CDSSTLVector<T, StaticSize>::end()
{
  return _vector + _size;
}

template<class T, unsigned int StaticSize>
T const* CDSSTLVector<T, StaticSize>::begin() const
{
  return _vector;
}

template<class T, unsigned int StaticSize>
T const* CDSSTLVector<T, StaticSize>::end() const
{
  return _vector + _size;
}

template<class T, unsigned int StaticSize>
void CDSSTLVector<T, StaticSize>::erase(T* iIterator)
{
  int i, idx = static_cast<int>(iIterator - _vector);
  for (i = idx + 1; i < _size; i++)
    _vector[i - 1] = CDS_MOVE(_vector[i]);
  erase_last();
}

template<class T, unsigned int StaticSize>
void CDSSTLVector<T, StaticSize>::erase(T* iFirst, T* iLast)
{
  CATCDSAssert(iFirst >= _vector && iFirst <= iLast && iLast <= _vector + _size);

  int i, j;
  int idxFirst = static_cast<int>(iFirst - _vector);
  int idxLast = static_cast<int>(iLast - _vector);
  for (i = idxLast, j = idxFirst; i < _size; i++, j++)
    _vector[j] = CDS_MOVE(_vector[i]);
  for (i = idxLast; i < _size; i++)
    _vector[i].~T();
  _size = idxLast;
}

template<class T, unsigned int StaticSize>
void CDSSTLVector<T, StaticSize>::erase_last()
{
  _vector[--_size].~T();
}

template<class T, unsigned int StaticSize>
void CDSSTLVector<T, StaticSize>::clear()
{
#ifdef CPP11_AVAILABLE
  if CDS_CONSTEXPR (!std::is_trivially_destructible<T>::value)
#endif
  {
    for (int i = 0; i < _size; i++)
      _vector[i].~T();
  }
  _size = 0;
}

template<class T, unsigned int StaticSize>
bool CDSSTLVector<T, StaticSize>::operator==(CDSSTLVector const& iSTLVector) const
{
  if (_size != iSTLVector._size)
    return false;
  for (int i = 0; i < _size; i++)
  {
    if (_vector[i] != iSTLVector._vector[i])
      return false;
  }
  return true;
}

template<class T, unsigned int StaticSize>
bool CDSSTLVector<T, StaticSize>::operator!=(CDSSTLVector const& iSTLVector) const
{
  return !(*this == iSTLVector);
}

template<class T, unsigned int StaticSize>
bool CDSSTLVector<T, StaticSize>::operator<(CDSSTLVector const& iSTLVector) const
{
  if (_size < iSTLVector._size)
    return true;
  if (_size != iSTLVector._size)
    return false;
  for (int i = 0; i < _size; i++)
  {
    if (_vector[i] < iSTLVector._vector[i])
      return true;
    if (_vector[i] != iSTLVector._vector[i])
      return false;
  }
  return false;
}

template<class T, unsigned int StaticSize>
bool CDSSTLVector<T, StaticSize>::operator<=(CDSSTLVector const& iSTLVector) const
{
  return !(iSTLVector < *this);
}

template<class T, unsigned int StaticSize>
bool CDSSTLVector<T, StaticSize>::operator>(CDSSTLVector const& iSTLVector) const
{
  return iSTLVector < *this;
}

template<class T, unsigned int StaticSize>
bool CDSSTLVector<T, StaticSize>::operator>=(CDSSTLVector const& iSTLVector) const
{
  return !(*this < iSTLVector);
}

template<class T, unsigned int StaticSize>
void CDSSTLVector<T, StaticSize>::swap(CDSSTLVector& iSTLVector)
{
  CDSSTLVectorAllocator<T, StaticSize>::swap(iSTLVector);
}

template<class T, unsigned int StaticSize>
void CDSSTLVector<T, StaticSize>::reverse()
{
  for (int i = 0; i < _size / 2; i++)
  {
    CATCDSSwap(_vector[i], _vector[_size - 1 - i]);
  }
}

template<class T>
class CATCDSArray : protected CDSSTLVector<T>
{
public:
  typedef T* iterator;
  typedef T const* const_iterator;
  
  typedef T* pointer;
  typedef T value_type;

  using CDSSTLVector<T>::_vector;
  using CDSSTLVector<T>::_capacity;
  using CDSSTLVector<T>::_size;

  CATCDSArray();

  CATCDSArray(CATCDSArray const& iArray);

  CATCDSArray& operator=(CATCDSArray const& iArray);

#ifdef CPP11_AVAILABLE
  CATCDSArray(CATCDSArray&& iArray);

  CATCDSArray& operator=(CATCDSArray&& iArray);

  explicit CATCDSArray(cds::span<T const> iSpan);
#endif

#if defined(CATIAR421)
  CATCDSArray(std::initializer_list<T> iList);
#endif

  explicit CATCDSArray(int iSize);
  CATCDSArray(int iSize, T const& iT);

  CATCDSArray(int iSize, T const* iaValues);

  CATCDSArray(CATMemAllocator&, int iReservedSize);

  ~CATCDSArray();

  CATCDSArray& operator=(T const* iaValues);

  CATCDSBoolean IsEmpty() const;

  int Size() const;
  int size() const;

  int GetNbElements() const;

  int Capacity() const;

  void Size(int iSize, T const& iValue = T());

  void Resize(int iSize);
  void Resize(int iSize, T const& iValue);

  void Fill(int iSize, T const& iValue);

  T& operator[](int iIdx);
  const T& operator[](int iIdx) const;

  T& Get(int iIdx);
  const T& Get(int iIdx) const;

  T& GetElement(int iIdx);
  const T& GetElement(int iIdx) const;

  void Append(T const& iElement);
#ifdef CPP11_AVAILABLE
  void Append(T&& iElement);

  template<class... Args>
  void Emplace(Args&&... iArgs);
#endif

  void AppendZeros(int inZeros);

  void Insert(int iIdx, T const& iElement);
  void InsertAt(int iIdx, T const& iElement);

  void Set(int iIdx, const T& iElement);

  T* GetBuffer();
  T const* GetBuffer() const;

  T* data();
  T const* data() const;

  template<class U>
  int Locate(U const& iValue, int iFrom = 0) const;

  // If sorted is true, the method assumes that the array is sorted => O(n), otherwise O(n^2)
  void RemoveDuplicates(bool iSorted);
  void RemoveAt(int iIdx);
  void QuickRemoveAt(int iIdx);
  // If iAllValues = false, stops after first value removal
  int RemoveValue(T const &iValue, bool iAllValues = false);
  //template<class U>
  //int RemoveValue(U const &iValue, bool iAllValues = false);
  void RemoveAll();
  int RemoveNulls();
  void RemovePosition(int iIndex);

  void Erase(T* iFirst, T* iLast);

  void ExpensiveRemoveAt(int iIdx);

  void PopBack();

  bool operator==(CATCDSArray const& iArray) const;
  bool operator!=(CATCDSArray const& iArray) const;
  bool operator<(CATCDSArray const& iArray) const;
  bool operator<=(CATCDSArray const& iArray) const;
  bool operator>(CATCDSArray const& iArray) const;
  bool operator>=(CATCDSArray const& iArray) const;

  void Swap(CATCDSArray& iArray);

  void Reverse();

  void Reserve(int iSize);

  T const* begin() const;
  T* begin();

  T const* end() const;
  T* end();

  T& Front();
  T const& Front() const;

  T& Back();
  T const& Back() const;

#ifdef CPP11_AVAILABLE
  cds::span<T> SubRange(int iStart, int iEnd);
  cds::span<T const> SubRange(int iStart, int iEnd) const;
  cds::span<T const> CSubRange(int iStart, int iEnd) const;
#endif

  void Intersection(CATCDSArray const &iOtherList, CATCDSArray &oResult) const;

  void Union(CATCDSArray const& iOtherList, CATCDSArray& oResult) const;

  template<class Iterator>
  void Append(Iterator iStart, Iterator iEnd);

  void Append(const CATCDSArray<T>& iToAppend);

  void AppendList(const CATCDSArray<T>& iToAppend);

  static CATCDSArray<T>* CreateInstance(CATMemAllocator&iAllocator, int iReservedSize);

  static void RemoveInstance(CATMemAllocator&iAllocator, CATCDSArray<T>* iArray);

  template<class T2>
  friend class CATCDSArray;
};

template<class T>
CATCDSArray<T>::CATCDSArray()
{
}

template<class T>
CATCDSArray<T>::CATCDSArray(CATCDSArray const& iArray)
  : CDSSTLVector<T>(iArray)
{
}

template<class T>
CATCDSArray<T>& CATCDSArray<T>::operator=(CATCDSArray const& iArray)
{
  CDSSTLVector<T>::operator=(iArray);
  return *this;
}

#ifdef CPP11_AVAILABLE
template<class T>
CATCDSArray<T>::CATCDSArray(CATCDSArray&& iArray)
  : CDSSTLVector<T>(std::move(iArray))
{
}

template<class T>
CATCDSArray<T>& CATCDSArray<T>::operator=(CATCDSArray&& iArray)
{
  CDSSTLVector<T>::operator=(std::move(iArray));
  return *this;
}

template<class T>
CATCDSArray<T>::CATCDSArray(cds::span<T const> iSpan)
  : CATCDSArray(iSpan.size(), iSpan.data())
{
}
#endif

#if defined(CATIAR421)
template<class T>
CATCDSArray<T>::CATCDSArray(std::initializer_list<T> iList)
  : CDSSTLVector<T>(iList)
{
}
#endif

template<class T>
CATCDSArray<T>::~CATCDSArray()
{
}

template<class T>
CATCDSArray<T>::CATCDSArray(int iSize)
  : CDSSTLVector<T>(iSize)
{
  CATCDSAssert(iSize >= 0);
}

template<class T>
CATCDSArray<T>::CATCDSArray(int iSize, T const& t)
  : CDSSTLVector<T>(iSize, t)
{
  CATCDSAssert(iSize >= 0);
}

template<class T>
CATCDSArray<T>::CATCDSArray(int iSize, T const* iaValues)
  : CDSSTLVector<T>(iaValues, iaValues + iSize)
{
  CATCDSAssert(iSize >= 0);
}

template<class T>
CATCDSArray<T>::CATCDSArray(CATMemAllocator &, int iReservedSize)
  : CDSSTLVector<T>()
{
  CATCDSAssert(iReservedSize >= 0);
  Reserve(iReservedSize);
}

template<class T>
CATCDSArray<T>& CATCDSArray<T>::operator=(T const* iaValues)
{
  for (int i = 0, size = Size(); i < size; i++)
    _vector[i] = iaValues[i];
  return *this;
}

template<class T>
CATCDSBoolean CATCDSArray<T>::IsEmpty() const
{
  return Size() == 0;
}

template<class T>
int CATCDSArray<T>::Size() const
{
  return static_cast<int>(CDSSTLVector<T>::size());
}

template<class T>
int CATCDSArray<T>::size() const
{
  return Size();
}

template<class T>
int CATCDSArray<T>::GetNbElements() const
{
  return Size();
}

template<class T>
int CATCDSArray<T>::Capacity() const
{
  return static_cast<int>(CDSSTLVector<T>::capacity());
}

template<class T>
void CATCDSArray<T>::Size(int iSize, T const& iValue)
{
  Resize(iSize, iValue);
}

template<class T>
void CATCDSArray<T>::Resize(int iSize)
{
  CATCDSAssert(iSize >= 0);
  CDSSTLVector<T>::resize(iSize);
}

template<class T>
void CATCDSArray<T>::Resize(int iSize, T const& iValue)
{
  CATCDSAssert(iSize >= 0);
  CDSSTLVector<T>::resize(iSize, iValue);
}

template<class T>
void CATCDSArray<T>::Fill(int iSize, T const& iValue)
{
  CATCDSAssert(iSize >= 0);
  CATCDSArray<T>::clear();
  Resize(iSize, iValue);
}

template<class T>
T& CATCDSArray<T>::operator[](int iIdx)
{
  CATCDSAssert(iIdx >= 0 && iIdx < _size);
  return _vector[iIdx];
}

template<class T>
T const& CATCDSArray<T>::operator[](int iIdx) const
{
  CATCDSAssert(iIdx >= 0 && iIdx < _size);
  return _vector[iIdx];
}

template<class T>
T& CATCDSArray<T>::Get(int iIdx)
{
  CATCDSAssert(iIdx >= 0 && iIdx < _size);
  return _vector[iIdx];
}

template<class T>
T const& CATCDSArray<T>::Get(int iIdx) const
{
  CATCDSAssert(iIdx >= 0 && iIdx < _size);
  return _vector[iIdx];
}

template<class T>
T& CATCDSArray<T>::GetElement(int iIdx)
{
  return Get(iIdx);
}

template<class T>
T const& CATCDSArray<T>::GetElement(int iIdx) const
{
  return Get(iIdx);
}

template<class T>
void CATCDSArray<T>::Append(const T& iElement)
{
  CDSSTLVector<T>::push_back(iElement);
}

#ifdef CPP11_AVAILABLE
template<class T>
void CATCDSArray<T>::Append(T&& iElement)
{
  CDSSTLVector<T>::push_back(std::move(iElement));
}

template<class T>
template<class... Args>
void CATCDSArray<T>::Emplace(Args&&... iArgs)
{
  CDSSTLVector<T>::emplace_back(std::forward<Args>(iArgs)...);
}
#endif

template<class T>
void CATCDSArray<T>::AppendZeros(int inZeros)
{
  for (int i = 0; i < inZeros; i++)
  {
    Append(0);
  }
}

template<class T>
void CATCDSArray<T>::Insert(int iIdx, T const& iElement)
{
  CATCDSAssert(iIdx >= 0 && iIdx <= _size);
  CDSSTLVector<T>::insert(_vector + iIdx, iElement);
}

template<class T>
void CATCDSArray<T>::InsertAt(int iIdx, T const& iElement)
{
  Insert(iIdx, iElement);
}

template<class T>
void CATCDSArray<T>::Set(int iIdx, const T& iElement)
{
  CATCDSAssert(iIdx >= 0);
  if (iIdx >= Size())
    Resize(iIdx + 1);
  _vector[iIdx] = iElement;
}

template<class T>
T* CATCDSArray<T>::GetBuffer()
{
  return &_vector[0];
}

template<class T>
T const* CATCDSArray<T>::GetBuffer() const
{
  return &_vector[0];
}

template<class T>
T* CATCDSArray<T>::data()
{
  return GetBuffer();
}

template<class T>
T const* CATCDSArray<T>::data() const
{
  return GetBuffer();
}

template<class T>
template<class U>
int CATCDSArray<T>::Locate(U const& iValue, int iFrom) const
{
  for (int i = iFrom, size = Size(); i < size; i++)
  {
    if (_vector[i] == iValue)
      return i;
  }
  return -1;
}

template<class T>
void CATCDSArray<T>::RemoveDuplicates(bool iSorted)
{
  int size = Size();
  if (size < 2)
    return;
  if (iSorted)
  {
    int i, idx = 0;
    for (i = 1; i < size; i++)
    {
      if (_vector[idx] != _vector[i])
        _vector[++idx] = _vector[i];
    }
    for (i = ++idx; i < _size; i++)
      _vector[i].~T();
    _size = idx;
  }
  else
  {
    int i, j;
    for (i = 0; i < _size; i++)
    {
      for(j = i + 1; j < _size; )      
      {
        if ((*this)[i] == (*this)[j])        
          RemoveAt(j);        
        else
          j++;
      }
    }
  }
}

template<class T>
void CATCDSArray<T>::RemoveAt(int iIdx)
{
  CATCDSAssert(iIdx >= 0 && iIdx < _size);
  CDSSTLVector<T>::erase(_vector + iIdx);
}

template<class T>
void CATCDSArray<T>::QuickRemoveAt(int iIdx)
{
  CATCDSAssert(iIdx >= 0 && iIdx < _size);
  _vector[iIdx] = CDS_MOVE(_vector[_size - 1]);
  CDSSTLVector<T>::erase(_vector + _size - 1);
}

template<class T>
int CATCDSArray<T>::RemoveValue(T const &iValue, bool iAllValues)
{
  if (iAllValues)
  {
    int iwrite = 0;
    for (int iread = 0; iread < _size; iread++)
    {
      T const &e = (*this)[iread];
      if (e != iValue)
      {
        if (iread != iwrite)
        {
          (*this)[iwrite] = e;
        }
        iwrite++;
      }
    }
    while (iwrite < _size)
    {
      CATCDSArray<T>::erase(&(*this)[_size - 1]);
    }
    return -1;
  }
  else
  {
    int idx = Locate(iValue);
    if (idx >= 0)
      RemoveAt(idx);
    return idx;
  }
}

/*template<class T>
template<class U>
int CATCDSArray<T>::RemoveValue(U const &iValue, bool iAllValues)
{
  if (iAllValues)
  {
    int iwrite = 0;
    for (int iread = 0; iread < _size; iread++)
    {
      T const &e = (*this)[iread];
      if (e != iValue)
      {
        if (iread != iwrite)
        {
          (*this)[iwrite] = e;
        }
        iwrite++;
      }
    }
    while (iwrite < _size)
    {
      CATCDSArray<T>::erase(&(*this)[_size - 1]);
    }
    return -1;
  }
  else
  {
    int idx = Locate(iValue);
    if (idx >= 0)
      RemoveAt(idx);
    return idx;
  }
}*/

template<class T>
void CATCDSArray<T>::RemoveAll()
{
  CDSSTLVector<T>::clear();
}

template<class T>
int CATCDSArray<T>::RemoveNulls()
{
  int i, j = 0, size = Size();
  for (i = 0; i < size; i++)
  {
    if (_vector[i])
    {
      if (j != i)
        _vector[j] = _vector[i];
      j++;
    }
  }
  for (i = j; i < _size; i++)
    _vector[i].~T();
  _size = j;
  return i - j;
}

template<class T>
void CATCDSArray<T>::RemovePosition(int iIndex)
{
  CATCDSAssert(iIndex >= 0 && iIndex < Size());
  CDSSTLVector<T>::erase(begin() + iIndex);
}

template<class T>
void CATCDSArray<T>::Erase(T* iFirst, T* iLast)
{
  CDSSTLVector<T>::erase(iFirst, iLast);
}

template<class T>
void CATCDSArray<T>::ExpensiveRemoveAt(int iIdx)
{
  RemoveAt(iIdx);
}

template<class T>
void CATCDSArray<T>::PopBack()
{
  CDSSTLVector<T>::erase_last();
}

template<class T>
bool CATCDSArray<T>::operator==(CATCDSArray const& iArray) const
{
  return CDSSTLVector<T>::operator==(iArray);
}

template<class T>
bool CATCDSArray<T>::operator!=(CATCDSArray const& iArray) const
{
  return CDSSTLVector<T>::operator!=(iArray);
}

template<class T>
bool CATCDSArray<T>::operator<(CATCDSArray const& iArray) const
{
  return CDSSTLVector<T>::operator<(iArray);
}

template<class T>
bool CATCDSArray<T>::operator<=(CATCDSArray const& iArray) const
{
  return CDSSTLVector<T>::operator<=(iArray);
}

template<class T>
bool CATCDSArray<T>::operator>(CATCDSArray const& iArray) const
{
  return CDSSTLVector<T>::operator>(iArray);
}

template<class T>
bool CATCDSArray<T>::operator>=(CATCDSArray const& iArray) const
{
  return CDSSTLVector<T>::operator>=(iArray);
}

template<class T>
void CATCDSArray<T>::Swap(CATCDSArray& iArray)
{
  CDSSTLVector<T>::swap(iArray);
}

template<class T>
void CATCDSArray<T>::Reverse()
{
  CDSSTLVector<T>::reverse();
}

template<class T>
void CATCDSArray<T>::Reserve(int iSize)
{
  CDSSTLVector<T>::reserve(iSize);
}

template<class T>
T const* CATCDSArray<T>::begin() const
{
  return CDSSTLVector<T>::begin();
}

template<class T>
T* CATCDSArray<T>::begin()
{
  return CDSSTLVector<T>::begin();
}

template<class T>
T const* CATCDSArray<T>::end() const
{
  return CDSSTLVector<T>::end();
}

template<class T>
T* CATCDSArray<T>::end()
{
  return CDSSTLVector<T>::end();
}

template<class T>
T& CATCDSArray<T>::Front()
{
  CATCDSAssert(_size > 0);
  return _vector[0];
}

template<class T>
T const& CATCDSArray<T>::Front() const
{
  CATCDSAssert(_size > 0);
  return _vector[0];
}

template<class T>
T& CATCDSArray<T>::Back()
{
  CATCDSAssert(_size > 0);
  return _vector[_size - 1];
}

template<class T>
T const& CATCDSArray<T>::Back() const
{
  CATCDSAssert(_size > 0);
  return _vector[_size - 1];
}

#ifdef CPP11_AVAILABLE
template<class T>
cds::span<T> CATCDSArray<T>::SubRange(int iStart, int iEnd)
{
  CATCDSAssert(iStart >= 0 && iStart <= iEnd && iEnd <= _size);
  return cds::span<T>(_vector + iStart, _vector + iEnd);
}

template<class T>
cds::span<T const> CATCDSArray<T>::SubRange(int iStart, int iEnd) const
{
  CATCDSAssert(iStart >= 0 && iStart <= iEnd && iEnd <= _size);
  return cds::span<T const>(_vector + iStart, _vector + iEnd);
}

template<class T>
cds::span<T const> CATCDSArray<T>::CSubRange(int iStart, int iEnd) const
{
  CATCDSAssert(iStart >= 0 && iStart <= iEnd && iEnd <= _size);
  return cds::span<T const>(_vector + iStart, _vector + iEnd);
}
#endif

template<class T>
void CATCDSArray<T>::Intersection(CATCDSArray<T> const &iOtherList, CATCDSArray<T> &oResult) const
{
  oResult.RemoveAll();
  T const * iterator;
  for(iterator = begin(); iterator != end(); ++iterator) 
  {
    T const &e = *iterator;
    if (iOtherList.Locate(e) >= 0)    
      oResult.Append(e);    
  }
}

template<class T>
void CATCDSArray<T>::Union(CATCDSArray<T> const &iOtherList, CATCDSArray<T> &oResult) const
{
  oResult.RemoveAll();
  T const * iterator;
  for(iterator = begin(); iterator != end(); ++iterator) 
  {
    T const &Element = *iterator;
    if (oResult.Locate(Element) < 0)
    {
      oResult.Append(Element);
    }
  }
  for(iterator = iOtherList.begin(); iterator != iOtherList.end(); ++iterator)
  {
    T const &Element = *iterator;
    if (oResult.Locate(Element) < 0)
    {
      oResult.Append(Element);
    }
  }
}

template<class T>
template<class Iterator>
void CATCDSArray<T>::Append(Iterator iStart, Iterator iEnd)
{
  CDSSTLVector<T>::insert(CDSSTLVector<T>::end(), iStart, iEnd);
}

template<class T>
void CATCDSArray<T>::Append(const CATCDSArray<T>& iToAppend)
{
  for (int i = 0; i < iToAppend.Size(); i++)
    Append(iToAppend[i]);
}

template<class T>
void CATCDSArray<T>::AppendList(const CATCDSArray<T>& iToAppend)
{
  Append(iToAppend);
}

template<class T>
CATCDSArray<T>* CATCDSArray<T>::CreateInstance(CATMemAllocator&iAllocator, int iReservedSize)
{
  return new CATCDSArray<T>(iAllocator, iReservedSize);
}

template<class T>
void CATCDSArray<T>::RemoveInstance(CATMemAllocator&iAllocator, CATCDSArray<T>* iArray)
{
  delete iArray;
}

template<>
class ExportedByCATCDSUtilities CATCDSArray<void*> : protected CDSSTLVector<void*>
{
public:
  typedef void** iterator;
  typedef void* const* const_iterator;

  explicit CATCDSArray(int iSize = 0);

  CATCDSArray(CATMemAllocator&, int iReservedSize);

  CATCDSArray(CATCDSArray const& iArray);
  CATCDSArray& operator=(CATCDSArray const& iArray);

#ifdef CPP11_AVAILABLE
  CATCDSArray(CATCDSArray&& iArray);
  CATCDSArray& operator=(CATCDSArray&& iArray);
#endif

#if defined(CATIAR421)
  CATCDSArray(std::initializer_list<void*> iList);
#endif

  CATCDSBoolean IsEmpty() const;
  int Size() const;
  int size() const;

  int GetNbElements() const;
  
  void Size(int iSize, void* iValue = 0)
  {
    Resize(iSize, iValue);
  }

  int Capacity() const;

  void Resize(int iSize, void* iValue = 0);

  void*& operator[](int iIdx);
  void* const& operator[](int iIdx) const;

  void*& Get(int iIdx);
  void* const& Get(int iIdx) const;

  void*& GetElement(int iIdx)
  {
    return Get(iIdx);
  }

  void* const& GetElement(int iIdx) const
  {
    return Get(iIdx);
  }

  void Set(int iIdx, void* iElement);

  void Append(void* iElement);

  typedef int (*PFCompare)(void const*, void const*);
  void QuickSort(PFCompare iPFCompare);

  int BinarySearch(void const* iValue, PFCompare iPFCompare) const;

  int Locate(void* iValue, int iFrom = 0) const;

  int RemoveValue(void* iValue, bool iAllValues = false);
  int Remove(CATCDSArray<void*> const& iArray);
  void RemovePosition(int iIdx);
  void QuickRemoveAt(int iIdx);

  void RemoveDuplicates(bool iSorted);

  void RemoveAll() { Size(0); }
  int RemoveNulls();

  void Erase(void** iFirst, void** iLast);

  void PopBack();

  void Insert(void* iValue, int iIdx);

  void Append(CATCDSArray<void*> const& iArray);

  void AppendList(CATCDSArray<void*> const& iArray)
  {
    Append(iArray);
  }

  void Reverse();

  void Reserve(int iSize);

  void* const* GetBuffer() const
  {
    return begin();
  }

  void** GetBuffer()
  {
    return begin();
  }

  void* const* data() const
  {
    return GetBuffer();
  }

  void** data()
  {
    return GetBuffer();
  }

  bool operator==(CATCDSArray<void*> const& iArray) const;
  bool operator!=(CATCDSArray<void*> const& iArray) const;
  bool operator<(CATCDSArray<void*> const& iArray) const;
  bool operator<=(CATCDSArray<void*> const& iArray) const;
  bool operator>(CATCDSArray<void*> const& iArray) const;
  bool operator>=(CATCDSArray<void*> const& iArray) const;

  void* const* begin() const;
  void** begin();
  void* const* end() const;
  void** end();

  static CATCDSArray<void*>* CreateInstance(CATMemAllocator&iAllocator, int iReservedSize)
  {
    return new CATCDSArray<void*>(iAllocator, iReservedSize);
  }

  static void RemoveInstance(CATMemAllocator&iAllocator, CATCDSArray<void*>* iArray)
  {
    delete iArray;
  }
};

template<class T>
class CATCDSArray<T*>
{
public:
  typedef T** iterator;
  typedef T* const* const_iterator;

  typedef T** pointer;
  typedef T* value_type;

  explicit CATCDSArray(int iSize = 0)
    : _array(iSize)
  {
  }

  CATCDSArray(CATMemAllocator& iAllocator, int iReservedSize) :
    _array(iAllocator, iReservedSize)
  {
  }

  CATCDSArray(CATCDSArray const& iArray)
    : _array(iArray._array)
  {
  }

  CATCDSArray& operator=(CATCDSArray const& iArray)
  {
    _array = iArray._array;
    return *this;
  }

#ifdef CPP11_AVAILABLE
  CATCDSArray(CATCDSArray&& iArray)
    : _array(std::move(iArray._array))
  {
  }

  CATCDSArray& operator=(CATCDSArray&& iArray)
  {
    _array = std::move(iArray._array);
    return *this;
  }
#endif

#if defined(CATIAR421)
  CATCDSArray(std::initializer_list<T*> iList)
    : _array(static_cast<int>(iList.size()))
  {
    int n = 0;
    for (T* e : iList)
      _array[n++] = e;
  }
#endif

  CATCDSBoolean IsEmpty() const
  {
    return _array.IsEmpty();
  }

  int Size() const
  {
    return _array.Size();
  }

  int size() const
  {
    return Size();
  }

  int GetNbElements() const
  {
    return _array.GetNbElements();
  }

  void Size(int iSize, T* iValue = 0)
  {
    _array.Size(iSize, const_cast<typename std::remove_const<T>::type*>(iValue));
  }

  void Resize(int iSize, T* iValue = 0)
  {
    _array.Resize(iSize, const_cast<typename std::remove_const<T>::type*>(iValue));
  }

  int Capacity() const
  {
    return _array.Capacity();
  }

  T*& operator[](int iIdx)
  {
    return const_cast<T*&>(reinterpret_cast<typename std::remove_const<T>::type*&>(_array[iIdx]));
  }
  T* const& operator[](int iIdx) const
  {
    return const_cast<T* const&>(reinterpret_cast<typename std::remove_const<T>::type* const&>(_array[iIdx]));
  }

  T*& Get(int iIdx)
  {
    return const_cast<T*&>(reinterpret_cast<typename std::remove_const<T>::type*&>(_array[iIdx]));
  }
  T* const& Get(int iIdx) const
  {
    return const_cast<T* const&>(reinterpret_cast<typename std::remove_const<T>::type* const&>(_array[iIdx]));
  }

  T*& GetElement(int iIdx)
  {
    return Get(iIdx);
  }
  T* const& GetElement(int iIdx) const
  {
    return Get(iIdx);
  }

  void Set(int iIdx, T* iElement)
  {
    _array.Set(iIdx, const_cast<typename std::remove_const<T>::type*>(iElement));
  }

  void DeleteAll()
  {
    int i = _array.Size();
    while (i--)
      delete static_cast<T*>(_array[i]);
    _array.RemoveAll();
  }

  int RemoveValue(T* iValue, bool iAllValues = false)
  {
    return _array.RemoveValue(iValue, iAllValues);
  }

  int Remove(CATCDSArray const& iArray)
  {
    return _array.Remove(iArray._array);
  }

  void RemovePosition(int iIdx)
  {
    _array.RemovePosition(iIdx);
  }

  void RemoveAt(int iIdx)
  {
    _array.RemovePosition(iIdx);
  }

  void ExpensiveRemoveAt(int iIdx)
  {
    RemoveAt(iIdx);
  }

  void RemoveDuplicates(bool iSorted)
  {
    _array.RemoveDuplicates(iSorted);
  }

  void PopBack()
  {
    _array.PopBack();
  }

  void QuickRemoveAt(int iIdx)
  {
    _array.QuickRemoveAt(iIdx);
  }

  void RemoveAll()
  {
    _array.RemoveAll();
  }

  int RemoveNulls()
  {
    return _array.RemoveNulls();
  }

  void Erase(T** iFirst, T** iLast)
  {
    _array.Erase(iFirst, iLast);
  }

  void Append(T* iElement)
  {
    _array.Append(const_cast<typename std::remove_const<T>::type*>(iElement));
  }

  typedef int (*PFCompare)(const T*, const T*);

  void QuickSort(PFCompare iPFCompare)
  {
    _array.QuickSort(reinterpret_cast<CATCDSArray<void*>::PFCompare>(iPFCompare));
  }

  int BinarySearch(T const* iValue, PFCompare iPFCompare) const
  {
    return _array.BinarySearch(iValue, reinterpret_cast<CATCDSArray<void*>::PFCompare>(iPFCompare));
  }

  int Locate(T* iValue, int iFrom = 0) const
  {
    return _array.Locate(iValue, iFrom);
  }

  void Insert(T* iValue, int iIdx)
  {
    return _array.Insert(const_cast<typename std::remove_const<T>::type*>(iValue), iIdx);
  }

  void Append(CATCDSArray<T*> const& iArray)
  {
    return _array.Append(iArray._array);
  }

  void AppendList(CATCDSArray<T*> const& iArray)
  {
    Append(iArray);
  }

  void Reverse()
  {
    _array.Reverse();
  }

  void Reserve(int iSize)
  {
    _array.Reserve(iSize);
  }

  T** GetBuffer()
  {
    return const_cast<T**>(reinterpret_cast<typename std::remove_const<T>::type**>(_array.GetBuffer()));
  }

  T* const* GetBuffer() const
  {
    return const_cast<T**>(reinterpret_cast<typename std::remove_const<T>::type* const*>(_array.GetBuffer()));
  }

  T** data()
  {
    return GetBuffer();
  }

  T* const* data() const
  {
    return GetBuffer();
  }

  T* const* begin() const
  {
    return const_cast<T**>(reinterpret_cast<typename std::remove_const<T>::type* const*>(_array.begin()));
  }

  T** begin()
  {
    return const_cast<T**>(reinterpret_cast<typename std::remove_const<T>::type**>(_array.begin()));
  }

  T* const* end() const
  {
    return const_cast<T**>(reinterpret_cast<typename std::remove_const<T>::type* const*>(_array.end()));
  }

  T** end()
  {
    return const_cast<T**>(reinterpret_cast<typename std::remove_const<T>::type**>(_array.end()));
  }

  bool operator==(CATCDSArray<T*> const& iArray) const
  {
    return _array == iArray._array;
  }

  bool operator!=(CATCDSArray<T*> const& iArray) const
  {
    return _array != iArray._array;
  }

  bool operator<(CATCDSArray<T*> const& iArray) const
  {
    return _array < iArray._array;
  }

  bool operator<=(CATCDSArray<T*> const& iArray) const
  {
    return _array <= iArray._array;
  }

  bool operator>(CATCDSArray<T*> const& iArray) const
  {
    return _array > iArray._array;
  }

  bool operator>=(CATCDSArray<T*> const& iArray) const
  {
    return _array >= iArray._array;
  }

  T*& Front()
  {
    return const_cast<T*&>(*reinterpret_cast<typename std::remove_const<T>::type**>(&_array[0]));
  }

  T* const& Front() const
  {
    return const_cast<T*&>(*reinterpret_cast<typename std::remove_const<T>::type* const*>(&_array[0]));
  }

  T*& Back()
  {
    return const_cast<T*&>(*reinterpret_cast<typename std::remove_const<T>::type**>(&_array[_array.Size() - 1]));
  }

  T* const& Back() const
  {
    return const_cast<T*&>(*reinterpret_cast<typename std::remove_const<T>::type* const*>(&_array[_array.Size() - 1]));
  }

#ifdef CPP11_AVAILABLE
  cds::span<T*> SubRange(int iStart, int iEnd)
  {
    CATCDSAssert(iStart >= 0 && iStart <= iEnd && iEnd <= _array.size());
    return cds::span<T>(begin() + iStart, begin() + iEnd);
  }

  cds::span<T* const> SubRange(int iStart, int iEnd) const
  {
    CATCDSAssert(iStart >= 0 && iStart <= iEnd && iEnd <= _array.size());
    return cds::span<T>(begin() + iStart, begin() + iEnd);
  }

  cds::span<T* const> CSubRange(int iStart, int iEnd) const
  {
    CATCDSAssert(iStart >= 0 && iStart <= iEnd && iEnd <= _array.size());
    return cds::span<T>(begin() + iStart, begin() + iEnd);
  }
#endif

  static CATCDSArray<T*>* CreateInstance(CATMemAllocator&iAllocator, int iReservedSize)
  {
    return new CATCDSArray<T*>(iAllocator, iReservedSize);
  }

  static void RemoveInstance(CATMemAllocator&iAllocator, CATCDSArray<T*>* iArray)
  {
    delete iArray;
  }

private:
  CATCDSArray<void*> _array;
};

#define CATCDSARRAY_DECLARE(T) typedef CATCDSArray<T> CATCDSArray##T;
#define CATCDSARRAY(T) CATCDSArray<T>
#define CATCDSARRAY_FORWARD template<class T> \
class CATCDSArray;

#if !defined(__CATCDSUtilities) && !defined(_SUNOS_SOURCE)
extern template class CATCDSArray<int>;
extern template class CATCDSArray<double>;
extern template class CATCDSArray<CATCDSBoolean>;
#endif

template<class Stream, class T>
Stream& operator<<(Stream& ioStream, CATCDSArray<T> const& iArray)
{
  ioStream << "[";
  for (int i = 0, n = iArray.Size(); i < n; i++)
  {
    if (i != 0)
      ioStream << ", ";
    ioStream << iArray[i];
  }
  ioStream << "]";
  return ioStream;
}

#endif
