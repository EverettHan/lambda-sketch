//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2018
//-----------------------------------------------------------------------------
#ifndef IVISUIGenericMultipipeScenarioFactory_H
#define IVISUIGenericMultipipeScenarioFactory_H

#include "IVInterfaces.h"

#include "CATBaseUnknown.h"
#include "IVISUIScenarioMultipipe.h"
class CATUnicodeString;
class CATVizViewer;
class IVDictionary;

//-----------------------------------------------------------------------------
extern ExportedByIVInterfaces IID IID_IVISUIGenericMultipipeScenarioFactory;

//-----------------------------------------------------------------------------
/**
 * IVISUIGenericMultipipeScenarioFactory
 */
class ExportedByIVInterfaces IVISUIGenericMultipipeScenarioFactory: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  // Avatar display
  virtual void Avatar(bool iOnOff) = 0;

  // Physical User 
  virtual void PupillaryDistance(double iDist) = 0; // mm

  // Navigations
  virtual void NavigationSpeed(double iSpeed) = 0; // m/s
  
  // Model
  virtual void AutoScale() = 0;
  virtual void ManualScale(double iScale) = 0;
  
  // Scenario instantiation
  virtual IVISUIScenarioMultipipe_var BuildScenario() const = 0;
};

//-----------------------------------------------------------------------------
CATDeclareHandler(IVISUIGenericMultipipeScenarioFactory, CATBaseUnknown);

//-----------------------------------------------------------------------------
/**
 * Instantiate a factory
 */

//
IVISUIGenericMultipipeScenarioFactory_var ExportedByIVInterfaces IVISUIGenericMultipipeScenarioFactory_Create(CATVizViewer* iViewer, IVISUIScenarioMultipipe::Mode iMode, CATUnicodeString const& iConfFile);

//
//IVISUIGenericMultipipeScenarioFactory_var ExportedByIVInterfaces IVISUIGenericMultipipeScenarioFactory_CreateFrom(CATVizViewer* iViewer, IVDictionary const& iParameters);

#endif
