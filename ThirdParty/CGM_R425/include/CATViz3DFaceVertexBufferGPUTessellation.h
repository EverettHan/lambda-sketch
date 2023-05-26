// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATViz3DFaceVertexBufferGPUTessellation.h
// Header definition of CATViz3DFaceVertexBufferGPUTessellation
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2012  Creation: Code generated by the CAA wizard  tzw
//===================================================================
#ifndef CATViz3DFaceVertexBufferGPUTessellation_H
#define CATViz3DFaceVertexBufferGPUTessellation_H

#include "SGInfra.h"
#include "CATViz3DFaceVertexBuffer.h"

//-----------------------------------------------------------------------

template <class Buffer,class MutableBuffer>
class l_CATVizVertexBufferEditHelperSpec;

class CATViz3DFaceMutableVertexBufferGPUTessellation;

class ExportedBySGInfra CATViz3DFaceVertexBufferGPUTessellation: public CATViz3DFaceVertexBuffer
{
  friend class l_CATVizVertexBufferEditHelperSpec<CATViz3DFaceVertexBufferGPUTessellation,CATViz3DFaceMutableVertexBufferGPUTessellation>;
public:

  /** @nodoc */
  CATViz3DFaceVertexBufferGPUTessellation(const CATViz3DFaceVertexBufferGPUTessellation & iSource);

  /** @nodoc */
  virtual unsigned int GetNumberOfBarTangents() const;

  /** @nodoc */ 
  virtual float const *GetBarTangent1ReadOnly() const;
  /** @nodoc */ 
  virtual float const *GetBarTangent2ReadOnly() const;

  /** @nodoc */
  virtual int HasBarTangents() const;

  virtual void EmptyVBO(unsigned int& newVBOCreation);

  /** @nodoc */
  virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);


protected:
  /** @nodoc */
  CATViz3DFaceVertexBufferGPUTessellation();

  /** @nodoc */
  CATViz3DFaceVertexBufferGPUTessellation& operator=(const CATViz3DFaceVertexBufferGPUTessellation & iSource);

  /** @nodoc */
  CATViz3DFaceVertexBufferGPUTessellation (unsigned int nbVertices, unsigned int nbNormals, float *vertices, float *normals = NULL, float *textures = NULL, const int textureFormat = 0, float *uv = NULL, float *tanBinorm = NULL, unsigned int iAllocMode = ALLOCATE_VERTICES | ALLOCATE_NORMALS | ALLOCATE_TEXTURES);

  /** @nodoc */
  virtual HRESULT Allocate(unsigned int nbVertices,unsigned int nbNormals, int hasTextures, int textureFormat, int hasUV, int hasTanBinorm, int clear = 1);
  /** @nodoc */
  virtual HRESULT EnsureCapacity(unsigned int nbVertices, unsigned int nbNormals, int hasTextures, int textureFormat, int hasUV, int hasTanBinorm);

  /** @nodoc */
  virtual float *GetBarTangent1() const;
  /** @nodoc */
  virtual float *GetBarTangent2() const;
  
  /** @nodoc */
  virtual void Empty();
  

  virtual l_CATVizVertexBufferEditHelper* GetEditHelper_Impl();

  void Swap(CATViz3DFaceVertexBufferGPUTessellation* iBuffer);
  
protected:

  virtual ~CATViz3DFaceVertexBufferGPUTessellation ();

protected:
  float * _edgeTangents;
};

//-----------------------------------------------------------------------

class ExportedBySGInfra CATViz3DFaceMutableVertexBufferGPUTessellation: public CATViz3DFaceVertexBufferGPUTessellation
{
public:
  CATViz3DFaceMutableVertexBufferGPUTessellation();
  
  /** @nodoc */
  CATViz3DFaceMutableVertexBufferGPUTessellation(const CATViz3DFaceVertexBufferGPUTessellation & iSource);

  /** @nodoc */
  CATViz3DFaceMutableVertexBufferGPUTessellation& operator=(const CATViz3DFaceVertexBufferGPUTessellation & iSource);

  /** @nodoc */
  CATViz3DFaceMutableVertexBufferGPUTessellation (unsigned int nbVertices, unsigned int nbNormals, float *vertices, float *normals = NULL, float *textures = NULL, const int textureFormat = 0, float *uv = NULL, float *tanBinorm = NULL, unsigned int iAllocMode = ALLOCATE_VERTICES | ALLOCATE_NORMALS | ALLOCATE_TEXTURES);
  
  inline void Swap(CATViz3DFaceMutableVertexBufferGPUTessellation* iBuffer){CATViz3DFaceVertexBufferGPUTessellation::Swap(iBuffer);}

protected:
  virtual l_CATVizVertexBufferEditHelper* GetEditHelper_Impl();
  virtual ~CATViz3DFaceMutableVertexBufferGPUTessellation() = default;
};

#endif
