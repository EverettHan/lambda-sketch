// COPYRIGHT Dassault Systemes 2012
//=============================================================================
//
// CATVidSubMenuAction.h
// Header definition of CATVidSubMenuAction
//
//=============================================================================
//  Feb 2012  Creation: LD5
//=============================================================================
#ifndef CATVidSubMenuAction_H
#define CATVidSubMenuAction_H

#include <VisuDialog.h>
#include <CATVidAbstractAction.h>
#include <CATBaseUnknown_WR.h>
class CATVidSubMenuActionGroup;
class CATVidAbstractActionGroup;
class CATVidMdlMenu;
class CATVidMdlSubMenu;

//-----------------------------------------------------------------------------

/** @ingroup groupVidMenu
 *
 * A @ref CATVidSubMenuAction is the abstraction of a command which opens a
 * custom submenu (@ref CATVidMdlSubMenu) inside a menu 
 * (@ref CATVidMdlMenu).
 *
 * @par Command
 * The command of an action is executed each time that the action is
 * activated, ie. when @ref CATVidAction#Activate is called. 
 * This command can be defined either 
 * by subclassing @ref CATVidAction and overriding @ref #Run, or by
 * listening to @ref #Activated events and reacting to them.
 *
 * @par Groups
 * Actions can be gathered in groups (@ref CATVidSubMenuActionGroup). This 
 * allow group enabling and disabling of submenus, and group storage of 
 * submenus.
 *
 * @par Submenus actions in menus
 * A submenu is a special kind of action that contains a submenu. When clicked 
 * on or hovered in a menu view, it opens this submenu.
 *
 * @par Menu / submenu parenting (see also @ref CATVidAction)
 * A submenu action can only be added once inside a menu, as it will be used 
 * for traversal of the menu tree. It represents a non-terminal node of the 
 * menu tree. 
 *
 * @see CATVidAbstractAction
 * @see CATVidAction
 * @see CATVidMenuActionGroup
 * @see CATVidMdlMenu
 */
class ExportedByVisuDialog CATVidSubMenuAction : public CATVidAbstractAction
{
  CATDeclareClass;
  friend class CATVidActionGroup;
  friend class CATVidMdlMenu;

public:
  /** Default constructor. */
  CATVidSubMenuAction();
  /**
   * Constructor with menu model. 
   *
   * @param i_pMenu the menu model. @c AddRef will be called on the pointer.
   */
  CATVidSubMenuAction(CATVidMdlSubMenu * i_pMenu);
  /**
   * @copydoc CATVidAbstractActionGroup#GetGroup
   */
  CATVidSubMenuActionGroup * GetGroup() const;
  /**
   * Add a menu to the action.
   *
   * @par
   * An action with a menu, if put in a @ref CATVidMdlMenu, will be interpreted
   * as a submenu. In @c CATVidMdlContextMenu and @c CATVidMdlSubMenu, this 
   * submenu pops on hovering of the menu item representing the action, or
   * clicking it. Actions which owns a menu do not execute any command and 
   * are not checkable.
   *
   * @param i_pMenu the menu associated to this action. @c AddRef will be
   * called on the pointer.
   */
  void SetSubMenu(CATVidMdlSubMenu * i_pMenu);
  /**
   * @return the menu opened by the action, if any.
   */
  CATVidMdlSubMenu * GetSubMenu() const;

protected:
  /** Destructor. */
  virtual ~CATVidSubMenuAction();
  /**
   * Keeps a weak reference on the menu that the action has been added to as a
   * menu item, if any. Used internally for menu / submenu parenting.
   */
  void SetContainerMenu(CATVidMdlMenu * i_pMenu);
  /**
   * Used internally for menu / submenu parenting.
   * @return the menu in which the action has been added as a menu item, if 
   * any.
   */
  CATVidMdlMenu * GetContainerMenu() const;
  /**
   * @copydoc CATVidAbstractActionGroup#SetGroup
   */
  virtual void SetGroup(CATVidAbstractActionGroup * i_pGroup);

private:
  /** Copy constructor. */
  CATVidSubMenuAction(CATVidSubMenuAction &);
  /** Copy operator. */
  CATVidSubMenuAction& operator=(CATVidSubMenuAction& original);

private:
  /**
   * See @ref #SetActionMenu .
   */
  CATVidMdlSubMenu * _pMenu;
  /**
   * See @ref #SetContainerMenu .
   */
  CATBaseUnknown_WR _wrContainerMenu;
};

//-----------------------------------------------------------------------------
#endif
