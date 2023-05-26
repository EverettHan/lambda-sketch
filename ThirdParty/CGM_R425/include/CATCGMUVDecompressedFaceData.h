/*
// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVDecompressedFaceData.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Sep 2013  Creation: NHD
//===================================================================
#ifndef CATCGMUVDecompressedFaceData_H
#define CATCGMUVDecompressedFaceData_H

#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATListOfULONG32.h"
#include "CATListOfDouble.h"
#include "CATCGMUVParamSubdivision1D.h"
#include "CATCGMUVFaceMeshBuffersItf.h"



class CATFace;
class CATCGMUVEdgeMeshFetcher;
class CATCGMUVFaceMeshBuffersItf2;
class CATCGMUVFaceMeshBuffersItf;
class CATCGMUVParam;
class CATCGMUVFaceWTData;
class CATUVFaceCacheReader;

class CATCGMUVDecompressedFaceData : public CATCGMUVFaceMeshBuffersItf
{
public:
  inline CATCGMUVDecompressedFaceData(const CATCGMUVFaceWTData* iFaceWTData);
  inline ~CATCGMUVDecompressedFaceData();
  
  HRESULT Initialize(CATUVFaceCacheReader& iFaceCacheReader);

  virtual HRESULT BeginTransaction()const {return S_OK;}
  virtual HRESULT EndTransaction() const{return S_OK;}

  virtual CATFace& GetFace() const{return *((CATFace*)0);}

  // returns iterator for edges underlying the face in question
  // returns S_FALSE and NULL, if no edges are present in the face (which should normally never happen)
  virtual HRESULT GetEdges(CATCGMUVFaceEdgesIter*& oIter)const ;

  // returns iterator for full vertices underlying the face in question
  // returns S_FALSE and NULL, if no full vertices are present in the face
  virtual HRESULT GetFullVertices(CATCGMUVFaceFullVerticesIter*& oIter)const;


  /////////////////////////////////////////////
  // Counts and Info
  /////////////////////////////////////////////

  virtual CATULONG32 GetNbVertices()const; 

  virtual CATULONG32 GetNbTriangles()const;

  virtual CATBoolean AreCoordsAvailable()const;

  virtual CATBoolean AreNormalsAvailable()const;

  virtual CATBoolean AreSurfParamsAvailable()const;

  /////////////////////////////////////////////
  // Face Curve Data
  /////////////////////////////////////////////

  virtual CATCGMUVFaceMeshCurveBuffersIter* GetFaceCurveDataIterator()const ;

  /////////////////////////////////////////////
  // Buffers
  /////////////////////////////////////////////

  virtual HRESULT GetCrvMeshForEdge(CATEdge& iEdge, CATCGMUVFaceMeshCurveBuffersItf*& oCurveMesh )const;

  // mesh, oNbVertices=oNbBorderVertices+oNbInternalVertices, Triangles Buffer refers to vertices using this order
  // if no distinctions between border vertices and internal vertices, all vertices are considered as internal vertices
  //
  // oTrAlignedWithFace
  //    TRUE: Means that triangle orientation is same as face orientation
  //    FALSE: Means that triangle orientation is opposite face orientation
  virtual HRESULT GetMeshTopology(
                      CATULONG32& oNbTriangles, CATULONG32& oNbBorderVertices, CATULONG32& oNbInternalVertices,
                      CATBoolean iGetTriangles, const CATULONG32*& oTriangles, CATBoolean& oTrAlignedWithFace,
                      CATBoolean& oReleaseAlloc) const;

  // iEdgeMeshFetcher needs to be passed only if you need border positions, i.e. if iGetBorderPositions is passed TRUE
  // Otherwise, pass iEdgeMeshFetcher as NULL
  virtual HRESULT GetMeshGeometry(
                      const CATCGMUVEdgeMeshFetcher* iEdgeMeshFetcher,
                      CATBoolean iGetBorderPositions, CATULONG32& oNbBorderPositions, const double*& oBorderPositions,
                      CATBoolean iGetBorderNormals, CATULONG32& oNbBorderNormals, const double*& oBorderNormals, 
                      CATBoolean iGetBorderUVs, CATULONG32& oNbBorderUVs, const double*& oBorderUVs, 
                      CATBoolean iGetInternalPositions, CATULONG32& oNbInternalPositions, const double*& oInternalPositions,
                      CATBoolean iGetInternalNormals, CATULONG32& oNbInternalNormals, const double*& oInternalNormals, 
                      CATBoolean iGetInternalUVs, CATULONG32& oNbInternalUVs, const double*& oInternalUVs, 
                      CATBoolean& oReleaseAlloc) const;

  // Get surface param subdivision information (only for internal points, not for border points)
  virtual HRESULT GetSurfParamSubdivision(
                      CATULONG32& oNbInternalUVs, 
                      const unsigned char*& oUSubdivBuffer, CATULONG32& oUSubdivBufferSize,
                      const unsigned char*& oVSubdivBuffer, CATULONG32& oVSubdivBufferSize,
                      const CATULONG32*& oIs, const CATULONG32*& oJs, const CATULONG32*& oLocations,
                      CATBoolean& oReleaseAlloc) const;


public:

  class EdgeData
  {
  public:
    inline EdgeData();
    inline ~EdgeData();

  public:
    //CATBoolean _IsFullEdge;
    CATEdge* _Edge;
  	CATULONG32 _NbVertices;
    CATULONG32* _VertexIndices;
	  double* _Tangents;
    CATCGMUVParamSubdivision1D _ParamSubdivision;
    CATListOfDouble _Params;

    CATULONG32 _NbDeltaVerticesInEdge;

    CATULONG32 _NbDeltaCoords;
    double* _DeltaCoords;

    CATULONG32 _NbDeltaTangents;
    double* _DeltaTangents;
  };

  //CATFace* _Face;
  const CATCGMUVFaceWTData* _FaceWTData;

  CATULONG32 _NbVertices;
  CATULONG32 _NbCVertices;
  CATULONG32 _NbInternalNormals;


  //CATBoolean _IsParamSubdAvailable;
  CATBoolean _AreTangentsAvailable;
  CATBoolean _AreBorderUVsAvailable;
  CATBoolean _AreBorderPosAvailable;
  CATBoolean _AreNormalsAvailable;
  CATBoolean _TrAlignedWithFace;
  CATBoolean _AreSurfParamsAvailable;
  CATBoolean _AreCoordsAvailable;
  CATBoolean _ReleaseAlloc;

  double* _InternalCoords;
  double* _SurfParams;
  double* _BorderNormals;
  double* _InternalNormals;

  CATULONG32* _TriangleIndices;
  CATULONG32 _NbTriangles;

  CATULONG32 _NbEdges;
  EdgeData* _EdgeData;
};

inline 
CATCGMUVDecompressedFaceData::CATCGMUVDecompressedFaceData(const CATCGMUVFaceWTData* iFaceWTData)
{
  _FaceWTData=iFaceWTData;
  
  //_Face        = 0;
  _NbVertices  = 0;
  _NbCVertices = 0;
  _NbInternalNormals = 0;


  //_IsParamSubdAvailable = FALSE;
  _AreTangentsAvailable   = FALSE;
  _AreBorderUVsAvailable  = FALSE;
  _AreBorderPosAvailable  = FALSE;
  _TrAlignedWithFace      = FALSE;
  _AreSurfParamsAvailable = FALSE;
  _AreCoordsAvailable     = FALSE;
  _AreNormalsAvailable    = FALSE;
  _ReleaseAlloc           = FALSE;


  _InternalCoords = 0;
  _SurfParams = 0;
  _BorderNormals = 0;
  _InternalNormals = 0;
  _TriangleIndices = 0;
  _NbTriangles = 0;

  _NbEdges = 0;
  _EdgeData = 0;
}

inline 
CATCGMUVDecompressedFaceData::~CATCGMUVDecompressedFaceData()
{
  //_Face = 0;
  _FaceWTData=0;
  _NbVertices = 0;
  _NbCVertices = 0;

  delete [] _InternalCoords; _InternalCoords = 0;
  delete [] _SurfParams; _SurfParams = 0;
  delete [] _BorderNormals; _BorderNormals = 0;
  delete [] _InternalNormals; _InternalNormals = 0;
  delete [] _TriangleIndices; _TriangleIndices = 0;
  _NbTriangles = 0;
 
  _NbEdges = 0;
  delete [] _EdgeData; _EdgeData = 0;
}

inline 
CATCGMUVDecompressedFaceData::EdgeData::EdgeData()
{
  //_IsFullEdge = FALSE;
  _Edge = 0;
  _NbVertices = 0;
  _VertexIndices = 0;
  _Tangents = 0;

  _NbDeltaVerticesInEdge = 0;
  _NbDeltaCoords = 0;
  _DeltaCoords = 0;
  _NbDeltaTangents = 0;
  _DeltaTangents = 0;
}

inline 
CATCGMUVDecompressedFaceData::EdgeData::~EdgeData()
{
  //_IsFullEdge = FALSE;
  _Edge = 0;
  _NbVertices = 0;
  delete [] _VertexIndices; _VertexIndices = 0;
  delete [] _Tangents; _Tangents = 0;

  delete [] _DeltaCoords; _DeltaCoords = 0;
  delete [] _DeltaTangents; _DeltaTangents = 0;
}

inline
CATULONG32 CATCGMUVDecompressedFaceData::GetNbVertices()const
{
  return _NbVertices;
}

inline
CATULONG32 CATCGMUVDecompressedFaceData::GetNbTriangles()const
{
  return _NbTriangles;
}

inline
CATBoolean CATCGMUVDecompressedFaceData::AreCoordsAvailable()const
{
  return _AreCoordsAvailable ;
}


inline
CATBoolean CATCGMUVDecompressedFaceData::AreNormalsAvailable()const
{
  return _AreNormalsAvailable;
}

inline
CATBoolean CATCGMUVDecompressedFaceData::AreSurfParamsAvailable()const
{
  return _AreSurfParamsAvailable;
}



#endif 

*/
