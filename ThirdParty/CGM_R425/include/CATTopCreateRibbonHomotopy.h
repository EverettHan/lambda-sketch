/* -*-C++-*- */

#ifndef CATTopCreateRibbonHomotopy_H
#define CATTopCreateRibbonHomotopy_H

// COPYRIGHT DASSAULT SYSTEMES 2001
// FCH may 2002

#include "BODYNOPE.h"
#include "CATTopRibbonHomotopy.h"


class CATGeoFactory;
class CATBody;
class CATEdge;
class CATMathPoint;
class CATTopData;
class CATConnectTool;
class CATIPGMConnectTool;

ExportedByBODYNOPE CATTopRibbonHomotopy  * CATTopCreateRibbonHomotopy(CATGeoFactory *iFactory, 
                                                                      CATTopData* iTopData,
                                                                      CATBody * iBody, 
                                                                      CATEdge * iEdge, 
                                                                      const CATMathPoint & iPoint,
                                                                      const CATConnectTool * iProfilePtr);

/* @nocgmitf */
ExportedByBODYNOPE CATTopRibbonHomotopy  * CATTopCreateRibbonHomotopy(CATGeoFactory *iFactory, 
                                                                      CATTopData* iTopData,
                                                                      CATBody * iBody, 
                                                                      CATEdge * iEdge, 
                                                                      const CATMathPoint & iPoint,
                                                                      CATIPGMConnectTool * iProfilePtr);

ExportedByBODYNOPE CATTopRibbonHomotopy  * CATTopCreateRibbonHomotopy(CATGeoFactory *iFactory, 
                                                                      CATTopData* iTopData,
                                                                      CATBody * iBody, 
                                                                      CATFace * iLeftFace,
                                                                      CATFace * iRightFace,
                                                                      CATFace * iCentreFace,
                                                                      const CATOrientation *iOri,
                                                                      const CATMathDirection * iDir,
                                                                      const CATMathPoint & iPoint,
                                                                      const CATConnectTool * iProfilePtr);

/* @nocgmitf */
ExportedByBODYNOPE CATTopRibbonHomotopy  * CATTopCreateRibbonHomotopy(CATGeoFactory *iFactory, 
                                                                      CATTopData* iTopData,
                                                                      CATBody * iBody, 
                                                                      CATFace * iLeftFace,
                                                                      CATFace * iRightFace,
                                                                      CATFace * iCentreFace,
                                                                      const CATOrientation *iOri,
                                                                      const CATMathDirection * iDir,
                                                                      const CATMathPoint & iPoint,
                                                                      CATIPGMConnectTool * iProfilePtr);

ExportedByBODYNOPE CATTopRibbonHomotopy  * CATTopCreateRibbonHomotopy(CATGeoFactory *iFactory, 
                                                                      CATTopData* iTopData,
                                                                      CATBody * iBody, 
                                                                      CATFace * iLeftFace,
                                                                      CATFace * iRightFace,
                                                                      CATFace * iCentreFace,
                                                                      const CATMathDirection * iDir,
                                                                      const CATMathPoint & iPoint,
                                                                      const CATConnectTool * iProfilePtr);

/* @nocgmitf */
ExportedByBODYNOPE CATTopRibbonHomotopy  * CATTopCreateRibbonHomotopy(CATGeoFactory *iFactory, 
                                                                      CATTopData* iTopData,
                                                                      CATBody * iBody, 
                                                                      CATFace * iLeftFace,
                                                                      CATFace * iRightFace,
                                                                      CATFace * iCentreFace,
                                                                      const CATMathDirection * iDir,
                                                                      const CATMathPoint & iPoint,
                                                                      CATIPGMConnectTool * iProfilePtr);


#endif
