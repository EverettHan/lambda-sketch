//===================================================================
// COPYRIGHT Dassault Systemes 2018/05/18
//===================================================================
// CATOmxBinaryStreamInputWrapper.cpp
// Header definition of class CATOmxBinaryStreamInputWrapper
//===================================================================
//
// Usage notes:
//
// CATIOmxBinaryStream's wrapper which expose read methods only.
// This can be seen as the java DK's InputStream: https://docs.oracle.com/javase/7/docs/api/java/io/InputStream.html
//
//===================================================================
//  2018/05/18 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATOmxBinaryStreamInputWrapper_H
#define CATOmxBinaryStreamInputWrapper_H

#include "CATOmxInputOutput.h"
#include "CATIOmxInputStream.h"
#include "CATOmxSR.h"

class ExportedByCATOmxInputOutput CATOmxBinaryStreamInputWrapper: public CATIOmxInputStream
{
public:
  CATOmxBinaryStreamInputWrapper(CATIOmxBinaryStream& iWrappedStream);
  virtual ~CATOmxBinaryStreamInputWrapper();

  /**
  * Seek in stream.
  *  @param iStart: use OMX_SEEK_BEG or OMX_SEEK_END or OMX_SEEK_CUR
  *  @param iOffset: the number of bytes to move forwards or backwards
  *                  depending on sign of iOffset.
  */
  HRESULT Seek(int iStart, CATLONG64 iOffset) OMX_Cxx11_OVERRIDE;

  /**
  * Read iByteCount bytes from the archive and copy them in oData.
  * oByteCount contains in output the number of bytes read from the archive.
  *
  * In case of EOF, do not return failure but S_OK and set oByteCount to
  * the number of bytes successfully read (can be 0)
  */
  HRESULT Read(CATLONG64 iByteCount, void* oData, CATLONG64& oByteCount) OMX_Cxx11_OVERRIDE;

  /**
  * Returns current position of the stream.
  */
  HRESULT GetCurrentPosition(CATLONG64& oPosition) OMX_Cxx11_OVERRIDE;

  /**
  * Flush internal buffers.
  */
  HRESULT Flush() OMX_Cxx11_OVERRIDE;

private:
  CATOmxSR<CATIOmxBinaryStream> _spWrappedStream;
};

#endif