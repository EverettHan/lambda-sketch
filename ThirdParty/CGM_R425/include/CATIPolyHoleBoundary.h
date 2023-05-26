#pragma once

#include "PolyBodyBoolean.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include <vector>
#include <utility>

/**
* Interface to a polyhedral boundary.
*
* A polyhedral boundary is a loop represented by vertices.
* It consists of:
*   o The positions at the vertices.
*   o The normals at the vertices.
*
*/
class ExportedByPolyBodyBoolean CATIPolyHoleBoundary {
public:
  /**
   * Returns the number of points in the boundary.
   * @return
   *   number of points.
   */
  virtual int GetNbNodes() const = 0;

  /**
   * Returns the position of a vertex.
   * @param idx
   *   The index of the vertex.
   * @return
   *   A CATMathPoint with the position of the vertex.
   */
  virtual CATMathPoint GetPosition(int idx) const = 0;

  virtual CATMathPoint const * GetPositions() const = 0;

  /**
   * Returns the normal of a vertex.
   * @param idx
   *   The index of the vertex.
   * @return
   *   A CATMathVector with the normal of the vertex.
   */
  virtual CATMathVector GetVertexNormal(int idx) const = 0;

  virtual CATMathVector const * GetNormals() const = 0;

  /**
   * Returns the adjacent triangles of a vertex.
   * @param idx
   *   The index of the vertex.
   * @param adjTriangles
   *	 The output vector. Each pair of CATMathPositions represents the opposite bar
   *	 of the vertex for each triangle.
   */
  virtual void GetAdjTriangles(int idx, std::vector<std::pair<CATMathPoint, CATMathPoint>>& adjTriangles) const  = 0;

  double Length();
};
