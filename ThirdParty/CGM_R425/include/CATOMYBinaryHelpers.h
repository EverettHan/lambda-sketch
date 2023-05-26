// COPYRIGHT Dassault Systemes 2020
//===================================================================
//
// CATOMYBinaryHelpers.h
// Header definition of CATOMYBinaryHelpers
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// June 2020  Creation: EPB
//===================================================================
#ifndef CATOMYBinaryHelpers_H
#define CATOMYBinaryHelpers_H

#include "ObjectModelerSystem.h"

#include "CATSysErrorDef.h"

class CATBinary;
class CATUnicodeString;
class CATUuid;

/**
 * Describe your class here.
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 */
class ExportedByObjectModelerSystem CATOMYBinaryHelpers
{
public:
  static CATUnicodeString GetHexaName(const CATBinary & seq);

  static CATBinary GetSeqFromHexa(const char* Hexaname, int length);

  static int BuildHexaValueFromChar(const char * stringToConvert, int length, int * weight);

  static CATUnicodeString Convert(const CATUuid& iUuidValue, unsigned int iFormat, const CATUnicodeString& iFallback);

  static CATBinary Convert(const CATUuid& iUuidValue, unsigned int iFormat, const CATBinary& iFallback);

  static CATBinary Convert(const CATUnicodeString& iStr, unsigned int iFormat, const CATBinary& iFallback);

  static CATUnicodeString Convert(const CATBinary& iBinary, unsigned int iFormat, const CATUnicodeString& iFallback);

  static CATUuid Convert(const CATUnicodeString& istr, unsigned int iFormat, const CATUuid& iFallback);

};

#endif
