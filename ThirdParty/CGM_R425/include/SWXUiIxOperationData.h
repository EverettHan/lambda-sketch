#ifndef SWXUiIxOperationData_H
#define SWXUiIxOperationData_H
// COPYRIGHT Dassault Systemes 2010
// Creation: HFS (JMF in the real world...)

#include "SWXUtBasePacket.h"
#include "SWXUtMacForOverride.h"

#include "CATListOfCATUnicodeString.h"
#include "SWXCATUnicodeStringComparer.h"
#include "SWXUtMap.h"
#include "SWXUtPacket.h"

class SWXIUiComponent_var;
class SWXUiInteractionContext;
class SWXUiIxContext;
class SWXUtBaseOperation;
class SWXUtPacket;

typedef SWXUtMap<CATUnicodeString, CATBaseUnknown*, SWXCATUnicodeStringComparer> SWXUiIxOperationData_PreviewMap;

class ExportedBySWXUtBasePacket SWXUiIxOperationData
{
public:
	SWXUiIxOperationData() : mPacket(NULL), mOperation(NULL), mApplyTimestamp(-1) {}
	~SWXUiIxOperationData() { mPacket = NULL; mOperation = NULL; }

	bool IsPreviewed(CATUnicodeString iPath, SWXIUiComponent_var iSourceComp);
	void AddToPreviews(CATUnicodeString iPath, SWXIUiComponent_var iSourceComp);
	CATListOfCATUnicodeString GetOutstandingPreviews(SWXIUiComponent_var iSourceComp);
	void ClearPreviews(const CATUnicodeString& iName);
	CATListOfCATUnicodeString GetAllOutstandingPreviews();

	SWXUtPacket* mPacket;
	SWXUtBaseOperation* mOperation;
	SWXUtPacketTimestamp_t mApplyTimestamp;
	
private:
	SWXUiIxOperationData_PreviewMap mPreviewedChanges;
};


#endif
