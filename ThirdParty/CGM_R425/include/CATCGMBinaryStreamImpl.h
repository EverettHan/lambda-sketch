/* -*-c++-*- */
#ifndef CATCGMBinaryStreamImpl_h
#define CATCGMBinaryStreamImpl_h

// class that wrap abstraction class CATIOmxBinaryStream 

#include "CATDataType.h"
#include "CATCGMBinaryStream.h"
#include "CATIOmxBinaryStream.h"


class CATCGMBinaryStreamImpl : public CATCGMBinaryStream
{
public : 
  CATCGMBinaryStreamImpl(CATIOmxBinaryStream * iStream);
  virtual ~CATCGMBinaryStreamImpl();


  // methods in CATIOmxBinaryStream
  HRESULT Seek(int iStart,CATLONG64 iOffset);
  HRESULT Write(CATLONG64 iByteCount,const void* iData);
  HRESULT Read(CATLONG64 iByteCount,void* oData,CATLONG64& oByteCount);
  HRESULT GetCurrentPosition(CATLONG64& oPosition);
  HRESULT Flush();

private :
  CATIOmxBinaryStream * _OmxBinaryStream;
};


#endif


