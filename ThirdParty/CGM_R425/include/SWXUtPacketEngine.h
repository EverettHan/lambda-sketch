#ifndef SWXUtPacketEngine_H
#define SWXUtPacketEngine_H

#include "SWXUtBasePacket.h"

#include "CATIDOMElement.h"
#include "CATListOfCATUnicodeString.h"
#include "CATUnicodeString.h"
#include "SWXIUiComponent.h"
#include "SWXIUiIxNotifiable.h"
#include "SWXIUiIxVisuEventListener.h"
#include "SWXIUtPacketEngineHarness.h"
#include "SWXUtMap.h"
#include "SWXUtPacket.h"
#include "SWXUtVector.h"

class SWXUiIxInteraction;
class SWXUiIxOperationData;

class ExportedBySWXUtBasePacket SWXUtPacketEngine : public CATBaseUnknown
{
public:
	SWXUtPacketEngine(SWXIUtPacketEngineHarness_var iHarness);
	~SWXUtPacketEngine();
public:
		// Add a new component to the master list of active components.
	void AddComponent(SWXIUiComponent_var iParentComponent,
		SWXIUiComponent * iComponent,
		const CATListOfCATUnicodeString & iBindings,
		const CATUnicodeString & iId);

	static CATIDOMElement_var OpenIxFile(const CATUnicodeString & iXmlFileName);

	SWXUiIxInteraction* GetInteractionFromEngine();
	SWXIUtPacketEngineHarness* GetHarness() { return mHarness; }

	const CATUnicodeString& GetUIParameterPrefix();

	void GetAllComponents(SWXUtVector<SWXIUiComponent_var> & oComponents);
	void GetChildComponents(SWXIUiComponent_var iComponent, SWXUtVector<SWXIUiComponent_var> & oChildren);

	void NotifyValueChanged(SWXIUiComponent_var iSourceComponent, enum SWXUiNotifyMode iChange);

	// Access to the translated stuff for this interaction. A wrapper around CATMsgCatalog.
	// For individual dialogs - Ix generic stuff uses BuildIxMessage.
	CATUnicodeString BuildMessage(const CATUnicodeString & iIxContext, const CATUnicodeString & iKey, CATUnicodeString * iMsgParameters = NULL, int iParamNb = 0);
	CATString BuildResource(const CATString & iIxContext, const CATString & iKey, CATString * iMsgParameters = NULL, int iParamNb = 0);

	CATString GetName();
	void UnhookEngine();
	SWXUtOperationContext * GetOperationContext() { return mContext; }
	
	bool GetJournalledFlag() { return mJournalled; }
	void SetJournalled(bool iJournalled) { mJournalled = iJournalled; }

	// Whether to call the "exclusive mode" operation methods on commit/load-operation/etc. 
	void SetCallExclusiveCommandMethods(bool iExclusive) { mCallExclusiveInitMethods = iExclusive; }

	void LoadOperation(int iIndex);
	void DoNotifyOperation(SWXIUiComponent_var iSourceComponent, int iPacketIndex, SWXUtParameterReason iReason, SWXUtPacketTimestamp_t& ioTimestamp, bool iApplyPreviewLater = true);
	void DoNotifyComponents(SWXIUiComponent_var iSourceComponent, enum SWXUtParameterReason iReason, int iPacketIndex);
	void SendUpdateToBoundComponents(SWXIUiComponent_var iSourceComponent, SWXUtPacket* iPacket, SWXUtPacketTimestamp_t iTimestamp, SWXUtParameterReason iReason);

	void PopPacket(SWXUtPacket * iPacket);
	void PushPacket(SWXUtPacket * iPacket);
	void RemoveComponent(SWXIUiComponent_var iComponent);
	void ConstructNewComponents();

	void ProcessPeerNotifications();

	SWXUtPacket* GetSpecificPacket(const CATUnicodeString& iPacketName);

private:
	friend class SWXUiIxInteraction; // for now.
	friend class SWXUiIxFreeInteraction; // for now.
	friend class SWXUiCommander; // for now.

	friend void SWXTestActionBar(); // for ODTs

	class ExportedBySWXUtBasePacket ComponentData
	{
	public:
		ComponentData() : mComponentTimestamp(-1) , mComponentEnabled(false) {}
		~ComponentData();
		SWXIUiComponent_var mComponent;
		SWXIUiComponent_var mParentComponent;
		SWXUtPacketTimestamp_t mComponentTimestamp;
		bool mComponentEnabled;
		CATListOfCATUnicodeString mComponentBindings;
		CATUnicodeString mComponentId;
	};

	SWXUtVector<ComponentData*> mRecords;
	SWXUtMap<SWXIUiComponent*, int> mLookup;
	SWXUtVector<SWXUiIxOperationData *> mOps;

	SWXUtVector<SWXIUiIxNotifiable_var> mNotifiableComponents;
	SWXUtVector<SWXIUiIxVisuEventListener_var> mVisuEventListeners;

	SWXIUtPacketEngineHarness_var mHarness;
	SWXUtOperationContext * mContext;

	CATUnicodeString mRandomPacketPrefix;
	
	bool mJournalled;

	SWXUtVector<int> mLoadTimestampsStart;
	SWXUtVector<int> mLoadTimestampsEnd;

	bool mCallExclusiveInitMethods;

	int mConstructedSoFar;

};

#endif
