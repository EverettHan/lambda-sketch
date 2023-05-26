#ifndef CATTopDistanceTool_H
#define CATTopDistanceTool_H
// COPYRIGHT DASSAULT SYSTEMES 2000

#include "ParallelLight.h"


#include "CATTopDef.h"
#include "CATEnhancedDistanceTool.h" // Modified By : SUH : 2003:6:11
#include "ListPOfCATCell.h"
#include "CATListOfCATSurParams.h"
#include "CATDataType.h"
#include "CATListOfDouble.h"
#include "ListPOfCATVertex.h"
#include "CATApproxDiagnosticType.h"

class CATMathSetOfPointsND;
class CATMathFunctionX;
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATCurve;
class CATSurface;
class CATCrvLimits;
class CATSurLimits;
class CATLaw;
class CATCompositeLaw;
class CATParallelComputer;
class CleanCurveEdgeMap; // Modified By : SUH : 2003:7:2
class CATEdge;
class CATBody;
class CATVertex;
class CATMathVector;
class CATEdgeCurve;

/**
* Defines the euclidean distance tool type.
*/
#define GeodesicTopDistanceToolType_Euclidian 3

/**
* Defines the geodesic distance tool type.
*/
#define GeodesicTopDistanceToolType_Geodesic  4

/**
* Defines the directional distance tool type.
*/
#define TopDistanceToolType_Directional       7

/**
* Defines the type of the law.
*/
#define LawType_Constant  1
#define LawType_Variable  2

/**
* Class defining the type of parallel computation.
* This class is used to define the parameters of a @href CATTopParallel operator.
*/
class ExportedByParallelLight CATTopDistanceTool : public CATEnhancedDistanceTool // Modified By : SUH : 2003:6:11
{
  CATCGMVirtualDeclareClass(CATTopDistanceTool);
public:

  /**
  * Constructs the distance tool for the parallel computation.
  * @param iGeoFactory
  * The pointer to geometry factory.
  * @param iSoftwareConfiguration
  * The pointer to the software configuration with which the code must be run.
  * @param iOrientation
  * The side on which the parallel is computed.
  * The cross product between the shell normal and the wire tangent define the
  * left side.
  * <br><b>Legal values </b>: <tt>CATOrientationPositive</tt> for the left side,
  * <tt>CATOrientationNegative</tt> for the right side.
  * @param iDistance
  * The pointer to the law defining the parallel offset.
  */
  CATTopDistanceTool( CATGeoFactory * iGeoFactory, CATTopData * iData, CATOrientation iOrientation, CATLaw *iDistance );
  CATTopDistanceTool( CATGeoFactory * iGeoFactory, CATTopData * iData, CATOrientation iOrientation, CATCompositeLaw *iDistance );

  ~CATTopDistanceTool();

  /** @nodoc */
  virtual CATTopSign GetSign();

  /** @nodoc @nocgmitf */
  virtual CATParallelComputer *GetParallelComputer( CATCurve * iCurve,
    CATCrvLimits & iCurveLimit,
    CATLONG32 iOrientationEdge,
    CATBoolean iExtrapolEdge,
    CATSurface * iSupport,
    CATSurLimits & iSupportLimit,
    CATLONG32 iOrientationSupport,
    CATBoolean iExtrapolSupport,
    CATParallelConnectTool *iConnectTool,
    CATMathSetOfPointsND * iInitPoints,
    CATBoolean iLoopSearch );

  /** @nodoc @nocgmitf */
  virtual CATCGMOperator * GetProjectOpe(CATGeoFactory * iFacto, CATTopData * iData, CATGeometry * iToProject, CATGeometry * iSupport);
  /** @nodoc @nocgmitf */
  virtual CATCGMOperator * GetDistOpe(CATGeoFactory * iFacto, CATTopData * iData, CATGeometry * iToProject, CATGeometry * iSupport);
  /** @nodoc */
  virtual int IsParallelImage(CATGeoFactory * iFacto, CATTopData * iData, CATGeometry * iSupport, CATGeometry * iCurveIni,CATLaw ** MapLaws, CATGeometry * iVtxImage,CATGeometry * iVtxOrig)=0;
  /** @nodoc */
  virtual void ComputeParallelImage(CATGeoFactory * iFacto, CATTopData * iData, CATGeometry * iSupport, CATGeometry * iCurveIni,CATLaw ** MapLaws, CATGeometry *& oVtxImage,CATGeometry * iVtxOrig)=0;
  /** @nodoc */
  virtual void ComputeParallelImageFromTangent(CATGeoFactory * iFacto, CATTopData * iData, CATGeometry * iSupport, CATGeometry * iCurveIni,CATLaw ** MapLaws, CATGeometry *& oVtxImage,CATGeometry * iVtxOrig,CATVertex * iVtxExtremity,CATMathVector & iTangent)=0;
  /** @nodoc */
  virtual void DuplicateTool(CATTopDistanceTool * & oNewTool)=0;
  /** @nodoc */
  virtual void SetTolerance(double iTolerance);
  virtual CATLONG32 GetTolerance ( double & oTolerance);
  
  /** @nodoc */
  // deprecated use SetNewSmoothing
  virtual void SetSmoothing(CATLONG32 iSmooth);
  virtual void GetSmoothing (CATLONG32 & oSmooth);

  /** @nodoc */
  // New Smoothing option
  // 0  => No smoothing
  // 1  => Smooth for tangency continuity 
  // 2  => Smooth for curvature continuity 
  virtual void SetNewSmoothing(CATLONG32 iSmooth);
  virtual void GetNewSmoothing (CATLONG32 & oSmooth);

  /** @nodoc @nocgmitf */
  // for internal use only
  // should cleaning be done & how?
  // CleaningMode:
  // -1 => Not set yet
  // 0  => No cleaning
  // 1  => clean with tangency deformation 
  // 2  => clean with curvature deformation 
  //
  // CleanAngleTol: Upper G1 threshold, above which no Clean will be attempted by the CleanCrv operator
  virtual void SetCleaningMode(CATLONG32 iCleaningMode, double * iCleanAngleTol = NULL);
  /** @nodoc @nocgmitf */
  virtual void GetCleaningMode(CATLONG32 & oCleaningMode, double * ioCleanAngleTol = NULL);


  // Start : MQZ : 2004:7:6
  /** @nodoc */
  // for internal use only
  // has user requested 3D cleaning?
  // Cleaning3DMode:
  // 0  => Default 2D cleaning
  // 1  => 3D Cleaning for the output 
  virtual void SetOutputWireCleaning3DMode(CATLONG32 iOutputWireCleaning3DMode);
  /** @nodoc */
  virtual void GetOutputWireCleaning3DMode(CATLONG32 & oOutputWireCleaning3DMode);
  // End : MQZ : 2004:7:6

  // Start : SUH : 2003:6:11
  /** @nodoc */
  virtual CATLONG32 GetCleanInputWireTolerance (double &oTolerance);
  /** @nodoc */
  virtual CATLONG32 GetComputeParallelTolerance (double &oTolerance);
  /** @nodoc */
  virtual CATLONG32 GetCleanOutputWireTolerance (double &oTolerance);

  /** @nodoc */
  virtual CATLONG32 ValidateInitSide (CATCurve * iCurve, CATCrvParam & iCrvParam,
    CATSurface * iSurface, CATSurParam & iSurParam,
    double iRadiusValue, double * iTangent3D,  double *oProduct = NULL)
  {
    return -1;
  }

  /** @nodoc */
  virtual CATLONG32 ProjectOnOriginalSurface(CATCurve        *  iCurve,
                                             CATCrvParam     &  iParam,
                                             CATSurface      *& oOriginalSurface,
                                             CATPCurve       *& oOriginalPCurve,
                                             CATCrvParam     &  oParam,
                                             CATSurParam     &  oCorrespondingParam);

  /** @nodoc */
  virtual CATLONG32 ProjectOnOriginalSurface(CATCurve        *  iCurve,
                                             CATCrvParam     &  iParam,
                                             CATSurface      *& oOriginalSurface,
                                             CATPCurve       *& oOriginalPCurve,
                                             CATCrvParam     &  oParam,
                                             CATSurParam     &  oCorrespondingParam,
                                             CATEdgeCurve   *& oOriginEdgeCurve,
                                             CATLONG32       & oOriginSurOrient);

  /** @nodoc */
  //permet de recuperer l'edge 2D correspondant a la courbe3D
  virtual CATEdgeCurve* GetMaps2DCurve(CATCurve * iCurve,CATCrvParam & iCrvParam);

  /** @nodoc */
  virtual void SetEdgeMaps( const int &iNbMaps, CleanCurveEdgeMap ** const &iMaps = 0);  

  /** @nodoc */
  void ExpandMaps(CATEdge * iEdge3D, const CATCrvLimits &iNewLimits); // Added : SUH : 2004:3:11
  /** @nodoc */
  virtual void FindSupportFaces(CATEdge * iEdge3D, CATLISTP(CATCell) &oBoundingFaces, CATListOfInt &oSurVsShell);
  /** @nodoc */
  virtual void FindSupportFaces(CATCurve * iCurve3D, const CATCrvParam &iCrvParam3D, CATLISTP(CATCell) &oBoundingFaces, CATListOfInt &oSurVsShell, CATLISTP(CATSurParam) * oSurParam = 0);
  /** @nodoc */
  // IZE wk. 10 2009 Improved support faces choice for a better init targeting
  virtual void AdvancedFindSupportFaces(CATEdge * iEdge3D, CATBody* iSupport, CATLISTP(CATCell) &oBoundingFaces, CATListOfInt &oSurVsShell);
  /** @nodoc */
  virtual void SearchInitSupportFromAdjacentFace(CATEdge* iEdge3D, CATBody* iSupport, CATLISTP(CATCell) &oBoundingFaces, CATListOfInt &oSurVsShell);
  /** @nodoc */
  virtual CATOrientation GetCurve3DOrientation(CATCurve * iCurve3D, const CATCrvParam &iCrvParam3D);
  /** @nodoc */
  void SetBody3D(CATBody * iWire3D,CATBoolean Option=FALSE);
  /** @nodoc */
  void SetBody2D(CATBody * iWire2D);
  /** @nodoc */
  CATSoftwareConfiguration * GetSoftwareConfiguration() const;
  /** @nodoc */
  void SetAngleTolerance(const double &iTolerance);
  /** @nodoc */
  CATLONG32 GetAngleTolerance(double &oTolerance);

  /** @nodoc */
  //iMaxCR = a measure of minimum G2 cont. required 
  //iMinCR = a measure of maximum G2 cont. required 
  CATLONG32 SetCurvatureRatio(const double &iMaxCR, const double &iMinCR);
  /** @nodoc */
  CATLONG32 GetCurvatureRatio(double &oMaxCR, double &oMinCR);

  /** @nodoc */
  // iMode = 0 : Use full tolerance for Parallel Computation, iCleanInputWireTol is useless.
  // iMode = 1 : Distribute tolerance such that CleanInputWire tol. is iCleanInputWireTol,if ...
  // iCleanInputWireTol is not specified, CleanInputWire tol. is maximum (i.e. _Tolerance - 2*Resolution)
  CATLONG32 SetToleranceDistribution(const short &iMode, double iCleanInputWireTol = -1);

  // End : SUH : 2003:6:11

  /** @nodoc */
  int RetrieveRoughGap(CATVertex* iVertex,double& iGap);
  
  /** @nodoc */
  //REN Sep 12' 05
  int IsInGap(CATEdgeCurve * iEC3D, const CATCrvParam &iParam, 
              CATSurParam &oPrevSurParam, CATSurParam &oNextSurParam,
              CATLISTP(CATCell) &PrevSupFaces, CATLISTP(CATCell) &NextSupFaces,
              int &oMapExtreme );

  double FindFalseGap(CATGeoFactory * iFactory, CATTopData * iTopData, CATEdgeCurve * iEdgeCurve3D, CATCrvParam & iCrvParam3D, CATCrvParam & iendCrvParam3D);

  void SetShellBody(CATBody * iShellBody);
  CATBody * _ShellBody;

  /** @nodoc */
  // info on type of law
  virtual CATBoolean IsConstantLaw();
  virtual CATBoolean IsVariableLaw();

  /** @nodoc */
  // for internal use only: to use the non approx law when law is with vertical tangent
  virtual void SetNonApproxLaw(CATCompositeLaw * iLaw);
  /** @nodoc @nocgmitf */
  virtual CATCompositeLaw * GetNonApproxLaw();

  virtual void SetApproxDiagnostic(CATApproxDiagnostic iDiagnostic);
  virtual CATApproxDiagnostic GetApproxDiagnostic();

  virtual void SetApproxDeviation(double iDeviation);
  virtual double GetApproxDeviation();

  //For AutoParallel
  //Start...APIs for user. More APIs will be provided depending on user inputs.
  virtual void SetNumberOfAutoParallels(CATLONG32 iNoOfParallels); //Sets the no. of Offsets
  
  //End... APIs for user.

  //For AutoParallel..internal use only.
  /** @nodoc @nocgmitf */
  CATLONG32 GetNumberOfAutoParallels();
  /** @nodoc @nocgmitf */
  CATBoolean IsAutoParallelRequested();
  /** @nodoc @nocgmitf */
  CATMathQuickDiscretizeFunctionX * GetExplicitFunctionForAutoParallel(CATSoftwareConfiguration * iConfig,
                                                                       CATGeoFactory * iFactory,
                                                                       CATParallelConnectTool * iTool,
                                                                        CATListOfDouble &iListOfOffsets);
  /** @nodoc @nocgmitf */
  void RemoveExpliFunc();

  /** @nodoc @nocgmitf */
  void SetAutoParallelLevel (short &iAutoParallelLevel);

  /** @nodoc @nocgmitf */
  virtual void GetEquivalentEuclideanTool(CATTopDistanceTool * & oNewTool);

protected :

  CATDistanceTool * _OldDistance;
  CATTopData   * _Data;
  short _TypeRaiser;

  // IZE wk. 11 2009 Moved from private to protected
  CATBody * _Wire3D; // Modified By : SUH : 2003:7:2
  CATBody * _Wire2D;

private :

  int FindCorrespondingMap(CATCurve * iCurve, const CATCrvParam &iCrvParam, CATOrientation * oEdgeVsECrv = 0);
  void DecideOnType();

  // Temporaire
  CATOrientation   _Orientation;
  double _Tolerance;
  CATLONG32 _HasBeenToleranced;
  CATLONG32 _Smoothing; // connect smoothing

  CATLONG32 _NbMaps;
  CleanCurveEdgeMap ** _Maps3D2D;
  double _AngleTol;//maximum angle accepted as G1 continuous while splitting the wire into G1 wires

  double _CleanAngleTol;//upper G1 threshold for Cleaning of wire
  double _CurvatureRatio[2];

  // Tolerance distribution mode, Values->
  // 0: full _Tolerance used for Parallel Computation
  // 1: _Tolerance distributed such that CleanInputWire tol. is maximum(i.e. _Tolerance - 2*Resolution)
  // 1: _Tolerance distributed such that CleanInputWire tol. is a specified one
  short _DistriMode; 
  double _DistriTol[3]; //in case user tolerance is distributed, this variable holds them

  // should cleaning be done & how?
  // -1 => Not set yet
  // 0  => No cleaning
  // 1  => clean with tangency deformation 
  // 2  => clean with curvature deformation 
  CATLONG32 _CleaningMode;

  // Smoothing option
  // 0  => No smoothing
  // 1  => Smooth for tangency continuity 
  // 2  => Smooth curvature continuity 

  CATLONG32 _OutputWireCleaning3DMode;
  // Cleaning option of the output wire
  // 0  => 2D Cleaning (on shell support) for the output wire
  // 1  => 3D Cleaning for the output wire

  CATLONG32 _NewSmoothing; // smoothing option from application

  CATLISTP(CATVertex) _VertexList;
  CATListOfDouble _GapList;
  short _LawType;
  CATCompositeLaw * _NonApproxLaw;
  CATApproxDiagnostic _ApproxDiagnostic;
  double _ApproxDeviation;
  CATLONG32 _NoOfParallels;
  CATBoolean _AutoParallel;
  //ST5 wk17: AutoParallel Versionning
  short _AutoParallelLevel;  
};

#endif
