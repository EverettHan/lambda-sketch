#ifndef CATCDSAggregateReflection_H
#define CATCDSAggregateReflection_H

// Reflection functionnalities for aggregate class based on Antony Polukhin ideas
// https://github.com/apolukhin/magic_get

#include <utility>
#include <type_traits>
#include <tuple>

namespace cds
{
  namespace details
  {
    // Small class which is always convertible to any type
    class Ubiq
    {
    public:
      int dummy;

      template<class T>
      constexpr operator T&&() const;
    };

    template<class T, class U>
    class ForgetFirst
    {
    public:
      using type = U;
    };

    template<class Aggregate, int index0, int... indexes>
    constexpr typename ForgetFirst<decltype(Aggregate{ Ubiq{index0}, Ubiq{indexes}... }), int>::type CountFields(std::integer_sequence<int, index0, indexes...>)
    {
      return sizeof...(indexes) + 1;
    }

    template<class Aggregate, int... indexes>
    constexpr int CountFields(std::integer_sequence<int, indexes...>)
    {
      return CountFields<Aggregate>(std::make_integer_sequence<int, sizeof...(indexes) - 1>());
    }


    template<class Aggregate, int n>
    auto AggregateToTuple(Aggregate &&iAggregate)
    {
      if constexpr (n == 1)
      {
        auto&&[t1] = std::move(iAggregate);
        return std::make_tuple(std::move(t1));
      } 
      else if constexpr (n == 2)
      {
        auto&&[t1, t2] = std::move(iAggregate);
        return std::make_tuple(std::move(t1), std::move(t2));
      }
      else if constexpr (n == 3)
      {
        auto&&[t1, t2, t3] = std::move(iAggregate);
        return std::make_tuple(std::move(t1), std::move(t2), std::move(t3));
      }
      else if constexpr (n == 4)
      {
        auto&&[t1, t2, t3, t4] = std::move(iAggregate);
        return std::make_tuple(std::move(t1), std::move(t2), std::move(t3), std::move(std::move(t4)));
      }
      else if constexpr (n == 5)
      {
        auto&&[t1, t2, t3, t4, t5] = std::move(iAggregate);
        return std::make_tuple(std::move(t1), std::move(t2), std::move(t3), std::move(t4), std::move(t5));
      }
      else if constexpr (n == 6)
      {
        auto&&[t1, t2, t3, t4, t5, t6] = std::move(iAggregate);
        return std::make_tuple(std::move(t1), std::move(t2), std::move(t3), std::move(t4), std::move(t5), std::move(t6));
      }
      else if constexpr (n == 7)
      {
        auto&&[t1, t2, t3, t4, t5, t6, t7] = std::move(iAggregate);
        return std::make_tuple(std::move(t1), std::move(t2), std::move(t3), std::move(t4), std::move(t5), std::move(t6), std::move(t7));
      }
      else if constexpr (n == 8)
      {
        auto&&[t1, t2, t3, t4, t5, t6, t7, t8] = std::move(iAggregate);
        return std::make_tuple(std::move(t1), std::move(t2), std::move(t3), std::move(t4), std::move(t5), std::move(t6), std::move(t7), std::move(t8));
      }
      else if constexpr (n == 9)
      {
        auto&&[t1, t2, t3, t4, t5, t6, t7, t8, t9] = std::move(iAggregate);
        return std::make_tuple(std::move(t1), std::move(t2), std::move(t3), std::move(t4), std::move(t5), std::move(t6), std::move(t7), std::move(t8), std::move(t9));
      }
      else if constexpr (n == 10)
      {
        auto&&[t1, t2, t3, t4, t5, t6, t7, t8, t9, t10] = std::move(iAggregate);
        return std::make_tuple(std::move(t1), std::move(t2), std::move(t3), std::move(t4), std::move(t5), std::move(t6), std::move(t7), std::move(t8), std::move(t9), std::move(t10));
      }
      else
      {
        static_assert(n <= 10, "Not implemented :-(");
        return 0;
      }
    }
  }

  // Count the number of field of the aggregate class/struct
  template<class Aggregate>
  constexpr int CountFields()
  {
    static_assert(std::is_aggregate<Aggregate>::value);
    return details::CountFields<Aggregate>(std::make_integer_sequence<int, sizeof(Aggregate)>());
  }

  namespace details
  {
    template<class Aggregate, int n = cds::CountFields<Aggregate>()>
    class AggregateTupleType
    {
    public:
      using type = decltype(details::AggregateToTuple<Aggregate, n>(std::declval<Aggregate>()));
    };
  }

  // Type of tuple equivalent to aggregate 
  // For struct {int _a; double _b; } aggregate_to_tuple_t is std::tuple<int, double>
  template<class Aggregate>
  using aggregate_to_tuple_t = typename details::AggregateTupleType<Aggregate>::type;
}

#endif
