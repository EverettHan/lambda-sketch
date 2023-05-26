/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATOmyPowerIOMPConnectMsg_H
#define __CATOmyPowerIOMPConnectMsg_H

#include "CATOmyPowerIOMPTransactionMsg.h"
#include "CATUuid.h"
#include "CATVVSUrl.h"

#include "CATCollec.h"
#include "CATListOfInt.h"
#include "CATUnicodeString.h"
#include "CATListOfCATVVSUrl.h"
#include "CATOMYCuteIO.h"
#include "CATBoolean.h"

class ExportedByCATOMYCuteIO CATOmyPowerIOMPConnectMsg : public CATOmyPowerIOMPTransactionMsg
{
	CATDeclareClass;

public :

	CATOmyPowerIOMPConnectMsg();
	virtual ~CATOmyPowerIOMPConnectMsg();

	// CATIStreamMsg Interface
	virtual HRESULT StreamData    ( void **oBuffer, uint32 *oLen);
	virtual HRESULT UnstreamData  ( void  *iBuffer, uint32  iLen);
	virtual HRESULT FreeStreamData( void  *iBuffer, uint32  iLen);
	virtual HRESULT SetMessageSpecifications();

	virtual HRESULT GetTaskType(CATUnicodeString & oTaskType){oTaskType = _Type; return S_OK;};
	virtual HRESULT SetTaskType(CATUnicodeString  iTaskType){_Type = iTaskType; return S_OK;};

	virtual HRESULT GetBuf(const char** oRepositoryName,const char** oBuf,int & oSize);
	virtual HRESULT SetBuf(const char* iRepositoryName,const char*  iBuf, int iSize);

  virtual HRESULT SetPrefetchConnection(CATBoolean iPrefetch){_Prefetch=iPrefetch; return S_OK;};
  virtual HRESULT GetPrefetchConnection(CATBoolean& oPrefetch){oPrefetch=_Prefetch; return S_OK;};

  virtual HRESULT GetCookieInfo(const char** oCookieUrl, const char** oCookieContent);
  virtual HRESULT SetCookieInfo(const char* iCookieUrl, const char* iCookieContent);

private :
	CATUnicodeString _repositoryName;
  CATUnicodeString _CookieUrl;
  CATUnicodeString _CookieContent;

	const char* _buf;
  
  int _size;
	CATUnicodeString _Type;	
	CATBoolean _Prefetch;

};

#endif
