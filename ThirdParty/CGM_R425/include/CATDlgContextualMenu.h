#ifndef CATDLGCONTEXTUALMENU_H
#define CATDLGCONTEXTUALMENU_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATDlgMenu.h"

class CATString;
class CATDlgMenuItem;
class CATDlgSubMenu;
class l_CATDlgContextualMenu;

#ifndef CATDlgContextualMenu_ADD
/** @nodoc */
#define CATDlgContextualMenu_ADD
#endif

#ifndef CATDlgContextualMenu_LateADD
/** @nodoc */
#define CATDlgContextualMenu_LateADD
#endif

/** 
 * Base class for specifying an object's dependent menu.
 * <b>Role</b>:
 * The contextual menu is assigned to a given object, and can be accessed by 
 * right clicking the object. It is used to offer context-dependent capabilities
 * to the end-user. 
 * <p>
 * A contextual menu, like any other menu, is made of submenus, push items, 
 * check items, radio items, and separators.
 * Use contextual menus whenever you want the end user to be able to access commands
 * specific to the current object.
 */
class ExportedByDI0PANV2 CATDlgContextualMenu : public CATDlgMenu
{

 public:

/** 
 * Constructs a CATDlgContextualMenu.
 * @param iParent
 *   The parent of the contextual menu.
 * @param iObjectName
 *   The name of the contextual menu.
 * @param iStyle
 *   The style of the contextual menu.
 *   <br>
 *   <b>Legal values</b> : 
 *   <dl>
 *   <dt><tt>NULL</tt><dd> by default, if no value is passed in argument, the contextual menu content is permanent.
 *   <dt><tt>CATDlgCtxEmpty</tt><dd> the contextual menu content can be redefined with respect to 
 * the context. In this case, the contextual menu content is emptied whenever the menu is 
 * deactivated by the end user.
 *   </dl>
 */
        CATDlgContextualMenu( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

/**
 * @nodoc 
 * Destructor.
 */
        virtual ~CATDlgContextualMenu();

/**
 * @nodoc 
 */
        CATDialog* GetDialog();

/**
 * @nodoc 
 * Get the internal object.
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
        l_CATDlgContextualMenu *_frameContextualMenu;

    /** @nodoc */
    CATDlgContextualMenu_ADD
};

/** @nodoc */
CATDlgContextualMenu_LateADD

#endif
