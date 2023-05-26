// COPYRIGHT DASSAULT SYSTEMES 2007

#ifndef CATVizMultiTextureVertexBuffer_H
#define CATVizMultiTextureVertexBuffer_H

#include "SGInfra.h"
#include "CATViz3DFaceVertexBuffer.h"
#include "CATVisTextureCoordinateSet.h"
#include "list.h"


template <class Buffer,class MutableBuffer>
class l_CATVizVertexBufferEditHelperSpec;

class CATVizMultiTextureMutableVertexBuffer;

/** @nodoc
 *  Legacy class to manage multi-texturing.
 *  Since R419, multi_texturing is available in the root class CATViz3DFaceVertexBuffer,
 *  so please prefer the new API, as this class will not be updated anymore.
 *  Besides, CGR persistancy is not available.
 */
class ExportedBySGInfra CATVizMultiTextureVertexBuffer : public CATViz3DFaceVertexBuffer
{
  friend class l_CATVizVertexBufferEditHelperSpec<CATVizMultiTextureVertexBuffer,CATVizMultiTextureMutableVertexBuffer>;
public:

  /** @nodoc */
  CATVizMultiTextureVertexBuffer();

  /** @nodoc */
  virtual float const* GetTexturesReadOnly() const;

  /** @nodoc */
  virtual unsigned int GetNumberOfTextures() const;

  /** @nodoc */
  virtual unsigned int GetNumberOfTextureCoordinates() const;

  /** @nodoc */
  virtual unsigned int GetNumberOfExtraTextureCoordinateSets() const;

  /** @nodoc */
  virtual CATVisTextureCoordinateSet const* GetExtraTextureCoordinateSetConst(const unsigned int iSetIndex) const;

protected:
  /** @nodoc */
  CATVizMultiTextureVertexBuffer (unsigned int nbVertices, unsigned int nbNormals, float *vertices, float *normals = NULL, float *textures = NULL, const int textureFormat = 0, float *uv = NULL, float *tanBinorm = NULL, unsigned int iAllocMode = ALLOCATE_VERTICES | ALLOCATE_NORMALS | ALLOCATE_TEXTURES);
  /** @nodoc */
  virtual HRESULT Allocate(unsigned int nbVertices,unsigned int nbNormals, int hasTextures, int textureFormat, int hasUV, int hasTanBinorm, int clear = 1);  
  
 /** 
  * @nodoc
  * Not implemented.
  */
  virtual HRESULT SetTextures(const float *iTextureCoordinates, const int iNbCoordinates, int iAllocMode);
  
  /** @nodoc */
  virtual float *GetTextures() const;

  /** @nodoc */
  virtual void Empty();

  virtual l_CATVizVertexBufferEditHelper* GetEditHelper_Impl();

  void Swap(CATVizMultiTextureVertexBuffer* iBuffer);

  /** @nodoc */
  virtual HRESULT AddTextureCoordinateSet(const CATVisTextureCoordinateSet* iSet);

  virtual ~CATVizMultiTextureVertexBuffer(); // calling delete not allowed
};

class ExportedBySGInfra CATVizMultiTextureMutableVertexBuffer : public CATVizMultiTextureVertexBuffer
{

public:

  /** @nodoc */
  CATVizMultiTextureMutableVertexBuffer();

  /** @nodoc */
  CATVizMultiTextureMutableVertexBuffer (unsigned int nbVertices, unsigned int nbNormals, float *vertices, float *normals = NULL, float *textures = NULL, const int textureFormat = 0, float *uv = NULL, float *tanBinorm = NULL, unsigned int iAllocMode = ALLOCATE_VERTICES | ALLOCATE_NORMALS | ALLOCATE_TEXTURES);

  /** @nodoc */
  inline void Swap(CATVizMultiTextureMutableVertexBuffer* iBuffer){CATVizMultiTextureVertexBuffer::Swap(iBuffer);}

protected:
  virtual l_CATVizVertexBufferEditHelper* GetEditHelper_Impl();
  virtual ~CATVizMultiTextureMutableVertexBuffer() = default;
};


#endif
