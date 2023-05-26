/**
 * @level Protected
 * @usage U2
 **/
/* -*-c++-*- */
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2009
//=============================================================================
 
#ifndef __CATIPowerIOLockBytes
#define __CATIPowerIOLockBytes

#include "CATILockBytes2Adapter.h"
#include "CATOMYUtils.h"
#include "CATVVSUrl.h"

extern ExportedByCATOMYUtils IID IID_CATIOmyPowerIOLockBytes;

class  ExportedByCATOMYUtils CATIOmyPowerIOLockBytes: public CATILockBytes2Adapter
{
public : 
  static inline const IID& ClassId() {return IID_CATIOmyPowerIOLockBytes;}
	virtual HRESULT GetVaultUrl(CATVVSUrl &oSrcUrl) = 0;
	virtual HRESULT GetWS(int &WS)=0;
	virtual HRESULT GetLateType(CATUnicodeString &oLT) = 0;
  virtual HRESULT OpenForReadNoBuffering() = 0;

};

#endif




