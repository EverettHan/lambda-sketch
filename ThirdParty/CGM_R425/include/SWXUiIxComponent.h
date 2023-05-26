#ifndef SWXUiIxComponent_H
#define SWXUiIxComponent_H

#include "SWXUtBasePacket.h"
#include "SWXUtMacForOverride.h"

#include "CATCommand.h"
#include "CATIDOMElement.h"
#include "CATListOfCATUnicodeString.h"
#include "CATMathTransformation.h"
#include "CATString.h"
#include "CATUnicodeString.h"
#include "SWXBaseUiEnums.h"
#include "SWXIUiComponent.h"
#include "SWXIUiIxVisuEventListener.h"
#include "SWXIUtPacketEngineHarness.h"
#include "SWXUiBaseEventArgs.h"
#include "SWXUiIxComponentBinding.h"
#include "SWXUtMap.h"
#include "SWXUtParameterReason.h"
#include "SWXUtSet.h"
#include "SWXUtVector.h"

class CATAcquisitionAgent;
class CATKeybdEvent;
class CATMathAxis;
class CATMathPlane;
class CATMathPoint;
class CATMathPoint2D;
class CATMathPoint2Df;
class CATMathTransformation;
class CATMathVector;
class CATNotification;
class CATSO;
class CATVidFraWindow;
class CATVidLayStack;
class CATVidWidget;
class SWXIUiComponent;
class SWXIUiComponent_var;
class SWXIUtSelectedObject_var;
class SWXUiBaseEvent;
class SWXUiIxInteraction;
class SWXUiSYPBase;
class SWXUtHandlerOut;
class SWXUtPacket;
class SWXUtPacketEngine;
class SWXUtPacketParameter;
class SWXUtPacketSimpleParameter;

class ExportedBySWXUtBasePacket SWXUiIxComponent : public CATCommand
{
	CATDeclareClass;

public:
	SWXUiIxComponent();
	virtual ~SWXUiIxComponent();

	// Utility functions:
	SWXUiIxInteraction* GetInteraction();

	virtual void GetUsageDetails(SWXUiIxComponentUsageDetails& oBindings);
	virtual void GetBindingDetails(SWXUtVector<SWXUiIxComponentBinding>& oBindings);
	bool IsBound(const CATUnicodeString& iName) const;

	// HFS avoid using this Binding() call - it errors for private bindings. Use GetPacketValue(), BindingAsResourceKey, etc.
	virtual CATUnicodeString Binding(const CATUnicodeString& iName, int index1 = -1, int index2 = -1) const;

	virtual CATUnicodeString BindingAsResourceKey(const CATUnicodeString& iName) const;

	// SWXIUiComponent interface (not directly implemented by this class - see subclasses)
	void InitializePrivateParams(SWXUtPrivateParamMap* iPrivateParams); // call this first before InitializeComponent calls. 
	virtual void InitializeComponent2(const CATListOfCATUnicodeString& iBindings, SWXUtPacket* iPacket, SWXIUiComponent* iParent, SWXIUtPacketEngineHarness* iHarness);
	virtual void InitializeComponent(const CATListOfCATUnicodeString& iBindings, SWXUtPacket* iPacket, SWXIUiComponent* iParent, SWXUiIxInteraction* iInteraction);
	virtual void ConstructComponent(SWXIUiComponent* iParent);
	inline virtual bool IsConstructed() { return mConstructed; }
	//N13: no op for most components -> only do this if you need to do a particular operation after all children'd CID have been built	
	virtual void FinalizeCIDBuild() { }

	// Add a widget to the parent component's container or dialog. 
	virtual void AddToContainer(SWXIUiComponent_var iSource, CATVidWidget * iWidget, CATUnicodeString iIndex = "");
	virtual void RemoveFromContainer(SWXIUiComponent_var iSource, CATVidWidget * iWidget);
	virtual CATVidWidget* GetEmbeddedWidget(){return NULL;}

	virtual void AddDialogToContainer(CATVidFraWindow * iDialog);
	virtual void RemoveDialogFromContainer(CATVidFraWindow * iDialog);


	// If the component supports selection, has to supply these methods.
	virtual CATAcquisitionAgent * GetAcquisitionAgent() { return NULL; }
	virtual bool IsSelectionState() { return false; } 
	virtual bool AutoAdvanceSelection() { return false; }

	// Update component after a change to other components or the packet.
	virtual void OnParameterChange(SWXUtParameterReason iReason);
	virtual void ApplyParameterChange(bool iPreview);//DEPRECATED

	virtual void UpdateLayout();

	// Is this component part of the current interaction, or does some option mean it's not relevant/visible?
	// DO NOT OVERRIDE IsEnabled() : Its implementation is depended on by SWXUiIxInteraction
	virtual bool IsEnabled(); 

	virtual void SetDomNode(const CATIDOMElement_var &iDomNode);
	virtual CATIDOMElement_var GetDomNode();

	virtual void BuildComponents(const CATIDOMElement_var& iNode);

	virtual void SetRelativePath(const CATUnicodeString iPath);
	virtual CATUnicodeString  GetRelativePath();

	virtual void RunCommand() { return; };

	virtual bool UserFocusOffered();
	virtual void ChildChangedFocus(SWXIUiComponent* iComponent, bool iFocusIn);

	virtual SWXIUiComponent* GetParent() { return mParent; }
	SWXUtPacket* GetPacketPrivileged() { return mPacket; };

	virtual void PreUnhook();
	virtual void Unhook();
	virtual void SetOwningIxFile(const CATUnicodeString& iOwningIxFile) { mOwningIxFile = iOwningIxFile; }
	virtual CATUnicodeString GetOwningIxFile()const{return mOwningIxFile;}

	virtual bool IsContainerComponent(){return false;}
	virtual unsigned int GetAllowedStyle()const{return 0;}

	void NotifyValueChanged(enum SWXUiNotifyMode iChange);

	virtual bool AcceptReturnKey() { return true; }

	virtual void HandleIdleEvent(){}

	virtual void SetVisibleFlag(const bool & iVisibleFlag) { mVisible=iVisibleFlag; }
	virtual bool GetVisibleFlag() {return mVisible;}  // true by default

	virtual void BubbleEvent(SWXUiBaseEvent* iEvt, SWXUiBaseEventArgs& iEvtArgs);
	virtual void TunnelEvent(SWXUiBaseEvent* iEvt, SWXUiBaseEventArgs& iEvtArgs, bool& obConsumed);

	virtual CATUnicodeString GetSelectionFieldCursor() {return "";}

	// no op by default, only for virtual scroll & trees
	virtual CATVidWidget * GetMasterWidget() { return NULL; }

	// SWXIUiIxVisuEventListener
	virtual SWXIUiIxVisuEventListener::EventAction_e KeyboardAction(const CATKeybdEvent * iEvent);
	virtual SWXIUiIxVisuEventListener::EventAction_e DeviceAction(const CATNotification * iNotification);
	virtual bool AutoRegister();
	virtual bool ShouldProcessKeyboardEvent(const CATKeybdEvent *ipEvent) const;
	virtual bool IsConsumedByListener(const CATKeybdEvent * iEvent)const;

	virtual void AfterDocumentUndoRedo();

	virtual void SetNameQualifier(const CATUnicodeString& iQualifier) {};

	virtual bool ValueChangeAffectsUndo() const { return true; }

	HRESULT GetIxContextTransform(CATMathTransformation &oValue);
	virtual HRESULT IsReadyForCommit(bool & obIsComponentReady, bool & obStopChecking);

	bool HasPrivateParams() const { return mPrivateParameters != NULL; }

protected:
	SWXUtPacketEngine* GetEngine() { return mHarness == NULL_var ? NULL : mHarness->GetEngine(); }
	virtual void BuildChildren(const CATUnicodeString& iOwningIxFile);

	virtual SWXIUiComponent_var BuildChild(
		const CATIDOMElement_var& iChild, 
		const CATUnicodeString& iRelativePath,
		const CATUnicodeString& iOwningIxFile);

	SWXIUiComponent* mParent;
	SWXUiIxInteraction* mInteraction;

	CATUnicodeString mRelativePath;
	CATUnicodeString mOwningIxFile;

	CATIDOMElement_var	mDomNode;
protected:
	SWXIUtPacketEngineHarness* mHarness;

private:	// Don't use mBindings directly any more - use the methood Binding(<name>) instead.
	class BindingStruct { public:
	BindingStruct(CATUnicodeString iName) : mName(iName), mAlwaysEnabled(false) {} 
	CATUnicodeString mName; bool mAlwaysEnabled; };
	SWXUtVector<BindingStruct> mBindings;
	CATUnicodeString BindingOrPrivateParam(SWXUtPacketSimpleParameter*& oParam, const CATUnicodeString& iName, int index1 = -1, int index2 = -1);
	friend class SWXTestParamComponent; // for testing BindingOrPrivateParam etc.

protected:
	// Packet access
	HRESULT SetPacketValue(const CATUnicodeString &iName, double iValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT GetPacketValue(const CATUnicodeString &iName, double &oValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT SetPacketValue(const CATUnicodeString &iName, int iValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT GetPacketValue(const CATUnicodeString &iName, int &oValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT SetPacketValue(const CATUnicodeString &iName, bool iValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT GetPacketValue(const CATUnicodeString &iName, bool &oValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT SetPacketValue(const CATUnicodeString &iName, const CATMathVector &iValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT GetPacketValue(const CATUnicodeString &iName, CATMathVector &oValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT SetPacketValue(const CATUnicodeString &iName, const CATMathPoint &iValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT GetPacketValue(const CATUnicodeString &iName, CATMathPoint &oValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT SetPacketValue(const CATUnicodeString &iName, const CATMathPoint2D &iValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT GetPacketValue(const CATUnicodeString &iName, CATMathPoint2D &oValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT SetPacketValue(const CATUnicodeString &iName, const CATMathPlane &iValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT GetPacketValue(const CATUnicodeString &iName, CATMathPlane &oValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT SetPacketValue(const CATUnicodeString &iName, const CATMathTransformation &iValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT GetPacketValue(const CATUnicodeString &iName, CATMathTransformation &oValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT SetPacketValue(const CATUnicodeString &iName, const CATMathAxis &iValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT GetPacketValue(const CATUnicodeString &iName, CATMathAxis &oValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT SetPacketValue(const CATUnicodeString &iName, const CATUnicodeString &iValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT GetPacketValue(const CATUnicodeString &iName, CATUnicodeString &oValue, int iIndex1 = -1, int iIndex2 = -1);

	HRESULT GetPacketValue(const CATUnicodeString &iName, const SWXUtHandlerOut& oValue, int iIndex1 = -1, int iIndex2 = -1);

	// for possible equation things
	HRESULT TrySetPacketValue(const CATUnicodeString &iName, const CATUnicodeString &iValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT SetPacketSelValue(const CATUnicodeString &iName, const SWXIUtSelectedObject_var& iValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT GetPacketSelValue(const CATUnicodeString &iName, const SWXUtHandlerOut& oValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT SetPacketSelValue(const CATUnicodeString &iName, const CATListValCATBaseUnknown_var& iValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT GetPacketSelValue(const CATUnicodeString &iName, CATListValCATBaseUnknown_var& oValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT GetPacketParameterRestrictions(const CATUnicodeString& iName, CATListOfCATUnicodeString& oRestrictions);
	HRESULT GetPacketParameterRestriction(const CATUnicodeString& iName, CATUnicodeString& oRestriction, int iIndex = 0);
	HRESULT GetPacketParameterTimestamp(const CATUnicodeString& iName, int& oTimestamp, int iIndex = -1, int iIndex2 = -1);
	HRESULT GetPacketOrderedSetSize(const CATUnicodeString& iName, int& oSize);
	HRESULT SetPacketOrderedSetSize(const CATUnicodeString& iName, int iSize);
	HRESULT GetPacketCaseListForParameter(const CATUnicodeString& iName, CATListOfCATUnicodeString& oCaseList);
	HRESULT GetPacketParameterTypeString(const CATUnicodeString& iName, CATUnicodeString& oType);
	HRESULT GetPacketEvaluatedValue(const CATUnicodeString &iName, CATUnicodeString &oValue, int iIndex1 = -1, int iIndex2 = -1);
	HRESULT GetPacketEquationOrValue(const CATUnicodeString &iName, CATUnicodeString &oValue, bool iEq=true, int iIndex1 = -1, int iIndex2 = -1);

	HRESULT GetParameterHasEquation(const CATUnicodeString& iName, bool &oYesNo,int iIndex1=-1, int iIndex2=-1);
	HRESULT SetParameterEquationVisibility(const CATUnicodeString& iName, bool iYesNo,int iIndex1=-1, int iIndex2=-1);
	HRESULT GetParameterEquationVisibility(const CATUnicodeString& iName, bool& oYesNo,int iIndex1=-1, int iIndex2=-1);
	HRESULT GetParseOrUnitError(const CATUnicodeString& iName, int& oErrLvl,int iIndex1=-1, int iIndex2=-1);
	HRESULT SetParseOrUnitError(const CATUnicodeString& iName, int iErrLvl,int iIndex1=-1, int iIndex2=-1);
	HRESULT CannotHaveEquation(const CATUnicodeString& iName, bool& oNoEq,int iIndex1=-1, int iIndex2=-1);
	CATUnicodeString GetFullParameterName(const CATUnicodeString& iName,int iIndex1=-1, int iIndex2=-1);
	HRESULT PacketRemoveElement(CATUnicodeString iOSPath, int iIndex, int iKey1 = -1);
	HRESULT PacketInsertElement(CATUnicodeString iOSPath, int iIndex, int iKey1 = -1);
	HRESULT SetPacketEquationData(const CATUnicodeString& iName,
		const CATUnicodeString& iCATStyle_formula,
		const CATListValCATBaseUnknown_var& iCATStyle_paramlist,
		int iIndex1=-1, int iIndex2=-1);
	SWXUtPacketParameter* GetPacketParameter(const CATUnicodeString& iName);


	void SetPacketPrivileged(SWXUtPacket* iPacket) { mPacket = iPacket; };

	CATUnicodeString BuildMessage(const CATUnicodeString & iKey, CATUnicodeString * iMsgParameters = NULL, int iParamNb = 0);
	CATUnicodeString BuildMessage(const CATUnicodeString & iContext, const CATUnicodeString & iKey);
	CATString BuildResource(const CATString & iKey);

	const CATMathTransformation& GetActiveComponentToProductTransform() const;
	const CATMathTransformation& GetProductToActiveComponentTransform() const;


protected:
	// The plan is to make this private. Please don't use it directly, please use the GetPacketValue etc. methods instead.
	SWXUtPacket* mPacket;

	void BuildInclude(const CATUnicodeString& iIxFile, 
		const CATUnicodeString& iUniquePrefix,
		const CATListOfCATUnicodeString& iWatchedParameters);

	void SetConstructed(bool iVal) { mConstructed = iVal;}
	void SetUniqueName(CATCommand* ipWidget);
private:
	void CheckTransform();
	CATListOfCATUnicodeString mBindingNames;

	bool mTransformed;
	CATMathTransformation mTransform;
	CATMathTransformation mInverseTransform;
	int mTransformTS;

	bool mConstructed;
	bool mVisible;
	int mUndoMark;

	SWXUtPrivateParamMap* mPrivateParameters;
	int mUniqueName;

	friend class SWXUiSetComponent;
};

#endif
