//===================================================================
// COPYRIGHT Dassault Systemes 2018/05/22
//===================================================================
// CATOmxHttpConstants.cpp
// Header definition of class CATOmxHttpConstants
//===================================================================
//
// Usage notes:
//
// Constants for http:
//    Methods
//    Headers
//    ContentTypes
//    Charset
//    Protocol
//
//===================================================================
//  2018/05/22 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATOmxHttpConstants_H
#define CATOmxHttpConstants_H

#include "CATOmxHttp.h"
#include "CATOmxKeyString.h"

class ExportedByCATOmxHttp CATOmxHttpConstants
{
public:
  static const CATOmxHttpConstants& s();

  // Methods
  CATOmxKeyString ksGET;
  CATOmxKeyString ksHEAD;
  CATOmxKeyString ksOPTIONS;
  CATOmxKeyString ksTRACE;
  CATOmxKeyString ksDELETE;
  CATOmxKeyString ksPOST;
  CATOmxKeyString ksPATCH;
  CATOmxKeyString ksPUT;

  // Headers
  CATOmxKeyString ksContentType;
  CATOmxKeyString ksContentEncoding;
  CATOmxKeyString ksAccept;
  CATOmxKeyString ksSecurityContext;

  // ContentType
  CATOmxKeyString ksCharsetParam;
  CATOmxKeyString ksApplicationJson;
  CATOmxKeyString ksApplicationXml;
  CATOmxKeyString ksApplicationOctetStream;
  CATOmxKeyString ksTextPlain;
  CATOmxKeyString ksTextHtml;
  CATOmxKeyString ksTextXml;

  // Charset
  CATOmxKeyString ksUTF_8;
  CATOmxKeyString ksUTF_16;
  CATOmxKeyString ksUS_ASCII;
  CATOmxKeyString ksASCII;
  CATOmxKeyString ksISO_8859_1;

  // Protocol
  CATOmxKeyString ksHTTP;

private:
  CATOmxHttpConstants();
  ~CATOmxHttpConstants();
};

#endif
