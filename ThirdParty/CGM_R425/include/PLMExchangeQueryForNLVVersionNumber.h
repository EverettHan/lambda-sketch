//===================================================================
// COPYRIGHT Dassault Systemes 2016/10/04
//===================================================================
// PLMExchangeQueryForNLVVersionNumber.h
// Header declaration of class PLMExchangeQueryForNLVVersionNumber
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2019/01/28 MPL8: Creation
//======

#ifndef PLMExchangeQueryForNLVVersionNumber_H
#define PLMExchangeQueryForNLVVersionNumber_H

#include "PLMExchangeWebServices.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfCATString.h"
#include "CATOmxAny.h"
#include "CATOmxArray.h"


class ExportedByPLMExchangeWebServices PLMExchangeQueryForNLVVersionNumber
{
public:

   // Standard constructors and destructors
   // -------------------------------------
   PLMExchangeQueryForNLVVersionNumber();
   virtual ~PLMExchangeQueryForNLVVersionNumber();

   HRESULT ExecuteQuery(CATUnicodeString & iRequestMessage,
                        CATOmxArray<CATOmxAny>* & oRecordSet);

   HRESULT CreateJsonObjectSetForVersionNumberWS(CATUnicodeString & iType, CATUnicodeString & iname, CATUnicodeString & iPolicy, CATUnicodeString & iPath);

   HRESULT CreateRequestMesageForVersionnumberWS(CATUnicodeString & oRequestMessage);
   HRESULT ReadRecordAttributes(const CATOmxAny *ipRecordRead, CATUnicodeString & oPath);
   HRESULT ReadRecordAttributes(const CATOmxAny *ipRecordRead, CATUnicodeString & oType, CATUnicodeString & oName, CATUnicodeString & oPath, CATUnicodeString & oCode);

   CATOmxAny         _jsonMainObjectAny;
   CATOmxAny         _jsonList;

private:

   HRESULT InitializeQuery();

   CATUnicodeString           _ServerURL;
   CATUnicodeString           _FullWebServicePath;
   CATUnicodeString           _SecurityRole;

};
#endif

