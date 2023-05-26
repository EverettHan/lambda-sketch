#ifndef CATCDSTupleHash_H
#define CATCDSTupleHash_H

#include "CATCDSHashCombine.h"

namespace std
{
  template<class... T>
  struct CATCDSHashUnpackedTuple;

  template<class T>
  struct CATCDSHashUnpackedTuple<T>
  {
    std::size_t operator()(T const &iT) const
    {
      return std::hash<T>()(iT);
    }
  };

  template<class H, class... Q>
  struct CATCDSHashUnpackedTuple<H, Q...>
  {
    std::size_t operator()(H const &iH, Q const &... iQ) const
    {
      auto h = CATCDSHashUnpackedTuple<Q...>()(iQ...);
      hash_combine(h, iH);
      return h;
    }
  };

  template<int... ints>
  struct CATCDSIntegerSequence
  {
  };

  template<int next, class Sequence>
  struct CATCDSAppendIntegerSequence;

  template<int next, int... ints>
  struct CATCDSAppendIntegerSequence<next, CATCDSIntegerSequence<ints...>>
  {

    typedef CATCDSIntegerSequence<ints..., next> type;
  };

  template<int S, int N>
  struct CATCDSMakeIntegerSequence
  {
    typedef typename CATCDSAppendIntegerSequence<N - 1, typename CATCDSMakeIntegerSequence<S, N - 1>::type>::type type;
  };

  template<int S>
  struct CATCDSMakeIntegerSequence<S, S>
  {
    typedef CATCDSIntegerSequence<> type;
  };

  template<class... T>
  struct hash<std::tuple<T...>>
  {
    template<int... ints>
    std::size_t operator()(std::tuple<T...> const &iTuple, CATCDSIntegerSequence<ints...>) const
    {
      return CATCDSHashUnpackedTuple<T...>()(std::get<ints>(iTuple)...);
    }

    std::size_t operator()(std::tuple<T...> const &iTuple) const
    {
      return (*this)(iTuple, typename CATCDSMakeIntegerSequence<0, sizeof...(T)>::type());
    }
  };
}

#endif
