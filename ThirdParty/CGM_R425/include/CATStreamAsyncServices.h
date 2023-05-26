#ifndef  __CATStreamAsyncServices_H
#define  __CATStreamAsyncServices_H

#include "CATUnicodeString.h"

#include "CATAssert.h"
#include "CATSysMacros.h"
#include "CATListOfCATOmyCioUrlUsageCtx.h"
#include "CATIOmyAsyncAccess.h"
#include "CATOmxVector.h"
#include "CATOmxArray.h"
#include "DSYSysTrace.h"

#include "CATAsyncServices.h"

class CATIPLMCompConnectionInstance;
class CATIPLMAsyncProviderInterfaces;
class CATVVSURLConnectionSharable;

class ExportedByCATAsyncServices CATStreamAsyncServices : public CATIOmyAsyncAccess
{
  CATDeclareClass;
public:
  CATStreamAsyncServices();
  virtual ~CATStreamAsyncServices();

  // Login Ticker service
  virtual HRESULT SetUpLoginTicket(const char *repoTyp, CATBinary& oBinConn);
  virtual HRESULT FlushLoginTicket(const char *repoTyp);

private:
    
  CATOmxSR<CATIPLMAsyncProviderInterfaces> GetCATIPLMAsyncProviderInterface(CATIPLMCompConnectionInstance * ipiCompCnx);  
};
#endif
