// COPYRIGHT Dassault Systemes 2012
//=============================================================================
//
// CATVidAbstractActionGroup.h
// Header definition of CATVidAbstractActionGroup
//
//=============================================================================
//  Feb 2012  Creation: LD5
//=============================================================================
#ifndef CATVidAbstractActionGroup_H
#define CATVidAbstractActionGroup_H

#include <VisuDialog.h>
#include <CATUnicodeString.h>
#include <CATVidURL.h>
#include <CATMathPoint2Df.h>
#include <CATSYPArray.h>
#include <CATVidActionBase.h>
#include <CATVidAbstractAction.h>
#include <CATBoolean.h>

//-----------------------------------------------------------------------------

/** @ingroup groupVidMenu
 *
 * Actions (@ref CATVidAbstractAction) can be gathered in groups of actions 
 * when actions are of compatible type (see @ref CATVidAbstractActionGroup, 
 * @ref CATVidSubMenuActionGroup...). 
 *
 * This allow group storage, group enabling, and some type-specific group
 * behaviour.
 *
 * @par Group / action parenting
 * An action must not be in two groups at once. Symetrically, a group must not 
 * contain the same action twice.
 *
 * @par Memory
 * If you want to keep a reference on a group of actions, you must own a 
 * reference on this group. In other words:
 *
 * @code
 * CATVidAction * pAction1 = new CATVidAction();
 * CATVidAction * pAction2 = new CATVidAction();
 * CATVidActionGroup * pGroup = new CATVidActionGroup();
 * pGroup->AddAction(pAction1);
 * pGroup->AddAction(pAction2);
 *
 * // Releasing pAction2:
 * CATSysReleasePtr(pAction2); 
 * // Action2 can be recovered, because we own a pointer on the group:
 * pAction2 = pGroup->GetAction(2);
 *
 * // Now, if we release the group:
 * CATSysReleasePtr(pGroup);
 *
 * // The released group is lost:
 * CHECK_TRUE(pAction1->GetGroup() == NULL);
 * // pAction2 is also lost.
 * @endcode
 */
class ExportedByVisuDialog CATVidAbstractActionGroup : public CATVidActionBase
{
  CATDeclareClass;

public:
  /** Index returned when an action is not in the group. */
  static const int NOT_IN_GROUP_IDX;

public:
    /** 
   * @return the number of action in the group. 
   */
  int GetActionsNb() const;
  /**
   * If a group of actions is disabled, all actions of the group are disabled.
   * If a group of actions is enabled, individual actions can still be disabled
   * with @ref CATVidAction#SetEnableFlag .
   * 
   * @return @c TRUE if the group of actions is enabled (default), @c FALSE if 
   * it is disabled.
   */
  CATBoolean GetEnableFlag() const;
  /**
   * By default, the action group is enabled, meaning that actions are enabled
   * unless their own enable flag is @c FALSE (@ref CATVidAction#EnableFlag).
   *
   * @param @c FALSE to disabled all actions in the group.
   *
   * @see #GetEnableFlag
   */
  void SetEnableFlag(CATBoolean i_bEnableFlag);
  /** 
   * Remove an action from the list of actions. 
   * @c Release will be called on the action. 
   *
   * @param i_pAction the action to remove.
   *
   * @return @c TRUE if the remove succeeded, @c FALSE if the action has not 
   * been found.
   */
  CATBoolean RemoveAction(CATVidAbstractAction * i_pAction);
  /** 
   * Remove an action from the list of actions. 
   * @c Release will be called on the action. 
   * 
   * @param i_iActIdx the index of the action to remove.
   *
   * @return @c TRUE if the remove succeeded.
   * Asserts that:
   * @code
   * 0 < i_idx < GetActionsNb();
   * @endcode
   */
  virtual CATBoolean RemoveActionOfIndex(int i_iActIdx);
  /**
   * Remove all action.
   */
  void RemoveAll();
  /**
   * Gets the i_idx-th action of the group.<br/>
   *
   * Asserts that 
   * @code
   * 0 < i_idx < GetActionsNb();
   * @endcode
   * and that the returned action is not @c NULL.
   * You must not @c Release the returned action.
   *
   * @return the <tt>i_idx</tt>-th action of the group.
   */
  CATVidAbstractAction * GetAction(int i_idx) const;

protected:
  /**
   * Default constructor. 
   */
  CATVidAbstractActionGroup();
  /**
   * Destructor.
   */
  virtual ~CATVidAbstractActionGroup();
  /** 
   * Appends an action to the list of actions. 
   *
   * @c AddRef will be called on the action. 
   */
  CATBoolean AddAction(CATVidAbstractAction * i_pAction);
  /**
   * @return @c TRUE if the index corresponds to an action in the group (ie. is
   * in <tt>[0,</tt> @ref #GetActionsNb <tt>]</tt> ), @c FALSE else.
   */
  CATBoolean IsValidIdx(int i_actIdx) const;
  /**
   * @param i_pAction the index of the action whose index must be looked for.
   * 
   * @return @c the action index if @c i_pAction is in the group, 
   * @ref #NOT_IN_GROUP_IDX else.
   */
  int FindActionIdx(CATVidAbstractAction * i_pAction) const;

private:
  /** Copy constructor. */
  CATVidAbstractActionGroup (CATVidAbstractActionGroup &);
  /** Assignment operator. */
  CATVidAbstractActionGroup& operator=(CATVidAbstractActionGroup&);
  /**
   * The list of actions contained in the group.
   */
  CATSYPDynArray<CATVidAbstractAction*> _Actions;
  /**
   * @c FALSE to disable all actions of the group; @c TRUE to disable them
   * one by one if needed.
   */
  CATBoolean _bEnableFlag;
};

//-----------------------------------------------------------------------------
#endif
