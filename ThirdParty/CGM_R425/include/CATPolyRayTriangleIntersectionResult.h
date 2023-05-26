//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyRayTriangleIntersectionResult
//
//=============================================================================
// 2009-07-01   MPX: New
//=============================================================================
#ifndef CATPolyRayTriangleIntersectionResult_H
#define CATPolyRayTriangleIntersectionResult_H

#include "CATPolyRayTriangleIntersector.h"
#include "CATPolyFastMeshExport.h"
#include "CATErrorDef.h"

class CATIPolyMesh;
class CATMathPoint;
class CATMathDirection;

class ExportedByCATPolyFastMesh CATPolyRayTriangleIntersectionResult
{
public:
  // Two methods to get intersection point. 
  // One gets the result point on the ray, the other gets the result on Triangle
  // Both points should be very close (within resolution)

  // Needs the ray origin and ray dir as input
  HRESULT GetIntersectionPointOnRay(CATMathPoint& iRayOrigin, CATMathDirection& iRayDir, CATMathPoint& oResultPoint);

  // Needs the CATIPolyMesh as input
  HRESULT GetIntersectionPointOnTriangle(CATIPolyMesh& iMesh, CATMathPoint& oResultPoint);
  
  // Get the index of the intersecting triangle
  int GetTriangleIdx() const {return _TriangleIdx;}

public:
  CATPolyRayTriangleIntersectionResult(int v1 = -1, int v2 = -1, int v3 = -1);

public:
  CATPolyRayTriangleIntersector::Result _Details;
  int _TriangleIdx;
  int _v1, _v2, _v3;
};

extern int operator == (const CATPolyRayTriangleIntersectionResult &iRes1, 
                        const CATPolyRayTriangleIntersectionResult &iRes2);
extern int operator != (const CATPolyRayTriangleIntersectionResult &iRes1, 
                        const CATPolyRayTriangleIntersectionResult &iRes2);
extern int CompareResults(CATPolyRayTriangleIntersectionResult* iRes1, 
                          CATPolyRayTriangleIntersectionResult* iRes2);

#endif // !CATPolyRayTriangleIntersectionResult_H

