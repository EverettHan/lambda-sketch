#ifndef __CATCkeScaleManagement_H
#define __CATCkeScaleManagement_H

#include "CATICkeMagnitude.h"
#include "CATICkeUnit.h"
#ifndef CATCkeScale_H
enum CATCkeScale
{
  CATNormalScale = 1,
  CATLargeScale = 2,
  CATExtraLargeScale = 3,
  CATSmallScale = 4,
  CATExtraSmallScale = 5,
  CATNanometricScale = 6
};
#define CATCkeScale_H
#endif

CATICkeUnit_var CATCkeGetDisplayUnit(const CATICkeMagnitude* iMagnitude, const CATBaseUnknown* iParm);
CATICkeUnit_var CATCkeGetDisplayUnit(const CATICkeMagnitude* iMagnitude, CATCkeScale iScale);

#endif
