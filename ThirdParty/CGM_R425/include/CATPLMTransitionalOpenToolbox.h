/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMTransitionalOpenToolbox_H
#define CATPLMTransitionalOpenToolbox_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATErrorDef.h"

class CATIAdpErrorMonitorAbstract;
class CATIPLMTransitionalOpenEngine;

// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMIntegrationInterfaces       AuthorizedModule
#define CATPLMTransitionalOpenEngine      AuthorizedModule
#define SWXAsMateModeler                  AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
	    #error Forbidden access to CATPLMTransitionalOpenToolbox from non-infrastructure module
        @error 
#endif
#undef CATPLMIntegrationInterfaces
#undef CATPLMTransitionalOpenEngine
#undef SWXAsMateModeler
// ----------------------------------------------------------------------------------------------------------------------

/**
 * Class to access private integration engines
 *<br><b>Role</b>: Thanks to its static method, you can access to the transitional open engine.
 */
class ExportedByCATPLMIntegrationInterfaces CATPLMTransitionalOpenToolbox
{
public:

  /**
  * Gets a transitional open engine.
  * @param CATIPLMTransitionalOpenEngine *& oTransitionalOpenEngine [out, CATBaseUnknown#Release]
  *   Release is to be called on the provided pointer when useless.
  * @param ioErrorMonitor [inout]
  *   The ErrorMonitor that collects all eventual errors happening during the open process.
  * @return
  *   S_OK if request succeeded.
  *   E_FAIL if request failed.
  */
  static HRESULT GetTransitionalOpenEngine( CATIPLMTransitionalOpenEngine *& oTransitionalOpenEngine, CATIAdpErrorMonitorAbstract * ioErrorMonitor = 0);

};
#endif
