/* COPYRIGHT DASSAULT SYSTEMES 2009 */


#ifndef CATIUExitDRMAuthorizationId_H
#define CATIUExitDRMAuthorizationId_H

#include "CATWTypes.h"
#include "CATErrorDef.h"
#include "CATSysDRMHR.h"
#include "CATUnicodeString.h"

#undef  ExportedByJS0DRMDOC 
#ifdef  __JS0DRMDOC
#define ExportedByJS0DRMDOC DSYExport
#else
#define ExportedByJS0DRMDOC DSYImport
#endif
#include "DSYExport.h"


extern "C" const IID IID_CATIUExitDRMAuthorizationId;


class ExportedByJS0DRMDOC  CATIUExitDRMAuthorizationId : public IUnknown
{
public:

  virtual HRESULT DRMRetrieveAuthorizationId (void  *&oDRMAuthorization,
					      size_t &oDRMAuthorizationIdSize)= 0;
  

};



#endif



