#ifndef CATAdpOperationDatumAccess_H
#define CATAdpOperationDatumAccess_H

// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @level Private
 * @usage U3
 */

// List of authorized infrastructure modules 
#if defined (private) || defined(friend) || defined (protected)

  #error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 
#endif
#define AuthorizedModule     999

#define CATPLMIntegrationAccess        AuthorizedModule
#define CATPLMREDataAccessor           AuthorizedModule
#define CATPLMItgTestIntegrationAccess AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

      #error Forbidden Access To CATPLMServicesLimitedAccess Services from a non-authorized module
        // Fatal error on solaris
        @error 
#endif

#undef CATPLMIntegrationAccess
#undef CATPLMREDataAccessor
#undef CATPLMItgTestIntegrationAccess

#include "CATPLMIntegrationAccess.h"

#include "CATAdpOperationDatum.h"
#include "CATUnicodeString.h"

/**
* Class to represent a modification in a history
**/
class ExportedByCATPLMIntegrationAccess CATAdpOperationDatumAccess
{
public:
  CATAdpOperationDatumAccess( const CATAdpOperationDatum &iDatum );
  virtual ~CATAdpOperationDatumAccess ();
   
  /**
   * Get the component updatestamp of the component.
   * @param oComponentUS [out]
   *   The component updatestamp.
   *
   * @return
   * <dl>
   *   <li><code>S_OK</code> if the owner of the component is available.</li>
   *   <li><code>S_FALSE</code> if no owner is available for the component (case for @href PLMCoreReference or @href PLMCoreRepReference).</li>
   *   <li><code>E_FAIL</code> if a fatal error occured during the operation.</li>
   * </dl>  
   */
  HRESULT GetComponentUS( int & oComponentUS ) const;

  /**
   * Returns the string value of the operation type enum.
   * @param iOpType [in]
   *   The opertaion type.
   */
  CATUnicodeString GetOperationNameFromOperationType ( CATAdpOperationDatum::OperationType iOpType );

private :
  CATAdpOperationDatum _BaseDatum;
};

#endif
