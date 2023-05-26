// COPYRIGHT Dassault Systemes 2005
#ifndef CATIListViewRecordReplayModel_H
#define CATIListViewRecordReplayModel_H

#include <CATViewItf.h>
#include <CATUnicodeString.h>

extern ExportedByCATViewItf IID IID_CATIListViewRecordReplayModel;

/**
 * CATIListViewRecordReplayModel. Interface to be implemented by Models to support Record/Replay of test cases.
 **/
class ExportedByCATViewItf CATIListViewRecordReplayModel: public CATBaseUnknown
{
   CATDeclareInterface;
public:

   /**
    *
    *
    * This method returns the string which is stored during the Record.
    * This string is later used to retrieve the same object and column during Replay.
    **/
    virtual CATUnicodeString GetRecordId( CATBaseUnknown_var iRowObject, CATString iColumnName) = 0;

    /**
    * iReplayId is the ID stored during Record.
    * This string identifies which object and which column that the model should return.
    **/
    virtual void GetReplayObject( const CATUnicodeString &iReplayId,
                                        CATBaseUnknown_var &oRowObject,
                                        CATString &oColumnName ) = 0;
};

CATDeclareHandler( CATIListViewRecordReplayModel, CATBaseUnknown );

#endif
