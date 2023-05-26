#ifndef CATMMCPROPERTYTYPE_H
#define CATMMCPROPERTYTYPE_H

#include "CATMMediaCore.h"

#include "CATUnicodeString.h"

enum CATMMCPropertyType {bytePtrType, stringType,booleanType, intType,uintType,floatType,doubleType,floatListType, baseUnknownPtrType, undefinedType};

class ExportedByCATMMediaCore CATMMCPropertyTypeConv
{
public:
  static CATUnicodeString     GetAsUnicode(CATMMCPropertyType iPropertyType);
  static CATMMCPropertyType   GetEnum     (const CATUnicodeString& iPropertyType);
};

#endif
