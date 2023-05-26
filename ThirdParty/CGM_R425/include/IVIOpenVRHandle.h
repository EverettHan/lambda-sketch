//===================================================================
// COPYRIGHT  2018/02/12
//===================================================================
#ifndef IVIOpenVRHandle_H
#define IVIOpenVRHandle_H

#include "IVInterfaces.h"

#include "IVHandTypes.h"
#include "IVIDeviceHandle.h"
class IVHand;

//=============================================================================
extern ExportedByIVInterfaces  IID IID_IVIOpenVRHandle ;

//=============================================================================
/**
 * IVIOpenVRHandle
 *
 * An IVIOpenVRHandle interface allows the use of an OpenVR device in the
 * 3DEXPERIENCE.
 *
 * Access to properties such as the device sensors values (buttons, analogs,
 * trackers) etc is done through IVIDeviceHandle
 *
 * See IVOpenVR.h for the IVAtomicID of the device components.
 *
 * Access to the OpenVR device specific properties is done through this
 * interface.
 *
 * See IVDeviceHandleEvents.h for events. This device dispatches the following
 * events:
 *
 * - IVDeviceButtonUpdated
 * - IVDeviceAnalogUpdated
 * - IVDeviceTrackerUpdated
 * - IVDeviceChanged
 */
class ExportedByIVInterfaces IVIOpenVRHandle: public IVIDeviceHandle
{
  CATDeclareInterface;

public:

  /**
   * Retrieve the left or right hand of the user.
   * 
   * @param iLeftOrRight Left or right hand.
   * 
   * @param oHand The request user hand.
   *
   * @return 
   * S_OK Success. The requested hand is tracked by the device and oHand has
   * been initialized.
   *
   * E_FAIL Error. The requested hand is not tracked by the device, or
   * internal error or preconditions not moet.
   */
  virtual HRESULT GetHand(IVHandId iLeftOrRight, IVHand& oHand) = 0;

  /**
   * Shutdown progressively the HMD display. This operation is complete after
   * the given duration.
   *
   * This call is non-blocking.
   *
   * @param iMs The duration of the operation in milliseconds. Must be
   * strictly positive.
   */
  virtual void FadeDisplay(double iMs) = 0;

  /**
   * Restore progressively the HMD display. This operation is complete
   * after the given duration.
   *
   * This call is non-blocking.
   *
   * @param iMs The duration of the operation in milliseconds. Must be
   * strictly positive.
   */
  virtual void UnfadeDisplay(double iMs) = 0;

  /**
   * Check whether the OpenVR headset has a proximity sensor. See
   * HeaderMounted
   *
   * @return true if the headset can detect whether it is positioned on the
   * user head. False otherwise.
   */
  virtual bool HeadSensorAvailability() const = 0;

  /**
   * Check whether the OpenVR headset is positioned on the user head through
   * its proximity sensor. See HeadSensor
   *
   * @return true if a proximity sensor is available and the headset is
   * positioned on the user head. false otherwise.
   */
  virtual bool HeadSensor() const = 0;

  /**
   * Trigger an haptic pulse on the controller which owns the tracker with the
   * given id with the given strength and during the given amount of time.
   *
   * Note: that if the device doesnt support haptic pulses, this call results
   * in a no-op.
   *
   * Note: any haptic pulse already running on the controller is canceled and
   * replaced.
   *
   * Note: in order to cancel a running haptic pulse, call this method with
   * iStrength set to 0.
   *
   * @param iTrackerId The tracker id.
   *
   * @param iStrength The strength of the pulse must belong to the ]0, 1]
   * range. If iStrength is <0, this call is a no-op. If iStrength is 0,
   * cancel the current haptic pulse. If iStrength is >1, it is capped to 1.
   *
   * @param iMs The duration of the pulse in milliseconds.
   */
  virtual void HapticPulse(IVAtomicID iTrackerId, double iStrength=1., unsigned short iMs=0) = 0;
};

//=============================================================================
CATDeclareHandler(IVIOpenVRHandle, IVIDeviceHandle);

#endif
