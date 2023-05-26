//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2018
//-----------------------------------------------------------------------------
#ifndef IVISUIWallScenarioFactory_H
#define IVISUIWallScenarioFactory_H

#include "IVInterfaces.h"

#include "CATBaseUnknown.h"
#include "IVISUIScenarioWall.h"
class CATUnicodeString;
class CATVizViewer;
class IVDictionary;

//-----------------------------------------------------------------------------
extern ExportedByIVInterfaces IID IID_IVISUIWallScenarioFactory;

//-----------------------------------------------------------------------------
/**
 * IVISUIWallScenarioFactory
 */
class ExportedByIVInterfaces IVISUIWallScenarioFactory: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  // Physical User 
  virtual void PupillaryDistance(double iDist) = 0; // mm

  // Navigations
  virtual void NavigationSpeed(double iSpeed) = 0; // m/s
  
  // Model
  virtual void ManualScale(double iScale) = 0;
  
  // Scenario instantiation
  virtual IVISUIScenarioWall_var BuildScenario() const = 0;
};

//-----------------------------------------------------------------------------
CATDeclareHandler(IVISUIWallScenarioFactory, CATBaseUnknown);

//-----------------------------------------------------------------------------
/**
 * Instantiate a factory
 */

//
IVISUIWallScenarioFactory_var ExportedByIVInterfaces IVISUIWallScenarioFactory_Create(CATVizViewer* iViewer, CATUnicodeString const& iConfFile);

#endif
