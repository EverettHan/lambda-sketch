#ifndef CATISelectMove2D_h
#define CATISelectMove2D_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrSelection.h"
#include "CATBaseUnknown.h"

class CATMathTransformation2D;

extern ExportedByCATAfrSelection IID IID_CATISelectMove2D;

class ExportedByCATAfrSelection CATISelectMove2D : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  virtual HRESULT Init(CATBaseUnknown ** ioMoveAgent) = 0;
  virtual HRESULT End() = 0;

  virtual HRESULT BeginMove(CATMathTransformation2D * ioTransformation) = 0;
  virtual HRESULT Move(CATMathTransformation2D * ioTransformation) = 0;
  virtual HRESULT EndMove(CATMathTransformation2D * ioTransformation) = 0;
};

CATDeclareHandler(CATISelectMove2D, CATBaseUnknown);

#endif
