#ifndef CATCDSStringHash_H
#define CATCDSStringHash_H

#include "CATCDSString.h"

namespace std
{
  template<>
  struct hash<CATCDSString>
  {
    std::size_t operator()(CATCDSString const &iS) const
    {
      return CATCDSStringHashIt(iS);
    }
  };
}

#endif
