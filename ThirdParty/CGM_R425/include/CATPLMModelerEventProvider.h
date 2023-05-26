#ifndef CATPLMModelerEventProvider_H
#define CATPLMModelerEventProvider_H

/**
 * @level Protected
 * @usage U1
 */

#include "CATBaseUnknown.h"
#include "CATPLMModelerBaseInterfaces.h"

class CATIPLMModelerEventRegister_var;

class ExportedByCATPLMModelerBaseInterfaces CATPLMModelerEventProvider : public CATBaseUnknown
{
  public:

    /**
     *  Get event register.
     *  <p>
     *  <b>Role:</b> The service provider an event register allowing user to subscribe 
     *               there event listener to modeler event controller.
     *  </p>
     *  @param ospRegister
     *     Event register.
     *
     *  @return HRESULT 
     *	   <ul>
     *     <li><tt>S_OK</tt>: everything is OK.
     *     <li><tt>E_FAIL</tt>: No event register is avalaible.
     *     </ul>
     */

    static HRESULT GetEventRegister(CATIPLMModelerEventRegister_var &ospRegister); 
};

#endif
