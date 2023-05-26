#ifndef CATCreateTopSkin_h
#define CATCreateTopSkin_h

// COPYRIGHT DASSAULT SYSTEMES  1999
// interdit a l'usage hormis en cas d'imperieuse necessite

#include "CATTopSkin.h"
#include "CATMathBox.h"
#include "PrimitivesLight.h"
class CATPlane;
class CATTopData;

// to delete
ExportedByPrimitivesLight
CATTopSkin * CATCreateTopSkin    (CATGeoFactory      * iFactory   ,
                                  CATTopData         * iTopData   ,
                                  CATPlane           * plane      ,
                                  CATMathBox         & iBox       );

// to keep
ExportedByPrimitivesLight
CATTopSkin * CATCreateTopOldSkin (CATGeoFactory      * iFactory   ,
                                  CATTopData         * iTopData   ,
                                  CATPlane           * plane      ,
                                  CATMathBox         & iBox       ,
                                  CATBody            * TargetBody = NULL);

ExportedByPrimitivesLight
CATTopSkin * CATCreateTopOldSkin (CATGeoFactory      * iFactory   ,
                                  CATTopData         * iTopData   ,
                                  CATSurface         * iSurface   ,
                                  int                  iNbPcurves ,
                                  CATPCurve         ** iPcurves   ,
                                  CATBody            * TargetBody = NULL);

ExportedByPrimitivesLight
CATTopSkin * CATCreateTopOldSkin (CATGeoFactory      * iFactory   ,
                                  CATTopData         * iTopData   ,
                                  CATSurface         * iSurface   ,
                                  int                  iNbPcurves ,
                                  CATPCurve         ** iPcurves   ,
                                  CATCrvLimits       * iLims      ,
                                  CATBody            * TargetBody = NULL);

#endif
