#ifndef CATAdpFamilyServices_H
#define CATAdpFamilyServices_H

// COPYRIGHT DASSAULT SYSTEMES 2009
/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "CATPLMIntegrationAccess.h"
#include "CATCollec.h"
class CATLISTV(CATAdpFamilyDatum);
class CATIAdpErrorMonitor;

#define AuthorizedModule                  999
#define CATPLMIntegrationAccess           AuthorizedModule
#define CATPLMItgTestIntegrationAccess    AuthorizedModule
#define CATComponentsFamily               AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
	    #error Forbidden access to CATAdpFamilyServices from non-infrastructure module
        @error 
#endif
#undef CATPLMIntegrationAccess
#undef CATPLMItgTestIntegrationAccess
#undef CATComponentsFamily

class ExportedByCATPLMIntegrationAccess CATAdpFamilyServices
{
public:
  CATAdpFamilyServices();
  virtual ~CATAdpFamilyServices();
   
/**
 * Synchronize the provided set of data.
 * <br><b>Role:</b>Synchronize in the database the content of the provided solved components with its generic component.
 * @param iData [in]
 *   The data provided by the user.
 *   <ul>
 *   <li>If some solved components provided are currently edited in the Authoring session, <code>ERR_01</code> error will be available on the provided @href CATIAdpErrorMonitor.</li> 
 *   <li>If the provided attributes do not match with the provided component, <code>ERR_02</code> error will be available on the provided @href CATIAdpErrorMonitor.</li>
 *   <li>If no data are provided by the user, <code>ERR_03</code> error will be available on the provided @href CATIAdpErrorMonitor.</li> 
 *   <li>If a datum reveals an incoherence between types of the generic component and the solved one, <code>ERR_04</code> error will be available on the provided @href CATIAdpErrorMonitor.</li> 
 *   </ul>
 * @param iErrorMonitor
 *   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this service. it can be created through the @href CATAdpErrorMonitorFactory#CreateErrorMonitor entry point.
* @return
 *   <ul>
 *   <li><tt>S_OK</tt> if the operation successfully ended.</li> 
 *   <li><tt>E_FAIL</tt> if a fatal error happened during the transaction. Nothing was done during the operation. The errors can be read through the provided @href CATIAdpErrorMonitor.</li>
 *   <li><tt>E_INVALIDARG</tt> if the provided @href CATIAdpErrorMonitor is nul or no data are provided.</li>
 *   </ul>
 */
  HRESULT SynchronizeUpdate( const CATLISTV(CATAdpFamilyDatum) & iData, CATIAdpErrorMonitor * iErrorMonitor );
};
#endif
