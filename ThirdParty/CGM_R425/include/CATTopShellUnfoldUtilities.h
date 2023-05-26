/*
=============================================================================

 COPYRIGHT   : DASSAULT SYSTEMES 2008
 
 DESCRIPTION : 

=============================================================================
*/

// <ClassName>: CATTopShellUnfoldUtilities
//
//=============================================================================
// Usage Notes: 
//            
//=============================================================================
// Jan 2008 Creation                   SUH
//=============================================================================

//BUGBUG document well

#ifndef CATTopShellUnfoldUtilities_H
#define CATTopShellUnfoldUtilities_H

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGeoFactory;
class CATShell;
class CATSurface;
class CATMathTransformation2D;
class CATSoftwareConfiguration;
class CATCurve;
class CATSurLimits;
class CATCrvLimits;
class CATPCurve;

#include "FrFTopologicalOpe.h" // exported by

#include "CATListOfCATPCurves.h"
#include "CATListOfCATCrvLimits.h"
#include "ListPOfCATFace.h"
#include "CATBoolean.h"
#include "CATMathSetOfPointsND.h"

class ExportedByFrFTopologicalOpe CATTopShellUnfoldUtilities
{
public:
  static       void       PrepareInputsForUnfoldTransfer(CATGeoFactory            *  iFactory              ,
                                                         CATTopData               *  iTopData              ,
                                                         CATBody                  *  iBody                 ,
                                                         CATBody                  *  iFlattenedBody        ,
                                                         CATLISTP(CATFace)         & ioListOfInputFaces    ,
                                                         CATLISTP(CATFace)         & ioListOfFlattenedFaces,
                                                         CATShell                 *& oShell                );

  //returns 0 on successful transfer of all p-curves to iTargetSurface, that is ioResultPCurves.Size = iInputPCurves.Size
  static       int        TransferPCurves               (CATSoftwareConfiguration *  iSoftConfig           ,
                                                         CATLISTP(CATPCurve)       & ioResultPCurves       ,
                                                         CATLISTP(CATPCurve)       & iInputPCurves         ,
                                                         CATLISTP(CATCrvLimits)    & iInputLimits          ,
                                                         CATSurface               *  iTargetSurface        ,
                                                         CATMathTransformation2D  *  iMathTransformation2D = NULL,
                                                         double                      iTol                  = -1);

  static       CATBoolean GetWireData                   (CATSoftwareConfiguration *  iSoftConfig           ,
                                                         CATBody                  *  iWire                 ,
                                                         double                   *  oMaxGap               );

  static       void       ProjectCurveOnSurface         (CATGeoFactory            *  ipFactory             ,
                                                         CATSoftwareConfiguration *  ipConfig              ,
                                                         CATCurve                 *  ipCurve               ,
                                                         CATSurface               *  ipSurface             ,
                                                   const CATSurLimits              & ipFaceLimits          ,
                                                   const CATCrvLimits              & ipEdgeLimits          ,
                                                         CATPCurve                *& opPCurve              );

  //allowed maximum deviation of result depending on the iBody
  static       double     GetMaxDeviation               (CATBody                  * iBody                 );

  //allowed maximum assembly tolerance for skin and wire
  static       double     GetMaxAsslyTolerance          (CATGeoFactory            * iFactory              );

  // Calculate relative waviness
  static double ComputeWaviness(CATCurve * irefCurve, CATCurve * iotherCurve, CATGeoFactory * pFactory/*, int method = 1*/);

  //static double HausdorffDistance(CATMathSetOfPointsND * setA, CATMathSetOfPointsND * setB, double &oMeanDistance);

  // it is users responsibility to delete returned intersection points
  static CATMathSetOfPointsND * FindIntersectionPoints(CATMathSetOfPointsND * setA, CATMathSetOfPointsND * setB, CATListOfInt &indexOfPointswrtSetA);

  static double ComputeWaviness(CATMathSetOfPointsND * ipPoints, CATGeoFactory* ipFactory);

  //for FrFUnfold, this is the ratio of max allowed deviation to the size of the model. The idea is to have maximum 0.1mm deviation on 20m plates.
  static const double     _DeviationFactor;

private:
  //for FrFUnfold, this is the maximum gap allowed in the internal edges/vertices of the result shell/result wire before any healing  
  static const double     _MaxAsslyTolerance;
};

#endif
