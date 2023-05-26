#ifndef CATProxyTransaction_H
#define CATProxyTransaction_H

// COPYRIGHT DASSAULT SYSTEMES 2005
/**
 * @level Protected
 * @usage U1
 */
#include "ExportedByCATPLMTos.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"
#include "CATOmxSR.h"
#include "CATProxyTransactionPurpose.h"
#include "CATErrorMacrosEx.h"

class CATError;
class CATProxySpace;
class CATComponentId;
class CATOxTransaction;
class CATProxyTransaction;

//==========================================================================
// How opening a Transaction (CATProxyTransactionManager.h must be included)
//==========================================================================
//
//		CATProxySpace space(...);
//    CATBoolean ok = FALSE;
//    CATProxyTransactionBegin(space, transaction, CatPLMTransactionXXX) 
//    {
//       //The XXX transaction is opened
//       //transaction is an handle on the current transaction (CATProxyTransaction)
//       your code
//       if(everything is fine)
//         ok = TRUE;
//       
//    }
//    CATProxyTransactionEnd(TransactionContext, internalTransaction, ok);
//
//===========================================================================
class ExportedByCATPLMTos CATProxyTransaction
{
public:
  /**
   * do not use directly, use CATProxyTransactionBegin
   */
  CATProxyTransaction(const CATProxySpace& space, CATProxyTransactionPurpose iPurpose);
  CATProxyTransaction(const CATComponentId& cid, CATProxyTransactionPurpose iPurpose);
  ~CATProxyTransaction();

  /**
   * do not use directly, use CATProxyTransactionEnd
   */
  void EndTransaction(CATBoolean iOkay);

  /**
  * Returns related space
  */
  CATProxySpace GetRelativeSpace() const;

  /**
   * Enable registration of deferred operations on this transaction
   */
  bool EnableDeferredExecution();

  inline CATOxTransaction* GetUsage() const { return const_cast<CATOxTransaction*>(_ImplUsage.Ref()); };
  inline void SetUsage(CATOxTransaction* iTransaction) { _ImplUsage = iTransaction; }

  /**
   * Commits the transaction and flushes it.
   * Notice that you caller take ownership of the possible error and must handle it.
   */
  CATError* CommitNow();
private:
  CATError* _EndTransaction(CATBoolean iOkay);
  CATProxyTransaction() = delete;
  CATProxyTransaction(const CATProxyTransaction &iCopy) = delete;
  CATProxyTransaction& operator=(const CATProxyTransaction &iCopy) = delete;

  CATOmxSR<CATOxTransaction> _ImplUsage;
};

/**
*  Start of Session Transaction
*/
#define CATProxyTransactionBegin(context,transaction,purpose) \
  { \
  CATProxyTransaction transaction(context,purpose); \
  CATXH_ENSURE_DESTRUCTION(transaction);

/**
*  End of Session Transaction
*/
#define CATProxyTransactionEnd(context,transaction,iOkay) \
  transaction.EndTransaction(iOkay); \
  } \
  do {} while(false)

#endif
