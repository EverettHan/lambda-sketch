#ifndef CATExtInPlaceSite_H_
#define CATExtInPlaceSite_H_

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include <CATBaseUnknown.h>
#include <CATLISTP_CATBaseUnknown.h>
#include <CATAfrFoundation.h>

/**
 * Adapter for the CATInPlaceSite interface.
 * <b>Role:</b>To implement the interface <tt>CATInPlaceSite</tt> 
 * for a class <tt>MyClass</tt>, 
 * write a class <tt>MyClassExtInPlaceSite</tt> subclassed from <tt>CATExtInPlaceSite</tt> 
 * and defined as an data extension of <tt>MyClass</tt>. <tt>MyClassExtInPlaceSite</tt> 
 * may override various methods, but in most case there is nothing to do.
 *
 * @see CATInPlaceSite,CATIUIActivate
 */
class ExportedByCATAfrFoundation CATExtInPlaceSite : public CATBaseUnknown {

  CATDeclareClass;
  
public :
  
  /**
  * Constructs the class.
  */
  CATExtInPlaceSite ();
  virtual ~CATExtInPlaceSite ();
  
  /**
    * Asks the site whether it accepts a subordinates ui-activable
    * object's ui-activation.
    * @return
    *   This default implementation always returns 1.
    */
  virtual int CanInPlaceActivate();
  
  /**
    * Notifies the site that ui-activation will begin.
    * <br>
    * Called by the ui-activation manager
    * @return 
    *   This default implementation always returns 1.
    */
  virtual int OnInPlaceActivate();
  
  /**
    * Notifies the site that ui-activation will end.
    *<br>
    * Called by the ui-activation manager
    * @return 
    *   This default implementation always returns 1.
    */
  virtual int OnInPlaceDeactivate();
  
  /**
    * Notifies the site that the ui-active object's workshop
    * is going to be displayed.
    * <br>
    * Called by the ui-activation manager 
    * <br>
    * <b>Important notice:</b> If you override this method,
    * don't forget to call the subclass' method
    * @return 
    *   This default implementation always returns 1.
    */
  virtual int OnUIActivate();
  
  /**
    * Notifies the site that the ui-active object's workshop
    * is going to be removed.
    * <br>
    * Called by the ui-activation manager 
    *<br>
    * <b>Important notice:</b> If you override this method,
    * don't forget to call the subclass' method
    * @return 
    *   This default implementation always returns 1.
    */
  virtual int OnUIDeactivate();
  
private :

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATExtInPlaceSite (const CATExtInPlaceSite &);
  CATExtInPlaceSite & operator= (const CATExtInPlaceSite &);
  
  CATLISTP(CATBaseUnknown) _Previous_path;

};

#endif 
