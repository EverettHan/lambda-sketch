#ifndef _CATOxUntieParameters_H
#define _CATOxUntieParameters_H
/**
* @level Private
* @usage U1
*/

#include "CATBoolean.h"

class CATOxUntieParameters
{
public:
  void UntieOnlyPenetratingLinks() { _OnlyPenetratingLinks = TRUE; }

  CATBoolean _OnlyPenetratingLinks = FALSE;
};

#endif

