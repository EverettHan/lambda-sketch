#ifndef CATCGMUVFaceMeshBuffersItf_H
#define CATCGMUVFaceMeshBuffersItf_H

#include "ExportedByTessellateCommon.h"

#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATFace;
class CATEdge;
class CATVertex;

class CATCGMUVFaceMeshCurveBuffersItf;
class CATCGMUVEdgeMeshFetcher;
class CATCGMUVFaceEdgesIter;
class CATCGMUVFaceFullVerticesIter;
class CATCGMUVFaceMeshCurveBuffersIter;

class CATMathPolyBuffers;

class ExportedByTessellateCommon CATCGMUVFaceMeshBuffersItf
{
public:
  virtual ~CATCGMUVFaceMeshBuffersItf();

public:
  virtual HRESULT BeginTransaction() const = 0;
  virtual HRESULT EndTransaction() const = 0;

public:

  virtual CATFace& GetFace() const = 0;

  // returns iterator for edges underlying the face in question
  // returns S_FALSE and NULL, if no edges are present in the face (which should normally never happen)
  virtual HRESULT GetEdges(CATCGMUVFaceEdgesIter*& oIter) const = 0;

  // returns iterator for full vertices underlying the face in question
  // returns S_FALSE and NULL, if no full vertices are present in the face
  virtual HRESULT GetFullVertices(CATCGMUVFaceFullVerticesIter*& oIter) const = 0;

  /////////////////////////////////////////////
  // Counts and Info
  /////////////////////////////////////////////

  virtual CATULONG32 GetNbVertices() const = 0; 

  virtual CATULONG32 GetNbTriangles() const = 0;

  virtual CATBoolean AreCoordsAvailable() const = 0;

  virtual CATBoolean AreNormalsAvailable() const = 0;

  virtual CATBoolean AreSurfParamsAvailable() const = 0;

  /////////////////////////////////////////////
  // Face Curve Data
  /////////////////////////////////////////////

  virtual CATCGMUVFaceMeshCurveBuffersIter* GetFaceCurveDataIterator() const = 0;

  /////////////////////////////////////////////
  // Buffers
  /////////////////////////////////////////////

  virtual HRESULT GetCrvMeshForEdge(CATEdge& iEdge, CATCGMUVFaceMeshCurveBuffersItf*& oCurveMesh )const = 0;
  
  // mesh, oNbVertices=oNbBorderVertices+oNbInternalVertices, Triangles Buffer refers to vertices using this order
  // if no distinctions between border vertices and internal vertices, all vertices are considered as internal vertices
  //
  // oTrAlignedWithFace
  //    TRUE: Means that triangle orientation is same as face orientation
  //    FALSE: Means that triangle orientation is opposite face orientation
  virtual HRESULT GetMeshTopology(
                      CATULONG32& oNbTriangles, CATULONG32& oNbBorderVertices, CATULONG32& oNbInternalVertices,
                      CATBoolean iGetTriangles, const CATULONG32*& oTriangles, CATBoolean& oTrAlignedWithFace,
                      CATBoolean& oReleaseAlloc) const = 0;

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
                      CATBoolean& oReleaseAlloc) const = 0;

  // Get surface param subdivision information (only for internal points, not for border points)
  virtual HRESULT GetSurfParamSubdivision(
                      CATULONG32& oNbInternalUVs, 
                      const unsigned char*& oUSubdivBuffer, CATULONG32& oUSubdivBufferSize,
                      const unsigned char*& oVSubdivBuffer, CATULONG32& oVSubdivBufferSize,
                      const CATULONG32*& oIs, const CATULONG32*& oJs, const CATULONG32*& oLocations,
                      CATBoolean& oReleaseAlloc) const;

	// Get FacePolyBuffers
	// @param oFacePolyBuffers [out, IUnknown#Release] AWPD
	virtual HRESULT GetPolyBuffers(const CATMathPolyBuffers* &oFacePolyBuffers) const;
};

#endif 

