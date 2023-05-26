// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVTessPolyMeshStorage.h
//
//===================================================================
// Jan 2012  Creation: ZFI
//===================================================================

#ifndef CATCGMUVTessPolyMeshStorage_H
#define CATCGMUVTessPolyMeshStorage_H

#include "ExportedByTessellateCommon.h"
#include "CATCGMUVTessMeshStorage.h"

class CATIPolyMesh;
class CATIPolySurfaceVertexPositionLayer;
class CATIPolySurfaceVertexNormalLayer;
class CATIPolySurfaceVertexUVLayer;
class CATIPolySurfaceOrientedBarTangentLayer;
class CATMathPolyBuffers;

class ExportedByTessellateCommon CATCGMUVTessPolyMeshStorage: public CATCGMUVTessMeshStorage
{
public :
  CATCGMUVTessPolyMeshStorage(CATFace& iFace,int iContextOrientation, int iNbMeshVertices, int iNbMeshTriangles,CATBoolean iStoreNormals, CATBoolean iStoreUVs, CATBoolean iStoreTGs=0, int iCacheFormat=0); // 0: float, 1: double
  virtual ~CATCGMUVTessPolyMeshStorage();

  void Dump();

public:
  CATIPolyMesh* GetPolyMesh();

private:
  //Face Mesh Storage
  HRESULT BeginFaceMeshStorage(int iNbMeshVertices, int iNbMeshTriangles);
  HRESULT StoreMeshVertex(int iNumVertex, const double iCoords[3]);
  HRESULT UpdateMeshVertex(int iNumVertex, const double iCoords[3]);
  HRESULT StoreMeshVertexNormal(int iNumVertex, const double iCoords[3], CATBoolean iInvert=0);
  HRESULT StoreMeshVertexUVs(int iNumVertex, const double iCoords[2]);  
  HRESULT StoreMeshTriangle(int iNumTriangle, const unsigned int iTrVertices[3],CATBoolean iInvert=0);
  HRESULT StoreMeshBarTangents(int iNumVertex1, int iNumVertex2, const double iTg1[3], const double iTg2[3]);

	HRESULT GetMeshVertex(int iNumVertex, double oCoords[3]);
  HRESULT GetMeshTriangle(int iNumTriangle, unsigned int oTrVertices[3]);
  HRESULT UpdateMeshTriangle(int iNumTriangle, const unsigned int iTrVertices[3]);
  
  //Buffers
  HRESULT AddVerticesAndTriangles(unsigned int iFirstNumVertex, unsigned int iNbVertices,
                                  unsigned int iFirstNumTriangle, unsigned int iNbTriangles,
                                  const CATULONG32* iTriangles,CATBoolean iInvert);

  HRESULT UpdateMeshVertices(unsigned int iFirstNumVertex, unsigned int iNbVertices,
                             const double* iPositions, const double* iNormals, const double* iUVs,
                             CATBoolean iIsPlanar,CATBoolean iInvertNormal);
  HRESULT UpdateMeshVertices(const CATMathPolyBuffers* iPolyBuffers, unsigned int iFirstNumVertex, CATBoolean iInvertNormal);

  HRESULT UpdateMeshVerticesAlongCurve(unsigned int iNbVertices, const CATULONG32* iMeshVertices,
                                       const double* iPositions, const double* iNormals, const double* iUVs,
                                       CATBoolean iIsPlanar,CATBoolean iInvertNormal);
  HRESULT UpdateMeshVerticesAlongCurve(const CATMathPolyBuffers* iPolyBuffers, const CATULONG32* iMeshVertices, CATBoolean iInvertNormal);
  
  //canonic
  HRESULT StoreMathSurface(const CATPolyMathSurface* iMathSurface, const CATMathTransformation2D& iUVTransfo, int iOrientation); //math surface released by caller

  //Config
  CATBoolean NeedNormals()const;
  CATBoolean NeedUVs()const;
  CATBoolean NeedTGs()const;
  CATBoolean NeedMathSurface()const;

private:

  // Mesh
  CATIPolyMesh* _PolyMesh;
  CATIPolySurfaceVertexPositionLayer* _PosLayer;
  CATIPolySurfaceVertexNormalLayer* _NormalLayer;
  CATIPolySurfaceVertexUVLayer* _UVLayer;
  CATIPolySurfaceOrientedBarTangentLayer* _TGLayer;
};

#endif
