#ifndef IVSUIScenarioEvents_H
#define IVSUIScenarioEvents_H

// COPYRIGHT Dassault Systemes 2016

/**
* @CAA2Level L0
* @CAA2Usage U1
*/

#include "IVInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATSYPEventArgs.h"

class CATSYPEvent;

/**
* Events emitted by the IVISUIScenario
*
* In order to register/unregister a component as a listener, call
* AddScenarioEventHandler/RemoveScenarioEventHandler on the SUI scenario.
* @see IVScenarioEvtArgs
*/
class ExportedByIVInterfaces IVScenarioEvents : public CATBaseUnknown
{

  CATDeclareClass;

public:

  /**
  * Event emitted
  * - by the SUI scenario
  * - each time a scenario is activated/deactivated
  * - with an IVScenarioEvtArgs instance, from which the listeners can
  *   retrieve the new state of the scenario.
  */
  static CATSYPEvent* IVScenarioChanged();

private:

  IVScenarioEvents();
};


/**
* IVScenarioEvtArgs - describes a modification of the state the SUI
* scenario whose state changed
* @see IVScenarioEvents
*/
class ExportedByIVInterfaces IVScenarioEvtArgs : public CATSYPEventArgs
{

  CATDeclareClass;

public:

  enum IVScenarioChange {
    IV_ACTIVATED,  // scenario was activated
    IV_DEACTIVATED // scenario was deactivated
  };
  
  /**
  * Describe a modification of the state of the SUI scenario.
  */
  IVScenarioEvtArgs(CATSYPEvent* i_pEvent, IVScenarioChange iChange): CATSYPEventArgs(i_pEvent), m_Change(iChange) {}

  /**
  * Describe the new state of the SUI scenario.
  */
  IVScenarioChange ScenarioChange() const { return m_Change; }
  
private:

  IVScenarioChange m_Change;

};

#endif
