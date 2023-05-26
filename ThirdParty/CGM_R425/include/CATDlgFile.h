#ifndef CATDLGFILESELECTIONBOX_H
#define CATDLGFILESELECTIONBOX_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//------------------------------------------------------------------------------
// Abstract: The base class for file selection box
//
//------------------------------------------------------------------------------
// Usage:    Assign a CATDlgFile to a CATDlgDocument.
//------------------------------------------------------------------------------
// Inheritance: CATDlgFile
//                CATDlgWindow
//                  CATDialog
//------------------------------------------------------------------------------
// Main methods:
//
//           SetDirectory               set root directory
//           GetDirectory               get directory
//           SetFilterPattern           set filter
//           GetFilterPattern           get filter
//           SetFileName                set filename on initialization 
//           GetSelection               get selected file
//           GetSelectionCount          get number of selected files
//           SetOKTitle                 set character string on OK button
//           SetAPPLYTitle              set character string on APPLY button
//           SetFILTERTitle             set character string on FILTER button
//           SetCANCELTitle             set character string on CANCEL button
//           SetHELPTitle               set character string on HELP button
//           GetOKTitle                 get character string on OK button
//           GetAPPLYTitle              get character string on APPLY button
//           GetFILTERTitle             get character string on FILTER button
//           GetCANCELTitle             get character string on CANCEL button
//           GetHELPTitle               get character string on HELP button
//           SetOKSensitivity           set OK button sensitivity
//           SetAPPLYSensitivity        set APPLY button sensitivity
//           SetFILTERSensitivity       set FILTER button sensitivity
//           SetCANCELSensitivity       set CANCEL button sensitivity
//           SetHELPSensitivity         set HELP button sensitivity
//           GetOKSensitivity           get OK button sensitivity
//           GetAPPLYSensitivity        get APPLY button sensitivity
//           GetFILTERSensitivity       get FILTER button sensitivity
//           GetCANCELSensitivity       get CANCEL button sensitivity
//           GetHELPSensitivity         get HELP button sensitivity
//           SetFilterStrings           set types of files
//           GetFilterStrings           get types of files
//           SetActiveFilterIndex       set current type of files
//           GetReadOnlyState           get value on read only checkButton (Windows only)
//           SetReadOnlyState           set value on read only checkButton (Windows only)
//------------------------------------------------------------------------------
// Events:
//
//           GetDiaOKNotification       selection of OK button
//           GetDiaCANCELNotification   selection of CANCEL button
//           GetDiaAPPLYNotification    selection of APPLY button
//           GetDiaHELPNotification     selection of HELP button
//------------------------------------------------------------------------------
// Styles:
//
//           CATDlgWndModal
//           CATDlgWndAPPLY
//           CATDlgWndHELP
//           CATDlgFileSave
//           CATDlgFileMultisel
//------------------------------------------------------------------------------

//--------------------------------------------------------------------------
#include "CATDlgWindow.h"

//--------------------------------------------------------------------------
class CATString;
class CATUnicodeString;
class l_CATDlgFile;
class CATInteractiveApplication;

//--------------------------------------------------------------------------
/**
 * Class delivering a file or folder selection box.
 * <b>Role</b>: Enables a file or folder selection.
 * This window offers a file selection box with a filter to 
 * apply to search for files or a folder selection box.
 * <p>
 * Under Windows, a standard Windows file or folder selection box is displayed 
 * <br>Under Unix, a standard Motif file selection dialog box is displayed 
 * <br>As so, the box texts follow the installation language of the Operatings System and not the language
 * selected for this software.
 * <p>
 * <b>Specific to Unix:</b>There are three kinds of file windows: 
 * default, apply, and help. Apply and help file windows feature an Apply 
 * and Help push button respectively, in addition to the OK, Filter and 
 * Cancel push buttons. In addition, a file window can be set to modal. 
 * The modal file window locks the dialog to this window as long as it is displayed. 
 * <p>
 * This window is used to list, select, open or save files or to list
 * and select folders.
 * <p>
 * The purpose of most methods below is to initialize the file selection 
 * box. Once the box ended, the application will have to interfere
 * only when the following events occur:
 * <ul>
 * <li>CATDlgDiaOKNotification (when, according to window style, the Open, Save or OK push button is pressed)</li>
 * <li>CATDlgDiaCANCELNotification (when the CANCEL push button is pressed)</li>
 * </ul>
 * In the meantime, all the dialog is managed by this software.
 */
class ExportedByDI0PANV2 CATDlgFile : public CATDlgWindow
{

//--------------------------------------------------------------------------
 public:

//      constructors - destructor
/**
 * Constructs a file selection box.
 * <br><b>Role</b>: Constructs a file selection box. 
 * @param iParent
 *   The parent of the CATDlgFile.
 *   The parent must be an instance of a class that derives from CATDlgDocument.
 * @param iDialogObjectName
 *   The dialog object name. 
 * @param iStyle
 *   The application window styles. You can cumulate several
 *   styles using a logical or.
 *   <br><b>Legal values</b>: 
 *   <ul>
 *   <li><tt>NULL</tt> (default):The 
 *   file window features the OK and Cancel push buttons (it is dedicated 
 *   to opening files), </li> 
 *   <li><tt>CATDlgWndModal</tt>:In addition to the default 
 *   style, the file window is modal (that is, no interaction is possible outside 
 *   this window as long as it is displayed). Under Windows, the file window is modal
 *   whatever the style specified. </li> 
 *   <li><tt>CATDlgWndAPPLY</tt>: 
 *   In addition to the default style, the file window features 
 *   the Apply push button. This style is ignored under Windows.</li> 
 *   <li><tt>CATDlgWndHELP</tt>: In addition to the default style, the file window features 
 *   the Help push button. This style is ignored under Windows.</li> 
 *   <li><tt>CATDlgFileSave</tt>: The file window is dedicated to saving files. 
 *   (the Open push button is replaced by the Save push button),</li> 
 *   <li><tt>CATDlgFileMultisel</tt>: The file window enables the
 *   file multiple selection.</li>
 *   <li><tt>CATDlgFolderChooser</tt>: The file window is dedicated
 *   to select a folder</li>
 *   <li><tt>CATDlgFileOverwritePrompt</tt> if the file window is dedicated to saving files,
 *   causes the window to generate a message box if the selected file already exists.
 *   The user must confirm whether to overwrite the file.
 *   </ul>
 */
        CATDlgFile( CATDialog *iParent, const CATString& iDialogObjectName, 
                    CATDlgStyle iStyle=NULL);
/**
 * Constructs a file selection box.
 * <br><b>Role</b>: Constructs a file selection box. 
 * @param iParent
 *   The parent of the CATDlgFile. 
 * @param iDialogObjectName
 *   The dialog object name. 
 * @param iStyle
 *   The application window styles. You can cumulate several
 *   styles using a logical or.
 *   <br><b>Legal values</b>: 
 *   <ul>
 *   <li><tt>NULL</tt>(default):The 
 *   file window features the OK and Cancel push buttons (it is dedicated 
 *   to opening files), </li> 
 *   <li><tt>CATDlgWndModal</tt>:In addition to the default 
 *   style, the file window is modal (that is, no interaction is possible outside 
 *   this window as long as it is displayed). Under Windows, the file window is modal
 *   whatever the style specified. </li>  
 *   <li><tt>CATDlgWndAPPLY</tt>: 
 *   In addition to the default style, the file window features 
 *   the Apply push button. This style is ignored under Windows.</li> 
 *   <li><tt>CATDlgWndHELP</tt>: In addition to the default style, the file window features 
 *   the Help push button. This style is ignored under Windows.</li>
 *   <li><tt>CATDlgFileSave</tt>: The file window is dedicated to saving files. 
 *   (the Open push button is replaced by the Save push button),</li> 
 *   <li><tt>CATDlgFileMultisel</tt>: The file window enables the
 *   file multiple selection,</li>
 *   <li><tt>CATDlgFolderChooser</tt>: The file window is dedicated
 *   to select a folder.</li>
 *   <li><tt>CATDlgFileOverwritePrompt</tt> if the file window is dedicated to saving files,
 *   causes the window to generate a message box if the selected file already exists.
 *   The user must confirm whether to overwrite the file.
 *   </ul>
 */
        CATDlgFile( CATInteractiveApplication *iParent, const CATString& iDialogObjectName, 
                    CATDlgStyle iStyle=NULL);
/**
 * @nodoc 
 */
        virtual ~CATDlgFile();

//      Directory management
/**
 * Sets the directory whose contents is currently displayed.
 * <br>Under Windows, the method is ignored if called after window is displayed.
 * @param iCurrentDirectory
 *   The current directory path.
 */
        void SetDirectory( const CATUnicodeString& iCurrentDirectory);
/**
 * Gets the directory whose contents is currently displayed.
 * @param oCurrentDirectory 
 *   The current directory path.
 */
        void GetDirectory( CATUnicodeString& oCurrentDirectory);

//      Filter management
/**
 * Sets the filter string.
 * @param iCurrentFilter
 *   The current filter.
 */
        void SetFilterPattern( const CATUnicodeString& iCurrentFilter);
/**
 * Gets the current filter (UNIX only).
 * @param oCurrentFilter
 *   The current filter.
 */
        void GetFilterPattern( CATUnicodeString& oCurrentFilter);

//      File management
/**
 * Sets the file name field contents.
 * @param iFileName
 *   The file name field contents.
 */
        void SetFileName( const CATUnicodeString& );

//      Get selected file
/**
 * Gets the selected file.
 * @param oSelectedFile
 *   The selected file.
 */
        void GetSelection( CATUnicodeString& oSelectedFile);
/**
 * Gets the selected files.
 * @param oSelectedFiles
 *   The selected files names.
 * @param iInputAllocatedSize
 *   The size you allocated for the oSelectedFiles parameter.
 */
        int  GetSelection( CATUnicodeString* oSelectedFiles, int iInputAllocatedSize);
/**
 * Gets the selected files count.
 * @return 
 *   The selected files count.
 */
        int  GetSelectionCount();

//      Set/get window labels
/**
 * Sets the filter label.
 * Ignored on Windows.
 * @param iLabel
 *   The label for the filter.
 */
        void SetFilterLabel( const CATUnicodeString& iLabel);
/**
 * Sets the directories label.
 * Ignored on Windows.
 * @param iLabel
 *   The label for the directories.
 */
        void SetDirectoriesLabel( const CATUnicodeString& );
/**
 * Sets the files label.
 * Ignored on Windows.
 * @param iLabel
 *   The label for the files.
 */
        void SetFilesLabel( const CATUnicodeString& );
/**
 * Sets the selection label.
 * Ignored on Windows.
 * @param iLabel
 *   The label for the selection.
 */
        void SetSelectionLabel( const CATUnicodeString& );
/**
 * Gets the filter label.
 * @return iLabel
 *   The filter label.
 */
        CATUnicodeString GetFilterLabel();
/**
 * Gets the directories label.
 * @return iLabel
 *   The directories label.
 */
        CATUnicodeString GetDirectoriesLabel();
/**
 * Gets the files label.
 * @return iLabel
 *   The files label.
 */
        CATUnicodeString GetFilesLabel();
/**
 * Gets the selection label.
 * @return iLabel
 *   The selection label.
 */
        CATUnicodeString GetSelectionLabel();

//      Set/get window buttons
/**
 * Sets the OK button title.
 * Ignored on Windows.
 * @param iTitle
 *   The OK button title.
 */
        void SetOKTitle( const CATUnicodeString& iTitle);
/**
 * Sets the APPLY button title.
 * Ignored on Windows.
 * @param iTitle
 *   The APPLY button title.
 */
        void SetAPPLYTitle( const CATUnicodeString& iTitle);
/**
 * Sets the FILTER button title.
 * Ignored on Windows.
 * @param iTitle
 *   The FILTER button title.
 */
        void SetFILTERTitle( const CATUnicodeString& iTitle);
/**
 * Sets the CANCEL button title.
 * Ignored on Windows.
 * @param iTitle
 *   The CANCEL button title.
 */
        void SetCANCELTitle( const CATUnicodeString& iTitle);
/**
 * Sets the HELP button title.
 * Ignored on Windows.
 * @param iTitle
 *   The HELP button title.
 */
        void SetHELPTitle( const CATUnicodeString& iTitle);
/**
 * Gets the OK button title.
 * @param iTitle
 *   The OK button title.
 */
        CATUnicodeString GetOKTitle();
/**
 * Gets the APPLY button title.
 * @param iTitle
 *   The APPLY button title.
 */
        CATUnicodeString GetAPPLYTitle();
/**
 * Gets the FILTER button title.
 * @param iTitle
 *   The FILTER button title.
 */
        CATUnicodeString GetFILTERTitle();
/**
 * Gets the CANCEL button title.
 * @param iTitle
 *   The CANCEL button title.
 */
        CATUnicodeString GetCANCELTitle();
/**
 * Gets the HELP button title.
 * @param iTitle
 *   The HELP button title.
 */
        CATUnicodeString GetHELPTitle();

/**
 * Sets the OK button sensitivity.
 * The sensitivity specifies the access to the user through selection. 
 * @param iSensitivity
 *   The OK button sensitivity.
 *   <br><b>Legal values</b>: <tt>CATDlgEnable</tt> so that the 
 *   OK button can be selected, or 
 *   <tt>CATDlgDisable</tt> otherwise.
 */
        void SetOKSensitivity( CATULong iSensitivity );
/**
 * Sets the APPLY button sensitivity.
 * The sensitivity specifies the access to the user through selection.  
 * @param iSensitivity
 *   The APPLY button sensitivity.
 *   <br><b>Legal values</b>: <tt>CATDlgEnable</tt> so that the 
 *   APPLY button can be selected, or 
 *   <tt>CATDlgDisable</tt> otherwise.
 */
        void SetAPPLYSensitivity( CATULong iSensitivity );
/**
 * Sets the FILTER button sensitivity.
 * The sensitivity specifies the access to the user through selection.  
 * @param iSensitivity
 *   The FILTER button sensitivity.
 *   <br><b>Legal values</b>: <tt>CATDlgEnable</tt> so that the 
 *   FILTER button can be selected, or 
 *   <tt>CATDlgDisable</tt> otherwise.
 */
        void SetFILTERSensitivity( CATULong iSensitivity );
/**
 * Sets the CANCEL button sensitivity.
 * The sensitivity specifies the access to the user through selection.  
 * @param iSensitivity
 *   The CANCEL button sensitivity.
 *   <br><b>Legal values</b>: <tt>CATDlgEnable</tt> so that the 
 *   CANCEL button can be selected, or 
 *   <tt>CATDlgDisable</tt> otherwise.
 */
        void SetCANCELSensitivity( CATULong iSensitivity );
/**
 * Sets the HELP button sensitivity.
 * The sensitivity specifies the access to the user through selection.  
 * @param iSensitivity
 *   The HELP button sensitivity.
 *   <br><b>Legal values</b>: <tt>CATDlgEnable</tt> so that the 
 *   HELP button can be selected, or 
 *   <tt>CATDlgDisable</tt> otherwise.
 */
        void SetHELPSensitivity( CATULong iSensitivity );
/**
 * Gets the OK button sensitivity.
 * The sensitivity specifies the access to the user through selection.  
 * @return 
 *   The OK button sensitivity.
 *   <br><b>Legal values</b>: <tt>CATDlgEnable</tt> if the 
 *   OK button can be selected, or 
 *   <tt>CATDlgDisable</tt> otherwise.
 */
        CATULong GetOKSensitivity();
/**
 * Gets the APPLY button sensitivity.
 * The sensitivity specifies the access to the user through selection.  
 * @return 
 *   The APPLY button sensitivity.
 *   <br><b>Legal values</b>: <tt>CATDlgEnable</tt> if the 
 *   APLLY button can be selected, or 
 *   <tt>CATDlgDisable</tt> otherwise.
 */
        CATULong GetAPPLYSensitivity();
/**
 * Gets the FILTER button sensitivity.
 * The sensitivity specifies the access to the user through selection.  
 * @return 
 *   The FILTER button sensitivity.
 *   <br><b>Legal values</b>: <tt>CATDlgEnable</tt> if the 
 *   FILTER button can be selected, or 
 *   <tt>CATDlgDisable</tt> otherwise.
 */
        CATULong GetFILTERSensitivity();
/**
 * Gets the CANCEL button sensitivity.
 * The sensitivity specifies the access to the user through selection.  
 * @return 
 *   The CANCEL button sensitivity.
 *   <br><b>Legal values</b>: <tt>CATDlgEnable</tt> if the 
 *   CANCEL button can be selected, or 
 *   <tt>CATDlgDisable</tt> otherwise.
 */
        CATULong GetCANCELSensitivity();
/**
 * Gets the HELP button sensitivity.
 * The sensitivity specifies the access to the user through selection.  
 * @return 
 *   The HELP button sensitivity.
 *   <br><b>Legal values</b>: <tt>CATDlgEnable</tt> if the 
 *   HELP button can be selected, or 
 *   <tt>CATDlgDisable</tt> otherwise.
 */
        CATULong GetHELPSensitivity();

//      type of file combo access ( Windows only)
/**
 * Sets the type filter combo strings (Windows only).
 * @param iTypeDescriptionList
 *   The type filter descriptions array.
 * @param iTypeExtensionsList
 *   The type filter extensions array.
 * @param iTypeFilterCount
 *   The type filter count.
 */
        void SetFilterStrings( CATUnicodeString *iTypeDescriptionList, 
                               CATString *iTypeExtensionsList, int iTypeFilterCount);
/**
 * Gets the type filter combo strings (Windows only).
 * @param oTypeDescriptionList
 *   The type filter descriptions array.
 * @param oTypeExtensionsList
 *   The type filter extensions array.
 * @param iInputAllocatedSize
 *   The size you allocated for oTypeDescriptionList and oTypeExtensionsList.
 */
        int  GetFilterStrings( CATUnicodeString *oTypeDescriptionList, 
                               CATString *oTypeExtensionsList, 
                               int iInputAllocatedSize);
/**
 * Sets the active item in the type filter combo (Windows only).
 * @param iActiveItem
 *   The active item.
 */
        void SetActiveFilterIndex( int iActiveItem );
/**
 * Gets the active item in the type filter combo (Windows only).
 * @return
 *   The active item.
 */
        int  GetActiveFilterIndex();
/**
 * Sets the file access to the read only value (Windows only).
 * @param iFlag
 *   The boolean value.
 */
        void SetReadOnlyState( int iFlag );
/**
 * Gets the file access type (Windows only).
 * @return
 *   The boolean value specifying if the access is read only.
 */
        int  GetReadOnlyState();

//      get event notifications
/** 
 * Returns the CATDiaOKNotification event notification.
 * It is sent by CATDlgFile whenever 
 * the OK push button is pressed.
 */
        CATNotification *GetDiaOKNotification() const;
/** 
 * Returns the CATDiaCANCELNotification event notification.
 * It is sent by CATDlgFile whenever 
 * the CANCEL push button is pressed.
 */
        CATNotification *GetDiaCANCELNotification() const;
/** 
 * Returns the CATDiaAPPLYNotification event notification.
 * It is sent by CATDlgFile whenever 
 * the APPLY push button is pressed.
 */
        CATNotification *GetDiaAPPLYNotification() const;
/** 
 * Returns the CATDiaHELPNotification event notification.
 * It is sent by CATDlgFile whenever 
 * the HELP push button is pressed.
 */
        CATNotification *GetDiaHELPNotification() const;

/**
 * @nodoc 
 * Returns the CATDlgFileSelectNotification event notification.
 * It is sent by CATDlgFile whenever 
 * the selected file is changed.
 */
        CATNotification *GetDlgFileSelectNotification() const;

/**
 * @nodoc 
 * Get internal object
 */
        virtual l_CATDialog* GetLetterObject();

/**
 * @nodoc 
 * Resets the internal object.
 */
        virtual void ResetLetterObject();

/**
 * @nodoc 
 * Runs the dialog window in a modal loop.
 * @return
 *  an integer identifying the button which has been pressed.
 * <br><b>Legal values:</b>
 * <dl>
 * <dt><tt>0</tt><dd> The Cancel button has been pressed. </dd></dt>
 * <dt><tt>1</tt><dd> The OK button has been pressed. </dd></dt>
 * </dl>
 */
        HRESULT DisplayBlocked();

/**
 * @nodoc
 * Requests the ClassName, IsA, and IsAKindOf methods to be created.
 */
        CATDeclareClass ;

//--------------------------------------------------------------------------
 protected:

//--------------------------------------------------------------------------
 private:

/**
 * @nodoc 
 * default constructor
 */
        CATDlgFile();        

/**
 * @nodoc 
 * address of internal object.
 */
        l_CATDlgFile* _frameFile;
};
#endif
