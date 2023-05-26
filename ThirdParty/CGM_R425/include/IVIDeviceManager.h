#ifndef _IVIDeviceManager_H
#define _IVIDeviceManager_H

//COPYRIGHT DASSAULT SYSTEMES 2010

#include "IVInterfaces.h"

#include "CATBaseUnknown.h"
#include "CATSysErrorDef.h"
#include "CATUnicodeString.h"
#include "IVDeviceDataType.h"
class CATSYPEventFactory;

/**
* IVGamepadProperties
* Properties of a gamepad controller
*/
struct ExportedByIVInterfaces IVGamepadProperties
{
  IVGamepadProperties() {}

  CATUnicodeString m_Name;
};

/**
* IVzSightProperties
* Properties of a Sensic zSight HMD
* m_Name is either "SEN zSight 1" or "SEN zSight 1/SEN zSight 2"
*/

struct ExportedByIVInterfaces IVzSightProperties
{
  IVzSightProperties() {}

  CATUnicodeString m_Name;
};


/**
* IVOpenVRDeviceProperties
* Properties of an OpenVR device HMD
*/
struct ExportedByIVInterfaces IVOpenVRDeviceProperties
{
  IVOpenVRDeviceProperties() {}
  CATUnicodeString m_Name;
  CATUnicodeString m_SystemName;
  IVHMDRealityType m_RealityType;
};


/**
* IVOpenXRDeviceProperties
* Properties of an OpenXR device HMD
*/
struct ExportedByIVInterfaces IVOpenXRDeviceProperties
{
  IVOpenXRDeviceProperties() {}
  CATUnicodeString m_Name;
  CATUnicodeString m_SystemName;
  IVHMDRealityType m_RealityType;
  bool m_HandTrackingSupport;
};

/**
* Interface to manage iV Devices.
* <strong>Role</strong>: The iV Device Manager allows the enumeration and retrieval of all iV Devices available at run time.
*
* @example
* <pre>
* // Sample code showing how to parse all available IVIJoystick devices
* HRESULT rc = S_OK;
* 
* IVIDeviceManager* pDeviceManager = NULL;
* rc = IVIDeviceManager::GetManager(pDeviceManager);
* if(FAILED(rc) || !pDeviceManager) return E_UNEXPECTED;
*
*  unsigned int nbJoysticks = 0;
*  HRESULT hr = pDeviceManager->GetDeviceCount(IID_IVIJoystick, nbJoysticks);
*  if(FAILED(hr)) return hr;
*
*  IVIDevice* pDevice = NULL;
*  for(unsigned int i=0; i < nbJoysticks; i++)
*  {
*    hr = pDeviceManager->GetDevice(IID_IVIJoystick, i, pDevice);
*    if(FAILED(hr) || !pDevice)
*    {
*      rc = hr;
*      continue;
*    }
*    
*    // Use pDevice here.
*    // Before using it as a IVIJoystick, a QueryInterface using IID_IVIJoystick must be called.
*    // See IVIDevice and IVIJoystick for more details.
*    // You can also use IVIDeviceManager::GetJoystick as a shortcut in order to retrieve the first available Joystick.
*
*    pDevice->Release();
*    pDevice = NULL;
*  }
* </pre>
*
* @see IVIDevice, IVIJoystick
*/
class ExportedByIVInterfaces IVIDeviceManager : public CATBaseUnknown
{

	 CATDeclareClass;

public:

  /** @nodoc */
  virtual ~IVIDeviceManager();

 /** 
  * @nodoc 
  * Retrieves the unique @href IVIDeviceManager instance.
  *
  * @param [out] oDeviceManager
  *   The @href IVIDeviceManager instance.
  *
  * <br><strong>Precondition</strong>:
  * <tt>oDeviceManager</tt> should be set to <tt>NULL</tt> before calling this method.
  *
  * <br><strong>Lifecycle rules deviation</strong>:
  * The @href IVIDeviceManager is a Singleton. Its lifecycle is automatically handled by the iV framework. 
  * The returned pointer should never be <tt>NULL</tt>, and the caller should <strong>never</strong> try and delete it.
  *
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The @href IVIDeviceManager instance is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The @href IVIDeviceManager instance could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oDeviceManager</tt> parameter was not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  static IVIDeviceManager* GetManager();   

  /**
  * Enumerate the available gamepad controllers
  * @see IVGamepadProperties
  */
  virtual int GetPluggedGamepadControllersCount() const = 0;
  virtual IVGamepadProperties GetPluggedGamepadControllers(unsigned int iDeviceIndex) const = 0;

  /**
  * Enumerate the available zSight HMDs
  * @see IVzSightProperties
  */
  virtual int GetPluggedzSightHMDsCount() const = 0;
  virtual IVzSightProperties GetPluggedzSightHMDs(unsigned int iDeviceIndex) const = 0;

  /**
  * Enumerate the available OpenVR HMDs
  * @see IVOpenVRDeviceProperties
  */
  virtual int GetPluggedOpenVRHMDsCount() const = 0;
  virtual IVOpenVRDeviceProperties GetPluggedOpenVRHMDs(unsigned int iDeviceIndex) const = 0;

  /**
  * Gets the properties of the available OpenXR HMD, if any.
  * @see IVOpenXRDeviceProperties
  */
  virtual int GetPluggedOpenXRHMDsCount() const = 0;
  virtual IVOpenXRDeviceProperties GetPluggedOpenXRHMDs(unsigned int iDeviceIndex) const = 0;
  virtual void ShutdownOpenXR() const = 0;

 /**
  * @nodoc 
  * Non-CAA method.
  */
  virtual CATBaseUnknown_var GetDevice(const IID& iDeviceCategory, const unsigned int iDeviceIndex = 0) const = 0;

 /**
  * @nodoc 
  * Retrieves the unique @href CATSYPEventFactory instance.
  */
  static CATSYPEventFactory* GetEventFactory();

 /**
  * @nodoc 
  * Internal use only.
  * Should only be called by IVScheduler.
  */
  virtual HRESULT RunTask() = 0;

  virtual bool AreVRExtensionsEnabled() = 0;

  virtual void RequestVRFeature() = 0;
  virtual void UnRequestVRFeature() = 0;
  virtual bool GetRequestVRFlag() = 0;

protected:
  /** @nodoc */
  IVIDeviceManager();

  virtual CATSYPEventFactory* GetDeviceEventFactory() = 0;

private:

  // Copy not allowed
  IVIDeviceManager(const IVIDeviceManager&);
  IVIDeviceManager& operator=(const IVIDeviceManager&);
};

#endif // _IVIDeviceManager_H
