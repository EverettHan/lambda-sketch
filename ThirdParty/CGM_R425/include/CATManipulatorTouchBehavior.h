#ifndef CATManipulatorTouchBehavior_H
#define CATManipulatorTouchBehavior_H

// COPYRIGHT DASSAULT SYSTEMES 2011

#include "CATVisFoundation.h"
#include "CATBaseUnknown.h"
class CATManipulator;
class VisMultitouchDeviceEvent;

class ExportedByCATVisFoundation CATManipulatorTouchBehavior : public CATBaseUnknown
{
public:

  CATDeclareClass;

  CATManipulatorTouchBehavior();
  
  virtual ~CATManipulatorTouchBehavior();
  
/** @nodoc */
  void SetActivateOnDownHoldTouchGesture(int iFlag); // appel de Activate sur le geste DownHold au lieu de Down
/** @nodoc */
  int GetActivateOnDownHoldTouchGesture() const;

/** @nodoc */
  void SetMoveOnFlickTouchGesture(int iFlag);
/** @nodoc */
  int GetMoveOnFlickTouchGesture() const;

/** @nodoc */
  void SetManipulateOnFlickTouchGesture(int iFlag);
/** @nodoc */
  int GetManipulateOnFlickTouchGesture() const;

/** @nodoc */
  void SetMoveOnPinchTouchGesture(int iFlag);
/** @nodoc */
  int GetMoveOnPinchTouchGesture() const;

/** @nodoc */
  void SetManipulateOnPinchTouchGesture(int iFlag);
/** @nodoc */
  int GetManipulateOnPinchTouchGesture() const;

/** @nodoc */
  void SetMoveOnPanTouchGesture(int iFlag);
/** @nodoc */
  int GetMoveOnPanTouchGesture() const;

/** @nodoc */
  void SetManipulateOnPanTouchGesture(int iFlag);
/** @nodoc */
  int GetManipulateOnPanTouchGesture() const;

/** @nodoc */
  void SetMoveOnRotateTouchGesture(int iFlag);
/** @nodoc */
  int GetMoveOnRotateTouchGesture() const;

/** @nodoc */
  void SetManipulateOnRotateTouchGesture(int iFlag);
/** @nodoc */
  int GetManipulateOnRotateTouchGesture() const;

/** @nodoc */
  void SetMoveOnAllTouchGesture(int iFlag);
/** @nodoc */
  int GetMoveOnAllTouchGesture() const;

/** @nodoc */
  void SetManipulateOnAllTouchGesture(int iFlag);
/** @nodoc */
  int GetManipulateOnAllTouchGesture() const;

/** @nodoc */
  void SetReactivateOnDownTouchGesture(int iFlag);
/** @nodoc */
  int GetReactivateOnDownTouchGesture() const;

/** @nodoc */
  virtual void AcceptHandOverToForTouchGesture(const CATManipulatorTouchBehavior* ipManipulationReceiver, const VisMultitouchDeviceEvent& iMultitouchEvent, int& oAgreement) const;
/** @nodoc */
  virtual void AcceptTakeOverFromForTouchGesture(const CATManipulatorTouchBehavior* ipManipulationGiver, const VisMultitouchDeviceEvent& iMultitouchEvent, int& oAgreement) const;

/** If the manipulator is set as standalone, all the touch contacts that begin on it even after a first touch will be splitted and the corresponding touch event will be sent to this particular manipulator. */
/** @nodoc */
  void SetAsStandaloneManipulator(int iFlag);
/** @nodoc */
  int IsStandaloneManipulator() const;

/** @nodoc */
  void SetInactiveTouch(int iFlag);
/** @nodoc */
  int GetInactiveTouch() const;

  // d6f: 2 and 3 fingers hold
/** @nodoc */
  void SetActivateOnTwoFingersHoldGesture(int iFlag);
/** @nodoc */
  int GetActivateOnTwoFingersHoldGesture() const;

/** @nodoc */
  void SetActivateOnThreeFingersHoldGesture(int iFlag);
/** @nodoc */
  int GetActivateOnThreeFingersHoldGesture() const;

/** @nodoc */
  void SetShowMagnifier(int iFlag);
/** @nodoc */
  int GetShowMagnifier() const;
  // d6f: ----- End -----

private:

  int _ActivateOnDownHoldGesture;
  int _MoveOnFlickGesture;
  int _ManipulateOnFlickGesture;
  int _MoveOnPinchGesture;
  int _ManipulateOnPinchGesture;
  int _MoveOnPanGesture;
  int _ManipulateOnPanGesture;
  int _MoveOnRotateGesture;
  int _ManipulateOnRotateGesture;
  int _MoveOnAllGesture;
  int _ManipulateOnAllGesture;
  int _ReactivateOnDownGesture;
  int _StandaloneMode;
  int _InactiveTouch;
  int _ActivateOnTwoFingersHoldGesture;
  int _ActivateOnThreeFingersHoldGesture;
  int _ShowMagnifier;
};


#endif
