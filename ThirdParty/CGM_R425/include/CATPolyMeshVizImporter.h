//=============================================================================
// COPYRIGHT Dassault Systemes 2007
//=============================================================================
//
// CATPolyMeshVizImporter.cpp
//
//=============================================================================
// 2007-05-XX   MNA: New.
//=============================================================================
#ifndef CATPolyMeshVizImporter_H
#define CATPolyMeshVizImporter_H

#include "PolyImportExport.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATViz3DFace;
class CAT3DFaceGP;
class CAT4x4Matrix;
class CATVizVertexBuffer;
class CATIPolyMesh;
class CATMapOfIntToInt;

//
class ExportedByPolyImportExport CATPolyMeshVizImporter
{
public:
  CATPolyMeshVizImporter();
  virtual ~CATPolyMeshVizImporter();

public:
  HRESULT Import(CATViz3DFace &iVizFace, const CAT4x4Matrix * iPosition,CATVizVertexBuffer &iBuffer,
                 CATIPolyMesh *&oMesh,
                 CATMapOfIntToInt *&oIndexGPIndexMesh) const;

  HRESULT Import(CAT3DFaceGP &iFaceGP,const CAT4x4Matrix * iPosition,
                 CATIPolyMesh *&oMesh,
                 CATMapOfIntToInt *&oIndexGPIndexMesh) const;

public:
  // Default is FALSE
  HRESULT DoImportVerticesNormals(CATBoolean iFlag = TRUE);

  // Default is FALSE
  HRESULT DoImportTextureCoords(CATBoolean iFlag = TRUE);

  // Default is FALSE
  HRESULT DoImportVerticesColors(CATBoolean iFlag = TRUE);

  // Default is FALSE
  HRESULT DoImportUVData(CATBoolean iFlag = TRUE);

  // Default is TRUE
  HRESULT DoKeepGPLinks(CATBoolean iFlag = TRUE);

  // Default is TRUE (FIXME: should be FALSE)
  HRESULT DoImportCellLayer(CATBoolean iFlag = TRUE);

  // Default is TRUE (FIXME: should be FALSE)
  HRESULT DoDuplicate(CATBoolean iFlag = TRUE);

  // Default is FALSE. When set to TRUE, implies DoDuplicate.
  HRESULT DoCreateEditableMesh(CATBoolean iFlag = TRUE);

  //
protected:
  CATBoolean _ImportVerticesNormals;
  CATBoolean _ImportTextureCoords;
  CATBoolean _ImportVerticesColor;
  CATBoolean _ImportVerticesCellLayer;
  CATBoolean _ImportUVData;

  CATBoolean _KeepGPLinks;

  CATBoolean _MeshDuplicate;

  CATBoolean _CreateEditableMesh;
};

#endif // !CATPolyMeshVizImporter_H
