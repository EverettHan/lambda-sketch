#ifndef CATIWorkshopCustomInterface_h
#define CATIWorkshopCustomInterface_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrSelection.h"
#include "CATBaseUnknown.h"

extern ExportedByCATAfrSelection IID IID_CATIWorkshopCustomInterface;

class ExportedByCATAfrSelection CATIWorkshopCustomInterface : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  virtual HRESULT GetCustomInterface(IID * ioNewIID) = 0;
};

#endif
