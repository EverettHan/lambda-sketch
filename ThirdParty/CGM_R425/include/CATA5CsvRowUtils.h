//===================================================================
// COPYRIGHT Dassault Systemes 2018/05/28
//===================================================================
// CATA5CsvRowUtils.cpp
// Header definition of class CATA5CsvRowUtils
//===================================================================
//
// Usage notes:
//
// Utils class for CsvRow.
//
//===================================================================
//  2018/05/28 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATA5CsvRowUtils_H
#define CATA5CsvRowUtils_H

#include "CATA5Parser.h"

class ExportedByCATA5Parser CATA5CsvRowUtils
{
public:
  /*
  * Returns true if the given row is identified as a root during an expand query.
  */
  static bool IsRowRootFromAnExpandQuery(CATA5::CsvRow& iRow);
};

#endif