#ifndef __CATILockBytes2Adapter_H
#define __CATILockBytes2Adapter_H

#include "VVSUtils.h"
#include "CATILockBytes2.h"
#include "CATOmxCRefTS.h"
#include "CATOmxSR.h"

/**
* CATILockBytes2Adapter.
* All methods will delegate to "delegate" object or return STG_E_UNIMPLEMENTEDFUNCTION
*/
class ExportedByVVSUtils CATILockBytes2Adapter: public CATILockBytes2
{
  CATOmxCRefTS<unsigned int> m_cRef;
protected:
  CATOmxSR<CATILockBytes2> m_delegate;
public:
  CATILockBytes2Adapter(CATILockBytes2* iDelegate = NULL);
  /**
  * IUnknown methods.
  */
  virtual HRESULT __stdcall QueryInterface(const IID &iIID,void **oPPV);
  virtual ULONG __stdcall AddRef();
  virtual ULONG __stdcall Release();

  /**
  * CATILockBytes methods.
  * @see CATILockBytes documentation
  */
  virtual HRESULT __stdcall ReadAt(ULARGE_INTEGER iOffset,void* iBuff,ULONG iLengthToRead,ULONG* oLengthRead);              
  virtual HRESULT __stdcall WriteAt(ULARGE_INTEGER iOffset,const void* iDataSource,ULONG iLengthToWrite,ULONG* LengthWritten);         
  virtual HRESULT __stdcall Flush();          
  virtual HRESULT __stdcall SetSize(ULARGE_INTEGER iLength);            
  virtual HRESULT __stdcall LockRegion(ULARGE_INTEGER iOffset,ULARGE_INTEGER iLegnth,DWORD dwLockType);
  virtual HRESULT __stdcall UnlockRegion( ULARGE_INTEGER iOffset,ULARGE_INTEGER iLength,DWORD dwLockType);  
  virtual HRESULT __stdcall Stat(STATSTG* oStat,DWORD iStatFlag);

  /**
  * CATILockBytes2 methods.
  * @see CATILockBytes2 documentation
  */
  virtual HRESULT __stdcall Open(DWORD iMode,DWORD iFlag,time_t iTS=0,ULARGE_INTEGER* iSize=0);
  virtual HRESULT __stdcall Close(DWORD iFlag=0);
  virtual HRESULT __stdcall Purge();

  virtual ~CATILockBytes2Adapter();
private:
  CATILockBytes2Adapter(const CATILockBytes2Adapter& );
  CATILockBytes2Adapter& operator=(const CATILockBytes2Adapter& );
};


#endif
