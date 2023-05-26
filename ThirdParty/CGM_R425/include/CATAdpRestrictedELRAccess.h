/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2015

#ifndef CATAdpRestrictedELRAccess_H
#define CATAdpRestrictedELRAccess_H

/**
 * @level Protected
 * @usage U1
 */

#include "CATPLMIntegrationAccess.h"
#include "CATSysErrorDef.h"
#include "CATBooleanDef.h"
#include "CATLISTV_CATComponentId.h"
class CATIAdpErrorMonitor;
class CATAdpRestrictedELRAccessImpl;

#define AuthorizedModule                  999
#define CATPLMIntegrationAccess           AuthorizedModule
#define CATPLMItgTestIntegrationAccess    AuthorizedModule
#define CATPLMLinksUI                     AuthorizedModule
#define CATDftGenModel                    AuthorizedModule //Drafting: enrichissement des informations fournies par la commande ModifyLinks sur les liens maitres d'une vue generative.
#if _MK_MODNAME_ == AuthorizedModule
#else
	    #error Forbidden access to CATAdpRestrictedELRAccess from non-infrastructure module
        @error 
#endif
#undef CATPLMIntegrationAccess
#undef CATPLMItgTestIntegrationAccess
#undef CATPLMLinksUI
#undef CATDftGenModel

/**
 * Class enabling to perform advanced operation for ELR application.
 * <br><b>Role</b>: <p>This class exposes functions dedicated to ELR use.</p>
 *
 * Example of usage :
 * <pre>
 * CATComponentId MyPort;
 * { ... retrieve your pointed Port }
 * CATComponentIds MyPortsToEnrich;
 * MyPortsToEnrich.Append(MyPort);
 * CATAdpRestrictedELRAccess ELRAccess;
 * if ( SUCCEEDED( ELRAccess.EnsureELRInformationAvailability(MyPortsToEnrich) ) )
 * {
 *   CATComponentId MyPortOwner;
 *   if ( SUCCEEDED( MyPort.HasPLMOwner(MyPortOwner) ) )
 *   {
 *     CATUnicodeString uOwnerAlias;
 *     if ( SUCCEEDED( MyPortOwner.HasAlias(uOwnerAlias) ) )
 *     { ... }
 *   }
 * }
 * else
 * {
 *   CATIAdpErrorMonitor * pErrorMonitor=0;
 *   if ( SUCCEEDED( ELRAccess.GetErrorMonitor(pErrorMonitor) ) )
 *   {
 *     // Error management
 *     CATSysReleasePtr(pErrorMonitor);
 *   }
 * }
 *</pre>
 */
class ExportedByCATPLMIntegrationAccess CATAdpRestrictedELRAccess
{
public:

/**
 * Constructor
 * @param iErrorMonitor
 * An error reviewer.
 * @see CATIAdpErrorMonitor
 */
  CATAdpRestrictedELRAccess(CATIAdpErrorMonitor * iErrorMonitor=0);
  ~CATAdpRestrictedELRAccess();

  enum ELRInformationLevel { Publications=0, AllPointed=1 };

/**
 * Prepare the given Components so that information are available for ELR application.
 * <b>Role</b>: the purpose of this service is to make detailed informations about given Components available, even if not opened in the Authoring Session.
 * Aimed informations are zombie aliases of pointed Components. Additionnaly, Owners of Publications are computed and its zombie aliases are initalized.
 * <ul>
 * <li><code>ERR_01_ELR</code> warning is available through the @href CATIAdpErrorMonitor if a given component is not a PLMPort in <code>Publications</code> mode. Component is ignored for treatment.</li>
 * <li><code>ERR_02_ELR</code> warning is available through the @href CATIAdpErrorMonitor if the given component is not directly pointed in <code>Publications</code> mode. Component is ignored for treatment.</li>
 * </ul>
 *
 * @param iComponents [in] : the Components to be treated.
 *   If no element is given, the algorithm will be applied on all the not opened components which are pointed by Opened Components (in accordance with given InformationLevel).
 *
 * @param iLevel [in] : the type of information needed.
 * <ul>
 * <li><code>Publication</code> : Only Publications will be treated. Publications owners will be made available and zombie aliases will be computed for it.</li>
 * <li><code>AllPointed</code> : All the given or pointed Components will be treated.</li>
 * </ul>
 *
 * @return
 *   <dl>
 *   <dt><code>S_OK</code> Operation succeeded <dd>
 *   <dt><code>E_FAIL</code> Error were encountered. See associated @use CATIAdpErrorMonitor content to fetch errors details<dd>
 *   </dl>
 */
  HRESULT EnsureELRInformationAvailability(const CATComponentIds & iComponents, CATAdpRestrictedELRAccess::ELRInformationLevel iLevel=Publications);

/**
  * Get the error monitor.
  * @param oErrorMonitor [out, CATBaseUnknown#Release]
  *   Reviewer containing errors (@see CATIAdpErrorMonitor)
  * @return
  *   <dl>
  *   <dt><code>S_OK</code> Operation succeeded <dd>
  *   <dt><code>E_FAIL</code> failure <dd>
  *   </dl>
  */
  HRESULT GetErrorMonitor(CATIAdpErrorMonitor *& oErrorMonitor);

private:
  /*
   * @nodoc
   */
  CATAdpRestrictedELRAccess (CATAdpRestrictedELRAccess &);
  /*
   * @nodoc
   */
  CATAdpRestrictedELRAccess& operator=(CATAdpRestrictedELRAccess&);

private:
  CATAdpRestrictedELRAccessImpl *_pImpl;
};
#endif
