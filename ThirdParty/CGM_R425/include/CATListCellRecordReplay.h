#ifndef _CATListCellRecordReplay_H
#define _CATListCellRecordReplay_H

#include <CATView.h>
#include <CATBaseUnknown.h>
#include <CATString.h>


/**
 * CATListView helper class for passing around row object and column id. This is necessary for cell selection.
 **/
class ExportedByCATView CATListCellRecordReplay : public CATBaseUnknown
{
   friend class CATViewCellEditControllerTst;
   CATDeclareClass;
public:

   CATListCellRecordReplay(CATBaseUnknown_var &iRowObject, const CATString &iColumn  );

   virtual ~CATListCellRecordReplay( void );

   CATString _column;
   CATBaseUnknown_var _rowObj;
};

#endif
