// COPYRIGHT Dassault Systemes 2002

#ifndef CATICkeEnoviaObjectFinder_H
#define CATICkeEnoviaObjectFinder_H

#include "KnowledgeItf.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByKnowledgeItf IID IID_CATICkeEnoviaObjectFinder;
#else
extern "C" const IID IID_CATICkeEnoviaObjectFinder ;
#endif

//------------------------------------------------------------------

class ExportedByKnowledgeItf CATICkeEnoviaObjectFinder: public CATBaseUnknown
{
	CATDeclareInterface;
	
public:
	enum WarningType { Creation = 1, Modification = 0x10, Modification_Pointants = 0x11, Deletion = 0x100 };

	/**
	* Use : for a parameter, iStartingObject is the parameter and iFatherOfStartingObject is its father
	*       for other object, iFatherOfStartingObject is the object and iStartingObject is NULL_var.
	*/
//	virtual HRESULT FindEnoviaFather (const CATBaseUnknown_var& iFatherOfStartingObject,
//		const CATBaseUnknown_var& iStartingObject,
//		CATBaseUnknown_var& oEnoviaObject,
//		CATUnicodeString& oTechnoLink) = 0;
//
		/**
	* Use : Returns true if the object has been partially rebuilt when importing the document
	*       from the PDM.
	*/
	virtual HRESULT IsObjectPartiallyRebuilt (const CATBaseUnknown_var& iPDMObject,
		int& oIsPartiallyRebuilt) = 0;

	/**
	* iStartingObject is the object to which the message is to be given.
	* iModifyingObject is an object related to this message (father, son, ..).
	*/
	virtual HRESULT WarnEnoviaObject (const CATBaseUnknown_var& iStartingObject,
		CATBaseUnknown_var iModifyingObject,
		const WarningType iMessage,
		const CATUnicodeString& info = CATUnicodeString()) = 0;

	/**
	* iStartingObject is the object to which the message is to be given.
	* iModifyingObject is an object related to this message (father, son, ..).
	*/
	virtual HRESULT IsPDMSafeSavable (const CATBaseUnknown_var& iStartingObject, CATUnicodeString& oWhyNotSavable) = 0;
};

//------------------------------------------------------------------
CATDeclareHandler(CATICkeEnoviaObjectFinder, CATBaseUnknown);

#endif
