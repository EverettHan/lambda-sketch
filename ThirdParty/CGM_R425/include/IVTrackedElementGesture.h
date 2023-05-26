// COPYRIGHT Dassault Systemes 2020
//===================================================================
//
// IVTrackedElementGesture.h
// Header definition of IVTrackedElementGesture
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2020  Creation: 
//===================================================================
#ifndef IVTrackedElementGesture_H
#define IVTrackedElementGesture_H

#include "IVInterfaces.h"

#include "CATMathTransformation.h"
// System
// -----------------------------------
#include "IVGesture.h"


struct IVTrackedElementData
{
  IVAtomicID deviceID; // Controller or hand
  IVAtomicID trackedElementID; // Useful in case of hand tracking, to track a specific part of the hand.
  CATMathTransformation axis;

  bool operator == (const IVTrackedElementData& element) const {
    return deviceID == element.deviceID && trackedElementID == element.trackedElementID;
  };

  bool operator != (const IVTrackedElementData& element) const {
    return !(*this == element);
  };
};



//-----------------------------------------------------------------------
class ExportedByIVInterfaces IVTrackedElementGesture : public IVGesture
{
  CATDeclareClass;

public:

  //Constructor/Destructor
  // -----------------------------------
  IVTrackedElementGesture(const CATUnicodeString& iName);
  virtual ~IVTrackedElementGesture();

  IVTrackedElementGesture(IVTrackedElementGesture const&);
  IVTrackedElementGesture& operator=(IVTrackedElementGesture const&);

  IVTrackedElementData TrackedElementData() const;
protected:

  friend class IVSpatialMoveOverGestureRecognizer;

  IVTrackedElementData _trackedElementData;

private:

  // Standard, Copy constructor and equal operator
  // -----------------------------------
  IVTrackedElementGesture(IVTrackedElementGesture &);
  IVTrackedElementGesture& operator=(IVTrackedElementGesture&);
};
//-----------------------------------------------------------------------

#endif




