//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2020
//===================================================================

#ifndef IVGestureRecognizer_H
#define IVGestureRecognizer_H

// IVInterfaces
// -----------------------------------
#include "IVInterfaces.h"

// UIVCoreTools
// -----------------------------------
#include "CATSYPEventArgs.h"

// System
// -----------------------------------
#include "CATCommand.h"

// IVInterfaces
// -----------------------------------
#include "IVDeviceDataType.h"
class IVButtonEvtArgs;
class IVAnalogEvtArgs;
class IVTrackerEvtArgs;
class IVSUIEntityEvtArgs;
class IVGestureRecognizerOnTimeoutCmd;
class IVGesture;

class IVGesturePossible :
  public CATNotification
{
  CATDeclareClass;
public:
  IVGesturePossible();
  virtual ~IVGesturePossible();
};

class IVGestureBegan :
  public CATNotification
{
  CATDeclareClass;
public:
  IVGestureBegan();
  virtual ~IVGestureBegan();
};

class IVGestureChanged :
  public CATNotification
{
  CATDeclareClass;
public:
  IVGestureChanged();
  virtual ~IVGestureChanged();
};

class IVGestureEnded :
  public CATNotification
{
  CATDeclareClass;
public:
  IVGestureEnded();
  virtual ~IVGestureEnded();
};

class IVGestureCancelled :
  public CATNotification
{
  CATDeclareClass;
public:
  IVGestureCancelled();
  virtual ~IVGestureCancelled();
};

class IVGestureRecognized :
  public CATNotification
{
  CATDeclareClass;
public:
  IVGestureRecognized();
  virtual ~IVGestureRecognized();
};


// IVGestureRecognizerState
// -----------------------------------
typedef enum
{
    IVGestureStateUnknown
  , IVGestureStatePossible
  , IVGestureStateBegan
  , IVGestureStateChanged
  , IVGestureStateEnded
  , IVGestureStateFailed
  , IVGestureStateCancelled
  , IVGestureStateRecognized //Discrete Gestures
} IVGestureRecognizerState;

class ExportedByIVInterfaces IVGestureRecognizer : public CATCommand
{
  CATDeclareClass;

public:

  ULONG GetRefCount();

  //Constructor/Destructor
  // -----------------------------------
  IVGestureRecognizer(CATCommand *iFather, const CATString &iName);
  IVGestureRecognizer();
  virtual ~IVGestureRecognizer();

  //
  virtual IVGesture* GetGesture();

  // IDENTITY
  //----------------------
  inline CATUnicodeString Name() const { const char* name = _gestureRecoName.ConvertToChar(); CATUnicodeString unicodeName(name); return unicodeName; };

  // NOTIFICATIONS
  // -----------------------------------
  //Continuous Gestures
  CATNotification * GetGesturePossibleNotification();
  CATNotification * GetGestureBeganNotification();
  CATNotification * GetGestureChangedNotification();
  CATNotification * GetGestureEndedNotification();
  CATNotification * GetGestureCancelledNotification();

  //Discrete Gestures
  CATNotification * GetGestureRecognizedNotification();

  // METHODS TO OVERRIDE IN SUBCLASSES
  // -----------------------------------
  virtual void OnButtonEvent(CATBaseUnknown* ipSender, const IVButtonEvtArgs* ipArgs);
  virtual void OnAnalogEvent(CATBaseUnknown* ipSender, const IVAnalogEvtArgs* ipArgs);
  virtual void OnTrackerEvent(CATBaseUnknown* ipSender, const IVTrackerEvtArgs* ipArgs);
  virtual void OnSUIEntityEvent(CATBaseUnknown* ipSender, const IVSUIEntityEvtArgs* ipArgs);
  virtual void BeginEventProcessing();
  virtual void StopEventProcessing();

  virtual IVGestureRecognizerState OnUserInteraction(CATCommand * ipFrom, CATNotification * ipNotif);
  virtual IVGestureRecognizerState OnAnalogEvent(CATBaseUnknown* ipListener, CATSYPEventArgs* ipArgs);
  virtual IVGestureRecognizerState OnButtonEvent(CATBaseUnknown* ipListener, CATSYPEventArgs* ipArgs);

  virtual IVGestureRecognizerState OnTrackerEvent(IVAtomicID iID, void * ipData);

  // GESTURE STATE
  // -----------------------------------
  IVGestureRecognizerState State() const;
  CATBoolean ModifiedState() const;

  // STATE
  //----------------------
  HRESULT Activate();
  HRESULT Desactivate();
  inline CATBoolean Activity() const { return _activity; };

protected:

  // GESTURE STATE
  // -----------------------------------
  HRESULT SetState(const IVGestureRecognizerState & iState);

  // COUNTDOWN
  //-------------------------------------------------
  //to override in each gesturereco using the timer
  virtual void OnCountDownOverInternalCB();

  HRESULT StartCountDown(const int & iTime, void * ipClientData);
  HRESULT StopCountDown();

  friend class IVGestureRecognizerOnTimeoutCmd;
  static void OnTimeOutOver(IVGestureRecognizer * ipGestureRecognizer);

  // STATE - OVERLOAD HOOK
  // STATE - OVERLOAD HOOK
  //----------------------
  virtual HRESULT ActivateInternal();
  virtual HRESULT DesactivateInternal();
  CATBoolean _activity;

private:

  // GESTURE STATE
  // -----------------------------------
  IVGestureRecognizerState _state;
  CATBoolean _modifiedState;

  // NOTIFICATIONS
  // -----------------------------------
  CATNotification       * _pGesturePossibleNotification;
  CATNotification       * _pGestureBeganNotification;
  CATNotification       * _pGestureChangedNotification;
  CATNotification       * _pGestureEndedNotification;
  CATNotification       * _pGestureCancelledNotification;
  CATNotification       * _pGestureRecognizedNotification;

  // IDENTITY
  // -----------------------------------
  CATString _gestureRecoName;

  // TIMER CB
  // -----------------------------------
  IVGestureRecognizerOnTimeoutCmd* _pTimeOutCmd;

  // Standard, Copy constructor and equal operator
  // -----------------------------------
  IVGestureRecognizer(IVGestureRecognizer &);
  IVGestureRecognizer& operator=(IVGestureRecognizer&);
};

//-----------------------------------------------------------------------
#endif
