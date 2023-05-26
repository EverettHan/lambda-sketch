//===================================================================
// COPYRIGHT Dassault Systemes 2018/05/16
//===================================================================
// CATOmxHttpClient.cpp
// Header definition of class CATOmxHttpClient
//===================================================================
//
// Usage notes:
// This class represents only the most basic contract for HTTP request execution.
// It imposes no restrictions or particular details on the request execution process and leaves the specifics of state management, authentication and redirect handling up to individual implementations.
//
// Example:
//    CATOmxSR<CATOmxHttpRequest> spRequest(new CATOmxHttpGet("http://www.httpbin.org/get"), Steal);
//    CATOmxSR<CATOmxHttpResponse> spResponse;
//    CATOmxSR<CATOmxHttpClient> spHttpClient(new CATOmxDefaultHttpClient(FALSE), Steal);
//    TST_SUCCESS_AND_FAIL(spHttpClient->Execute(*spRequest, spResponse.AsPtrRef()));
//
//    CATOmxSR<CATOmxHttpEntity> spEntity = spResponse->GetEntity();
//    if (spEntity != NULL)
//    {
//      CATOmxSR<CATIOmxInputStream> spInputStream;
//      TST_SUCCESS_AND_FAIL(spEntity->GetContent(spInputStream.AsPtrRef()));
//
//      CATOmxUTF8String utf8String;
//      TST_SUCCESS_AND_FAIL(CATOmxIOUtils::ToString(spInputStream, utf8String));
//    }
//
//===================================================================
//  2018/05/16 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATOmxHttpClient_H
#define CATOmxHttpClient_H

#include "CATOmxHttp.h"
#include "CATOmxSharable.h"
#include "CATOmxHttpRequest.h"
#include "CATOmxHttpResponse.h"

class ExportedByCATOmxHttp CATOmxHttpClient: public CATOmxSharable
{
public:
  /*
  * Executes HTTP request using the default context.
  *
  * @param iRequest
  *   the request to execute 
    * if GetServiceName made on CATOmxHttpRequest returns NotDefined(CATAsyncHttpRequest), authentication is not managed, only this mode is supported.
  * @param oResponse [out, CATBaseUnknown#Release]
  *   the response to the request. This is always a final response, never an intermediate response with an 1xx status code.
  *   Whether redirects or authentication challenges will be returned or handled automatically depends on the implementation and configuration of this client.
  *
  * @return
  *   S_OK the request has been executed and response returned.
  *   E_FAIL connection issue or http protocol error.
  */
  virtual HRESULT Execute(CATOmxHttpRequest& iRequest, CATOmxHttpResponse*& oResponse);

protected:
  CATOmxHttpClient();
  virtual ~CATOmxHttpClient();

private:
  CATOmxHttpClient(CATOmxHttpClient&);
  CATOmxHttpClient& operator=(CATOmxHttpClient&);
};

#endif