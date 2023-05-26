//===================================================================
// COPYRIGHT [!output company] 2011/04/06
//===================================================================
// CATIKweNotify.cpp
// Header definition of class CATIKweNotify
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/04/06 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIKweNotify_H
#define CATIKweNotify_H

#include "KnowledgeItf.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

class CATCommand;
class CATKweHTMLTooltip;
extern ExportedByKnowledgeItf  IID IID_CATIKweNotify ;


class ExportedByKnowledgeItf CATIKweNotify: public CATBaseUnknown
{
CATDeclareInterface;

public:
	enum NotifyTooltipStyle
	{
		Tooltip,
		FloatingWindow,
		Managed
	};
	// To show one shot informations
	// Also flushes the message list 
	virtual void ShowInformation(const CATUnicodeString &iInformation) = 0;

	// Stores a message in the message list to show it with other ones later.
	virtual void StoreInformation(const CATUnicodeString &iInformation) = 0;

	// Displays all the information contained in the message list.
	virtual void FlushInformations() = 0;


	// Displays an HTML Tooltip.
	// Warning: html content is limited to what CATVidCtlTextEditor supports
	virtual CATKweHTMLTooltip * ShowHTMLTooltip(CATCommand *iFather,const CATIKweNotify::NotifyTooltipStyle &iStyle, const CATUnicodeString &iTitle, const CATUnicodeString &iHTMLBody, const CATBoolean iIsBodyHTML) = 0;

};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIKweNotify, CATBaseUnknown );

#endif
