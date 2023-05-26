/* -*-C++-*- */

#ifndef CATVariableFilletLaw_H
#define CATVariableFilletLaw_H

// COPYRIGHT DASSAULT SYSTEMES 1998

//-----------------------------------------------------------------------------
//
// CATVariableFilletLaw 
// Definition of a VariableFilletLaw class 
//
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Usage notes:
//
// The CATVariableFilletLaw is dedicated to Chamfer and Variable Fillet Operator
//
// - With the specification data of fillet, this object creates and stores
// all the necessary data to variable fillet computation.
//
// - This object is manipulated by the topological fillet operator
// 
// - With the N edges (and respective orientations), M 'Cleaned Curves'
// are created. Each 'Cleaned Curve' is C2 continuous. (M<=N)
//
// - For Chamfer, MappingLaw = 0 and RadiusLaw = 0.
//
// - For Fillet Only, 
//   - M 'Mapping Laws' are created.
//   . Each 'Mapping Law' contains the necessary data for quick evaluation
//   w (parameter on cleaned curve) --> S (curv abs % on list of Cleaned Curves)
//   . Each 'Mapping Law' is a law that contains degree 5 polynom  
//   - 1 'Radius Law' is created.
//   . The 'Radius Law' contains the necessary data for radius evaluation
//   . The 'Radius Law' is a law that contains CATCompositeLaw
//   . This CATCompositeLaw is a spline law + specific extrapolation
//  
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Apr. 98  Creation                                              O. SCHOUTTETEN
// Jul. 98  Modification for chamfer                              O. SCHOUTTETEN
// Nov. 05  Modification for G1 variable fillet (new clean curve) CWM
//-----------------------------------------------------------------------------

#include "Fillet.h"

#include "ListPOfCATEdge.h"

#include "CATMathDef.h"
#include "CATSoftwareConfiguration.h"
#include "CATCrvParam.h"
#include "CATIACGMLevel.h"
#include "CATVariableFilletLawGeo.h"


class CATGeoFactory;
class CATSurface;
class CATEdge;
class CATCurve;
class CATLaw;
class CATSplineLaw;
class CATMathFunction;
class CATMathPolynomX;
class CATCrvParam;
class CATDynFilletRadius;
class CATLISTP(CATDynFilletRadius);
class CATTopData;
class CATBody;
class CATSplineLawOp;
class CATVariableFilletCleanCurve;
class CATVariableFilletSpineTools;

class ExportedByFillet CATVariableFilletLaw
{
 public:

  //---------------------------------------------------------------------------
  // Default Constructor
  //
  //---------------------------------------------------------------------------
  CATVariableFilletLaw (CATSoftwareConfiguration * iConfig);
  //---------------------------------------------------------------------------
  // Constructor dedicated to Chamfer 
  //
  //---------------------------------------------------------------------------
  //
  // iEdges           : CATLISTP(CATEdge) &
  // iOrientations    : CATLONG32 [iNumberOfEdges] (+1 or -1)
  // iClose           : CATLONG32 (0: Open, 1: Closed)
  //
  //---------------------------------------------------------------------------
  CATVariableFilletLaw (CATSoftwareConfiguration * iConfig,
                        CATGeoFactory * iFactory,
                        CATLONG32 iNumberOfEdges,
                        CATLISTP (CATEdge) & iEdges,
                        CATLONG32 * iOrientations, 
                        CATLONG32 iClose,
                        double iLongExtra=0);
  //---------------------------------------------------------------------------
  // Constructor dedicated to Variable Fillet
  //
  //---------------------------------------------------------------------------
  // iEdgeIndex           : CATLONG32 [iNumberOfImpositions]
  // iCurvilinearParam    : double [iNumberOfImpositions]
  //                        on Edge (0. at beginning of edge, 1. at end of edge)
  //   for example :
  //
  //        +1              -1              +1
  //   --*--------*-- ---*-----------*--- ------
  //    .1       .9     .8          .2 
  //
  //
  //
  //
  // iRadius              : double [iNumberOfImpositions]
  // iSlopeDefined        : CATLONG32 [iNumberOfImpositions]
  //                        (0: not imposed, 1: imposed)
  // iSlope               : double [iNumberOfImpositions]
  //                        this slope is given as dR/ds
  //                        (R: radius, s: CurvilinearParam on Edge)
  //                        the value is relevant only if iSlopeDefined = 1
  // 
  //---------------------------------------------------------------------------
  CATVariableFilletLaw (CATSoftwareConfiguration * iConfig,
                        CATGeoFactory * iFactory,
                        CATLONG32 iNumberOfEdges,
                        CATLISTP (CATEdge) &, 
                        CATLONG32 * iOrientations,
                        CATLONG32 iClose,
                        CATLONG32 iNumberOfImpositions,
                        CATLONG32 * iEdgeIndex, 
                        double * iCurvilinearParam, 
                        double * iRadius,
                        CATLONG32 * iSlopeDefined, 
                        double * iSlope,
                        double iLongExtra=0);

  CATVariableFilletLaw (CATSoftwareConfiguration * iConfig,
                        CATGeoFactory * iFactory,
                        CATLONG32 iNumberOfEdges,
                        CATLISTP (CATEdge) &, 
                        CATLONG32 * iOrientations,
                        CATLONG32 iClose,
                        CATLONG32 iNumberOfImpositions,
                        CATLONG32 * iEdgeIndex, 
                        double * iCurvilinearParam, 
                        double * iRadius,
                        CATLONG32 * iSlopeDefined, 
                        double * iSlope,
                        int iRadiusLawMode,
                        int iContinuityMode,
                        double iLongExtra=0);

  // Constructor using new clean curve
  CATVariableFilletLaw (CATSoftwareConfiguration * iConfig,
                        CATGeoFactory * iFactory,
                        CATBody * iBody,
                        CATVariableFilletSpineTools * iSpineTools,
                        CATLONG32 iNumberOfEdges,
                        CATLISTP (CATEdge) &, 
                        CATLONG32 * iOrientations,
                        CATLONG32 iClose,
                        CATLONG32 iNumberOfImpositions,
                        CATLONG32 * iEdgeIndex, 
                        double * iCurvilinearParam, 
                        double * iRadius,
                        CATLONG32 * iSlopeDefined, 
                        double * iSlope,
                        int iRadiusLawMode,
                        int iContinuityMode,
                        double iLongExtra=0);
  //---------------------------------------------------------------------------
  // Constructor : For shape fillet with external law
  //---------------------------------------------------------------------------
  // iSpine = Mono wire body, containing only one edge, or two for closed spine  
  //          (the two edges using the same geometry)
  //---------------------------------------------------------------------------
  CATVariableFilletLaw ( CATGeoFactory *                  iFactory, 
                          CATTopData *                    iData,
                          CATBody *                       iSpine,
                          CATLISTP(CATDynFilletRadius) *  iRadiusList,
                          int                             iRadiusLawMode=0);

  //---------------------------------------------------------------------------
  // Destructor
  //---------------------------------------------------------------------------

  virtual ~CATVariableFilletLaw ();

  //---------------------------------------------------------------------------
  // Get Number Of Cleaned Curves
  //  
  //---------------------------------------------------------------------------
  virtual CATLONG32 GetNumberOfCleanedCurves ();

  //---------------------------------------------------------------------------
  // Get One Cleaned Curve (and Orientation)
  //  
  //---------------------------------------------------------------------------
  virtual CATCurve * GetOneCleanedCurve (CATLONG32 iCleanedCurveIndex,
										 CATLONG32 & oOrientation);

  //---------------------------------------------------------------------------
  // Get One Cleaned Curve Index from Edge Index 
  // 0 <= iEdgeIndex < N ;  0 <= oCleanedCurveIndex < M 
  //
  //---------------------------------------------------------------------------
  virtual CATLONG32 GetOneCleanedCurveIndex (CATLONG32 iEdgeIndex);

  //---------------------------------------------------------------------------
  // Get One Mapping Law 
  //  
  //---------------------------------------------------------------------------
  virtual CATLaw * GetOneMappingLaw (CATLONG32 iCleanedCurveIndex);

  //---------------------------------------------------------------------------
  // Get Radius Law
  //  
  //---------------------------------------------------------------------------
  virtual CATLaw * GetRadiusLaw  ();

  //---------------------------------------------------------------------------
  // Get Report Function
  // For initialization purposes,
  // Parameter on Edge --> Parameter on Cleaned Curve
  //---------------------------------------------------------------------------
  virtual CATMathFunction * GetReportFunction (CATLONG32 iEdgeIndex);

  //-----------------------------------------------------------------------------
  //Set External Radius Law (and so it is NOT REMOVED after use) 
  //-----------------------------------------------------------------------------
  void SetExternalRadiusLaw(CATLaw * iLaw);

  void SetCurrentSupport(CATSurface *iSurface1, CATSurface *iSurface2);

protected:

  //---------------------------------------------------------------------------
  // Compute Curve Mapping
  //---------------------------------------------------------------------------
  void ComputeCurveMapping ();

  //---------------------------------------------------------------------------
  // Compute Cleaned Curves
  //---------------------------------------------------------------------------
  //void ComputeCleanedCurves ();
  void ComputeCleanedCurves(CATLONG32 iNumberOfImpositions = 0, CATLONG32 * iEdgeIndex = 0, double * iCurvilinearParams = 0);

  //---------------------------------------------------------------------------
  // Compute Precise Cleaned Curves
  //---------------------------------------------------------------------------
  void ComputePreciseCleanedCurves ();

private:
  void SetRadiusLaw  (CATLaw       * iLaw);
  void SetMappingLaw (CATLaw       * iLaw);
  void SetSplineLaw  (CATSplineLaw * iLaw);
  void SetSpline     (CATCurve     * iSpline);

  void ComputeCleanCurveAndMapping(double iDeviation = 0.0);
  //-----------------------------------------------------------------------------
  // Compute RadiusLaw
  //-----------------------------------------------------------------------------
  void ComputeRadiusLaw(CATLONG32 iNumberOfImpositions, double iMySize,
                        CATLONG32 * iEdgeIndex,
                        double * iCurvilinearParams,
                        double * iRadii,
                        CATLONG32 * iSlopeDefined,
                        double * iSlope);

  void ComputeInitialRadiusLaw(CATLONG32 iNumberOfImpositions,  
                               CATLONG32 * iEdgeIndex, 
                               double * iCurvilinearParams, 
                               double * iRadii,
                               CATLONG32 * iSlopeDefined, 
                               double * iSlope);
  //-----------------------------------------------------------------------------
  void Init(); // init everything
  void Init(CATSoftwareConfiguration * iConfig,
            CATGeoFactory * iFactory,
            CATLONG32 iNumberOfEdges,
            CATLISTP (CATEdge) & iEdges,
            CATLONG32 * iOrientations,
            CATLONG32 iClose,
            double iLongExtra);
  //-----------------------------------------------------------------------------

  void ComputeVariableFilletLaw(CATLONG32 iNumberOfImpositions, 
								                CATLONG32 *iEdgeIndex,
                                double * iCurvilinearParams,
                                double * iRadii,
                                CATLONG32 * iSlopeDefined,
                                double * iSlope);

  void ComputePartialLengths();
  void ComputeDeviationForCleanCurve(CATLONG32 iSampleSize, double & oDeviation);
  void TwoStepExtrapolation(const CATCrvParam &iParam, double iMySize, int iDir);

private:
  
  //---------------------------------------------------------------------------
  // Data
  //---------------------------------------------------------------------------
  CATSoftwareConfiguration * _SoftwareConfig;
  CATGeoFactory * _Factory;
  CATLONG32 _NumberOfEdges;
  CATLISTP(CATEdge) * _Edges;
  CATLONG32 * _Orientations;
  CATLONG32 _Close;

  CATBoolean _IsValid ; // Pour eviter les Throw dans le constructeur

  CATLONG32 _NumberOfCleanedCurves;
  CATCurve * _Spline;
  CATLONG32 _CleanedCurveOrientation;

  CATMathPolynomX ** _Polynoms;
  CATLaw * _MappingLaw;
  CATSplineLaw * _SplineLaw;
  CATLaw * _RadiusLaw;
  CATLaw * _ExternalRadiusLaw;
  CATCrvParam _StartParam, _EndParam;

  CATVariableFilletLawGeo * _GeoLaw;
  int _NumberMultiLaw;
  CATLaw ** _MultiRadiusLaw;
  int _LawIndex;

  double * _Lengths;
  double * _PartialLengths;

  CATLONG32 * _NbArcsPerEdge;
  double * _LengthsOnCleanedCurve; 
  double * _PartialLengthsOnCleanedCurve;

  double _LongExtra;

  CATVariableFilletCleanCurve * _CleanCurve; //pour la creation de la nouvelle clean curve
  CATVariableFilletSpineTools * _SpineTools;
  CATSplineLawOp * _SplineLawOp;
  CATBody *_InitialBody;
  double _RadMin, _FirstRad, _LastRad;
  CATBoolean _IsRadiusLawComputed;

  int _RadiusLawMode;
  int _ContinuityMode;
};
#endif
