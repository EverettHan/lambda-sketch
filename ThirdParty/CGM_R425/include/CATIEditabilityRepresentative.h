// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATIEditabilityRepresentative.h
//
//  June 2011  Creation JRZ
//===================================================================
/**
  * @level Protected
  * @usage U3
*/

#ifndef CATIEditabilityRepresentative_H
#define CATIEditabilityRepresentative_H

#include "CATPLMComponentInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMComponentInterfaces IID IID_CATIEditabilityRepresentative;
#else
extern "C" const IID IID_CATIEditabilityRepresentative ;
#endif

//------------------------------------------------------------------

/**
 * Editability is defined at the PLMComponent level.
 * But it may be necessary to control the editability status of a session objects that is not a PLMComponent,
 * typically, on selection, when controling that the leaf of a CATPathElement is or not editable.
 *
 * By implementing that interface, session objects that are not PLMComponent
 * can indicate which PLMComponent controls their editability
 *
 */
class CATIPLMComponent;
class ExportedByCATPLMComponentInterfaces CATIEditabilityRepresentative : public CATBaseUnknown
{
  CATDeclareInterface;

  public:

	/**
	* Returns the PLMComponent that controls editability of the session object that implements that interface
	* @param opiComp [out, CATBaseUnknown#Release]
	*      The returned component
	*
  *	@return
	*      S_OK
	*      E_FAIL
	*/

      virtual HRESULT GetPLMComponent(CATIPLMComponent *& opiComp) = 0;
};

#endif
