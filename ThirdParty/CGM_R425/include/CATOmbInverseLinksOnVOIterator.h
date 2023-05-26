#ifndef CATOmbInverseLinksOnVOIterator_H
#define CATOmbInverseLinksOnVOIterator_H

#include "IUnknown.h"
#include "CATBaseUnknown.h"
#include "CATObjectModelerBase.h"

class CATILinkableObject;

// Obsolete, do not use.
class CATOmbInverseLinksOnVOIterator
{
public:
  CATOmbInverseLinksOnVOIterator(CATILinkableObject & iDoNotUse) {}
  ~CATOmbInverseLinksOnVOIterator() {}

  void operator++ () {}
  void operator++ (int) {}

  CATBaseUnknown * operator() () { return nullptr; }
};

#endif
