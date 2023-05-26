#ifndef IVDeviceDescription_H
#define IVDeviceDescription_H

// COPYRIGHT Dassault Systemes 2015

/**
* @CAA2Level L0
* @CAA2Usage U1
*/

#include "IVInterfaces.h"
#include "CATBaseUnknown.h"
#include "IVDeviceAtomicType.h"
#include "CATMathTransformation.h"

class CATUnicodeString;
class IVDeviceDefinition;

/**
 * IVDeviceDescription describes the VRPN devices as a set of atomic devices (buttons,
 * analogs, trackers).
 *
 * @see IVIDeviceHandle in order to manage such a device.
 *
 */
class ExportedByIVInterfaces IVDeviceDescription
{

public:

  /**
  * Create an IVDeviceDescription from the device components.
  */
  IVDeviceDescription();

  /**
  * Create an IVDeviceDescription from the device components.
  */
  virtual ~IVDeviceDescription();

  /**
  * Create an IVDeviceDescription from an IVDeviceDescription.
  */
  IVDeviceDescription(IVDeviceDescription const& iRhs);

  /**
  * Copy an IVDeviceDescription from an IVDeviceDescription.
  */
  IVDeviceDescription& operator=(IVDeviceDescription const& iRhs);
  
  /**
   * Declare a button component whose state will be updated
   * according to a button event with the given id.
   *
   * @param iEvtId
   * The button event id. 
   * Note: the IVAtomicID of the component will be the same as the event id.
   * @return
   *   An HRESULT value.
   *   <br><strong>Legal values</strong>:
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dd>The <tt>iEvtId</tt> is successfully added</dd>
   *     <dt>S_FALSE</dt>
   *     <dd>The <tt>iEvtId</tt> is already added</dd>
   *     <dt>E_FAIL</dt>
   *     <dd>The <tt>iEvtId</tt> add failed</dd>
   *   </dl>
   */
  HRESULT AddButton(unsigned int iEvtId);

  /**
  * Declare a button component whose state will be updated
  * according to a button event with the given id.
  *
  * @param iEvtId
  * The button/analog/tracker event id.
  * Note: the IVAtomicID of the component will be the same as the event id.
  * @param iID
  * The IVAtomicID of the component.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The <tt>iEvtId</tt> is successfully added</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>The <tt>iEvtId</tt> is already added</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The <tt>iEvtId</tt> add failed</dd>
  *   </dl>
  */
  HRESULT AddButton(unsigned int iEvtId, IVAtomicID iID);

  /**
  * Declare a button component whose state will be updated
  * according to a button event with the given id.
  *
  * @param iEvtId
  * The button/analog/tracker event id.
  * Note: the IVAtomicID of the component will be the same as the event id.
  * @param iAlias
  * The user alias of button component
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The <tt>iEvtId</tt> is successfully added</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>The <tt>iEvtId</tt> is already added</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The <tt>iEvtId</tt> add failed</dd>
  *   </dl>
  */
  HRESULT AddNamedButton(unsigned int iEvtId, const CATUnicodeString& iAlias);

  /**
  * Declare a button component whose state will be updated
  * according to a button event with the given id.
  *
  * @param iEvtId
  * The button/analog/tracker event id.
  * Note: the IVAtomicID of the component will be the same as the event id.
  * @param iID
  * The IVAtomicID of the component.
  * @param iAlias
  * The user alias of button/analog/tracker component
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The <tt>iEvtId</tt> is successfully added</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>The <tt>iEvtId</tt> is already added</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The <tt>iEvtId</tt> add failed</dd>
  *   </dl>
  */
  HRESULT AddNamedButton(unsigned int iEvtId, IVAtomicID iID, const CATUnicodeString& iAlias);

  /**
  * Declare an analog component whose state will be updated
  * according to an analog event with the given id.
  *
  * @param iEvtId
  * The analog event id.
  * Note: the IVAtomicID of the component will be the same as the event id.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The <tt>iEvtId</tt> is successfully added</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>The <tt>iEvtId</tt> is already added</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The <tt>iEvtId</tt> add failed</dd>
  *   </dl>
  */
  HRESULT AddAnalog(unsigned int iEvtId);

  /**
  * Declare an analog component whose state will be updated
  * according to an analog event with the given id.
  *
  * @param iEvtId
  *   The button/analog/tracker event id.
  *   Note: the IVAtomicID of the component will be the same as the event id.
  * @param iID
  *   The IVAtomicID of the component.
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The <tt>iEvtId</tt> is successfully added</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>The <tt>iEvtId</tt> is already added</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The <tt>iEvtId</tt> add failed</dd>
  *   </dl>
  */
  HRESULT AddAnalog(unsigned int iEvtId, IVAtomicID iID);

  /**
  * Declare an analog component whose state will be updated
  * according to an analog event with the given id.
  *
  * @param iEvtId
  *   The button/analog/tracker event id.
  *   Note: the IVAtomicID of the component will be the same as the event id.
  * @param iAlias
  *   The user alias of button/analog/tracker component
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The <tt>iEvtId</tt> is successfully added</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>The <tt>iEvtId</tt> is already added</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The <tt>iEvtId</tt> add failed</dd>
  *   </dl>
  */
  HRESULT AddNamedAnalog(unsigned int iEvtId, const CATUnicodeString& iAlias);

  /**
  * Declare an analog component whose state will be updated
  * according to an analog event with the given id.
  *
  * @param iEvtId
  *   The button/analog/tracker event id.
  *   Note: the IVAtomicID of the component will be the same as the event id.
  * @param iID
  *   The IVAtomicID of the component.
  * @param iAlias
  *   The user alias of button/analog/tracker component
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The <tt>iEvtId</tt> is successfully added</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>The <tt>iEvtId</tt> is already added</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The <tt>iEvtId</tt> add failed</dd>
  *   </dl>
  */
  HRESULT AddNamedAnalog(unsigned int iEvtId, IVAtomicID iID, const CATUnicodeString& iAlias);

  /**
  * Declare a tracker component whose state will be updated
  * according to a tracker event with the given id.
  *
  * @param iEvtId
  *   The tracker event id.
  *   Note: the IVAtomicID of the component will be the same as the event id.
  * @param iPostprocess (trackers only)
  *   The transformation that will be used to modify the pose of the tracker
  *   event
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The <tt>iEvtId</tt> is successfully added</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>The <tt>iEvtId</tt> is already added</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The <tt>iEvtId</tt> add failed</dd>
  *   </dl>
  */
  HRESULT AddTracker(unsigned int iEvtId, const CATMathTransformation& iPostProcess = CATMathTransformation());

  /**
   * Declare a tracker component whose state will be updated
   * according to a tracker event with the given id.
   *
   * @param iEvtId
   *   The tracker event id. 
   *   Note: the IVAtomicID of the component will be the same as the event id.
   * @param iID
   *   The IVAtomicID of the component.
   * @param iPostprocess (trackers only)
   *   The transformation that will be used to modify the pose of the tracker
   *   event
   * @return
   *   An HRESULT value.
   *   <br><strong>Legal values</strong>:
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dd>The <tt>iEvtId</tt> is successfully added</dd>
   *     <dt>S_FALSE</dt>
   *     <dd>The <tt>iEvtId</tt> is already added</dd>
   *     <dt>E_FAIL</dt>
   *     <dd>The <tt>iEvtId</tt> add failed</dd>
   *   </dl>
   */
  HRESULT AddTracker(unsigned int iEvtId, IVAtomicID iID, const CATMathTransformation& iPostprocess = CATMathTransformation());
  
  /**
   * Declare a tracker component whose state will be updated
   * according to a tracker event with the given id.
   *
   * @param iEvtId
   *   The button/analog/tracker event id. 
   *   Note: the IVAtomicID of the component will be the same as the event id.
   * @param iAlias
   *   The user alias of button/analog/tracker component
   * @param iPostprocess (trackers only)
   *   The transformation that will be used to modify the pose of the tracker
   *   event
   * @return
   *   An HRESULT value.
   *   <br><strong>Legal values</strong>:
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dd>The <tt>iEvtId</tt> is successfully added</dd>
   *     <dt>S_FALSE</dt>
   *     <dd>The <tt>iEvtId</tt> is already added</dd>
   *     <dt>E_FAIL</dt>
   *     <dd>The <tt>iEvtId</tt> add failed</dd>
   *   </dl>
   */
  HRESULT AddNamedTracker(unsigned int iEvtId, const CATUnicodeString& iAlias, const CATMathTransformation& iPostProcess = CATMathTransformation());

  /**
   * Declare a tracker component whose state will be updated
   * according to a tracker event with the given id.
   *
   * @param iEvtId
   *   The button/analog/tracker event id. 
   *   Note: the IVAtomicID of the component will be the same as the event id.
   * @param iID
   *   The IVAtomicID of the component.
   * @param iAlias
   *   The user alias of button/analog/tracker component
   * @param iPostprocess (trackers only)
   *   The transformation that will be used to modify the pose of the tracker
   *   event
   * @return
   *   An HRESULT value.
   *   <br><strong>Legal values</strong>:
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dd>The <tt>iEvtId</tt> is successfully added</dd>
   *     <dt>S_FALSE</dt>
   *     <dd>The <tt>iEvtId</tt> is already added</dd>
   *     <dt>E_FAIL</dt>
   *     <dd>The <tt>iEvtId</tt> add failed</dd>
   *   </dl>
   */
  HRESULT AddNamedTracker(unsigned int iEvtId, IVAtomicID iID, const CATUnicodeString& iAlias, const CATMathTransformation& iPostprocess = CATMathTransformation());

private:
  friend class IVVRPNDevicesFactory;

  IVDeviceDefinition* m_pDeviceDefinition;
};

#endif
