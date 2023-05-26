// COPYRIGHT Dassault Systemes 2012
//=============================================================================
//
// CATVidActionGroup.h
// Header definition of CATVidActionGroup
//
//=============================================================================
//  Feb 2012  Creation: LD5
//=============================================================================
#ifndef CATVidActionGroup_H
#define CATVidActionGroup_H

#include <VisuDialog.h>
#include <CATVidAbstractActionGroup.h>
#include <CATVidAction.h>

//-----------------------------------------------------------------------------

/** @ingroup groupVidMenu
 *
 * Actions (@ref CATVidAction) can be gathered in groups to be made exclusive
 * (@see #GetExclusiveFlag).
 *
 * Please see @ref CATVidAbstractActionGroup for other group features.
 *
 * @see CATVidAction
 */
class ExportedByVisuDialog CATVidActionGroup : public CATVidAbstractActionGroup
{
  CATDeclareClass;

public:
  /** Index returned when an action is not in the group. */
  static const int NOT_IN_GROUP_IDX;

public:
  /**
   * Default constructor. 
   */
  CATVidActionGroup();
  /**
   * Actions constructor. 
   *
   * @param i_Actions actions of the group.
   */
  CATVidActionGroup(const CATSYPDynArray<CATVidAction*>& i_Actions);
  /** 
   * @copydoc CATVidAbstractActionGroup#AddAction 
   */
  CATBoolean AddAction(CATVidAction * i_pAction);
  /** 
   * Appends actions to the list of actions. @c AddRef will be called 
   * on all actions.
   *
   * @param i_Actions list of actions to add.
   */
  CATBoolean AddActions(const CATSYPDynArray<CATVidAction*>& i_Actions);
  /**
   * @param i_Actions list of actions to remove.
   *
   * @return @c TRUE if all actions have been successfully removed.
   */
  CATBoolean RemoveActions(const CATSYPDynArray<CATVidAction*>& i_Actions);
  /** 
   * @copydoc CATVidAbstractActionGroup#RemoveActionOfIndex 
   */
  virtual CATBoolean RemoveActionOfIndex(int i_iActIdx);
  /**
   * @copydoc CATVidAbstractActionGroup#GetAction
   */
  CATVidAction * GetAction(int i_idx) const;
  /**
   * By default, an action group is exclusive, meaning that there can be only
   * zero or one checked action at one time. When checking an action which has
   * been put inside a checkable group, last checked action, if any, is
   * automatically unchecked. Please note that you must make your actions
   * checkable, ie @ref CATVidAction#SetCheckableFlag to @c TRUE , before
   * being able to check them.
   *
   * A non-exclusive action group is useful to store checkable actions at one
   * single place ( see @ref #CATVidActionGroup ).
   * 
   * @return @c TRUE if the action group is exclusive (default), @c FALSE else.
   */
  CATBoolean GetExclusiveFlag() const;
  /**
   * @param i_bExclusiveFlag @c FALSE to allow several actions to be checked at
   * one time in the group (default is @c TRUE).
   *
   * @see #GetExclusiveFlag
   */
  void SetExclusiveFlag(CATBoolean i_bExclusiveFlag);
  /**
   * @return the index of currently checked action if @c ExclusiveFlag is
   * @c TRUE (default) and an action is checked, @ref #NOT_IN_GROUP_IDX else. 
   */
  int GetCheckedActionIdx() const;
  /**
   * Does nothing if the group is not exclusive. 
   * Else (default), toggles the checked action to the action of index
   * @c i_actIdx if @c i_actIdx is in <tt>[0,</tt> @ref #GetActionsNb 
   * <tt>]</tt>. Uncheck currently checked action else.
   */
  void SetCheckedActionIdx(int i_actIdx);
  /**
   * @return the currently checked action if @c ExclusiveFlag is @c TRUE 
   * (default) and an action is checked, @c NULL else.
   */
  CATVidAction * GetCheckedAction() const;
  /**
   * Does nothing if the group is not exclusive.
   * Else (default), checks the exclusive action. Equivalent to calling 
   * @ref CATVidAction#SetCheckFlag (TRUE) on the input action. 
   * 
   * @param i_pAction the action to check. If @c NULL, does nothing.
   */
  void SetCheckedAction(CATVidAction * i_pAction);

  /**
   * Get the @c CheckedActionChanged event.
   *
   * The @c CheckedActionChanged event is emitted only if the group is
   * exclusive, each time that a new action is checked, unchecking the
   * previously checked one, if any. It is not sent when the currently checked
   * action is unchecked or removed from the group, even if the 
   * @c CheckedAction property changes for @c NULL.
   *
   * @par EventProperties
   *   - Name: @c "CheckedActionChanged"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidActionChangedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent * CheckedActionChanged();

protected:
  /**
   * Destructor.
   */
  virtual ~CATVidActionGroup();
  /**
   * @return @c TRUE if the index corresponds to an action in the group (ie. is
   * in <tt>[0,</tt> @ref #GetActionsNb <tt>]</tt> ), @c FALSE else.
   */
  CATBoolean IsValidIdx(int i_actIdx) const;

private:
  /** Copy constructor. */
  CATVidActionGroup (CATVidActionGroup &);
  /** Assignment operator. */
  CATVidActionGroup& operator=(CATVidActionGroup&);
  /** 
  * Uncheck all remaining actions after the first found checked action. 
  */
  void UncheckAllActionsAfterFirstChecked();
  /**
   * Uncheck all actions of the group.
   */
  void UncheckAllActions();

private:
  /** 
   * If an action is part of an exclusive action group, it will be represented
   * by a radio button. If not, it will be represented by a check box.
   */
  CATBoolean _bExclusiveFlag;
  /** 
   * If the group is exclusive (ie. @ref #GetExclusiveFlag returns @c TRUE), 
   * the index of currently checked action. Else, @ref #NOT_IN_GROUP_IDX.
   */
  int _checkedActionIdx;
};

//-----------------------------------------------------------------------------
#endif
