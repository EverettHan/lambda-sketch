//==============================================================================
// Copyright Dassault Systemes Provence 2012, All Rights Reserved
//==============================================================================
//
// CATFrFSurLocalConnectChecker.h
//
//==============================================================================
//
// Usage notes: Operator for local computation of geometric continuity between
//              two surfaces whithout knowing the topology
//
//   To compute G0 and G1 continuity deviation we directly use 
//   CATMathLocalConnectChecker.
//
//   To compute G2 continuity deviation without knowing the topology we have to find  
//   the common direction of both surfaces for which the deviation is maximum using 
//   CATMathLocalConnectChecker.
//   Direction is used to compute the normal curvature of the surface at this point
//   in this direction 
//   The directions are choosen in the tangent plane and caracterized by an angle.
//   A direction is considered as common if the plane created by this direction 
//   and the average normal of the surfaces intersects the two surfaces.
//   To determinate where the deviation is maximum we do a sampling on all common 
//   directions.
//
//==============================================================================
//   /05/12 G7S Creation
// 27/08/13 RAQ Modif commentaires, GetG1Error et GetG2Error sont en radian
// 31/07/18 NLD Suppression du constructeur par defaut; ce n'est pas comme cela que l'on travaille
//==============================================================================
#ifndef CATFrFSurLocalConnectChecker_H
#define CATFrFSurLocalConnectChecker_H

#include "CATTolerance.h"
#include "CATSurParam.h"
#include "CATMathDirection.h"
#include "CATMathPlane.h"
#include "FrFOpeSur.h"

class CATSoftwareConfiguration;
class CATMathLocalConnectChecker;
class CATMathSurfaceGData;
class CATSurface;
class CATGeoFactory;
#define CATFrFSurLocalConnectChecker_NoDefaultConstructor

class ExportedByFrFOpeSur CATFrFSurLocalConnectChecker
{
public :

  // Constructor
  #ifndef CATFrFSurLocalConnectChecker_NoDefaultConstructor
  CATFrFSurLocalConnectChecker();
  #endif
  CATFrFSurLocalConnectChecker( CATSoftwareConfiguration* iConfig, const CATTolerance& iTolObject );

  // Destructor
  virtual ~CATFrFSurLocalConnectChecker();

  // Operator Run
  // return : 0 if there is no deviation
  //          1 if an unexpected deviation happened
  //          2 if G2 cannot be computed (no common direction between the two surfaces) 
  int Run( CATSurParam& iFirstParam, CATSurParam& iSecondParam, 
           CATSurface* iFirstSurface, CATSurface* iSecondSurface );

  // Set conntinuities to check
  void SetContinuityToCheck( int iOrder );

  // Return conntinuities to check
  int GetContinuityToCheck();

  // Return continuities deviation
  double GetG0Error(); // (mm)
  double GetG1Error(); // (rad)
  double GetG2Error(); // (%)
  double GetG3Error(); // (rad)

  // Return the direction where G2 deviation is maximum
  void GetDirMaxG2Error( CATMathDirection& oDir );

  // Return the orthogonal direction where G2 deviation is maximum
  void GetOrthoDir( CATMathDirection& oDir );

  // Set the number of mesaures for G2 sampling
  void SetNbOfMeasures( int iNbOfMeasures );

  // Return the number of measures
  int GetNbOfMeasures();

  // Method for DEBUG
  void SetDebugFactory(CATGeoFactory* iFactory);

  // Return normal curvatures computed on each surface
  void GetNormalCurvatures(double& oNormalCurvFirstSurf, double& oNormalCurvSecondSurf);

private : 

  // Create CATMathSurfaceGData of the two surfaces
  int CreateSurfaceGData();

  // Compute deviation continuities
  int ComputeContinuityErrors();

  // Sampling for G2 Continuity
  int ComputeG2Continuity();

  // Compute sampling angle and initial direction
  int ComputeAngleAndDir(const CATMathPlane    & iPlane,
                               double          & oAngle,
                               CATMathDirection& oInitialDir);

  //------------------Data
        CATSoftwareConfiguration*     _Config;
  const CATTolerance*                 _Tol;
        CATMathLocalConnectChecker*   _ConnectChecker;
        CATMathSurfaceGData*          _FirstGData;
        CATMathSurfaceGData*          _SecondGData;

        CATSurParam                   _FirstParam;
        CATSurParam                   _SecondParam;
        CATSurface*                   _FirstSurface;
        CATSurface*                   _SecondSurface;

        int                           _Order;
        int                           _NbOfMeasures;
        double                        _G0Error;
        double                        _G1Error;
        double                        _G2Error;
        double                        _G3Error;
        double                        _FirstCurv;
        double                        _SecondCurv;

        CATMathDirection              _DirMaxG2Error;
        CATMathDirection              _OrthoDir;

        CATGeoFactory*                _Factory;

};

#endif

