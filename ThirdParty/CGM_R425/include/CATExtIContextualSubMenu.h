#ifndef __CATExtIContextualSubMenu_h
#define __CATExtIContextualSubMenu_h

// COPYRIGHT DASSAULT SYSTEMES 2005

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATAfrFoundation.h"
#include "CATBaseUnknown.h"
#include "CATIContextualSubMenu.h"
#include "TIE_CATIContextualSubMenu.h"

class CATCmdAccess;


/**
 * Adapter for the CATIContextualSubMenu interface.
 * <b>Role:</b>To implement the interface <tt>CATIContextualSubMenu</tt> 
 * for a class <tt>MyClass</tt>, 
 * write a class <tt>MyClassExtIContextualSubMenu</tt> subclassed from <tt>CATExtIContextualSubMenu</tt> 
 * and defined as a data extension of <tt>MyClass</tt>. <tt>MyClassExtIContextualSubMenu</tt>.
 * <br>A standard implementation consists in building in the constructor a chain of @href CATCmdAccess which represents the contextual sub-menu 
 * for the object implementing the CATIContextualSubMenu interface. The other methods do not need to be overloaded.
 *
 * @see CATIContextualSubMenu
 */
class ExportedByCATAfrFoundation CATExtIContextualSubMenu : public CATBaseUnknown {
 
  CATDeclareClass;

public:

  /**
  * Constructs the class.
  * <br><b>Role:</b>You can here create the chain of @href CATCmdAccess which represents the contextual sub-menu 
  * for the object implementing the CATIContextualSubMenu interface.
  * Do not forget to set the _accessChain protected data member whith the first access of the chain.
  */
  CATExtIContextualSubMenu();

  /**
  * Deletes the class.
  * <br><b>Role:</b>The default behavior is to delete the _accessChain protected data member and all its chain.
  */

  virtual ~CATExtIContextualSubMenu ();

  /**
    * Gets the object's contextual sub-menu.
    * <br><b>Role:</b>This method returns a chain of @href CATCmdAccess which represents the contextual sub-menu 
    * for the object implementing the CATIContextualSubMenu interface.
    * This method can be overloaded. Its default behavior is only to return the _accessChain protected data member
    * which was set in the contructor.
    * @return
    *   The first access of the chain.
    */
  virtual CATCmdAccess * GetContextualSubMenu ();

  /**
  * @nodoc
  * Changes the component state.
  * <br><b>Role:</b>This method deletes the _accessChain when the component state is set to Destroyed.
  * DO NOT IMPLEMENT.
  */
  virtual HRESULT ChangeComponentState (ComponentState iFromState,
                                        ComponentState iToState,
                                        const CATSysChangeComponentStateContext * iContext);


protected:

  /**
    * Chain of CATCmdAccess which represents the contextual sub-menu 
    * for the object implementing the CATIContextualSubMenu interface.
    * <br><b>Role:</b>This chain may be built in the constructor of the extension. It is returned by GetContextualSubMenu.
    *
    * @see CATCmdAccess
  */
  CATCmdAccess *         _accessChain;

  /**
   * @nodoc
   */
  void Init();

  

private:

  void Clean ();

};

#endif//__CATExtIContextualSubMenu_h
