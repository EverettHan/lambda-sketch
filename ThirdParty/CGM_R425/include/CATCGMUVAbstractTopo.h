// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVAbstractTopo.h
//
//===================================================================
//
// Sep 2012  Creation: NHD / MPX
//===================================================================
#ifndef CATCGMUVAbstractTopo_H
#define CATCGMUVAbstractTopo_H

#include "ExportedByTessellateCommon.h"

#include "CATTopDefine.h"
#include "CATCGMUVParam.h"
#include "CATTessellateParamCache.h"
#include "CATSoftwareConfiguration.h"

#include "CATUVAbstractTopoHandles.h"

#include "CATUVListOfFaceHandles.h"
#include "CATUVListOfEdgeHandles.h"
#include "CATUVListOfLoopHandles.h"
#include "CATUVListOfVertexHandles.h"

class CATCGMUVTessCodeVersion;
class CATTessFaceDataCache;
class CATTessEdgeDataCache;
class CATEdge;

class ExportedByTessellateCommon CATCGMUVAbstractTopo 
{
public :
  virtual ~CATCGMUVAbstractTopo();

  virtual double GetResolution() const = 0;


  //////////////////////////////////////////
  // Methods for a Face
  //////////////////////////////////////////

  virtual HRESULT GetFaceId(
                      const CATUVFaceHandle iFaceHandle,
                      CATULONG32& oFaceId) const = 0;
  
  virtual HRESULT GetLoopsOfFace(
                      const CATUVFaceHandle iFaceHandle, 
                      CATUVListOfLoopHandles& oLoopList, 
                      CATListOfInt& oLocs) const = 0;
  
  virtual HRESULT GetFaceMeshBuffer(
                      const CATUVFaceHandle iFaceHandle,
                      const CATCGMUVParam& iUVParam,
                      CATSoftwareConfiguration& iConfig,
                      CATULONG32& oMeshBufferSize,
                      const unsigned char*& oMeshBuffer,
                      CATCGMUVTessCodeVersion& oTessCodeVersion) const = 0;

  virtual HRESULT GetFaceMeshBuffer(
                      const CATUVFaceHandle iFaceHandle,
                      const CATTessellateParamCache& iUVParam,
                      CATSoftwareConfiguration& iConfig,
                      CATULONG32& oMeshBufferSize,
                      const unsigned char*& oMeshBuffer,
                      CATCGMUVTessCodeVersion& oTessCodeVersion) const = 0;

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
                      double& oVmax) const = 0;

  virtual HRESULT GetOrientationWrtSurface(
                      const CATUVFaceHandle iFaceHandle, 
                      CATOrientation& oOrientation) const;

  //////////////////////////////////////////
  // Methods for a Loop
  //////////////////////////////////////////
  
  virtual HRESULT GetLoopId(
                      const CATUVLoopHandle iLoopHandle, 
                      CATULONG32 &oLoopId) const = 0;

  virtual HRESULT GetEdgesInLoop(
                      const CATUVLoopHandle iLoopHandle, 
                      CATUVListOfEdgeHandles& oEdgeList,  
                      CATListOfInt& oOrientations) const = 0;

  virtual HRESULT GetVerticesInLoop(
                      const CATUVLoopHandle iLoopHandle, 
                      CATUVListOfVertexHandles& oVertexList) const = 0;


  //////////////////////////////////////////
  // Methods for an Edge
  //////////////////////////////////////////

  virtual HRESULT GetEdgeId(
                      const CATUVEdgeHandle iEdgeHandle,
                      CATULONG32& oEdgeId) const = 0;
  
  virtual HRESULT GetVertices(
                      const CATUVEdgeHandle iEdgeHandle, 
                      CATUVVertexHandle& oStartV,
                      CATUVVertexHandle& oEndV) const = 0;

  virtual HRESULT GetEdgeMeshBuffer(
                      const CATUVEdgeHandle iEdgeHandle,
                      const CATCGMUVParam& iUVParam,
                      CATSoftwareConfiguration& iConfig, 
                      CATULONG32& oMeshBufferSize, 
                      const unsigned char*& oMeshBuffer,
                      CATCGMUVTessCodeVersion& oTessCodeVersion) const = 0;

  virtual HRESULT GetEdgeMeshBuffer(
                      const CATUVEdgeHandle iEdgeHandle,
                      const CATTessellateParamCache& iUVParam,
                      CATSoftwareConfiguration& iConfig, 
                      CATULONG32& oMeshBufferSize, 
                      const unsigned char*& oMeshBuffer,
                      CATCGMUVTessCodeVersion& oTessCodeVersion) const = 0;

  virtual HRESULT GetClassicEdgeCache(
                      const CATUVEdgeHandle iFaceHandle,
                      const CATCGMUVParam& iUVParam,
                      CATSoftwareConfiguration& iConfig,
                      const CATTessEdgeDataCache*& oCache) const;

  virtual HRESULT GetClassicEdgeCache(
                      const CATUVEdgeHandle iFaceHandle,
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
                      CATOrientation& oOrientation) const = 0;

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

  virtual CATBoolean IsLocalEdgeMeshAvailable() const;

  virtual HRESULT GetLocalEdgeMesh(
                      const CATUVEdgeHandle iEdgeHandle,
                      CATULONG32 &oNbEPoints,
                      const double* &oParams,
                      const double* &oPositions) const;
  
  virtual CATEdge* GetCATEdge(const CATUVEdgeHandle iEdgeHandle) const;

  //////////////////////////////////////////
  // Methods for a Vertex
  //////////////////////////////////////////

  //virtual HRESULT GetVertexId(
  //                    const CATUVVertexHandle iVertex,
  //                    CATULONG32& oVertexId) const = 0;
};

#endif

