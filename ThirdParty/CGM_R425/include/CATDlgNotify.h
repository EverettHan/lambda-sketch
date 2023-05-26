#ifndef CATDLGNOTIFY_H
#define CATDLGNOTIFY_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "CATDlgWindow.h"

class CATString;
class CATUnicodeString;
class l_CATDlgNotify;
class CATInteractiveApplication;

/**
 * Base class for information modal dialog windows.
 * <p>
 * <b>note:</b> Notify windows are always modal under Windows Operating Systems.
 * <p>
 * <b>note:</b> These windows are implemented as standard windows provided by the Operating Systems. As so, 
 * the button texts ("Cancel", "Apply",...) follow the installation language of the Operatings System and not the language
 * selected for V6.
 */
class ExportedByDI0PANV2 CATDlgNotify : public CATDlgWindow {
	public:

		/**
		 * Constructor.
		 * @param iParent
		 * The parent widget.
		 * @param iObjectName
		 * The internal name of the popup window.
		 * @param iStyle
		 * The style of the popup window.
		 * <br><b>Legal values:</b>
		 * <dl>
		 * <dt><tt>CATDlgNfyInformation</tt><dd> To specify an information window.
                 * It is the default style.
		 * <dt><tt>CATDlgNfyWarning</tt><dd> To specify a warning window </dd></dt>
		 * <dt><tt>CATDlgNfyError</tt><dd> To specify an error window </dd></dt>
		 * <dt><tt>CATDlgNfyAction</tt><dd> To specify a confirmation window </dd></dt>
		 * <dt><tt>CATDlgNfyAbortRetryIgnore</tt><dd> The window has Abort, Retry and Ignore buttons </dd></dt>
		 * <dt><tt>CATDlgNfyRetryCancel</tt><dd> The window has Retry and Cancel buttons </dd></dt>
		 * <dt><tt>CATDlgNfyOK</tt><dd> The window has an OK button </dd></dt>
		 * <dt><tt>CATDlgNfyOKCancel</tt><dd> The window has OK and Cancel buttons </dd></dt>
		 * <dt><tt>CATDlgNfyYesNo</tt><dd> The window has Yes and No buttons </dd></dt>
		 * <dt><tt>CATDlgNfyYesNoCancel</tt><dd> The window has Yes, No and Cancel buttons </dd></dt>
		 * <dt><tt>CATDlgWndModal</tt><dd> The window is modal </dd></dt>
		 * </dl>
                 * A button style should always be used.
		 */
		CATDlgNotify( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

		/**
		 * Constructor.
		 * @param iParent
		 * The parent application object.
		 * @param iObjectName
		 * The internal name of the popup window.
		 * @param iStyle
		 * The style of the popup window.
		 * <br><b>Legal values:</b>
		 * <dl>
		 * <dt><tt>CATDlgNfyInformation</tt><dd> To specify an information window.
                 * It is the default style.
		 * <dt><tt>CATDlgNfyWarning</tt><dd> To specify a warning window </dd></dt>
		 * <dt><tt>CATDlgNfyError</tt><dd> To specify an error window </dd></dt>
		 * <dt><tt>CATDlgNfyAction</tt><dd> To specify a confirmation window </dd></dt>
		 * <dt><tt>CATDlgNfyAbortRetryIgnore</tt><dd> The window has Abort, Retry and Ignore buttons </dd></dt>
		 * <dt><tt>CATDlgNfyRetryCancel</tt><dd> The window has Retry and Cancel buttons </dd></dt>
		 * <dt><tt>CATDlgNfyOK</tt><dd> The window has an OK button </dd></dt>
		 * <dt><tt>CATDlgNfyOKCancel</tt><dd> The window has OK and Cancel buttons </dd></dt>
		 * <dt><tt>CATDlgNfyYesNo</tt><dd> The window has Yes and No buttons </dd></dt>
		 * <dt><tt>CATDlgNfyYesNoCancel</tt><dd> The window has Yes, No and Cancel buttons </dd></dt>
		 * <dt><tt>CATDlgWndModal</tt><dd> The window is modal </dd></dt>
		 * </dl>
                 * A button style should always be used.
		 */
		CATDlgNotify( CATInteractiveApplication *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

		/**
		 * Destructor.
		 */
		virtual ~CATDlgNotify();

		/**
		 * Sets the message displayed by the window.
		 * @param iText
		 *  the text of the message.
		 */
		void SetText( const CATUnicodeString& iText);

		/**
		 * Gets the message displayed by the window.
		 * @return
		 *  the text of the message.
		 */
		CATUnicodeString GetText();

		/** @nodoc */
		void SetOKTitle( const CATUnicodeString& );

		/** @nodoc */
		void SetCANCELTitle( const CATUnicodeString& );

		/** @nodoc */
		void SetHELPTitle( const CATUnicodeString& );

		/** @nodoc */
		CATUnicodeString GetOKTitle();

		/** @nodoc */
		CATUnicodeString GetCANCELTitle();

		/** @nodoc */
		CATUnicodeString GetHELPTitle();


		/**
		 * Runs the dialog window in a modal loop.
		 * @param iMessage
		 *  the message displayed by the window.
		 * @param iWndTitle
		 *  the title of the window.
		 * @return
		 *  an integer identifying the button which has been pressed.
		 * <br><b>Legal values:</b>
		 * <dl>
		 * <dt><tt>1</tt><dd> The OK button has been pressed. </dd></dt>
		 * <dt><tt>2</tt><dd> The Cancel button has been pressed. </dd></dt>
		 * <dt><tt>3</tt><dd> The Yes button has been pressed. </dd></dt>
		 * <dt><tt>4</tt><dd> The No button has been pressed. </dd></dt>
		 * <dt><tt>5</tt><dd> The Retry button has been pressed. </dd></dt>
		 * <dt><tt>6</tt><dd> The Abort button has been pressed. </dd></dt>
		 * <dt><tt>7</tt><dd> The Ignore button has been pressed. </dd></dt>
		 * </dl>
		 */
		int DisplayBlocked(const CATUnicodeString &iMessage, const CATUnicodeString &iWndTitle);

		/** @nodoc */
		CATNotification *GetDiaOKNotification() const;

		/** @nodoc */
		CATNotification *GetDiaCANCELNotification() const;

		/** @nodoc */
		CATNotification *GetDiaHELPNotification() const;


		/**
		 * Returns the event notification sent when the <tt>Abort</tt> button is pressed.
		 */
		CATNotification *GetNfyAbortNotification() const;

		/**
		 * Returns the event notification sent when the <tt>Retry</tt> button is pressed.
		 */
		CATNotification *GetNfyRetryNotification() const;

		/**
		 * Returns the event notification sent when the <tt>Ignore</tt> button is pressed.
		 */
		CATNotification *GetNfyIgnoreNotification() const;

		/**
		 * Returns the event notification sent when the <tt>OK</tt> button is pressed.
		 */
		CATNotification *GetNfyOKNotification() const;

		/**
		 * Returns the event notification sent when the <tt>Cancel</tt> button is pressed.
		 */
		CATNotification *GetNfyCancelNotification() const;

		/**
		 * Returns the event notification sent when the <tt>Yes</tt> button is pressed.
		 */
		CATNotification *GetNfyYesNotification() const;

		/**
		 * Returns the event notification sent when the <tt>No</tt> button is pressed.
		 */
		CATNotification *GetNfyNoNotification() const;

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
		l_CATDlgNotify * _frameNotifyWindow;
};
#endif
