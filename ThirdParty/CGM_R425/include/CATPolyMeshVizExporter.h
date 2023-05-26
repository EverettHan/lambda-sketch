//=============================================================================
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// CATPolyMeshVizExporter.cpp
//
//=============================================================================
// 2008-02-13   BPG: New.
//=============================================================================
#ifndef CATPolyMeshVizExporter_H
#define CATPolyMeshVizExporter_H

#include "PolyImportExport.h"

#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATViz3DFace;
class CAT3DFaceGP;
class CATVizVertexBuffer;
class CATIPolyMesh;
class CATIPolySurface;
class CATPolySurfaceCompactVertexIndexMapper;
class CAT3DRep;
class IVisSGCustomPrimitive;
class IVisSG3DPrimitive;
class CATGraphicAttributeSet;
class VisRawBuffer;
class CATPolyPrimitiveDescriptionMesh;

class ExportedByPolyImportExport CATPolyMeshVizExporter
{
public:
  CATPolyMeshVizExporter();
  virtual ~CATPolyMeshVizExporter();

public:

  HRESULT Export (CATIPolyMesh &iMesh, const CATPolySurfaceCompactVertexIndexMapper* iCompactIndexMap, 
                  CAT3DFaceGP *&oFaceGP) const;

  // You'll need to do a CATVisHelpers::SetVertexBuffer on output faceGP afterwards
  HRESULT Export (CATIPolyMesh &iMesh, CATVizVertexBuffer &ioVertexBuffer, int iVertexBufferEntry, 
                  const CATPolySurfaceCompactVertexIndexMapper* iCompactIndexMap, CAT3DFaceGP *&oFaceGP) const;

public:

  HRESULT Export (CATIPolyMesh &iMesh, CATVizVertexBuffer &ioVertexBuffer, int iVertexBufferEntry, 
                  const CATPolySurfaceCompactVertexIndexMapper* iCompactIndexMap, CATViz3DFace *&oVizFace) const;



protected:

  HRESULT FillVertexBuffers(CATIPolySurface& iMesh,
    float* VertexPositionBuffer,
    float* VertexNormalBuffer,
    float* VertexUVBuffer,
    float* VertexTangentBuffer,
    float* VertexBinormalBuffer) const;

protected:
  CATBoolean _ExportNormalsP;
  CATBoolean _ExportUVsP;
  CATBoolean _ExportTextureP;
};

#endif // !CATPolyMeshVizExporter_H
