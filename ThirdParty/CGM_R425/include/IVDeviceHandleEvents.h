#ifndef IVDeviceHandleEvents_H
#define IVDeviceHandleEvents_H

// COPYRIGHT Dassault Systemes 2015

/**
* @CAA2Level L0
* @CAA2Usage U1
*/

#include "IVInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATSYPEventArgs.h"
#include "CATMathTransformation.h"
#include "IVDeviceAtomicType.h"

class CATSYPEvent;

/**
* Events emitted by IV Devices.
*
* In order to register/unregister a component as a listener, call
* AddDeviceEventHandler/RemoveDeviceEventHandler on the device.
* @see IVDeviceEvtArgs
*/
class ExportedByIVInterfaces IVDeviceHandleEvents : public CATBaseUnknown
{

  CATDeclareClass;

public:

  /**
  * Event emitted:
  * - by a device.
  * - for each button that was modified during the update of the device.
  * - with an IVButtonEvtArgs instance, from which listeners can retrieve the
  *   new state of the button.
  */
  static CATSYPEvent* IVDeviceButtonUpdated();

  /**
  * Event emitted:
  * - by a device.
  * - for each analog that was modified during the update of the device.
  * - with an IVAnalogEvtArgs instance, from which listeners can retrieve the
  *   new state of the analog.
  */
  static CATSYPEvent* IVDeviceAnalogUpdated(); // see IVAnalogEvtArgs

  /**
  * Event emitted:
  * - by a device.
  * - for each tracker that was modified during the update of the device.
  * - with an IVTrackerEvtArgs instance, from which listeners can retrieve the
  *   new state of the tracker.
  */
  static CATSYPEvent* IVDeviceTrackerUpdated();

  /**
  * Event emitted:
  * - by a device.
  * - each time it has been modified
  * - with an IVDeviceHandleEvtArgs instance, from which listeners can retrieve the
  *   new state of the device.
  */
  static CATSYPEvent* IVDeviceChanged(); // see IVDeviceHandleEvtArgs


  /**
   * Event emitted:
   * - by a device handle
   * - Each time a connection (to the device) attempt fails.
   * - with an IVDeviceEvtArgs instance
   */
  static CATSYPEvent* IVDeviceHandshakeError(); // see IVDeviceEvtArgs
  
private:

  IVDeviceHandleEvents();
};


/**
* IVDeviceEvtArgs - base class for device event arguments.
* @see IVDeviceHandleEvents
*/
class ExportedByIVInterfaces IVDeviceEvtArgs : public CATSYPEventArgs
{

  CATDeclareClass;

public:

  IVDeviceEvtArgs(CATSYPEvent *i_pEvent, CATULONG64 iTicks): CATSYPEventArgs(i_pEvent), m_ticks(iTicks) {};

  virtual ~IVDeviceEvtArgs() {};

  CATULONG64 TStamp() const { return m_ticks; }


private:

  CATULONG64 const m_ticks;
};

/**
 * IVButtonEvtArgs - describes a button modification on the device that
 * emitted the IVDeviceButtonUpdated event.
 */
class ExportedByIVInterfaces IVButtonEvtArgs : public IVDeviceEvtArgs
{

  CATDeclareClass;

public:

  /**
  * Describe a modification of the state of the button.
  */
  IVButtonEvtArgs(CATSYPEvent *i_pEvent, CATULONG64 iTicks, IVAtomicID iID, double iValue): IVDeviceEvtArgs(i_pEvent, iTicks), m_ID(iID), m_Value(iValue) {}

  /**
  * Describe the ID of the button.
  */
  IVAtomicID ID() const { return m_ID; }
  
  /**
  * Describe the new state of the button.
  */
  double Value() const { return m_Value; }

private:

  IVAtomicID m_ID;
  double m_Value; // -1 : IDLE / 0 : TOUCHED / ]0;1] : PRESSED 
};

/**
 * IVAnalogEvtArgs - describes a analog modification on the device that
 * emitted the IVDeviceAnalogUpdated event.
 */
class ExportedByIVInterfaces IVAnalogEvtArgs : public IVDeviceEvtArgs
{

  CATDeclareClass;

public:

  /**
  * Describe a modification of the value of the analog.
  */
  IVAnalogEvtArgs(CATSYPEvent *i_pEvent, CATULONG64 iTicks, IVAtomicID iID, double iValue): IVDeviceEvtArgs(i_pEvent, iTicks), m_ID(iID), m_Value(iValue) {}

  /**
  * Describe the ID of the analog.
  */
  const IVAtomicID ID() const { return m_ID; }

  /**
  * Describe the new value of the analog.
  */
  double Value() const { return m_Value; }

private:
  IVAtomicID m_ID;
  double m_Value;
};

/**
 * IVTrackerEvtArgs - describes a tracker modification on the device that
 * emitted the IVDeviceTrackerUpdated event.
 */
class ExportedByIVInterfaces IVTrackerEvtArgs : public IVDeviceEvtArgs
{

  CATDeclareClass;

public:

  /**
  * Describe a modification of the pose of the tracker.
  */
  IVTrackerEvtArgs(CATSYPEvent *i_pEvent, CATULONG64 iTicks, IVAtomicID iID, const CATMathTransformation& iPose): IVDeviceEvtArgs(i_pEvent, iTicks), m_ID(iID), m_Pose(iPose) {}

  /**
  * Describe the ID of the tracker.
  */
  IVAtomicID ID() const { return m_ID; }

  /**
  * Describe the new pose of the tracker.
  */
  const CATMathTransformation& Pose() const { return m_Pose; }

private:
  IVAtomicID m_ID;
  CATMathTransformation m_Pose;
};

/**
 * IVDeviceHandleEvtArgs - describe the modification of the device that
 * emitted the IVDeviceChanged event.
 */
class ExportedByIVInterfaces IVDeviceHandleEvtArgs : public IVDeviceEvtArgs
{
  CATDeclareClass;

public:

  //
  enum IVDeviceChange { 
    IV_CONNECTED,    // device was connected
    IV_DISCONNECTED, // device was disconnected
    IV_UPDATED       // device was updated
  };

  /**
  * Describe a modification of the state of the device.
  */
  IVDeviceHandleEvtArgs(CATSYPEvent *i_pEvent, CATULONG64 iTicks, IVDeviceChange iChange): IVDeviceEvtArgs(i_pEvent, iTicks), m_Change(iChange) {}

  /**
  * Describe the new state of the device.
  */
  IVDeviceChange DeviceChange() const { return m_Change; }

private:

  IVDeviceChange m_Change;
};

#endif
