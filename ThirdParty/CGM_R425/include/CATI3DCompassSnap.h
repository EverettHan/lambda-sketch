#ifndef CATI3DCompassSnap_h
#define CATI3DCompassSnap_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrSelection.h"
#include "CATBaseUnknown.h"

extern ExportedByCATAfrSelection IID IID_CATI3DCompassSnap;

class CATPathElement;
class CATMathAxis;
class CATMathDirection;

class ExportedByCATAfrSelection CATI3DCompassSnap : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  // ioTargetAxis : Input is decoded axis by default implementation
  //                Output is axis modified by application
  // TargetDimension : 0 target is point
  //                   1 target is a line or a curve
  //                   2 target is a plane or a surface
  //                  -1 target is undefined

  virtual HRESULT Snap(CATPathElement * iPath, 
                       CATMathDirection * iEyeDirection,
                       CATMathAxis * ioTargetAxis,
                       int * ioTargetDimension) = 0;
};

CATDeclareHandler(CATI3DCompassSnap, CATBaseUnknown);

#endif
