#ifndef CATFrFFSFilletUtilities_H
#define CATFrFFSFilletUtilities_H
//=============================================================================
// Copyright Dassault Systemes Provence 2009-2018, all rights reserved
//=============================================================================
//
// CATFrFFSFilletUtilities :
// Implementation utility funtion of fillet operators
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// 10/07/19 : NLD ; Reception de la configuration dans ExtractTraceCurves()
//                  et GetProjectionOnSurface()
//                  Généralisation préventive à ExtractTrimCurve()
// 11/10/18 : HLN ; Passage de la soft conf. en argument de GetRelevantLimits
// 08/08/16 : HLN ; Ajout methode ExtractArcBorder
// 22/02/16 : HLN ; XScale : suppression valeur par defaut des tol. en argument
// 28/06/13 : HLN ; Ajout methodes ExtractTrimTraces et PositionPtGeoFace
// 08/03/13 : HLN ; XScale : Ajout iFactory dans CheckKnots, ComputeCurveFromDerivatives
// 24/04/12 : NLD ; eye liner
// 16/04/12 : HLN ; Deplacement dans ProtectedInterfaces
// 26/09/11 : HLN ; cleaning, making up
// 02/07/09 : MWE ; Creation d'apres CATClassATopoOperators\ProtectedInterfaces\CATCltFilletUtilities.h
//=============================================================================
#include "CATFrFFilletStyle.h"

#include "CATFrFFSError.h"
#include "CATBoolean.h"
#include "CATIsoParameter.h"
#include "CATCrvLimits.h"
#include "CATTopDefine.h"
#include "ListPOfCATFace.h"

class CATSurParam;
class CATSurLimits;
class CATSurface;
class CATNurbsSurface;
class CATCurve;
class CATGeoFactory;
class CATKnotVector;
class CATDistanceMinPtSur;
class CATMathSetOfPointsND;
class CATFrFNurbsMultiForm;
class CATMathPoint;
class CATMathDirection;
class CATFace;
class CATBody;
class CATPCurve;
class CATPLine;
class CATSoftwareConfiguration;
//#include "CATFrFFSFilletDevInfo.h" 
class ExportedByCATFrFFilletStyle CATFrFFSFilletUtilities
//hln class CATFrFFSFilletUtilities
{
  public:

  CATFrFFSFilletUtilities( ); 
  ~CATFrFFSFilletUtilities();

  static CATFrFNurbsMultiForm *ComputeCurveFromDerivatives(CATGeoFactory *iFactory,
                                                           CATSoftwareConfiguration* iConfig,
                                                           const CATKnotVector *iKnotVector,
                                                           int iMinFlag, const double MinRadius,
                                                           const CATMathSetOfPointsND *iPoints,
                                                           const CATMathSetOfPointsND *iFstDer,
                                                           const CATMathSetOfPointsND *i2ndDer = 0,
                                                           const CATMathSetOfPointsND *i3rdDer = 0);

/*hln29022016  static CATFrFFSError::Error ComputeSegmentation(CATGeoFactory *iFactory, CATSoftwareConfiguration* iConfig,
                                                  int iDim, int iNPts, 
                                                  int iNRows, double *iPoints, 
                                                  int iParamFlag, double *iDefaultPar, double *iParOfRow1, 
                                                  double *iParOfRow2, CATKnotVector *iStartKnotVec, 
                                                  double iTol, int iMaxSeg, CATKnotVector *&oResultKnot,
//hln22022016                                                  double iSmooth = 0.01);
                                                  double iSmooth);*/

  static CATFrFFSError::Error ComputeSegmentation(CATGeoFactory *iFactory, CATSoftwareConfiguration* iConfig,
                                                  int iDim, int iNPts, int iNRows, double *iPoints,
                                                  int nfix, int *afix,
                                                  int iParamFlag, double *iDefaultPar, double *iParOfRow1, 
                                                  double *iParOfRow2, CATKnotVector *iStartKnotVec, 
                                                  double iTol, int iMaxSeg, CATKnotVector *&oResultKnot,
//hln22022016                                                  double iSmooth=0.01, int iTan=0, double * ioTan=0,
                                                  double iSmooth, int iTan=0, double * ioTan=0,
                                                  int iJoinInternal=0, int iImprovement=0);

  static CATBoolean GetProjectionOnSurface(CATGeoFactory *iFactory, CATSoftwareConfiguration* iConfig,
                                           CATSurParam *iStartPar, CATMathPoint &iPoint, CATMathDirection &iNormal,
                                           CATCurve *iCurve, CATSurface *iBaseSurf, CATSurLimits &iBaseLimits,
                                           CATSurLimits &iMaxLimits, CATDistanceMinPtSur *DistminOp, double iTolerance, 
                                           CATMathPoint &oProjectedPoint, CATSurParam &oParam, double &oDist );

  static CATBoolean CheckKnots            (CATGeoFactory *iFactory,
                                           CATKnotVector &InitialKnotVec,
                                           int npar, double *iParameter,
                                           CATKnotVector &NewKnotVector);

  static CATFrFFSError::Error ExtractTrimCurve(CATGeoFactory *iFactory, CATSoftwareConfiguration* iConfig,
                                               CATFace *iFilFace, CATSurface *iFilletSurface, 
                                               CATIsoParameter iFilOrient, CATBoolean iAtStart, 
                                               CATPCurve *&oTrimCurve, CATCrvLimits &oTrimLimits, int &oTrimOrient,
//hln22022016                                               double iTolApprox=0.02);
                                               double iTolApprox);
    // returns 0 OK, 1 : match fails so output=input
    //static int MatchTrimCurve(CATGeoFactory *iFactory, CATFace *BaseFace, CATSurface *iFilletSurface,
    //                          int iContinuity, CATCurve *&ioTrimCurve , CATCrvLimits &ioTrimLimits, int &ioTrimOrient,
    //                           double iTolApprox=0.02, int iProj=0);

    // returns 0 OK, 1 : match fails so output=input
   // static int MatchFilletSurfaceForTrimming(CATGeoFactory *iFactory, CATFace *BaseFace1,
    //                                                     CATSurface *iFilletSurface,CATPCurve *Trace1, int iContinuity, 
    //                                                     CATCurve *&iTrimCurve1,CATCurve *&iTrimCurve2 );

    //static CATFrFFSError::Error TrimFillet( CATGeoFactory *iFactory, int iTrimOption, CATNurbsSurface *&ioFilletSurface,
    //                                      CATIsoParameter iFilOrient, CATFace *ioFilletFace,
    //                                      CATBoolean iAtStart, CATPCurve *iTrimCurve, CATCrvLimits &iTrimLimits,
    //                                      CATFace *&oResFace, CATBody *&oResBody );
               
  static CATFrFFSError::Error ExtractTraceCurves(CATGeoFactory *iFactory, CATSoftwareConfiguration *iSoftConf,
                                                 CATSurface *iFilletSurface, 
                                                 CATSurLimits *iFilLimits,
                                                 CATIsoParameter iFilOrient, 
                                                 CATCurve *TrimCurve1, CATCurve *TrimCurve2,
                                                 CATPCurve *&oTrace1, CATPCurve *&oTrace2);

  static void GetFilletLimitation(CATGeoFactory *iGeoFac, CATSoftwareConfiguration *iSoftConf,
                                  CATFace *iFilletFace,
                                  CATSurface *iBaseSurf1, CATCurve *iBaseCurve1,
                                  CATSurface *iBaseSurf2, CATCurve *iBaseCurve2,
                                  CATSurParam &oFilLow, CATSurParam &oFilHigh,
                                  CATIsoParameter &IsoFlag, int &oOrient, int &oAtMin,
//hln22022016                                  double iTolerance=0.001);
                                  double iTolerance);

   // static void CheckErrorBody(CATBody *ErrorBody, CATBody *BaseBody1, CATBody *BaseBody2, CATListOfCltFilletDevInfo &ErrorPointList );
 
  static int PositionPtGeoFace(CATGeoFactory *iFactory, CATSoftwareConfiguration *iConfig,
                                const CATMathPoint & iMathPoint, CATLISTP(CATFace) &ilBaseFace, 
                                double iTolerance, CATLocation &oLocation);

  static CATFrFFSError::Error ExtractTrimTraces(CATGeoFactory *iFactory, CATSoftwareConfiguration *iConfig, 
//                                                CATFace *iBaseFace1, CATFace *iBaseFace2, CATFace *iFilFace, 
                                                CATLISTP(CATFace) &ilBaseFace1, CATLISTP(CATFace) &ilBaseFace2, CATFace *iFilFace, 
                                                CATSurface *iFilletSurface, CATIsoParameter iFilOrient,
                                                double iTolApprox, CATSurParam oCornerSurParam[4]);

  static CATFrFFSError::Error ExtractArcBorder(CATGeoFactory *iFactory,
                                               CATSurface *iFilletSurface, CATBoolean iTraceOrientation, int iWhatBorder,
                                               CATPLine *&oTrimBorder);
};
#endif
