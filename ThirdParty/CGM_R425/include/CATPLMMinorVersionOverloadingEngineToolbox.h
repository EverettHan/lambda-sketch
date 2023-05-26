/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMMinorVersionOverloadingEngineToolbox_H
#define CATPLMMinorVersionOverloadingEngineToolbox_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATErrorDef.h"

class CATIPLMEngineListener;
class CATIAdpErrorMonitorAbstract;
class CATIPLMMinorVersionOverloadingEngine_var;

// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMIntegrationInterfaces       AuthorizedModule
#define CATPLMIdentification_PLM          AuthorizedModule
#define PLMUICommands                     AuthorizedModule
#define CATOmbDebugLink                   AuthorizedModule
#define AuthUICommands                    AuthorizedModule 
#define CATPLMDmtDocCommands              AuthorizedModule 
#define CATImmNavFilter                   AuthorizedModule 

#if _MK_MODNAME_ == AuthorizedModule
#else
	    #error Forbidden access to CATPLMMinorVersionOverloadingEngineToolbox from non-infrastructure module
        @error 
#endif
#undef CATPLMIntegrationInterfaces
#undef CATPLMIdentification_PLM
#undef PLMUICommands
#undef CATOmbDebugLink
#undef AuthUICommands
#undef CATPLMDmtDocCommands
#undef CATImmNavFilter
// ----------------------------------------------------------------------------------------------------------------------

/**
 * Class to access private integration engines
 *<br><b>Role</b>: Thanks to its static method, you can access to the synchronization engine.
 */
class ExportedByCATPLMIntegrationInterfaces CATPLMMinorVersionOverloadingEngineToolbox
{
public:

  /**
  * Gets overloading engine.
  * @param oSynchronizationEngine
  *   The overloading engine.
  * @param ioListener [inout]
  *   The error listener to use during synchronization process
  *   If NULL, a default listener will be used.
  * @param ioErrorMonitor [inout]
  *   The ErrorMonitor that collects all eventual errors happening during synchronization process 
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT GetMinorVersionOverloadingEngine( CATIPLMMinorVersionOverloadingEngine_var & oMinorVersionOverloadingEngine , CATIPLMEngineListener * ioListener=0 , CATIAdpErrorMonitorAbstract * ioErrorMonitor=0 );
};
#endif
