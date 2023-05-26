//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2015
//-----------------------------------------------------------------------------
#ifndef IVIMotionDevice_H
#define IVIMotionDevice_H

#include "IVInterfaces.h"

#include "CATBaseUnknown.h"
#include "IVDeviceDataType.h"
#include "IVDataType.h"
class CATMathQuaternion;
class CATMathTransformation;
class CATMathVector;
class CATSYPEvent;
class CATSYPEventHandler;


extern ExportedByIVInterfaces IID IID_IVIMotionDevice;

/**
 * AtomicID of the motiondevice analog components
 */
struct IVMotionDeviceAnalog
{
  static const IVAtomicID GRAVITY_X = 0;
  static const IVAtomicID GRAVITY_Y = 1;
  static const IVAtomicID GRAVITY_Z = 2;
  static const IVAtomicID ACCEL_X   = 3;
  static const IVAtomicID ACCEL_Y   = 4;
  static const IVAtomicID ACCEL_Z   = 5;
};

/**
 * AtomicID of the motiondevice tracker components
 */
struct IVMotionDeviceTracker
{
  static const IVAtomicID ORIENTATION = 0;
};


/**
 * IVIMotionDevice
 *
 * @see IVDevicesFactory in order to instantiate such a component.
 *
 */
class ExportedByIVInterfaces IVIMotionDevice : public CATBaseUnknown
{

CATDeclareInterface;

public:

  /**
   *
   */
  virtual CATMathTransformation GetMotionDevicePose() const = 0;

  /**
   *
   */
  virtual CATMathQuaternion GetMotionDeviceOrientation() const = 0;
  
  /**
   *
   */
  virtual CATMathVector GetGravity() const = 0;

  /**
   *
   */
  virtual CATMathVector GetAcceleration() const = 0;
  
  /**
   *
   */
  virtual IVTimestamp GetTimestamp() const = 0;

  /**
   * Register/unregister a component as a handler for the events emitted by this device.
   * see IVDeviceHandleEvents for the descriptions of the events as well as
   * their argument.
   */
  virtual int AddDeviceEventHandler(CATSYPEvent *iEvent, CATSYPEventHandler *iHandler, int i = 1) = 0;
  virtual int RemoveDeviceEventHandler(CATSYPEvent *iEvent, CATSYPEventHandler *iHandler) = 0;
};

CATDeclareHandler(IVIMotionDevice, CATBaseUnknown);

#endif
