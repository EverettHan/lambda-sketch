/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATOmyPowerIOMPGenericTransactionMsg_H
#define __CATOmyPowerIOMPGenericTransactionMsg_H

#include "CATOmyPowerIOMPTransactionMsg.h"
#include "CATUuid.h"
#include "CATIOmxBinaryStream.h"

#include "CATCollec.h"
#include "CATMessageClass.h"
#include "CATWOmxBinaryStream.h"
#include "CATIPLMTaskMP.h"
#include "CATOMYCuteIO.h"
#include "CATAssert.h"

class CATICommMsg ;
class CATIPLMCompRecordReadSet;

class ExportedByCATOMYCuteIO CATOmyPowerIOMPGenericTransactionMsg : public CATOmyPowerIOMPTransactionMsg
{
	CATDeclareClass;

public :

	CATOmyPowerIOMPGenericTransactionMsg(CATIPLMTaskMP * iTaskImpl) {CATAssert(iTaskImpl) ; _spTaskImpl=iTaskImpl;}
  CATOmyPowerIOMPGenericTransactionMsg()                          {};
	virtual ~CATOmyPowerIOMPGenericTransactionMsg()                 {};

  // CATIStreamMsg Interface
	virtual HRESULT StreamData    ( void **oBuffer, uint32 *oLen);
	virtual HRESULT UnstreamData  ( void  *iBuffer, uint32  iLen);
	virtual HRESULT FreeStreamData( void  *iBuffer, uint32  iLen);
	virtual HRESULT SetMessageSpecifications();
  
  virtual HRESULT Run(CATIPLMCompRecordReadSet*& opRecords) ;
  
private :

  CATOmxSR<CATIPLMTaskMP> _spTaskImpl;
};

#endif
