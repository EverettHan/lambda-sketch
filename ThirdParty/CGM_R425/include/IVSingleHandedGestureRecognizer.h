//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2020
//===================================================================

#ifndef IVSingleHandedGestureRecognizer_H
#define IVSingleHandedGestureRecognizer_H

// IVInterfaces
// -----------------------------------
#include "IVGestureRecognizer.h"
#include "IVDeviceAtomicType.h"
#include "IVGestureDataSet.h"
#include "IVISUIEntity.h"

// Mathematics
// -----------------------------------
#include "CATMathTransformation.h"

//-----------------------------------------------------------------------
class IVSingleHandedGestureRecognizer : public IVGestureRecognizer
{
  CATDeclareClass;

public:

  //Constructor/Destructor
  // -----------------------------------
  IVSingleHandedGestureRecognizer();
  virtual ~IVSingleHandedGestureRecognizer();

  virtual IVGesture* GetGesture();

  // Methods For Subclasses
  // -----------------------------------
  virtual void OnButtonEvent(CATBaseUnknown* ipSender, const IVButtonEvtArgs* ipArgs);
  virtual void OnSUIEntityEvent(CATBaseUnknown* ipSender, const IVSUIEntityEvtArgs* ipArgs);
  virtual void OnTrackerEvent(CATBaseUnknown* ipSender, const IVTrackerEvtArgs* ipArgs);

  // Getter/Setter
  // -----------------------------------
  inline IVISUIEntity_var HandEntity() const { return _trackerEntity; };
  inline void SetHandEntity(IVISUIEntity_var iHand) { _trackerEntity = iHand; };
  inline IVAtomicID ButtonAtomicID() const { return _buttonAtomicID; };
  inline void SetButtonAtomicID(IVAtomicID iButtonID) { _buttonAtomicID = iButtonID; };
  inline void SetTrackedDevice(IVAtomicID iTrackedDeviceID) { _trackedDeviceID = iTrackedDeviceID; };
  inline IVAtomicID TrackedDeviceID() const { return _trackedDeviceID; };
  inline void SetTrackedElement(IVAtomicID iTrackedElementID) { _trackedElementID = iTrackedElementID; };
  inline IVAtomicID TrackedElementID() const { return _trackedElementID; };

protected:

  // Raw Data
  // -----------------------------------
  CATMathTransformation GestureBeganLocation();
  CATMathTransformation GestureLocation();
  CATMathTransformation PreviousGestureLocation();

  IVGestureDataSet & GestureDataSet();

  // Single handed Gesture - to overload in single handed each gesture
  // -----------------------------------
  virtual void OnMoveOver();
  virtual void OnDragBegan();
  virtual void OnDragChanged();
  virtual void OnDragEnded();

  // Inner Data
  //-----------------------------
  virtual void ResetGestureData();

  IVISUIEntity_var _trackerEntity;
  IVAtomicID _buttonAtomicID;
  IVAtomicID _trackedDeviceID;
  IVAtomicID _trackedElementID;

  CATMathTransformation _handPose;
  CATLONG64 _handPoseTimeStamp;

  unsigned int _buttonButtonState;
  CATBoolean _isDragged;

  HRESULT RegisterCurrGestureData();
  HRESULT RegisterHandLocation(CATMathTransformation &iHand, CATLONG64 &iTime);
  void ResetHandLocationList();
  virtual int DefaultMaxLocationsItemsInList();//to override in each gesture
  IVGestureDataSet _gestureDataSet;

  // STATE - OVERLOAD HOOK
  //----------------------
  virtual HRESULT ActivateInternal();
  virtual HRESULT DesactivateInternal();

  // Single handed Gesture
  // -----------------------------------
  void OnButtonStateChangedInternal(unsigned int buttonValue);
  void OnMoveOverInternal(CATMathTransformation& iPose, CATLONG64 iSystemTime);
  void OnDragBeganInternal();
  void OnDragChangedInternal(CATMathTransformation& iPose, CATLONG64 iSystemTime);
  void OnDragEndedInternal();

private:

  // Standard, Copy constructor and equal operator
  // -----------------------------------
  IVSingleHandedGestureRecognizer(IVSingleHandedGestureRecognizer &);
  IVSingleHandedGestureRecognizer& operator=(IVSingleHandedGestureRecognizer&);
};
//-----------------------------------------------------------------------
#endif




