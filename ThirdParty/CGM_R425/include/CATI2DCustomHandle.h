#ifndef CATI2DCustomHandle_h
#define CATI2DCustomHandle_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrSelection.h"
#include "CATBaseUnknown.h"

class CATMathTransformation2D;

extern ExportedByCATAfrSelection IID IID_CATI2DCustomHandle;

class ExportedByCATAfrSelection CATI2DCustomHandle : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  virtual HRESULT BeginMoveHandle(CATMathTransformation2D * iTransformation) = 0;
  virtual HRESULT MoveHandle(CATMathTransformation2D * iTransformation) = 0;
  virtual HRESULT EndMoveHandle(CATMathTransformation2D * iTransformation) = 0;
};

CATDeclareHandler(CATI2DCustomHandle, CATBaseUnknown);

#endif
