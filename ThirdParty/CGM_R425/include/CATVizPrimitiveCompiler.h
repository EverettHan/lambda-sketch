#ifndef _CATVizPrimitiveCompiler_
#define _CATVizPrimitiveCompiler_

#include "CATVisHashTable.h"

#include "CATVizPtrList.h"
#include "CATVizUV3DEdge.h"
#include "CATUVCompressedTangent.h"
#include "CATGraphicAttributeSet.h"

class CATViz3DFace;
class CATVizUV3DFace;
class CATVizPrimitiveSet;
class CATVizVertexBuffer;
class CATGraphicMaterial;

#ifndef WINDOWS_SOURCE
#define __forceinline inline
#endif

typedef struct _CATTangentInformation_
{
  float *tangent1;
  unsigned int index1;
  float *tangent2;
  unsigned int index2;

} CATTangentInformation;

struct CATFacesWithSameGASAndMaterial
{
  CATFacesWithSameGASAndMaterial()
  {
    mat = NULL;
    hasTextures = false;
    hasTangents = false;
    nbTexCoords = 0;
  }

  CATFacesWithSameGASAndMaterial(CATVizUV3DFace * iFace,
                                 CATGraphicAttributeSet iGas,
                                 CATGraphicMaterial * iMat = NULL)
  {
    faces.AddTail(iFace);
    gas = iGas;
    mat = iMat;
    hasTextures = false;
    hasTangents = false;
    nbTexCoords = 0;
  }

  CATGraphicAttributeSet gas;
  CATGraphicMaterial * mat;
  bool hasTextures;
  bool hasTangents;
  unsigned int nbTexCoords;
  CATVizPtrList<CATVizUV3DFace> faces;
};

struct CATEdgesWithSameGAS
{
  CATEdgesWithSameGAS() {}

  CATEdgesWithSameGAS(CATVizUV3DEdge * iEdge, CATGraphicAttributeSet iGas)
  {
    edges.AddTail(iEdge);
    gas = iGas;
  }

  CATGraphicAttributeSet gas;
  CATVizPtrList<CATVizUV3DEdge> edges;
};

class CATVizPrimitiveCompiler
{
public:
  CATVizPrimitiveCompiler();
  ~CATVizPrimitiveCompiler();

  __forceinline static CATVizPrimitiveCompiler *GetCompiler();

  // return the number of merged faces
  unsigned int BuildMergedFaces(CATVizPrimitiveSet *set, CATVizVertexBuffer *vb);

  CATVizUV3DFace * GetMergedFace(unsigned int i);
  CATGraphicAttributeSet GetGAS(unsigned int i);
  CATGraphicMaterial * GetMaterial(unsigned int i);

  // return the number of merged edges
  unsigned int BuildMergedEdges(CATVizPrimitiveSet *set, CATVizVertexBuffer *vb);

  CATVizUV3DEdge * GetMergedEdge(unsigned int i);
  CATGraphicAttributeSet GetEdgeGAS(unsigned int i);

  void ResetTemporaryBuffer();
  void Empty();

  //void Execute(CATRefinementEngine::MeshCB iCB, void * user_data);

  __forceinline unsigned int GetNumberOfTriangles();
  __forceinline unsigned int GetNumberOfVertices();
  __forceinline unsigned int *GetTriangles();
  __forceinline float *GetVertices();
  __forceinline float *GetNormals();
  __forceinline float *GetBarTangent1();
  __forceinline float *GetBarTangent2();
  
protected:

  void AddFace(CATViz3DFace * face, bool isPlanar);
  void AddEdge(CATVizUV3DEdge * edge);

  __forceinline void ReallocateVerticesArrays(unsigned int nbVertices);
  __forceinline void ReallocateTriangleArray(unsigned int nbTriangles);
  __forceinline void ReallocateEdgeIndicesArray(unsigned int nbIndices);
  //__forceinline void ReallocateTangentArray(unsigned int nbTangents, unsigned int nbTriangles);

  //++ temporary buffer data
  unsigned int _nbAllocatedVertices;
  unsigned int _currentVBSize; // actual size of the new VB
  float        * _vertices;
  float        * _normals;
  float        * _texCoords;
  float        * _tangents;
  float        * _binormals;
  float        * _edgeTangent1;
  float        * _edgeTangent2;

  // buffer for tangents of one edge
  unsigned int _tangentsBufferLength;
  float * _tangentsBuffer;

  // for merged faces
  unsigned int _nbAllocatedTriangles;
  unsigned int _nbTriangles;
  unsigned int * _triangles; // indices

  // for merged edges
  unsigned int _nbAllocatedEdgeIndices;
  unsigned int _nbEdgeIndices;
  unsigned int * _edgeIndices; // indices
  //--
  
  // the vertex buffer we are working on :
  // can be a VB owned by a face, or by a rep (in case of stripped mode)
  CATVizVertexBuffer * _currentVB;

  bool _currentHasTextures;
  bool _currentHasTangents;
  unsigned int _currentNbTexCoords;

  // mapping table used to merge vertices with same index
  unsigned int _allocatedMapping;
  CATVizPtrList<int> ** _mapping;

  CATTangentInformation * _tangentsInformationBuffer;
  unsigned int _tangentsInformationBufferLength;

  // data uv3dface
  //unsigned int _nbInternalTangents;

  //unsigned int _nbAllocatedInternalTangents;

  //CATUVCompressedTangent *_internalTangents;
  //unsigned int *_tangentIndices;
  //unsigned char *_coefs;
  //unsigned char *_centralCoefs;

  CATVizPtrList<CATVizUV3DEdge> _edges;

  // Merged Faces
  CATVizPtrList<CATFacesWithSameGASAndMaterial> _groupFaces;

  // Merged Edges
  CATVizPtrList<CATEdgesWithSameGAS> _groupEdges;
  
  static CATVizPrimitiveCompiler _theCompiler;
};

__forceinline void CATVizPrimitiveCompiler::ReallocateVerticesArrays(unsigned int nbVertices)
{
  if (nbVertices > _nbAllocatedVertices)
  {
    unsigned int sizeToAlloc = (_nbAllocatedVertices < 1024) ? 1024 : _nbAllocatedVertices;
    while (sizeToAlloc < nbVertices) sizeToAlloc *= 2;

    float * tmpf = (float *)realloc(_vertices, 3*sizeToAlloc*sizeof(float));
	if (tmpf) _vertices = tmpf; // static code analysis: 6308
    tmpf  = (float *)realloc(_normals,  3*sizeToAlloc*sizeof(float));
	if (tmpf) _normals = tmpf; // static code analysis: 6308

    tmpf = (float *)realloc(_texCoords, 3*sizeToAlloc*sizeof(float));
	if (tmpf) _texCoords = tmpf; // static code analysis: 6308
    tmpf  = (float *)realloc(_tangents,  3*sizeToAlloc*sizeof(float));
	if (tmpf) _tangents = tmpf; // static code analysis: 6308
    tmpf = (float *)realloc(_binormals, 3*sizeToAlloc*sizeof(float));
	if (tmpf) _binormals = tmpf; // static code analysis: 6308

    tmpf = (float *)realloc(_edgeTangent1, 3*sizeToAlloc*sizeof(float));
	if (tmpf) _edgeTangent1 = tmpf; // static code analysis: 6308
    tmpf = (float *)realloc(_edgeTangent2, 3*sizeToAlloc*sizeof(float));
	if (tmpf) _edgeTangent2 = tmpf; // static code analysis: 6308

    _nbAllocatedVertices = sizeToAlloc;
  }
}

__forceinline void CATVizPrimitiveCompiler::ReallocateTriangleArray(unsigned int nbTriangles)
{
  if (nbTriangles > _nbAllocatedTriangles)
  {
    unsigned int * tmp = (unsigned int *)realloc(_triangles, 3*nbTriangles*sizeof(unsigned int));
	if (tmp) _triangles = tmp; // static code analysis: 6308
    //_centralCoefs = (unsigned char *)realloc(_centralCoefs, nbTriangles*sizeof(unsigned char));
    _nbAllocatedTriangles = nbTriangles;
  }
}

__forceinline void CATVizPrimitiveCompiler::ReallocateEdgeIndicesArray(unsigned int nbIndices)
{
  if (nbIndices > _nbAllocatedEdgeIndices)
  {
    unsigned int * tmp = (unsigned int *)realloc(_edgeIndices, nbIndices*sizeof(unsigned int));
	if (tmp) _edgeIndices = tmp; // static code analysis: 6308
    _nbAllocatedEdgeIndices = nbIndices;
  }
}

/*
__forceinline void CATVizPrimitiveCompiler::ReallocateTangentArray(unsigned int nbTangents, unsigned int nbTriangles)
{
  if (nbTangents > _nbAllocatedInternalTangents)
  {
    _internalTangents = (CATUVCompressedTangent *)realloc(_internalTangents, 2*nbTangents*sizeof(CATUVCompressedTangent));
    _tangentIndices = (unsigned int *)realloc(_tangentIndices, 2*nbTangents*sizeof(unsigned int));
    _coefs = (unsigned char *)realloc(_coefs, nbTangents*sizeof(unsigned char));

    _nbAllocatedInternalTangents = nbTangents;
  }
}
*/
__forceinline CATVizPrimitiveCompiler *CATVizPrimitiveCompiler::GetCompiler()
{
  return &_theCompiler;
}

__forceinline unsigned int CATVizPrimitiveCompiler::GetNumberOfTriangles()
{
  return _nbTriangles;
}

__forceinline unsigned int *CATVizPrimitiveCompiler::GetTriangles()
{
  return _triangles;
}

__forceinline unsigned int CATVizPrimitiveCompiler::GetNumberOfVertices()
{
  return _currentVBSize;
}


__forceinline float *CATVizPrimitiveCompiler::GetVertices()
{
  return _vertices;
}

__forceinline float *CATVizPrimitiveCompiler::GetNormals()
{
  return _normals;
}

__forceinline float *CATVizPrimitiveCompiler::GetBarTangent1()
{
  return _edgeTangent1;
}

__forceinline float *CATVizPrimitiveCompiler::GetBarTangent2()
{
  return _edgeTangent2;
}

#endif
