#ifndef __CATIWorkbenchExit_h
#define __CATIWorkbenchExit_h

// COPYRIGHT DASSAULT SYSTEMES 2000 

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

class CATFrmEditor;
class CATPathElement;

extern ExportedByCATAfrItf IID IID_CATIWorkbenchExit;

class ExportedByCATAfrItf CATIWorkbenchExit : public CATBaseUnknown {
	
  CATDeclareInterface;
  
public:

	virtual HRESULT GetExitPath (CATFrmEditor * iEditor, CATPathElement * oPath) = 0;
	
	virtual HRESULT BeforeExit (CATFrmEditor * iEditor) = 0;

	virtual HRESULT AfterExit (CATFrmEditor * iEditor) = 0;

};

CATDeclareHandler (CATIWorkbenchExit, CATBaseUnknown);

#endif
