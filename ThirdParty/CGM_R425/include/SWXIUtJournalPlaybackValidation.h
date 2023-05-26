//===================================================================

//===================================================================
// SWXIUtJournalPlaybackValidation.cpp
// Header definition of class SWXIUtJournalPlaybackValidation
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2013/06/13 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef SWXIUtJournalPlaybackValidation_H
#define SWXIUtJournalPlaybackValidation_H

#include "SWXUtJournal.h"
#include "CATBaseUnknown.h"

extern ExportedBySWXUtJournal  IID IID_SWXIUtJournalPlaybackValidation ;

class CATListValCATUnicodeString;
class CATUnicodeString;
class SWXUtOperationContext;

class ExportedBySWXUtJournal SWXIUtJournalPlaybackValidation : public CATBaseUnknown
{
	CATDeclareInterface;

	public:

		enum ValidationEvents_e
		{
			ValidationEvent_Unknown					= 0x0,
			ValidationEvent_CommandStart			= 0x1,
			ValidationEvent_OperationStart			= 0x2,
			ValidationEvent_AfterPreviewChanges		= 0x4,
			ValidationEvent_AfterApplyChanges		= 0x8,
			ValidationEvent_OperationEnd			= 0x10,
			ValidationEvent_CommandEnd				= 0x20
		};

	public:

		virtual int GetValidationMode() const = 0;
		virtual bool GetValidationInfoStrings( ValidationEvents_e iEvent, SWXUtOperationContext* iContext, CATListValCATUnicodeString& oStrings ) const = 0;
		virtual bool ValidateInformation( ValidationEvents_e iEvent, SWXUtOperationContext* iContext, CATListValCATUnicodeString& iInfo, CATUnicodeString& oError ) = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler( SWXIUtJournalPlaybackValidation, CATBaseUnknown );

#endif
