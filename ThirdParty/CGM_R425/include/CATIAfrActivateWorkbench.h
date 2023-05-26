#ifndef CATIAfrActivateWorkbench_h
#define CATIAfrActivateWorkbench_h

// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATString.h"

extern ExportedByCATAfrItf IID IID_CATIAfrActivateWorkbench;

/**
* Interface to choose the initial workbench when UI activating an object.
* <b>Role</b>: When an object is UI activated, its workshop is displayed like one of
* its workbench if it has one of them. Implementing this interface allows you to overwrite 
* the default choice of the initial workbench for a workshop, i.e the last used workbench 
* for this workshop.
* <br>
* This interface must be implemented on ui-activable object ( as @href CATIUIActivate ). 
* Here are some ui-activable object types:<ul>
* <li><b>ASMPRODUCT</b> is the ui-activable type for Products, </li>
* <li><b>DrwDrawing</b> for Drawings,</li>
* <li><b>MechanicalPart</b> for Parts.</li>
* </ul>
*/
class ExportedByCATAfrItf CATIAfrActivateWorkbench : public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /**
  * Method called when UI activating an object.
  * <br><b>Role</b>: 
  * This method is called when the user ui-activates an object which edits itself in a workshop.
  * This method should return a workbench name useable in this workshop. If this workbench can not be 
  * activated (not a workbench name, not a workbench of the workshop, workbench not licensed), 
  * the default mechanism will be used to choose the workbench.
  * @return 
  *   The name of the workbench to activate.
  */
  virtual CATString & GetInitialWorkbench () = 0;
};


#endif
