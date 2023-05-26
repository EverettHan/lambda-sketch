#ifndef CATDLGCHECKITEM_H
#define CATDLGCHECKITEM_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATDlgMenuItem.h"

class l_CATDlgCheckItem;

#ifndef CATDlgCheckItem_ADD
/** @nodoc */
#define CATDlgCheckItem_ADD
#endif

#ifndef CATDlgCheckItem_LateADD
/** @nodoc */
#define CATDlgCheckItem_LateADD
#endif

/** 
 * Base class for check menu items.
 * <b>Role</b>:
 * A check menu item is used to build menus and submenus and allows the user to set an option among 
 * several available options in a menu, a submenu, or a toolbar.
 * A check item has two states, "on" or "off". 
 * Selecting a check item sets its state to "on" if it was "off" or to "off" if it was "on", 
 * regardless the state of the other check items. So several check items can be in 
 * the state "on" while several others can be in the state "off". 
 * <br>
 * Use check items whenever you propose to the end user a choice among several inclusive options, 
 * that is when several options can be selected at the same time, in a menu, a submenu, a toolbar, or an icon box. 
 */
class ExportedByDI0PANV2 CATDlgCheckItem : public CATDlgMenuItem
{

 public:

			/** 
			 * Constructs a CATDlgCheckItem.
			 * @param iParent
			 *   The parent of the check item.
			 * @param iObjectName
			 *   The name of the check item.
			 * @param iStyle
			 *   The style of the check item.
			 */
        CATDlgCheckItem( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        virtual ~CATDlgCheckItem();

			/**
			 * Returns the state of the check item.
			 *   <br>
			 * The state of the check item can be.
			 *   <dl>
			 *   <dt><tt>CATDlgCheck</tt><dd> if the check item is checked,
			 *   <dt><tt>CATDlgUncheck</tt><dd> if it is unchecked.
			 *   </dl>
			 */
        CATULong  GetState();
			
			/**
			 * Sets the state of the check item.
			 * @param iState
			 * The state of the check item to set.
			 *   <br>
			 *   <b>Legal values</b> : It can be set to either :
			 *   <dl>
			 *   <dt><tt>CATDlgCheck</tt><dd> to check the check item,
			 *   <dt><tt>CATDlgUncheck</tt><dd> to uncheck it.
			 *   </dl>
			 * @param iNotify
			 * Set this parameter to a non null value if you want the corresponding notification to be sent.
			 * Otherwise set it to 0, so no notification will be sent. 
			 */
				void SetState( CATULong iState, int iNotify=1);

			/**
			 * Returns the event notification sent whenever the check item is checked or unchecked.
			 */
        CATNotification *GetChkIModifyNotification() const;

			/**
			 * @nodoc
			 * Returns the internal object.
			 */
        virtual l_CATDialog* GetLetterObject();

			/**
			 * @nodoc 
			 * Resets the internal object.
			 */
        virtual void ResetLetterObject();

       /**
        * @nodoc
        * Requests the ClassName, IsA, and IsAKindOf methods to be created.
        */
        CATDeclareClass ;

 private:

			/**
			 * @nodoc
			 * Address of the internal object.
			 */
        l_CATDlgCheckItem* _frameCheckItem;

        /** @nodoc */
        CATDlgCheckItem_ADD
};

/** @nodoc */
CATDlgCheckItem_LateADD

#endif
