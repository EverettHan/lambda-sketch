#ifndef CATIPLMEditRepOccurrence_H
#define CATIPLMEditRepOccurrence_H

#include "CATBaseUnknown.h"
#include "CATPLMModelerOccInterfaces.h"
#include "CATListPV.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerOccInterfaces IID IID_CATIPLMEditRepOccurrence;
#else
extern "C" const IID IID_CATIPLMEditRepOccurrence;
#endif

/**
* @level Private
* @usage U3
*/

class ExportedByCATPLMModelerOccInterfaces CATIPLMEditRepOccurrence : public CATBaseUnknown
{
  CATDeclareInterface;

public:

	/**
	*  For a given Rep Occurrence, creates an overloading stream.	
	*  @return
	*      <code>S_OK</code> if the overloading stream is successfully created.<br>
	*      <code>S_FALSE</code> if the overloading is already existing.<br>
	*      <code>E_FAIL</code> otherwise<br>
	*/
	virtual	HRESULT CreateOverloadingStream() = 0;

	/**
	*  For a given source rep instance, destroys the overloading stream if existing.
	*  @return
	*      <code>S_OK</code> if the overloading stream is successfull removed<br>
	*      <code>E_FAIL</code> otherwise - ex : no overloading in current context<br>
	*/
	virtual	HRESULT RemoveOverloadingStream() = 0;

	/**
	*  For a given source rep instance, checks if exists an overloading stream.
	*	 @param oBool
	*			 TRUE if the stream is overloaded, FALSE otherwise
	*  @return
	*      <code>S_OK</code> the stream is overladed<br>
	*      <code>S_FALSE</code> the stream is NOT overladed<br>
	*      <code>E_FAIL</code> otherwise <br>
	*/
	virtual	HRESULT IsStreamOverloaded(CATBoolean & oBool) = 0;

};

CATDeclareHandler(CATIPLMEditRepOccurrence, CATBaseUnknown);

#endif
