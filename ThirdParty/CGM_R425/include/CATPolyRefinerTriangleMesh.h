// COPYRIGHT DASSAULT SYSTEMES 2007-2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyRefinerTriangleMesh.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// May 2007  Creation: ndo
//===================================================================
#ifndef CATPolyRefinerTriangleMesh_h
#define CATPolyRefinerTriangleMesh_h

#include "PolyVizRefiners.h"
#include "CATErrorDef.h"  // HRESULT definition.
#include "CATBoolean.h"
#include "CATAssert.h"

class CATCGMOutput;

// For improved performance, do no define CGMMESHREFINER_TURN_ON_BOUND_CHECK.
//#define CGMMESHREFINER_TURN_ON_BOUND_CHECK 1


//-----------------------------------------------------------------------------
// CATPolyRefinerTriangleMesh
// Class defining a simple tessellation (refinement) of triangle.
// No geometry is stored in this class (topology only).
// The numbers of vertices, bars and triangles of this simple mesh cannot exceed 65535.
//-----------------------------------------------------------------------------
class ExportedByPolyVizRefiners CATPolyRefinerTriangleMesh 
{

public:

  CATPolyRefinerTriangleMesh ();
  ~CATPolyRefinerTriangleMesh ();

public:

  // 
  // Basic queries about the vertices, bars and triangles of the tessellated triangle.
  // Vertices are numbered from 1 to GetNbVertices ().
  // 

  inline unsigned int GetNbVertices () const;
  inline unsigned int GetNbBars () const;
  inline unsigned int GetNbTriangles () const;

  // Return the two vertices of the bar given the bar index.
  // @param iBar
  //   Index from 1 to GetNbBars () included.
  // @param oBarVertices[]
  //   The two vertices of the bar (0 if bar is undefined.)
  inline void GetBar (const unsigned int iBar, unsigned int oBarVertices[]) const;

  // Return the two triangles adjacent to the bar given the bar index.
  // @param iBar
  //   Index from 1 to GetNbBars () included.
  // @param oBarTriangles[]
  //   The two triangles adjacent to the bar (0 is triangle is undefined.)
  inline void GetBarTriangles (const unsigned int iBar, unsigned int oBarTriangles[]) const;

  // Return the three vertices of the triangle given the triangle index.
  // @param iTriangle
  //   Index from 1 to GetNbTriangles () included.
  // @param oTriangleVertices[]
  //   The three vertices of the triangle (0 if triangle is undefined.)
  inline void GetTriangle (const unsigned int iTriangle, unsigned int oTriangleVertices[]) const;

  // Return the three bars of the triangle given the triangle index.
  // @param iTriangle
  //   Index from 1 to GetNbTriangles () included.
  // @param oTriangleBars[]
  //   The three bars of the triangle (0 if triangle is undefined.)
  inline void GetTriangleBars (const unsigned int iTriangle, unsigned int oTriangleBars[]) const;

public:

  //
  // Basic const services.
  // 

  // Check if a bar belongs to a triangle.
  CATBoolean IsBarOfTriangle (const unsigned int bar, const unsigned int triangle) const;

  // Return the opposite vertex to a bar in a triangle.
  unsigned int GetOppositeVertex (const unsigned int bar, const unsigned int triangle) const;

  // Return the two vertices opposite the bar shared by two triangles (0 undefined vertices).
  void GetOppositeVertices (const unsigned int iBar, unsigned int& oVertex0, unsigned int& oVertex1) const;

public:

  //
  // Basic services.
  //

  // Flip a bar.  The bar must be shared by two triangles.
  HRESULT FlipBar (const unsigned int bar);

public:

  // For debugging purposes.
  CATBoolean Check () const;
  void Print (CATCGMOutput& stream) const;

protected:

  // Memory management.

  HRESULT SetNbVertices (const unsigned int iNbVertices);

  HRESULT ReserveBars (const unsigned int iNbBars);
  HRESULT ReserveTriangles (const unsigned int iNbTriangles);

  void Clear ();

protected:

  // Method extracting the bars from an array of triangles.  The arrays for bar related data must have 
  // been allocated with the method ReserveBars prior to a call to this method.
  HRESULT ExtractBars ();

protected:

  unsigned int _NbVertices;

  // Bar data.

  unsigned int _NbBars;                    // Number of bars.
  unsigned short* _BarVertices;            // Two vertices per bar.
  unsigned short* _BarTriangles;           // Two triangles per bar.

  // Triangle data.

  unsigned int _NbTriangles;               // Number of triangles.
  unsigned short* _TriangleVertices;       // Three vertices per triangle.
  unsigned short* _TriangleBars;           // Three bars per triangle.

};


inline unsigned int CATPolyRefinerTriangleMesh::GetNbVertices () const
{
  return _NbVertices;
}

inline unsigned int CATPolyRefinerTriangleMesh::GetNbBars () const
{
  return _NbBars;
}

inline unsigned int CATPolyRefinerTriangleMesh::GetNbTriangles () const
{
  return _NbTriangles;
}

inline void CATPolyRefinerTriangleMesh::GetBar (const unsigned int iBar,
                                               unsigned int oBarVertices[]) const
{
#ifdef CGMMESHREFINER_TURN_ON_BOUND_CHECK
  CATAssert (_BarVertices && 0 < iBar && iBar <= _NbBars);
#else
  CATAssert (_BarVertices);
#endif
  const unsigned int offset = 2 * (iBar-1);
  oBarVertices[0] = _BarVertices[offset];
  oBarVertices[1] = _BarVertices[offset + 1];
}

inline void CATPolyRefinerTriangleMesh::GetBarTriangles (const unsigned int iBar,
                                                        unsigned int oBarTriangles[]) const
{
#ifdef CGMMESHREFINER_TURN_ON_BOUND_CHECK
  CATAssert (_BarTriangles && 0 < iBar && iBar <= _NbBars);
#else
  CATAssert (_BarTriangles);
#endif
  const unsigned int offset = 2 * (iBar-1);
  oBarTriangles[0] = _BarTriangles[offset];
  oBarTriangles[1] = _BarTriangles[offset + 1];
}

inline void CATPolyRefinerTriangleMesh::GetTriangle (const unsigned int iTriangle,
                                                    unsigned int oTriangleVertices[]) const
{
#ifdef CGMMESHREFINER_TURN_ON_BOUND_CHECK
  CATAssert (_TriangleVertices && 0 < iTriangle && iTriangle <= _NbTriangles);
#else
  CATAssert (_TriangleVertices);
#endif
  const unsigned int offset = 3 * (iTriangle-1);
  oTriangleVertices[0] = _TriangleVertices[offset];
  oTriangleVertices[1] = _TriangleVertices[offset + 1];
  oTriangleVertices[2] = _TriangleVertices[offset + 2];
}

inline void CATPolyRefinerTriangleMesh::GetTriangleBars (const unsigned int iTriangle,
                                                        unsigned int oTriangleBars[]) const
{
#ifdef CGMMESHREFINER_TURN_ON_BOUND_CHECK
  CATAssert (_TriangleVertices && 0 < iTriangle && iTriangle <= _NbTriangles);
#else
  CATAssert (_TriangleVertices);
#endif
  const unsigned int offset = 3 * (iTriangle-1);
  oTriangleBars[0] = _TriangleBars[offset];
  oTriangleBars[1] = _TriangleBars[offset + 1];
  oTriangleBars[2] = _TriangleBars[offset + 2];
}

#endif
