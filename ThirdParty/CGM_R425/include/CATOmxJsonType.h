//===================================================================
// COPYRIGHT Dassault Systemes 2017/06/22
//===================================================================
// CATOmxJsonType.cpp
// Header definition of class CATOmxJsonType
//===================================================================
//
// Usage notes:
//  This enum defines the supported json values.
//
//===================================================================
//  2017/06/22 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATOmxJsonType_H
#define CATOmxJsonType_H

#include "CATOMY.h"

namespace CATOmxJsonType
{
  enum Type
  {
    Null,         // empty value
    Boolean,      // bool
    Double,       // double
    Integer,      // int
    Long,         // CATLONG64
    String,       // CATUnicodeString
    Array,        // CATOmxJsonArray
    Object        // CATOmxJsonObject
  };

  /*
  * Returns the string format of the given CATOmxJsonType::Type
  */
  ExportedByCATOMY const char * ToString(CATOmxJsonType::Type iType);
}

#endif