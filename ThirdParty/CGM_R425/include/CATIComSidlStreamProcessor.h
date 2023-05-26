#ifndef CATIComSidlStreamProcessor_h
#define CATIComSidlStreamProcessor_h

#include "CATComSidl.h"
#include "CATBaseUnknown.h"

class CATIComSidlInputStream;
class CATIComSidlOutputStream;

extern ExportedByCATComSidl IID IID_CATIComSidlStreamProcessor;

class ExportedByCATComSidl CATIComSidlStreamProcessor: public CATBaseUnknown
{
   CATDeclareInterface;
   
public:
   virtual HRESULT Execute(CATIComSidlInputStream*iRequest,CATIComSidlOutputStream*oResponse)=0;
};

#endif









