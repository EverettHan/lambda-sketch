// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATPLMTLogEntriesBuilder.h
// Define the CATPLMTLogEntriesBuilder interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATPLMTLogEntriesBuilder_H
#define CATPLMTLogEntriesBuilder_H

#include "CATPLMServicesItf.h"
#include "CATListOfCATUnicodeString.h"
#include "CATPLMTEvent.h"

class CATTime;
class CATPLMID;
class CATListPtrCATPLMTLogEntry;
class CATPLMHistoryRecordLight;

class ExportedByCATPLMServicesItf CATPLMTLogEntriesBuilder
{
public:
	CATPLMTLogEntriesBuilder(CATListPtrCATPLMTLogEntry *iLogEntries);
	~CATPLMTLogEntriesBuilder();

	HRESULT Parse(    
		const CATPLMID &iActionID                      , // ActionID
		const CATUnicodeString &iUniqueId              , // CompCES
		const CATPLMID &iCompPLMID                     , // CompPLMID
		const CATPLMTEvent::CATPLMTEventType iOperation, // Operation
		const int iCompCUS                             , // CompCUS
		const CATTime &iModificationDate               , // ModificationDate
		const CATUnicodeString &iUser                  , // User
		const CATUnicodeString &iRole                  , // Role
		const CATUnicodeString &iProject               , // Project
		const CATUnicodeString &iHistoryComment        , // HistoryComment
		const CATPLMID &iCompOwner                     , // CompOwner
		const CATPLMID &iCompInstanceOf                , // CompInstanceOf
		const CATListOfCATUnicodeString &iOperationData, // OperationData
		const CATUnicodeString &iUserFactID            , // UserFactID
		const CATUnicodeString &iUserFactName          , // UserFactName
		const CATUnicodeString &iEventID               , // EventID
		const CATPLMID &iDerivedFrom                   , // DerivedFromPLMID
		const CATUnicodeString &iUserData                // UserData
		);
	HRESULT Parse(CATPLMHistoryRecordLight *iRecordLight);

private:
	CATListPtrCATPLMTLogEntry *log;
	CATListOfCATUnicodeString  userFactIDs;
	int offset;
};
#endif
