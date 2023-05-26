// COPYRIGHT DASSAULT SYSTEMES 2014

#ifndef IVISUIScenarioWall_h
#define IVISUIScenarioWall_h

#include "IVInterfaces.h"
#include "IVISUIScenario.h"

extern ExportedByIVInterfaces IID IID_IVISUIScenarioWall;

class ExportedByIVInterfaces IVISUIScenarioWall : public IVISUIScenario
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

  virtual HRESULT GetMode(IVISUIScenarioWall::Mode& oMode) const = 0;

  /**
  * Set the scenario mode.
  *
  * @param iMode [in]
  *   The scenario mode.
  */
  virtual HRESULT SetMode(IVISUIScenarioWall::Mode iMode) = 0;

  /**
  * Get the model scale
  *
  * @param oScale [out]
  *   The model scale.
  */
  virtual HRESULT GetModelScale(double& oScale) const = 0;

  /**
  * Set the model scale
  *
  * @param iScale [in]
  *   The model scale.
  */
  virtual HRESULT SetModelScale(double iScale) = 0;

  /**
  * Get the scenario scale mode.
  *
  * @param oMode [out]
  *   The scenario scale mode.
  */
  virtual HRESULT GetScaleMode(IVISUIScenarioWall::ScaleMode& oMode) const = 0;

  /**
  * Set the scenario scale mode.
  *
  * @param iMode [in]
  *   The scenario scale mode.
  */
  virtual HRESULT SetScaleMode(IVISUIScenarioWall::ScaleMode iMode) = 0;

  /**
  * Get the scenario fullscreen mode.
  *
  * @param oMode [out]
  *   If oMode == 1 : Simple fullscreen mode is used.
  *   If oMode == 2 : "Fullscreen for Design" mode is used, i.e. the action bar is available.
  */
  virtual HRESULT GetFullscreenMode(int& oMode) const = 0;

  /**
  * Set the scenario fullscreen mode.
  *
  * @param iMode [in]
  *   If iMode == 1 : Simple fullscreen mode is used.
  *   If iMode == 2 : "Fullscreen for Design" mode is used, i.e. the action bar is available.
  */
  virtual HRESULT SetFullscreenMode(int iMode) = 0;
};

CATDeclareHandler(IVISUIScenarioWall, IVISUIScenario);

#endif  // IVSUIScenarioWall_h
