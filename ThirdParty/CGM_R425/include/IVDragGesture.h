// COPYRIGHT Dassault Systemes 2020
//===================================================================
//
// IVDragGesture.h
// Header definition of IVDragGesture
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2020  Creation: 
//===================================================================
#ifndef IVDragGesture_H
#define IVDragGesture_H

#include "IVInterfaces.h"
#include "IVGesture.h"
#include "IVButtonGesture.h"
#include "IVTrackedElementGesture.h"

// Mathematics
// -----------------------------------
#include "CATMathTransformation.h"


//-----------------------------------------------------------------------
class ExportedByIVInterfaces IVDragGesture : public IVGesture
{
  CATDeclareClass;

public:

  //Constructor/Destructor
  // -----------------------------------
  IVDragGesture(const CATUnicodeString& iName);
  virtual ~IVDragGesture();

  IVDragGesture(IVDragGesture const&);
  IVDragGesture& operator=(IVDragGesture const&);

  // State
  // -----------------------------------
  enum IVDragGestureState {
    IV_BUTTON_PRESSED = 0,
    IV_DRAG,
    IV_BUTTON_RELEASED,
  };
  IVDragGestureState DragState() const;

  const CATMathTransformation& DragPose() const;

  IVButtonData ButtonData() const;
  IVTrackedElementData TrackedElementData() const;

protected:

  friend class IVDragGestureRecognizer;

  IVDragGestureState _dragState;
  CATMathTransformation _dragPose;

  IVButtonData _buttonData;
  IVTrackedElementData _trackedElementData;

};
//-----------------------------------------------------------------------

#endif




