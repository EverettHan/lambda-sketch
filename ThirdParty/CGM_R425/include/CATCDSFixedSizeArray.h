#ifndef CATCDSFixedSizeArray_H
#define CATCDSFixedSizeArray_H

#include <array>
#include <utility>
#include <type_traits>
#include <initializer_list>

#include "CATCDSAssert.h"
#include "CATCDSCPlusPlusVersions.h"

namespace cds
{
  template<class T, std::size_t... N>
  class array;

  template<class T, std::size_t N>
  class array<T, N> : public std::array<T, N>
  {
  public:
    using Base = std::array<T, N>;
    using Base::begin;
    using Base::end;
    
    array() = default;
    array(array const &) = default;
    array& operator=(array const &) = default;
    array(array &&) = default;
    array& operator=(array &&) = default;
    ~array() = default;

    template<class U, class = std::enable_if_t<std::is_convertible<U, T>::value>>
    constexpr array(std::initializer_list<U> iValues)
    {
      int size = 0;
      for (auto const &v : iValues)
      {
        (*this)[size++] = v;
      }
      CATCDSAssert(size <= N);
      std::fill(begin() + size, end(), T());
    }

#ifdef CPP11_AVAILABLE_V2
    constexpr 
#endif
      T const & operator[](std::size_t idx) const noexcept
    {
      CATCDSAssert(idx < N);
      return Base::operator[](idx);
    }

#ifdef CPP11_AVAILABLE_V2
    constexpr
#endif
    T & operator[](std::size_t idx) noexcept
    {
      CATCDSAssert(idx < N);
      return Base::operator[](idx);
    }
  };

  template<class T, std::size_t Head, std::size_t... Tail>
  class array<T, Head, Tail...> : public array<array<T, Tail...>, Head> 
  {
  public:
    using Base = array<array<T, Tail...>, Head>;
    using Base::Base;
  };
}

#endif
