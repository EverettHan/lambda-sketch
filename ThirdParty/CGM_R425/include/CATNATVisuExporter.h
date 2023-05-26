//=============================================================================
// COPYRIGHT Dassault Systemes 2010
//=============================================================================
//
// CATNATVisuExporter.h
//
//=============================================================================
// 2010-09-05   XCZ: New.
//=============================================================================
#ifndef CATNATVisuExporter_H
#define CATNATVisuExporter_H

// ExportedBy
#include "PolyVizObject.h"

// System
#include "CATBoolean.h"
#include "CATErrorDef.h" // HRESULT.
#include "CATListPV.h"

class CATIPolyCurve;
class CATIPolySurfaceVertexLine;
class CAT3DLineGP;
class CAT3DEdgeGP;
class CAT3DBoundingGP;
class CATViz3DLine;
class CATViz3DEdge;
class IVisSG3DPrimitive;
class IVisSGCustomPrimitive;
class CAT3DRep;
class CATPolySurfaceCompactVertexIndexMapper;
class CATGraphicAttributeSet;
class CATIPolyMesh;
class CATPolyBody;
class CAT4x4Matrix;
class VisRawBuffer;
class CATPolyBodyImportVizLayer;
class CATPolyBodyExportVizLayer;
class CATBVHNodeConst;
class IVisSG3DNodeGroup;
class CATPolyBodyObject;

//
class ExportedByPolyVizObject CATNATVisuExporter
{
public:
  CATNATVisuExporter();
  ~CATNATVisuExporter();

public:

  // Rep
  static HRESULT RemovePrimitiveNewSG(CAT3DRep *&oRep, void * iPrimitiveKey);
  static HRESULT UpdateNewSG (CAT3DRep *&oRep, void * iPrimitiveKey,CATIPolyMesh &iMesh,const CATGraphicAttributeSet& iGA);

  static HRESULT ExportNewSG (const CATPolyBody& iPolyBody,
    const CAT4x4Matrix& iPosition,
    CAT3DRep *&oRep,
    int iUseHierarchy = 0,
    CATPolyBodyObject *iPB = NULL,
    const CATPolyBodyImportVizLayer* iImportVizLayer = 0,
    CATPolyBodyExportVizLayer* ioExportVizLayer = 0,
    int iWithVertices = 0, 
    int iWithEdges=1);

  static void RecursiveBuildRep(const CATPolyBody& iPolyBody,CATBVHNodeConst *pTreeNode,IVisSG3DNodeGroup *pNodeGroup,const CATPolyBodyImportVizLayer* iImportVizLayer,
                                            CATPolyBodyExportVizLayer* ioExportVizLayer,CATPolyBodyObject *iPB = NULL);

  static HRESULT ExportNewSG (const CATListPV& iPolyBodies,
    const CATListPV& iPositionMatrices,
    CAT3DRep*& oRep);

  // Mesh
  static HRESULT GetFaceDescriptionFromPolyMesh(const CATIPolyMesh& iMesh,const CATGraphicAttributeSet& iGA,IVisSG3DPrimitive *&pFacePrimitive);
  static HRESULT CreateVerticesRawBuffersFromPolyMesh(const CATIPolyMesh& iMesh,const CATGraphicAttributeSet& iGA,VisRawBuffer *&oVisVerticesBuffer,int bSetColors = 1,int bSetTexCoord = 1,int inbLevels = 0);
  static HRESULT CreateIndicesRawBuffersFromPolyMesh(const CATIPolyMesh& iMesh,const CATGraphicAttributeSet& iGA,VisRawBuffer *&oVisIndicesBuffer);
  static HRESULT CreatePrimitiveFromRawBuffers(const CATIPolyMesh& iMesh,VisRawBuffer &iVisVerticesBuffer,VisRawBuffer &iVisIndicesBuffer,IVisSG3DPrimitive *&pFacePrimitive,VisRawBuffer *iVisVertColorBuffer = NULL,int bSetTexCoord = 1,int bUseTexCoordForGeomorphing = 0);

  // Line
  static HRESULT GetEdgeDescriptionFromCurve(CATIPolyCurve &iSurfaceLine,const CATGraphicAttributeSet& iGA, IVisSGCustomPrimitive *& OEdgePrimitive);

  // V5
  static HRESULT ExportTerrainMesh(const CATIPolyMesh& iMesh,CAT3DRep*& oRep);
private:
  static HRESULT UpdateFaceDescriptionFromPolyMesh(const CATIPolyMesh &iMesh,const CATGraphicAttributeSet& iGA,IVisSGCustomPrimitive *&pFacePrimitive,int ibUpdateIndices = 0);

};

#endif // !CATNATVisuExporter_H
