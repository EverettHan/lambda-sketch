#ifndef CATCDSFreelessArray_H
#define CATCDSFreelessArray_H

// Spatial builds CDS on VC12.  Some of the advanced
// C++ features are not supported on this compiler, and the collision detection
// functionality is not needed for them.
#if !defined(_MSC_VER) || _MSC_VER >= 1900
#include "CATCDSArray.h"

#include <algorithm>

#undef min
#undef max

template<class T>
class CATCDSFreelessArrayImp;

template<class T, bool = std::is_trivially_destructible<T>::value>
class CATCDSFreelessArrayTrait;

template<class T>
class CATCDSFreelessArrayTrait<T, true> { public: using type = CATCDSArray<T>; };
template<class T>
class CATCDSFreelessArrayTrait<T, false> { public: using type = CATCDSFreelessArrayImp<T>; };

template<class T>
using CATCDSFreelessArray = typename CATCDSFreelessArrayTrait<T>::type;

template<class T>
class CATCDSFreelessArrayImp
{
public:
  CATCDSFreelessArrayImp() = default;
  ~CATCDSFreelessArrayImp();
  CATCDSFreelessArrayImp(CATCDSFreelessArrayImp const&) = default;
  CATCDSFreelessArrayImp& operator=(CATCDSFreelessArrayImp const&) = default;
  CATCDSFreelessArrayImp(CATCDSFreelessArrayImp &&) = default;
  CATCDSFreelessArrayImp& operator=(CATCDSFreelessArrayImp &&) = default;

  CATCDSFreelessArrayImp(int iSize, T const & = T());

  void Reserve(int iSize);
  void Resize(int iSize, T const &iT = T());
  void RemoveAll();

  void Append(T const &iT);
  void Append(T &&iT);

  template<class... Args>
  void Emplace(Args&&... iArgs);

  T const & operator[](int i) const;
  T & operator[](int i);

  T const * begin() const;
  T const * end() const;

  T * begin();
  T * end();

  T const & Front() const;
  T & Front();
  T const & Back() const;
  T & Back();

  int Size() const;
  bool IsEmpty() const;

  void Swap(CATCDSFreelessArrayImp<T> &iArray);

private:
  int _size = 0;
  CATCDSArray<T> _array;
};

template<class T>
CATCDSFreelessArrayImp<T>::CATCDSFreelessArrayImp(int iSize, T const &iT)
  : _size(iSize)
  , _array(iSize, iT)
{

}

template<class T>
CATCDSFreelessArrayImp<T>::~CATCDSFreelessArrayImp()
{
  _size = _array.Size();
}

template<class T>
void CATCDSFreelessArrayImp<T>::Reserve(int iSize)
{
  _array.Reserve(iSize);
}

template<class T>
void CATCDSFreelessArrayImp<T>::Resize(int iSize, T const &iT)
{
  for (int i = _size, size = std::min(_array.Size(), iSize); i < size; i++)
  {
    _array[i] = iT;
  }
  if (iSize > _array.Size())
    _array.Resize(iSize, iT);
  _size = iSize;
}

template<class T>
void CATCDSFreelessArrayImp<T>::RemoveAll()
{
  _size = 0;
}

template<class T>
void CATCDSFreelessArrayImp<T>::Append(T const &iT)
{
  if (_size < _array.Size())
    _array[_size] = iT;
  else
    _array.Append(iT);
  ++_size;
}

template<class T>
void CATCDSFreelessArrayImp<T>::Append(T &&iT)
{
  if (_size < _array.Size())
    _array[_size] = std::move(iT);
  else
    _array.Append(std::move(iT));
  ++_size;
}

template<class T>
template<class... Args>
void CATCDSFreelessArrayImp<T>::Emplace(Args&&... iArgs)
{
  if (_size < _array.Size())
    _array[_size] = T(std::forward<Args>(iArgs)...);
  else
    _array.Emplace(std::forward<Args>(iArgs)...);
  ++_size;
}

template<class T>
T const & CATCDSFreelessArrayImp<T>::operator[](int i) const
{
  CATCDSAssert(i >= 0 && i < _size);
  return _array[i];
}

template<class T>
T & CATCDSFreelessArrayImp<T>::operator[](int i)
{
  CATCDSAssert(i >= 0 && i < _size);
  return _array[i];
}

template<class T>
T const * CATCDSFreelessArrayImp<T>::begin() const
{
  return _array.begin();
}

template<class T>
T const * CATCDSFreelessArrayImp<T>::end() const
{
  return _array.begin() + Size();
}

template<class T>
T * CATCDSFreelessArrayImp<T>::begin()
{
  return _array.begin();
}

template<class T>
T * CATCDSFreelessArrayImp<T>::end()
{
  return _array.begin() + Size();
}

template<class T>
int CATCDSFreelessArrayImp<T>::Size() const
{
  return _size;
}

template<class T>
bool CATCDSFreelessArrayImp<T>::IsEmpty() const
{
  return Size() == 0;
}

template<class T>
void CATCDSFreelessArrayImp<T>::Swap(CATCDSFreelessArrayImp<T> &iArray)
{
  std::swap(_size, iArray._size);
  _array.Swap(iArray._array);
}

template<class T>
T const & CATCDSFreelessArrayImp<T>::Front() const
{
  return _array.Front();
}

template<class T>
T & CATCDSFreelessArrayImp<T>::Front()
{
  return _array.Front();
}

template<class T>
T const & CATCDSFreelessArrayImp<T>::Back() const
{
  return _array[Size() - 1];
}

template<class T>
T & CATCDSFreelessArrayImp<T>::Back()
{
  return _array[Size() - 1];
}
#endif
#endif
