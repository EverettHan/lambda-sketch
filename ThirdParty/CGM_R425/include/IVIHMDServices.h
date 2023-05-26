//===================================================================
// COPYRIGHT Dassault Systemes 2017/10/30
//===================================================================
// IVIHMDServices.cpp
// Header definition of class IVIHMDServices
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2017/10/30 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef IVIHMDServices_H
#define IVIHMDServices_H

#include "IVInterfaces.h"
#include "CATBaseUnknown.h"

#include "IVDeviceDataType.h"
#include "CATMathTransformation.h"
#include "CATListOfCATUnicodeString.h"
#include "IVISUIPositionedElement.h"

class IVIDeviceHandle;
class CATSYPEventHandler;

extern ExportedByIVInterfaces  IID IID_IVIHMDServices;

class IVIHMDServices_var;

class ExportedByIVInterfaces IVIHMDServices : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  static HRESULT GetInstance(IVIHMDServices_var& ohSingleton);

  /**
  * Returns true if at least an HMD is available, else false.
  * @param oListOfHMDs [out]
  *   The list of available HMDs' names.
  */
  virtual bool AreHMDsPresent(CATListOfCATUnicodeString& oListOfHMDs) const = 0;

  /**
  * For a given device, type of component (button / analog) and component id, returns the position and size of said component in the virtual world.
  *
  * @param ipDeviceHandle [in]
  *   The Device that contains the component. For the list of IVIDeviceHandle available in a given scenario, look at IVISUIScenario::GetListDevices.
  * @param iComponentType [in]
  *   The type of component, ie IVAtomicType::BUTTON or IVATOMICTYPE::ANALOG
  * @param iComponentId [in]
  *   The id of the component. For the list of buttons and analogs IDs available on a given IVIDeviceHandle, see IVIDeviceHandle::GetButtonIDs and ::GetAnalogIDs.
  * @param oLocalComponentTransfo [out]
  *   The local matrix of the component, in regard to the IVISUIPositionedElement (see hereafter) it belongs to.
  * @param ospElement [out]
  *   The element (such as an IVISUIHand) that contains the component.
  * @param oWitdh [out]
  *   The width of the component in the physical world.
  * @param oHeight [out]
  *   The height of the component in the physical world.
  *
  * @return
  *   The global CATMathTransformation that is the position of the component in the virtual world - it is given by multiplying the virtual global matrix of the ospElement by the oLocalComponentTransfo of the button.
  */
  virtual CATMathTransformation GetComponentPosition(IVIDeviceHandle* ipDeviceHandle, IVAtomicType::Type iComponentType, const IVAtomicID& iComponentId, CATMathTransformation& oLocalComponentTransfo, IVISUIPositionedElement_var& ospElement, float& oWitdh, float& oHeight) const = 0;

  /**
  * For a given device, type of component (button / analog) and component id, returns the position and size of said component in the physical world.
  *
  * @param ipDeviceHandle [in]
  *   The Device that contains the component. For the list of IVIDeviceHandle available in a given scenario, look at IVISUIScenario::GetListDevices.
  * @param iComponentType [in]
  *   The type of component, ie IVAtomicType::BUTTON or IVATOMICTYPE::ANALOG
  * @param iComponentId [in]
  *   The id of the component. For the list of buttons and analogs IDs available on a given IVIDeviceHandle, see IVIDeviceHandle::GetButtonIDs and ::GetAnalogIDs.
  * @param oLocalComponentTransfo [out]
  *   The local matrix of the component, in regard to the IVISUIPositionedElement (see hereafter) it belongs to.
  * @param oWitdh [out]
  *   The width of the component in the physical world.
  * @param oHeight [out]
  *   The height of the component in the physical world.
  */
  virtual void GetPhysicalLocalComponentPosition(IVIDeviceHandle* ipDeviceHandle, IVAtomicType::Type iComponentType, const IVAtomicID& iComponentId, CATMathTransformation& oLocalComponentTransfo, float& oWitdh, float& oHeight) const = 0;

  /**
  * Adds a listener on a device tracker, in order to retrieve its global pose in the virtual world.
  *
  * @param iDeviceComponentType [in]
  *   The Device component type to listen to : IV_HEAD, IV_PRIMARY_CONTROLLER or IV_SECONDARY_CONTROLLER
  * @param iHandler [in]
  *   The component that must be called when the event is emitted. The associated callback will receive a CATSYPEventArgs of type IVTrackerEvtArgs, which will contain the pose.
  */
  virtual void AddTrackerListener(const IVDeviceComponentType& iDeviceComponentType, CATSYPEventHandler *iHandler) = 0;

  /**
  * Removes the listener that was created with AddPoseHandler.
  *
  * @param iDeviceComponentType [in]
  *   The Device component type that was listened to : IV_HEAD, IV_PRIMARY_CONTROLLER or IV_SECONDARY_CONTROLLER
  * @param iHandler [in]
  *   The component that was used in the aforementioned method.
  */
  virtual void RemoveTrackerListener(const IVDeviceComponentType& iDeviceComponentType, CATSYPEventHandler *iHandler) = 0;

  /**
  * Sets the scenario controller meshes.
  * This method can be called before the scenario activation, or during the VR session to change the controller models dynamically.
  *
  * @param iCGRMesh [in]
  *   The CGR mesh that will be used, e.g. "OpenVR_Controller.cgr". It needs to exist in a Rsc/RscCNext module.
  * @param iSystemType [in]
  *   The type of system whose controllers you need updated, e.g. IV_VIVE, IV_WINDOWSMR... See the IVDeviceSystemType list in IVDeviceDataType.h
  *   If the parameter is unused, the currently available controllers, whichever type they are, will be updated.
  * @param iDeviceComponentType [in]
  *   Use this parameter if the system needs different models for the primary and secondary controller : for instance, with the Windows MR or the Vive Cosmos controllers.
  *   If there is no distinction between left and right - for instance, with the HTC Vive controllers - this parameter can be unused.
  */
  virtual void SetControllerMesh(CATUnicodeString const& iCGRMesh, const IVDeviceSystemType& iSystemType = IV_UNKNOWN_SYSTEM_TYPE, const IVDeviceComponentType& iDeviceComponentType = IV_UNKNOWN_COMPONENT) = 0;

};

//-----------------------------------------------------------------------
CATDeclareHandler(IVIHMDServices, CATBaseUnknown);

#endif