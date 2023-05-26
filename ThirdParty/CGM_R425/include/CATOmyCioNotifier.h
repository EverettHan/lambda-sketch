// COPYRIGHT Dassault Systemes 2005
//===================================================================

/**
 * @level Private
 * @usage U2
 */
#ifndef __CATOMYCIONOTIFIER_H
#define __CATOMYCIONOTIFIER_H

#include "CATOMYUtils.h"
#include "CATIOmyCioNotifier.h"
#include "CATOmyCioNotifierAdapter.h"

class ExportedByCATOMYUtils CATOmyCioNotifier : public CATOmyCioNotifierAdapter
{
public:
  CATOmyCioNotifier();
  ~CATOmyCioNotifier();
  /////////////////////////////////////////
  /// CATIOmyCioNotifier implementation ///
  /////////////////////////////////////////
  /** 
  * Gets the filter of notification event.
  * <br><b>Role</b>: Informs on which event about CATOmyCioUrlUsageCtx, CuteIO must raised a notification .
  * @return
  *   The event filter
  */
  virtual int GetContextNotificationMode() const;
  
  /** 
  * Gets the filter of notification event.
  * <br><b>Role</b>: Informs on which event about CATOmyCioUrlUsageCtx, CuteIO must raised a notification .
  * @return
  *   The event filter
  */  
  virtual int GetTransactionNotificationMode() const;

   /** 
   * Informs that the action specified by the notification has successed
   * <br><b>Role</b>: CuteIO infoms caller that the action about the
   * UrlUsage is successful. This action is specified by the content of the notification
   * @param iUrlUsageCtx [in]
   *   The returned UrlContex.
   * @param iNotifications [in]
   *   The type of action that succeed
   */
   virtual void CtxSuccessful(const CATOmyCioUrlUsageCtx* oUrlUsageCtx, CATOmyCioContextNotifications iNotifications);

   /** 
   * Informs that the action specified by the notification has failed
   * <br><b>Role</b>: CuteIO infoms caller that the action about the
   * UrlUsage is successful. This action is specified by the content of the notification
   * @param iUrlUsageCtx [in]
   *   The returned UrlContex.
   * @param iNotifications [in]
   *   The type of action that succeed.
   */
   virtual void CtxError(const CATOmyCioUrlUsageCtx* iUrlUsageCtx, CATOmyCioContextNotifications iNotifications, int iErrorCode);

   /** 
   * Informs that a transaction has change this state, into a specified state.
   * @param iTransaction [in]
   *   The transaction taht has changed its states.
   * @param iState [in]
   *   The new state notifiaction of the transaction.
   */
   virtual void TransactionChangeState(const CATOmyCuteIOTransaction* iTransaction, CATOmyCioTransactionNotifications iState);

protected:
  // Success
  virtual void S_CachedInPC(const CATOmyCioUrlUsageCtx* iUrlUsageCtx);
  virtual void S_CachedInSL(const CATOmyCioUrlUsageCtx* iUrlUsageCtx);
  virtual void S_CachedInXM(const CATOmyCioUrlUsageCtx* iUrlUsageCtx);
  virtual void S_CachedInU(const CATOmyCioUrlUsageCtx* iUrlUsageCtx);
  virtual void S_CachedConnectionCreated(const CATOmyCioUrlUsageCtx* iUrlUsageCtx);
  virtual void S_SentToDestination(const CATOmyCioUrlUsageCtx* iUrlUsageCtx);
  virtual void S_CachedConnectionClosed(const CATOmyCioUrlUsageCtx* iUrlUsageCtx);
  // failure
  virtual void E_CachedInPC(const CATOmyCioUrlUsageCtx* iUrlUsageCtx, int iErrorCode);
  virtual void E_CachedInSL(const CATOmyCioUrlUsageCtx* iUrlUsageCtx, int iErrorCode);
  virtual void E_CachedInXM(const CATOmyCioUrlUsageCtx* iUrlUsageCtx, int iErrorCode);
  virtual void E_CachedInU(const CATOmyCioUrlUsageCtx* iUrlUsageCtx, int iErrorCode);
  virtual void E_CachedConnectionCreated(const CATOmyCioUrlUsageCtx* iUrlUsageCtx, int iErrorCode);
  virtual void E_SentToDestination(const CATOmyCioUrlUsageCtx* iUrlUsageCtx, int iErrorCode);
  virtual void E_CachedConnectionClosed(const CATOmyCioUrlUsageCtx* iUrlUsageCtx, int iErrorCode);
  // Change of transaction state
  virtual void TransCreation(const CATOmyCuteIOTransaction* iTransaction);
  virtual void TransPreparation(const CATOmyCuteIOTransaction* iTransaction);
  virtual void TransExecution(const CATOmyCuteIOTransaction* iTransaction);
  virtual void TransCommitment(const CATOmyCuteIOTransaction* iTransaction);
  virtual void TransAbort(const CATOmyCuteIOTransaction* iTransaction);
  virtual void TransClosure(const CATOmyCuteIOTransaction* iTransaction);
};

#endif

