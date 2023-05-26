#ifndef __CATIDropManager_h
#define __CATIDropManager_h

// COPYRIGHT DASSAULT SYSTEMES 2000
// Implement this interface on your workbench ([workbenchName]_init late type)
// if you want the drop source and target to be specialized while your workbench is current.

#include "CATAfrFoundation.h"
#include "CATBaseUnknown.h"

class CATFrmDropSource;
class CATFrmDropTarget;
class CATFrmEditor;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrFoundation IID IID_CATIDropManager;
#else
extern "C" const IID IID_CATIDropManager;
#endif

class ExportedByCATAfrFoundation CATIDropManager: public CATBaseUnknown {

  CATDeclareInterface;

public:

  // These 2 methods are called by Select command during Drag and Drop operations.
  // The editor pointer is the editor currently under the cursor.
  // It is different from the current editor during a drag on a not current editor.
  virtual CATFrmDropSource * GetDropSource (CATFrmEditor * & ipEditor) = 0;
  virtual CATFrmDropTarget * GetDropTarget (CATFrmEditor * & ipEditor) = 0;

};

CATDeclareHandler (CATIDropManager, CATBaseUnknown);

#endif//__CATIDropManager_h
