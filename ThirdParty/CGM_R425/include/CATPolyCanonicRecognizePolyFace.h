// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCanonicRecognizePolyFace.h
//
//===================================================================
//
// Usage notes: Recognize canonics (planes, cylinders, cones, sphere, torus)
// in a Mesh
//
//===================================================================
//
// Dec 2010  Creation: ANR
//===================================================================

#ifndef CATPolyCanonicRecognizePolyFace_H
#define CATPolyCanonicRecognizePolyFace_H 

#include "CATPolyCanonicOperators.h"  
#include "CATBoolean.h"
#include "CATIPolySurface.h" 
#include "CATIPolyMesh.h"

#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATListOfDouble.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATMathPlane.h"
#include "CATPolyPlaneMeshIntersector.h"
#include "CATPolyExactArithmetic.h"

class CATPolyGeometricForm;
class CATPolyCanonicOperData ;
class CATPolyCanonicOperTol ;


class CATIPolyMeshTriangleIterator;
class CATPolyPointMeshDistanceAccelerator;
class CATPolyPointMeshDistance;

class CATSoftwareConfiguration ;
 
class ExportedByCATPolyCanonicOperators CATPolyCanonicRecognizePolyFace
{

public:
  /**
  *  Constructor and Destructor
  */
  CATPolyCanonicRecognizePolyFace(CATIPolySurface *iSurface); 

  CATPolyCanonicRecognizePolyFace (int iCloudNbPts, double *iCloudOfPts, double *iCloudNormals = NULL, CATBoolean iOnlyRecognize = TRUE) ;

  virtual ~CATPolyCanonicRecognizePolyFace();

  // Pour le Versionning
  void SetConfig (CATSoftwareConfiguration *iConfig) ;

  /**
  *  Set Tolerances
  */
  void SetTolOnVertices(double iTolVrt=0.1); //
  void SetToleranceSag(double iTolSag=0.1); // Pour les cylindre/Cones/Spheres/Tores
  void SetToleranceAlign(double iTolAlign=1., double iTolPlane = 0.05); // Planeite 

  void SetMaxRadius(double iMaxRadius=500.); // Tout est sphere/Cylindre ...

  // _DetectionTab[6] = {Plan, Cylindre, Cone, Sphere, Tore, Fillet/Tuyau}
  // Si _DetectionTab = 0 , alors on cherche dans chaque type
  void SetDetectOption(CATBoolean *iDetectionTab = 0) ;

  // pour Boeing, certains pts sont alignes ...
  void SetFiltreAlignPts(CATBoolean iMode = FALSE ) ;

  // dans le cas Mesh non tessele, pas besoin de calculer des Inits sur les bords ( Trop couteux! )
  void SetDisableInitSolut() ;

  void FixedRANSACNbiterations(int iNbIterations = 10, int iContainingSeed = -1) ;

  // On fixe le type a trouver, Pas de tolerance
  // iType={1, ..., 6 } = {Plan, Cylindre, Cone, Sphere, Tore, Fillet/Tuyau}
  void ForceDetection(int iType) ; 

  void SetFilletVersion(CATBoolean iNewVersion = FALSE, CATBoolean iOrderedSections = TRUE ) ;

  void SetRadiusReference (double iRefRadius=0., double iRefSag=0. ) ;
  void SetRefTriangle(int iSeed) ;

  void SetNbIteration(int iNbOfIterations);

  // Pour le digit : Perfo 
  void ImposedPlaneMeshIntersector(int iImposedNbOfPtsForFillet, CATMathPoint *iImposedTabOfPtsForComputeFillet, double iImposedRadiusForComputeFillet) ;


  int ComputeQuadricCoeff(int iNbPts, double *iTabOfPts, double *iTabNormals, CATMathPoint &oCenter, CATMathVector &oAxis, double oCoeffs[]) ;

  /**
  * Run
  */
  int Run() ;

  // iType={0, 1, 2, 3, 4} = {Plan, Cylindre, Cone, Sphere, Tore}
  // Init :  iRadius1, iRadius2( Tore ),  iCenter, iAlpha( Cone ), iAxis
  int Run(int iType, int iNbPts, CATMathPoint *iTabOfPts, double iRadius1, double iRadius2, 
    CATMathPoint &iCenter, double iAlpha, CATMathVector &iAxis, double iTol, double &oMaxDist, double &oPercPtsOK) ; 

  // iType={0, 1, 2, 3, 4} = {Plan, Cylindre, Cone, Sphere, Tore}
  // Init :  iRadius1, iRadius2( Tore ),  iCenter, iAlpha( Cone ), iAxis
  int Run(int iType, int iNbPts, double *iTabOfCoords, double iRadius1, double iRadius2, 
    CATMathPoint &iCenter, double iAlpha, CATMathVector &iAxis, double iTol, double &oMaxDist, double &oPercPtsOK) ; 

  //  Sur les contraintes :
  int Run_FixedConstraintsForPlane(CATMathVector &iFixedAxis) ;
  int Run_FixedConstraintsForCylinder(double iTol, CATMathVector &iFixedAxis, double &iFixedRadius, CATMathPoint *iInitCenter = 0) ;
  int Run_FixedConstraintsForCone(double iTol, CATMathVector &iFixedAxis, double &iFixedRadius1, double &iFixedRadius2, CATMathPoint *iInitCenter = 0) ;
  int Run_FixedConstraintsForSphere(double iTol, double &iFixedRadius, CATMathPoint *iInitCenter = 0) ;
  int Run_FixedConstraintsForTorus(double iTol, CATMathVector &iFixedAxis, double &iFixedSmallRadius, double &iFixedBigRadius, CATMathPoint *iInitCenter = 0) ;

  //  Sur les contraintes ( les points qui changent ):
  int Run_FixedConstraintsForPlane(int iNbPts, double *iTabOfCoords, CATMathVector &iFixedAxis) ;
  int Run_FixedConstraintsForCylinder(int iNbPts, double *iTabOfCoords, double iTol, CATMathVector &iFixedAxis, double &iFixedRadius, CATMathPoint *iInitCenter = 0) ;
  int Run_FixedConstraintsForCone(int iNbPts, double *iTabOfCoords, double iTol, CATMathVector &iFixedAxis, double &iFixedRadius1, double &iFixedRadius2, CATMathPoint *iInitCenter = 0) ;
  int Run_FixedConstraintsForSphere(int iNbPts, double *iTabOfCoords, double iTol, double &iFixedRadius, CATMathPoint *iInitCenter = 0) ;
  int Run_FixedConstraintsForTorus(int iNbPts, double *iTabOfCoords, double iTol, CATMathVector &iFixedAxis, double &iFixedSmallRadius, double &iFixedBigRadius, CATMathPoint *iInitCenter = 0) ;


  //lors de la propogation, il se peut qu'on a deja un bon Init
  void InitSolutionForPropagation(CATMathPoint &iInitCenter, CATMathVector &iInitAxis, double iInitRadius1, double iInitRadius2) ;
  /**
  * Get
  */

  void GetType(CATPolyGeometricForm &oForm) ;

  // l'erreur sur les vertex
  void GetMaxError(double iTol, double &oMaxDist, double &oPerctIsOK) ;

  int GetNbActiveBorder() ;

  // Call Only if oForm is Fillet :
  void GetParameters(int &oNfOfSections, double *&oSectionRadius, CATMathPoint *&oSectionCenter, 
    CATMathVector *&oSectionAxis, CATListOfDouble *&oSectionPoints, CATBoolean &oProfiledSurf) ;

  void GetKOTriangles(CATListOfInt &oListOfTriangKO, double &oRayonFillet); //Dans le cas de Fillet


  // Attentin Ca marche que pour le nouveau algo SetFilletVersion = TRUE
  void GetInfosFillet(int &oNbFacets, double *&oRadius, CATMathVector *&oAxis) ;

  void GetPrecisionFillet(double &oMaxSag, double &oMeanSag) ;

  // Ne pas utiliser : Pour ANR
  void GetQuadricParameters(CATMathPoint &oCenter, CATMathVector &oAxis) ;

  // dans le cas Cloud seulement :
  void GetEstimateNormals(double *&oNormalsCoords) ;

  void GetListOfPointsOK(CATListOfInt &oBestListOfPts) ;

private:

  static const double _epsg ; 
  static const double _epsf ;  
  static const double _epsx ; 

  int RunOnCloud() ;
  void ComputeGeometricInvariantDefinitions() ;

  int ComputeQuadric() ;
  int ComputeConic_withoutNormal() ;
  void ComputeInitsOnMeshByIntersection() ;
  int ComputeInitsOnMesh() ;
  int AdvancedInitsOnMesh() ;
  int ComputeInitsOnDigitMesh() ;

  CATBoolean FoundCircle(const CATLISTV(CATMathPoint) &iPoints, 
    double &oRadius, CATMathPoint &oCenter, CATMathVector &oAxis, double &oSag) ;

  CATBoolean DetectCylOrConeByTwoCircles() ;
  CATBoolean DetectTorusByThreeCircles() ;

  CATBoolean DetectIsPlane() ;

  CATBoolean DetectIsCylinderWithInit() ;
  CATBoolean DetectIsCylinder() ;

  CATBoolean DetectIsConeWithInit() ; 
  CATBoolean DetectIsCone() ;

  CATBoolean DetectIsSphere() ; 
  CATBoolean DetectIsTorus() ;


  CATBoolean FoundCirclePar3Points(CATMathPoint &P1,  CATMathPoint &P2, CATMathPoint &P3,
    double &oRadius, CATMathPoint &oCenter, CATMathVector &oAxis, double &oSag) ;

  //// Inspirer par le code de ZFI/NDO
  //CATBoolean DetectCircle(int nbVertices, CATMathPoint *iTabOfPts, CATBoolean iWithTestOption,
  //                        double &oRadius, CATMathPoint &oCenter, CATMathVector &oAxis, double &oSag) ;

  CATBoolean InitFillet() ;
  void ModifyFillet() ;

  CATBoolean TestOnNormalsIsOK(CATMathVector &iAxisSolut) ; 
  void CallPlaneMeshIntersector(CATMathPlane &iplane, double &oSag) ;
  //Appel plusieurs fois
  CATBoolean CallPlaneMeshIntersector(CATIPolyMesh *iPolyMesh, CATPolyExactArithmetic *exactArithmetic,
    CATMathPlane &iplane, CATPolyPlaneMeshIntersector *intersector, 
    double &oRadius, CATMathPoint &oCenter,
    CATMathVector &oAxis, double &oSag) ;

  CATBoolean QuickDetectTorus() ;

  void TestAndVerifyCylinder(CATMathPoint &iCenter, CATMathVector &iAxis, double iRadius) ;
  void TestAndVerifyCone(CATMathPoint &iCenter1, CATMathPoint &iCenter2, CATMathVector &iAxis, double iRadius1, double iRadius2) ;


  CATBoolean CheckCylinderResult() ;
  CATBoolean CheckConeResult() ;
  CATBoolean CheckSphereResult() ;
  CATBoolean CheckTorusResult() ;

  void Test_wrt_BestForm(CATMathPoint &iCenter1, CATMathPoint &iCenter2, CATMathVector &iAxis, double iRadius1, double iRadius2) ;

  int FoundSphereForDigit(CATMathPoint &oCenter, double &oRadius) ;


  int InitDataForConstraintes() ;

  CATBoolean RansacForPlaneDetection(CATMathVector *iImposedAxis=NULL) ;
  CATBoolean RansacForCylinderDetection() ;

  CATBoolean Cloud_DetectIsPlane() ;
  CATBoolean Cloud_DetectIsCylinder() ;
  CATBoolean Cloud_DetectIsCone() ;
  CATBoolean Cloud_DetectIsSphere() ;
  int EstimateNormals() ;

  void QuadrErrorForInitCylinder(double iRadius, double &oError) ;
  int ComputeQuadricForInit() ;
  double EstimateRadiusForCylinder(CATMathPoint &iCenter, CATMathVector &iAxis) ;

  void Torus_Constr_I_R_r(double iTol, CATMathVector &iFixedAxis, double &iFixedSmallRadius, double &iFixedBigRadius) ;
  void Torus_Constr_I_R(double iTol, CATMathVector &iFixedAxis, double &iFixedBigRadius) ;
  void Torus_Constr_I_r(double iTol, CATMathVector &iFixedAxis, double &iFixedSmallRadius) ;
  void Torus_Constr_I(double iTol, CATMathVector &iFixedAxis) ;

  CATBoolean InitAxisForTorus(int iNbVertices,  CATMathPoint *iPoints, CATMathVector &oEstimateAxis) ; 
  void Torus_Constr_R_r(double iTol, double &iFixedSmallRadius, double &iFixedBigRadius) ;
  void Torus_Constr_R(double iTol, double &iFixedBigRadius) ;
  void Torus_Constr_r(double iTol, double &iFixedSmallRadius) ;

  int converge_cylinder_context_cloud(double iTol, CATMathVector& iFixedAxis, double& iFixedRadius, CATMathPoint* iInitCenter,
                                      double& oRadiusSolut, CATMathPoint& oCenterSolut, CATMathVector& oFixedAxis, double& opercent_pts_ok);

  // Les champs =====================================

  CATSoftwareConfiguration *_Config ;

  CATIPolySurface *_PolySurf ;   
  double _TolSag, _TolAlign, _TolPlane ; 
  CATPolyCanonicOperTol* _Tolerance;
  CATBoolean _FixedSag ;

  CATBoolean _InitializeData, _ImposedConstr ;

  CATPolyCanonicOperData *_data ;
  CATIPolyMesh *_PolyMesh ;

  CATBoolean *_DetectTabOption ;

  int _NbTriangles, _NbVertices;
  CATListOfInt _ListOfFacets, _ListOfVertices ;

  CATMathPoint *_Points ;
  CATMathVector *_Normals_T, *_Normals_V ;
  CATMathPoint *_CenterFacets ;
  CATPolyGeometricForm *_DetectedForm ;
  double *_MedianFacet, *_FacetArea;
  double _CurrentBox ;

  CATBoolean _FiltragePtsAlignes ;
  int _NbPtsOfMeasure, _NbFacetsOfMeasure ;
  CATMathPoint *_PtsOfMeasure, *_FacetsOfMeasure ;

  int _NbBorders, _NbActiveBorder ;
  CATListOfInt _MaxBorder[2] ; 
  CATListOfInt *_ActiveBorderList ;

  double _Quadric[10] ;
  CATMathPoint  _QuadricCenter1, _QuadricCenter2 ;
  CATMathVector _QuadricAxis;
  CATBoolean _InitQuadric ;

  CATMathPoint	_centreG ;
  double			_C0[10]; // coefficients centree  


  CATListOfDouble _RadiusInit, _CenterInit, _AxisInit, _InitSag;

  double _EstimateSag, _ExactSag, _PNTSAG, _InitPNTSAG ;
  double _MaxRadius ;
  CATBoolean _ImposedMaxRadius ;


  // ajout pour detect Fillet
  CATBoolean _IsFillet ;
  double _FilletRayon ;

  CATIPolyMeshTriangleIterator* _TriangleIterator;
  CATPolyPointMeshDistanceAccelerator* _PointMeshDistanceAccelerator;
  CATPolyPointMeshDistance* _PolyPointMeshDistanceOperator;

  // Parametres de travail pour les fillets
  double _WorkParamForDist ;
  CATBoolean _ProfiledSurf ;
  int _NfOfSections ;
  double *_SectionRadius ;
  CATMathPoint  *_SectionCenter;
  CATMathVector *_SectionAxis;
  CATListOfDouble *_SectionPoints;

  CATBoolean _ForceDetect ;
  int        _TypeToDetect ; 
  CATPolyGeometricForm *_BestFormComputed ;
  double _MaxDistVrtToForm ;

  CATBoolean _VersionFillet, _OrderedSections ;

  double _FilletRayonRef, _FilletSagRef;
  int    _FilletSeedRef;


  CATListOfInt _ListOfTriangKO ; // dans le cas de 
  double _RayonFillet ;
  int _NbFilletFacets ;
  double *_FilletRadiusT;
  CATMathVector *_FilletAxisT ;

  double _MaxSag, _MeanSag ;

  // Pour proto Digit
  double _TolVrt ;
  CATBoolean _FixedTolOnVertices ;


  int _ImposedNbOfPtsForFillet;
  CATMathPoint *_ImposedTabOfPtsForComputeFillet ;
  double _ImposedRadiusForComputeFillet;


  // Pour le Cloud
  int            _CloudNumberOfPts ; 
  CATBoolean     _ModeCloudActive, _OnlyRecognize ;
  double *_CloudInputCoords, *_CloudEstimateNormals ;
  double _CurrentCloudBox ;

  double _I1, _I2, _I3, _I4, _P, _Q, _Is, _Ir ;
  double _K1, _K2, _r, _Phi, _Lambda[3] ;

  double _Radius_Sph, _Radius_Cyl, _Alpha_Cone ;


  CATListOfInt _BestListOfPts ; // dans le cas du RANSAC

  CATBoolean _WithInitSolutions ;

  double _InitSmallRadius, _InitBigRadius ; 

  CATMathPoint _InitCenter ;
  CATMathVector _InitAxis ;
  double _InitRadius1, _InitRadius2 ;

  int _NbIteraions_Ransac, _ContainingSeed ;

  int _NbOfIterations;
  CATBoolean _ImposedNbMaxits;
};

#endif
