#ifndef CATDLGSTDFILE_H
#define CATDLGSTDFILE_H

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//------------------------------------------------------------------------------
// Abstract: The base class for file selection box
//
//------------------------------------------------------------------------------
// Usage:    Assign a CATDlgStdFile to a CATDlgDocument.
//------------------------------------------------------------------------------
// Inheritance UNIX: CATDlgStdFile
//                     CATDlgDialog
//                       CATDlgWindow
//                         CATDialog
// Inheritance Windows: CATDlgStdFile
//                        CATDlgFile
//                          CATDlgDialog
//                            CATDialog
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
//           SetFilterStrings           set types of files
//           GetFilterStrings           get types of files
//           SetActiveFilterIndex       set current type of files
//           GetReadOnlyState           get value on read only checkButton
//           SetReadOnlyState           set value on read only checkButton
//------------------------------------------------------------------------------
// Events:
//
//           GetDiaOKNotification       selection of Open, Save or OK button
//           GetDiaCANCELNotification   selection of CANCEL button
//------------------------------------------------------------------------------
// Styles:
//
//           CATDlgWndModal
//           CATDlgStdFileMultisel
//------------------------------------------------------------------------------

#include "CATDlgStandard.h"
#include "CATListOfCATUnicodeString.h"
#include <time.h>

#include "DI0PANV2.h"

#ifdef DRIVER_WINDOWS
#define MODE_CATDLGFILE
#endif
#ifdef DRIVER_MOTIF
#define NO_MODE_CATDLGFILE
#endif
#if defined (DRIVER_COCOA) || defined (DRIVER_ANDROID)
#define MODE_CATDLGFILE
#endif
#ifdef DRIVER_DYNAMIC
#define MODE_CATDLGFILE
#endif

#ifdef MODE_CATDLGFILE
#include "CATDlgFile.h"
#else
#include "CATDlgDialog.h"
#endif

#include "CATDlgNotification.h"

// 2 includes kept to avoid build problems 
#include "CATLib.h"
#include "CATMsgCatalog.h"

class CATDlgCheckButton;
class CATDlgCombo;
class CATDlgEditor;
class CATDlgFrame;
class CATDlgLabel;
class CATDlgMultiList;
class CATDlgNotify;
class CATDlgPushButton;
class CATDlgRadioButton;
class CATDlgSelectorList;

class CATSettingRepository;
class CATUnicodeString;

//--------------------------------------------------------------------------
/**
 * Class delivering a file or folder selection box.
 * <b>Role</b>: Enables a file or folder selection.
 * This window offers a file selection box with a filter to 
 * apply to search for files or a folder selection box.
  * <p>
 * Under Windows, a standard Windows file or folder selection box is displayed. 
 * <br>As so, the box texts follow the installation language of the Operatings System and not the language
 * selected for this software.
 * <br>Under Unix, a window partly emulating a Windows file or folder selection box is displayed. 
* <p>
 * This window is used to list, select, open or save files or to list
 * and select folders.
 * <p>
 * The purpose of most methods below is to initialize the file/folder selection 
 * box. Once the box ended, the application will have to interfere
 * only when the following events occur:
 * <ul>
 * <li>CATDiaOKNotification (when, according to the type of window, the Open, Save or OK push button is pressed)</li>
 * <li>CATDiaCANCELNotification (when the CANCEL push button is pressed)</li>
 * </ul>
 * In the meantime, all the dialog is managed by this software.
 */

#ifdef MODE_CATDLGFILE
class ExportedByCATDlgStandard CATDlgStdFile : public CATDlgFile
#else
class ExportedByCATDlgStandard CATDlgStdFile : public CATDlgDialog
#endif
{
  /** @nodoc */
  CATDeclareClass;

//--------------------------------------------------------------------------
 public:

//      constructors - destructor
/**
 * Constructs an Open file selection box.
 * <br><b>Role</b>: Constructs a file selection box dedicated to opening files.
 * @param iParent
 *   The parent of the CATDlgStdFile object.
 *   The parent must be an instance of a class that derives 
 *   from CATDlgDocument.
 * @param iDialogObjectName
 *   The dialog object name. 
 * @param iStyle
 *   The application window style. 
 *   <br><b>Legal values</b>:
 *   <tt>NULL (default)</tt> 
 *   <tt>CATDlgWndModal</tt> if the file window is modal (that is, no interaction is possible outside 
 *   this window as long as it is displayed). Under Windows the window is always modal.
 *
 * @param iStdStyle
 *   Defines the activity of differents check buttons. You can cumulate several
 *   styles using a logical or.
 *   <br><b>Legal values</b>:
 *   <tt>CATDlgStdFileMultisel</tt> if the file window enables the
 *   file multiple selection, or
 *   <tt>CATDlgStdFileReadOnly</tt> so that the
 *   file window contains a check button for the read mode. Under Windows,
 *   the check button is available whatever the style.
 *   <tt>CATDlgStdFileOverwritePrompt</tt> if the file window is dedicated to saving files,
 *   causes the window to generate a message box if the selected file already exists.
 *   The user must confirm whether to overwrite the file.
 * @param iavailableExtensions
 *   Defines a list of filters for the open context.
 *   You may pass an empty list and define the types of files using
 *   @href #SetFilterStrings.
 */
        CATDlgStdFile( CATDialog *iParent, const CATString& iDialogObjectName, 
                       CATDlgStyle iStyle, CATDlgStyle iStdStyle,
                       const CATListOfCATUnicodeString& iavailableExtensions);
/**
 * Constructs a Save file selection box.
 * <br><b>Role</b>: Constructs a file selection box dedicated to saving files.
 * @param iParent
 *   The parent of the CATDlgStdFile object.
 *   The parent must be an instance of a class that derives 
 *   from CATDlgDocument. * @param iDialogObjectName
 *   The dialog object name. 
 * @param iStyle
 *   The application window style. 
 *   <br><b>Legal values</b>: <tt>NULL (default)</tt> 
 *   or <tt>CATDlgWndModal</tt> if the file window is modal (that is, no interaction is possible outside 
 *   this window as long as it is displayed). Under Windows, the window is always modal.
 *
 * @param iavailableExtensions
 *   Defines a list of filters for the open context.
 *   You may pass an empty list and define the types of files using
 *   @href #SetFilterStrings.
 */
        CATDlgStdFile( CATDialog *iParent, const CATString& iDialogObjectName, 
                       CATDlgStyle iStyle, const CATListOfCATUnicodeString& iavailableExtensions);
/**
 * Constructs a folder selection box.
 * <br><b>Role</b>: Constructs a folder selection box. 
 * @param iParent
 *   The parent of the CATDlgStdFile object.
 *   The parent must be an instance of a class that derives 
 *   from CATDlgDocument.
 * @param iDialogObjectName
 *   The dialog object name. 
 * @param iStyle
 *   The application window style. .
 *   <br><b>Legal values</b>: <tt>NULL (default)</tt> 
 *   or <tt>CATDlgWndModal</tt> if the file window is modal (that is, no interaction is possible outside 
 *   this window as long as it is displayed). Under Windows, the window is always modal.
 */
        CATDlgStdFile( CATDialog *iParent, const CATString& iDialogObjectName,
                       CATDlgStyle iStyle);
/**
 * @nodoc 
 */
        virtual ~CATDlgStdFile();

#ifndef MODE_CATDLGFILE
//      Directory management
/**
 * Sets the directory whose contents is currently displayed.
 * <br>Under Windows, the method is ignored if called after window is displayed.
 * @param iCurrentDirectory
 *   The directory path to be made current
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
 * Sets the filter string (open context and save context).
 * @param iCurrentFilter
 *   The current filter.
 */
        void SetFilterPattern( const CATUnicodeString& iCurrentFilter);
/**
 * Gets the current filter (open context and save context).
 * @param oCurrentFilter
 *   The current filter.
 */
        void GetFilterPattern( CATUnicodeString& oCurrentFilter);
/**
 * nodoc
 * not implemented on Windows. Is an alternative to SetFilterStrings
 * Sets the list of available extensions (open context and save context).
 * @param iavailableExtensions
 *   The current list.
 */
        void SetListAvailableExtensions (const CATListOfCATUnicodeString& iavailableExtensions);

//      File management
/**
 * Sets the file name field contents.
 * @param iFileName
 *   The file name field contents.
 */
        void SetFileName( const CATUnicodeString&);

//      Get selected file or folder
/**
 * Gets the selected file or folder.
 * @param oSelection
 *   The selected file or folder.
 */
        void GetSelection( CATUnicodeString& oSelection);
/**
 * Gets the selected files or the selected folder.
 * @param oSelections
 *   The selected files names or the selected folder name.
 * @param iInputAllocatedSize
 *   The size you allocated for the oSelections parameter.
 */
        int GetSelection( CATUnicodeString* oSelections, int iInputAllocatedSize);
/**
 * Gets the selected files count or the selected folder count.
 * @return 
 *   The selected files count or the selected folder count.
 */
        int  GetSelectionCount();

//      Set/get window labels
/**
 * Overwrites the default filter label.
 * Ignored on Windows.
 * @param iLabel
 *   The label for the filter.
 */
        void SetFilterLabel( const CATUnicodeString& iLabel);
/**
 * Overwrites the default directories label.
 * Ignored on Windows.
 * @param iLabel
 *   The label for the directories.
 */
        void SetDirectoriesLabel( const CATUnicodeString& iLabel);
/**
 * Overwrites the default files label.
 * Ignored on Windows.
 * @param iLabel
 *   The label for the files.
 */
        void SetFilesLabel( const CATUnicodeString& iLabel);
/**
 * Overwrites the default selection label.
 * Ignored on Windows.
 * @param iLabel
 *   The label for the selection.
 */
        void SetSelectionLabel( const CATUnicodeString& iLabel);
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

//      type of file combo access
/**
 * Sets the type filter combo strings.
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
 * Gets the type filter combo strings.
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
 * Sets the active item in the type filter combo.
 * @param iActiveItem
 *   The active item.
 */
        void SetActiveFilterIndex( int iActiveItem);
/**
 * Gets the active item in the type filter combo.
 * @return
 *   The active item.
 */
        int  GetActiveFilterIndex();

/**
 * Sets the file access to the read only value (open context only).
 * @param iFlag
 *   The boolean value.
 */
        void SetReadOnlyState( int iFlag);
/**
 * Gets the file access type (open context only).
 * @return
 *   The boolean value specifying if the access is read only.
 */
        int  GetReadOnlyState();

/**
 * @nodoc 
 * Sets the preview activity (open context only).
 * @param iFlag
 *   The boolean value.
 */
        void SetPreviewState( int iFlag);
/**
 * @nodoc 
 * Gets the preview activity (open context only).
 * @return
 *   The boolean value specifying if the preview mode is activated.
 */
        int  GetPreviewState();

/**
 * @nodoc 
 * Gets the current extension filter (open context and save context).
 * @return
 *   The current extension filter.
 */
        CATUnicodeString GetExtension();
/**
 * @nodoc 
 * Gets the current description filter (open context and save context).
 * @return
 *   The current extension filter.
 */
        CATUnicodeString GetDescription();

//      Button management
/**
 * @nodoc 
 */
        void SetFILTERTitle( const CATUnicodeString&);

/**
 * @nodoc 
 */
        CATUnicodeString GetFILTERTitle();

/**
 * @nodoc 
 */
        void SetFILTERSensitivity( CATULong cst);

/**
 * @nodoc 
 */
        CATULong GetFILTERSensitivity();

/**
 * @nodoc 
 */
        HRESULT DisplayBlocked();

/**
 * @nodoc 
 * Returns the CATDlgFileSelectNotification event notification.
 * It is sent by CATDlgFile whenever the selected file is changed.
 */
        static inline CATNotification *GetDlgFileSelectNotification()
               { return _Static_v_file_select; }
#endif

//--------------------------------------------------------------------------

 private:

//      default constructor
/**
 * @nodoc 
 */
        CATDlgStdFile();        

#ifndef MODE_CATDLGFILE
/**
 * @nodoc 
 */
        void setDirectory(CATUnicodeString& ioCurrentDirectory);

/**
 * @nodoc 
 */
        void fillPatterns(const CATUnicodeString& iFileName);

/**
 * @nodoc 
 */
        void tildeManagement(CATUnicodeString *ioSelections, int iSelectionsNumber);

/**
 * @nodoc 
 */
        void commonInit(CATDlgStyle, CATDlgStyle iStdStyle=NULL);

//      Sort method
/**
 * @nodoc 
 */
        static int mySortMethod(CATUnicodeString, CATUnicodeString);

//      Closing the window sends the cancel modification
/**
 * @nodoc 
 */
        void DismissNotify(CATCommand*, CATNotification*, CATCommandClientData);
/**
 * @nodoc 
 */
        void OnWindClose(CATCommand*, CATNotification*, CATCommandClientData);
/**
 * @nodoc 
 */
        void OnSelectDirNameCombo(CATCommand*, CATNotification*, CATCommandClientData);
/**
 * @nodoc 
 */
        void OnModifyDirNameCombo(CATCommand*, CATNotification*, CATCommandClientData);
/**
 * @nodoc 
 */
        void OnUpPushB(CATCommand*, CATNotification*, CATCommandClientData);
/**
 * @nodoc 
 */
        void OnCreatePushB (CATCommand*, CATNotification*, CATCommandClientData);
/**
 * @nodoc 
 */
        void OnRadBModifyListOrDetails(CATCommand*, CATNotification*, CATCommandClientData);
/**
 * @nodoc 
 */
        void FillFileMultiList(const int iDirName, const int iFilter);
/**
 * @nodoc 
 */
        void OnContextualMenu(CATCommand*, CATNotification*, CATCommandClientData);
/**
 * @nodoc 
 */
        void OnEditCell(CATCommand*, CATNotification*, CATCommandClientData);
/**
 * @nodoc 
 */
        void OnSelectFileMultiList(CATCommand*, CATNotification*, CATCommandClientData);
/**
 * @nodoc 
 */
        void OnActivateFileMultiList(CATCommand*, CATNotification*, CATCommandClientData);
/**
 * @nodoc 
 */
        void OnEditModifyFileNameEditor(CATCommand*, CATNotification*, CATCommandClientData);
/**
 * @nodoc 
 */
        void MakePath(const CATUnicodeString& iDirName, const CATUnicodeString& iFileName,
                      CATUnicodeString& oFilePath);
/**
 * @nodoc 
 */
        CATBool IsADirectory(const CATUnicodeString& iFolder, const CATUnicodeString& iFile, CATBool iNotify=FALSE);
/**
 * @nodoc 
 */
        CATBool IsAFile(const CATUnicodeString& iFolder, const CATUnicodeString& iFile);
/**
 * @nodoc 
 */
        HRESULT GetFileInfo(const CATUnicodeString& iFolder, const CATUnicodeString& iFile,
                            CATBool& oDirectory, int& oSize, time_t& oModified);
/**
 * @nodoc 
 */
        void OnSelectFileTypeCombo(CATCommand*, CATNotification *, CATCommandClientData);
/**
 * @nodoc 
 */
        void SpecialSendNotification(CATNotification *p_notif);

/**
 * @nodoc 
 */
        void updateSettings();
#endif
/**
 * @nodoc 
 */
        enum CATDlgContextType {
        CATDlgStdFileOPEN = 0,
        CATDlgStdFileSAVEAS = 1,
        CATDlgStdFileCHOOSE = 2
        };

//      Context : open (0:default), save (1:if iStyle & CATDlgFileSave)
//      or directory chooser (2:if iStyle & CATDlgFolderChooser)
        CATDlgContextType _Context;

#define MaxDirNameNumber 15
//      Get the available DirNames
//      pointer on an array of strings, each one being a DirName
        CATUnicodeString _DirNames[MaxDirNameNumber];
//      number of DirNames
        int _DirNameNumber;

//      Selection in the list
//      Open and Save : the files; DirNameChooser : the selected DirName
        CATUnicodeString* _Selections;
//      number of selections
        int _SelectionsCount;

//      Patterns in the input
//      Open : the files
        CATUnicodeString* _Patterns;
//      number of patterns
        int _PatternsCount;
//      search flags for patterns
        CATBool _FirstPattern;
        CATBool _LastPattern;

//      ---------------------------------------------------------------------
//      Open and Save contexts

//      DirNames
        int _CurrentDirName;
        CATDlgCombo* _DirNameCombo;

//      Up Push Button
        CATDlgPushButton* _UpPushButton;

//      File list with details or without details
        CATDlgRadioButton* _ListRadioButton;
        CATDlgRadioButton* _DetailsRadioButton;

//      File multi lists
        CATDlgFrame* _FileListFrame;
//      the default list without details (displayed when the _ListRadioButton is checked)
        CATDlgMultiList* _FileMultiList;
//      the list with details (displayed in place of _FileMultiList if _DetailsRadioButton checked)
        CATDlgMultiList* _FileMultiListWithDetails;

//      File or Folder name
        CATDlgEditor* _FileNameEditor;

//      For errors
        CATDlgNotify* _Error;

//      Filter types
        CATDlgCombo* _FilesOfTypeCombo;
//      the current line in _FilesOfTypeCombo (one line may contain several extensions)
        int _CurrentFilter;
//      extension of the document to open or to save
        CATUnicodeString _CurrentExtension;

//      --------------------------------------------------------------------
//      Differents labels

        CATDlgLabel* _lookInLabel;
        CATDlgLabel* _fileNameLabel;
        CATDlgLabel* _filesOfTypeLabel;

//      --------------------------------------------------------------------
//      Open context only

//      Check button "open as read only" (appears only in the open context)
        CATDlgCheckButton* _OpenAsReadOnlyCheckButton;

//      Check button "preview" (appears only in the open context)
        CATDlgCheckButton* _PreviewCheckButton;

//      Last selected filter in open context
        static int _DefaultFilterInOpenContext;

//      Contextual menu
        static int _HideFolders;
        static int _HideSystemFiles;
        static int _HideFoldersWD;
        static int _HideSystemFilesWD;

        int _OpenReadOnly;
        int _Preview;
        int _OverwritePrompt;

//      --------------------------------------------------------------------
//      Save context only

//      Set the document name in the file editor
//      Set the list of the extensions allowed for the document to save
//      Set the number of extensions in the list
        CATUnicodeString _FileName;

//      --------------------------------------------------------------------
//      List of the descriptions and extensions

//      list of the descriptions (ex: All Files, All CATIA V5 Files, ...)
        CATListOfCATUnicodeString _FilterDesc;
//      list of the extensions (ex: *.*, *.txt, *.tif, *.CATPart, ...)
        CATListOfCATUnicodeString _FilterExt;

        int _FilterNumber;

        CATListOfCATUnicodeString _AvailableExtensions;
 
        static CATDlgFileSelectNotification * _Static_v_file_select;

//--------------------------------------------------------------------------
#ifndef MODE_CATDLGFILE
//      --------------------------------------------------------------------
//      Record-Replay management
//      --------------------------------------------------------------------
 private:
/**
 * @nodoc 
 */
        CATUnicodeString _tempDirectorie, _tempSelection; // kept for V5R9 - V5R9 SP1 compat
        int _response;
//      --------------------------------------------------------------------
//      Rename management
//      --------------------------------------------------------------------
        CATUnicodeString _oldPath;
 public:
/**
 * @nodoc 
 */
        virtual int SaveState(CATNotification *, CATMarshal &);
/**
 * @nodoc 
 */
        virtual int RestoreState(CATNotification *, CATMarshal &);

#endif

};
#endif
