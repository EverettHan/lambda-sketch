// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyBarGraphSurfaceLayers.h
//
//===================================================================
// October 2011  Creation NDO
//===================================================================
#ifndef CATPolyBodyBarGraphSurfaceLayers_H
#define CATPolyBodyBarGraphSurfaceLayers_H

#include "CATPolyBarGraph.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATPolyRefCounted.h"

#include "CATMapOfIntToInt.h"
#include "CATPolyBodyBarGraphDataVector.h"
#include <vector>

#include "CATIPolySurfaceVertexTextureCoordConstLayer.h"
#include "CATUnicodeString.h"

class CATPolyBodyBarGraph;
class CATPolyBodyBarGraphSurfaceDataLayer;
class CATPolyBodyBarGraphSurfaceIndexData;

/**
 * Layers associated to a CATPolyFace including:
 *   (1) Vertex normal layer (or layers one for each frame.)
 *   (2) Texture coordinates layer (or layers one for each frame.)
 *   (3) Map of nodes from the graph to a surface vertex to address its normal or its texture coordinates.
 */
class ExportedByPolyBarGraph CATPolyBodyBarGraphSurfaceLayers : public CATPolyRefCounted
{
public:
  class ExportedByPolyBarGraph LayerIdIterator
  {
  public:
    LayerIdIterator(const CATPolyBodyBarGraphSurfaceLayers& iSurfaceLayer, CATPolyBodyBarGraphDataVector::DataType iDataType, unsigned int iFrame);
    ~LayerIdIterator();

  public:
    void Begin();
    CATBoolean End() const;
    void operator++(int);
    unsigned int Get() const;

  private:
    const CATPolyBodyBarGraphDataVector::DataType _DataType;
    const std::vector<CATPolyBodyBarGraphDataVector*> *_DataLayers;
    unsigned int _CurrentId;
  };

public:

  CATPolyBodyBarGraphSurfaceLayers (CATPolyBodyBarGraph& iBodyGraph, const unsigned int iSuggestedSize);

protected:

  ~CATPolyBodyBarGraphSurfaceLayers ();

public:

  /**
   * Adds a new vertex normal/texture/other coordinates layer.
   * @param oNewLayer
   *   The layer index.
   * @param iStartPos
   *   The start position to search new layer position (depend on previous layer position).
   * @param iType
   *   The layer type.
   * @param iClassId
   *   The class type used to create PolyBody texture layer.
   * @param iDim
   *   The dimension of imported layer.
   * @param iIdentifier
   *   The layer identifier if any.
   * @param iConstraint
   *   The layer is processed as a constraint on position.
   * @param iFrame
   *   The index of the frame (ranging from 0 to GetNbFrames () - 1.)
   */
  HRESULT AddVertexDataCoordLayer (unsigned int &oNewLayer, unsigned int iStartPos, CATPolyBodyBarGraphDataVector::DataType iType, unsigned int iDim, const CLSID& iClassId, const CATUnicodeString& iIdentifier, CATBoolean iConstraint, unsigned int iFrame);

public:

  /**
   * Adds a surface vertex to the surface layers and returns its index.
   * @param oSurfaceVertex
   *   The returned index of the surface vertex.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> if the surface vertex is added successfully;
   *   <li> <tt>E_FAIL</tt> or another error code if an error occurs.
   * </ul>
   */
  HRESULT AddSurfaceVertex (unsigned int& oSurfaceVertex);

  /**
   * Removes a surface vertex from the surface layers.
   * @param iSurfaceVertex
   *   The input index of the surface vertex to remove.
   * @return
   *   <li> <tt>S_OK</tt> if the surface vertex is removed successfully;
   *   <li> <tt>E_FAIL</tt> or another error code if an error occurs.
   */
  HRESULT RemoveSurfaceVertex (const unsigned int iSurfaceVertex);

  /**
   * Associates a surface vertex to a node.
   */
  HRESULT SetSurfaceVertex (const unsigned int iNode, const unsigned int iSurfaceVertex);

  /**
   * Given a node returns its surface vertex.
   */
  HRESULT GetSurfaceVertex (const unsigned int iNode, unsigned int& oSurfaceVertex) const;

  /**
   *
   */
  HRESULT MoveNode(const unsigned int iSrcNode, const unsigned int iDstNode);

  /**
   * Given a node returns its surface node index. Used when normal cost is enabled.
   */
  HRESULT SetSurfaceNode(const unsigned int iNode, const unsigned int iSurfaceNode);

  /**
   * Given a node returns its surface node.
   */
  HRESULT GetSurfaceNode(const unsigned int iNode, unsigned int& oSurfaceNode) const;

  /**
 * Returns TRUE if cuts are enabled for this layer.
 * @param iLayer
 *   The index of the layer.
 * @param iFrame
 *   The index of the frame (ranging from 0 to GetNbFrames () - 1.)
 */
  CATBoolean IsCutLayer(unsigned int iLayer, unsigned int iFrame) const;

public:

  CATPolyBodyBarGraphDataVector* GetVertexDataLayer(const unsigned int iLayer, const unsigned int iFrame);
  const CATPolyBodyBarGraphDataVector* GetVertexDataLayer(const unsigned int iLayer, const unsigned int iFrame) const;

  HRESULT GetNewCutSurfaceVertex(unsigned int& oCutSV, unsigned int iLayer, unsigned int iFrame);
  HRESULT SetCutSurfaceVertex(unsigned int iBar, unsigned int iNode, unsigned int iCutSV, unsigned int iLayer, unsigned int iFrame, CATBoolean iIgnoreSurfaceVertex = FALSE);
  HRESULT GetCutSurfaceVertex(unsigned int iBar, unsigned int iNode, unsigned int &oCutSV, unsigned int iLayer, unsigned int iFrame) const;
  HRESULT GetCutSurfaceVertices(unsigned int iBar, unsigned int iNode, std::vector<unsigned int>& oCutSVs, unsigned int iFrame) const;
  HRESULT RemoveBarCutSurfaceVertex0(unsigned int iBar, unsigned int iLayer, unsigned int iFrame);
  HRESULT RemoveBarCutSurfaceVertex1(unsigned int iBar, unsigned int iLayer, unsigned int iFrame);

  HRESULT BuildDuplicateData(const CATSetOfInt& iNodes);
  unsigned int GetNbDuplicates(unsigned int iFrame) const;
  unsigned int GetDuplicateIndex(unsigned int iNode, const std::vector<unsigned int> & iCutSVs, unsigned int iFrame) const;
  unsigned int GetDuplicateNode(unsigned int iIndex, unsigned int iFrame) const;
  unsigned int GetDuplicateCutSurfaceVertex(unsigned int iIndex, unsigned int iLayer, unsigned int iFrame) const;
  HRESULT GetCCWTriangleDuplicates(unsigned int(&ioTriNodes)[3], unsigned int f, unsigned int iFrame) const;
  HRESULT GetCCWTriangleCutSurfaceVertices(std::vector<unsigned int>(&oTriCutSV)[3], const unsigned int(&iTriNodes)[3], unsigned int f, unsigned int iFrame) const;

private:

  CATPolyBodyBarGraph& _BodyGraph;

  CATPolyBodyBarGraphSurfaceIndexData *_SurfaceIndexData;
  std::vector<CATPolyBodyBarGraphSurfaceDataLayer*> _FrameDataLayers;

  unsigned int _LayerSize;                     // Size of the layers (normals, texture coordinates).

private:

  HRESULT IncreaseSize ();

  // Forbidden.
  CATPolyBodyBarGraphSurfaceLayers (const CATPolyBodyBarGraphSurfaceLayers& iOther);
  CATPolyBodyBarGraphSurfaceLayers& operator= (const CATPolyBodyBarGraphSurfaceLayers& iOther);

};

#endif
