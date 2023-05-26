#ifndef CATMMCTABLEDUMP_H
#define CATMMCTABLEDUMP_H

#include "CATMMediaCore2.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfInt.h"

/**
  * @ingroup groupPotentialSysInfra
  * @brief Service to dump text in basic table format.\n
  * Current limitations:
  * - centered text in a colmun is not yet supported.
  * - It does not support adding a new column when lines have already been added.
  * - A new line cannot be inserted out of the end of the table.
  */
class ExportedByCATMMediaCore2 CATMMCTableDump
{
public:
  enum align {TDA_Left=0, TDA_Center=1, TDA_Right=2};
  CATMMCTableDump(align ialign = TDA_Left)          ;
  virtual ~CATMMCTableDump()                      {};

  bool  AddColumn(align ialign=TDA_Left);
  bool  RemoveColumn(int iIndex);
  bool  AddToColumn(int iColumnIndex, const CATUnicodeString& iText);
  bool  NextRow();

  CATUnicodeString  Dump()                         const ;

  static int GetNbRows(const CATUnicodeString& iText);

  CATUnicodeString          _columnSeparator;

private:
  CATListOfCATUnicodeString _columns;
  CATListOfInt              _columnsWidths;
  CATListOfInt              _columnsAttributes;

  int GetNbRows() const;
  int GetSizelLastRow(int iColumnIndex);
  static CATUnicodeString CompleteWithSpaces(int from, int total);
  static CATUnicodeString GetAligned(CATUnicodeString text, int total, align ialign=TDA_Left);
};

#endif
