//========================================================================================================
// COPYRIGHT Dassault Systemes 2011
//========================================================================================================
//
//  CATOmyPowerIOMPTestTransactionMsg.h
//
//  Implementation of the CATIOmyPowerIOMPTestTransactionMsg interface.
//
//========================================================================================================

/**
 * @level Protected
 * @usage U1
 */

#ifndef _CATOMYPOWERIOMPTESTTRANSACTIONMSG_H_
#define _CATOMYPOWERIOMPTESTTRANSACTIONMSG_H_

#include "CATOmyPowerIOMPTransactionMsg.h"
#include "CATOMYCuteIO.h"

class ExportedByCATOMYCuteIO CATOmyPowerIOMPTestTransactionMsg: public CATOmyPowerIOMPTransactionMsg{
  CATDeclareClass;
 public:
  // ####################################################################################################
  // Constructors and destructors
  // ####################################################################################################
  CATOmyPowerIOMPTestTransactionMsg();
  virtual ~CATOmyPowerIOMPTestTransactionMsg();

  // ####################################################################################################
  // CATIOmyPowerIOMPTestTransactionMsg interface
  // ####################################################################################################
  virtual HRESULT SetMessageSize(unsigned int iSize);
  virtual HRESULT GetMessageSize(unsigned int& oSize);

  // ####################################################################################################
  // CATIStreamMsg Interface
  // ####################################################################################################
	virtual HRESULT StreamData    ( void **oBuffer, uint32 *oLen);
	virtual HRESULT UnstreamData  ( void  *iBuffer, uint32  iLen);
	virtual HRESULT FreeStreamData( void  *iBuffer, uint32  iLen);
	virtual HRESULT SetMessageSpecifications();

 private:
  /** The size of the message */
  unsigned int _messageSize;
  // For the copy methods not to be automatically constructed
  CATOmyPowerIOMPTestTransactionMsg& operator = ( const CATOmyPowerIOMPTestTransactionMsg&);
  CATOmyPowerIOMPTestTransactionMsg(const CATOmyPowerIOMPTestTransactionMsg&);
};

#endif
