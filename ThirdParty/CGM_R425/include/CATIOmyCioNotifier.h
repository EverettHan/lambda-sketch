// COPYRIGHT Dassault Systemes 2005
//===================================================================
//  May 2005  Creation: Code generated by the CAA wizard  FLE

/**
 * @level Protected
 * @usage U4
 */
#ifndef CATIOmyCioNotifier_H
#define CATIOmyCioNotifier_H

#include "CATOMYCuteIO.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOMYCuteIO IID IID_CATIOmyCioNotifier;
#else
extern "C" const IID IID_CATIOmyCioNotifier ;
#endif


class CATUuid;
class CATOmyCioUrlUsageCtx;
class CATOmyCuteIOTransaction;

/**
* Interface representing a notifier to follow actions taken by CuteIO.
* <p>
* This interface is implemented by a CATOmyCioNotifierAdapter.
*/
class ExportedByCATOMYCuteIO CATIOmyCioNotifier: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
    
  enum  CATOmyCioContextNotifications
  { 
    NoCtxNotification = 0x00, // No notification will be raised.
    CachedInPC = 0x01, // Informs caller that an URL is cached in Persistent Cache.
    CachedInSL = 0x02, // Informs caller that an URL is cached in Selective Loading Cache.
    CachedInXM  = 0x04, // Informs caller that an URL is cached in eXtended Memory Cache.
    CachedInU = 0x08, // Informs caller that an URL is cached in Upload Cache.
    CachedInLV = 0x80, //
    CachedConnectionCreated = 0x10, // Informs caller that an URLConnection is created on the last cached stream.
    SentToDestination = 0x20, // Informs caller that an URL is sent to distant location (Usually the Vault).
    CachedConnectionClosed = 0x40, // Informs caller that an URLConnection has been closed on a cached stream.
    AllCtxNotifications = 0xFF // All notification will be raised.
  } ;

  enum  CATOmyCioTransactionNotifications
  { 
    NoTransactionNotification = 0x00, // No notification will be raised.
    Creation = 0x01, // A transaction is created.
    Preparation = 0x02, // A transaction is closed.
    Execution  = 0x04, // A transaction is executed.
    Commitment = 0x08, // A transaction is commited.
    Abort = 0x10, // A transaction is aborted.
    Closure = 0x20, // A transaction is closed.
    AllTransactionNotifications = 0xFF  // All notification will be raised.
  } ;
  
  
  /** 
  * Gets the filter of notification event.
  * <br><b>Role</b>: Informs on which event about CATOmyCioUrlUsageCtx, CuteIO must raised a notification .
  * @return
  *   The event filter
  */
  virtual int GetContextNotificationMode() const = 0;
  
  /** 
  * Gets the filter of notification event.
  * <br><b>Role</b>: Informs on which event about CATOmyCioUrlUsageCtx, CuteIO must raised a notification .
  * @return
  *   The event filter
  */  
  virtual int GetTransactionNotificationMode() const = 0;

   /** 
   * Informs that the action specified by the notification has successed
   * <br><b>Role</b>: CuteIO infoms caller that the action about the
   * UrlUsage is successful. This action is specified by the content of the notification
   * @param iUrlUsageCtx [in]
   *   The returned UrlContex.
   * @param iNotifications [in]
   *   The type of action that succeed
   */
   virtual void CtxSuccessful(const CATOmyCioUrlUsageCtx* oUrlUsageCtx, CATOmyCioContextNotifications iNotifications) = 0;

   /** 
   * Informs that the action specified by the notification has failed
   * <br><b>Role</b>: CuteIO infoms caller that the action about the
   * UrlUsage is successful. This action is specified by the content of the notification
   * @param iUrlUsageCtx [in]
   *   The returned UrlContex.
   * @param iNotifications [in]
   *   The type of action that succeed.
   */
   virtual void CtxError(const CATOmyCioUrlUsageCtx* iUrlUsageCtx, CATOmyCioContextNotifications iNotifications, int iErrorCode) = 0;

   /** 
   * Informs that a transaction has change this state, into a specified state.
   * @param iTransaction [in]
   *   The transaction taht has changed its states.
   * @param iState [in]
   *   The new state notifiaction of the transaction.
   */
   virtual void TransactionChangeState(const CATOmyCuteIOTransaction* iTransaction, CATOmyCioTransactionNotifications iState) = 0;
};



#endif
