// Creation: November 2021 - TCT5

#ifndef _AIX_SOURCE

#ifndef CATPolyEdgeBreakerCornerTable_h
#define CATPolyEdgeBreakerCornerTable_h

#include "PolyEdgeBreaker.h"

#include "CATPolyEdgeBreakerOptimizedVertexCollections.h"

#include "CATSysErrorDef.h"

#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <utility>

class CATPolyEdgeBreakerStreamable;

class ExportedByPolyEdgeBreaker CATPolyEdgeBreakerCornerTable
{
public:
  CATPolyEdgeBreakerCornerTable(unsigned int iNbTriangles, bool iMapInputIdx = false);
  virtual ~CATPolyEdgeBreakerCornerTable();

public:
  bool IsClosed() const;
  bool VertexIsReferencedByTriangle(int iTriangle, int iVertex) const;
  bool IsVertexNonManifold(int iVertex, int& oRefVertex) const;

public:
  void SwapCW(int iTriangle);
  void SwapCCW(int iTriangle);
  void SwapTriangles(int iTriangle1, int iTriangle2);

public:
  void ReplaceVertexIndicesWithStreamedVertexIndices(const std::vector<int> &iMapOfStreamedVertexIndicesToInputIndices);

public: // For debug only
  bool AreEqual(const CATPolyEdgeBreakerCornerTable &iOther) const;

// Filling Methods
public:
  inline void SetVertex(int iCorner, int iVertex)
  {
    m_V[iCorner] = iVertex;
  }

  inline void SetOpposite(int iCorner, int iOppositeCorner)
  {
    m_O[iCorner] = iOppositeCorner;
  }

  inline void SetTriangleInputIndex(int iTriangle, int iInputIndex)
  {
    if (iTriangle < m_InputTriangleIndices.size())
      m_InputTriangleIndices[iTriangle] = iInputIndex;
  }

// Topology Methods 
public:
  HRESULT GetLoops(unsigned int iNbOfBoundaryVertices, std::vector<std::vector<int>> &oLoops);
  HRESULT FindAndSplitNonManifoldVertices();
  HRESULT BuildMapOfCornerTableVerticesToMergedVertices(unsigned int iNbVertices);
  HRESULT BuildVerticesWithSharedPositionsClusters(const CATPolyEdgeBreakerStreamable &iStreamable);
  HRESULT BuildSplitVerticesClusters(const CATPolyEdgeBreakerStreamable& iStreamable);

  // For vertex maps/sets optimization
public:
  void CheckIfInputVerticesHaveCompactRange();

  void MakeOptimizedVertexSet(CATPolyEdgeBreakerOptimizedVertexSet& oVertexSet) const
  {
    if (m_InputVerticesHaveCompactRange)
      oVertexSet = CATPolyEdgeBreakerOptimizedVertexSet(0, m_MaxInputVertexIndex);
    else
      oVertexSet = CATPolyEdgeBreakerOptimizedVertexSet(1, m_MaxInputVertexIndex);
  }

  template <typename T>
  void MakeOptimizedVertexMap(CATPolyEdgeBreakerOptimizedVertexMap<T>& oVertexMap) const
  {
    if (m_InputVerticesHaveCompactRange)
      oVertexMap = CATPolyEdgeBreakerOptimizedVertexMap<T>(0, m_MaxInputVertexIndex);
    else
      oVertexMap = CATPolyEdgeBreakerOptimizedVertexMap<T>(1, m_MaxInputVertexIndex);
  }

// Getters
public:
  inline unsigned int GetNbTriangles() const
  {
    return m_NbTriangles;
  }

  inline unsigned int GetTriangle(int iCorner) const
  {
    return iCorner / 3;
  }

  inline int GetOpposite(int iCorner) const
  {
    return m_O[iCorner];
  }

  inline int GetVertex(int iCorner) const
  {
    return m_V[iCorner];
  }

  int GetMergedVertex(int iVertex) const;
  unsigned int CountNbOfExtraVerticesInducedBySplit() const;

  inline int GetNextCorner(int iCorner) const
  {
    return (iCorner / 3) * 3 + ((iCorner + 1) % 3);
  }

  inline int GetPrevCorner(int iCorner) const
  {
    return GetNextCorner(GetNextCorner(iCorner));
  }

  inline int GetCCWCorner(int iCorner) const
  {
    return GetOpposite(GetPrevCorner(iCorner));
  }

  inline int GetCWCorner(int iCorner) const
  {
    return GetOpposite(GetNextCorner(iCorner));
  }

  inline int GetRightTriangle(int iCorner) const
  {
    return GetTriangle(GetCWCorner(iCorner));
  }

  inline int GetLeftTriangle(int iCorner) const
  {
    return GetTriangle(GetCCWCorner(iCorner));
  }

  inline std::vector<int>&& StealMapOfInputTriangleIndices()
  {
    return std::move(m_InputTriangleIndices);
  }

  inline std::vector<unsigned char>&& StealMapOfTriangleRotations()
  {
    return std::move(m_TriangleRotations);
  }

  inline std::vector<unsigned int>& GetNbOfTrianglesPerFaceGPIdx()
  {
    return m_NbOfTrianglesPerFaceGPIdx;
  }

  inline std::unordered_map<int, int>& GetClustersOfVerticesWithSamePosition()
  {
    return m_ClustersOfVerticesWithSamePosition;
  }

  inline const std::unordered_map<int, int>& GetClustersOfVerticesWithSamePosition() const
  {
    return m_ClustersOfVerticesWithSamePosition;
  }

  inline void SetClustersOfVerticesWithSamePosition(std::unordered_map<int, int>& iClusters)
  {
    m_ClustersOfVerticesWithSamePosition = iClusters;
  }

  inline std::unordered_map<int, int>& GetClustersOfSplitVertices()
  {
    return m_ClustersOfSplitVertices;
  }

  inline const std::unordered_map<int, int>& GetClustersOfSplitVertices() const
  {
    return m_ClustersOfSplitVertices;
  }

  inline void SetClustersOfSplitVertices(std::unordered_map<int, int>& iClusters)
  {
    m_ClustersOfSplitVertices = iClusters;
  }

// CGR-specific
public:
  inline void NewFaceGP(unsigned int iNbTriangles)
  {
    m_NbOfTrianglesPerFaceGPIdx.push_back(iNbTriangles);
  }

protected:
  unsigned int m_NbTriangles;

  std::vector<int> m_O;
  std::vector<int> m_V;
  
  std::vector<int> m_MapOfCornerTableVerticesToMergedVertices;
  std::unordered_map<int, int> m_ClustersOfVerticesWithSamePosition;
  std::unordered_map<int, int> m_ClustersOfSplitVertices;

  std::vector<int> m_InputTriangleIndices; // Optional
  std::vector<unsigned char> m_TriangleRotations; // Optional
  std::vector<unsigned int> m_NbOfTrianglesPerFaceGPIdx; // Optional, only used for CGR streaming

  // For vertex maps/sets optimization
  bool m_InputVerticesHaveCompactRange;
  int m_MaxInputVertexIndex;
};

#endif

#endif // AIX
