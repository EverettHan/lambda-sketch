/* COPYRIGHT DASSAULT SYSTEMES 2003 */

#ifndef CATViz3DFace_H
#define CATViz3DFace_H

#ifndef NULL
#define NULL 0
#endif 

#include "SGInfra.h"
#include "CATIAV5Level.h"
#include "IUnknown.h"

#include "CATVizIndexType.h"
#include "CATGraphicAttributeSet.h"
#include "CATVizPrimitive.h"
//#include "CATSupport.h"
#include "CATVizMacForMetaClass.h"
#include "CATBoolean.h"
#include "CATVisMacroForInterfaces.h"
#include "IVisSG3DFace.h"

class CATViz3DFaceIVisSG3DFaceBOAImpl;

class CATStreamer;
class CATRender;
class CATViz3DEdge;
class CATVizVertexBuffer;
class CATDL;

#define HAS_TRIANGLES      1
#define HAS_STRIPS         2
#define HAS_FANS           4
#define IS_PLANAR          8
#define BYTE_COMPRESSION   16
#define SHORT_COMPRESSION  32
#define INT_COMPRESSION    128
#define IS_PACKED          64
#define POOL_ALLOCATED     256
#define HAS_VERTEX_BUFFER  512

/**
* Class to create the graphic primitive of a 3D face.<br>
* <b>Role</b>: Class to describe the standard tessellation of a face.
* A face is made of triangles, triangle strips, and triangle fans.
* This is one of the most common encountered graphic primitive.<br>
*  Main Methods:<br>
*    Drawing and texturing.<br>
*    Retrieve the tessellation parameters.
*/

class CATViz3DFaceTrianglesIterator;
class CATViz3DFace;
class IVisSG3DFace;
class CATViz3DFaceIVisSG3DFaceBOAImpl;

class ExportedBySGInfra CATViz3DFace : public CATVizPrimitive
{
   friend class CATViz3DFaceTrianglesIterator;
   friend class SGCGRStreamerForCATViz3DFace;
   friend class SGCGRNodesFactoryA;

   CATVizDeclareClass;

public :
  CATVisDeclarePublicInterfaceAdhesion(CATViz3DFace, IVisSG3DFace, CATViz3DFaceIVisSG3DFaceBOAImpl);
   
  /** @nodoc */
  CATViz3DFace (void);

  /** @nodoc */
  CATViz3DFace (const CATViz3DFace & toCopy);
  
  /** @nodoc */
  CATViz3DFace (const unsigned int iTriangleIndices[],
                const unsigned int iNbTriangle,
                const unsigned int iTriangleStripIndices[],
                const unsigned int iNbTriangleStrip,
                const unsigned int iNbVertexPerTriangleStrip[],
                const unsigned int iTriangleFanIndices[],
                const unsigned int iNbTriangleFan,
                const unsigned int iNbVertexPerTriangleFan[],
                const float *      iPlanarNormal = NULL,
                CATBoolean         iVBExist = FALSE,
                const CATVizVertexBuffer * iVB = NULL);

  /** @nodoc */
  CATViz3DFace (const void *       iTriangleIndices,
                const unsigned int iNbTriangle,
                const void *       iTriangleStripIndices,
                const unsigned int iNbTriangleStrip,
                const unsigned int iNbVertexPerTriangleStrip[],
                const void *       iTriangleFanIndices,
                const unsigned int iNbTriangleFan,
                const unsigned int iNbVertexPerTriangleFan[],
                CATVizIndexType    iIndexType,
                const float *      iPlanarNormal = NULL,
                CATBoolean         iPacked = FALSE,
                CATBoolean         iVBExist = FALSE,
                const CATVizVertexBuffer * iVB = NULL);

  /** @nodoc */
  virtual CATVizPrimitive * Duplicate();

  /** @nodoc */
  virtual void Draw(CATRender &iRender);

  /** @nodoc */
  virtual int DetailCulling(CATRender *render);
  
  /** @nodoc */
  virtual void Stream(CATStreamer& oStr,int iSavetype=0);
  INLINE virtual unsigned char GetStreamId() const;

  /** @nodoc */
  virtual void UnStream(CATStreamer& iStr);

  INLINE void GetReadOnly ( void         const * & oTriangleIndices,
                            unsigned int         & oNbTriangle,
                            void         const * & oTriangleStripIndices,
                            unsigned int         & oNbTriangleStrip,
                            unsigned int const * & oNbVertexPerTriangleStrip,
                            void         const * & oTriangleFanIndices,
                            unsigned int         & oNbTriangleFan,
                            unsigned int const * & oNbVertexPerTriangleFan,
                            CATVizIndexType      & oIndexType,
                            int unpack = 1)const;

  INLINE void GetReadOnly ( unsigned int const * & oTriangleIndices,
                            unsigned int         & oNbTriangle,
                            unsigned int const * & oTriangleStripIndices,
                            unsigned int         & oNbTriangleStrip,
                            unsigned int const * & oNbVertexPerTriangleStrip,
                            unsigned int const * & oTriangleFanIndices,
                            unsigned int         & oNbTriangleFan,
                            unsigned int const * & oNbVertexPerTriangleFan,
                            float        const * & oPlanarNormal)const;

  /** @nodoc */
  INLINE int IsPacked() const;

  /** @nodoc */
  INLINE void Unpack();

  /** @nodoc */
  INLINE float const * GetNormalReadOnly() const;

  /** @nodoc */
  INLINE unsigned int GetNVert();

  /** @nodoc */
  INLINE CATBoolean HasVertexBuffer() const;

  /** @nodoc */
  INLINE CATVizVertexBuffer * GetVertexBuffer() const;

  /** @nodoc */
  void SetVertexBuffer(CATVizVertexBuffer * iVertexBuffer);

  /** @nodoc */
  HRESULT ConvertIndicesTo(CATVizIndexType iIndexType, int checkValidity = 1);

  /** @nodoc */
  CATVizIndexType CompressIndices();

  /** @nodoc */
  INLINE CATVizIndexType GetIndexType();

  /** @nodoc */
  virtual void Empty();

  /** @nodoc */
  virtual HRESULT GetBorderEdges(unsigned int & oNbEdges, CATViz3DEdge ** & oEdges);

  /** @nodoc */
  size_t Allocate( const unsigned int iNbTriangles,
                 void * &           oTriangleIndices,
                 const unsigned int iNbTriangleStrip,
                 const unsigned int iNbTriangleStripIndices,
                 unsigned int * &   oNbVertexPerTriangleStrip,
                 void * &           oTriangleStripIndices,
                 const unsigned int iNbTriangleFan,
                 const unsigned int iNbTriangleFanIndices,
                 unsigned int * &   oNbVertexPerTriangleFan,
                 void * &           oTriangleFanIndices,
                 const CATBoolean   iIsPlanar,
                 float * &          oPlanarNormal,
                 CATVizIndexType    iIndexType = CATVizUIntType,
                 CATBoolean         iPacked = FALSE,
                 CATBoolean         allocateOnPool = FALSE,
                 CATBoolean         iVBExist = FALSE,
                 CATVizVertexBuffer * iVB = NULL);

  /* Faster than calling GetMaxIndex() and GetMinIndex() */
  void GetIndicesRange(unsigned int & oMinIndex, unsigned int & oMaxIndex);

  /** @nodoc */
  unsigned int GetMaxIndex();

  /** @nodoc */
  unsigned int GetMinIndex();

  /** @nodoc */
  virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

  /** @nodoc */
  virtual unsigned int AddRef();
  virtual unsigned int Release();
  virtual unsigned int GetRefCount();

protected :

  void Swap(CATViz3DFace* iOther);

  /** @nodoc */
  virtual ~CATViz3DFace (void);    

  size_t GetBufferSize(const void *       iTriangleIndices,
                      const unsigned int iNbTriangles,
                      const void *       iTriangleStripIndices,
                      const unsigned int iNbTriangleStrip,
                      const unsigned int iNbVertexPerTriangleStrip[],
                      const void *       iTriangleFanIndices,
                      const unsigned int iNbTriangleFan,
                      const unsigned int iNbVertexPerTriangleFan[],
                      const float *      iPlanarNormal = NULL,
                      CATVizIndexType    iIndexType = CATVizUIntType,
                      CATBoolean         iPacked = FALSE,
                      CATBoolean         iVB     = FALSE);
  /** @nodoc */
  char * BuildBuffer( const void *       iTriangleIndices,
                      const unsigned int iNbTriangles,
                      const void *       iTriangleStripIndices,
                      const unsigned int iNbTriangleStrip,
                      const unsigned int iNbVertexPerTriangleStrip[],
                      const void *       iTriangleFanIndices,
                      const unsigned int iNbTriangleFan,
                      const unsigned int iNbVertexPerTriangleFan[],
                      const float *      iPlanarNormal = NULL,
                      CATVizIndexType    iIndexType = CATVizUIntType,
                      CATBoolean         iPacked = FALSE,
                      CATBoolean         allocateOnPool = FALSE,
                      CATBoolean         iVBExist = FALSE,
                      const CATVizVertexBuffer * iVB = NULL);

  /** @nodoc */

  char *_data;
private :

  void ReleaseBuffer();
  void EmptyGeometryBuffer();

  INLINE unsigned char* GetRefCountInData();
  INLINE void SetRefCountInData(unsigned char iRef);
};

class ExportedBySGInfra CATViz3DFaceTrianglesIterator
{
public :
   
   CATViz3DFaceTrianglesIterator(CATViz3DFace & iFace);
   virtual ~CATViz3DFaceTrianglesIterator();

   void SetVerticesIndicesAsPosInArray(int iOnOff);
   int  AreVerticesIndicesAsPosInArray();

   unsigned int GetNbTriangles();
   unsigned int GetTriangleIndex(unsigned int iIndex);
   void         SetTriangleIndex(unsigned int iIndex, unsigned int iValue);

   unsigned int GetNbStrips();
   unsigned int GetNbVerticesPerStrip(unsigned int iStripNum);
   unsigned int GetStripIndex(unsigned int iIndex);
   void         SetStripIndex(unsigned int iIndex, unsigned int iValue);

   unsigned int GetNbFans();
   unsigned int GetNbVerticesPerFan(unsigned int iFanNum);
   unsigned int GetFanIndex(unsigned int iIndex);
   void         SetFanIndex(unsigned int iIndex, unsigned int iValue);

   unsigned int GetNbIndices();
   unsigned int GetIndex(unsigned int iIndex);
   void         SetIndex(unsigned int iIndex, unsigned int iValue);

protected :

   void InitDataFromFace();
   void CheckIndexType(unsigned int iValue);

   void const*         _trianglesIndices;
   void const*         _stripIndices;
   void const*         _fanIndices;
   unsigned int        _nbTriangles;
   unsigned int        _nbStrips;
   unsigned int        _nbFans;
   CATVizIndexType     _indexType; /** @win64 fbq : 64-bit structure padding **/
   unsigned int const* _nbVerticesPerStrip;
   unsigned int const* _nbVerticesPerFan;

   unsigned int      _nbStripVertices;
   unsigned int      _nbFanVertices;

   CATViz3DFace &    _face;

   unsigned int      _isPacked:1;
   unsigned int      _verticesIndicesAsPosInArray:1;

private :

   CATViz3DFaceTrianglesIterator(const CATViz3DFaceTrianglesIterator &);
   CATViz3DFaceTrianglesIterator & operator = (const CATViz3DFaceTrianglesIterator &);
};


INLINE void CATViz3DFace::GetReadOnly(void         const * & oTriangleIndices,
                                      unsigned int         & oNbTriangle,
                                      void         const * & oTriangleStripIndices,
                                      unsigned int         & oNbTriangleStrip,
                                      unsigned int const * & oNbVertexPerTriangleStrip,
                                      void         const * & oTriangleFanIndices,
                                      unsigned int         & oNbTriangleFan,
                                      unsigned int const * & oNbVertexPerTriangleFan,
                                      CATVizIndexType   & oIndexType,
                                      int unpack)const
{
   if(_data)
   {
      
      if (unpack && (((unsigned int *)_data)[0] & IS_PACKED))
      {
        //UGLY
        ((CATViz3DFace*)this)->Unpack();
      }

      const unsigned int header = *((unsigned int *)_data);
      
      unsigned int sizeOfIndex = sizeof(unsigned int);
      
      if (header & INT_COMPRESSION)
      {
         oIndexType = CATVizUIntType;
      }
      else if (header & SHORT_COMPRESSION)
      {
         oIndexType = CATVizUShortType;
         sizeOfIndex = sizeof(unsigned short);
      }
      else if (header & BYTE_COMPRESSION)
      {
         oIndexType = CATVizUCharType;
         sizeOfIndex = sizeof(unsigned char);
      }
      
      char * cursor = &_data[sizeof(unsigned int)];
      
      // vertex buffer
      if (header & HAS_VERTEX_BUFFER)
      {
         cursor += sizeof(CATVizVertexBuffer *);
      }

      // planar normal
      if (header & IS_PLANAR)
      {
         cursor += 3*sizeof(float);
      }
      
      if((header & HAS_STRIPS) && (header & HAS_FANS))
      {
         // Strips and Fans (and triangles ?)
         if (header & HAS_TRIANGLES)
         {
            oNbTriangle = *((unsigned int *)cursor);
            cursor += sizeof(unsigned int);
         }
         else
         {
            oNbTriangle      = 0;
            oTriangleIndices = NULL;
         }
         
         oNbTriangleStrip = *((unsigned int *)cursor);
         cursor += sizeof(unsigned int);
         oNbTriangleFan = *((unsigned int *)cursor);
         cursor += sizeof(unsigned int);
         
         unsigned int jumpInFansIndices = *((unsigned int *)cursor);
         cursor += sizeof(unsigned int);
         
         oNbVertexPerTriangleStrip = (unsigned int *)cursor;
         cursor += oNbTriangleStrip*sizeof(unsigned int);
         
         oNbVertexPerTriangleFan = (unsigned int *)cursor;
         cursor += oNbTriangleFan*sizeof(unsigned int);
         
         if (header & HAS_TRIANGLES)
         {
            oTriangleIndices = cursor;
            cursor += oNbTriangle*3*sizeOfIndex;
         }
         
         oTriangleStripIndices = cursor;
         oTriangleFanIndices = &_data[jumpInFansIndices];
      }
      else if(header & HAS_STRIPS)
      {
         // Strips (and triangles ?)
         oTriangleFanIndices       = NULL;
         oNbTriangleFan            = 0;
         oNbVertexPerTriangleFan   = NULL;
         
         if (header & HAS_TRIANGLES)
         {
            oNbTriangle = *((unsigned int *)cursor);
            cursor += sizeof(unsigned int);
         }
         else
         {
            oNbTriangle      = 0;
            oTriangleIndices = NULL;
         }
         
         oNbTriangleStrip = *((unsigned int *)cursor);
         cursor += sizeof(unsigned int);
         
         oNbVertexPerTriangleStrip = (unsigned int *)cursor;
         cursor += oNbTriangleStrip*sizeof(unsigned int);
         
         if (header & HAS_TRIANGLES)
         {
            oTriangleIndices = cursor;
            cursor += oNbTriangle*3*sizeOfIndex;
         }
         
         oTriangleStripIndices = cursor;
      }
      else if(header & HAS_FANS)
      {
         // Fans (and triangles ?)
         oTriangleStripIndices     = NULL;
         oNbTriangleStrip          = 0;
         oNbVertexPerTriangleStrip = NULL;
         
         if (header & HAS_TRIANGLES)
         {
            oNbTriangle = *((unsigned int *)cursor);
            cursor += sizeof(unsigned int);
         }
         else
         {
            oNbTriangle      = 0;
            oTriangleIndices = NULL;
         }
         
         oNbTriangleFan = *((unsigned int *)cursor);
         cursor += sizeof(unsigned int);
         
         oNbVertexPerTriangleFan = (unsigned int *)cursor;
         cursor += oNbTriangleFan*sizeof(unsigned int);
         
         if (header & HAS_TRIANGLES)
         {
            oTriangleIndices = cursor;
            cursor += oNbTriangle*3*sizeOfIndex;
         }
         
         oTriangleFanIndices = cursor;
      }
      else if(header & HAS_TRIANGLES)
      {
         // Triangles only
         oTriangleStripIndices     = NULL;
         oNbTriangleStrip          = 0;
         oNbVertexPerTriangleStrip = NULL;
         oTriangleFanIndices       = NULL;
         oNbTriangleFan            = 0;
         oNbVertexPerTriangleFan   = NULL;
         
         oNbTriangle = *((unsigned int *)cursor);
         cursor += sizeof(unsigned int);
         
         oTriangleIndices = cursor;
         cursor += oNbTriangle*3*sizeOfIndex;
         
      }
      else
      {
         // Nothing
         oTriangleIndices           = NULL;
         oNbTriangle                = 0;
         oTriangleStripIndices      = NULL;
         oNbTriangleStrip           = 0;
         oNbVertexPerTriangleStrip  = NULL;
         oTriangleFanIndices        = NULL;
         oNbTriangleFan             = 0;
         oNbVertexPerTriangleFan    = NULL;
         oIndexType                 = CATVizUIntType;
      }
   }
   else
   {
      oTriangleIndices           = NULL;
      oNbTriangle                = 0;
      oTriangleStripIndices      = NULL;
      oNbTriangleStrip           = 0;
      oNbVertexPerTriangleStrip  = NULL;
      oTriangleFanIndices        = NULL;
      oNbTriangleFan             = 0;
      oNbVertexPerTriangleFan    = NULL;
      oIndexType                 = CATVizUIntType;
   }
}

// Optimized Get for CAT3DFaceGP
INLINE void CATViz3DFace::GetReadOnly ( unsigned int const * & oTriangleIndices,
                                        unsigned int         & oNbTriangle,
                                        unsigned int const * & oTriangleStripIndices,
                                        unsigned int         & oNbTriangleStrip,
                                        unsigned int const * & oNbVertexPerTriangleStrip,
                                        unsigned int const * & oTriangleFanIndices,
                                        unsigned int         & oNbTriangleFan,
                                        unsigned int const * & oNbVertexPerTriangleFan,
                                        float        const * & oPlanarNormal)const
{
   if(_data)
   {
      if (((unsigned int *)_data)[0] & IS_PACKED)
      {
         //UGLY
         ((CATViz3DFace*)this)->Unpack();
      }

      const unsigned int header = *((unsigned int *)_data);
      
      unsigned int sizeOfIndex = sizeof(unsigned int);
      
      // If we are not in integer mode, we convert the indices
      if(!(header & INT_COMPRESSION))
      {
         //UGLY
         ((CATViz3DFace*)this)->ConvertIndicesTo(CATVizUIntType, 0);
      }

      char * cursor = &_data[sizeof(unsigned int)];
      
      // vertex buffer
      if (header & HAS_VERTEX_BUFFER)
      {
         cursor += sizeof(CATVizVertexBuffer *);
      }

      // planar normal
      if (header & IS_PLANAR)
      {
         oPlanarNormal = (float *)cursor;
         cursor += 3*sizeof(float);
      }
      else
      {
         oPlanarNormal = NULL;
      }
      
      if((header & HAS_STRIPS) && (header & HAS_FANS))
      {
         // Strips and Fans (and triangles ?)
         if (header & HAS_TRIANGLES)
         {
            oNbTriangle = *((unsigned int *)cursor);
            cursor += sizeof(unsigned int);
         }
         else
         {
            oNbTriangle      = 0;
            oTriangleIndices = NULL;
         }
         
         oNbTriangleStrip = *((unsigned int *)cursor);
         cursor += sizeof(unsigned int);
         oNbTriangleFan = *((unsigned int *)cursor);
         cursor += sizeof(unsigned int);
         
         unsigned int jumpInFansIndices = *((unsigned int *)cursor);
         cursor += sizeof(unsigned int);
         
         oNbVertexPerTriangleStrip = (unsigned int *)cursor;
         cursor += oNbTriangleStrip*sizeof(unsigned int);
         
         oNbVertexPerTriangleFan = (unsigned int *)cursor;
         cursor += oNbTriangleFan*sizeof(unsigned int);
         
         if (header & HAS_TRIANGLES)
         {
            oTriangleIndices = (unsigned int *)cursor;
            cursor += oNbTriangle*3*sizeOfIndex;
         }
         
         oTriangleStripIndices = (unsigned int *)cursor;
         oTriangleFanIndices = (unsigned int *)&_data[jumpInFansIndices];
      }
      else if(header & HAS_STRIPS)
      {
         // Strips (and triangles ?)
         oTriangleFanIndices       = NULL;
         oNbTriangleFan            = 0;
         oNbVertexPerTriangleFan   = NULL;
         
         if (header & HAS_TRIANGLES)
         {
            oNbTriangle = *((unsigned int *)cursor);
            cursor += sizeof(unsigned int);
         }
         else
         {
            oNbTriangle      = 0;
            oTriangleIndices = NULL;
         }
         
         oNbTriangleStrip = *((unsigned int *)cursor);
         cursor += sizeof(unsigned int);
         
         oNbVertexPerTriangleStrip = (unsigned int *)cursor;
         cursor += oNbTriangleStrip*sizeof(unsigned int);
         
         if (header & HAS_TRIANGLES)
         {
            oTriangleIndices = (unsigned int *)cursor;
            cursor += oNbTriangle*3*sizeOfIndex;
         }
         
         oTriangleStripIndices = (unsigned int *)cursor;
      }
      else if(header & HAS_FANS)
      {
         // Fans (and triangles ?)
         oTriangleStripIndices     = NULL;
         oNbTriangleStrip          = 0;
         oNbVertexPerTriangleStrip = NULL;
         
         if (header & HAS_TRIANGLES)
         {
            oNbTriangle = *((unsigned int *)cursor);
            cursor += sizeof(unsigned int);
         }
         else
         {
            oNbTriangle      = 0;
            oTriangleIndices = NULL;
         }
         
         oNbTriangleFan = *((unsigned int *)cursor);
         cursor += sizeof(unsigned int);
         
         oNbVertexPerTriangleFan = (unsigned int *)cursor;
         cursor += oNbTriangleFan*sizeof(unsigned int);
         
         if (header & HAS_TRIANGLES)
         {
            oTriangleIndices = (unsigned int *)cursor;
            cursor += oNbTriangle*3*sizeOfIndex;
         }
         
         oTriangleFanIndices = (unsigned int *)cursor;
      }
      else if(header & HAS_TRIANGLES)
      {
         // Triangles only
         oTriangleStripIndices     = NULL;
         oNbTriangleStrip          = 0;
         oNbVertexPerTriangleStrip = NULL;
         oTriangleFanIndices       = NULL;
         oNbTriangleFan            = 0;
         oNbVertexPerTriangleFan   = NULL;
         
         oNbTriangle = *((unsigned int *)cursor);
         cursor += sizeof(unsigned int);
         
         oTriangleIndices = (unsigned int *)cursor;
         cursor += oNbTriangle*3*sizeOfIndex;
         
      }
      else
      {
         // Nothing
         oTriangleIndices           = NULL;
         oNbTriangle                = 0;
         oTriangleStripIndices      = NULL;
         oNbTriangleStrip           = 0;
         oNbVertexPerTriangleStrip  = NULL;
         oTriangleFanIndices        = NULL;
         oNbTriangleFan             = 0;
         oNbVertexPerTriangleFan    = NULL;
      }
   }
   else
   {
      oTriangleIndices           = NULL;
      oNbTriangle                = 0;
      oTriangleStripIndices      = NULL;
      oNbTriangleStrip           = 0;
      oNbVertexPerTriangleStrip  = NULL;
      oTriangleFanIndices        = NULL;
      oNbTriangleFan             = 0;
      oNbVertexPerTriangleFan    = NULL;
   }
}

INLINE int CATViz3DFace::IsPacked() const
{
   return (_data && (((unsigned int *)_data)[0] & IS_PACKED)) ? 1 : 0;
}

INLINE void CATViz3DFace::Unpack()
{
   if(!IsPacked()) return;
   CATVizIndexType indexType = GetIndexType();
   if (indexType == CATVizUCharType)
   {
      unsigned int maxIndex = GetMaxIndex();
      if (maxIndex*3 >= 256)
         ConvertIndicesTo(CATVizUShortType);
   }
   else if (indexType == CATVizUShortType)
   {
      unsigned int maxIndex = GetMaxIndex();
      if (maxIndex*3 >= 65536)
         ConvertIndicesTo(CATVizUIntType);
   }

//   ConvertIndicesTo(CATVizUShortType);
   void const* triIndex=NULL; 
   void const* stripIndex=NULL; 
   void const* fanIndex=NULL;
   unsigned int    triNum = 0, stripNum = 0, fanNum = 0;
   unsigned int const* numVertsInStrip=NULL;
   unsigned int const* numVertsInFan=NULL;
   
   GetReadOnly(triIndex,
               triNum,
               stripIndex,
               stripNum,
               numVertsInStrip,
               fanIndex,
               fanNum,
               numVertsInFan,
               indexType,0);
   
   
   //NC5 : Tightness : UGLY Cast to be able to convert the indices
   switch (indexType)
   {
      case CATVizUCharType:
      {
         unsigned char *indexData = (unsigned char *)triIndex;
         unsigned int i;
         for (i = 0 ; i <triNum*3 ; ++i)
         {
            *indexData *= 3;
            indexData++;
         }
         
         indexData = (unsigned char *)stripIndex;
         for (i = 0 ; i < stripNum ; ++i)
         {
            for (unsigned int j = 0 ; j < numVertsInStrip[i] ; ++j)
            {
               *indexData *= 3;
               indexData++;
            }
         }

         indexData = (unsigned char *)fanIndex;
         
         for (i = 0 ; i < fanNum ; ++i)
         {
            for (unsigned int j = 0 ; j < numVertsInFan[i] ; ++j)
            {
               *indexData *= 3;
               indexData++;
            }
         }
      }
      break;
      
      case CATVizUShortType:
      {
         unsigned short *indexData = (unsigned short *)triIndex;
         unsigned int i;
         for (i = 0 ; i <triNum*3 ; ++i)
         {
            *indexData *= 3;
            indexData++;
         }
         indexData = (unsigned short *)stripIndex;
         for (i = 0 ; i < stripNum ; ++i)
         {
            for (unsigned int j = 0 ; j < numVertsInStrip[i] ; ++j)
            {
               *indexData *= 3;
               indexData++;
            }
         }
   
         indexData = (unsigned short *)fanIndex;
         
         for (i = 0 ; i < fanNum ; ++i)
         {
            for (unsigned int j = 0 ; j < numVertsInFan[i] ; ++j)
            {
               *indexData *= 3;
               indexData++;
            }
         }
      }
      break;
      
      case CATVizUIntType:
      {
         unsigned int *indexData = (unsigned int *)triIndex;
         unsigned int i;
         for (i = 0 ; i <triNum*3 ; ++i)
         {
            *indexData *= 3;
            indexData++;
         }
         
         indexData = (unsigned int *)stripIndex;
         for (i = 0 ; i < stripNum ; ++i)
         {
            for (unsigned int j = 0 ; j < numVertsInStrip[i] ; ++j)
            {
               *indexData *= 3;
               indexData++;
            }
         }
         indexData = (unsigned int *)fanIndex;
         for (i = 0 ; i < fanNum ; ++i)
         {
            for (unsigned int j = 0 ; j < numVertsInFan[i] ; ++j)
            {
               *indexData *= 3;
               indexData++;
            }
         }
      }
      break;
   }   
   ((unsigned int *)_data)[0] &= ~IS_PACKED;
}


INLINE unsigned char CATViz3DFace::GetStreamId() const
{
	return VIZFACE;
}

INLINE float const * CATViz3DFace::GetNormalReadOnly() const
{
   if (_data && (((unsigned int *)_data)[0] & IS_PLANAR)){
      if (((unsigned int *)_data)[0] & HAS_VERTEX_BUFFER)
         return (float *)&_data[sizeof(unsigned int) + sizeof(CATVizVertexBuffer *)];
      else
         return (float *)&_data[sizeof(unsigned int)];
   }else
      return NULL;
}

INLINE unsigned int CATViz3DFace::GetNVert()
{
   void const* triIndex=NULL;
   void const* stripIndex=NULL;
   void const* fanIndex=NULL;
   unsigned int    triNum = 0, stripNum = 0, fanNum = 0;
   unsigned int const* numVertsInStrip=NULL;
   unsigned int const* numVertsInFan=NULL;
   CATVizIndexType indexType;
   
   GetReadOnly(triIndex,
               triNum,
               stripIndex,
               stripNum,
               numVertsInStrip,
               fanIndex,
               fanNum,
               numVertsInFan,
               indexType,
               0);

   unsigned int nVerts = triNum*3;
   if(stripNum > 0)
   {
      for(unsigned int i=0;i<stripNum;i++)
         nVerts += numVertsInStrip[i];
   }
   if(fanNum > 0)
   {
      for(unsigned int i=0;i<fanNum;i++)
         nVerts += numVertsInFan[i];
   }
   return nVerts;
}

INLINE CATVizIndexType CATViz3DFace::GetIndexType()
{
   CATVizIndexType indexType = CATVizUIntType;
   if(_data)
   {
      if (((unsigned int *)_data)[0] & INT_COMPRESSION)
         return indexType;
      else if (((unsigned int *)_data)[0] & BYTE_COMPRESSION)
         indexType = CATVizUCharType;
      else if (((unsigned int *)_data)[0] & SHORT_COMPRESSION)
         indexType = CATVizUShortType;
   }
   return indexType;
}

INLINE unsigned char* CATViz3DFace::GetRefCountInData()
{
   if( !_data ) return 0;
#ifdef _ENDIAN_LITTLE
   return ((unsigned char *)_data)+3;
#else
   return ((unsigned char *)_data);
#endif
}
INLINE void CATViz3DFace::SetRefCountInData(unsigned char iRef)
{
   if( !_data ) return;
#ifdef _ENDIAN_LITTLE
   ((unsigned char *)_data)[3] = iRef;
#else
   ((unsigned char *)_data)[0] = iRef;
#endif
}
INLINE CATBoolean CATViz3DFace::HasVertexBuffer() const
{
   return (_data && (((unsigned int *)_data)[0] & HAS_VERTEX_BUFFER)) ? TRUE : FALSE;
}
INLINE CATVizVertexBuffer * CATViz3DFace::GetVertexBuffer() const
{
   return (_data && (((unsigned int *)_data)[0] & HAS_VERTEX_BUFFER)) ? *(CATVizVertexBuffer **)(&_data[sizeof(unsigned int)]) : NULL;
}

#endif
