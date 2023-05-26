//===================================================================
// COPYRIGHT Dassault Systemes 2018/05/18
//===================================================================
// CATOmxHttpEntity.cpp
// Header definition of class CATOmxHttpEntity
//===================================================================
//
// Usage notes:
//
// An entity that can be sent or received with an HTTP message. Entities can be found in some requests and in responses, where they are optional.
// There are two distinct types of entities, depending on where their content originates:
//    streamed: The content is received from a stream, or generated on the fly. In particular, this category includes entities being received from a connection. Streamed entities are generally not repeatable.
//    self-contained: The content is in memory or obtained by means that are independent from a connection or other entity. Self-contained entities are generally repeatable.
//
// Adapted from apache http: http://hc.apache.org/httpcomponents-core-ga/httpcore/apidocs/org/apache/http/HttpEntity.html
//
//===================================================================
//  2018/05/18 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATOmxHttpEntity_H
#define CATOmxHttpEntity_H

#include "CATOmxHttp.h"
#include "CATIOmxInputStream.h"
#include "CATOmxHttpHeader.h"
#include "CATOmxSharable.h"

class ExportedByCATOmxHttp CATOmxHttpEntity : public CATOmxSharable
{
public:
  /*
  * Returns a content stream of the entity.
  * Repeatable entities are expected to create a new instance of CATIOmxInputStream for each invocation of this method and therefore can be consumed multiple times.
  * Entities that are not repeatable are expected to return the same CATIOmxInputStream instance and therefore may not be consumed more than once.
  *
  * @param [oInputStream] [out, CATBaseUnknown#Release]
  *   the content as an input stream
  *
  * @return
  *   S_OK input stream returned correctly. Do not forget to RELEASE it.
  *   E_FAIL the entity cannot be represented as an input stream.
  */
  virtual HRESULT GetContent(CATIOmxInputStream*& oInputStream) = 0;

  /*
  * Obtains the Content-Encoding header, if known.
  * This is the header that should be used when sending the entity, or the one that was received with the entity. 
  *
  * @return
  *   the Content-Encoding header for this entity, or null (CATOmxHttpHeader::IsNull()) if the content encoding is unknown.
  */
  virtual CATOmxHttpHeader GetContentEncoding() const = 0;

  /*
  * Obtains the Content-Type header, if known.
  * This is the header that should be used when sending the entity, or the one that was received with the entity.
  * It can include a charset attribute.
  *
  * @return
  *   the Content-Type header for this entity, or null (CATOmxHttpHeader::IsNull()) if the content type is unknown.
  */
  virtual CATOmxHttpHeader GetContentType() const = 0;

  /*
  * Tells the length of the content, if known.
  *
  * @return
  *   the number of bytes of the content, or a negative number (-1) if unknown.
  */
  virtual CATLONG64 GetContentLength() const = 0;

  /*
  * Tells if the entity is capable of producing its data more than once.
  * A repeatable entity's getContent() method can be called more than once whereas a non-repeatable entity's can not.
  *
  * @return
  *   true if the entity is repeatable, false otherwise.
  */
  virtual bool IsRepeatable() const = 0;

  /*
  * Tells whether this entity depends on an underlying stream. Streamed entities that read data directly from the socket should return true.
  * Self-contained entities should return false.
  *
  * @return
  *   true if the entity content is streamed, false otherwise
  */
  virtual bool IsStreaming() const = 0;

  /*
  * Tells about chunked encoding for this entity.
  * The primary purpose of this method is to indicate whether chunked encoding should be used when the entity is sent.
  * For entities that are received, it can also indicate whether the entity was received with chunked encoding.
  *
  * @return
  *   true if chunked encoding is preferred for this entity, or false if it is not
  */
  virtual bool IsChunked() const = 0;
};

#endif
