#ifndef CATCGMUVFaceMeshBuffersItf2_H
#define CATCGMUVFaceMeshBuffersItf2_H

#include "ExportedByTessellateCommon.h"

#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATCGMUVAbstractTopo.h"

class CATCGMUVFaceMeshCurveBuffersItf2;
class CATCGMUVEdgeMeshFetcher;
class CATCGMUVFaceEdgesIter2;
class CATCGMUVFaceFullVerticesIter2;
class CATCGMUVFaceMeshCurveBuffersIter2;

class CATCGMTessellatePointIter;
class CATCGMTessellateTrianIter;
class CATCGMTessellateFaceEdgeIter;

class CATMathPolyBuffers;

class ExportedByTessellateCommon CATCGMUVFaceMeshBuffersItf2
{
public:
  virtual ~CATCGMUVFaceMeshBuffersItf2();
public:

  // returns iterator for edges underlying the face in question
  // returns S_FALSE and NULL, if no edges are present in the face (which should normally never happen)
  virtual HRESULT GetEdges(CATCGMUVFaceEdgesIter2*& oIter) const = 0;

  // returns iterator for full vertices underlying the face in question
  // returns S_FALSE and NULL, if no full vertices are present in the face
  virtual HRESULT GetFullVertices(CATCGMUVFaceFullVerticesIter2*& oIter) const = 0;

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

  virtual CATCGMUVFaceMeshCurveBuffersIter2* GetFaceCurveDataIterator() const = 0;

  /////////////////////////////////////////////
  // Buffers
  /////////////////////////////////////////////

  virtual HRESULT GetCrvMeshForEdge(CATUVEdgeHandle iEdge, CATCGMUVFaceMeshCurveBuffersItf2*& oCurveMesh )const = 0;
  
  // mesh, oNbVertices=oNbBorderVertices+oNbInternalVertices, Triangles Buffer refers to vertices using this order
  // if no distinctions between border vertices and internal vertices, all vertices are considered as internal vertices
  //
  // oTrAlignedWithSurface
  //    TRUE: Means that triangles are aligned with surface orientation
  //    FALSE: Means that triangles are aligned with face orientation 
  //          (which may or may not be same as surface orientation depending on the face's orientation w.r.t. surface)
  virtual HRESULT GetMeshTopology(
                      CATULONG32& oNbTriangles, CATULONG32& oNbBorderVertices, CATULONG32& oNbInternalVertices,
                      CATBoolean iGetTriangles, const CATULONG32*& oTriangles,CATBoolean& oTrAlignedWithSurface,
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
	virtual HRESULT GetPolyBuffers(const CATMathPolyBuffers* &oFacePolyBuffers) const;

  /////////////////////////////////////////////
  // Iterators
  /////////////////////////////////////////////

  virtual HRESULT GetMeshIterators(
                      CATCGMTessellatePointIter*& oPointIter,
                      CATCGMTessellateTrianIter*& oTrianIter,
                      CATCGMTessellateFaceEdgeIter*& oFaceEdgeIter) const = 0;
};

#endif 

