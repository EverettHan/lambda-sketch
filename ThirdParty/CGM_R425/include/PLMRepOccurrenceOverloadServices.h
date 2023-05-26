#ifndef PLMRepOccurrenceOverloadServices_H
#define PLMRepOccurrenceOverloadServices_H

#include "CATPLMModelerBaseInterfaces.h"

#include "IUnknown.h"
#include "CATBoolean.h"

class CATPLMOccurrenceWrapper;
class PLMIRepOccurrenceOverloadServices;

//------------------------------------------------------------------

/**
 * Class providing services to create/remove/check overload of a Representation Occurrence.
 */

class ExportedByCATPLMModelerBaseInterfaces PLMRepOccurrenceOverloadServices
{
public:

  PLMRepOccurrenceOverloadServices(CATPLMOccurrenceWrapper & iOccWrap);
  virtual ~PLMRepOccurrenceOverloadServices ();

	/**
	*  For a given Representation Occurrence, creates an overloading stream.	
	*  @return
	*      <code>S_OK</code> if the overloading stream is successfully created.<br>
	*      <code>S_FALSE</code> if the overloading is already existing.<br>
	*      <code>E_FAIL</code> otherwise<br>
	*/
	HRESULT CreateOverloadingStream();

	/**
	*  For a given Representation Occurrence, destroys the overloading stream if existing.
	*  @return
	*      <code>S_OK</code> if the overloading stream is successfull removed<br>
	*      <code>E_FAIL</code> otherwise - ex : no overloading in current context<br>
	*/
	HRESULT RemoveOverloadingStream();

	/**
	*  For a given Representation Occurrence, checks if exists an overloading stream.
	*	 @param iCheckSubOverload
	*			 if TRUE, check if an overload stream exists in a lower context embeded in this occurrence.
	*	 @param oOverload
	*			 TRUE if the stream is overloaded in the context this occurrence, FALSE otherwise.
	*	 @param oSubOverload
  *      TRUE if iCheckSubOverload is TRUE and a stream is overloaded in a lower context embeded in this occurrence, FALSE otherwise.
	*	 @param oSubOverloadedOccWrap
  *      The highest embeded overloaded occurrence if iCheckSubOverload is TRUE and a stream is overloaded in a lower context embeded in this occurrence.
	*  @return
	*      <code>S_OK</code> if succeeded<br>
	*      <code>E_FAIL</code> otherwise <br>
	*/
  HRESULT IsStreamOverloaded(CATBoolean iCheckSubOverload, CATBoolean & oOverload, CATBoolean & oSubOverload, CATPLMOccurrenceWrapper & oSubOverloadedOccWrap);

private:
  CATPLMOccurrenceWrapper & _occWrap;
  PLMIRepOccurrenceOverloadServices * _repOccOverloadServices;
};

//------------------------------------------------------------------

#endif
