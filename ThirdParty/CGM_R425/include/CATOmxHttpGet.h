//===================================================================
// COPYRIGHT Dassault Systemes 2018/05/17
//===================================================================
// CATOmxHttpGet.cpp
// Header definition of class CATOmxHttpGet
//===================================================================
//
// Usage notes:
//
// HTTP GET method.
// The HTTP GET method is defined in section 9.3 of RFC2616 :
//    The GET method means retrieve whatever information (in the form of an entity) is identified by the Request-URI.
//    If the Request-URI refers to a data-producing process, it is the produced data which shall be returned as the entity in the response and not the source text of the process, unless that text happens to be the output of the process.
//
// Adapted from apache http: https://hc.apache.org/httpcomponents-client-ga/httpclient/apidocs/org/apache/http/client/methods/HttpGet.html
//
//===================================================================
//  2018/05/17 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATOmxHttpGet_H
#define CATOmxHttpGet_H

#include "CATOmxHttp.h"
#include "CATOmxHttpRequest.h"

class ExportedByCATOmxHttp CATOmxHttpGet: public CATOmxHttpRequest
{
public:
  CATOmxHttpGet(const CATUnicodeString& iURL);
  virtual ~CATOmxHttpGet();

  /*
  * Returns the HTTP method this request uses, such as GET, PUT, POST, or other.
  */
  virtual CATOmxKeyString GetMethod() const OMX_Cxx11_OVERRIDE;

private:
  CATOmxHttpGet (CATOmxHttpGet &);
  CATOmxHttpGet& operator=(CATOmxHttpGet&);
};


#endif