//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2012
//===================================================================
// CATVidMdlMenu.h
// Header definition of class CATVidMdlMenu
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2012/03/28 Creation: Code generated by the 3DS wizard  LD5
//===================================================================

#ifndef CATVidMdlMenu_H
#define CATVidMdlMenu_H

#include <VisuDialog.h>
#include <CATIVidMdl.h>
#include <CATVidCtlPopup.h>
#include <CATVidCtl.h>
#include <CATVidLayLayer.h>
#include <nlohmann/json_fwd.hpp>

class CATVidAction;
class CATVidMouseEventArgs;
class CATVidToggleEventArgs;
class CATVidCtl;
class CATVidAbstractAction;
class CATVidActionGroup;
class CATVidMdlMenuItem;
class CATVidMdlStandardList;
class CATVidCtlMenuView;
class CATVidMdlSelectionChangedEventArgs;
class CATVidCtlPopup;
class CATVidLayLayer;
class CATVidMdlItemViewBuiltEventArgs;

/**
 * @defgroup groupVidMenu VID Menus
 * This module contains the menu infrastructure of VID.
 */ 

/** @ingroup groupVidMenu
 *
 * Base menu class for all CID menus.
 *
 * @par
 * A @ref CATVidMdlMenu is a model class that deals with:
 * @li a model list storing the data of the menu, in which you can add actions
 * (user-defined commands), headers (title for a block of action), separators 
 * and submenus.
 * @li a view of the model list, built each time that displaying the menu is 
 * required (@ref #Display).
 *
 * @par Actions (CATVidAction)
 * An action is a user-defined command. In the menu view, it is represented by
 * a clickable menu entry. A single action can be added to several menus, but 
 * you must not add the same action twice in a single menu / submenus tree.
 * The @c RecordName of the action is the @c Name of the corresponding
 * widget (@ref CATVidAbstractAction#GetRecordName, @ref #AppendAction, 
 * @ref #AddAction). 
 *
 * @par Group of actions (CATVidActionGroup)
 * If you add an action to the menu, all actions that are currently in the
 * group will be individually added to the menu. 
 * 
 * @par Headers
 * A header is a menu entry that may be used to display a title before a block 
 * of actions. It cannot be interacted with in the menu view. If you want your
 * menu to be recordable, headers should be fed to the menu with a record name, 
 * which will be used to identify the header when a mouse event is received
 * (@ref #AppendHeader, @ref #AddHeader).
 *
 * @par
 * Separators are used to separate different blocks of actions. They cannot
 * be interacted with in the menu view.
 *
 * @par Submenus 
 * To make a submenu inside the menu, you must add an action with a submenu 
 * (@ref CATVidAction#SetMenu). When a menu entry representing an action
 * which contains such a submenu is clicked on or hovered inside the menu view, 
 * the submenu is opened. An action containing a submenu cannot be activated
 * through the menu view.
 *
 * @see CATVidAction
 * @see CATVidActionGroup
 */
class ExportedByVisuDialog CATVidMdlMenu : public CATBaseUnknown
{
CATDeclareClass;
friend class CATVidFraContextMenu;
friend class CATVidSubMenuAction;
friend class CATVidCtl;
friend class l_CATVidCtlSimpleCombo;//To change the contextual menu owner when line editor is updated during a contextual menu invokation.
public:
  /** Default Constructor. */
  CATVidMdlMenu();
  /**
  * Constructor.
  *
  * @param i_pOwner the control that this context menu refers to. Only a weak 
  * reference will be kept on the pointer.
  */
  CATVidMdlMenu(CATVidCtl * i_pOwner);
  /**
   * Append an action to the menu. @c AddRef will be called on the pointer.
   * 
   * @param i_pAction action that must be added to the menu. Must not be 
   * @c NULL.
   */
  void AppendAction(CATVidAbstractAction * i_pAction);
  /**
   * Insert an action in the menu. @c AddRef will be called on the pointer.
   * 
   * @param i_itemIdx position where the action must be inserted.  
   * @param i_pAction action to insert. Must not be @c NULL.
   */
  CATBoolean InsertAction(int i_itemIdx, CATVidAbstractAction * i_pAction);
  /**
   * Call @ref #AppendAction on all actions that are currently inside
   * @c i_pGroup. Does not @c AddRef the input pointer i_pGroup, but @c AddRef
   * all actions. 
   * 
   * @param i_pGroup a group of actions that must be added to the menu. Must
   * not be @c NULL.
   */
  void AppendActionsFromGroup(CATVidActionGroup * i_pGroup);
  /**
   * Insert all actions that are currently in @c i_pGroup in the menu. 
   * @c AddRef will not be called on the group, but will be called on all 
   * actions.
   * 
   * @param i_itemIdx position where the group of actions must be inserted.  
   * @param i_pAction group of actions to insert. Must not be @c NULL.
   */
  CATBoolean InsertActionsFromGroup(int i_itemIdx, CATVidActionGroup * i_pGroup);
  /**
   * Appends a header with an optional record name to the menu.
   *
   * @param i_sHeader text of the header.
   * @param i_sRecordName name that will be used to identify the header menu
   * item in CID record.
   */
  void AppendHeader(const CATUnicodeString& i_sHeader, const CATString& i_sRecordName = "");
  /**
   * Insert a header with an optional record name in the menu. 
   * 
   * @param i_itemIdx position where the header must be inserted.  
   * @param i_sHeader text of the header.
   * @param i_sRecordName name that will be used to identify the header menu
   * item in CID record.
   */
  CATBoolean InsertHeader(int i_itemIdx, const CATUnicodeString& i_sHeader, const CATString& i_sRecordName = "");
  /**
   * Append a separator to the menu. 
   */
  void AppendSeparator();
  /**
   * Insert a separator in the menu.
   * 
   * @param i_itemIdx the position where the separator must be inserted.
   */
  CATBoolean InsertSeparator(int i_itemIdx);
  /**
   * Asserts that <tt>0 < i_itemIdx < GetLength() - 1</tt> Removes the 
   * @c i_itemIdx -th menu item of the menu. 
   *
   * @param i_itemIdx the index of the menu item to remove.
   *
   * @return @c TRUE if the menu item has been removed, @c FALSE it the 
   * operation failed.
   */
  CATBoolean RemoveMenuItem(int i_itemIdx);
  /**
   * Remove all menu items.
   */
  void RemoveAll();
  /**
   * Asserts that <tt>0 < i_itemIdx < GetLength() - 1</tt>.
   *
   * @param i_itemIdx the index of the menu item to retreive
   *
   * @return the item at index <tt>CATVidModelIndex(i_itemIdx, 0, GetModel())
   * </tt> of the model list (@ref #GetModel). 
   */
  CATVidMdlMenuItem * GetMenuItem(int i_itemIdx);
  /**
   * @return the number of items in the menu (actions, separators, headers, 
   * submenu actions items).
   */
  int GetLength() const;
  /**
   * Display a popup containing the menu. 
   *
   * @see #Hide
   */
  void Display();
  /**
   * Hides the popup displaying the menu. Not called when the popup auto-hides.
   *
   * @see #Display
   */
  void Hide();
  /**
   * Hide the root menu of the tree of this menu. Hiding the root menu hide
   * all submenus.
   *
   * @see #Hide
   */
  void HideRootMenu();
  /**
   * Hide all submenus of this menu.
   *
   * @see #Hide
   */
  void HideAllSubMenus();
  /**
   * If this menu is a submenu, then it is contained in an action. The father
   * menu of said menu is the menu in which this action has been added to.
   *
   * @return the father of the menu in the model menu tree, @c NULL if this
   * menu is the root menu.
   */
  CATVidMdlMenu * GetFatherMenu() const;
  /**
   * @return the view of the model menu. If the view has not been built,
   * returns NULL.
   *
   * @see #BuildView
   */
  CATVidCtlMenuView * GetView() const;
  /**
   * @return the model menu: a list of @ref CATVidCtlMenuItem. 
   *
   * @see #BuildModel
   */
  CATVidMdlStandardList * GetModel() const;
  /**
   * Sets the RecordName, used to identify the window of the popup, especially when extracted.
   * @param i_sName the name of the menu, used for record.
   */
  void SetRecordName(const CATString& i_sName);
  CATString GetRecordName() const;

  /**
   * Activate the persistent flag to allow the menu view to stay on display
   * when the user clicks inside the view. On this case, the menu will
   * close exclusively on click outside the menu view.
   * Default value is @c FALSE.
   */
  CATBoolean GetPersistentFlag() const;
  /**
   * @param i_persistentFlag @c TRUE if the menu must not disappear on
   * click inside its view.
   * 
   * @see #GetPersistentFlag
   */
  void SetPersistentFlag(const CATBoolean & i_persistentFlag); 
    /**
   * @return the control that this context menu refers to.
   */
  CATVidCtl * GetOwner() const;
    /**
   * @param i_position the position of the context menu view inside the viewer 
   * returned by @ref #GetViewer().
   */
  void SetPosition(const CATMathPoint2Df& i_position);
  /**
   * Used for A2X to  dumped the sturcture of the model menu into a JSON.
   */
  nlohmann::json DumpJSONStructure();
  /**
   * Used for A2X to  dumped a model property.
   */
  nlohmann::json GetComputedPropertyInJSON(const std::string& i_propertyName) const;

protected:
  /** Destructor. */
  virtual ~CATVidMdlMenu();
    /**
   * Builds the menu model, a @ref CATVidMdlStandardList of 
   * @ref CATVidCtlMenuItem. 
   */
  virtual void BuildModel();
  /** 
   * Builds the view of the menu -- a @ref CATVidCtlMenuView -- from the menu
   * model.
   */
  virtual void BuildView();
  /**
   * @param i_pMenu the father of this menu in the model menu tree.
   * 
   * @see #GetFatherMenu
   */
  void SetFatherMenu(CATVidMdlMenu * i_pMenu);
  /**
   * @param i_pModel the menu model. 
   *
   * @see #GetModel
   */
  void SetModel(CATVidMdlStandardList * i_pModel); 
  /**
   * @param i_pView the view of the menu model.
   *
   * @see #GetView
   */
  void SetView(CATVidCtlMenuView * i_pView); 
  /**
   * Add all event handlers that must be alive while the menu is on display.
   */
  void AddViewEventHandlers();
  /**
   * Remove all event handlers added in @ref AddViewEventHandlers. 
   */
  void RemoveViewEventHandlers();
    /**
   * Callback function called when the menu is on display and the selection 
   * changes in the menu view.
   * 
   * @param i_pSender the @ref CATVidCtlAbstractItemsView that sent the 
   * @ref CATVidCtlAbstractItemsView#SelectionChanged event.
   * @param i_pArgs the arguments of the event.
   */
  void OnSelectionChanged(CATBaseUnknown * i_pSender, CATVidMdlSelectionChangedEventArgs * i_pArgs);
    /**
   * Callback function called when the menu is on display and the mouse is 
   * pressed inside one of the @ref CATVidGP of the menu view.
   * 
   * @param i_pSender the @ref CATVidGP that sent the @ref CATVidGP#MousePress 
   * event.
   * @param i_pArgs the arguments of the event.
   */
  void OnMousePress(CATBaseUnknown * i_pSender, CATVidMouseEventArgs * i_pArgs);
  /**
   * Callback function called when the menu is on display and the mouse is 
   * released inside one of the @ref CATVidGP of the menu view.
   * 
   * @param i_pSender the @ref CATVidGP that sent the 
   * @ref CATVidGP#MouseRelease event.
   * @param i_pArgs the arguments of the event.
   */
  void OnMouseRelease(CATBaseUnknown * i_pSender, CATVidMouseEventArgs * i_pArgs);
  /**
   * Callback function called each time that the view of a menu item has been
   * built.
   *
   * @param i_pSender the view of the menu
   * @param i_pArgs arguments in which the view of the menu item can be found
   */
  void OnItemViewBuilt(CATBaseUnknown * i_pSender, CATVidMdlItemViewBuiltEventArgs * i_pArgs);

  CATVidCtlPopup* GetChildMenuContainer();
  /**
   * @return The position of the context menu view inside the viewer returned 
   * by @ref #GetViewer().
   */
  const CATMathPoint2Df& GetPosition() const;

  virtual int GetPreventDisplayFlag() {return 0;}
private:
  /** Copy constructor. */
  CATVidMdlMenu (CATVidMdlMenu &);
  /** Assignment operator. */
  CATVidMdlMenu& operator=(CATVidMdlMenu&);
  /** Called when a submenu is (finally) open, to select corresponding entry on its father.*/
  void ForceSelectionToIndexOfCurrentlyDisplayedMenu();
  /** Allow to update the index of the item of the (finally) displayed sub-menu.*/
  void SetIndexOfCurrentlyDisplayedMenu(const CATVidMdlIndex& i_indexOfCurrentlyDisplayedMenu);
private:

  int IsMenuClicking();//to decide or not to give focus to line/text editor.
  /**
  * Control to which the context menu is bound to, if any.
  */
  CATBaseUnknown_WR _wrOwner;
  /** @see #GetPersistentFlag */
  int _persistentFlag;

  int _IsMenuClicking;

    /** @see #GetModel */
  CATVidMdlStandardList * _pModel;
  /** @see #GetView */
  CATBaseUnknown_WR _wrView;
  /** @see #GetFatherMenu */
  CATBaseUnknown_WR _wrFatherMenu;
  /** @see #OnSelectionChanged */
  CATSYPEventHandler * _pOnSelectionChangedEventHandler;
  /** @see #OnItemViewBuilt */
  CATSYPEventHandler * _pOnItemViewBuiltEventHandler;
  /** @see #OnMouseRelease */
  CATSYPEventHandler * _pOnReleaseEventHandler;
  /** @see #OnMousePress */
  CATSYPEventHandler * _pOnPressEventHandler;
    /**
   * @see #GetRecordName
  */
  CATString _sRecordName;

    /**
   * @param i_pOwner the control that this context menu refers to. A weak 
   * reference will be kept on the pointer.
   */
  void SetOwner(CATVidCtl * i_pOwner);

  CATVidCtlPopup *GetPopupForSubMenu() {return CAT_DYNAMIC_CAST(CATVidCtlPopup, (CATBaseUnknown*)(CATBaseUnknown_var(_popupForSubMenuWR)));}
  CATVidCtl *GetViewContainer() {return CAT_DYNAMIC_CAST(CATVidCtl, (CATBaseUnknown*)(CATBaseUnknown_var(_viewContainerWR)));}
  CATVidLayLayer *GetMainContainer() {return CAT_DYNAMIC_CAST(CATVidLayLayer, (CATBaseUnknown*)(CATBaseUnknown_var(_mainContainerWR)));}

  friend class l_CATVidEditorBase;
  friend class CATVidMenuDisplayer;
    /**
   * The position where the context menu will be displayed.
   */
  CATMathPoint2Df _position;
   /**
   * Index of the last item to have been selected. Needed because selection 
   * event is sent many times when a new index is selected.
   */
  CATVidMdlIndex _lastSelectedItem;
  CATVidMdlIndex _indexOfCurrentlyDisplayedMenu;
  CATBaseUnknown_WR _popupForSubMenuWR;
  //CATVidCtlPopup* _pPopupForSubMenu;
  CATBaseUnknown_WR _mainContainerWR;
  //CATVidLayLayer* _pMainContainer;
  CATBaseUnknown_WR _viewContainerWR;
  //CATVidCtl* _pViewContainer;
};

//-----------------------------------------------------------------------

#endif