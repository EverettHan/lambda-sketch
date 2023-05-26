#ifndef CATFrmObjectEditor_H_
#define CATFrmObjectEditor_H_

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATFrmEditor.h"
#include "CATAfrFoundation.h"

class CATPathElement;
class CATBaseUnknown;
class CATCmdContainer;

/**
 * Class for an object editor.
 * <b>Role</b>: The object editor is an instance of the <tt>CATFrmObjectEditor</tt>
 * class associated with an object instance which represents the data this editor edits. It is returned by 
 * the <tt>GetEditor</tt> method of the @href CATIEditor implementation.
 * @see CATFrmEditor
 */
class ExportedByCATAfrFoundation CATFrmObjectEditor: public CATFrmEditor
{
  CATDeclareClass;

public:

  /**
   * Constructs an object editor.
   * @param ipEditedObject
   *   The edited object.
   *   <br><b>Legal values</b>: A non null pointer to the edited object
   *   implementation.
   * @see CATIEditor, CATIDocumentEdit
   */
  CATFrmObjectEditor (CATBaseUnknown * ipEditedObject);
  ~CATFrmObjectEditor ();

  /**
   * Returns the edited object.
   * @return
   *   The edited object.
   */
  CATBaseUnknown * GetEditedObject();

  /** @nodoc */
  virtual void Activate ();
  /** @nodoc */
  virtual void Deactivate ();
  /** @nodoc */
  virtual CATFrmWindow * CreateDefaultWindow ();

#ifdef _WINDOWS_SOURCE
  /** 
   * @nodoc
   * For OLE Server.
   */
  virtual HANDLE MemoryDraw(CLIPFORMAT Format, int width, int height);
#endif

  /** @nodoc */
  virtual CATCmdContainer * GetContextualMenu ();
  /** @nodoc */
  virtual CATCmdContainer * GetDefaultContextualMenu ();


private:

  CATBaseUnknown * _pEditedObject;
};

#endif
