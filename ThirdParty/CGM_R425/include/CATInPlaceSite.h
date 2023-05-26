#ifndef CATInPlaceSite_H_
#define CATInPlaceSite_H_

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U4 CATExtInPlaceSite
 */

#include "CATBaseUnknown.h"
#include "CATAfrItf.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATAfrItf IID_CATInPlaceSite;
#else
extern "C" const IID IID_CATInPlaceSite;
#endif


/**
  * Interface to allow ui-activation of embedded objects implementing the 
  * CATIUIActivate interface.
  * <b>Role:</b>
  * A document contains a hierarchical structure of objects. Some 
  * of these objects are able to provide a set of commands, called 
  * a workshop. Such objects get this ability by 
  * implementing the @href CATIUIActivate interface,
  * and these objects are then said to be <b>ui-activable</b>. An 
  * ui-activable object whose workshop is displayed is the 
  * <b>ui-active</b> object. UI-activation operates on @href CATPathElement
  * objects which are path from the document's
  * root to an object in the document's tree structure.
  * <br>
  * The basis of the ui-activation mechanisms lay on three actors :
  * <ul>
  * <li>- the @href CATIUIActivate interface implemented by 
  * ui-activable objects,</li>
  * <li>- the <tt>CATInPlaceSite </tt> interface implemented by site 
  * objects,</li>
  * <li>- the @href CATFrmEditor class that manages the current ui-active
  * object.</li>
  * </ul>
  * UI-activation consists of pairs of site / ui-activable objects
  * managed by the <tt>CATFrmEditor</tt> class. In order to be ui-activated
  * (having its workshop displayed on the screen), an ui-activable object
  * must have a valid site object in its hierarchy. The role of the site
  * is to accept or block the ui-activation requests coming from the 
  * subordinates ui-activable objects.
  * <br>
  * The <tt>CATInPlaceSite</tt> methods are called by the ui-activation
  * manager with respect to the following sequence:
  * <ul>
  * <li><tt>CanInPlaceActivate</tt> : does the site accept the ui-activation 
  * request</li>
  * <li><tt>OnInPlaceActivate</tt> : ui-activation initialization 
  * notification</li>
  * <li><tt>OnUIActivate</tt> : workshop display notification</li>
  * <li> ... </li>
  * <li><tt>OnInPlaceDeactivate</tt> : workshop removal notification</li>
  * <li><tt>OnUIDeactivate</tt> : ui-deactivation completed</li>
  * </ul>
  * <b>Note:</b>
  * Using a subclass of @href CATExtInPlaceSite is mandatory 
  * recommended when implementing this interface.
  *
  * <p><b>BOA information</b>: this interface CANNOT be implemented
  * using the BOA (Basic Object Adapter).
  * To know more about the BOA, refer to the CAA Encyclopedia home page.
  * Click Middleware at the bottom left, then click the Object Modeler tab page.
  * Several articles deal with the BOA.</p>
  */
class ExportedByCATAfrItf CATInPlaceSite: public CATBaseUnknown
{
  CATDeclareInterface;

public:
  
  /**
    * Asks the site whether it accepts a subordinates ui-activable
    * object's ui-activation.
    * @return
    *   1 on accept, 0 on reject.
    */
  virtual int  CanInPlaceActivate () = 0;
  
  /**
    * Notifies the site that ui-activation will begin.
    * Called by the ui-activation manager 
    * @return 
    *   0 on failure, 1 otherwise.
    */
  virtual int  OnInPlaceActivate () = 0;
  
  /**
    * Notifies the site that the ui-active object's workshop
    * is going to be displayed.
    * Called by the ui-activation manager.
    * @return 
    *   0 on failure, 1 otherwise.
    */
  virtual int  OnUIActivate () = 0;
  
  /**
    * Notifies the site that ui-activation will end.
    * Called by the ui-activation manager .
    * @return 
    *   0 on failure, 1 otherwise.
    */
  virtual int  OnInPlaceDeactivate () = 0;
  
  /**
    * Notifies the site that the ui-active object's workshop
    * is going to be removed.
    * Called by the ui-activation manager.
    * @return 
    *   0 on failure, 1 otherwise.
    */
  virtual int  OnUIDeactivate () = 0;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler (CATInPlaceSite, CATBaseUnknown);


#endif
