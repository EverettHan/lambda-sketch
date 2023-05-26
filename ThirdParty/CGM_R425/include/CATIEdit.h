#ifndef CATIEdit_h
#define CATIEdit_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U4 CATExtIEdit
 */

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

class CATCommand;
class CATDlgFrame;
class CATPathElement;
class CATDialog;
class CATString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIEdit;
#else
extern "C" const IID IID_CATIEdit;
#endif


/**
  * Interface implemented by CATIA objects to react to double clicking.
  * <b>Role:</b> A double clic on a pad in the part design 
  * workshop pops up the definition dialog, and the invocation
  * of the contextual menu on a pad makes the item "Definition ..."
  * available under the "Object Pad.1" submenu). 
  * <br>
  * This is possible because the Pad object implements CATIEdit.
  * When double-clicked on, or activated from the "Definition ..."
  * contextual item, a CATIA object implementing CATIEdit is callbacked
  * on its @href #Activate method and is then expected to start a @href
  * CATCommand.
  * <br>
  * Note that before being activated via @href #Activate, the ui-activation
  * manager ui-activates the first ui-activable object ( @href CATIUIActivate )
  * in the immediate hierarchy of this feature.
  * <br> 
  * <b>Important notice</b>: Using the @href CATExtIEdit as a base class
  * when implementing <tt>CATIEdit</tt> is mandatory. 
  * <p><b>BOA information</b>: this interface can be implemented
  * using the BOA (Basic Object Adapter).
  * To know more about the BOA, refer to the CAA Encyclopedia home page. 
  * Click Middleware at the bottom left, then click the Object Modeler tab page.
  * Several articles deal with the BOA.</p>
  */
class ExportedByCATAfrItf CATIEdit : public CATBaseUnknown
{
  CATDeclareInterface;
  
public:
  
  /**
    * Returns the command to launch to edit the object.
    * <br><b>Role:</b>
    * Called by the ui-activation manager, see @href CATIUIActivate,
    * when the user double-clics on the feature, or selects the
    * "Definition .." sub-item on the feature's contextual menu.
    * @param iPath
    *   A <tt>CATPathElement</tt> to the current feature object
    * @return
    *   Returning the instanciated command, if any, is a good choice
    * @see CATPathElement
    */
  virtual CATCommand  * Activate (CATPathElement * iPath) = 0;

  /**
    * @nodoc
    * Please implement @href #GetPanelItem instead.
    * Must return NULL.
    */
  virtual CATDlgFrame * GetInPanelEditor () = 0;

  /**
    * Returns a <tt>CATDlgFrame</tt> widget representing the current feature. 
    * <br><b>Role:</b> During a multi-selection of feature objects
    * implementing the CATIEdit interface, it is thus possible for a 
    * command to build a compound dialog containing each selected feature's 
    * editing widget.
    * @param iParent
    *   The widget that the returned CATDlgFrame must parented to.
    * @param iTitle
    *   The title that the returned widget must have.
    * @return
    *   A new <tt>CATPathElement</tt>, child of <tt>iParent</tt> with the title 
    * <tt>iTitle</tt>.
    * @see CATDlgFrame
    */
  virtual CATDlgFrame * GetPanelItem (CATDialog * iParent, 
                                      const CATString & iTitle) = 0;
};



CATDeclareHandler (CATIEdit, CATBaseUnknown);

#endif
