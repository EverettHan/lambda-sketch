#ifndef CATDLGBARMENU_H
#define CATDLGBARMENU_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATDlgMenu.h"

class CATString;
class CATDlgSubMenu;
class l_CATDlgBarMenu;

#ifndef CATDlgBarMenu_ADD
/** @nodoc */
#define CATDlgBarMenu_ADD
#endif

#ifndef CATDlgBarMenu_LateADD
/** @nodoc */
#define CATDlgBarMenu_LateADD
#endif

/** 
 * Base class for menu bar management.
 * <b>Role</b>:
 * The menu bar contains objects (instances of the CATDlgSubMenu class) to create pull-down menus.
 * They are generally named Start, File, Edit, View, Help or ?, and so forth.<br>
 * Use the menu bar to contain and display menus.
 * A menu bar parent must be an instance of a class that derives from the classes @href CATDlgDocument 
 * or @href CATDlgDialog. It can contain only one menu bar instance.<br>
 * Submenus are placed from left to right in the menu bar, in the order they are instantiated.
 */
class ExportedByDI0PANV2 CATDlgBarMenu : public CATDlgMenu
{

 public:

			/** 
			 * Constructs a CATDlgBarMenu.
			 * @param iParent
			 *   The parent of the bar menu.
			 * @param iObjectName
			 *   The name of the bar menu.
			 * @param iStyle
			 *   The style of the bar menu.
			 */
        CATDlgBarMenu( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        virtual ~CATDlgBarMenu();

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
        l_CATDlgBarMenu* _frameMenuBar;

    /** @nodoc */
    CATDlgBarMenu_ADD
};

/** @nodoc */
CATDlgBarMenu_LateADD

#endif
