//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2019
//-----------------------------------------------------------------------------
#ifndef IVIHololensHandle_H
#define IVIHololensHandle_H

#include "IVInterfaces.h"

#include "IVHandTypes.h"
#include "IVIDeviceHandle.h"
class CATMathPoint;
class IVHand;

//-----------------------------------------------------------------------------
extern ExportedByIVInterfaces  IID IID_IVIHololensHandle;

//-----------------------------------------------------------------------------
/**
 * IVIHololensHandle
 *
 * An IVIHololensHandle interface allows the use of a HoloLens device in the
 * 3DEXPERIENCE.
 *
 * Access to properties such as the device sensors values (buttons, analogs,
 * trackers) etc is done through IVIDeviceHandle
 *
 * See IVHololens.h for the IVAtomicID of the device components.
 *
 * Access to the HoloLens device specific properties is done through this
 * interface.
 *
 * See IVDeviceHandleEvents.h for events. This device dispatches the following
 * events:
 *
 * - IVDeviceButtonUpdated
 * - IVDeviceAnalogUpdated
 * - IVDeviceTrackerUpdated
 * - IVDeviceChanged
 * - IVDeviceHandshakeError
 */
class ExportedByIVInterfaces IVIHololensHandle: public IVIDeviceHandle
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
   * Set the device focus at the given position. The device focus is the
   * position in the physical space where the hololens headset will try to
   * maximize hologram stability
   *
   * @param iPosition Position in the physical space (units: millimeters)
   */
  virtual void Focus(CATMathPoint const& iPosition) = 0;
};

//-----------------------------------------------------------------------------
/**
 * IVIHololensHandle
 */
CATDeclareHandler(IVIHololensHandle, IVIDeviceHandle);

#endif
