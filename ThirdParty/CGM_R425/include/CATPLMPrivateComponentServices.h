/**
* @level Private
* @usage U1
*/
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
#ifndef CATPLMPrivateComponentServices_H
#define CATPLMPrivateComponentServices_H


#include "CATPLMServicesItf.h" // must be remplaced by CATPLMCallbackLimitedAccess.h
#include "IUnknown.h"

class CATPLMTypeIdMetaDataImpl;
class CATIPLMCompCallbackMgr;
class CATIPLMCompCallbackPublisher;
/**
 * RESTRICTED TOOLBOX
 * @nodoc
 */
 //ExportedByCATPLMCallbackLimitedAccess soon...
class ExportedByCATPLMServicesItf CATPLMPrivateComponentServices
{
public:

  /**
  * Retrieves the CATIPLMCompCallbackMgr on CATPLMAdapter.
  */
  static HRESULT GetAdapterCallBackMgr(CATIPLMCompCallbackMgr** oCallbackMgr);

  /**
  * Retrieves the CATIPLMCompCallbackPublisher on CATPLMAdapter.
  */
  static HRESULT GetAdapterCallBackPublisher(CATIPLMCompCallbackPublisher** oCallbackPublisher);
};


#endif
