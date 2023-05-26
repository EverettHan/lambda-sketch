#ifndef CATDLGSTATUSBAR_H
#define CATDLGSTATUSBAR_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */


#include "CATDlgBar.h"

class CATString;
class l_CATDlgStatusBar;

#ifndef CATDlgStatusBar_ADD
/** @nodoc */
#define CATDlgStatusBar_ADD
#endif

#ifndef CATDlgStatusBar_LateADD
/** @nodoc */
#define CATDlgStatusBar_LateADD
#endif

/** 
 * Base class for document status bar.
 * <b>Role</b>:
 * The status bar is used to display temporary or permanent information related to the application
 * status, such as the prompts of the active command or its messages, and a keyboard entry field that is used
 * by the application PowerInput. It is generally located at the bottom of the window.
 * It can also include push buttons, check buttons, radio buttons, and labels. 
 * <br>
 * Use the status bar when you want to give application status information.
 */
class ExportedByDI0PANV2 CATDlgStatusBar : public CATDlgBar
{

 public:

				/** 
				 * Constructs a CATDlgStatusBar.
				 * @param iParent
				 *   The parent of the status bar.
				 * @param iObjectName
				 *   The name of the status bar.
				 * @param iStyle
				 *   The style of the status bar.
				 * The style can be :
				 *   <dl>
				 *   <dt><tt>NULL</tt><dd> : for the default status bar (if no value is passed).
				 *   </dl>
				 */
        CATDlgStatusBar( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        virtual ~CATDlgStatusBar();

        /**
         * Sets the PowerInput mode.
         * @param iMode
         * The mode to set for the PowerInput.
				 * The mode can be :
				 *   <dl>
				 *   <dt><tt>1</tt><dd> : the PowerInput is enabled.
				 *   <dt><tt>0</tt><dd> : the PowerInput is disabled.
				 *   </dl>
         */
        void SetPowerInputMode(int iMode);

        /**
         * Returns the PowerInput mode.
				 * The mode can be :
				 *   <dl>
				 *   <dt><tt>1</tt><dd> : the PowerInput is enabled.
				 *   <dt><tt>0</tt><dd> : the PowerInput is disabled.
				 *   </dl>
         */
        int  GetPowerInputMode();

        /**
         * Sets the PowerInput label.
         * @param iLabel
         * The label to set for the PowerInput.
         */
        void SetPowerInputLabel( const CATUnicodeString& iLabel);

        /**
         * Returns the PowerInput label.
         */
        CATUnicodeString& GetPowerInputLabel();

        /**
         * Sets the default PowerInput label.
         * @param iLabel
         * The default label to set for the PowerInput.
         */
        void SetDefaultPowerInputLabel( const CATUnicodeString& iLabel);

        /**
         * Sets the PowerInput text.
         * @param iText
         * The text to set for the PowerInput.
         */
        void SetPowerInputText( const CATUnicodeString& iText);

        /**
         * Returns the PowerInput text.
         */
        CATUnicodeString& GetPowerInputText();

        /**
         * Sets the PowerInput state.
         * @param iState
         * The state to set for the PowerInput.
				 * The state can be :
				 *   <dl>
				 *   <dt><tt>0</tt><dd> : the PowerInput entry must be associated with the active dialog box.
				 *   <dt><tt>1</tt><dd> : the PowerInput entry was caught by the CATApplicationDocument.
				 *   <dt><tt>2</tt><dd> : the PowerInput entry cannot be decoded.
				 *   </dl>
         */
        void SetPowerInputState(int iState);

        /**
         * Returns the PowerInput field separator.
         */
        CATUnicodeChar& GetFieldSeparator();

				/**
				 * Returns the event notification sent whenever the end user edits the PowerInput entry field.
				 */
        CATNotification *GetEditModifyNotification() const;

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
        l_CATDlgStatusBar* _frameStatusBar;

    /** @nodoc */
    CATDlgStatusBar_ADD
};

/** @nodoc */
CATDlgStatusBar_LateADD

#endif
