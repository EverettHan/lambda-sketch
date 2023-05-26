#ifndef IVIAddin_H
#define IVIAddin_H

//COPYRIGHT DASSAULT SYSTEMES 2009

#include "CATVisItf.h"
#include "CATBaseUnknown.h"


extern ExportedByCATVisItf IID IID_IVIAddin;

class ExportedByCATVisItf IVIAddin: public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual HRESULT __stdcall StartAddin(const IID& iIVInterfaceToStart = IID_IUnknown) = 0;
  virtual unsigned int __stdcall HasStarted(const IID& iIVInterfaceToCheck = IID_IUnknown) = 0;
  virtual HRESULT __stdcall StopAddin(const IID& iIVInterfaceToStop = IID_IUnknown) = 0;
};

//------------------------------------------------------------------

#endif // IVIAddin_H
