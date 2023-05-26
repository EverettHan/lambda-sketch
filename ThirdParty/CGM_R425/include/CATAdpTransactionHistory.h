#ifndef CATAdpTransactionHistory_H
#define CATAdpTransactionHistory_H

// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @level Private
 * @usage U3
 */

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"
class CATPLMID;
class CATAdpOperationDatum;
class CATPLMCEStamp;
class CATUnicodeString;
class CATTime;
class CATAdpPrivateTransactionHistory;
/**
* Class to represent a modification in a history
**/
class ExportedByCATPLMIntegrationAccess CATAdpTransactionHistory
{
public:

  virtual ~CATAdpTransactionHistory();

  CATAdpTransactionHistory( const CATAdpTransactionHistory & );
  CATAdpTransactionHistory & operator=( const CATAdpTransactionHistory & );
  int operator==(const CATAdpTransactionHistory & iOther) const;
  int operator!=(const CATAdpTransactionHistory & iOther) const;

/**
 * Get the date of modification
 * @param [out] oDate
 *   The CATTime at which the transaction was due
 * @return
 *  An HRESULT value
 * <dl>
 *  <dt>S_FALSE</dt><dd>No date available</dd>
 *  <dt>E_FAIL</dt><dd>Impossible to get the date.</dd>
 * </dl>  
 */
  HRESULT When( CATTime & oDate ) const;

/**
 * Get the change log associated with the element (ie. action and message)
 * @param [out] oAction
 *   The action which was set for this history
 * @return
 *  An HRESULT value
 * <dl>
 *  <dt>S_FALSE</dt><dd>No action or no message available</dd>
 *  <dt>E_FAIL</dt><dd>Impossible to get action or message.</dd>
 * </dl>  
 */
  HRESULT Why( CATPLMID & oAction, CATUnicodeString & oMessage ) const;

/**
 * Get the informations associated with the user, that is username, his role and his project
 * @param [out] oUser
 *   The user name
 * @param [out] orole
 *   The user role
 * @param [out] oProject
 *   The user project
 * @return
 *  An HRESULT value
 * <dl>
 *  <dt>S_FALSE</dt><dd>No action or no message available</dd>
 *  <dt>E_FAIL</dt><dd>Impossible to get action or message.</dd>
 * </dl>  
 */
  HRESULT Who( CATUnicodeString & oUser, CATUnicodeString & oRole, CATUnicodeString & oProject ) const;

/**
 * Get the informations about the content of the modifications performed through this history.
 * @param ioPosition [inout]
 *   On input, it's the index of the component (specify 0 for the first component). On output, it will contain the next index.
 * It is self incremented.
 * @param [out] oOperationData
 *   The structure containing the informations
 *
 * @return
 * <dl>
 *   <li><code>S_OK</code> if everything ran ok.</li>
 *   <li><code>S_FALSE</code> if no more operation is available. All the operations available were parsed.</li>
 *   <li><code>E_INVALIDARG</code> if invalid position is provided.</li>
 *   <li><code>E_FAIL</code> if a fatal error occured during the operation.</li>
 * </dl>  
 */
  HRESULT NextComponentModification( int & ioPosition, CATAdpOperationDatum & oOperationDatum ) const;

private:
  friend class CATAdpTransactionHistoryAccess;
  friend class CATAdpChangeHistoryQuery;
  friend class CATAdpPrivateTransactionHistoryPoolTest;
  CATAdpTransactionHistory(CATAdpPrivateTransactionHistory * iLetter);
  CATAdpPrivateTransactionHistory * _letter;
};

// CATLISTV(CATAdpTransactionHistory) definition

// Clean previous functions requests
#include "CATLISTV_Clean.h"

// Required functions
/** @nodoc INTERNAL */
#define CATLISTV_Append
#define CATLISTV_Size
#define CATLISTV_InsertAt
#define CATLISTV_RemoveAll


// Get macros
// Generate interface of collection-class
#include "CATLISTV_Declare.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATPLMIntegrationAccess
CATLISTV_DECLARE(CATAdpTransactionHistory)

// Typedef declaration for users easy identification.
typedef CATLISTV(CATAdpTransactionHistory) CATListAdpTransactionHistory;

#endif
