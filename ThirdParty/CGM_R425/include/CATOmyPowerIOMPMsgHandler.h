//========================================================================================================
// COPYRIGHT Dassault Systemes 2011
//========================================================================================================
//
//  CATOmyPowerIOMPMsgHandler.h
//
//  Generic powerIO message handler from which all messge handlers should
//  inherit.
//
//  It is a generic Backbone Transaction Message Handler, from which all other
//  message handlers should inherit (c++ and OM). It checks the coherence of the
//  messageCount and the transactionID before calling the pure virtual
//  HandleCATIOmyPowerIOMPTransactionMsg method that must be implemented by
//  children classes. The purpose of this handler is to give all transaction
//  message handlers the same behavior checking message count and transactionID
//
//========================================================================================================

/**
 * @level Private
 * @usage U1
 */

#ifndef _CATOMYPOWERIOMPMSGHANDLER_H_
#define _CATOMYPOWERIOMPMSGHANDLER_H_

#include "CATBaseUnknown.h"     // For AddRef Release (I presume...)
#include "CATOMYCuteIO.h"       // For the dll specific data

// Backbone
#include "CATICommMsg.h"        // For CATAssert on messages

class CATOmyPowerIOMPCommand;

class ExportedByCATOMYCuteIO CATOmyPowerIOMPMsgHandler: public CATBaseUnknown{
  // OM declaration
	CATDeclareClass;

 public:
  // ####################################################################################################
  // Constructors and destructors
  // ####################################################################################################
  CATOmyPowerIOMPMsgHandler();
  virtual ~CATOmyPowerIOMPMsgHandler();

  // ####################################################################################################
  // Implements CATIMessageReceiver::HandleMessage
  // ####################################################################################################
  /**
   * Handle the received message
   *
   * It asserts if the message count is not good, that's to say it DOES NOT
   * VERIFY one of these three points:
   * - It derives from CATOmyPowerIOMPTransactionMsg
   * - It contains a valid transaction ID or message count
   * - Its associated process declares it is the message it expected (condition
   * tested on the message count, @see CATOmyAsyncProcess::CheckMessageCount for
   * more info)
   *
   * In the special case it does not find any process dealing with the
   * transaction Id, this method assumes the transaction may have been aborted
   * and this is a residual message. It then continues without asserting. Else,
   * it calls the HandleMessageCustom method and asserts on the success of the
   * result
   *
   * @param ipiTransactionMessage Incoming message
   *
   */
  void HandleMessage(CATICommMsg *ipiTransactionMessage);

 protected:
  /**
   * Method handling CATOmyPowerIOMPTransactionMsg type incoming messages
   *
   * It must be implemented by children of current class.
   *
   * @param ipiTransactionMessage The incoming message
   * @return S_OK if all was OK, else E_FAIL
   */
  virtual HRESULT HandleCATIOmyPowerIOMPTransactionMsg(const char * iMsgName, CATICommMsg *ipiTransactionMessage) = 0;

 private:
  // For the copy methods not to be automatically constructed
  CATOmyPowerIOMPMsgHandler& operator = ( const CATOmyPowerIOMPMsgHandler&);
  CATOmyPowerIOMPMsgHandler(const CATOmyPowerIOMPMsgHandler&);

  CATOmyPowerIOMPCommand * _pCommandAsync;
};

#endif
