
/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATIOmyPowerIOMPConnectMsg_H
#define __CATIOmyPowerIOMPConnectMsg_H

#include "CATUuid.h"
#include "CATVVSUrl.h"
#include "CATOMYCuteIO.h"
#include "CATBaseUnknown.h"

#include "CATCollec.h"
#include "CATUnicodeString.h"
#include "CATListOfCATVVSUrl.h"
#include "CATListOfCATUnicodeString.h"

#include "CATIOmyPowerIOMPTransactionMsg.h"

extern ExportedByCATOMYCuteIO IID IID_CATIOmyPowerIOMPConnectMsg ;

class CATIOmyPowerIOMPConnectMsg : public CATIOmyPowerIOMPTransactionMsg
{
	CATDeclareInterface;

public :
	virtual HRESULT GetBuf(const char** oRepositoryName,const char** oBuf,int & oSize) = 0;
	virtual HRESULT SetBuf(const char* iRepositoryName,const char*  iBuf, int iSize) = 0;

	virtual HRESULT GetTaskType(CATUnicodeString & oTaskType) = 0;
	virtual HRESULT SetTaskType(CATUnicodeString  iTaskType) = 0;
	
	virtual HRESULT SetPrefetchConnection(CATBoolean iPrefetch) = 0; 
  virtual HRESULT GetPrefetchConnection(CATBoolean& oPrefetch) =0; 

  virtual HRESULT GetCookieInfo(const char** oCookieUrl, const char** oCookieContent) = 0;
  virtual HRESULT SetCookieInfo(const char* iCookieUrl, const char* iCookieContent) = 0;

};
#endif
