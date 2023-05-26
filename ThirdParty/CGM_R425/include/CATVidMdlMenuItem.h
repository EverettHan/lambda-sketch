// COPYRIGHT Dassault Systemes 2012
//=============================================================================
//
// CATVidMdlMenuItem.h
// Header definition of CATVidMdlMenuItem
//
//=============================================================================
//  May 2012  Creation: LD5
//=============================================================================
#ifndef CATVidMdlMenuItem_H
#define CATVidMdlMenuItem_H

#include "VisuDialog.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATString.h"
#include "CATVidColor.h"
#include "CATString.h"
#include <nlohmann/json_fwd.hpp>

class CATVidWidget;
class CATVidAbstractAction;
class CATVidSubMenuAction;
class CATVidAction;
class CATVidMdlMenu;

/** @ingroup groupVidMenu
 *
 * Base class for menu items. Wraps data that can be put inside a menu,
 * adding a @c SelectedFlag to it. This flag is used by 
 * @c CATVidAbstractItemsView to handle selection. This class is only used
 * internally.
 *
 * @see CATVidMdlMenu
 */
class ExportedByVisuDialog CATVidMdlMenuItem : public CATBaseUnknown
{
  CATDeclareClass;

public:
  /** 
   * Type of the menu item. Gives indication about what kind of data must
   * be displayed in the menu view. 
   */
  enum ItemType {
    /** Menu item is a separator, not selectable in menu view. The menu item
    wraps no data as the separator is a purely visual item. */
    SeparatorItem=0, 
    /** Menu item is a header, not selectable in menu view. The data wrapped
    bu this item is a @c CATUnicodeString. */
    HeaderItem, 
    /** Menu item is an action item, selectable in menu view. The data wrapped 
    by this item is a @ref CATVidCtlAction. */
    ActionItem,
    /** Menu item is a submenu action item, selectable in menu view. The data 
    wrapped by this item is a @ref CATVidSubMenuAction. */
    SubMenuItem}; 

public:
  /**
   * Separator constructor. 
   *
   * @see #ItemType
   */
  CATVidMdlMenuItem();
  /**
   * Menu header constructor. 
   *
   * @param i_sHeader a header.
   *
   * @see #ItemType
   */
  CATVidMdlMenuItem(const CATUnicodeString& i_sHeader, const CATString& i_sRecordName);
  /**
   * Action or submenu item constructor.
   *
   * @param i_pAction the action that must be represented in the menu view.
   * Cannot be @c NULL. @c AddRef will be called on the pointer.
   *
   * @see #ItemType
   */
  CATVidMdlMenuItem(CATVidAbstractAction * i_pAction);
  /**
   * @return the type of the item.
   *
   * @see #ItemType
   */
  ItemType GetType() const;
  /**
   * Used by the @c CATVidCtlAbstractListView.
   *
   * @return @c TRUE if the item can be selected.
   */
  CATBoolean GetSelectableFlag() const;
  /**
   * Used by the @c CATVidCtlAbstractListView.
   *
   * @param i_bSelectableFlag @c FALSE to disallow selection of the menu item.
   */
  void SetSelectableFlag(CATBoolean i_bSelectableFlag);
  /**
   * Used by the @c CATVidCtlAbstractListView.
   *
   * @return i_bSelectedFlag @c TRUE when the item is selected, @c FALSE else.
   */
  CATBoolean GetSelectedFlag() const;
  /**
   * Used by the @c CATVidCtlAbstractListView.
   *
   * @param i_bSelectedFlag @c TRUE when the item is selected, @c FALSE else.
   */
  void SetSelectedFlag(CATBoolean i_bSelectedFlag);
  /**
   * Used by the @c CATVidCtlAbstractListView.
   *
   * @return @c TRUE if the item can be picked.
   */
  CATBoolean GetItemPickableFlag() const;
  /**
   * Used by the @c CATVidCtlAbstractListView.
   *
   * @param i_bItemPickableFlag @c FALSE to disallow pick on the menu item.
   */
  void SetItemPickableFlag(CATBoolean i_bItemPickableFlag);
  /**
   * @return a header in case the menu item type is @c MenuItem.
   *
   * @see #ItemType
   */
  CATUnicodeString GetHeader() const;
  /**
   * @return a not @c NULL widget in case the menu item type is @c ActionItem ,
   * or @ SubMenuItem, @c NULL else.
   *
   * @see #ItemType
   */
  CATVidAbstractAction * GetAbstractAction() const;
  /**
   * @return a not @c NULL widget in case the menu item type is @c ActionItem ,
   * @c NULL else.
   *
   * @see #ItemType
   */
  CATVidAction * GetAction() const;
  /**
   * @return a not @c NULL widget in case the menu item type is 
   * @c SubMenuActionItem , @c NULL else.
   *
   * @see #ItemType
   */
  CATVidSubMenuAction * GetSubMenuAction() const;
  /**
   * @return the name of the item, used for record if the item is pickable.
   */
  CATString GetRecordName() const;
  /**
   * @param i_sName the name of the item, used for record if the item is 
   * pickable.
   */
  void SetRecordName(const CATString& i_sName);
  /** 
   * Used for data binding. Asserts that @c ItemType is @c ActionItem or
   * @c SubMenuItem.
   * @copydoc CATVidAction#GetIcon 
   */
  CATUnicodeString GetIcon() const;
  /** 
   * Used for data binding.
   * @copydoc CATVidAction#SetIcon
   */
  void SetIcon(const CATUnicodeString& i_sIcon);
  /**
   * Used for data binding. Asserts that @c ItemType is @c ActionItem or
   * @c SubMenuItem.
   * @copydoc CATVidAction#GetText
   */
  CATUnicodeString GetText() const;
   /** 
   * Used for data binding. Asserts that @c ItemType is @c ActionItem or 
   * @c SubMenuItem.  
   * @copydoc CATVidAction#SetText
   */
  void SetText(const CATUnicodeString& i_sText);
  /** 
   * Used for data binding. Asserts that @c ItemType is @c ActionItem. 
   * @copydoc CATVidAction#GetAcceleratorLabel
   */
  CATUnicodeString GetAcceleratorLabel() const;
  /** 
   * Used for data binding. Asserts that @c ItemType is @c ActionItem. 
   * @copydoc CATVidAction#SetCheckState
   */
  void SetCheckState(CATBoolean i_bCheckState);
  /** 
   * Used for data binding. Asserts that @c ItemType is @c ActionItem. 
   * @copydoc CATVidAction#GetCheckState
   */
  CATBoolean GetCheckState() const;
  /** 
   * Used for data binding. Asserts that @c ItemType is @c ActionItem. 
   * @copydoc CATVidAction#GetCheckableFlag
   */
  CATBoolean GetCheckableFlag() const;
    /** 
   * Used for data binding. Asserts that @c ItemType is @c ActionItem. 
   * @copydoc CATVidAction#GetExclusiveFlag
   */
  CATBoolean GetExclusiveFlag() const;
  /** 
   * Used for data binding. Asserts that @c ItemType is @c ActionItem or 
   * @c SubMenuItem.
   * @copydoc CATVidAction#GetEnableState
   */
  void SetEnableState(CATBoolean i_bEnableState);
  /** 
   * Used for data binding. Asserts that @c ItemType is @c ActionItem or 
   * @c SubMenuItem.
   * @copydoc CATVidAction#GetEnableState
   */
  CATBoolean GetEnableState() const;
  /** 
   * Used for data binding with CATVidGPSquare#GetVisibleFlag.
   */
  CATBoolean GetIconState() const;
  /**
   * Used for A2X to  dumped menu item data into a JSON.
   */
  nlohmann::json DumpJSONStructure();
  /*
   * Used for A2X to identify if the MenuItem is a submenu action that is display a MdlMenu
   */
  CATBoolean IsFatherOf(const CATVidMdlMenu* pMdlMenu);

protected:
  /** Destructor. */
  virtual ~CATVidMdlMenuItem();

private:
  /**
   * Flag used by the @c CATVidCtlAbstractListView to disallow selection on the
   * item when the latter is selected in a menu.
   */
  CATBoolean _bSelectableFlag;
  /**
   * Flag used by the @c CATVidCtlAbstractListView to disallow selection on an 
   * item.
   */
  CATBoolean _bSelectedFlag;
  /**
   * Flag used by the @c CATVidCtlAbstractListView to disallow pick on an item.
   */
  CATBoolean _bItemPickableFlag;
  /**
   * @see #ItemType
   */
  ItemType _eType;
  /**
   * @see #GetAction
   */
  CATVidAbstractAction * _pAction;
  /**
   * @see #GetHeader
   */
  CATUnicodeString _sHeader;
  /**
   * @see #GetRecordName
   */
  CATString _sRecordName;
  /**
   * @see #SetText
   */
  CATUnicodeString _sText;
  /**
   * @see #SetEnableState
   */
  CATBoolean _bEnableState;
  /**
   * @see #SetIcon
   */
  CATUnicodeString _sIcon;


private:
  /** Copy constructor. */
  CATVidMdlMenuItem (CATVidMdlMenuItem &);
  /** Assignment operator. */
  CATVidMdlMenuItem& operator=(CATVidMdlMenuItem&);
  /** Check state of menu item.
  
  Cannot be simply connected to check state of the check box view as user can
  click either in the check box or anywhere in the menu item to check the action.

  Thus mouse clicks are catched at the level of the menu view and dealt with in
  @ref #CATVidMdlMenu.
  */
  CATBoolean _bCheckState;
};

//-----------------------------------------------------------------------------
#endif
