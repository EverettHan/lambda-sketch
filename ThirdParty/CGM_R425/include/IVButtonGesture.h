// COPYRIGHT Dassault Systemes 2020
//===================================================================
//
// IVButtonGesture.h
// Header definition of IVButtonGesture
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2020  Creation: 
//===================================================================
#ifndef IVButtonGesture_H
#define IVButtonGesture_H

#include "IVInterfaces.h"

// System
// -----------------------------------
#include "IVGesture.h"

// State
// -----------------------------------
enum IVButtonGestureState {
  IV_BUTTON_PRESSED = 0,
  IV_BUTTON_TOUCHED, // eg for Oculus controllers
  IV_BUTTON_HOLD,
  IV_BUTTON_RELEASED,
};

struct IVButtonData
{
  IVAtomicID buttonID;
  IVAtomicID deviceID; // Controller or hand
  IVButtonGestureState buttonState;
  double squeezeRatio; // -1 : IDLE / 0 : TOUCHED / ]0;1[ : SQUEEZED / 1 : PRESSED 

  bool operator == (const IVButtonData& mapping) const {
    return buttonID == mapping.buttonID && deviceID == mapping.deviceID && buttonState == mapping.buttonState && squeezeRatio == mapping.squeezeRatio;
  };

  bool operator != (const IVButtonData& mapping) const {
    return !(*this == mapping);
  };

};


//-----------------------------------------------------------------------
class ExportedByIVInterfaces IVButtonGesture : public IVGesture
{
  CATDeclareClass;

public:

  //Constructor/Destructor
  // -----------------------------------
  IVButtonGesture(const CATUnicodeString& iName);
  virtual ~IVButtonGesture();

  IVButtonGesture(IVButtonGesture const&);
  IVButtonGesture& operator=(IVButtonGesture const&);

  IVButtonData ButtonData() const;

protected:

  friend class IVButtonGestureRecognizer;

  IVButtonData _buttonData;

private:

};
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
class ExportedByIVInterfaces IVButtonPressGesture : public IVButtonGesture
{
  CATDeclareClass;

public:

  //Constructor/Destructor
  // -----------------------------------
  IVButtonPressGesture(const CATUnicodeString& iName);
  virtual ~IVButtonPressGesture();

private:

  friend class IVButtonGestureRecognizer;

  // Standard, Copy constructor and equal operator
  // -----------------------------------
  IVButtonPressGesture(IVButtonPressGesture&);
  IVButtonPressGesture& operator=(IVButtonPressGesture&);
};
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
class ExportedByIVInterfaces IVButtonReleaseGesture : public IVButtonGesture
{
  CATDeclareClass;

public:

  //Constructor/Destructor
  // -----------------------------------
  IVButtonReleaseGesture(const CATUnicodeString& iName);
  virtual ~IVButtonReleaseGesture();

private:

  friend class IVButtonGestureRecognizer;

  // Standard, Copy constructor and equal operator
  // -----------------------------------
  IVButtonReleaseGesture(IVButtonReleaseGesture&);
  IVButtonReleaseGesture& operator=(IVButtonReleaseGesture&);
};

//-----------------------------------------------------------------------
class ExportedByIVInterfaces IVButtonTouchedGesture : public IVButtonGesture
{
  CATDeclareClass;

public:

  //Constructor/Destructor
  // -----------------------------------
  IVButtonTouchedGesture(const CATUnicodeString& iName);
  virtual ~IVButtonTouchedGesture();

private:

  friend class IVButtonGestureRecognizer;

  // Standard, Copy constructor and equal operator
  // -----------------------------------
  IVButtonTouchedGesture(IVButtonTouchedGesture&);
  IVButtonTouchedGesture& operator=(IVButtonTouchedGesture&);
};

//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
class ExportedByIVInterfaces IVButtonHoldGesture : public IVButtonGesture
{
  CATDeclareClass;

public:

  //Constructor/Destructor
  // -----------------------------------
  IVButtonHoldGesture(const CATUnicodeString& iName);
  virtual ~IVButtonHoldGesture();

private:

  friend class IVButtonGestureRecognizer;

  // Standard, Copy constructor and equal operator
  // -----------------------------------
  IVButtonHoldGesture(IVButtonHoldGesture&);
  IVButtonHoldGesture& operator=(IVButtonHoldGesture&);
};
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
class ExportedByIVInterfaces IVButtonSqueezeGesture : public IVButtonGesture
{
  CATDeclareClass;

public:

  //Constructor/Destructor
  // -----------------------------------
  IVButtonSqueezeGesture(const CATUnicodeString& iName);
  virtual ~IVButtonSqueezeGesture();

private:

  friend class IVButtonGestureRecognizer;

  // Standard, Copy constructor and equal operator
  // -----------------------------------
  IVButtonSqueezeGesture(IVButtonSqueezeGesture&);
  IVButtonSqueezeGesture& operator=(IVButtonSqueezeGesture&);
};
//-----------------------------------------------------------------------

#endif




