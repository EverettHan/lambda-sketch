// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshRemesherOpe.h
//
//===================================================================
// December 2017  Creation NUA
//===================================================================
#ifndef CATPolyMeshRemesherOpe_H
#define CATPolyMeshRemesherOpe_H
 
 
#include "CATPolySmoothingOperators.h"
#include "CATListOfInt.h"

// Error handling
#include "CATSysErrorDef.h"

#include "CATTolerance.h"

#include <utility>
#include <algorithm>
#include <vector>
#include <set>

class CATIPolyMesh;
class CATIPolySurfaceVertexFacetNeighborhood;
class CATIPolyMeshTriangleIterator;
class CATIPolySurfaceVertexIterator;

class CATPolyPointMeshDistance;
class CATPolyPointMeshDistanceAccelerator;

// d'apres A Remeshing Approach to Multiresolution Modeling, Mario Botsch Leif Kobbelt

class ExportedByCATPolySmoothingOperators CATPolyMeshRemesherOpe
{
public:
  CATPolyMeshRemesherOpe(CATIPolyMesh & iMesh, double L, CATTolerance *iTolObject = NULL);

  ~CATPolyMeshRemesherOpe();

  HRESULT Run(size_t NbIter);

  void FreezeMeshBoundary()
  {
    m_FreezeBoundary = true;
  }

  void AddEdgeToFreeze(const int iV1, const int iV2)
  {
    m_FrozenEdges.insert(Edge_t(iV1, iV2));
    m_FrozenVertices.insert(iV1);
    m_FrozenVertices.insert(iV2);
  }
  void AddVertexToFreeze(const int iV)
  {
    m_FrozenVertices.insert(iV);    
  }

  void EnableReprojectionOnOriginalMesh()
  {
    m_NeedReprojectionOnOriginalMesh = true;
  }

private:

  CATListOfInt GetTrianglesAroundbar(const int iNumV1, const int iNumV2, CATIPolySurfaceVertexFacetNeighborhood * VoisinOpe) const;

  HRESULT RemoveUnreferencedVertices();
  
  HRESULT SplitLongEdge();
  HRESULT CollapseShortEdges();
  HRESULT FlipEdges(size_t & NbFlips);
  HRESULT RelocateVertices();
  HRESULT ReprojectOnMesh();

  double m_L;
  CATIPolyMesh & m_Mesh;
  bool m_FreezeBoundary;
  bool m_NeedReprojectionOnOriginalMesh;

  CATIPolyMeshTriangleIterator * m_TriangleIterOriginal;
  
  struct Edge_t
  {
    int m_I1, m_I2;
    Edge_t(int i1, int i2) : m_I1(i1), m_I2(i2) { if (m_I1 > m_I2) std::swap(m_I1, m_I2); }
    Edge_t() : m_I2(0), m_I1(0) {}
    bool operator< (const Edge_t & iOther) const
    {
      if (m_I1 < iOther.m_I1) return true;
      if (m_I1 > iOther.m_I1) return false;
      return m_I2 < iOther.m_I2;
    }
  };
  std::set<Edge_t> m_FrozenEdges;
  std::set<int> m_FrozenVertices;

  // mesh original pour la reprojection
  // WARNING : copie profonde
  CATIPolyMesh * m_OriginalMesh;

  CATPolyPointMeshDistance * m_ProjOpe;
  CATPolyPointMeshDistanceAccelerator * m_ProjOpeAccelerator;

  CATTolerance * m_TolObject;
}; 

#endif
