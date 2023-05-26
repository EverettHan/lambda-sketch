#ifndef CATI3DCompassSniff_h
#define CATI3DCompassSniff_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrSelection.h"
#include "CATBaseUnknown.h"
#include "CAT3DCompassTypedefs.h"

extern ExportedByCATAfrSelection IID IID_CATI3DCompassSniff;

class CATPathElement;
class CATMathAxis;
class CATMathDirection;

class ExportedByCATAfrSelection CATI3DCompassSniff : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  // Drag and drop from center
  virtual HRESULT BeginDrag() = 0;
  virtual HRESULT Drag(CATPathElement * iPath,
                       CATMathDirection * iEyeDirection,
                       CATMathAxis * ioTargetAxis,
                       int * ioTargetDimension) = 0;
  virtual HRESULT EndDrag() = 0;

  // Move
  virtual HRESULT BeginMove(int * oFreeze) = 0;
  virtual HRESULT Move(CATPathElement * iPath, 
                       CATMathDirection * iEyeDirection,
                       CATMathAxis * iDetectedPosition,
                       CATCompassTransformationType * iTransfoType,
                       CATMathAxis * ioCompassPosition,
                       int * oPositionModified,
                       int * oMoveStateAfterDetection) = 0;
  virtual HRESULT EndMove() = 0;
};

CATDeclareHandler(CATI3DCompassSniff, CATBaseUnknown);

#endif
