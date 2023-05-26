//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATIPolyFastMesh
//
//=============================================================================
// 2009-07-01   MPX: New
//=============================================================================
#ifndef CATPolyListOfRayTriangleIntersections_H
#define CATPolyListOfRayTriangleIntersections_H

#include "CATLISTV_Clean.h"

#define CATLISTV_Append
#define CATLISTV_QuickSort

#include "CATLISTV_Declare.h"

#include "CATPolyRayTriangleIntersectionResult.h"
#include "CATPolyConvexHullExport.h"

#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATPolyConvexHull

CATLISTV_DECLARE (CATPolyRayTriangleIntersectionResult)
typedef CATLISTV(CATPolyRayTriangleIntersectionResult) CATPolyListOfRayTriangleIntersections;

#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy

#endif // !CATPolyListOfRayTriangleIntersections_H
