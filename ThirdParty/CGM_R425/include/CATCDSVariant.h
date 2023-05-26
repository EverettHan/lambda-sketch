#ifndef CATCDSVariant_H
#define CATCDSVariant_H

#if defined(_DARWIN_SOURCE) || defined(_ANDROID_SOURCE) || defined(_IOS_SOURCE)
#include <tuple>

namespace cds
{
  template<class... T>
  struct variant : public std::tuple<T...>
  {
    template<class U> variant(U&&) {}
    variant() = default;
    ~variant() = default; 
    variant(variant const&) = default;
    variant& operator=(variant const&) = default;

    std::size_t index() const {return 0;}
  };

  template<class Callback, class... Args>
  decltype(auto) invoke(Callback&& callback, Args&&... args)
  {
    return std::forward<Callback>(callback)(std::forward<Args>(args)...);
  }

  template<class T>
  struct variant_size : std::integral_constant<std::size_t, 1> {};

  namespace details
  {
    template<class Callback, class Tuple, std::size_t... indexes>
    decltype(auto) apply_imp(Callback&& callback, Tuple&& tuple, std::index_sequence<indexes...>)
    {
      //return invoke(std::forward<Callback>(callback), std::get<indexes>(std::forward<Tuple>(tuple))...);
      return std::forward<Callback>(callback)(std::get<indexes>(std::forward<Tuple>(tuple))...);
    }
  }

  template<class Callback, class Tuple>
  decltype(auto) apply(Callback&& callback, Tuple&& tuple)
  {
    return details::apply_imp(std::forward<Callback>(callback), std::forward<Tuple>(tuple), std::make_index_sequence<std::tuple_size<std::remove_reference_t<Tuple>>::value>());
  }

  namespace details
  {
    template<std::size_t index, std::size_t size,class Callback, class Variant>
    decltype(auto) visit_imp(Callback&& callback, Variant&& variant)
    {
      if constexpr (index + 1 == size)
      {
        return invoke(std::forward<Callback>(callback), std::get<index>(std::forward<Variant>(variant)));
      }
      else
      {
        if (variant.index() == index)
          //return invoke(std::forward<Callback>(callback), std::get<index>(std::forward<Variant>(variant)));
          return (std::forward<Callback>(callback))(std::get<index>(std::forward<Variant>(variant)));
        else
          return visit_imp<index + 1, size>(std::forward<Callback>(callback), std::forward<Variant>(variant));
      }
    }
  }

  template<class Callback, class Variant>
  decltype(auto) visit(Callback&& callback, Variant&& variant)
  {
    return details::visit_imp<0, variant_size<std::remove_reference_t<Variant>>::value>(std::forward<Callback>(callback), std::forward<Variant>(variant));
  }
  
  template<class Callback, class Variant1, class Variant2>
  decltype(auto) visit(Callback&& callback, Variant1&& variant1, Variant2&& variant2)
  {
    return std::forward<Callback>(callback)(std::get<0>(std::forward<Variant1>(variant1)), std::get<0>(std::forward<Variant2>(variant2)));
  }
}
#else
#include <variant>

namespace cds
{
  template<class... T>
  using variant = std::variant<T...>;

  template<class Callback, class Tuple>
  decltype(auto) apply(Callback&& callback, Tuple&& tuple)
  {
    return std::apply(std::forward<Callback>(callback), std::forward<Tuple>(tuple));
  }

  template<class Callback, class Variant>
  decltype(auto) visit(Callback&& callback, Variant&& variant)
  {
    return std::visit(std::forward<Callback>(callback), std::forward<Variant>(variant));
  }
  
  template<class Callback, class Variant1, class Variant2>
  decltype(auto) visit(Callback&& callback, Variant1&& variant1, Variant2&& variant2)
  {
    return std::visit(std::forward<Callback>(callback), std::forward<Variant1>(variant1), std::forward<Variant2>(variant2));
  }
}
#endif

#endif
