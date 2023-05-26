//=============================================================================
// COPYRIGHT Dassault Systemes 2011
//=============================================================================
//
// CATPolyBodyVisuBuilder.h
//
//=============================================================================
// 2011-09-26 ZFI
// NewSG->XCZ (CATNATVisuExporter)
//=============================================================================
#ifndef CATPolyBodyVisuBuilder_H
#define CATPolyBodyVisuBuilder_H

#include "PolyVizUtils.h"
#include "CATErrorDef.h" 
#include "CATBoolean.h"
#include "CATListPV.h"
#include <vector>

class CATPolyBody;
class CATIPolyBodyFrameLayers;
class CATPolyCell;
class CATPolyFace;
class CATIPolyMesh;
class CATIPolySurfaceVertexPositionConstLayer;
class CATIPolySurfaceVertexNormalConstLayer;
class CATIPolySurfaceVertexTextureCoordConstLayer;
class CATIPolyLayerIterator;
class CATIPolyCurve;

class CATMapOfPtrToPtr;
class CAT3DRep;
class CATPolyBodyVisLayer;
class CATPolyBodyVisLayerSet;
class CATPolyBodyImportVizLayer;
class CATPolyBodyExportVizLayer;
class IVisSG3DPrimitive;
class IVisSGCustomPrimitive;
class VisRawBuffer;
class CATGraphicAttributeSet;
class CAT3DFaceGP;
class CAT4x4Matrix;


/**
This class exports a CATPolyBody and constructs a CATRep.
It exports the data to a VisPrimitiveGroupRep.
*/
class ExportedByPolyVizUtils CATPolyBodyVisuBuilder
{

public:

	CATPolyBodyVisuBuilder () ;
	virtual ~CATPolyBodyVisuBuilder ();

public:

  /**
   * Observer interface to use for mapping the cells to the cells from the input operands.
   */
  class ExportedByPolyVizUtils Observer 
  {

  public:

    virtual ~Observer () {}

  public:

    /**
     * Observer call made to map a CATPolyBody cell to a primitive key.
     * @param iPrimitiveKey
     *   A primitive key: see IVisSG3DPrimitiveIterator::IVisSGPrimitiveKey
     */
    virtual void Map (const CATPolyBody& iPolyBody, const CATPolyCell& iCell, CAT3DRep* rep, void* iPrimitiveKey) {}  

    /**
     * Observer call made to map a CATPolyBody cell to a graphic primitive.
     * @param iGP
     *   A graphic primitive.
     */
    virtual void Map (const CATPolyBody& iPolyBody, const CATPolyCell& iCell, CAT3DRep* rep, CAT3DFaceGP* iGP) {}  

  };

public:

  /**
   * Exports a CATPolyBody and constructs a CAT3DRep (CAT3DBagRep).  
   * @param iPolyBody
   *   The CATPolyBody to export.
   * @param iPositionMatrix
   *   An optional position matrix.
   * @param iTextureMatrix
   *   An optional texture matrix.
   * @param iVisLayer
   *   Visualization layer.
   * @param oRep
   *   The rep constructed by the method.
   * @param iWithVertices
   *   Enable vertices export (unused)
   * @param iWithEdges
   *   Enable edges export (1 : one edge per rep; 2 : all edges in one rep)
   */
  HRESULT Run (const CATPolyBody& iPolyBody, const CAT4x4Matrix* iPosition, const CAT4x4Matrix* iTextureMatrix, 
               const CATPolyBodyVisLayer* iVisLayer, CAT3DRep*& oRep, Observer* obs = 0, int iWithVertices = 0, int iWithEdges = 1);

  /**
   * Exports a CATPolyBody and constructs a CAT3DRep (CAT3DBagRep).  
   * An optional position matrix and optional visualization attributes can be specified.
   */
  HRESULT Run (const CATPolyBody& iPolyBody, const CAT4x4Matrix* iPosition, const CATPolyBodyVisLayer* iVisLayer, 
               CAT3DRep*& oRep);

  /**
   * Exports a set of CATPolyBody (from a CATPolyBodyVisLayerSet) into a CAT3DRep (CAT3DBagRep).
   */
  HRESULT Run (const CATPolyBodyVisLayerSet& iPolyBodies, CAT3DRep*& oRep);

public:

  //Export a list of PolyBody's +Positions to a CAT3DRep
  HRESULT Run(const CATListPV& iPolyBodies,
              const CATListPV& iPositionMatrices,
              CAT3DRep*& oRep,
              const CATPolyBodyImportVizLayer* iImportVizLayer = 0,
              CATPolyBodyExportVizLayer* ioExportVizLayer = 0,
              int iWithVertices=0, 
              int iWithEdges=1);
  
  //Export a CATPolyBody to a CAT3DRep  
  HRESULT Run (const CATPolyBody& iPolyBody,
               const CAT4x4Matrix* iPosition, 
               CAT3DRep*& oRep, 
               const CATPolyBodyImportVizLayer* iImportVizLayer = 0,
               CATPolyBodyExportVizLayer* ioExportVizLayer = 0,
               int iWithVertices = 0, 
               int iWithEdges=1);

  //Remove a CATPolyCell Visu in an exported CAT3DRep
  HRESULT RemoveCell(const CATPolyBody& iPolyBody, const CATPolyCell& iPolyCell, CAT3DRep& ioRep,
                     const CATPolyBodyImportVizLayer* iImportVizLayer=0,
                     CATPolyBodyExportVizLayer* ioExportVizLayer=0);

  //Update a CATPolyCell Visu in an exported CAT3DRep
  HRESULT UpdateCell (const CATPolyBody& iPolyBody, const CATPolyCell& iPolyCell, CAT3DRep& ioRep, 
                      const CATPolyBodyImportVizLayer* iImportVizLayer=0,
                      CATPolyBodyExportVizLayer* ioExportVizLayer=0);

public:

  /**
   * Exports a CATPolyBody into a CAT3DRep (case of multiple layers of the CATPolyBody.)
   * @param iVisLayer
   *   An optional input vis layer containing the graphic attributes associated to the cells of the CATPolyBody.
   * @param iRepPosition
   *   The position of the CAT3DRep after export of the CATPolyBody in the container rep (as in a CAT3DBagRep).
   * @param oRep
   *   The output rep (including position matrix.)
   * @param oVisPrimitiveLayer)
   *   An ouput vis layer mapping the primitives to the cell of the input CATPolyBody.
   */
  HRESULT RunMultiLayer (const CATPolyBody& iPolyBody,
                         const CATIPolyBodyFrameLayers& iFrameLayers,
                         unsigned int iFrame, 
                         const CATPolyBodyVisLayer* iVisLayer,
                         const CAT4x4Matrix* iRepPosition,
                         CAT3DRep*& oRep,
                         CATPolyBodyVisLayer& oVisPrimitiveLayer);

  /**
   * Updates the CAT3DRep with a frame of the CATPolyBody (case of multiple layers of the CATPolyBody.)
   * @param iVisLayer
   *   An optional input vis layer containing the graphic attributes associated to the cells of the CATPolyBody.
   * @param iVisPrimitiveLayer)
   *   An input vis layer mapping the primitives to the cell of the input CATPolyBody.
   * @param ioRep
   *   The rep to be updated with the frame data.
   */
  HRESULT UpdateFrame (const CATPolyBody& iPolyBody,
                       const CATIPolyBodyFrameLayers& iFrameLayers,
                       unsigned int iFrame,
                       const CATPolyBodyVisLayer* iVisLayer,
                       CATPolyBodyVisLayer& iVisPrimitiveLayer,
                       CAT3DRep& ioRep);

public:

  HRESULT ActivateExportAdOldSceneGraph(CATBoolean iActivate){_ExportAsOldSceneGraph=iActivate;return S_OK;}

private:

  HRESULT GetEdgeDescriptionFromCurve(CATIPolyCurve &iSurfaceLine, const CATGraphicAttributeSet& iGA,IVisSGCustomPrimitive*& oEdgePrimitive);

  HRESULT GetEdgeDescriptionFromCurves(std::vector<CATIPolyCurve *> &iSurfaceLineVec, const CATGraphicAttributeSet& iGA, IVisSGCustomPrimitive*& oEdgePrimitive);

  HRESULT CreatePrimitiveFromRawBuffers (const CATIPolyMesh& iMesh,
                                         CATIPolySurfaceVertexPositionConstLayer* posLayer,
                                         CATIPolySurfaceVertexNormalConstLayer* normalLayer,
                                         CATIPolyLayerIterator* layerIterator,
                                         VisRawBuffer& iVisVerticesBuffer, VisRawBuffer& iVisIndicesBuffer,
                                         IVisSG3DPrimitive*& pFacePrimitive, VisRawBuffer *iVisVertColorBuffer = 0);

  HRESULT CreateVerticesRawBuffersFromPolyFace (const CATIPolyMesh& iMesh,
                                                CATIPolySurfaceVertexPositionConstLayer* posLayer,
                                                CATIPolySurfaceVertexNormalConstLayer* normalLayer,
                                                CATIPolyLayerIterator* layerIterator,
                                                VisRawBuffer*& oVisVerticesBuffer);

  HRESULT CreateIndicesRawBuffersFromPolyFace (const CATPolyFace& iPolyFace, VisRawBuffer*& oVisIndicesBuffer);

  // Standard model.
  HRESULT GetFaceDescriptionFromPolyFace(const CATPolyFace& iPolyFace, const CATGraphicAttributeSet& iGA,IVisSG3DPrimitive*& pFacePrimitive);
  HRESULT GetFaceGPFromPolyFace(const CATPolyFace& iPolyFace, const CATGraphicAttributeSet& iGA,CAT3DFaceGP*& pFacePrimitive);
  HRESULT UpdateFaceDescriptionFromPolyFace(const CATPolyFace& iPolyFace, const CATGraphicAttributeSet& iGA, IVisSGCustomPrimitive& pFacePrimitive, int iUpdateIndice = 0);

  // Model with multiple frame layers.
  HRESULT GetFaceDescriptionFromPolyFace(const CATPolyFace& iPolyFace,const CATIPolyBodyFrameLayers& iFrameLayers,const unsigned int iFrame, const CATGraphicAttributeSet& iGA,IVisSG3DPrimitive*& pFacePrimitive);
  HRESULT GetFaceGPFromPolyFace(const CATPolyFace& iPolyFace,const CATIPolyBodyFrameLayers& iFrameLayers,const unsigned int iFrame, const CATGraphicAttributeSet& iGA,CAT3DFaceGP*& pFacePrimitive);
  HRESULT UpdateFaceDescriptionFromPolyFace(const CATPolyFace& iPolyFace, const CATIPolyBodyFrameLayers& iFrameLayers,const unsigned int iFrame,const CATGraphicAttributeSet& iGA,IVisSGCustomPrimitive& pFacePrimitive);

private:

  HRESULT RunPrivate (const CATPolyBody& iPolyBody,
                      const CATPolyBodyVisLayer* iVisLayer,  // If different from 0, then superceeds iImportVizLayer.
                      const CAT4x4Matrix* iPosition, 
                      const CAT4x4Matrix* iTextureMatrix,
                      CAT3DRep*& oRep, 
                      const CATPolyBodyImportVizLayer* iImportVizLayer = 0,
                      CATPolyBodyExportVizLayer* ioExportVizLayer = 0,
                      int iWithVertices = 0, 
                      int iWithEdges = 1,
                      Observer* obs = 0);

private:
  CATBoolean _ExportAsOldSceneGraph;

};


/**
 * Observer class for update of the CATPolyBodyExportVizLayer during export.
 */
class ExportedByPolyVizUtils CATPolyBodyExportVizLayerBuilderObserver : public CATPolyBodyVisuBuilder::Observer 
{

public:

  CATPolyBodyExportVizLayerBuilderObserver (CATPolyBodyExportVizLayer& exportVizLayer) : _ExportVizLayer (exportVizLayer) {}
  ~CATPolyBodyExportVizLayerBuilderObserver () {}

public:

  virtual void Map (const CATPolyBody& iPolyBody, const CATPolyCell& iCell, CAT3DRep* rep, void* iPrimitiveKey);

  virtual void Map (const CATPolyBody& iPolyBody, const CATPolyCell& iCell, CAT3DRep* rep, CAT3DFaceGP* iGP);

private:

  CATPolyBodyExportVizLayer& _ExportVizLayer;

};


#endif 
