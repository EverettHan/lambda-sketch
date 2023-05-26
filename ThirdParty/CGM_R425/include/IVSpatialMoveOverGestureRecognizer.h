//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2020
//===================================================================

#ifndef IVSpatialMoveOverGestureRecognizer_H
#define IVSpatialMoveOverGestureRecognizer_H

// IVInterfaces
// -----------------------------------
#include "IVSingleHandedGestureRecognizer.h"
#include "IVDeviceAtomicType.h"

class IVTrackedElementGesture;

//-----------------------------------------------------------------------
class IVSpatialMoveOverGestureRecognizer : public IVSingleHandedGestureRecognizer
{
  CATDeclareClass;

public:

  //Constructor/Destructor
  // -----------------------------------
  IVSpatialMoveOverGestureRecognizer();
  virtual ~IVSpatialMoveOverGestureRecognizer();

  virtual IVGesture* GetGesture();

protected:

  // Single handed Gesture - to overload in single handed each gesture
  // -----------------------------------
  virtual void OnMoveOver();

private:

  IVTrackedElementGesture* _trackedElementGesture;

  // Standard, Copy constructor and equal operator
  // -----------------------------------
  IVSpatialMoveOverGestureRecognizer(IVSpatialMoveOverGestureRecognizer &);
  IVSpatialMoveOverGestureRecognizer& operator=(IVSpatialMoveOverGestureRecognizer&);
};
//-----------------------------------------------------------------------
#endif
