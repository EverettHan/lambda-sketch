//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 2003                                          *
//*===========================================================================*
//*                                                                           *
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Creation novembre 2003                                                   *
//*===========================================================================*
#ifndef __CATSYSMULTIBUFFER
#define __CATSYSMULTIBUFFER

#include "CATWTypes.h"
#include "JS0COMP.h"
#include "JS0BASEILB.h"
#include "CATILockBytes.h"
#include "DSYSysMultiBuffer.h"



class ExportedByJS0COMP CATSysMultiBuffer : public DSYSysMultiBuffer 
{ 
  friend HRESULT ExportedByJS0COMP CATGetBuffersFromILockBytes (CATILockBytes *iLB,CATSysMultiBuffer **oHmem);
public :

  CATSysMultiBuffer(size_t iSize);
  virtual ~CATSysMultiBuffer();
  
   ULONG AddRef();
   ULONG Release();
    
   HRESULT Realloc(ULARGE_INTEGER iLength);
   HRESULT CopyTo( ULARGE_INTEGER iOffset, const void *iSource,  size_t iLength,  size_t *oWriten);
 
   HRESULT CopyFrom( ULARGE_INTEGER iOffset, void *oDest, 
		    size_t iLength, size_t *oRead);
   HRESULT GetSize ( size_t *oSize);
  
   HRESULT GetBuffersInfo( unsigned int *oNb, size_t *oSize);
  // Never delete the oBuff pointer !!It is a direct access onto the Buffer
   HRESULT GetBuffer ( unsigned int iIndice, char **oBuff);
  
   HRESULT FlushBuffer (int iMax=0);
  
   void setLock(int iVal);
	int getLock();
	 
	 HRESULT CopyToInt( ULARGE_INTEGER iOffset, const void *iSource, size_t iLength,  size_t *oWriten);
   HRESULT ReallocInt(ULARGE_INTEGER iLength);
private:
	
  
  CATSysMultiBuffer(DSYSysMultiBuffer *& iMLB): _l_MB(iMLB) {};
   
  DSYSysMultiBuffer  * _l_MB;
  
};

#endif
