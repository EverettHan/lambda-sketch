//===================================================================
// COPYRIGHT Dassault Systemes 2016/10/04
//===================================================================
// PLMExchangeQueryForNLVVersionGraphPath.h
// Header declaration of class PLMExchangeQueryForNLVVersionGraphPath
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2019/01/28 MPL8: Creation
//======

#ifndef PLMExchangeQueryForNLVVersionGraphPath_H
#define PLMExchangeQueryForNLVVersionGraphPath_H

#include "PLMExchangeWebServices.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfCATString.h"
#include "CATOmxAny.h"
#include "CATOmxArray.h"


class ExportedByPLMExchangeWebServices PLMExchangeQueryForNLVVersionGraphPath
{
public:

    // Standard constructors and destructors
    // -------------------------------------
    PLMExchangeQueryForNLVVersionGraphPath();
    virtual ~PLMExchangeQueryForNLVVersionGraphPath();


   /* enum WebServiceContext
    {
        WebServiceContextUnknown = 0,
        WebServiceContextImport,
        WebServiceContextExport,
    };*/

   

    HRESULT ExecuteQuery(const CATListOfCATUnicodeString & iListPhysicalIDs,
                         CATOmxArray<CATOmxAny>* & oRecordSet);

    HRESULT ReadRecordAttributes(const CATOmxAny *ipRecordRead, CATUnicodeString & ousPhysicalID, CATUnicodeString & oPathValue);

private:

    HRESULT InitializeQuery();

    CATUnicodeString           _ServerURL;
    CATUnicodeString           _FullWebServicePath;
    CATUnicodeString           _SecurityRole;
};
#endif

