//===================================================================
// COPYRIGHT Dassault Systemes 2018/05/23
//===================================================================
// CATOmxBasicHttpResponse.cpp
// Header definition of class CATOmxBasicHttpResponse
//===================================================================
//
// Usage notes:
//
// Basic implementation of CATOmxHttpResponse.
//
// Adapted from apache http: http://hc.apache.org/httpcomponents-core-ga/httpcore/apidocs/org/apache/http/message/BasicHttpResponse.html
//
//===================================================================
//  2018/05/23 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATOmxBasicHttpResponse_H
#define CATOmxBasicHttpResponse_H

#include "CATOmxHttp.h"
#include "CATOmxHttpResponse.h"
#include "CATOmxCxxPortability.h"
#include "CATOmxSR.h"

class ExportedByCATOmxHttp CATOmxBasicHttpResponse: public CATOmxHttpResponse
{
public:
  CATOmxBasicHttpResponse(const CATOmxHttpStatusLine& iStatusLine);
  virtual ~CATOmxBasicHttpResponse();

  CATOmxHttpEntity* GetEntity() const OMX_Cxx11_OVERRIDE;
  void SetEntity(CATOmxHttpEntity* ipEntity);

  CATOmxHttpStatusLine GetStatusLine() const OMX_Cxx11_OVERRIDE;
  void SetStatusLine(const CATOmxHttpStatusLine& iStatusLine);

private:
  CATOmxBasicHttpResponse(CATOmxBasicHttpResponse &);
  CATOmxBasicHttpResponse& operator=(CATOmxBasicHttpResponse&);

  CATOmxSR<CATOmxHttpEntity> _spEntity;
  CATOmxHttpStatusLine _StatusLine;
};

#endif