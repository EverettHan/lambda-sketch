/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATOmyPowerIOMPTransactionMsg_H
#define __CATOmyPowerIOMPTransactionMsg_H

#include "CATBBMessage.h"

#include "CATOMYCuteIO.h"       // For the ExportedByCATOMYCuteIO definition

class CATIBBStreamer;
class ExportedByCATOMYCuteIO CATOmyPowerIOMPTransactionMsg : public CATBBMessage
{
	CATDeclareClass;

 public :

	CATOmyPowerIOMPTransactionMsg();
	virtual ~CATOmyPowerIOMPTransactionMsg();

  // CATIOmyPowerIOMPTransactionMsg Interface
	virtual HRESULT SetTransactionId(int iTransactionId);
	virtual HRESULT GetTransactionId(int & oTransactionId);

	virtual HRESULT SetMessageCount(int iMessageCount);
	virtual HRESULT GetMessageCount(int & oMessageCount);

  virtual HRESULT IsHandleOnIdle() { return _bHandleOnIdle ? S_OK : S_FALSE; }

 protected:
  /**
   * Streams the content of current transaction
   * @param pICATIBBStreamer The streamer to use
   */
  void StreamTransaction(CATIBBStreamer * pICATIBBStreamer);
  /**
   * Unstream the current transaction
   * @param pICATIBBStreamer The streamer to use
   */
  void UnstreamTransaction(CATIBBStreamer * pICATIBBStreamer);

  void SetHandleOnIdle(CATBoolean iHandleOnIdle) { _bHandleOnIdle = iHandleOnIdle; }

 private :
	int _TransactionId;
  unsigned int _MessageCount;
  CATBoolean _bHandleOnIdle;
};

#endif // __CATOmyPowerIOMPTransactionMsg_H
