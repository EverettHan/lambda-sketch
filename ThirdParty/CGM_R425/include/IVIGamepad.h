//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2015
//-----------------------------------------------------------------------------
#ifndef IVIGamepad_H
#define IVIGamepad_H

#include "IVInterfaces.h"

#include "IVDeviceDataType.h"
#include "CATBaseUnknown.h"
class CATSYPEvent;
class CATSYPEventHandler;

extern ExportedByIVInterfaces IID IID_IVIGamepad;

/**
 * AtomicID of the gamepad buttons components
 */
struct ExportedByIVInterfaces IVGamepadButton
{
  static const IVAtomicID A     = 0;  // A button
  static const IVAtomicID B     = 1;  // B button
  static const IVAtomicID X     = 2;  // X button
  static const IVAtomicID Y     = 3;  // Y button
  static const IVAtomicID LB    = 4;  // LB button
  static const IVAtomicID RB    = 5;  // RB button
  static const IVAtomicID BACK  = 6;  // Back button
  static const IVAtomicID START = 7;  // Start button
  static const IVAtomicID LSB   = 8;  // Left stick button
  static const IVAtomicID RSB   = 9;  // Right stick button
  static const IVAtomicID LT    = 10; // Deprecated. Do not use
  static const IVAtomicID RT    = 11; // Deprecated. Do not use
};


/**
 *AtomicID of the gamepad analog components
 */
struct ExportedByIVInterfaces IVGamepadAnalog
{
  static const IVAtomicID LSX  = 0; // Left stick X
  static const IVAtomicID LSY  = 1; // Left stick Y
  static const IVAtomicID RSX  = 2; // Right stick X
  static const IVAtomicID RSY  = 3; // Right stick Y
  static const IVAtomicID DPAD = 4; // Direction pad
  static const IVAtomicID LT   = 5; // Left trigger as an analog
  static const IVAtomicID RT   = 6; // Right trigger as an analog
};

/**
 * IVIGamepad components represent a gamepad controller:
 * - with a xbox-like topology.
 * - managed through xinput only.
 * 
 * On xinput gamepad controllers:
 * - the Left and Right triggers are analogs.
 * - Analog values of sticks are given in the backward->forward direction
 * 
 * Note: The direction pad is an analog with the following values: -1.0
 * (neutral position), 0.0 (top), 45. (top-right), 90.0 (right) etc.
 */
class ExportedByIVInterfaces IVIGamepad : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  // Gamepad type. Always XInput
  enum GamepadType {
    XInput, 
    DInput,
    Unknown
  };

  /**
   * Retrieve the gamepad type. 
   * Deprecated. Do not use.
   *
   * @return
   * The gamepad type. Always IVIGamepad:::XINPUT
   */
  virtual IVIGamepad::GamepadType GetType() const = 0;

  /**
   * Retrieve the value of the button with the given id.
   *
   * @param iID
   * The button id. see IVGamepadAnalog
   *
   * @return
   * S_OK Success.
   * E_XXX Internal error or there is no analog with the given id.
   */
  virtual HRESULT GetButton(IVAtomicID iID, unsigned int& oValue) const = 0;

  /**
   * Retrieve the value of the analog with the given id.
   *
   * @param iID
   * The axis id. see IVGamepadAnalog
   *
   * @return
   * S_OK Success.
   * E_XXX Internal error or there is no analog with the given id.
   */
  virtual HRESULT GetAxis(IVAtomicID iID, double& oValue) const = 0;

  /**
   * Register/unregister a component as a handler for the events emitted by this device.
   * Components can listen to:
   * - button modifications (IVDeviceButtonUpdated/IVButtonEvtArgs)
   * - analog modifications (IVDeviceAnalogUpdated/IVAnalogEvtArgs)
   * - device modifications (IVDeviceChanged/IVDeviceHandleEvtArgs)
   *
   * Each kind of event is emitted with an argument describing the
   * modification.
   *
   * see IVDeviceHandleEvents for the descriptions of the events as well as
   * their argument.
   */
  virtual int AddDeviceEventHandler(CATSYPEvent *iEvent, CATSYPEventHandler *iHandler, int i = 1) = 0;
  virtual int RemoveDeviceEventHandler(CATSYPEvent *iEvent, CATSYPEventHandler *iHandler) = 0;
};

CATDeclareHandler(IVIGamepad, CATBaseUnknown);

#endif
