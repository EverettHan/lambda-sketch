#ifndef CATDLGDIALOG_H
#define CATDLGDIALOG_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */


#include "CATDlgWindow.h"


class CATString;
class CATUnicodeString;
class CATDlgContextualMenu;
class CATDlgBarMenu;
class CATInteractiveApplication;
class CATNotification;
class CATDialog;
class CATCommand;

class l_CATDlgDialog;
class l_CATDialog;

#include "CATDlgUtility.h"
#include "CATBoolean.h"

#ifndef CATDlgDialog_ADD
/** @nodoc */
#define CATDlgDialog_ADD
#endif

#ifndef CATDlgDialog_LateADD
/** @nodoc */
#define CATDlgDialog_LateADD
#endif

/** 
 * Base class for popup windows.
 * <b>Role</b>:
 * The dialog window is designed to enable the dialog between the end user and the application. 
 * Is is dedicated to either :
 * <ul>
 * <li>display views of a document,</li>
 * <li>contain controls arranged to enable the end user to enter values, or select options to edit, 
 *  modify, or print these documents, or to globally parameterize the application.</li>
 * </ul>
 * It allows data acquisition from the user. Applications can thus request data from the user to go on executing.<br>
 * In addition, a dialog window can be set to modal. In this case, the dialog is limited to this window,
 * and when it ends, the window disappears.
 * <br>
 * Use the dialog window as a base class when you want to create a window for a document or a dialog.
 * <br>
 * The parent of an instance of a class that derives from CATDlgDialog must be an instance of a class that derives from 
 * @href CATInteractiveApplication or @href CATDlgDocument.
 */
class ExportedByDI0PANV2 CATDlgDialog : public CATDlgWindow
{

 public:

        /** 
         * Constructs a CATDlgDialog.
         * @param iParent
         *   The parent of the dialog.
         * @param iObjectName
         *   The name of the dialog.
         * @param iStyle
         *   The style of the dialog.
         * The style can be :
         *   <dl>
         *   <dt><tt>NULL</tt><dd> if no value is passed, for the default dialog window with the OK, Cancel, and Help push buttons.
         *   <dt><tt>CATDlgWndModal</tt><dd> for a modal dialog window ; no interaction is possible outside this window 
         * as long as it is displayed. The cursor changes to prevent from doing anything outside of the window.
         *   <dt><tt>CATDlgWndBtnOKCancel</tt><dd> for a standard dialog window with the OK and Cancel push buttons.
         *   <dt><tt>CATDlgWndBtnOKCancelPreview</tt><dd> for a standard dialog window with the OK, Cancel and Preview push buttons.
         *   <dt><tt>CATDlgWndBtnOKApplyClose</tt><dd> for a standard dialog window with the OK, Apply and Close push buttons.
         *   <dt><tt>CATDlgWndBtnClose</tt><dd> for a standard dialog window with the Close push button.
         *   <dt><tt>CATDlgWndNoButton</tt><dd> for a dialog window without any push button.
         *   <dt><tt>CATDlgWndSmallDecoration</tt><dd> for a dialog window without any title bar.
         *   <dt><tt>CATDlgWndNoDecoration</tt><dd> for a dialog window without any title bar nor resizing frame.
         *   <dt><tt>CATDlgWndPointerLocation</tt><dd> for a dialog window created at the mouse cursor location.
         *   <dt><tt>CATDlgWndAutoResize</tt><dd> for a dialog window automatically resized with respect to its content's modifications.
         *   <dt><tt>CATDlgWndNoResize</tt><dd> for a dialog window not resizable by the end user. 
         * The minimize and maximize buttons are not available
         *   <dt><tt>CATDlgWndChildMDI</tt><dd> for a dialog window located within its parent application main window.
         *   <dt><tt>CATDlgWndTitleBarHelp</tt><dd> for a dialog window with the help button located in the title bar, as a question mark.
         * This is possible with Windows only and has no effect with UNIX
         *   <dt><tt>CATDlgWndSavePreferences</tt><dd> to save and restore the dimensions of the dialog window as set by any resize performed by the user.
         * This style is ignored when CATDlgWndChildMDI is set.
         *   </dl>
         */
        CATDlgDialog( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        /** 
         * Constructs a CATDlgDialog with a specified parent for the event management.
         * @param iParent
         *   The parent of the dialog.
         * @param iEventMgr
         *   The command parent of the dialog (for the event notification management).
         * @param iObjectName
         *   The name of the dialog.
         * @param iStyle
         *   The style of the dialog.
         * The style can be :
         *   <dl>
         *   <dt><tt>NULL</tt><dd> if no value is passed, for the default dialog window with the OK, Cancel, and Help push buttons.
         *   <dt><tt>CATDlgWndModal</tt><dd> for a modal dialog window ; no interaction is possible outside this window 
         * as long as it is displayed. The cursor changes to prevent from doing anything outside of the window.
         *   <dt><tt>CATDlgWndBtnOKCancel</tt><dd> for a standard dialog window with the OK and Cancel push buttons.
         *   <dt><tt>CATDlgWndBtnOKCancelPreview</tt><dd> for a standard dialog window with the OK, Cancel and Preview push buttons.
         *   <dt><tt>CATDlgWndBtnOKApplyClose</tt><dd> for a standard dialog window with the OK, Apply and Close push buttons.
         *   <dt><tt>CATDlgWndBtnClose</tt><dd> for a standard dialog window with the Close push button.
         *   <dt><tt>CATDlgWndNoButton</tt><dd> for a dialog window without any push button.
         *   <dt><tt>CATDlgWndSmallDecoration</tt><dd> for a dialog window without any title bar.
         *   <dt><tt>CATDlgWndNoDecoration</tt><dd> for a dialog window without any title bar nor resizing frame.
         *   <dt><tt>CATDlgWndPointerLocation</tt><dd> for a dialog window created at the mouse cursor location.
         *   <dt><tt>CATDlgWndAutoResize</tt><dd> for a dialog window automatically resized with respect to its content's modifications.
         *   <dt><tt>CATDlgWndNoResize</tt><dd> for a dialog window not resizable by the end user. 
         * The minimize and maximize buttons are not available
         *   <dt><tt>CATDlgWndChildMDI</tt><dd> for a dialog window located within its parent application main window.
         *   <dt><tt>CATDlgWndTitleBarHelp</tt><dd> for a dialog window with the help button located in the title bar, as a question mark.
         * This is possible with Windows only and has no effect with UNIX
         *   <dt><tt>CATDlgWndSavePreferences</tt><dd> to save and restore the dimensions of the dialog window as set by any resize performed by the user.
         * This style is ignored when CATDlgWndChildMDI is set.
         *   </dl>
         */
        CATDlgDialog( CATDialog *iParent, CATCommand *iEventMgr, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        /** 
         * Constructs a CATDlgDialog with the application as parent.
         * @param iParent
         *   The parent of the dialog.
         * @param iObjectName
         *   The name of the dialog.
         * @param iStyle
         *   The style of the dialog.
         * The style can be :
         *   <dl>
         *   <dt><tt>NULL</tt><dd> if no value is passed, for the default dialog window with the OK, Cancel, and Help push buttons.
         *   <dt><tt>CATDlgWndModal</tt><dd> for a modal dialog window ; no interaction is possible outside this window 
         * as long as it is displayed. The cursor changes to prevent from doing anything outside of the window.
         *   <dt><tt>CATDlgWndBtnOKCancel</tt><dd> for a standard dialog window with the OK and Cancel push buttons.
         *   <dt><tt>CATDlgWndBtnOKCancelPreview</tt><dd> for a standard dialog window with the OK, Cancel and Preview push buttons.
         *   <dt><tt>CATDlgWndBtnOKApplyClose</tt><dd> for a standard dialog window with the OK, Apply and Close push buttons.
         *   <dt><tt>CATDlgWndBtnClose</tt><dd> for a standard dialog window with the Close push button.
         *   <dt><tt>CATDlgWndNoButton</tt><dd> for a dialog window without any push button.
         *   <dt><tt>CATDlgWndSmallDecoration</tt><dd> for a dialog window without any title bar.
         *   <dt><tt>CATDlgWndNoDecoration</tt><dd> for a dialog window without any title bar nor resizing frame.
         *   <dt><tt>CATDlgWndPointerLocation</tt><dd> for a dialog window created at the mouse cursor location.
         *   <dt><tt>CATDlgWndAutoResize</tt><dd> for a dialog window automatically resized with respect to its content's modifications.
         *   <dt><tt>CATDlgWndNoResize</tt><dd> for a dialog window not resizable by the end user. 
         * The minimize and maximize buttons are not available
         *   <dt><tt>CATDlgWndChildMDI</tt><dd> for a dialog window located within its parent application main window.
         *   <dt><tt>CATDlgWndTitleBarHelp</tt><dd> for a dialog window with the help button located in the title bar, as a question mark.
         * This is possible with Windows only and has no effect with UNIX
         *   <dt><tt>CATDlgWndSavePreferences</tt><dd> to save and restore the dimensions of the dialog window as set by any resize performed by the user.
         * This style is ignored when CATDlgWndChildMDI is set.
         *   </dl>
         */
        CATDlgDialog( CATInteractiveApplication *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        virtual ~CATDlgDialog();

        /**
         * Returns the contextual menu of the dialog window if any.
         */
        CATDlgContextualMenu* GetContextualMenu();

        /**
         * Returns the menu bar of the dialog window if any.
         */
        CATDlgBarMenu* GetMenuBar();

        /**
         * Sets the OK push button title if not defined in resource file.
         * @param iTitle
         * The title to set.
         */
        void SetOKTitle( const CATUnicodeString& iTitle );

        /**
         * Sets the Apply push button title if not defined in resource file.
         * @param iTitle
         * The title to set.
         */
        void SetAPPLYTitle( const CATUnicodeString& iTitle );

        /**
         * Sets the Cancel push button title if not defined in resource file.
         * @param iTitle
         * The title to set.
         */
        void SetCANCELTitle( const CATUnicodeString& iTitle );

        /**
         * Sets the Help push button title if not defined in resource file.
         * @param iTitle
         * The title to set.
         */
        void SetHELPTitle( const CATUnicodeString& iTitle );

        /**
         * Sets the Preview push button title if not defined in resource file.
         * @param iTitle
         * The title to set.
         */
        void SetPREVIEWTitle( const CATUnicodeString& iTitle );

        /**
         * @nodoc
         * Sets the PREVIOUS push button title if not defined in resource file.
         * @param iTitle
         * The title to set.
         */
        void SetPREVIOUSTitle( const CATUnicodeString& iTitle );

        /**
         * @nodoc
         * Sets the NEXT push button title if not defined in resource file.
         * @param iTitle
         * The title to set.
         */
        void SetNEXTTitle( const CATUnicodeString& iTitle );

        /**
         * @nodoc
         * Sets the FINISH push button title if not defined in resource file.
         * @param iTitle
         * The title to set.
         */
        void SetFINISHTitle( const CATUnicodeString& iTitle );

        /**
         * Sets the CLOSE push button title if not defined in resource file.
         * @param iTitle
         * The title to set.
         */
        void SetCLOSETitle( const CATUnicodeString& iTitle );

        /**
         * Returns the OK push button title.
         */
        CATUnicodeString GetOKTitle();

        /**
         * Returns the Apply push button title.
         */
        CATUnicodeString GetAPPLYTitle();

        /**
         * Returns the Cancel push button title.
         */
        CATUnicodeString GetCANCELTitle();

        /**
         * Returns the Help push button title.
         */
        CATUnicodeString GetHELPTitle();

        /**
         * Returns the Preview push button title.
         */
        CATUnicodeString GetPREVIEWTitle();

        /**
         * @nodoc
         * Returns the Previous push button title.
         */
        CATUnicodeString GetPREVIOUSTitle();

        /**
         * @nodoc
         * Returns the Next push button title.
         */
        CATUnicodeString GetNEXTTitle();

        /**
         * @nodoc
         * Returns the Finish push button title.
         */
        CATUnicodeString GetFINISHTitle();

        /**
         * Returns the CLOSE push button title.
         */
        CATUnicodeString GetCLOSETitle();

        /**
         * Sets the OK push button sensitivity.
         * @param iSensitivity
         * The sensitivity to set.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> to enable the push button,
         *   <dt><tt>CATDlgDisable</tt><dd> to disable the push button (grayed),
         *   </dl>
         */
        void SetOKSensitivity( CATULong iSensitivity );

        /**
         * Sets the Cancel push button sensitivity.
         * @param iSensitivity
         * The sensitivity to set.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> to enable the push button,
         *   <dt><tt>CATDlgDisable</tt><dd> to disable the push button (grayed),
         *   </dl>
         */
        void SetCANCELSensitivity( CATULong iSensitivity );

        /**
         * Sets the Preview push button sensitivity.
         * @param iSensitivity
         * The sensitivity to set.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> to enable the push button,
         *   <dt><tt>CATDlgDisable</tt><dd> to disable the push button (grayed),
         *   </dl>
         */
        void SetPREVIEWSensitivity( CATULong iSensitivity );

        /**
         * Sets the Apply push button sensitivity.
         * @param iSensitivity
         * The sensitivity to set.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> to enable the push button,
         *   <dt><tt>CATDlgDisable</tt><dd> to disable the push button (grayed),
         *   </dl>
         */
        void SetAPPLYSensitivity( CATULong iSensitivity );

        /**
         * Sets the Close push button sensitivity.
         * @param iSensitivity
         * The sensitivity to set.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> to enable the push button,
         *   <dt><tt>CATDlgDisable</tt><dd> to disable the push button (grayed),
         *   </dl>
         */
        void SetCLOSESensitivity( CATULong iSensitivity );

        /**
         * Sets the Help push button sensitivity.
         * @param iSensitivity
         * The sensitivity to set.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> to enable the push button,
         *   <dt><tt>CATDlgDisable</tt><dd> to disable the push button (grayed),
         *   </dl>
         */
        void SetHELPSensitivity( CATULong iSensitivity );

        /**
         * @nodoc
         * Sets the Previous push button sensitivity.
         * @param iSensitivity
         * The sensitivity to set.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> to enable the push button,
         *   <dt><tt>CATDlgDisable</tt><dd> to disable the push button (grayed),
         *   </dl>
         */
        void SetPREVIOUSSensitivity( CATULong iSensitivity );

        /**
         * @nodoc
         * Sets the Next push button sensitivity.
         * @param iSensitivity
         * The sensitivity to set.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> to enable the push button,
         *   <dt><tt>CATDlgDisable</tt><dd> to disable the push button (grayed),
         *   </dl>
         */
        void SetNEXTSensitivity( CATULong iSensitivity );

        /**
         * @nodoc
         * Sets the Finish push button sensitivity.
         * @param iSensitivity
         * The sensitivity to set.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> to enable the push button,
         *   <dt><tt>CATDlgDisable</tt><dd> to disable the push button (grayed),
         *   </dl>
         */
        void SetFINISHSensitivity( CATULong iSensitivity );

        /**
         * Returns the OK push button sensitivity.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> if the push button is enabled,
         *   <dt><tt>CATDlgDisable</tt><dd> if the push button is disabled (grayed),
         *   </dl>
         */
        CATULong GetOKSensitivity();

        /**
         * Returns the Cancel push button sensitivity.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> if the push button is enabled,
         *   <dt><tt>CATDlgDisable</tt><dd> if the push button is disabled (grayed),
         *   </dl>
         */
        CATULong GetCANCELSensitivity();

        /**
         * Returns the Preview push button sensitivity.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> if the push button is enabled,
         *   <dt><tt>CATDlgDisable</tt><dd> if the push button is disabled (grayed),
         *   </dl>
         */
        CATULong GetPREVIEWSensitivity();

        /**
         * Returns the Apply push button sensitivity.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> if the push button is enabled,
         *   <dt><tt>CATDlgDisable</tt><dd> if the push button is disabled (grayed),
         *   </dl>
         */
        CATULong GetAPPLYSensitivity();

        /**
         * Returns the Close push button sensitivity.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> if the push button is enabled,
         *   <dt><tt>CATDlgDisable</tt><dd> if the push button is disabled (grayed),
         *   </dl>
         */
        CATULong GetCLOSESensitivity();

        /**
         * Returns the Help push button sensitivity.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> if the push button is enabled,
         *   <dt><tt>CATDlgDisable</tt><dd> if the push button is disabled (grayed),
         *   </dl>
         */
        CATULong GetHELPSensitivity();

        /**
         * @nodoc
         * Returns the Previous push button sensitivity.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> if the push button is enabled,
         *   <dt><tt>CATDlgDisable</tt><dd> if the push button is disabled (grayed),
         *   </dl>
         */
        CATULong GetPREVIOUSSensitivity();

        /**
         * @nodoc
         * Returns the Next push button sensitivity.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> if the push button is enabled,
         *   <dt><tt>CATDlgDisable</tt><dd> if the push button is disabled (grayed),
         *   </dl>
         */
        CATULong GetNEXTSensitivity();

        /**
         * @nodoc
         * Returns the Finish push button sensitivity.
         *   <br>
         *   <b>Legal values</b> : It can be set to either :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> if the push button is enabled,
         *   <dt><tt>CATDlgDisable</tt><dd> if the push button is disabled (grayed),
         *   </dl>
         */
        CATULong GetFINISHSensitivity();

        /**
          * Sets the default push button.
          * <br><b>Role:</b>
          * The default push button is the one activated when the end user presses the Enter key.
          * In the @href CATDlgDialog constructor class, the default is set to CATDlgWndOK. 
          * @param iButton
          * The default push button to set.
          *   <br>
          *   <b>Legal values</b> :
          *   <dl>
          *   <dt><tt>NULL</tt><dd> : no default push button,
          *   <dt><tt>CATDlgWndOK</tt><dd> : the OK push button,
          *   <dt><tt>CATDlgWndCANCEL</tt><dd> : the Cancel push button,
          *   <dt><tt>CATDlgWndPREVIEW</tt><dd> : the Preview push button,
          *   <dt><tt>CATDlgWndAPPLY</tt><dd> : the Apply push button.
          *   <dt><tt>CATDlgWndCLOSE</tt><dd> : the Close push button,
          *   <dt><tt>CATDlgWndHELP</tt><dd> : the Help push button,
          *   </dl>
          */
        void SetDefaultButton( int iButton);

        /**
         * Returns the default push button.
         * The default push button is the one activated when the end user presses the Enter key.
         *   <br>
         *   <b>Legal values</b> :
         *   <dl>
         *   <dt><tt>NULL</tt><dd> : no default push button,
         *   <dt><tt>CATDlgWndOK</tt><dd> : the OK push button,
         *   <dt><tt>CATDlgWndCANCEL</tt><dd> : the Cancel push button,
         *   <dt><tt>CATDlgWndPREVIEW</tt><dd> : the Preview push button,
         *   <dt><tt>CATDlgWndAPPLY</tt><dd> : the Apply push button.
         *   <dt><tt>CATDlgWndCLOSE</tt><dd> : the Close push button,
         *   <dt><tt>CATDlgWndHELP</tt><dd> : the Help push button,
         *   </dl>
         */
        int  GetDefaultButton();

        /**
         * Puts the dialog window controls on PowerInput.
         */
        void TakePowerInputFocus();

        /**
         * Removes the dialog window controls from PowerInput.
         */
        void ReleasePowerInputFocus();

        /**
         * Forces regeneration of PowerInput.
         */
        void UpdatePowerInput();

        /**
         * Returns the PowerInput label from the active box.
         */
        virtual CATUnicodeString& BuildPowerInputLabel();

        /**
         * Returns the PowerInput text from the active box.
         */
        virtual CATUnicodeString& BuildPowerInputText();

        /**
         * Decodes a PowerInput text.
         * @param iText
         * The text to decode.
         */
        virtual void DecodePowerInputText(const CATUnicodeString& iText);

        /**
         * Method called before first field is modified.
         */
        virtual void PowerInputBeginTransaction();

        /**
         * Method called after last field is modified.
         */
        virtual void PowerInputEndTransaction();

        /**
         * Parses power input text.
         * @param iFieldArray
         * The field string array containing the different values entered in the PowerInput (separated by comas).
         * @param iNbmax
         * The field array size.
         */
        int ParsePowerInputText(CATUnicodeString* iFieldArray, int iNbmax);

        /**
         * Returns the event notification sent whenever the OK push button is pressed.
         */
        CATNotification *GetDiaOKNotification() const;

        /**
         * Returns the event notification sent whenever the Cancel push button is pressed.
         */
        CATNotification *GetDiaCANCELNotification() const;

        /**
         * Returns the event notification sent whenever the Preview push button is pressed.
         */
        CATNotification *GetDiaPREVIEWNotification() const;

        /**
         * Returns the event notification sent whenever the Apply push button is pressed.
         */
        CATNotification *GetDiaAPPLYNotification() const;

        /**
         * Returns the event notification sent whenever the Close push button is pressed.
         */
        CATNotification *GetDiaCLOSENotification() const;

        /**
         * Returns the event notification sent whenever the Help push button is pressed.
         */
        CATNotification *GetDiaHELPNotification() const;

        /**
         * @nodoc
         * Returns the event notification sent whenever the Previous push button is pressed.
         */
        CATNotification *GetDiaPREVIOUSNotification() const;

        /**
         * @nodoc
         * Returns the event notification sent whenever the Next push button is pressed.
         */
        CATNotification *GetDiaNEXTNotification() const;

        /**
         * @nodoc
         * Returns the event notification sent whenever the Finish push button is pressed.
         */
        CATNotification *GetDiaFINISHNotification() const;

        /**
         * Returns the event notification sent whenever the dialog window is restored.
         */
        CATNotification *GetMDIRestoreNotification() const;

        /**
         * Returns the event notification sent whenever the dialog window is minimized.
         */
        CATNotification *GetMDIMinimizeNotification() const;

        /**
         * Returns the event notification sent whenever the dialog window is maximized.
         */
        CATNotification *GetMDIMaximizeNotification() const;

        /**
         * Returns the event notification sent whenever the dialog window is closed.
         */
        CATNotification *GetMDICloseNotification() const;

        /**
         * Returns the event notification sent whenever the dialog window is activated as the next of the current one.
         */
        CATNotification *GetMDINextNotification() const;

        /**
         * Returns the event notification sent whenever the dialog window is activated as the previous of the current one.
         */
        CATNotification *GetMDIPreviousNotification() const;

        /**
         * Returns the event notification sent whenever the dialog window is activated.
         */
        CATNotification *GetMDIActivateNotification() const;

        /**
         * @nodoc
         * Sets the ratio value, width/height, of the dialog window.
         */
        void SetRatioSize(float iratio);

        /**
         * @nodoc
         * Returns the current ratio value, width/height, of the dialog window.
         */
        float GetRatioSize() const;

        /**
         * @nodoc
         * Keeps the ratio when we resize the dialog box if the value of
         * the parameter is different of zero.
         */
        void KeepRatio(int iflag);

        /**
         * Sets the focus on the specified dialog component.
         * @param iDialog
         *   The dialog component with the focus.
         * By default, the first editable component has the keyboard focus.
         *   <br>
         *   <b>An editable component is one of this following list</b> :
         *   <dl>
         *   <dt><tt>CATDlgEditor</tt><dd> : without the style CATDlgEdtReadOnly.
         *   <dt><tt>CATDlgCombo</tt><dd> : with the style CATDlgCmbEntry.
         *   <dt><tt>CATDlgSpinner</tt><dd> : with the style CATDlgSpnEntry.
         *   </dl>
         * If the dialog box has more than one of editable component, the first one is positioned
         * at the top left most position.
         * The user is able to change the keyboard focus with the Tab key and/or the mouse.
         */
        void SetFocusOn(CATDialog *iDialog);

        /**
         * @nodoc
         */
        CATDialog* GetFocus();

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

 protected:

        /**
         * @nodoc
         * Address of the internal object.
         */
        l_CATDlgDialog *_frameDialogWindow;

        /** @nodoc */
        CATDlgDialog_ADD
};

/** @nodoc */
CATDlgDialog_LateADD

#endif
