// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVEdgeCurveWTData.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Feb 2012  Creation: ZFI
//===================================================================

#ifndef CATCGMUVEdgeCurveWTData_H
#define CATCGMUVEdgeCurveWTData_H

#include "ExportedByTessellateCommon.h"
#include "CATRefCounted.h"
#include "CATListPV.h"
#include "CATListOfDouble.h"

#include "CATListOfInt.h"

class CATCGMUVEdgeWTData;
class CATCGMUVFaceWTData;
class CATCGMUVFaceMeshCurveBuffersItf;
class CATEdgeCurve;
class CATPCurve;

class ExportedByTessellateCommon CATCGMUVEdgeCurveWTData
{
public:
  CATCGMUVEdgeCurveWTData();
  virtual ~CATCGMUVEdgeCurveWTData();

public:
  HRESULT SetParams(double* iParams, unsigned int iNbParams)
  {
    _NbParams=iNbParams;
    if (_Params)
      delete [] _Params;
    _Params = iParams;
    return S_OK;
  }
  
  int GetNbParams(){return _NbParams;}
  double* GetParams(){return _Params;}

  //Get/Set
public:
  void SetEdgeWTData(CATCGMUVEdgeWTData* iEdgeWTData){ _EdgeData= iEdgeWTData;}
  CATCGMUVEdgeWTData* GetEdgeWTData(){return _EdgeData;}
  
  void SetFaceWTData(CATCGMUVFaceWTData* iFaceWTData){_FaceData = iFaceWTData;}
  CATCGMUVFaceWTData* GetFaceWTData(){return _FaceData;}

  void SetCurveMesh(const CATCGMUVFaceMeshCurveBuffersItf* iCurveMesh){_CurveMesh=iCurveMesh;}
  const CATCGMUVFaceMeshCurveBuffersItf* GetCurveMesh(){return _CurveMesh;}

  //local tessellation
  HRESULT SetLimits(double iWS, double iWE);
  HRESULT SetOriginalCurve(CATEdgeCurve* iEdgeCurve, CATPCurve* iPCurve);
  HRESULT AppendMeshVertex(int iIdxMeshV, int& oIdxV);
  HRESULT SetVertexLocalParam(int iIdxV, double iParam);
  inline HRESULT GetOriginalCurve(CATEdgeCurve*& oEdgeCurve, CATPCurve*& oPCurve)
  {
    oEdgeCurve=_EdgeCurve;
    oPCurve=_PCurve;
    return S_OK;
  }
  HRESULT CheckParams();
  HRESULT GetVertices(CATListOfInt& oVertices){oVertices=_MeshVertices;return S_OK;}
  HRESULT GetLocalParams(CATListOfDouble& oParams) {oParams=_LocalParams;return S_OK;}
  void SetParamsFromLocalParams() 
  {
    _NbParams = _LocalParams.Size();
    if (_Params)
      delete [] _Params;
    _Params=new double[_NbParams];
    for (int i=1; i<=_NbParams;++i)
      _Params[i-1]=_LocalParams[i];
  }
  inline HRESULT GetLimits(double& oWS, double& oWE)
  {
    if (_Sens==1)
    {
      oWS=_WMin;
      oWE=_WMax;
    }
    else
    {
      oWE=_WMin;
      oWS=_WMax;
    }
    return S_OK;
  }
  inline HRESULT GetCurveParamAtEdgeVertex(CATULONG32 iIdx, double& oW) const
  {
    double W = _LocalParams[iIdx+1];
    if (_Sens==1)
      oW = (1.-W)*_WMin + W*_WMax;
    else
      oW = (1.-W)*_WMax + W*_WMin;
    return S_OK;
  }
  inline HRESULT GetCurveLocalParamAtEdgeVertex(CATULONG32 iIdx, double& oW) const
  {
    oW = _LocalParams[iIdx+1];
    return S_OK;
  }

private:
  CATCGMUVEdgeWTData* _EdgeData;
  CATCGMUVFaceWTData* _FaceData;
  const CATCGMUVFaceMeshCurveBuffersItf* _CurveMesh;

  //topo
private:
  CATCGMUVEdgeCurveWTData* _NextEdgeCurveWTData; //next in edge
  friend class CATCGMUVEdgeWTData;
  friend class CATCGMUVEdgeCurveWTDataIter;

private:
  double* _Params;
  int _NbParams;

  //local tessellation
  CATListOfInt _MeshVertices;
  CATListOfDouble _LocalParams;
  CATEdgeCurve* _EdgeCurve;
  CATPCurve* _PCurve;
  double _WMin, _WMax;
  int _Sens;
};

#endif
