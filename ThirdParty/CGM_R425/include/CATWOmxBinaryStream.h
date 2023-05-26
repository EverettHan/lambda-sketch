#ifndef __CATWOmxBinaryStream_H
#define __CATWOmxBinaryStream_H

#include "CATOmxKernel.h"
#include "CATOmxPortability.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxKind.h"
#include "CATOmxSR.h"
#include <stdio.h>

class CATIOmxBinaryStream;
class CATUnicodeString;
class CATOmxKeyString;
class CATUuid;
class CATOmxAny;
class CORBAAny;
class _SEQUENCE_octet;
class CATBinary;
class CATOmxBaseArray;
class CATStream;
class CATILockBytes2;
class CATOmxKeyValueBlock;
class CATOmxUTF8String;
template<typename T, CATOmxCollecManagerLocator M> class CATOmxArray;
template<typename K, typename V, CATOmxCollecManagerLocator KM, CATOmxCollecManagerLocator VM> class CATOmxOMap;
template<> Exporting  CATOmxCollecManager& CATOmxDefaultCollecManager<CATUuid>::manager();
template<> Exporting  CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmxKeyString>::manager();
class CATIOmxBinaryStreamDictionary;

/**endianness management*/
enum CATOmxEndianness { omx_big_endian = 0, omx_little_endian = 1, omx_unknown_endian = 2 };

/** compatibility box with other streaming classes.*/
enum CATOmxCompatibilityMode
{
  /** default mode (sane and natural)*/
  omx_compat_none,
  /** XDataArchive compatibility (legacy purpose)*/
  omx_compat_xdata,
  /** CATStreamDefinition compatibility (legacy purpose)*/
  omx_compat_omb,
  /** CATOmbStreamHelper/CATOmsStreamHelper (legacy purpose)*/
  omx_compat_oms,
  /**
   * Enable some kind of compression.
   * This does not mean at all a zip'ed content.
   * Typically we try to write very frequent "little" integers on one single byte (WriteSize format is used everywhere).
   * Notice that by using this mode, all comments on numbers of bytes used and on compatibility between signed/unsigned APIs become wrong
   */
  omx_compression1
};

/**
 * CATOmxKind persistency managament.
 * These values are guaranted at the contrary af CATOmxKind enum values.
 */
typedef unsigned char OMX_PERSISTENT_KIND;

#define OMXPK_COMPLEX (1<<5)
#define OMXPK_LIST    (1<<6)

#define OMXPK_VOID   ((OMX_PERSISTENT_KIND)(  1 ))
#define OMXPK_BOOL   ((OMX_PERSISTENT_KIND)(  2 ))
#define OMXPK_OCTET  ((OMX_PERSISTENT_KIND)(  3 ))
#define OMXPK_INT    ((OMX_PERSISTENT_KIND)(  4 ))
#define OMXPK_DOUBLE ((OMX_PERSISTENT_KIND)(  5 ))
#define OMXPK_STRING ((OMX_PERSISTENT_KIND)(  6 ))
#define OMXPK_UUID   ((OMX_PERSISTENT_KIND)(  7 ))
#define OMXPK_INT64  ((OMX_PERSISTENT_KIND)(  8 ))
#define OMXPK_ID     ((OMX_PERSISTENT_KIND)(  9 ))
#define OMXPK_TIME   ((OMX_PERSISTENT_KIND)(  10))
#define OMXPK_ENUM   ((OMX_PERSISTENT_KIND)(  11))

#define OMXPK_TECHNO ((OMX_PERSISTENT_KIND)( 13|OMXPK_COMPLEX))
#define OMXPK_ERROR  ((OMX_PERSISTENT_KIND)( 14|OMXPK_COMPLEX))
#define OMXPK_COMPO  ((OMX_PERSISTENT_KIND)( 15|OMXPK_COMPLEX))
#define OMXPK_SPEC   ((OMX_PERSISTENT_KIND)( 16|OMXPK_COMPLEX))
#define OMXPK_ATTR   ((OMX_PERSISTENT_KIND)( 17|OMXPK_COMPLEX))
#define OMXPK_EXT    ((OMX_PERSISTENT_KIND)( 18|OMXPK_COMPLEX))
#define OMXPK_ANY    ((OMX_PERSISTENT_KIND)( 19|OMXPK_COMPLEX))

#define OMXPK_LAST   ((OMX_PERSISTENT_KIND)( 24|OMXPK_COMPLEX))

/**
 * Wrapper on CATIOmxBinaryStream (raw binary stream abstraction).
 * It manages streaming/unstreaming of all raw C-types and of various Sytsem/ObjectModelerCollection data structures.
 * Endianness can be managed as wanted (using platform endianness or an invariant one).
 * It is designed to replace some similar binary stream helpers (CATSpecStream/CATStreamDefinition/CATOmsStreamHelper...)
 * CATOmxCompatibilityMode allows to stream datas with the same binary result as with these classes.
 * It uses named methods (Write[Int|Double...] instead of << operators in order to avoid ambiguities but all methods returning this
 * you can pipe them (stream.WriteInt(1).WriteString("a string").WriteDouble(1.5) ....
 * GetState contains the first error code that has been returned.
 */
class ExportedByCATOmxKernel CATWOmxBinaryStream
{
  CATIOmxBinaryStream* m_stream;
  HRESULT m_state;
  unsigned char m_version;
  CATBoolean m_switchEndianness;
  CATBoolean m_dummyStream;
  CATOmxSR<CATIOmxBinaryStreamDictionary> m_dictionary;
  CATOmxEndianness m_endianness;
  CATOmxCompatibilityMode m_mode;
public:
  /** Set raw stream.*/
  void SetStream(CATIOmxBinaryStream* iStream);
protected:
  /**
   * override this method to trap failures.
   */
  virtual void OnError(HRESULT iHR, const char* iWhere);
public:
  /** constructor from a CATIOmxBinaryStream*/
  CATWOmxBinaryStream(CATIOmxBinaryStream* iArchive = NULL);

  /** Get raw stream.*/
  CATIOmxBinaryStream* GetStream();

  /** Returns the first error code that has been detected.*/
  inline HRESULT GetState() const { return m_state; }

  /** Returns the first error code that has been detected.*/
  inline operator HRESULT() const { return m_state; }

  /** Resets the state of the object, use with care*/
  inline void SetState(HRESULT hr) { m_state = hr; }

  /** Returns current position in the stream.*/
  CATLONG64 GetCurrentPosition();

  /** Seek (see CATIOmxBinaryStream::Seek).*/
  CATWOmxBinaryStream& Seek(int iOrigin, CATLONG64 iOffset);

  /** Seek to absolute offset iOffset.*/
  CATWOmxBinaryStream& AbsoluteSeek(CATLONG64 iOffset);

  /** Flush underlying stream (see CATIOmxBinaryStream::Flush).*/
  CATWOmxBinaryStream& Flush();

  /** Returns stream endianness.*/
  inline CATOmxEndianness GetStreamEndianness() const { return m_endianness; }

  /** Returns OS endianness.*/
  static CATOmxEndianness GetOSEndianness();

  /** Returns TRUE if Os and stream endianness are diferent.*/
  inline CATBoolean MustSwitchEndianness() const { return m_switchEndianness; }

  /** Set stream endianness.*/
  void SetEndianness(CATOmxEndianness iEndianness);

  /** Set compatibility mode to iMode. Allows to read/write datas compatible with corresponding streaming class.*/
  void SetCompatibilityMode(CATOmxCompatibilityMode iMode);

  /** Get compatibility mode.*/
  inline CATOmxCompatibilityMode GetCompatibilityMode() const { return m_mode; }

  /** Get string dictionary.*/
  inline CATIOmxBinaryStreamDictionary* GetDictionary() { return m_dictionary; }
  /** Set string dictionary.*/
  CATWOmxBinaryStream& SetDictionary(CATIOmxBinaryStreamDictionary* iDictionary);
  /** Enable a string dictionary.*/
  CATWOmxBinaryStream& EnableDictionary();

  /** Write a byte.*/
  inline CATWOmxBinaryStream& WriteByte(unsigned char b) { return WriteBytes(&b, 1); }
  /** Read a byte.*/
  inline CATWOmxBinaryStream& ReadByte(unsigned char& b) { return ReadBytes(&b, 1); }

  /** Write a byte.*/
  inline CATWOmxBinaryStream& WriteByte(char b) { return WriteBytes(&b, 1); }
  /** Read a byte.*/
  inline CATWOmxBinaryStream& ReadByte(char& b) { return ReadBytes(&b, 1); }

  /** Write an array of bytes.*/
  CATWOmxBinaryStream& WriteBytes(const void* b, CATLONG64 size);
  /** Read an array of bytes.*/
  CATWOmxBinaryStream& ReadBytes(void* b, CATLONG64 size);

  /**
   * Writes an encoded size.
   * Uses N bytes to write an integer where N is the smaller integer as iSize<128^N.
   * Not compatible with ReadInt/ReadLong.
   */
  CATWOmxBinaryStream& WriteSize(unsigned int iSize);
  CATWOmxBinaryStream& WriteSize64(CATULONG64 iSize);

  /** Read a size written by WriteSize*/
  CATWOmxBinaryStream& ReadSize(unsigned int& oSize);
  inline CATWOmxBinaryStream& ReadSize(int& oSize) { return ReadSize((unsigned int&)oSize); }
  CATWOmxBinaryStream& ReadSize64(CATULONG64& oSize);
  inline CATWOmxBinaryStream& ReadSize64(CATLONG64& oSize) { return ReadSize64((CATULONG64&)oSize); }

  /** Write a char (1 byte).*/
  inline CATWOmxBinaryStream& WriteChar(char i) { return WriteBytes(&i, 1); }
  /** Read a char (1 byte).*/
  inline CATWOmxBinaryStream& ReadChar(char& i) { return ReadBytes(&i, 1); }

  /** Write a short (2 bytes).*/
  CATWOmxBinaryStream& WriteShort(short i);
  /** Read a short (2 bytes).*/
  CATWOmxBinaryStream& ReadShort(short& i);

  /** Write an int (4 bytes).*/
  CATWOmxBinaryStream& WriteInt(CATINT32 i);
  /** Read an int (4 bytes).*/
  CATWOmxBinaryStream& ReadInt(CATINT32& i);

  /** Write a 64bits integer (8 bytes).*/
  CATWOmxBinaryStream& WriteInt64(CATLONG64 i);
  /** Read a 64bits integer (8 bytes).*/
  CATWOmxBinaryStream& ReadInt64(CATLONG64& i);

  /** Write a float (4 bytes).*/
  CATWOmxBinaryStream& WriteFloat(float i);
  /** Read a float (4 bytes).*/
  CATWOmxBinaryStream& ReadFloat(float& i);

  /** Write a double (8 bytes).*/
  CATWOmxBinaryStream& WriteDouble(double i);
  /** Read a double (8 bytes).*/
  CATWOmxBinaryStream& ReadDouble(double& i);

  /**
   * System data structure streaming.
   */

   /** Write a CATUnicodeString.*/
  CATWOmxBinaryStream& WriteString(const CATUnicodeString& str,/*internal use*/CATBoolean corbaAnyCall = FALSE);
  /** Read a CATUnicodeString.*/
  CATWOmxBinaryStream& ReadString(CATUnicodeString& str,/*internal use*/CATBoolean corbaAnyCall = FALSE);

  /** Write an uuid (16 bytes). Notice an uuid has no endianness.*/
  CATWOmxBinaryStream& WriteUuid(const CATUuid& uuid);
  /** Read an uuid (16 bytes). Notice an uuid has no endianness.*/
  CATWOmxBinaryStream& ReadUuid(CATUuid& uuid);

  /** Write a CATBinary.*/
  CATWOmxBinaryStream& WriteBinary(const CATBinary& bin);
  /** Read a CATBinary.*/
  CATWOmxBinaryStream& ReadBinary(CATBinary& bin);

  /**
   * Omb data structure streaming.
   */
   /** Write a CORBAAny.*/
  CATWOmxBinaryStream& WriteCORBAAny(const CORBAAny& any);
  /** Read a CORBAAny.*/
  CATWOmxBinaryStream& ReadCORBAAny(CORBAAny& any);

  /** Write a _SEQUENCE_octet.*/
  CATWOmxBinaryStream& WriteSequence(const _SEQUENCE_octet& seq);
  /** Read a _SEQUENCE_octet.*/
  CATWOmxBinaryStream& ReadSequence(_SEQUENCE_octet& seq);

  /**
   * Omx data structure streaming.
   */
   /** Write a CATOmxKeyString.*/
  CATWOmxBinaryStream& WriteKeyString(const CATOmxKeyString& str);
  /** Read a CATOmxKeyString.*/
  CATWOmxBinaryStream& ReadKeyString(CATOmxKeyString& str);

  /** Write a CATOmxArray of byte.*/
  inline CATWOmxBinaryStream& WriteByteArray(const CATOmxArray<unsigned char, CATOmxDefaultCollecManager<unsigned char>::manager>& array) { return WriteArray(reinterpret_cast<const CATOmxBaseArray&>(array), CATOmxDefaultCollecManager<unsigned char>::manager); }
  /** Read a CATOmxArray of byte.*/
  inline CATWOmxBinaryStream& ReadByteArray(CATOmxArray<unsigned char, CATOmxDefaultCollecManager<unsigned char>::manager>& array) { return ReadArray(reinterpret_cast<CATOmxBaseArray&>(array), CATOmxDefaultCollecManager<unsigned char>::manager); }

  /** Write a CATOmxArray of integers.*/
  CATWOmxBinaryStream& WriteIntArray(const CATOmxArray<CATINT32, CATOmxDefaultCollecManager<CATINT32>::manager>& array);
  /** Read a CATOmxArray of integers.*/
  CATWOmxBinaryStream& ReadIntArray(CATOmxArray<CATINT32, CATOmxDefaultCollecManager<CATINT32>::manager>& array);

  /** Write a CATOmxArray of 64 bits integers.*/
  CATWOmxBinaryStream& WriteInt64Array(const CATOmxArray<CATLONG64, CATOmxDefaultCollecManager<CATLONG64>::manager>& array);
  /** Read a CATOmxArray of 64 bits integers.*/
  CATWOmxBinaryStream& ReadInt64Array(CATOmxArray<CATLONG64, CATOmxDefaultCollecManager<CATLONG64>::manager>& array);

  /** Write a CATOmxArray of double.*/
  CATWOmxBinaryStream& WriteDoubleArray(const CATOmxArray<double, CATOmxDefaultCollecManager<double>::manager>& array);
  /** Read a CATOmxArray of double.*/
  CATWOmxBinaryStream& ReadDoubleArray(CATOmxArray<double, CATOmxDefaultCollecManager<double>::manager>& array);

  /** Write a CATOmxArray of CATUnicodeString.*/
  CATWOmxBinaryStream& WriteStringArray(const CATOmxArray<CATUnicodeString, CATOmxDefaultCollecManager<CATUnicodeString>::manager>& array);
  /** Read a CATOmxArray of CATUnicodeString.*/
  CATWOmxBinaryStream& ReadStringArray(CATOmxArray<CATUnicodeString, CATOmxDefaultCollecManager<CATUnicodeString>::manager>& array);

  /** Write a CATOmxArray of CATOmxKeyString.*/
  CATWOmxBinaryStream& WriteKeyStringArray(const CATOmxArray<CATOmxKeyString, CATOmxDefaultCollecManager<CATOmxKeyString>::manager>& array);
  /** Read a CATOmxArray of CATOmxKeyString.*/
  CATWOmxBinaryStream& ReadKeyStringArray(CATOmxArray<CATOmxKeyString, CATOmxDefaultCollecManager<CATOmxKeyString>::manager>& array);

  /** Write a CATOmxArray of CATUuid.*/
  CATWOmxBinaryStream& WriteUuidArray(const CATOmxArray<CATUuid, CATOmxDefaultCollecManager<CATUuid>::manager>& array);
  /** Read a CATOmxArray of CATUuid.*/
  CATWOmxBinaryStream& ReadUuidArray(CATOmxArray<CATUuid, CATOmxDefaultCollecManager<CATUuid>::manager>& array);

  /** Write a CATOmxOMap<CATOmxKeyString,CATOmxAny> (@see #WriteAny limitations).*/
  CATWOmxBinaryStream& WriteMap(const CATOmxOMap<CATOmxKeyString, CATOmxAny, CATOmxDefaultCollecManager<CATOmxKeyString>::manager, CATOmxDefaultCollecManager<CATOmxAny>::manager>&);
  /** Read a CATOmxOMap<CATOmxKeyString,CATOmxAny>  (@see #WriteAny limitations).*/
  CATWOmxBinaryStream& ReadMap(CATOmxOMap<CATOmxKeyString, CATOmxAny, CATOmxDefaultCollecManager<CATOmxKeyString>::manager, CATOmxDefaultCollecManager<CATOmxAny>::manager>&, CATBoolean iKeepOldItems = FALSE);


  /** Write a CATOmxKeyValueBlock (@see #WriteAny limitations).*/
  CATWOmxBinaryStream& WriteBlock(const CATOmxKeyValueBlock&);
  /** Read a CATOmxKeyValueBlock  (@see #WriteAny limitations).*/
  CATWOmxBinaryStream& ReadBlock(CATOmxKeyValueBlock&);

  /**
   * Write a CATOmxAny.
   * CAUTION: only basic types are supported: bool/octet/int/int64/double/string/identifier/uuid.
   * Notice also that extended kinds are not supported (just skipped).
   * There is an exception for (standard) omx_enum/omx_time values which are fully supported.
   */
  CATWOmxBinaryStream& WriteAny(const CATOmxAny& any);
  /** Read a CATOmxAny (@see #WriteAny limitations).*/
  CATWOmxBinaryStream& ReadAny(CATOmxAny& any);

  /** Return persistent value of CATOmxKind iKind.*/
  static OMX_PERSISTENT_KIND EncodeKind(CATOmxKind iKind);
  /** Return CATOmxKind value of persistent value iByte.*/
  static CATOmxKind    DecodeKind(OMX_PERSISTENT_KIND iByte);

  /**
   * Unsigned versions (binary compatible with signed versions).
   */
   /** Write an unsigned char.*/
  inline CATWOmxBinaryStream& WriteUChar(unsigned char b) { return WriteBytes(&b, 1); }
  /** Read an unsigned char.*/
  inline CATWOmxBinaryStream& ReadUChar(unsigned char& b) { return ReadBytes(&b, 1); }

  /** Write an unsigned short.*/
  CATWOmxBinaryStream& WriteUShort(unsigned short i);
  /** Read an unsigned short.*/
  CATWOmxBinaryStream& ReadUShort(unsigned short& i);

  /** Write an unsigned integer.*/
  CATWOmxBinaryStream& WriteUInt(CATUINT32 i);
  /** Read an unsigned integer.*/
  CATWOmxBinaryStream& ReadUInt(CATUINT32& i);

  /** Write an unsigned 64 bit integer.*/
  CATWOmxBinaryStream& WriteUInt64(CATULONG64 i);
  /** Read an unsigned 64 bit integer.*/
  CATWOmxBinaryStream& ReadUInt64(CATULONG64& i);

  /** see WriteStream(CATIOmxBinaryStream& ).*/
  inline CATWOmxBinaryStream& WriteStream(CATWOmxBinaryStream& iStream) { return WriteStream(*iStream.GetStream()); }
  /** Write at the end of this stream content of of iStream (from its current position to its end) .*/
  CATWOmxBinaryStream& WriteStream(CATIOmxBinaryStream& iStream);

  /**
   * Legacy methods from CATSpecStream/CATStreamDefinition/CATOmsStreamHelper.
   */

   /** see WriteBytes.*/
  inline CATWOmxBinaryStream& WriteUChar(const void* b, CATLONG64 count) { return WriteBytes(b, count); }
  /** see ReadBytes.*/
  inline CATWOmxBinaryStream& ReadUChar(void* b, CATLONG64 count) { return ReadBytes(b, count); }

  /** see WriteInt. */
  inline CATWOmxBinaryStream& WriteLong(CATLONG32 i) { return WriteInt((CATINT32)i); }
  /** see ReadInt. */
  inline CATWOmxBinaryStream& ReadLong(CATLONG32& i) { return ReadInt((CATINT32&)i); }

  /** see WriteUInt. */
  inline CATWOmxBinaryStream& WriteULong(CATULONG32 i) { return WriteUInt((CATUINT32)i); }
  /** see ReadUInt. */
  inline CATWOmxBinaryStream& ReadULong(CATULONG32& i) { return ReadUInt((CATUINT32&)i); }

  /** see WriteString. */
  inline CATWOmxBinaryStream& WriteUnicode(const CATUnicodeString& str) { return WriteString(str); }
  /** see ReadString. */
  inline CATWOmxBinaryStream& ReadUnicode(CATUnicodeString& str) { return ReadString(str); }

  /** see WriteCORBAAny. */
  inline CATWOmxBinaryStream& WriteAny(const CORBAAny& any) { return WriteCORBAAny(any); }
  /** see ReadCORBAAny. */
  inline CATWOmxBinaryStream& ReadAny(CORBAAny& any) { return ReadCORBAAny(any); }

  /*if true set endianness to the opposite of OS endianness.*/
  CATWOmxBinaryStream& SetConversion(CATBoolean iConvertEndianness);

  /*returns true if next byte in stream is equal to iValue. In this case byte is "eaten".*/
  CATBoolean PeekValue(unsigned char iValue);

  /**
   * Write some informations on current implementation used.
   * Endianness is set to little endian.
   * If iUseStringDictionary is used then all CATOmxKeyString written are stored in a dictionary
   * which will be written in EndWriteArchive.
   * This allows to replace
   *     N streaming of the string (which calls WriteSize)
   *  by
   *     1 streaming of the string + N WriteSize
   * and reduce the size of the stream.
   */
  HRESULT BeginWriteArchive(int iUseStringDictionary = 0);
  /** Must be called at the very end of the streaming procedure if BeginWriteArchive has been called*/
  HRESULT EndWriteArchive();

  /** Must be called at the very beginning of the unstreaming if BeginWriteArchive was called when streaming.*/
  HRESULT BeginReadArchive();
  /** Must be called at the very end of the unstreaming if BeginReadArchive was called.*/
  HRESULT EndReadArchive();

  /** Returns "standard" "optimal" buffer size (128ko) */
  static int GetOptimalBufferSize();

  /**
   * Create a memory buffer raw stream (read-write).
   * You can specify the buffer used.
   * Must be released by caller.
   */
  static CATIOmxBinaryStream* CreateMemoryStream(char* iBuffer = NULL, CATLONG64 iBufferSize = -1);

  /**
   * Create a CATIOmxBinaryStream wrapper on a CATStream.
   */
  static CATIOmxBinaryStream* CreateOmxStreamOnCATStream(CATStream& iStream, CATLONG64 iMaxSize = -1, CATLONG64 iBufferSize = -1);

  /**
   * Create a CATIOmxBinaryStream wrapper on a FILE.
   * @param iMustClose
   *   if true, close(iFile) will be called when deleting the CATIOmxBinaryStream object
   */
  static CATIOmxBinaryStream* CreateFileStream(FILE* iFile, CATBoolean iMustClose);

  /**
   * Create a CATIOmxBinaryStream wrapper on a file.
   * @param iPath
   *   Path of the file to open
   * @param iMode
   *  Open mode using fopen  convention.
   * @param oStream
   *   Opened stream
   */
  static HRESULT CreateFileStream(const CATUnicodeString& iPath, const char* iMode, CATOmxSR<CATIOmxBinaryStream>& oStream);


  /**
   * Create a CATOmxBoundedStream wrapped on a CATIOmxBinaryStream
   * @param iStart
   *   index to start the bound
   * @param iEnd
   *  index where the bound ends
   * @param oBoundedStream
   *   the created bounded stream, implemented by CATOmxBoundedStream
   */
  static HRESULT CreateBoundedStream(const CATIOmxBinaryStream& iStream, CATLONG64 iStart, CATLONG64 iEnd, CATOmxSR<CATIOmxBinaryStream>& oBoundedStream);

  /**
   * Bind to a CATIOmxBinaryStream wrapper on a memory buffer.
   * See CreateMemoryStream.
   * @param iMustDelete
   *   if true, iBuffer will be delete[]'d when underlying stream will die.
   */
  CATWOmxBinaryStream& BindToMemoryStream(char* iBuffer = NULL, CATLONG64 iBufferSize = -1);
  CATWOmxBinaryStream& BindToMemoryStream(char* iBuffer, CATLONG64 iBufferSize, CATBoolean iMustDelete);

  /**
   * Bind to a CATIOmxBinaryStream wrapper on a CATStream.
   * See CreateOmxStreamOnCATStream.
   */
  CATWOmxBinaryStream& BindToCATStream(CATStream& iStream, CATLONG64 iMaxSize = -1, CATLONG64 iBufferSize = -1);

  /**
   * Bind to a CATIOmxBinaryStream wrapper on a file.
   * See CreateFileStream.
   */
  CATWOmxBinaryStream& BindToFile(const CATUnicodeString& iPath, const char* iMode);

  /**
   * Bind to a CATIOmxBinaryStream wrapper on a CATILockBytes2 object.
   * You are responsible for opening of the CATILockBytes2 in the appropriate mode.
   * @param iCloseOnDelete
   *   if true, CATILockBytes2::Close will be closed automatically when the CATIOmxBinaryStream will be destroyed
   */
  CATWOmxBinaryStream& BindToILockBytes2(CATILockBytes2& iILB2, int iCloseOnDelete);

  /**
   * Steal the memory buffer from the raw stream created by previous method.
   * oBuffer must be deleted by delete[]
   */
  inline HRESULT GetMemoryStreamBuffer(CATBoolean steal, char*& oBuffer, CATLONG64& oBufferSize) { return GetMemoryStreamBuffer(m_stream, steal, oBuffer, oBufferSize); }

  /** static version of previous method*/
  static HRESULT GetMemoryStreamBuffer(CATIOmxBinaryStream* iStream, CATBoolean steal, char*& oBuffer, CATLONG64& oBufferSize);

  /** Reallocate memory buffer if one.*/
  CATWOmxBinaryStream& Reallocate(CATLONG64 iNewLen);

  /** Returns stream size (starting from current position)*/
  static HRESULT GetSize(CATIOmxBinaryStream* iStream, CATLONG64& oSize);

  /** Set the stream in failure mode*/
  CATWOmxBinaryStream& ReturnFailure(HRESULT hr, const char* iWhere = NULL);

  /**Write a numeric C type as-is with endianness management. Warning iNum may be modified*/
  CATWOmxBinaryStream& WriteNumeric(void* iNum, size_t sizeOf);
  /**Read a numeric C type as-is with endianness management*/
  CATWOmxBinaryStream& ReadNumeric(void* iNum, size_t sizeOf);

  /** destructor.*/
  ~CATWOmxBinaryStream();
private:
  CATWOmxBinaryStream(const CATWOmxBinaryStream&);
  CATWOmxBinaryStream& operator=(const CATWOmxBinaryStream&);

  /**Stub to delete*/
  CATWOmxBinaryStream& WriteCType(void* iObj, CATUINT32 sizeOf);
  /**Stub to delete*/
  CATWOmxBinaryStream& ReadCType(void* iObj, CATUINT32 sizeOf);

  CATWOmxBinaryStream& WriteArray(const CATOmxBaseArray& iArray, CATOmxCollecManagerLocator locator);
  CATWOmxBinaryStream& ReadArray(CATOmxBaseArray& oArray, CATOmxCollecManagerLocator locator);
};

#endif

