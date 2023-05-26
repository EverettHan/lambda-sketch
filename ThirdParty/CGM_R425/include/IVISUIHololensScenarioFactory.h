//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2019
//-----------------------------------------------------------------------------
#ifndef IVISUIHololensScenarioFactory_H
#define IVISUIHololensScenarioFactory_H

#include "IVInterfaces.h"

#include "CATBaseUnknown.h"
#include "IVISUIScenario.h"
class CATUnicodeString;
class CATVizViewer;
class IVISUIBehaviour;
class IVSUIExternalBehaviourFactory;

//-----------------------------------------------------------------------------
extern ExportedByIVInterfaces IID IID_IVISUIHololensScenarioFactory;

//-----------------------------------------------------------------------------
/**
 * IVISUIHololensScenarioFactory
 */
class ExportedByIVInterfaces IVISUIHololensScenarioFactory: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
   * Set the viewer for the scenario. 
   *
   * @note This parameter is mandatory (no defaults).
   */
  virtual void Viewer(CATVizViewer* iViewer) = 0;

  /**
   * 
   * @note This parameter is mandatary (no defaults).
   */
  virtual void RemoteAddress(CATUnicodeString const& iAddress) = 0;

  /**
   * Enable/disable the avatar display management.
   *
   * Default is false (no avatar display).
   */
  virtual void Avatar(bool iOnOff) = 0;

  /**
   * Enable/distable the airgrab navigation behaviour.
   *
   * Default is false (no airgrab).
   */
  virtual void AirGrab(bool iOnOff) = 0;

  /**
   * Add an external behaviour to the scenario. The external behaviour will be
   * instantiated through the given factory during the scenario construction.
   */
  virtual void AddExternalBehaviour(IVSUIExternalBehaviourFactory* iBehaviourFactory) = 0;

  /**
   * Build the IV scenario.
   *
   * @return The scenario. NULL if internal error or preconditions not met
   * (e.g. device not available)
   */
  virtual IVISUIScenario_var BuildScenario() const = 0;
};

//-----------------------------------------------------------------------------
/**
 * IVISUIHololensScenarioFactory_var
 */
CATDeclareHandler(IVISUIHololensScenarioFactory, CATBaseUnknown);

//-----------------------------------------------------------------------------
/**
 * Instantiate a factory
 */
IVISUIHololensScenarioFactory_var ExportedByIVInterfaces IVISUIHololensScenarioFactory_Create();


#endif
