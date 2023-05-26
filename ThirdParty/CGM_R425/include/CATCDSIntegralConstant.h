#ifndef CATCDSIntegralConstant_H
#define CATCDSIntegralConstant_H

#include <type_traits>

namespace cds
{
  namespace details
  {
    template<int Value, char... N>
    class integral_constant;

    template<int Value, char N>
    class integral_constant<Value, N>
    {
    public:
      using type = std::integral_constant<int, 10 * Value + (N - '0')>;
    };

    template<int Value, char Head, char... Tail>
    class integral_constant<Value, Head, Tail...>
    {
    public:
      using type = std::integral_constant<int, integral_constant<10 * Value + (Head - '0'), Tail...>::type::value>;
    };
  }
}

template<char... digits>
auto operator "" _c()
{
  return typename cds::details::integral_constant<0, digits...>::type();
}

#endif
