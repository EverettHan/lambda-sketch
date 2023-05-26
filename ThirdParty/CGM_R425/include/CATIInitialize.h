#ifndef CATIInitialize_h
#define CATIInitialize_h

// COPYRIGHT DASSAULT SYSTEMES 2001

#include "JS0CORBA.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByJS0CORBA IID IID_CATIInitialize;
#else
extern "C" const IID IID_CATIInitialize;
#endif


class ExportedByJS0CORBA CATIInitialize: public CATBaseUnknown
{
   CATDeclareInterface;
   public :
      virtual HRESULT __stdcall Init(int flag = 0 ) = 0;
};

#endif
