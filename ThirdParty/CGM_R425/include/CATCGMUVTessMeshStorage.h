// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVTessMeshStorage.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Jan 2012  Creation: ZFI
//===================================================================

#ifndef CATCGMUVTessMeshStorage_H
#define CATCGMUVTessMeshStorage_H

#include "ExportedByTessellateCommon.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATDataType.h"

class CATBody;
class CATFace;
class CATMathPoint;
class CATMathVector;
class CATEdge;
class CATPolyMathSurface;
class CATMathTransformation2D;
class CATMathPolyBuffers;

class ExportedByTessellateCommon CATCGMUVTessMeshStorage
{
public :
  CATCGMUVTessMeshStorage();
  virtual ~CATCGMUVTessMeshStorage();
  virtual void Dump();

public:
  //Face Mesh Storage
  virtual HRESULT BeginFaceMeshStorage(int iNbMeshVertices, int iNbMeshTriangles)=0;

  //Element
  virtual HRESULT StoreMeshVertex(int iNumVertex, const double iCoords[3])=0;
  virtual HRESULT UpdateMeshVertex(int iNumVertex, const double iCoords[3])=0;
  virtual HRESULT StoreMeshVertexNormal(int iNumVertex, const double iCoords[3], CATBoolean iInvert=0)=0;
  virtual HRESULT StoreMeshVertexUVs(int iNumVertex, const double iCoords[2])=0;
  virtual HRESULT StoreMeshTriangle(int iNumTriangle, const unsigned int iTrVertices[3], CATBoolean iInvert=0)=0;
  virtual HRESULT StoreMeshBarTangents(int iNumVertex1, int iNumVertex2, const double iTg1[3], const double iTg2[3]){return E_FAIL;}

	virtual HRESULT GetMeshVertex(int iNumVertex, double oCoords[3])=0;
  virtual HRESULT GetMeshTriangle(int iNumTriangle, unsigned int oTrVertices[3])=0;
  virtual HRESULT UpdateMeshTriangle(int iNumTriangle, const unsigned int iTrVertices[3])=0;

  //Buffers
  virtual HRESULT AddVerticesAndTriangles(unsigned int iFirstNumVertex, unsigned int iNbVertices,
                                          unsigned int iFirstNumTriangle, unsigned int iNbTriangles,
                                          const CATULONG32* iTriangles,CATBoolean iInvert)=0;

  virtual HRESULT UpdateMeshVertices(unsigned int iFirstNumVertex, unsigned int iNbVertices,
                                     const double* iPositions, const double* iNormals, const double* iUVs,
                                     CATBoolean iIsPlanar,CATBoolean iInvertNormal)=0;
  virtual HRESULT UpdateMeshVertices(const CATMathPolyBuffers* iPolyBuffers, unsigned int iFirstNumVertex, CATBoolean iInvertNormal);
    
  virtual HRESULT UpdateMeshVerticesAlongCurve(unsigned int iNbVertices, const CATULONG32* iMeshVertices,
                                               const double* iPositions, const double* iNormals, const double* iUVs,
                                               CATBoolean iIsPlanar,CATBoolean iInvertNormal)=0;
  virtual HRESULT UpdateMeshVerticesAlongCurve(const CATMathPolyBuffers* iPolyBuffers, const CATULONG32* iMeshVertices, CATBoolean iInvertNormal);

  //canonic poly surface
  //iUVTransfo gives transformation of original UVs to UVs to be used on given iMathSurface
  //iOrientation gives 1 or -1, to be applied to the normal given by iMathSurface, to have good oriented normals
  virtual HRESULT StoreMathSurface(const CATPolyMathSurface* iMathSurface, const CATMathTransformation2D& iUVTransfo, int iOrientation)=0;

  //Config
  virtual CATBoolean NeedNormals()const=0;
  virtual CATBoolean NeedUVs()const=0;
  virtual CATBoolean NeedTGs()const{return 0;}
  virtual CATBoolean NeedMathSurface()const=0;
};

#endif
