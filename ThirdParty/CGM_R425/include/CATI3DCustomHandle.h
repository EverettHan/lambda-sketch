#ifndef CATI3DCustomHandle_h
#define CATI3DCustomHandle_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrSelection.h"
#include "CATBaseUnknown.h"

class CATMathTransformation;

extern ExportedByCATAfrSelection IID IID_CATI3DCustomHandle;

class ExportedByCATAfrSelection CATI3DCustomHandle : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  //
  // Interface servant au d�placement de toutes les poign�es 
  // (standard-CAT3DHandleManager + personnalis�es) 
  virtual HRESULT BeginMoveHandle(CATMathTransformation * iTransformation) = 0;
  virtual HRESULT MoveHandle(CATMathTransformation * iTransformation) = 0;
  virtual HRESULT EndMoveHandle(CATMathTransformation * iTransformation) = 0;
};

CATDeclareHandler(CATI3DCustomHandle, CATBaseUnknown);

#endif
