#ifndef SWXUiIxComponentBinding_H
#define SWXUiIxComponentBinding_H
// COPYRIGHT Dassault Systemes 2010
// Creation: HFS (JMF in the real world)
#include "SWXUtVector.h"
class CATUnicodeString;
#include "CATString.h"

// The new way to do bindings is to use this inside the GetUsageDetails() methods of the UI component interface. 
// 
// e.g. 
// void SWXUiMyComponent::GetUsageDetails(SWXUiIxComponentUsageDetails& oDetails)
// {
//     base_class::GetUsageDetails(oDetails);
// 	    SWXUIIX_BINDING(BINDING_UNDOONAPPLY, "String", "Causes the component to set an undo mark on every apply when used with Undo='Incremental' ix files");
// }
//
// Please try to make the documentation useful and meaningful!
//
#define SWXUIIX_BINDING( NAME, TYPE, COMMENT ) \
	static const char* DOC_##NAME = COMMENT; \
	oDetails.mBindings.PushBack(SWXUiIxComponentBinding(NAME, TYPE, false)); \
	oDetails.mBindings.Back().SetDoc(DOC_##NAME, __FILE__);

// Class used to declare a single component binding

class SWXUiIxComponentBinding
{
public:
	SWXUiIxComponentBinding(const CATUnicodeString& iName, const CATUnicodeString& iType, bool iList = false)
	{
		mName = iName;
		mType = iType;
		mList = iList;
		mDoc = NULL;
	}
	bool operator<(const SWXUiIxComponentBinding& rhs) const
	{
		return (mName < rhs.GetName()) ? true : false;
	}

	const CATUnicodeString& GetName() const { return mName; }
	const CATUnicodeString& GetType() const { return mType; }
	const bool GetIsList() const { return mList; }
	void SetIsList() { mList = true; }
	void SetDoc(const char* iDoc, const char* iFile) { mDoc = iDoc; mFile = iFile; }
	const char* GetDoc() { return mDoc; }
	CATString GetFile() { return mFile;}
private:
	CATUnicodeString mName;
	CATUnicodeString mType;
	bool mList;
	const char* mDoc;
	CATString mFile;
};

// Collection of bindings and related data

class SWXUiIxComponentUsageDetails
{
public:
	SWXUiIxComponentUsageDetails() : mChildren(ChildrenStandard), mGetDoc(false) {}

	SWXUtVector<SWXUiIxComponentBinding> mBindings;

	enum Children { // allowed XML child nodes of a UI component
		ChildrenStandard, // other UI comps, parameter, override, case - all parsed at construction time
		ChildrenNone, // no children allowed
		ChildrenOverrideOnly, // only override allowed - parsed at construction time
		ChildrenInterPacket, // override, linkback, parameter - parsed when some action occurs such as starting a subcommand 
		ChildrenTriggerComponent //Used exclusively for triggerComponentSettings.
	} mChildren;

	int mGetDoc;

};

#endif
