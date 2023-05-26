#ifndef CATPolyMeshKRingOpe_h__
#define CATPolyMeshKRingOpe_h__

//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2020, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshKRingOpe.h : retrieve the k-ring (the vertices that can be reach through at most k edges) of each vertex of a CATIPolyMesh
//
//===================================================================
// January 2020 :  Creation NUA
//===================================================================

// export
#include "ExportedByCATPolyFeatureLineOperator.h"

#include "CATSysErrorDef.h"

// STL
#include <cstddef>
#include <set>
#include <map>

#ifdef _WINDOWS_SOURCE
#include <ppl.h>
#include <concurrent_unordered_map.h>
#endif

class CATIPolyMesh;
class CATIPolySurfaceVertexFacetNeighborhood;

class ExportedByCATPolyFeatureLineOperator CATPolyMeshKRingOpe
{
public:
  CATPolyMeshKRingOpe(const CATIPolyMesh & iMesh, size_t RingSize);
  ~CATPolyMeshKRingOpe();

  HRESULT Run();

  typedef std::set<int> SetOfVertices_t;
  const SetOfVertices_t & GetVertexRing(int NumV) const;

private:

  size_t m_RingSize;
#ifdef _WINDOWS_SOURCE
  Concurrency::concurrent_unordered_map<int, SetOfVertices_t> m_K_RingVertices;
#else 
  std::map<int, SetOfVertices_t> m_K_RingVertices;
#endif
  std::map<int, SetOfVertices_t> m_1_RingVertices;

  const CATIPolyMesh & m_Mesh;
  CATIPolySurfaceVertexFacetNeighborhood * m_VoisinOpe;
};

#endif // CATPolyMeshKRingOpe_h__
