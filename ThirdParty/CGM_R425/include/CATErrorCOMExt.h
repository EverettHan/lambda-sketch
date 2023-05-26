#ifndef __CATErrorCOMExt
#define __CATErrorCOMExt


// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATBaseUnknown.h"
#include "JS0ERROR.h"
 

//
// Error management for catia exposed interfaces 
//
class ExportedByJS0ERROR CATErrorCOMExt : public CATBaseUnknown
{

   CATDeclareClass;
   
 public:

   CATErrorCOMExt();
   virtual ~CATErrorCOMExt();
  
   
   HRESULT __stdcall InterfaceSupportsErrorInfo(REFIID riid );

 

};
#endif
