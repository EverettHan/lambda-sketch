//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2018
//-----------------------------------------------------------------------------
#ifndef IVISUIDesktopWallScenarioFactory_H
#define IVISUIDesktopWallScenarioFactory_H

#include "IVInterfaces.h"

#include "CATBaseUnknown.h"
#include "IVISUIScenarioWall.h"
class CATUnicodeString;
class CATVizViewer;

//-----------------------------------------------------------------------------
extern ExportedByIVInterfaces IID IID_IVISUIDesktopWallScenarioFactory;

//-----------------------------------------------------------------------------
/**
 * IVISUIDesktopWallScenarioFactory
 */
class ExportedByIVInterfaces IVISUIDesktopWallScenarioFactory: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  enum DesktopWallNavMode {
    IV_DESKTOP_WALL_NONE = 0,
    IV_DESKTOP_WALL_FLY,
    IV_DESKTOP_WALL_WALK
  };

  // Physical User 
  virtual void PupillaryDistance(int iDist) = 0; // mm

  // Screen Eye Distance
  virtual void ScreenEyeDistance(int iScreenEyeDistance) = 0; // cm

  // Screen Size
  virtual void ScreenSize(int iScreenWidth, int iScreenHeight) = 0; // mm

  // Active Stereoscopy
  virtual void ActiveStereoscopy(bool iOnOff) = 0;
                                                                    
  // Navigations
  virtual void DefaultNavigation(DesktopWallNavMode iNav) = 0;
  virtual void NavigationSpeed(double iSpeed) = 0; // m/s
  
  // Model
  virtual void AutoScale() = 0;
  virtual void ManualScale(float iScale) = 0;
  
  // Scenario instantiation
  virtual IVISUIScenarioWall_var BuildScenario() const = 0;
};

//-----------------------------------------------------------------------------
CATDeclareHandler(IVISUIDesktopWallScenarioFactory, CATBaseUnknown);

//-----------------------------------------------------------------------------
/**
 * Instantiate a factory
 */

//
IVISUIDesktopWallScenarioFactory_var ExportedByIVInterfaces IVISUIDesktopWallScenarioFactory_Create(CATVizViewer* iViewer);

#endif
