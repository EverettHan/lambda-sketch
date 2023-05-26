/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2008
//-----------------------------------------------------------------------------
//
// class CATAdpErrorMonitorFactory :
// 
// Services to manage Life Cycle of Error Monitor(s) to be used by applications
//
//-----------------------------------------------------------------------------
// 07/07/08 Creation                                                        VCS
//-----------------------------------------------------------------------------

#ifndef CATAdpErrorMonitorFactory_H
#define CATAdpErrorMonitorFactory_H

// System
/**
 * @level Private
 * @usage U1
 */

#include "CATBaseUnknown.h"
#include "CATPLMIntegrationAccess.h"

class CATUuid;
class CATAdpErrorMonitor;
class CATIAdpErrorMonitor;
class CATIAdpErrorMonitorAbstract;
class CATIPLMComponent;

/**
* Services to manage Life Cycle of Error monitor(s) to be used by applications or Adp services
* <br><b>Role:</b> manages the <b>Creation, Identification, Referencing of ErrorMonitor </b> 
* in the current session.
* <br> Any application managing Errors raised by PLM services it uses during its execution
* <br> needs to control the Life cycle of an error monitor: 
* <ul>
* <li>Creation/reference in session: CreateErrorMonitor</li>
* <li>Use the Error Monitor: cf CATIAdpErrorMonitor behaviors  </li>
* <li>Recover an ErrorMonitor previously created using its identifier: FindErrorMonitor</li>
* <li>When the ErrorMonitor becomes useless: CATIAdpErrorMonitor->Release()
* </ul>
*/
class ExportedByCATPLMIntegrationAccess CATAdpErrorMonitorFactory
{
public:

	/**
	* Creates an Error Monitor in the current session. 
	* <br><b>Role:</b> Creates an Error Monitor to be handled by callers and references it in the current session.
	* <br> an AddRef is performed here on ErrorMonitor just created.
	* <br> <b>Caller has to Release it after use.</b>   
	* @param oErrorMonitorId
	*     the Error monitor Identifier, as it is referenced in the current session.
	* @param opiErrorMonitor [out, CATBaseUnknown#Release]
	*     the interface pointer on the Error monitor created by the factory.
	* @return
	*		 S_OK : Error monitor created and operation successfull
	* <br> E_FAIL : creation failed: Error monitor not created, output have NULL values
	*/
	static HRESULT CreateErrorMonitor(CATUuid & oErrorMonitorId, CATIAdpErrorMonitor* & opiErrorMonitor);

	/**
	* Finds an Error Monitor in the current session.
	* <br><b>Role:</b> Finds an Error Monitor previously created in the session.
	* <br> an AddRef has been performed here on ErrorMonitor when created. It is NOT performed again 
	* when giving it back to its caller.
	* @param iErrorMonitorId
	*     the Identifier of the Error monitor to search for , as it is referenced in the current session.
	* @param opiErrorMonitor [out, CATBaseUnknown#Release]
	*     An interface pointer on the Error monitor found in the session.
	* @return
	*		 S_OK : Error monitor found and operation successfull
	*	<br> E_FAIL  : search failed : Error monitor not found, output have NULL values
	*/
	static HRESULT FindErrorMonitor(CATUuid & iErrorMonitorId, CATIAdpErrorMonitor* & opiErrorMonitor);

	/**
	 * Shortcut to
	 * <code>
	 * CATIAdpErrorMonitor * myMonitor = NULL;
	 * CATUuid uiidIReallyDontCareAbout;
	 * if(SUCCEEDED(CATAdpErrorMonitorFactory::CreateErrorMonitor(uiidIReallyDontCareAbout, myMonitor)) && myMonitor)
	 * {
	 *   // your code
	 * }
   * @return CATBaseUnknown#Release
	 */
	static CATIAdpErrorMonitor * CreateErrorMonitor();
};
#endif
