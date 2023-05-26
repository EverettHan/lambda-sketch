#ifndef CATDLGSCROLLBAR_H
#define CATDLGSCROLLBAR_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "CATDlgControl.h"

class CATString;
class l_CATDlgScrollBar;
class CATDlgSYPInterval;

#ifndef CATDlgScrollBar_ADD
/** @nodoc */
#define CATDlgScrollBar_ADD
#endif

#ifndef CATDlgScrollBar_LateADD
/** @nodoc */
#define CATDlgScrollBar_LateADD
#endif

/** 
 * Base class for scale control.
 * <b>Role</b>:
 * This class allows the user to scroll a clipped object.
 * <br>
 * The scroll bar allows to set scrolling facilities to a scrollable dialog object.
 * A scroll bar consists in a field (a shaft) ended on both sides by a scroll arrow between
 * which an indicator (a scroll box, or thumb) shows the location of the data displayed with
 * respect to the whole data. A scroll bar can be horizontal or vertical.
 * <br>
 * Use scroll bar whenever you display areas that don't fit in the available space. 
 */
class ExportedByDI0PANV2 CATDlgScrollBar : public CATDlgControl
{

 public:

			/** 
			 * Constructs a CATDlgScrollBar.
			 * @param iParent
			 *   The parent of the scroll bar.
			 * @param iObjectName
			 *   The name of the scroll bar.
			 * @param iStyle
			 *   The style of the scroll bar.
			 * The style can be :
			 *   <dl>
			 *   <dt><tt>NULL</tt><dd> if no value is passed, for the default scroll bar, 
			 *   <dt><tt>CATDlgCtrHorizontal</tt><dd> for a horizontal scroll bar (this is the default), 
			 *   <dt><tt>CATDlgCtrVertical</tt><dd> for a vertical scroll bar.
			 *   </dl>
			 */
        CATDlgScrollBar( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        virtual ~CATDlgScrollBar();

			/**
			 * Sets the scroll box position.
			 * The scroll box position must be set in the range defined by the minimum and maximum values.
			 * @param iPosition
			 * The position to set for the scroll box.
			 * @param iNotify
			 * Set this parameter to a non null value if you want the corresponding notification to be sent.
			 * Otherwise set it to 0, so no notification will be sent. 
			 */
        int SetScrollPos( int iPosition, int iNotify = 1 );

			/**
			 * Returns the scroll box position.
			 */
        int GetScrollPos();

			/**
			 * Sets the minimum and maximum values for the scroll bar range.
			 * @param iMin
			 * The minimum value to set for the scroll bar range.
			 * @param iMax
			 * The maximum value to set for the scroll bar range.
			 */
        void  SetScrollRange( int iMin, int iMax);

			/**
			 * Retrieves the minimum and maximum values for the scroll bar range.
			 * @param oMin
			 * The returned minimum value for the scroll bar range.
			 * @param oMax
			 * The returned maximum value for the scroll bar range.
			 */
        void  GetScrollRange( int& oMin, int& oMax);

			/**
			 * Sets the scroll box size (number of displayed decimals).
			 * @param iSize
			 * The size to set for the scroll box.
			 */
        void  SetScrollBoxSize(int iSize);

			/**
			 * Returns the scroll box size (number of displayed decimals).
			 */
        int   GetScrollBoxSize();

			/**
			 * Returns the event notification sent whenever the scroll arrows or the shaft is clicked.
			 */
        CATNotification *GetScrollBarModifyNotification() const;

			/**
			 * Returns the event notification sent whenever the scroll box is dragged.
			 */
        CATNotification *GetScrollBarDragNotification() const;

				/**
				 * @nodoc 
				 * Returns the internal object.
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

				/**
				 * @nodoc 
		     * Address of the internal object.
				 */
        l_CATDlgScrollBar *_frameScrollBar;

        /** @nodoc */
        CATDlgScrollBar_ADD
};

/** @nodoc */
CATDlgScrollBar_LateADD

#endif
