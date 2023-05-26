/**
 * @level Protected
 * @usage U1
 */
//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/10/27
//===================================================================
// CATIOmyPowerIOMPTransactionMsg.cpp
// Header definition of class CATIOmyPowerIOMPTransactionMsg
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2010/10/27 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIOmyPowerIOMPTransactionMsg_H
#define CATIOmyPowerIOMPTransactionMsg_H

#include "CATOMYCuteIO.h"
#include "CATBaseUnknown.h"

extern ExportedByCATOMYCuteIO  IID IID_CATIOmyPowerIOMPTransactionMsg ;

/**
 * Interface that should be implemented by all the messages handled by powerIO,
 * it is about the transaction information of the message
 */
class ExportedByCATOMYCuteIO CATIOmyPowerIOMPTransactionMsg : public CATBaseUnknown
{
  CATDeclareInterface;

public:

	virtual HRESULT SetTransactionId(int iTransactionId) = 0;
	virtual HRESULT GetTransactionId(int & oTransactionId) = 0;

	virtual HRESULT SetMessageCount(int iMessageCount) = 0;
	virtual HRESULT GetMessageCount(int & oMessageCount) = 0;

  virtual HRESULT IsHandleOnIdle() = 0;
};

//-----------------------------------------------------------------------

#endif
