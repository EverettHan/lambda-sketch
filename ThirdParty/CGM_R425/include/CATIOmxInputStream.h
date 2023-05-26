//===================================================================
// COPYRIGHT Dassault Systemes 2018/05/18
//===================================================================
// CATIOmxInputStream.cpp
// Header definition of class CATIOmxInputStream
//===================================================================
//
// Usage notes:
//
// CATIOmxBinaryStream's interface which expose read methods only.
// This can be seen as the java DK's InputStream: https://docs.oracle.com/javase/7/docs/api/java/io/InputStream.html
//
//===================================================================
//  2018/05/18 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATIOmxInputStream_H
#define CATIOmxInputStream_H

#include "CATOmxInputOutput.h"
#include "CATIOmxBinaryStream.h"
#include "CATOmxCxxPortability.h"

class ExportedByCATOmxInputOutput CATIOmxInputStream : public CATIOmxBinaryStream
{
public:
  virtual ~CATIOmxInputStream();

  /**
  * Seek in stream.
  *  @param iStart: use OMX_SEEK_BEG or OMX_SEEK_END or OMX_SEEK_CUR
  *  @param iOffset: the number of bytes to move forwards or backwards
  *                  depending on sign of iOffset.
  */
  virtual HRESULT Seek(int iStart, CATLONG64 iOffset) = 0;

  /**
  * Read iByteCount bytes from the archive and copy them in oData.
  * oByteCount contains in output the number of bytes read from the archive.
  *
  * In case of EOF, do not return failure but S_OK and set oByteCount to
  * the number of bytes successfully read (can be 0)
  */
  virtual HRESULT Read(CATLONG64 iByteCount, void* oData, CATLONG64& oByteCount) = 0;

  /**
  * Returns current position of the stream.
  */
  virtual HRESULT GetCurrentPosition(CATLONG64& oPosition) = 0;

  /**
  * Flush internal buffers.
  */
  virtual HRESULT Flush() = 0;

private:
  // Not implemented since this is an InputStream
  HRESULT Write(CATLONG64 iByteCount, const void* iData) OMX_Cxx11_FINAL { return E_NOTIMPL; }
};

#endif