#ifndef CATIAfrUIActivation_h
#define CATIAfrUIActivation_h

// COPYRIGHT DASSAULT SYSTEMES 2004

/**
 * @CAA2Level L1
 * @CAA2Usage U6
 */

#include <CATAfrItf.h>
#include <CATBaseUnknown.h>

extern ExportedByCATAfrItf IID IID_CATIAfrUIActivation;

/**
* Base interface to add behavior to ui-activable types.
* <b>Role</b>: This interface must never be implemented. Each ui-activable type provides an interface 
* derived from this one which can be implemented to execute any code when the user ui-activates or 
* ui-deactivates an object of this type. For a given ui-activable type, the derived interface name is 
* built as follows : CATI<ui-active->IsA()>UIActivated.<ul>
* <li>ASMPRODUCT is the ui-activable type for Products
* <li>PRTSketch for Sketches
* <li>DrwDrawing for Drawings
* <li>MechanicalPart for Parts</ul>
* For instance, for sketches, the interface name is CATIPRTSketchUIActivated. Each late type which 
* implements CATIPRTSketchUIActivated will be called on the UIActivation method when any sketch 
* is ui-activated and on the UIDeactivation method when any sketch is ui-deactivated.
* <br>
*/
class ExportedByCATAfrItf CATIAfrUIActivation : public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /**
  * Method to call when ui-activating.
  * <br><b>Role</b>: 
  * This method is called when the user ui-activates an object which has the type contained in the 
  * interface name.
  * When this method is called, the current ui-active object has already been changed.
  * @return 
  *   Return code. Not used at this time. 
  */
    virtual HRESULT UIActivation () = 0;

  /**
  * Method to call when ui-deactivating.
  * <br><b>Role</b>: 
  * This method is called when the user ui-deactivates an object which has the type contained in the 
  * interface name.
  * When this method is called, the current ui-active object has not been changed yet.
  * @return 
  *   Return code. If this code is not S_OK, the ui-deactivation will be cancelled. 
  */
    virtual HRESULT UIDeactivation () = 0;
};


#endif
