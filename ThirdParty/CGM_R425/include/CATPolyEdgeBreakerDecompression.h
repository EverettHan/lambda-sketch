// Creation: November 2021 - TCT5

#ifndef _AIX_SOURCE

#ifndef CATPolyEdgeBreakerDecompression_h
#define CATPolyEdgeBreakerDecompression_h

#include "PolyEdgeBreaker.h"

#include "CATSysErrorDef.h"

#include <unordered_map>
#include <unordered_set>

class CATPolyEdgeBreakerCornerTable;
class CATPolyEdgeBreakerStreamable;

class CATIPolyEdgeBreaker3DEditableLayer
{
public:
  CATIPolyEdgeBreaker3DEditableLayer() {}
  virtual ~CATIPolyEdgeBreaker3DEditableLayer() {}

public:
  virtual HRESULT Get(int iVertex, double& oX, double& oY, double& oZ, bool castOutputToFloat = false) const = 0;
  virtual HRESULT Set(int iVertex, double iX, double iY, double iZ, bool castInputToFloat = false) = 0;

  virtual unsigned int GetPrecision() const = 0;
};

class ExportedByPolyEdgeBreaker CATPolyEdgeBreakerDecompression
{
public:
  CATPolyEdgeBreakerDecompression(const CATPolyEdgeBreakerStreamable& iStreamable);
  virtual ~CATPolyEdgeBreakerDecompression();

public:
  HRESULT Run(CATPolyEdgeBreakerCornerTable *&opCornerTable);

  HRESULT UncompressLayers();

public:
  int GetLastAddedVertex() const;

public:
  void SetPositionLayer(CATIPolyEdgeBreaker3DEditableLayer *ipLayer);
  void SetNormalLayer(CATIPolyEdgeBreaker3DEditableLayer *ipLayer);

protected:
  HRESULT Uncompress();
  
  HRESULT Stitch(int iCorner);

  HRESULT AssignUnsetVertices(int iStartTriangle, int iEndTriangle);
  HRESULT AssignBoundaryVertices(int iStartTriangle, int iEndTriangle);
  HRESULT PropagateVertexAroundAdjacentCorners(int iCorner);

  HRESULT ProcessHandle(int iCorner); 
  HRESULT ProcessHandlesBothSides(int iCorner0, int iCorner1);

  enum class QuantizationMethod
  {
    None,
    Delta,
    Lineic,
    Parallelogram
  };

  HRESULT UncompressPositions();
  HRESULT UncompressPosition(int iVertex, QuantizationMethod iMethod, int iDataForPrediction[2], std::unordered_set<int>& ioVisitedNonManifoldVertices, int &ioNbDecodedVertices, int &ioNbVerticesSet);
  HRESULT UncompressNormals();
  HRESULT GetParallelogram(int iCorner0, int iCorner1, int iCorner2, double &oX, double &oY, double &oZ) const;

protected:
  const CATPolyEdgeBreakerStreamable &m_Streamable;
  
  CATPolyEdgeBreakerCornerTable *m_pCornerTable;
  
  std::unordered_map<int, int> m_HandleCornerPairs;
  int m_LastAddedVertex;
  unsigned int m_NbAddedTriangle;
  unsigned int m_NbOfBoundaryVerticesSet;

  CATIPolyEdgeBreaker3DEditableLayer *m_pPositionLayer;
  CATIPolyEdgeBreaker3DEditableLayer *m_pNormalLayer;

  std::unordered_map<int, std::tuple<unsigned int, float, float, float>> m_PredictedPositions;
};

#endif

#endif // AIX
