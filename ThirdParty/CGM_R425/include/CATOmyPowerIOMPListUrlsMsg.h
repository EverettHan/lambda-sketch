/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATOmyPowerIOMPListUrlsMsg_H
#define __CATOmyPowerIOMPListUrlsMsg_H

#include "CATOmyPowerIOMPTransactionMsg.h"
#include "CATUuid.h"

#include "CATCollec.h"
#include "CATMessageClass.h"
#include "CATUnicodeString.h"
#include "CATVVSUrl.h"
#include "CATOmxArray.h"

#include "CATOMYCuteIO.h"

class CATICommMsg ;

class ExportedByCATOMYCuteIO CATOmyPowerIOMPListUrlsMsg : public CATOmyPowerIOMPTransactionMsg
{
	CATDeclareClass;

public :

	CATOmyPowerIOMPListUrlsMsg();
	virtual ~CATOmyPowerIOMPListUrlsMsg();

	// CATIStreamMsg Interface
	virtual HRESULT StreamData    ( void **oBuffer, uint32 *oLen);
	virtual HRESULT UnstreamData  ( void  *iBuffer, uint32  iLen);
	virtual HRESULT FreeStreamData( void  *iBuffer, uint32  iLen);
	virtual HRESULT SetMessageSpecifications();

	virtual HRESULT SetUrls(const CATVVSUrl &iUrlSrc, const CATVVSUrl &iUrlDest);
	virtual HRESULT GetListOfUrls(CATOmxArray<CATVVSUrl> & oListUrlsSrc, CATOmxArray<CATVVSUrl> & oListUrlsDest)
    {oListUrlsSrc=_UrlsListSrc;oListUrlsDest=_UrlsListDest;return S_OK;}

	virtual HRESULT PushVVSTransactionParam(CATUnicodeString &iParamName, CATUnicodeString &iParamValue);
	virtual HRESULT GetListVVSTransactionParam(CATListOfCATUnicodeString &oListParamName, CATListOfCATUnicodeString &oListParamValue);
	
  virtual HRESULT SetCachePath(CATUnicodeString& iCachePath);
  virtual HRESULT GetCachePath(CATUnicodeString& oCachePath);

  virtual HRESULT SetIsOnlyCheckOut(CATBoolean iIsOnlyCheckOut);
  virtual HRESULT GetIsOnlyCheckOut(CATBoolean& oIsOnlyCheckOut);


private :
  CATUnicodeString       _CachePath;
  CATBoolean             _IsOnlyCheckOut;

	CATOmxArray<CATVVSUrl> _UrlsListSrc;
	CATOmxArray<CATVVSUrl> _UrlsListDest;
	
	CATListOfCATUnicodeString _listParamName;
	CATListOfCATUnicodeString _listParamValue;
	
  int _NumberOfRegisterEntries;
	int _size;
};

#endif
