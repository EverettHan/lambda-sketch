// COPYRIGHT Dassault Systemes 2005
//===================================================================

/**
 * @level Protected
 * @usage U2
 */

#ifndef CATOmyCioNotifierAdapter_H
#define CATOmyCioNotifierAdapter_H

#include "CATOMYUtils.h"
#include "CATIOmyCioNotifier.h"

class CATOmyCioUrlUsageCtx;
class CATOmyCuteIOTransaction;

class ExportedByCATOMYUtils CATOmyCioNotifierAdapter: public CATIOmyCioNotifier
{

    CATDeclareClass;

public:
  CATOmyCioNotifierAdapter();
  ~CATOmyCioNotifierAdapter();
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
};

#endif // CATOmyCioNotifierAdapter_H
