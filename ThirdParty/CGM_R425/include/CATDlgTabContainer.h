#ifndef CATDLGTABCONTAINER_H
#define CATDLGTABCONTAINER_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATDlgBox.h"

class CATString;
class l_CATDlgTabContainer;
class CATDlgTabPage;
class CATNotification;

#ifndef CATDlgTabContainer_ADD
/** @nodoc */
#define CATDlgTabContainer_ADD
#endif

#ifndef CATDlgTabContainer_LateADD
/** @nodoc */
#define CATDlgTabContainer_LateADD
#endif

/**
 * Base class for managing <tt>CATDlgTabPages</tt>.
 */
class ExportedByDI0PANV2 CATDlgTabContainer : public CATDlgBox {
	public:

		/**
		 * Constructor.
		 * @param iParent
		 * The parent widget.
		 * @param iObjectName
		 * The internal name of the tab container.
		 * @param iStyle
		 * The style of the tab container.
		 * <br><b>Legal values:</b>Only the current default value is available.
		 */
        CATDlgTabContainer( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

		/**
		 * Destructor.
		 */
        virtual ~CATDlgTabContainer();

		/**
		 * Sets the selected <tt>CATDlgTabPage</tt>.
		 * @param iIndex
		 *  the index of the <tt>CATDlgTabPage</tt> to select.
		 * <br><b>Legal values:</b> The first <tt>CATDlgTabPage</tt> has index 0.
		 * @param iNotify
		 *  specifies whether the <tt>GetTabSelectNotification</tt> should be fired upon selection.
		 * <br><b>Legal values:</b>
		 * <dl>
		 * <dt><tt>0</tt><dd> do not fire the notification. </dd></dt>
		 * <dt><tt>not 0</tt><dd> fire the notification.</dd></dt>
		 * </dl>
		 */
        void SetSelectedPage(int iIndex, int iNotify=0);

		/**
		 * Sets the selected <tt>CATDlgTabPage</tt>.
		 * @param iPage
		 *  the <tt>CATDlgTabPage</tt> to select.
		 * @param iNotify
		 *  specifies whether the <tt>GetTabSelectNotification</tt> should be fired upon selection.
		 * <br><b>Legal values:</b>
		 * <dl>
		 * <dt><tt>0</tt><dd> do not fire the notification. </dd></dt>
		 * <dt><tt>not 0</tt><dd> fire the notification.</dd></dt>
		 * </dl>
		 */
        void SetSelectedPage(CATDlgTabPage *iPage, int iNotify=0);

		/**
		 * Gets the currently selected <tt>CATDlgTabPage</tt>.
		 * @return
		 *  the index of the currently selected <tt>CATDlgTabPage</tt>.
		 * <br><b>Legal values:</b> The first <tt>CATDlgTabPage</tt> has index 0.
		 */
        int GetSelectedPage();

		/**
		 * Gets the currently selected <tt>CATDlgTabPage</tt>.
		 * @return
		 *  the currently selected <tt>CATDlgTabPage</tt>.
		 */
		CATDlgTabPage *GetSelectedPagePtr();

		/**
		 * Gets the <tt>CATDlgTabPage</tt> at the specified index.
		 * @param iIndex
		 *  the index of the <tt>CATDlgTabPage</tt> to return.
		 * @return
		 *  the <tt>CATDlgTabPage</tt> at the specified index.
		 */
        CATDlgTabPage *GetPagePtr( int iIndex );


		/**
		 * Return count of <tt>CATDlgTabPages</tt> contained by the <tt>CATDlgTabContainer</tt>.
		 */
        int GetPageCount();

		/**
		 * Reorder the <tt>CATDlgTabPages</tt> contained by the <tt>CATDlgTabContainer</tt>.
		 * @param iNewPageOrder
		 *  an array of integers which describes at which position the <tt>CATDlgTabPages</tt>
		 *  currently at index <tt>0..iSize - 1</tt>should wind up.
		 * <br><b>Legal values:</b> The first <tt>CATDlgTabPage</tt> has index 0.
		 * @param iSize
		 *  the size of the <tt>iNewPageOrder</tt> integer array.
		 * @return
		 *  the currently selected <tt>CATDlgTabPage</tt>.
		 */
        void SwitchPages(int *iNewPageOrder, int iSize);

		/**
		 * Remove all <tt>CATDlgTabPages</tt> contained by the <tt>CATDlgTabContainer</tt>.
		 */
        void RemoveAllPages();

		/**
		 * Returns the event sent whenever the selected <tt>CATDlgTabPage</tt> changes.
		 */
		CATNotification *GetTabSelectNotification() const;

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
 	CATDeclareClass;

	private:

		/** @nodoc
		 * Address of internal object.
		 */
		l_CATDlgTabContainer* _frameTabContainer;

    /** @nodoc */
    CATDlgTabContainer_ADD
};

/** @nodoc */
CATDlgTabContainer_LateADD

#endif
