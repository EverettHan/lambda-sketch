// COPYRIGHT DASSAULT SYSTEMES 2003

#ifndef CATISpaceDriver_h
#define CATISpaceDriver_h

#include "CATVisFoundation.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisFoundation IID IID_CATISpaceDriver;
#else
extern "C" const IID IID_CATISpaceDriver;
#endif

class CATGraphicWindow;

class ExportedByCATVisFoundation CATISpaceDriver : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual HRESULT RegisterWindow(CATGraphicWindow *pWindow) = 0;
  virtual HRESULT UnregisterWindow(CATGraphicWindow *pWindow) = 0;
  virtual HRESULT ForceActiveWindow(int force) = 0;
};

#endif
