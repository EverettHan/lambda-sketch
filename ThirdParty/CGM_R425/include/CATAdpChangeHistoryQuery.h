#ifndef CATAdpChangeHistoryQuery_H
#define CATAdpChangeHistoryQuery_H

// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @level Private
 * @usage U3
 */

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATAdpTransactionHistory.h"
#include "CATCollec.h"
#include "CATPLMTLogEntry.h"
#include "CATBooleanDef.h"
class CATLISTV(CATPLMID);
class CATPLMID;
class CATIAdpErrorMonitor;
class CATAdpHistoryHandler;
class CATAdpActionsParser;

/**
* Class to make queries on histories 
**/
class ExportedByCATPLMIntegrationAccess CATAdpChangeHistoryQuery
{
public:
/**
 * Constructor
 * @param *iUnknown
 *   For further use
 */
  CATAdpChangeHistoryQuery( CATBaseUnknown * iUnknown = NULL );
  virtual ~CATAdpChangeHistoryQuery();
   
/**
 * Get history of all modifications given a precise action
 * @param [in] iAction
 *   The action from which components are bound
 * @param [inout] iopErrorMonitor
 *  the monitor that will be informed of the errors
 * @param [out] oTransactionHistoryList
 *  the list of transaction history, see @href CATListAdpTransactionHistory
 * @param [in] iOrderByDate
 *  tell if the list of transaction history will be ordered by date or not
 * @return
 *  An HRESULT value
 * <dl>
 *  <dt>E_FAIL</dt><dd>Could not get history from action. See error monitor for more informations</dd>
 * </dl>  
 */
  HRESULT GetHistoryFromAction( const CATPLMID & iAction, 
                                CATIAdpErrorMonitor * iopErrorMonitor,
                                CATListAdpTransactionHistory & oTransactionHistoryList,
								CATBoolean iOrderByDate=FALSE );

/**
 * Get history of all modifications given a precise component
 * @param [in] iComponent
 *   The component from which actions are bound.
 * @param [in/out] iopErrorMonitor
 *  the monitor that will be informed of the errors
 * @param [out] oTransactionHistoryList
 *  the list of transaction history, see @href CATListAdpTransactionHistory
 * @param [in] iOrderByDate
 *  tell if the list of transaction history will be ordered by date or not
 * @return
 *  An HRESULT value
 * <dl>
 *  <dt>E_FAIL</dt><dd>Could not get history from action. See error monitor for more informations</dd>
 * </dl>  
 */
  HRESULT GetHistoryFromComponent( const CATPLMID & iComponent, 
                                   CATIAdpErrorMonitor * iopErrorMonitor,
                                   CATListAdpTransactionHistory & oTransactionHistoryList,
								   CATBoolean iOrderByDate=FALSE );

/**
 * Get the actions which leaded to modifications on the provided components.
 * @param [in] iComponents
 *  The components which actions have to be introspected from.
 * @param [inout] iopErrorMonitor
 *  The monitor that will be informed of the errors
 * @param [out] oActionsParser
 *  A parser enabling to iterate on the resulting actions.
 * @param [in] iOrderByDate
 *  tell if the list of transaction history will be ordered by date or not
 * @return
 *  An HRESULT value
 * <dl>
 *  <dt>E_FAIL</dt><dd>Could not get actions from provided components. See error monitor for more informations</dd>
 * </dl>  
 */
  HRESULT GetActionsFromComponents( const CATLISTV(CATPLMID) & iComponents, 
                                    CATIAdpErrorMonitor * iopErrorMonitor,
                                    CATAdpActionsParser & oActionsParser,
									CATBoolean iOrderByDate=FALSE );

/**
 * Get history of all modifications given a precise component
 * @param [in] iComponents
 *  The components which actions have to be introspected from.
 * @param [in/out] ioErrorMonitor
 *  the monitor that will be informed of the errors
 * @param [out] oLog
 *  the list of transaction history, see @href CATListCATPLMTLogEntry
 * @return
 *  An HRESULT value
 * <dl>
 *  <dt>E_FAIL</dt><dd>Could not get history from action. See error monitor for more informations</dd>
 * </dl>  
 */
  HRESULT GetLogFromComponents(const CATLISTV(CATPLMID) &iComponents, CATIAdpErrorMonitor *ioErrorMonitor, CATListPtrCATPLMTLogEntry &oLog);


/**
 * Check if an action has already been used for a modification id database.
 * @param [in] iAction
 *   The action to check
 * @param [inout] iopErrorMonitor
 *  the monitor that will be informed of the errors
 * @param [out] oEntryExists
 *  TRUE if a modification was made under the input action
 * @return
 * <dl>
 *  <dt>E_FAIL</dt><dd>Could not get history from action. See error monitor for more informations</dd>
 *  <dt>E_NOTIMPL</dt><dd>The provider can't answer this question</dd>
 * </dl>  
 */
  HRESULT CheckHistoryFromAction ( const CATPLMID & iAction, 
                                   CATIAdpErrorMonitor * iopErrorMonitor,
                                   CATBoolean & oEntryExists );

private:
/**
 * @nodoc
 */
  HRESULT ManageHistoryResults( CATAdpHistoryHandler & iHManager, CATListAdpTransactionHistory & oTransactionHistoryList );

};
#endif
