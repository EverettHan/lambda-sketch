#ifndef CATCGMUVFaceMeshBasicItf_H
#define CATCGMUVFaceMeshBasicItf_H

#include "ExportedByTessellateCommon.h"

#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATListOfULONG32.h"

class CATFace;
class CATEdge;
class CATVertex;

class CATCGMUVParamSubdivision1D;
//class CATCGMUVFaceMeshCurveBasicItf;
class CATCGMUVEdgeMeshFetcher;

class ExportedByTessellateCommon CATCGMUVFaceMeshBasicItf
{
public:
  virtual ~CATCGMUVFaceMeshBasicItf();
public:

  virtual CATFace& GetFace() const = 0;


  /////////////////////////////////////////////
  // Vertex Geometry data
  /////////////////////////////////////////////

  virtual CATULONG32 GetNbVertices() const = 0; 

  virtual CATBoolean AreCoordsAvailable() const = 0;

  // iVIdx should be between 0 and (GetNbVertices() - 1)
  virtual HRESULT GetCoords(CATULONG32 iVIdx, double& oX, double& oY, double& oZ) const = 0;

  virtual CATBoolean AreNormalsAvailable() const = 0;

  // iVIdx should be between 0 and (GetNbVertices() - 1)
  virtual HRESULT GetNormal(CATULONG32 iVIdx, double& oX, double& oY, double& oZ) const = 0;

  virtual CATBoolean AreSurfParamsAvailable() const = 0;

  // iVIdx should be between 0 and (GetNbVertices() - 1)
  virtual HRESULT GetSurfParams(CATULONG32 iVIdx, double& oU, double& oV) const = 0;



  /////////////////////////////////////////////
  // Triangle data
  /////////////////////////////////////////////

  virtual CATULONG32 GetNbTriangles() const = 0;

  virtual CATBoolean AreTrianglesAlignedWithCATSurface() const = 0;

  // iTIdx should be between 0 and (GetNbTriangles() - 1)
  // oV1, oV2, oV3 returned should be between 0 and (GetNbVertices() - 1)
  virtual HRESULT GetTriangleCorners(CATULONG32 iTIdx, CATULONG32& oV1, CATULONG32& oV2, CATULONG32& oV3) const = 0;


  /////////////////////////////////////////////
  // CATVertex data 
  /////////////////////////////////////////////

  virtual CATBoolean AreCATVertexIndicesAvailable() const = 0;

  // oVIdx returned should be between 0 and (GetNbVertices() - 1)
  virtual HRESULT GetIndexAtCATVertex(CATVertex& iVertex, CATULONG32& oVIdx) const = 0;



  /////////////////////////////////////////////
  // CATEdge data 
  /////////////////////////////////////////////

  virtual CATULONG32 GetNbVerticesInEdge(CATEdge& iEdge) const = 0;

  // iEVIdx should be between 0 and (GetNbVerticesInEdge(iEdge) - 1)
  // oVIdx returned should be between 0 and (GetNbVertices() - 1)
  // The sequence should be aligned along the CATEdge direction
  virtual HRESULT GetIndexAtEdgeVertex(CATEdge& iEdge, CATULONG32 iEVIdx, CATULONG32& oVIdx) const = 0;
  virtual HRESULT GetEdgeVertexIndices(CATEdge& iEdge, CATListOfULONG32& oEdgeVertexIndices)const=0;

  virtual CATBoolean AreCurveParamsAvailable() const = 0;

  // iEVIdx should be between 0 and (GetNbVerticesInEdge(iEdge) - 1)
  // The sequence should be aligned along the CATEdge direction
  virtual HRESULT GetCurveParamAtEdgeVertex(CATEdge& iEdge, CATULONG32 iEVIdx, double& oW) const = 0;

  virtual CATBoolean AreTangentsAvailable() const = 0;

  // iEVIdx should be between 0 and (GetNbVerticesInEdge(iEdge) - 1)
  // The sequence should be aligned along the CATEdge direction
  virtual HRESULT GetTangentAtEdgeVertex(CATEdge& iEdge, CATULONG32 iEVIdx, double& oX, double& oY, double& oZ) const = 0;
  
  /////////////////////////////////////////////
  // CATEdge data 
  /////////////////////////////////////////////

  // should return true if and only if ParamSubdivision is available for all edges
  virtual CATBoolean IsCrvParamSubdivisionAvailable() const = 0;

  // should return true if ParamSubdivision is available for given edge
  virtual CATBoolean IsCrvParamSubdivisionAvailableForEdge(CATEdge& iEdge) const;

  // Get edge curve params in the form of compressed subdivision 
  virtual HRESULT GetCrvParamSubdivisionForEdge(CATEdge& iEdge, CATCGMUVParamSubdivision1D& oParamSubdivision) const = 0;
  
  ////all data (perfo)
  ////edge curve
  //virtual HRESULT GetCrvMeshForEdge(CATEdge& iEdge, CATCGMUVFaceMeshCurveBasicItf*& oCurveMesh)const=0;
  //
  ////mesh, oNbVertices=oNbBorderVertices+oNbInternalVertices, Triangles Buffer refers to vertices using this order
  ////if no distinctions between border vertices and internal vertices, all vertices are considered as internal vertices
  //virtual HRESULT GetMeshTopology(
  //                    CATULONG32& oNbTriangles, CATULONG32& oNbBorderVertices, CATULONG32& oNbInternalVertices,
  //                    CATBoolean iGetTriangles, const CATULONG32*& oTriangles,CATBoolean& oTrAlignedWithSurface,
  //                    CATBoolean& oReleaseAlloc) const {return E_FAIL;}

  //// iEdgeMeshFetcher needs to be passed only if you need border positions, i.e. if iGetBorderPositions is passed TRUE
  //// Otherwise, pass iEdgeMeshFetcher as NULL
  //virtual HRESULT GetMeshGeometry(
  //                    const CATCGMUVEdgeMeshFetcher* iEdgeMeshFetcher,
  //                    CATBoolean iGetBorderPositions, CATULONG32& oNbBorderPositions, const double*& oBorderPositions,
  //                    CATBoolean iGetBorderNormals, CATULONG32& oNbBorderNormals, const double*& oBorderNormals, 
  //                    CATBoolean iGetBorderUVs, CATULONG32& oNbBorderUVs, const double*& oBorderUVs, 
  //                    CATBoolean iGetInternalPositions, CATULONG32& oNbInternalPositions, const double*& oInternalPositions,
  //                    CATBoolean iGetInternalNormals, CATULONG32& oNbInternalNormals, const double*& oInternalNormals, 
  //                    CATBoolean iGetInternalUVs, CATULONG32& oNbInternalUVs, const double*& oInternalUVs, 
  //                    CATBoolean& oReleaseAlloc) const {return E_FAIL;}
    

public:

  /////////////////////////////////////////////
  // Not to be implemented by derived class
  /////////////////////////////////////////////

  // iAlignWithCATSurface : TRUE (Align with CATSurface), FALSE (Align with CATFace)
  // iTIdx should be between 0 and (GetNbTriangles() - 1)
  // oV1, oV2, oV3 returned should be between 0 and (GetNbVertices() - 1)
  HRESULT GetOrientedTriangleCorners(
                          CATBoolean iAlignWithCATSurface,
                          CATULONG32 iTIdx, 
                          CATULONG32& oV1, 
                          CATULONG32& oV2, 
                          CATULONG32& oV3) const;

  virtual HRESULT CheckMeshCorrectness() const;

  virtual void Dump() const;

protected:

  // iAlignWithCATSurface : TRUE (Align with CATSurface), FALSE (Align with CATFace)
  CATBoolean IsTriangleReversalNeeded(CATBoolean iAlignWithCATSurface) const;

  CATBoolean IsFaceOrientationNegative() const;
};

#endif 

