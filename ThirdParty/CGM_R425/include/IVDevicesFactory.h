//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2015
//-----------------------------------------------------------------------------
#ifndef IVDevicesFactory_H
#define IVDevicesFactory_H

#include "IVInterfaces.h"

#include "IVIDeviceHandle.h"
#include "IVIFlystick.h"
#include "IVIGamepad.h"
#include "IVILocationDevice.h"
#include "IVIMotionDevice.h"
class CATUnicodeString;
class CATVizViewer;
class IVDeviceDefinition;

/**
 * IVDevicesFactory
 */
class ExportedByIVInterfaces IVDevicesFactory 
{
public:

  /**
   * Create an IVIGamepad component from the first available attached gamepad
   * controller.
   *
   * Note: when looking for an available controller, devices that can be
   * manipulated as Xbox 360 controllers (XInput) will be prefered over those
   * that can be manipulated only as DirectInput controllers.
   *
   * @see IVIGamepad for more explanations.
   */
  static IVIGamepad_var CreateIVGamepad();

  /**
   * Create an IVIDeviceHandle from the VRPN device events published by the
   * given VRPN device server.
   *
   * @param iDeviceDefinition
   * The list of button/analog/tracker that must be associated with the vrpn
   * events.
   *
   * @param iServiceName
   * The VRPN service name
   *
   * @param iServerAddress
   * The network address of the VRPN server
   *
   * @param iServerPort
   * The port used to connect to the VRPN server
   *
   * @return
   * An IVIDeviceHandle. NULL_var if internal error or preconditions not met.
   */
  static IVIDeviceHandle_var CreateIVVRPNRemoteDevice(const IVDeviceDefinition& iDeviceDefinition,
                                                      const CATUnicodeString& iVRPNService,
                                                      const CATUnicodeString& iServerAddress,
                                                      const unsigned int iServerPort=3883);

  /**
   * Create an IVIFlystick from a remote DTrack flystick exported by a VRPN
   * device server.
   *
   * Note: for the mapping beetween the physical DTrack
   * buttons/analogs/tracker and the IVAtomicID of the IVIFlystick, @see
   * IVVRPNRemoteDTrack
   *
   * @param iFlystick
   * The DTrack flystick identifier. @see IVVRPNRemoteDTrack
   *
   * @param iServiceName
   * The VRPN service name
   *
   * @param iServerAddress
   * The network address of the VRPN server
   *
   * @param iServerPort
   * The port used to connect to the VRPN server
   *
   * @return
   * An IVIFlystick_var. NULL_var if internal error or preconditions not met.
   */
  static IVIFlystick_var CreateIVVRPNRemoteFlystick(const IVVRPNRemoteDTrack& iFlystick,
                                                    const CATUnicodeString& iVRPNService,
                                                    const CATUnicodeString& iServerAddress,
                                                    const unsigned int iServerPort=3883);

//-----------------------------------------------------------------------------

//:FIXME: Migrate V6IOSIVSampleDocument.cpp so that it uses directly the API
//provided by IVDeviceCore instead, then remove those methods from the factory
//for now. (rationale: dont expose services that are not necessary/used by
//real customers)
  
  /**
   * Create an IVIMotionDevice
   */
  static IVIMotionDevice_var CreateIVMotionDevice();

  /**
   * Create an IVILocationDevice
   */
  static IVILocationDevice_var CreateIVLocationDevice();

  /**
   * Activate the automatic update of the IV devices in session.
   *
   * When this mode is activated, UpdateAllDevices is automatically called for
   * you at Idle-time, calling UpdateAllDevices yourself will do nothing.
   *
   * Note that this mode cannot be deactivated.
   */
  static void ActivateUpdateOnIdle();
  
  /**
   * Activate the automatic update of the IV devices in session.
   *
   * When this mode is activated, UpdateAllDevices is automatically called
   * each time the given viewer is updated.
   *
   * Note that this mode cannot be deactivated manually. 
   *
   * However, it will be automatically deactivated when the viewer is
   * destroyed.  In this case, IV devices in session will not be updated
   * anymore automatically
   */
  static void ActivateUpdateOnViewer(CATVizViewer* iVizViewer);

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

  IVDevicesFactory();
};


#endif
