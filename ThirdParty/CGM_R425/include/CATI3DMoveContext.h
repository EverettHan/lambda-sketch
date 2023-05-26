#ifndef CATI3DMoveContext_h
#define CATI3DMoveContext_h

// COPYRIGHT DASSAULT SYSTEMES 2002

#include "CATAfrSelection.h"
#include "CATBaseUnknown.h"

class CATFrmEditor;

extern ExportedByCATAfrSelection IID IID_CATI3DMoveContext;

class ExportedByCATAfrSelection CATI3DMoveContext : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  virtual HRESULT GetEditor(CATFrmEditor ** oEditor) = 0;
};

CATDeclareHandler(CATI3DMoveContext, CATBaseUnknown);

#endif
