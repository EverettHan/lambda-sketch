#ifndef CATHTTPTOOLSPROXY_H
#define CATHTTPTOOLSPROXY_H

#include "CATHttp.h"
#include "DSYString.h"

#define CATHTTP_PROXY_WS_EQUAL_HTTP	1
//Useless if you use CATHttpClient or DSYSysHttpCommunication
HRESULT ExportedByJS0HTTP CATHttpGetProxyForUrl(CATUnicodeString iUrl, CATUnicodeString& oProxyUrl, CATUnicodeString& oProxyName, unsigned int& oProxyPort, unsigned int iFlag = 0);

#endif
