/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef _CATIFmuDialogBox_h
#define _CATIFmuDialogBox_h


#include "CATBaseUnknown.h"

#include "CATUnicodeString.h"
class CATCommand;
class CATNotification;
class CATIDocEnvironment;
class CATDocument;
class CATIDocId;

/**
 * Access to standard dialog boxes of File menu.
 * <b>Role</b>: Manage standard File menu dialog boxes.<br>
 * <b>Lifecycle rules:</b> the dialog box's destruction must be required by calling @href #RequestDelayedDestruction
 * and then it must be released by calling @href #Release.<br>
 * If the caller is a @href CATCommand and not a @href CATDialog, you should call<pre>
 *    CATCommand *pCmd = pDlgBox->GetEventPublisher();
 *    pCmd->SetFather(<the caller>);</pre>
 * in order to let the caller recieve the notifications.
 */
// Note for implementation
// -----------------------
// CATIFmuDialogBox::RequestDelayedDestruction() + CATIFmuDialogBox::Release() -> 2 Release().
// Take care that the implementation's reference counter must be 2 once the implementation is created.

#include "CATFmuFileAccessItfCPP.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATFmuFileAccessItfCPP IID IID_CATIFmuDialogBox;
#else
extern "C" const IID IID_CATIFmuDialogBox;
#endif

class ExportedByCATFmuFileAccessItfCPP CATIFmuDialogBox : public CATBaseUnknown
{
	public:

		CATDeclareInterface;

		/**
		* Gets the document environment 
		* @return  CATBaseUnknown#Release
		*   The document environment of the dialog box
		*/
		virtual CATIDocEnvironment* GetDocEnvironment()=0;

		/**
		* Gets the selection
		* @param oSelection
		*   The selection which depends on the context:<br>
		*   - the file name to open<br>
		*   - the file name to save as<br> 
		*	  - the folder or a DLName 
		*/
		virtual void GetSelection(CATUnicodeString& oSelection)=0;

		/**
		* Gets the count of the selected files to open (Open context only)..
		* @return 
		*   The selected files count.
		*/
		virtual int  GetSelectionCount()=0;

		/**
		* Gets the selected files to open (Open context only)..
		* @param oSelection
		*   The selected names.
		* @param iInputAllocatedSize
		*   The size you allocated for the oSelections parameter.
		*/
		virtual int  GetSelection(CATUnicodeString* oSelections,
								  int iInputAllocatedSize)=0;

		/**
		* Gets the selected document identifier
		* @param oDocId [out, CATBaseUnknown#Release]
		*   The identifier of the selected document, according to box type :<br>
		*   - the document to open<br>
		*   - the document to save as
		*/
		virtual void GetDocId(CATIDocId** oDocId)=0;

		/**
		* Gets the selected documents to open (Open context only)..
		* @param oDocIds
		*   The selected document identifiers.
		* @param iInputAllocatedSize
		*   The size you allocated for the oDocIds parameter.
		*/
		virtual int  GetDocId(CATIDocId*** oDocIds,
								int iInputAllocatedSize)=0;

		/**
		* Reads the current extension filter.
		* @return
		*   The string value specifying the extension filter.
		*/
		virtual CATUnicodeString GetExtension()=0;

		/**
		* Reads the current description filter.
		* @return
		*   The string value specifying the description filter.
		*/
		virtual CATUnicodeString GetDescription()=0;
    
		/**
		* Sets the type filter combo strings.
		* @param iTypeDescriptionList
		*   The type filter descriptions array.
		* @param iTypeExtensionsList
		*   The type filter extensions array.
		* @param iTypeFilterCount
		*   The type filter count.
		*/
		virtual void SetFilterStrings( CATUnicodeString *iTypeDescriptionList, 
									   CATString *iTypeExtensionsList,
									   int iTypeFilterCount)=0;

		/**
		* Set the active item in the type filter combo.
		* @param iActiveFilter
		*   The active filter.
		*/
        virtual void SetActiveFilterIndex(int iActiveFilter)=0;

		/**
		* Get the active filter in the type filter combo.
		* @return
		*   The active filter.
		*/
        virtual int GetActiveFilterIndex()=0;
									   
		/**
		* Sets the directory whose contents is currently displayed.
		* @param iCurrentDirectory
		*   The current directory path.
		*/
		virtual void SetDirectory( const CATUnicodeString& iCurrentDirectory)=0;

		/**
		* Gets the directory whose contents is currently displayed.
		* @param oCurrentDirectory 
		*   The current directory path.
		*/
		virtual void GetDirectory( CATUnicodeString& oCurrentDirectory)=0;

		/**
		* Sets the file name field contents.
		* @param iFileName
		*   The file name field contents.
		*/
		virtual void SetFileName( const CATUnicodeString& iFileName)=0;

		/**
		* Gets the file access type (Open context only).
		* @return
		*   The boolean value specifying if the access is read only.
		*/
		virtual int  GetReadOnlyState() =0;
		
		/**
		* Sets the document to save (for Save only).
		* @param iDocumentToSave
		*   The document to save.
		*/
		virtual HRESULT SetDocumentToSave(CATDocument* iDocumentToSave)=0;
		
		/**
		* Sets the document to save (for Save only).
		* @param iDocumentToSave
		*   The document to save.
		*/
		virtual HRESULT SetDocumentToSave(CATUnicodeString iDocumentToSave)=0;

		/**
		* Sets the title of the dialog object to the specified character string. 
		* @param iTitle
		* The title to be displayed.
		*/
		virtual void SetTitle( const CATUnicodeString& iTitle)=0;

		/**
		* Returns the current display state of the dialog object.
		*   <br>
		* The visibility state can be :
		*   <dl>
		*   <dt><tt>CATDlgShow</tt><dd> if the dialog object is shown,
		*   <dt><tt>CATDlgHide</tt><dd> if the dialog object is hidden.
		*   </dl>
		*/
		virtual unsigned long GetVisibility()=0;

		/**
		* Sets the display state of the dialog object.
		* @param iState
		* The visibility state to set.
		*   <br>
		*   <b>Legal values</b> : It can be set to either :
		*   <dl>
		*   <dt><tt>CATDlgShow</tt><dd> to show the dialog object,
		*   <dt><tt>CATDlgHide</tt><dd> to hide the dialog object.
		*   </dl>
		*/
		virtual void SetVisibility( unsigned long iState)=0;

		/**
		* Gets the event publisher.
		* @return 
		*   The event publisher.
		*/
		virtual CATCommand * GetEventPublisher()=0;
		/**
		* Gets the ok notification.
		* @return 
		*   The ok notification.
		*/
		virtual CATNotification * GetDiaOKNotification()=0;
		/**
		* Gets the cancel notification.
		* @return 
		*   The cancel notification.
		*/
		virtual CATNotification * GetDiaCANCELNotification()=0;

		/**
		* Requests the command delayed destruction.
		* <br><b>Role</b>: The command will ve destroyed as soon as this will be possible.
		*/
		virtual void RequestDelayedDestruction()=0;

};

#endif
