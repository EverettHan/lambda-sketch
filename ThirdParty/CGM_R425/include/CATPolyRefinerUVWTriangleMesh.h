// COPYRIGHT DASSAULT SYSTEMES 2007-2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyRefinerUVWTriangleMesh.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// May 2007  Creation: ndo
//===================================================================
#ifndef CATPolyRefinerUVWTriangleMesh_h
#define CATPolyRefinerUVWTriangleMesh_h

#include "PolyVizRefiners.h"
#include "CATPolyRefinerTriangleMesh.h"
#include "CATPolyRefinerTSurfaceTessPoint.h"
#include "CATErrorDef.h"  // HRESULT definition.
#include "CATMathPoint.h"
#include "CATMathVector.h"

#ifdef CGMMESHREFINER_TURN_ON_BOUND_CHECK
#include "CATAssert.h"
#endif

class CATPolyRefinerPattern;
class CATMathPoint;
class CATMathVector;

class CATCGMOutput;


//-----------------------------------------------------------------------------
// CATPolyRefinerUVWTriangleMesh
// Class defining a simple tessellation pattern for adaptive refinement.
//-----------------------------------------------------------------------------
class ExportedByPolyVizRefiners CATPolyRefinerUVWTriangleMesh : public CATPolyRefinerTriangleMesh
{

public:

  // Initialize a tessellated triangle uniformly at the given level.
  CATPolyRefinerUVWTriangleMesh (const unsigned int level);

  // Initialize a tessellated triangle from a generic pattern and specific refinement levels.
  CATPolyRefinerUVWTriangleMesh (const CATPolyRefinerPattern& iPattern, const unsigned int levelsSide[]);

  ~CATPolyRefinerUVWTriangleMesh ();

public:

  //
  // Queries about the tessellation of a PN-Triangle surface.
  // Iterators through the vertices: corners, sides and inside the PN-triangle.
  //

  // Return the corner vertex.
  inline unsigned int GetCornerVertex (const unsigned int iCorner) const;
 
  // Return the number of inner vertices (also the refinement level) of the side (from 1 to 3).
  // Iterators for inner vertices of side. (Iterator returns 0 when done cycling through all vertices.)
  inline unsigned int GetNbInnerVerticesOfSide (const unsigned int iSide) const;
  unsigned int GetFirstInnerVertexOfSide (const unsigned int iSide) const;
  unsigned int NextInnerVertexOfSide (const unsigned int vertex) const;

  // Return the number of inner vertices of the triangle.
  // Iterator for inner vertices of triangle. (Iterator returns 0 when done cycling through all vertices.)
  inline unsigned int GetNbInnerVerticesOfTriangle () const;
  unsigned int GetFirstInnerVertexOfTriangle () const;
  unsigned int NextInnerVertexOfTriangle (const unsigned int vertex) const;

public:

  //
  // Queries about the parameters u, v, w associated to the vertices and the
  // coordinates of the 3D points.
  // 

  // Return the UVW associated to a vertex.
  // @param iVertex
  //   Index from 1 to GetNbVertices () included.
  inline void GetUVW (const unsigned int iVertex, double uvw[]) const;

  // Return a pointer to the coordinates of the vertex.
  // (from 1 to GetNbVertices () included).
  inline CATMathPoint& Point (const unsigned int iVertex);
  inline const CATMathPoint& Point (const unsigned int iVertex) const;

  // Return a pointer to the normal at the vertex.
  // (from 1 to GetNbVertices () included).
  inline CATMathVector& Normal (const unsigned int iVertex);
  inline const CATMathVector& Normal (const unsigned int iVertex) const;

public:

  // Given the barycentric coordinates, evaluate the point.
  void Evaluate (const double uvw[], CATMathPoint& oPoint) const;
 
public:

  //
  // Functions supporting the optimization of the pattern by bar flipping.
  //

  // Return all the bars that are candidates to a flip.
  // Array must be deleted after a call to this method.
  unsigned int* GetCandidateBarsToFlip (unsigned int& oNbBarsToFlip) const;

public:

  // For debugging purposes.
  void Print (CATCGMOutput& stream) const;

protected:

  // Number of inner vertices along the sides of the triangle.
  unsigned int _NbSideInnerVertices[3];

  // UVW Parameters.
  CATPolyRefinerTSurfaceTessPoint* _UVW;

protected:

  void Clear ();

};


inline unsigned int CATPolyRefinerUVWTriangleMesh::GetCornerVertex (const unsigned int iCorner) const
{
#ifdef CGMMESHREFINER_TURN_ON_BOUND_CHECK
  CATAssert (0 < iCorner && iCorner <= 3);
#endif
  return iCorner;
}
 
inline unsigned int CATPolyRefinerUVWTriangleMesh::GetNbInnerVerticesOfSide (const unsigned int iSide) const
{
#ifdef CGMMESHREFINER_TURN_ON_BOUND_CHECK
  CATAssert (0 < iSide && iSide <= 3);
#endif
  return _NbSideInnerVertices[iSide-1];
}

inline unsigned int CATPolyRefinerUVWTriangleMesh::GetNbInnerVerticesOfTriangle () const
{
  return _NbVertices - _NbSideInnerVertices[0] - _NbSideInnerVertices[1] - _NbSideInnerVertices[2] - 3;
}

inline void CATPolyRefinerUVWTriangleMesh::GetUVW (const unsigned int iVertex, double uvw []) const
{
#ifdef CGMMESHREFINER_TURN_ON_BOUND_CHECK
  CATAssert (_UVW && 0 < iVertex && iVertex <= GetNbVertices ());
#else
  CATAssert (_UVW);
#endif
  _UVW[iVertex-1].GetUVW (uvw);
}

inline CATMathPoint& CATPolyRefinerUVWTriangleMesh::Point (const unsigned int index)
{
#ifdef CGMMESHREFINER_TURN_ON_BOUND_CHECK
  CATAssert (0 < index && index <= _NbVertices);
#else
  CATAssert (_UVW);
#endif
  return _UVW[index-1].Point ();
}

inline const CATMathPoint& CATPolyRefinerUVWTriangleMesh::Point (const unsigned int index) const
{
#ifdef CGMMESHREFINER_TURN_ON_BOUND_CHECK
  CATAssert (0 < index && index <= _NbVertices);
#else
  CATAssert (_UVW);
#endif
  return _UVW[index-1].Point ();
}

inline CATMathVector& CATPolyRefinerUVWTriangleMesh::Normal (const unsigned int index)
{
#ifdef CGMMESHREFINER_TURN_ON_BOUND_CHECK
  CATAssert (0 < index && index <= _NbVertices);
#else
  CATAssert (_UVW);
#endif
  return _UVW[index-1].Normal ();
}

inline const CATMathVector& CATPolyRefinerUVWTriangleMesh::Normal (const unsigned int index) const
{
#ifdef CGMMESHREFINER_TURN_ON_BOUND_CHECK
  CATAssert (0 < index && index <= _NbVertices);
#else
  CATAssert (_UVW);
#endif
  return _UVW[index-1].Normal ();
}

#endif
