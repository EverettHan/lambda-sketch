//===================================================================
// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATCSCurveCGMCurvilinearImp.h
// Implementation of CATCSCurveCGMCurvilinearImp
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// April 2008  Creation                                          KJD
//===================================================================

#ifndef CATCSCurveCGMCurvilinearImp_H
#define CATCSCurveCGMCurvilinearImp_H

#include "CATIAV5Level.h"

// FCX 04.2021 : removed in CXR32/R424
#if !defined(CATIAV5R32) && !defined(CATIAR424)

#include "SkinWireImp.h"
#include "CATBoolean.h"
#include "CATCSCurveCGMImp.h"

class CATSoftwareConfiguration;
class CATCrvLimits;
class CATCurve;
class CATVertex;
class CATGeoFactory;
class CATCurve;
class CATMathPoint;
class CATPlane;
class CATCGMStream;

//-----------------------------------------------------------------------

class ExportedBySkinWireImp CATCSCurveCGMCurvilinearImp
{
public:

  //Object management

  CATCSCurveCGMCurvilinearImp(CATSoftwareConfiguration * ipSoftwareConfiguration, int iNbCurves, CATCurve ** iCurves, CATCrvLimits * iCurveLimits, int * iOrientations, double iTolerance, CATBoolean iNoReparameterization = FALSE);

  // Creates a CATCSCurve representing a single curve (the max limits are used as CATCSCurve domain)
  CATCSCurveCGMCurvilinearImp(CATSoftwareConfiguration * ipSoftwareConfiguration, CATCurve * ipCurve);

  CATCSCurveCGMCurvilinearImp(const CATCSCurveCGMCurvilinearImp & iCurveCGMImp);
  CATCSCurveCGMCurvilinearImp();
  virtual ~CATCSCurveCGMCurvilinearImp();

  // Implementation methods
  void SetPeriodic();

  void SetClosureTolerance(const double iTol); //llr1 for IR-817527 :  the user wants to be able to choose the tolerance

  CATCSCrvParamType GetLimits(double &oLow, double &oUp);

  CATBoolean IsPlanar(double oPlaneCoords[6], double iTolerance);

  void Evaluate(double iT,
                double* oaPoint,
                double* oaFirstDeriv,
                double* oaSecondDeriv,
                double* oaThirdDeriv = 0);

  int GetNbOfDiscontinuities();

  void GetDiscontinuitiesParams(double *oaValues);

  //Les indices des discontinuites (iIdx) sont numerotes a partir de 1.
  void EvaluateAtDiscontinuity(int iIdx,
                               CATCSDiscontinuitySide iSide,
                               double iT,
                               double* oaPoint,
                               double* oaFirstDeriv,
                               double* oaSecondDeriv,
                               double* oaThirdDeriv = 0);  
  
  void ApplyTransformation(const double iMatrix[3][3], const double iTranslation[3]);

  CATBoolean IsClosed(CATCSCurveCGMContinuityImp & oClosureContinuity);

  // FCX 09.2008 : new methods for ComputeHelpParameters
  int ComputeDistanceMin(CATMathPoint * iPoint, double & oParam);
  int ComputeDistanceMin(CATCSCurveCGMCurvilinearImp * iCrv, double & oParam1, double & oParam2);
  // END FCX 09.2008

  inline CATGeoFactory* GetGeoFactory() {return _pFactory;}

  // FCX 02.2009 : for debug only
  void Stream(const char* iDebugDir, const char* iDebugName, CATGeoFactory * iFactory, int & oNbCurves, CATCurve **& oCurveTable, unsigned int & ioIndex, CATBoolean iForceIndex = FALSE);

  // FCX 07.2014 : new stream architecture for EK
  void Stream(CATCGMStream & oStream);
  void Stream(char *& oStreamData, size_t & oLength);
  CATBoolean Unstream(CATCGMStream & iStream, CATGeoFactory *& iopFactory);

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
      
private:
  // Data

  CATSoftwareConfiguration  *  _pConfig;
  CATGeoFactory             *  _pFactory;
  int                          _NbCurves;
  CATCurve                  ** _pCurveTable;            //List of the initial curves
  CATCrvLimits              *  _pCurveLimitTable;       //List of the initial CurveLimit
  int                       *  _pOrientationTable;      //List of the initial orientation
  CATBoolean                   _IsPeriodic;
  double                       _ClosureTolerance;       //the tolerance that we use to test whether the curve is closed.
  CATBoolean                   _IsReParameterized;      
  CATCurve                  ** _pReparamCurveTable;     //List of the reparameterized curves
  double                    *  _pLocalHighParamTable;   //List of the local high param of every subcurve
  double                    *  _pLocalLowParamTable;   //List of the local high param of every subcurve
  double                    *  _pGlobalParamTable;      //Parameters on the global curve of the elements of _pLocalHighParamTable.
  int                          _NbDiscontinuities;
  int                      *   _pContinuity;
  double                       _ApproxTolerance;
  double                       _G1ToleranceGeo;
  CATBoolean                   _NoReparameterization;
  CATBoolean                   _SingleCurveMode;

  
  // FCX 07.2008 : current positionning transformation
  CATMathVector     _T;
  CATMath3x3Matrix  _R;

  CATBoolean _PlanarityComputed;
  CATBoolean _IsPlanar;
  double _PlaneCoords[6];

  // FCX 07.2014 : new stream architecture for EK
  CATBoolean _StreamReparameterizedCurves;
};

//-----------------------------------------------------------------------

#endif
#endif
