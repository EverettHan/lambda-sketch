#ifndef CATAsyncHttpOn3DSpaceRequest_H
#define CATAsyncHttpOn3DSpaceRequest_H

#include "DSYSysDlgServices.h"

#include "CATAsyncHttpRequest.h"

#include "CATSysErrorDef.h"

#include "CATOmxHttp.h"

#include "CATIAV5Level.h"

class ExportedByCATOmxHttp CATAsyncHttpOn3DSpaceRequest : public CATAsyncHttpRequest
{
public:
  CATAsyncHttpOn3DSpaceRequest(const Params& iParams);
  virtual ~CATAsyncHttpOn3DSpaceRequest();

#ifdef CATIAR423
  // current method has no sense, it is hardcoded for current class, GetAuthenticationType returns DSYSysIsTimeout3DSpace
  void SetAuthenticationType(DSYSysIsTimeoutService iServiceType);

  DSYSysIsTimeoutService GetAuthenticationType() const;
#endif

  //ConnectIfNecessary/Connect are used in CATAsyncHttpPlatformAdapter::_Reconnect
  CATBoolean ConnectIfNecessary() const;

  HRESULT Connect();

private:
  CATUnicodeString _InstanceId;
};

#endif
