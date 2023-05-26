#ifndef CATI3DCompassVRManipulator_h
#define CATI3DCompassVRManipulator_h

// COPYRIGHT DASSAULT SYSTEMES 2005

// This class is for compass internal use only.
// Please don't use it.

#include "CATAfrSelection.h"
#include "CATBaseUnknown.h"

extern ExportedByCATAfrSelection IID IID_CATI3DCompassVRManipulator;

//#include "CATMathPoint.h"
//#include "CATMathDirection.h"
#include "CATString.h"

class CAT3DViewer;
class CAT3DViewpoint;
class CATMathAxis;
class CATMathPoint;
class CATMathDirection;
class CATCommand;
class CAT3DRep;
class CAT3DManipulator;

class ExportedByCATAfrSelection CATI3DCompassVRManipulator : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  virtual CAT3DManipulator * Create(CATCommand * iFather, const CATString &iName,CAT3DRep * iRep) = 0;

  virtual void SetTranslationXYZ(
    const CATMathDirection & dirX, const CATMathDirection & dirY, const CATMathDirection & dirZ) = 0;
  virtual void BeginFeedback(const CATMathPoint & Position) =0;
  virtual void UpdateFeedback(const CATMathPoint &) =0;

  virtual void VRConnect(CAT3DViewer * Viewer, CAT3DViewpoint * VRViewpoint) =0;
  virtual void VRDisconnect() =0;
  virtual const int GetDeviceType() =0;
  virtual void SetDeviceManipulationMode(const int mode, CATMathAxis * iAxis) =0;

  
};


#endif
