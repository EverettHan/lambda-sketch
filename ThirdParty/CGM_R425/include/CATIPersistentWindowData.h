#ifndef CATIPERSISTENTWINDOWDATA_H
#define CATIPERSISTENTWINDOWDATA_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrFoundation.h"
//===========================================================================
// General Interface for persistent Window Data
//===========================================================================
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrFoundation IID IID_CATIPersistentWindowData;
#else
extern "C" const IID IID_CATIPersistentWindowData;
#endif
class  ExportedByCATAfrFoundation CATIPersistentWindowData : public CATBaseUnknown
{
   CATDeclareInterface;
   
   public:
      virtual void  GetWindowData(void ** stream, unsigned long& length) =0 ;
      virtual void  SetWindowData(void *  stream, unsigned long  length) =0 ;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------
CATDeclareHandler(CATIPersistentWindowData, CATBaseUnknown);

#endif
