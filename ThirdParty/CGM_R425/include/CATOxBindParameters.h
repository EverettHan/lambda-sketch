#ifndef _CATOxBindParameters_H
#define _CATOxBindParameters_H
/**
* @level Private
* @usage U1
*/
#include "CATBaseUnknown.h"
#include "CATBoolean.h"

class CATOxBindParameters
{
public:
  void BindNotLoaded() { _ForceLoading = TRUE; }
  void BindOnlyPenetratingLinks() { _OnlyPenetratingLinks = TRUE; }

  CATBoolean _OnlyPenetratingLinks = FALSE;
  CATBoolean _ForceLoading = FALSE;
};

#endif

