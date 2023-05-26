// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMConnectDisconnectSpecific.h
// Header definition of CATPLMConnectDisconnectSpecific
//
//===================================================================
//
// Usage notes:
// this code is used by licensing team
// (we are not able to launch CATIA if there is no connection to M1)
//
//===================================================================
//
// April 2009  Creation: EPB
//===================================================================

#ifndef CATPLMConnectDisconnectSpecific_H
#define CATPLMConnectDisconnectSpecific_H

#include "CATSysErrorDef.h"//SpecialAPI/PublicInterfaces

#include "CATPLMServicesItf.h"

class CATPLMConnectionParameters;

/**
* @level Protected
* @usage U1
*/

class ExportedByCATPLMServicesItf CATPLMConnectDisconnectSpecific
{
  public:
    /** 
    * connection to M1. If it works, disconnection from M1.
    *
    * <br><b>Role</b>: 
    * connection to M1. If it works, disconnection from M1.
    *
    * @param ipConnectionParameters [in]
    *   connection parameters. This connection parameters can be updated. Some parameters can be added to the CATPLMConnectionParameters
    *
    * @return
    *     <dt>S_OK</dt>
    *     <dd>connection and disconnection are successful. Provider is ready to Connect</dd>
    *     <dt>S_FALSE</dt>
    *     <dd>Some Parameters are not valuated. impossible to connect</dd>
    *     <dt>E_FAIL </dt>
    *     <dd>A problem occurs during the connection. get further information by using CATIPLMErrorStack</dd>
    *
    */
    static HRESULT ConnectDisconnect(CATPLMConnectionParameters * iopConnectionParameters);
};

#endif
