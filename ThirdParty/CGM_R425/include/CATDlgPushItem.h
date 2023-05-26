#ifndef CATDLGPUSHITEM_H
#define CATDLGPUSHITEM_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "CATDlgMenuItem.h"

class CATString;
class l_CATDlgPushItem;

#ifndef CATDlgPushItem_ADD
/** @nodoc */
#define CATDlgPushItem_ADD
#endif

#ifndef CATDlgPushItem_LateADD
/** @nodoc */
#define CATDlgPushItem_LateADD
#endif

/**
 * Base class for menu items.
 * <b>Role:</b>Assign a CATDlgPushItem to any menu.
 */
class ExportedByDI0PANV2 CATDlgPushItem : public CATDlgMenuItem {

	public:

		/**
		 * Constructor.
		 * @param iParent
		 * The parent widget.
		 * @param iObjectName
		 * The internal name of the menu item.
		 * @param iStyle
		 * The style of the menu item.
		 * <b>Legal values:</b>Only the current default value is available.
		 */
		CATDlgPushItem( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

		/**
		 * Destructor.
		 */
		virtual ~CATDlgPushItem();

		/**
		 * Returns the event notification sent whenever the menu item is activated.
		 */
		CATNotification *GetMenuIActivateNotification() const;

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
		l_CATDlgPushItem* _frameItem;

    /** @nodoc */
    CATDlgPushItem_ADD
};

/** @nodoc */
CATDlgPushItem_LateADD

#endif
