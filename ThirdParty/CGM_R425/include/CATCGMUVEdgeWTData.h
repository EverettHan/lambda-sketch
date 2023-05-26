// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVEdgeWTData.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Sep 2011  Creation: ZFI
//===================================================================

#ifndef CATCGMUVEdgeWTData_H
#define CATCGMUVEdgeWTData_H

#include "ExportedByTessellateCommon.h"
#include "CATErrorDef.h"
#include "CATRefCounted.h"
#include "CATListOfDouble.h"
#include "CATListPV.h"
#include "CATBoolean.h"
#include "CATCGMUVEdgeCurveWTData.h"
#include "CATTopDefine.h"
#include <ListPOfCATCell.h>

class CATCGMUVEdgeMeshBuffersItf;
class CATCGMUVEdgeMeshBasicItf;
class CATEdge;
class CATVertex;
class CATPolyIntDoublyLinkedList;
class CATCGMUVEdgeCurveWTData;
class CATCGMUVFaceWTData;
class CATCGMUVEdgeWTData;
class CATMathCurve;

class CATTessEdgeDataCache;
class CATTessPointOnEdgeCache;
class CATCGMUVEdgeMeshRichItf;


class ExportedByTessellateCommon CATCGMUVEdgeWTData
{
public:
  CATCGMUVEdgeWTData();
  virtual ~CATCGMUVEdgeWTData();

public:
    //Geometry  
  int GetNbIndices()const{return _NbIndices;}
  int GetNbIndices0()const{return _NbIndices0;}

  double* GetParams()const{return _Params;}
  
  void SetParams(double* iParams, unsigned int iNbParams)
  {
    _NbIndices0=iNbParams;
    _NbIndices=_NbIndices0;
    _Params = iParams;
  }

  void SetParams(const CATListOfDouble& iParams,const CATPolyIntDoublyLinkedList& iIndexMap);
 
  int GetEdgeIndex(int iIndex)const
  {
    int edgeIndex=0;
    
    if (_IndexMap)
      edgeIndex= _IndexMap[iIndex-1];
    else 
      edgeIndex=iIndex;

    return edgeIndex;
  }

  //Get/Set
public:
  const CATCGMUVEdgeMeshBuffersItf* GetEdgeMesh()const{return _EdgeMesh;}
  void SetEdgeMesh(const CATCGMUVEdgeMeshBuffersItf* iEdgeMesh){_EdgeMesh=iEdgeMesh;}

  int GetSens()const {return _Sens;}
  void SetSens(int iSens){_Sens=iSens;}  

  double* GetPositionsToUpdate(){return _Positions;}
  double* GetTangentsToUpdate(){return _Tangents;}
    
  const double* GetPositions()const{return _Positions;}
  const double* GetTangents()const{return _Tangents;}
  
  void SetPositions(double* iPositions){_Positions=iPositions;}
  void SetTangents(double* iTangents){_Tangents=iTangents;}
  void AllocatePositionsAndTangents(CATBoolean iWithTangents);

public:  
  //topo
  void AddCurveWTData(CATCGMUVEdgeCurveWTData* iCurveInfo);
  CATBoolean IsLinkedTo(CATCGMUVFaceWTData* iFaceWTData);

  //delta
  void SetDeltaComputed(CATBoolean iDeltaComputed, int iNbDelta){_DeltaComputed=iDeltaComputed; _NbDelta=iNbDelta;}
  CATBoolean IsDeltaComputed() const{return _DeltaComputed;}

  //Get/Set
public:
  CATEdge* GetEdge(){return _Edge;}
  void SetEdge(CATEdge* iEdge){_Edge=iEdge;}

  CATULONG32 GetTag()const {return _Tag;}
  void SetTag(CATULONG32 iTag){_Tag=iTag;}  

  CATOrientation GetOrientation() const{return _Orientation;}
  void SetOrientation(CATOrientation iOrientation) {_Orientation=iOrientation;}

  void GetVertices(CATVertex*& oStartV, CATVertex*& oEndV){oStartV=_StartV; oEndV=_EndV;}
  void SetVertices(CATVertex* iStartV, CATVertex* iEndV){_StartV=iStartV; _EndV=iEndV;}

  const CATMathCurve* GetMathCurve(){return _MathCurve;}
  void SetMathCurve(const CATMathCurve* iMathCurve){_MathCurve=iMathCurve;}

  // local tessellation
  HRESULT Init(double iWS, double iWE);
  HRESULT Fill(int iNbPoints, const double* iParams, const double* iPositions, CATTessPointOnEdgeCache * iFirstTessPointOnEdgeCache=0, CATLONG32 * iCacheFormat=0); // !iCacheFormat or iCacheFormat[0]=0 : float, iCacheFormat[0]=1 (double)
  HRESULT GetLocalData(int & oNbLocalPoints, const double* &oLocalParams, const double* &oLocalPositions);
  HRESULT SetLocalData(int iNbLocalPoints, const double* iLocalParams, const double* iLocalPositions);
  CATCGMUVEdgeMeshRichItf* GetMesh()const;
  const CATTessEdgeDataCache* GetData()const;
  inline HRESULT GetBoundingLimits(double& oWMin, double& oWMax, int& oSens)const;
  inline CATTessPointOnEdgeCache * GetFirstTessPointOnEdgeCache()const;
  HRESULT SetGlobalParams(const CATListOfDouble& iWs);
  HRESULT FinishTessellation();
  inline int GetNbVertices()const;
  void GetDeltaStatus(int& oNbDelta, CATListPtrCATCell * oListOfDeltaCells = 0); // -1: unknown; 0: no delta; >0: nb delta
  HRESULT ComputeEdgeDelta(int& oNbDelta);
  inline void AddDeltaCell(CATCell* iCell);

private:
  //topo
  CATCGMUVEdgeCurveWTData* _FirstCrvWTData;
  CATEdge* _Edge;
  CATULONG32 _Tag;
  CATVertex *_StartV, *_EndV;
  CATOrientation _Orientation;
  const CATMathCurve* _MathCurve;

  //working form
  int _NbIndices0,_NbIndices;
  int* _IndexMap;

  CATBoolean _ReleasePosTan;
  double* _Positions;
  double* _Tangents;
  double* _Params;
  
  //delta
  CATBoolean _DeltaComputed;
  int _NbDelta;
  CATListPtrCATCell _ListOfDeltaCells;

  //geometry
  const CATCGMUVEdgeMeshBuffersItf* _EdgeMesh;
  int _Sens;
  
  //local tessellation
  double _WMin, _WMax;
  int _SensParam;
  CATListOfDouble _Ws;
  const CATTessEdgeDataCache* _Data;
  CATTessPointOnEdgeCache* _FirstTessPointOnEdgeCache;

  //local data
  int _NbLocalPoints;
  double* _LocalParams;
  double* _LocalPositions;

private:
  friend class CATCGMUVEdgeCurveWTDataIter;
};

//Curves Iter
class ExportedByTessellateCommon CATCGMUVEdgeCurveWTDataIter
{
public:
  CATCGMUVEdgeCurveWTDataIter(CATCGMUVEdgeWTData& iEdgeData)
  {
    _CurrentCrvWTData= iEdgeData._FirstCrvWTData;
  }
  
  ~CATCGMUVEdgeCurveWTDataIter()
  {
    _CurrentCrvWTData=0;
  }

public:
  CATCGMUVEdgeCurveWTDataIter& Begin(CATCGMUVEdgeWTData& iEdgeData)
  {
    _CurrentCrvWTData= iEdgeData._FirstCrvWTData;
    return *this;
  }
  
  CATBoolean End() const
  {
    return (_CurrentCrvWTData!=0)? 0:1;
  }
  
  CATCGMUVEdgeCurveWTDataIter &operator++()
  {
    if (_CurrentCrvWTData)
      _CurrentCrvWTData=_CurrentCrvWTData->_NextEdgeCurveWTData;
    return *this;
  }

  CATCGMUVEdgeCurveWTData* Get()
  {
    return _CurrentCrvWTData;
  }

private:
  CATCGMUVEdgeCurveWTData* _CurrentCrvWTData;
};

inline HRESULT CATCGMUVEdgeWTData::GetBoundingLimits(double& oWMin, double& oWMax, int& oSens)const
{
  oWMin = _WMin;
  oWMax = _WMax;
  oSens=_SensParam;
  return S_OK;
}

inline CATTessPointOnEdgeCache * CATCGMUVEdgeWTData::GetFirstTessPointOnEdgeCache()const
{
  return _FirstTessPointOnEdgeCache;
}

inline int CATCGMUVEdgeWTData::GetNbVertices()const
{
  return _Ws.Size();
}

inline void CATCGMUVEdgeWTData::AddDeltaCell(CATCell* iCell)
{
	_ListOfDeltaCells.RemoveValue(iCell); // pour ne pas dupliquer
	_ListOfDeltaCells.Append(iCell);
}

#endif
