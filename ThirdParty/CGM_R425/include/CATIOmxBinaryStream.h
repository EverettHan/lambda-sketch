/**
 * @level Private
 * @usage U1
 */

#ifndef __CATIOmxBinaryStream_H
#define __CATIOmxBinaryStream_H

#include "CATBaseUnknown.h"
#include "CATDataType.h"
#include "CATOmxPortability.h"

/** Seek from beginning of the archive.*/
#define OMX_SEEK_BEG 1
/** Seek from end of the archive.*/
#define OMX_SEEK_END 2
/** Seek from current position of the archive.*/
#define OMX_SEEK_CUR 4

/**
* A basic binary stream interface.
*/
class CATIOmxBinaryStream: public CATBaseUnknown
{
public:

 /**
  * Seek in stream.
  *  @param iStart: use OMX_SEEK_BEG or OMX_SEEK_END or OMX_SEEK_CUR
  *  @param iOffset: the number of bytes to move forwards or backwards
  *                  depending on sign of iOffset.
  */
  virtual HRESULT Seek(int iStart,CATLONG64 iOffset)=0;
  
  /**
   * Write iByteCount bytes of iData into the archive.
   */
  virtual HRESULT Write(CATLONG64 iByteCount,const void* iData)=0;

  /**
   * Read iByteCount bytes from the archive and copy them in oData.
   * oByteCount contains in output the number of bytes read from the archive.
   *
   * In case of EOF, do not return failure but S_OK and set oByteCount to 
   * the number of bytes successfully read (can be 0)
   */
  virtual HRESULT Read(CATLONG64 iByteCount,void* oData,CATLONG64& oByteCount)=0;

  /**
   * returns current position of the stream.
   */ 
  virtual HRESULT GetCurrentPosition(CATLONG64& oPosition)=0;

  /**
   * Flush internal buffers.
   */ 
  virtual HRESULT Flush()=0;
};

#endif
