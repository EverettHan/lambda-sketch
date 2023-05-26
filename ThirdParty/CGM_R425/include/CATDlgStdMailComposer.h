#ifndef CATDLGMAILCOMPOSER_H
#define CATDLGMAILCOMPOSER_H

#include "CATDlgWindow.h"

class CATString;
class CATUnicodeString;
class CATDialog;
class CATInteractiveApplication;
class l_CATDialog;
class l_CATDlgStdMailComposer;

/**
 * Base class for mail composer dialog windows.
 * <p>
 * <b>note:</b> mail composer windows are always modal.
 * <p>
 * <b>note:</b> These windows are implemented as standard windows provided by the Operating Systems.
 * As so, the button texts ("Cancel", "Apply",...) follow the installation language of the Operatings System and not the language selected for V6.
 */
class ExportedByDI0PANV2 CATDlgStdMailComposer : public CATDlgWindow {
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
		 */
		CATDlgStdMailComposer( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

		/**
		 * Constructor.
		 * @param iParent
		 * The parent application object.
		 * @param iObjectName
		 * The internal name of the popup window.
		 * @param iStyle
		 * The style of the popup window.
		 * <br><b>Legal values:</b>
		 */
		CATDlgStdMailComposer( CATInteractiveApplication *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

		/**
		 * Destructor.
		 */
		virtual ~CATDlgStdMailComposer();

		/**
		 * Runs the dialog window in a modal loop.
		 * @param iScreenCapture
		 *  If TRUE, a capture of the screen is automatically attached.
		 * @return
		 *  an integer identifying the return code.
		 * <br><b>Legal values:</b>
		 * <dl>
		 * <dt><tt>0</tt><dd> The mail is sent. </dd></dt>
		 * <dt><tt>1</tt><dd> The mail is cancelled. </dd></dt>
		 * <dt><tt>2</tt><dd> The mail is saved. </dd></dt>
		 * <dt><tt>3</tt><dd> The mail is not sent. </dd></dt>
		 * </dl>
		 */
		int DisplayBlocked(CATBoolean iScreenCapture=FALSE);

		/**
		 * Runs the dialog window in a modal loop.
		 * @param iName the name of the attached document (ex: "preview.png")
		 * @param iMimeType the mimetype of the attached document (ex: "image/png")
		 * @param iData the attached document data
		 * @param iLength the attached document data length
		 * @return 
		 *    0 the mail is sent
		 *    1 the mail is cancelled
		 *    2 the mail is saved
		 *    3 the mail is not sent
		 */
		int DisplayBlocked(const CATUnicodeString& iName, const CATUnicodeString& iMimeType, unsigned char * iData, int iLength);

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
		l_CATDlgStdMailComposer * _frameMailComposerWindow;
};
#endif
