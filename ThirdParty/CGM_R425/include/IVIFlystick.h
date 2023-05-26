//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2015
//-----------------------------------------------------------------------------
#ifndef IVIFlystick_H
#define IVIFlystick_H

#include "IVInterfaces.h"
#include "CATBaseUnknown.h"
#include "IVDeviceDataType.h"
#include "CATMathTransformation.h"

extern ExportedByIVInterfaces  IID IID_IVIFlystick;

/**
 * IVAtomicID of the flystick button components
 */
struct IVFlystickButton
{
  static const IVAtomicID B0 = 0;
  static const IVAtomicID B1 = 1;
  static const IVAtomicID B2 = 2;
  static const IVAtomicID B3 = 3;

  static const IVAtomicID BSTICK = 4;
};


/**
 * IVAtomicID of the flystick analog components
 */
struct IVFlystickAnalog
{
  static const IVAtomicID SX = 0;
  static const IVAtomicID SY = 1;
};


/**
 * AtomicID of the flystick tracker components
 */
struct IVFlystickTracker
{
  static const IVAtomicID POSER = 0;
};


/**
 * IVVRPNRemoteDTrack
 *
 * Used to create an IVIFlystick from a DTrack flystick exposed by a VRPN
 * device server.
 *
 * @see IVDevicesFactory::CreateIVVRPNRemoteFlystick
 *
 * Mapping beetween the atomic ID of the resulting IVIFlystick and the
 * physical DTrack flystick:
 *
 *   * B0 is the trigger
 *   * B1...B4 are the buttons on the top of the flystick, before the axis, given from the left to the right
 *   * B5 is the axis button 
 *   * X is the horizontal analog of the axis
 *   * Y is the vertical analog of the axis
 *   * POSE is the pose of the flystick
 *
 * The pose of the DTrack flystick depends on the DTrack configuration
 * (referential "F" associated with the flystick, referential in which "F"
 * is expressed)
 *
 * @param index: index of VRPN DTrack flystick set of buttons/analogs (for the
 * first flystick, this is 0)
 *
 * @param trackerIndex: index of the VRPN DTrack tracker
 *
 * @param poseCalibration: flystick pose post processing transformation
 *
 * Note: it is not possible to identify with *one* index the set of
 * buttons/analogs/tracker of a given DTrack flystick (this limitation is
 * imposed by the the vrpn driver from the vrpn library).
 */
struct ExportedByIVInterfaces IVVRPNRemoteDTrack {
  unsigned int index;
  unsigned int trackerIndex;
  CATMathTransformation poseCalibration;

  //
  IVVRPNRemoteDTrack(unsigned int i, unsigned int ti, const CATMathTransformation& p=CATMathTransformation())
    : index(i), trackerIndex(ti), poseCalibration(p) {}

  //
  IVVRPNRemoteDTrack(unsigned int i, const CATMathTransformation& p= CATMathTransformation()):
    index(i), trackerIndex(i), poseCalibration(p) {}

  //
  IVVRPNRemoteDTrack():
    index(0), trackerIndex(0) {}
};


/**
 * IVIFlystick components represent a VR flystick with the following topology:
 * - 4 buttons
 * - 1 clickable stick
 * - 1 tracker
 *
 * Because the role of the IVIFlystick is to provide a common interfaces to
 * flysticks from different vendors/accessed through different protocoles
 * (vendor sdk, VRPN protocole etc.), see the documentation of the
 * IVDevicesFactory::CreateXXXFlystick methods in order to know which
 * button/analog/tracker's atomic id maps to its physical counterpart of type
 * XXX.
 *
 */
class ExportedByIVInterfaces IVIFlystick: public CATBaseUnknown
{
CATDeclareInterface;

public:

  /**
   * Retrieve the value of the button with the given id.
   *
   * @param iID
   * The button id. see IVFlystickButton
   * Note: for xinput controllers, querying IVGamepadButton::LT/RT yields E_FAIL.
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
   * The axis id. see IVFlystickAnalog
   *
   * @return
   * S_OK Success.
   * E_XXX Internal error or there is no analog with the given id.
   */
  virtual HRESULT GetAxis(IVAtomicID iID, double& oValue) const = 0;

  /**
   * Retrieve the pose of the tracker
   *
   * @return
   * S_OK Success.
   * E_XXX Internal error
   */
  virtual HRESULT GetPose(CATMathTransformation& oValue) const = 0;
};

CATDeclareHandler(IVIFlystick, CATBaseUnknown);

#endif
