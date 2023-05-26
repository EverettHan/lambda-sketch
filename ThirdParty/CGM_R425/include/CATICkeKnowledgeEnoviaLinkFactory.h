// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATICkeKnowledgeEnoviaLinkFactory.h
// Define the CATICkeKnowledgeEnoviaLinkFactory interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Jun 2005  Creation: Code generated by the CAA wizard  sgq
//===================================================================
#ifndef CATICkeKnowledgeEnoviaLinkFactory_H
#define CATICkeKnowledgeEnoviaLinkFactory_H

#include "KnowledgeItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByKnowledgeItf IID IID_CATICkeKnowledgeEnoviaLinkFactory;
#else
extern "C" const IID IID_CATICkeKnowledgeEnoviaLinkFactory ;
#endif

class CATICkeKnowledgeEnoviaLink_var;
class CATICkeLinkableAtom_var;
class CATISpecAttrAccess_var;
class CATISpecAttrKey_var;
class CATUnicodeString;

//------------------------------------------------------------------

/**
* Interface used for creating @href CATICkeKnowledgeEnoviaLink .
*
* @href CATICkeKnowledgeEnoviaLink, CATICkeKnowledgeEnoviaLinkListener
*/
class ExportedByKnowledgeItf CATICkeKnowledgeEnoviaLinkFactory: public CATBaseUnknown
{
	CATDeclareInterface;

public:

	enum CATCkeAttrInOut { cke_NEUTRAL, cke_IN, cke_OUT };

	virtual HRESULT CreateSemanticLink (
		const CATUnicodeString& iWeakType,
		const CATUnicodeString& iTypeOfPointed,
		const CATUnicodeString& iRoleOfPointed,
		const CATICkeLinkableAtom_var& iObjectToPoint,
		CATISpecAttrAccess_var iFatherOfSemLink,
		CATISpecAttrKey_var iFatherAttributeForSemLink,
		int iWithProxy,
		CATCkeAttrInOut iQuality,
		CATICkeKnowledgeEnoviaLink_var& oSemanticLink) = 0;

	// No constructors or destructors on this pure virtual base class
	// --------------------------------------------------------------
};

//------------------------------------------------------------------
CATDeclareHandler(CATICkeKnowledgeEnoviaLinkFactory, CATBaseUnknown);

#endif