#ifndef __CATLnkConstants_H
#define __CATLnkConstants_H

#include "CATUnicodeString.h"
#include "CATVVSUrl.h"
#include "AC0XXLNK.h"

struct CATLnkConstantsStruct
{
  const CATUnicodeString CATLnk;

  const CATUnicodeString LinkTable; //storage containing PLMRelations, LinkHandles and PLMComplementaryData
  const CATUnicodeString PLMRelations; //stream containg duplicate of relations private data, warning, starts with binary '\3' character
  const CATUnicodeString LinkHandles;  //stream containg links, warning, starts with binary '\3' character
  const CATUnicodeString PLMComplementaryData; //stream containg ???, warning, starts with binary '\3' character
  const CATUnicodeString Specs; //stream containg asociation (object,attribute) => link id + "additional infos", warning, starts with binary '\3' character
  const CATUnicodeString Extra; //stream containing MCX features, warning, starts with binary '\3' character

  const CATVVSUrl pCacheDummyUrl; //dummy URL used for CATLnk stored inside PLM attribute ("pCache")

  //PLMCoreStreamStorage extension
  const CATOmxKeyString PLMCoreStreamStorage;
  //PLMCoreStreamStorage.Stream attribute
  const CATOmxKeyString Stream;

  CATLnkConstantsStruct();
};

ExportedByAC0XXLNK const CATLnkConstantsStruct& CATLnkConstants();

#endif
