//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 2004                                          *
//*===========================================================================*
//*                                                                           *
//*  Ows wrapper on StreamLockBytes   lockbytes                               *
//*                                                                           *
//*  Usage Notes: Use by composite stream implementation                      *
//*===========================================================================*
//*  Creation juin 2004                                                       *
//*===========================================================================*
#ifndef __CATOmyStreamLockBytesHandler_H
#define __CATOmyStreamLockBytesHandler_H

#include "CATILockBytes2.h"
#include "CATUnicodeString.h"
#include "CATOmyStorageHandler.h"
#include "CATOMYBaseSession.h"

/**
* @level Protected
* @usage U4 CATOmyStreamLockBytesHandler
*/

class ExportedByCATOMYBaseSession CATOmyStreamLockBytesHandler : public CATILockBytes2
{
public:

  CATOmyStreamLockBytesHandler( CATOmyStorageHandler * iStr, CATUnicodeString iLocalId );
  ~CATOmyStreamLockBytesHandler();

 //------------------------
  // Heritage IUnknown
  //------------------------
  HRESULT __stdcall QueryInterface(const IID &iid, void **ppv);
  
  ULONG __stdcall AddRef() ;
  
  ULONG __stdcall Release() ;

  
  HRESULT __stdcall ReadAt( ULARGE_INTEGER iOffset,
			    void FAR *iBuff,
			    ULONG iLengthToRead,
			    ULONG FAR *oLengthRead);
  
  HRESULT __stdcall WriteAt( ULARGE_INTEGER iOffset,
			     const void FAR *iDataSource,
			     ULONG iLengthToWrite,
			     ULONG FAR *LengthWritten);
  
  HRESULT __stdcall Flush( void);
  
  HRESULT __stdcall SetSize( ULARGE_INTEGER iLength);
  
  HRESULT __stdcall LockRegion( ULARGE_INTEGER iOffset,
				ULARGE_INTEGER iLegnth,
				DWORD dwLockType);
  
  HRESULT __stdcall UnlockRegion( ULARGE_INTEGER iOffset,
				  ULARGE_INTEGER iLength,
				  DWORD dwLockType);
  
  HRESULT __stdcall Stat( STATSTG FAR *oStat,
			  DWORD iStatFlag);
 
  HRESULT __stdcall Open( DWORD iMode, DWORD iFlag, time_t iTS=0, 
			  ULARGE_INTEGER *iSize=NULL);
  
  HRESULT __stdcall Close( DWORD iFlag =0);
  
  HRESULT __stdcall Purge() ;

  void Invalidate(){_StorageValid = FALSE;};
  
private:
  
  CATBoolean             _StorageValid:1; /* Uses when composite stream is closed */
  CATOmyStorageHandler * _Storage;        /* Data access - Representation storage */
  CATUnicodeString       _LocalId;        /* Data access - Local identifier       */
  ULONG                  _Ref;            /* AddRef counter                       */
  CATILockBytes2   *     _ILockBytes2;    /* Associated stream Lock Bytes         */
};

#endif
