// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCanonicDetectOper_2.h
//
//===================================================================
//
// Usage notes: Find canonics (planes, ... (cylinders, cones, fillets) )  in a Mesh
//
//===================================================================
// 
// Mai 2014 : ANR : Creation
//===================================================================

#ifndef CATPolyCanonicDetectOper_2_H
#define CATPolyCanonicDetectOper_2_H

#include "CATPolyCanonicOperators.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATIPolyMesh.h" 
#include "CATPolyGeoUtil.h"
#include "CATLib.h" 
#include "CATMathPlane.h"
#include "CATListOfDouble.h"
#include "CATListOfInt.h"
#include "CATPolyPointsOctreeOper.h"

#include "CATPolyCriterionPrimDetec.h"

class CATIPolyMeshTriangleIterator;
class CATPolyPointMeshDistanceAccelerator;
class CATPolyPointMeshDistance;
class CATMapOfIntToInt ;
class CATPolyGeometricForm ; 

class ExportedByCATPolyCanonicOperators CATPolyCanonicDetectOper_2
{

public:
  /**
  *  Constructor and Destructor
  */
  CATPolyCanonicDetectOper_2(CATIPolyMesh *iPolyMesh);

  virtual ~CATPolyCanonicDetectOper_2();


  /**
  *  Set Tolerances
  */ 
  void SetToleranceOnVertices(double iTol);
  void SetToleranceOnTriangles(double iTol);


  /** 
  *  Set Options
  */ 
  void SetPlaneSurfDetection(CATBoolean iActivate);


  // Si iCriterion = CATPolyDetectPrimitivesByMinArea     : iValueParam = Aire Minimum pour la region retenue
  // Si iCriterion = CATPolyDetectPrimitivesByMaxNbPlanes : iValueParam = Nombre Max de Plans a rechercher dans le Mesh 
  void SetCriterionForPlane (double iValueParam, CATPolyCriterionForDetectPrimitives iCriterion);


  /**
  * Run
  */
  HRESULT Run( ); 

  //
  void GetLargestPlane(CATMathPlane &oPlane, CATListOfInt &oListOftriangles) ;

  // Il faut seter un nombre de plans a trouver
  int GetNbPlanesResult() ;
  void GetPlane(int iNumPlane, CATMathPlane &oPlane, CATListOfInt &oListOftriangles) ;

private:

  int InitAlloc() ;
  int CallToOctreeOper() ;
  int ComputeInitPlanes() ;

  void ListOfVerticesFromListOfTriangles(CATListOfInt &iListOfTriangles, CATListOfInt &oListOfVertices) ;
  void DistancePtsToPlane(CATListOfInt &iListVertices, double InputTol, CATMathPlane &iPlane, double &oCurrentMaxError, double &oCurrentMeanError, double &oPourc) ;

  void UpdatePlanarPatch(CATListOfInt &iListVertices, double InputTol, CATPolyGeometricForm &oFormResult, 
    double &oCurrentMaxError, double &oCurrentMeanError, CATBoolean iWithComputeDistance=TRUE) ;

  void ExpandPlaneAroundFacet(CATIPolyMesh *_MyPolyMesh, CATPolyGeoUtil *igeometryUtil, int iIdxFacet,  CATMathPoint &InitCenter, CATMathVector &InitNormal,
    CATMapOfIntToInt *_MapOfTrianglesNotToVisit, double InputTol, CATListOfInt &oTrianglesList, CATPolyGeometricForm &oForm) ;


  void PropagateByDistance(double InputTol, CATIPolyMesh *_MyPolyMesh, CATPolyGeoUtil *geometryUtil, 
    CATListOfInt &_ListOfTrianglesFromSeed, CATMapOfIntToInt *_MapOfFacetsIsOK,
    CATPolyGeometricForm &iFormResult ) ;

  int ComputeLargestPlane() ;

  //Utilities
  void ComputeNormalTriangle(int iFacet, CATMathVector &oNormal) ;
  void ComputeNormalWithNRings(int iIdxFacet, int iNbRing, CATMathVector &oNormal) ;

  double ComputeAreaTriangle(int iFacet) ;

  CATIPolyMesh *_PolyMesh ;

  double _InputTolOnVertices, _InputTolOnTriangles ;

  CATPolyGeoUtil *_geometryUtil ;
  int _NbVertices ;
  double *_VerticesCoords ;
  double *_NormalsCoords ; 
  int * _Indexes ;

  // Optimise Normal Compute :
  CATListOfDouble _NormalList ;
  CATMapOfIntToInt *_MapNormalOnFacets;

  CATListOfDouble _AreaList ;
  CATMapOfIntToInt *_MapAreaOnFacets;

  CATPolyPointsOctreeOper *_OctreeOper ;

  CATIPolyMeshTriangleIterator* _TriangleIterator;
  CATPolyPointMeshDistanceAccelerator* _PointMeshDistanceAccelerator;
  CATPolyPointMeshDistance* _PolyPointMeshDistanceOperator;

  int _NbOfCondidatePts ;
  CATMathPoint  *_CondidatePts ;
  CATMathVector *_CondiateNormals ;
  int *_CondidateVertices ;

  CATMathPlane _LargestPlane ;
  CATListOfInt _LargestListOfTriangles;

  CATMapOfIntToInt *_ActivateTriangles ; 
  CATMathPlane *_TabOfLargestPlane ;
  CATListOfInt *_TabOfLargestListOfTriangles ;
  double *_AreaOfFoundedPlanes ;
  int _NbFoundedPlanes ;

  CATPolyCriterionForDetectPrimitives _PlaneCriterion ;
  int _NbPlanesToFound ;
  double _MinPlaneArea ;
};

#endif
