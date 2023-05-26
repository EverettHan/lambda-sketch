// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVTessBuilder.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Dec 2010  Creation: ZFI
//===================================================================

#ifndef CATCGMUVTessBuilder_H
#define CATCGMUVTessBuilder_H

#include "ExportedByTessellateCommon.h"
#include "CATErrorDef.h"
#include "CATTopDefine.h"
#include "CATListPV.h"
#include "CATBoolean.h"
#include "CATTessellateParam.h"

//exact topo
class CATBody;
class CATDomain;
class CATVolume;
class CATFace;
class CATEdge;
class CATVertex;

//other
class CATCGMUVCommonSettings;

//wt data
class CATCGMUVWTData;
class CATCGMUVFaceWTData;
class CATCGMUVEdgeWTData;

//storage
class CATCGMUVTessMeshStorage;
class CATCGMUVTessCurveStorage;
class CATCGMUVTessPLineStorage;
class CATCGMUVTessMeshVertexStorage;

//other
class CATEdgeCurve;
class CATPCurve;
class CATCrvParam;
class CATSurface;
class CATCGMUVFaceCacheAccess;
class CATCGMUVEdgeCacheAccess;
class CATCGMUVTessBuilderBuffers;
class CATMathPoint;
class CATTessellateParam;

class ExportedByTessellateCommon CATCGMUVTessBuilder
{
public :
  CATCGMUVTessBuilder(const CATTessellateParam& iTessParam);
  virtual ~CATCGMUVTessBuilder();

public:
  //compute WT Data
  HRESULT ComputeWTData(CATBody& iBody, CATCGMUVWTData& ioWTData,CATBoolean iProcessVerticesAsFreeVertices=0);

public:
  //tessellation of a face and border edges
  HRESULT GetFaceTessellation(CATFace& iFace, const CATCGMUVFaceWTData& iFaceWTData,
                              CATCGMUVTessMeshStorage& ioTessMeshStorage, 
                              CATCGMUVTessCurveStorage** ioTessCurvesStorages, 
                              CATCGMUVTessMeshVertexStorage** iMeshVertexStorages)const;
  //tessellation of a wire edge
  HRESULT GetWireEdgeTessellation(CATEdge& iEdge, CATCGMUVEdgeWTData& iEdgeWTData, CATCGMUVTessPLineStorage& ioTessPLineStorage)const;
  
  //tessellation of free vertex
  HRESULT GetFreeVertexTessellation(CATVertex& iVertex, CATMathPoint& oPoint)const;

  //PREPROCESS
private:
  HRESULT PreProcessBody     (CATBody& iBody    , CATCGMUVWTData& ioWTData) ;
  HRESULT PreProcessDomain   (CATDomain& iDomain, CATCGMUVWTData& ioWTData) ;
  HRESULT PreProcessVolume   (CATVolume& iVolume, CATCGMUVWTData& ioWTData) ;
  HRESULT PreProcessFace     (CATFace& iFace    , CATCGMUVWTData& ioWTData, CATOrientation iOrientation) ;
  HRESULT PreProcessFaceEdge (CATEdge& iEdge    , CATCGMUVWTData& ioWTData, CATCGMUVFaceWTData& iFaceWTData) ;
  HRESULT PreProcessWireEdge     (CATEdge& iEdge    , CATCGMUVWTData& ioWTData) ;    

  //Fill Data
private:
  HRESULT FillFaceData(CATCGMUVFaceWTData& iFaceWTData)const;
  HRESULT FillFaceEdgeData(CATCGMUVEdgeWTData& iEdgeWTData)const;
  HRESULT FillWireEdgeData(CATCGMUVEdgeWTData& iEdgeWTData)const;

  //Compute Delta
private:
  HRESULT ComputeEdgeDelta(CATCGMUVEdgeWTData& ioEdgeWTData) const;
  HRESULT ComputeEdgeGeometry(CATCGMUVEdgeWTData& ioEdgeWTData) const;

private:   
  HRESULT GetFaceTessellationTrivial(CATFace& iFace, const CATCGMUVFaceWTData& iFaceWTData,
                                     CATCGMUVTessMeshStorage& ioTessMeshStorage,
                                     CATCGMUVTessCurveStorage** ioTessCurvesStorages,
                                     CATCGMUVTessMeshVertexStorage** iMeshVertexStorages)const;
    
  HRESULT GetFaceTessellationFromCacheMesh(CATFace& iFace, const CATCGMUVFaceWTData& iFaceWTData,
                                           CATCGMUVTessMeshStorage& ioTessMeshStorage, 
                                           CATCGMUVTessCurveStorage** ioTessCurvesStorages,
                                           CATCGMUVTessMeshVertexStorage** iMeshVertexStorages)const;
	void SetCacheFormat(int iCacheFormat);


private:
  HRESULT AddDelta(CATULONG32* iFinalTriangles, int& iIdxV, int& iIdxT,
                   int iVPrev,  int iVNext, CATListOfInt* iVertexToNeighborTriangles, unsigned int iVertexToNeighborTrianglesSize)const;

  HRESULT ComputeCrvPointAndTangent(const CATEdgeCurve& iEdgeCurve, const CATCrvParam& iCrvParam, double* oP, double* oT=0)const;

private:
  friend class CATCGMUVTessBody;
  friend class CATTessellateBody;
  friend class CATTessellateBodyStatic;
  friend class CATCGMV5Tessellator;

protected:
  CATTessellateParam _TessParam;  
  CATCGMUVFaceCacheAccess* _FaceCacheAccess;
  CATCGMUVEdgeCacheAccess* _EdgeCacheAccess;
  CATCGMUVTessBuilderBuffers* _GeometryBuffers;
  CATBoolean _ProcessVerticesAsFreeVertices;
	int _CacheFormat;
};

#endif
