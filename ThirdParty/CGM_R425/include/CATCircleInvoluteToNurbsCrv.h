//====================================================================
// Copyright Dassault Systemes Provence 2007, all rights reserved 
//====================================================================


//------------------------------------------------------------------
// Approximate the Circle Curve Involute by a Nurbs
// 
//------------------------------------------------------------------
#include "FrFOpeCrv.h"
#include "CATMathInterval.h"

class CATSoftwareConfiguration;
class CATGeoFactory;

class CATPlane;
class CATCurve;


class ExportedByFrFOpeCrv CATCircleInvoluteToNurbsCrv
{
public:
  //Constructeur 
  CATCircleInvoluteToNurbsCrv(CATSoftwareConfiguration * iSoftConfig, CATGeoFactory * iFactory,
    const CATMathInterval& iAngleInterval, double iRayon, double iTol);
  ~CATCircleInvoluteToNurbsCrv();
  //OPtion specific choose of a Plane 
  void SetPlane(CATPlane * iSupportPlane);
  int Run();
  CATCurve * GetResult();

private:
  CATSoftwareConfiguration * _SoftConfig;
  CATGeoFactory            * _Factory;
  CATMathInterval           _Interval;
  double                    _Rayon;
  double                    _Tol;
  CATPlane                 *_Support; 
  CATCurve             *_Result;
};

