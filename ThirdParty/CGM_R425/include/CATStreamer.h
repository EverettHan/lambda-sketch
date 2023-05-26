/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES  1997
//============================================================================
//
// CATMathStream (Mother class for CATCGMStream)
//
//=============================================================================
//
// Usage notes:
//
//=============================================================================
// Jan. 98   Moved and Renamed by                                 P. Catel
//=============================================================================

#ifndef CATStreamer_h
#define CATStreamer_h

class CATRep;
class CATCGRContainer;
class CATGraphicAttributeSet;
class CATCGRSetting;
class CATSGExtendedData;

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "SGInfra.h"
#include "CATDescribeCgr.h"
#include "CATVisHashTable.h"
#include "CATDataType.h"
#include "CATUnicodeString.h"
#include "CATFile.h"
#include "CATVizPtrList.h"
#include "CATBoolean.h"
#include "CATVizGlobals.h"
#include "BigLittle.h"
#include "CATMathPointf.h"
#include "CATCGRContainer.h"
#include "CATVizAllocator.h"

class CATMappingOperator;
class CAT4x4Matrix;
class CATSGContext;

// for shader migration
#if !defined(_ANDROID_SOURCE) && !defined(_LINUX_SOURCE)
class CATShaderDSFXMigration;
#endif
class CATCgfxDsfxConverter;

#define CATStreamerBLOCKSIZE 50000
#define CATOptBuffer 30000
#define ADRESSLISTSIZE 100

#define NOMULTIREF  (0x00)
#define MULTIREF    (0x01)
#define MATEXTREF   (0x02)

#define UNDEFINED   (0xff)
#define FACE3       (0x50)
#define PLANARFACE3 (0x51)
#define LINE3       (0x52)
#define POLYLINE3   (0x53)
#define MARKER3     (0x54)
#define FIXEDARROW  (0x55)
#define FIXEDPLAN   (0x56)
#define CYLINDER    (0x57)
#define CURVEDPIPE  (0x58)
#define ANNOTEXT3   (0x59)
#define EDGE3       (0x60)

#define AXISREP3		(0x61)
#define BAGREP3			(0x62)
#define CURVEDPIPEREP3	(0x63)
#define CUSTOMREP3      (0x64)
#define CYLINDERREP3	(0x65)
#define LODREP3			(0x66)
#define SURFACICREP     (0x67)
#define LINEREP3		(0x68)

#define GEOMTEXT2   (0x69)
#define BAGREP2     (0x70)
#define CUSTOMREP2  (0x71)

#define CURVEREP3   (0x72)
#define POINTREP3   (0x73)
#define PLANREP3   (0x74)
#define LIGHTSOURCEREP3 (0x75)
#define VIEWPOINT3  (0x76)
#define ARROW3  (0x77)
#define MONOWIREREP  (0x78)

#define ARCCIRCLE2  (0x79)
#define ARCELLIPSE2 (0x80)
#define LINE2       (0x81)
#define MARKER2     (0x82)
#define POLYGON2    (0x83)
#define RECTANGLE2  (0x84)
#define SIMPLELINE2 (0x85)
#define INTERNALSMOOTHEDGE3     (0x86)
#define ARROWSYMBOL2 (0x87)
#define SYMBOL2      (0x88)

#define REP2DTO3D    (0x89)
#define LIGHTSOURCE3    (0x90)
#define CGRREP     (0x91)
#define VOXELREP3     (0x92)
#define SEMANTICBAGREP3     (0x93)
#define VERTEXBUFFERREP3 (0x94)
#define SURFACICREPPROXY3 (0x95)
#define SMARTCGRREP (0x96)

#define SCISSORBAGREP2 (0x98)
#define POINTREP2 (0x99)
#define FILTERBAGREP3 (0x9A)

#define LAYERFILTER (0x9B)

#define ARCELLIPSE3 (0x9C)
#define ARCCIRCLE3 (0x9D)
#define ARCCIRCLEREP3 (0x9E)
#define ARCELLIPSEREP3 (0x9F)

#define IMAGEPIXEL3 (0xA0)
#define AXISSYSTEMREP3 (0xA1)
#define EDGECRV3 (0xA2)
#define TOLERANCESCALEBAGREP3 (0xA3)

#define ANNOTATIONTEXT2	(0xA4)
#define FIXEDARROW2		(0xA5)
#define IMAGEPIXEL2		(0xA6)
#define NURBS2			(0xA7)
#define POLYBEZIER2		(0xA8)
#define POLYPOLYGON2	(0xA9)

#define LINEREP2		(0xAA)
#define ARCCIRCLEREP2	(0xAB)
#define ARCELLIPSEREP2	(0xAC)
#define ARROWSYMBOLREP2 (0xAD)
#define POLYGONEREP2	(0xAE)
#define IMAGEPIXELREP2  (0xAF)
#define PERFORATEDPOLYGONREP2 (0xB0)
#define CLIPPINGFILTER (0xB1)
#define SCISSORFILTER (0xB2)
#define FILTERBAGREPWITHTOLERANCESCALE3 (0xB3)
#define PERFORATEDPOLYGON2    (0xB4)
#define UVRREP3    (0xB5)
#define PRIMITIVEGROUPREP (0xB6)
#define VIS3DNODEGROUPREP (0xB7)
#define VIS3DBILLBOARDREP (0xB8)
#define VIS3DFIXEDSIZENODEGROUPREP (0xB9)
#define CAT3DLODBAGREP (0xBA)

#define VOLUME3 (0xBB)
#define POINTCLOUDREP (0xBC)
#define UNIFORMLATTICEREP (0xBE)

#define REFPLANEREP (0xBD)
#define REFPLANEGP (0xBF)

#define CANONICALCONEREP (0xC0)
#define CANONICALCUBOIDREP (0xC1)
#define CANONICALCURVEDPIPEREP (0xC2)
#define CANONICALCYLINDERREP (0xC3)
#define CANONICALPARTIALSPHEREREP (0xC4)
#define CANONICALPARTIALTORUSREP (0xC5)
#define CANONICALSPHEREREP (0xC6)
#define CANONICALTORUSREP (0xC7)

#define EDGEHCS3 (0xC8)

#define VOXELVOLUMEREP (0xC9)

// Compression flags available
#define INT_PACKING           (1 << 0)
#define GAS_PACKING           (1 << 1)
#define BIT_PACKING           (1 << 2)
#define BIT_BOOLEAN           (1 << 3)
#define ZIP_COMPRESSION       (1 << 4)

//*******************************
//  The NT/UNIX marker
//*******************************
#ifdef _ENDIAN_LITTLE
#define NT_MARKER 1
#else
#define NT_MARKER 0
#endif

// Multi Container CGR
#include "CATDataType.h"
class CATCGRContainer;
class CATVizUVRStreamOptions;

typedef struct _CATStreamerTemporaryBuffer_
{
   void *buffer;
   unsigned int sizeInBytes;
   int used;
} CATStreamerTemporaryBuffer;

class CATStreamerClassNames
{
public:

   CATStreamerClassNames();
   ~CATStreamerClassNames();
   char *GetClassName(int id)
   {
      if (_classNames)
         return _classNames[id];
      else
         return NULL;
   }

protected:
   char **_classNames;
};

class ExportedBySGInfra CATStreamer
{
  public:
  CATStreamer();
  CATStreamer(int maxlen);
  CATStreamer(void*, int);

  static CATStreamer * CreateInstance(CATStream *, const char* iName, int directModeOn = 0);
  virtual ~CATStreamer();

  void* operator new(size_t iSize) { return CATVizAllocator::PermanentAllocate(iSize); }
  void operator delete(void* iObject) { CATVizAllocator::PermanentDeallocate(iObject); }

  inline void ReadData (void *buffer_data, ULONG long_data);
  virtual void WriteData(const void *buffer_data, ULONG long_data);

  void WriteChar  (const char);
  void WriteChar  (const char*, const int nbcell );
  void WriteUChar  (const unsigned char);
  void WriteUChar  (const unsigned char* , const int nbcell );
  void WriteFloat(const float);
  void WriteFloat(float const*, const int nbcell);
  void WriteShort  (const short);
  void WriteShort  (short* , const int nbcell);
  void WriteUShort  (const unsigned short);
  void WriteUShort  (const unsigned short* , const int nbcell);
  void WriteInt   (const int, int notcompacted=0);
  void WriteInt   (int*, const int nbcell );
  void OldWriteInt   (const int);
  void WriteIntAt  (const int  Value , const int Address);
  void WriteUInt   (const unsigned int);
  void OldWriteUInt   (const unsigned int);
  void WriteString (const char*);
  void WriteULong (const CATULONG32);
  void WriteLong (const CATLONG32);
  void WriteDouble (const double);
  void WriteDouble (const double*, const int nbcell);

  void WriteVerticesArray(float const*, const int nbcell);
  void WriteVerticesQuantArray(unsigned short const* toadd, const int nbcell);

  void WriteNormalsArray(float const*, const int nbcell);
  void WriteTexturesArray(float const*, const int nbVertices, const int inputDimTC, const int toWriteDimTC);
  void SkipTexturesArray (const int nbVertices, int inputDimTC);

  //++ To support minor evolutions in CGR format
  void WriteBeginBlock();
  void WriteEndBlock();

  void ReadBeginBlock();
  void ReadEndBlock();
  //--

  void WriteAttribute(const CATGraphicAttributeSet & iAttribute);
  void WriteBoolean(CATBoolean iBit);
  void WriteBit(CATBoolean iBit);
  void WriteBits(unsigned int iData, unsigned char nBits);
  void EncodeNormal(float*);

  void DecodePolarVectors( unsigned int nbVectors,void *);
  void DecodePolarVector(float*);
  void EncodePolarVector(float*);
  void EncodePolarVectors(unsigned int nbVectors, float* vector);

  inline void ReadChar    (char&);
  inline void ReadChar    (char* , const int nbcell );
  inline void ReadUChar   (unsigned char&);
  inline void ReadUChar   (unsigned char* , const int nbcell );
  inline void ReadFloat   (float&);
  inline void ReadFloat   (float*, const int nbcell)    ;
  inline void ReadShort   (short&)    ;
  inline void ReadUShort  (unsigned short&)    ;
  inline void ReadUShort  (unsigned short*, const int nbcell)    ;
  inline void ReadShort   (short*, const int nbcell)    ;
  inline void ReadInt     (int&)    ;
  inline void OldReadInt  (int&);
  inline void ReadInt     (int*, const int nbcell)    ;
  inline void ReadUInt    (unsigned int&)    ;
  inline void OldReadUInt (unsigned int&)    ;
  inline void ReadString  (char*&)  ;
  inline void ReadULong	  (CATULONG32&);
  inline void ReadLong    (CATLONG32&);
  inline void ReadDouble  (double &);
  inline void ReadDouble  (double *, const int nbcell);
  inline char *ReadClassName(int & toDelete);
  inline void ReadClassName (char*&);
  void ReadVerticesArray(float*, const int nbcell);
  void ReadVerticesQuantArray(unsigned short* toread, const int nbcell);
  void ReadNormalsArray(float*, const int nbcell);

  //void ReadTexturesArray(float*, const int nbcell, const int toReadDimTC);
  void ReadTexturesArray(float*, const int nbVertices, const int inputDimTC, const int toReadDimTC);

  void ReadAttribute(CATGraphicAttributeSet & oAttribute);
  inline CATBoolean ReadBit();
  inline CATBoolean ReadBoolean();
  void ReadBits(unsigned int & oData, unsigned char nBits);

  unsigned int ReadPackedInt(unsigned int maxValue);
  void DecodeNormal(float*);
  void DecodeNormal(short*);
  inline void ReadBoundingPrimitive(float*, float*, float*, float&);

  HRESULT MakeStandalone();
  HRESULT SetMinSize(CATULONG32 newSize);
  inline const void *   GetBuffer() const;
  inline CATULONG32  GetLength() const;
  inline CATStream * GetStream();
  HRESULT Commit();

  inline HRESULT SetCurrentPosition(unsigned int pos);
  inline int  GetCurrentPosition() const;
  void Reset();
  inline void Advance( int siz );

  inline void          SetConversion(unsigned char);
  inline unsigned char GetConversion()        const;


  int PreProcessCGR(CATRep *iRep);
  inline CATINTPTR RepToSave(CATRep *iRep);
  inline short GetBEStatus();
  inline void SetBEStatus(short iStatus);

  inline void          SetSGContext(CATSGContext* iCtx) { _currentSGContext = iCtx; }
  inline CATSGContext* GetSGContext() { return _currentSGContext; }


  void ComputeCurrentRepBoundingBox(CAT3DRep* iRep, CATMathPointf & oBoxCenter, CATMathPointf & oBoxDim);
  inline void SetCurrentRepBoundingBox(const CATMathPointf & oBoxMin, const CATMathPointf & oBoxMax, bool iIsAllowed, bool iPropagate = true)
  {
    _current_bbox_min = oBoxMin;
    _current_bbox_max = oBoxMax;
    _isBBoxCompessionAllowed = iIsAllowed;

    if(_container && iPropagate)
      _container->PropagateCurrentRepBBox(this);
  }

  inline void GetCurrentRepBoundingBox(CATMathPointf & oBoxMin, CATMathPointf & oBoxMax, bool & oIsAllowed) const
  {
    oBoxMin = _current_bbox_min;
    oBoxMax = _current_bbox_max;
    oIsAllowed = _isBBoxCompessionAllowed;
  }

  inline int FindIndex(void*);
  int RegisterObject(void* object);
  int IsValidIndex(int pos);
  void* GetMultiRefObject(int);
  void AddMultiRefObject(void* ,int);
  void AddMultiRefObjectToBeReleased(CATBaseUnknown* ,int);

  // CGR resources management
  CATCGRContainer * GetResourceCGRContainer();

  CATCgfxDsfxConverter* GetCgfxDsfxConverter();

  //compression
  void SetNumberOfVertices(int nb);
  inline int  GetNumberOfVertices();
  void packc(int v);
  inline void unpackc(int &);
  inline void unpackc(unsigned char *, int nbIndices, int multiply = 1);
  inline void unpackc(unsigned short *, int nbIndices, int multiply = 1);
  inline void unpackc(unsigned int *, int nbIndices, int multiply = 1);

  inline static void ConvertShort  (short & value);
  inline static void ConvertUShort (unsigned short & value);
  inline static void ConvertInt    (int & value);
  inline static void ConvertUInt   (unsigned int & value);
  inline static void ConvertFloat  (float & value);
  inline static void ConvertLong   (CATLONG32 &  value);
  inline static void ConvertULong  (CATULONG32& value);
  inline static void ConvertDouble (double & value);

  inline void SetCurrentVersion (int version);
  inline int  GetCurrentVersion ();

  HRESULT SetBuffer(char *iBuffer, CATULONG32 iBufferLength);
  void    ResetBuffer();

  CATStreamer * GetStreamer(const char *iName);
  CATStreamer * CreateStreamer(const char *iName);

  CATCGRContainer * GetContainer();
  void              SetContainer(CATCGRContainer * iContainer);
  inline int IsBufferAllocated();

  inline const char *GetName();

  inline void SetLightDataStreaming(unsigned int iOnOff);
  inline unsigned int LightDataStreaming();

  inline void SetLightSceneGraph(unsigned int iOnOff);
  inline unsigned int LightSceneGraph();

  inline void SetSmartLoading(unsigned int iOnOff);
  inline unsigned int SmartLoading();

  inline void SetTargetLevel(CATVizSemanticLevel iTargetLevel);
  inline CATVizSemanticLevel TargetLevel();

  void *CreateTemporaryBuffer(unsigned int sizeInByte);
  void ReleaseTemporaryBuffer(void *buffer);

  HRESULT Compress();
  HRESULT Decompress();

  // file size statistics

  inline void SetCompressionFlags(int iCompressionFlags);
  inline int  GetCompressionFlags();

  inline void SetUVR(CATVizUVRStreamOptions * uvrOptions);
  inline CATVizUVRStreamOptions * GetUVR();

  void SetCGRSettings(CATCGRSetting * cgrSettings);
  CATCGRSetting * GetCGRSettings();


  virtual void PushStat(const char * name);
  virtual void PopStat();

  void SetCorrupted();
  CATBoolean IsCorrupted();

  void PushMappingOperator(CATMappingOperator *mappingOperator);
  void PopMappingOperator();
  CATMappingOperator *GetCurrentMappingOperator();

  void PushTextureMatrix(CAT4x4Matrix * iMatrix);
  void PopTextureMatrix();
  CAT4x4Matrix * GetCurrentTextureMatrix();

  void SetSGExtendedData(CATSGExtendedData* pData);
  CATSGExtendedData* GetSGExtendedData();

  static bool IsBBOXCompressionAllowed(const CAT3DRep & iRep);

protected:

  void Reallocate    (CATULONG32 newmaxlen);

  CATCGRContainer * _container;

  inline static void Convert(short & value, void * valueInBuffer = NULL);
  inline static void Convert(unsigned short & value, void * valueInBuffer = NULL);
  inline static void Convert(int & value, void * valueInBuffer = NULL);
  inline static void Convert(unsigned int & value, void * valueInBuffer = NULL);
  inline static void Convert(float & value, void * valueInBuffer = NULL);
#ifndef PLATEFORME_DS64
  inline static void Convert(CATLONG32 &  value, void * valueInBuffer = NULL);
  inline static void Convert(CATULONG32& value, void * valueInBuffer = NULL);
#endif
  inline static void Convert(double & value, void * valueInBuffer = NULL);

	// E8C : deprecated but kept for CATVizDebugStreamer
	CATStreamer(CATStream* iStream, const char* iName, int directModeOn = 0);

private:

  char *          _name;
  char *          _buffer;
  CATULONG32      _length;
  CATULONG32      _allocated_length;
  int             _cgrVersion;
  int             _compressionFlags;
  CATULONG32      _bitContainerPos;
  unsigned int    _bitContainer;
  unsigned int    _bitsRemaining;

  // Stream used in direct IO mode
  CATStream *     _stream;

  /*Les tableaux suivants servent dans les methode WriteVerticesArray et WriteNormalsArray
  ils sont utilises a la lecture et a l'ecriture*/
  float          * _optBuffer;
  int              _optBufferSize;
  unsigned char  * _flagbuffer;
  int              _flagBufferSize;
  short          * _optBuffer2;
  int              _optBuffer2Size;

  CATGraphicAttributeSet *_attributes;
  unsigned int            _nbAttributes;

  CATULONG32  _current_position;

  CATVisHashTable * _noLineicPreProcessTable;

  int _adress_list_size;
  int _allocated_adress_list;
  void** objectList;
  CATVizPtrList<CATBaseUnknown> objectToBeReleasedList;

  CATMathPointf _current_bbox_min;
  CATMathPointf _current_bbox_max;
  bool _isBBoxCompessionAllowed;

  int _nbVertices;
  unsigned char _nbBitsPerVertex;

  unsigned int _directMode         : 1;
  unsigned int _conversion         : 1;
  unsigned int _invalidBE          : 1;
  unsigned int _bufferAllocated    : 2; // 1 if _buffer is mallocated, 2 if _buffer is newed, 0 if buffer must not be deleted otherwise
  unsigned int _isFirstRead        : 1;
  unsigned int _lightDataStreaming : 1;
  unsigned int _lightSceneGraph    : 1;
  unsigned int _smartLoading       : 1;

  // Compression flags buffering
  unsigned int _bitBoolean         : 1;
  unsigned int _bitPacking         : 1;
  unsigned int _intPacking         : 1;
  unsigned int _gasPacking         : 1;
  unsigned int _corrupted          : 1;

  CATVizSemanticLevel _targetLevel;

  static CATStreamerClassNames _classNames;

  CATVizUVRStreamOptions * _uvrOptions;
  CATCGRSetting          * _cgrSettings;


  CATVizPtrList<CATStreamerTemporaryBuffer> _temporaryBuffers;
  CATVizPtrList<CATMappingOperator> _mappingOperatorsStack;
  CATVizPtrList<CAT4x4Matrix> _textureMatricesStack;

  CATCgfxDsfxConverter* m_Converter;

  CATSGExtendedData* _SGExtendedData = nullptr;
  CATSGContext* _currentSGContext;

	void SetName(const char* iName);
	friend class CATCGRContainer;

	// Internal
	void InitStreamer(void* iBuf, int iBufSize, int MaxLength, CATStream* iStream, const char* iName, int directModeOn);

    // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATStreamer (const CATStreamer &);
  CATStreamer & operator= (const CATStreamer &);
};

// READ MACROS

#define READONE(type,dest)\
if(_conversion)\
{\
  if (_current_position + sizeof(type) <= _length)\
  {\
   Convert(dest,(void *)&_buffer[_current_position]);\
   _current_position += sizeof(type);\
  }\
  else\
  {\
    _corrupted = 1;\
    dest = 0;\
  }\
}\
else\
{\
   ReadData(&dest, sizeof(type));\
}\

// Read an array of datatype
#define READARRAY(nbcells,type,dest)\
if(_conversion)\
{\
   if (_current_position + nbcells*sizeof(type) <= _length)\
     for(int i=0;i<nbcells;i++)\
     {\
        Convert(dest[i],(void *)&_buffer[_current_position]);\
        _current_position += sizeof(type);\
     }\
   else\
   {\
     _corrupted = 1;\
     if (dest)\
      memset (dest, 0, nbcells*sizeof(type));\
   }\
}\
else\
{\
   ReadData(dest, nbcells*sizeof(type));\
}\


// Read one datatype without conversion
#define READONENOCONVERT(type,dest) \
ReadData(&dest, sizeof(type));      \

// Read an array of datatype without conversion
#define READARRAYNOCONVERT(nbcells,type,dest)   \
ReadData(dest, nbcells*sizeof(type));           \

//******************************************************************************
//*** INLINED METHODS: *********************************************************
//******************************************************************************
inline const char *CATStreamer::GetName()
{
   return _name;
}

inline void CATStreamer::ReadData(void *buffer_data, ULONG long_data)
{
   if(_isFirstRead)
   {
      _current_position = 0;
      _isFirstRead      = 0;
   }

   if (_current_position + long_data <= _length)
   {
     memcpy (buffer_data,&(_buffer[_current_position]), long_data);
     _current_position += long_data;
   }
   else
   {
     _corrupted = 1;
     if (buffer_data)
      memset (buffer_data, 0, long_data);
   }
}

inline void CATStreamer::ReadChar   (char& toread)
{
  if(_isFirstRead)
  {
    _current_position = 0;
    _isFirstRead      = 0;
  }
  if (_current_position < _length)
    toread = _buffer[_current_position++];
  else
  {
    _corrupted = 1;
    toread = 0;
  }
}

inline void CATStreamer::ReadChar   (char* toread, const int nbcell )
{
   READARRAYNOCONVERT(nbcell,char,toread);
}

inline void CATStreamer::ReadUChar   (unsigned char& toread)
{
  if(_isFirstRead)
  {
    _current_position = 0;
    _isFirstRead      = 0;
  }
  if (_current_position < _length)
    toread = _buffer[_current_position++];
  else
  {
    _corrupted = 1;
    toread = 0;
  }
}

inline void CATStreamer::ReadUChar   (unsigned char* toread, const int nbcell )
{
   READARRAYNOCONVERT(nbcell,unsigned char,toread);
}

inline void CATStreamer::ReadFloat(float& toread)
{
   READONE(float,toread);
}

inline void CATStreamer::ReadFloat  (float* toread , const int nbcell )
{
   READARRAY(nbcell,float,toread);
}

inline void CATStreamer::ReadDouble(double& toread)
{
   READONE(double,toread);
}

inline void CATStreamer::ReadDouble  (double* toread , const int nbcell )
{
   READARRAY(nbcell,double,toread);
}

inline void CATStreamer::ReadShort   (short& toread)
{
   READONE(short,toread);
}

inline void CATStreamer::ReadUShort   (unsigned short& toread)
{
   READONE(unsigned short,toread);
}

inline void CATStreamer::ReadUShort   (unsigned short* toread, const int nbcell)
{
   READARRAY(nbcell,unsigned short,toread);
}

inline void CATStreamer::ReadShort  (short* toread , const int nbcell )
{
   READARRAY(nbcell,short,toread);
}

inline void CATStreamer::ReadInt(int& toread)
{
   if(_intPacking)
   {
      unsigned int type = 0;
      ReadBits(type, 2);
      switch(type)
      {
      case 1 :
         {
            unsigned char tmp = 0;
            ReadData(&tmp, sizeof(unsigned char));
            toread = tmp;
         } break;
      case 2 :
         {
            unsigned short tmp = 0;
            ReadData(&tmp, sizeof(unsigned short));
            toread = tmp;
         } break;
      case 0 :
      case 3 :
         {
            ReadData(&toread, sizeof(unsigned int));
         } break;
      }
      return;
   }

   if (_cgrVersion >= 1100600)
   {
      unsigned char t=0;
      ReadUChar(t);

      if (t==255)
      {
         OldReadInt(toread);
      }
      else
      {
         toread = t;
      }
   }
   else
   {
      OldReadInt(toread);
   }
}

inline void CATStreamer::OldReadInt(int & toread)
{
   READONE(int,toread);
}

inline void CATStreamer::ReadInt  (int* toread , const int nbcell )
{
   READARRAY(nbcell,int,toread);
}

inline void CATStreamer::OldReadUInt(unsigned int& toread)
{
   READONE(unsigned int,toread);
}

inline void CATStreamer::ReadUInt(unsigned int& toread)
{
   if(_intPacking)
   {
      ReadInt((int &)toread);
      return;
   }

   if(_cgrVersion >= 1101410)
   {
      unsigned char t=0;
      ReadUChar(t);

      if (t==255)
      {
         OldReadUInt(toread);
      }
      else
         toread = t;
   }
   else
   {
      OldReadUInt(toread);
   }
}

inline void CATStreamer::ReadULong (CATULONG32& toread)
{
   READONE(CATULONG32, toread);
}

inline void CATStreamer::ReadLong (CATLONG32& toread)
{
   READONE(CATLONG32, toread);
}

inline void CATStreamer::ReadString  (char*& toread)
{
   int siz = 0;
   ReadInt(siz);

   toread = new char[siz+1];
   toread[siz] = '\0';
   READARRAYNOCONVERT(siz,char,toread);
}

inline char *CATStreamer::ReadClassName(int & toDelete)
{
   if (_cgrVersion >= 1100600)
   {
      toDelete = 0;
      unsigned char id = 0;
      ReadUChar(id);
      switch(id)
      {
      case AXISREP3://CAT3DAxisRep
         return _classNames.GetClassName(0);
         break;

      case BAGREP3://CAT3BagRep
         return _classNames.GetClassName(1);
         break;

      case CURVEDPIPEREP3://CAT3DCurvedPipeRep
         return _classNames.GetClassName(2);
         break;

      case CUSTOMREP3://CAT3DCustomRep
         return _classNames.GetClassName(3);
         break;

      case CYLINDERREP3://CAT3DCylinderRep
         return _classNames.GetClassName(4);
         break;

      case LODREP3://CAT3DlodRep
         return _classNames.GetClassName(5);
         break;

      case SURFACICREP://CATSurfacicRep
         return _classNames.GetClassName(6);
         break;

      case LINEREP3://CAT3DLineRep
         return _classNames.GetClassName(7);
         break;

      case CUSTOMREP2://CAT2DCustomRep
         return _classNames.GetClassName(8);
         break;

      case BAGREP2://CAT2DBagRep
         return _classNames.GetClassName(9);
         break;

      case CURVEREP3://CAT3DCurveRep
         return _classNames.GetClassName(10);
         break;

      case POINTREP3://CAT3DPointRep
         return _classNames.GetClassName(11);
         break;

      case PLANREP3://CAT3DPlanRep
         return _classNames.GetClassName(12);
         break;

      case MONOWIREREP://CATMonoWireRep
         return _classNames.GetClassName(13);
         break;

      case REP2DTO3D://CAT2DTo3DRep
         return _classNames.GetClassName(14);
         break;
      case CGRREP://CATCGRRep
         return _classNames.GetClassName(15);
         break;
      case VOXELREP3://CATVizVoxelRep
         return _classNames.GetClassName(16);
         break;
      case SEMANTICBAGREP3://CATMonoWireRep
         return _classNames.GetClassName(17);
         break;
	   case VERTEXBUFFERREP3://CATVizVertexBufferRep
         return _classNames.GetClassName(18);
         break;
	   case SURFACICREPPROXY3://CATVizSurfacicRepProxy
         return _classNames.GetClassName(19);
         break;
      case SMARTCGRREP://CAT3DAxisRep
         return _classNames.GetClassName(20);
         break;
      case SCISSORBAGREP2://CAT2DScissorBagRep
         return _classNames.GetClassName(21);
         break;
	  case POINTREP2://CAT2DPointRep
         return _classNames.GetClassName(22);
         break;
	  case FILTERBAGREP3://CAT3DFilterBagRep
         return _classNames.GetClassName(23);
         break;
	  case ARCELLIPSEREP3://CAT3DArcEllipseRep
		 return _classNames.GetClassName(24);
		 break;
	  case ARCCIRCLEREP3://CAT3DArcCircleRep
		 return _classNames.GetClassName(25);
		 break;
	  case AXISSYSTEMREP3://CAT3DAxisRep
         return _classNames.GetClassName(26);
         break;
	  case TOLERANCESCALEBAGREP3://CAT3DBagRepWithToleranceScale
         return _classNames.GetClassName(27);
         break;
	  case LINEREP2://CAT2DLineRep
         return _classNames.GetClassName(28);
         break;
	  case ARCCIRCLEREP2://CAT2DArcCircleRep
         return _classNames.GetClassName(29);
         break;
	  case ARCELLIPSEREP2://CAT2DArcEllipseRep
         return _classNames.GetClassName(30);
         break;
	  case ARROWSYMBOLREP2://CAT2DArrowSymbolRep
         return _classNames.GetClassName(31);
         break;
	  case POLYGONEREP2://CAT2DPolygonRep
         return _classNames.GetClassName(32);
         break;
	  case IMAGEPIXELREP2://CAT2DImagePixelRep
         return _classNames.GetClassName(33);
         break;
	  case PERFORATEDPOLYGONREP2://CAT2DPerforatedPolygonRep
         return _classNames.GetClassName(34);
         break;
	  case FILTERBAGREPWITHTOLERANCESCALE3://CAT2DPerforatedPolygonRep
         return _classNames.GetClassName(35);
         break;
	  case UVRREP3://CAT2DPerforatedPolygonRep
         return _classNames.GetClassName(36);
         break;
	  case PRIMITIVEGROUPREP://VisPrimitiveGroupRep
         return _classNames.GetClassName(37);
         break;
	  case VIS3DNODEGROUPREP://Vis3DNodeGroupRep
         return _classNames.GetClassName(38);
         break;
	  case UNDEFINED://Undefined
         return _classNames.GetClassName(39);
         break;
	  case VIS3DBILLBOARDREP://Vis3DBillboardRep
         return _classNames.GetClassName(40);
         break;
    case VIS3DFIXEDSIZENODEGROUPREP: //Vis3DFixedSizeNodeGroupRep
         return _classNames.GetClassName(41);
         break;
    case CAT3DLODBAGREP: //CAT3DLodBagRep
         return _classNames.GetClassName(42);
         break;
	case POINTCLOUDREP: //CAT3DPointCloudRep
         return _classNames.GetClassName(43);
         break;
    case UNIFORMLATTICEREP: // CAT3DUniformLatticeRep
        return _classNames.GetClassName(44);
        break;
    case REFPLANEREP: // CAT3DReferencePlaneRep
        return _classNames.GetClassName(45);
        break;
    case CANONICALCONEREP: // CAT3DCanonicalConeRep
        return _classNames.GetClassName(46);
        break;
    case CANONICALCUBOIDREP: // CAT3DCanonicalCuboidRep
        return _classNames.GetClassName(47);
        break;
    case CANONICALCURVEDPIPEREP: // CAT3DCanonicalCurvedPipeRep
        return _classNames.GetClassName(48);
        break;
    case CANONICALCYLINDERREP: // CAT3DCanonicalCylinderRep
        return _classNames.GetClassName(49);
        break;
    case CANONICALPARTIALSPHEREREP: // CAT3DCanonicalPartialSphereRep
        return _classNames.GetClassName(50);
        break;
    case CANONICALPARTIALTORUSREP: // CAT3DCanonicalPartialTorusRep
        return _classNames.GetClassName(51);
        break;
    case CANONICALSPHEREREP: // CAT3DCanonicalSphereRep
        return _classNames.GetClassName(52);
        break;
    case CANONICALTORUSREP: // CAT3DCanonicalTorusRep
        return _classNames.GetClassName(53);
        break;
    case VOXELVOLUMEREP://CAT3DVoxelVolumeRep
      return _classNames.GetClassName(54);
      break;

    default:
         return NULL;
         break;
      }
   }
   else
   {
      toDelete = 1;
      char *name = NULL;
      ReadString(name);
      return name;
   }
}
inline void CATStreamer::ReadClassName(char*& name)
{
   if (_cgrVersion >= 1100600)
   {
      unsigned char id = 0;
      ReadUChar(id);
      switch(id)
      {
      case AXISREP3://CAT3DAxisRep
         name = new char [13];
         name[12]='\0';
         strncpy(name,"CAT3DAxisRep",12);
         break;

      case BAGREP3://CAT3BagRep
         name = new char [12];
         name[11]='\0';
         strncpy(name,"CAT3DBagRep",11);
         break;

      case CURVEDPIPEREP3://CAT3DCurvedPipeRep
         name = new char [19];
         name[18]='\0';
         strncpy(name,"CAT3DCurvedPipeRep",18);
         break;

      case CUSTOMREP3://CAT3DCustomRep
         name = new char [15];
         name[14]='\0';
         strncpy(name,"CAT3DCustomRep",14);
         break;

      case CYLINDERREP3://CAT3DCylinderRep
         name = new char [17];
         name[16]='\0';
         strncpy(name,"CAT3DCylinderRep",16);
         break;

      case LODREP3://CAT3DlodRep
         name = new char [12];
         name[11]='\0';
         strncpy(name,"CAT3DLodRep",11);
         break;

      case SURFACICREP://CATSurfacicRep
         name = new char [15];
         name[14]='\0';
         strncpy(name,"CATSurfacicRep",14);
         break;

      case LINEREP3://CAT3DLineRep
         name = new char [13];
         name[12]='\0';
         strncpy(name,"CAT3DLineRep",12);
         break;

      case CUSTOMREP2://CAT2DCustomRep
         name = new char [15];
         name[14]='\0';
         strncpy(name,"CAT2DCustomRep",14);
         break;

      case BAGREP2://CAT2DBagRep
         name = new char [12];
         name[11]='\0';
         strncpy(name,"CAT2DBagRep",11);
         break;

      case CURVEREP3://CAT3DCurveRep
         name = new char [14];
         name[13]='\0';
         strncpy(name,"CAT3DCurveRep",13);
         break;

      case POINTREP3://CAT3DPointRep
         name = new char [14];
         name[13]='\0';
         strncpy(name,"CAT3DPointRep",13);
         break;

      case PLANREP3://CAT3DPlanRep
         name = new char [13];
         name[12]='\0';
         strncpy(name,"CAT3DPlanRep",12);
         break;

      case MONOWIREREP://CATMonoWireRep
         name = new char [15];
         name[14]='\0';
         strncpy(name,"CATMonoWireRep",14);
         break;

      case REP2DTO3D://CAT2DTo3DRep
         name = new char [13];
         name[12]='\0';
         strncpy(name,"CAT2DTo3DRep",12);
         break;
      case CGRREP://CATCGRRep
         name = new char [10];
         name[9]='\0';
         strncpy(name,"CATCGRRep",9);
         break;
      case VOXELREP3://CATVizVoxelRep
         name = new char [15];
         name[14]='\0';
         strncpy(name,"CATVizVoxelRep",14);
         break;
      case SEMANTICBAGREP3://CATMonoWireRep
         name = new char [20];
         name[19]='\0';
         strncpy(name,"CAT3DSemanticBagRep",19);
         break;
	   case VERTEXBUFFERREP3://CATVizVertexBufferRep
         name = new char [22];
         name[21]='\0';
         strncpy(name,"CATVizVertexBufferRep",21);
         break;
	   case SURFACICREPPROXY3://CATVizSurfacicRepProxy
         name = new char [23];
         name[22]='\0';
         strncpy(name,"CATVizSurfacicRepProxy",22);
         break;
      case SMARTCGRREP://CAT3DAxisRep
         name = new char [15];
         name[14]='\0';
         strncpy(name,"CATSmartCGRRep",14);
         break;
      case SCISSORBAGREP2://CAT2DScissorBagRep
         name = new char [19];
         name[18]='\0';
         strncpy(name,"CAT2DScissorBagRep",18);
         break;
	  case POINTREP2://CAT2DPointRep
         name = new char [14];
         name[13]='\0';
         strncpy(name,"CAT2DPointRep",13);
         break;
	  case FILTERBAGREP3://CAT3DFilterBagRep
		  name = new char [18];
		  name[17]='\0';
         strncpy(name,"CAT3DFilterBagRep",17);
         break;
	  case ARCELLIPSEREP3://CAT3DArcEllipseRep
		  name = new char [19];
		  name[18]='\0';
		  strncpy(name,"CAT3DArcEllipseRep",18);
		  break;
	  case ARCCIRCLEREP3://CAT3DArcCircleRep
		  name = new char [18];
		  name[17]='\0';
		  strncpy(name,"CAT3DArcCircleRep",17);
		  break;
	  case AXISSYSTEMREP3://CAT3DAxisSystemRep
         name = new char [19];
         name[18]='\0';
         strncpy(name,"CAT3DAxisSystemRep",18);
         break;
	  case TOLERANCESCALEBAGREP3://CAT3DBagRepWithToleranceScale
         name = new char [30];
         name[29]='\0';
         strncpy(name,"CAT3DBagRepWithToleranceScale",29);
         break;
	  case LINEREP2://CAT2DLineRep
         name = new char [13];
         name[12]='\0';
         strncpy(name,"CAT2DLineRep",12);
         break;
	  case ARCCIRCLEREP2://CAT2DArcCircleRep
         name = new char [18];
         name[17]='\0';
         strncpy(name,"CAT2DArcCircleRep",17);
         break;
	  case ARCELLIPSEREP2://CAT2DArcEllipseRep
         name = new char [19];
         name[18]='\0';
         strncpy(name,"CAT2DArcEllipseRep",18);
         break;
	  case ARROWSYMBOLREP2://CAT2DArrowSymbolRep
         name = new char [20];
         name[19]='\0';
         strncpy(name,"CAT2DArrowSymbolRep",19);
         break;
	  case POLYGONEREP2://CAT2DPolygonRep
         name = new char [16];
         name[15]='\0';
         strncpy(name,"CAT2DPolygonRep",15);
         break;
	  case IMAGEPIXELREP2://CAT2DImagePixelRep
         name = new char [19];
         name[18]='\0';
         strncpy(name,"CAT2DImagePixelRep",18);
         break;
	  case PERFORATEDPOLYGONREP2://CAT2DPerforatedPolygonRep
         name = new char [26];
         name[25]='\0';
         strncpy(name,"CAT2DPerforatedPolygonRep",25);
         break;
 	  case FILTERBAGREPWITHTOLERANCESCALE3://CAT3DFilterBagRepWithToleranceScale
         name = new char [36];
         name[35]='\0';
         strncpy(name,"CAT3DFilterBagRepWithToleranceScale",35);
         break;
 	  case PRIMITIVEGROUPREP://VisPrimitiveGroupRep
         name = new char [21];
         name[20]='\0';
         strncpy(name,"VisPrimitiveGroupRep",20);
         break;
  	case VIS3DNODEGROUPREP://Vis3DNodeGroupRep
         name = new char [18];
         name[17]='\0';
         strncpy(name,"Vis3DNodeGroupRep",17);
         break;
  	case UNDEFINED://Undefined
         /*name = new char [10];
         name[9]='\0';
         strncpy(name,"Undefined",9);*/
    case VIS3DBILLBOARDREP://Vis3DBillboardRep
         name = new char[18];
         name[17] = '\0';
         strncpy(name, "Vis3DBillboardRep", 17);
         break;
    case VIS3DFIXEDSIZENODEGROUPREP://Vis3DFixedSizeNodeGroupRep
         name = new char[27];
         name[26] = '\0';
         strncpy(name, "Vis3DFixedSizeNodeGroupRep", 26);
         break;
    case CAT3DLODBAGREP: //CAT3DLodBagRep
         name = new char[15];
         name[14] = '\0';
         strncpy(name, "CAT3DLodBagRep", 14);
         break;
	case POINTCLOUDREP: //CAT3DPointCloudRep
         name = new char[19];
         name[18] = '\0';
         strncpy(name, "CAT3DPointCloudRep", 18);
         break;
    case UNIFORMLATTICEREP:
        name = new char[23];
        name[22] = '\0';
        strncpy(name, "CAT3DUniformLatticeRep", 22);
        break;
    case REFPLANEREP:
        name = new char[23];
        name[22] = '\0';
        strncpy(name, "CAT3DReferencePlaneRep", 22);
        break;
    case CANONICALCONEREP: // CAT3DCanonicalConeRep
        name = new char[22];
        name[21] = '\0';
        strncpy(name, "CAT3DCanonicalConeRep", 21);
        break;
    case CANONICALCUBOIDREP: // CAT3DCanonicalCuboidRep
        name = new char[25];
        name[24] = '\0';
        strncpy(name, "CAT3DCanonicalCuboidRep", 24);
        break;
    case CANONICALCURVEDPIPEREP: // CAT3DCanonicalCurvedPipeRep
        name = new char[28];
        name[27] = '\0';
        strncpy(name, "CAT3DCanonicalCurvedPipeRep", 27);
        break;
    case CANONICALCYLINDERREP: // CAT3DCanonicalCylinderRep
        name = new char[26];
        name[25] = '\0';
        strncpy(name, "CAT3DCanonicalCylinderRep", 25);
        break;
    case CANONICALPARTIALSPHEREREP: // CAT3DCanonicalPartialSphereRep
        name = new char[31];
        name[30] = '\0';
        strncpy(name, "CAT3DCanonicalPartialSphereRep", 30);
        break;
    case CANONICALPARTIALTORUSREP: // CAT3DCanonicalPartialTorusRep
        name = new char[30];
        name[29] = '\0';
        strncpy(name, "CAT3DCanonicalPartialTorusRep", 29);
        break;
    case CANONICALSPHEREREP: // CAT3DCanonicalSphereRep
        name = new char[24];
        name[23] = '\0';
        strncpy(name, "CAT3DCanonicalSphereRep", 23);
        break;
    case CANONICALTORUSREP: // CAT3DCanonicalTorusRep
        name = new char[23];
        name[22] = '\0';
        strncpy(name, "CAT3DCanonicalTorusRep", 22);
        break;
    case VOXELVOLUMEREP://CAT3DVoxelVolumeRep
      name = new char[20];
      name[19] = '\0';
      strncpy(name, "CAT3DVoxelVolumeRep", 19);
      break;
      }
   }
   else {
      ReadString(name);
   }
}

inline void CATStreamer::Convert(short & value, void * valueInBuffer)
{
   if(valueInBuffer)
   {
      // Conversion optimization when value in buffer is known.
      // It avoids swapping
      char *tmp = &((char *)valueInBuffer)[1];
      char *out4 = (char *)&value;
      *(out4++) = *(tmp--);
      *(out4) = *(tmp);
      return;
   }
  unsigned char* c = (unsigned char*) &value ;

  unsigned char t ;
  t = c[0] ;
  c[0] = c[1] ;
  c[1] = t ;
}

inline void CATStreamer::Convert(unsigned short & value, void * valueInBuffer)
{
   if(valueInBuffer)
   {
      // Conversion optimization when value in buffer is known.
      // It avoids swapping
      char *tmp = &((char *)valueInBuffer)[1];
      char *out4 = (char *)&value;
      *(out4++) = *(tmp--);
      *(out4) = *(tmp);
      return;
   }

  unsigned char* c = (unsigned char*) &value ;

  unsigned char t ;
  t = c[0] ;
  c[0] = c[1] ;
  c[1] = t ;
}

inline void CATStreamer::Convert(int & value, void * valueInBuffer)
{
   if(valueInBuffer)
   {
      // Conversion optimization when value in buffer is known.
      // It avoids swapping
      char *tmp = &((char *)valueInBuffer)[3];
      char *out4 = (char *)&value;
      *(out4++) = *(tmp--);
      *(out4++) = *(tmp--);
      *(out4++) = *(tmp--);
      *(out4) = *(tmp);
      return;
   }

  unsigned char* c = (unsigned char*) &value ;

  unsigned char t ;
  t = c[0] ;
  c[0] = c[3] ;
  c[3] = t ;
  t = c[1] ;
  c[1] = c[2] ;
  c[2] = t ;
}


inline void CATStreamer::Convert(unsigned int & value, void * valueInBuffer)
{
   if(valueInBuffer)
   {
      // Conversion optimization when value in buffer is known.
      // It avoids swapping
      char *tmp = &((char *)valueInBuffer)[3];
      char *out4 = (char *)&value;
      *(out4++) = *(tmp--);
      *(out4++) = *(tmp--);
      *(out4++) = *(tmp--);
      *(out4) = *(tmp);
      return;
   }

   unsigned char* c = (unsigned char*) &value ;

  unsigned char t ;
  t = c[0] ;
  c[0] = c[3] ;
  c[3] = t ;
  t = c[1] ;
  c[1] = c[2] ;
  c[2] = t ;
}


inline void CATStreamer::Convert(float & value, void * valueInBuffer)
{
   if(valueInBuffer)
   {
      // Conversion optimization when value in buffer is known.
      // It avoids swapping
      char *tmp = &((char *)valueInBuffer)[3];
      char *out4 = (char *)&value;
      *(out4++) = *(tmp--);
      *(out4++) = *(tmp--);
      *(out4++) = *(tmp--);
      *(out4) = *(tmp);
      return;
   }

   unsigned char* c = (unsigned char*) &value ;

   unsigned char t ;
   t = c[0] ;
   c[0] = c[3] ;
   c[3] = t ;
   t = c[1] ;
   c[1] = c[2] ;
   c[2] = t ;
}

#ifndef PLATEFORME_DS64
inline void CATStreamer::Convert(CATLONG32 &  value, void * valueInBuffer)
{
  // sizeof (unsigned long)=8 sous Unix 64bits
  int size=sizeof(CATLONG32);

  if (valueInBuffer)
   {
      char *tmp = &((char *)valueInBuffer)[size-1];
      char *out4 = (char *)&value;
      for(int i=0;i<size;i++)
         *(out4++) = *(tmp--);
      return;
   }

  unsigned char* c = (unsigned char*) &value ;
  unsigned char t ;
  for(int i=0;i<size/2;i++)
  {
	  t=c[i];
	  c[i]=c[size-1-i];
	  c[size-1-i]=t;
  }
}

inline void CATStreamer::Convert(CATULONG32& value, void * valueInBuffer)
{
  //sizeof (unsigned long)=8 sous Unix 64bits
  int size=sizeof(CATULONG32);

  if (valueInBuffer)
   {
      char *tmp = &((char *)valueInBuffer)[size-1];
      char *out4 = (char *)&value;
      for(int i=0;i<size;i++)
         *(out4++) = *(tmp--);
      return;
   }

  unsigned char* c = (unsigned char*) &value ;
  unsigned char t ;
  for(int i=0;i<size/2;i++)
  {
	  t=c[i];
	  c[i]=c[size-1-i];
	  c[size-1-i]=t;
  }
}
#endif

inline void CATStreamer::Convert(double & value, void * valueInBuffer)
{
  /*sizeof (unsigned long)=8 sous Unix 64bits*/
  int size=sizeof(double);

  if (valueInBuffer)
   {
      char *tmp = &((char *)valueInBuffer)[size-1];
      char *out4 = (char *)&value;
      for(int i=0;i<size;i++)
         *(out4++) = *(tmp--);
      return;
   }

  unsigned char* c = (unsigned char*) &value ;
  unsigned char t ;
  for(int i=0;i<size/2;i++)
  {
	  t=c[i];
	  c[i]=c[size-1-i];
	  c[size-1-i]=t;
  }
}

inline void CATStreamer::ConvertFloat(float& value)
{
   Convert(value);
}

inline void CATStreamer::ConvertInt(int& value)
{
   Convert(value);
}

inline void CATStreamer::ConvertUInt(unsigned int& value)
{
   Convert(value);
}

inline void CATStreamer::ConvertULong(CATULONG32& value)
{
   Convert(value);
}

inline void CATStreamer::ConvertLong(CATLONG32& value)
{
   Convert(value);
}

inline void CATStreamer::ConvertDouble(double& value)
{
   Convert(value);
}

inline void CATStreamer::ConvertShort(short& value)
{
   Convert(value);
}

inline void CATStreamer::ConvertUShort(unsigned short& value)
{
   Convert(value);
}

inline int CATStreamer::FindIndex(void* object)
{
  if (!_adress_list_size)
      return -1;
  else
    {
      for (int i = 0;i<_adress_list_size;i++)
        if (objectList[i] == object)
          return i;
      return -1;
    }
}

inline void CATStreamer::unpackc(int &toread)
{
   if(_bitPacking)
   {
      ReadBits((unsigned int &)toread, _nbBitsPerVertex);
      return;
   }

   if (_cgrVersion >= 1100600)
   {
      if (_nbVertices < 256)
      {
         if (_current_position < _length)
         {
           toread = (_buffer[_current_position] & 0x000000FF);
           _current_position += sizeof(char);
         }
         else
         {
           _corrupted = 1;
           toread = 0;
         }
         return;
      }
   }
   if (_nbVertices < 65536)
   {
     if (_current_position + 2 <= _length)
     {
      toread = (_buffer[_current_position] <<8 & 0x0000FF00)
         |(_buffer[_current_position+1] & 0x000000FF);
      _current_position += 2*sizeof(char);
     }
     else
     {
       _corrupted = 1;
       toread = 0;
     }
   }
   else if (_nbVertices < 16777216)
   {
     if (_current_position + 3 <= _length)
     {
      toread = (_buffer[_current_position] <<16 & 0x00FF0000)
         |(_buffer[_current_position+1] <<8 & 0x0000FF00)
         |(_buffer[_current_position+2] & 0x000000FF);
      _current_position += 3*sizeof(char);
     }
     else
     {
       _corrupted = 1;
       toread = 0;
     }
   }
   else
      ReadInt(toread);
}

inline void CATStreamer::unpackc(unsigned char *indices, int nbIndices, int multiply)
{
   if(_bitPacking)
   {
      for (int i = 0 ; i < nbIndices ; ++i)
      {
         unsigned int tmp = 0;
         ReadBits(tmp, _nbBitsPerVertex);
         indices[i] = tmp*multiply;
      }
      return;
   }

   char * tmp = &_buffer[_current_position];
   if (_cgrVersion >= 1100600 && _nbVertices < 256)
   {
     if (_current_position + nbIndices <= _length)
     {
       for (int i = 0 ; i < nbIndices ; ++i)
       {
         *(indices++) = (*(tmp++) & 0x000000FF)*multiply;
       }
       _current_position += nbIndices*sizeof(char);
     }
     else
     {
       _corrupted = 1;
       if (indices)
        memset(indices, 0, nbIndices*sizeof(char));\
     }
   }
   else if (_nbVertices < 65536)
   {
     if (_current_position + 2*nbIndices <= _length)
     {
      for (int i = 0 ; i < nbIndices ; ++i)
      {
         *(indices++) = ((tmp[0] << 8 & 0x0000FF00) | (tmp[1] & 0x000000FF))*multiply;
         tmp += 2;
      }
      _current_position += 2*nbIndices*sizeof(char);
     }
     else
     {
       _corrupted = 1;
       if (indices)
         memset(indices, 0, nbIndices*sizeof(char));\
     }
   }
   else if (_nbVertices < 16777216)
   {
     if (_current_position + 3*nbIndices <= _length)
     {
      for (int i = 0 ; i < nbIndices ; ++i)
      {
         *(indices++) = ((tmp[0] << 16 & 0x00FF0000) | (tmp[1] << 8 & 0x0000FF00) | (tmp[2] & 0x000000FF))*multiply;
         tmp += 3;
      }
      _current_position += 3*nbIndices*sizeof(char);
     }
     else
     {
       _corrupted = 1;
       if (indices)
         memset(indices, 0, nbIndices*sizeof(char));\
     }
   }
   else
   {
      for (int i = 0 ; i < nbIndices ; ++i)
      {
         ReadInt((int &)*(indices));
         *(indices++) *= multiply;
      }
   }
}

inline void CATStreamer::unpackc(unsigned short *indices, int nbIndices, int multiply)
{
   if(_bitPacking)
   {
      for (int i = 0 ; i < nbIndices ; ++i)
      {
         unsigned int tmp = 0;
         ReadBits(tmp, _nbBitsPerVertex);
         indices[i] = tmp*multiply;
      }
      return;
   }

   char * tmp = &_buffer[_current_position];
   if (_cgrVersion >= 1100600 && _nbVertices < 256)
   {
     if (_current_position + nbIndices <= _length)
     {
      for (int i = 0 ; i < nbIndices ; ++i)
      {
         *(indices++) = (*(tmp++) & 0x000000FF)*multiply;
      }
      _current_position += nbIndices*sizeof(char);
     }
     else
     {
       _corrupted = 1;
       if (indices)
         memset(indices, 0, nbIndices*sizeof(short));\
     }
   }
   else if (_nbVertices < 65536)
   {
     if (_current_position + 2*nbIndices <= _length)
     {
      for (int i = 0 ; i < nbIndices ; ++i)
      {
         *(indices++) = ((tmp[0] << 8 & 0x0000FF00) | (tmp[1] & 0x000000FF))*multiply;
         tmp += 2;
      }
      _current_position += 2*nbIndices*sizeof(char);
     }
     else
     {
       _corrupted = 1;
       if (indices)
         memset(indices, 0, nbIndices*sizeof(short));\
     }
   }
   else if (_nbVertices < 16777216)
   {
     if (_current_position + 3*nbIndices <= _length)
     {
      for (int i = 0 ; i < nbIndices ; ++i)
      {
         *(indices++) = ((tmp[0] << 16 & 0x00FF0000) | (tmp[1] << 8 & 0x0000FF00) | (tmp[2] & 0x000000FF))*multiply;
         tmp += 3;
      }
      _current_position += 3*nbIndices*sizeof(char);
     }
     else
     {
       _corrupted = 1;
       if (indices)
         memset(indices, 0, nbIndices*sizeof(short));\
     }
   }
   else
   {
      for (int i = 0 ; i < nbIndices ; ++i)
      {
         ReadInt((int &)*(indices));
         *(indices++) *= multiply;
      }
   }
}

inline void CATStreamer::unpackc(unsigned int *indices, int nbIndices, int multiply)
{
   if(_bitPacking)
   {
      for (int i = 0 ; i < nbIndices ; ++i)
      {
         ReadBits((unsigned int &)indices[i], _nbBitsPerVertex);
         indices[i] *= multiply;
      }
      return;
   }

   char * tmp = &_buffer[_current_position];
   if (_cgrVersion >= 1100600 && _nbVertices < 256)
   {
     if (_current_position + nbIndices <= _length)
     {
      for (int i = 0 ; i < nbIndices ; ++i)
      {
         *(indices++) = (*(tmp++) & 0x000000FF)*multiply;
      }
      _current_position += nbIndices*sizeof(char);
     }
     else
     {
       _corrupted = 1;
       if (indices)
         memset(indices, 0, nbIndices*sizeof(int));\
     }
   }
   else if (_nbVertices < 65536)
   {
     if (_current_position + 2*nbIndices <= _length)
     {
      for (int i = 0 ; i < nbIndices ; ++i)
      {
         *(indices++) = ((tmp[0] << 8 & 0x0000FF00) | (tmp[1] & 0x000000FF))*multiply;
         tmp += 2;
      }
      _current_position += 2*nbIndices*sizeof(char);
     }
     else
     {
       _corrupted = 1;
       if (indices)
         memset(indices, 0, nbIndices*sizeof(int));\
     }
   }
   else if (_nbVertices < 16777216)
   {
     if (_current_position + 2*nbIndices <= _length)
     {
      for (int i = 0 ; i < nbIndices ; ++i)
      {
         *(indices++) = ((tmp[0] << 16 & 0x00FF0000) | (tmp[1] << 8 & 0x0000FF00) | (tmp[2] & 0x000000FF))*multiply;
         tmp += 3;
      }
      _current_position += 3*nbIndices*sizeof(char);
     }
     else
     {
       _corrupted = 1;
       if (indices)
         memset(indices, 0, nbIndices*sizeof(int));\
     }
   }
   else
   {
      for (int i = 0 ; i < nbIndices ; ++i)
      {
         ReadInt((int &)*(indices));
         *(indices++) *= multiply;
      }
   }
}


inline void CATStreamer::SetCurrentVersion (int version)
{
  _cgrVersion=version;
}

inline int  CATStreamer::GetCurrentVersion ()
{
  return _cgrVersion;
}

inline void CATStreamer::ReadBoundingPrimitive(float*bcenter, float*bdim, float*scenter, float &radius)
{
/*   float tab[10];
   ReadFloat(tab, 10);
   bcenter[0] = tab[0];
   bcenter[1] = tab[1];
   bcenter[2] = tab[2];
   bdim[0] = tab[3];
   bdim[1] = tab[4];
   bdim[2] = tab[5];
   scenter[0] = tab[6];
   scenter[1] = tab[7];
   scenter[2] = tab[8];
   radius = tab[9];
*/
   ReadFloat(bcenter,3);
   ReadFloat(bdim,3);
   ReadFloat(scenter,3);
   ReadFloat(radius);

}

inline CATINTPTR CATStreamer::RepToSave(CATRep *iRep)
{
  if (!iRep || !_noLineicPreProcessTable)
    return 1;

  void *toSave  = NULL;
  void *found   = NULL;
  found = (_noLineicPreProcessTable->Locate((void *)iRep,toSave));
  if (NULL == found)
    return 1;
  else
    return ((CATINTPTR)toSave);
}

inline short CATStreamer::GetBEStatus()
{
  return _invalidBE;
}

inline void CATStreamer::SetBEStatus(short iStatus)
{
  _invalidBE = iStatus;
}

inline int CATStreamer::IsBufferAllocated()
{
   return _bufferAllocated;
}



inline int CATStreamer::GetNumberOfVertices()
{
  return _nbVertices;
}

inline void CATStreamer::SetLightDataStreaming(unsigned int iOnOff)
{
   _lightDataStreaming = iOnOff;
}

inline unsigned int CATStreamer::LightDataStreaming()
{
   return _lightDataStreaming;
}

inline void CATStreamer::SetLightSceneGraph(unsigned int iOnOff)
{
   _lightSceneGraph = iOnOff;
}

inline unsigned int CATStreamer::LightSceneGraph()
{
   return _lightSceneGraph;
}

inline void CATStreamer::SetSmartLoading(unsigned int iOnOff)
{
   _smartLoading = iOnOff;
}

inline unsigned int CATStreamer::SmartLoading()
{
   return _smartLoading;
}

inline void CATStreamer::SetTargetLevel(CATVizSemanticLevel iTargetLevel)
{
   _targetLevel = iTargetLevel;
}

inline CATVizSemanticLevel CATStreamer::TargetLevel()
{
   return _targetLevel;
}

inline HRESULT CATStreamer::SetCurrentPosition(unsigned int pos)
{
   if(pos != _current_position && pos <= _length)
   {
      if(_stream && _directMode)
      {
         // We seek to the correct address
         // Seen with ADT, we give him a relative adress
         CATULONG64 newpos = 0;
         if(FAILED(_stream->Seek(pos, STREAM_SEEK_SET, &newpos)) || newpos != pos)
         //if(FAILED(_stream->Seek((long)pos-(long)_current_position, STREAM_SEEK_CUR, &newpos)) || newpos != pos)
            return E_FAIL;
      }
      else
         _isFirstRead = 0;

      _current_position = pos;
   }
   return S_OK;
}

inline int CATStreamer::GetCurrentPosition() const
{
  return _current_position;
}

inline void CATStreamer::Advance( int siz )
{
   SetCurrentPosition(_current_position + siz);
}

inline const void * CATStreamer::GetBuffer() const
{
  return _buffer;
}

inline CATULONG32 CATStreamer::GetLength() const
{
   return _length;
}

inline CATStream * CATStreamer::GetStream()
{
   return _stream;
}

inline void CATStreamer::SetConversion(unsigned char conv)
{
  _conversion = conv;
}


inline unsigned char CATStreamer::GetConversion()        const
{
  return _conversion;
}

inline void CATStreamer::SetCompressionFlags(int iCompressionFlags)
{
   _compressionFlags = iCompressionFlags;

   _bitBoolean = (_compressionFlags & BIT_BOOLEAN) ? 1 : 0;
   _bitPacking = (_compressionFlags & BIT_PACKING) ? 1 : 0;
   _intPacking = (_compressionFlags & INT_PACKING) ? 1 : 0;
   _gasPacking = (_compressionFlags & GAS_PACKING) ? 1 : 0;
}

inline int CATStreamer::GetCompressionFlags()
{
   return _compressionFlags;
}

inline  CATBoolean CATStreamer::ReadBit()
{
   if (_bitsRemaining)
   {
      CATBoolean bit = _bitContainer & 1;
      _bitContainer >>= 1;
      _bitsRemaining--;
      return bit;
   }
   else
   {
      CATBoolean bit;
      // Read a new bit container
      OldReadUInt(_bitContainer);
      bit = _bitContainer & 1;
      _bitContainer >>= 1;
      _bitsRemaining = 31;
      return bit;
   }
}

inline CATBoolean CATStreamer::ReadBoolean()
{
   CATBoolean bit;

   if (_bitBoolean)
   {
      bit = ReadBit();
   }
   else
   {
      ReadUChar(bit);
   }

   return bit;
}


inline void CATStreamer::SetUVR(CATVizUVRStreamOptions * uvrOptions)
{
   _uvrOptions = uvrOptions;
}

inline CATVizUVRStreamOptions * CATStreamer::GetUVR()
{
   return _uvrOptions;
}

#endif
