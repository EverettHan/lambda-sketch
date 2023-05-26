#ifndef CATOleAutoInit_h
#define CATOleAutoInit_h


// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS0DSPA.h"
#include "CATBoolean.h"
#include "IUnknown.h"

class CATBaseDispatch;

/**
 * Initialization of OLE Automation
 * @deprecated
 */
ExportedByJS0DSPA HRESULT __stdcall CATOleInitialize( void);

/**
 * Close the OLE library, freeing the ressources
 * @deprecated
 */
ExportedByJS0DSPA void  CATOLECleanUp(void);

#endif // CATOleAutoInit_h









