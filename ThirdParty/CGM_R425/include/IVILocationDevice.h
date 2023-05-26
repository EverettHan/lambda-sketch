#ifndef IVILocationDevice_H
#define IVILocationDevice_H

#include "IVInterfaces.h"
#include "CATSysErrorDef.h"
#include "CATBaseUnknown.h"
#include "IVDeviceDataType.h"
#include "CATMathPoint2D.h"
class CATSYPEvent;
class CATSYPEventHandler;

extern ExportedByIVInterfaces IID IID_IVILocationDevice;

/**
 * AtomicID of the location device analog components
 */
struct IVLocationDeviceAnalog
{
  static const IVAtomicID LATITUDE  = 0;
  static const IVAtomicID LONGITUDE = 1;
};

/**
 * Interface representing a device with location-detection sensors (e.g. a GPS).
 */
class ExportedByIVInterfaces IVILocationDevice : public CATBaseUnknown
{

  CATDeclareInterface;

public:

  /**
   * Return the current position as gps coordinates: (latitude, longitude).
   */
  virtual CATMathPoint2D GetLocation() const = 0;

  /**
   * Register/unregister a component as a handler for the events emitted by this device.
   * see IVDeviceHandleEvents for the descriptions of the events as well as
   * their argument.
   */
  virtual int AddDeviceEventHandler(CATSYPEvent *iEvent, CATSYPEventHandler *iHandler, int i = 1) = 0;
  virtual int RemoveDeviceEventHandler(CATSYPEvent *iEvent, CATSYPEventHandler *iHandler) = 0;
};

CATDeclareHandler(IVILocationDevice, CATBaseUnknown);

#endif
