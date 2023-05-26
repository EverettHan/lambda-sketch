/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2002
#ifndef _CATIFmuDialogFactory_h
#define _CATIFmuDialogFactory_h

#include "CATInteractiveInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATFmuDocChooserEnvironment.h"

#define  CATIFmuDialogFactory_CreateDocumentChooser()  virtual HRESULT CreateDocumentChooser(\
    CATDialog *ipDlgParent,\
    const CATString &iIdentifier,\
    CATFmuDocChooserEnvOptions iEnvOptions,\
    unsigned long iStyle,\
    CATIDocId *ipDefaultDocId,\
    CATIFmuDocChooser *&opDocChooser) = 0


class CATIFmuDocChooser;
class CATIFmuDialogBox;
class CATDialog;
class CATString;
class CATIDocId;
class CATCommand;
class CATDocument;

/**
 * Interface to create file or document related dialog boxes.
 *
 * <br><b>Role</b>: Two distinct dialogs can be created using this factory.
 * A file or folder selection box on one side and a multi-environment document chooser 
 * on the other side. The second one lets the user choose between the available
 * environments (File, ENOVIA, SmarTeam...) and even documents in session 
 * and/or catalog browser if required.<br>
 * You require an interface from CATApplicationFrame::GetFrame(). With the returned interface, you can create a file, folder or document chooser.<br>
 * Sample:<pre>
 *  CATApplicationFrame *pApplicationFrame = CATApplicationFrame::GetFrame();
 *  if (pApplicationFrame != NULL)
 *    hr = pApplicationFrame->QueryInterface(IID_CATIFmuDialogFactory, (void**)&pDocEnvChooserFactory);</pre>
 * This interface is implemented. Don't implement it again.
 */
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATInteractiveInterfaces IID IID_CATIFmuDialogFactory;
#else
extern "C" const IID IID_CATIFmuDialogFactory;
#endif

class ExportedByCATInteractiveInterfaces CATIFmuDialogFactory : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  /**
   * Creates a dialog box of the File menu in the curent document environment.
   * <br><b>Role</b>: Creates a dialog box of the file menu.
   * @param ipDlgParent
   *   The parent class in the CATCommand agregation
   *   hierarchy. The parent must be an instance of a class that derives
   *   from CATDlgInteractiveApplication or CATDlgDocument.
   *   The notifications are first sent to it.<br>
   *   If the caller is a @href CATCommand and not a @href CATDialog , you should call<pre>
   *      CATCommand *pCmd = pDlgBox->GetEventPublisher(); 
   *      pCmd->SetFather(<the caller>);</pre>
   *   in order to let the caller recieve the notifications.
   * @param iDialogObjectName
   *   The dialog object name.
   * @param iStyle
   *   The application window styles. You can cumulate several
   *   styles using a logical or.
   *   <br><b>Legal values</b>: <tt>NULL (default)</tt> so that the
   *   file window features the OK and Cancel push buttons (it is dedicated
   *   to opening files), or <tt>CATDlgWndModal</tt> if, in addition to the default
   *   style, the file window is modal (that is, no interaction is possible outside
   *   this window as long as it is displayed), or <tt>CATDlgWndAPPLY</tt>
   *   if, in addition to the default style, the file window features
   *   the Apply push button, or <tt>CATDlgWndHELP</tt>
   *   if, in addition to the default style, the file window features
   *   the Help push button, or <tt>CATDlgFileMultisel</tt>
   *   if the file window enables the file multiple selection.
   *   or <tt>CATDlgFileSave</tt> if the file window is dedicated to saving files.
   *   (the Open push button is replaced by the Save push button),
   *   or <tt>CATDlgFolderChooser</tt> if the file window is dedicated
   *   to select a Folder. Notice that CATDlgFileSave and CATDlgFolderChooser
   *   styles are mutually exclusive
   * @param oDialogBox [out, CATBaseUnknown#Release]
   *    The created dialog box.
   * @param iDocumentToSave
   *  The document to save in case of a save dialog box else NULL
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL,
   */
  virtual HRESULT CreateFileDialogBox(CATDialog *ipDlgParent,
    const CATString& iDialogObjectName,
    unsigned long iStyle,
    CATIFmuDialogBox*& oDialogBox,
    CATDocument* iDocumentToSave=NULL)=0;

  /**
   * Starts a document selection command.
   * <br><b>Role</b>: The document chooser is created and launched.
   *
   * @param ipDlgParent
   *   The parent in dialog tree. 
   *   The notifications are first sent to it.<br>
   *   If the caller is a @href CATCommand and not a @href CATDialog, you should call<pre>
   *      CATCommand *pCmd = NULL;
   *      HRESULT hr = pDocChooser->GetEventPublisher(pCmd);
   *      if (SUCCEEDED(hr) && CATSysCheckExpression(pCmd != NULL))
   *        pCmd->SetFather(<the caller>);</pre>
   *   in order to let the caller recieve the notifications.
   * @param iIdentifier
   *   The command identifier.
   * @param iEnvOptions
   *   If you want the document chooser to offer the documents opened in the session and/or the catalog access,
   *   you have to specify <tt> @href CATDocChooserInSession </tt> and/or <tt> @href CATDocChooserCatalogBrowser </tt>.
   *   Use the operator OR (|) to separate options.<br>
   * @param iStyle
   *   Dialog options for acquisition management. Use the operator OR (|) to separate options.<br>
   *   <dl>
   *   <dt><tt>CATDlgFileMultisel</tt></dt>
   *     <dd>Multi-selection (the default is only one selection),</dd>
   *   </dl>
   * @param ipDefaultDocId
   *   If the method is called in order to find or replace a document, <tt>ipDefaultDocId</tt> indicates
   *   where the user may look first. For example, with a file environment, the current directory and the file name can be set.
   * @param opDocChooser [out, CATBaseUnknown#Release]
   *   Created CATIFmuDocChooser for acquisition.<br>
   *   If the method succeeds, the pointer must be not NULL, and you'll have to run <tt>Release</tt>.
   *
   * @return
   * Error code
   */
   CATIFmuDialogFactory_CreateDocumentChooser();

};

#endif
