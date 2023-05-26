#ifndef CATTopCheckCornerJournal_H_
#define CATTopCheckCornerJournal_H_

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "Parallel.h"
#include "CATTopCheckJournal.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATBody.h"
#include "CATListOfCATGeometries.h"
class CATCGMJournal;
class CATCGMJournalList;
class CATGeometry;
class CATTopCorner;


class ExportedByParallel CATTopCheckCornerJournal
{
public:

  CATTopCheckCornerJournal (CATCGMJournalList* iReport, CATTopCorner * CornerOpe,
                      CATBody*           iResult);

  virtual ~CATTopCheckCornerJournal();

  // pour donner les entrees de l'operateur ...
  void AppendAppui(CATBody* input, CATTopCheckJournalType copy_or_not);


  // throw an error on problem detection (throw is conditionned to "CATTopCheckJournal")
  void Check();

void AppendSupport(CATBody* isupport);

protected:
 
  CATLISTP(CATBody)        _AppuisCopy;
  CATLISTP(CATBody)        _AppuisNoCopy;
  CATBody*                 _Output;
  CATCGMJournalList *      _OrigReport;
  CATCGMJournalList *      _Report;
  CATTopCorner         *   _CornOp;
  CATBody *                _Support;
};



#endif
