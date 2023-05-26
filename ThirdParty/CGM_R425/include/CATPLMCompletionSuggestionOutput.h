// COPYRIGHT Dassault Systemes 2012
//===================================================================
// Nov 2012  Creation: DTI
//===================================================================
#ifndef CATPLMCompletionSuggestionOutput_H
#define CATPLMCompletionSuggestionOutput_H

#include "CATBaseUnknown.h"
#include "CATPLMServicesItf.h"

#include "CATUnicodeString.h"
#include "CATOmxAny.h"

class CATWOmxBinaryStream;

class ExportedByCATPLMServicesItf CATPLMCompletionSuggestionOutput : public CATBaseUnknown
{
public:
  CATPLMCompletionSuggestionOutput ();
  ~CATPLMCompletionSuggestionOutput ();

  /**
  * Adds a string in the list of suggestions.
	*	CAUTION : this method should NOT be used by CATIPLMCompStatement users.
  * @param iStr
  *    The string to add.
  * @return
  *    E_INVALIDARG : iStr is empty
  *    S_OK : The string has been added.
  */	
	HRESULT AddSuggestion (const CATUnicodeString &iStr);

  /**
  * Returns the list of suggestions.
  * @param oStr
  *    The list of suggestions.
  * @return
  *    S_OK : The string has been added.
  */	
	HRESULT GetSuggestion (CATOmxAny &oStr);

  /**
  * Returns the empty status of the list of suggestions.
  * @return
  *   1 : The list is empty
  *   0 : The list is not empty.
  */	
	int IsEmpty ();

  /**
  * Appends a list.
  * @param iCompletionSuggestion
  *    The object containing list to add.
  * @return
  *    the list containing the stored list + the list to add.
  */
	CATPLMCompletionSuggestionOutput& operator+(CATPLMCompletionSuggestionOutput &iCompletionSuggestion);

  /**
  * Marshalls the object in the input stream.
  */
  HRESULT Marshall (CATWOmxBinaryStream &iStream);

  /**
  * Unmarshalls the object from the input stream.
  */
  HRESULT Unmarshall (CATWOmxBinaryStream &iStream);

private:
	CATOmxAny _Suggestions;
};

#endif
