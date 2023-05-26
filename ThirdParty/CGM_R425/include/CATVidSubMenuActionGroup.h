// COPYRIGHT Dassault Systemes 2012
//=============================================================================
//
// CATVidActionGroup.h
// Header definition of CATVidActionGroup
//
//=============================================================================
//  Feb 2012  Creation: LD5
//=============================================================================
#ifndef CATVidSubMenuActionGroup_H
#define CATVidSubMenuActionGroup_H

#include <VisuDialog.h>
#include <CATVidAbstractActionGroup.h>
#include <CATVidSubMenuAction.h>

//-----------------------------------------------------------------------------

/** @ingroup groupVidMenu
 *
 * @see CATVidAbstractActionGroup
 */
class ExportedByVisuDialog CATVidSubMenuActionGroup : public CATVidAbstractActionGroup
{
  CATDeclareClass;

public:
  /**
   * Default constructor. 
   */
  CATVidSubMenuActionGroup();
  /**
   * Actions constructor.
   *
   * @param i_Actions actions of the group.
   */
  CATVidSubMenuActionGroup(const CATSYPDynArray<CATVidSubMenuAction*>& i_Actions);
  /** 
   * @copydoc CATVidAbstractActiongroup#AddAction 
   */
  CATBoolean AddAction(CATVidSubMenuAction * i_pAction);
  /** 
   * Appends submenu actions to the list of actions. @c AddRef will be called 
   * on all actions.
   *
   * @param i_Actions list of submenu actions to add.
   */
  CATBoolean AddActions(const CATSYPDynArray<CATVidSubMenuAction*>& i_Actions);
  /**
   * @param i_Actions list of actions to remove.
   *
   * @return @c TRUE if all actions have been successfully removed.
   */
  CATBoolean RemoveActions(const CATSYPDynArray<CATVidSubMenuAction*>& i_Actions);
  /**
   * @copydoc CATVidAbstractActionGroup#GetAction
   */
  CATVidSubMenuAction * GetAction(int i_idx) const;
protected:
  /**
   * Destructor.
   */
  virtual ~CATVidSubMenuActionGroup();

private:
  /** Copy constructor. */
  CATVidSubMenuActionGroup (CATVidSubMenuActionGroup&);
  /** Assignment operator. */
  CATVidSubMenuActionGroup& operator=(CATVidSubMenuActionGroup& original);
};

//-----------------------------------------------------------------------------
#endif
