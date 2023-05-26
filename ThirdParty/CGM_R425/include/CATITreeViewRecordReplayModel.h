// COPYRIGHT Dassault Systemes 2005
#ifndef CATITreeViewRecordReplayModel_H
#define CATITreeViewRecordReplayModel_H

#include <CATViewItf.h>
#include <CATUnicodeString.h>

extern ExportedByCATViewItf IID IID_CATITreeViewRecordReplayModel;

/**
 * CATITreeViewRecordReplayModel. Interface to be implemented by Models to support Record/Replay of test cases.
 **/
class ExportedByCATViewItf CATITreeViewRecordReplayModel: public CATBaseUnknown
{
   CATDeclareInterface;
public:

      /**
      * iRecordObject is an strict contract object known to the View and the Model
      * This object is only used during record/replay.
      *
      * This method returns the string which is stored during the Record.
      * This string is later used to retrieve the same object during Replay.
      **/
      virtual CATUnicodeString GetRecordId( CATBaseUnknown_var iRecordObject ) = 0;

      /**
      * iReplayId is the ID stored during Record. This string identifies which object
      * that the model should return. The returned object must be the same contract
      * object used by the View and Model during record/replay.
      **/
      virtual CATBaseUnknown_var GetReplayObject( const CATUnicodeString &iReplayId ) = 0;

};

CATDeclareHandler( CATITreeViewRecordReplayModel, CATBaseUnknown );

#endif
