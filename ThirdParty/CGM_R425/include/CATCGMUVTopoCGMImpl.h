// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVAbstractTopo.h
//
//===================================================================
//
// Sep 2012  Creation: NHD / MPX
//===================================================================
#ifndef CATCGMUVTopoCGMImpl_H
#define CATCGMUVTopoCGMImpl_H

#include "CATBaseUnknown.h"
#include "CATCGMUVAbstractTopo.h"

#include "CATTopDefine.h"
#include "CATCGMUVParam.h"
#include "CATTessellateParamCache.h"
#include "CATSoftwareConfiguration.h"

#include "ExportedByTessellateCommon.h"

class CATFace;
class CATEdge;
class CATDomain;
class CATVertex;


class CATGeoFactory;

class ExportedByTessellateCommon CATCGMUVTopoCGMImpl 
  : public CATCGMUVAbstractTopo 
{
public :
  
  inline CATCGMUVTopoCGMImpl(double iResolution);
  virtual ~CATCGMUVTopoCGMImpl();

public :

  virtual double GetResolution() const;


  //////////////////////////////////////////
  // Methods for a Face
  //////////////////////////////////////////

  virtual HRESULT GetFaceId(
                      const CATUVFaceHandle iFaceHandle,
                      CATULONG32& oFaceId) const;
  
  virtual HRESULT GetLoopsOfFace(
                      const CATUVFaceHandle iFaceHandle, 
                      CATUVListOfLoopHandles& oLoopList, 
                      CATListOfInt& oLocs) const;
  
  virtual HRESULT GetFaceMeshBuffer(
                      const CATUVFaceHandle iFaceHandle,
                      const CATCGMUVParam& iUVParam,
                      CATSoftwareConfiguration& iConfig,
                      CATULONG32& oMeshBufferSize,
                      const unsigned char*& oMeshBuffer,
                      CATCGMUVTessCodeVersion& oTessCodeVersion) const;

	  virtual HRESULT GetFaceMeshBuffer(
                      const CATUVFaceHandle iFaceHandle,
                      const CATTessellateParamCache& iTessParam,
                      CATSoftwareConfiguration& iConfig,
                      CATULONG32& oMeshBufferSize,
                      const unsigned char*& oMeshBuffer,
                      CATCGMUVTessCodeVersion& oTessCodeVersion) const;

  virtual HRESULT GetClassicFaceCache(
                      const CATUVFaceHandle iFaceHandle,
                      const CATCGMUVParam& iUVParam,
                      CATSoftwareConfiguration& iConfig,
                      const CATTessFaceDataCache*& oCache) const;

  virtual HRESULT GetClassicFaceCache(
                      const CATUVFaceHandle iFaceHandle,
                      const CATTessellateParamCache& iTessParam,
                      CATSoftwareConfiguration& iConfig,
                      const CATTessFaceDataCache*& oCache) const;

  // returns either mesh buffer or classic cache (whichever available)
  virtual HRESULT GetFaceMesh(
                      const CATUVFaceHandle iFaceHandle,
                      const CATCGMUVParam& iUVParam,
                      CATSoftwareConfiguration& iConfig,
                      CATULONG32& oMeshBufferSize,
                      const unsigned char*& oMeshBuffer,
                      CATCGMUVTessCodeVersion& oTessCodeVersion,
                      const CATTessFaceDataCache*& oCache) const;

  virtual HRESULT Get2DBoundingBox(
                      const CATUVFaceHandle iFaceHandle, 
                      double& oUmin, 
                      double& oVmin, 
                      double& oUmax, 
                      double& oVmax) const;

  virtual HRESULT GetOrientationWrtSurface(
                      const CATUVFaceHandle iFaceHandle, 
                      CATOrientation& oOrientation) const;


  //////////////////////////////////////////
  // Methods for a Loop
  //////////////////////////////////////////
  
  virtual HRESULT GetLoopId(const CATUVLoopHandle iLoopHandle, CATULONG32 &oLoopId) const;

  virtual HRESULT GetEdgesInLoop(const CATUVLoopHandle iLoopHandle, CATUVListOfEdgeHandles& oEdgeList,  CATListOfInt& oOrientations) const;

  virtual HRESULT GetVerticesInLoop(const CATUVLoopHandle iLoopHandle, CATUVListOfVertexHandles& oVertexList) const;


  //////////////////////////////////////////
  // Methods for an Edge
  //////////////////////////////////////////

  virtual HRESULT GetEdgeId(const CATUVEdgeHandle iEdgeHandle,CATULONG32& oEdgeId) const;
  
  virtual HRESULT GetVertices(
                      const CATUVEdgeHandle iEdgeHandle, 
                      CATUVVertexHandle& oStartV,
                      CATUVVertexHandle& oEndV) const;

  virtual HRESULT GetEdgeMeshBuffer(
                      const CATUVEdgeHandle iEdgeHandle,
                      const CATCGMUVParam& iUVParam,
                      CATSoftwareConfiguration& iConfig, 
                      CATULONG32& oMeshBufferSize, 
                      const unsigned char*& oMeshBuffer,
                      CATCGMUVTessCodeVersion& oTessCodeVersion) const;

  virtual HRESULT GetEdgeMeshBuffer(
                      const CATUVEdgeHandle iEdgeHandle,
                      const CATTessellateParamCache& iUVParam,
                      CATSoftwareConfiguration& iConfig, 
                      CATULONG32& oMeshBufferSize, 
                      const unsigned char*& oMeshBuffer,
                      CATCGMUVTessCodeVersion& oTessCodeVersion) const;

  virtual HRESULT GetClassicEdgeCache(
                      const CATUVEdgeHandle iEdgeHandle,
                      const CATCGMUVParam& iUVParam,
                      CATSoftwareConfiguration& iConfig,
                      const CATTessEdgeDataCache*& oCache) const;

  virtual HRESULT GetClassicEdgeCache(
                      const CATUVEdgeHandle iEdgeHandle,
                      const CATTessellateParamCache& iUVParam,
                      CATSoftwareConfiguration& iConfig,
                      const CATTessEdgeDataCache*& oCache) const;

  // returns either mesh buffer or classic cache (whichever available)
  virtual HRESULT GetEdgeMesh(
                      const CATUVEdgeHandle iEdgeHandle,
                      const CATCGMUVParam& iUVParam,
                      CATSoftwareConfiguration& iConfig, 
                      CATULONG32& oMeshBufferSize, 
                      const unsigned char*& oMeshBuffer,
                      CATCGMUVTessCodeVersion& oTessCodeVersion,
                      const CATTessEdgeDataCache*& oCache) const;

  virtual HRESULT GetOrientationWrtCurve(
                      const CATUVEdgeHandle iEdgeHandle, 
                      CATOrientation& oOrientation) const;

 
  virtual CATBoolean IsEdgeEvalAvailable() const;

  virtual HRESULT GetUvAtEdgeStart(
                      const CATUVEdgeHandle iEdgeHandle, 
                      const CATUVEdgeHandle iFaceHandle, 
                      double &oU,
                      double &oV) const;

  virtual HRESULT GetUvAtEdgeEnd(
                      const CATUVEdgeHandle iEdgeHandle, 
                      const CATUVEdgeHandle iFaceHandle, 
                      double &oU,
                      double &oV) const;

  virtual HRESULT GetUvOnEdge(
                      const CATUVEdgeHandle iEdgeHandle, 
                      const CATUVEdgeHandle iFaceHandle, 
                      CATULONG32 iNbWs,
                      const double* Ws,
                      double* oUVs) const;

  virtual CATEdge* GetCATEdge(const CATUVEdgeHandle iEdgeHandle) const;

  //////////////////////////////////////////
  // Methods for a Vertex
  //////////////////////////////////////////

  virtual HRESULT GetVertexId(const CATUVVertexHandle iVertex,CATULONG32& oVertexId) const;

private :
  inline CATFace* GetFaceFromHandle(const CATUVFaceHandle iFaceHandle) const;
  inline CATEdge* GetEdgeFromHandle(const CATUVEdgeHandle iEdgeHandle) const;
  inline CATVertex* GetVertexFromHandle(const CATUVVertexHandle iVertexHandle) const;
  inline CATDomain* GetLoopFromHandle(const CATUVLoopHandle iLoopHandle) const;

private :
  double _Resolution;
};

CATCGMUVTopoCGMImpl::CATCGMUVTopoCGMImpl(double iResolution)
: _Resolution(iResolution)
{
}

inline CATFace* CATCGMUVTopoCGMImpl::GetFaceFromHandle(const CATUVFaceHandle iFaceHandle)const
{
  return (CATFace*)iFaceHandle;
}
 
inline CATEdge* CATCGMUVTopoCGMImpl::GetEdgeFromHandle(const CATUVEdgeHandle iEdgeHandle)const
{
  return(CATEdge*) iEdgeHandle;
}

inline CATVertex* CATCGMUVTopoCGMImpl::GetVertexFromHandle(const CATUVVertexHandle iVertexHandle)const
{
  return (CATVertex*) iVertexHandle;
}

inline CATDomain* CATCGMUVTopoCGMImpl::GetLoopFromHandle(const CATUVLoopHandle iLoopHandle)const
{
  return (CATDomain*) iLoopHandle;
}

#endif

