// COPYRIGHT DASSAULT SYSTEMES 1997 
//==========================================================================
//
// CATFrFAnalyseCrvCrv
// 
//==========================================================================
//
// Usage notes:
//
//========================================================================== 
// May  1999     design, for internal debug use              PRG
// Oct. 2000     interface/implementation                    PRG
//               several construction global functions
// this class is designed to measure continuity between two curves
// there are several way to use it :
//    1/ we do not know the position of the curves,
//    in that case, we compute the minimum distance points
//    2/ we compare the endpoints of the curves (start or end must be input)
//    3/ we compare the continuity between two points that are given thanks
//    to CATCrvParam.
//  Oct. 2003    Mis en commentaire via define FrFNotUsed    NDN
//========================================================================== 
#ifdef FrFNotUsed


#ifndef CATFrFAnalyseCrvCrv_H
#define CATFrFAnalyseCrvCrv_H

#include "FrFAdvancedOpeCrv.h"
#include "CATCGMVirtual.h"

class CATGeoFactory;
class CATCartesianPoint;

class CATCurve;
class CATCrvParam;
class CATMathPoint;
class CATMathVector;

#include "CATMathDef.h"

//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedOpeCrv CATFrFCrvCrvAnalysis  : public CATCGMVirtual
{
  public :
  //-------------------  Destructeurs ------------------------- 
  virtual ~CATFrFCrvCrvAnalysis();
  
  virtual CATLONG32 GetGContinuityOrder(double tolPtG0,
                                   double tolAngleG1,
                                   double tolG2AngleOscultorPlaneDev,
                                   double tolG2RelativeCurvatureRadiusRatio) = 0;
  // the returned value is equal to -1, 0, 1 or 2


  // C0 if the gap is smaller than tolPtG0 - G0 and C0 are then the same here
  // C1 first derivative have to be the same (same direction and same norms),
  //       with given tolerances
  // C2 if the angle between the normals of osculator planes is smaller than tolG2AngleOscultorPlaneDev
  //    and if the ratio between both curvature radii is between 1-tolG2RelativeCurvatureRadiusRatio
  //    and 1+tolG2RelativeCurvatureRadiusRatio .
  virtual CATLONG32 GetCContinuityOrder(double tolPtG0,
                                   double tolAngleD1,
                                   double tolRatioNormD1,
                                   double tolAngleD2,
                                   double tolRatioNormD2) = 0;
 // the returned value is equal to -1, 0, 1 or 2

  virtual void GetG0Analysis(double& distance) = 0;
  virtual void GetG1Analysis(double& D1Angle) = 0;
  virtual void GetC1Analysis(double& D1Angle, 
                             double& D1NormRatio) = 0;

  virtual void GetG2Analysis(double& OsculatorPlaneDev, 
                             double& CurvatureRadiusRatio) = 0;

  virtual void GetC2Analysis(double& D2Angle, 
                             double& D2NormRatio) = 0;

  // get curvature radii
  virtual void GetCurvatureRadii(double& R1, double& R2) = 0;
  // get curvature radius vector
  virtual void GetCurvatureRadiusVectors(CATMathVector& R1Vector, 
                                         CATMathVector& R2Vector) = 0;

  // get create points on curve
  virtual void CreatePoints(CATCartesianPoint* CP1, 
                            CATCartesianPoint* CP2) = 0;

  //------------------- Acces aux resultats -------------------
  virtual void Run() = 0;
};

//--------------------------------
// first global creation function
//--------------------------------
ExportedByFrFAdvancedOpeCrv CATFrFCrvCrvAnalysis* 
CreateFrFCrvCrvAnalysis(CATGeoFactory* iFactory,
                           CATCurve*      iCurve1,
                           CATCurve*      iCurve2);

//---------------------------------
// second global creation function
//---------------------------------
ExportedByFrFAdvancedOpeCrv CATFrFCrvCrvAnalysis* 
CreateFrFCrvCrvAnalysis(CATGeoFactory* iFactory,
                           CATCurve* iCurve1, CATLONG32 iSide1,  // 0 for start and 1 for the end
                           CATCurve* iCurve2, CATLONG32 iSide2); // 0 for start and 1 for the end

//--------------------------------
// third global creation function
//--------------------------------
ExportedByFrFAdvancedOpeCrv CATFrFCrvCrvAnalysis* 
CreateFrFCrvCrvAnalysis(CATGeoFactory* iFactory,
                           CATCurve* iCurve1, CATCrvParam& crvParam1,
                           CATCurve* iCurve2, CATCrvParam& crvParam2);  
#endif


#endif







