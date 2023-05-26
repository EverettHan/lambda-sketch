/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2001  
#ifndef CATCgrStream_H
#define CATCgrStream_H

/**
 * @level Private
 * @usage U1
 */

#include "CGRSTREAM.h"
#include "CATNmdFile.h"
#include "AC0XXLNK.h"

extern "C" ExportedByCATCGRStream
HRESULT CATGetCgrStream(const char* iFilePath,
						const CATULONG32  iAllocatedSize,
						void* iAllocatedBuffer, CATULONG32 * oRealSize );

extern "C" ExportedByCATCGRStream
HRESULT CATGetCgrStreamSize(const char* iFilePath, CATULONG32 * oBufferSize );

class CATCGRStreamGetterImpl;
class CATDocument;


// if you want to use the Size method then use the GetStream method, then use an instance of CATCgrStreamGetter
// allocated on the stack, this way seeking the actual storage is done only once instead of twice.
class ExportedByAC0XXLNK CATCGRStreamGetter
{
  CATCGRStreamGetter(const CATCGRStreamGetter&);
  CATCGRStreamGetter& operator=(const CATCGRStreamGetter&);
public:
  CATCGRStreamGetter(const CATDocument* iDoc);
  ~CATCGRStreamGetter();

  // you can either call these 2.
  ULONG GetStreamSize();
  HRESULT GetStream(const CATULONG32  iAllocatedSize,
                    void* iAllocatedBuffer, ULONG* oRealSize );

  // or this one to do it all in one call.
  HRESULT GetStream(void** oAllocatedBuffer, ULONG* oRealSize);
  
private:
  CATCGRStreamGetterImpl *_impl;
};

#endif

