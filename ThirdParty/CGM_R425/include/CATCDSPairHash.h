#ifndef CATCDSPairHash_H
#define CATCDSPairHash_H

#include "CATCDSHashCombine.h"

namespace std
{
  template<class T1, class T2>
  struct hash<std::pair<T1, T2>>
  {
    std::size_t operator()(std::pair<T1, T2> const &p) const
    {
      auto h = std::hash<T1>()(p.first);
      hash_combine(h, p.second);
      return h;
    }
  };
}

#endif
