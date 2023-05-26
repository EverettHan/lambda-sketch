#ifndef CATDLGTREE_H
#define CATDLGTREE_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//------------------------------------------------------------------------------
// Abstract: The base class for tree control - Windows only
//           This class is subject to heavy changes.
//
//------------------------------------------------------------------------------
// Usage:    Like any control, assign CATDlgTree to any container or window.
//------------------------------------------------------------------------------
// Inheritance: CATDlgTree
//                CATDlgControl
//                  CATDialog
//------------------------------------------------------------------------------
// Main methods:
//
//------------------------------------------------------------------------------
// Styles:
//
//------------------------------------------------------------------------------

//--------------------------------------------------------------------------
#include "CATDlgControl.h"

//#ifdef DRIVER_WINDOWS

//--------------------------------------------------------------------------
class CATString;
class l_CATDialog;
class l_CATDlgTree;



#include "CATDlgTreeItem.h"

#include "CATListPV.h"

//--------------------------------------------------------------------------

/**
 * Class to add a tree to a control.
 * <b>Role</b>: Adds a tree to a control.
 */

class ExportedByDI0PANV2 CATDlgTree : public CATDlgControl
{

//--------------------------------------------------------------------------
 public:

//      constructor - destructor
/**
 * Constructs a tree.
 * <br><b>Role</b>: Constructs a tree. 
 * @param iParent
 *   The parent class in the CATCommand agregation 
 *   hierarchy. 
 * @param iDialogObjectName
 *   The dialog object name. 
 * @param iStyle
 *   The application window styles. You can cumulate several
 *   styles using a logical or.
 */
        CATDlgTree( CATDialog *iParent, const CATString& iDialogObjectName, 
                     CATDlgStyle iStyle=NULL);
/**
 * @nodoc 
 */
        virtual ~CATDlgTree();

//      get internal object
/**
 * @nodoc 
 */
        virtual l_CATDialog* GetLetterObject();

//      resets the internal object.
/**
 * @nodoc 
 */
        virtual void ResetLetterObject();

/**
 * @nodoc
 * Requests the ClassName, IsA, and IsAKindOf methods to be created.
 */
        CATDeclareClass;

/**
 * Returns the number of items in the tree.
 * <br><b>Role</b>: Returns the number of items in the tree.
 */
        unsigned int GetCount();

/**

 * Set the selection state of an item.

 * <br><b>Role</b>: Set the selection state of an item.

 * @param iItem

 *   The item for which the selection state is set. 

 * @param iSelect

 *   The flag for selection. 

 */

        void SelectItem(CATDlgTreeItem * iItem, CATBoolean iSelect);



/**
 * Returns the current selected items in the tree.
 * <br><b>Role</b>: Returns the current selected item in the tree, this is a CATListPV of CATDlgTreeItem *
 */
        CATListPV GetSelectedItem();

/**
 * Returns the parent of an item in the tree.
 * <br><b>Role</b>: Returns the parent of an item in the tree.
 * @param iItem
 *   The item for which the parent is searched. 
 */
        CATDlgTreeItem * GetParentItem(CATDlgTreeItem * iItem);

/**
 * Inserts an item in the tree.
 * <br><b>Role</b>: Inserts an item in the tree.
 * @param iItemText
 *   The text of the item to insert. 
 * @param iItemParent
 *   The item will be inserted as a child of this item. 
 * @param iItemAfter
 *   The item will be inserted just after this item. 
 */
        CATDlgTreeItem * InsertItem(CATUnicodeString& iItemText, CATDlgTreeItem * iItemParent = CATDLGTREEITEMROOT, CATDlgTreeItem * iItemAfter = CATDLGTREEITEMLAST);

/**
 * Assigns data to an item in the tree.
 * <br><b>Role</b>: Assigns data to an item in the tree.
 * @param iItem
 *   The item for which the data is assigned. 
 * @param iData
 *   The data assigned to the item. 
 */
        void SetItemData(CATDlgTreeItem * iItem, CATBaseUnknown *iData);

/**
 * Returns the data assigned to an item in the tree.
 * <br><b>Role</b>: Returns the data assigned to an item in the tree.
 * @param iItem
 *   The item for which the data is returns. 
 */
        CATBaseUnknown * GetItemData(CATDlgTreeItem * iItem);

/**
 * Forces the tree to be invalidated and drawn.
 * <br><b>Role</b>: Forces the tree to be invalidated and drawn.
 */
        void Invalidate();

/**

 * Returns the event notification sent when an item is selected in the tree.

 */

        CATNotification *GetSelectItemNotification() const;


/**

 * Returns the event notification sent when an item is unselected in the tree.

 */

        CATNotification *GetUnselectItemNotification() const;



/**

 * Returns the event notification sent when all the items are unselected in the tree.

 */

        CATNotification *GetUnselectAllNotification() const;



//--------------------------------------------------------------------------
 private:

//      address of internal object.
/**
 * @nodoc 
 */
        l_CATDlgTree* _frameTree;
};
#endif
//#endif
