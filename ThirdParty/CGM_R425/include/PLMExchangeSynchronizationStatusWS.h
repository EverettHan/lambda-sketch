//===================================================================
// COPYRIGHT Dassault Systemes 2021
//===================================================================
// PLMExchangeSynchronizationStatusWS.h
// Header declaration of class PLMExchangeSynchronizationStatusWS
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2021/04/09 MPL8: Creation
//======

#include "CATIAV5Level.h"
								
#ifdef CATIAR424  // EBD - FUN111890	

#ifndef PLMExchangeSynchronizationStatusWS_H
#define PLMExchangeSynchronizationStatusWS_H

#include "PLMExchangeWebServices.h"
#include "CATOmxAny.h"
#include "CATOmxArray.h"
#include "CATOmxList.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfCATString.h"

class ExportedByPLMExchangeWebServices PLMExchangeSynchronizationStatusWS
{

public:
   PLMExchangeSynchronizationStatusWS();
   virtual ~PLMExchangeSynchronizationStatusWS();

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

