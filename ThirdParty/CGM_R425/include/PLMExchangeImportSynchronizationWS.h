//===================================================================
// COPYRIGHT Dassault Systemes 2021
//===================================================================
// PLMExchangeImportSynchronizationWS.h
// Header declaration of class PLMExchangeImportSynchronizationWS
//===================================================================
//
// Usage notes:
//
//===================================================================

#include "CATIAV5Level.h"

#ifdef CATIAR424  // EBD - FUN111890	

#ifndef PLMExchangeImportSynchronizationWS_H
#define PLMExchangeImportSynchronizationWS_H



#include "PLMExchangeWebServices.h"
#include "CATOmxAny.h"
#include "CATOmxArray.h"
#include "CATOmxList.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfCATString.h"

class ExportedByPLMExchangeWebServices PLMExchangeImportSynchronizationWS
{

public:
   PLMExchangeImportSynchronizationWS();
   virtual ~PLMExchangeImportSynchronizationWS();

   HRESULT ExecuteQuery(const CATUnicodeString &iJSONRequestMessage,
      CATOmxArray<CATOmxAny>* & oRecordSet);

   HRESULT ParseResponseMessage(const CATUnicodeString & iResponseMessage, CATOmxArray<CATOmxAny>*& oRecordReadSet);

private:

   HRESULT InitializeQuery();
   
   HRESULT CreateRequestHeaders(CATListOfCATUnicodeString& oRequestHeaders);

   CATUnicodeString           _ServerURL;
   CATUnicodeString           _FullWebServicePath;
   CATUnicodeString           _SecurityRole;
};
//----------------------------------------------------------------------------------------
#endif
#endif

