#ifndef __CATEWorkbenchExit_h
#define __CATEWorkbenchExit_h

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATAfrFoundation.h"
#include "CATBaseUnknown.h"

class CATPathElement;
class CATFrmEditor;


class ExportedByCATAfrFoundation CATEWorkbenchExit : public CATBaseUnknown {
	
  CATDeclareClass;
  
public:

  CATEWorkbenchExit ();
  virtual ~CATEWorkbenchExit ();

  virtual HRESULT GetExitPath (CATFrmEditor * iEditor, CATPathElement * oExitPath);
  virtual HRESULT BeforeExit (CATFrmEditor * iEditor);
  virtual HRESULT AfterExit (CATFrmEditor * iEditor);

    
private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATEWorkbenchExit (const CATEWorkbenchExit &);
  CATEWorkbenchExit & operator= (const CATEWorkbenchExit &);
};


#endif
