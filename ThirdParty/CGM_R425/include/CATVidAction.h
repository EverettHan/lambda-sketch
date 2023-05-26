// COPYRIGHT Dassault Systemes 2012
//=============================================================================
//
// CATVidAction.h
// Header definition of CATVidAction
//
//=============================================================================
//  Feb 2012  Creation: LD5
//=============================================================================
#ifndef CATVidAction_H
#define CATVidAction_H

#include "VisuDialog.h"
#include "CATVidAbstractAction.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"
class CATVidAbstractActionGroup;
class CATSYPEvent;
class CATVidActionGroup;

//-----------------------------------------------------------------------------

/** @ingroup groupVidMenu
 * A @ref CATVidAction is the abstraction of a custom command.
 *
 * @par Command
 * The command of an action is executed each time that the action is
 * activated, ie. when #Activate is called. This command can be defined either 
 * by subclassing @ref CATVidAction and overriding @ref #Run, or by
 * listening to @ref #Activated events and reacting to them.
 *
 * @par Checkable actions
 * A checkable action (@ref #SetCheckableFlag) has a check state 
 * (@ref #SetCheckState). This state may be taken into account when
 * implementing the command of the action, for example.
 *
 * @par Exclusive actions
 * Actions can be made exclusive by adding them in an exclusive group 
 * (@ref CATVidActionGroup#SetExclusiveFlag). Only one checkable action at a 
 * time can be checked in an exclusive group. 
 *
 * @par Simple actions in menus
 * Actions can be added in menus. When added in a @ref CATVidMdlMenu, an 
 * enabled action can be activated and toggled with a click on the 
 * corresponding action menu item. Disabled actions cannot be interacted with.
 *
 * @par Menu / submenu parenting (see also @ref CATVidSubMenuAction)
 * A simple action can be added into several @ref CATVidMdlMenu. It 
 * represents a leaf of the menu / submenu tree.
 *
 * @par Data template (see @ref CATVidAbstractAction for more information)
 * If the action is checkable, but not exclusive, the icon is replaced by a 
 * check box. If the action is checkable and exclusive, the icon is replaced by 
 * a radio button.
 *
 * @see CATVidAbstractAction
 * @see CATVidSubMenuAction
 * @see CATVidActionGroup
 * @see CATVidMdlMenu
 */
class ExportedByVisuDialog CATVidAction : public CATVidAbstractAction
{
  CATDeclareClass;
  friend class CATVidActionGroup;
  friend class CATVidMdlMenu;

public:
  /** Default constructor. */
  CATVidAction();
  /**
   * @copydoc CATVidAbstractActionGroup#GetGroup
   */
  CATVidActionGroup * GetGroup() const;
  /**
   * When activated, an action executes a user-defined command. 
   *
   * @par
   * In practice, @ref #Activate calls @ref #Run, then send an @ref #Activated 
   * event. The command to execute can be defined either by sublassing 
   * @c CATVidAction and redefining @ref #Run, or by listening to 
   * @ref #Activated events.
   */
  void Activate();
  /**
   * Does nothing. You can subclass @c CATVidAction to implement a command to
   * execute.
   */
  virtual void Run();
  /**
   * @return an label for the accelerator of this action 
   * (eg. <tt>"Ctrl + E"</tt>).
   */
  CATUnicodeString GetAcceleratorLabel() const;
  /**
   * @param i_sAcceleratorLabel label for the accelerator of this action.
   */
  void SetAcceleratorLabel(const CATUnicodeString& i_sAcceleratorLabel);
  /**
   * @return the checkable flag of the action.
   */
  CATBoolean GetCheckableFlag() const;
  /**
   * Enable this flag to allow an action to be checked/unchecked with 
   * @ref #SetCheckState . 
   * 
   * <br/> Default value is @c FALSE.
   *
   * @param i_bCheckableFlag @c TRUE if this action has a check state, 
   * @c FALSE else.
   */
  void SetCheckableFlag(CATBoolean i_bCheckableFlag);
  /**
   * @return @c TRUE if the action belongs to an exclusive group.
   */
  CATBoolean GetExclusiveFlag() const;
  /**
   * @return @c TRUE if the action is checked, @c FALSE if it is unchecked.
   */
  CATBoolean GetCheckState() const;
  /**
   * Check or uncheck the action, in case the action is checkable. Does nothing
   * else. 
   *
   * @param i_bCheckState @c TRUE to check the action, @c FALSE to uncheck it.
   */
  void SetCheckState(CATBoolean i_bCheckState);
  /**
   * Toggle the check state of the action from @c TRUE to @c FALSE or from
   * @c FALSE to @c TRUE .
   */
  void Toggle();
  /**
   * Get the @c Activated event.
   *
   * The @c Activated event is emitted each time that the action is activated.
   *
   * If the action is in a group, it propagates to this group.
   *
   * @par EventProperties
   *   - Name: @c "Activated"
   *   - Type of propagation: @c OriginToRoot
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent * Activated();
  /**
   * Get the @c CheckStateChanged event.
   *
   * The @c CheckStateChanged event is emitted each time that the action
   * is checked or unchecked, ie. each time that the action state changes from
   * resp. @c FALSE to @c TRUE or @c TRUE to @c FALSE.
   *
    * If the action is in a group, it propagates to this group.
   *
   * @par EventProperties
   *   - Name: @c "CheckStateChanged"
   *   - Type of propagation: @c OriginToRoot
   *   - Type of argument: @ref CATVidToggleEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent * CheckStateChanged();

protected:
  /** Destructor. */
  virtual ~CATVidAction();
  /**
   * @copydoc CATVidAbstractActionGroup#SetGroup
   */
  virtual void SetGroup(CATVidAbstractActionGroup * i_pGroup);

private:
  /** Copy constructor. */
  CATVidAction(CATVidAction &);
  /** Copy operator. */
  CATVidAction& operator=(CATVidAction& original);
  /**
   * Set the check state of an action in a group without updating the check 
   * state of all the actions of said group. Only used in 
   * @ref CATVidActionGroup.
   *
   * @param i_bChecked the new check state.
   */
  void SetCheckStateFromGroup(CATBoolean i_bChecked);

private:
  /** 
   * See @ref #SetCheckableFlag .
   */
  CATBoolean _bCheckableFlag;
  /**
   * Check box or radio button is selected.
   */
  CATBoolean _bCheckState;
  /** @see #SetAcceleratorLabel */
  CATUnicodeString _sAcceleratorLabel;
};

//-----------------------------------------------------------------------------
#endif
