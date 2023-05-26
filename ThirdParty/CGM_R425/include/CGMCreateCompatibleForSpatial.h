#ifndef CGMCreateCompatibleForSpatial_h
#define CGMCreateCompatibleForSpatial_h
#include "CATTopologicalOperatorsLight.h"
  /**
* For Spatial use only.  *** Please do not use. *** 
**/
#include "ListPOfCATBody.h"
class CATGeoFactory;
class CATTopData;
class CATICGMTopCompatible;

ExportedByCATTopologicalOperatorsLight CATICGMTopCompatible *
CGMCreateCompatibleForSpatial(
  CATGeoFactory *iFactory, CATTopData *iTopData, CATLISTP(CATBody) * iBodyList);
#endif
