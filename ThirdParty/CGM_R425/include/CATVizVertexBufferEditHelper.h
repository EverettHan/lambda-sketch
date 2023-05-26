#ifndef _CATVizVertexBufferEditHelper_H_
#define _CATVizVertexBufferEditHelper_H_

#include "SGInfra.h"
#include "CATSysErrorDef.h"

class CATRep;
class CAT3DFaceGPEditHelper;
class CATVizVertexBuffer;
class l_CATVizVertexBufferEditHelper;
class CATVisTextureCoordinateSet;

enum VBEditAuthorization
{
  //OK, edition is possible
  eVBEditOK,
  //One mandatory parameter is NULL (either buffer or Rep, if ShareCount==1)
  eVBEditNullParams,
  //The given rep does not contain the VertexBuffer
  eVBEditWrongRep,
  //The vertex buffer is referenced in more than one graphic primitive
  eVBEditMultipleAggregation,
  //The face which reference the vertex buffer is referenced in more than one rep
  eVBEditFaceMultipleAggregation,
  //The SurfacicRep is stripped, therefore edition is impossible
  eVBEditStripped,
  //The vertex buffer is currently in Edition in a EditHelper Instance (could be in a CAT3DFaceGPEditHelper)
  eVBEditInEdition,
  //Generic error, should not be possible to get this value
  eVBEditError
};

class ExportedBySGInfra CATVizVertexBufferEditHelper
{
  friend class CAT3DFaceGPEditHelper;
public:

  CATVizVertexBufferEditHelper();

  ~CATVizVertexBufferEditHelper();

  static VBEditAuthorization IsEditionPossible(CATVizVertexBuffer* iBuffer,CATRep* iCtx);
  /**
   * @nodoc
   * Support, CAT3DCustomRep, CATSurfacicRep and CATVizVertexBufferRep
   */
  HRESULT Reset(CATVizVertexBuffer* ,CATRep* iCtx);

  HRESULT Allocate(unsigned int nbVertices,unsigned int nbNormals, int hasTextures, int textureFormat, int hasUV, int hasTanBinorm, int clear = 1);
  
  HRESULT EnsureCapacity(unsigned int nbVertices, unsigned int nbNormals, int hasTextures, int textureFormat, int hasUV, int hasTanBinorm);

  HRESULT SetTextures(const float *iTextureCoordinates, const int iNbCoordinates);

  HRESULT SetUV(const float *iUV);

  void Empty();

  unsigned int GetNumberOfVertices() const;

  unsigned int GetNumberOfNormals() const;

  unsigned int GetNumberOfTextures() const;

  unsigned int GetNumberOfTextureCoordinates() const;

  unsigned int GetNumberOfUV() const;

  unsigned int GetNumberOfTangents() const;

  unsigned int GetNumberOfBinormals() const;

  float *GetVertices() const;

  float *GetNormals() const;

  float *GetTextures() const;

  float *GetUV() const;

  float *GetTangents() const;

  float *GetBinormals() const;

  float *GetBarTangent1() const;

  float *GetBarTangent2() const;

  CATVizVertexBuffer* GetBuffer() const;
  
  HRESULT AddTextureCoordinateSet(const CATVisTextureCoordinateSet* iSet);

  unsigned int GetNumberOfExtraTextureCoordinateSets() const;
  
  CATVisTextureCoordinateSet* GetExtraTextureCoordinateSet(const unsigned int iSetIndex) const;
  
  CATVisTextureCoordinateSet* GetTextureCoordinateSet(const CATUnicodeString& iIdentifier) const;

protected:

  static l_CATVizVertexBufferEditHelper* l_GetImplForFaceEditHelper(CATVizVertexBuffer*);

  l_CATVizVertexBufferEditHelper* m_Impl;
  CATRep*          m_CurrentContext;

private:

  CATVizVertexBufferEditHelper(CATVizVertexBufferEditHelper const&);
  CATVizVertexBufferEditHelper& operator=(CATVizVertexBufferEditHelper const&);

#ifndef _AIX_SOURCE
  static void* operator new(size_t);
  static void* operator new[](size_t);
  static void* operator new(size_t, void*);
  static void* operator new[](size_t, void*);

  static void  operator delete(void*);
  static void  operator delete[](void*);
  static void  operator delete(void*,void*);
  static void  operator delete[](void*,void*);
#endif
};

#endif
