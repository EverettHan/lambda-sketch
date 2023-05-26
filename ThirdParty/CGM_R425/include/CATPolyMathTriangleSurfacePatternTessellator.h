// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMathTriangleSurfacePatternTessellator.h
//
//===================================================================
//
// February 2009  Creation: ndo
//===================================================================
#ifndef CATPolyMathTriangleSurfacePatternTessellator_h
#define CATPolyMathTriangleSurfacePatternTessellator_h

#include "PolyVizRefiners.h"
#include "CATErrorDef.h"  // HRESULT definition.
#include "CATIAV5Level.h"

class CATPolyMathTriangleSurface;
class CATPolyRefinerUVWTriangleMesh;
class CATPolyRefinerPatternMeshBuilder;

class ExportedByPolyVizRefiners CATPolyMathTriangleSurfacePatternTessellator 
{

public:

  CATPolyMathTriangleSurfacePatternTessellator () {}
  ~CATPolyMathTriangleSurfacePatternTessellator () {}

public:

  // Tessellate a triangle surface non-uniformly to achieve (ideally) a deviation below the input sag.
  // A parameter specifies the maximum level of a uniform tessellation not to be exceeded; the 
  // non-uniform tessellation will not have a number of vertices and triangles greater than a uniform
  // tessellation at this level.
  // @param iPatch
  //   The triangle surface to tessellate.
  // @param iSag
  //    The maximum sag of the tessellated object.
  // @param iLevelMax
  //    The maximum level of a uniform tessellation not to exceed (in vertex and triangle counts).
  // @param iSideLevels
  //    Optional parameter. The levels of refinement along the three sides of the triangle.
  //    If this parameter is not set (or negative), the levels are computed.
  // @param oMesh
  //   The output mesh.  The method allocates the object.
  //   The caller must delete the object.
  // @param iComputeNormal
  //   Compute the normals on the output mesh.
  // @return 
  //   E_FAIL on failure and S_OK on success.
  static HRESULT Tessellate (const CATPolyMathTriangleSurface& iPatch,
                             const double iSag, unsigned int iLevelMax, const int* iSideLevels,
                             CATPolyRefinerUVWTriangleMesh*& oMesh, const unsigned int iComputeNormal = 1);

#ifdef CATIAR213
  // Same as Tessellate but uses UV2 tessellation
  static HRESULT Tessellate2 (const CATPolyMathTriangleSurface& iPatch,
                              const double iSag, unsigned int iLevelMax, int* iSideLevels,
                              CATPolyRefinerUVWTriangleMesh*& oMesh, const unsigned int iComputeNormal = 1);
#endif

  // Tessellate a triangle surface as a planar surface. In this mode, only the sides of the triangle surface
  // are discretized for the tessellation.  The arguments of the command are the same as above.
  static HRESULT TessellateAsPlane (const CATPolyMathTriangleSurface& iPatch,
                                    const double iSag, const unsigned int iLevelMax, const int* iSideLevels,
                                    CATPolyRefinerUVWTriangleMesh*& oMesh);

public:

  // Compute the positions of the vertices of a triangle mesh for a patch.
  static HRESULT ComputePoints (const CATPolyMathTriangleSurface& iPatch,
                                CATPolyRefinerUVWTriangleMesh& iMesh);

  // Compute the positions and the normals of the vertices of a triangle mesh for a patch.
  static HRESULT ComputePointsAndNormals (const CATPolyMathTriangleSurface& iPatch,
                                          CATPolyRefinerUVWTriangleMesh& iMesh);

public:

  static HRESULT Optimize (const CATPolyMathTriangleSurface& iPatch, CATPolyRefinerUVWTriangleMesh& iMesh);
  static const CATPolyRefinerPatternMeshBuilder& GetPatternMeshBuilder ();

};

#endif
