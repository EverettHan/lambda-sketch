//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyDecoMeshBars.h
//
//=============================================================================
// 2009-03-18 ZFI
//=============================================================================

#ifndef CATPolyDecoMeshBars_H
#define CATPolyDecoMeshBars_H

#include "PolyBodyBuilders.h"
#include "CATPolyRefCounted.h"

#include "CATErrorDef.h" 
#include "CATBoolean.h"
#include "CATListOfInt.h"
#include "CATListPV.h"

class CATIPolyMesh;
class CATPolyBars;

class CATPolySurfaceFacetSupportLayer;
class CATPolyBarsBarSupportLayer;

class CATPolyMeshVertexNNormalsLayer;
class CATPolyMeshVertexNTexCoordsLayer;
class CATPolyMeshVertexNUVsLayer;

class CATMathPoint;
class CATMathVector;

class CATIPolySurfaceVertexTextureCoordLayer;
class CATIPolySurfaceVertexNormalLayer;
class CATIPolySurfaceVertexUVLayer;

class CATPolyDecoMeshObserver;
class CATMapOfIntToInt;

class CATMathPoint2D;

class ExportedByPolyBodyBuilders CATPolyDecoMeshBars:public CATPolyRefCounted
{
public:
	CATPolyDecoMeshBars () ;
	virtual ~CATPolyDecoMeshBars () ;

public:
  HRESULT Clear();
  HRESULT Init();
  HRESULT Init(CATIPolyMesh* iMesh);
  
  HRESULT AddVertex(const CATMathPoint& iPoint, 
                    int& oVertexIndex);
  
  HRESULT SetVertexNormal(const int iVertexIndex,
                          const CATMathVector& iNormal, 
                          const int iTag);

  HRESULT SetVertexUV(const int iVertexIndex,
                      const CATMathPoint2D& iUV, 
                      const int iTag);

  HRESULT AddBar(const int iVertices[2],
                 int& oBarIndex, 
                 const int iTag);

  HRESULT AddTriangle(const int iVertices[3],
                      int& oTrIndex, 
                      const int iTag);

  HRESULT MergeVertices(const int iV1, const int iV2);
  //when closed
  HRESULT GetVertexFaces(const int iIdxVertex,
                         CATListOfInt &oVertexSupports) const;
  int GetNbVertexFaces(const int iIdxVertex)const;

  //when opened
  int GetVertexFace(const int iIdxVertex)const;
  int GetBarFace(const int iIdxBar) const;

  //split 
  HRESULT SplitBar(const int iV1, const int iV2, const double iAlpha, int& oV);

public:

  //get/set
  CATIPolyMesh* GetPolyMesh() {return _PolyMesh;}
  CATPolyBars* GetPolyBars() {return _PolyBars;}
  CATListPV& GetWires(){return _Wires;}

  CATPolySurfaceFacetSupportLayer* GetFacetSupportLayer(){return _FacetSupportLayer;}
  CATPolyBarsBarSupportLayer* GetBarSupportLayer(){return _BarSupportLayer;}

  //when closed
  CATPolyMeshVertexNNormalsLayer* GetNNormalsLayer(){return _NNormalsLayer;}
  CATPolyMeshVertexNTexCoordsLayer* GetNTexCoordsLayer(){return _NTexCoordsLayer;}
  CATPolyMeshVertexNUVsLayer* GetNUVsLayer(){return _NUVsLayer;}

  //when openend
  CATIPolySurfaceVertexNormalLayer* GetNormalLayer(){return _NormalLayer;}
  CATIPolySurfaceVertexTextureCoordLayer* GetTexCoordLayer(){return _TexCoordsLayer;}

  //get/set/const
  const CATIPolyMesh* GetPolyMesh() const {return _PolyMesh;}
  const CATPolyBars* GetPolyBars() const{return _PolyBars;}

  const CATPolySurfaceFacetSupportLayer* GetFacetSupportLayer()const{return _FacetSupportLayer;}
  const CATPolyBarsBarSupportLayer* GetBarSupportLayer()const{return _BarSupportLayer;}

  //when closed 
  const CATPolyMeshVertexNNormalsLayer* GetNNormalsLayer()const{return _NNormalsLayer;}
  const CATPolyMeshVertexNTexCoordsLayer* GetNTexCoordsLayer()const{return _NTexCoordsLayer;}
  const CATPolyMeshVertexNUVsLayer* GetNUVsLayer()const{return _NUVsLayer;}

  //when opened
  const CATIPolySurfaceVertexNormalLayer* GetNormalLayer()const{return _NormalLayer;}
  const CATIPolySurfaceVertexTextureCoordLayer* GetTexCoordLayer()const{return _TexCoordsLayer;}
  
  //key management
public:
  HRESULT GetMaxKeyForTriangles(int& oMaxKey)const;
  HRESULT GetCopyOfFacetSupportLayer(CATPolySurfaceFacetSupportLayer& ioFacetSuppportLayer)const;

public:
  enum  VertexTypeIds
  {
    SurfaceVertex,
    HoleVertex, 
    EdgeVertex, 
    PolyVertex
  };
  typedef int VertexType;

  int GetVertexType(const int iVertex)const;
  HRESULT SetVertexType(const int iVertex, const int iType);


private:
  HRESULT InitPrivate(CATIPolyMesh* iMesh);

private:
  CATIPolyMesh* _PolyMesh;
  CATPolyBars* _PolyBars;
  CATListPV _Wires;

  CATPolyDecoMeshObserver* _PolyMeshObserver;

  CATPolySurfaceFacetSupportLayer* _FacetSupportLayer;
  CATPolyBarsBarSupportLayer* _BarSupportLayer;

  CATPolyMeshVertexNNormalsLayer* _NNormalsLayer;
  CATPolyMeshVertexNTexCoordsLayer* _NTexCoordsLayer;  
  CATPolyMeshVertexNUVsLayer* _NUVsLayer;  

  CATIPolySurfaceVertexNormalLayer* _NormalLayer;
  CATIPolySurfaceVertexTextureCoordLayer* _TexCoordsLayer;
  CATIPolySurfaceVertexUVLayer* _UVLayer;

  CATMapOfIntToInt* _VertexToVertexType;
};

#endif 
