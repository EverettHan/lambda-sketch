/*
 * CATIOmyOfflineDataAccess.h
 *
 *  Created on: Apr 23, 2013
 *      Author: PJQ
 */

#ifndef CATIOMYOFFLINEDATAACCESS_H_
#define CATIOMYOFFLINEDATAACCESS_H_

#include "CATOMYBaseSession.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATSysErrorDef.h"
#include "CATIOmxBinaryStream.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOMYBaseSession IID IID_CATIOmyOfflineDataAccess;
#else
extern "C" const IID IID_CATIOmyOfflineDataAccess ;
#endif

/**
 * @level Protected
 * @usage U4
 * Interface for specific implementation of CATOmyOfflineDataAccess backend
 */
class ExportedByCATOMYBaseSession CATIOmyOfflineDataAccess : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  virtual HRESULT SetOfflineData(const CATUnicodeString & iDataKey, CATIOmxBinaryStream * iData)=0;
  virtual HRESULT HasOfflineData(const CATUnicodeString & iDataKey)=0;
  virtual HRESULT GetOfflineData(const CATUnicodeString & iDataKey, CATIOmxBinaryStream * oData)=0;
};
CATDeclareHandler(CATIOmyOfflineDataAccess,CATBaseUnknown);
#endif /* CATIOMYOFFLINEDATAACCESS_H_ */
