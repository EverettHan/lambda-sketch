//===================================================================
// COPYRIGHT Dassault 2010
//===================================================================
// SWXUtPacket.h: Packet passed between UI and model for interaction
//===================================================================

#ifndef SWXUtPacket_H
#define SWXUtPacket_H

#include "CATCommand.h"
#include "CATUnicodeString.h"
#include "SWXCATUnicodeStringComparer.h"
#include "SWXIUtKnowledgePacket.h"
#include "SWXIUtSelectedObject.h"
#include "SWXUtBasePacket.h"
#include "SWXUtMap.h"
#include "SWXUtParameterMap.h"
#include "SWXUtSet.h"
#include "SWXUtVector.h"

class CATBaseUnknown_var;
class CATICkeParm;
class CATIDOMElement_var;
class CATIDOMNode;
class CATListValCATBaseUnknown_var;
class CATMathAxis;
class CATMathPlane;
class CATMathPoint;
class CATMathPoint2D;
class CATMathTransformation;
class CATMathVector;
class CATNotification;
class SWXIUtPacketChange;
class SWXUtHandlerOut;
class SWXUtOperationContext;
class SWXUtPacketParameter;
class SWXUtPacketParametersIterator;
class SWXUtParamName;

typedef int SWXUtPacketTimestamp_t;
typedef enum SWXUtPacketEnableState_e { SWXUtPacket_Disabled = 0, SWXUtPacket_Enabled = 1, SWXUtPacket_AlwaysEnabled = 2 } SWXUtPacketEnableState;

//-----------------------------------------------------------------------
// This class is not intended to be subclassed. It provides an abstraction layer.
class ExportedBySWXUtBasePacket SWXUtPacket : public CATCommand
{
	CATDeclareClass;
public:

	SWXUtPacket(const CATUnicodeString& iPacketDefintionFile, bool iJournalled = true, int iTimestamp=0);
	virtual ~SWXUtPacket();

	enum ErrorLevel { kNoError, kParseError, kUnitError, kUnprocessedEqual };

	void SetOwnerOfSubpacket(SWXUtPacket* iOwningPacket, const CATUnicodeString& iPrefix);
	void RemoveOwnerOfSubpacket(SWXUtPacket* iOwningPacket);
	SWXUtPacket* GetOwningSubpacket(SWXUtPacketParameter* iParameter);//IZO snapping for arcslots

	// The most important method: get a parameter by name.
	// The name is the name path in the XML, excluding cases.
	// e.g. "Limits.EndSpec1.BlindDistance" or "Offset".
	SWXUtPacketParameter* GetParameter(const CATUnicodeString& iName);

	// STRONGLY DISCOURAGED - LEGACY and unreliable - use peer notifications between operations instead
	void PublishReferenceChange(const CATUnicodeString& iParameterName);

	/*
	Simple iterators:
	for(name = GetFirstParameterName(iter);
	name.GetLengthInChar() > 0;
	GetNextParameterName(name, iter))

	Note this only works on top level parameters. Not recommended for external use.
	*/
	const CATUnicodeString GetFirstParameterName(SWXUtPacketParametersIterator*& oIter);
	void GetNextParameterName(CATUnicodeString& ioName, SWXUtPacketParametersIterator*& ioIter);

	// for introspectable support.
	const CATUnicodeString GetFirstParameterNameUnder(const CATUnicodeString& iInitialPath, SWXUtPacketParametersIterator*& oIter);

	const CATUnicodeString GetParameterName(const SWXUtPacketParameter* iParameter) const;

	SWXUtPacketParameter* GetFirstParameter(SWXUtPacketParametersIterator*& oIter);
	void GetNextParameter(SWXUtPacketParameter*& ioParameter, SWXUtPacketParametersIterator*& ioIter);

	void GetAllFullSubpackets(SWXUtVector<SWXUtPacket*>& ioSubpackets);

	// Is the parameter in a "case" which is current according to the value(s) of the
	// parameters referenced by the case?
	SWXUtPacketEnableState IsParameterEnabled(const CATUnicodeString& iName);

	// Get all the restriction strings (used for selection filters, limits on values, etc.)
	HRESULT GetParameterRestrictions(const CATUnicodeString& iName, CATListOfCATUnicodeString& oRestrictions);

	// Get the restriction string (used for selection filters, limits on values, etc.)
	HRESULT GetParameterRestriction(const CATUnicodeString& iName, CATUnicodeString& oRestriction, int iIndex = 0);

	// Get the packet timestamp of the last modification of this parameter.
	// Used by model or UI or anyone to see what's changed since the last time they saw the packet.
	HRESULT GetParameterTimestamp(const CATUnicodeString& iName, int& oTimestamp);
	HRESULT GetParameterTimestamp(const SWXUtPacketParameter* iParameter, int& oTimestamp);
	void SetParameterTimestamp( SWXUtPacketParameter* iParameter, int iTimestamp );

	// Get the type...
	HRESULT GetParameterTypeString(const CATUnicodeString& iName, CATUnicodeString& oType);

	// Get all the "cases" listed below a parameter. If some are returned, that implies
	// they are the only valid values (except for booleans, I guess, where true and false always work).
	HRESULT GetCaseListForParameter(const CATUnicodeString& iName, CATListOfCATUnicodeString& oCaseList);

	// Sets the caselist to a new value-list
	HRESULT SetCaseListForParameter(const CATUnicodeString& iName, const CATListOfCATUnicodeString& iCaseList);
	// Did the XML get opened successfully?
	bool IsBoundToXML() { return mFoundFile; }

	int GetLastTimestamp() { return mTimestamp; }

	void AddSetChangeMonitor(const CATUnicodeString& iPath, const void* iMonitorKey);
	bool GetNextSetChange(const CATUnicodeString& iPath, void* iMonitorKey, bool& oInsert, int& oKey);
	void RemoveSetChangeMonitor(const CATUnicodeString& iPath, void* iMonitorKey);

	// Internal.
	void ParameterChanged(const CATUnicodeString& iParamName, SWXUtPacketParameter* iPacketParam, bool iIgnoreErrors = false);

	void GetOperationDetails(CATUnicodeString& oOp, CATUnicodeString& oLib)
	{
		oOp = mOperationClass;
		oLib = mOperationLibrary;
	}

	HRESULT TrySetValue(const CATUnicodeString &iName, const CATUnicodeString &iNewValue);

	// Utilities for setting and getting basic value types.
	HRESULT SetValue(CATUnicodeString iName, double iValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT GetValue(CATUnicodeString iName, double &oValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT SetValue(CATUnicodeString iName, int iValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT GetValue(CATUnicodeString iName, int &oValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT SetValue(CATUnicodeString iName, bool iValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT GetValue(CATUnicodeString iName, bool &oValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT SetValue(CATUnicodeString iName, const CATMathVector &iValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT GetValue(CATUnicodeString iName, CATMathVector &oValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT SetValue(CATUnicodeString iName, const CATMathPoint &iValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT GetValue(CATUnicodeString iName, CATMathPoint &oValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT SetValue(CATUnicodeString iName, const CATMathPoint2D &iValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT GetValue(CATUnicodeString iName, CATMathPoint2D &oValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT SetValue(CATUnicodeString iName, const CATMathPlane &iValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT GetValue(CATUnicodeString iName, CATMathPlane &oValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT SetValue(CATUnicodeString iName, const CATMathTransformation &iValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT GetValue(CATUnicodeString iName, CATMathTransformation &oValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT SetValue(CATUnicodeString iName, const CATMathAxis &iValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT GetValue(CATUnicodeString iName, CATMathAxis &oValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT SetValue(CATUnicodeString iName, const CATUnicodeString& iValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT GetValue(CATUnicodeString iName, CATUnicodeString &oValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT GetEvaluatedValue(const CATUnicodeString &iName, CATUnicodeString &oValue);

	HRESULT SetOrderedSetSize(const CATUnicodeString &iName, int iValue);
	HRESULT GetOrderedSetSize(const CATUnicodeString &iName, int &oValue);

	// Remove indexed element from orderedset
	HRESULT RemoveElement(CATUnicodeString iOSPath, int iIndex, int iKey1 = -1);
	HRESULT InsertElement(CATUnicodeString iOSPath, int iIndex, int iKey1 = -1);

	////////////////////////////////////////////////////////////////////////////////
	// ENHANCED OBJECT-IN-PACKET INTERFACE (selection location information available)
	// SWXIUtSelectedObject is the wrapper object for a selectable object + position of selection
	HRESULT SetSelValue(CATUnicodeString iName, const SWXIUtSelectedObject_var& iValue, int iKey1 = -1, int iKey2 = -1);
	// Returns SWXIUtSelectedObject, the wrapper object for a selectable object + position of selection
	HRESULT GetSelValue(CATUnicodeString iName, const SWXUtHandlerOut& oValue, int iKey1 = -1, int iKey2 = -1);
	// The list must contain SWXIUtSelectedObject objects (not bare selectable objects)
	HRESULT SetSelValue(const CATUnicodeString &iName, const CATListValCATBaseUnknown_var& iValue);
	// The list will contain SWXIUtSelectedObject objects (not bare selectable objects)
	HRESULT GetSelValue(const CATUnicodeString &iName, CATListValCATBaseUnknown_var& oValue);

	////////////////////////////////////////////////////////////////////////////////
	// BASIC OBJECT-IN-PACKET INTERFACE
	// Get/Set for bare objects - internally these will create a SWXIUtSelectedObject to store
	// the passed in object (or the Get objects will get the selectable object from that).
	HRESULT SetValue(CATUnicodeString iName, const CATBaseUnknown_var &iValue, int iKey1 = -1, int iKey2 = -1);
	HRESULT GetValue(CATUnicodeString iName, const SWXUtHandlerOut &oValue, int iKey1 = -1, int iKey2 = -1);
	// Ditto these access the list of selectable objects (edges/faces/whatever) through the
	// SWXIUtSelectedObject instances that are actually stored in the packet.
	HRESULT SetValue(const CATUnicodeString &iName, const CATListValCATBaseUnknown_var &iValue);
	HRESULT GetValue(const CATUnicodeString &iName, CATListValCATBaseUnknown_var &oValue);

	static HRESULT CopyValue(SWXUtPacketParameter* iFrom, SWXUtPacketParameter* iTo, bool iCopyRestriction = false);

	HRESULT SetStoredParamValue( const CATUnicodeString& iName, const CATUnicodeString& iValue );
	HRESULT GetStoredParamValue( const CATUnicodeString& iName, CATUnicodeString& oValue );

	// IN and out of parameters
	HRESULT LoadParameter(const CATUnicodeString &iName, CATICkeParm* iParam);
	HRESULT ApplyParameter(const CATUnicodeString &iName, CATICkeParm* iParam);
	HRESULT AssociateParameter(const CATUnicodeString &iName, CATICkeParm* iParam);
	HRESULT DissociateParameter(const CATUnicodeString &iName);
	CATICkeParm* AskAssociatedParameter(const CATUnicodeString &iName);

	CATICkeParm* AskDisplayParameter(const CATUnicodeString &iName);

	HRESULT WriteToFile(const CATUnicodeString& iFilename);

	// For the UI to add constant value parameters for hardcoded values in UI XML
	// Returns a randomized name for the parameter so that the operation can't be coded
	// to access it.
	CATUnicodeString AddPrivateParameter(
		const CATUnicodeString& iType,
		const CATUnicodeString& iValue,
		const CATUnicodeString& iRestriction,
		bool iIsList);
	bool IsPrivateParameter(const SWXUtPacketParameter* iParam);

	typedef SWXUtMap<CATUnicodeString, CATIDOMElement_var, SWXCATUnicodeStringComparer> subpacketMap_t;

	// For Ix xml parsing
	static bool IsPacketTagName(const CATUnicodeString& iName);
	void ParseAndAddNode(bool iRecovery,
		const CATUnicodeString& iPrefix,
		CATIDOMElement_var iNode,
		subpacketMap_t& ioSubpackets,
		SWXUtPacket* iTransferPacket,
		const CATUnicodeString& iTransferPacketPrefix);

	// Utility function: when handed a "prototype" description for an OrderedSet, e.g. SetName.#.StringItem,
	// substitues in an index. Note that OrderedSets use a zero based index.
	static CATUnicodeString IndexOSName(const CATUnicodeString& iOrderedSetPrototypeName, int index1, int index2 = -1, int index3 = -1, CATUnicodeString* iIndexString = NULL);

	// Utility function: when handed a "prototype" description for an OrderedSet, e.g. SetName.#.StringItem,
	// returns the core OrderedSet name (in this example, "SetName") which can then be queried as an
	// integer to get or set the size of the OrderedSet.
	static CATUnicodeString ExtractOSName(const CATUnicodeString& iOrderedSetPrototypeName);

	// Utility function: when handed a "prototype" description for an OrderedSet, e.g. SetName.#.StringItem,
	// and an actual description e.g. SetName.5.StringItem, returns -1 if the prototype and description
	// don't match, and the number if they do (5 in this example).
	static int MatchOSName(const CATUnicodeString& iOrderedSetPrototypeName, const CATUnicodeString& iOrderedSetName);

	// Error handling for packets. It's possible to register against a parameter. Errors are
	// available through the packet in an ordered set - tehe file SWXUiErrorInformationPacket.xsd
	// is merged into all packets at run-time.
	HRESULT SetError(const CATUnicodeString& iParameterPath, const CATUnicodeString& iErrorResourceId);
	HRESULT ClearAllErrors();
	HRESULT GetErrorState(const CATUnicodeString& iParameterPath, const CATUnicodeString& iErrorResourceId);

	void SetAsyncChangeInterface(SWXIUtPacketChange* iAsyncChangeInterface);
	void NotifyAsyncOperationChange();

	//FRED ADDED THIS
	void SetJournal(bool iBool);
	bool GetJournal();

	SWXUtPacket* AddSubpacket(const CATUnicodeString& iPacketName, const CATUnicodeString& iParamName);

	//MAX for equations
	HRESULT ParameterHasEquation(const CATUnicodeString& iParamName,bool& oYesNo);
	HRESULT SetParameterEquationVisibility(const CATUnicodeString& iParamName,bool iYesNo);
	HRESULT GetParameterEquationVisibility(const CATUnicodeString& iParamName,bool& oYesNo);
	HRESULT GetParseOrUnitError(const CATUnicodeString& iParamName,int& oErrLvl);
	HRESULT SetParseOrUnitError(const CATUnicodeString& iParamName,int iErrLvl);
	HRESULT CannotHaveEquation(const CATUnicodeString& iParamName,bool& oNoEq);
	HRESULT SetPacketEquationData(const CATUnicodeString& iParamName,
		const CATUnicodeString& iCATStyle_formula,
		const CATListValCATBaseUnknown_var& iCATStyle_paramlist);

	// for unit specific conversions
	// only get is needed, setting in units is taken care of by "TrySetValue"
	HRESULT GetValueInUnit(const CATUnicodeString &iName, const CATUnicodeString &iUnit,
		CATUnicodeString& oValue);

	HRESULT SetDisplayUnit(const CATUnicodeString &iName, const CATUnicodeString &iUnit);
	HRESULT GetDisplayUnit(const CATUnicodeString &iName, CATUnicodeString &oUnit);

	// very very special - DO NOT USE - only for SubPackets
	void SetTimestamp(SWXUtPacketTimestamp_t iTS) { mTimestamp = iTS; }

	void GetAllKeysOfSet(const CATUnicodeString& iParamName, const SWXUtSet<int>*& oKeys);
	void RecordPacketChangeToJournal( const CATUnicodeString& iKeyName, const CATUnicodeString& iNewValue );
	void RecordPacketStructureChangeToJournal( const CATUnicodeString& iKeyName, int iIndex, bool iInsertElement );
	CATUnicodeString GetPacketFileName()const {return GetPacketDefinitionFile();}; //public version added 12/11/12 -sjr

	SWXIUtKnowledgePacket* GetKnowledge();
	bool IsKnowledgeAllowed() { return mKnowledgeAllowed; }

	void ReadRecentChanges(int iTimestamp, int& oTimestamp, SWXUtSet<CATUnicodeString>& oChangedParams);

	CATUnicodeString GetPacketDefinitionFile() const { return mPacketDefinitionFile; }
	SWXUtPacketParameter* FindPacketParameter(const CATUnicodeString& iPath);
private:
	SWXUtMap <SWXUtPacket*,SWXUtPacket* > mSubPacketPacketMap;
	// For Ix xml parsing
	static SWXUtPacketParameter* ParseNode(SWXUtPacket* iPacket, SWXUtParameterMap& ioParameters, bool iRecovery,
		const CATUnicodeString& iPrefix,
		SWXUtPacketParameter* iParentParam,
		CATIDOMElement_var iNode,
		subpacketMap_t& ioSubpackets, SWXUtPacket* iTransferPacket,
		const CATUnicodeString& iTransferPacketPrefix,
		const SWXUtMap<CATUnicodeString, CATListOfCATUnicodeString> iPendingNHCases);
	static void ParseParameters(SWXUtPacket* iPacket, SWXUtParameterMap& ioParameters,
		bool iRecovery,
		const CATUnicodeString& iPrefix,
		SWXUtPacketParameter* iParentParam,
		CATIDOMNode* iNode,
		SWXUtPacket::subpacketMap_t& ioSubpackets, SWXUtPacket* iTransferPacket,
		const CATUnicodeString& iTransferPacketPrefix,
		const SWXUtMap<CATUnicodeString, CATListOfCATUnicodeString> iPendingNHCases);
	static void ParseSingleCase(CATIDOMElement_var iChild,
		SWXUtPacket* iPacket, bool iRecovery,
		SWXUtPacketParameter* iParentParam,
		const CATUnicodeString& iPrefix,
		SWXUtPacket::subpacketMap_t& ioSubpackets, SWXUtPacket* iTransferPacket,
		const CATUnicodeString& iTransferPacketPrefix,
		const SWXUtMap<CATUnicodeString, CATListOfCATUnicodeString> iPendingNHCases);
	static void ParseCases(SWXUtPacket* iPacket, bool iRecovery,
		SWXUtPacketParameter* iParentParam,
		const CATUnicodeString& iPrefix,
		CATIDOMNode* iNode,
		SWXUtPacket::subpacketMap_t& ioSubpackets, SWXUtPacket* iTransferPacket,
		const CATUnicodeString& iTransferPacketPrefix);
	static SWXUtPacketParameter* CreateParameter(SWXUtPacket* iPacket, SWXUtPacketParameter* iParent,
		const CATUnicodeString& iFullname,
		const CATUnicodeString& iType,
		const CATUnicodeString& iValue,
		const CATUnicodeString& iRestriction,
		bool iIsList, const CATUnicodeString& iMinimum, const CATUnicodeString& iMaximum);

	SWXUtParameterMap mParameters;
	bool mFoundFile;

	void InitializeDictionary();
	CATUnicodeString mPacketDefinitionFile;

	SWXUtPacketTimestamp_t mTimestamp;

	CATUnicodeString mOperationLibrary;
	CATUnicodeString mOperationClass;

	CATUnicodeString mErrorString;

	// To catch weird type errors. Not implemented. If you see this
	// it's probably because you are passing something like a CATBaseUnknown *.
	// Use a CATBaseUnknown_var instead.
	HRESULT SetValue(const CATUnicodeString &iName, void *ipPointer);
	HRESULT GetValue(const CATUnicodeString &iName, void * &ipPointer);

	// used for subpackets only
	SWXUtMap<SWXUtPacket*, CATUnicodeString> mLinkingPackets;
	SWXIUtPacketChange* mAsyncChangeInterface;

	//FRED ADDED THIS STUFF
	bool mJournal;

	SWXIUtKnowledgePacket_var mKnowledge;
	bool mKnowledgeAllowed;

	// Not public for good reasons. Need to revise once tested. HFS.
public:
	class RecentValues { public: int mTimestamp; CATUnicodeString mParameter; };
	class CircularBuffer
	{
	public:
		CircularBuffer();
		void Write(int iTimestamp, const CATUnicodeString& iParameter);
		int GetOldest();

		int         mSize;   /* maximum number of elements           */
		int         mStart;  /* index of oldest element              */
		int         mEnd;    /* index at which to write new element  */
		SWXUtVector<RecentValues> mElems;
	} mCircularBuffer;
};

#endif
