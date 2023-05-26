#ifndef IVIBehaviourEvents_H
#define IVIBehaviourEvents_H

// COPYRIGHT Dassault Systemes 2022

#include "IVInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATSYPEventArgs.h"

class CATSYPEvent;

/**
* Events emitted by the IVExtBehaviour
* @see IVBehaviourEvtArgs
*/
class ExportedByIVInterfaces IVIBehaviourEvents : public CATBaseUnknown
{

  CATDeclareClass;

public:

  /**
  * Event emitted
  * - by any behaviour
  * - each time it's activated and deactivated
  * - with an IVBehaviourEvtArgs instance, from which the listeners can
  *   retrieve the new state of the behaviour.
  */
  static CATSYPEvent* IVBehaviourStateChanged();

  /**
* Event emitted
* - by the air grab behaviour
* - each time its state machine changes state
* - with an IVAirGrabBehaviourEvtArgs instance, from which the listeners can
*   retrieve the new state of the behaviour (IDLE, GRAB with 1 or 2 grips, RESETSCALE)
*/
  static CATSYPEvent* IVAirGrabBehaviourStateChanged();
private:

  IVIBehaviourEvents();
};


/**
* IVAirGrabBehaviourEvtArgs - describes a modification of the state the
* behaviour whose state changed
* @see IVIBehaviourEvents
*/
class ExportedByIVInterfaces IVAirGrabBehaviourEvtArgs : public CATSYPEventArgs
{

  CATDeclareClass;

public:

  enum IVAirGrabBehaviourChange {
    IV_AIRGRAB_IDLE,       // Air Grab Idle Mode
    IV_AIRGRAB_GRAB1,      // One grip pressed
    IV_AIRGRAB_GRAB2,      // Two grips pressed
    IV_AIRGRAB_RESETSCALE, // Reset Scale 
  };

  /**
  * Describe a modification of the state of the behaviour
  */
  IVAirGrabBehaviourEvtArgs(CATSYPEvent* i_pEvent, IVAirGrabBehaviourChange iBehaviourState) : CATSYPEventArgs(i_pEvent), m_behaviourState(iBehaviourState) {}

  /**
  * Describe the new state of the behaviour
  */
  IVAirGrabBehaviourChange BehaviourState() const { return m_behaviourState; }

private:

  IVAirGrabBehaviourChange m_behaviourState;

};

/**
* IVBehaviourEvtArgs - describes a modification of the state of a behaviour (activated/deactivated)
* @see IVIBehaviourEvents
*/
class ExportedByIVInterfaces IVBehaviourEvtArgs : public CATSYPEventArgs
{

  CATDeclareClass;

public:

  enum IVBehaviourChange {
    IV_BEHAVIOUR_ACTIVATED,  // behaviour was activated
    IV_BEHAVIOUR_DEACTIVATED // behaviour was deactivated
  };

  /**
  * Describe a modification of the state of the behaviour
  */
  IVBehaviourEvtArgs(CATSYPEvent* i_pEvent, IVBehaviourChange iBehaviourState) : CATSYPEventArgs(i_pEvent), m_behaviourState(iBehaviourState) {}

  /**
  * Describe the new state of the behaviour
  */
  IVBehaviourChange BehaviourState() const { return m_behaviourState; }

private:

  IVBehaviourChange m_behaviourState;

};

#endif
