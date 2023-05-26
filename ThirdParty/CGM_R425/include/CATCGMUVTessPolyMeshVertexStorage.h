// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVTessPolyMeshVertexStorage.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Jan 2012  Creation: ZFI
//===================================================================

#ifndef CATCGMUVTessPolyMeshVertexStorage_H
#define CATCGMUVTessPolyMeshVertexStorage_H

#include "CATCGMUVTessMeshVertexStorage.h"

class CATVertex;
class CATPolyMeshVertex;
class CATIPolyMesh;
class CATVertex;
class CATCGMUVTessPolyMeshStorage;

class ExportedByTessellateCommon CATCGMUVTessPolyMeshVertexStorage: public CATCGMUVTessMeshVertexStorage
{
public :
  CATCGMUVTessPolyMeshVertexStorage(CATVertex& iVertex,CATCGMUVTessPolyMeshStorage& iTessMeshStorage);
  virtual ~CATCGMUVTessPolyMeshVertexStorage();

public:
  CATPolyMeshVertex* GetPolyMeshVertex();

private:
  HRESULT StoreMeshVertex(const unsigned int iMeshVertex);
  HRESULT StorePoint(const CATMathPoint& iPosition);

private:
  //Mesh Vertex
  CATPolyMeshVertex* _PolyMeshVertex;
  CATIPolyMesh* _PolyMesh;
  CATVertex* _Vertex;
};

#endif
