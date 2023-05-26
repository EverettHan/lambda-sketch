// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2014-2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMappingSegmentation.h
//
//===================================================================
//
// Usage notes: Simple Segmentation of Digit Mesh ( Regioning for Create CurveNetWork )
//
//===================================================================
// 
// Jan 2017 : ANR : Indus pour Reverse pour CurveNetWork/SurfaceNetWork (HONDA )
// Mai 2014 : ANR : Creation
//===================================================================

#ifndef CATPolyMappingSegmentation_H
#define CATPolyMappingSegmentation_H

#include "CATPolyCanonicOperators.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATIPolyMesh.h" 
#include "CATPolyGeoUtil.h"
#include "CATPolyTopoUtil.h"
#include "CATLib.h" 
#include "CATMathPlane.h"
#include "CATListOfDouble.h"
#include "CATListOfInt.h"  
#include "CATPolyMappingSegmDefineOptions.h"

class CATIPolyMeshTriangleIterator;
class CATPolyPointMeshDistanceAccelerator;
class CATPolyPointMeshDistance;
class CATMapOfIntToInt ; 
class CATPolyComputeCurvatures ; 

class ExportedByCATPolyCanonicOperators CATPolyMappingSegmentation
{

public:
  /**
  *  Constructor and Destructor
  */
  CATPolyMappingSegmentation(CATIPolyMesh *iPolyMesh);

  virtual ~CATPolyMappingSegmentation();

  /** 
  *  Set Options
  */  
  void SetAngle(const double iAngle=30); 

  // voir PolyhedralOperatorsAdv\ProtectedInterfaces\CATPolyMappingSegmDefineOptions.h
  void SetKMeansParams(int iNbClustering = 25, CATPolyCriterionForMappingSegmentation iCriterion = CATPolyClusteringNormals) ;

  //
  void SetParamsForCurvatureOper(CATPolyClusteringCurvaturesMethods iOper = ClusteringCurvaturesOperNua_dim_1);

  //
  void SetRandomInitCentroid(CATBoolean iMode) ;

  // Mode Split ou non en zone connexes :
  void SetSplitOption(CATBoolean iSplitInZonesConnexes=FALSE) ;

  void SetFilterSmallZones(int iNbMinTriangles = 1, CATBoolean iMergeSmallConnexeZones = FALSE ) ;

  //
  void SetCuttingPatch(int iIdxFacet = 0 ) ;
   

  /**
  * Run
  */
  HRESULT Run( ); 
   

  // les get
  int GetNbPatchesResult() ;
  void GetPatch(int iNumPatch, CATListOfInt &oListOftriangles) ;
    
  // A voir avec Reverse plus tard si on explose pas en zones connexes ???
  void GetSmallZones(CATListOfInt &oListOftriangles) ;

private:
   
   
  //Utilities
  void ListOfVerticesFromListOfTriangles(CATListOfInt &iListOfTriangles, CATListOfInt &oListOfVertices) ;
  void ListOfTrianglesFromListOfVertices(CATListOfInt &iListOfVertices, CATListOfInt &oListOfTriangles) ;
  void ComputeNormalTriangle(int iFacet, CATMathVector &oNormal) ;
  void ComputeNormalWithNRings(int iIdxFacet, int iNbRing, CATMathVector &oNormal) ;

  double ComputeAreaTriangle(int iFacet) ;

  // proto
  void Clustering_Proto_Normals(int k, CATListOfInt &iIndexInit) ;
  void Clustering_Proto_Curvatures(int k, CATListOfInt &iIndexInit) ;
  void Clustering_Proto_Voronoi(int k, CATListOfInt &iIndexInit) ;

  void splitInConnexeAreas() ;

  int SearchSeeds(CATListOfInt &oIndexInit) ;

  void CuttingOnePatch(int iIdxFacet) ;

  ////
  //CATBoolean GetOppositeAngle(int iIdxTriangle, int iNoVertex1, int iNoVertex2, CATAngle &oOppositeAngle) ;
  //double GetWeightOnEdge(const int iNoVertex1, const int iNoVertex2, CATBoolean iDivide) ;
  //double GetCotWeightFormula (const int iNoVertex1, const int iNoVertex2) ;

  //int VoronoiArea(int iIdxVertex, double &oVoronoiArea) ;
  //int MeanCurvatureVec(const int iNoVertex, CATMathVector &oMeanCrb) ;
  //int MixedArea(int iNoVertex, double &oMixedArea) ;
  //int GaussCurvature(const int iNoVertex, double &oGaussCrb) ;

  void MergeSmallZones(CATListOfInt &ioListOfFacetsToMerge, int iSize, CATListOfInt *ioListToKeep);
  //void ExpandConnexeZone(int iIdxFacet, CATMapOfIntToInt *iMapOfListToMerge, CATListOfInt &oExpandList);
  void ExpandFunction(int iIdxFacet, CATMapOfIntToInt *iMapOfListToMerge, CATMapOfIntToInt *iWorkingMap,
                      CATListOfInt &oExpandList, 
                      CATListOfInt &oListOfNeighbPatches, 
                      CATListOfInt &oSeedForEachNeighbors);

  void NormalOfPatch(CATListOfInt &iPatchFacets, CATMathVector &oNormalOfPatchToMerge);
  void ExpandInPatch(int iIdxFacet, CATMapOfIntToInt *iWorkingMap, int iIndexPatch, int iSizeOfTargetPatch, CATListOfInt &oExpandList);

  // Champs prives .........
  CATIPolyMesh *_PolyMesh ;

  //
  CATIPolyMesh *_WorkPolyMesh; 
  int *_TabNewToOld_v ;
  int *_TabNewToOld_t ;
  int _NbVertices, _Nbtriangles ;
  CATPolyGeoUtil *_geometryUtil ;
  CATPolyTopoUtil *_topoUtil ;
  int _IdxFacet ;

  // Optimise Normal Compute :
  CATListOfDouble _NormalList ;
  CATMapOfIntToInt *_MapNormalOnFacets;

  CATListOfDouble _AreaList ;
  CATMapOfIntToInt *_MapAreaOnFacets; 

  CATIPolyMeshTriangleIterator* _TriangleIterator;
  CATPolyPointMeshDistanceAccelerator* _PointMeshDistanceAccelerator;
  CATPolyPointMeshDistance* _PolyPointMeshDistanceOperator;
   
   

  CATMapOfIntToInt *_ActivateTriangles ;  
  CATListOfInt *_TabOfLargestListOfTriangles ;
  int _NbFoundedPatches ;
    
  CATListOfInt *_OrderedTabOfLargestListOfTriangles;
  double *_OrderedAreaOfFoundedPatches ;
   
  CATBoolean _RandomInit ;

  CATPolyComputeCurvatures *_CurvatureOper ;
    
  int _NbClustering ;
  CATPolyCriterionForMappingSegmentation _TypeOfClustering ;
  double _Angle_d;
  CATBoolean _SplitInZonesConnexes ;

  CATMapOfIntToInt *_MapOfVisitedTriangles ;

  int _NbMinTriangles ;
  CATBoolean _FilterSmallZones, _MergeSmallConnexeZones;

  CATListOfInt _AssemblySmallZones ;

  CATBoolean _SpecialCuttingPatch ;
  int _InputIdxFacet ;

  CATPolyClusteringCurvaturesMethods _curvature_operator_Method;

};

#endif
