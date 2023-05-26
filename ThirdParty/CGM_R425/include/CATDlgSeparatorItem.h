#ifndef CATDLGSEPARATORITEM_H
#define CATDLGSEPARATORITEM_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "CATDlgMenuItem.h"

class CATString;
class l_CATDlgSeparatorItem;

#ifndef CATDlgSeparatorItem_ADD
/** @nodoc */
#define CATDlgSeparatorItem_ADD
#endif

#ifndef CATDlgSeparatorItem_LateADD
/** @nodoc */
#define CATDlgSeparatorItem_LateADD
#endif

/** 
 * Base class for menu separators.
 * <b>Role</b>:
 * This class allows to group consistent menu items.
 * The separator item is used to leave thin vertical or horizontal empty areas between different items
 * in menus and toolbars to help better visualize the different parts of a menu, a submenu, a toolbar, or an icon box,
 * and to group related items in these parts.
 * <br>
 * Use separator items whenever you want to clearly separate groups of items in a menu, a submenu, a toolbar, or an icon box.
 */
class ExportedByDI0PANV2 CATDlgSeparatorItem : public CATDlgMenuItem
{

 public:

			/** 
			 * Constructs a CATDlgSeparatorItem.
			 * @param iParent
			 *   The parent of the menu separator.
			 * @param iObjectName
			 *   The name of the menu separator.
			 * @param iStyle
			 *   The style of the menu separator.
			 * The style can be :
			 *   <dl>
			 *   <dt><tt>NULL</tt><dd> if no value is passed, for the default menu separator, 
			 *   </dl>
			 */
        CATDlgSeparatorItem( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        virtual ~CATDlgSeparatorItem();

				/**
				 * @nodoc 
				 * Returns the internal object.
				 */
        virtual l_CATDialog* GetLetterObject();

				/** @nodoc 
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
        l_CATDlgSeparatorItem* _frameSeparator;

        /** @nodoc */
        CATDlgSeparatorItem_ADD
};

/** @nodoc */
CATDlgSeparatorItem_LateADD

#endif
