#ifndef CATIDocumentEdit_H_
#define CATIDocumentEdit_H_

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

#include "CATBaseUnknown.h"
#include "CATAfrItf.h"
class CATFrmWindow;
class CATFrmEditor;
class CATPathElement;

#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATAfrItf IID_CATIDocumentEdit;
#else
extern "C" const IID IID_CATIDocumentEdit;
#endif


/**
  * @nodoc : deprecated R217 - Obsolete in V6.
  * Interface to enable the correct behaviour of a document in the
  * MDI (Multiple Document Interface) CATIA application.
  * <b>Role:</b> 
  * <ul>
  * <li> providing data needed for a document's user-interface 
  * intialization (see @href #GetActiveObject , @href #CreateDefaultWindow ),
  * </li>
  * <li> providing informations to the document's about its
  * user interface's state (see @href #Activate, @href #Deactivate ),</li>
  * <li> providing a snapshot of the document in the OLE context
  * (see @href #MemoryDraw )</li>
  * </ul>
  * Every document must implement this interface by an extension of a late
  * type that stands for the document type.
  */
class ExportedByCATAfrItf CATIDocumentEdit : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  
  /**
    * Unused method. It is by-passed by the equivalent method
    * of the editor. An empty implementation of this method is
    * mandatory.
    */
  virtual void  Activate () = 0;

  /**
    * Unused method. It is by-passed by the equivalent method
    * of the editor. An empty implementation of this method is
    * mandatory.
    */
  virtual void  Deactivate () = 0;

  
  /**
    * Creates a window to display a document.
    * <br><b>Role:</b>
    * This method is called to create the first document's window
    * (called the default window). 
    * @param iEditor
    *   The editor associated to the document implementing this
    *   interface
    * @return
    *   The new window.
    * @see CATFrmWindow
    */
  virtual CATFrmWindow * CreateDefaultWindow (CATFrmEditor * iEditor) = 0;
  
  /**
    * Returns a picture containing a snapshot of the document in
    * OLE context. 
    * <br><b>Note:</b> Used on Win9x and WinNT platforms only.
    * <br><b>Role:</b>
    * The purpose of this method is to return
    * an picture of width <tt>iWidth</tt> and height <tt>iHeight</tt>
    * containing a snapshot of the document.
    * The desired picture format is controlled via the <tt>iFormat</tt>
    * argument which real type is the win32 CLIPFORMAT type.
    * The return value is a win32 handle to the picture.
    * @param iFormat
    *   A win32 CLIPFORMAT telling the desired output picture's format.
    * @param iWidth
    *   The desired output picture's width
    * @param iHeight
    *   The desired output picture's height
    * @return
    *   A win32 handle (HANDLE) to the rendered picture.
    */
  virtual void * MemoryDraw (unsigned short iFormat, 
                            int iWidth, 
                            int iHeight) = 0;

  /**
    * Returns a path to the first object to ui-activate.
    * <br><b>Role:</b>
    * The ui-activation manager can't know about the initial
    * object to ui-activate for a newly opened or created document. So
    * the purpose of this method is to create a new @href CATPathElement
    * containing a path in the model to the first ui-activable object to 
    * ui-activate.
    * @return
    *   A path to the first object to ui-activate.
    * @see CATIUIActivate
    */
  virtual CATPathElement GetActiveObject () = 0;

};


CATDeclareHandler(CATIDocumentEdit,CATBaseUnknown);

#endif
