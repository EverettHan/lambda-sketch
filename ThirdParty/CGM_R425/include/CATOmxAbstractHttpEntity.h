//===================================================================
// COPYRIGHT Dassault Systemes 2018/05/18
//===================================================================
// CATOmxAbstractHttpEntity.cpp
// Header definition of class CATOmxAbstractHttpEntity
//===================================================================
//
// Usage notes:
//
// Abstract base class for entities.
// Provides the commonly used attributes for streamed and self-contained implementations of HttpEntity. 
//
// Adapted from apache http: http://hc.apache.org/httpcomponents-core-ga/httpcore/apidocs/org/apache/http/entity/AbstractHttpEntity.html
//
//===================================================================
//  2018/05/18 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATOmxAbstractHttpEntity_H
#define CATOmxAbstractHttpEntity_H

#include "CATOmxHttp.h"
#include "CATOmxHttpEntity.h"
#include "CATOmxHttpHeader.h"

class ExportedByCATOmxHttp CATOmxAbstractHttpEntity: public CATOmxHttpEntity
{
public:
  CATOmxAbstractHttpEntity();
  virtual ~CATOmxAbstractHttpEntity();

  CATOmxHttpHeader GetContentEncoding() const OMX_Cxx11_OVERRIDE;
  void SetContentEncoding(const CATOmxHttpHeader& iContentEncodingHeader);

  CATOmxHttpHeader GetContentType() const OMX_Cxx11_OVERRIDE;
  void SetContentType(const CATOmxHttpHeader& iContentTypeHeader);

  bool IsChunked() const OMX_Cxx11_OVERRIDE;
  void SetChunked(bool iChunked);

private:
  CATOmxHttpHeader _ContentEncodingHeader;
  CATOmxHttpHeader _ContentTypeHeader;
  bool _Chunked;
};

#endif