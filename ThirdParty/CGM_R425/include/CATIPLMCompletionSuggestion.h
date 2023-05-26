// COPYRIGHT Dassault Systemes 2012
//===================================================================
// Nov 2012  Creation: DTI
//===================================================================
#ifndef CATIPLMCompletionSuggestion_H
#define CATIPLMCompletionSuggestion_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"
#include "CATPLMCompletionSuggestionOutput.h"
class CATUnicodeString;

extern ExportedByCATPLMServicesItf  IID IID_CATIPLMCompletionSuggestion ;

class ExportedByCATPLMServicesItf CATIPLMCompletionSuggestion : public CATBaseUnknown
{
  CATDeclareInterface;

public:

	/**
	* Gets a suggestion of completion for a given string.
	* @param iStr
	*    The string to be completed.
	* @param oOutput
  *    The Completion Suggestion result.
	*	@return
  *    S_OK : The list has no error.
	*		 E_INVALIDARG : iStr is empty or oOutput is not empty.
  *    E_FAIL  : A problem occurs during the query.
	*/
  virtual HRESULT GetCompletionSuggestion( CATUnicodeString iStr, CATPLMCompletionSuggestionOutput &oOutput ) = 0;

};
//------------------------------------------------------------------
CATDeclareHandler( CATIPLMCompletionSuggestion, CATBaseUnknown );

//-----------------------------------------------------------------------
#endif
