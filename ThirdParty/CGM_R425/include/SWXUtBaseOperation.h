#ifndef SWXUtBaseOperation_H
#define SWXUtBaseOperation_H

#include "CATCommand.h"
#include "SWXUtMacForOverride.h" // many derived operations use override
#include "SWXUtBasePacket.h"
#include "SWXUtMap.h"
#include "SWXUtOperationEventManager.h"

class CATIPLMProducts_var;
class CATListValCATICkeParm_var;
class SWXIAsSaveBodiesInstances_var;
class SWXUtBaseOperationContext;
class SWXUtOperation;
class SWXUtOperationContext;
class SWXUtPacket;
class SWXUtParameterNameSet;

// =======================================================================================================
// Do not modify this interface without review by John Franks or Dan Dignam. This is an interface to be
// used by products outside SolidWorks control and must be modified only with review.
// =======================================================================================================

class ExportedBySWXUtBasePacket SWXUtBaseOperation : public CATCommand
{
	CATDeclareClass;
public:
	SWXUtBaseOperation();
	virtual ~SWXUtBaseOperation();
	virtual SWXUtOperation * GetSWXUtOperation() = 0;
	virtual void InitializeWithContext(SWXUtOperationContext* iContext, SWXUtPacket* iPacket = NULL) = 0;

	virtual void InitializeExclusiveCommand(SWXUtPacket *ipPacket) = 0;

	// Load data into a packet
	virtual HRESULT LoadPacket(SWXUtPacket *iPacket) = 0;

	// Notifications passed through from the UI.
	// Apply will always be told about all changes, back to the last Apply, and including
	// changes that have already been previewed.
	virtual void ApplyChanges(SWXUtPacket* iPacket, const SWXUtParameterNameSet &iChangeList) = 0;
	virtual void PreviewChanges(SWXUtPacket* iPacket, const SWXUtParameterNameSet &iChangeList) = 0;
	virtual void Commit(SWXUtPacket* iPacket, bool iRepeating = false) = 0;

	// Special commit for non-repeating end of an exclusive command.
	virtual void ExclusiveCommit() = 0;
	virtual void Cancel() = 0;

	template <class T, class V> void SubscribeToNotification(T *iReceiver, V* iNotification)
	{
		SWXUtOperationEventManager::Subscribe(iReceiver, iNotification);
	};

	virtual SWXUtOperationContext* GetContext() = 0;
};

#endif
