#ifndef CATIComSidlProcessor_h
#define CATIComSidlProcessor_h

#include "CATComSidl.h"
#include "CATBaseUnknown.h"

extern ExportedByCATComSidl IID IID_CATIComSidlProcessor;

class ExportedByCATComSidl CATIComSidlProcessor: public CATBaseUnknown
{
   CATDeclareInterface;
   
public:
   virtual HRESULT Execute(const char * iRequest,
      int iSize,
      char*& oResponse,
      int & oSize)=0;
   
};

#endif









