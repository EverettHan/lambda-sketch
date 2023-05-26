
#ifndef CATICAfrComponentController_H
#define CATICAfrComponentController_H

// COPYRIGHT DASSAULT SYSTEMES 2011/12/19
/**
 * @level Protected
 * @CAA2Usage U3
 */

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATString.h"

class CATCAfrComponentControllerArg;

extern ExportedByCATAfrItf  IID IID_CATICAfrComponentController ;
//-----------------------------------------------------------------------------

/**
* @nodoc
* Interface to manage the Afr Component.
* <br><b>Role</b>: This interface enable to nstantiate a C-Afr component.
*/
class ExportedByCATAfrItf CATICAfrComponentController: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
	* @nodoc
    * Instantiates a C-Afrcomponent.
	*
    *  @param ipControllerArg
    *    The CATCAfrComponentControllerArg of the component.
    *
	*  @return
	*    An HRESULT value. 
	*    <br><b>Legal values</b>:
    *    <ul>
    *      <li><b>S_OK</b>The function was executed successfully.</li>
    *      <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *    </ul>
    */
    virtual HRESULT ComponentAction( CATCAfrComponentControllerArg* ipControllerArg ) = 0;

};
#endif
