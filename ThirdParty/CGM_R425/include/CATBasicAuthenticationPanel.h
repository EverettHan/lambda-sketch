#ifndef CATBASICAUTHENTICATIONPANEL_H
#define CATBASICAUTHENTICATIONPANEL_H

// COPYRIGHT DASSAULT SYSTEMES 2006

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//------------------------------------------------------------------------------
// Abstract: The base class for a basic authentication panel
//------------------------------------------------------------------------------
// Usage:    Creation in the user exit interface for encryption (DRM)
//------------------------------------------------------------------------------
// Inheritance: CATBaseUnknown
//------------------------------------------------------------------------------
// Main methods:
//              - AddLogo
//              - AddLabelAndEditor
//              - AddSeparator
//              - GetLine
//              - GetLineCount
//              - SetTitle
//              - WaitPassword
//------------------------------------------------------------------------------
// Styles:
//------------------------------------------------------------------------------

// System
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATString.h"
#include "CATUnicodeString.h"

// Dialog
class l_CATBasicAuthenticationPanel;

#include "CATDlgStandard.h"
#include "CATDlgDocument.h"
#include "CATDlgDialog.h"

/**
 * Base class for the basic authentication panel.
 * <b>Role</b>:
 * The basic authentication panel allows the end user to give answers to different questions, usually name and password through a keyboard entry.
 */
class ExportedByCATDlgStandard CATBasicAuthenticationPanel : public CATBaseUnknown
{
  public:

       /**
        * Constructs an empty basic authentication panel.
        */
       CATBasicAuthenticationPanel();

       virtual ~CATBasicAuthenticationPanel();
  
       /**
        * Inserts an image at the current line in the basic authentication panel.
        * @param iLogo
        * The name of the icon.
        */
        void AddLogo(const CATString& iLogo);
  
       /**
        * Inserts a separator at the current line in the basic authentication panel.
        */
        void AddSeparator();
  
       /**
        * Inserts a label and an editor at the current line in the basic authentication panel.
        * @param iLabelText
        * The text of the label.
        * @param iDefaultText
        * The default text displayed in the editor.
        * @param iWidthEdit
        * The visible text width (column count).
        * @param iPassword
        * <br>
        * <b>Legal values:</b>
        * <dl>
        * <dt><tt>TRUE</tt><dd> if the text is hidden with special characters. </dd></dt>
        * <dt><tt>FALSE</tt><dd> if the text isn't hidden. (default)</dd></dt>
        * </dl>
        */
        void AddLabelAndEditor(const CATUnicodeString& iLabelText,
                               const CATUnicodeString& iDefaultText,
                               const int iWidthEdit=10, const CATBoolean iPassword=FALSE);

       /**
        * Retrieves the contents of the line from its index (first line has 0 for index).
        * @param oLine
        * The returned contents of the specified line.
        * @param iIndex
        * The index of the line.
        */
       void GetLine(CATUnicodeString& oLine, const int iIndex);

       /**
        * Returns the number of questions in the basic authentication panel.
        */
       int GetLineCount();

       /**
        * Sets the title of the dialog object to the specified character string.
        * @param iTitle
        * The title to be displayed.
        */
       void SetTitle(const CATUnicodeString& iTitle);

       /**
        * Runs the dialog window in a modal loop.
        * @param oUserName
        *  the text of the first editor, typically the user name.
        *  oUserName is empty if the basic authentication panel contains 0 editor.
        * @param oPassword
        *  the text of the second editor, typically the password.
        *  oPassword is empty if the basic authentication panel contains 0 or 1 editor.
        * @return
        *  an integer identifying the button which has been pressed.
        * <br><b>Legal values:</b>
        * <dl>
        * <dt><tt>1</tt><dd> The OK button has been pressed. </dd></dt>
        * <dt><tt>0</tt><dd> The Cancel button has been pressed. </dd></dt>
        * </dl>
       */
       int WaitAuthentication(CATUnicodeString &oUserName, CATUnicodeString &oPassword);


       /**
        * Inserts a check button at the current line in the basic authentication panel.
        * @param iText
        * The text of the check button.
        * @param iDefaultCheckButtonState
        * The default state of the check button.
        * <br><b>Legal values:</b>
        * <dl>
        * <dt><tt>CATDlgUncheck</tt><dd> The button is unchecked. </dd></dt>
        * <dt><tt>CATDlgCheck</tt><dd>   The button is checked. </dd></dt>
        * </dl>
        */
       void AddCheckButton(const CATUnicodeString& iText,
                           const CATULong iDefaultCheckButtonState);

        /**
        * Retrieves the state of the check button from its index (first line has 0 for index).
        * @param oCheckButtonState
        * The returned state of the check button.
        * @param iIndex
        * The index of the line.
        */
       void GetCheckButtonState (CATULong &oCheckButtonState, const int iIndex);

        /**
        * Returns the number of check button in the panel.
        */
       int GetCheckButtonLineCount();
  
  private:

       /**
        * @nodoc
        */
       l_CATBasicAuthenticationPanel    *_letterPanel;
       /**
        * @nodoc
        */
       CATDlgDocument                    *_CATDlgDocument;
};

#endif
