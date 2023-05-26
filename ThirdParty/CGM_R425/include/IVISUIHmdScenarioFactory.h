//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2018
//-----------------------------------------------------------------------------
#ifndef IVISUIHmdScenarioFactory_H
#define IVISUIHmdScenarioFactory_H

#include "IVInterfaces.h"

#include "CATBaseUnknown.h"
#include "IVISUIScenarioMultipipe.h"
class CATMathVector;
class CATVizViewer;
class IVDictionary;

//-----------------------------------------------------------------------------
extern ExportedByIVInterfaces IID IID_IVISUIHmdScenarioFactory;

//-----------------------------------------------------------------------------
/**
 * IVISUIHmdScenarioFactory
 */
class ExportedByIVInterfaces IVISUIHmdScenarioFactory: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  enum HmdScenarioFlavor {
    IV_HMD_NAVIGATION = 0,
    IV_HMD_NATURAL_AMBIANCE,
    IV_HMD_HANDS,
  };

  enum HmdDevice {
    IV_HMD_OPENVR = 0,
    IV_HMD_ZSIGHT,
    IV_HMD_OPENXR
  };

  enum HmdNavMode {
    IV_HMD_EXAMINE = 0,
    IV_HMD_FLY,
    IV_HMD_WALK,
    IV_HMD_TELEPORT
  };
  
  enum HmdGroundMode {
    IV_DESIGNER_GROUND = 0,
    IV_NATURAL_GROUND
  };

  enum HmdBlendMode {
    IV_HMD_OPAQUE = 0,
    IV_HMD_ALPHA = 1
  };

  
  // Scenario flavor
  //-----------------
  virtual void ScenarioFlavor(HmdScenarioFlavor iFlavor) = 0; // default: IV_HMD_NAVIGATION

  // Device
  //-------
  virtual void Device(HmdDevice iDevice) = 0;       // default: IV_HMD_OPENVR
  virtual void PupillaryDistance(double iDist) = 0; // mm, default: 65

  // Device Blend Mode (For Mixed Reality)
  //------------
  virtual void DeviceBlendMode(HmdBlendMode iBlendMode) = 0;

  // Navigations
  //------------
  virtual void DefaultNavigation(HmdNavMode iNav) = 0;
  virtual void NavigationSpeed(double iSpeed) = 0;   // m/s

  // Interactions
  //-------------
  virtual void ProductExplore(bool iOnOff) = 0; // default: false

  //GI Capture 
  virtual void GICapture(bool iOnOff) = 0; //default false
  virtual void GIImmersiveMode(bool iOnOff) = 0;

  // Model
  //------
  virtual void Scale(double iScale) = 0; // default: 1.0
  virtual void InteractionContextScale(double iScale) = 0; // default: 1.0

  // Ground mode
  //------------
  virtual void GroundMode(HmdGroundMode iMode) = 0; // default: natural

  // Designer ground mode options
  virtual void UserSize(double iSize) = 0; // mm, default: 1750

  // Natural ground mode options
  virtual void AutomaticGroundHeight() = 0;
  virtual void ManualGroundHeight(double iHeight) = 0; // mm, default: 0

  // VR collaboration
  //-----------------
  virtual void VRCollaboration(bool iOnOff) = 0; // default: true

  // Commands Menu
  //-----------------
  virtual void CommandsMenu(bool iOnOff) = 0; // default: false

  // Navigation Next
  //-----------------
  virtual void NavigationNext(bool iOnOff) = 0; // default: false

  // Animated Components
  //-----------------
  virtual void AnimatedComponents(bool iOnOff) = 0; // default: false

  // Cameras
  //-----------------
  virtual void CameraNavigation(bool iCameraType, CATListOfCATUnicodeString const& iCameras) = 0; // default: no camera navigation

  // Human Avatar
  //-----------------
  virtual void HumanAvatar(bool iOnOff) = 0;                  // default: false
  virtual void HumanAvatarGender(bool iOnOff) = 0;            // default: true
  virtual void HumanAvatarHeight(double iAvatarHeight)  = 0;  // mm, default: 1750

  // Rendering options
  //------------------
  virtual void GroundLock(bool iOnOff) = 0;            // default: false
  virtual void MasterRendering(bool iOnOff) = 0;       // default: true
  virtual void Highlight(bool iOnOff) = 0;             // default: true
  virtual void PreHighlight(bool iOnOff) = 0;          // default: true
  virtual void MirrorWindow(bool iOnOff) = 0;          // default: true
  virtual void AsynchronousRendering(bool iOnOff) = 0; // default: true

  // Device Display
  //------------------
  virtual void DisplayGenericTrackers(bool iOnOff) = 0;    // default: true
  virtual void DisplayAnalogFeedback(bool iOnOff) = 0;     // default: true

  //
  virtual IVISUIScenarioMultipipe_var BuildScenario() const = 0;
};

//-----------------------------------------------------------------------
/**
 * IVISUIHmdScenarioFactory_var
 */
CATDeclareHandler(IVISUIHmdScenarioFactory, CATBaseUnknown);

//-----------------------------------------------------------------------------
/**
 * Instantiate a factory
 */

//
IVISUIHmdScenarioFactory_var ExportedByIVInterfaces IVISUIHmdScenarioFactory_Create(CATVizViewer* iViewer);

//
//IVISUIHmdScenarioFactory_var ExportedByIVInterfaces IVISUIHmdScenarioFactory_CreateFrom(CATVizViewer* iViewer, IVDictionary const& iParameters);

#endif
