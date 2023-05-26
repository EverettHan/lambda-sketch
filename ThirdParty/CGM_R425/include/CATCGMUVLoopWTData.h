// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVLoopWTData.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Feb 2013  Creation: MPX
//===================================================================

#ifndef CATCGMUVLoopWTData_H
#define CATCGMUVLoopWTData_H

#include "ExportedByTessellateCommon.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATTopDefine.h"
#include "CATLoop.h"
#include "CATCGMUVEdgeWTData.h"
#include "CATCGMUVWTData.h"
#include <string.h>

class CATCGMUVEdgeWTData;
class CATCGMUVVertexWTData;
class CATVertex;

class ExportedByTessellateCommon CATCGMUVLoopWTData
{
public:
  inline CATCGMUVLoopWTData(CATULONG32 iTag);
  virtual ~CATCGMUVLoopWTData();

public:
  void Init(CATLoop* iLoop, CATCGMUVWTData* ioWTData)
  {
    _NbEdges = (*iLoop).GetNbCellUses();
    InitEdges(_NbEdges);
    CATULONG32 i=0;
    for(i=0; i<_NbEdges;i++)
    {
      CATOrientation OriEdge ;
      CATEdge* pEdge = (CATEdge*)(*iLoop).GetCell(i+1, &OriEdge);
      CATCGMUVEdgeWTData* pEdgeWTData = ioWTData->GetEdgeWTData(*pEdge);
      if(pEdgeWTData)
      {
        _EdgeWTDatas[i] = pEdgeWTData;
        _Orientations[i]= OriEdge;
      }else
      {
        ioWTData->AddEdgeWTData(*pEdge, pEdgeWTData);
        _EdgeWTDatas[i] = pEdgeWTData;
        _Orientations[i]= OriEdge;
      }
     
    }
  }
  void InitEdges(CATULONG32 nbEdges)
  {
    _NbAllocatedEdges=nbEdges;
    if (_NbAllocatedEdges)
    {
      _EdgeWTDatas=new CATCGMUVEdgeWTData*[_NbAllocatedEdges];
      _Orientations=new CATOrientation[_NbAllocatedEdges];
      memset(_EdgeWTDatas,0,_NbAllocatedEdges*sizeof(CATCGMUVEdgeWTData*));
      memset(_Orientations,0,_NbAllocatedEdges*sizeof(CATOrientation));
    }
  }

  void InitFullVertices(CATULONG32 nbVertices)
  {
    _NbAllocatedVertices=nbVertices;
    if (_NbAllocatedVertices)
    {
      _FullVertices=new CATVertex*[_NbAllocatedVertices];
      memset(_FullVertices,0,_NbAllocatedVertices*sizeof(CATVertex*));
    }
  }

  void AddEdgeWTData(CATCGMUVEdgeWTData* iEdgeWTData, CATOrientation iOri)
  {
    if (_NbEdges>=_NbAllocatedEdges)
      return;
    _EdgeWTDatas[_NbEdges]=iEdgeWTData;
    _Orientations[_NbEdges]=iOri;
    ++_NbEdges;
  }

  void AddFullVertex(CATVertex* iVertex)
  {
    if (_NbFullVertices>=_NbAllocatedVertices)
      return;
    _FullVertices[_NbFullVertices]=iVertex;
    ++_NbFullVertices;
  }

  CATULONG32 GetTag()const {return _Tag;}
  void SetTag(CATULONG32 iTag){_Tag=iTag;}  

  //get
  CATCGMUVEdgeWTData* GetEdgeWTData(CATULONG32 iNumEdge, CATOrientation& oOri)const
  {
    oOri = _Orientations[iNumEdge-1];
    return _EdgeWTDatas[iNumEdge-1];
  }
  CATULONG32 GetNbEdges()const{return _NbEdges;}

  CATVertex* GetFullVertex(CATULONG32 iNumVertex)const
  {
    return _FullVertices[iNumVertex-1];
  }
  CATULONG32 GetNbFullVertices()const{return _NbFullVertices;}

private:
  CATULONG32 _Tag;

  CATULONG32 _NbEdges, _NbAllocatedEdges;
  CATCGMUVEdgeWTData** _EdgeWTDatas;
  CATOrientation* _Orientations;

  CATULONG32 _NbFullVertices, _NbAllocatedVertices;
  CATVertex** _FullVertices;
};

inline 
CATCGMUVLoopWTData::CATCGMUVLoopWTData(CATULONG32 iTag)
: _Tag(iTag), _NbEdges(0), _NbAllocatedEdges(0), _EdgeWTDatas(0), _Orientations(0), _NbFullVertices(0), _NbAllocatedVertices(0), _FullVertices(0)
{
}

#endif
