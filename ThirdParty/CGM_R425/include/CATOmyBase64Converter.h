/**
* @level Private
* @usage U1
*/
#ifndef CATOmyBase64Converter_H
#define CATOmyBase64Converter_H

#include "CATOMYUtils.h"
#include "sequence_octet.h"

// COPYRIGHT DASSAULT SYSTEMES 2000

class CATUnicodeString;

class ExportedByCATOMYUtils CATOmyBase64Converter
{
public:
  /**
  * DO NOT USE EXCEPT FOR LEGACY PURPOSE.
  * DOES NOT CONFORM TO RFC2045
  * USE CAT(SysTS)CodePage::ConvertToBase64 INSTEAD.
  */
  static void SequenceToBase64String(const SEQUENCE(octet)& seq, CATUnicodeString& outstr);

  /**
  * BAD BASE 64 DECODER FOR THOSE WHO LOVE:
  *  _SEQUENCE_octet
  *  NO RETURN CODE
  *  STUPID ARGUMENTS
  *  INVALID RESULT IN CASE OF ERROR
  * USE CAT(SysTS)CodePage::ConvertFromBase64 INSTEAD.
  * NOTICE THAT CAT(SysTS)CodePage::ConvertFromBase64 WILL GIVE CORRECT RESULT
  * EVEN ON BASE 64 STRINGS ENCODED BY CATOMBBase64Converter::SequenceToBase64String
  */
  static void Base64StringToSequence(const CATUnicodeString& in, int len, SEQUENCE(octet)& out);

  /**
  * DO NOT USE EXCEPT FOR LEGACY PURPOSE.
  * DOES NOT CONFORM TO RFC2045
  * USE CAT(SysTS)CodePage::ConvertToBase64 INSTEAD.
  */
  static void SequenceToBase64String(const SEQUENCE(octet)& seq, char *& outstr,unsigned int& outlen);

};
#endif
