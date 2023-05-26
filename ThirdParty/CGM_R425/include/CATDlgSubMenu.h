#ifndef CATDLGSUBMENU_H
#define CATDLGSUBMENU_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATDlgMenu.h"

class CATString;
class l_CATDlgSubMenu;

#ifndef CATDlgSubMenu_ADD
/** @nodoc */
#define CATDlgSubMenu_ADD
#endif

#ifndef CATDlgSubMenu_LateADD
/** @nodoc */
#define CATDlgSubMenu_LateADD
#endif

/**
 * Base class for submenus.
 * <b>Role:</b>Assign a <tt>CATDlgSubMenu</tt> to a menu bar.
 */
class ExportedByDI0PANV2 CATDlgSubMenu : public CATDlgMenu {

	public:

		/**
		 * Constructor.
		 * @param iParent
		 * The parent widget.
		 * @param iObjectName
		 * The internal name of the submenu.
		 * @param iStyle
		 * The style of the submenu.
		 * <b>Legal values:</b>
		 * <dl>
		 * <dt><tt>default</tt><dd> The menu cannot be detached from its parent menu. </dd></dt>
		 * <dt><tt>CATDlgMnuPinnable</tt><dd> The menu can be detached from its parent menu. 
		 * This style is ignored on Windows.</dd></dt>
		 * <dt><tt>CATDlgMnuHelp</tt><dd> The menu is positionned at the rightmost position
		 * in the menu bar.</dd></dt>
		 * </dl>
		 */
		CATDlgSubMenu( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

		/**
		 * Destructor.
		 */
		virtual ~CATDlgSubMenu();

		/** @nodoc
		 * Get internal object.
		 */
		virtual l_CATDialog* GetLetterObject();

		/** @nodoc 
		 * Resets internal object.
		 */
		 virtual void ResetLetterObject();

       /**
        * @nodoc
        * Requests the ClassName, IsA, and IsAKindOf methods to be created.
        */
        CATDeclareClass ;
	private:

		/** @nodoc
		 * Address of internal object.
		 */
		l_CATDlgSubMenu *_frameSubMenu;

    /** @nodoc */
    CATDlgSubMenu_ADD
};

/** @nodoc */
CATDlgSubMenu_LateADD

#endif

