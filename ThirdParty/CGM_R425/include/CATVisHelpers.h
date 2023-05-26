// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATVisHelpers.h
// Header definition of CATVisHelpers
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// September 2014 Creation: jxo
//===================================================================
#ifndef CATVisHelpers_H
#define CATVisHelpers_H

// ExportedBy
#include "PolyVizUtils.h"

// Visu
class CAT3DFaceGP;
class CAT3DCylinderGP;
class CAT3DCurvedPipeGP;
class CATViz3DFace;
class CAT3DLineGP;
class CAT3DEdgeGP;
class CATViz3DLine;
class CATViz3DEdge;
class CAT3DBoundingGP;
class CATGraphicPrimitive;
class CAT3DMarkerGP;
class CATViz3DMarker;
class CAT3DLineGPWithCrvParams;
class CAT3DEdgeGPWithCrvParams;
class CATVizVertexBuffer;
class CATVizVertexBufferEditHelper;
class CATRep;

// System
#include "CATErrorDef.h"
#include "CATIAV5Level.h"
#ifdef CATIAR417
#define POLYSGTIGHTNESS
#endif

#include "CATUnicodeString.h"

class ExportedByPolyVizUtils CATVisHelpers
{
public:

  static void Get(CAT3DFaceGP & iGP, 
                  int          * oAllocate,
                  float const ** oVertices,
                  int          * oVerticesArraySize,
                  float const ** oNormals,
                  int          * oNormalsArraySize,
                  int   const ** oTriangleIndices,
                  int          * oNbTriangle,
                  int   const ** oTriangleStripIndices,
                  int          * oNbTriangleStrip,
                  int   const ** oNbVertexPerTriangleStrip,
                  int   const ** oTriangleFanIndices,
                  int          * oNbTriangleFan,
                  int   const ** oNbVertexPerTriangleFan);
  static void GetTextureCoordinatesReadOnly(CAT3DFaceGP & iGP,
                                            float const ** oTextureCoord);
  static void Get(CAT3DBoundingGP & iGP, 
                  int          * oAllocate,
                  float const ** oVertices,
                  int          * oVerticesArraySize,
                  float const ** oNormals,
                  int          * oNormalsArraySize,
                  int   const ** oTriangleIndices,
                  int          * oNbTriangle,
                  int   const ** oTriangleStripIndices,
                  int          * oNbTriangleStrip,
                  int   const ** oNbVertexPerTriangleStrip,
                  int   const ** oTriangleFanIndices,
                  int          * oNbTriangleFan,
                  int   const ** oNbVertexPerTriangleFan);
  static void GetUV(CAT3DBoundingGP & iGP, 
                    int          * oAllocate,
                    float const ** oUV,
                    int          * oUVArraySize);

  static void Get(CAT3DCylinderGP & iGP, 
                  int          * oAllocate,
                  float const ** oVertices,
                  int          * oVerticesArraySize,
                  float const ** oNormals,
                  int          * oNormalsArraySize,
                  int   const ** oTriangleIndices,
                  int          * oNbTriangle,
                  int   const ** oTriangleStripIndices,
                  int          * oNbTriangleStrip,
                  int   const ** oNbVertexPerTriangleStrip,
                  int   const ** oTriangleFanIndices,
                  int          * oNbTriangleFan,
                  int   const ** oNbVertexPerTriangleFan);

  static void Get(CAT3DCurvedPipeGP & iGP, 
                  int          * oAllocate,
                  float const ** oVertices,
                  int          * oVerticesArraySize,
                  float const ** oNormals,
                  int          * oNormalsArraySize,
                  int   const ** oTriangleIndices,
                  int          * oNbTriangle,
                  int   const ** oTriangleStripIndices,
                  int          * oNbTriangleStrip,
                  int   const ** oNbVertexPerTriangleStrip,
                  int   const ** oTriangleFanIndices,
                  int          * oNbTriangleFan,
                  int   const ** oNbVertexPerTriangleFan);
  static void SetVertexBuffer(CAT3DFaceGP & iGP, CATVizVertexBuffer & iVizVertexBuffer, CATRep * iContext = 0);

  static float const * GetNormal(CATViz3DFace & iFace);
  static void Get(CATViz3DFace & iFace,
                  unsigned int const * & oTriangleIndices,
                  unsigned int         & oNbTriangle,
                  unsigned int const * & oTriangleStripIndices,
                  unsigned int         & oNbTriangleStrip,
                  unsigned int const * & oNbVertexPerTriangleStrip,
                  unsigned int const * & oTriangleFanIndices,
                  unsigned int         & oNbTriangleFan,
                  unsigned int const * & oNbVertexPerTriangleFan,
                  float        const * & oPlanarNormal);

  static void Get(CAT3DLineGP & iLine, float const**oPoints, int *oNbPoints,int *oLineType);
  static void Get(CAT3DEdgeGP & iEdge, CAT3DBoundingGP **oFref1,CAT3DBoundingGP **oFref2,
                  float const**oVerticesFref1,int const**oIndices,int *oIndicesSize);
  static HRESULT GetTangents(CAT3DEdgeGP & iE, float const**tangents);
  static HRESULT GetCrvParams(CAT3DEdgeGP & iB, float const**oCrvParams);
  static void Get(const CATViz3DLine & iLine, float const**oPoints, unsigned int *oNbPoints, unsigned int *oLineType);
  // indexType should be CATVizIndexType*
  static void Get(CATViz3DEdge & iEdge, void const* & oIndices, unsigned int & oIndicesSize, void * indexType, int unpack = 1);

  // oSymbol should be CATSymbolType*
  static void Get (CAT3DMarkerGP & iMarker, const float **oPoints, int *oNbPoint, void * oSymbol);
  static void Get (CATViz3DMarker & iMarker, const float **oPoints, int *oNbPoint, void * oSymbol);

  static HRESULT GetTangents(CAT3DLineGPWithCrvParams & iB, float const**tangents);
  static HRESULT GetCrvParams(CAT3DLineGPWithCrvParams & iB, float const**oCrvParams);
  static HRESULT GetTangents(CAT3DEdgeGPWithCrvParams & iB, float const**tangents);
  static HRESULT GetCrvParams(CAT3DEdgeGPWithCrvParams & iB, float const**oCrvParams);
  static HRESULT SetTangents(CAT3DLineGPWithCrvParams & iGP, CATRep * iContext, float * tangents, int copy);
  static HRESULT SetTangents(CAT3DEdgeGPWithCrvParams & iGP, CATRep * iContext, float * tangents, int copy);


  // Read only
  static float const * GetVertices(CATVizVertexBuffer & iB);
  static float const * GetNormals(CATVizVertexBuffer & iB);
  static float const * GetTextures(CATVizVertexBuffer & iB, int & oDim, const CATUnicodeString& identifier = "DEFAULT_TC_SET");
  static float const * GetTangents(CATVizVertexBuffer & iB);
  static float const * GetUV(CATVizVertexBuffer & iB);
  static float const * GetBinormals(CATVizVertexBuffer & iB);

  // Read/write
  static HRESULT Allocate(CATVizVertexBuffer & iB, CATRep * iContext, unsigned int nbVertices,unsigned int nbNormals, int hasTextures, int textureFormat, int hasUV, int hasTanBinorm, int clear = 1);
  static float * GetVertices(CATVizVertexBuffer & iB, CATRep * iContext);
  static float * GetNormals(CATVizVertexBuffer & iB, CATRep * iContext);
  static float * GetTextures(CATVizVertexBuffer & iB, CATRep * iContext, int& oDim, const CATUnicodeString * identifier);
  static float * GetUV(CATVizVertexBuffer & iB, CATRep * iContext);
  static float * GetTangents(CATVizVertexBuffer & iB, CATRep * iContext);
  static float * GetBinormals(CATVizVertexBuffer & iB, CATRep * iContext);
  // To use one predefined helper for all calls
  static HRESULT Allocate(CATVizVertexBuffer & iB, CATVizVertexBufferEditHelper * helper, unsigned int nbVertices,unsigned int nbNormals, int hasTextures, int textureFormat, int hasUV, int hasTanBinorm, int clear = 1);
  static float * GetVertices(CATVizVertexBuffer & iB, CATVizVertexBufferEditHelper * helper);
  static float * GetNormals(CATVizVertexBuffer & iB, CATVizVertexBufferEditHelper * helper);
  static float * GetTextures(CATVizVertexBuffer & iB, CATVizVertexBufferEditHelper * helper, int& oDim, const CATUnicodeString* identifier);
  static float * GetUV(CATVizVertexBuffer & iB, CATVizVertexBufferEditHelper * helper);
  static float * GetTangents(CATVizVertexBuffer & iB, CATVizVertexBufferEditHelper * helper);
  static float * GetBinormals(CATVizVertexBuffer & iB, CATVizVertexBufferEditHelper * helper);

protected:
  CATVisHelpers(){}
  ~CATVisHelpers(){}
};

#endif

