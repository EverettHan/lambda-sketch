// Creation: November 2021 - TCT5

#ifndef _AIX_SOURCE

#ifndef CATPolyEdgeBreakerCompression_h
#define CATPolyEdgeBreakerCompression_h

#include "PolyEdgeBreaker.h"

#include "CATPolyEdgeBreakerCornerTable.h"

#include "CATSysErrorDef.h"

#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <tuple>

class CATPolyEdgeBreakerStreamable;

class CATIPolyEdgeBreaker3DConstLayer
{
public:
  CATIPolyEdgeBreaker3DConstLayer() {}
  virtual ~CATIPolyEdgeBreaker3DConstLayer() {}

public:
  virtual void SetMapOfStreamedVertexIndicesToMeshIndices(const std::vector<int>*) = 0;

public:
  virtual HRESULT Get(int iVertex, double& oX, double& oY, double& oZ, bool castOutputToFloat = false) const = 0;
  virtual unsigned int GetPrecision() const = 0;
};

class ExportedByPolyEdgeBreaker CATPolyEdgeBreakerCompression
{
public:
  CATPolyEdgeBreakerCompression(CATPolyEdgeBreakerCornerTable &iCornerTable);
  virtual ~CATPolyEdgeBreakerCompression();

public:
  HRESULT Run(CATPolyEdgeBreakerStreamable &ioStreamable);

public:
  void SetPositionLayer(CATIPolyEdgeBreaker3DConstLayer *ipLayer);
  void SetNormalLayer(CATIPolyEdgeBreaker3DConstLayer *ipLayer);

protected:
  HRESULT Compress();

  HRESULT VisitBoundaryVertices();
  int FindSuitableStartTriangle();

  enum class QuantizationMethod
  {
    None,
    Delta,
    Lineic,
    Parallelogram
  };

  HRESULT Quantize();
  HRESULT QuantizePositions();
  HRESULT QuantizePosition(int iVertex, QuantizationMethod iMethod, int iDataForPrediction[2], std::unordered_set<int>& ioVisitedNonManifoldVertices);
  HRESULT QuantizeNormals();
  HRESULT GetParallelogram(int v0, int v1, int v2, double &oX, double &oY, double &oZ) const;

  HRESULT ComputeClustersOfVerticesWithSamePosition(const std::vector<std::vector<int>> &iLoops);
  bool HandleVerticesWithSharedPositions(int iStreamedVertexIdx, int &oRefStreamedVertexIdx);
  
  HRESULT FillSplitVertexClusters();
  HRESULT MergeSplitVerticesInIndexMap();

  HRESULT CheckAndEditOptionsAccordingToVersion();

protected:
  CATPolyEdgeBreakerCornerTable &m_CornerTable;
  CATPolyEdgeBreakerStreamable *m_pStreamable;

  unsigned int m_NbOfVisitedTriangles;
  CATPolyEdgeBreakerOptimizedVertexSet m_VisitedVertices;

  unsigned int m_NbOfVisitedBoundaryVertices;
  std::unordered_set<int> m_BoundaryVerticesToSet;

  CATIPolyEdgeBreaker3DConstLayer *m_pPositionLayer;
  CATIPolyEdgeBreaker3DConstLayer *m_pNormalLayer;

  std::vector<float> m_EncodedPositions;
  std::unordered_map<int, std::tuple<unsigned int, float, float, float>> m_PredictedPositions;
};

#endif

#endif // AIX
