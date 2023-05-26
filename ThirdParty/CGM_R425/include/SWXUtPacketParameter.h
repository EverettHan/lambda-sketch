//===================================================================
// COPYRIGHT Dassault 2010
//===================================================================
// SWXUtPacketParameter.h
//===================================================================

#ifndef SWXUtPacketParameter_H
#define SWXUtPacketParameter_H

#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"
#include "SWXUtAssert.h"
#include "SWXUtBasePacket.h"
#include "SWXUtMacForOverride.h"
#include "SWXUtMap.h"
#include "SWXUtPacket.h"

class CATICkeParm;
class CATIDOMDocument_var;
class CATIDOMElement_var;
class CATMathAxis;
class CATMathPoint;
class CATMathTransformation;
class CATUnicodeString;
class SWXTestContext;
class SWXUtParamName;

//-----------------------------------------------------------------------
class ExportedBySWXUtBasePacket SWXUtPacketParameter : public CATBaseUnknown
{
	CATDeclareClass;
public:
	SWXUtPacketParameter(const CATUnicodeString& iName, const CATUnicodeString& iTypeString,  
		const CATUnicodeString& iRestriction, bool iList, 
		SWXUtPacket* iPacket, SWXUtPacketParameter* iParent);

	virtual SWXUtPacketParameter* Clone( const CATUnicodeString& iNamePrefix, SWXUtPacketParameter* iParent);

	virtual ~SWXUtPacketParameter();

	virtual SWXUtPacketParameter* FindParameter(const CATUnicodeString& iName);

	virtual bool IsParameterEnabled(const CATUnicodeString& iName, const CATUnicodeString& iParentValue, bool& oFoundCases);

	// Fails if it's a duplicate.
	void AddChildParameter(SWXUtPacketParameter* iChild);

	virtual HRESULT TrySetValue(const CATUnicodeString& iNewValue);

	const CATListOfCATUnicodeString GetRestrictions();
	const CATUnicodeString GetRestriction(int index = 0); // zero based index
	const CATUnicodeString& GetTypeString() { return mTypeString; }

	const bool GetListFlag() { return mListFlag; }

	void SetCaseNames(CATListOfCATUnicodeString& iCaseNames);
	const CATListOfCATUnicodeString& GetCaseNames() { return mCaseNames; }

	virtual void SetTimestamp(int iStamp);
	int GetTimestamp() const;

	CATListOfCATUnicodeString& GetCaseList() { return mCaseList; }
	void SetCaseList(const CATListOfCATUnicodeString& iCaseList) { mCaseList.RemoveAll(); mCaseList = iCaseList;}
	void AddCaseToList(const CATUnicodeString& iCaseName);
	bool IsInCaseList(const CATUnicodeString& iCaseName);

    SWXUtPacketParameter *GetParent() const {return mParent;}
	virtual SWXUtParameterMap& GetChildren();
	CATUnicodeString GetName() const;

	// Utilities for setting and getting values.
	virtual HRESULT SetValue(double iValue);
	virtual HRESULT GetValue(double &oValue);
	virtual HRESULT SetValue(int iValue);
	virtual HRESULT GetValue(int &oValue);
	virtual HRESULT SetValue(bool iValue);
	virtual HRESULT GetValue(bool &oValue);
	virtual HRESULT SetValue(const CATMathPoint& iValue);
	virtual HRESULT GetValue(CATMathPoint& oValue);
	virtual HRESULT SetValue(const CATMathVector& iValue);
	virtual HRESULT GetValue(CATMathVector& oValue);
	virtual HRESULT SetValue(const CATMathPoint2D& iValue);
	virtual HRESULT GetValue(CATMathPoint2D& oValue);
	virtual HRESULT SetValue(const CATMathPlane& iValue);
	virtual HRESULT GetValue(CATMathPlane& oValue);
	virtual HRESULT SetValue(const CATMathAxis& iValue);
	virtual HRESULT GetValue(CATMathAxis& oValue);
	virtual HRESULT SetValue(const CATMathTransformation& iValue);
	virtual HRESULT GetValue(CATMathTransformation& oValue);
	virtual HRESULT SetValue(const CATUnicodeString &iValue);
	virtual HRESULT GetValue(CATUnicodeString &oValue);
	virtual HRESULT SetValue(const CATBaseUnknown_var &iValue);
	virtual HRESULT GetValue(const SWXUtHandlerOut &oValue);
	virtual HRESULT SetValue(const CATListValCATBaseUnknown_var &iValue);
	virtual HRESULT GetValue(CATListValCATBaseUnknown_var &oValue);

	virtual HRESULT GetStoredValue( CATUnicodeString& oValue ) { return E_NOTIMPL; }
	virtual HRESULT SetStoredValue( const CATUnicodeString& iValue ) { return E_NOTIMPL; }

	virtual HRESULT GetValueInUnit(const CATUnicodeString &iUnit, CATUnicodeString& oValue);
	virtual HRESULT SetDisplayUnit(const CATUnicodeString& iUnit);
	virtual HRESULT GetDisplayUnit(CATUnicodeString& oUnit);
	virtual HRESULT SetEquationData(const CATUnicodeString& iCATStyle_formula, 
		const CATListValCATBaseUnknown_var& iCATStyle_paramlist);

	virtual HRESULT GetSerializedValue(CATUnicodeString &oValue);

	virtual HRESULT LoadParameter(CATICkeParm* iParam);
	virtual HRESULT ApplyParameter(CATICkeParm* iParam);
	virtual HRESULT AssociateParameter(CATICkeParm* iParam) { return E_FAIL; }
	virtual CATICkeParm* AskAssociatedParameter() { return NULL; };
	virtual CATICkeParm* AskDisplayParameter() { return NULL; };
	virtual HRESULT DissociateParameter() { return E_FAIL; }
	
	// sets and orderedSets only
	virtual void AddSetChangeMonitor(const void* iMonitorKey) { return; }
	virtual bool GetNextSetChange(void* iMonitorKey, bool& oInsert, int& oKey)  { return false; }
	virtual void RemoveSetChangeMonitor(void* iMonitorKey) { return; }

	HRESULT WritePrototypesToDOM(CATIDOMDocument_var iDocument, 
		CATIDOMElement_var iParentNode, 
		CATUnicodeString iPrefix) const;
	HRESULT WriteOverridesToDOM(CATIDOMDocument_var iDocument, 
		CATIDOMElement_var iOverridesNode) const;

	// called by packet
	virtual void CheckChangedValue();

	virtual void GetAllFullSubpackets(SWXUtVector<SWXUtPacket*>& ioSubpackets);

	void AddNonHierarchicalCase(CATUnicodeString iPath, CATListOfCATUnicodeString iNames);

	// stuff for equations
	virtual bool IsEquationLHS() { return false; }
	virtual CATUnicodeString GetFormulaRHS() { return CATUnicodeString(""); }
	virtual void ShowEquation(bool iShow) { mShowFormula=iShow; }
	virtual bool GetEquationVisibility() { return mShowFormula;}
	virtual int  GetParseOrUnitError() { return 0;}
	virtual void SetParseOrUnitError(int ) { }
	virtual bool CannotHaveEquation() { return true;}

	virtual void GetAllKeysOfSet(const SWXUtSet<int>*& oKeys) { oKeys = NULL; }; 

	virtual HRESULT CopyValueTo(SWXUtPacketParameter* iTo);
	virtual HRESULT CopyRestrictionsTo(SWXUtPacketParameter* iTo);

	SWXUtPacket* GetOwningPacket() { return mOwningPacket; }//IZO for snapping arcslots
	virtual SWXUtPacket *GetSubpacket() { return NULL; }

protected:
	virtual bool HasSubscription() { return false;}
	virtual void RemoveSubscription() { }
	virtual void EnsureSubscription(CATICkeParm* iParam) { }
	virtual void OnChangeValueEvent(CATCallbackEvent iEvent,
		void* iFrom,
		CATNotification* iNotification,
		CATSubscriberData iInfo,
		CATCallback iCallback) { }

protected:
	// constructor for Clone()
	SWXUtPacketParameter(const SWXUtPacketParameter& iOriginal, const CATUnicodeString& iNamePrefix, SWXUtPacketParameter* iParent);
	int RemoveDirectChild(const CATUnicodeString& iName);
	int RenameChild(const CATUnicodeString& iOldName, const CATUnicodeString& iNewName);

	virtual void SetName(const CATUnicodeString& iNewName);

	int mTimestamp;
	CATUnicodeString mTypeString;

	CATUnicodeString mName;
	CATListOfCATUnicodeString mCaseNames; // the values of the parent for which this is enabled.
	SWXUtPacket* mOwningPacket;

	//MAX added this for equation callback management
	bool mHasSubscription;
	bool mShowFormula;
	CATUnicodeString mDisplayUnit;
	CATUnicodeString mCATIAStyle_formula;
	CATListValCATBaseUnknown_var mCATIAStyle_listofparameters;

	bool IsNonHierarchicallyEnabled(const CATUnicodeString& iPath, bool& oFoundCases);

private:
	SWXUtParameterMap mChildren;
	SWXUtPacketParameter* mParent;
	CATListOfCATUnicodeString mRestrictions;


	bool mListFlag;

	// This is used for timestamp purposes to ensure that changes are seen by 
	SWXUtPacketParameter* mPrototype; 

	// case list for options, or anything else with restricted case values. 
	// has to be stored explicitly since some child cases may be empty. 
	CATListOfCATUnicodeString mCaseList; // this is the case list for values of this parameter

	SWXUtMap<CATUnicodeString, CATListOfCATUnicodeString> mNonHierarchicalCases;

	void SetRestrictions(const CATUnicodeString& iRestrictions);

	//Fixing iOs error - enums cannot be fwd declared. 
	//Commenting this as this seems not be required anymore..
	//friend SWXTestResult SWXTestUtParameterCase(SWXTestContext& iTestContext);
};

#endif
