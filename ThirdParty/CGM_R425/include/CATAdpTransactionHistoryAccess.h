#ifndef CATAdpTransactionHistoryAccess_H
#define CATAdpTransactionHistoryAccess_H

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

#include "CATAdpTransactionHistory.h"
#include "CATUnicodeString.h"

/**
* Class to access specific data in a history.
**/
class ExportedByCATPLMIntegrationAccess CATAdpTransactionHistoryAccess
{
public:
  CATAdpTransactionHistoryAccess( const CATAdpTransactionHistory &iAdpHistory );
  virtual ~CATAdpTransactionHistoryAccess();

/**
 * Get the unique id of the history.
 * @param [out] oUniqueId
 *   The unique id of the transaction
 */
  HRESULT GetUniqueId ( CATUnicodeString & oUniqueId ) const;

private:
  CATAdpTransactionHistory _BaseHistory;
};
#endif
