// COPYRIGHT DASSAULT SYSTEMES 2007-2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyUVTessellatorTools.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// June 2007  Creation: ndo
//===================================================================
#ifndef CATPolyUVTessellatorTools_H
#define CATPolyUVTessellatorTools_H

#include "PolyVizRefiners.h"


/*
Tools computing the parameters of a tessellated PNT triangle after uniform tessellation.
Tools computing the parameters of a refined polymesh.
*/
class ExportedByPolyVizRefiners CATPolyUVTessellatorTools
{

public:

  CATPolyUVTessellatorTools () {}

  ~CATPolyUVTessellatorTools () {}

public:

  // Compute the step size given a level for uniform refinement.
  static inline double GetStepSize (const unsigned int level);

  // Number of vertices in the case of a uniform grid.
  static inline unsigned int ComputeNbVerticesOfUniformGrid (const unsigned int level);

  // Number of bars in the case of a uniform grid.
  static inline unsigned int ComputeNbBarsOfUniformGrid (const unsigned int level);

  // Number of triangles in the case of a uniform grid.
  static inline unsigned int ComputeNbTrianglesOfUniformGrid (const unsigned int level);

public:

  // Given the number of vertices, bars and triangles of Mesh 0, and a level of uniform refinement,
  // compute the number of vertices of the refined mesh.
  static inline unsigned int ComputeNbVerticesOfMeshRefinedUniformly (const unsigned int iNbVertices,
                                                                      const unsigned int iNbBars,
                                                                      const unsigned int iNbTriangles,
                                                                      const unsigned int level);

  // Given the number of bars and triangles of Mesh 0, and a level of uniform refinement,
  // compute the number of bars of the refined mesh.
  static inline unsigned int ComputeNbBarsOfMeshRefinedUniformly (const unsigned int iNbBars,
                                                                 const unsigned int iNbTriangles,
                                                                 const unsigned int level);

  // Given the number of triangles of Mesh 0, and a level of uniform refinement,
  // compute the number of triangles of the refined mesh.
  static inline unsigned int ComputeNbTrianglesOfMeshRefinedUniformly (const unsigned int iNbTriangles,
                                                                       const unsigned int level);

public:

  // Decoder.
  // Given the (u, v, w) integer coordinates of a vertex (all ranging from 0 to (Level+1) with:
  // u + v + w = Level + 1) and the level of refinement, compute the vertex number.
  // Vertex are numbers from 1 to (Level+2)*(Level+3) / 2 included.
  static unsigned int DecodeVertexFromUVW (const unsigned int u, const unsigned int v, const unsigned int w);

};


inline double CATPolyUVTessellatorTools::GetStepSize (const unsigned int level)
{
  return 1 / double (level + 1);
}

inline unsigned int CATPolyUVTessellatorTools::ComputeNbVerticesOfUniformGrid (const unsigned int level)
{
  return (level + 2) * (level + 3) / 2;
}

inline unsigned int CATPolyUVTessellatorTools::ComputeNbBarsOfUniformGrid (const unsigned int level)
{
  return 3 * (level + 1) * (level + 2) / 2;
}

inline unsigned int CATPolyUVTessellatorTools::ComputeNbTrianglesOfUniformGrid (const unsigned int level)
{
  return (level + 1) * (level + 1);
}

inline unsigned int CATPolyUVTessellatorTools::ComputeNbVerticesOfMeshRefinedUniformly (const unsigned int iNbVertices,
                                                                                        const unsigned int iNbBars,
                                                                                        const unsigned int iNbTriangles,
                                                                                        const unsigned int level)
{
  const unsigned int nbVerticesPerBar = level;  // Inner vertices only!
  const unsigned int nbVerticesPerTriangle = (level * (level - 1)) / 2; // Inner vertices only!
  return iNbVertices + nbVerticesPerBar * iNbBars + nbVerticesPerTriangle * iNbTriangles;
}

inline unsigned int CATPolyUVTessellatorTools::ComputeNbBarsOfMeshRefinedUniformly (const unsigned int iNbBars,
                                                                                    const unsigned int iNbTriangles,
                                                                                    const unsigned int level)
{
  const unsigned int nbBarsPerBar = level + 1;
  const unsigned int nbBarsPerTriangle = ComputeNbBarsOfUniformGrid (level) - 3 * nbBarsPerBar; // Inner bars only!
  return nbBarsPerBar * iNbBars + nbBarsPerTriangle * iNbTriangles;
}

inline unsigned int CATPolyUVTessellatorTools::ComputeNbTrianglesOfMeshRefinedUniformly (const unsigned int iNbTriangles,
                                                                                      const unsigned int level)
{
  const unsigned int nbTrianglesPerTriangle = ComputeNbTrianglesOfUniformGrid (level);
  return nbTrianglesPerTriangle * iNbTriangles;
}

#endif
