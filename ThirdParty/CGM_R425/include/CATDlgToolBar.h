#ifndef CATDLGTOOLBAR_H
#define CATDLGTOOLBAR_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATDlgBar.h"

class CATString;
class l_CATDlgToolBar;
class CATDlgContextualMenu;

#ifndef CATDlgToolBar_ADD
/** @nodoc */
#define CATDlgToolBar_ADD
#endif

#ifndef CATDlgToolBar_LateADD
/** @nodoc */
#define CATDlgToolBar_LateADD
#endif

/**
 * Base class for dockable frames.
 * <b>Role:</b>Assign a CATDlgToolBar to a document window.
 */

class ExportedByDI0PANV2 CATDlgToolBar : public CATDlgBar {
	public:

		/**
		 * Constructor.
		 * @param iParent
		 * The parent widget.
		 * @param iObjectName
		 * The internal name of the toolbar.
		 * @param iStyle
		 * The style of the tab toolbar.
		 * <br><b>Legal values:</b>
		 * <dl>
		 * <dt><tt>CATDlgTlbDockOnBottom</tt><dd> The toolbar is anchored to the bottom of the window. </dd></dt>
		 * <dt><tt>CATDlgTlbDockOnLeft</tt><dd> The toolbar is anchored to the left of the window. </dd></dt>
		 * <dt><tt>CATDlgTlbDockOnRight</tt><dd> The toolbar is anchored to the right of the window. </dd></dt>
		 * <dt><tt>CATDlgTlbDockOnTop</tt><dd> The toolbar is anchored to the top of the window. </dd></dt>
		 * <dt><tt>CATDlgTlbUnDock</tt><dd> The toolbar has its own window. </dd></dt>
		 * </dl>
		 */
        CATDlgToolBar( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

		/**
		 * Destructor.
		 */
        virtual ~CATDlgToolBar();

		/**
		 * Dock or undock the toolbar.
		 * @param iState
		 * The style of the tab toolbar.
		 * <br><b>Legal values:</b>
		 * <dl>
		 * <dt><tt>CATDlgTlbDockOnBottom</tt><dd> The toolbar is anchored to the bottom of the window. </dd></dt>
		 * <dt><tt>CATDlgTlbDockOnLeft</tt><dd> The toolbar is anchored to the left of the window. </dd></dt>
		 * <dt><tt>CATDlgTlbDockOnRight</tt><dd> The toolbar is anchored to the right of the window. </dd></dt>
		 * <dt><tt>CATDlgTlbDockOnTop</tt><dd> The toolbar is anchored to the top of the window. </dd></dt>
		 * <dt><tt>CATDlgTlbUnDock</tt><dd> The toolbar has its own window. </dd></dt>
		 * </dl>
		 */
        CATULong SetDockState(CATULong iState);

		/**
		 * Returns whether the toolbar is docked on not.
		 * @return
		 * The style of the tab toolbar.
		 * <br><b>Legal values:</b>
		 * <dl>
		 * <dt><tt>CATDlgTlbDockOnBottom</tt><dd> The toolbar is anchored to the bottom of the window. </dd></dt>
		 * <dt><tt>CATDlgTlbDockOnLeft</tt><dd> The toolbar is anchored to the left of the window. </dd></dt>
		 * <dt><tt>CATDlgTlbDockOnRight</tt><dd> The toolbar is anchored to the right of the window. </dd></dt>
		 * <dt><tt>CATDlgTlbDockOnTop</tt><dd> The toolbar is anchored to the top of the window. </dd></dt>
		 * <dt><tt>CATDlgTlbUnDock</tt><dd> The toolbar has its own window. </dd></dt>
		 * </dl>
		 */
        CATULong GetDockState();

		/**
		 * Positions the toolbar.
		 * @param iX
		 * the x coordinate of the toolbar.
		 * @param iY
		 * the y coordinate of the toolbar.
		 */
        void SetFloatingPosition(int x, int y);

		/**
		 * Gets the position of the toolbar.
		 * @param iX
		 * the x coordinate of the toolbar.
		 * @param iY
		 * the y coordinate of the toolbar.
		 */
        void GetFloatingPosition( int& oX, int &oY);

		/**
		 * Returns the event notification sent whenever the toolbar is closed.
		 */
        CATNotification *GetWindCloseNotification() const;

		/**
		 * Returns the event notification sent whenever the toolbar is docked.
		 */
        CATNotification *GetWindDockNotification() const;

		/**
		 * Returns the event notification sent whenever the toolbar buttons are pressed.
		 */
        CATNotification *GetToolBarMButtonNotification() const;

		/**
		 * Returns contextual menu associated with the toolbar.
		 */
        CATDlgContextualMenu* GetContextualMenu();

		/** @nodoc
		 * Enables/Disables docking.
		 */
        void SetDockMode(CATBool iDockable);

		/** @nodoc
		 * Gets the docking capability.
		 */
        CATBool GetDockMode();

		/** @nodoc
		 * Cleans the associated settings.
		 */
        void CleanSettings();

		/** @nodoc
		 * Sets the lock property for all toolbars.
		 */
        static void LockToolBars(CATBool iLock);

		/** @nodoc
		 * Gets the lock property for all toolbars.
		 */
        static CATBool ToolBarsAreLocked();

		/** @nodoc
		 * Highlights the toolbar.
		 */
        void Highlight();

		/** @nodoc
		 * Docks/Dedocks the toolbar.
		 */
        void Dock(CATBool iDock);

		/** @nodoc
		 * Sets the number of icons per row in the toolbar.
		 */
        void SetNumIconPerRow(int iNum);

		/** @nodoc
		 * Gets the number of icons per row in the toolbar.
		 */
        int GetNumIconPerRow();

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
        l_CATDlgToolBar* _frameToolBar;

		/** @nodoc
		 * lock property.
		 */
        static CATBool _ToolBarsAreLocked;

        /** @nodoc */
        CATDlgToolBar_ADD
};

/** @nodoc */
CATDlgToolBar_LateADD

#endif
