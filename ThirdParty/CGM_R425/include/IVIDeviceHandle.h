#ifndef IVIDeviceHandle_H
#define IVIDeviceHandle_H

// COPYRIGHT Dassault Systemes 2015

/**
* @CAA2Level L0
* @CAA2Usage U1
*/

#include "IVInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "IVDeviceAtomicType.h"

class CATMathTransformation;
class CATSYPEvent;
class CATSYPEventHandler;

extern ExportedByIVInterfaces IID IID_IVIDeviceHandle;

/**
* IVIDeviceHandle components manage a set of atomic devices (buttons,
* analogs, trackers)
*
* @see IVDevicesFactory in order to instantiate such a component.
*
*/
class ExportedByIVInterfaces IVIDeviceHandle : public CATBaseUnknown
{

  CATDeclareInterface;

public:

  /**
  * Get to the count of atomic IDs of all the buttons of this device
  * handle.
  *
  * @return
  *  The Button Ids count.
  */
  virtual int GetButtonIDsCount() = 0;

  /**
  * Get the array of atomic IDs of all the buttons of this device
  * handle.
  *
  * @param oButtons[out]
  *   The array to update.
  * @return
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Success</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>Failed</dd>
  *   </dl>
  */
  virtual HRESULT GetButtonIDs(IVAtomicID oButtons[]) = 0;

  /**
  * Get to the count of atomic IDs of all the analogs of this device
  * handle.
  *
  * @return
  *  The Analog Ids count.
  */
  virtual int GetAnalogIDsCount() = 0;

  /**
  * Get the array of atomic IDs of all the analogs of this device
  * handle.
  *
  * @param oAnalogs [out]
  *   The array to update.
  * @return
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Success</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>Failed</dd>
  *   </dl>
  */
  virtual HRESULT GetAnalogIDs(IVAtomicID oAnalogs[]) = 0;

  /**
  * Get to the count of atomic IDs of all the trackers of this device
  * handle.
  *
  * @return
  *  The Trackers Ids count.
  */
  virtual int GetTrackerIDsCount() = 0;

  /**
  * Get the array of atomic IDs of all the trackers of this device
  * handle.
  *
  * @param oTrackers [out]
  *   The array to update.
  * @return
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Success</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>Failed</dd>
  *   </dl>
  */
  virtual HRESULT GetTrackerIDs(IVAtomicID oTrackers[]) = 0;

  /**
  * Get the state of the button with the given id.
  *
  * @param iID [in]
  *   The id of the button
  * @param oState [out]
  *   The state of the button: 1 if pressed, 0 otherwise
  * @return
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Success</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>No button with the requested id or preconditions not met or internal error</dd>
  *   </dl>
  */
  virtual HRESULT GetButtonState(IVAtomicID iID, unsigned int& oState) = 0;

  /**
  * Get the state of the button with the given (user-defined) alias.
  *
  * @param iUserAlias [in]
  *   The alias of the button
  * @param oState [out]
  *   The state of the button: 1 if pressed, 0 otherwise
  * @return
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Success</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>No button with the requested id or preconditions not met or internal error</dd>
  *   </dl>
  */
  virtual HRESULT GetButtonState(const CATUnicodeString& iUserAlias, unsigned int& oState) const = 0;

  /**
  * Get the value of the analog with the given id.
  *
  * @param iID [in]
  *   The id of the axis
  * @param oValue [out]
  *   The value of the analog
  * @return
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Success</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>No axis with the requested id or preconditions not met or internal error</dd>
  *   </dl>
  */
  virtual HRESULT GetAnalogValue(IVAtomicID iID, double& oValue) = 0;

  /**
  * Get the value of the analog with the given (user-defined) alias.
  *
  * @param iUserAlias [in]
  *   The alias of the axis
  * @param oValue [out]
  *   The value of the analog
  * @return
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Success</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>No axis with the requested id or preconditions not met or internal error</dd>
  *   </dl>
  */
  virtual HRESULT GetAnalogValue(const CATUnicodeString& iUserAlias, double& oValue) const = 0;

  /**
   * Check whether the tracker with the given id is available.
   *
   * A tracker is not available for example when the controller it belongs to
   * is not powered on.
   *
   * When the tracker is not available, GetTrackerPose returns the last known
   * tracker pose.
   *
   * @param iID [in]
   *   The id of the tracker
   * @return
   *   <br><strong>Legal values</strong>:
   *   <dl>
   *     <dt>true</dt>
   *     <dd>The tracker is available</dd>
   *     <dt>false</dt>
   *     <dd>The tracker is not available or no tracker with the requested id or preconditions not met or internal error</dd>
   *   </dl>
   */
  virtual bool TrackerConnected(IVAtomicID iTrackerId) const = 0;
  
  /**
  * Get the CATMathTransformation that defines the location and
  * orientation of the tracker with the given id.
  *
  * @param iID [in]
  *   The id of the tracker
  * @param oTransfo [out]
  *   The location and orientation of the tracker
  * @return
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Success</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>No tracker with the requested id or preconditions not met or internal error</dd>
  *   </dl>
  */
  virtual HRESULT GetTrackerPose(IVAtomicID iID, CATMathTransformation& oTransfo) = 0;

  /**
  * Get the CATMathTransformation that defines the location and
  * orientation of the tracker with the given (user-defined) alias.
  *
  * @param iUserAlias [in]
  *   The alias of the tracker
  * @param oTransfo [out]
  *   The location and orientation of the tracker
  * @return
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Success</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>No tracker with the requested id or preconditions not met or internal error</dd>
  *   </dl>
  */
  virtual HRESULT GetTrackerPose(const CATUnicodeString& iUserAlias, CATMathTransformation& oTransfo) const = 0;

  /**
  * Lookup the atomic ID of the button/analog/tracker with the given alias.
  *
  * @param iType [in]
  *   The type of the atomic component
  * @param iName [in]
  *   The alias of the atomic component
  * @return
  *   The IVAtomicID of the component. IVAtomicID_INVALID if internal error or
  *   no component with such a type/alias.
  */
  virtual IVAtomicID GetComponentID(IVAtomicType::Type iType, const CATUnicodeString& iName) const = 0;

  /**
  * Lookup the alias of the button/analog/tracker with the given atomic id.
  *
  * @param iType [in]
  *   The type of the atomic component
  * @param iID [in]
  *   The atomic ID of the atomic component
  * @return
  *   The alias of the component. Empty string if internal error or no
  *   component with such a type/id.
  */
  virtual CATUnicodeString GetComponentAlias(IVAtomicType::Type iType, IVAtomicID iID) const = 0;

  /**
  * Retrieves the alias of the device.
  *
  * @param oAlias [out]
  *   The alias of the device.
  */
  virtual void GetAlias(CATUnicodeString& oAlias) const = 0;

  /**
  * Add a listener for the events dispatched by this component.
  *
  * Events that can be listened to  are:
  * - button events (see IVDeviceHandleEvents#IVDeviceButtonUpdated)
  * - analog events (see IVDeviceHandleEvents#IVDeviceAnalogUpdated)
  * - tracker events (see IVDeviceHandleEvents#IVDeviceTrackerUpdated)
  * - whole device events (see IVDeviceHandleEvents#IVDeviceChanged)
  *
  * @param iEvent [in]
  *   The event to listen to (see IVDeviceHandleEvents)
  * @param iHandler [in]
  *   The component that must be called when the event is emitted.
  * @param i
  *  The parameter i is ignored. The events are never consumed.
  *  This parameter is available so that you can use AddCATSYPWRefMethEventHandler
  * @return
  *   1 if succeeded
  */
  virtual int AddDeviceEventHandler(CATSYPEvent* iEvent, CATSYPEventHandler* iHandler, int i = 1) = 0;

  /**
  * Remove a listener for the events dispatched by this component.
  *
  * Events that can be listened to  are:
  * - button events (see IVDeviceHandleEvents#IVDeviceButtonUpdated)
  * - analog events (see IVDeviceHandleEvents#IVDeviceAnalogUpdated)
  * - tracker events (see IVDeviceHandleEvents#IVDeviceTrackerUpdated)
  * - whole device events (see IVDeviceHandleEvents#IVDeviceChanged)
  *
  * @param iEvent [in]
  *  The event to listen to (see IVDeviceHandleEvents)
  * @param iHandler [in]
  *  The component that must be called when the event is emitted.
  * @return
  *   1 if succeeded
  */
  virtual int RemoveDeviceEventHandler(CATSYPEvent* iEvent, CATSYPEventHandler* iHandler) = 0;
};

CATDeclareHandler(IVIDeviceHandle, CATBaseUnknown);

#endif
