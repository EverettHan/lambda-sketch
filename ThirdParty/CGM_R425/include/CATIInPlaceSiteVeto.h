#ifndef __CATIInPlaceSiteVeto_h
#define __CATIInPlaceSiteVeto_h

// COPYRIGHT DASSAULT SYSTEMES 2004

/**
 * IID CAA exposed (CATAfrCATIInPlaceSiteVetoIID.h)
 * Please implement thru the adapter : CATExtInPlaceSiteVeto
 */

#include "CATBaseUnknown.h"
#include "CATAfrItf.h"

class CATFrmEditor;
class CATPathElement;


/**
  * Interface to allow or not ui-activation of embedded objects implementing the 
  * @href CATIUIActivate interface.
  * <b>Role:</b>This interface can be implemented on an ui-activable class
  * to forbid ui-activation depending on a context.
  * <br> see @href CATInPlaceSite interface documentation for explanations about the ui-activation mechanisms.
  * <b>Important notice</b>: Using the @href CATExtInPlaceSiteVeto as a base class
  * when implementing <tt>CATIInPlaceSiteVeto</tt> is mandatory. 
  * <p><b>BOA information</b>: this interface CAN be implemented
  * using the BOA (Basic Object Adapter).
  * To know more about the BOA, refer to the CAA Encyclopedia home page.
  * Click Middleware at the bottom left, then click the Object Modeler tab page.
  * Several articles deal with the BOA.</p>
  */

class ExportedByCATAfrItf CATIInPlaceSiteVeto : public CATBaseUnknown {

	CATDeclareInterface;

public:

  /**
    * Asks the object implementing CATIInPlaceSiteVeto whether it accepts an ui-activation.
    * @param iPathToActivate
    *   The method decides whether the ui-activation of this path element is acceptable.
    *   The actual object concerned should be the terminal object of the path.
    *   The object implementing CATIInPlaceSiteVeto should appear in the path also, 
    *   because an object should decide about ui-activation of another object only it embeds this other object.
    * @param iInEditor
    *   The editor where the ui-activation could be done.
    * @return
    *   <dl>
    *   <dt><tt>S_OK</tt>   <dd>if authorizes ui-activation
    *   <dt><tt>E_FAIL</tt> <dd>otherwise
    *   </dl>
		*/
	virtual HRESULT CanInPlaceActivate (
		CATPathElement * iPathToActivate,
		CATFrmEditor   * iInEditor
		) = 0;

};


#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATAfrItf IID_CATIInPlaceSiteVeto;
#else
extern "C" const IID IID_CATIInPlaceSiteVeto;
#endif
CATDeclareHandler (CATIInPlaceSiteVeto, CATBaseUnknown);

#endif//__CATIInPlaceSiteVeto_h
