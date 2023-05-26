
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMappingSegmentation.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//  
// Jan 2017 : ANR : Creation Indus pour Reverse pour CurveNetWork/SurfaceNetWork (HONDA )
//===================================================================
#ifndef CATPolyMappingSegmDefineOptions_H
#define CATPolyMappingSegmDefineOptions_H

 //
typedef enum  
{  
  CATPolyClusteringNormals = 0,
  CATPolyClusteringVoronoi = 1,
  ClusteringCurvatures     = 2 // Don't used...
  // ...
}CATPolyCriterionForMappingSegmentation;
 

//
typedef enum
{
  ClusteringCurvaturesOperRvs_dim_1 = 0,
  ClusteringCurvaturesOperNua_dim_1 = 1,
  ClusteringCurvaturesOperNua_dim_3 = 2 // Don't used...
  // ...
}CATPolyClusteringCurvaturesMethods;

#endif
