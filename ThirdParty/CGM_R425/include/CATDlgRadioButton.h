#ifndef CATDLGRADIOBUTTON_H
#define CATDLGRADIOBUTTON_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATDlgControl.h"

class CATString;
class l_CATDialog;
class l_CATDlgRadioButton;
class CATDlgRadioItem;

#ifndef CATDlgRadioButton_ADD
/** @nodoc */
#define CATDlgRadioButton_ADD
#endif

#ifndef CATDlgRadioButton_LateADD
/** @nodoc */
#define CATDlgRadioButton_LateADD
#endif

/**
 * Base class for radio buttons.
 * <b>Role</b>:
 * A radio button is used for selecting mutually exclusive options.
 * <br>
 * Use radio buttons whenever you propose to the end user a choice among several mutually exclusive options,
 * that is when one option only can be selected among all the options proposed.
 */
class ExportedByDI0PANV2 CATDlgRadioButton : public CATDlgControl
{

 public:

/**
 * Constructs a CATDlgRadioButton.
 * @param iParent
 *   The parent of the radio button.
 * @param iObjectName
 *   The name of the radio button.
 * @param iStyle
 *   The style of the radio button.
 *   <br><b>Legal values</b>: <tt>NULL (default)</tt> so that the
 *   title is placed at the right of the button, or
 *   <tt>CATDlgBtnNoIndicator</tt> if the text is placed in the button.
 */
        CATDlgRadioButton( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        virtual ~CATDlgRadioButton();

/**
 * Returns the state of the radio button.
 *   <br>
 * The state of the radio button can be:
 *   <dl>
 *   <dt><tt>CATDlgCheck</tt><dd> if the radio button is checked,
 *   <dt><tt>CATDlgUncheck</tt><dd> if it is unchecked.
 *   </dl>
 */
        CATULong GetState();

/**
 * Sets the state of the radio button.
 * @param iState
 * The state of the radio button to set.
 *   <br>
 *   <b>Legal values</b> : It can be set to either :
 *   <dl>
 *   <dt><tt>CATDlgCheck</tt><dd> to check the radio button,
 *   <dt><tt>CATDlgUncheck</tt><dd> to uncheck it.
 *   </dl>
 * @param iNotify
 * Set this parameter to a non null value if you want the corresponding notification to be sent.
 * Otherwise set it to 0, so no notification will be sent.
 */
        void SetState( CATULong iState, int iNotify=1);

/**
 * Returns the event notification sent whenever the radio button is checked or unchecked.
 */
        CATNotification *GetRadBModifyNotification() const;

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
 */
        l_CATDlgRadioButton* _frameExclusiveButton;

        /** @nodoc */
        CATDlgRadioButton_ADD
};

/** @nodoc */
CATDlgRadioButton_LateADD

#endif
