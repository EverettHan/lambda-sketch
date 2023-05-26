#ifndef CATCDSReallocableTrait_H
#define CATCDSReallocableTrait_H

#include "CATCDSCPlusPlusVersions.h"

#ifdef CPP17_AVAILABLE
// Linux does not like much
//#include "CATCDSAggregateReflection.h"
#endif

#include <type_traits>
#include <memory>
#include <tuple>
#include <utility>

template<class T>
class CATDynFunctionPtr;

template<class T>
class CATDynSharedPtr;

template<class T>
class CATDynUniquePtr;

namespace cds
{
template<class T, std::size_t... Dim>
class array;
}

// You can inherit of this class if you want to declare your class as reallocable.
// Be careful no check are performed.
class CATCDSReallocable {};

namespace cds
{
  // is_reallocable<T>::value must be specialized for structures which are not trivially copiable
  // but can be moved with a mempcy without destruction of copied data.
  // Typically smart pointers fall into this category.
  // It enables more optimized code for CATCDSArray::Reserve
  // When declared specialization must occur before CATCDSArray definition.

  // default value is false_type
  template<class T> class is_reallocable;

#ifdef CPP17_AVAILABLE
  template<class T> inline constexpr bool is_reallocable_v = is_reallocable<T>::value;
#endif

  namespace details
  {
    //template<class T, class Enable = void> class is_reallocable_aggregate : public std::false_type {};
#ifdef CPP17_AVAILABLE
    //template<class T> class is_reallocable_aggregate<T, std::enable_if_t<std::is_aggregate<T>::value>> : public is_reallocable<aggregate_to_tuple_t<T>> {};
#endif
  }

  // specialization for trivial class
  //template<class T> class is_reallocable : public std::conditional_t<(std::is_trivial<T>::value || details::is_reallocable_aggregate<T>::value), std::true_type, std::false_type> {};
  template<class T> class is_reallocable : public std::is_base_of<CATCDSReallocable, T> {};

  // specialization for smart pointers type
  template<class T> class is_reallocable<std::unique_ptr<T>> : public std::true_type {};
  template<class T> class is_reallocable<std::shared_ptr<T>> : public std::true_type {};
  template<class T> class is_reallocable<CATDynFunctionPtr<T>> : public std::true_type {};
  template<class T> class is_reallocable<CATDynSharedPtr<T>> : public std::true_type {};
  template<class T> class is_reallocable<CATDynUniquePtr<T>> : public std::true_type {};

  // cds::array
  template<class T, std::size_t... Dim> class is_reallocable<cds::array<T, Dim...>> : public is_reallocable<T> {};

  // specialization for pair and tuple
//#ifdef CPP17_AVAILABLE
#if 0
  template<class T1, class T2> class is_reallocable<std::pair<T1, T2>> : public std::conjunction<is_reallocable<T1>, is_reallocable<T2>> {};
  template<class... T> class is_reallocable<std::tuple<T...>> : public std::conjunction<is_reallocable<T>...> {};
#else
  template<class T1, class T2> class is_reallocable<std::pair<T1, T2>> : public std::integral_constant<bool, is_reallocable<T1>::value && is_reallocable<T2>::value> {};

  namespace details
  {
    template<bool... b> class all;
    template<> class all<> : public std::true_type {};
    template<bool... b> class all<true, b...> : public all<b...> {};
    template<bool... b> class all<false, b...> : public std::false_type {};
  }

  template<class... T> class is_reallocable<std::tuple<T...>> : public std::integral_constant<bool, details::all<is_reallocable<T>::value...>::value> {};
#endif
}

#endif
