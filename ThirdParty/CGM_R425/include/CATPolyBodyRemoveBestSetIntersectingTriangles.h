// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyRemoveBestSetIntersectingTriangles.h
// Header definition of CATPolyBodyRemoveBestSetIntersectingTriangles
//
//===================================================================
//
// Usage notes:
// This operator is dedicated to auto intersections removal in the PolyMeshes of a PolyBody
// There is usually a lot of different triangles subsets that, when removed, make the PolyMesh self intersections free.
// We will try to determine, according to some criteria that are defined above, which triangles subset is the best to be removed.
// The selection criteria is based on the cardinality of the subset (the less triangles we get rid of, the better), and cumulated areas of the selected triangles
// (removing only one giant triangle is not so good, it can represent a large part of the overall mesh).
// In addition, the operator will prevent triangles that define geometrical supports of edges and/or vertices of the PolyBody from being removed.
// Thus, we CANNOT GUARANTEE that the resulting PolyMeshes will be self intersections free.
// BE CAREFUL : this operator does not process the intersections between triangles from DIFFERENT meshes !
//
//===================================================================
//
// JUN 2015 Creation: ng4
//===================================================================
#ifndef CATPolyBodyRemoveBestSetIntersectingTriangles_h
#define CATPolyBodyRemoveBestSetIntersectingTriangles_h

#include "PolyBodyBVHOperators.h"
#include "CATErrorMacros.h"

class CATPolyBody;

class ExportedByPolyBodyBVHOperators CATPolyBodyRemoveBestSetIntersectingTriangles
{
public:

  CATPolyBodyRemoveBestSetIntersectingTriangles(CATPolyBody &iPolyBody);

  ~CATPolyBodyRemoveBestSetIntersectingTriangles();

  // This will launch the clash computation for each Surface support of all the faces of the PolyBody defined in the constructor.
  // CAREFUL : the clashes between two different meshes will not be checked !
  // As we do not want to remove triangles that define support geometries for edges or vertices, the resulting meshes may contain some auto intersections left.
  // In this case, we will return S_FALSE
  HRESULT Run();

private:

  CATPolyBody &_mPolyBody;
};

#endif

