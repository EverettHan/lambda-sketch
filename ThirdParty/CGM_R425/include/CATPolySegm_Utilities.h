//===================================================================
// Copyright Dassault Systemes Provence 2010-2019, All Rights Reserved
//===================================================================
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
// Juillet 2019 : ANR : Ajout de l'erreur Moyenne(pour reverse)
// 20 Dec 2010  Create by ANR 
//===================================================================

#ifndef CATPolySegm_Utilities_H
#define CATPolySegm_Utilities_H

#include "CATPolyCanonicOperators.h" 

#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATBoolean.h"
#include "CATIPolyMesh.h"
#include "CATMathPlane.h"


class ExportedByCATPolyCanonicOperators CATPolySegm_Utilities
{

public:

  CATPolySegm_Utilities(void) {};

  virtual ~CATPolySegm_Utilities(void) {};


  static int ComputeMeanPlane_P(int NbPoints, const double *VerticesCoords, CATMathPlane &oBasePlane, CATBoolean iTest = FALSE);

  static CATBoolean ReajustPlane(CATMathPlane &aPlane, int nbPnts, const double *iTabOfPoints,
                                 CATMathPoint& oP1, CATMathPoint& oP2, CATMathPoint& oP3, CATMathPoint& oP4, const double ioffset);

  //
  static CATBoolean DistancePtsToPlane_P(int iNbPoints, CATMathPoint *iTabOfPoints, CATMathPoint &iCenter,
                                         CATMathVector &iAxis, double iTolerance, double &oPourc, double &oMaxDist, double &oMeanDist);

  static CATBoolean DistancePtsToPlane_P(int iNbPoints, double *iTabOfCoords, CATMathPoint &iCenter,
                                         CATMathVector &iAxis, double iTolerance, double &oPourc, double &oMaxDist, double &oMeanDist);

  //
  static CATBoolean DistancePtsToCylinder_P(int iNbPoints, CATMathPoint *iTabOfPoints, double iRadius, CATMathPoint &iCenter,
                                            CATMathVector &iAxis, double iTolerance, double &oPourc, double &oMaxDist, double &oMeanDist);

  static CATBoolean DistancePtToCylinder_P(CATMathPoint &iPoint,  double iRadius, CATMathPoint &iCenter, CATMathVector &iAxis,
                                           double iTolerance, double &oDist);

  //
  static CATBoolean DistancePtsToCone_P(int iNbPoints, CATMathPoint *iTabOfPoints,  double iRadius1, double iRadius2,
                                        CATMathPoint &iCenter1, CATMathPoint &iCenter2, CATMathVector &iAxis, double iTolerance,
                                        double &oPourc, double &oMaxDist, double &oMeanDist);

  static CATBoolean DistancePtToCone_P(CATMathPoint &iPoint, double iRadius1, double iRadius2, CATMathPoint &iCenter1, CATMathPoint &iCenter2, CATMathVector &iAxis,
                                       double iTolerance, double &oDist);

  //
  static CATBoolean DistancePtsToSphere_P(int iNbPoints, CATMathPoint *iTabOfPoints, double iRadius, CATMathPoint &iCenter,
                                          double iTolerance, double &oPourc, double &oMaxDist, double &oMeanDist);

  static CATBoolean DistancePtToSphere_P(CATMathPoint &iPoint, double iRadius, CATMathPoint &iCenter, double iTolerance, double &oDist);

  //
  static CATBoolean DistancePtsToTorus_P(int iNbPoints, CATMathPoint *iTabOfPoints, double iSmallRadius, double iBigRadius,
                                         CATMathPoint &iCenter, CATMathVector &iAxis, double iTolerance, 
                                         double &oPourc, double &oMaxDist, double &oMeanDist);

  static CATBoolean DistancePtToTorus_P(CATMathPoint &iPoint, double iRadius1, double iRadius2, CATMathPoint &iCenter1, CATMathVector &iAxis,
                                        double iTolerance, double &oDist);

  //
  static CATBoolean DistancePtToFillet_P(CATMathPoint &iPoint,  double iRadius, CATMathPoint &iCenter, double iTolerance, 
                                        double &oMaxDist);

  //
  static CATBoolean IsSharpInMesh(CATIPolyMesh *iPolyMesh, double iTolSharp = 60);

  // Inspirer par le code de ZFI/NDO
  static CATBoolean DetectCircle(int nbVertices, CATMathPoint *iTabOfPts, CATBoolean iWithTestOption,
                                 double &oRadius, CATMathPoint &oCenter, CATMathVector &oAxis, double &oSag);

  //Sans le test sur le BoundingBox :
  static CATBoolean DetectBestCircle(int nbVertices, CATMathPoint *iTabOfPts,
                                     double &oRadius, CATMathPoint &oCenter, CATMathVector &oAxis, double &oSag);

private:
   
  static CATBoolean InertialFrame_P(const int      iNbPoints,
    const double*  iCoords,
    double         oBarycenter[3],
    double         oEigenValues[3],
    double         oEigenVectors[3][3]);


};

#endif
