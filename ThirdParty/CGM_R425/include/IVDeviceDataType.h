//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2015
//-----------------------------------------------------------------------------
#ifndef IVDeviceDataType_H
#define IVDeviceDataType_H

#include "IVInterfaces.h"
#include "IVDeviceAtomicType.h"

/**
 * Device status
 */
struct IVDeviceStatus {
  enum Type {
    UP,
    DOWN,
    UNKNOWN,
    BROKEN
  };
};

/**
* IVDeviceFamilyType
*/
enum IVDeviceFamilyType {
  IV_DEVICE_GAMEPAD = 0,
  IV_DEVICE_SENSICSZSIGHT,
  IV_DEVICE_OPENVR,
  IV_DEVICE_OPENXR
};

/**
* IVHMDRealityType
*/
enum IVHMDRealityType {
  IV_VIRTUAL_REALITY = 0,
  IV_AUGMENTED_REALITY
};

/**
* IVDeviceSystemType
*/
enum IVDeviceSystemType {
  IV_VIVE_PRO,
  IV_VIVE_COSMOS,
  IV_WINDOWS_MR,
  IV_HMD_EMULATOR,
  IV_VR_INK,
  IV_OCULUS_QUEST,
  IV_UNKNOWN_SYSTEM_TYPE = 0xFF
};

/**
* IVDeviceComponentType
*/
enum IVDeviceComponentType {
  IV_UNKNOWN_COMPONENT = 0,
  IV_HEAD,
  IV_PRIMARY_CONTROLLER,
  IV_SECONDARY_CONTROLLER
};

/**
* IVDeviceControllerItem
*/
enum IVDeviceControllerItem
{
  IV_SYSTEM_ITEM = 0,  // System button
  IV_MENU_ITEM,        // Menu button
  IV_GRIP_ITEM,        // Grip (lateral) button
  IV_TRIGGER_ITEM,     // Rear Trigger button
  IV_PRIMARY_ITEM,     // Primary button (Logitech VR Ink)
  IV_AX_ITEM,          // A / X button (Oculus Quest, right / left controller)
  IV_BY_ITEM,          // B / Y button (Oculus Quest, right / left controller)
  IV_THUMBSTICK_ITEM,  // B / Y button (Oculus Quest, right / left controller)
  IV_TOUCHPAD_ITEM     // Touchpad button
};

#endif
