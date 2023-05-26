#ifndef CATIOmyComponentServices_H
#define CATIOmyComponentServices_H

// ObjectModelerSystem
#include "CATOMYComponentServicesToolsBridge.h"
// SystemTS
#include "IUnknown.h"

class CATIPLMCompCallbackMgr;
class CATIPLMCompCallbackPublisher;

class ExportedByCATOMYComponentServicesToolsBridge CATIOmyComponentServices
{
public:
  virtual HRESULT GetAdapterCallBackMgr(CATIPLMCompCallbackMgr** oCallbackMgr) = 0;

  virtual HRESULT GetAdapterCallBackPublisher(CATIPLMCompCallbackPublisher** oCallbackMgr) = 0;

};
#endif

