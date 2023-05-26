/**
 * @level Protected
 * @usage U1
 */

//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/11/25
//===================================================================
// CATIOmyPowerIOMPPLMQLResultMsgList.cpp
// Header definition of class CATIOmyPowerIOMPPLMQLResultMsgList
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2010/11/25 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIOmyPowerIOMPPLMQLResultMsgList_H
#define CATIOmyPowerIOMPPLMQLResultMsgList_H

#include "CATIOmyPowerIOMPTransactionMsg.h"

extern ExportedByCATOMYCuteIO  IID IID_CATIOmyPowerIOMPPLMQLResultMsgList ;

class CATIOmyPowerIOMPPLMQLResultMsg;

/**
   FIFO List of CATIOmyPowerIOMPPLMQLResultMsg
*/
class ExportedByCATOMYCuteIO CATIOmyPowerIOMPPLMQLResultMsgList: public CATIOmyPowerIOMPTransactionMsg
{
  CATDeclareInterface;

public:

  /**
   * Add a message in the list
   * @param ipMsg The message to add
   * @return S_OK if everything goes well, E_FAIL if failed
   */
  virtual HRESULT PushMessage(CATIOmyPowerIOMPPLMQLResultMsg* ipiMsg) = 0;

  /**
   * Pop a message from the list (return it and remove it from the list)
   * @param opiMsg The message to add
   * @return S_OK if everything goes well,
             E_FAIL if failed,
             S_FALSE to warn the list is empty
   */
  virtual HRESULT PopMessage(CATIOmyPowerIOMPPLMQLResultMsg* &opiMsg) = 0;

  /**
   * Remove the message from the list
   * @param ipMsg The message to remove
   * @return S_OK if everything goes well else E_FAIL
   */
  virtual HRESULT RemoveMessage(CATIOmyPowerIOMPPLMQLResultMsg* ipiMsg) = 0;

  /**
   * Returns the size of the list
   * @param size the size of the list
   * @return S_OK if everything goes well else E_FAIL
   */
  virtual HRESULT Size(ULONG& oSize) = 0;

  /**
   * Remove all the messages from the list
   * @return S_OK if everything goes well else E_FAIL
   */
  virtual HRESULT RemoveAll() = 0;

};

//-----------------------------------------------------------------------

#endif