#ifndef CATCDSSpan_H
#define CATCDSSpan_H

#include "CATCDSFixedSizeArray.h"
#include "CATCDSAssert.h"
#include "CATCDSCPlusPlusVersions.h"

#include <algorithm>
#include <cstddef>
#include <type_traits>
#include <utility>

namespace cds
{

template<class T, std::size_t... Dim>
class span;

namespace details
{
  template<std::size_t... Dim> class product;
  template<> class product<> : public std::integral_constant<std::size_t, 1> {};
  template<std::size_t DimH, std::size_t... DimQ> class product<DimH, DimQ...> : public std::integral_constant<std::size_t, DimH * product<DimQ...>::value> {};
  
  template<class T, std::size_t... Dim>
  class storage;

  template<std::size_t... Dim>
  struct get
  {
    template<class T>
    static cds::span<T, Dim...> apply(T* data, std::size_t i)
    {
      return span<T, Dim...>(data + i * product<Dim...>::value);
    }
  };

  template<>
  struct get<>
  {
    template<class T>
    static T& apply(T* data, std::size_t i)
    {
      return data[i];
    }
  };

  template<std::size_t... Dim>
  struct get_index;

  template<>
  struct get_index<>
  {
    static int eval()
    {
      return 0;
    }
  };

  template<std::size_t DimH, std::size_t... DimQ>
  struct get_index<DimH, DimQ...>
  {
    template<class IndexTypeH, class... IndexTypeQ>
    static auto eval(IndexTypeH indexH, IndexTypeQ... indexQ)
    {
      CATCDSAssert(indexH >= 0 && indexH < DimH);
      return indexH * product<DimQ...>::value + get_index<DimQ...>::eval(indexQ...);
    }
  };

  // Implementation of internal span storage for different extent size : dynamic and static
  template<class T, std::size_t FirstDim, std::size_t... OtherDim>
  class storage<T, FirstDim, OtherDim...>
  {
  public:
    storage() = delete;
    storage(storage const &) = default;
    storage& operator=(storage const &) = default;
    ~storage() = default;

    storage(T* data, std::size_t iSize)
      : _data(data) 
    { 
    }

    template<std::size_t N>
    storage(T* data, std::integral_constant<std::size_t, N>)
      : _data(data)
    {
      static_assert(sizeof...(OtherDim) == 0 && FirstDim <= N, "Invalid size");
    }

    storage(T* data) 
      : _data(data) 
    { 
    }

    std::size_t first_dim() const
    {
      return FirstDim;
    }

    std::size_t size() const
    {
      return product<FirstDim, OtherDim...>::value;
    }

    decltype(auto) operator[](std::size_t i) const
    {
      return get<OtherDim...>::apply(_data, i);
    }

    T* data() const
    {
      return _data;
    }

    bool operator==(storage const& other) const
    {
      return _data == other._data;
    }

    bool operator<(storage const& other) const
    {
      return _data < other._data;
    }

  private:
    T* _data = nullptr;
  };

  template<class T>
  class storage<T>
  {
  public:
    storage() = default;
    storage(storage const &) = default;
    storage& operator=(storage const &) = default;
    ~storage() = default;

    storage(T* data, std::size_t iSize) 
      : _data(data) 
      , _size(iSize)
    {}

    template<std::size_t N>
    storage(T* data, std::integral_constant<std::size_t, N>)
      : _data(data)
      , _size(N)
    {
    }

    std::size_t first_dim() const
    {
      return _size;
    }

    std::size_t size() const
    {
      return _size;
    }

    T& operator[](std::size_t i) const
    {
      return _data[i];
    }

    T* data() const
    {
      return _data;
    }

    bool operator==(storage const& other) const
    {
      return _data == other._data && _size == other._size;
    }

    bool operator<(storage const& other) const
    {
      return _data < other._data || _data == other._data && _size < other._size;
    }
    
  private:
    T* _data = nullptr;
    std::size_t _size = 0;
  };


  // is_span trait
  template<class T>
  class is_span : public std::integral_constant<bool, false> {};

  template<class T, std::size_t... Dim>
  class is_span<span<T, Dim...>> : public std::integral_constant<bool, true> {};

  // is_dynamic_span trait
  template<class T>
  class is_dynamic_span : public std::integral_constant<bool, false> {};

  template<class T>
  class is_dynamic_span<span<T>> : public std::integral_constant<bool, true> {};

  // is_array trait
  template<class T>
  class is_array : public std::integral_constant<bool, false>{};

  template<class T, std::size_t... N>
  class is_array<array<T, N...>> : public std::integral_constant<bool, true> {};

  // c_array
  template<class T, std::size_t... Dim>
  class c_array_type;

  template<class T>
  class c_array_type<T> { public: using type = T; };

  template<class T, std::size_t DimH, std::size_t... DimQ>
  class c_array_type<T, DimH, DimQ...> { public: using type = typename c_array_type<T, DimQ...>::type[DimH]; };

  template<class T, std::size_t... Dim>
  using c_array = typename c_array_type<T, Dim...>::type;

  // is_strong_convertible trait
  template<class From, class To>
  class is_strong_convertible : public std::integral_constant<bool, false> {};

  template<class From, class To>
  class is_strong_convertible<From*, To*> : public std::integral_constant<bool, (std::is_convertible<From*, To*>::value && sizeof(From) == sizeof(To))> {};
  
  // is_c_array trait
  template<class U, class T, std::size_t...Dim>
  class is_c_array : public std::integral_constant<bool, false> {};

  template<class U, class T>
  class is_c_array<U, T> : public std::is_same<U, T> {};

  template<class U, class T>
  class is_c_array<U*, T*> : public is_strong_convertible<U*, T*> {};

  template<class U, class T, std::size_t DimH, std::size_t... DimQ>
  class is_c_array<U[DimH], T, DimH, DimQ...> : public is_c_array<U, T, DimQ...> {};
}

// Span implementation

template<class T, std::size_t... Dim>
class span
{
public:
  using pointer = T*;
  using value_type = T;
  using iterator = T*;
  using const_iterator = iterator;

  // default constructors

  span() = default;
  span(span const &) = default;
  span& operator=(span const &) = default;
  ~span() = default;

  // span to const
  #ifdef CPP11_AVAILABLE_V2
  template<bool Dependent = false, class = std::enable_if_t<(Dependent || sizeof...(Dim) > 1 && !std::is_same<T, std::remove_const_t<T>>::value)>>
  span(span<std::remove_const_t<T>, Dim...> const &iSpan, int dummy = 0)
    : _storage(iSpan.data(), iSpan.size())
  {}
  #endif

  // nullptr
  span(std::nullptr_t) 
    : _storage()
  {}

  // Buffer
  template<bool Dependent = false, class = std::enable_if_t<(Dependent || sizeof...(Dim) == 0)>>
  span(pointer data, std::size_t size) 
    : _storage(data, size) 
  {}

  template<class Pointer, class = std::enable_if_t<(sizeof...(Dim) > 0) && std::is_pointer<Pointer>::value>>
  explicit span(Pointer data)
    : _storage(data) 
  {
    CATCDSAssert(data != nullptr);
  }

  // Range
  span(pointer firstElem, pointer lastElem)
    : _storage(firstElem, std::distance(firstElem, lastElem))
  {
    CATCDSAssert(sizeof...(Dim) == 0 || _storage.size() >= details::product<Dim...>::value);
  }

  // Exact size array
  template<class U, std::size_t N, class = std::enable_if_t<details::is_c_array<U[N], std::remove_const_t<T>, Dim...>::value>>
  span(U (&arr)[N])
    : _storage(reinterpret_cast<T*>(&arr))
  {
  }

  template<class U, std::size_t N, class = std::enable_if_t<details::is_c_array<U[N], std::remove_const_t<T>, Dim...>::value>>
  span(U const (&arr)[N])
    : _storage(reinterpret_cast<T const*>(&arr))
  {
  }

  span(array<std::remove_const_t<T>, Dim...> &arr)
    : _storage(reinterpret_cast<T*>(&arr))
  {
  }

  span(array<std::remove_const_t<T>, Dim...> const &arr)
    : _storage(reinterpret_cast<T*>(&arr))
  {
  }

  // Array
  //template<class U, std::size_t N, class = std::enable_if_t<(details::is_strong_convertible<U*, T*>::value && sizeof...(Dim) <= 1)>>
  template<std::size_t N, class = std::enable_if_t<(N < 0 || sizeof...(Dim) <= 1)>>
  span(std::remove_const_t<T>(&arr)[N])
    : _storage(arr, std::integral_constant<std::size_t, N>())
  {
    static_assert(sizeof...(Dim) == 0 || details::product<Dim...>::value <= N, "Array size is lower than span size");
  }

  //template<class U, std::size_t N, class = std::enable_if_t<(details::is_strong_convertible<U*, T*>::value && sizeof...(Dim) <= 1)>>
  template<std::size_t N, class = std::enable_if_t<(N < 0 || sizeof...(Dim) <= 1)>>
  span(std::remove_const_t<T> const (&arr)[N])
    : _storage(arr, std::integral_constant<std::size_t, N>())
  {
    static_assert(sizeof...(Dim) == 0 || details::product<Dim...>::value <= N, "Array size is lower than span size");
  }

  
  template<class U, std::size_t N, class = std::enable_if_t<(details::is_strong_convertible<U*, std::remove_const_t<T>*>::value && sizeof...(Dim) <= 1)>>
  span(array<U, N> &arr)
    : _storage(arr.data(), std::integral_constant<std::size_t, N>())
  {
    static_assert(sizeof...(Dim) == 0 || details::product<Dim...>::value <= N, "Array size is lower than span size");
  }

  template<class U, std::size_t N, class = std::enable_if_t<(details::is_strong_convertible<U*, std::remove_const_t<T>*>::value && sizeof...(Dim) <= 1)>>
  span(array<U, N> const &arr)
    : _storage(arr.data(), std::integral_constant<std::size_t, N>())
  {
    static_assert(sizeof...(Dim) == 0 || details::product<Dim...>::value <= N, "Array size is lower than span size");
  }

  // Container
  template<class Container, class = std::enable_if_t<!details::is_span<Container>::value && !details::is_array<Container>::value &&
    details::is_strong_convertible<typename Container::pointer, pointer>::value &&
    details::is_strong_convertible<typename Container::pointer, decltype(std::declval<Container>().data())>::value>>
  span(Container &container)
    : _storage(container.data(), container.size())
  {
    CATCDSAssert(sizeof...(Dim) == 0 || _storage.size() >= details::product<Dim...>::value);
  }

  template<class Container, class = std::enable_if_t<!details::is_span<Container>::value && !details::is_array<Container>::value &&
    std::is_const<T>::value &&
    details::is_strong_convertible<typename Container::pointer, pointer>::value &&
    details::is_strong_convertible<typename Container::pointer, decltype(std::declval<Container>().data())>::value>>
  span(Container const &container)
    : _storage(container.data(), container.size())
  {
    CATCDSAssert(sizeof...(Dim) == 0 || _storage.size() >= details::product<Dim...>::value);
  }

  // Span
  template<std::size_t OtherDim, class = std::enable_if_t<(sizeof...(Dim) == 0 || sizeof...(Dim) == 1 && OtherDim >= details::product<Dim...>::value)>>
  span(const span<const T, OtherDim>& other)
    : _storage(other.data(), other.size())
  {
    CATCDSAssert(sizeof...(Dim) == 0 || other.size() >= details::product<Dim...>::value);
  }

  template<std::size_t OtherDim, class = std::enable_if_t<(sizeof...(Dim) == 0 || sizeof...(Dim) == 1 && OtherDim >= details::product<Dim...>::value)>>
  span(const span<std::remove_const_t<T>, OtherDim>& other)
    : _storage(other.data(), other.size())
  {
    CATCDSAssert(sizeof...(Dim) == 0 || other.size() >= details::product<Dim...>::value);
  }

  #ifdef CPP11_AVAILABLE_V2
  template<bool Dependent = false, class = std::enable_if_t<(Dependent || sizeof...(Dim) <= 1)>>
  span(const span<const T>& other)
    : _storage(other.data(), other.size())
  {
    CATCDSAssert(sizeof...(Dim) == 0 || other.size() >= details::product<Dim...>::value);
  }

  template<bool Dependent = false, class = std::enable_if_t<(Dependent || sizeof...(Dim) <= 1)>>
  span(const span<std::remove_const_t<T>>& other)
    : _storage(other.data(), other.size())
  {
    CATCDSAssert(sizeof...(Dim) == 0 || other.size() >= details::product<Dim...>::value);
  }
  #endif

  // operator[]

  decltype(auto) operator[](std::size_t i) const
  {
    CATCDSAssert(i >= 0 && i < _storage.first_dim());
    return _storage[i];
  }

  template<class IndexType, IndexType i>
  T & operator[](std::integral_constant<IndexType, i>) const
  {
    static_assert(i >= 0 && i < details::product<Dim...>::value, "Invalid access");
    return data()[i];
  }

  // operator()
  template<class... IndexType>
  T& operator()(IndexType... indexes)
  {
    static_assert(sizeof...(IndexType) == sizeof...(Dim), "Invalid number of arguments for operator()");
    auto index = details::get_index<Dim...>::eval(indexes...);
    return data()[index];
  }

  // bool cast for dynamic span
  template<bool Dependent = false, class = std::enable_if_t<(Dependent || sizeof...(Dim) == 0)>>
  explicit operator bool() const
  {
    return size() != 0;
  }

   // size / data

  int size() const
  {
    return static_cast<int>(_storage.size());
  }

  T* data() const
  {
    return _storage.data();
  }

  span<T> SubRange(int iStart, int iEnd)
  {
    CATCDSAssert(iStart >= 0 && iStart <= iEnd && iEnd <= size());
    return span<T>(data() + iStart, iEnd - iStart);
  }

  span<T> SubSpan(int iOffset, int iSize)
  {
    CATCDSAssert(iOffset >= 0 && iSize >= 0 && iOffset + iSize <= size());
    return span<T>(data() + iOffset, iSize);
  }

  // iterators

  iterator begin() const
  {
    return _storage.data();
  }

  iterator end() const
  {
    return _storage.data() + _storage.size();
  }

  // comparison operator
  bool operator==(span const &other) const
  {
    return _storage == other._storage;
  }

  bool operator!=(span const &other) const
  {
    return !(*this == other);
  }

  bool operator<(span const &other) const
  {
    return _storage < other._storage;
  }

  bool operator<=(span const &other) const
  {
    return !(other < *this);
  }

  bool operator>(span const &other) const
  {
    return other < *this;
  }

  bool operator>=(span const &other) const
  {
    return !(*this < other);
  }

  template<bool Dependent = false, class = std::enable_if_t<(Dependent || sizeof...(Dim) == 0)>>
  bool operator==(std::nullptr_t) const
  {
    return size() == 0;
  }

  template<bool Dependent = false, class = std::enable_if_t<(Dependent || sizeof...(Dim) == 0)>>
  bool operator!=(std::nullptr_t) const
  {
    return size() != 0;
  }

private:
  details::storage<T, Dim...> _storage;
};

// Free functions : size, data

template<class T, std::size_t... Dim>
int size(span<T, Dim...> const &iSpan)
{
  return static_cast<int>(iSpan.size());
}

template<class T, std::size_t... Dim>
T* data(span<T, Dim...> const &iSpan)
{
  return iSpan._storage();
}

// make_span helper functions
template<class T>
span<T> make_span(T* data, std::ptrdiff_t size)
{
  return span<T>(data, size);
}

template<class T>
span<T> make_span(T* begin, T* end)
{
  return span<T>(begin, end);
}

template<class T, std::size_t N>
auto make_span(T (&arr)[N])
{
  return span<T, N>(arr);
}

template<class T, std::size_t N>
auto make_span(T const (&arr)[N])
{
  return span<T const, N>(arr);
}

template<class T, std::size_t N1, std::size_t N2>
auto make_span(T(&arr)[N1][N2])
{
  return span<T, N1, N2>(arr);
}

template<class T, std::size_t N1, std::size_t N2>
auto make_span(T const(&arr)[N1][N2])
{
  return span<T const, N1, N2>(arr);
}

template<class T, std::size_t... Dim>
auto make_span(array<T, Dim...> &arr)
{
  return span<T, Dim...>(arr);
}

template<class T, std::size_t... Dim>
auto make_span(array<T, Dim...> const &arr)
{
  return span<T const, Dim...>(arr);
}

template<class Container, class = std::enable_if_t<!details::is_span<Container>::value && !details::is_array<Container>::value>>
auto make_span(Container& cont)
{
  return span<typename Container::value_type>(cont);
}

template<class Container, class = std::enable_if_t<!details::is_span<Container>::value && !details::is_array<Container>::value>>
auto make_span(const Container& cont)
{
  return span<const typename Container::value_type>(cont);
}

template <class T, std::size_t... Dim>
span<T, Dim...> const & make_span(span<T, Dim...> const &span)
{
  return span;
}

// Algorithm helpers for span and array

template<class T, std::size_t... N>
void copy(span<T const, N...> iSeq, span<T, N...> oSeq)
{
  CATCDSAssert(iSeq.size() <= oSeq.size());
  std::copy_n(iSeq.data(), iSeq.size(), oSeq.data());
}

template<class T, std::size_t... N>
void copy(span<T, N...> iSeq, span<T, N...> oSeq)
{
  copy(span<T const, N...>(iSeq), oSeq);
}

template<class T, std::size_t N>
void copy(span<T const> iSeq, span<T, N> oSeq)
{
  CATCDSAssert(iSeq.size() == N);
  std::copy_n(iSeq.begin(), iSeq.size(), oSeq.begin());
}

template<class T, std::size_t N>
void copy(span<T> iSeq, span<T, N> oSeq)
{
  copy(span<T const>(iSeq), oSeq);
}

template<class T, std::size_t N>
void copy(span<T const, N> iSeq, span<T> oSeq)
{
  CATCDSAssert(oSeq.size() == N);
  std::copy_n(iSeq.begin(), iSeq.size(), oSeq.begin());
}

template<class T, std::size_t N>
void copy(span<T, N> iSeq, span<T> oSeq)
{
  copy(span<T const, N>(iSeq), oSeq);
}

template<class C1, class C2, class = std::enable_if_t<!details::is_span<C1>::value || !details::is_span<C2>::value>>
void copy(C1 const &iInput, C2 &&oOutput)
{
  copy(make_span(iInput), make_span(oOutput));
}

template<class T, class U, std::size_t... N>
void fill(span<T, N...> oSeq, U const &iValue)
{
  std::fill_n(oSeq.data(), oSeq.size(), iValue);
}

template<class C, class T, class = std::enable_if_t<!details::is_span<C>::value>>
void fill(C &oOutput, T const &iValue)
{
  fill(make_span(oOutput), iValue);
}

// Dynamic operator+ overload for span and array

// Static size span and array offsetting is disabled for build time int
// Offseting is possible through static constant defined in CATCDSIntegralConstant
// my_array + 2 have to be writtent my_array + 2_c
// In order to offset with runtime value, a cast to dynamic span is necessary
// my_array + i have to be written cds::span<T>(my_array) + i

template<class T>
auto operator+(span<T> iSpan, std::size_t offset)
{
  auto size = iSpan.size() - offset;
  CATCDSAssert(size >= 0);
  return span<T>(iSpan.data() + offset, size);
}

template<class T>
span<T>& operator+=(span<T> &iSpan, std::size_t offset)
{
  return iSpan = iSpan + offset;
}

template<class T, std::size_t N>
auto operator+(span<T, N> iSpan, std::size_t)
{
  static_assert(N < 0, "Use static constant (ie 1_c) for offsetting static span");
  return iSpan;
}

template<class T, std::size_t N>
auto operator+(array<T, N> const &iArray, std::size_t offset)
{
  static_assert(N < 0, "Use static constant (ie 1_c) for offsetting static array");
  return make_span(iArray);
}

template<class T, std::size_t N>
auto operator+(array<T, N> &iArray, std::size_t offset)
{
  static_assert(N < 0, "Use static constant (ie 1_c) for offsetting static array");
  return make_span(iArray);
}

// Static operator+ overload for span and array

template<class T, std::size_t N, class IndexType, IndexType Offset>
auto operator+(span<T, N> iSpan, std::integral_constant<IndexType, Offset> const &)
{
  static_assert(Offset <= N, "Offset is greater then span size");
  return span<T, N - Offset>(iSpan.data() + Offset);
}

template<class T, std::size_t N, class IndexType, IndexType Offset>
span<T, N>& operator+=(span<T, N> &iSpan, std::integral_constant<IndexType, Offset> const &offset)
{
  return iSpan = iSpan + offset;
}

template<class T, std::size_t N, class IndexType, IndexType Offset>
auto operator+(array<T, N> const &iArray, std::integral_constant<IndexType, Offset> const &iC)
{
  return make_span(iArray) + iC;
}

template<class T, std::size_t N, class IndexType, IndexType Offset>
auto operator+(array<T, N> &iArray, std::integral_constant<IndexType, Offset> const &iC)
{
  return make_span(iArray) + iC;
}

}

template<class T, std::size_t... Dim>
using CATCDSSpan = cds::span<T, Dim...>;

#endif
