/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATIOmyPowerIOMPListUrlsMsg_H
#define __CATIOmyPowerIOMPListUrlsMsg_H

#include "CATUuid.h"
#include "CATVVSUrl.h"
#include "CATOMYCuteIO.h"
#include "CATBaseUnknown.h"
#include "CATMessageClass.h"

#include "CATCollec.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATVVSUrl.h"
#include "CATOmxArray.h"

#include "CATIOmyPowerIOMPTransactionMsg.h"

extern ExportedByCATOMYCuteIO IID IID_CATIOmyPowerIOMPListUrlsMsg ;

class CATIOmyPowerIOMPListUrlsMsg : public CATIOmyPowerIOMPTransactionMsg
{
	CATDeclareInterface;

public :
	//For List Urls
	virtual HRESULT SetUrls(const CATVVSUrl &iUrlSrc, const CATVVSUrl &iUrlDest) = 0;
	virtual HRESULT GetListOfUrls(CATOmxArray<CATVVSUrl> & oListUrlsSrc, CATOmxArray<CATVVSUrl> & oListUrlsDest) = 0;

	//For CATVVSTransaction Properties
	virtual HRESULT PushVVSTransactionParam(CATUnicodeString &iParamName,CATUnicodeString &iParamValue) = 0;
	virtual HRESULT GetListVVSTransactionParam(CATListOfCATUnicodeString &oListParamName, CATListOfCATUnicodeString &oListParamValue) = 0;
	
	// Path du VaultSite VVS
	virtual HRESULT SetCachePath(CATUnicodeString& iCachePath)=0;
  virtual HRESULT GetCachePath(CATUnicodeString& oCachePath)=0;

	// Boolean to indicate that we're dealing with only check out urls
	virtual HRESULT SetIsOnlyCheckOut(CATBoolean iIsOnlyCheckOut)=0;
  virtual HRESULT GetIsOnlyCheckOut(CATBoolean& oIsOnlyCheckOut)=0;
};
#endif
