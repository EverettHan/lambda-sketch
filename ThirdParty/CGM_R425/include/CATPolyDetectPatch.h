// COPYRIGHT DASSAULT SYSTEMES 2010-2022, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyDetectPatch.h
//
//===================================================================
//
// Usage notes: Find canonics (planes, cylinders, cones, fillets)
// in a Mesh from one triangle and one type
//
//===================================================================
// Aout 2022   : ANR : preparation de .h pour propagation manuelle a partir d'une liste graine
// Mai 2022    : ANR : Partiel : Ajout constraint "passant par" - livraison sur TSk de reverse
// 24 Fev 2022    : ANR : Attacher la fonction au lieu du cr
// Fev 2022    : ANR : Convergence 2022xfd02 ---->IR-921443-3DEXPERIENCER2022x
// Jul 2010  Creation: GR5
//===================================================================

#ifndef CATPolyDetectPatch_H
#define CATPolyDetectPatch_H

#include "CATPolyCanonicOperators.h"
#include "CATErrorDef.h"
#include "CATListOfInt.h" 
#include "CATBoolean.h"
#include "CATMathPlane.h"
#include "CATListOfDouble.h"
#include "CATPolyPointsOctreeOper.h"
#include "CATPolyPolygon2D.h"
#include "CATMathPoint2D.h"
#include "CATPolyExactArithmetic.h"

#ifndef _AIX_SOURCE
#include "CATPolyDetectPrimitivesInCloud.h"
#endif

#include "CATTolerance.h"

class CATIPolySurfaceFacetIterator;
class CATPolyIntegerSetPartition;
class CATPolyIntegerSetCover;
class CATPolySegmentLayer;
class CATIPolySurface; 
class CATIPolyMesh;
class CATPolyCanonicOperTol; 
class CATPolyGeometric2DPatch;
class CATPolySegmentManager;
class CATPolyGeometricForm;
class CATSoftwareConfiguration;
 
class CATPolyGeoUtil;
class CATMapOfIntToInt;
class CATPolyCanonicOperData;
class CATMathVector ;

class ExportedByCATPolyCanonicOperators CATPolyDetectPatch
{

public:

  // 2^0, 2^1, 2^2,2^3,2^4,2^5 ...
  enum
  {
    detect_plane_from_seed    = 1,
    detect_cylinder_from_seed = 2
  };

  /**
  *  Constructor and Destructor
  */
  CATPolyDetectPatch(CATTolerance *iTolObject=NULL);

  /**
  *  Constructor (multi-run ) on cloud of point
  */
  CATPolyDetectPatch(CATSoftwareConfiguration* iConfig, CATTolerance* iTolObject, int iNbPoints, double* iTabOfPoints);

  //
  virtual ~CATPolyDetectPatch();
 
  // Pour le Versionning
  void SetConfig (CATSoftwareConfiguration *iConfig) ;

  // For Tesselation ======================================================================================

  /**
  *  Set Tolerances
  */
  HRESULT SetToleranceExact(float iTolExact);
  HRESULT SetToleranceSag(float iTolSag);
  HRESULT SetToleranceAlign(float iTolAlign);
  HRESULT SetToleranceAlignExact(float iTolAlignExact);
  HRESULT SetToleranceSNT(float iSNT);

  // Attention pour le Plan : On attend une tol en degre ! -----> a partir de iLevel > 1 (23xGA) : ca sera en mm pour etre homegene avec Cloud
  void SetToleranceDigit(double iTol = 0.5, int iMaxInitNbFacets = 100);

  //
  void SetNewVersion(CATBoolean iMode = TRUE ) ;
 
  //
  void TrianglesNotToVisit(CATMapOfIntToInt *iMapOfVisitedTriangles) ;

  // set this option to get the last implementation level (n) : by default, we have level n-1.
  // current level = 1
  // iLevel = 2 : take into account tolerance in mm instead degree (Plane) ----> // new constraint 23xGA
  void ActivateTheLastLevel(int iLevel = 1); 

  /**
  * Run
  */
  HRESULT Run(int iType, int iIdxFacet,CATIPolySurface &iSurface, CATIPolySurfaceFacetIterator &iFacetIterator,
              CATPolyIntegerSetPartition& ioFacetPartition, CATPolySegmentLayer *&ioSegmentLayer);


  // For Digit ======================================================================================

  // Si la norme du vecteur ou la valeur du rayon est nulle ---> alors c'est pas une contrainte
  void FixedConstraintsForPlane(CATMathVector &iFixedAxis) ;
  void FixedConstraintsForCylinder(CATMathVector &iFixedAxis, double &iFixedRadius) ;
  void FixedConstraintsForCylinder(CATMathVector& iFixedAxis, CATMathPoint & iPassingByPoint); // new constraint 23xGA-FD01 (pour reverse) ---- passant par
  void FixedConstraintsForCone(CATMathVector &iFixedAxis, double &iFixedRadius1, double &iFixedRadius2) ;
  void FixedConstraintsForSphere(double &iFixedRadius) ;
  void FixedConstraintsForSphere(CATMathPoint& iFixedCenter); // new constraint 23xGA-FD01 (pour reverse) ---- passant par ----> c'est forcement centre dans ce cas
  void FixedConstraintsForTorus(CATMathVector &iFixedAxis, double &iFixedSmallRadius, double &iFixedBigRadius) ;
  
  HRESULT RunDigit(int iType, int iIdxFacet, CATIPolyMesh *iMesh, CATListOfInt &oTrianglesList, CATPolyGeometricForm &oForm);
  HRESULT RunDigit(int iType, CATListOfInt &iIdxFacets, CATIPolyMesh *iMesh, CATListOfInt &oTrianglesList, CATPolyGeometricForm &oForm);

  // Il y a que le Plan pour l'instant   
  HRESULT RunCloud(int iType, int iIdxPoint, int iNbPoints, double *iTabOfPoints, double iTol, CATListOfInt &oInitPtsList, CATListOfInt &oPointsList, CATPolyGeometricForm &oForm); // VA disparaitre ---- migrer sur le suivant

  // Il y a que le Plan pour l'instant
  HRESULT RunCloud(int iType, int iIdxPoint, int iNbPoints, double *iTabOfPoints, int *iActivePoints, double iTol, CATListOfInt &oInitPtsList, CATListOfInt &oPointsList, CATPolyGeometricForm &oForm);

  // Il y a que le Plan/Cylindre pour l'instant
  // if #ifdef _WINDOWS_SOURCE ( to migrate to linux 22x FD02 )
  // ----------------------- RAPPEL -----------------------
  // 2^0, 2^1, 2^2,2^3,2^4,2^5 ...
  //enum
  //{
  //  SEARCH_PLANES = 1,
  //  SEARCH_CYLINDERS = 2,
  //  SEARCH_JUNCTIONS = 4,
  //  SEARCH_PIPES = 8,
  //  SEARCH_SPHERES = 16,
  //  SEARCH_CONES = 32
  //};
  HRESULT RunCloud(int iParamSearchType, int iIdxPoint, double iTol, CATListOfInt& oPointsList, CATPolyGeometricForm& oForm);

  //Not yet Implemeted --->23xFD02 (23xFD01?)
  //Limitation : Only Plane/Cylinder
  HRESULT RunCloud(int iParamSearchType, CATListOfInt& iIdxListOfPoints, double iTol, CATListOfInt& oPointsList, CATPolyGeometricForm& oForm);

  //
  void GetErrors(double &omax_deviation, double& mean_deviation, double& opercent, int &oIndexMaxDeviation, CATMathPoint &opoint_with_max_deviation);

private:



  HRESULT CallFilletOperator(CATIPolySurface *iSurface, int IdxTriSeed, CATPolySegmentManager &isegmentManager, 
                             double iMaxRadius, int &oNewIndex, double &oRadiusFillet);


  HRESULT RunWithExpand(int iType, int iIdxFacet, CATIPolySurface &iSurface, CATIPolySurfaceFacetIterator &iFacetIterator,
																          CATPolyIntegerSetPartition& ioFacetPartition, CATPolySegmentLayer *&ioSegmentLayer) ;


  // Pour QSR : Le plan Moyen
  CATBoolean InertialFrame (const int iNbPoints, const double *iCoords,
                            double oBarycenter[3], double oEigenValues[3], double oEigenVectors[3][3]) ;

  int ComputeMeanPlane(int NbPoints, const double *VerticesCoords, CATMathPlane &oBasePlane, CATBoolean iTest) ;


  void ComputeVertexNormal(int iVrt, CATMathVector &oNormalV) ;
  void ComputeNormalTriangle(int iFacet, CATMathVector &oNormal) ;
  void ExpandPlaneAroundFacet(CATIPolyMesh *iMesh, int iIdxFacet, CATListOfInt &oTrianglesList, CATPolyGeometricForm &oForm) ;

  HRESULT ExpandPlaneAroundPoint(int iNbPoints, double *iTabOfPoints, int iIdxPoint, CATListOfInt &oInitPtsList, CATListOfInt &oPointsList, CATPolyGeometricForm &oForm) ; // VA disparaitre ---- migrer sur le suivant
  HRESULT ExpandPlaneAroundPoint(int iNbPoints, double *iTabOfPoints, int *iActivePoints, int iIdxPoint, CATListOfInt &oInitPtsList, CATListOfInt &oPointsList, CATPolyGeometricForm &oForm) ;

  void UpdatePlanarPatch(double *VerticesCoords, CATListOfInt &iListVertices, double InputTol, 
                         CATPolyGeometricForm &oFormResult, double &oCurrentMaxError, double &oCurrentMeanError) ;

  int GetBarOrientation (const int iVertices[3], const int iVertex0, const int iVertex1) ;
  HRESULT GetTriangleFromPolygon (const CATPolyPolygon2D& polygon, CATPolyFace2D* face, int v[]) ;

  HRESULT ConstructPolygonAndTriangulate (const CATPolyExactArithmetic* exactArithmetic,
                                          const CATMathPoint2D* points2D, const int nbPoints,
                                          CATPolyPolygon2D& oPolygon) ;
  HRESULT MeshConstruction(int iNbPoints, double *iVerticesCoords, CATListOfInt &iPointsList, CATPolyGeometricForm &iForm) ;


  HRESULT ExpandCylinderAroundPoint(int iNbPoints, double *iTabOfPoints, int *iActivePoints, int iIdxPoint, CATListOfInt &oInitPtsList, CATListOfInt &oPointsList, CATPolyGeometricForm &oForm) ;
  int FitPlaneToPoints(double *iVerticesCoords, CATListOfInt &iListVertices, CATMathVector &oNormal) ;

  int SearchCylinder(double *iVerticesCoords, int *iActivePoints, CATListOfInt &iListOfPoint, 
                     CATPolyGeometricForm &oCylinderForm, double &oMaxDist, double &oPerctIsOK) ;

  int EvalCurvatureOnQuadric(double xx, double yy, double zz, double *iCoeff, double &oKK, double &oHH) ;

  void PropagatePlane(CATIPolyMesh *iMesh, int iIdxFacet, CATPolyGeometricForm &ioForm, CATListOfInt &oTrianglesList) ;

  int DefineInit(int iNbPts, double *iTabOfPts, CATPolyGeometricForm &iForm, CATMathPoint &oCenter, double &oRadius1, double &oRadius2, CATMathVector &oAxis, double &oAlpha) ;

  void PropagatePrimitiveByDistance(int iType, double iTolerance, CATIPolyMesh *iMesh, CATPolyGeometricForm &iBestFormComputed, CATListOfInt &ioListOfTrianglesFromSeed) ;
  void PropagatePrimitiveByDistance(int iType, double iTolerance, CATIPolyMesh *iMesh, int iIdxFacet, CATPolyGeometricForm &iForm, CATListOfInt &ioTrianglesList) ;

  void ComputesVerticesListFromFacetsList(CATIPolyMesh *iMesh, CATListOfInt &iTrianglesList, CATListOfInt &oVerticesList) ;
  void EstimateToleranceForPlane(CATIPolyMesh *iMesh, CATPolyGeometricForm &iPlanarForm, CATListOfInt &iTrianglesList, double &oPlanarTol3D) ;
  void UpdatePlane(CATIPolyMesh *iMesh, CATListOfInt &iTrianglesList, CATPolyGeometricForm &ioForm) ;
  void UpdateCone(CATIPolyMesh *iMesh, CATListOfInt &iTrianglesList, CATPolyGeometricForm &ioForm) ;

  void ajust_result(CATIPolyMesh* iMyPolyMesh, CATListOfInt& ioListOfTriangles, CATPolyGeometricForm& iogForm);

  // Champs Prives :
  //-------------------------------------------------
  CATSoftwareConfiguration *_Config ;
 
  CATPolyCanonicOperTol* _Tolerance;
  CATBoolean _NewVersion ;
 
  double _DigitTol ;
  int _MaxInitNbFacets ;
  CATBoolean _DigitMeshCase ;
  CATBoolean _modified_tolerance;
  
  CATBoolean _OptionCleanResult ;

  // Dev sur le Plan : On supprime le code de Mer facebook
  CATIPolyMesh *_MyPolyMesh ; 
  CATPolyCanonicOperData *_Data ;
  CATPolyGeoUtil *_GeoUtil ;
  CATListOfDouble _NormalV, _NormalList ;
  CATMapOfIntToInt *_MapOnNormalVertices, *_MapOnFacets;

  CATMapOfIntToInt *_MapDesActivateTrs ; // on alloue la plus petite

  // Dev sur les constraintes
  CATMathVector _FixedAxis ;
  double _FixedRadius1, _FixedRadius2 ;

  CATBoolean _ConstrOnPlane, _ConstrOnCylinder, _ConstrOnCone, _ConstrOnsphere, _ConstrOnTorus;



  // Dev pour le Cloud
  CATBoolean _CloudCase ;
  CATPolyPointsOctreeOper *_OctreeOper ;
  int *_Indexes ; // Temp A supprimer
  int _IdxInitLeaf ;
  int _MinPointsOctree ;


  CATMapOfIntToInt *_MapOfTrianglesNotToVisit ; // Proto de JEP sur Reconstruction3D

  CATTolerance *_TolObject ;
  double _zero_value;
  double _null_norm_of_vector;

  CATBoolean _new_dev_propagation_on_cloud_from_seed; //multi-run
  int _Input_nb_points;
  double* _input_vertices_coords;

  int _ParamSearchMode;
#ifndef _AIX_SOURCE
  CATPolyDetectPrimitivesInCloud *_detect_oper;
#endif

  double _max_deviation, _mean_deviation, _opercent;
  int _IndexMaxDeviation; CATMathPoint _point_with_max_deviation;

  int _LastLevel;
  CATMathPoint _Point_on_Axis; // for cylinder (and axis)
  CATBoolean _passing_by_point;
};

#endif
