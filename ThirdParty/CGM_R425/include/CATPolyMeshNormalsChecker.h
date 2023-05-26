//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2016
//=============================================================================
//
// CATPolyMeshNormalsChecker
//
// Check if the normal layer is coherent with the triangles orientations
//
//=============================================================================
// 2016-06-27 JXO: New.
// 2017-10-31 JXO: Check with the number of bad triangles
//=============================================================================
#ifndef CATPolyMeshNormalsChecker_H
#define CATPolyMeshNormalsChecker_H

#include "CATPolyAnalyzeOperators.h"

// Poly math
#include "CATSetOfInt.h"

// System
#include "CATErrorDef.h"


class CATIPolyMesh;

/**
 * This check looks for the normal layer, and if set looks to see if vertex normals
 * are coherent with the triangle normals.
 */
class ExportedByCATPolyAnalyzeOperators CATPolyMeshNormalsChecker
{
public:
  /**
  * Looks for the normal layer, and if set looks to see if vertex normals
  * are coherent with the triangle normals.
  * @param iMesh
  *        Input mesh to be checked.
  * @param oBadVertices
  *        Set of vertices index that have their normal too different from one of the adjacent triangles.
  * @param iMinimumCos
  *        The minimum cosinus the vertex normal must have with the triangle normal to be considered valid.
  *        We compute VertexNormal dot TriangleNormal and if this value is below iMinimumCos, then the vertex is not valid.
  *        Default value of -0.5 means an angle of 120 degrees or more between the two normals and the vertex is not valid.
  * @return S_OK if no vertex is invalid.
  *         S_FALSE if at least one vertex is invalid.
  *         E_XXX on unrecoverable error.
  */
  static HRESULT Check(const CATIPolyMesh & iMesh, CATSetOfInt & oBadVertices, double iMinimumCos = -0.5);

  /**
  * Looks for the normal layer, and if set looks to see if vertex normals
  * are coherent with the triangle normals.
  * @param iMesh
  *        Input mesh to be checked.
  * @param oBadVertices
  *        Set of vertices index that have their normal too different from the one from the adjacent triangles.
  * @param oBadTriangles
  *        Set of triangle index that have their normal too different from one from the adjacent triangles.
  * @param iMinimumCos
  *        The minimum cosinus the vertex normal must have with the triangle normal to be considered valid.
  *        We compute VertexNormal dot TriangleNormal and if this value is below iMinimumCos, then the vertex is not valid.
  *        Default value of -0.5 means an angle of 120 degrees or more between the two normals and the vertex is not valid.
  * @return S_OK if no vertex is invalid.
  *         S_FALSE if at least one vertex is invalid.
  *         E_XXX on unrecoverable error.
  */
  static HRESULT Check(const CATIPolyMesh & iMesh, CATSetOfInt & oBadVertices, CATSetOfInt & oBadTriangles, double iMinimumCos = -0.5);

protected:
  CATPolyMeshNormalsChecker(){}
  ~CATPolyMeshNormalsChecker(){}
};


#endif // !CATPolySurfaceNormalsChecker_H
