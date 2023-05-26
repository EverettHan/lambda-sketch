// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVFaceWTData.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Sep 2011  Creation: ZFI
//===================================================================

#ifndef CATCGMUVFaceWTData_H
#define CATCGMUVFaceWTData_H

#include "ExportedByTessellateCommon.h"
#include "CATRefCounted.h"
#include "CATListPV.h"
#include "CATCGMUVEdgeCurveWTData.h"
#include "CATCGMUVLoopWTData.h"
#include "CATCGMUVVertexWTData.h"
#include "CATDataType.h"
#include <ListPOfCATCell.h>
#include "CATFace.h"
#include "CATLoop.h"
#include "CATMapOfPtrToInt.h"
#include "CATTessFaceDataCache.h"
#include "CATMathPolyBuffers.h"
#include "CATTessFaceInsideDeltaCache.h"

class CATCGMUVFaceMeshBuffersItf;
class CATSurface;
class CATCGMUVEdgeCurveWTData;

class CATTessPointIter;
class CATTessStripeIter;
class CATTessFanIter;
class CATTessPolyIter;
class CATTessTrianIter;
class CATTessIsoIter;
class CATCGMUVFaceMeshRichItf;

class CATListPtrCATCell;
class CATCGMUVCommonSettings;
class CATTessFaceInsideDeltaCache;

class ExportedByTessellateCommon CATCGMUVFaceWTData
{
public:
  CATCGMUVFaceWTData();
  virtual ~CATCGMUVFaceWTData();

  //Loops/Curves data
public:
  ////old set
  //HRESULT SetCurvesWTData(CATListPV& iEdgesCurvesCacheWTDatas)
  //{
  //  _NbCrvs=iEdgesCurvesCacheWTDatas.Size();
  //  _EdgesCurvesCacheWTDatas=new CATCGMUVEdgeCurveWTData*[_NbCrvs];
  //  int numCrv=0;
  //  for (numCrv=0; numCrv<_NbCrvs;++numCrv)
  //    _EdgesCurvesCacheWTDatas[numCrv]=(CATCGMUVEdgeCurveWTData*)iEdgesCurvesCacheWTDatas[numCrv+1];
  //  return S_OK;
  //}
  //new set
  void InitLoopsWTData(CATCGMUVWTData* iWTData)
  {
		if (!iWTData)
			return;

    _NbAllocatedLoops= _Face->GetNbDomains();
    if (_NbAllocatedLoops)
    {
      _LoopsWTData=new CATCGMUVLoopWTData*[_NbAllocatedLoops];
      _Locs=new CATLocation[_NbAllocatedLoops];
      memset(_LoopsWTData,0,_NbAllocatedLoops*sizeof(CATCGMUVLoopWTData*));
      memset(_Locs,0,_NbAllocatedLoops*sizeof(CATLocation));
    }

    CATULONG32 NbVertexInFace = 0;
    CATULONG32 i = 0;
    for(i=0;i<_NbAllocatedLoops;i++)
    {
      CATLocation Location;
      CATLoop* pLoop = (CATLoop*)_Face->GetDomain(i+1,&Location);
      
      if(pLoop)
      {
        //_Locs[i] = Location;
        CATCGMUVLoopWTData* pLoopWTData = new CATCGMUVLoopWTData(pLoop->GetPersistentTag());
        if(pLoopWTData)
        {
          pLoopWTData->Init(pLoop,iWTData);
          //_LoopsWTData[i] = pLoopWTData;
          AddLoopWTData(pLoopWTData,Location);

        }
				// VertexInFace
				unsigned int NbCells = (*pLoop).GetNbCellUses();
				if (NbCells==1)
				{
					CATCell * Cell = (*pLoop).GetCell(1);
					if (Cell && Cell->GetDimension()==0) // CATVertexInFace
					{
						NbVertexInFace++;
						//CATCGMUVVertexWTData
						CATVertex* vertex = (CATVertex*) Cell;
						CATCGMUVVertexWTData* vertexWTData=iWTData->GetVertexWTData(*vertex);
						if (!vertexWTData)
						{
							iWTData->AddVertexWTData(*vertex, vertexWTData);
							if (vertexWTData)
							{
								vertexWTData->SetVertex(vertex);
								vertexWTData->AddBoundedCells(_Face);
							}
						}
					}
				}

      }
    }

		if (NbVertexInFace>0)
			_VertexInFaceIndice = new CATMapOfPtrToInt(NbVertexInFace);


  }
  void AddLoopWTData(CATCGMUVLoopWTData* iLoopWTData, CATLocation iLoc)
  {
    if (_NbLoops>=_NbAllocatedLoops)
      return;
    _LoopsWTData[_NbLoops]=iLoopWTData;
    _Locs[_NbLoops]=iLoc;
    ++_NbLoops;
  }

  void AddVertexInFace(CATVertex* iVertexInFace, CATLONG32 indexInFace)
  {
    if (_VertexInFaceIndice)
			_VertexInFaceIndice->Insert(iVertexInFace, indexInFace);
  }

  CATLONG32 GetNumberOfVertexInFace() const
  {
    if (_VertexInFaceIndice)
			return _VertexInFaceIndice->Size();
		return 0;
  }

	const CATMapOfPtrToInt * GetVertexInFaceMap() const
	{
		return _VertexInFaceIndice;
	}

  void InitCurvesWTData(CATULONG32 iNbCrvs)
  {
    _NbAllocatedCrvs=iNbCrvs;
    if (_NbAllocatedCrvs)
    {
      _EdgesCurvesCacheWTDatas=new CATCGMUVEdgeCurveWTData*[_NbAllocatedCrvs];
      memset(_EdgesCurvesCacheWTDatas,0,_NbAllocatedCrvs*sizeof(CATCGMUVEdgeCurveWTData*));
    }
  }
  void AddCurveWTData(CATCGMUVEdgeCurveWTData* iCrvWTData)
  {
    if (_NbCrvs>=_NbAllocatedCrvs)
      return;
    _EdgesCurvesCacheWTDatas[_NbCrvs]=iCrvWTData;
    ++_NbCrvs;
  }

  //get
  CATCGMUVLoopWTData* GetLoopWTData(CATULONG32 iNumLoop, CATLocation& oLoc)const
  {
    oLoc = _Locs[iNumLoop-1];
    return _LoopsWTData[iNumLoop-1];
  }
  CATULONG32 GetNbLoops()const{return _NbLoops;}

  CATCGMUVEdgeCurveWTData* GetCrvWTData(CATULONG32 iNumCrv)const
  {
    return _EdgesCurvesCacheWTDatas[iNumCrv-1];
  }
  CATULONG32 GetNbCrvs()const{return _NbCrvs;}

	CATULONG32 GetNbIsoVertexLines()const
	{
		if (_Data)
		{
			const CATMathPolyBuffers* PolyBuffers = _Data->GetPolyBuffers ();
			if (PolyBuffers)
				return PolyBuffers->GetNbVertexLines();
		}
		return 0;
	}

	const CATLONG32* GetIsoVertexLineIndicesBuffer (CATLONG32 iNumIso, CATLONG32& oNbIndices) const
	{
		CATLONG32* oIndicesBuffer = 0;
		oNbIndices = 0;
		if (_Data)
		{
			const CATMathPolyBuffers* PolyBuffers = _Data->GetPolyBuffers ();
			if (PolyBuffers)
			{
				const CATLONG32* IndicesBuffer = PolyBuffers->GetVertexLineIndicesBuffer ();
				const CATLONG32* NbVerticesPerVertexLineBuffer = PolyBuffers->GetNbVerticesPerVertexLineBuffer ();
				CATLONG32 NbIsos = PolyBuffers->GetNbVertexLines ();
				CATLONG32 iad = 0;
				for(CATLONG32 i=1;i<=NbIsos;i++)
				{
					CATLONG32 NbIndices = NbVerticesPerVertexLineBuffer[i-1];
					if (i==iNumIso)
					{
						//oIndicesBuffer = &IndicesBuffer[iad];
						oIndicesBuffer = NbIndices>0 ? new CATLONG32[NbIndices]:0;
						if (oIndicesBuffer)
						{
							for (int k=0; k<(int)NbIndices;++k)
								oIndicesBuffer[k] = IndicesBuffer[iad+k]/3; // indice stored as vertex adress
						}
						oNbIndices = NbIndices;
						return oIndicesBuffer;
					}
					iad = iad + NbIndices;
				}
			}
		}
		return oIndicesBuffer;
	}

  //GET/SET
public:  
  CATFace* GetFace(){return _Face;}
  void SetFace(CATFace* iFace){_Face=iFace;}

  CATULONG32 GetTag()const {return _Tag;}
  void SetTag(CATULONG32 iTag){_Tag=iTag;} 
  
  const CATCGMUVFaceMeshBuffersItf* GetFaceMesh()const{return _FaceMesh;}
  void SetFaceMesh(const CATCGMUVFaceMeshBuffersItf* iFaceMesh){
    _FaceMesh = iFaceMesh;
  }

  //CATCGMUVCacheAttribute* GetAttribute(){return _Attribute;}
  //void SetAttribute(CATCGMUVCacheAttribute* iAttribute){_Attribute = iAttribute;}

  CATULONG32 GetNbSplits()const{return _NbSplits;}
  void SetNbSplits(CATULONG32 iNbSplits){_NbSplits = iNbSplits;}
  
  CATULONG32 GetNbVertices()const{return _NbVertices;}
  void SetNbVertices(CATULONG32 iNbVertices){_NbVertices = iNbVertices;}

  CATULONG32 GetNbTriangles()const{return _NbTriangles;}
  void SetNbTriangles(CATULONG32 iNbTriangles){_NbTriangles = iNbTriangles;}

  CATLONG32 GetOrientation() const{return _Orientation;}
  void SetOrientation(CATLONG32 iOrientation) {_Orientation=iOrientation;}

  CATOrientation GetOrientationWrtSurf() const{return _OrientationWrtSurf;}
  void SetOrientationWrtSurf(CATOrientation iOrientation) {_OrientationWrtSurf=iOrientation;}

  void Get2DBox(double &oUmin, double &oVmin, double &oUmax, double &oVmax) const{
    oUmin = _2DBox[0]; oVmin = _2DBox[1]; oUmax = _2DBox[2]; oVmax = _2DBox[3]; 
  }
  void Set2DBox(double iUmin, double iVmin, double iUmax, double iVmax){
    _2DBox[0] = iUmin; _2DBox[1] = iVmin; _2DBox[2] = iUmax; _2DBox[3] = iVmax; 
  }
	
	void SetDeltaCache(const CATTessFaceInsideDeltaCache* iDeltaCache){
		if (_DeltaCache)
			_DeltaCache->Release();
		_DeltaCache = iDeltaCache;
		if (_DeltaCache)
			_DeltaCache->AddRef();
  }

	const CATTessFaceInsideDeltaCache* GetDeltaCache() const{
		return _DeltaCache;
	}

  //local tessellation
  HRESULT StoreData(CATBoolean iPlane,
                    CATLONG32 iNbPoints, CATTessPointIter *iPoints,
                    CATLONG32 iNbStrips, CATTessStripeIter *iStrips,
                    CATLONG32 iNbFans, CATTessFanIter *iFans,
                    CATLONG32 iNbPolygons, CATTessPolyIter *iPolygons,
                    CATLONG32 iNbTriangles, CATTessTrianIter *iTriangles, CATCGMUVCommonSettings * iSettings, 
										CATLONG32 * iCacheFormat=0); // !iCacheFormat or iCacheFormat[0]=0 : float, iCacheFormat[0]=1 (double)
  HRESULT StoreData(CATBoolean iPlane,
                    CATLONG32 iNbPoints, CATTessPointIter *iPoints,
                    CATLONG32 iNbIsos, CATTessIsoIter *iIsos, CATCGMUVCommonSettings * iSettings, 
										CATLONG32 * iCacheFormat=0); // !iCacheFormat or iCacheFormat[0]=0 : float, iCacheFormat[0]=1 (double)
  HRESULT StoreDataForGeomVisu(CATBoolean iPlane,
                    CATLONG32 iNbPoints, CATTessPointIter *iPoints,
                    CATLONG32 iNbStrips, CATTessStripeIter *iStrips,
                    CATLONG32 iNbFans, CATTessFanIter *iFans,
                    CATLONG32 iNbPolygons, CATTessPolyIter *iPolygons,
                    CATLONG32 iNbTriangles, CATTessTrianIter *iTriangles, CATCGMUVCommonSettings * iSettings,
										CATLONG32 * iCacheFormat=0); // !iCacheFormat or iCacheFormat[0]=0 : float, iCacheFormat[0]=1 (double)
	CATBoolean TrianglesOrientedAsSurf()const {return _TrianglesOrientedAsSurf;}
  HRESULT Verify(int & ioNbMissingEdges);
  CATCGMUVFaceMeshRichItf* GetMesh()const;
  
	const CATTessFaceDataCache* GetData()const;
	void SetData(const CATTessFaceDataCache* iDataCache){
		if (_Data)
			_Data->Release();
		_Data = iDataCache;
		if (_Data)
			_Data->AddRef();
  }

  HRESULT FinishTessellation();
  void GetDeltaStatus(int& oNbDelta, CATListPtrCATCell * oListOfDeltaCells = 0); // -1: unknown; 0: no delta; >0: nb delta

	HRESULT GetPolyBuffers(const CATMathPolyBuffers* &oFacePolyBuffers) const;
	HRESULT GetDataAsTriangles(CATULONG32& oNbTriangles, const CATULONG32*& oTriangles, CATULONG32& oNbVertices, CATBoolean& oTrAlignedWithFace, CATBoolean& oReleaseAlloc) const;
	HRESULT GetDataGeometry(CATBoolean iGetPositions, CATULONG32& oNbPositions, const double*& oPositions,
													CATBoolean iGetNormals, CATULONG32& oNbNormals, const double*& oNormals, 
													CATBoolean iGetUVs, CATULONG32& oNbUVs, const double*& oUVs, 
													CATBoolean& oReleaseAlloc) const;

private:
  //topo
  CATCGMUVEdgeCurveWTData** _EdgesCurvesCacheWTDatas;
  CATCGMUVLoopWTData** _LoopsWTData;
  CATLocation* _Locs;
  CATFace* _Face;
  CATULONG32 _Tag;

	CATMapOfPtrToInt * _VertexInFaceIndice; // Full vertices

  // Attribute


  //CATCGMUVCacheAttribute* _Attribute;

  //geometry
  const CATCGMUVFaceMeshBuffersItf* _FaceMesh;

  //sizes
  CATULONG32 _NbLoops, _NbAllocatedLoops;
  CATULONG32 _NbCrvs, _NbAllocatedCrvs;
  CATULONG32 _NbVertices, _NbTriangles,_NbSplits;
  CATLONG32 _Orientation;
  CATOrientation _OrientationWrtSurf;
  double _2DBox[4]; // umin, vmin, umax, vmax
	CATBoolean _TrianglesOrientedAsSurf;

  //local tessellation
  const CATTessFaceDataCache* _Data;
	const CATTessFaceInsideDeltaCache* _DeltaCache;

	//contextual delta 
  int _NbDelta;
  CATListPtrCATCell _ListOfDeltaCells;

private:
  friend class CATCGMUVLoopCurveWTDataIter;
};

#endif
