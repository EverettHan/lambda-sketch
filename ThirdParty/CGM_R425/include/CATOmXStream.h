#ifndef CATOmXStream_h
#define CATOmXStream_h
/**
 * @level Private
 * @usage U1
 *
 */
#include "CATPLMIdentificationAccess.h"
#include "CATOmXStreamDef.h"

#include "CATBooleanDef.h"
#include "CATErrorDef.h"
#include "CATCORBATypes.h"
#include "CATUnicodeString.h"

class CATStream;
class CATOxStreamer;
class CATILockBytes2;
class CATBinary;

/**
 * Base class of the stream and unstream operations.
 * Note: Do not use this this crap but directly CATOxStreamer (try also not to use CATOxStreamer...)
 */
class ExportedByCATPLMIdentificationAccess CATOmXStream 
{
public:
  /**
  * Constructs CATOmXStream for read only stream operation.
  *
  * @param iBuffer
  *  The memory area directly acceded for the read operation.
  *
  * @param iSizeBuffer
  *  The size in bytes of <tt>iBuffer</tt>.
  *
  */
  CATOmXStream(void* iBuffer, size_t iSizeBuffer,  const CATOmXStreamVersion  iVersion = CATOmXStreamVersion_CurrentSoftwareVersion);
  
  /**
  * Constructs CATOmXStream for read only stream operation.
  *
  * @param iBinary
  *  The memory area directly acceded for the read operation.
  */
  CATOmXStream(const CATBinary & iBinary, const CATOmXStreamVersion  iVersion = CATOmXStreamVersion_CurrentSoftwareVersion);
  
  /**
  * Constructs CATOmXStream for read only or write only stream operation.
  *
  * @param ioFile
  * The stream from which the stream is read.
  *
  * @param iAcces
  *  The kind of acces allowed on the CATOmXStream.
  * <br>The first acces of the stream may be done with <tt>OpenReadStreamHeader</tt> or <tt>OpenWriteStreamHeader</tt>.
  * <br>The last acces of the stream may be done with <tt>CloseReadStreamHeader</tt> or <tt>CloseWriteStreamHeader</tt>.
  *
  * @param iEnableByAddress
  *  Reserved for future use (do not change the default value)
  */
  CATOmXStream(const char*            iFilename,
               const CATOmXStreamAccess iAcces,
               const CATOmXStreamVersion  iVersion = CATOmXStreamVersion_CurrentSoftwareVersion,
               const CATOmXStreamEncoding iEncoding  = CATOmXStreamEncoding_Binary);

  /**
  * Constructs CATOmXStream for stream operation.
  *
  * @param iInitialNumberOfBytes
  *  The initial number of bytes for internal buffer.
  *
  * @param iAcces
  *  The kind of acces allowed on the CATOmXStream.
  *
  * @param iEnableByAddress
  *  Reserved for future use (do not change the default value)
  */
  CATOmXStream(size_t                 iInitialNumberOfBytes,
              const CATOmXStreamAccess iAcces,
              const CATOmXStreamVersion  iVersion = CATOmXStreamVersion_CurrentSoftwareVersion,
              const CATOmXStreamEncoding iEncoding  = CATOmXStreamEncoding_Binary);
  /**
  * @nodoc
  * Constructs CATOmXStream for read only or write only stream operation.
  *
  * @param iDirectStreaming
  * The stream from which the stream is read or writen.
  *
  * @param iAcces
  *  The kind of acces allowed on the CATOmXStream.
  * <br>The first acces of the stream may be done with <tt>OpenReadStreamHeader</tt> or <tt>OpenWriteStreamHeader</tt>.
  * <br>The last acces of the stream may be done with <tt>CloseReadStreamHeader</tt> or <tt>CloseWriteStreamHeader</tt>.
  *
  * @param iEnableByAddress
  *  Reserved for future use (do not change the default value)
  */
  CATOmXStream(CATStream              & iDirectStreaming,
               const CATOmXStreamAccess iAcces,
               const CATOmXStreamVersion  iVersion = CATOmXStreamVersion_CurrentSoftwareVersion);

  /** @nodoc */
  ~CATOmXStream();

  /**
  * Duplicate current Multi-area buffer in a contiguous CATBinary
  *
  * @param ioBinary
  *        The targetted contiguous area
  * @return
  *      E_INVALIDARG   : If invalid parameters
  *      E_ACCESSDENIED : If working mode is not compatible 
  *                       Supported configuration : CATOmXStreamStorage_memory + CATOmXStreamEncoding_Binary
  *      S_OK           : if succeeded
  *      E_FAIL         : if failure
  */
  HRESULT FillContiguousArea (CATBinary & ioBinary) const;

  /** 
  * Access to internal structure
  */
  inline CATOxStreamer* GetDefaultStreamer() {return &GetLetter();}
  inline CATOxStreamer& GetLetter() {return *_Streamer;}
private:
  CATOmXStream(CATILockBytes2* iLockBytes,const CATOmXStreamAccess iAcces,const CATOmXStreamVersion  iVersion = CATOmXStreamVersion_CurrentSoftwareVersion);
  CATOmXStream(const CATOmXStreamVersion iVersion);
  CATOmXStream();
  CATOmXStream(CATStream& iDirectStreaming,size_t iSizeStream,const CATOmXStreamVersion  iVersion = CATOmXStreamVersion_CurrentSoftwareVersion);
  CATOmXStream(const CATOmXStream & iCopy);
  CATOmXStream& operator=(const CATOmXStream & iCopy);

  CATOxStreamer* _Streamer;

};




#endif

