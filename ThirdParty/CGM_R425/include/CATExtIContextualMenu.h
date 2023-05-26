#ifndef CATExtIContextualMenu_h
#define CATExtIContextualMenu_h

// COPYRIGHT DASSAULT SYSTEMES 2000
/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATAfrFoundation.h"
#include "CATBaseUnknown.h"

class CATCmdContainer;

/**
  * Adapter class of the CATIContextualMenu interface.
  * <br>Two ways to implement this interface:
  * <ol>
  * <li>You want to customize a default menu which contains these commands: Cut, Copy, Paste, 
  * PasteSpecial, Delete, Open Properties, Selection Sets, Define Selection Sets , Hide/Show and
  * some commands about the graph if your window contains one. 
  * <br>So in the constructor of your data extension you 
  * retrieve the default contextual menu, thanks to @href #GetContextualMenu, and you create 
  * several items, that you chain to it. It is not necessary to overwrite the 
  * <tt>GetContextualMenu</tt> method.
  * <br>Example of constructor:
  * <pre>
  *  MyDataExtensionClass::MyDataExtensionClass
  * {
  *    CATCmdContainer * pMenu = NULL ; 
  *    CATExtIContextualMenu::GetContextualMenu(pMenu);
  *    NewAccess(CATCmdStarter,pst1,"CAAPst1Module");
  *    .....
  *    AddAccessChild(pMenu,pst1); 
  * }
  * </pre> 
  * </li>
  * <li>You want a specific contextual menu. 
  * <br>So you write a data extension in overwriting
  * @href #GetContextualMenu to return your own menu. Your extension creates a 
  *  CATCmdContainer (the menu) and manages completely its content and its destruction.</li>
  * </ol>
  * 
  * @see CATIContextualSubMenu
*/
class ExportedByCATAfrFoundation CATExtIContextualMenu : public CATBaseUnknown
{
  CATDeclareClass;
  
public:
  
  /** 
    * Default constructor. 
    * <br><b>Note:</b>Initializes the contextual menu with commands defined at the top of 
    * this page. 
    */
  CATExtIContextualMenu();

  ~CATExtIContextualMenu();

  /**
   * Returns the contextual menu.
   * <br><b>Note:</b>This method returns the contextual menu. Its content can change between 
   * two calls.
   */
  virtual HRESULT GetContextualMenu(CATCmdContainer *& oMenu);
  
protected:
  /** @nodoc */
  CATCmdContainer * _Menu;
};

#endif

