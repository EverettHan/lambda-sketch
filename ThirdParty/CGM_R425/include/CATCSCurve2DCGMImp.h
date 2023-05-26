//===================================================================
// COPYRIGHT Dassault Systemes 2016
//===================================================================
//
// CATCSCurve2DCGMImp.h
// Header of CATCSCurve2DCGMImp
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// March 2016  Creation                                         FCX
//===================================================================

#ifndef CATCSCurve2DCGMImp_H
#define CATCSCurve2DCGMImp_H

#include "CATIAV5Level.h"

// FCX 04.2021 : removed in CXR32/R424
#if !defined(CATIAV5R32) && !defined(CATIAR424)

#include "SkinWireImp.h"
#include "CATCSSkinWireImpEnums.h"
#include "CATBoolean.h"
#include "CATMathTransformation2D.h"
#include "CATMathPlane.h"

class CATSoftwareConfiguration;
class CATCrvLimits;
class CATPCurve;
class CATGeoFactory;
class CATMathPoint2D;
class CATCGMStream;

class ExportedBySkinWireImp CATCSCurve2DCGMImp
{
public:

  //Object management

  CATCSCurve2DCGMImp(CATSoftwareConfiguration * ipSoftwareConfiguration, int iNbCurves, CATPCurve ** iCurves, CATCrvLimits * iCurveLimits, int * iOrientations, double iTolerance, CATBoolean iNoReparameterization = FALSE);
  CATCSCurve2DCGMImp(const CATCSCurve2DCGMImp & iCurveCGMImp);
  CATCSCurve2DCGMImp();
  virtual ~CATCSCurve2DCGMImp();


  void SetSketchPlane(const CATMathPlane& iPlane);

  CATCSCrvParamType GetLimits(double &oLow, double &oUp);

  void SetPeriodic();

  void Evaluate2D(double iT,
                  double* oaPoint,
                  double* oaFirstDeriv,
                  double* oaSecondDeriv,
                  double* oaThirdDeriv = 0);

  void Evaluate(double iT,
    double* oaPoint,
    double* oaFirstDeriv,
    double* oaSecondDeriv,
    double* oaThirdDeriv = 0);

  int GetNbOfDiscontinuities();

  void GetDiscontinuitiesParams(double *oaValues);

  //Les indices des discontinuites (iIdx) sont numerotes a partir de 1.
  void EvaluateAtDiscontinuity2D(int iIdx,
                                 CATCSDiscontinuitySide iSide,
                                 double iT,
                                 double* oaPoint,
                                 double* oaFirstDeriv,
                                 double* oaSecondDeriv,
                                 double* oaThirdDeriv = 0);
  
  void ApplyTransformation2D(double iMatrix[3][3]);

  CATBoolean EvaluateLength(double iStart, double iEnd, double &oLength);

  CATBoolean EvaluateCurvature(double iT, double &oCurvature);

  CATBoolean EvaluateCurvatureDeriv(double iT, double &oCurvatureDeriv);
  
  CATBoolean IsClosed(CATCSCurveCGMContinuityImp & oClosureContinuity);

  int ComputeDistanceMin(CATMathPoint2D * iPoint, double & oParam);
  int ComputeDistanceMin(CATCSCurve2DCGMImp * iCrv, double & oParam1, double & oParam2);

  void ComputeTransformations();

  inline CATGeoFactory* GetGeoFactory() {return _pFactory;}

  // new stream architecture for EK
  void Stream(CATCGMStream & oStream);
  void Stream(char *& oStreamData, size_t & oLength);
  CATBoolean Unstream(CATCGMStream & iStream, CATGeoFactory *& iopFactory);

  // FCX 02.2009 : for debug only
  /*void Stream(const char* iDebugDir, const char* iDebugName, CATGeoFactory * iFactory, int & oNbCurves, CATCurve **& oCurveTable, unsigned int & ioIndex, CATBoolean iForceIndex = FALSE);

private:
  void ClearInternalData();
  void ComputeDataModel();
  void UpdateDataModel();
  void ComputeCurvilinearCurve();
  void ComputeGlobalParam();
  void ComputeDiscontinuities();
  void GlobalToLocalParam(double iGlobalT, double & oLocalT, int & oCurveNumber);
  void LocalToGlobalParam(double iLocalT, int iCurveNumber, double & oGlobalT);
  //ComputeConnexionContinuity returns -1 if function is continuous, 0 otherwise
  int ComputeConnexionContinuity(CATCurve * iEC1, double iW1, int iOrientation1, CATCurve * iEC2, double iW2, int iOrientation2);

  // FCX 09.2008 : new methods for ComputeHelpParameters
  int ComputeDistanceMin(CATCurve * iCrv, CATCrvLimits & iLimits, double & oParam, double & oLocalCrvParam, double & ioDMin);
  // END FCX 09.2008

  // FCX 03.2013
  //CATBoolean IsPlanar(CATCurve *ipCurve, CATPlane *& opCurvePlane, double oPlaneNormal[3], double iAngularTolerance);
  //CATBoolean MergePlanes(CATPlane *& ipPlane, CATPlane *& iopGlobalPlane, double iPlaneNormal[3], double ioGlobalPlaneNormal[3], double iAngularTolerance, CATBoolean iFirstCall);
      */

private:
  
  // Internal methods

  void CreateInternalData(int iNbCurves, CATPCurve ** iCurves, CATCrvLimits * iCurveLimits, int * iOrientations);
  void ClearInternalData();
  void ComputeDataModel();
  void UpdateDataModel();
  void ComputeGlobalParam();
  void ComputeDiscontinuities();
  void GlobalToLocalParam(double iGlobalT, double & oLocalT, int & oCurveNumber);
  void LocalToGlobalParam(double iLocalT, int iCurveNumber, double & oGlobalT);

  // Data

  CATSoftwareConfiguration   * _pConfig;
  CATGeoFactory              * _pFactory;
  CATBoolean                   _IsValid;
  int                          _NbCurves;
  CATPCurve                 ** _pCurveTable;            //List of the initial curves
  CATCrvLimits               * _pCurveLimitTable;       //List of the initial CurveLimit
  int                        * _pOrientationTable;      //List of the initial orientation
  CATBoolean                   _IsPeriodic;
  double                     * _pLocalHighParamTable;
  double                     * _pLocalLowParamTable;
  double                     * _pGlobalParamTable;      //Parameters on the global curve of the elements of _pLocalHighParamTable.
  int                          _NbDiscontinuities;
  int                        * _pContinuity;
  double                       _ApproxTolerance;
  double                       _G1ToleranceGeo;
  CATBoolean                   _NoReparameterization;
  CATMathTransformation2D     _T;                      // current location of the curve
  CATMathPlane                _SketchPlane;
  CATMathTransformation2D     **_pPlaneToSketchTranformation;

};

//-----------------------------------------------------------------------

#endif
#endif
