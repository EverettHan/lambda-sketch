#ifndef CATDLGCHECKBUTTON_H
#define CATDLGCHECKBUTTON_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATDlgControl.h"

class CATString;
class l_CATDialog;
class l_CATDlgCheckButton;

#ifndef CATDlgCheckButton_ADD
/** @nodoc */
#define CATDlgCheckButton_ADD
#endif

#ifndef CATDlgCheckButton_LateADD
/** @nodoc */
#define CATDlgCheckButton_LateADD
#endif

/** 
 * Base class for check buttons.
 * <b>Role</b>:
 * The check buttons allow to select several options among all the proposed options,
 * that is several can be checked while the others are unchecked.<br>
 * Use check buttons whenever you propose to the end user a choice among several inclusive options, 
 * that is when several options can be selected at the same time. 
 */
class ExportedByDI0PANV2 CATDlgCheckButton : public CATDlgControl
{

 public:

			/** 
			 * Constructs a CATDlgCheckButton.
			 * @param iParent
			 *   The parent of the check button.
			 * @param iObjectName
			 *   The name of the check button.
			 * @param iStyle
			 *   The style of the check button.
			 *   <br><b>Legal values</b>: <tt>NULL (default)</tt> so that the
			 *   title is placed at the right of the button, or
			 *   <tt>CATDlgBtnNoIndicator</tt> if the text is placed in the button.
			 */
        CATDlgCheckButton( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        virtual ~CATDlgCheckButton();

			/**
			 * Returns the state of the check button.
			 *   <br>
			 * The state of the check button can be.
			 *   <dl>
			 *   <dt><tt>CATDlgCheck</tt><dd> if the check button is checked,
			 *   <dt><tt>CATDlgUncheck</tt><dd> if it is unchecked.
			 *   </dl>
			 */
        CATULong  GetState();

			/**
			 * Sets the state of the check button.
			 * @param iState
			 * The state of the check button to set.
			 *   <br>
			 *   <b>Legal values</b> : It can be set to either :
			 *   <dl>
			 *   <dt><tt>CATDlgCheck</tt><dd> to check the check button,
			 *   <dt><tt>CATDlgUncheck</tt><dd> to uncheck it.
			 *   </dl>
			 * @param iNotify
			 * Set this parameter to a non null value if you want the corresponding notification to be sent.
			 * Otherwise set it to 0, so no notification will be sent. 
			 */
				void SetState( CATULong iState, int iNotify=1);

			/**
			 * Returns the event notification sent whenever the check button is checked or unchecked.
			 */
        CATNotification *GetChkBModifyNotification() const;

			/**
			 * Returns the event notification sent whenever the check button is double clicked. 
			 * The expected behavior is to loop on the associated command.
			 */
        CATNotification *GetChkBDoubleClickNotification() const;

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
        l_CATDlgCheckButton* _frameCheckButton;

        /** @nodoc */
        CATDlgCheckButton_ADD
};

/** @nodoc */
CATDlgCheckButton_LateADD

#endif
