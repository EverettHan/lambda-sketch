/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2009
#ifndef CATPLMTransitionalOpenCallbackAdapter_H
#define CATPLMTransitionalOpenCallbackAdapter_H

/**
 * @level Protected
 * @usage U2
 */
#include "CATPLMIntegrationInterfaces.h"
#include "CATIPLMTransitionalOpenCallback.h"

class CATIPLMComponent;
class CATLISTP(CATIPLMComponent);

class ExportedByCATPLMIntegrationInterfaces CATPLMTransitionalOpenCallbackAdapter: public CATIPLMTransitionalOpenCallback
{
public:

  /**
  * @see CATIPLMTransitionalOpenCallback#OnAfterOpen
  */
   HRESULT OnAfterOpen (const CATLISTP(CATIPLMComponent) & iOpenedComponents) ;
};

#endif
