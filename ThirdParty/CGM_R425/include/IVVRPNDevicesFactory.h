#ifndef IVVRPNDevicesFactory_H
#define IVVRPNDevicesFactory_H

// COPYRIGHT Dassault Systemes 2015

/**
* @CAA2Level L0
* @CAA2Usage U1
*/

#include "IVInterfaces.h"

class IVIDeviceHandle_var;
class IVDeviceDescription;
class CATUnicodeString;

/**
 * IVVRPNDevicesFactory instantiates the VRPN devices as a set of atomic devices (buttons,
 * analogs, trackers).
 *
 * @see IVIDeviceHandle in order to manage such a device.
 *
 */
class ExportedByIVInterfaces IVVRPNDevicesFactory
{
public:

  /**
   * Create an IVIDeviceHandle from the VRPN device events published by the
   * given VRPN device server.
   *
   * @param iDeviceDescription [in]
   * The list of button/analog/tracker that must be associated with the vrpn
   * events.
   * @param iServiceName
   * The VRPN service name
   * @param iServerAddress
   * The network address of the VRPN server
   * @param iServerPort
   * The port used to connect to the VRPN server
   * @return
   * An IVIDeviceHandle. NULL_var if internal error or preconditions not met.
   */
  static IVIDeviceHandle_var CreateIVVRPNRemoteDevice(const IVDeviceDescription& iDeviceDescription,
                                                      const CATUnicodeString& iVRPNService,
                                                      const CATUnicodeString& iServerAddress,
                                                      const unsigned int iServerPort=3883);

  /**
   * Synchronize all the IV devices in session.
   * 
   * Precondition: you can call this service only from the main thread.
   *
   * Note: You typically want to call this service when you're the owner of
   * the application mainloop.
   * 
   * Note: If the device update mode was switched to automatic mode, this
   * service will do nothing.
   */
  static void UpdateAllDevices();

private:

  IVVRPNDevicesFactory();
};


#endif
