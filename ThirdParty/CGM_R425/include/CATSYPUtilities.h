#ifndef CATSYPUtilities_H
#define CATSYPUtilities_H

#include <IntroInfra.h>
#include <CATListOfCATUnicodeString.h>
#include <IUnknown.h> // included for HRESULT definition
#include <CATSYPArray.h>

class CATUnicodeString;

extern "C" ExportedByIntroInfra 
  void CATSYPChangeDecimalPointToLocal(CATUnicodeString& i_string);

extern "C" ExportedByIntroInfra 
  void CATSYPChangeLocalPointToDecimal(CATUnicodeString& i_string);

extern "C" ExportedByIntroInfra
  HRESULT CATGetMembers( const CATUnicodeString& iString, CATListOfCATUnicodeString &oMembers, const CATUnicodeString& iSeparator);

extern "C" ExportedByIntroInfra
  void CATSYPPutMembersInArray(const CATUnicodeString& iString,
  CATSYPDynArray<CATUnicodeString>&oMembers,
  const CATUnicodeString& iSeparator);

extern "C" ExportedByIntroInfra
int ConvertSypStyleVersionToInt(const CATUnicodeString& i_version);
#endif
