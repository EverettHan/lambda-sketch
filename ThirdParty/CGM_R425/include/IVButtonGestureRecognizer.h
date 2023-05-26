//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2020
//===================================================================

#ifndef IVButtonGestureRecognizer_H
#define IVButtonGestureRecognizer_H

// IVInterfaces
// -----------------------------------
#include "IVGestureRecognizer.h"
#include "IVDeviceAtomicType.h"

class IVButtonGesture;
class IVButtonPressGesture;
class IVButtonHoldGesture;
class IVButtonReleaseGesture;
class IVButtonSqueezeGesture;
class IVButtonTouchedGesture;

//-----------------------------------------------------------------------
class IVButtonGestureRecognizer : public IVGestureRecognizer
{
  CATDeclareClass;

public:

  //Constructor/Destructor
  // -----------------------------------
  IVButtonGestureRecognizer();
  virtual ~IVButtonGestureRecognizer();

  // Get recognized gesture
  // -----------------------------------
  /*
   * @return type : IVButtonGesture
   */
  virtual IVGesture* GetGesture();

  // Methods For Subclasses
  // -----------------------------------
  virtual void OnButtonEvent(CATBaseUnknown* ipSender, const IVButtonEvtArgs* ipArgs);
  virtual void OnAnalogEvent(CATBaseUnknown* ipSender, const IVAnalogEvtArgs* ipArgs);

  // Getter/Setter
  // -----------------------------------
  inline IVAtomicID ButtonAtomicID() const { return _buttonAtomicID; };
  inline void SetButtonAtomicID(IVAtomicID iID) { _buttonAtomicID = iID; };
  inline unsigned int GetButtonValue() const { return _buttonValue; };

protected:

  // ButtonGestureReco
  //-----------------------------
  void OnButtonStateChangedInternal(unsigned int buttonValue);
  void OnButtonPressedInternal();
  void OnButtonReleasedInternal();
  void OnButtonTouchedInternal();

  // Button Gesture - to overload in single handed each gesture
  // -----------------------------------
  virtual void OnSqueezeBegan();//pour les boutons analogiques
  virtual void OnSqueezeChanged();//pour les boutons analogiques
  virtual void OnSqueezeEnded();//pour les boutons analogiques

  virtual void OnPress();//bouton enfoncé complètement
  virtual void OnRelease();//bouton commence a etre relaché
  virtual void OnHold();

  // Inner Data
  //-----------------------------
  virtual void ResetGestureData();

  IVAtomicID _buttonAtomicID;
  unsigned int _buttonValue;

  CATBoolean _isHolded;
  CATBoolean _isPressed;
  CATBoolean _squeezeBegan;

  // CountDown
  //-------------------------------------------------
  //to override in each gesturereco using the timer
  virtual void OnCountDownOverInternalCB(int iTimeElaps, void *ipClientData);

private:

  IVButtonGesture* _pButtonGesture;
  IVButtonPressGesture* _pButtonPressGesture;
  IVButtonHoldGesture* _pButtonHoldGesture;
  IVButtonReleaseGesture* _pButtonReleaseGesture;
  IVButtonSqueezeGesture* _pButtonSqueezeGesture;
  IVButtonTouchedGesture* _pButtonTouchedGesture;

  // Standard, Copy constructor and equal operator
  // -----------------------------------
  IVButtonGestureRecognizer(IVButtonGestureRecognizer &);
  IVButtonGestureRecognizer& operator=(IVButtonGestureRecognizer&);
};
//-----------------------------------------------------------------------
#endif




