#ifndef CATDLGTABPAGE_H
#define CATDLGTABPAGE_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */


#include "CATDlgBox.h"

class CATString;
class CATDlgTabContainer;
class l_CATDlgTabPage;

#ifndef CATDlgTabPage_ADD
/** @nodoc */
#define CATDlgTabPage_ADD
#endif

#ifndef CATDlgTabPage_LateADD
/** @nodoc */
#define CATDlgTabPage_LateADD
#endif

/**
 * Base class for pages in a <tt>CATDlgTabContainer</tt>.
 */
class ExportedByDI0PANV2 CATDlgTabPage : public CATDlgBox {

	public:

		/**
		 * Constructor.
		 * @param iParent
		 * The parent widget.
		 * @param iObjectName
		 * The internal name of the tab page.
		 * @param iStyle
		 * The style of the tab page.
		 * <br><b>Legal values:</b>
		 * <ul>
		 * <li><tt>default</tt>: The layout of the page is done using tabulations</li>
		 * <li><tt>CATDlgGridLayout</tt>: The layout of the page is done with a grid</li>
		 * </ul>
		 */
        CATDlgTabPage( CATDlgTabContainer *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

		/**
		 * Destructor.
		 */
        virtual ~CATDlgTabPage();

		/** @nodoc
		 * Get internal object.
		 */
        virtual l_CATDialog* GetLetterObject();

		/** @nodoc 
		 * Resets internal object.
		 */
         virtual void ResetLetterObject();

		/**
		 * Sets the default orientation of the page.
		 * @param iOrient
		 *  a constant describing the orientation of the page.
		 * <br><b>Legal values:</b>
		 * <dl>
		 * <dt><tt>Vertical</tt><dd> The contained widgets will be positionned along a vertical line. </dd></dt>
		 * <dt><tt>Horizontal</tt><dd> The contained widgets will be positionned along an horizontal line.</dd></dt>
		 * </dl>
		 */
        void SetDefaultOrientation(Orientation iOrient) ;

		/**
		 * Returns the orientation of the page.
		 * @return
		 *  a constant describing the orientation of the page.
		 * <br><b>Legal values:</b>
		 * <dl>
		 * <dt><tt>Vertical</tt><dd> The contained widgets will be positionned along a vertical line. </dd></dt>
		 * <dt><tt>Horizontal</tt><dd> The contained widgets will be positionned along an horizontal line.</dd></dt>
		 * </dl>
		 */
        Orientation GetDefaultOrientation() ;

		/**
		 * Causes any resizing of the tab page to be transmitted to the supplied child widget.
		 * @param iDialog
		 * the widget to resize when the tab page is resized.
		 */
        void Attach4Sides(CATDialog *iDialog) ;

		/**
		 * Removes all the attachments which cause the supplied child widget to be resized
		 * when the tab page is resized.
		 * @param iDialog
		 * the widget to detach from the tab page.
		 */
        void ResetAttachment(CATDialog *iDialog) ;


		/**
		 * Attaches one or many child widgets to an invisible horizontal tabulation. 
		 * <br><b>Role:</b>
		 * <br>Use this method to specify the way widgets should be positionned and 
		 * resized when the tab page is resized.
		 * @param iIndex
		 * an integer which identifies the tabulation.
		 * @param iAttachment
		 * a constant which specifies the position of the widgets with respect to the tabulation.
		 * <br><b>Legal values:</b>
		 * <dl>
		 * <dt><tt>CATDlgUnspecified</tt><dd> The position of the widget with respect to the tabulation is left unspecified. </dd></dt>
		 * <dt><tt>CATDlgTopOrLeft</tt><dd> The left side of the widget is aligned on the tabulation. 
		 * The tabulation does not move when the tab page is resized.</dd></dt>
		 * <dt><tt>CATDlgTopOrLeftRelative</tt><dd> The left side of the widget is aligned on the tabulation. 
		 * The tabulation moves to accomodate the resizing of the tab page.</dd></dt>
		 * <dt><tt>CATDlgRightOrBottom</tt><dd> The right side of the widget is aligned on the tabulation.
		 * The tabulation does not move when the tab page is resized.</dd></dt>
		 * <dt><tt>CATDlgRightOrBottomRelative</tt><dd> The right side of the widget is aligned on the tabulation.
		 * The tabulation moves to accomodate the resizing of the tab page.</dd></dt>
		 * <dt><tt>CATDlgCenter</tt><dd> The widget is centered on the tabulation.
		 * The tabulation does not move when the tab page is resized.</dd></dt>
		 * <dt><tt>CATDlgCenterRelative</tt><dd> The widget is centered on the tabulation.
		 * The tabulation moves to accomodate the resizing of the tab page.</dd></dt>
		 * </dl>
		 * @param iFirstDialog
		 * the first widget of a variable list of child widgets to attach to the tabulation.
		 */
        void SetHorizontalAttachment(CATDlgTabIndex iIndex,
                            CATDlgAttachment iAttachment, CATDialog *iFirstDialog, ...);

		/**
		 * Attaches one or many child widgets to an invisible vertical tabulation. 
		 * <br><b>Role:</b>
		 * <br>Use this method to specify the way widgets should be positionned and 
		 * resized when the tab page is resized.
		 * @param iIndex
		 * an integer which identifies the tabulation.
		 * @param iAttachment
		 * a constant which specifies the position of the widgets with respect to the tabulation.
		 * <br><b>Legal values:</b>
		 * <dl>
		 * <dt><tt>CATDlgUnspecified</tt><dd> The position of the widget with respect to the tabulation is left unspecified. </dd></dt>
		 * <dt><tt>CATDlgTopOrLeft</tt><dd> The top side of the widget is aligned on the tabulation. 
		 * The tabulation does not move when the tab page is resized.</dd></dt>
		 * <dt><tt>CATDlgTopOrLeftRelative</tt><dd> The top side of the widget is aligned on the tabulation. 
		 * The tabulation moves to accomodate the resizing of the tab page.</dd></dt>
		 * <dt><tt>CATDlgRightOrBottom</tt><dd> The bottom side of the widget is aligned on the tabulation.
		 * The tabulation does not move when the tab page is resized.</dd></dt>
		 * <dt><tt>CATDlgRightOrBottomRelative</tt><dd> The bottom side of the widget is aligned on the tabulation.
		 * The tabulation moves to accomodate the resizing of the tab page.</dd></dt>
		 * <dt><tt>CATDlgCenter</tt><dd> The widget is centered on the tabulation.
		 * The tabulation does not move when the tab page is resized.</dd></dt>
		 * <dt><tt>CATDlgCenterRelative</tt><dd> The widget is centered on the tabulation.
		 * The tabulation moves to accomodate the resizing of the tab page.</dd></dt>
		 * </dl>
		 * @param iFirstDialog
		 * the first widget of a variable list of child widgets to attach to the tabulation.
		 */
        void SetVerticalAttachment  (CATDlgTabIndex iIndex,
                            CATDlgAttachment iAttachment, CATDialog *iFirstDialog, ...);


		/**
		 * Returns the vertical tabulation on which a widget is attached.
		 * @param iDialog
		 * the attached child widget.
		 * @param iAttachment
		 * the type of attachment of the widget.
		 * @return
		 * an integer which identifies the tabulation.
		 */
        int GetVerticalTabIndex(CATDialog *iDialog, CATDlgAttachment iAttachment);

		/**
		 * Returns the horizontal tabulation on which a widget is attached.
		 * @param iDialog
		 * the attached child widget.
		 * @param iAttachment
		 * the type of attachment of the widget.
		 * @return
		 * an integer which identifies the tabulation.
		 */
        int GetHorizontalTabIndex(CATDialog *iDialog, CATDlgAttachment iAttachment);

		/**
		 * Adds a child widget to an existing horizontal tabulation.
		 * @param iIndex
		 * an integer which identifies the tabulation.
		 * @param iDialog
		 * the widget to attach to the tabulation.
		 * @param iReferenceDialog
		 * a reference widget which is already aligned on the tabulation.
		 * @param iMode
		 * a constant describing the insertion mode.
		 * <br><b>Legal values:</b>
		 * <dl>
		 * <dt><tt>After</tt><dd> the widget is inserted after the reference widget.</dd></dt>
		 * <dt><tt>Before</tt><dd> the widget is inserted before the reference widget.</dd></dt>
		 * </dl>
		 */
        void InsertAlongHorizontalTab(CATDlgTabIndex iIndex, CATDialog *iDialog,
                                     CATDialog *iReferenceDialog, InsertionMode iMode);
		/**
		 * Adds a child widget to an existing vertical tabulation.
		 * @param iIndex
		 * an integer which identifies the tabulation.
		 * @param iDialog
		 * the widget to attach to the tabulation.
		 * @param iReferenceDialog
		 * a reference widget which is already aligned on the tabulation.
		 * @param iMode
		 * a constant describing the insertion mode.
		 * <br><b>Legal values:</b>
		 * <dl>
		 * <dt><tt>After</tt><dd> the widget is inserted after the reference widget.</dd></dt>
		 * <dt><tt>Before</tt><dd> the widget is inserted before the reference widget.</dd></dt>
		 * </dl>
		 */
        void InsertAlongVerticalTab(CATDlgTabIndex iIndex, CATDialog *iDialog,
                                     CATDialog *iReferenceDialog, InsertionMode iMode);

		/**
		 * Detaches a child widget of the tab page from an horizontal tabulation.
		 * @param iIndex
		 * an integer which identifies the tabulation.
		 * @param iDialog
		 * the widget to detach from the tabulation.
		 */
        void RemoveAlongHorizontalTab(CATDlgTabIndex iIndex, CATDialog *iDialog);

		/**
		 * Detaches a child widget of the tab page from an vertical tabulation.
		 * @param iIndex
		 * an integer which identifies the tabulation.
		 * @param iDialog
		 * the widget to detach from the tabulation.
		 */
        void RemoveAlongVerticalTab  (CATDlgTabIndex iIndex, CATDialog *iDialog);

		/**
		 * Positions a child widget at the position previously held by another child widget.
		 * @param iNewDialog
		 * the child widget to position.
		 * @param iOldDialog
		 * the child widget whose position will be occupied <tt>iNewDialog</tt>.
		 */
        void ReplaceKeepAttachments(CATDialog *iNewDialog, CATDialog *iOldDialog);


		/**
		 * Sets whether a grid column can be resized or not.
		 * <br><b>Precondition</b>: the <tt>CATDlgTabPage</tt> must use the <tt>CATDlgGridLayout</tt> style. 
		 * @param iIndex
		 * the index of the grid column.
		 * @param iState
		 * a constant describing the resizing policy for the column.
		 * <br><b>Legal values:</b>
		 * <dl>
		 * <dt><tt>0</tt><dd> the column has a fixed size. </dd></dt>
		 * <dt><tt>1</tt><dd> the column is resized when the tab page is resized.</dd></dt>
		 * </dl>
		 */
        void SetGridColumnResizable(short int iIndex, int iState=1);

		/**
		 * Sets whether a grid row can be resized or not.
		 * <br><b>Precondition</b>: the <tt>CATDlgTabPage</tt> must use the <tt>CATDlgGridLayout</tt> style. 
		 * @param iIndex
		 * the index of the grid row.
		 * @param iState
		 * a constant describing the resizing policy for the row.
		 * <br><b>Legal values:</b>
		 * <dl>
		 * <dt><tt>0</tt><dd> the row has a fixed size. </dd></dt>
		 * <dt><tt>1</tt><dd> the row is resized when the tab page is resized.</dd></dt>
		 * </dl>
		 */
        void SetGridRowResizable(short int iIndex, int iState=1);

		/**
		 * Returns whether a grid column can be resized or not.
		 * <br><b>Precondition</b>: the <tt>CATDlgTabPage</tt> must use the <tt>CATDlgGridLayout</tt> style. 
		 * @param iIndex
		 * the index of the grid column.
		 * @return
		 * a constant describing the resizing policy for the column.
		 * <br><b>Legal values:</b>
		 * <dl>
		 * <dt><tt>0</tt><dd> the column has a fixed size. </dd></dt>
		 * <dt><tt>1</tt><dd> the column is resized when the tab page is resized.</dd></dt>
		 * </dl>
		 */
        int IsGridColumnResizable(short int iIndex);

		/**
		 * Returns whether a grid row can be resized or not.
		 * <br><b>Precondition</b>: the <tt>CATDlgTabPage</tt> must use the <tt>CATDlgGridLayout</tt> style. 
		 * @param iIndex
		 * the index of the grid row.
		 * @return
		 * a constant describing the resizing policy for the row.
		 * <br><b>Legal values:</b>
		 * <dl>
		 * <dt><tt>0</tt><dd> the row has a fixed size. </dd></dt>
		 * <dt><tt>1</tt><dd> the row is resized when the tab page is resized.</dd></dt>
		 * </dl>
		 */
        int IsGridRowResizable(short int iIndex);

       /**
        * @nodoc
        * Requests the ClassName, IsA, and IsAKindOf methods to be created.
        */
        CATDeclareClass ;

	private:

		/** @nodoc
		 * Address of internal object.
		 */
        l_CATDlgTabPage* _frameTabPage;

        /** @nodoc */
        CATDlgTabPage_ADD
};

/** @nodoc */
CATDlgTabPage_LateADD

#endif
