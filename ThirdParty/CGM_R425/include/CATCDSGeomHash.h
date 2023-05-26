#ifndef CATCDSGeomHash_H
#define CATCDSGeomHash_H

#include "CATCDS3Point.h"
#include "CATCDS3Vector.h"
#include "CATCDSHashCombine.h"

namespace std
{
  template<>
  struct hash<CATCDS3Point>
  {
    std::size_t operator()(CATCDS3Point const &p) const
    {
      auto h = std::hash<double>()(p[0]);
      hash_combine(h, std::hash<double>()(p[1]));
      hash_combine(h, std::hash<double>()(p[2]));
      return h;
    }
  };

  template<>
  struct hash<CATCDS3Vector>
  {
    std::size_t operator()(CATCDS3Vector const &v) const
    {
      auto h = std::hash<double>()(v[0]);
      hash_combine(h, std::hash<double>()(v[1]));
      hash_combine(h, std::hash<double>()(v[2]));
      return h;
    }
  };
}

#endif
