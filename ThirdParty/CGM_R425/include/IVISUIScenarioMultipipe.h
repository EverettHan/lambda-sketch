#ifndef IVISUIScenarioMultipipe_h
#define IVISUIScenarioMultipipe_h

// COPYRIGHT DASSAULT SYSTEMES 2014

/**
* @CAA2Level L0
* @CAA2Usage U1
*/

#include "IVInterfaces.h"
#include "IVISUIScenario.h"
#include "IVISUIInteractionContext.h" // to remove

class CATViewpoint;
class CAT3DBagRep;

extern ExportedByIVInterfaces IID IID_IVISUIScenarioMultipipe;

/**
* Interface representing an Immersive Virtuality Scenario dedicated to CAVE or HMD.
*/
class ExportedByIVInterfaces IVISUIScenarioMultipipe : public IVISUIScenario
{

  CATDeclareInterface;

public:
  enum Mode
  {
    Auditorium = 0,
    Immersive = 1
  };

  enum ScaleMode
  {
    Automatic = 0,
    Defined = 1
  };

  enum ICInitializationMode 
  { 
    IV_DEFAULT = 0,
    IV_USE_VP, 
    IV_USE_RAW_VP, 
    IV_USE_VP_AND_GROUND, 
    IV_USE_VP_3DAMBIANCE,
    IV_USE_VP_AND_MANUALGROUND 
  };

  /**
  * Get the scenario mode.
  *
  * @param oMode [out]
  *   The scenario mode.
  * @return
  *   An HRESULT value.
  */
  virtual HRESULT GetMode(Mode& oMode) const = 0;

  /**
  * Set the scenario mode.
  *
  * @param iMode [in]
  *   The scenario mode.
  * @return
  *   An HRESULT value.
  */
  virtual HRESULT SetMode(Mode iMode) = 0;

  /**
  * Get the model scale.
  *
  * @param oScale [out]
  *   The model scale.
  * @return
  *   An HRESULT value.
  */
  virtual HRESULT GetModelScale(double& oScale) const = 0;

  /**
  * Set the model scale.
  *
  * @param iScale [in]
  *   The model scale.
  * @return
  *   An HRESULT value.
  */
  virtual HRESULT SetModelScale(double iScale) = 0;

  /**
  * Get the scenario scale mode.
  *
  * @param oMode [out]
  *   The scenario scale mode.
  * @return
  *   An HRESULT value.
  */
  virtual HRESULT GetScaleMode(ScaleMode& oMode) const = 0;

  /**
  * Set the scenario scale mode.
  *
  * @param iMode [in]
  *   The scenario scale mode.
  * @return
  *   An HRESULT value.
  */
  virtual HRESULT SetScaleMode(ScaleMode iMode) = 0;

  /**
  * Get the viewpoints list count.
  *
  * @return
  *   The scenario viewpoints list count.
  * @return
  *   An HRESULT value.
  */
  virtual unsigned int GetViewpointsCount() = 0;

  /**
  * Get the viewpoints used for the scenario.
  *
  * @param iIndex [in]
  *   The scenario viewpoint index.
  * @return
  *   The scenario viewpoint.
  */
  virtual CATViewpoint* GetViewpoint(unsigned iIndex) = 0;

  /**
   * Configure the scenario so that devices with tracked controllers (such as
   * those that may come with an HMD) are not rendered.
   *
   * By default, controllers are rendered.
   *
   * SetRenderModelVisibility is taken into account either if it is called
   * before the scenario is started, or dynamically. In which case it targets only the controllers themselves.
   * Every other rep around them (textures on the buttons, lasers) is not impacted.
   *
   * Useful only when the scenario is configured with a device with tracked
   * controllers.
   *
   * @param iOnOff [in]
   *   If true, the controllers are displayed. If false, they're removed.
   *
   */
  virtual void SetRenderModelVisibility(bool iOnOff) = 0;

  /**
   * Configure the scenario so that the update of the 3DEXPERIENCE main
   * display is temporarily disabled.
   *
   * By default, the main display is updated.
   *
   * SetMasterRenderingUpdate is taken into account only if it is called
   * before the scenario is started.
   *
   * Useful only when the scenario is configured so that:
   *  - it manages additional displays (such as for HMDs)
   *  - more rendering performance is required for those displays
   */
  virtual void SetMasterRenderingUpdate(bool iOnOff) = 0;

  /**
   * Configure the scenario so that the interaction context is initialized on the ground, according to the viewpoint, 
   * according to the ambiance.
   *
   * SetInteractionContextInitMode is taken into account only if it is called
   * before the scenario is started.
   */
  virtual void SetInteractionContextInitMode(ICInitializationMode iMode) = 0;

  /**
   * Configure the scenario so that 3Dambiance is displayed.
   *
   * Set3DAmbianceMode is taken into account only if it is called
   * before the scenario is started.
   */
  virtual void Set3DAmbianceMode(bool iOnOff) = 0;

  /**
   * Show or hide the 3D scene from the 3DEXPERIENCE main display in VR.
   *
   * @note the scene is displayed by default.
   */
  virtual void DisplaySceneInVR(bool iOnOff) = 0;

  /**
   * Get the Ambiance rep to Capture the GI in case of Interactive ambiance
   *
   */
  virtual CAT3DBagRep* GetVRAmbianceBagRep() = 0;
};

CATDeclareHandler(IVISUIScenarioMultipipe, IVISUIScenario);

#endif  // IVSUIScenarioMultipipe_h
