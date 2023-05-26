#ifndef CATAfrEditor_H
#define CATAfrEditor_H

// COPYRIGHT DASSAULT SYSTEMES 2008

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATAfrFoundation.h"

class CATIAfrEditor;


class ExportedByCATAfrFoundation CATAfrEditor
{
public:
  /**
   * Returns the current activated editor.
   * <br><b>Role</b>: This method must be carrefully used. 
   * <br>If your are in any method of a <tt>CATStateCommand</tt>, use the GetEditor() method
   * of <tt>CATStateCommand</tt> (inherited from <tt>CATDialogAgent</tt>), to have the 
   * current editor.
   * <br>If you a are in a CATCommand, use <tt>GetCurrentEditor</tt> <b>only</b> in the constructor. Keep
   * a pointer on it, and use this pointer in all methods of the command.
   * <br><b>Legal values</b>: The returned value may be null if
   * no editor is currently activated.
   * <br><b>Lifecycle rules deviation</b>: No AddRef is performed 
   * on the returned value. 
   */
  static CATIAfrEditor * GetCurrentEditor();

};

#endif
