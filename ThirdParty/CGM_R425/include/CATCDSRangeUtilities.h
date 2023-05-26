#ifndef CATCDSRangeUtilities_H
#define CATCDSRangeUtilities_H

#include <tuple>
#include <type_traits>

#include "CATCDSVariant.h"

template<class Iterator1, class Iterator2>
class CATCDSRange : private std::pair<Iterator1, Iterator2>
{
public:
  using Base = std::pair<Iterator1, Iterator2>;
  
  CATCDSRange(Base const &iBase)
    : Base(iBase)
  {}

  Iterator1& begin()
  {
    Base &base = *this;
    return base.first;
  }

  Iterator2& end()
  {
    Base &base = *this;
    return base.second;
  }

  Iterator1 const& begin() const
  {
    Base const &base = *this;
    return base.first;
  }

  Iterator2 const& end() const
  {
    Base const &base = *this;
    return base.second;
  }
};

template<class Iterator1, class Iterator2>
auto Range(std::pair<Iterator1, Iterator2> const &iRange)
{
  return CATCDSRange<Iterator1, Iterator2>(iRange);
}

template<class Iterator1, class Iterator2>
auto Range(Iterator1 const &iBegin, Iterator2 const &iEnd)
{
  return CATCDSRange<Iterator1, Iterator2>(std::make_pair(iBegin, iEnd));
}

namespace cds
{
  namespace details
  {
    template<class T>
    void voidf(T&&...)
    {
    }
  }
}

class CATCDSIndexIterator
{
public:
  CATCDSIndexIterator(int iIndex = 0)
    : _index(iIndex)
  {}

  CATCDSIndexIterator & operator++()
  {
    ++_index;
    return *this;
  }

  CATCDSIndexIterator & operator++(int n)
  {
    _index++;
    return *this;
  }

  int const & operator*() const
  {
    return _index;
  }

  //decltype(auto) operator->() const

  bool operator==(CATCDSIndexIterator const & iIterator) const
  {
    return _index == iIterator._index;
  }

  bool operator!=(CATCDSIndexIterator const & iIterator) const
  {
    return _index != iIterator._index;
  }

  int _index = 0;

  using difference_type = int;
  using value_type = int;
  using pointer = int*;
  using reference = int&;
  using iterator_category = std::random_access_iterator_tag;
};

inline int operator-(CATCDSIndexIterator const &iEnd, CATCDSIndexIterator const &iStart)
{
  return iEnd._index - iStart._index;
}

class CATCDSIndexRange
{
public:
  CATCDSIndexRange(int iStart = 0, int iEnd = 0)
    : _start(iStart)
    , _end(iStart <= iEnd ? iEnd : iStart)
  {}

  auto begin()
  {
    return CATCDSIndexIterator(_start);
  }

  auto end()
  {
    return CATCDSIndexIterator(_end);
  }

private:
  int _start = 0;
  int _end = 0;
};

namespace cds
{
  namespace details
  {
    template<class Tuple1, class Tuple2, int... Ints>
    void assign_ref_tuple(Tuple1 const &oTuple, Tuple2 &&iTuple, std::integer_sequence<int, Ints...>)
    {
      voidf((std::get<Ints>(oTuple) = std::move(std::get<Ints>(iTuple)))...);
    }
  }
}

namespace std
{
  template<class... T>
  void swap(tuple<T&...> const &iTuple1, tuple<T&...> const &iTuple2)
  {
    auto temp = cds::apply([](auto&&... values) { return std::tuple<T...>(std::move(values)...); }, iTuple1);
    cds::details::assign_ref_tuple(iTuple1, std::move(iTuple2), std::make_integer_sequence<int, sizeof...(T)>{});
    cds::details::assign_ref_tuple(iTuple2, std::move(temp), std::make_integer_sequence<int, sizeof...(T)>{});
  }
}

template<class... Iterator>
class CATCDSZipIterator : private std::tuple<Iterator...>
{
public:
  using Base = std::tuple<Iterator...>;
  using Base::Base;

  CATCDSZipIterator & operator++()
  {
    Base& base = *this;
    cds::apply([](auto&& ...iterators) { cds::details::voidf(++iterators...); }, base);
    return *this;
  }

  CATCDSZipIterator & operator++(int)
  {
    Base& base = *this;
    cds::apply([](auto&& ...iterators) { cds::details::voidf(iterators++...); }, base);
    return *this;
  }

  CATCDSZipIterator & operator+=(std::int64_t n)
  {
    Base& base = *this;
    cds::apply([n](auto&& ...iterators) { cds::details::voidf(iterators += n...); }, base);
    return *this;
  }

  CATCDSZipIterator operator+(std::int64_t n)
  {
    auto res(*this);
    return res += n;
  }

  CATCDSZipIterator & operator--()
  {
    Base& base = *this;
    cds::apply([](auto&& ...iterators) { cds::details::voidf(--iterators...); }, base);
    return *this;
  }

  CATCDSZipIterator & operator--(int)
  {
    Base& base = *this;
    cds::apply([](auto&& ...iterators) { cds::details::voidf(iterators--...); }, base);
    return *this;
  }

  CATCDSZipIterator & operator-=(std::int64_t n)
  {
    Base& base = *this;
    cds::apply([n](auto&& ...iterators) { cds::details::voidf(iterators -= n...); }, base);
    return *this;
  }

  CATCDSZipIterator operator-(std::int64_t n)
  {
    auto res(*this);
    return res -= n;
  }

  auto operator*() const
  {
    Base const& base = *this;
    return cds::apply([](auto&& ...iterators) { return std::forward_as_tuple(*iterators...); }, base);    
  }

  /*decltype(auto) operator->() const
  {
    return *_iterator;
  }*/

  bool operator==(CATCDSZipIterator const & iIterator) const
  {
    if constexpr (!std::is_same<CATCDSIndexIterator, std::tuple_element_t<0, Base>>::value)
    {
      return std::get<0>(*this) == std::get<0>(iIterator);
    }
    else
    {
      return std::get<1>(*this) == std::get<1>(iIterator);
    }
  }

  bool operator!=(CATCDSZipIterator const & iIterator) const
  {
    return !(*this == iIterator);
  }

  bool operator<(CATCDSZipIterator const & iIterator) const
  {
    if constexpr (!std::is_same<CATCDSIndexIterator, std::tuple_element_t<0, Base>>::value)
    {
      return std::get<0>(*this) < std::get<0>(iIterator);
    }
    else
    {
      return std::get<1>(*this) < std::get<1>(iIterator);
    }
  }

  bool operator<=(CATCDSZipIterator const & iIterator) const
  {
    return !(iIterator < *this);
  }

  bool operator>(CATCDSZipIterator const & iIterator) const
  {
    return iIterator < *this;
  }

  bool operator>=(CATCDSZipIterator const & iIterator) const
  {
    return !(*this < iIterator);
  }

  auto operator-(CATCDSZipIterator const &iIterator) const
  {
    if constexpr (!std::is_same<CATCDSIndexIterator, std::tuple_element_t<0, Base>>::value)
    {
      return std::get<0>(*this) - std::get<0>(iIterator);
    }
    else
    {
      return std::get<1>(*this) - std::get<1>(iIterator);
    }
  }

  auto operator[](int n) const
  {
    Base const& base = *this;
    return cds::apply([n](auto&& ...iterators) { return std::forward_as_tuple(iterators[n]...); }, base);
  }

  using difference_type = std::conditional_t<std::is_same<CATCDSIndexIterator, std::tuple_element_t<0, Base>>::value, typename std::iterator_traits<std::tuple_element_t<1, Base>>::difference_type, typename std::iterator_traits<std::tuple_element_t<0, Base>>::difference_type>;
  using value_type = std::tuple<typename std::iterator_traits<Iterator>::value_type...>;
  using pointer = void;
  using reference = std::tuple<typename std::iterator_traits<Iterator>::reference...>;;
  // Si toutes les iterator_category sont de type random_access_iterator_tag on hérite cette propriété sinon on sélectionne forward_iterator_tag (pas très propre :-p)
  using iterator_category = std::conditional_t<(... && std::is_same<typename std::iterator_traits<Iterator>::iterator_category, std::random_access_iterator_tag>::value),
    std::random_access_iterator_tag, std::forward_iterator_tag>;
};

template<class... Iterator>
auto ZipIterator(Iterator const&... iterators)
{
  return CATCDSZipIterator<Iterator...>(iterators...);
}

template<class... Range>
class CATCDSZipRange : private std::tuple<Range...>
{
public:
  using Base = std::tuple<Range...>;
  using Base::Base;

  auto begin()
  {
    Base &base = *this;
    return cds::apply([](auto& ...range) { return ZipIterator(range.begin()...); }, base);
  }

  auto end()
  {
    Base &base = *this;
    return cds::apply([](auto& ...range) { return ZipIterator(range.end()...); }, base);
  }
};

template<class... Ranges>
auto ZipRange(Ranges&&... ranges)
{
  return CATCDSZipRange<Ranges...>(std::forward<Ranges>(ranges)...);
}

inline CATCDSIndexRange IndexRange(int iStart = 0)
{
  return CATCDSIndexRange{ iStart , iStart };
}

inline CATCDSIndexRange IndexRange(int iStart, int iEnd)
{
  return CATCDSIndexRange{ iStart , iEnd };
}

inline CATCDSIndexRange IndexRange(std::pair<int, int> const &iRange)
{
  return CATCDSIndexRange{ iRange.first , iRange.second };
}

template<class Range>
auto IndexRange(Range &&range)
{
  return ZipRange(IndexRange(), std::forward<Range>(range));
}


template<class Iterator>
class CATCDSIndirectIterator
{
public:
  using Base = Iterator;
  using Base::Base;

  CATCDSIndirectIterator & operator++()
  {
    ++_iterator;
    return *this;
  }

  CATCDSIndirectIterator & operator++(int n)
  {
    _iterator++;
    return *this;
  }

  CATCDSIndirectIterator & operator+=(std::int64_t n)
  {
    _iterator += n;
    return *this;
  }

  CATCDSIndirectIterator operator+(std::int64_t n)
  {
    auto res(*this);
    return res += n;
  }

  CATCDSIndirectIterator & operator--()
  {
    --_iterator;
    return *this;
  }

  CATCDSIndirectIterator & operator--(int n)
  {
    _iterator--;
    return *this;
  }

  CATCDSIndirectIterator & operator-=(std::int64_t n)
  {
    _iterator -= n;
    return *this;
  }

  CATCDSIndirectIterator operator-(std::int64_t n)
  {
    auto res(*this);
    return res -= n;
  }

  decltype(auto) operator*() const
  {
    return **_iterator;
  }

  decltype(auto) operator->() const
  {
    return *_iterator;
  }

  bool operator==(CATCDSIndirectIterator const & iIterator) const
  {
    return _iterator == iIterator._iterator;
  }

  bool operator!=(CATCDSIndirectIterator const & iIterator) const
  {
    return _iterator != iIterator._iterator;
  }

  bool operator<(CATCDSIndirectIterator const & iIterator) const
  {
    return _iterator < iIterator._iterator;
  }

  bool operator<=(CATCDSIndirectIterator const & iIterator) const
  {
    return _iterator <= iIterator._iterator;
  }

  bool operator>(CATCDSIndirectIterator const & iIterator) const
  {
    return _iterator > iIterator._iterator;
  }

  bool operator>=(CATCDSIndirectIterator const & iIterator) const
  {
    return _iterator >= iIterator._iterator;
  }

  auto operator-(CATCDSIndirectIterator const &iIterator) const
  {
    iIterator._iterator - _iterator;
  }

  decltype(auto) operator[](int n) const
  {
    return *_iterator[n];
  }

  using difference_type = typename std::iterator_traits<Iterator>::difference_type;
  //using pointer = void;
  using reference = decltype(**static_cast<CATCDSIndirectIterator*>(nullptr));
  using value_type = std::remove_reference_t<reference>;
  using iterator_category = typename std::iterator_traits<Iterator>::iterator_category;

private:
  Iterator _iterator;
};

template<class Iterator>
auto IndirectIterator(Iterator &&iIterator)
{
  return CATCDSIndirectIterator<Iterator>(std::forward(iIterator));
}

template<class Range>
class CATCDSIndirectRange : private Range
{
public:
  using Base = Range;
  using Base::Base;

  auto begin()
  {
    Base &base = *this;
    return IndirectIterator(base.begin());
  }

  auto end()
  {
    Base &base = *this;
    return IndirectIterator(base.end());
  }
};

template<class Range>
auto IndirectRange(Range &&iRange)
{
  return CATCDSIndirectRange<Range>(std::forward(iRange));
}

#if 1

template<class... Range>
class CATCDSJoinRange;

template<class... Type>
class CATCDSJoinIterator
{
private:
  static constexpr int size = sizeof...(Type);
  static constexpr int last = sizeof...(Type) - 1;

  using Range = CATCDSJoinRange<std::tuple_element_t<0, Type>...>;

  template<int n, class Iterator>
  struct FlagIterator : public std::integral_constant<int, n> { FlagIterator(Iterator value) : _value(value) {} Iterator _value; };

  template<int n>
  using range_descriptor_t = std::tuple_element_t<n, std::tuple<Type...>>;

  template<int n>
  using range_t = std::tuple_element_t<0, range_descriptor_t<n>>;

  template<int n>
  using iterator_begin_t = std::tuple_element_t<1, range_descriptor_t<n>>;

  template<int n>
  using iterator_end_t = std::tuple_element_t<2, range_descriptor_t<n>>;

  using sentinel_t = iterator_end_t<last>;

  template<class> struct variant_traits;
  template<int... Ints> struct variant_traits<std::integer_sequence<int, Ints...>> { using type = cds::variant<FlagIterator<Ints, iterator_begin_t<Ints>>...>; };

  using variant_t = typename variant_traits<std::make_integer_sequence<int, size>>::type;

public:
  CATCDSJoinIterator(Range const &iRange)
    : _pRange(&iRange)
    , _iterator(FlagIterator<0, iterator_begin_t<0>>{iRange.template get<0>().begin()})
  {}

  CATCDSJoinIterator & operator++()
  {
    Validate();
    cds::visit([](auto& iterator) { ++iterator._value; }, _iterator);
    return *this;
  }

  CATCDSJoinIterator & operator++(int)
  {
    Validate();
    cds::visit([](auto& iterator) { iterator._value++; }, _iterator);
    return *this;
  }

  decltype(auto) operator*() const
  {
    return cds::visit([](auto const& iterator) -> decltype(*std::declval<iterator_begin_t<0>>()) { return *iterator._value; }, _iterator);
  }

  decltype(auto) operator->() const
  {
    return cds::visit([](auto const& iterator) { return iterator._value; }, _iterator);
  }

  bool operator==(sentinel_t const & iSentinel) const
  {
    Validate();
    return cds::visit([&iSentinel](auto const &iterator)
    {
      using T = std::decay_t<decltype(iterator)>;
      if constexpr (T::value == last)
      {
        return iterator._value == iSentinel;
      }
      else
      {
        return false;
      }
    }, _iterator);
  }

  bool operator!=(sentinel_t const & iSentinel) const
  {
    return !(*this == iSentinel);
  }

private:
  void Validate() const
  {
    cds::visit([this](auto const &iterator)
    {
      using T = std::decay_t<decltype(iterator)>; 
      Validate<T::value>();
    }, _iterator);
  }

  template<int n>
  void Validate() const
  {
    if constexpr (n < last)
    {
      if (std::get<n>(_iterator)._value == _pRange->template get<n>().end())
      {
        FlagIterator<n + 1, iterator_begin_t<n + 1>> f{ _pRange->template get<n + 1>().begin() };
        _iterator = f;
        Validate<n + 1>();
      }
    }
  }

  Range const *_pRange = nullptr;
  mutable variant_t _iterator;
};

template<class... Range>
class CATCDSJoinRange : private std::tuple<Range...>
{
public:
  using Base = std::tuple<Range...>;
  using Base::Base;

  template<int n>
  decltype(auto) get() const
  {
    Base const &base = *this;
    return std::get<n>(base);
  }

  template<int n>
  decltype(auto) get()
  {
    Base &base = *this;
    return std::get<n>(base);
  }

  using Iterator = CATCDSJoinIterator<
    std::tuple<Range,
      std::remove_reference_t<decltype(static_cast<std::remove_reference_t<Range>*>(nullptr)->begin())>,
      std::remove_reference_t<decltype(static_cast<std::remove_reference_t<Range>*>(nullptr)->end())>>...>;

  auto begin() const
  {
    return Iterator(*this);
  }

  auto end() const
  {
    return get<sizeof...(Range) - 1>().end();
  }
};

template<class... Range>
auto JoinRange(Range &&... iRange)
{
  return CATCDSJoinRange<Range...>(std::forward<Range>(iRange)...);
}

template<class Range, class Op>
class CATCDSTransformRange;

template<class Range, class Iterator, class Op>
class CATCDSTransformIterator
{
public:
  CATCDSTransformIterator(Iterator const &iIterator, CATCDSTransformRange<Range, Op> const *ipRange)
    : _iterator(iIterator)
    , _pRange(ipRange)
  {}

  CATCDSTransformIterator & operator++()
  {
    ++_iterator;
    return *this;
  }

  CATCDSTransformIterator & operator++(int n)
  {
    _iterator++;
    return *this;
  }

  CATCDSTransformIterator & operator+=(std::int64_t n)
  {
    _iterator += n;
    return *this;
  }

  CATCDSTransformIterator operator+(std::int64_t n)
  {
    auto res(*this);
    return res += n;
  }

  CATCDSTransformIterator & operator--()
  {
    --_iterator;
    return *this;
  }

  CATCDSTransformIterator & operator--(int n)
  {
    _iterator--;
    return *this;
  }

  CATCDSTransformIterator & operator-=(std::int64_t n)
  {
    _iterator -= n;
    return *this;
  }

  CATCDSTransformIterator operator-(std::int64_t n)
  {
    auto res(*this);
    return res -= n;
  }

  decltype(auto) operator*() const
  {
    return _pRange->_data(*_iterator);
  }

  bool operator==(CATCDSTransformIterator const & iIterator) const
  {
    return _iterator == iIterator._iterator;
  }

  bool operator!=(CATCDSTransformIterator const & iIterator) const
  {
    return _iterator != iIterator._iterator;
  }

  bool operator<(CATCDSTransformIterator const & iIterator) const
  {
    return _iterator < iIterator._iterator;
  }

  bool operator<=(CATCDSTransformIterator const & iIterator) const
  {
    return _iterator <= iIterator._iterator;
  }

  bool operator>(CATCDSTransformIterator const & iIterator) const
  {
    return _iterator > iIterator._iterator;
  }

  bool operator>=(CATCDSTransformIterator const & iIterator) const
  {
    return _iterator >= iIterator._iterator;
  }

  auto operator-(CATCDSTransformIterator const &iIterator) const
  {
    iIterator._iterator - _iterator;
  }

  bool operator==(Iterator const & iIterator) const
  {
    return _iterator == iIterator;
  }

  bool operator!=(Iterator const & iIterator) const
  {
    return _iterator != iIterator;
  }

  decltype(auto) operator[](int n) const
  {
    return _pRange->_data(_iterator[n]);
  }

private:
  Iterator _iterator;
  CATCDSTransformRange< Range, Op> const *_pRange = nullptr;
};

template<class Range, class Op>
class CATCDSTransformRange
{
public:
  CATCDSTransformRange(Range range, Op op)
    : _data(std::forward<Range>(range), std::move(op))
  {}

  auto begin()
  {
    using Iterator = std::remove_reference_t<decltype(_data._range.begin())>;
    return CATCDSTransformIterator<Range, Iterator, Op>(_data._range.begin(), this);
  }

  auto end()
  {
    using Iterator = std::remove_reference_t<decltype(_data._range.end())>;
    return CATCDSTransformIterator<Range, Iterator, Op>(_data._range.end(), this);
  }

  struct Data : public Op
  {
    Data(Range range, Op op)
      : Op(std::move(op))
      , _range(std::forward<Range>(range))
    {}

    Range _range;
  } _data;
};

template<class Range, class Op>
auto TransformRange(Range&& iRange, Op op)
{
  return CATCDSTransformRange<Range, Op>(std::forward<Range>(iRange), std::move(op));
}

template<class Range, class MemberClass, class MemberType>
auto MemberRange(Range&& iRange, MemberType MemberClass::* ipMemberPointer)
{
  return TransformRange(std::forward<Range>(iRange), [ipMemberPointer](auto& e)
  {
    return e.*ipMemberPointer;
  });
}

#endif

#endif
