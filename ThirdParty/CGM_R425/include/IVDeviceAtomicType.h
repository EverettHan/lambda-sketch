#ifndef IVDeviceAtomicType_H
#define IVDeviceAtomicType_H

// COPYRIGHT Dassault Systemes 2015

/**
* @CAA2Level L1
* @CAA2Usage U1
*/

/**
 * Enumerates the different type of atomic on a device.
 * <b>Role</b>: It can be used in IVIDeviceHandle
 * to specify the atomics of the device.
 * @param BUTTON
 * Use this enum for the buttons
 * @param ANALOG
 * Use this enum for the axis
 * @param TRACKER
 * Use this enum for the trackers
 * @param INVALID
 * Use this enum for initialisation
*/
struct IVAtomicType {
  enum Type { 
    BUTTON,
    ANALOG,
    TRACKER,
    INVALID
  };
private:
  IVAtomicType();
};

/**
 * IVAtomicID
 */
typedef unsigned int IVAtomicID;

const IVAtomicID IVAtomicID_INVALID = -1; // max unsigned int

#endif
